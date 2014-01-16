###
### Project settings
###

# the projects name
export PROJECT = moodlight

# define the cpu that is used in the project
# [ stm32f0 | stm32f3 | stm32f4 ]
export MCU ?= stm32f0

# serial port for debugging
export PORT ?= /dev/ttyUSB0


###
### Paths and environment
### 
export PRJDIR = $(CURDIR)
export BINDIR = $(PRJDIR)/bin
export SRCDIR = $(PRJDIR)/src
export BOOTDIR = $(PRJDIR)/boot
export INCLUDES = -I$(PRJDIR)/include

#export LINKERSCRIPT = $(BOOTDIR)/STM32F303VC_FLASH.ld
export STARTUPFILE = $(BOOTDIR)/stm32f0_startup.s
export SYSCALLS = $(BOOTDIR)/$(MCU)_syscalls.c

# stm lib config
export STM_LIB_BASE = $(PRJDIR)/lib/$(MCU)_stdperiph_lib
include $(STM_LIB_BASE)/Makefile.include

# check if all needed information was provided from stm-lib included Makefile
ifeq ($(LINKERSCRIPT),)
  $(error No linkerscript defined, define variable LINKERSCRIPT)
endif
ifeq ($(STARTUPFILE),)
  $(error No startup file defined, define varialbe STARTUPFILE)
endif
ifeq ($(SYSINITFILE),)
  $(error No system init file defined, please define SYSINITFILE)
endif
ifdef ($(CPUOPT),)
  $(error No cpu options defined by lib makefile, please define CPUOPT cpu options (-mcpu, -mfloat-abi, -mfpu)
endif

###
### Compiler and toolchain options
###
# compiler prefix
export PREFIX = @arm-none-eabi-
#export PREFIX = /home/hauke/tools/codesourcery_2013.11/bin/arm-none-eabi-
# tools
export CC = $(PREFIX)gcc
export AR = $(PREFIX)ar
export AS = $(PREFIX)as
export LINK = $(PREFIX)gcc
export SIZE = $(PREFIX)size
export OBJCOPY = $(PREFIX)objcopy
export MAKE = make
export FLASHER = st-flash
export TERMPROG = minicom
# flags
OPTIMIZATION = -O0
#CPUOPT = -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16  --> to be defined in the STM_LIB/Makefile.include
#STMFLAGS = -DUSE_STDPERIPH_DRIVER -DSTM32F30X  --> to be defined in the STM_LIB/Makefile.include
export CFLAGS = -ggdb -g3 $(OPTIMIZATION) -std=gnu99 -Wall -Wstrict-prototypes $(CPUOPT) -mlittle-endian -mthumb -mthumb-interwork -nostartfiles $(STMFLAGS)
export ASFLAGS = -ggdb -g3 $(CPUOPT) -mlittle-endian
export LINKFLAGS = -ggdb -g3 -std=gnu99 $(CPUOPT) -mlittle-endian -static -lgcc -mthumb -mthumb-interwork -nostartfiles -T$(LINKERSCRIPT)
export LINKFLAGS += -specs=nano.specs -lc -lnosys	# use newlib nano
export FFLAGS = write $(BINDIR)/$(PROJECT).bin 0x8000000
export TERMFLAGS = -b115200 -D$(PORT) -w



###
### Environment setup
###
export MODULES = $(STM_LIB_BINARY) $(BINDIR)/$(PROJECT).a

# collect source and object files for the project binary
SRC = $(wildcard $(SRCDIR)/*.c) 
#SRC := $(shell find $(SRCDIR) -name '*.c')
OBJ := $(SRC:$(SRCDIR)/%.c=$(BINDIR)/%.o) 
OBJ += $(BINDIR)/startup.o $(BINDIR)/syscalls.o $(BINDIR)/sysinit.o

###
### Print compile options and targets
###
$(info #####################################################)
$(info # Now compiling $(BINDIR)/$(PROJECT).bin)
$(info #----------------------------------------------------)
$(info # Target:       $(MCU))
$(info # Linkerscript: $(LINKERSCRIPT))
$(info # Startupfile:  $(STARTUPFILE))
$(info # Systeminit:   $(SYSINITFILE))
$(info #####################################################)

###
### Target definitions
###

.PHONY: all flash clean

# build the project
all: $(BINDIR)/$(PROJECT).hex $(BINDIR)/$(PROJECT).bin $(BINDIR)/$(PROJECT).elf
	@$(SIZE) $(BINDIR)/$(PROJECT).elf

# flash project using the stlink v2 via st-flash
flash: $(BINDIR)/$(PROJECT).bin
	$(FLASHER) $(FFLAGS)

# open terminal to the connected device
term: 
	$(info [TERMINAL]  $(PORT))
	$(TERMPROG) $(TERMFLAGS)

# clean the project build files
clean:
	$(info [CLEANING]  $(BINDIR))
	@rm -r -f $(BINDIR)

clean-stmlib:
	$(info [CLEANING]  $(STM_LIB_BINDIR))
	@$(MAKE) -s -C $(STM_LIB_BASE) clean

# clean everything
clean-all: clean clean-stlib


###
### Sub-targets
###

$(BINDIR)/$(PROJECT).hex: $(BINDIR)/$(PROJECT).elf
	$(info [OBJCOPY]   $(BINDIR)/$(PROJECT).hex)
	$(OBJCOPY) -O ihex $(BINDIR)/$(PROJECT).elf $(BINDIR)/$(PROJECT).hex

$(BINDIR)/$(PROJECT).bin: $(BINDIR)/$(PROJECT).elf
	$(info [OBJCOPY]   $(BINDIR)/$(PROJECT).bin)
	$(OBJCOPY) -O binary $(BINDIR)/$(PROJECT).elf $(BINDIR)/$(PROJECT).bin

$(BINDIR)/$(PROJECT).elf: $(MODULES)
	$(info [LINKING]   $(BINDIR)/$(PROJECT).elf)
	$(LINK) -o $(BINDIR)/$(PROJECT).elf -Wl,--start-group $(MODULES) -lm -Wl,--end-group -Wl,-Map=$(BINDIR)/$(PROJECT).map $(LINKFLAGS)

$(BINDIR)/$(PROJECT).a: $(OBJ)
	$(info [BUILDING]  $@)
	$(AR) -rc $(BINDIR)/$(PROJECT).a $(OBJ)

$(BINDIR)/%.o: $(SRCDIR)/%.c 
	$(info [COMPILING] $@)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

$(BINDIR)/startup.o: $(STARTUPFILE)
	$(info [ASSEMBLY]  $@)
	@mkdir -p $(BINDIR)
	$(AS) $(ASFLAGS) $^ -o $@

$(BINDIR)/syscalls.o: $(SYSCALLS)
	$(info [COMPILING] $@)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

$(BINDIR)/sysinit.o: $(SYSINITFILE)
	$(info [COMPILING] $@)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

$(STM_LIB_BINARY):
	$(info [BUILDING]  $@)
	@$(MAKE) -s -C $(STM_LIB_BASE)
	
