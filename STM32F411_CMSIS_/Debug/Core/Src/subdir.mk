################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/print_redirect.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/print_redirect.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/print_redirect.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/main.o: ../Core/Src/main.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Core/Src/print_redirect.o: ../Core/Src/print_redirect.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/print_redirect.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Core/Src/system_stm32f4xx.o: ../Core/Src/system_stm32f4xx.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

