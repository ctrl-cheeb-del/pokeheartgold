	.public _02236B80
	.public _02236B94
	.public _02236B9C
	.public _02236BA4
	.public _02236BB2
	.public _02236BBE
	.public _02236BCC
	.public _02236BD0
	.public _02236BD4
	.public _02236BD8
	.public _02236BDC
	.public _02236BE0
	.public _02236BF4
	.public _02236C0C
	.public _02236C1A
	.public _02236C22
	.public _02236C38
	.public _02236C3C
	.public _02236C4A
	.public _02236C58
	.public _02236C62
	.public _02236C6C
	.public _02236C70
	.public _02236C74
	.public _02236C7E
	.public _02236C8A
	.public _02236C94
	.public _02236C98
	.public _02236CBA
	.public _02236CD6
	.public _02236CE0
	.public _02236CE8
	.public _02236CFC
	.public _02236D30
	.public _02236D4A
	.public _02236D64
	.public _02236D78
	.public _02236D8E
	.public _02236DA4
	.public _02236DC2
	.public _02236DC8
	.public _02236DD0
	.public _02236DE4
	.public _02236DEC
	.public _02236DF0
	.public _02236DF4
	.public _02236E08
	.public _02236E10
	.public _02236E14
	.public _02236E1C
	.public _02236E20
	.public _02236E56
	.public _02236E70
	.public _02236EB4
	.public _02236EBA
	.public _02236EE4
	.public _02236F94
	.public _02236FB6
	.public _02236FFC
	.public _0223701C
	.public _0223703E
	.public _0223704E
	.public _022370B6
	.public _022370DE
	.public _022370E4
	.public _022370EC
	.public _022370F0
	.public _02237104
	.public _0223710C
	.public _02237110
	.public _02237114
	.public _02237118
	.public _0223711C
	.public _0223712A
	.public _02237178
	.public _022371A8
	.public _022371AC
	.public _022371C6
	.public _022371D4
	.public _02237208
	.public _02237248
	.public _0223724C
	.public _02237250
	.public _0223725C
	.public _02237260
	.public _02237284
	.public _0223729C
	.public _022372A6
	.public _022372AA
	.public _022372AC
	.public _022372B0
	.public _022372D0
	.public _022372D4
	.public ov80_02236B78
	.public ov80_02236BE4
	.public ov80_02236C2C
	.public ov80_02236C78
	.public ov80_02236C9C
	.public ov80_02236DD4
	.public ov80_02236DF8
	.public ov80_02236E24
	.public ov80_02236E90
	.public ov80_02236F24
	.public ov80_022370F4
	.public ov80_02237120
	.public ov80_02237130
	.public ov80_022371B0
	.public ov80_02237254
	.public ov80_02237264
	.public ov80_022372B4
	.public ov80_0223DD38
    .include "asm/macros.inc"
	.include "overlay_80_02236B78.inc"
	.include "global.inc"

    .text
	.public ov80_02236B78
	.public ov80_02236BE4
	.public ov80_02236C2C
	.public ov80_02236C78
	.public ov80_02236DD4
	.public ov80_02236DF8
	.public ov80_02236E24
	.public ov80_022370F4
	.public ov80_02237120
	.public ov80_02237130
	.public ov80_022371B0
	.public ov80_02237254
	.public ov80_022372B4

	thumb_func_start ov80_02236E90
