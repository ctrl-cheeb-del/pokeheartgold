	.include "asm/macros.inc"
	.include "overlay_80_02239BF0.inc"
	.include "global.inc"
	.public ov80_02239C80
	.public ov80_0223DB24


    .text
	.public ov80_02239BF0
	.public ov80_02239C28
	.public ov80_02239C54

	thumb_func_start ov80_02239C80
ov80_02239C80: ; 0x02239C80
	push {r4, r5, r6, lr}
	sub sp, #8
	add r6, r1, #0
	add r4, r6, #0
	add r4, #0x26
	bl sub_0209680C
	add r5, r0, #0
	mov r0, #6
	ldrsh r0, [r4, r0]
	cmp r0, #0
	ble _02239CA2
	sub r0, r0, #1
	strh r0, [r4, #6]
	add sp, #8
	mov r0, #0
	pop {r4, r5, r6, pc}
_02239CA2:
	ldrb r0, [r4, #1]
	cmp r0, #3
	bhi _02239D64
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02239CB4: ; jump table
	.short _02239CBC - _02239CB4 - 2 ; case 0
	.short _02239D22 - _02239CB4 - 2 ; case 1
	.short _02239D22 - _02239CB4 - 2 ; case 2
	.short _02239D22 - _02239CB4 - 2 ; case 3
_02239CBC:
	mov r0, #2
	ldrsh r1, [r4, r0]
	cmp r1, #3
	bhi _02239D0C
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02239CD0: ; jump table
	.short _02239CD8 - _02239CD0 - 2 ; case 0
	.short _02239CD8 - _02239CD0 - 2 ; case 1
	.short _02239CF0 - _02239CD0 - 2 ; case 2
	.short _02239CF0 - _02239CD0 - 2 ; case 3
_02239CD8:
	mov r1, #4
	ldrsh r1, [r4, r1]
	cmp r1, #0
	bne _02239CE8
	strh r0, [r4, #8]
	mov r0, #3
	strh r0, [r4, #0xa]
	b _02239D16
_02239CE8:
	mov r1, #3
	strh r1, [r4, #8]
	strh r0, [r4, #0xa]
	b _02239D16
_02239CF0:
	mov r0, #4
	ldrsh r0, [r4, r0]
	cmp r0, #0
	bne _02239D02
	mov r0, #0
	strh r0, [r4, #8]
	mov r0, #1
	strh r0, [r4, #0xa]
	b _02239D16
_02239D02:
	mov r0, #1
	strh r0, [r4, #8]
	mov r0, #0
	strh r0, [r4, #0xa]
	b _02239D16
_02239D0C:
	bl GF_AssertFail
	add sp, #8
	mov r0, #1
	pop {r4, r5, r6, pc}
_02239D16:
	mov r0, #2
	ldrsh r0, [r4, r0]
	strh r0, [r4, #0xc]
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
_02239D22:
	ldrb r3, [r4, #1]
	ldr r1, [r6]
	ldrh r2, [r6, #0xc]
	add r3, r3, #2
	lsl r3, r3, #1
	add r6, r4, r3
	mov r3, #2
	ldrsh r3, [r6, r3]
	add r0, sp, #0
	bl ov80_0222EFD0
	ldr r0, [r5, #0x30]
	add r1, sp, #0
	bl ov42_022299C0
	ldrb r1, [r4, #1]
	mov r0, #2
	ldrsh r2, [r4, r0]
	add r1, r1, #2
	lsl r1, r1, #1
	add r1, r4, r1
	ldrsh r0, [r1, r0]
	cmp r2, r0
	bne _02239D5A
	mov r0, #0x2d
	strh r0, [r4, #6]
	mov r0, #1
	b _02239D6A
_02239D5A:
	mov r0, #0x1e
	strh r0, [r4, #6]
	ldrb r0, [r4, #1]
	add r0, r0, #1
	b _02239D6A
_02239D64:
	add sp, #8
	mov r0, #1
	pop {r4, r5, r6, pc}
_02239D6A:
	strb r0, [r4, #1]
	mov r0, #0
	add sp, #8
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov80_02239C80

    .rodata

ov80_0223DB24: ; 0x0223DB24
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov80_02239C80
