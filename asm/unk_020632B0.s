#include "constants/sndseq.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/pokemon.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "constants/std_script.h"
#include "fielddata/script/scr_seq/event_D24R0204.h"
#include "constants/field_move_response.h"
	.include "asm/macros.inc"
	.include "unk_020632B0.inc"
	.include "global.inc"

	.public sub_020632B0
	.public MapObjectMovementCmd108_Step1
	.public _020632FC
	.public _0206330A
	.public _02063336
	.public _02063344
	.public _0206336A
	.public _02063378
	.public _020633A2
	.public _020633B2
	.public _02063416
	.public _0206341C
	.public _02063420
	.public _02063448
	.public _02063456
	.public _020634CC
	.public _020634D0
	.public _02063550
	.public _020635AA
	.public _020635B8
	.public _020635E0
	.public _020635EE
	.public _02063616
	.public _02063624
	.public _0206366E
	.public _0206367C
	.public _02063680
	.public _020FE0C4
	.public _020FE0D4
	.public _020FE0E4
	.public _020FE104
	.public _020FE134
	.public _020FE164
	.public _020FE194
	.public _020FE1A4

	.text
	.public MapObjectMovementCmd108_Step1

	thumb_func_start sub_020632B0
sub_020632B0: ; 0x020632B0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r1, #0
	str r3, [sp, #4]
	mov r1, #0xc
	str r0, [sp]
	add r7, r2, #0
	ldr r5, [sp, #0x24]
	bl sub_0205F3C0
	add r4, r0, #0
	mov r0, #0xb
	mov r1, #0x1c
	bl Heap_AllocAtEnd
	mov r1, #0
	mov r2, #0x1c
	str r0, [r4, #8]
	bl MI_CpuFill8
	mov r0, #0x10
	add r1, sp, #0x10
	ldrsb r0, [r1, r0]
	cmp r5, #0
	strb r0, [r4]
	strb r5, [r4, #1]
	ldrh r0, [r1, #0x18]
	strb r0, [r4, #3]
	ble _020632FC
	lsl r0, r5, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0206330A
_020632FC:
	lsl r0, r5, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0206330A:
	bl _ffix
	str r0, [sp, #8]
	ldr r0, [r4, #8]
	strb r6, [r0, #1]
	ldr r0, [r4, #8]
	strb r7, [r0, #2]
	ldr r1, [r4, #8]
	ldr r0, [sp, #4]
	strb r0, [r1, #3]
	lsl r0, r6, #4
	cmp r0, #0
	ble _02063336
	lsl r0, r6, #0x10
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _02063344
_02063336:
	lsl r0, r6, #0x10
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_02063344:
	bl _ffix
	ldr r1, [sp, #8]
	bl FX_Div
	ldr r1, [r4, #8]
	str r0, [r1, #4]
	lsl r0, r7, #4
	cmp r0, #0
	ble _0206336A
	lsl r0, r7, #0x10
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _02063378
_0206336A:
	lsl r0, r7, #0x10
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_02063378:
	bl _ffix
	ldr r1, [sp, #8]
	bl FX_Div
	ldr r1, [r4, #8]
	str r0, [r1, #8]
	ldr r0, [sp, #4]
	lsl r0, r0, #4
	cmp r0, #0
	ble _020633A2
	ldr r0, [sp, #4]
	lsl r0, r0, #0x10
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _020633B2
_020633A2:
	ldr r0, [sp, #4]
	lsl r0, r0, #0x10
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_020633B2:
	bl _ffix
	ldr r1, [sp, #8]
	bl FX_Div
	ldr r1, [r4, #8]
	str r0, [r1, #0xc]
	mov r0, #0xb4
	add r1, r5, #0
	bl _s32_div_f
	ldr r1, [r4, #8]
	strb r0, [r1]
	ldr r1, [r4, #8]
	ldr r0, [sp]
	add r1, #0x10
	bl MapObject_CopyPositionVector
	ldr r0, [r4, #8]
	ldr r0, [r0, #0x14]
	str r0, [r4, #4]
	ldr r0, [sp]
	bl sub_02060F78
	ldr r0, [sp]
	ldr r1, _0206341C ; =0x00010004
	bl MapObject_SetFlagsBits
	add r2, sp, #0x10
	mov r1, #0x10
	ldrsb r1, [r2, r1]
	ldr r0, [sp]
	bl MapObject_SetOrQueueFacing
	add r1, sp, #0x10
	ldrh r1, [r1, #0x18]
	ldr r0, [sp]
	bl sub_0205F328
	ldr r0, [sp]
	bl MapObject_IncrementMovementStep
	ldr r0, [sp]
	bl MapObject_CheckVisible
	cmp r0, #0
	bne _02063416
	ldr r0, _02063420 ; =SEQ_SE_DP_DANSA
	bl PlaySE
_02063416:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_0206341C: .word 0x00010004
_02063420: .word SEQ_SE_DP_DANSA
	thumb_func_end sub_020632B0
