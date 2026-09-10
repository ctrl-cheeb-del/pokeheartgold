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

	thumb_func_start ov39_022274D4
ov39_022274D4: ; 0x022274D4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	add r4, r2, #0
	bl ov39_02227DB8
	cmp r0, #0
	bne _022274E8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_022274E8:
	ldr r0, [r5]
	bl Save_PlayerData_GetIGTAddr
	mov r1, #0x66
	lsl r1, r1, #2
	add r1, r5, r1
	mov r2, #4
	bl MI_CpuCopy8
	mov r2, #0x19
	lsl r2, r2, #4
	ldr r0, [r5]
	add r1, r6, #0
	add r2, r5, r2
	bl ov39_022271CC
	mov r0, #0x67
	lsl r0, r0, #2
	mov r6, #0
	add r7, r5, #0
	add r1, r0, #4
_02227512:
	ldr r3, [r4]
	ldr r2, [r4, #4]
	add r6, r6, #1
	str r3, [r7, r0]
	str r2, [r7, r1]
	add r4, #8
	add r7, #8
	cmp r6, #3
	blt _02227512
	mov r0, #0xfa
	ldr r1, _02227530 ; =0x000055F1
	lsl r0, r0, #2
	str r1, [r5, r0]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02227530: .word 0x000055F1
	thumb_func_end ov39_022274D4


	thumb_func_start ov39_02227534
ov39_02227534: ; 0x02227534
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl ov39_02227DB8
	cmp r0, #0
	bne _02227546
	mov r0, #0
	pop {r3, r4, r5, pc}
_02227546:
	bl sub_0202FBCC
	sub r1, r0, #4
	ldr r0, _02227584 ; =0x00001D4C
	cmp r1, r0
	beq _02227556
	bl GF_AssertFail
_02227556:
	bl sub_0202FC74
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [r5, r1]
	ldr r0, [r5]
	bl ov40_02244B3C
	bl sub_020307DC
	add r1, r0, #0
	add r0, r4, #0
	mov r2, #0x80
	bl MI_CpuCopy8
	ldr r0, _02227588 ; =0x00000411
	mov r1, #0x3c
	strb r1, [r5, r0]
	ldr r1, _0222758C ; =0x000059D8
	sub r0, #0x29
	str r1, [r5, r0]
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02227584: .word 0x00001D4C
_02227588: .word 0x00000411
_0222758C: .word 0x000059D8
	thumb_func_end ov39_02227534


	thumb_func_start ov39_02227590
ov39_02227590: ; 0x02227590
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl ov39_02227DB8
	cmp r0, #0
	bne _022275A6
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_022275A6:
	mov r0, #0x19
	lsl r0, r0, #4
	add r0, r5, r0
	mov r1, #0
	mov r2, #0x10
	bl MI_CpuFill8
	mov r1, #0x19
	lsl r1, r1, #4
	strh r4, [r5, r1]
	add r0, r1, #2
	strb r6, [r5, r0]
	add r0, r1, #3
	strb r7, [r5, r0]
	add r0, sp, #8
	ldrb r2, [r0, #0x10]
	add r0, r1, #4
	strb r2, [r5, r0]
	add r0, r1, #0
	sub r0, #0x50
	add r1, #8
	str r0, [r5, r1]
	mov r0, #0x3f
	mov r1, #0
	lsl r0, r0, #4
	str r1, [r5, r0]
	ldr r1, _022275E4 ; =0x000059D9
	sub r0, #8
	str r1, [r5, r0]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022275E4: .word 0x000059D9
	thumb_func_end ov39_02227590


	thumb_func_start ov39_022275E8
ov39_022275E8: ; 0x022275E8
	push {r4, lr}
	add r4, r0, #0
	bl ov39_02227DB8
	cmp r0, #0
	bne _022275F8
	mov r0, #0
	pop {r4, pc}
_022275F8:
	mov r0, #0x19
	lsl r0, r0, #4
	add r0, r4, r0
	mov r1, #0
	mov r2, #0x10
	bl MI_CpuFill8
	mov r0, #0x19
	ldr r1, _02227640 ; =0x0000FFFF
	lsl r0, r0, #4
	strh r1, [r4, r0]
	mov r1, #0xfe
	add r0, r1, #0
	add r0, #0x94
	strb r1, [r4, r0]
	mov r1, #0xff
	add r0, r1, #0
	add r0, #0x94
	strb r1, [r4, r0]
	add r0, r1, #0
	add r0, #0x95
	strb r1, [r4, r0]
	add r0, r1, #0
	add r0, #0x41
	add r1, #0x99
	str r0, [r4, r1]
	mov r0, #0x3f
	mov r1, #0
	lsl r0, r0, #4
	str r1, [r4, r0]
	ldr r1, _02227644 ; =0x000059D9
	sub r0, #8
	str r1, [r4, r0]
	mov r0, #1
	pop {r4, pc}
	nop
_02227640: .word 0x0000FFFF
_02227644: .word 0x000059D9
	thumb_func_end ov39_022275E8


	thumb_func_start ov39_02227648
ov39_02227648: ; 0x02227648
	push {r4, lr}
	add r4, r0, #0
	bl ov39_02227DB8
	cmp r0, #0
	bne _02227658
	mov r0, #0
	pop {r4, pc}
_02227658:
	mov r0, #0x19
	lsl r0, r0, #4
	add r0, r4, r0
	mov r1, #0
	mov r2, #0x10
	bl MI_CpuFill8
	mov r0, #0x19
	ldr r1, _0222769C ; =0x0000FFFF
	lsl r0, r0, #4
	strh r1, [r4, r0]
	mov r1, #0xff
	add r0, r1, #0
	add r0, #0x93
	strb r1, [r4, r0]
	add r0, r1, #0
	add r0, #0x94
	strb r1, [r4, r0]
	add r0, r1, #0
	add r0, #0x95
	strb r1, [r4, r0]
	add r0, r1, #0
	add r0, #0x41
	add r1, #0x99
	str r0, [r4, r1]
	mov r0, #0x3f
	mov r1, #0
	lsl r0, r0, #4
	str r1, [r4, r0]
	ldr r1, _022276A0 ; =0x000059D9
	sub r0, #8
	str r1, [r4, r0]
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
_0222769C: .word 0x0000FFFF
_022276A0: .word 0x000059D9
	thumb_func_end ov39_02227648
