MEMORY {
	SRAM (rwx) : ORIGIN = 0x402F0400, LENGTH = 128K
}

SECTIONS
{
    . = 0x402F0400;

    .text :
    {
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
    } > SRAM

    .data :
    {
        *(.data)
        *(.data.*)
    } > SRAM

    .bss :
    {
        *(.bss)
        *(.bss.*)
        *(COMMON)
    } > SRAM

    . = ALIGN(4);
    _end = .;
}
