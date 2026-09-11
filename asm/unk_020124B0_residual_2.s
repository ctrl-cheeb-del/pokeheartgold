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
	thumb_func_start sub_0201268C
sub_0201268C: ; 0x0201268C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r4, r1, #0
	ldrh r1, [r4]
	add r5, r0, #0
	str r3, [sp, #0x1c]
	str r1, [r5, #0xc]
	ldrh r1, [r4]
	str r2, [sp, #0x18]
	ldr r6, [sp, #0x38]
	str r1, [r5, #0x10]
	ldrh r2, [r4, #2]
	ldrh r1, [r4]
	ldr r3, [sp, #0x44]
	ldr r7, [sp, #0x3c]
	sub r1, r2, r1
	str r1, [r5, #0x14]
	mov r1, #2
	add r2, r6, #0
	bl sub_02010E64
	ldr r0, [sp, #0x18]
	mov r1, #0
	str r0, [r5, #0x18]
	ldr r0, [sp, #0x1c]
	str r1, [r5, #0x1c]
	str r0, [r5, #0x20]
	str r1, [r5, #0x24]
	ldr r0, [sp, #0x40]
	str r7, [r5, #0x30]
	str r0, [r5, #0x34]
	ldr r0, [sp, #0x44]
	str r0, [r5, #0x2c]
	ldrh r0, [r4, #6]
	str r0, [r5, #0x28]
	add r0, r5, #0
	bl sub_020127B8
	ldr r0, _02012750 ; =sub_02010F00
	ldr r2, _02012754 ; =0x000003FF
	add r1, r5, #0
	bl SysTask_CreateOnVWaitQueue
	add r0, r5, #0
	mov r1, #0
	bl sub_02010EE0
	add r0, r5, #0
	mov r1, #1
	bl sub_02010EE0
	str r6, [sp]
	mov r3, #0
	str r3, [sp, #4]
	str r3, [sp, #8]
	mov r0, #0xff
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x28]
	str r0, [sp, #0x14]
	ldrb r1, [r4, #4]
	ldrb r2, [r4, #5]
	add r0, r7, #0
	bl sub_02010F84
	str r6, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0xff
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x28]
	mov r3, #1
	str r0, [sp, #0x14]
	ldrb r1, [r4, #4]
	ldrb r2, [r4, #5]
	add r0, r7, #0
	bl sub_02010F84
	ldr r3, [r5, #0x28]
	add r0, r7, #0
	mov r1, #3
	add r2, r6, #0
	bl sub_02011068
	ldr r0, [sp, #0x44]
	ldr r2, _02012758 ; =sub_02010C38
	str r0, [sp]
	ldr r0, [r5, #0x34]
	add r1, r5, #0
	add r3, r6, #0
	bl sub_0200FF88
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02012750: .word sub_02010F00
_02012754: .word 0x000003FF
_02012758: .word sub_02010C38
	thumb_func_end sub_0201268C
