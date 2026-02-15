################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../i2c_oled/src/i2c.c 

OBJS += \
./i2c_oled/src/i2c.o 

C_DEPS += \
./i2c_oled/src/i2c.d 


# Each subdirectory must supply rules for building sources it contributes
i2c_oled/src/%.o i2c_oled/src/%.su i2c_oled/src/%.cyclo: ../i2c_oled/src/%.c i2c_oled/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"/home/arjunm/STM32_MCU/stm32f4xx_drivers/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-i2c_oled-2f-src

clean-i2c_oled-2f-src:
	-$(RM) ./i2c_oled/src/i2c.cyclo ./i2c_oled/src/i2c.d ./i2c_oled/src/i2c.o ./i2c_oled/src/i2c.su

.PHONY: clean-i2c_oled-2f-src

