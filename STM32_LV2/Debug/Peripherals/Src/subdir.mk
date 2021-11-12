################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripherals/Src/exti.c \
../Peripherals/Src/gpio.c \
../Peripherals/Src/i2c.c \
../Peripherals/Src/rcc.c \
../Peripherals/Src/spi.c \
../Peripherals/Src/tim.c \
../Peripherals/Src/uart1.c 

OBJS += \
./Peripherals/Src/exti.o \
./Peripherals/Src/gpio.o \
./Peripherals/Src/i2c.o \
./Peripherals/Src/rcc.o \
./Peripherals/Src/spi.o \
./Peripherals/Src/tim.o \
./Peripherals/Src/uart1.o 

C_DEPS += \
./Peripherals/Src/exti.d \
./Peripherals/Src/gpio.d \
./Peripherals/Src/i2c.d \
./Peripherals/Src/rcc.d \
./Peripherals/Src/spi.d \
./Peripherals/Src/tim.d \
./Peripherals/Src/uart1.d 


# Each subdirectory must supply rules for building sources it contributes
Peripherals/Src/exti.o: ../Peripherals/Src/exti.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Peripherals/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Device" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL/STM32F4xx_HAL_Driver/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/display/ILI9341" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripherals/Src/exti.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripherals/Src/gpio.o: ../Peripherals/Src/gpio.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Peripherals/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Device" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL/STM32F4xx_HAL_Driver/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/display/ILI9341" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripherals/Src/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripherals/Src/i2c.o: ../Peripherals/Src/i2c.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Peripherals/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Device" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL/STM32F4xx_HAL_Driver/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/display/ILI9341" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripherals/Src/i2c.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripherals/Src/rcc.o: ../Peripherals/Src/rcc.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Peripherals/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Device" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL/STM32F4xx_HAL_Driver/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/display/ILI9341" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripherals/Src/rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripherals/Src/spi.o: ../Peripherals/Src/spi.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Peripherals/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Device" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL/STM32F4xx_HAL_Driver/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/display/ILI9341" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripherals/Src/spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripherals/Src/tim.o: ../Peripherals/Src/tim.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Peripherals/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Device" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL/STM32F4xx_HAL_Driver/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/display/ILI9341" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripherals/Src/tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripherals/Src/uart1.o: ../Peripherals/Src/uart1.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Peripherals/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Device" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL/STM32F4xx_HAL_Driver/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/display/ILI9341" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripherals/Src/uart1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

