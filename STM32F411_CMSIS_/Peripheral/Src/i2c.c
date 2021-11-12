/*
 * i2c.c
 *
 *  Created on: Sep 8, 2021
 *      Author: thanh
 */
#include "i2c.h"

/*
 * @brief SPI GPIO configiguration
 * SPI1 PB6-SCL PB7-SDA
 */
void i2c_I2C1_GPIO_config(void)
{
	//Enable clock
	RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	//Mode altenate
	GPIOB->MODER &= ~(GPIO_MODER_MODE6 | GPIO_MODER_MODE7);
	GPIOB->MODER &= ~(GPIO_MODER_MODE6_0 | GPIO_MODER_MODE6_1 | GPIO_MODER_MODE7_0 | GPIO_MODER_MODE7_0);
	//Speed high
	GPIOB->OSPEEDR &= ~(0xFUL << 12);
	GPIOB->OSPEEDR |= (0xFUL << 12);
	//Map to i2c
	GPIOB->AFR[0] &= ~(0xFFUL << 24);
	GPIOB->AFR[0] |= (0x44UL << 24);
}

/*
 * @brief I2C configuration
 */
_Bool i2c_I2C1_config(void)
{
	//Enable I2C clock
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
	//Tell I2c register APB1 clock frequency
	I2C1->CR2 &= ~(I2C_CR2_FREQ);
	I2C1->CR2 |= 36UL;
	//Rice Time
	I2C1->TRISE &= ~(I2C_TRISE_TRISE);
	I2C1->TRISE |= 36 + 1;
	//I2C speed
	I2C1->CCR = 40;
	//Enable I2C prephiral
	I2C1->CR1 |= I2C_CR1_PE;
}

/*
 * @brief I2C check address
 */
_Bool i2c_I2C1_isSlaveAddressExist(uint8_t addr, uint32_t timeOut)
{
	uint32_t starTick = rcc_msGetTicks();
	//Wait for I2C busy
	I2C1->CR1 &= ~(I2C_CR1_ACK_Pos);
	I2C1->CR1 |= I2C_CR1_START;
	while(!(I2C1->SR1 & I2C_SR1_SB));
	{
		if(rcc_msGetTicks() - starTick > timeOut) return false;
	}

	//Send slave address
	I2C1->DR = addr;
	//Wait for ACK
	while(!(I2C1->SR1 & I2C_SR1_ADDR));
	{
		if(rcc_msGetTicks() - starTick > timeOut) return false;
	}
	//Generate stop condition
	I2C1->CR1 |= I2C_CR1_STOP;
	//Clear ADDR flag
	__IO uint32_t temp = I2C1->SR1;
	temp = I2C1->SR2;
	(void)temp;
	//Wait for busy
	while(!(I2C1->SR2 & I2C_SR2_BUSY));
	{
		if(rcc_msGetTicks() - starTick > timeOut) return false;
	}
	return true;
}

/*
 * @brief I2C transmit (master)
 */
_Bool i2c_I2C1_masterTransmit(uint8_t addr,uint8_t *data, uint8_t len, uint32_t timeOut)
{
	uint32_t starTick = rcc_msGetTicks();
	//Wait for I2C busy
	I2C1->CR1 &= ~(I2C_CR1_ACK_Pos);
	I2C1->CR1 |= I2C_CR1_START;
	while(!(I2C1->SR1 & I2C_SR1_SB));
	{
		if(rcc_msGetTicks() - starTick > timeOut) return false;
	}

	//Send slave address
	I2C1->DR = addr;
	//Wait for ACK
	while(!(I2C1->SR1 & I2C_SR1_ADDR));
	{
		if(rcc_msGetTicks() - starTick > timeOut) return false;
	}
	//Generate stop condition
	I2C1->CR1 |= I2C_CR1_STOP;
	__IO uint32_t temp = I2C1->SR1;
	temp = I2C1->SR2;
	(void)temp;
	//Send data
	uint8_t dataIdx = 0;
	uint8_t dataSize = len;
	while(dataSize > 0)
	{
		while(!(I2C1->SR1 & I2C_SR1_TXE))
		{
			if(rcc_msGetTicks() - starTick > timeOut) return false;
			I2C1->DR = data[dataIdx];
			dataIdx ++;
			dataSize --;
		}
	}
	//Wait for BTF flag
	while(!(I2C1->SR1 & I2C_SR1_BTF));
	{
		if(rcc_msGetTicks() - starTick > timeOut) return false;
	}
	//Generate stop condition
	I2C1->CR1 |= I2C_CR1_STOP;
	return true;
}
/*
 * @brief I2C receive (master)
 */
