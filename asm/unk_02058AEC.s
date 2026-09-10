	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"

	.bss

	.public _021D41CC
_021D41CC:
	.space 0xC

	.public _021D41D8
_021D41D8:
	.space 0x40

	.rodata

	.public _020FC7CC
_020FC7CC:
	.byte 0x00, 0x01, 0x02, 0x03
	.byte 0x04, 0x00, 0x00, 0x00

	.text

	thumb_func_start sub_02058AEC
sub_02058AEC: ; 0x02058AEC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	add r6, r1, #0
	ldr r0, [sp, #0x24]
	mov r1, #0x3c
	str r2, [sp]
	str r3, [sp, #4]
	ldr r5, [r6, #0xc]
	bl Heap_AllocAtEnd
	mov r1, #0
	mov r2, #0x3c
	add r4, r0, #0
	bl MI_CpuFill8
	ldr r0, [r6, #0xc]
	bl Save_PlayerData_GetProfile
	add r1, r0, #0
	add r0, r4, #0
	bl sub_0208AD34
	add r0, r5, #0
	bl SaveArray_IsNatDexEnabled
	str r0, [r4, #0x1c]
	add r0, r5, #0
	bl sub_02088288
	str r0, [r4, #0x2c]
	add r0, r5, #0
	bl Save_PlayerData_GetOptionsAddr
	str r0, [r4, #4]
	ldr r0, [sp]
	str r0, [r4]
	mov r0, #1
	strb r0, [r4, #0x11]
	ldr r0, [sp, #4]
	strb r0, [r4, #0x14]
	ldr r0, [r4]
	bl Party_GetCount
	strb r0, [r4, #0x13]
	mov r0, #0
	strh r0, [r4, #0x18]
	ldr r0, [sp, #0x20]
	strb r0, [r4, #0x12]
	add r0, r5, #0
	bl Save_SpecialRibbons_Get
	str r0, [r4, #0x20]
	mov r0, #0
	str r0, [r4, #0x30]
	add r0, r5, #0
	bl sub_0208828C
	str r0, [r4, #0x34]
	ldr r1, _02058B7C ; =_020FC7CC
	add r0, r4, #0
	bl sub_02089D40
	ldr r1, _02058B80 ; =gOverlayTemplate_PokemonSummary
	add r0, r6, #0
	add r2, r4, #0
	bl FieldSystem_LaunchApplication
	str r4, [r7]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02058B7C: .word _020FC7CC
_02058B80: .word gOverlayTemplate_PokemonSummary
	thumb_func_end sub_02058AEC
	thumb_func_start sub_02058B84
sub_02058B84: ; 0x02058B84
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, r1, #0
	mov r1, #0x44
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x44
	add r4, r0, #0
	bl MI_CpuFill8
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #0xc]
	bl Save_PlayerData_GetOptionsAddr
	str r0, [r4, #0xc]
	ldr r0, [r5, #0x24]
	add r0, #0xa4
	ldr r0, [r0]
	str r0, [r4, #0x14]
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #0xc]
	bl SaveArray_Party_Get
	str r0, [r4]
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #0xc]
	bl Save_Bag_Get
	str r0, [r4, #4]
	mov r0, #0x43
	ldr r1, [r5, #0x24]
	lsl r0, r0, #2
	add r0, r1, r0
	str r0, [r4, #0x20]
	add r0, r4, #0
	mov r1, #0
	add r0, #0x25
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #2
	add r0, #0x24
	strb r1, [r0]
	ldr r0, [r5, #0x24]
	add r0, #0xa4
	ldr r0, [r0]
	cmp r0, #0
	beq _02058C1E
	mov r1, #1
	bl LinkBattleRuleset_GetRuleValue
	add r1, r4, #0
	add r1, #0x36
	ldrb r1, [r1]
	mov r2, #0xf
	lsl r0, r0, #0x18
	bic r1, r2
	lsr r2, r0, #0x18
	mov r0, #0xf
	and r0, r2
	orr r1, r0
	add r0, r4, #0
	add r0, #0x36
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x36
	ldrb r0, [r0]
	mov r1, #0xf0
	bic r0, r1
	add r1, r4, #0
	add r1, #0x36
	ldrb r1, [r1]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x18
	b _02058C3E
_02058C1E:
	add r0, r4, #0
	add r0, #0x36
	ldrb r1, [r0]
	mov r0, #0xf
	bic r1, r0
	mov r0, #3
	orr r1, r0
	add r0, r4, #0
	add r0, #0x36
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x36
	ldrb r1, [r0]
	mov r0, #0xf0
	bic r1, r0
	mov r0, #0x30
_02058C3E:
	orr r1, r0
	add r0, r4, #0
	add r0, #0x36
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #0x64
	add r0, #0x37
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0x3c
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x26
	strb r1, [r0]
	mov r2, #0
_02058C5C:
	add r0, r5, r2
	add r0, #0x3d
	ldrb r1, [r0]
	add r0, r4, r2
	add r0, #0x30
	add r2, r2, #1
	strb r1, [r0]
	cmp r2, #6
	blt _02058C5C
	ldr r0, [r5, #0x24]
	ldr r1, _02058C7C ; =gOverlayTemplate_PartyMenu
	add r2, r4, #0
	bl FieldSystem_LaunchApplication
	str r4, [r5, #4]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02058C7C: .word gOverlayTemplate_PartyMenu
	thumb_func_end sub_02058B84
