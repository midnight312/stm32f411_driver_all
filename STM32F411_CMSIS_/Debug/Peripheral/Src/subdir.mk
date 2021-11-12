################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/Src/adc1.c \
../Peripheral/Src/crc.c \
../Peripheral/Src/exti.c \
../Peripheral/Src/gpio.c \
../Peripheral/Src/i2c.c \
../Peripheral/Src/pwr.c \
../Peripheral/Src/rcc.c \
../Peripheral/Src/rtc.c \
../Peripheral/Src/spi.c \
../Peripheral/Src/tim.c \
../Peripheral/Src/usart.c 

OBJS += \
./Peripheral/Src/adc1.o \
./Peripheral/Src/crc.o \
./Peripheral/Src/exti.o \
./Peripheral/Src/gpio.o \
./Peripheral/Src/i2c.o \
./Peripheral/Src/pwr.o \
./Peripheral/Src/rcc.o \
./Peripheral/Src/rtc.o \
./Peripheral/Src/spi.o \
./Peripheral/Src/tim.o \
./Peripheral/Src/usart.o 

C_DEPS += \
./Peripheral/Src/adc1.d \
./Peripheral/Src/crc.d \
./Peripheral/Src/exti.d \
./Peripheral/Src/gpio.d \
./Peripheral/Src/i2c.d \
./Peripheral/Src/pwr.d \
./Peripheral/Src/rcc.d \
./Peripheral/Src/rtc.d \
./Peripheral/Src/spi.d \
./Peripheral/Src/tim.d \
./Peripheral/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/Src/adc1.o: ../Peripheral/Src/adc1.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/Src/adc1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Peripheral/Src/crc.o: ../Peripheral/Src/crc.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/Src/crc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Peripheral/Src/exti.o: ../Peripheral/Src/exti.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/Src/exti.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Peripheral/Src/gpio.o: ../Peripheral/Src/gpio.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/Src/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Peripheral/Src/i2c.o: ../Peripheral/Src/i2c.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/Src/i2c.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Peripheral/Src/pwr.o: ../Peripheral/Src/pwr.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/Src/pwr.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Peripheral/Src/rcc.o: ../Peripheral/Src/rcc.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/Src/rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Peripheral/Src/rtc.o: ../Peripheral/Src/rtc.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/Src/rtc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Peripheral/Src/spi.o: ../Peripheral/Src/spi.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/Src/spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Peripheral/Src/tim.o: ../Peripheral/Src/tim.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/Src/tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Peripheral/Src/usart.o: ../Peripheral/Src/usart.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/Src/usart.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

