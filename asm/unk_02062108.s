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
	.include "unk_02062108.inc"
	.include "global.inc"

	.data

	.public _0210FACC
_0210FACC:
	.word _020FDA84
	.word _020FDAC4
	.word _020FDB04

	.text

	thumb_func_start EventObjectMovementMan_Create
EventObjectMovementMan_Create: ; 0x02062214
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	mov r0, #4
	mov r1, #0x14
	bl Heap_AllocAtEnd
	add r4, r0, #0
	bne _0206222A
	bl GF_AssertFail
_0206222A:
	add r2, r4, #0
	mov r1, #0x14
	mov r0, #0
_02062230:
	strb r0, [r2]
	add r2, r2, #1
	sub r1, r1, #1
	bne _02062230
	add r0, r5, #0
	bl MapObject_GetManager
	bl MapObjectManager_GetPriority
	sub r2, r0, #1
	ldr r0, _0206225C ; =MovementScriptMachine
	add r1, r4, #0
	bl SysTask_CreateOnMainQueue
	add r7, r0, #0
	bne _02062254
	bl GF_AssertFail
_02062254:
	str r5, [r4, #0xc]
	str r6, [r4, #0x10]
	add r0, r7, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0206225C: .word MovementScriptMachine
	thumb_func_end EventObjectMovementMan_Create
	thumb_func_start EventObjectMovementMan_IsFinish
EventObjectMovementMan_IsFinish: ; 0x02062260
	push {r3, lr}
	bl SysTask_GetData
	ldr r0, [r0, #4]
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end EventObjectMovementMan_IsFinish
	thumb_func_start EventObjectMovementMan_Delete
EventObjectMovementMan_Delete: ; 0x0206226C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl SysTask_GetData
	add r4, r0, #0
	ldr r0, [r4, #0xc]
	bl MapObject_IsMovementPaused
	cmp r0, #1
	beq _02062284
	bl GF_AssertFail
_02062284:
	ldr r0, [r4, #0xc]
	bl MapObject_ClearHeldMovementIfActive
	mov r0, #4
	add r1, r4, #0
	bl Heap_FreeExplicit
	add r0, r5, #0
	bl SysTask_Destroy
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end EventObjectMovementMan_Delete
	thumb_func_start MovementScriptMachine
MovementScriptMachine: ; 0x0206229C
	push {r3, r4, r5, lr}
	ldr r4, _020622B4 ; =sMovementScriptMachineStateFuncs
	add r5, r1, #0
_020622A2:
	ldr r1, [r5]
	add r0, r5, #0
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	blx r1
	cmp r0, #1
	beq _020622A2
	pop {r3, r4, r5, pc}
	nop
_020622B4: .word sMovementScriptMachineStateFuncs
	thumb_func_end MovementScriptMachine
	thumb_func_start MovementScriptMachineSub_Init
MovementScriptMachineSub_Init: ; 0x020622B8
	mov r1, #0
	str r1, [r0, #8]
	mov r1, #1
	str r1, [r0]
	add r0, r1, #0
	bx lr
	thumb_func_end MovementScriptMachineSub_Init
	thumb_func_start MovementScriptMachineSub_WaitReady
MovementScriptMachineSub_WaitReady: ; 0x020622C4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0xc]
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #0
	bne _020622D6
	mov r0, #0
	pop {r4, pc}
_020622D6:
	mov r0, #2
	str r0, [r4]
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end MovementScriptMachineSub_WaitReady
	thumb_func_start MovementScriptMachineSub_SetMovementCommand
MovementScriptMachineSub_SetMovementCommand: ; 0x020622E0
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0xc]
	ldrh r1, [r1]
	bl MapObject_SetHeldMovement
	mov r0, #3
	str r0, [r4]
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end MovementScriptMachineSub_SetMovementCommand
	thumb_func_start MovementScriptMachineSub_WaitMovementCommand
MovementScriptMachineSub_WaitMovementCommand: ; 0x020622F8
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0xc]
	bl MapObject_IsMovementPaused
	cmp r0, #0
	bne _0206230A
	mov r0, #0
	pop {r4, pc}
_0206230A:
	mov r0, #4
	str r0, [r4]
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end MovementScriptMachineSub_WaitMovementCommand
	thumb_func_start MovementScriptMachineSub_LoopCheck
MovementScriptMachineSub_LoopCheck: ; 0x02062314
	ldr r1, [r0, #8]
	ldr r3, [r0, #0x10]
	add r2, r1, #1
	str r2, [r0, #8]
	ldrh r1, [r3, #2]
	cmp r2, r1
	bge _0206232A
	mov r1, #1
	str r1, [r0]
	add r0, r1, #0
	bx lr
_0206232A:
	add r1, r3, #4
	str r1, [r0, #0x10]
	ldrh r1, [r3, #4]
	cmp r1, #0xfe ; EndMovement
	beq _0206233C
	mov r1, #0
	str r1, [r0]
	mov r0, #1
	bx lr
_0206233C:
	mov r1, #1
	str r1, [r0, #4]
	mov r1, #5
	str r1, [r0]
	mov r0, #0
	bx lr
	thumb_func_end MovementScriptMachineSub_LoopCheck
	thumb_func_start MovementScriptMachineSub_Done
MovementScriptMachineSub_Done: ; 0x02062348
	mov r0, #0
	bx lr
	thumb_func_end MovementScriptMachineSub_Done
	thumb_func_start sub_0206234C
sub_0206234C: ; 0x0206234C
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r4, r1, #0
	cmp r7, #4
	blt _0206235A
	bl GF_AssertFail
_0206235A:
	ldr r3, _0206238C ; =_020FD198
	ldr r6, [r3]
	cmp r6, #0
	beq _02062384
	mov r1, #0
_02062364:
	add r2, r1, #0
	add r5, r6, #0
_02062368:
	ldr r0, [r5]
	cmp r4, r0
	bne _02062374
	lsl r0, r7, #2
	ldr r0, [r6, r0]
	pop {r3, r4, r5, r6, r7, pc}
_02062374:
	add r2, r2, #1
	add r5, r5, #4
	cmp r2, #4
	blt _02062368
	add r3, r3, #4
	ldr r6, [r3]
	cmp r6, #0
	bne _02062364
_02062384:
	bl GF_AssertFail
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0206238C: .word _020FD198
	thumb_func_end sub_0206234C
	thumb_func_start sub_02062390
sub_02062390: ; 0x02062390
	push {r4, r5}
	ldr r4, _020623C4 ; =_020FD198
	ldr r5, [r4]
	cmp r5, #0
	beq _020623BA
	mov r2, #0
_0206239C:
	add r3, r2, #0
_0206239E:
	ldr r1, [r5]
	cmp r0, r1
	bne _020623AA
	add r0, r3, #0
	pop {r4, r5}
	bx lr
_020623AA:
	add r3, r3, #1
	add r5, r5, #4
	cmp r3, #4
	blt _0206239E
	add r4, r4, #4
	ldr r5, [r4]
	cmp r5, #0
	bne _0206239C
_020623BA:
	mov r0, #0
	mvn r0, r0
	pop {r4, r5}
	bx lr
	nop
_020623C4: .word _020FD198
	thumb_func_end sub_02062390
	thumb_func_start sub_020623C8
sub_020623C8: ; 0x020623C8
	sub r0, #0x38
	cmp r0, #3
	bhi _020623D2
	mov r0, #1
	bx lr
_020623D2:
	mov r0, #0
	bx lr
	.balign 4, 0
	thumb_func_end sub_020623C8
	thumb_func_start sub_020623D8
sub_020623D8: ; 0x020623D8
	push {r4, lr}
	sub sp, #0x10
	ldr r3, _020623FC ; =_020FDA28
	add r2, sp, #0
	add r4, r0, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	cmp r4, #4
	blt _020623F2
	bl GF_AssertFail
_020623F2:
	lsl r1, r4, #2
	add r0, sp, #0
	ldr r0, [r0, r1]
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_020623FC: .word _020FDA28
	thumb_func_end sub_020623D8
	thumb_func_start sub_02062400
sub_02062400: ; 0x02062400
	push {r3, r4, r5, lr}
	add r5, r0, #0
_02062404:
	add r0, r5, #0
	bl MapObject_GetMovementCommand
	add r4, r0, #0
	cmp r4, #0xff
	beq _02062424
	add r0, r5, #0
	bl MapObject_GetMovementStep
	add r2, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl MapObject_RunMovementCommand
	cmp r0, #0
	bne _02062404
_02062424:
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_02062400
	thumb_func_start sub_02062428
sub_02062428: ; 0x02062428
	push {r4, lr}
	add r4, r0, #0
	bl sub_02062400
	add r0, r4, #0
	mov r1, #0x20
	bl MapObject_TestFlagsBits
	cmp r0, #0
	bne _02062440
	mov r0, #0
	pop {r4, pc}
_02062440:
	add r0, r4, #0
	mov r1, #0x20
	bl MapObject_ClearFlagsBits
	add r0, r4, #0
	mov r1, #0xff
	bl MapObject_SetMovementCommand
	add r0, r4, #0
	mov r1, #0
	bl MapObject_SetMovementStep
	mov r0, #1
	pop {r4, pc}
	thumb_func_end sub_02062428
	thumb_func_start MapObject_RunMovementCommand
MapObject_RunMovementCommand: ; 0x0206245C
	push {r3, lr}
	lsl r3, r1, #2
	ldr r1, _0206246C ; =gMovementCmdTable
	ldr r3, [r1, r3]
	lsl r1, r2, #2
	ldr r1, [r3, r1]
	blx r1
	pop {r3, pc}
	.balign 4, 0
_0206246C: .word gMovementCmdTable
	thumb_func_end MapObject_RunMovementCommand
	thumb_func_start MapObjectMovementCmd098_Step2
MapObjectMovementCmd098_Step2: ; 0x02062470
	push {r3, lr}
	mov r1, #0x20
	bl MapObject_SetFlagsBits
	mov r0, #0
	pop {r3, pc}
	thumb_func_end MapObjectMovementCmd098_Step2
	thumb_func_start sub_0206247C
sub_0206247C: ; 0x0206247C
	push {r4, lr}
	add r4, r0, #0
	bl MapObject_SetFacingDirection
	add r0, r4, #0
	mov r1, #0
	bl sub_0205F328
	add r0, r4, #0
	bl sub_02060F78
	add r0, r4, #0
	bl MapObject_IncrementMovementStep
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_0206247C

	.rodata

	.public _020FDA1C
_020FDA1C:
	.byte 0x00, 0x50, 0x00, 0x00
	.byte 0x00, 0x60, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00
	.public _020FDA28
_020FDA28:
	.byte 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00
	.byte 0x0A, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00
	.public sMovementScriptMachineStateFuncs
sMovementScriptMachineStateFuncs:
	.word MovementScriptMachineSub_Init
	.word MovementScriptMachineSub_WaitReady
	.word MovementScriptMachineSub_SetMovementCommand
	.word MovementScriptMachineSub_WaitMovementCommand
	.word MovementScriptMachineSub_LoopCheck
	.word MovementScriptMachineSub_Done
	.public _020FDA50
_020FDA50:
	.byte 0x00, 0x20, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00
	.byte 0x00, 0x30, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00
	.public _020FDA68
_020FDA68:
	.byte 0x00, 0x25, 0x00, 0x00, 0x80, 0x24, 0x00, 0x00
	.byte 0x80, 0x24, 0x00, 0x00, 0x80, 0x24, 0x00, 0x00, 0x80, 0x24, 0x00, 0x00, 0x80, 0x24, 0x00, 0x00
	.byte 0x80, 0x24, 0x00, 0x00
	.public _020FDA84
	.public _020FDA84
_020FDA84:
	.byte 0x00, 0x40, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00
	.byte 0x00, 0xA0, 0x00, 0x00, 0x00, 0xB0, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00
	.byte 0x00, 0xC0, 0x00, 0x00, 0x00, 0xB0, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00
	.byte 0x00, 0x80, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.public _020FDAC4
	.public _020FDAC4
_020FDAC4:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00
	.byte 0x00, 0x40, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00
	.byte 0x00, 0x60, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00
	.byte 0x00, 0x30, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.public _020FDB04
	.public _020FDB04
_020FDB04:
	.byte 0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00
	.byte 0x00, 0x80, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x00
	.byte 0x00, 0xA0, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00
	.byte 0x00, 0x50, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
