	.include "asm/macros.inc"
	.include "unk_02033AE0.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02033FC4
sub_02033FC4: ; 0x02033FC4
	push {r3, r4, lr}
	sub sp, #0x2c
	ldr r3, _02033FEC ; =_020F692C
	add r4, r0, #0
	add r2, sp, #0
	mov r1, #0x29
_02033FD0:
	ldrb r0, [r3]
	add r3, r3, #1
	strb r0, [r2]
	add r2, r2, #1
	sub r1, r1, #1
	bne _02033FD0
	cmp r4, #0x29
	blo _02033FE4
	bl GF_AssertFail
_02033FE4:
	add r0, sp, #0
	ldrb r0, [r0, r4]
	add sp, #0x2c
	pop {r3, r4, pc}
	.balign 4, 0
_02033FEC: .word _020F692C
	thumb_func_end sub_02033FC4
	thumb_func_start sub_02033FF0
sub_02033FF0: ; 0x02033FF0
	push {r3, r4, lr}
	sub sp, #0x2c
	ldr r3, _02034018 ; =_020F6955
	add r4, r0, #0
	add r2, sp, #0
	mov r1, #0x29
_02033FFC:
	ldrb r0, [r3]
	add r3, r3, #1
	strb r0, [r2]
	add r2, r2, #1
	sub r1, r1, #1
	bne _02033FFC
	cmp r4, #0x29
	blo _02034010
	bl GF_AssertFail
_02034010:
	add r0, sp, #0
	ldrb r0, [r0, r4]
	add sp, #0x2c
	pop {r3, r4, pc}
	.balign 4, 0
_02034018: .word _020F6955
	thumb_func_end sub_02033FF0
