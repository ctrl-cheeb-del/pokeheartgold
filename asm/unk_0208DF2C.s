#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_0208DE40.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0208DF2C
sub_0208DF2C: ; 0x0208DF2C
	push {r3, r4, lr}
	sub sp, #0x1c
	ldr r3, _0208DF94 ; =_02104EA4
	add r4, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x10
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r1, sp, #8
	str r0, [r2]
	mov r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	mov r0, #0x13
	bl Camera_New
	mov r1, #0xa7
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r2, #1
	str r2, [sp]
	ldr r0, [r4, r1]
	lsl r1, r2, #0x10
	str r0, [sp, #4]
	ldr r3, _0208DF98 ; =0x000005C1
	add r0, sp, #0x10
	add r2, sp, #8
	bl Camera_Init_FromPosDistanceAndAngle
	mov r2, #0xa7
	lsl r2, r2, #2
	mov r1, #0x19
	ldr r2, [r4, r2]
	mov r0, #0
	lsl r1, r1, #0xe
	bl Camera_SetPerspectiveClippingPlane
	mov r0, #0xa7
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Camera_ClearFixedTarget
	mov r0, #0xa7
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Camera_SetStaticPtr
	add sp, #0x1c
	pop {r3, r4, pc}
	nop
_0208DF94: .word _02104EA4
_0208DF98: .word 0x000005C1
	thumb_func_end sub_0208DF2C
