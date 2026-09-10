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

	thumb_func_start ov39_022271CC
ov39_022271CC: ; 0x022271CC
	push {r3, r4, r5, lr}
	add r4, r2, #0
	add r5, r1, #0
	add r0, r4, #0
	mov r1, #0
	mov r2, #8
	bl MI_CpuFill8
	ldrb r0, [r5, #0x19]
	mov r1, #1
	strb r0, [r4]
	ldrb r0, [r5, #0x1a]
	strb r0, [r4, #1]
	ldrb r0, [r5, #0x15]
	strb r0, [r4, #2]
	ldrb r0, [r5, #0x16]
	strb r0, [r4, #3]
	ldrh r0, [r5, #0x1c]
	strh r0, [r4, #4]
	ldrb r0, [r4, #6]
	bic r0, r1
	ldrb r1, [r5, #0x1b]
	lsl r1, r1, #0x1f
	lsr r2, r1, #0x1f
	mov r1, #1
	and r1, r2
	orr r0, r1
	strb r0, [r4, #6]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov39_022271CC


	thumb_func_start ov39_02227208
ov39_02227208: ; 0x02227208
	push {r4, r5, r6, lr}
	ldr r2, _022272E4 ; =0x00000414
	add r4, r1, #0
	mov r1, #0
	add r5, r0, #0
	bl MI_CpuFill8
	mov r0, #0x51
	add r3, r4, #0
	ldr r1, [r4, #4]
	lsl r0, r0, #2
	str r1, [r5, r0]
	ldr r1, [r4, #8]
	add r0, #0xc
	str r1, [r5]
	add r3, #0xc
	add r2, r5, r0
	mov r6, #5
_0222722C:
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	sub r6, r6, #1
	bne _0222722C
	ldr r0, [r3]
	mov r1, #0x53
	str r0, [r2]
	ldr r0, [r4, #0x3c]
	lsl r1, r1, #2
	str r0, [r5, #8]
	ldr r0, [r4, #0x38]
	ldr r2, _022272E8 ; =0x000059DC
	str r0, [r5, #4]
	mov r0, #0
	mvn r0, r0
	str r0, [r5, r1]
	mov r1, #0xfa
	lsl r1, r1, #2
	str r2, [r5, r1]
	add r1, r1, #4
	str r2, [r5, r1]
	bl ov39_0222A2C0
	add r1, r0, #0
	ldr r0, [r4, #4]
	bl Heap_Alloc
	mov r1, #0xed
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0
	mvn r0, r0
	bl ov39_0222A2C0
	add r2, r0, #0
	mov r0, #0xed
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl MI_CpuFill8
	mov r2, #0x32
	ldr r3, [r4, #4]
	mov r0, #0
	mov r1, #0x1b
	lsl r2, r2, #4
	bl NewMsgDataFromNarc
	mov r1, #0xfd
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldr r0, [r4, #4]
	bl MessageFormat_New
	mov r1, #0xfe
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #1
	ldr r1, [r4, #4]
	lsl r0, r0, #8
	bl String_New
	mov r1, #0xff
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldr r0, [r4, #4]
	bl ov39_02227DEC
	mov r1, #0x63
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldr r0, [r4]
	str r0, [r5, #0xc]
	mov r0, #GAME_VERSION
	strb r0, [r5, #0x10]
	mov r0, #2
	strb r0, [r5, #0x11]
	add r0, r5, #0
	add r0, #0xc
	bl ov39_0222A110
	cmp r0, #1
	beq _022272D6
	bl GF_AssertFail
_022272D6:
	mov r1, #0xf1
	mov r0, #1
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #0xc
	str r0, [r5, r1]
	pop {r4, r5, r6, pc}
	.balign 4, 0
_022272E4: .word 0x00000414
_022272E8: .word 0x000059DC
	thumb_func_end ov39_02227208


	thumb_func_start ov39_022272EC
ov39_022272EC: ; 0x022272EC
	push {r4, lr}
	add r4, r0, #0
	bl ov39_0222A130
	mov r0, #0xf1
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r0, #0x38
	ldr r0, [r4, r0]
	bl String_Delete
	mov r0, #0xfe
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl MessageFormat_Delete
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl DestroyMsgData
	mov r0, #0xed
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Heap_Free
	bl ov39_02227E3C
	mov r0, #0x63
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Heap_Free
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov39_022272EC
