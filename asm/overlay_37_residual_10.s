	.include "asm/macros.inc"
	.include "overlay_37.inc"
	.include "global.inc"

	.text
	.public _021E7968
	.public ov37_021E5900
	.public ov37_021E5A84
	.public ov37_021E5B94
	.public ov37_021E5CC8
	.public ov37_021E5CF0
	.public ov37_021E5D10
	.public ov37_021E5E30
	.public ov37_021E5F98
	.public ov37_021E6090
	.public ov37_021E60C0
	.public ov37_021E6244
	.public ov37_021E6418
	.public ov37_021E657C
	.public ov37_021E65EC
	.public ov37_021E69DC
	.public ov37_021E6B64
	.public ov37_021E6D14
	.public ov37_021E6F5C
	.public ov37_021E6FC8
	.public ov37_021E70BC
	.public ov37_021E713C
	.public ov37_021E72B4
	.public ov37_021E72E8
	.public ov37_021E73B4
	.public ov37_021E741C
	.public ov37_021E7478
	.public ov37_021E755C
	.public ov37_021E762C
	.public ov37_021E76F0
	.public ov37_021E78E0
	.public ov37_021E7970
	.public ov37_021E7978
	.public ov37_021E7988
	.public ov37_021E7998
	.public ov37_021E79B4
	.public ov37_021E79D0
	.public ov37_021E79EC
	.public ov37_021E7A08
	.public ov37_021E7A24
	.public ov37_021E7A4C
	.public ov37_021E7A80
	.public ov37_021E7AC8
	.public ov37_021E7D20

	.public ov37_021E5F20
	.public ov37_021E5F5C
	.public ov37_021E6540
	.public ov37_021E6818
	.public ov37_021E6848
	.public ov37_021E6860
	.public ov37_021E68AC
	.public ov37_021E68D0
	.public ov37_021E6928
	.public ov37_021E694C
	.public ov37_021E6980
	.public ov37_021E6B40
	.public ov37_021E6BFC
	.public ov37_021E6C38
	.public ov37_021E6C58
	.public ov37_021E6C84
	.public ov37_021E6CC0
	.public ov37_021E6DD0
	.public ov37_021E6E04
	.public ov37_021E6E2C
	.public ov37_021E6E6C
	.public ov37_021E6E70
	.public ov37_021E6E90
	.public ov37_021E6EB4
	.public ov37_021E6F14
	.public ov37_021E745C
	.public ov37_021E75C4
	.public ov37_021E75E0
	.public ov37_021E75E8
	.public ov37_021E76A0
	.public ov37_021E76C0
	.public ov37_021E76D0
	.public ov37_021E7844
	.public ov37_021E784C
	.public ov37_021E7880
	.public ov37_021E78A4
	.public ov37_021E78C4

	thumb_func_start ov37_021E76F0
ov37_021E76F0: ; 0x021E76F0
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bl ov37_021E75C4
	add r5, r0, #0
	cmp r5, #5
	bhi _021E778E
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E770A: ; jump table
	.short _021E778E - _021E770A - 2 ; case 0
	.short _021E7716 - _021E770A - 2 ; case 1
	.short _021E775C - _021E770A - 2 ; case 2
	.short _021E775C - _021E770A - 2 ; case 3
	.short _021E775C - _021E770A - 2 ; case 4
	.short _021E7788 - _021E770A - 2 ; case 5
_021E7716:
	mov r0, #0xc1
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0xe
	bgt _021E778E
	bl sub_02033250
	cmp r0, #1
	beq _021E7730
	mov r0, #0x25
	mov r1, #1
	lsl r0, r0, #0xa
	str r1, [r4, r0]
_021E7730:
	mov r0, #0xc2
	mov r1, #0x13
	lsl r0, r0, #2
	str r1, [r4, r0]
	mov r0, #1
	bl sub_02038C1C
	ldr r0, _021E7830 ; =0x000093F8
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021E7758
	add r0, r4, #0
	bl ov37_021E78A4
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x15
	bl Sprite_SetAnimCtrlSeq
_021E7758:
	mov r0, #2
	pop {r3, r4, r5, pc}
_021E775C:
	mov r0, #1
	bl sub_0205A904
	mov r0, #0xc5
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r5, r0
	bge _021E778E
	ldr r0, _021E7834 ; =0x000093F4
	ldr r0, [r4, r0]
	cmp r0, #2
	bne _021E777E
	add r0, r4, #0
	mov r1, #0
	bl ov37_021E76D0
	b _021E778E
_021E777E:
	add r0, r4, #0
	mov r1, #1
	bl ov37_021E76D0
	b _021E778E
_021E7788:
	mov r0, #8
	bl sub_0205A904
_021E778E:
	mov r0, #0xc5
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r5, r0
	bge _021E77D8
	bl sub_02037454
	mov r1, #0xc6
	lsl r1, r1, #2
	str r0, [r4, r1]
	bl sub_02033250
	mov r1, #0xc7
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, _021E7838 ; =0x00009404
	ldr r2, [r4, r0]
	cmp r2, #0
	beq _021E77D8
	add r0, r0, #4
	ldr r1, [r4, r1]
	ldr r0, [r4, r0]
	tst r0, r1
	bne _021E77D8
	add r0, r4, #0
	mov r1, #1
	bl ov37_021E76D0
	ldr r1, _021E7834 ; =0x000093F4
	mov r0, #1
	str r0, [r4, r1]
	add r0, r1, #0
	mov r2, #0
	add r0, #0x10
	str r2, [r4, r0]
	add r1, #0x14
	str r2, [r4, r1]
_021E77D8:
	bl ov37_021E75C4
	mov r1, #0xc5
	lsl r1, r1, #2
	str r0, [r4, r1]
	bl sub_02037454
	mov r1, #0xc6
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	cmp r1, r0
	bge _021E782C
	ldr r0, _021E7834 ; =0x000093F4
	mov r1, #2
	str r1, [r4, r0]
	mov r1, #1
	add r0, #0x10
	str r1, [r4, r0]
	bl sub_02033250
	mov r1, #0xc7
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	eor r0, r1
	ldr r1, _021E783C ; =0x00009408
	str r0, [r4, r1]
	ldr r1, [r4, r1]
	mov r0, #0
	sub r1, r1, #2
	cmp r1, #0xe
	bhi _021E7824
	mov r2, #1
	add r3, r2, #0
	lsl r3, r1
	ldr r1, _021E7840 ; =0x00004045
	tst r1, r3
	beq _021E7824
	add r0, r2, #0
_021E7824:
	cmp r0, #0
	bne _021E782C
	bl GF_AssertFail
_021E782C:
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E7830: .word 0x000093F8
_021E7834: .word 0x000093F4
_021E7838: .word 0x00009404
_021E783C: .word 0x00009408
_021E7840: .word 0x00004045
	thumb_func_end ov37_021E76F0
