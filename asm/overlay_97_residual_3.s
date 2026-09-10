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

	thumb_func_start ov97_0221E898
ov97_0221E898: ; 0x0221E898
	push {r3, r4, r5, lr}
	add r5, r3, #0
	bl PCStorage_GetMonByIndexPair
	mov r1, #0xac
	mov r2, #0
	add r4, r0, #0
	bl GetBoxMonData
	cmp r0, #0
	beq _0221E908
	add r0, r4, #0
	mov r1, #5
	mov r2, #0
	bl GetBoxMonData
	mov r1, #0
	str r0, [r5]
	add r0, r4, #0
	add r2, r1, #0
	bl GetBoxMonData
	str r0, [r5, #4]
	add r0, r4, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetBoxMonData
	strh r0, [r5, #8]
	add r0, r4, #0
	mov r1, #0x70
	mov r2, #0
	bl GetBoxMonData
	strh r0, [r5, #0xa]
	mov r0, #0
	strh r0, [r5, #0xc]
	add r2, r5, #0
	strh r0, [r5, #0xe]
	add r0, r4, #0
	mov r1, #0x75
	add r2, #0x18
	bl GetBoxMonData
	add r0, r4, #0
	bl BoxMonIsShiny
	strh r0, [r5, #0x10]
	add r0, r4, #0
	mov r1, #0x6f
	mov r2, #0
	bl GetBoxMonData
	strh r0, [r5, #0x12]
	mov r0, #1
	pop {r3, r4, r5, pc}
_0221E908:
	mov r0, #0
	str r0, [r5]
	str r0, [r5, #4]
	strh r0, [r5, #8]
	strh r0, [r5, #0xa]
	strh r0, [r5, #0xc]
	strh r0, [r5, #0xe]
	strh r0, [r5, #0x10]
	strh r0, [r5, #0x12]
	pop {r3, r4, r5, pc}
	thumb_func_end ov97_0221E898


	thumb_func_start ov97_0221E91C
ov97_0221E91C: ; 0x0221E91C
	push {r3, r4, r5, lr}
	add r4, r3, #0
	bl PCStorage_GetMonByIndexPair
	mov r1, #0xac
	mov r2, #0
	add r5, r0, #0
	bl GetBoxMonData
	cmp r0, #0
	beq _0221E966
	add r0, r5, #0
	mov r1, #5
	mov r2, #0
	bl GetBoxMonData
	str r0, [r4]
	mov r2, #0
	str r2, [r4, #4]
	add r0, r5, #0
	mov r1, #0x4c
	bl GetBoxMonData
	strh r0, [r4, #8]
	add r0, r5, #0
	mov r1, #0x70
	mov r2, #0
	bl GetBoxMonData
	strh r0, [r4, #0xa]
	mov r0, #0
	strh r0, [r4, #0xc]
	strh r0, [r4, #0xe]
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	mov r0, #1
	pop {r3, r4, r5, pc}
_0221E966:
	mov r0, #0
	str r0, [r4]
	str r0, [r4, #4]
	strh r0, [r4, #8]
	strh r0, [r4, #0xa]
	strh r0, [r4, #0xc]
	strh r0, [r4, #0xe]
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov97_0221E91C
