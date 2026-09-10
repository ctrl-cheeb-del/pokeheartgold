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

	thumb_func_start ov39_02228BAC
ov39_02228BAC: ; 0x02228BAC
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x40]
	bl ov39_02228A70
	cmp r0, #1
	bne _02228BC2
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_02228BC2:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #4
	bhi _02228C6E
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02228BD8: ; jump table
	.short _02228BE2 - _02228BD8 - 2 ; case 0
	.short _02228BF0 - _02228BD8 - 2 ; case 1
	.short _02228C12 - _02228BD8 - 2 ; case 2
	.short _02228C30 - _02228BD8 - 2 ; case 3
	.short _02228C6A - _02228BD8 - 2 ; case 4
_02228BE2:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02228C6E
_02228BF0:
	ldr r0, _02228C74 ; =0x00000F0F
	add r3, r4, #0
	str r0, [sp]
	add r3, #0x90
	ldr r1, [r4, #0x2c]
	ldr r3, [r3]
	add r0, r4, #0
	mov r2, #0x11
	bl ov39_02228B04
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02228C6E
_02228C12:
	mov r1, #0x8d
	ldr r0, [r4, #4]
	lsl r1, r1, #2
	bl ov39_02228AC0
	add r1, r4, #0
	add r1, #0x84
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02228C6E
_02228C30:
	add r0, r4, #0
	add r0, #0x84
	ldr r0, [r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	bne _02228C56
	add r0, r4, #0
	add r0, #0x84
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02228C6E
_02228C56:
	cmp r0, #2
	bne _02228C6E
	add r0, r4, #0
	add r0, #0x84
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	mov r0, #8
	str r0, [r4, #8]
	b _02228C6E
_02228C6A:
	mov r0, #1
	str r0, [r4, #8]
_02228C6E:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02228C74: .word 0x00000F0F
	thumb_func_end ov39_02228BAC


	thumb_func_start ov39_02228C78
ov39_02228C78: ; 0x02228C78
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	beq _02228C90
	cmp r0, #1
	beq _02228CCC
	cmp r0, #2
	beq _02228CE4
	b _02228D00
_02228C90:
	ldr r0, [r4]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl sub_02039418
	mov r0, #4
	bl Sys_SetSleepDisableFlag
	bl sub_0203A880
	ldr r0, _02228D08 ; =0x00000F0F
	add r3, r4, #0
	str r0, [sp]
	add r3, #0x90
	ldr r1, [r4, #0x28]
	ldr r3, [r3]
	add r0, r4, #0
	mov r2, #1
	bl ov39_02228B04
	add r0, r4, #0
	bl ov39_02228A8C
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02228D00
_02228CCC:
	ldr r0, [r4, #0x40]
	bl ov39_02228A70
	cmp r0, #0
	bne _02228D00
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02228D00
_02228CE4:
	ldr r0, [r4]
	mov r1, #2
	add r0, #0x14
	mov r2, #1
	mov r3, #0x14
	bl ov00_021EC3F0
	mov r0, #2
	bl ov00_021EC454
	bl ov00_021EC4A4
	mov r0, #2
	str r0, [r4, #8]
_02228D00:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	nop
_02228D08: .word 0x00000F0F
	thumb_func_end ov39_02228C78


	thumb_func_start ov39_02228D0C
ov39_02228D0C: ; 0x02228D0C
	push {r4, lr}
	sub sp, #0x48
	add r4, r0, #0
	bl ov00_021EC60C
	bl ov00_021EC5B4
	cmp r0, #0
	beq _02228D8A
	bl ov00_021EC724
	cmp r0, #8
	bhi _02228D6A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02228D32: ; jump table
	.short _02228D6A - _02228D32 - 2 ; case 0
	.short _02228D6A - _02228D32 - 2 ; case 1
	.short _02228D6A - _02228D32 - 2 ; case 2
	.short _02228D6A - _02228D32 - 2 ; case 3
	.short _02228D80 - _02228D32 - 2 ; case 4
	.short _02228D6A - _02228D32 - 2 ; case 5
	.short _02228D6A - _02228D32 - 2 ; case 6
	.short _02228D44 - _02228D32 - 2 ; case 7
	.short _02228D6A - _02228D32 - 2 ; case 8
_02228D44:
	add r0, sp, #8
	add r1, sp, #4
	bl ov00_021EC11C
	str r0, [r4, #0x14]
	ldr r0, [sp, #8]
	str r0, [r4, #0x18]
	ldr r0, [sp, #4]
	str r0, [r4, #0x1c]
	bl ov00_021EC210
	bl ov00_021EC8D8
	add r0, r4, #0
	bl ov39_02228AA8
	mov r0, #6
	str r0, [r4, #8]
	b _02228D8A
_02228D6A:
	add r0, sp, #0
	bl ov00_021EC0FC
	add r0, r4, #0
	bl ov39_02228AA8
	mov r0, #0xa
	str r0, [r4, #8]
	sub r0, #0xc
	str r0, [r4, #0x10]
	b _02228D8A
_02228D80:
	add r0, sp, #0xc
	bl ov00_021EC9E0
	mov r0, #3
	str r0, [r4, #8]
_02228D8A:
	mov r0, #0
	add sp, #0x48
	pop {r4, pc}
	thumb_func_end ov39_02228D0C
