	.include "asm/macros.inc"
	.include "global.inc"

	.rodata
	.balign 4, 0
	.public sRomArchiveName
sRomArchiveName:
	.asciz "rom"
