################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/printf_redirect.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/printf_redirect.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/printf_redirect.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/main.o: ../Core/Src/main.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/printf_redirect.o: ../Core/Src/printf_redirect.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/printf_redirect.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

