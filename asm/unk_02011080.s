	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02011080
sub_02011080: ; 0x02011080
	push {r3, r4, r5, r6, r7, lr}
	add r4, r2, #0
	mov r2, #0xc3
	add r6, r1, #0
	mov r1, #0
	lsl r2, r2, #2
	add r5, r0, #0
	add r7, r3, #0
	bl memset
	cmp r4, #1
	bne _020110AA
	mov r0, #6
	lsl r0, r0, #6
	str r7, [r5, r0]
	mov r0, #0xc2
	lsl r0, r0, #2
	strb r4, [r5, r0]
	add r0, r0, #1
	strb r6, [r5, r0]
	pop {r3, r4, r5, r6, r7, pc}
_020110AA:
	mov r0, #6
	lsl r0, r0, #6
	str r7, [r5, r0]
	mov r0, #0xc1
	ldr r1, [sp, #0x18]
	lsl r0, r0, #2
	str r1, [r5, r0]
	add r1, r0, #4
	strb r4, [r5, r1]
	add r0, r0, #5
	strb r6, [r5, r0]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02011080
