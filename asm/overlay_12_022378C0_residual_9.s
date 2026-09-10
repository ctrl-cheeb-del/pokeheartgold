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

	thumb_func_start ov12_0223A3F0
ov12_0223A3F0: ; 0x0223A3F0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	bl OverlayManager_GetArgs
	add r7, r0, #0
	ldr r0, [r7]
	mov r1, #4
	tst r1, r0
	beq _0223A414
	mov r1, #0x63
	lsl r1, r1, #2
	ldr r2, [r7, r1]
	mov r1, #0x10
	tst r1, r2
	bne _0223A414
	mov r1, #0x80
	tst r0, r1
	beq _0223A41A
_0223A414:
	add sp, #0xc
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_0223A41A:
	bl sub_0203769C
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r0, _0223A5DC ; =FS_OVERLAY_ID(OVY_5)
	mov r1, #2
	bl HandleLoadOverlay
	mov r0, #5
	mov r1, #0x30
	bl Heap_Alloc
	add r6, r0, #0
	mov r0, #0x66
	lsl r0, r0, #2
	str r6, [r7, r0]
	mov r0, #0
	add r1, r6, #0
	mov r2, #0x30
	bl MIi_CpuClearFast
	str r7, [r6]
	ldr r0, [r7, #0x14]
	cmp r0, #5
	bhi _0223A4CE
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223A458: ; jump table
	.short _0223A4CE - _0223A458 - 2 ; case 0
	.short _0223A464 - _0223A458 - 2 ; case 1
	.short _0223A488 - _0223A458 - 2 ; case 2
	.short _0223A4AC - _0223A458 - 2 ; case 3
	.short _0223A4CE - _0223A458 - 2 ; case 4
	.short _0223A4AC - _0223A458 - 2 ; case 5
_0223A464:
	bl sub_02039998
	cmp r0, #0
	bne _0223A47A
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	mov r1, #0x16 ; GAME_STAT_LOCAL_LINK_BATTLE_WINS
	bl GameStats_Inc
	b _0223A4CE
_0223A47A:
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	mov r1, #0x1b ; GAME_STAT_WIFI_BATTLE_WINS
	bl GameStats_Inc
	b _0223A4CE
_0223A488:
	bl sub_02039998
	cmp r0, #0
	bne _0223A49E
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	mov r1, #0x17 ; GAME_STAT_LOCAL_LINK_BATTLE_LOSSES
	bl GameStats_Inc
	b _0223A4CE
_0223A49E:
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	mov r1, #0x1c ; GAME_STAT_WIFI_BATTLE_LOSSES
	bl GameStats_Inc
	b _0223A4CE
_0223A4AC:
	bl sub_02039998
	cmp r0, #0
	bne _0223A4C2
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	mov r1, #0x18 ; GAME_STAT_LOCAL_LINK_BATTLE_DRAWS
	bl GameStats_Inc
	b _0223A4CE
_0223A4C2:
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	mov r1, #0x1d ; GAME_STAT_WIFI_BATTLE_DRAWS
	bl GameStats_Inc
_0223A4CE:
	ldr r1, [r7]
	mov r0, #8
	tst r0, r1
	beq _0223A538
	mov r4, #0
	add r5, r7, #0
_0223A4DA:
	add r0, r4, #0
	bl sub_020378AC
	lsl r0, r0, #2
	ldr r1, [r5, #4]
	add r0, r6, r0
	str r1, [r0, #4]
	add r0, r4, #0
	bl sub_020378AC
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0xf8
	ldr r0, [r0]
	mov r1, #5
	bl PlayerProfile_GetPlayerName_NewString
	ldr r1, [sp, #8]
	add r4, r4, #1
	lsl r1, r1, #2
	add r1, r6, r1
	add r5, r5, #4
	str r0, [r1, #0x14]
	cmp r4, #4
	blt _0223A4DA
	mov r0, #5
	str r0, [r6, #0x24]
	add r0, r6, #0
	mov r1, #2
	add r0, #0x28
	strb r1, [r0]
	add r0, r6, #0
	mov r1, #1
	add r0, #0x29
	strb r1, [r0]
	ldr r1, [r7, #0x14]
	cmp r1, #5
	beq _0223A52E
	add r0, r6, #0
	add r0, #0x2a
	strb r1, [r0]
	b _0223A5C4
_0223A52E:
	add r0, r6, #0
	mov r1, #3
	add r0, #0x2a
	strb r1, [r0]
	b _0223A5C4
_0223A538:
	lsl r0, r4, #2
	str r0, [sp]
	add r0, r4, #0
	bl sub_020378AC
	ldr r1, [sp]
	lsl r0, r0, #2
	add r1, r7, r1
	ldr r1, [r1, #4]
	add r0, r6, r0
	str r1, [r0, #4]
	mov r0, #1
	eor r0, r4
	lsl r5, r0, #2
	str r0, [sp, #4]
	bl sub_020378AC
	add r1, r7, r5
	lsl r0, r0, #2
	ldr r1, [r1, #4]
	add r0, r6, r0
	str r1, [r0, #4]
	add r0, r4, #0
	bl sub_020378AC
	add r4, r0, #0
	ldr r0, [sp]
	mov r1, #5
	add r0, r7, r0
	add r0, #0xf8
	ldr r0, [r0]
	bl PlayerProfile_GetPlayerName_NewString
	lsl r1, r4, #2
	add r1, r6, r1
	str r0, [r1, #0x14]
	ldr r0, [sp, #4]
	bl sub_020378AC
	add r4, r0, #0
	add r0, r7, r5
	add r0, #0xf8
	ldr r0, [r0]
	mov r1, #5
	bl PlayerProfile_GetPlayerName_NewString
	lsl r1, r4, #2
	add r1, r6, r1
	str r0, [r1, #0x14]
	mov r0, #5
	str r0, [r6, #0x24]
	add r0, r6, #0
	mov r1, #2
	add r0, #0x28
	strb r1, [r0]
	add r0, r6, #0
	mov r1, #0
	add r0, #0x29
	strb r1, [r0]
	ldr r1, [r7, #0x14]
	cmp r1, #5
	beq _0223A5BC
	add r0, r6, #0
	add r0, #0x2a
	strb r1, [r0]
	b _0223A5C4
_0223A5BC:
	add r0, r6, #0
	mov r1, #3
	add r0, #0x2a
	strb r1, [r0]
_0223A5C4:
	ldr r0, _0223A5E0 ; =0x000001B2
	ldrb r1, [r7, r0]
	add r0, r6, #0
	add r0, #0x2c
	strb r1, [r0]
	add r0, r6, #0
	bl ov05_0221BA00
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_0223A5DC: .word FS_OVERLAY_ID(OVY_5)
_0223A5E0: .word 0x000001B2
	thumb_func_end ov12_0223A3F0
