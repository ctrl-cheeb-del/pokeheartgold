#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_39_thumb.inc"
	.include "global.inc"

	.text
	.public _0222AB80
	.public ov39_02227088
	.public ov39_022271CC
	.public ov39_02227208
	.public ov39_022272EC
	.public ov39_022273B0
	.public ov39_02227420
	.public ov39_022274D4
	.public ov39_02227534
	.public ov39_02227590
	.public ov39_022275E8
	.public ov39_02227648
	.public ov39_02227778
	.public ov39_022278D4
	.public ov39_02227A5C
	.public ov39_02227B24
	.public ov39_02227B5C
	.public ov39_02227D5C
	.public ov39_02227DE4
	.public ov39_02227DEC
	.public ov39_02227E8C
	.public ov39_02227F14
	.public ov39_02227FEC
	.public ov39_0222801C
	.public ov39_022280D4
	.public ov39_02228140
	.public ov39_02228308
	.public ov39_02228370
	.public ov39_02228418
	.public ov39_02228440
	.public ov39_022285CC
	.public ov39_022287F8
	.public ov39_022288A0
	.public ov39_02228964
	.public ov39_0222899C
	.public ov39_022289D0
	.public ov39_02228A34
	.public ov39_02228AC0
	.public ov39_02228B04
	.public ov39_02228BAC
	.public ov39_02228C78
	.public ov39_02228D0C
	.public ov39_02228DA0
	.public ov39_02228E54
	.public ov39_02228EC8
	.public ov39_02228F18
	.public ov39_02228F54
	.public ov39_02228FC8
	.public ov39_022290A4
	.public ov39_0222915C
	.public ov39_02229224
	.public ov39_0222A8B0
	.public ov39_0222A8B4
	.public ov39_0222A8C0
	.public ov39_0222A8D4
	.public ov39_0222A8E4
	.public ov39_0222A90C
	.public ov39_0222A944
	.public ov39_0222AA20
	.public ov39_02227060
	.public ov39_02227080
	.public ov39_02227188
	.public ov39_022271A4
	.public ov39_022271C0
	.public ov39_02227334
	.public ov39_02227348
	.public ov39_02227364
	.public ov39_0222738C
	.public ov39_022273F8
	.public ov39_0222748C
	.public ov39_022274B4
	.public ov39_022276A4
	.public ov39_022276E0
	.public ov39_02227720
	.public ov39_0222774C
	.public ov39_02227B1C
	.public ov39_02227B20
	.public ov39_02227B50
	.public ov39_02227B54
	.public ov39_02227B58
	.public ov39_02227D44
	.public ov39_02227D50
	.public ov39_02227DB8
	.public ov39_02227E3C
	.public ov39_02227E48
	.public ov39_02227E6C
	.public ov39_02227ECC
	.public ov39_02227EF4
	.public ov39_02227F60
	.public ov39_02227F74
	.public ov39_02227F84
	.public ov39_02227FA8
	.public ov39_02227FC4
	.public ov39_02227FFC
	.public ov39_022280B4
	.public ov39_02228120
	.public ov39_022285A8
	.public ov39_02228948
	.public ov39_02228A70
	.public ov39_02228A8C
	.public ov39_02228AA8
	.public ov39_02228B6C
	.public ov39_02228B74
	.public ov39_02228D90
	.public ov39_02228EA4
	.public ov39_0222908C

	thumb_func_start ov39_02227B5C
ov39_02227B5C: ; 0x02227B5C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r6, #1
	bl ov39_0222A2B4
	add r4, r0, #0
	bl ov39_0222A2A8
	mov r0, #0xfb
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	ldrh r0, [r4]
	cmp r1, r0
	beq _02227B7C
	bl GF_AssertFail
_02227B7C:
	mov r0, #1
	mov r1, #0
	lsl r0, r0, #0xa
	str r1, [r5, r0]
	ldrh r1, [r4]
	ldr r0, _02227D14 ; =0x00005209
	cmp r1, r0
	bgt _02227BAE
	bge _02227C34
	ldr r2, _02227D18 ; =0x00004E21
	cmp r1, r2
	bgt _02227BA6
	sub r0, r2, #1
	cmp r1, r0
	blt _02227BA2
	beq _02227BE4
	cmp r1, r2
	beq _02227C00
	b _02227CE6
_02227BA2:
	cmp r1, #0
	b _02227CE6
_02227BA6:
	sub r0, r0, #1
	cmp r1, r0
	beq _02227C18
	b _02227CE6
_02227BAE:
	ldr r0, _02227D1C ; =0x000055F1
	cmp r1, r0
	bgt _02227BBE
	bge _02227C64
	sub r0, r0, #1
	cmp r1, r0
	beq _02227C4C
	b _02227CE6
_02227BBE:
	ldr r0, _02227D20 ; =0x000059D8
	cmp r1, r0
	bgt _02227BC8
	beq _02227C7C
	b _02227CE6
