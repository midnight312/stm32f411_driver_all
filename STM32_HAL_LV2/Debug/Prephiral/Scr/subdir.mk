################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Prephiral/Scr/exti.c \
../Prephiral/Scr/gpio.c \
../Prephiral/Scr/rcc.c \
../Prephiral/Scr/spi.c \
../Prephiral/Scr/tim.c \
../Prephiral/Scr/uart1.c 

OBJS += \
./Prephiral/Scr/exti.o \
./Prephiral/Scr/gpio.o \
./Prephiral/Scr/rcc.o \
./Prephiral/Scr/spi.o \
./Prephiral/Scr/tim.o \
./Prephiral/Scr/uart1.o 

C_DEPS += \
./Prephiral/Scr/exti.d \
./Prephiral/Scr/gpio.d \
./Prephiral/Scr/rcc.d \
./Prephiral/Scr/spi.d \
./Prephiral/Scr/tim.d \
./Prephiral/Scr/uart1.d 


# Each subdirectory must supply rules for building sources it contributes
Prephiral/Scr/exti.o: ../Prephiral/Scr/exti.c Prephiral/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Application/Display/Tim1637" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Scr/exti.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Prephiral/Scr/gpio.o: ../Prephiral/Scr/gpio.c Prephiral/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Application/Display/Tim1637" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Scr/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Prephiral/Scr/rcc.o: ../Prephiral/Scr/rcc.c Prephiral/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Application/Display/Tim1637" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Scr/rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Prephiral/Scr/spi.o: ../Prephiral/Scr/spi.c Prephiral/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Application/Display/Tim1637" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Scr/spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Prephiral/Scr/tim.o: ../Prephiral/Scr/tim.c Prephiral/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Application/Display/Tim1637" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Scr/tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Prephiral/Scr/uart1.o: ../Prephiral/Scr/uart1.c Prephiral/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_HAL_LV2_1/Application/Display/Tim1637" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Scr/uart1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

