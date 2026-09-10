	.include "asm/macros.inc"
	.include "unk_02012DD8.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0201333C
sub_0201333C: ; 0x0201333C
	push {r3}
	sub sp, #4
	cmp r0, #0
	bne _02013348
	ldr r0, _0201335C ; =0x0400004A
	b _0201334A
_02013348:
	ldr r0, _02013360 ; =0x0400104A
_0201334A:
	ldrb r1, [r0]
	add r0, sp, #0
	strb r1, [r0]
	add r1, sp, #0
	mov r0, #0
	ldrsb r0, [r1, r0]
	add sp, #4
	pop {r3}
	bx lr
	.balign 4, 0
_0201335C: .word 0x0400004A
_02013360: .word 0x0400104A
	thumb_func_end sub_0201333C
