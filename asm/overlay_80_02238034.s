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

	thumb_func_start ov80_022380A0
ov80_022380A0: ; 0x022380A0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r2, #0
	str r0, [sp]
	str r1, [sp, #4]
	add r7, r3, #0
	mov r4, #0
	add r5, r6, #0
_022380B0:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	add r2, r4, #0
	bl ov80_02238034
	mov r1, #0
	strh r0, [r5]
	cmp r4, #0
	ble _022380D6
	lsl r0, r4, #1
	ldrh r3, [r6, r0]
	add r2, r6, #0
_022380C8:
	ldrh r0, [r2]
	cmp r0, r3
	beq _022380D6
	add r1, r1, #1
	add r2, r2, #2
	cmp r1, r4
	blt _022380C8
_022380D6:
	cmp r1, r4
	bne _022380DE
	add r5, r5, #2
	add r4, r4, #1
_022380DE:
	cmp r4, r7
	blt _022380B0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_022380A0
