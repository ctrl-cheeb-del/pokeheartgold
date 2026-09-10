#include "config.h"
	.include "asm/macros.inc"
	.include "unk_02068FC8.inc"
	.include "global.inc"

	.text
	.public sub_02068FC8
	.public sub_020691A8
	.public sub_020691C4
	.public sub_020691E0
	.public sub_020691E8
	.public sub_020692A0
	.public sub_020692C4
	.public sub_02069308
	.public sub_020693AC
	.public sub_0206940C
	.public sub_02069464
	.public sub_02069498
	.public sub_020691A8
	.public sub_020691C4
	.public sub_020691E0
	.public sub_020692A0
	.public sub_020692C4
	.public sub_02069308
	.public sub_020693AC
	.public sub_0206940C
	.public sub_02069464
	.public sub_02069498

	thumb_func_start sub_020691E8
sub_020691E8: ; 0x020691E8
	push {r3, r4, r5, r6, r7, lr}
	bl FieldSystem_GetSaveData
	add r7, r0, #0
	bl Save_GameStats_Get
	add r0, r7, #0
	bl Save_VarsFlags_Get
	add r6, r0, #0
	add r0, r7, #0
	bl Save_Frontier_GetStatic
	add r5, r0, #0
	add r0, r6, #0
	mov r4, #0
	bl CheckGameClearFlag
	cmp r0, #0
	beq _02069216
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_02069216:
	add r0, r7, #0
	bl Save_Pokedex_Get
	bl Pokedex_NationalDexIsComplete
	cmp r0, #0
	beq _0206922A
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_0206922A:
	add r0, r5, #0
	mov r1, #0
	mov r2, #0xff
	bl FrontierSave_GetStat
	cmp r0, #0x64
	bhs _02069270
	add r0, r5, #0
	mov r1, #2
	mov r2, #0xff
	bl FrontierSave_GetStat
	cmp r0, #0x64
	bhs _02069270
	add r0, r5, #0
	mov r1, #4
	mov r2, #0xff
	bl FrontierSave_GetStat
	cmp r0, #0x64
	bhs _02069270
	add r0, r5, #0
	mov r1, #6
	mov r2, #0xff
	bl FrontierSave_GetStat
	cmp r0, #0x64
	bhs _02069270
	add r0, r5, #0
	mov r1, #8
	mov r2, #0xff
	bl FrontierSave_GetStat
	cmp r0, #0x64
	blo _02069276
_02069270:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_02069276:
	add r0, r6, #0
	mov r1, #0xf1
	bl Save_VarsFlags_CheckFlagInArray
	cmp r0, #0
	beq _02069288
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_02069288:
	mov r1, #0x61
	add r0, r6, #0
	lsl r1, r1, #2
	bl Save_VarsFlags_CheckFlagInArray
	cmp r0, #0
	beq _0206929C
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_0206929C:
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_020691E8