_02227BC8:
	add r2, r0, #3
	cmp r1, r2
	bgt _02227BE2
	add r2, r0, #1
	cmp r1, r2
	blt _02227BE2
	beq _02227CA0
	add r2, r0, #2
	cmp r1, r2
	beq _02227CB8
	add r0, r0, #3
	cmp r1, r0
	beq _02227CD0
_02227BE2:
	b _02227CE6
_02227BE4:
	add r0, r5, #0
	add r1, r4, #0
	bl ov39_02227E48
	add r6, r0, #0
	ldr r0, _02227D24 ; =0x00000154
	ldr r1, [r5, r0]
	ldr r0, _02227D28 ; =0x00000400
	str r1, [r5, r0]
	bne _02227CE6
	ldr r1, _02227D2C ; =ov39_02227B50
	add r0, #0xc
	str r1, [r5, r0]
	b _02227CE6
_02227C00:
	add r0, r5, #0
	add r1, r4, #0
	bl ov39_02227E6C
	add r6, r0, #0
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	mov r0, #1
	lsl r0, r0, #0xa
	str r1, [r5, r0]
	b _02227CE6
_02227C18:
	add r0, r5, #0
	add r1, r4, #0
	bl ov39_02227ECC
	add r6, r0, #0
	ldr r0, _02227D30 ; =0x0000015C
	ldr r1, [r5, r0]
	ldr r0, _02227D28 ; =0x00000400
	str r1, [r5, r0]
	bne _02227CE6
	ldr r1, _02227D34 ; =ov39_02227B54
	add r0, #0xc
	str r1, [r5, r0]
	b _02227CE6
_02227C34:
	add r0, r5, #0
	add r1, r4, #0
	bl ov39_02227EF4
	add r6, r0, #0
	mov r0, #0x16
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	mov r0, #1
	lsl r0, r0, #0xa
	str r1, [r5, r0]
	b _02227CE6
_02227C4C:
	add r0, r5, #0
	add r1, r4, #0
	bl ov39_02227F60
	add r6, r0, #0
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	mov r0, #1
	lsl r0, r0, #0xa
	str r1, [r5, r0]
	b _02227CE6
_02227C64:
	add r0, r5, #0
	add r1, r4, #0
	bl ov39_02227F84
	add r6, r0, #0
	mov r0, #0x5a
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	mov r0, #1
	lsl r0, r0, #0xa
	str r1, [r5, r0]
	b _02227CE6
_02227C7C:
	add r0, r5, #0
	add r1, r4, #0
	bl ov39_02227FC4
	add r6, r0, #0
	ldr r0, _02227D38 ; =0x0000016C
	ldr r1, [r5, r0]
	ldr r0, _02227D28 ; =0x00000400
	str r1, [r5, r0]
	bne _02227C98
	ldr r1, _02227D3C ; =ov39_02227B20
	add r0, #0xc
	str r1, [r5, r0]
	b _02227CE6
_02227C98:
	ldr r1, _02227D40 ; =ov39_02227B24
	add r0, #0xc
	str r1, [r5, r0]
	b _02227CE6
_02227CA0:
	add r0, r5, #0
	add r1, r4, #0
	bl ov39_02227FFC
	add r6, r0, #0
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	mov r0, #1
	lsl r0, r0, #0xa
	str r1, [r5, r0]
	b _02227CE6
_02227CB8:
	add r0, r5, #0
	add r1, r4, #0
	bl ov39_022280B4
	add r6, r0, #0
	mov r0, #0x5d
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	mov r0, #1
	lsl r0, r0, #0xa
	str r1, [r5, r0]
	b _02227CE6
_02227CD0:
	add r0, r5, #0
	add r1, r4, #0
	bl ov39_02228120
	add r6, r0, #0
	mov r0, #0x5e
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	mov r0, #1
	lsl r0, r0, #0xa
	str r1, [r5, r0]
_02227CE6:
	cmp r6, #0
	bne _02227D06
	mov r0, #6
	mov r1, #2
	lsl r0, r0, #6
	str r1, [r5, r0]
	ldrh r2, [r4]
	add r1, r0, #4
	str r2, [r5, r1]
	add r1, r0, #0
	ldrh r2, [r4, #2]
	add r1, #8
	sub r0, r0, #4
	str r2, [r5, r1]
	mov r1, #1
	b _02227D0C
_02227D06:
	mov r0, #0x5f
	mov r1, #0
	lsl r0, r0, #2
_02227D0C:
	str r1, [r5, r0]
	add r0, r6, #0
	pop {r4, r5, r6, pc}
	nop
_02227D14: .word 0x00005209
_02227D18: .word 0x00004E21
_02227D1C: .word 0x000055F1
_02227D20: .word 0x000059D8
_02227D24: .word 0x00000154
_02227D28: .word 0x00000400
_02227D2C: .word ov39_02227B50
_02227D30: .word 0x0000015C
_02227D34: .word ov39_02227B54
_02227D38: .word 0x0000016C
_02227D3C: .word ov39_02227B20
_02227D40: .word ov39_02227B24
	thumb_func_end ov39_02227B5C
