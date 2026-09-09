#include "config.h"
	.include "asm/macros.inc"
	.include "unk_02030A98.inc"
	.include "global.inc"

	.bss

	.public _021D2AFC
_021D2AFC:
	.space 0x1628

	.text

	thumb_func_start sub_020314A4
sub_020314A4: ; 0x020314A4
	push {r4, lr}
	mov r1, #0x80
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x80
	add r4, r0, #0
	bl MI_CpuFill8
	add r0, r4, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_020314A4

	thumb_func_start sub_020314BC
sub_020314BC: ; 0x020314BC
	ldr r3, _020314C0 ; =Heap_Free
	bx r3
	.balign 4, 0
_020314C0: .word Heap_Free
	thumb_func_end sub_020314BC

	thumb_func_start sub_020314C4
sub_020314C4: ; 0x020314C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x64
	add r6, r1, #0
	add r5, r0, #0
	add r0, r6, #0
	bl Save_PlayerData_GetProfile
	add r4, r0, #0
	add r0, r6, #0
	bl Save_WiFiHistory_Get
	str r0, [sp]
	add r0, r6, #0
	bl Save_SysInfo_Get
	add r0, r6, #0
	bl Save_Misc_Const_Get
	add r7, r0, #0
	add r0, sp, #0x10
	bl OS_GetOwnerInfo
	add r0, r7, #0
	add r1, sp, #0xc
	add r2, sp, #8
	add r3, sp, #4
	bl SaveMisc_GetFavoriteMon
	add r0, r5, #0
	mov r1, #0
	mov r2, #0x80
	bl MI_CpuFill8
	add r0, r4, #0
	bl PlayerProfile_GetNamePtr
	add r1, r0, #0
	add r0, r5, #0
	bl CopyU16StringArray
	add r0, r4, #0
	bl PlayerProfile_GetTrainerID
	str r0, [r5, #0x10]
	add r0, r4, #0
	bl PlayerProfile_GetTrainerGender
	strb r0, [r5, #0x14]
	ldr r0, [sp, #0xc]
	mov r1, #0xfe
	strh r0, [r5, #0x1c]
	ldrb r0, [r5, #0x1b]
	bic r0, r1
	ldr r1, [sp, #8]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	lsl r1, r1, #0x19
	lsr r1, r1, #0x18
	orr r0, r1
	strb r0, [r5, #0x1b]
	ldrb r0, [r5, #0x1b]
	mov r1, #1
	bic r0, r1
	ldr r1, [sp, #4]
	lsl r1, r1, #0x18
	lsr r2, r1, #0x18
	mov r1, #1
	and r1, r2
	orr r0, r1
	strb r0, [r5, #0x1b]
	ldr r0, [sp]
	bl WifiHistory_GetPlayerCountry
	strb r0, [r5, #0x17]
	ldr r0, [sp]
	bl WiFiHistory_GetPlayerRegion
	strb r0, [r5, #0x18]
	ldr r0, _020315B4 ; =0x0000FFFF
	mov r1, #0
	add r2, r5, #0
_02031566:
	add r1, r1, #1
	strh r0, [r2, #0x20]
	add r2, r2, #2
	cmp r1, #0x28
	blt _02031566
	add r1, r5, #0
	add r0, r7, #0
	add r1, #0x20
	bl SaveMisc_GetBattleGreeting
	add r0, sp, #4
	ldrb r0, [r0, #0xe]
	strb r0, [r5, #0x15]
	add r0, r4, #0
	bl PlayerProfile_GetTrainerGender
	add r7, r0, #0
	add r0, r4, #0
	bl PlayerProfile_GetAvatar
	add r1, r0, #0
	add r0, r7, #0
	mov r2, #0
	bl GetUnionRoomAvatarAttrBySprite
	strb r0, [r5, #0x16]
	mov r0, #GAME_VERSION
	strb r0, [r5, #0x19]
	mov r0, #2
	strb r0, [r5, #0x1a]
	add r0, r6, #0
	add r1, r5, #0
	mov r2, #0x7c
	bl SaveArray_CalcCRC16
	add r5, #0x7c
	strh r0, [r5]
	add sp, #0x64
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_020315B4: .word 0x0000FFFF
	thumb_func_end sub_020314C4

	thumb_func_start sub_020315B8
sub_020315B8: ; 0x020315B8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0xf
	bl String_New
	add r1, r5, #0
	mov r2, #0xf
	add r4, r0, #0
	bl CopyU16ArrayToStringN
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	thumb_func_end sub_020315B8

	thumb_func_start sub_020315D0
sub_020315D0: ; 0x020315D0
	ldrb r0, [r0, #0x14]
	cmp r0, #0
	beq _020315DC
	cmp r0, #1
	beq _020315DC
	mov r0, #0
_020315DC:
	bx lr
	.balign 4, 0
	thumb_func_end sub_020315D0

	thumb_func_start sub_020315E0
sub_020315E0: ; 0x020315E0
	ldrh r0, [r0, #0x1c]
	ldr r1, _020315EC ; =0x000001EF
	cmp r0, r1
	blo _020315EA
	mov r0, #0
_020315EA:
	bx lr
	.balign 4, 0
_020315EC: .word 0x000001EF
	thumb_func_end sub_020315E0

	thumb_func_start sub_020315F0
sub_020315F0: ; 0x020315F0
	push {r3, lr}
	add r2, r0, #0
	ldrh r0, [r2, #0x1c]
	ldr r1, _0203160C ; =0x000001EF
	cmp r0, r1
	blo _02031600
	mov r0, #0
	pop {r3, pc}
_02031600:
	ldrb r1, [r2, #0x1b]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x19
	bl sub_02070438
	pop {r3, pc}
	.balign 4, 0
_0203160C: .word 0x000001EF
	thumb_func_end sub_020315F0

	thumb_func_start sub_02031610
sub_02031610: ; 0x02031610
	ldrb r0, [r0, #0x1b]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	cmp r0, #1
	bls _0203161C
	mov r0, #1
_0203161C:
	bx lr
	.balign 4, 0
	thumb_func_end sub_02031610

	thumb_func_start sub_02031620
sub_02031620: ; 0x02031620
	ldrb r0, [r0, #0x17]
	cmp r0, #0xea
	blo _02031628
	mov r0, #0
_02031628:
	bx lr
	.balign 4, 0
	thumb_func_end sub_02031620

	thumb_func_start sub_0203162C
sub_0203162C: ; 0x0203162C
	push {r4, lr}
	ldrb r1, [r0, #0x17]
	cmp r1, #0xea
	blo _02031638
	mov r0, #0
	pop {r4, pc}
_02031638:
	ldrb r4, [r0, #0x18]
	add r0, r1, #0
	bl LocationGmmDatRegionCountGetByCountryMsgNo
	cmp r0, r4
	bhs _02031646
	mov r4, #0
_02031646:
	add r0, r4, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_0203162C

	thumb_func_start sub_0203164C
sub_0203164C: ; 0x0203164C
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	ldrb r0, [r5, #0x1e]
	add r4, r1, #0
	mov r6, #0
	cmp r0, #0
	bne _020316CE
	ldrh r0, [r5, #0x20]
	strh r0, [r4]
	ldrh r0, [r5, #0x22]
	strh r0, [r4, #2]
	ldrh r0, [r5, #0x24]
	strh r0, [r4, #4]
	ldrh r0, [r5, #0x26]
	strh r0, [r4, #6]
	ldrh r0, [r4]
	cmp r0, #5
	blo _02031676
	add r6, r6, #1
	b _020316AA
_02031676:
	ldrh r0, [r4, #2]
	cmp r0, #0x13
	bls _02031680
	add r6, r6, #1
	b _020316AA
_02031680:
	ldrh r0, [r4, #4]
	ldr r1, _020316E8 ; =0x0000FFFF
	cmp r0, r1
	beq _02031694
	add r1, sp, #4
	add r2, sp, #0
	bl GetCategoryAndMsgNoByECWordIdx
	cmp r0, #0
	beq _020316A8
_02031694:
	ldrh r0, [r4, #6]
	ldr r1, _020316E8 ; =0x0000FFFF
	cmp r0, r1
	beq _020316AA
	add r1, sp, #4
	add r2, sp, #0
	bl GetCategoryAndMsgNoByECWordIdx
	cmp r0, #0
	bne _020316AA
_020316A8:
	add r6, r6, #1
_020316AA:
	cmp r6, #0
	ble _020316C8
	add r0, r4, #0
	mov r1, #4
	bl MailMsg_Init_WithBank
	mov r0, #0
	strh r0, [r4, #2]
	ldr r0, _020316EC ; =0x0000011F
	mov r1, #0x63
	bl GetECWordIndexByPair
	strh r0, [r4, #4]
	ldr r0, _020316E8 ; =0x0000FFFF
	strh r0, [r4, #6]
_020316C8:
	add sp, #8
	mov r0, #0
	pop {r4, r5, r6, pc}
_020316CE:
	mov r0, #0x28
	add r1, r2, #0
	bl String_New
	add r5, #0x20
	add r1, r5, #0
	mov r2, #0x28
	add r4, r0, #0
	bl CopyU16ArrayToStringN
	add r0, r4, #0
	add sp, #8
	pop {r4, r5, r6, pc}
	.balign 4, 0
_020316E8: .word 0x0000FFFF
_020316EC: .word 0x0000011F
	thumb_func_end sub_0203164C

	thumb_func_start sub_020316F0
sub_020316F0: ; 0x020316F0
	ldrb r0, [r0, #0x15]
	cmp r0, #1
	blo _020316FA
	cmp r0, #0xc
	bls _020316FC
_020316FA:
	mov r0, #1
_020316FC:
	bx lr
	.balign 4, 0
	thumb_func_end sub_020316F0

	thumb_func_start sub_02031700
sub_02031700: ; 0x02031700
	ldrb r0, [r0, #0x16]
	cmp r0, #0xf
	bls _02031708
	mov r0, #0
_02031708:
	bx lr
	.balign 4, 0
	thumb_func_end sub_02031700
