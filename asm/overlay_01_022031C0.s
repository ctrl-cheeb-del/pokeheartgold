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

	thumb_func_start ov01_02203654
ov01_02203654: ; 0x02203654
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r1, #0
	add r4, r0, #0
	ldr r0, [r5, #0x30]
	ldr r1, [r5, #4]
	ldr r2, [r5, #8]
	ldr r3, [r5, #0xc]
	str r0, [sp]
	bl sub_0205F0F8
	cmp r0, #0
	bne _02203678
	add r0, r4, #0
	bl ov01_021F1640
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
_02203678:
	ldr r0, [r5, #0x14]
	cmp r0, #0
	bne _022036B0
	add r0, r4, #0
	add r1, sp, #0x1c
	bl sub_02068DB8
	add r6, r5, #0
	add r6, #0x18
	add r3, sp, #0x10
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [r5, #0x24]
	bl sub_0206121C
	str r0, [r5, #0x14]
	cmp r0, #1
	bne _022036B0
	ldr r0, [sp, #0x14]
	add r1, sp, #0x1c
	str r0, [sp, #0x20]
	add r0, r4, #0
	bl sub_02068DA8
_022036B0:
	ldr r0, [r5]
	cmp r0, #0
	beq _022036C4
	cmp r0, #1
	beq _0220373E
	cmp r0, #2
	bne _022036C0
	b _022037C8
_022036C0:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
_022036C4:
	ldr r0, [r5, #0x24]
	bl FollowMon_GetMapObject
	add r6, r0, #0
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #0x3c]
	bl ov01_021F771C
	add r7, r0, #0
	bl sub_02023FB0
	add r4, r0, #0
	add r0, r7, #0
	bl sub_02023FB0
	add r1, r0, #0
	ldr r3, _022037DC ; =0xFFFF0000
	lsl r1, r1, #0x10
	and r3, r4
	lsr r3, r3, #0x10
	ldr r2, _022037E0 ; =ov01_02209B18
	mov r0, #1
	lsr r1, r1, #0xd
	lsl r3, r3, #3
	bl GF_CreateNewVramTransferTask
	add r0, r6, #0
	bl ov01_022055DC
	cmp r0, #0
	beq _02203734
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
	b _02203738
_02203734:
	mov r0, #0
	str r0, [r5, #0x3c]
_02203738:
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
_0220373E:
	ldr r3, _022037E4 ; =ov01_022094BC
	add r2, sp, #4
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
	str r0, [sp, #4]
	mov r0, #1
	ldr r1, [r5, #0x10]
	lsl r0, r0, #0xc
	bl _s32_div_f
	str r0, [sp, #8]
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #0x3c]
	bl ov01_021F771C
	add r1, sp, #4
	bl sub_02023E78
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	beq _022037A2
	ldr r0, [r5, #0x24]
	bl FollowMon_GetMapObject
	ldr r3, [r5, #0x10]
	ldr r2, [r5, #0x44]
	add r4, r3, #0
	lsl r2, r2, #0xc
	mul r4, r2
	asr r2, r4, #1
	lsr r2, r2, #0x1e
	add r2, r4, r2
	ldr r1, [r5, #0x40]
	asr r2, r2, #2
	add r2, r1, r2
	ldr r1, [r5, #0x3c]
	str r2, [r1]
	add r1, r5, #0
	add r1, #0x48
	bl MapObject_SetPositionVector
_022037A2:
	ldr r0, [r5, #0x10]
	cmp r0, #4
	blt _022037D8
	ldr r0, [r5]
	mov r1, #1
	add r0, r0, #1
	str r0, [r5]
	ldr r0, [r5, #0x2c]
	add r0, #0x3c
	bl Field3dObject_SetActiveFlag
	ldr r0, [sp]
	mov r1, #1
	bl MapObject_SetVisible
	mov r0, #0
	add sp, #0x28
	str r0, [r5, #0x10]
	pop {r3, r4, r5, r6, r7, pc}
_022037C8:
	ldr r0, [r5, #0x10]
	add r0, r0, #1
	str r0, [r5, #0x10]
	cmp r0, #4
	blt _022037D8
	add r0, r4, #0
	bl ov01_021F1640
_022037D8:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022037DC: .word 0xFFFF0000
_022037E0: .word ov01_02209B18
_022037E4: .word ov01_022094BC
	thumb_func_end ov01_02203654
