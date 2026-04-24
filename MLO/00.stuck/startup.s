.section .text
.global _start

_start:
	/*
	* Use the top of the public stack region.
	* Public stack: 0x4030B800 -> 0x4030CE00 (6KB)
	* SP starts at top and grows downward.
	*/
	ldr sp, =0x4030CE00
	bl main

hang:
	b hang

@specifies no executable stack is required to the linker
.section .note.GNU-stack, "", %progbits

