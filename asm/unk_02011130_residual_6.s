	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	.public sub_02011130
	.public sub_0201164C
	.public sub_0201169C
	.public sub_020116EC
	.public sub_02011744
	.public sub_020117A0
	.public sub_020117FC
	.public sub_02011884
	.public sub_020118BC
	.public sub_02011918
	.public sub_020119F4
	.public sub_02011A44
	.public sub_02011AD8
	.public sub_02011B5C
	.public sub_02011B94
	.public sub_02011BF0
	.public sub_02011CB8
	.public sub_02011D08
	.public sub_02011D60
	.public sub_02011D98
	.public sub_02011DEC
	.public sub_02011EC0
	.public sub_02011F10
	.public sub_02011FF8
	.public sub_02012030
	.public sub_02012090
	.public sub_020121A4
	thumb_func_start sub_02011D08
sub_02011D08: ; 0x02011D08
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0x104
	add r4, r0, #0
	mov r1, #0
	bl sub_02010EE0
	ldr r1, [r4, #0xc]
	add r5, r0, #0
	asr r0, r1, #6
	lsr r0, r0, #0x19
	add r0, r1, r0
	asr r0, r0, #7
	add r1, sp, #0
	mov r2, #0xc0
	mov r3, #0
	bl sub_02010A00
	mov r7, #0x12
	mov r6, #0
	add r4, sp, #0
	lsl r7, r7, #6
_02011D34:
	ldr r1, [r4]
	mov r0, #0x80
	neg r1, r1
	bl sub_02010A7C
	mov r1, #3
	lsl r1, r1, #8
	strh r0, [r5, r1]
	ldr r1, [r4]
	mov r0, #0x80
	bl sub_02010A7C
	strh r0, [r5, r7]
	add r6, r6, #1
	add r4, r4, #4
	add r5, r5, #2
	cmp r6, #0xc0
	blt _02011D34
	add sp, #0x1fc
	add sp, #0x104
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02011D08
