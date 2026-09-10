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

	thumb_func_start ov01_021F7CE4
ov01_021F7CE4: ; 0x021F7CE4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	bl sub_0205F40C
	add r6, r0, #0
	add r0, r5, #0
	ldr r4, [r6, #4]
	bl ov01_021FA2D4
	cmp r0, #1
	beq _021F7DA2
	cmp r4, #0
	beq _021F7DA2
	add r0, r5, #0
	bl MapObject_GetFacingDirection
	add r7, r0, #0
	add r0, r5, #0
	bl sub_0205F330
	cmp r0, #0
	bne _021F7D56
	cmp r7, #1
	bls _021F7D1C
	mov r0, #1
	str r0, [sp, #4]
	b _021F7D20
_021F7D1C:
	mov r0, #0
	str r0, [sp, #4]
_021F7D20:
	add r0, r4, #0
	bl sub_02023EF4
	ldr r1, [sp, #4]
	cmp r1, r0
	bne _021F7D34
	mov r0, #3
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bne _021F7D4C
_021F7D34:
	ldr r1, [sp, #4]
	add r0, r4, #0
	bl sub_02023EE0
	add r0, r4, #0
	mov r1, #0
	bl sub_02023F40
	add r0, r4, #0
	mov r1, #0
	bl sub_02023F04
_021F7D4C:
	add r0, r4, #0
	mov r1, #0
	bl sub_02023F04
	b _021F7D88
_021F7D56:
	cmp r7, #1
	bls _021F7D60
	mov r0, #1
	str r0, [sp]
	b _021F7D64
_021F7D60:
	mov r0, #0
	str r0, [sp]
_021F7D64:
	add r0, r4, #0
	bl sub_02023EF4
	ldr r1, [sp]
	cmp r1, r0
	beq _021F7D7E
	add r0, r4, #0
	bl sub_02023EE0
	add r0, r4, #0
	mov r1, #0
	bl sub_02023F40
_021F7D7E:
	mov r1, #1
	add r0, r4, #0
	lsl r1, r1, #0xc
	bl sub_02023F04
_021F7D88:
	strb r7, [r6, #2]
	add r0, r5, #0
	bl sub_0205F330
	strb r0, [r6, #3]
	add r0, r5, #0
	add r1, r4, #0
	bl ov01_021FA3E8
	add r0, r5, #0
	add r1, r4, #0
	bl ov01_021F8C88
_021F7DA2:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov01_021F7CE4
