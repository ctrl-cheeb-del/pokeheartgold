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

	thumb_func_start ov39_02227778
ov39_02227778: ; 0x02227778
	push {r4, lr}
	mov r1, #0xf1
	add r4, r0, #0
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	cmp r0, #1
	bne _02227836
	add r0, r1, #0
	add r0, #0x24
	ldr r2, [r4, r0]
	ldr r0, _022278C8 ; =0x000059DC
	cmp r2, r0
	beq _022277E4
	add r0, r1, #0
	add r0, #0x4d
	ldrb r0, [r4, r0]
	cmp r0, #0
	beq _022277AA
	add r0, r1, #0
	add r0, #0x4d
	ldrb r0, [r4, r0]
	add r1, #0x4d
	sub r0, r0, #1
	strb r0, [r4, r1]
	b _022277E4
_022277AA:
	bl ov39_0222A13C
	cmp r0, #9
	bhi _022277E4
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022277BE: ; jump table
	.short _022277E4 - _022277BE - 2 ; case 0
	.short _022277D2 - _022277BE - 2 ; case 1
	.short _022277E4 - _022277BE - 2 ; case 2
	.short _022277E4 - _022277BE - 2 ; case 3
	.short _022277E4 - _022277BE - 2 ; case 4
	.short _022277E4 - _022277BE - 2 ; case 5
	.short _022277E4 - _022277BE - 2 ; case 6
	.short _022277D2 - _022277BE - 2 ; case 7
	.short _022277D2 - _022277BE - 2 ; case 8
	.short _022277D2 - _022277BE - 2 ; case 9
_022277D2:
	add r0, r4, #0
	bl ov39_022278D4
	cmp r0, #1
	bne _022277E4
	mov r0, #0xfa
	ldr r1, _022278C8 ; =0x000059DC
	lsl r0, r0, #2
	str r1, [r4, r0]
_022277E4:
	add r0, r4, #0
	bl ov39_02227A5C
	ldr r1, _022278CC ; =0x0000040C
	ldr r2, [r4, r1]
	cmp r2, #0
	beq _02227836
	sub r1, #0xc
	add r0, r4, #0
	add r1, r4, r1
	blx r2
	cmp r0, #1
	bne _02227836
	ldr r0, _022278CC ; =0x0000040C
	mov r1, #0
	str r1, [r4, r0]
	sub r0, #0xc
	ldr r2, [r4, r0]
	cmp r2, #0
	beq _02227820
	mov r1, #0x15
	lsl r1, r1, #4
	ldr r0, [r4, r1]
	add r1, #0x2c
	add r1, r4, r1
	blx r2
	mov r0, #1
	mov r1, #0
	lsl r0, r0, #0xa
	str r1, [r4, r0]
_02227820:
	mov r0, #1
	lsl r0, r0, #0xa
	add r0, r4, r0
	mov r1, #0
	mov r2, #0x10
	bl MI_CpuFill8
	mov r0, #0xfb
	ldr r1, _022278C8 ; =0x000059DC
	lsl r0, r0, #2
	str r1, [r4, r0]
_02227836:
	mov r3, #0xef
	lsl r3, r3, #2
	ldr r0, [r4, r3]
	lsl r1, r0, #2
	ldr r0, _022278D0 ; =ov39_0222A8B4
	ldr r2, [r0, r1]
	cmp r2, #0
	beq _022278C2
	add r1, r3, #0
	add r3, r3, #4
	ldr r3, [r4, r3]
	add r1, #0x10
	lsl r3, r3, #2
	ldr r2, [r2, r3]
	add r0, r4, #0
	add r1, r4, r1
	blx r2
	cmp r0, #0
	beq _022278C2
	cmp r0, #1
	beq _02227866
	cmp r0, #2
	beq _022278AC
	b _022278C2
_02227866:
	mov r0, #0xf3
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	mov r2, #0xc
	bl MI_CpuFill8
	mov r0, #0xf
	lsl r0, r0, #6
	ldr r1, [r4, r0]
	mov r2, #0xc
	add r1, r1, #1
	str r1, [r4, r0]
	add r0, #0xc
	add r0, r4, r0
	mov r1, #0
	bl MI_CpuFill8
	mov r1, #0xef
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	lsl r2, r0, #2
	ldr r0, _022278D0 ; =ov39_0222A8B4
	ldr r2, [r0, r2]
	add r0, r1, #4
	ldr r0, [r4, r0]
	lsl r0, r0, #2
	ldr r0, [r2, r0]
	cmp r0, #0
	bne _022278C2
	mov r2, #0
	add r0, r1, #4
	str r2, [r4, r0]
	str r2, [r4, r1]
	b _022278C2
