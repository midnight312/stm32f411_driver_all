################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Display/Tim1637/tm1637.c 

OBJS += \
./Application/Display/Tim1637/tm1637.o 

C_DEPS += \
./Application/Display/Tim1637/tm1637.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Display/Tim1637/tm1637.o: ../Application/Display/Tim1637/tm1637.c Application/Display/Tim1637/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Application/Display/Tim1637" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Display/Tim1637/tm1637.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

