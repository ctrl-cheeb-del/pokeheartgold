	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205A3B0
sub_0205A3B0: ; 0x0205A3B0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r2, #0
	add r0, sp, #0
	strb r4, [r0, #2]
	cmp r1, #0
	beq _0205A3C4
	cmp r1, #1
	beq _0205A3DC
	pop {r3, r4, r5, pc}
_0205A3C4:
	ldr r1, [r5, #0x44]
	cmp r1, #0
	bne _0205A404
	ldrb r0, [r0, #2]
	add r1, sp, #0
	add r1, #2
	str r0, [r5, #0x34]
	mov r0, #0x63
	mov r2, #1
	bl sub_02037030
	pop {r3, r4, r5, pc}
_0205A3DC:
	cmp r4, #0
	bne _0205A3F4
	ldr r1, [r5, #0x30]
	mov r2, #1
	strb r1, [r0, #1]
	add r1, sp, #0
	mov r0, #0x67
	add r1, #1
	bl sub_02037108
	str r4, [r5, #0x3c]
	pop {r3, r4, r5, pc}
_0205A3F4:
	mov r1, #7
	strb r1, [r0]
	mov r0, #0x67
	add r1, sp, #0
	mov r2, #1
	bl sub_02037108
	str r4, [r5, #0x3c]
_0205A404:
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0205A3B0
