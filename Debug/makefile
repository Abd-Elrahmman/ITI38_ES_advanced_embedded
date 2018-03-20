################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
day3-watch-uart.lss \

FLASH_IMAGE += \
day3-watch-uart.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: day3-watch-uart.elf secondary-outputs

# Tool invocations
day3-watch-uart.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,day3-watch-uart.map -mmcu=atmega32 -o "day3-watch-uart.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

day3-watch-uart.lss: day3-watch-uart.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S day3-watch-uart.elf  >"day3-watch-uart.lss"
	@echo 'Finished building: $@'
	@echo ' '

day3-watch-uart.hex: day3-watch-uart.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex day3-watch-uart.elf  "day3-watch-uart.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: day3-watch-uart.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 day3-watch-uart.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: day3-watch-uart.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:day3-watch-uart.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) day3-watch-uart.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
