################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Prephiral/Src/adc1.c \
../Prephiral/Src/exti.c \
../Prephiral/Src/gpio.c \
../Prephiral/Src/pwr.c \
../Prephiral/Src/rcc.c \
../Prephiral/Src/spi.c \
../Prephiral/Src/timer.c \
../Prephiral/Src/uart.c 

OBJS += \
./Prephiral/Src/adc1.o \
./Prephiral/Src/exti.o \
./Prephiral/Src/gpio.o \
./Prephiral/Src/pwr.o \
./Prephiral/Src/rcc.o \
./Prephiral/Src/spi.o \
./Prephiral/Src/timer.o \
./Prephiral/Src/uart.o 

C_DEPS += \
./Prephiral/Src/adc1.d \
./Prephiral/Src/exti.d \
./Prephiral/Src/gpio.d \
./Prephiral/Src/pwr.d \
./Prephiral/Src/rcc.d \
./Prephiral/Src/spi.d \
./Prephiral/Src/timer.d \
./Prephiral/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Prephiral/Src/adc1.o: ../Prephiral/Src/adc1.c Prephiral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Src/adc1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Prephiral/Src/exti.o: ../Prephiral/Src/exti.c Prephiral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Src/exti.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Prephiral/Src/gpio.o: ../Prephiral/Src/gpio.c Prephiral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Src/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Prephiral/Src/pwr.o: ../Prephiral/Src/pwr.c Prephiral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Src/pwr.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Prephiral/Src/rcc.o: ../Prephiral/Src/rcc.c Prephiral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Src/rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Prephiral/Src/spi.o: ../Prephiral/Src/spi.c Prephiral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Src/spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Prephiral/Src/timer.o: ../Prephiral/Src/timer.c Prephiral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Src/timer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Prephiral/Src/uart.o: ../Prephiral/Src/uart.c Prephiral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -DSTM32F411E_DISCO -c -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Core/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Prephiral/Inc" -I"/home/thanh/STM32CubeIDE/workspace_1.6.1/STM32_LV1/Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Prephiral/Src/uart.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

