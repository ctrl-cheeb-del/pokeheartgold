	.include "asm/macros.inc"
	.include "overlay_97.inc"
	.include "global.inc"

	.text
	.public _0221FC98
	.public ov97_0221E5D4
	.public ov97_0221E700
	.public ov97_0221E898
	.public ov97_0221E91C
	.public ov97_0221E98C
	.public ov97_0221EA88
	.public ov97_0221EB38
	.public ov97_0221EC14
	.public ov97_0221EDE4
	.public ov97_0221EEA4
	.public ov97_0221EFD0
	.public ov97_0221F020
	.public ov97_0221F0E0
	.public ov97_0221F14C
	.public ov97_0221F1D8
	.public ov97_0221F294
	.public ov97_0221F428
	.public ov97_0221F56C
	.public ov97_0221F5F8
	.public ov97_0221F74C
	.public ov97_0221F7DC
	.public ov97_0221F9E0
	.public ov97_0221FAEC
	.public ov97_0221FBDC
	.public ov97_0221FCA8
	.public ov97_0221FCB8
	.public ov97_0221FCCC
	.public ov97_0221FCF4
	.public ov97_0221FCFC
	.public ov97_0221FD04
	.public ov97_0221FD20
	.public ov97_0221FD3C
	.public ov97_0221FD58
	.public ov97_0221E5C0
	.public ov97_0221E69C
	.public ov97_0221E6DC
	.public ov97_0221E7F4
	.public ov97_0221E814
	.public ov97_0221E834
	.public ov97_0221E864
	.public ov97_0221E88C
	.public ov97_0221E97C
	.public ov97_0221EBD8
	.public ov97_0221EE84
	.public ov97_0221F010
	.public ov97_0221FB80
	.public ov97_0221FBA0
	.public ov97_0221FC54

	thumb_func_start ov97_0221E5D4
ov97_0221E5D4: ; 0x0221E5D4
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, [r4, #4]
	cmp r0, #5
	bhi _0221E68A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0221E5F2: ; jump table
	.short _0221E5FE - _0221E5F2 - 2 ; case 0
	.short _0221E604 - _0221E5F2 - 2 ; case 1
	.short _0221E620 - _0221E5F2 - 2 ; case 2
	.short _0221E62E - _0221E5F2 - 2 ; case 3
	.short _0221E650 - _0221E5F2 - 2 ; case 4
	.short _0221E66E - _0221E5F2 - 2 ; case 5
_0221E5FE:
	mov r0, #1
	str r0, [r4, #4]
	b _0221E68A
_0221E604:
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x5c
	str r0, [sp, #8]
	mov r0, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #2
	str r0, [r4, #4]
	b _0221E68A
_0221E620:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0221E68A
	mov r0, #3
	str r0, [r4, #4]
	b _0221E68A
_0221E62E:
	ldr r0, [r4, #8]
	bl sub_020935E0
	cmp r0, #2
	bne _0221E642
	mov r0, #0
	str r0, [r4, #0x28]
	mov r0, #4
	str r0, [r4, #4]
	b _0221E68A
_0221E642:
	cmp r0, #3
	bne _0221E68A
	mov r0, #1
	str r0, [r4, #0x28]
	mov r0, #4
	str r0, [r4, #4]
	b _0221E68A
_0221E650:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x5c
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #5
	str r0, [r4, #4]
	b _0221E68A
_0221E66E:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0221E68A
	add r0, r5, #0
	bl OverlayManager_GetArgs
	add r1, r0, #0
	add r0, r4, #0
	bl ov97_0221E98C
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, pc}
_0221E68A:
	ldr r0, [r4, #8]
	bl sub_02093A40
	ldr r0, [r4, #0xc]
	bl ov97_0221F010
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, pc}
	thumb_func_end ov97_0221E5D4
