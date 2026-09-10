#include "config.h"
#include "constants/pokemon.h"
#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_12_022378C0.inc"
	.include "global.inc"

	.text
	.public _0226BFD8
	.public ov12_02237D00
	.public ov12_02237ED0
	.public ov12_02237F18
	.public ov12_02238358
	.public ov12_0223843C
	.public ov12_022387AC
	.public ov12_022389B8
	.public ov12_02238A68
	.public ov12_02239664
	.public ov12_02239730
	.public ov12_022397E4
	.public ov12_02239854
	.public ov12_022399D4
	.public ov12_02239C28
	.public ov12_0223A0D4
	.public ov12_0223A260
	.public ov12_0223A3F0
	.public ov12_0223A664
	.public ov12_0226BFDC
	.public ov12_0226BFE0
	.public ov12_0226BFE8
	.public ov12_0226BFF8
	.public ov12_0226C008
	.public ov12_0226C018
	.public ov12_0226C02C
	.public ov12_0226C044
	.public ov12_0226C060
	.public ov12_0226C080
	.public ov12_0226C0A8
	.public ov12_0226C0D0
	.public ov12_0226C0F8
	.public ov12_0226C120
	.public ov12_0226C174
	.public ov12_0226C1C8
	.public ov12_0226C2DC

	.public ov12_02238A30
	.public ov12_02238A64
	.public ov12_022395BC
	.public ov12_02239644
	.public ov12_022396E8
	.public ov12_022396F0
	.public ov12_02239810
	.public ov12_0223998C
	.public ov12_022399BC
	.public ov12_0223A088
	.public ov12_0223A218
	.public ov12_0223A3A8
	.public ov12_0223A5E4
	.public ov12_0223A620
	.public ov12_0223A7A0

	thumb_func_start ov12_02239854
ov12_02239854: ; 0x02239854
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	add r0, r5, #0
	bl BattleSystem_GetMaxBattlers
	str r0, [sp]
	add r0, r5, #0
	mov r6, #0
	bl BattleSystem_GetCriticalHpMusicFlag
	add r4, r0, #0
	add r0, r5, #0
	bl BattleSystem_GetBattleType
	mov r1, #0x22
	lsl r1, r1, #4
	tst r0, r1
	beq _0223987A
	b _02239984
_0223987A:
	mov r0, #2
	tst r0, r4
	beq _02239898
	mov r0, #1
	tst r0, r4
	beq _02239984
	ldr r0, _02239988 ; =0x00000704
	add r1, r6, #0
	bl StopSE
	add r0, r5, #0
	mov r1, #2
	bl BattleSystem_SetCriticalHpMusicFlag
	pop {r3, r4, r5, r6, r7, pc}
_02239898:
	ldr r0, [sp]
	add r4, r6, #0
	cmp r0, #0
	ble _02239906
_022398A0:
	add r0, r5, #0
	add r1, r4, #0
	bl BattleSystem_GetOpponentData
	add r7, r0, #0
	bl ov12_02261264
	cmp r0, #0
	bne _022398BE
	add r0, r5, #0
	bl BattleSystem_GetBattleSpecial
	mov r1, #0x10
	tst r0, r1
	beq _022398D6
_022398BE:
	add r0, r5, #0
	add r1, r4, #0
	bl BattleSystem_GetFieldSide
	cmp r0, #0
	bne _022398FE
	add r0, r5, #0
	bl BattleSystem_GetBattleSpecial
	mov r1, #0x10
	tst r0, r1
	beq _022398FE
_022398D6:
	add r0, r7, #0
	bl OpponentData_GetHpBar
	add r1, r0, #0
	beq _022398FE
	ldr r0, [r1, #0x28]
	ldr r1, [r1, #0x2c]
	lsl r0, r0, #0x10
	lsl r1, r1, #0x10
	lsr r0, r0, #0x10
	lsr r1, r1, #0x10
	mov r2, #0x30
	bl CalculateHpBarColor
	cmp r0, #1
	bne _022398FE
	add r0, r4, #0
	bl MaskOfFlagNo
	orr r6, r0
_022398FE:
	ldr r0, [sp]
	add r4, r4, #1
	cmp r4, r0
	blt _022398A0
_02239906:
	cmp r6, #0
	beq _0223992C
	add r0, r5, #0
	bl BattleSystem_GetCriticalHpMusicFlag
	cmp r0, #0
	bne _0223992C
	ldr r0, _02239988 ; =0x00000704
	bl PlaySE
	add r0, r5, #0
	mov r1, #1
	bl BattleSystem_SetCriticalHpMusicFlag
	add r0, r5, #0
	mov r1, #4
	bl BattleSystem_SetCriticalHpMusicDelay
	b _0223994A
_0223992C:
	cmp r6, #0
	bne _0223994A
	add r0, r5, #0
	bl BattleSystem_GetCriticalHpMusicFlag
	cmp r0, #0
	beq _0223994A
	ldr r0, _02239988 ; =0x00000704
	mov r1, #0
	bl StopSE
	add r0, r5, #0
	mov r1, #0
	bl BattleSystem_SetCriticalHpMusicFlag
_0223994A:
	add r0, r5, #0
	bl BattleSystem_GetCriticalHpMusicFlag
	cmp r0, #0
	beq _02239984
	add r0, r5, #0
	bl BattleSystem_GetCriticalHpMusicDelay
	add r4, r0, #0
	ldr r0, _02239988 ; =0x00000704
	bl IsSEPlaying
	cmp r0, #0
	bne _02239984
	sub r1, r4, #1
	bne _0223997A
	ldr r0, _02239988 ; =0x00000704
	bl PlaySE
	add r0, r5, #0
	mov r1, #4
	bl BattleSystem_SetCriticalHpMusicDelay
	pop {r3, r4, r5, r6, r7, pc}
_0223997A:
	lsl r1, r1, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl BattleSystem_SetCriticalHpMusicDelay
_02239984:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02239988: .word 0x00000704
	thumb_func_end ov12_02239854
