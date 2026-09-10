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

	thumb_func_start sub_02068FC8
sub_02068FC8: ; 0x02068FC8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xa4
	str r0, [sp, #0x10]
	ldr r6, [sp, #0xb8]
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	add r0, r6, #0
	str r3, [sp, #0x1c]
	ldr r5, [sp, #0xbc]
	bl FieldSystem_GetSaveData
	str r0, [sp, #0x20]
	bl Save_PlayerData_GetProfile
	add r7, r0, #0
	ldr r0, [sp, #0x20]
	bl Save_GameStats_Get
	add r4, r0, #0
	ldr r2, _020691A0 ; =0x0000066C
	add r0, r5, #0
	mov r1, #0
	bl memset
	ldr r0, [sp, #0x1c]
	strb r0, [r5, #5]
	add r0, r6, #0
	bl sub_020691E8
	str r0, [sp, #0x24]
	add r0, r7, #0
	bl PlayerProfile_GetLanguage
	str r0, [sp]
	str r5, [sp, #4]
	ldr r0, [sp, #0x10]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x18]
	mov r1, #GAME_VERSION
	bl sub_020692A0
	add r0, r7, #0
	bl PlayerProfile_GetTrainerID_VisibleHalf
	str r0, [sp, #0x28]
	add r0, r7, #0
	bl PlayerProfile_GetTrainerGender
	str r0, [sp, #0x2c]
	add r0, r7, #0
	bl PlayerProfile_GetNamePtr
	str r0, [sp, #0x30]
	add r0, r7, #0
	bl PlayerProfile_GetMoney
	str r0, [sp, #0x34]
	ldr r0, [r6, #0xc]
	bl Save_Pokedex_Get
	bl Pokedex_CountDexOwned
	str r0, [sp, #0x38]
	ldr r0, [r6, #0xc]
	bl Save_Pokedex_Get
	bl Pokedex_IsEnabled
	str r0, [sp, #0x3c]
	add r0, r4, #0
	bl GameStats_GetScore
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x30]
	str r1, [sp]
	ldr r1, [sp, #0x3c]
	ldr r3, [sp, #0x34]
	str r1, [sp, #4]
	str r0, [sp, #8]
	ldr r1, [sp, #0x2c]
	ldr r0, [sp, #0x28]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r5, [sp, #0xc]
	bl sub_020692C4
	ldr r0, [sp, #0x20]
	bl Save_PlayerData_GetIGTAddr
	str r0, [sp, #0x40]
	add r0, r6, #0
	add r1, sp, #0x94
	add r2, sp, #0x78
	bl sub_02055624
	add r0, r6, #0
	add r1, sp, #0x84
	add r2, sp, #0x78
	bl FieldSystem_GetGameClearTime
	ldr r0, [r6, #0xc]
	bl Save_VarsFlags_Get
	bl CheckGameClearFlag
	add r1, sp, #0x78
	str r1, [sp]
	ldr r1, [sp, #0x14]
	lsl r0, r0, #0x18
	str r1, [sp, #4]
	ldr r1, [sp, #0x40]
	str r5, [sp, #8]
	lsr r0, r0, #0x18
	add r2, sp, #0x94
	add r3, sp, #0x84
	bl sub_02069308
	ldr r0, [r6, #0xc]
	bl Save_TrainerCard_Get
	str r0, [sp, #0x44]
	add r0, r4, #0
	mov r1, #0x21
	bl GameStats_GetCapped
	str r0, [sp, #0x48]
	add r0, r4, #0
	mov r1, #0x1a
	bl GameStats_GetCapped
	str r0, [sp, #0x4c]
	add r0, r4, #0
	mov r1, #0x15
	bl GameStats_GetCapped
	str r0, [sp, #0x50]
	add r0, r4, #0
	mov r1, #0x19
	bl GameStats_GetCapped
	str r0, [sp, #0x54]
	add r0, r4, #0
	mov r1, #0x5c
	bl GameStats_GetCapped
	str r0, [sp, #0x58]
	add r0, r4, #0
	mov r1, #0x14
	bl GameStats_GetCapped
	ldr r1, [sp, #0x58]
	add r1, r1, r0
	ldr r0, [sp, #0x54]
	add r1, r0, r1
	ldr r0, [sp, #0x50]
	add r1, r0, r1
	ldr r0, [sp, #0x4c]
	add r0, r0, r1
	str r0, [sp, #0x5c]
	add r0, r4, #0
	mov r1, #0x16
	bl GameStats_GetCapped
	str r0, [sp, #0x60]
	add r0, r4, #0
	mov r1, #0x1b
	bl GameStats_GetCapped
	str r0, [sp, #0x64]
	add r0, r4, #0
	mov r1, #0x17
	bl GameStats_GetCapped
	str r0, [sp, #0x68]
	add r0, r4, #0
	mov r1, #0x1c
	bl GameStats_GetCapped
	str r0, [sp, #0x6c]
	add r0, r4, #0
	mov r1, #0x14
	bl GameStats_GetCapped
	str r0, [sp, #0x70]
	add r0, r4, #0
	mov r1, #0x19
	bl GameStats_GetCapped
	add r4, r0, #0
	ldr r0, [sp, #0x44]
	bl TrainerCard_SignatureExists
	str r0, [sp, #0x74]
	ldr r0, [sp, #0x44]
	bl TrainerCard_GetSignature
	ldr r1, [sp, #0x74]
	ldr r2, [sp, #0x60]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp]
	str r0, [sp, #4]
	ldr r1, [sp, #0x48]
	ldr r0, [sp, #0x5c]
	ldr r3, [sp, #0x68]
	add r0, r1, r0
	ldr r1, [sp, #0x64]
	str r5, [sp, #8]
	add r1, r2, r1
	ldr r2, [sp, #0x6c]
	add r2, r3, r2
	ldr r3, [sp, #0x70]
	add r3, r3, r4
	bl sub_020693AC
	add r0, r7, #0
	add r1, r6, #0
	add r2, r5, #0
	bl sub_0206940C
	mov r3, #0
	ldr r0, _020691A0 ; =0x0000066C
	add r2, r3, #0
_02069186:
	ldrb r1, [r5, r2]
	add r2, r2, #1
	eor r3, r1
	cmp r2, r0
	blo _02069186
	ldr r0, _020691A4 ; =0x00000668
	mov r1, #0
	strh r3, [r5, r0]
	add r0, r0, #2
	strh r1, [r5, r0]
	add sp, #0xa4
	pop {r4, r5, r6, r7, pc}
	nop
_020691A0: .word 0x0000066C
_020691A4: .word 0x00000668
	thumb_func_end sub_02068FC8
