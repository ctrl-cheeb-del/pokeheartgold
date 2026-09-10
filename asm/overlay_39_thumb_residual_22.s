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

	thumb_func_start ov39_02228EC8
ov39_02228EC8: ; 0x02228EC8
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _02228F14 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	bne _02228EE4
	mov r0, #2
	tst r0, r1
	bne _02228EE4
	bl System_GetTouchNew
	cmp r0, #1
	bne _02228F0E
_02228EE4:
	add r0, r4, #0
	add r0, #0x64
	mov r1, #0
	bl sub_0200E5D4
	add r0, r4, #0
	mov r1, #0
	add r0, #0x94
	str r1, [r0]
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x1c]
	neg r0, r0
	bl ov39_02228B74
	cmp r0, #1
	bne _02228F0A
	mov r0, #0
	str r0, [r4, #8]
	b _02228F0E
_02228F0A:
	mov r0, #8
	str r0, [r4, #8]
_02228F0E:
	mov r0, #0
	pop {r4, pc}
	nop
_02228F14: .word gSystem
	thumb_func_end ov39_02228EC8


	thumb_func_start ov39_02228F18
ov39_02228F18: ; 0x02228F18
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldr r0, [r4, #8]
	cmp r0, #9
	beq _02228F28
	bl sub_0203946C
_02228F28:
	bl sub_0203A914
	add r0, r4, #0
	bl ov39_02228AA8
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x7c
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #0
	str r0, [r4, #8]
	mov r0, #1
	add sp, #0xc
	pop {r3, r4, pc}
	thumb_func_end ov39_02228F18


	thumb_func_start ov39_02228F54
ov39_02228F54: ; 0x02228F54
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x10]
	mov r2, #0
	add r0, #0xf
	cmp r0, #0x11
	bhi _02228FA2
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02228F70: ; jump table
	.short _02228FA0 - _02228F70 - 2 ; case 0
	.short _02228F9C - _02228F70 - 2 ; case 1
	.short _02228FA2 - _02228F70 - 2 ; case 2
	.short _02228FA0 - _02228F70 - 2 ; case 3
	.short _02228FA2 - _02228F70 - 2 ; case 4
	.short _02228FA2 - _02228F70 - 2 ; case 5
	.short _02228FA2 - _02228F70 - 2 ; case 6
	.short _02228FA2 - _02228F70 - 2 ; case 7
	.short _02228FA2 - _02228F70 - 2 ; case 8
	.short _02228FA2 - _02228F70 - 2 ; case 9
	.short _02228FA0 - _02228F70 - 2 ; case 10
	.short _02228FA2 - _02228F70 - 2 ; case 11
	.short _02228FA0 - _02228F70 - 2 ; case 12
	.short _02228F9C - _02228F70 - 2 ; case 13
	.short _02228F98 - _02228F70 - 2 ; case 14
	.short _02228FA2 - _02228F70 - 2 ; case 15
	.short _02228F94 - _02228F70 - 2 ; case 16
	.short _02228F98 - _02228F70 - 2 ; case 17
_02228F94:
	mov r2, #0x96
	b _02228FA2
_02228F98:
	mov r2, #0x97
	b _02228FA2
_02228F9C:
	mov r2, #0x9c
	b _02228FA2
_02228FA0:
	mov r2, #0x9b
_02228FA2:
	ldr r0, _02228FC4 ; =0x00000F0F
	add r3, r4, #0
	str r0, [sp]
	add r3, #0x90
	ldr r1, [r4, #0x24]
	ldr r3, [r3]
	add r0, r4, #0
	bl ov39_02228B04
	add r0, r4, #0
	mov r1, #0xc
	mov r2, #0xb
	bl ov39_02228B6C
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02228FC4: .word 0x00000F0F
	thumb_func_end ov39_02228F54


	thumb_func_start ov39_02228FC8
ov39_02228FC8: ; 0x02228FC8
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	add r1, r4, #0
	add r1, #0x94
	ldr r1, [r1]
	cmp r1, #3
	bhi _02229064
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02228FE4: ; jump table
	.short _02228FEC - _02228FE4 - 2 ; case 0
	.short _0222900C - _02228FE4 - 2 ; case 1
	.short _0222902C - _02228FE4 - 2 ; case 2
	.short _0222904C - _02228FE4 - 2 ; case 3
_02228FEC:
	ldr r1, _02229088 ; =0x00000F0F
	add r3, r4, #0
	str r1, [sp]
	add r3, #0x90
	ldr r1, [r4, #0x24]
	ldr r3, [r3]
	mov r2, #0xba
	bl ov39_02228B04
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02229080
_0222900C:
	ldr r0, [r4, #0x40]
	bl ov39_02228A70
	cmp r0, #0
	bne _02229080
	bl sub_0203946C
	bl ov00_021EC8D8
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02229080
_0222902C:
	ldr r1, _02229088 ; =0x00000F0F
	add r3, r4, #0
	str r1, [sp]
	add r3, #0x90
	ldr r1, [r4, #0x24]
	ldr r3, [r3]
	mov r2, #0xbb
	bl ov39_02228B04
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02229080
_0222904C:
	ldr r0, [r4, #0x40]
	bl ov39_02228A70
	cmp r0, #0
	bne _02229080
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02229080
_02229064:
	add r0, r4, #0
	add r0, #0x98
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x98
	str r1, [r0]
	add r0, r4, #0
	add r0, #0x98
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _02229080
	mov r0, #8
	str r0, [r4, #8]
_02229080:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	nop
_02229088: .word 0x00000F0F
	thumb_func_end ov39_02228FC8
