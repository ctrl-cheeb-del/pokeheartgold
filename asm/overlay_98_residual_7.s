	.include "asm/macros.inc"
	.public ov98_0221E5C0
	.public ov98_0221E5D0
	.public ov98_0221E5E0
	.public ov98_0221E684
	.public ov98_0221E6CC
	.public ov98_0221E6E0
	.public ov98_0221E6F0
	.public ov98_0221E784
	.public ov98_0221E7E8
	.public ov98_0221E8A8
	.public ov98_0221E970
	.public ov98_0221E9FC
	.public ov98_0221EA4C
	.public ov98_0221EAA8
	.public ov98_0221EABC
	.public ov98_0221EB84
	.public ov98_0221EBD8
	.public ov98_0221EBEC
	.public ov98_0221EC08
	.public ov98_0221EC24
	.public ov98_0221EC3C
	.public ov98_0221ECD0
	.public ov98_0221ED3C
	.public ov98_0221ED48
	.public ov98_0221EDA4
	.public ov98_0221EDC4
	.public ov98_0221EE28
	.public ov98_0221EE84
	.public ov98_0221EE9C
	.public ov98_0221EEDC
	.public ov98_0221EEEC
	.public ov98_0221EEFC
	.public ov98_0221EF14
	.public ov98_0221EF24
	.public ov98_0221EF64
	.public ov98_0221EF80
	.public ov98_0221EFA4
	.public ov98_0221EFB4
	.public ov98_0221EFE8
	.public ov98_0221F01C
	.public ov98_0221F024
	.public ov98_0221F058
	.public ov98_0221F090
	.public ov98_0221F0EC
	.public ov98_0221F120
	.public ov98_0221F150
	.public ov98_0221F174
	.public _0221F194
	.public ov98_0221F19C
	.public ov98_0221F1AC
	.public ov98_0221F1C0
	.public ov98_0221F1E0
	.public ov98_0221F1E4
	.public ov98_0221F1F8
	.public ov98_0221F220
	.public ov98_0221F248
	.include "overlay_98.inc"
	.include "global.inc"

	.text

	thumb_func_start ov98_0221F024
ov98_0221F024: ; 0x0221F024
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r5, _0221F050 ; =0x00000000
	bne _0221F030
	bl GF_AssertFail
_0221F030:
	ldr r7, _0221F054 ; =0x000001ED
	mov r4, #0
_0221F034:
	ldrb r0, [r6, r4]
	bl MATH_CountPopulation
	cmp r0, #5
	bne _0221F044
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
_0221F044:
	add r4, r4, #1
	cmp r4, r7
	blt _0221F034
	add r0, r5, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0221F050: .word 0x00000000
_0221F054: .word 0x000001ED
	thumb_func_end ov98_0221F024


	thumb_func_start ov98_0221F058
ov98_0221F058: ; 0x0221F058
	push {r3, r4, r5, r6, r7, lr}
	mov r5, #0
	add r6, r0, #0
	add r4, r5, #0
	mov r7, #0x2c
_0221F062:
	add r0, r4, #0
	mul r0, r7
	add r0, r6, r0
	mov r1, #0
	bl ov98_0221F01C
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #1
	bl ov98_0221EFE8
	cmp r0, #0
	beq _0221F082
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
_0221F082:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #0xa
	blo _0221F062
	add r0, r5, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov98_0221F058
