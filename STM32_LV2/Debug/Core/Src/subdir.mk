################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/main.o: ../Core/Src/main.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Peripherals/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Device" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL/STM32F4xx_HAL_Driver/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/display/ILI9341" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32f4xx_it.o: ../Core/Src/stm32f4xx_it.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Peripherals/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Device" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL/STM32F4xx_HAL_Driver/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/display/ILI9341" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/system_stm32f4xx.o: ../Core/Src/system_stm32f4xx.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/Peripherals/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Device" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/CMSIS/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL/STM32F4xx_HAL_Driver/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/HAL" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV2/display/ILI9341" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

