	.include "asm/macros.inc"
	.include "unk_02033AE0.inc"
	.include "global.inc"

	.bss

	.public _021D412C
_021D412C:
	.space 0x4

	.rodata

	.public _020F692C
_020F692C:
	.byte 0x01, 0x01, 0x01, 0x01
	.byte 0x03, 0x03, 0x03, 0x04, 0x03, 0x04, 0x07, 0x03, 0x07, 0x04, 0x01, 0x04, 0x01, 0x01, 0x04, 0x01
	.byte 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x04, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x03, 0x01, 0x03
	.byte 0x00, 0x01, 0x01, 0x01, 0x03
	.public _020F6955
_020F6955:
	.byte 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00
	.public _020F6980
_020F6980:
	.word 0, sub_020342C0, 0
	.word 0, sub_020342C0, 0
	.word sub_0203776C, sub_020342C0, 0
	.word sub_020345D0, sub_02034520, 0
	.word sub_0203453C, sub_02034520, 0
	.word sub_02034524, sub_020342C0, 0
	.word sub_02038B3C, sub_02038C18, 0
	.word sub_02038B9C, sub_02038C18, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word sub_02037618, sub_020342C4, 0
	.word sub_02037640, sub_020342C4, 0
	.word sub_02037668, sub_020342C4, 0
	.word sub_020342CC, sub_020342C0, 0
	.word sub_02034310, sub_020342C0, 0
	.word sub_02034338, sub_020342C0, 0
	.word sub_02037A24, sub_020342C4, 0
	.word sub_02037AAC, sub_020342C4, 0
	.word sub_02037A98, sub_020342C8, 0
	.word sub_02037B6C, sub_02037B88, 0
	.word sub_02037C68, sub_02037C94, 0
	.word sub_02039220, sub_020342C0, 0

	.text

	thumb_func_start sub_02033BC4
sub_02033BC4: ; 0x02033BC4
	mov r1, #4
	mov r3, #6
	ldrsh r1, [r0, r1]
	ldrsh r2, [r0, r3]
	cmp r1, r2
	ble _02033BDC
	mov r2, #0xa
	ldrsh r2, [r0, r2]
	ldrsh r0, [r0, r3]
	add r0, r2, r0
	sub r0, r0, r1
	bx lr
_02033BDC:
	ldrsh r0, [r0, r3]
	sub r0, r0, r1
	bx lr
	.balign 4, 0
	thumb_func_end sub_02033BC4
	thumb_func_start sub_02033BE4
sub_02033BE4: ; 0x02033BE4
	push {r4, lr}
	add r4, r0, #0
	bl sub_02033BC4
	mov r1, #0xa
	ldrsh r1, [r4, r1]
	sub r0, r1, r0
	pop {r4, pc}
	thumb_func_end sub_02033BE4
	thumb_func_start sub_02033BF4
sub_02033BF4: ; 0x02033BF4
	mov r1, #4
	mov r2, #8
	ldrsh r3, [r0, r1]
	ldrsh r1, [r0, r2]
	cmp r3, r1
	ble _02033C06
	ldrsh r0, [r0, r2]
	sub r0, r3, r0
	bx lr
_02033C06:
	mov r1, #0xa
	ldrsh r1, [r0, r1]
	ldrsh r0, [r0, r2]
	sub r0, r0, r3
	sub r0, r1, r0
	bx lr
	.balign 4, 0
	thumb_func_end sub_02033BF4
	thumb_func_start sub_02033C14
sub_02033C14: ; 0x02033C14
	push {r3, lr}
	add r2, r0, #0
	add r0, r1, #0
	mov r1, #0xa
	ldrsh r1, [r2, r1]
	bl _s32_div_f
	add r0, r1, #0
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end sub_02033C14
	thumb_func_start sub_02033C28
sub_02033C28: ; 0x02033C28
	mov r1, #8
	ldrsh r1, [r0, r1]
	strh r1, [r0, #6]
	bx lr
	thumb_func_end sub_02033C28
	thumb_func_start sub_02033C30
sub_02033C30: ; 0x02033C30
	ldr r3, [r0, #0x1c]
	mov r2, #0
	ldr r1, [r0, #0x18]
	cmp r3, #0
	ble _02033C4C
_02033C3A:
	ldrb r0, [r1, #0xe]
	cmp r0, #0
	bne _02033C44
	add r0, r1, #0
	bx lr
_02033C44:
	add r2, r2, #1
	add r1, #0x10
	cmp r2, r3
	blt _02033C3A
_02033C4C:
	mov r0, #0
	bx lr
	thumb_func_end sub_02033C30
	thumb_func_start sub_02033C50
sub_02033C50: ; 0x02033C50
	ldr r3, [r0, #0x1c]
	mov r2, #0
	ldr r1, [r0, #0x18]
	cmp r3, #0
	ble _02033C6C
_02033C5A:
	ldrb r0, [r1, #0xe]
	cmp r0, #0
	beq _02033C64
	mov r0, #0
	bx lr
_02033C64:
	add r2, r2, #1
	add r1, #0x10
	cmp r2, r3
	blt _02033C5A
_02033C6C:
	mov r0, #1
	bx lr
	thumb_func_end sub_02033C50
