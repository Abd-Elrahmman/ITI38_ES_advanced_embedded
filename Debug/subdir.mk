################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Clock_adjust.c \
../DIO_prog.c \
../OS.c \
../OS_cfg.c \
../TIM_prog.c \
../UART.c \
../UART_Rx_TEST.c \
../UART_cfg.c \
../keypad.c \
../main.c \
../protocol.c \
../sw.c \
../task1.c \
../task2.c \
../taskSwitchLed.c 

OBJS += \
./Clock_adjust.o \
./DIO_prog.o \
./OS.o \
./OS_cfg.o \
./TIM_prog.o \
./UART.o \
./UART_Rx_TEST.o \
./UART_cfg.o \
./keypad.o \
./main.o \
./protocol.o \
./sw.o \
./task1.o \
./task2.o \
./taskSwitchLed.o 

C_DEPS += \
./Clock_adjust.d \
./DIO_prog.d \
./OS.d \
./OS_cfg.d \
./TIM_prog.d \
./UART.d \
./UART_Rx_TEST.d \
./UART_cfg.d \
./keypad.d \
./main.d \
./protocol.d \
./sw.d \
./task1.d \
./task2.d \
./taskSwitchLed.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


