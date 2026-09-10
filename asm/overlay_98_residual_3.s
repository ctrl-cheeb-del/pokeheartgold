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

	thumb_func_start ov98_0221EA4C
ov98_0221EA4C: ; 0x0221EA4C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r1, #0
	str r2, [sp, #8]
	add r4, r3, #0
	beq _0221EA5E
	mov r5, #1
	add r6, r5, #0
	b _0221EA62
_0221EA5E:
	mov r5, #2
	mov r6, #5
_0221EA62:
	ldr r0, [r0]
	bl Sprite_GetPaletteProxy
	add r1, r5, #0
	bl NNS_G2dGetImagePaletteLocation
	add r5, r0, #0
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #8]
	str r0, [sp, #4]
	add r0, r7, #0
	add r2, r6, #0
	add r3, r5, #0
	bl GfGfxLoader_GXLoadPal
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _0221EA9C
	cmp r4, #0
	beq _0221EA92
	ldr r0, _0221EAA0 ; =0x05000200
	b _0221EA94
_0221EA92:
	ldr r0, _0221EAA4 ; =0x05000600
_0221EA94:
	add r0, r5, r0
	mov r1, #0x20
	bl TintPalette_GrayScale
_0221EA9C:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221EAA0: .word 0x05000200
_0221EAA4: .word 0x05000600
	thumb_func_end ov98_0221EA4C
