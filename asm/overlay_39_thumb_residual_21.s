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

	thumb_func_start ov39_02228DA0
ov39_02228DA0: ; 0x02228DA0
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	bl ov00_021ECDC8
	cmp r0, #5
	bhi _02228E44
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02228DBA: ; jump table
	.short _02228DCC - _02228DBA - 2 ; case 0
	.short _02228E44 - _02228DBA - 2 ; case 1
	.short _02228E44 - _02228DBA - 2 ; case 2
	.short _02228DC6 - _02228DBA - 2 ; case 3
	.short _02228DCC - _02228DBA - 2 ; case 4
	.short _02228DCC - _02228DBA - 2 ; case 5
_02228DC6:
	mov r0, #5
	str r0, [r4, #8]
	b _02228E44
_02228DCC:
	add r0, r4, #0
	bl ov39_02228AA8
	add r0, sp, #4
	add r1, sp, #0
	bl ov00_021EC11C
	str r0, [r4, #0x14]
	ldr r0, [sp, #4]
	str r0, [r4, #0x18]
	ldr r0, [sp]
	str r0, [r4, #0x1c]
	bl ov00_021EC210
	bl ov00_021EC8D8
	mov r0, #6
	str r0, [r4, #8]
	ldr r1, [sp]
	cmp r1, #7
	bhi _02228E32
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02228E02: ; jump table
	.short _02228E32 - _02228E02 - 2 ; case 0
	.short _02228E12 - _02228E02 - 2 ; case 1
	.short _02228E12 - _02228E02 - 2 ; case 2
	.short _02228E24 - _02228E02 - 2 ; case 3
	.short _02228E16 - _02228E02 - 2 ; case 4
	.short _02228E2E - _02228E02 - 2 ; case 5
	.short _02228E20 - _02228E02 - 2 ; case 6
	.short _02228E2E - _02228E02 - 2 ; case 7
_02228E12:
	str r0, [r4, #8]
	b _02228E32
_02228E16:
	bl ov00_021FA0D8
	mov r0, #6
	str r0, [r4, #8]
	b _02228E32
_02228E20:
	str r0, [r4, #8]
	b _02228E32
_02228E24:
	bl ov00_021ED9B4
	mov r0, #6
	str r0, [r4, #8]
	b _02228E32
_02228E2E:
	bl sub_020399EC
_02228E32:
	ldr r1, [sp, #4]
	ldr r0, _02228E4C ; =0xFFFFB1E0
	cmp r1, r0
	bge _02228E44
	ldr r0, _02228E50 ; =0xFFFF8AD1
	cmp r1, r0
	blt _02228E44
	mov r0, #6
	str r0, [r4, #8]
_02228E44:
	mov r0, #0
	add sp, #8
	pop {r4, pc}
	nop
_02228E4C: .word 0xFFFFB1E0
_02228E50: .word 0xFFFF8AD1
	thumb_func_end ov39_02228DA0


	thumb_func_start ov39_02228E54
ov39_02228E54: ; 0x02228E54
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl sub_0202C6F4
	add r6, r0, #0
	ldr r0, [r5]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl Save_SysInfo_Get
	add r4, r0, #0
	add r0, r6, #0
	bl sub_0202C08C
	add r0, r4, #0
	bl Save_SysInfo_GetDwcProfileId
	cmp r0, #0
	bne _02228E8E
	add r0, r6, #0
	bl sub_0203A040
	add r1, r0, #0
	add r0, r4, #0
	bl Save_SysInfo_SetDwcProfileId
_02228E8E:
	add r0, r4, #0
	bl Save_SysInfo_GetDwcProfileId
	mov r0, #9
	str r0, [r5, #8]
	ldr r0, [r5]
	mov r1, #1
	str r1, [r0, #0x7c]
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov39_02228E54
