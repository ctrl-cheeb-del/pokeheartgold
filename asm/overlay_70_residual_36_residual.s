#include "config.h"
#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.public MI_CpuFill8
	.public NewString_ReadMsgData
	.public String_Delete
	.public ov70_0224190C
	.public ov70_02242D44
	.public ov70_02242FC4
	.public ov70_02243EB8
	.public ov70_02243F7C
	.public ov70_02243FE0
	.public sub_02019688
	.public sub_020196E8
	.public sub_020197F4
	.public sub_02019B08
	.text

	thumb_func_start ov70_02242D44
ov70_02242D44: ; 0x02242D44
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r0, r1, #0
	str r1, [sp, #4]
	str r2, [sp, #8]
	cmp r0, #6
	bne _02242D58
	mov r3, #0x21
	b _02242D5A
_02242D58:
	mov r3, #0x22
_02242D5A:
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x1c]
	mov r1, #0
	mov r2, #0x64
	bl sub_02019688
	ldr r0, [r5, #0x1c]
	mov r1, #0
	bl sub_02019B08
	ldr r1, [sp, #4]
	add r0, r5, #0
	bl ov70_0224190C
	add r0, r5, #0
	add r0, #0x64
	mov r1, #1
	mov r2, #0x1a
	bl MI_CpuFill8
	mov r4, #0
	add r6, r4, #0
_02242D88:
	add r1, r4, #0
	ldr r0, [r5, #0x24]
	add r1, #0x6e
	bl NewString_ReadMsgData
	add r7, r0, #0
	ldr r0, [sp, #4]
	cmp r0, #4
	bne _02242DBE
	add r0, r5, #0
	add r1, r4, #0
	bl ov70_02243F7C
	cmp r0, #1
	bne _02242DB2
	add r2, r5, r4
	add r2, #0x64
	mov r1, #1
	ldr r0, _02242E50 ; =0x000F0E02
	strb r1, [r2]
	b _02242DE0
_02242DB2:
	add r2, r5, r4
	add r2, #0x64
	mov r1, #0
	ldr r0, _02242E54 ; =0x00080902
	strb r1, [r2]
	b _02242DE0
_02242DBE:
	add r0, r5, #0
	add r1, r4, #0
	bl ov70_02243FE0
	cmp r0, #1
	bne _02242DD6
	add r2, r5, r4
	add r2, #0x64
	mov r1, #1
	ldr r0, _02242E50 ; =0x000F0E02
	strb r1, [r2]
	b _02242DE0
_02242DD6:
	add r2, r5, r4
	ldr r0, _02242E54 ; =0x00080902
	add r2, #0x64
	mov r1, #0
	strb r1, [r2]
_02242DE0:
	str r0, [sp]
	ldr r1, [r5, #4]
	ldr r0, [r5, #0x1c]
	add r1, r1, r6
	add r2, r7, #0
	mov r3, #2
	bl ov70_02242FC4
	add r0, r7, #0
	bl String_Delete
	add r4, r4, #1
	add r6, #0x10
	cmp r4, #9
	blt _02242D88
	ldr r2, [r5, #4]
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x24]
	add r2, #0xe0
	mov r3, #0x44
	bl ov70_02243EB8
	ldr r0, [sp, #4]
	cmp r0, #6
	bne _02242E34
	ldr r0, [r5, #0x24]
	mov r1, #0xae
	bl NewString_ReadMsgData
	add r4, r0, #0
	ldr r0, _02242E50 ; =0x000F0E02
	add r2, r4, #0
	str r0, [sp]
	ldr r1, [r5, #4]
	ldr r0, [r5, #0x1c]
	add r1, #0xf0
	mov r3, #2
	bl ov70_02242FC4
	add r0, r4, #0
	bl String_Delete
_02242E34:
	ldr r2, [sp, #8]
	mov r1, #0
	lsl r2, r2, #0x18
	ldr r0, [r5, #0x1c]
	asr r2, r2, #0x18
	add r3, r1, #0
	bl sub_020196E8
	ldr r0, [r5, #0x1c]
	mov r1, #0
	bl sub_020197F4
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02242E50: .word 0x000F0E02
_02242E54: .word 0x00080902
	thumb_func_end ov70_02242D44