_Bool i2c_I2C1_receiveTransmit(uint8_t addr,uint8_t *data, uint8_t len, uint32_t timeOut)
{
	uint32_t starTick = rcc_msGetTicks();
	uint8_t dataIdx = 0;
	uint8_t dataSize = len;
	//Wait for BUSY
	while(!(I2C1->SR2 & I2C_SR2_BUSY));
	{
		if(rcc_msGetTicks() - starTick > timeOut) return false;
	}
	//Generate start condition
	I2C1->CR1 &= ~(I2C_CR1_ACK_Pos);
	I2C1->CR1 |= I2C_CR1_ACK;
	I2C1->CR1 |= I2C_CR1_START;
	while(!(I2C1->SR1 & I2C_SR1_SB));
	{
		if(rcc_msGetTicks() - starTick > timeOut) return false;
	}
	//Send address slave
	I2C1->DR = addr | 0x01UL; //Read slave
	while(!(I2C1->SR1 & I2C_SR1_ADDR));
	{
		if(rcc_msGetTicks() - starTick > timeOut) return false;
	}
	if(len == 0)
	{
		__IO uint32_t temp = I2C1->SR1;
		temp = I2C1->SR2;
		(void)temp;
		//Generate stop condition
		I2C1->CR1 |= I2C_CR1_STOP;
		return false;
	}

	while(dataSize > 0)
	{
		if(dataSize > 2)
		{
			//Wait until BTF = 1
			while(!(I2C1->SR1 & I2C_SR1_BTF));
			{
				if(rcc_msGetTicks() - starTick > timeOut) return false;
			}
			//Set ACK low
			I2C1->CR1 &= ~I2C_CR1_ACK;
			while(dataSize > 0)
			{
			dataIdx = I2C1->DR;
			dataIdx++;
			dataSize--;
			//Wait until BTF = 1
			while(!(I2C1->SR1 & I2C_SR1_BTF) && (dataSize > 2) );
			{
				if(rcc_msGetTicks() - starTick > timeOut) return false;
			}
			//Set stop high
			I2C1->CR1 |= I2C_CR1_STOP;
			}
			if(dataSize == 2)
			{
				I2C1->CR1 |= I2C_CR1_STOP;
			}
			//Read data twice
			data[dataIdx] = I2C1->DR;
			dataIdx++;
			dataSize--;
			data[dataIdx] = I2C1->DR;
			dataIdx++;
			dataSize--;
		}
		else
		{
			//Wait until addr = 1
			while(!(I2C1->SR1 & I2C_SR1_ADDR));
			{
				if(rcc_msGetTicks() - starTick > timeOut) return false;
			}
			//Set ACK low POS high
			I2C1->CR1 &= ~I2C_CR1_ACK;
			I2C1->CR1 |= (I2C_CR1_ACK_Pos);
			//Clear addr flag
			__IO uint32_t temp = I2C1->SR1;
			temp = I2C1->SR2;
			(void)temp;
			//Wait BTF = 1
			while(!(I2C1->SR1 & I2C_SR1_BTF));
			{
				if(rcc_msGetTicks() - starTick > timeOut) return false;
			}
			//Set stop high
			I2C1->CR1 |= I2C_CR1_STOP;
			//Read data twice
			data[dataIdx] = I2C1->DR;
			dataIdx++;
			dataSize--;
			data[dataIdx] = I2C1->DR;
			dataIdx++;
			dataSize--;
		}
	}
	return true;
}
