	.include "asm/macros.inc"
	.public BattleArcade_GetMonCount
	.public BattleArcade_GetOpponentMonCount
	.public BattleArcade_MultiplayerCheck
	.public BattleArcade_NewBattleSetup
	.public _0223804A
	.public _02238054
	.public _0223805A
	.public _02238062
	.public _02238070
	.public _0223807C
	.public _0223808C
	.public _02238090
	.public _02238094
	.public _02238098
	.public _0223809C
	.public _022380B0
	.public _022380C8
	.public _022380D6
	.public _022380DE
	.public _022380FA
	.public _02238102
	.public _02238106
	.public _0223810E
	.public _02238112
	.public _0223812E
	.public _02238136
	.public _0223813A
	.public _02238142
	.public _02238146
	.public _022381B4
	.public _022381C8
	.public _022381CA
	.public _022381DC
	.public _02238202
	.public _0223824A
	.public _0223826A
	.public _0223828A
	.public _0223829A
	.public _02238304
	.public _0223832A
	.public _02238330
	.public _02238354
	.public _0223835C
	.public _02238360
	.public _02238364
	.public _02238368
	.public _0223836C
	.public _0223837C
	.public _02238380
	.public _022383EC
	.public _02238424
	.public _02238440
	.public _02238466
	.public _0223847E
	.public _02238488
	.public _0223848C
	.public _0223848E
	.public _02238494
	.public _022384B4
	.public _022384B8
	.public _022384C4
	.public _022384CC
	.public _022384D4
	.public ov80_02238034
	.public ov80_022380A0
	.public ov80_02238344
	.public ov80_02238370
	.public ov80_02238384
	.public ov80_022383A8
	.public ov80_022383C0
	.public ov80_02238430
	.public ov80_02238444
	.public ov80_02238498
	.public ov80_022384BC
	.public ov80_0223D514
	.public ov80_0223D516
	.public ov80_0223D518
	.public ov80_0223D51A
	.include "overlay_80_02238034.inc"
	.include "global.inc"

    .text
	.public BattleArcade_GetMonCount
	.public BattleArcade_GetOpponentMonCount
	.public BattleArcade_MultiplayerCheck
	.public ov80_02238034
	.public ov80_02238370
	.public ov80_02238384
	.public ov80_022383A8
	.public ov80_02238430
	.public ov80_02238444
	.public ov80_02238498
	.public ov80_022384BC

	thumb_func_start ov80_022383C0
ov80_022383C0: ; 0x022383C0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, [r5, #0x74]
	bl SaveArray_Party_Init
	ldrb r0, [r5, #0x10]
	mov r1, #1
	bl BattleArcade_GetOpponentMonCount
	str r0, [sp]
	mov r0, #0xb
	bl AllocMonZeroed
	add r7, r0, #0
	ldr r0, [sp]
	mov r6, #0
	cmp r0, #0
	ble _02238424
	mov r0, #0x33
	lsl r0, r0, #4
	add r4, r5, r0
_022383EC:
	add r0, r5, #0
	bl ov80_02238370
	add r2, r0, #0
	add r0, r4, #0
	add r1, r7, #0
	bl ov80_0222A140
	ldr r1, [r5, #0x74]
	add r0, r5, #0
	add r2, r7, #0
	bl ov80_022383A8
	ldr r0, [r5, #0x74]
	add r1, r6, #0
	bl Party_GetMonByIndex
	mov r1, #0
	str r1, [sp, #4]
	mov r1, #6
	add r2, sp, #4
	bl SetMonData
	ldr r0, [sp]
	add r6, r6, #1
	add r4, #0x38
	cmp r6, r0
	blt _022383EC
_02238424:
	add r0, r7, #0
	bl Heap_Free
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_022383C0
