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
	.include "unk_020658D4.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02066444
sub_02066444: ; 0x02066444
	push {r3, r4, r5, lr}
	sub sp, #0x30
	ldr r5, _020664CC ; =_020FE3F4
	add r3, r0, #0
	ldmia r5!, {r0, r1}
	add r4, sp, #0x20
	add r2, r4, #0
	stmia r4!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r5, _020664D0 ; =_020FE434
	add r4, sp, #0x10
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r5, _020664D4 ; =_020FE444
	add r4, sp, #0
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	mov r1, #0
_02066472:
	lsl r0, r1, #2
	ldr r0, [r2, r0]
	cmp r3, r0
	bne _02066480
	add sp, #0x30
	mov r0, #3
	pop {r3, r4, r5, pc}
_02066480:
	add r0, r1, #1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	cmp r1, #4
	blo _02066472
	mov r2, #0
	add r1, sp, #0x10
_0206648E:
	lsl r0, r2, #2
	ldr r0, [r1, r0]
	cmp r3, r0
	bne _0206649C
	add sp, #0x30
	mov r0, #2
	pop {r3, r4, r5, pc}
_0206649C:
	add r0, r2, #1
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	cmp r2, #4
	blo _0206648E
	mov r2, #0
	add r1, sp, #0
_020664AA:
	lsl r0, r2, #2
	ldr r0, [r1, r0]
	cmp r3, r0
	bne _020664B8
	add sp, #0x30
	mov r0, #1
	pop {r3, r4, r5, pc}
_020664B8:
	add r0, r2, #1
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	cmp r2, #4
	blo _020664AA
	bl GF_AssertFail
	mov r0, #0
	add sp, #0x30
	pop {r3, r4, r5, pc}
	.balign 4, 0
_020664CC: .word _020FE3F4
_020664D0: .word _020FE434
_020664D4: .word _020FE444
	thumb_func_end sub_02066444
	thumb_func_start sub_020664D8
sub_020664D8: ; 0x020664D8
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	bl MapObject_GetFieldSystem
	add r4, r0, #0
	add r0, r5, #0
	bl MapObject_GetXCoord
	str r0, [sp, #8]
	add r0, r5, #0
	bl MapObject_GetZCoord
	add r2, r0, #0
	ldr r1, [sp, #8]
	add r0, r4, #0
	str r2, [sp, #4]
	bl GetMetatileBehavior
	add r6, r0, #0
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	bl MetatileBehavior_IsTallGrass
	cmp r0, #1
	bne _02066516
	add r0, r5, #0
	mov r1, #0
	bl ov01_021FF070
	b _0206652A
_02066516:
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #1
	bne _0206652A
	add r0, r5, #0
	mov r1, #0
	bl ov01_021FF8F0
_0206652A:
	add r0, r5, #0
	bl ov01_022055DC
	cmp r0, #0
	beq _02066596
	add r0, r5, #0
	bl MapObject_GetFacingDirection
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r0, #0xfe
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bhi _02066596
	add r0, r5, #0
	add r1, sp, #8
	add r2, sp, #4
	bl ov01_02205604
	ldr r1, [sp, #8]
	ldr r2, [sp, #4]
	add r0, r4, #0
	bl GetMetatileBehavior
	add r4, r0, #0
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	bl MetatileBehavior_IsTallGrass
	cmp r0, #1
	bne _0206657C
	mov r1, #1
	str r1, [sp]
	ldr r2, [sp, #8]
	ldr r3, [sp, #4]
	add r0, r5, #0
	bl ov01_021FF0E4
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
_0206657C:
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #1
	bne _02066596
	mov r1, #1
	str r1, [sp]
	ldr r2, [sp, #8]
	ldr r3, [sp, #4]
	add r0, r5, #0
	bl ov01_021FF964
_02066596:
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_020664D8
