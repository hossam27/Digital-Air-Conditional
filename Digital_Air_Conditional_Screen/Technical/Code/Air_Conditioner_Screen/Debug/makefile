################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/EEPROM/subdir.mk
-include MCAL/DIO/subdir.mk
-include BSW/lcd/subdir.mk
-include BSW/Switch/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Air_Conditioner_Screen.lss \

FLASH_IMAGE += \
Air_Conditioner_Screen.hex \

EEPROM_IMAGE += \
Air_Conditioner_Screen.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Air_Conditioner_Screen.elf secondary-outputs

# Tool invocations
Air_Conditioner_Screen.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Air_Conditioner_Screen.map -mmcu=atmega32 -o "Air_Conditioner_Screen.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Air_Conditioner_Screen.lss: Air_Conditioner_Screen.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Air_Conditioner_Screen.elf  >"Air_Conditioner_Screen.lss"
	@echo 'Finished building: $@'
	@echo ' '

Air_Conditioner_Screen.hex: Air_Conditioner_Screen.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Air_Conditioner_Screen.elf  "Air_Conditioner_Screen.hex"
	@echo 'Finished building: $@'
	@echo ' '

Air_Conditioner_Screen.eep: Air_Conditioner_Screen.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Air_Conditioner_Screen.elf  "Air_Conditioner_Screen.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Air_Conditioner_Screen.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Air_Conditioner_Screen.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Air_Conditioner_Screen.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
