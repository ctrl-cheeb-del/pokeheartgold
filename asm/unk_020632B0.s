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

	.text

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
	thumb_func_start MapObjectMovementCmd108_Step1
MapObjectMovementCmd108_Step1: ; 0x02063424
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	bl sub_0205F3E4
	add r4, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _02063448
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _02063456
_02063448:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_02063456:
	bl _ffix
	str r0, [sp]
	asr r0, r0, #0x1f
	str r0, [sp, #4]
	ldr r6, [r4, #8]
	ldr r2, [sp]
	ldr r0, [r6, #4]
	ldr r3, [sp, #4]
	asr r1, r0, #0x1f
	bl _ll_mul
	ldr r3, [r6, #0x10]
	mov r6, #2
	mov r2, #0
	lsl r6, r6, #0xa
	add r6, r0, r6
	adc r1, r2
	lsl r0, r1, #0x14
	lsr r1, r6, #0xc
	orr r1, r0
	add r0, r3, r1
	str r2, [sp, #0xc]
	str r0, [sp, #8]
	ldr r6, [r4, #8]
	ldr r2, [sp]
	ldr r0, [r6, #0xc]
	ldr r3, [sp, #4]
	asr r1, r0, #0x1f
	bl _ll_mul
	mov r3, #2
	ldr r2, [r6, #0x18]
	mov r6, #0
	lsl r3, r3, #0xa
	add r3, r0, r3
	adc r1, r6
	lsl r0, r1, #0x14
	lsr r1, r3, #0xc
	orr r1, r0
	add r0, r2, r1
	str r0, [sp, #0x10]
	add r0, r5, #0
	bl MapObject_GetFieldSystem
	add r6, r0, #0
	add r0, r5, #0
	bl MapObject_CheckFlag29
	add r2, r0, #0
	add r0, r6, #0
	add r1, sp, #8
	bl sub_02061248
	cmp r0, #0
	beq _020634CC
	ldr r0, [sp, #0xc]
	str r0, [r4, #4]
	b _020634D0
_020634CC:
	ldr r0, [r4, #4]
	str r0, [sp, #0xc]
_020634D0:
	add r0, r5, #0
	add r1, sp, #8
	bl MapObject_SetPositionVector
	ldr r0, [r4, #8]
	ldrb r1, [r0]
	ldrb r0, [r4, #2]
	mul r0, r1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_SinDegNoWrap
	ldr r7, [r4, #8]
	add r6, r0, #0
	ldr r0, [r7, #8]
	ldr r2, [sp]
	ldr r3, [sp, #4]
	asr r1, r0, #0x1f
	bl _ll_mul
	add r2, r0, #0
	ldr r0, [r7, #0x14]
	mov r3, #0
	mov r7, #2
	lsl r7, r7, #0xa
	add r2, r2, r7
	adc r1, r3
	lsl r1, r1, #0x14
	lsr r2, r2, #0xc
	orr r2, r1
	add r0, r0, r2
	asr r2, r6, #0x1f
	lsr r1, r6, #0x10
	lsl r2, r2, #0x10
	orr r2, r1
	lsl r1, r6, #0x10
	add r6, r1, r7
	adc r2, r3
	lsl r1, r2, #0x14
	lsr r2, r6, #0xc
	orr r2, r1
	add r1, r0, r2
	ldr r0, [sp, #0xc]
	str r3, [sp, #8]
	sub r0, r1, r0
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r1, sp, #8
	str r3, [sp, #0x10]
	bl sub_0205F9A0
	mov r0, #1
	ldrsb r1, [r4, r0]
	sub r1, r1, #1
	strb r1, [r4, #1]
	ldrb r1, [r4, #2]
	add r1, r1, #1
	strb r1, [r4, #2]
	ldrsb r0, [r4, r0]
	cmp r0, #0
	ble _02063550
	add sp, #0x14
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_02063550:
	mov r0, #0
	str r0, [sp, #0x10]
	str r0, [sp, #0xc]
	str r0, [sp, #8]
	add r0, r5, #0
	add r1, sp, #8
	bl MapObject_SetFacingVector
	add r0, r5, #0
	add r1, sp, #8
	bl sub_0205F9A0
	ldr r2, [r4, #8]
	mov r1, #1
	ldrsb r1, [r2, r1]
	add r0, r5, #0
	bl MapObject_AddCurrentX
	ldr r2, [r4, #8]
	mov r1, #2
	ldrsb r1, [r2, r1]
	add r0, r5, #0
	bl MapObject_AddCurrentY
	ldr r2, [r4, #8]
	mov r1, #3
	ldrsb r1, [r2, r1]
	add r0, r5, #0
	bl MapObject_AddCurrentZ
	ldr r6, [r4, #8]
	mov r0, #1
	ldrsb r1, [r6, r0]
	lsl r0, r1, #4
	cmp r0, #0
	ble _020635AA
	lsl r0, r1, #0x10
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _020635B8
_020635AA:
	lsl r0, r1, #0x10
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_020635B8:
	bl _ffix
	ldr r1, [r6, #0x10]
	add r0, r1, r0
	str r0, [sp, #8]
	ldr r6, [r4, #8]
	mov r0, #2
	ldrsb r1, [r6, r0]
	lsl r0, r1, #4
	cmp r0, #0
	ble _020635E0
	lsl r0, r1, #0x10
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _020635EE
_020635E0:
	lsl r0, r1, #0x10
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_020635EE:
	bl _ffix
	ldr r1, [r6, #0x14]
	add r0, r1, r0
	str r0, [sp, #0xc]
	ldr r6, [r4, #8]
	mov r0, #3
	ldrsb r1, [r6, r0]
	lsl r0, r1, #4
	cmp r0, #0
	ble _02063616
	lsl r0, r1, #0x10
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _02063624
_02063616:
	lsl r0, r1, #0x10
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_02063624:
	bl _ffix
	ldr r1, [r6, #0x18]
	add r0, r1, r0
	str r0, [sp, #0x10]
	add r0, r5, #0
	add r1, sp, #8
	bl MapObject_SetPositionVector
	add r0, r5, #0
	bl sub_02061070
	ldr r1, _0206367C ; =0x00020008
	add r0, r5, #0
	bl MapObject_SetFlagsBits
	add r0, r5, #0
	bl sub_02060F78
	add r0, r5, #0
	bl sub_0205F484
	add r0, r5, #0
	mov r1, #0
	bl sub_0205F328
	add r0, r5, #0
	bl MapObject_IncrementMovementStep
	add r0, r5, #0
	bl MapObject_CheckVisible
	cmp r0, #0
	bne _0206366E
	ldr r0, _02063680 ; =SEQ_SE_DP_SUTYA2
	bl PlaySE
_0206366E:
	ldr r0, [r4, #8]
	bl Heap_Free
	mov r0, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_0206367C: .word 0x00020008
_02063680: .word SEQ_SE_DP_SUTYA2
	thumb_func_end MapObjectMovementCmd108_Step1

	.rodata

	.public _020FE0C4
_020FE0C4:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00
	.public _020FE0D4
_020FE0D4:
	.byte 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00
	.public _020FE0E4
_020FE0E4:
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00
	.public _020FE104
_020FE104:
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063B08
	.word sub_02063C88
	.word sub_02063C88
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063AFC
	.public _020FE134
_020FE134:
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B20
	.word sub_02063CB4
	.word sub_02063CB4
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B00
	.public _020FE164
_020FE164:
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B9C
	.word sub_02063D30
	.word sub_02063D30
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B04
	; File boundary?
	.public _020FE194
_020FE194:
	.word sub_020643B8
	.word sub_020643E4
	.word sub_02064410
	.word sub_0206443C
	.public _020FE1A4
_020FE1A4:
	.word sub_0206464C
	.word sub_02064668
	.word sub_02064694
	.word sub_020646DC
	.word sub_02064714
	.word sub_02064730
	.word sub_02064748
	.word sub_02064764
	.word sub_02064778
	.word sub_02064790
	.word sub_020647A8
	.word sub_020647C0
	.word sub_020647E8
	.word sub_02064808
	.word sub_02064824
	.word sub_020648A0
	.word sub_020648C8
	.word sub_020648E4
