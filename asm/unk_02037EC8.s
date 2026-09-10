	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02037EC8
sub_02037EC8: ; 0x02037EC8
	push {r4}
	sub sp, #0xc
	ldr r4, _02037F10 ; =_020F6A90
	add r3, sp, #0
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	str r0, [r3]
	ldr r0, _02037F14 ; =_021D4150
	ldr r0, [r0]
	ldr r1, [r0, #0x24]
	cmp r0, #0
	bne _02037EEC
	add sp, #0xc
	mov r0, #0
	pop {r4}
	bx lr
_02037EEC:
	ldr r0, [sp]
	cmp r0, #0
	beq _02037F08
_02037EF2:
	ldr r0, [r2]
	cmp r1, r0
	bne _02037F00
	add sp, #0xc
	mov r0, #1
	pop {r4}
	bx lr
_02037F00:
	add r2, r2, #4
	ldr r0, [r2]
	cmp r0, #0
	bne _02037EF2
_02037F08:
	mov r0, #0
	add sp, #0xc
	pop {r4}
	bx lr
	.balign 4, 0
_02037F10: .word _020F6A90
_02037F14: .word _021D4150
	thumb_func_end sub_02037EC8
