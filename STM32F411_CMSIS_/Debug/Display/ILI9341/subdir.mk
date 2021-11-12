################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Display/ILI9341/MY_ILI9341.c \
../Display/ILI9341/TSC2046.c 

OBJS += \
./Display/ILI9341/MY_ILI9341.o \
./Display/ILI9341/TSC2046.o 

C_DEPS += \
./Display/ILI9341/MY_ILI9341.d \
./Display/ILI9341/TSC2046.d 


# Each subdirectory must supply rules for building sources it contributes
Display/ILI9341/MY_ILI9341.o: ../Display/ILI9341/MY_ILI9341.c Display/ILI9341/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/ILI9341/MY_ILI9341.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"
Display/ILI9341/TSC2046.o: ../Display/ILI9341/TSC2046.c Display/ILI9341/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Peripheral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/display" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Display/ILI9341" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32F411_CMSIS_/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/ILI9341/TSC2046.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