ov80_02236E90: ; 0x02236E90
	push {r4, r5, r6, r7, lr}
	sub sp, #0x84
	str r0, [sp, #0x14]
	ldr r0, [sp, #0xa8]
	add r7, r3, #0
	str r0, [sp, #0xa8]
	add r0, r1, #0
	add r1, r2, #0
	bl ov80_02236C2C
	str r0, [sp, #0x18]
	mov r0, #0
	mov ip, r0
	ldr r0, [sp, #0xa8]
	cmp r0, #0
	ble _02236EE4
	add r4, sp, #0x34
	add r5, sp, #0x1c
_02236EB4:
	add r6, r7, #0
	add r3, sp, #0x4c
	mov r2, #7
_02236EBA:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02236EBA
	add r0, sp, #0x1c
	ldrh r0, [r0, #0x30]
	add r7, #0x38
	lsl r0, r0, #0x15
	lsr r0, r0, #0x15
	strh r0, [r4]
	add r0, sp, #0x1c
	ldrh r0, [r0, #0x32]
	add r4, r4, #2
	strh r0, [r5]
	mov r0, ip
	add r1, r0, #1
	ldr r0, [sp, #0xa8]
	add r5, r5, #2
	mov ip, r1
	cmp r1, r0
	blt _02236EB4
_02236EE4:
	ldr r0, [sp, #0x98]
	ldr r2, [sp, #0xa8]
	str r0, [sp]
	mov r0, #0xb
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	add r1, sp, #0x1c
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0xa0]
	str r0, [sp, #0x10]
	ldr r3, [sp, #0x14]
	add r0, sp, #0x34
	bl ov80_02236C9C
	ldr r0, [sp, #0xa4]
	ldr r1, [sp, #0x98]
	str r0, [sp]
	ldr r0, [sp, #0x14]
	ldr r2, [sp, #0xa0]
	str r0, [sp, #4]
	mov r0, #0xb
	str r0, [sp, #8]
	mov r0, #0xcd
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x9c]
	mov r3, #0
	bl ov80_0222A52C
	add sp, #0x84
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov80_02236E90


	thumb_func_start ov80_02236F24
ov80_02236F24: ; 0x02236F24
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r5, r0, #0
	ldrb r0, [r5, #4]
	add r6, r1, #0
	bl ov80_02236DD4
	str r0, [sp, #0x10]
	ldrb r0, [r5, #4]
	mov r1, #0
	bl ov80_02236DF8
	str r0, [sp, #0xc]
	ldr r0, _022370EC ; =0x000004D4
	ldr r0, [r5, r0]
	bl HealParty
	ldr r0, _022370F0 ; =0x000004D8
	ldr r0, [r5, r0]
	bl HealParty
	ldrb r0, [r5, #4]
	bl ov80_022370F4
	add r1, r0, #0
	mov r0, #0xb
	bl BattleSetup_New
	ldr r1, [r6, #0xc]
	add r4, r0, #0
	str r1, [sp]
	ldr r1, [r6, #0x1c]
	str r1, [sp, #4]
	ldr r2, [r6, #8]
	ldr r3, [r6, #0x18]
	mov r1, #0
	bl sub_02051D18
	mov r0, #0x53
	mov r1, #0x13
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r0, r0, #4
	str r1, [r4, r0]
	ldr r0, [r4, #4]
	ldr r1, [sp, #0x10]
	bl Party_InitWithMaxSize
	mov r0, #0xb
	bl AllocMonZeroed
	add r7, r0, #0
	ldr r0, [sp, #0x10]
	mov r6, #0
	cmp r0, #0
	ble _02236FB6
_02236F94:
	ldr r0, _022370EC ; =0x000004D4
	add r1, r6, #0
	ldr r0, [r5, r0]
	bl Party_GetMonByIndex
	add r1, r7, #0
	bl CopyPokemonToPokemon
	add r0, r4, #0
	add r1, r7, #0
	mov r2, #0
	bl BattleSetup_AddMonToParty
	ldr r0, [sp, #0x10]
	add r6, r6, #1
	cmp r6, r0
	blt _02236F94
_02236FB6:
	add r0, r7, #0
	bl Heap_Free
	add r0, r4, #0
	bl BattleSetup_SetAllySideBattlersToPlayer
	ldrb r1, [r5, #6]
	add r0, sp, #0x14
	mov r2, #0xb
	lsl r1, r1, #1
	add r1, r5, r1
	ldrh r1, [r1, #0x18]
	mov r3, #0xcc
	bl ov80_02229F04
	bl Heap_Free
	mov r0, #0xb
	str r0, [sp]
	ldr r2, [sp, #0xc]
	add r0, r4, #0
	add r1, sp, #0x14
	mov r3, #1
	bl ov80_0222A480
	ldrb r0, [r5, #4]
	mov r1, #0
	bl ov80_02236DF8
	add r1, r0, #0
	ldr r0, [r4, #8]
	bl Party_InitWithMaxSize
	mov r7, #0
	add r6, r4, #0
_02236FFC:
	add r0, r5, #0
	bl ov80_02237264
	str r0, [r6, #0x34]
	add r7, r7, #1
	add r6, #0x34
	cmp r7, #4
	blt _02236FFC
	mov r0, #0xb
	bl AllocMonZeroed
	add r7, r0, #0
	ldr r0, [sp, #0xc]
	mov r6, #0
	cmp r0, #0
	ble _0223703E
_0223701C:
	ldr r0, _022370F0 ; =0x000004D8
	add r1, r6, #0
	ldr r0, [r5, r0]
	bl Party_GetMonByIndex
	add r1, r7, #0
	bl CopyPokemonToPokemon
	add r0, r4, #0
	add r1, r7, #0
	mov r2, #1
	bl BattleSetup_AddMonToParty
	ldr r0, [sp, #0xc]
	add r6, r6, #1
	cmp r6, r0
	blt _0223701C
_0223703E:
	add r0, r7, #0
	bl Heap_Free
	ldrb r0, [r5, #4]
	cmp r0, #2
	beq _0223704E
	cmp r0, #3
	bne _022370E4
_0223704E:
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
	ldrb r1, [r5, #6]
	add r0, sp, #0x14
	mov r2, #0xb
	add r1, r1, #7
	lsl r1, r1, #1
	add r1, r5, r1
	ldrh r1, [r1, #0x18]
	mov r3, #0xcc
	bl ov80_02229F04
	bl Heap_Free
	mov r0, #0xb
	str r0, [sp]
	ldr r2, [sp, #0xc]
	add r0, r4, #0
	add r1, sp, #0x14
	mov r3, #3
	bl ov80_0222A480
	ldrb r0, [r5, #4]
	mov r1, #0
	bl ov80_02236DF8
	add r1, r0, #0
	ldr r0, [r4, #0x10]
	bl Party_InitWithMaxSize
	mov r0, #0xb
	bl AllocMonZeroed
	add r7, r0, #0
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	cmp r0, #0
	ble _022370DE
	add r6, r0, #0
_022370B6:
	ldr r0, _022370F0 ; =0x000004D8
	add r1, r6, #0
	ldr r0, [r5, r0]
	bl Party_GetMonByIndex
	add r1, r7, #0
	bl CopyPokemonToPokemon
	add r0, r4, #0
	add r1, r7, #0
	mov r2, #3
	bl BattleSetup_AddMonToParty
	ldr r0, [sp, #8]
	add r6, r6, #1
	add r1, r0, #1
	ldr r0, [sp, #0xc]
	str r1, [sp, #8]
	cmp r1, r0
	blt _022370B6
_022370DE:
	add r0, r7, #0
	bl Heap_Free
_022370E4:
	add r0, r4, #0
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_022370EC: .word 0x000004D4
_022370F0: .word 0x000004D8
	thumb_func_end ov80_02236F24
