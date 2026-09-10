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
	.public ov01_021F72DC
	.public ov01_021F7504
	.public ov01_021F772C
	.public ov01_021F7810
	.public ov01_021F7894
	.public ov01_021F7918
	.public ov01_021F7A90
	.public ov01_021F7B14
	.public ov01_021F7B90
	.public ov01_021F7C14
	.public ov01_021F7C80
	.public ov01_021F7CE4
	.public ov01_021F7E6C
	.public ov01_021F7EE4
	.public ov01_021F7F54
	.public ov01_021F80C4
	.public ov01_021F8164
	.public ov01_021F81FC
	.public ov01_021F82F0
	.public ov01_021F8374
	.public ov01_021F84F4
	.public ov01_021F85F4
	.public ov01_021F8708
	.public ov01_021F878C
	.public ov01_021F8874
	.public ov01_021F89B8
	.public ov01_021F8AB0
	.public ov01_021F8B30
	.include "overlay_01_021F72DC.inc"
	.include "global.inc"

	.text
	.public ov01_022089CC
	.public ov01_022089D8
	.public ov01_022089E8
	.public ov01_022089F8
	.public ov01_02208A08
	.public ov01_02208A18
	.public ov01_02208A28
	.public ov01_02208A38
	.public ov01_02208A48
	.public ov01_02208A64
	.public ov01_02208A80
	.public ov01_02208AA0
	.public ov01_02208AC0
	.public ov01_02208AE4
	.public ov01_02208B0C
	.public ov01_02208B34
	.public ov01_021F73CC
	.public ov01_021F73F4
	.public ov01_021F7408
	.public ov01_021F7434
	.public ov01_021F7478
	.public ov01_021F74B4
	.public ov01_021F74C8
	.public ov01_021F7704
	.public ov01_021F771C
	.public ov01_021F77A4
	.public ov01_021F77D0
	.public ov01_021F796C
	.public ov01_021F79A0
	.public ov01_021F79DC
	.public ov01_021F7A18
	.public ov01_021F7A54
	.public ov01_021F7CBC
	.public ov01_021F7DA8
	.public ov01_021F7DD0
	.public ov01_021F7DFC
	.public ov01_021F7E28
	.public ov01_021F7FC8
	.public ov01_021F801C
	.public ov01_021F8070
	.public ov01_021F829C
	.public ov01_021F8400
	.public ov01_021F847C
	.public ov01_021F856C
	.public ov01_021F85BC
	.public ov01_021F86B8
	.public ov01_021F8804
	.public ov01_021F883C
	.public ov01_021F88F0
	.public ov01_021F894C
	.public ov01_021F8A4C
	.public ov01_021F8BA8
	.public ov01_021F8BE0
	.public ov01_021F8C00
	.public ov01_021F8C30
	.public ov01_021F8C3C
	.public ov01_021F8C64
	.public ov01_021F8C88
	.public ov01_021F8CC8
	.public ov01_021F8CFC
	.public ov01_021F8D24
	.public ov01_021F8D28
	.public ov01_021F8D40
	.public ov01_021F8D58

	thumb_func_start ov01_021F8874
ov01_021F8874: ; 0x021F8874
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r4, r2, #0
	add r2, sp, #0
	mov r0, #0
	str r0, [r2]
	str r0, [r2, #4]
	str r0, [r2, #8]
	add r0, r1, #0
	bl sub_02023F30
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	cmp r4, #3
	bhi _021F88DA
	add r1, r4, r4
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021F88A4: ; jump table
	.short _021F88DA - _021F88A4 - 2 ; case 0
	.short _021F88AC - _021F88A4 - 2 ; case 1
	.short _021F88B8 - _021F88A4 - 2 ; case 2
	.short _021F88CA - _021F88A4 - 2 ; case 3
_021F88AC:
	cmp r0, #0x18
	blt _021F88DA
	mov r0, #6
	lsl r0, r0, #0xc
	str r0, [sp, #8]
	b _021F88DA
_021F88B8:
	cmp r0, #0x28
	bge _021F88C4
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp]
	b _021F88DA
_021F88C4:
	ldr r0, _021F88E8 ; =0xFFFFB000
	str r0, [sp]
	b _021F88DA
_021F88CA:
	cmp r0, #0x38
	bge _021F88D4
	ldr r0, _021F88EC ; =0xFFFFF000
	str r0, [sp]
	b _021F88DA
_021F88D4:
	mov r0, #5
	lsl r0, r0, #0xc
	str r0, [sp]
_021F88DA:
	add r0, r5, #0
	add r1, sp, #0
	bl MapObject_SetFacingVector
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_021F88E8: .word 0xFFFFB000
_021F88EC: .word 0xFFFFF000
	thumb_func_end ov01_021F8874
