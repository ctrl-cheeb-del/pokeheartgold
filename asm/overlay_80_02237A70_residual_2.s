	.include "asm/macros.inc"
	.public _02237A86
	.public _02237A8E
	.public _02237A94
	.public _02237A9C
	.public _02237AAA
	.public _02237AB6
	.public _02237AC4
	.public _02237AC8
	.public _02237ACC
	.public _02237AD0
	.public _02237AD4
	.public _02237AD8
	.public _02237AEC
	.public _02237B04
	.public _02237B12
	.public _02237B1A
	.public _02237B36
	.public _02237B3E
	.public _02237B42
	.public _02237B4A
	.public _02237B4E
	.public _02237B6A
	.public _02237B72
	.public _02237B76
	.public _02237B7E
	.public _02237B82
	.public _02237BF0
	.public _02237BF2
	.public _02237C04
	.public _02237C2A
	.public _02237C70
	.public _02237C90
	.public _02237CB0
	.public _02237CC0
	.public _02237D28
	.public _02237D4E
	.public _02237D54
	.public _02237D6C
	.public _02237D74
	.public _02237D78
	.public _02237D7C
	.public _02237D80
	.public _02237D84
	.public _02237D94
	.public _02237D98
	.public _02237DAC
	.public _02237DDE
	.public _02237DEC
	.public _02237DF2
	.public _02237E5A
	.public _02237E7E
	.public _02237EA8
	.public _02237EC0
	.public _02237ECA
	.public _02237ECE
	.public _02237ED0
	.public _02237ED4
	.public _02237EF4
	.public _02237EF8
	.public _02237F4E
	.public _02237F6A
	.public _02237F74
	.public _02237F84
	.public _02237FA2
	.public _0223800E
	.public _02238030
	.public ov80_02237A70
	.public ov80_02237ADC
	.public ov80_02237B24
	.public ov80_02237B58
	.public ov80_02237B8C
	.public ov80_02237D5C
	.public ov80_02237D88
	.public ov80_02237D8C
	.public ov80_02237D9C
	.public ov80_02237DF4
	.public ov80_02237E18
	.public ov80_02237E30
	.public ov80_02237E88
	.public ov80_02237ED8
	.public ov80_02237EFC
	.public ov80_02237F3C
	.public ov80_02237F9C
	.public ov80_02237FA4
	.public ov80_0223D4D4
	.public ov80_0223D4D6
	.public ov80_0223D4D8
	.public ov80_0223D4DA
	.include "overlay_80_02237A70.inc"
	.include "global.inc"

    .text
	.public ov80_02237A70
	.public ov80_02237B24
	.public ov80_02237B58
	.public ov80_02237D5C
	.public ov80_02237D88
	.public ov80_02237D8C
	.public ov80_02237D9C
	.public ov80_02237DF4
	.public ov80_02237E18
	.public ov80_02237E30
	.public ov80_02237E88
	.public ov80_02237ED8
	.public ov80_02237EFC
	.public ov80_02237F9C
	.public ov80_02237FA4

	thumb_func_start ov80_02237B8C
ov80_02237B8C: ; 0x02237B8C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x48
	add r5, r0, #0
	ldrb r0, [r5, #0x10]
	add r6, r1, #0
	mov r1, #0
	bl ov80_02237B24
	str r0, [sp, #0x10]
	ldrb r0, [r5, #0x10]
	mov r1, #0
	bl ov80_02237B58
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x2c]
	bl HealParty
	ldrb r0, [r5, #0x10]
	bl ov80_02237D5C
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
	mov r1, #0x15
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r0, r0, #4
	str r1, [r4, r0]
	ldr r0, [r4, #4]
	ldr r1, [sp, #0x10]
	bl Party_InitWithMaxSize
	bl sub_0203769C
	cmp r0, #0
	bne _02237BF0
	mov r6, #0
	b _02237BF2
_02237BF0:
	mov r6, #2
_02237BF2:
	mov r0, #0xb
	bl AllocMonZeroed
	add r7, r0, #0
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	cmp r0, #0
	ble _02237C2A
_02237C04:
	ldr r0, [r5, #0x28]
	add r1, r6, #0
	bl Party_GetMonByIndex
	add r1, r7, #0
	bl CopyPokemonToPokemon
	add r0, r4, #0
	add r1, r7, #0
	mov r2, #0
	bl BattleSetup_AddMonToParty
	ldr r0, [sp, #0x14]
	add r6, r6, #1
	add r1, r0, #1
	ldr r0, [sp, #0x10]
	str r1, [sp, #0x14]
	cmp r1, r0
	blt _02237C04
_02237C2A:
	add r0, r7, #0
	bl Heap_Free
	add r0, r4, #0
	bl BattleSetup_SetAllySideBattlersToPlayer
	ldrb r1, [r5, #0x11]
	add r0, sp, #0x18
	mov r2, #0xb
	lsl r1, r1, #1
	add r1, r5, r1
	ldrh r1, [r1, #0x30]
	mov r3, #0xcc
	bl ov80_02229F04
	bl Heap_Free
	mov r0, #0xb
	str r0, [sp]
	ldr r2, [sp, #0xc]
	add r0, r4, #0
	add r1, sp, #0x18
	mov r3, #1
	bl ov80_0222A480
	ldrb r0, [r5, #0x10]
	mov r1, #0
	bl ov80_02237B58
	add r1, r0, #0
	ldr r0, [r4, #8]
	bl Party_InitWithMaxSize
	mov r7, #0
	add r6, r4, #0
_02237C70:
	add r0, r5, #0
	bl ov80_02237E88
	str r0, [r6, #0x34]
	add r7, r7, #1
	add r6, #0x34
	cmp r7, #4
	blt _02237C70
	mov r0, #0xb
	bl AllocMonZeroed
	add r7, r0, #0
	ldr r0, [sp, #0xc]
	mov r6, #0
	cmp r0, #0
	ble _02237CB0
_02237C90:
	ldr r0, [r5, #0x2c]
	add r1, r6, #0
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
	blt _02237C90
_02237CB0:
	add r0, r7, #0
	bl Heap_Free
	ldrb r0, [r5, #0x10]
	cmp r0, #2
	beq _02237CC0
	cmp r0, #3
	bne _02237D54
_02237CC0:
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
	ldrb r1, [r5, #0x11]
	add r0, sp, #0x18
	mov r2, #0xb
	add r1, r1, #7
	lsl r1, r1, #1
	add r1, r5, r1
	ldrh r1, [r1, #0x30]
	mov r3, #0xcc
	bl ov80_02229F04
	bl Heap_Free
	mov r0, #0xb
	str r0, [sp]
	ldr r2, [sp, #0xc]
	add r0, r4, #0
	add r1, sp, #0x18
	mov r3, #3
	bl ov80_0222A480
	ldrb r0, [r5, #0x10]
	mov r1, #0
	bl ov80_02237B58
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
	ble _02237D4E
	add r6, r0, #0
_02237D28:
	ldr r0, [r5, #0x2c]
	add r1, r6, #0
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
	blt _02237D28
_02237D4E:
	add r0, r7, #0
	bl Heap_Free
_02237D54:
	add r0, r4, #0
	add sp, #0x48
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_02237B8C
