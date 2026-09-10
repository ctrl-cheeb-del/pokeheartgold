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
	thumb_func_start sub_02063D30
sub_02063D30: ; 0x02063D30
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	ldr r3, _02063E4C ; =_020FE0E4
	add r2, sp, #0
	add r7, r0, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	add r0, r7, #0
	bl sub_0205F3BC
	add r4, r0, #0
	ldrb r0, [r4, #1]
	cmp r0, #3
	bhi _02063E46
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02063D64: ; jump table
	.short _02063D6C - _02063D64 - 2 ; case 0
	.short _02063DB2 - _02063D64 - 2 ; case 1
	.short _02063DD8 - _02063D64 - 2 ; case 2
	.short _02063DEE - _02063D64 - 2 ; case 3
_02063D6C:
	add r0, r7, #0
	bl MapObject_GetFacingDirection
	mov r5, #0
	add r6, r0, #0
	add r1, r5, #0
	add r0, sp, #0
	mov r2, #5
	b _02063D82
_02063D7E:
	add r1, r1, #4
	add r5, r5, #1
_02063D82:
	cmp r5, #4
	bge _02063D92
	ldrsb r3, [r4, r2]
	lsl r3, r3, #4
	add r3, r0, r3
	ldr r3, [r1, r3]
	cmp r6, r3
	bne _02063D7E
_02063D92:
	cmp r5, #4
	blt _02063D9A
	bl GF_AssertFail
_02063D9A:
	add r0, r5, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	strb r6, [r4, #4]
	add r0, r2, r1
	strb r0, [r4, #6]
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
_02063DB2:
	mov r0, #5
	ldrsb r0, [r4, r0]
	add r2, sp, #0
	lsl r3, r0, #4
	mov r0, #6
	ldrsb r0, [r4, r0]
	lsl r1, r0, #2
	add r0, r2, r3
	ldr r0, [r1, r0]
	mov r1, #0
	bl sub_0206234C
	add r1, r0, #0
	add r0, r7, #0
	bl MapObject_ForceSetHeldMovement
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
_02063DD8:
	add r0, r7, #0
	bl sub_02062428
	cmp r0, #0
	bne _02063DE8
	add sp, #0x20
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02063DE8:
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
_02063DEE:
	mov r0, #8
	ldrsb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, #8]
	ldrsb r0, [r4, r0]
	cmp r0, #8
	bge _02063E02
	add sp, #0x20
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02063E02:
	mov r0, #0
	strb r0, [r4, #8]
	mov r0, #7
	ldrsb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, #7]
	ldrsb r0, [r4, r0]
	cmp r0, #4
	bge _02063E30
	mov r0, #6
	ldrsb r0, [r4, r0]
	add sp, #0x20
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	strb r0, [r4, #6]
	mov r0, #1
	strb r0, [r4, #1]
	pop {r3, r4, r5, r6, r7, pc}
_02063E30:
	mov r1, #4
	ldrsb r1, [r4, r1]
	add r0, r7, #0
	bl MapObject_SetFacingDirection
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
	mov r0, #0
	strb r0, [r4, #7]
	strb r0, [r4]
_02063E46:
	mov r0, #0
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02063E4C: .word _020FE0E4
	thumb_func_end sub_02063D30
