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

	thumb_func_start ov02_02245E68
ov02_02245E68: ; 0x02245E68
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r0, #0x10
	mov r1, #0
	bl Field3dObject_SetActiveFlag
	add r0, r5, #0
	add r0, #0x9c
	ldrb r0, [r0]
	mov r6, #0
	cmp r0, #0
	ble _02245EB8
	add r0, r5, #0
	add r7, r5, #0
	str r0, [sp]
	add r0, #0x8c
	add r4, r6, #0
	add r7, #0x10
	str r0, [sp]
_02245E8E:
	add r1, r5, #0
	add r1, #0x88
	ldr r1, [r1]
	add r0, r7, #0
	add r1, r1, r4
	bl Field3dObject_RemoveAnimation
	add r0, r5, #0
	add r0, #0x88
	ldr r0, [r0]
	ldr r1, [sp]
	add r0, r0, r4
	bl Field3dModelAnimation_Unload
	add r0, r5, #0
	add r0, #0x9c
	ldrb r0, [r0]
	add r6, r6, #1
	add r4, #0x14
	cmp r6, r0
	blt _02245E8E
_02245EB8:
	add r0, r5, #0
	mov r1, #0
	add r0, #0x9c
	strb r1, [r0]
	add r0, r5, #0
	bl Field3dModel_Unload
	add r0, r5, #0
	add r0, #0x88
	ldr r0, [r0]
	bl Heap_Free
	add r0, r5, #0
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov02_02245E68


	thumb_func_start ov02_02245ED8
ov02_02245ED8: ; 0x02245ED8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r0, #0
	str r3, [sp, #0xc]
	add r0, #0x9c
	ldrb r0, [r0]
	add r7, r2, #0
	str r1, [sp, #8]
	cmp r0, #0
	beq _02245F38
	mov r6, #0
	cmp r0, #0
	ble _02245F2E
	add r0, r5, #0
	str r0, [sp, #0x10]
	add r0, #0x10
	str r0, [sp, #0x10]
	add r0, r5, #0
	str r0, [sp, #0x14]
	add r0, #0x8c
	add r4, r6, #0
	str r0, [sp, #0x14]
_02245F04:
	add r1, r5, #0
	add r1, #0x88
	ldr r1, [r1]
	ldr r0, [sp, #0x10]
	add r1, r1, r4
	bl Field3dObject_RemoveAnimation
	add r0, r5, #0
	add r0, #0x88
	ldr r0, [r0]
	ldr r1, [sp, #0x14]
	add r0, r0, r4
	bl Field3dModelAnimation_Unload
	add r0, r5, #0
	add r0, #0x9c
	ldrb r0, [r0]
	add r6, r6, #1
	add r4, #0x14
	cmp r6, r0
	blt _02245F04
_02245F2E:
	add r0, r5, #0
	add r0, #0x88
	ldr r0, [r0]
	bl Heap_Free
_02245F38:
	add r1, r5, #0
	ldr r0, [sp, #0xc]
	add r1, #0x9c
	strb r0, [r1]
	add r1, r5, #0
	add r1, #0x9c
	add r0, r5, #0
	ldrb r2, [r1]
	add r0, #0xa0
	mov r1, #0x14
	ldr r0, [r0]
	mul r1, r2
	bl Heap_Alloc
	add r1, r5, #0
	add r1, #0x88
	str r0, [r1]
	add r2, r5, #0
	add r2, #0x9c
	add r0, r5, #0
	ldrb r3, [r2]
	add r0, #0x88
	mov r2, #0x14
	ldr r0, [r0]
	mov r1, #0
	mul r2, r3
	bl MI_CpuFill8
	add r0, r5, #0
	add r0, #0x9c
	ldrb r0, [r0]
	mov r6, #0
	cmp r0, #0
	ble _02245FCA
	add r0, r5, #0
	str r0, [sp, #0x18]
	add r0, #0x8c
	str r0, [sp, #0x18]
	add r0, r5, #0
	str r0, [sp, #0x1c]
	add r0, #0x10
	add r4, r6, #0
	str r0, [sp, #0x1c]
_02245F8E:
	add r0, r5, #0
	add r0, #0xa0
	ldr r0, [r0]
	ldr r2, [sp, #8]
	str r0, [sp]
	ldr r0, [sp, #0x18]
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0x88
	ldr r0, [r0]
	ldrh r3, [r7]
	add r0, r0, r4
	bl Field3dModelAnimation_LoadFromFilesystem
	add r1, r5, #0
	add r1, #0x88
	ldr r1, [r1]
	ldr r0, [sp, #0x1c]
	add r1, r1, r4
	bl Field3dObject_AddAnimation
	add r0, r5, #0
	add r0, #0x9c
	ldrb r0, [r0]
	add r6, r6, #1
	add r7, r7, #2
	add r4, #0x14
	cmp r6, r0
	blt _02245F8E
_02245FCA:
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov02_02245ED8


	thumb_func_start ov02_02245FD0
ov02_02245FD0: ; 0x02245FD0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r0, #0x9c
	ldrb r0, [r0]
	mov r7, #0
	add r6, r7, #0
	cmp r0, #0
	ble _0224602E
	add r4, r7, #0
_02245FE2:
	add r0, r5, #0
	add r0, #0x9e
	ldrh r0, [r0]
	cmp r0, #0
	beq _02245FFE
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0224600C
_02245FFE:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0224600C:
	bl _ffix
	add r1, r0, #0
	add r0, r5, #0
	add r0, #0x88
	ldr r0, [r0]
	add r0, r0, r4
	bl Field3dModelAnimation_FrameAdvanceAndCheck
	add r7, r7, r0
	add r0, r5, #0
	add r0, #0x9c
	ldrb r0, [r0]
	add r6, r6, #1
	add r4, #0x14
	cmp r6, r0
	blt _02245FE2
_0224602E:
	add r0, r5, #0
	add r0, #0x10
	bl Field3dObject_Draw
	add r5, #0x9c
	ldrb r0, [r5]
	cmp r7, r0
	bne _02246042
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02246042:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov02_02245FD0


	thumb_func_start ov02_02246048
ov02_02246048: ; 0x02246048
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r0, #0x9c
	ldrb r0, [r0]
	mov r4, #0
	cmp r0, #0
	ble _022460A2
	mov r7, #0x3f
	add r6, r4, #0
	lsl r7, r7, #0x18
_0224605C:
	add r0, r5, #0
	add r0, #0x9e
	ldrh r0, [r0]
	cmp r0, #0
	beq _02246076
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	b _02246082
_02246076:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fsub
_02246082:
	bl _ffix
	add r1, r0, #0
	add r0, r5, #0
	add r0, #0x88
	ldr r0, [r0]
	add r0, r0, r6
	bl Field3dModelAnimation_FrameAdvanceAndLoop
	add r0, r5, #0
	add r0, #0x9c
	ldrb r0, [r0]
	add r4, r4, #1
	add r6, #0x14
	cmp r4, r0
	blt _0224605C
_022460A2:
	add r5, #0x10
	add r0, r5, #0
	bl Field3dObject_Draw
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov02_02246048
