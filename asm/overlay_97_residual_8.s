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

	thumb_func_start ov97_0221FBDC
ov97_0221FBDC: ; 0x0221FBDC
	push {r4, r5, lr}
	sub sp, #0x24
	add r5, r1, #0
	add r4, r0, #0
	ldrb r0, [r5, #6]
	mov r3, #2
	str r0, [sp]
	ldrb r0, [r5, #7]
	str r0, [sp, #4]
	ldr r0, [r5]
	str r0, [sp, #8]
	ldrh r1, [r5, #4]
	ldrb r2, [r5, #8]
	add r0, sp, #0x14
	bl GetMonSpriteCharAndPlttNarcIdsEx
	ldr r0, [r5]
	mov r3, #0x96
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldrh r0, [r5, #4]
	add r1, sp, #0x10
	lsl r3, r3, #2
	str r0, [sp, #0xc]
	ldrh r0, [r1, #4]
	ldrh r1, [r1, #6]
	ldr r2, [r4]
	ldr r3, [r4, r3]
	bl sub_02014540
	add r1, sp, #0x10
	ldrh r0, [r1, #4]
	ldrh r1, [r1, #8]
	ldr r2, [r4]
	bl AllocAndReadWholeNarcMemberByIdPair
	add r1, sp, #0x10
	add r5, r0, #0
	bl NNS_G2dGetUnpackedPaletteData
	cmp r0, #1
	beq _0221FC3A
	bl GF_AssertFail
_0221FC3A:
	ldr r0, [sp, #0x10]
	mov r1, #0x97
	lsl r1, r1, #2
	ldr r0, [r0, #0xc]
	add r1, r4, r1
	mov r2, #0x20
	bl MIi_CpuCopy16
	add r0, r5, #0
	bl Heap_Free
	add sp, #0x24
	pop {r4, r5, pc}
	thumb_func_end ov97_0221FBDC
