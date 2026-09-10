	.include "asm/macros.inc"
	.include "unk_02056D7C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205712C
sub_0205712C: ; 0x0205712C
	push {r3, r4, r5, r6, r7, lr}
	mov r4, #0
	ldr r7, _0205717C ; =_021D41C4
	add r5, r4, #0
	add r6, r4, #0
_02057136:
	ldr r0, [r7]
	add r1, r0, r4
	add r1, #0x24
	ldrb r1, [r1]
	cmp r1, #0
	beq _02057168
	add r2, r0, r4
	add r2, #0xcc
	ldrb r2, [r2]
	add r1, r0, #0
	add r1, #0x34
	cmp r2, #0
	bne _0205715A
	add r2, r0, #0
	add r2, #0xec
	ldrb r2, [r2]
	cmp r2, #0
	beq _02057168
_0205715A:
	add r0, r0, r4
	add r0, #0xcc
	strb r6, [r0]
	add r0, r4, #0
	add r1, r1, r5
	bl sub_0205704C
_02057168:
	add r4, r4, #1
	add r5, #8
	cmp r4, #8
	blt _02057136
	ldr r0, _0205717C ; =_021D41C4
	mov r1, #0
	ldr r0, [r0]
	add r0, #0xec
	strb r1, [r0]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0205717C: .word _021D41C4
	thumb_func_end sub_0205712C
