	.include "asm/macros.inc"

	.rodata
	.balign 4, 0

	.public Frontier_Init
	.public Frontier_Main
	.public Frontier_Exit
	.public gOverlayTemplate_Frontier
gOverlayTemplate_Frontier:
	.word Frontier_Init, Frontier_Main, Frontier_Exit, 0xFFFFFFFF
