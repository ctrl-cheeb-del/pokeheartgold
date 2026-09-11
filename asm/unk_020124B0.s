	.include "asm/macros.inc"
	.public _020124DC
	.public _020124F6
	.public _02012520
	.public _02012548
	.public _0201255A
	.public _0201258A
	.public _0201259C
	.public _020125C4
	.public _020125D0
	.public _02012644
	.public _02012660
	.public _02012680
	.public _02012684
	.public _02012688
	.public _02012750
	.public _02012754
	.public _02012758
	.public _02012798
	.public _020127A6
	.public _020127AC
	.public _020127B0
	.public sub_020124B0
	.public sub_020125D4
	.public sub_020125EC
	.public sub_0201262C
	.public sub_0201268C
	.public sub_0201275C
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	.public sub_020125D4
	.public sub_020125EC
	.public sub_0201262C
	.public sub_0201275C
	thumb_func_start sub_020124B0
sub_020124B0: ; 0x020124B0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r0, [sp]
	ldr r0, [r0, #0xc]
	ldr r1, _020125D0 ; =0x00003FFF
	bl _s32_div_f
	lsl r0, r1, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	ldr r0, [sp]
	mov r1, #0
	bl sub_02010EE0
	add r7, r0, #0
	ldr r0, [sp]
	mov r1, #1
	bl sub_02010EE0
	add r4, r0, #0
	mov r6, #0
	add r5, r4, #0
_020124DC:
	ldr r0, [sp]
	ldr r1, [r0, #0xc]
	ldr r0, _020125D0 ; =0x00003FFF
	cmp r1, r0
	bge _02012520
	mov r1, #0x60
	ldr r0, [sp, #4]
	sub r1, r1, r6
	bl sub_020109D8
	cmp r0, #0x7f
	ble _020124F6
	mov r0, #0x7f
_020124F6:
	mov r1, #0xbf
	sub r1, r1, r6
	lsl r1, r1, #1
	add r3, r7, r1
	mov r1, #0x80
	sub r2, r1, r0
	mov r1, #3
	lsl r1, r1, #8
	strh r2, [r3, r1]
	mov r1, #0x12
	mov r2, #0x80
	lsl r1, r1, #6
	strh r2, [r3, r1]
	mov r1, #3
	lsl r1, r1, #8
	strh r2, [r5, r1]
	mov r1, #0x12
	add r0, #0x80
	lsl r1, r1, #6
	strh r0, [r5, r1]
	b _02012548
_02012520:
	mov r0, #0xbf
	sub r0, r0, r6
	lsl r0, r0, #1
	mov r1, #3
	add r0, r7, r0
	mov r2, #0
	lsl r1, r1, #8
	strh r2, [r0, r1]
	mov r1, #0x12
	mov r2, #0x80
	lsl r1, r1, #6
	strh r2, [r0, r1]
	mov r0, #3
	add r1, r2, #0
	lsl r0, r0, #8
	strh r1, [r5, r0]
	mov r0, #0x12
	mov r1, #0xff
	lsl r0, r0, #6
	strh r1, [r5, r0]
_02012548:
	add r6, r6, #1
	add r5, r5, #2
	cmp r6, #0x60
	blt _020124DC
	ldr r1, _020125D0 ; =0x00003FFF
	ldr r0, [sp, #4]
	mov r5, #0x60
	add r4, #0xc0
	sub r6, r1, r0
_0201255A:
	ldr r0, [sp]
	ldr r1, [r0, #0xc]
	ldr r0, _020125D0 ; =0x00003FFF
	cmp r1, r0
	bge _0201258A
	mov r0, #0xbf
	sub r0, r0, r5
	lsl r0, r0, #1
	mov r1, #3
	add r0, r7, r0
	mov r2, #0x80
	lsl r1, r1, #8
	strh r2, [r0, r1]
	mov r1, #0x12
	lsl r1, r1, #6
	strh r2, [r0, r1]
	mov r0, #3
	add r1, r2, #0
	lsl r0, r0, #8
	strh r1, [r4, r0]
	mov r0, #0x12
	lsl r0, r0, #6
	strh r1, [r4, r0]
	b _020125C4
_0201258A:
	add r1, r5, #0
	add r0, r6, #0
	sub r1, #0x60
	bl sub_020109D8
	add r1, r0, #0
	cmp r1, #0x7f
	ble _0201259C
	mov r1, #0x7f
_0201259C:
	mov r0, #0xbf
	sub r0, r0, r5
	lsl r0, r0, #1
	mov r2, #3
	add r0, r7, r0
	mov r3, #0
	lsl r2, r2, #8
	strh r3, [r0, r2]
	mov r2, #0x80
	sub r3, r2, r1
	mov r2, #0x12
	lsl r2, r2, #6
	strh r3, [r0, r2]
	mov r0, #3
	add r1, #0x80
	lsl r0, r0, #8
	strh r1, [r4, r0]
	mov r1, #0xff
	add r0, r2, #0
	strh r1, [r4, r0]
_020125C4:
	add r5, r5, #1
	add r4, r4, #2
	cmp r5, #0xc0
	blt _0201255A
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_020125D0: .word 0x00003FFF
	thumb_func_end sub_020124B0