_022278AC:
	mov r0, #0xf3
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	mov r2, #0xc
	bl MI_CpuFill8
	mov r0, #0xf
	mov r1, #0
	lsl r0, r0, #6
	str r1, [r4, r0]
_022278C2:
	mov r0, #1
	pop {r4, pc}
	nop
_022278C8: .word 0x000059DC
_022278CC: .word 0x0000040C
_022278D0: .word ov39_0222A8B4
	thumb_func_end ov39_02227778


	thumb_func_start ov39_022278D4
ov39_022278D4: ; 0x022278D4
	push {r3, r4, r5, lr}
	mov r3, #0xfa
	add r5, r0, #0
	lsl r3, r3, #2
	ldr r1, [r5, r3]
	ldr r2, _02227A4C ; =0x000055F0
	mov r4, #0
	cmp r1, r2
	bgt _0222790C
	bge _02227986
	ldr r0, _02227A50 ; =0x00005208
	cmp r1, r0
	bgt _02227904
	bge _0222795C
	ldr r2, _02227A54 ; =0x00004E21
	cmp r1, r2
	bgt _02227902
	sub r0, r2, #1
	cmp r1, r0
	blt _02227902
	beq _02227938
	cmp r1, r2
	beq _0222794A
_02227902:
	b _02227A34
_02227904:
	add r0, r0, #1
	cmp r1, r0
	beq _02227974
	b _02227A34
_0222790C:
	ldr r0, _02227A58 ; =0x000059D8
	cmp r1, r0
	bgt _0222791C
	bge _022279A4
	add r0, r2, #1
	cmp r1, r0
	beq _02227992
	b _02227A34
_0222791C:
	add r2, r0, #3
	cmp r1, r2
	bgt _02227936
	add r2, r0, #1
	cmp r1, r2
	blt _02227936
	beq _022279B6
	add r2, r0, #2
	cmp r1, r2
	beq _02227A00
	add r0, r0, #3
	cmp r1, r0
	beq _02227A1C
_02227936:
	b _02227A34
_02227938:
	mov r0, #0x19
	sub r3, #0x34
	lsl r0, r0, #4
	ldr r1, [r5, r3]
	add r0, r5, r0
	bl ov39_0222A164
	add r4, r0, #0
	b _02227A38
_0222794A:
	add r0, r3, #0
	sub r0, #0x3c
	sub r3, #0x34
	ldrh r0, [r5, r0]
	ldr r1, [r5, r3]
	bl ov39_0222A1C0
	add r4, r0, #0
	b _02227A38
_0222795C:
	add r0, r3, #0
	sub r0, #0x3c
	mov r1, #0x19
	sub r3, #0x34
	lsl r1, r1, #4
	ldrb r0, [r5, r0]
	ldr r2, [r5, r3]
	add r1, r5, r1
	bl ov39_0222A200
	add r4, r0, #0
	b _02227A38
_02227974:
	add r0, r3, #0
	sub r0, #0x3c
	sub r3, #0x34
	ldrb r0, [r5, r0]
	ldr r1, [r5, r3]
	bl ov39_0222A268
	add r4, r0, #0
	b _02227A38
_02227986:
	sub r3, #0x34
	ldr r0, [r5, r3]
	bl ov39_0222A2CC
	add r4, r0, #0
	b _02227A38
_02227992:
	mov r0, #0x19
	sub r3, #0x34
	lsl r0, r0, #4
	ldr r1, [r5, r3]
	add r0, r5, r0
	bl ov39_0222A2EC
	add r4, r0, #0
	b _02227A38
_022279A4:
	mov r0, #0x19
	lsl r0, r0, #4
	sub r3, #0x34
	ldr r0, [r5, r0]
	ldr r1, [r5, r3]
	bl ov39_0222A33C
	add r4, r0, #0
	b _02227A38
_022279B6:
	add r0, r3, #0
	add r0, #8
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _022279CA
	cmp r0, #1
	beq _022279DC
	cmp r0, #2
	beq _022279EE
	b _02227A38
_022279CA:
	mov r0, #0x19
	sub r3, #0x34
	lsl r0, r0, #4
	ldr r1, [r5, r3]
	add r0, r5, r0
	bl ov39_0222A394
	add r4, r0, #0
	b _02227A38
