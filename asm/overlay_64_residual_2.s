	.include "asm/macros.inc"
	.include "overlay_64.inc"
	.include "global.inc"
	.public HallOfFameShowcase_Init
	.public HallOfFameShowcase_Main
	.public _021E6E7C
	.public ov64_021E5B10
	.public ov64_021E5CD0
	.public ov64_021E607C
	.public ov64_021E6170
	.public ov64_021E62C8
	.public ov64_021E652C
	.public ov64_021E677C
	.public ov64_021E6B84
	.public ov64_021E6C1C
	.public ov64_021E6E88
	.public ov64_021E6E98
	.public ov64_021E6EA8
	.public ov64_021E6EB8
	.public ov64_021E6ECC
	.public ov64_021E6ECE
	.public ov64_021E6EE4
	.public ov64_021E6EFC
	.public ov64_021E6F18
	.public ov64_021E6F34
	.public ov64_021E6F50
	.public ov64_021E6F6C
	.public ov64_021E6F8C
	.public ov64_021E6FAC
	.public ov64_021E6FD4
	.public ov64_021E7008
	.public ov64_021E7040
	.public ov64_021E70C8
	.public ov64_021E70FC
	.public ov64_021E73A0
	.public ov64_021E73D4
	.public ov64_021E7408
	.public ov64_021E743C


	.text
	.public HallOfFameShowcase_Exit
	.public ov64_021E5A88
	.public ov64_021E5AAC
	.public ov64_021E5AC8
	.public ov64_021E5AE4
	.public ov64_021E5B00
	.public ov64_021E5CA4
	.public ov64_021E6010
	.public ov64_021E602C
	.public ov64_021E605C
	.public ov64_021E6118
	.public ov64_021E620C
	.public ov64_021E622C
	.public ov64_021E6260
	.public ov64_021E6270
	.public ov64_021E6274
	.public ov64_021E6278
	.public ov64_021E6280
	.public ov64_021E6288
	.public ov64_021E62A8
	.public ov64_021E64F8
	.public ov64_021E6754
	.public ov64_021E6BD8
	.public ov64_021E6E30

	thumb_func_start HallOfFameShowcase_Main
HallOfFameShowcase_Main: ; 0x021E5A18
	push {r3, r4, r5, lr}
	add r4, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r4]
	add r5, r0, #0
	cmp r1, #3
	bhi _021E5A74
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E5A34: ; jump table
	.short _021E5A3C - _021E5A34 - 2 ; case 0
	.short _021E5A48 - _021E5A34 - 2 ; case 1
	.short _021E5A58 - _021E5A34 - 2 ; case 2
	.short _021E5A68 - _021E5A34 - 2 ; case 3
_021E5A3C:
	bl ov64_021E6288
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E5A74
_021E5A48:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021E5A74
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E5A74
_021E5A58:
	bl ov64_021E62C8
	cmp r0, #0
	bne _021E5A74
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E5A74
_021E5A68:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021E5A74
	mov r0, #1
	pop {r3, r4, r5, pc}
_021E5A74:
	add r0, r5, #0
	bl ov64_021E605C
	mov r0, #0x4d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteSystem_DrawSprites
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end HallOfFameShowcase_Main
