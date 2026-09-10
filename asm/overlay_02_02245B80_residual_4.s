#include "constants/abilities.h"
#include "constants/species.h"
#include "constants/sndseq.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/std_script.h"
	.include "asm/macros.inc"
	.public ov02_02245B80
	.public ov02_02245B9C
	.public ov02_02245BC8
	.public ov02_02245D18
	.public ov02_02245DB0
	.public ov02_02245DE0
	.public ov02_02245E04
	.public ov02_02245E68
	.public ov02_02245ED8
	.public ov02_02245FD0
	.public ov02_02246048
	.public ov02_022460AC
	.public ov02_022460CC
	.public ov02_022460FC
	.public ShowLegendaryWing
	.public ov02_022461AC
	.public ov02_022461DC
	.public ov02_022462DC
	.public ov02_022462E8
	.public ov02_02246304
	.public ov02_02246330
	.public ov02_02246398
	.public ov02_02246444
	.public ov02_02246490
	.public ov02_0224650C
	.public ov02_02246534
	.public ov02_02246548
	.public ov02_0224662C
	.public ov02_0224663C
	.public ov02_02246714
	.public ov02_02246744
	.public ov02_02246798
	.public OpenAlphHiddenRoom
	.public ov02_022467E8
	.public ov02_02246818
	.public ov02_0224686C
	.public ov02_02246964
	.public ov02_022469A0
	.public ov02_022469B4
	.public ov02_022469D8
	.public ov02_02246A34
	.public ov02_0225321C
	.public ov02_0225321E
	.public ov02_02253222
	.public ov02_02253228
	.public ov02_0225322E
	.public ov02_02253234
	.public ov02_0225323A
	.public ov02_02253240
	.public ov02_02253246
	.public ov02_0225324C
	.public ov02_02253254
	.public ov02_02253264
	.public ov02_02253D80
	.public ov02_02253D84
	.include "overlay_02.inc"
	.include "global.inc"

	.text

	thumb_func_start ov02_02246548
ov02_02246548: ; 0x02246548
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r4, r2, #0
	add r6, r3, #0
	cmp r1, #0
	ble _02246568
	lsl r0, r1, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _02246576
_02246568:
	lsl r0, r1, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_02246576:
	bl _ffix
	strh r0, [r5, #8]
	cmp r4, #0
	ble _02246592
	lsl r0, r4, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _022465A0
_02246592:
	lsl r0, r4, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_022465A0:
	bl _ffix
	strh r0, [r5, #0xa]
	strh r6, [r5, #0xe]
	add r0, sp, #0x10
	ldrh r0, [r0, #0x10]
	strh r0, [r5, #0x12]
	mov r0, #0
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x12]
	cmp r0, #0
	beq _022465CA
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _022465D8
_022465CA:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_022465D8:
	bl _ffix
	add r1, r0, #0
	mov r0, #0x5a
	lsl r0, r0, #0xe
	bl FX_Div
	str r0, [r5, #0x14]
	ldr r0, [r5, #4]
	ldr r1, [r5, #0x18]
	ldr r0, [r0, #0x24]
	bl Camera_Copy
	ldr r1, [r5, #0x18]
	add r0, sp, #0
	bl Camera_GetLookAtCamTarget
	add r4, sp, #0
	add r3, r5, #0
	add r3, #0x20
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	add r4, r2, #0
	str r0, [r3]
	add r3, r5, #0
	ldmia r4!, {r0, r1}
	add r3, #0x2c
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	str r0, [r3]
	ldr r1, [r5, #0x18]
	add r0, r2, #0
	bl Camera_SetFixedTarget
	ldr r0, [r5, #0x18]
	bl Camera_SetStaticPtr
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov02_02246548
