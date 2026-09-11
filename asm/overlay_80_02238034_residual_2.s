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

	thumb_func_start BattleArcade_NewBattleSetup
BattleArcade_NewBattleSetup: ; 0x02238150
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x50
	add r7, r0, #0
	ldrb r0, [r7, #0x10]
	add r5, r1, #0
	mov r1, #0
	bl BattleArcade_GetMonCount
	str r0, [sp, #0x10]
	ldrb r0, [r7, #0x10]
	mov r1, #0
	bl BattleArcade_GetOpponentMonCount
	str r0, [sp, #0xc]
	ldrb r0, [r7, #0x10]
	bl ov80_02238344
	add r1, r0, #0
	mov r0, #0xb
	bl BattleSetup_New
	ldr r1, [r5, #0xc]
	add r4, r0, #0
	str r1, [sp]
	ldr r1, [r5, #0x1c]
	str r1, [sp, #4]
	ldr r2, [r5, #8]
	ldr r3, [r5, #0x18]
	mov r1, #0
	bl sub_02051D18
	mov r1, #0x53
	lsl r1, r1, #2
	mov r2, #0x14
	str r2, [r4, r1]
	add r0, r1, #4
	str r2, [r4, r0]
	ldr r0, [r7, #0x14]
	add r1, #0x28
	str r0, [r4, r1]
	ldr r0, [r7, #0x74]
	ldr r1, [r7, #0x70]
	str r0, [sp, #0x14]
	ldrb r0, [r7, #0x13]
	str r1, [sp, #0x18]
	cmp r0, #0x1b
	bne _022381B4
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r1, [sp, #0x14]
_022381B4:
	ldr r0, [r4, #4]
	ldr r1, [sp, #0x10]
	bl Party_InitWithMaxSize
	bl sub_0203769C
	cmp r0, #0
	bne _022381C8
	mov r5, #0
	b _022381CA
_022381C8:
	mov r5, #2
_022381CA:
	mov r0, #0xb
	bl AllocMonZeroed
	add r6, r0, #0
	mov r0, #0
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	cmp r0, #0
	ble _02238202
_022381DC:
	ldr r0, [sp, #0x18]
	add r1, r5, #0
	bl Party_GetMonByIndex
	add r1, r6, #0
	bl CopyPokemonToPokemon
	add r0, r4, #0
	add r1, r6, #0
	mov r2, #0
	bl BattleSetup_AddMonToParty
	ldr r0, [sp, #0x1c]
	add r5, r5, #1
	add r1, r0, #1
	ldr r0, [sp, #0x10]
	str r1, [sp, #0x1c]
	cmp r1, r0
	blt _022381DC
_02238202:
	add r0, r6, #0
	bl Heap_Free
	add r0, r4, #0
	bl BattleSetup_SetAllySideBattlersToPlayer
	ldrb r1, [r7, #0x11]
	add r0, sp, #0x20
	mov r2, #0xb
	lsl r1, r1, #1
	add r1, r7, r1
	add r1, #0x78
	ldrh r1, [r1]
	mov r3, #0xcc
	bl ov80_02229F04
	bl Heap_Free
	mov r0, #0xb
	str r0, [sp]
	ldr r2, [sp, #0xc]
	add r0, r4, #0
	add r1, sp, #0x20
	mov r3, #1
	bl ov80_0222A480
	ldrb r0, [r7, #0x10]
	mov r1, #0
	bl BattleArcade_GetOpponentMonCount
	add r1, r0, #0
	ldr r0, [r4, #8]
	bl Party_InitWithMaxSize
	mov r6, #0
	add r5, r4, #0
_0223824A:
	add r0, r7, #0
	bl ov80_02238444
	str r0, [r5, #0x34]
	add r6, r6, #1
	add r5, #0x34
	cmp r6, #4
	blt _0223824A
	mov r0, #0xb
	bl AllocMonZeroed
	add r6, r0, #0
	ldr r0, [sp, #0xc]
	mov r5, #0
	cmp r0, #0
	ble _0223828A
_0223826A:
	ldr r0, [sp, #0x14]
	add r1, r5, #0
	bl Party_GetMonByIndex
	add r1, r6, #0
	bl CopyPokemonToPokemon
	add r0, r4, #0
	add r1, r6, #0
	mov r2, #1
	bl BattleSetup_AddMonToParty
	ldr r0, [sp, #0xc]
	add r5, r5, #1
	cmp r5, r0
	blt _0223826A
_0223828A:
	add r0, r6, #0
	bl Heap_Free
	ldrb r0, [r7, #0x10]
	cmp r0, #2
	beq _0223829A
	cmp r0, #3
	bne _02238330
_0223829A:
	add r0, r4, #0
	bl BattleSetup_SetAllySideBattlersToPlayer
	bl sub_0203769C
	mov r1, #1
	sub r0, r1, r0
	bl sub_02034818
	mov r1, #1
	lsl r1, r1, #8
	ldr r1, [r4, r1]
	bl PlayerProfile_Copy
	ldrb r1, [r7, #0x11]
	add r0, sp, #0x20
	mov r2, #0xb
	add r1, r1, #7
	lsl r1, r1, #1
	add r1, r7, r1
	add r1, #0x78
	ldrh r1, [r1]
	mov r3, #0xcc
	bl ov80_02229F04
	bl Heap_Free
	mov r0, #0xb
	str r0, [sp]
	ldr r2, [sp, #0xc]
	add r0, r4, #0
	add r1, sp, #0x20
	mov r3, #3
	bl ov80_0222A480
	ldrb r0, [r7, #0x10]
	mov r1, #0
	bl BattleArcade_GetOpponentMonCount
	add r1, r0, #0
	ldr r0, [r4, #0x10]
	bl Party_InitWithMaxSize
	mov r0, #0xb
	bl AllocMonZeroed
	add r6, r0, #0
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	cmp r0, #0
	ble _0223832A
	add r5, r0, #0
_02238304:
	ldr r0, [sp, #0x14]
	add r1, r5, #0
	bl Party_GetMonByIndex
	add r1, r6, #0
	bl CopyPokemonToPokemon
	add r0, r4, #0
	add r1, r6, #0
	mov r2, #3
	bl BattleSetup_AddMonToParty
	ldr r0, [sp, #8]
	add r5, r5, #1
	add r1, r0, #1
	ldr r0, [sp, #0xc]
	str r1, [sp, #8]
	cmp r1, r0
	blt _02238304
_0223832A:
	add r0, r6, #0
	bl Heap_Free
_02238330:
	ldr r0, [r7, #0x70]
	bl HealParty
	ldr r0, [r7, #0x74]
	bl HealParty
	add r0, r4, #0
	add sp, #0x50
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end BattleArcade_NewBattleSetup


	thumb_func_start ov80_02238344
ov80_02238344: ; 0x02238344
	cmp r0, #3
	bhi _0223836C
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02238354: ; jump table
	.short _0223835C - _02238354 - 2 ; case 0
	.short _02238360 - _02238354 - 2 ; case 1
	.short _02238364 - _02238354 - 2 ; case 2
	.short _02238368 - _02238354 - 2 ; case 3
_0223835C:
	mov r0, #0x81
	bx lr
_02238360:
	mov r0, #0x83
	bx lr
_02238364:
	mov r0, #0x8f
	bx lr
_02238368:
	mov r0, #0x8f
	bx lr
_0223836C:
	mov r0, #0x81
	bx lr
	thumb_func_end ov80_02238344
