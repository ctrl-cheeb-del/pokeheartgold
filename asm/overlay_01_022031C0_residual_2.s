#include "constants/sndseq.h"
#include "constants/moves.h"
#include "constants/std_script.h"
#include "constants/species.h"
#include "constants/sprites.h"
#include "constants/maps.h"
#include "constants/mmodel.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0096_D31R0201.h"
#include "msgdata/msg/msg_0066_D23R0102.h"
	.include "asm/macros.inc"
	.public ov01_02203654
	.public ov01_02203890
	.public ov01_022094B0
	.public ov01_022094BC
	.public ov01_022094C8
	.public ov01_022094DC
	.public ov01_022094F0
	.public ov01_02209504
	.public ov01_02209B18
	.include "overlay_01_022031C0.inc"
	.include "global.inc"

	.text
	.public ov01_022031C0
	.public ov01_022031E8
	.public ov01_022031F8
	.public ov01_02203270
	.public ov01_0220329C
	.public ov01_0220335C
	.public ov01_022033E0
	.public ov01_022033E4
	.public ov01_022034B8
	.public ov01_022034F8
	.public ov01_022035A4
	.public ov01_022035DC
	.public ov01_022037E8
	.public ov01_02203820
	.public ov01_022039BC
	.public ov01_022039E0

	thumb_func_start ov01_02203890
ov01_02203890: ; 0x02203890
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r1, #0
	ldr r7, [r5, #0x30]
	ldr r1, [r5, #4]
	add r4, r0, #0
	ldr r2, [r5, #8]
	ldr r3, [r5, #0xc]
	add r0, r7, #0
	bl sub_0205F0F8
	cmp r0, #0
	bne _022038B4
	add r0, r4, #0
	bl ov01_021F1640
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_022038B4:
	ldr r0, [r5]
	cmp r0, #0
	beq _022038C6
	cmp r0, #1
	beq _0220391C
	cmp r0, #2
	beq _022039A4
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_022038C6:
	ldr r0, [r5, #0x24]
	bl FollowMon_GetMapObject
	add r6, r0, #0
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #0x3c]
	bl ov01_021F771C
	add r0, r6, #0
	bl ov01_022055DC
	cmp r0, #0
	beq _02203912
	add r0, r6, #0
	bl MapObject_GetFacingDirection
	lsl r0, r0, #0x18
	add r1, r5, #0
	lsr r4, r0, #0x18
	add r0, r6, #0
	add r1, #0x48
	bl MapObject_CopyPositionVector
	add r1, r5, #0
	add r2, r5, #0
	add r0, r4, #0
	add r1, #0x48
	add r2, #0x3c
	bl ov01_022039BC
	ldr r0, [r5, #0x3c]
	ldr r0, [r0]
	str r0, [r5, #0x40]
	add r0, r4, #0
	bl ov01_022039E0
	str r0, [r5, #0x44]
	b _02203916
_02203912:
	mov r0, #0
	str r0, [r5, #0x3c]
_02203916:
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
_0220391C:
	ldr r3, _022039B8 ; =ov01_022094B0
	add r2, sp, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r5, #0x10]
	add r1, r0, #1
	mov r0, #1
	str r1, [r5, #0x10]
	lsl r0, r0, #0xc
	bl _s32_div_f
	str r0, [sp]
	mov r0, #1
	ldr r1, [r5, #0x10]
	lsl r0, r0, #0xc
	bl _s32_div_f
	str r0, [sp, #4]
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #0x3c]
	bl ov01_021F771C
	add r1, sp, #0
	bl sub_02023E78
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	beq _0220397E
	ldr r0, [r5, #0x24]
	bl FollowMon_GetMapObject
	ldr r2, [r5, #0x44]
	ldr r1, [r5, #0x10]
	lsl r2, r2, #0xc
	mul r2, r1
	asr r1, r2, #1
	lsr r1, r1, #0x1e
	add r1, r2, r1
	ldr r3, [r5, #0x40]
	asr r1, r1, #2
	add r2, r3, r1
	ldr r1, [r5, #0x3c]
	str r2, [r1]
	add r1, r5, #0
	add r1, #0x48
	bl MapObject_SetPositionVector
_0220397E:
	ldr r0, [r5, #0x10]
	cmp r0, #4
	blt _022039B4
	ldr r0, [r5]
	mov r1, #1
	add r0, r0, #1
	str r0, [r5]
	ldr r0, [r5, #0x2c]
	add r0, #0x3c
	bl Field3dObject_SetActiveFlag
	add r0, r7, #0
	mov r1, #1
	bl sub_02069DC8
	mov r0, #0
	add sp, #0xc
	str r0, [r5, #0x10]
	pop {r4, r5, r6, r7, pc}
_022039A4:
	ldr r0, [r5, #0x10]
	add r0, r0, #1
	str r0, [r5, #0x10]
	cmp r0, #0x10
	blt _022039B4
	add r0, r4, #0
	bl ov01_021F1640
_022039B4:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022039B8: .word ov01_022094B0
	thumb_func_end ov01_02203890
