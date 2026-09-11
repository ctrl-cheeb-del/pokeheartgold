	.include "asm/macros.inc"
	.include "overlay_113.inc"
	.include "asm/include/overlay_113_split.inc"
	.include "global.inc"

	.text
	.public UnownReport_Exit
	.public ov113_021E59F8
	.public ov113_021E5A48
	.public ov113_021E5B60
	.public ov113_021E5B70
	.public ov113_021E5BB0
	.public ov113_021E5C60
	.public ov113_021E5CF8
	.public ov113_021E5D28
	.public ov113_021E5D4C
	.public ov113_021E5EC4
	.public ov113_021E6274
	.public ov113_021E629C
	.public ov113_021E62E0
	.public ov113_021E64DC
	.public ov113_021E663C
	.public ov113_021E66E4
	.public ov113_021E6754
	.public ov113_021E6930
	.public ov113_021E6988
	.public ov113_021E69A8

	thumb_func_start ov113_021E62B0
ov113_021E62B0: ; 0x021E62B0
	push {r4, lr}
	add r4, r0, #0
	add r0, #0xac
	ldr r0, [r0]
	cmp r0, #0
	beq _021E62C0
	bl SpriteSystem_TransferOam
_021E62C0:
	bl GF_RunVramTransferTasks
	ldr r0, [r4, #0x40]
	bl DoScheduledBgGpuUpdates
	ldr r3, _021E62D8 ; =0x027E0000
	ldr r1, _021E62DC ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_021E62D8: .word 0x027E0000
_021E62DC: .word 0x00003FF8
	thumb_func_end ov113_021E62B0

