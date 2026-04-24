OBJDIR = obj
COMMONDIR = ../common

COMMON_OBJS := $(wildcard $(COMMONDIR)/obj/*.o)

CC 	= arm-none-linux-gnueabihf-gcc
AS      = arm-none-linux-gnueabihf-as
LD      = arm-none-linux-gnueabihf-ld
OBJCOPY = arm-none-linux-gnueabihf-objcopy
OBJDUMP = arm-none-linux-gnueabihf-objdump

LOAD_ADDR = 0x402F0400
CFLAGS   = -mcpu=cortex-a8 -nostdlib -nostartfiles -Wall -Wextra
ASFLAGS   = -mcpu=cortex-a8

.PHONY: all clean disasm

all: $(OBJDIR) MLO

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/mlo_blink.o: mlo_blink.c
	$(CC) $(CFLAGS) -I$(COMMONDIR) -c $< -o $@

$(OBJDIR)/startup.o: startup.s
	$(AS) $(ASFLAGS) $< -o $@

mlo_blink.elf: $(OBJDIR)/startup.o $(OBJDIR)/mlo_blink.o $(COMMON_OBJS) # order matters
	$(LD) -T linker.ld $^ -o $@

mlo_blink.bin: mlo_blink.elf
	$(OBJCOPY) -O binary $< $@

MLO: mlo_blink.bin mkheader.py
	python3 mkheader.py $< $@
	@echo ""
	@echo "==> MLO ready. Copy to FAT-formatted SD card boot partition."

disasm: mlo_blink.elf
	$(OBJDUMP) -d $<

clean:
	rm -rf obj mlo_blink.elf mlo_blink.bin MLO 
