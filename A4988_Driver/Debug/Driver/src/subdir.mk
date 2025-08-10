################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/src/stm32f446xx_GPIO_driver.c \
../Driver/src/stm32f446xx_Timer_driver.c 

OBJS += \
./Driver/src/stm32f446xx_GPIO_driver.o \
./Driver/src/stm32f446xx_Timer_driver.o 

C_DEPS += \
./Driver/src/stm32f446xx_GPIO_driver.d \
./Driver/src/stm32f446xx_Timer_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/src/%.o Driver/src/%.su Driver/src/%.cyclo: ../Driver/src/%.c Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -c -I"C:/Users/Phuri/STM32CubeIDE/A4988_Stepper/A4988_Driver/Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver-2f-src

clean-Driver-2f-src:
	-$(RM) ./Driver/src/stm32f446xx_GPIO_driver.cyclo ./Driver/src/stm32f446xx_GPIO_driver.d ./Driver/src/stm32f446xx_GPIO_driver.o ./Driver/src/stm32f446xx_GPIO_driver.su ./Driver/src/stm32f446xx_Timer_driver.cyclo ./Driver/src/stm32f446xx_Timer_driver.d ./Driver/src/stm32f446xx_Timer_driver.o ./Driver/src/stm32f446xx_Timer_driver.su

.PHONY: clean-Driver-2f-src

