#include "constants/items.h"
#include "constants/moves.h"
	.include "asm/macros.inc"
	.include "unk_02074E5C.inc"
	.include "global.inc"

	.rodata

	.public _020FFE30
_020FFE30:
	.word sub_02075534
	.word sub_020342B8
	.word 0
	.word sub_02075028
	.word sub_020342B8
	.word 0
	.word sub_020750B4
	.word sub_02074ED8
	.word 0
	.word sub_0207513C
	.word sub_02074EDC
	.word sub_02074EF8
	.word sub_020751A8
	.word sub_02074EF4
	.word sub_02074F18
	.word sub_02075210
	.word sub_02074EE4
	.word sub_02074F38
	.word sub_0207530C
	.word sub_02074EEC
	.word sub_02074F54
	.word sub_02075398
	.word sub_02074EF4
	.word sub_02074F74
	.word sub_02075398
	.word sub_02074EF4
	.word sub_02074F7C
	.word sub_02075424
	.word sub_02074EE4
	.word sub_02074F84
	.word sub_02075424
	.word sub_02074EE4
	.word sub_02074F8C
	.word sub_020755B4
	.word sub_020755E4
	.word sub_02074F94


	.text
	thumb_func_start sub_02074F9C
sub_02074F9C: ; 0x02074F9C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, #5
	mov r1, #4
	str r2, [sp, #8]
	add r7, r3, #0
	bl Heap_Alloc
	add r6, r0, #0
	ldr r0, [sp]
	bl BattleSystem_GetSendBufferPtr
	add r5, r0, #0
	ldr r0, [sp]
	bl ov12_0223A960
	add r4, r0, #0
	ldr r0, [sp]
	bl ov12_0223A96C
	mov ip, r0
	add r0, sp, #0x10
	ldrh r3, [r4]
	ldrb r0, [r0, #0x10]
	add r1, r3, #5
	add r2, r1, r0
	mov r1, #1
	lsl r1, r1, #0xc
	cmp r2, r1
	bls _02074FE4
	mov r1, ip
	strh r3, [r1]
	mov r1, #0
	strh r1, [r4]
_02074FE4:
	ldr r1, [sp, #4]
	mov r3, #0
	strb r1, [r6]
	ldr r1, [sp, #8]
	strb r1, [r6, #1]
	add r1, sp, #0x10
	ldrb r1, [r1, #0x10]
	strh r1, [r6, #2]
_02074FF4:
	ldrb r2, [r6, r3]
	ldrh r1, [r4]
	add r3, r3, #1
	strb r2, [r5, r1]
	ldrh r1, [r4]
	add r1, r1, #1
	strh r1, [r4]
	cmp r3, #4
	blo _02074FF4
	mov r3, #0
	cmp r0, #0
	ble _0207501E
_0207500C:
	ldrb r2, [r7, r3]
	ldrh r1, [r4]
	add r3, r3, #1
	strb r2, [r5, r1]
	ldrh r1, [r4]
	add r1, r1, #1
	strh r1, [r4]
	cmp r3, r0
	blt _0207500C
_0207501E:
	add r0, r6, #0
	bl Heap_Free
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end sub_02074F9C