_022279DC:
	mov r0, #0x19
	sub r3, #0x34
	lsl r0, r0, #4
	ldr r1, [r5, r3]
	add r0, r5, r0
	bl ov39_0222A3DC
	add r4, r0, #0
	b _02227A38
_022279EE:
	mov r0, #0x19
	sub r3, #0x34
	lsl r0, r0, #4
	ldr r1, [r5, r3]
	add r0, r5, r0
	bl ov39_0222A434
	add r4, r0, #0
	b _02227A38
_02227A00:
	add r0, r3, #0
	add r1, r3, #0
	sub r0, #0x3c
	sub r1, #0x38
	sub r3, #0x34
	mov r2, #5
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r3, [r5, r3]
	lsl r2, r2, #6
	bl ov39_0222A48C
	add r4, r0, #0
	b _02227A38
_02227A1C:
	add r0, r3, #0
	add r1, r3, #0
	sub r0, #0x3c
	sub r1, #0x38
	sub r3, #0x34
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, [r5, r3]
	bl ov39_0222A4C0
	add r4, r0, #0
	b _02227A38
_02227A34:
	bl GF_AssertFail
_02227A38:
	cmp r4, #1
	bne _02227A46
	mov r0, #0xfa
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
_02227A46:
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	nop
_02227A4C: .word 0x000055F0
_02227A50: .word 0x00005208
_02227A54: .word 0x00004E21
_02227A58: .word 0x000059D8
	thumb_func_end ov39_022278D4


	thumb_func_start ov39_02227A5C
ov39_02227A5C: ; 0x02227A5C
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0xfb
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	ldr r0, _02227B0C ; =0x000059DC
	cmp r1, r0
	bne _02227A70
	mov r0, #1
	pop {r4, pc}
_02227A70:
	bl ov39_0222A13C
	mov r1, #0x52
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r1, #4
	ldr r2, [r4, r1]
	ldr r0, [r4, r0]
	cmp r2, r0
	beq _02227B06
	cmp r2, #9
	bhi _02227AFC
	add r0, r2, r2
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02227A94: ; jump table
	.short _02227AFC - _02227A94 - 2 ; case 0
	.short _02227AFC - _02227A94 - 2 ; case 1
	.short _02227AFC - _02227A94 - 2 ; case 2
	.short _02227AFC - _02227A94 - 2 ; case 3
	.short _02227AFC - _02227A94 - 2 ; case 4
	.short _02227AFC - _02227A94 - 2 ; case 5
	.short _02227AFC - _02227A94 - 2 ; case 6
	.short _02227AA8 - _02227A94 - 2 ; case 7
	.short _02227ACC - _02227A94 - 2 ; case 8
	.short _02227ADA - _02227A94 - 2 ; case 9
_02227AA8:
	add r0, r1, #0
	mov r3, #1
	add r0, #0x38
	str r3, [r4, r0]
	add r0, r1, #0
	mov r2, #0
	add r0, #0x3c
	str r2, [r4, r0]
	add r0, r1, #0
	mov r2, #7
	add r0, #0x40
	str r2, [r4, r0]
	add r1, #0x34
	str r3, [r4, r1]
	ldr r1, _02227B10 ; =ov39_02227B58
	ldr r0, _02227B14 ; =0x0000040C
	str r1, [r4, r0]
	b _02227AFC
_02227ACC:
	ldr r1, _02227B18 ; =ov39_02227B1C
	ldr r0, _02227B14 ; =0x0000040C
	str r1, [r4, r0]
	add r0, r4, #0
	bl ov39_02227B5C
	b _02227AFC
_02227ADA:
	add r0, r1, #0
	mov r2, #0
	add r0, #0x38
	str r2, [r4, r0]
	add r1, #0x3c
	str r2, [r4, r1]
	bl ov39_0222A158
	mov r1, #0x62
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #1
	sub r1, #0xc
	str r0, [r4, r1]
	ldr r1, _02227B10 ; =ov39_02227B58
	ldr r0, _02227B14 ; =0x0000040C
	str r1, [r4, r0]
_02227AFC:
	mov r0, #0x52
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	add r0, r0, #4
	str r1, [r4, r0]
_02227B06:
	mov r0, #1
	pop {r4, pc}
	nop
_02227B0C: .word 0x000059DC
_02227B10: .word ov39_02227B58
_02227B14: .word 0x0000040C
_02227B18: .word ov39_02227B1C
	thumb_func_end ov39_02227A5C
