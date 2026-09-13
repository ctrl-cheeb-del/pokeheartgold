	.include "asm/macros.inc"
	.include "overlay_108.inc"
	.include "global.inc"

	.text
	.extern SafariDecoration_Init
	.extern SafariDecoration_Exit
	.extern SafariDecoration_Main
	.extern ov108_021E8A88
	.extern ov108_021E8AD4
	.extern ov108_021E8B24
	.extern ov108_021E8B68
	.extern ov108_021E8BC0
	.extern ov108_021E8C18
	.extern ov108_021E8C64
	.extern ov108_021E8CD4
	.extern ov108_021E8E10
	.extern ov108_021E8E60
	.extern ov108_021E8EA4
	.extern ov108_021E8ED8
	.extern ov108_021E8F00
	.extern ov108_021E90C4
	.extern ov108_021E9144
	.extern ov108_021E9198
	.extern ov108_021E91D4
	.extern ov108_021E91F8
	.extern ov108_021E9204
	.extern ov108_021E9210
	.extern ov108_021E9230
	.extern ov108_021E929C
	.extern ov108_021E9304
	.extern ov108_021E9388
	.extern ov108_021E93A8
	.extern ov108_021E940C
	.extern ov108_021E9488
	.extern ov108_021E94E8
	.extern ov108_021E9528
	.extern ov108_021E95AC
	.extern ov108_021E96FC
	.extern ov108_021E979C
	.extern ov108_021E9830
	.extern ov108_021E9850
	.extern ov108_021E9A08
	.extern ov108_021E9A60
	.extern ov108_021E9BD4
	.extern ov108_021E9C14
	.extern ov108_021E9C2C
	.extern ov108_021E9C3C
	.extern ov108_021E9CD0
	.extern ov108_021E9D30
	.extern ov108_021E9DE0
	.extern ov108_021E9E10
	.extern ov108_021E9E80
	.extern ov108_021E9EB8
	.extern ov108_021E9F04
	.extern ov108_021E9F20
	.extern ov108_021E9F94
	.extern ov108_021EA040
	.extern ov108_021EA260
	.extern ov108_021EA2EC
	.extern ov108_021EA334
	.extern ov108_021EA418
	.extern ov108_021EA47C
	.extern ov108_021EA50C
	.extern ov108_021EA52C
	.extern ov108_021EA584
	.extern ov108_021EA5E4
	.extern ov108_021EA624
	.extern ov108_021EA63C
	.extern ov108_021EA700
	.extern ov108_021EA9C4
	.extern ov108_021EA9D8
	.extern ov108_021EA9E4
	.extern ov108_021EAAA4
	.extern ov108_021EAAB0
	.extern ov108_021EAAC0
	.extern ov108_021EAAD0
	.extern ov108_021EAAE4
	.extern ov108_021EAB00
	.extern ov108_021EAB1C
	.extern ov108_021EAB38
	.extern ov108_021EAB54
	.extern ov108_021EAB70
	.extern ov108_021EAB8C
	.extern ov108_021EABA8
	.extern ov108_021EABC8
	.extern ov108_021EABF0
	.extern ov108_021EAC18
	.extern ov108_021EAC48
	.extern ov108_021EACE8
	.extern ov108_021EACF0
	.extern ov108_021EACF8
	.extern ov108_021EAD00
	.extern ov108_021EAD08
	.extern ov108_021EAD28


	thumb_func_start ov108_021E8968
ov108_021E8968: ; 0x021E8968
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r1, #0
	add r5, r0, #0
	ldr r0, [r4]
	bl Save_SafariZone_Get
	add r2, r5, #0
	str r0, [r5, #0x20]
	mov r1, #0
	add r2, #0x24
	bl SafariZone_CopyAreaSet
	ldr r0, [r4]
	bl Save_PlayerData_GetOptionsAddr
	add r6, r0, #0
	bl Options_GetTextSpeed
	strb r0, [r5, #0x18]
	add r0, r6, #0
	bl Options_GetFrame
	strb r0, [r5, #0x19]
	ldr r0, [r4, #4]
	bl MenuInputStateMgr_GetState
	str r0, [r5, #0x10]
	str r4, [r5, #0x1c]
	ldr r0, [r4, #0x20]
	mov r1, #6
	ldrb r0, [r0]
	bl _s32_div_f
	ldr r0, _021E8A74 ; =0x00000431
	strb r1, [r5, r0]
	ldr r0, [r5, #0x1c]
	mov r1, #6
	ldr r0, [r0, #0x20]
	ldrb r0, [r0]
	bl _s32_div_f
	mov r1, #0x43
	lsl r1, r1, #4
	strb r0, [r5, r1]
	ldr r0, [r4]
	bl Save_PlayerData_GetProfile
	add r6, r0, #0
	ldr r0, [r5, #0x20]
	bl SafariZone_GetObjectUnlockLevel
	add r7, r0, #0
	add r0, r6, #0
	bl PlayerProfile_GetTrainerID
	str r0, [sp, #4]
	add r0, r6, #0
	bl PlayerProfile_GetTrainerGender
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	ldr r0, [r5]
	ldr r3, _021E8A78 ; =0x0000042D
	str r0, [sp]
	ldr r0, [sp, #4]
	add r1, r7, #0
	add r3, r5, r3
	bl ov108_021EA63C
	mov r1, #0xcd
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldrb r0, [r4, #0x19]
	strb r0, [r5, #0x1a]
	cmp r0, #5
	bls _021E8A06
	mov r0, #0
	strb r0, [r5, #0x1a]
_021E8A06:
	ldrb r1, [r5, #0x1a]
	mov r0, #0x7a
	mul r0, r1
	add r0, r5, r0
	add r0, #0x25
	ldrb r1, [r0]
	mov r0, #0x1e
	sub r1, r0, r1
	ldr r0, _021E8A7C ; =0x00000435
	strb r1, [r5, r0]
	sub r0, #8
	ldrb r0, [r5, r0]
	mov r1, #6
	bl _s32_div_f
	ldr r1, _021E8A80 ; =0x0000042E
	strb r0, [r5, r1]
	sub r0, r1, #1
	ldrb r0, [r5, r0]
	mov r1, #6
	bl _s32_div_f
	cmp r1, #0
	ble _021E8A3E
	ldr r0, _021E8A80 ; =0x0000042E
	ldrb r1, [r5, r0]
	add r1, r1, #1
	strb r1, [r5, r0]
_021E8A3E:
	mov r0, #0x43
	lsl r0, r0, #4
	sub r1, r0, #2
	ldrb r2, [r5, r0]
	ldrb r1, [r5, r1]
	cmp r2, r1
	blo _021E8A50
	mov r1, #0
	strb r1, [r5, r0]
_021E8A50:
	ldr r0, [r5, #0x1c]
	mov r1, #0xff
	strh r1, [r0, #0x1c]
	ldr r0, [r4]
	bl Save_SysInfo_RTC_Get
	ldr r0, [r0, #0x14]
	bl GF_RTC_GetTimeOfDayByHour
	ldr r1, _021E8A84 ; =0x0000042C
	strb r0, [r5, r1]
	ldrb r0, [r5, r1]
	cmp r0, #4
	bne _021E8A70
	mov r0, #3
	strb r0, [r5, r1]
_021E8A70:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E8A74: .word 0x00000431
_021E8A78: .word 0x0000042D
_021E8A7C: .word 0x00000435
_021E8A80: .word 0x0000042E
_021E8A84: .word 0x0000042C
	thumb_func_end ov108_021E8968
