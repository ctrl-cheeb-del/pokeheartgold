	.include "asm/macros.inc"
	.public ov05_0221BA00
	.public ov05_0221BA70
	.public ov05_0221BB00
	.public ov05_0221BB30
	.public ov05_0221BD28
	.public ov05_0221BE04
	.public ov05_0221BE80
	.public ov05_0221BF08
	.public ov05_0221C018
	.public ov05_0221C050
	.public ov05_0221C21C
	.public ov05_0221C430
	.public ov05_0221C558
	.public ov05_0221C568
	.public ov05_0221C5A8
	.public ov05_0221C5C4
	.public ov05_0221C6C8
	.public ov05_0221C7FC
	.public ov05_0221C80C
	.public ov05_0221C8A0
	.public ov05_0221C8E0
	.public ov05_0221C908
	.public ov05_0221CAB8
	.public ov05_0221CB70
	.public ov05_0221CC04
	.public ov05_0221CC58
	.public ov05_0221CC74
	.public ov05_0221CCF4
	.public ov05_0221CD24
	.public ov05_0221CDC4
	.public ov05_0221CE0C
	.public ov05_0221CE50
	.public ov05_0221CE88
	.public ov05_0221CEB8
	.public ov05_0221CFF0
	.public ov05_0221D020
	.public ov05_0221D054
	.public ov05_0221D094
	.public ov05_0221D140
	.public ov05_0221D228
	.public ov05_0221D240
	.public ov05_0221D318
	.public ov05_0221D3AC
	.public ov05_0221D414
	.public ov05_0221D4D0
	.public ov05_0221D530
	.public ov05_0221D5DC
	.public ov05_0221D664
	.public ov05_0221D690
	.public ov05_0221D6C4
	.public ov05_0221D7AC
	.public ov05_0221D890
	.public ov05_0221D904
	.public ov05_0221D9F0
	.public ov05_0221DAE0
	.public ov05_0221DB18
	.public ov05_0221DB4C
	.public ov05_0221DB70
	.public ov05_0221DB94
	.public ov05_0221DC34
	.public ov05_0221DC60
	.public ov05_0221DD08
	.public ov05_0221DDEC
	.public ov05_0221DE38
	.public ov05_0221DE6C
	.public ov05_0221DF38
	.public ov05_0221E07C
	.public ov05_0221E0A8
	.public ov05_0221E110
	.public ov05_0221E274
	.public ov05_0221E2D8
	.public ov05_0221E390
	.public ov05_0221E42C
	.public ov05_0221E4C8
	.public ov05_0221E564
	.public ov05_0221E5E4
	.public ov05_0221E60C
	.public ov05_0221E624
	.public ov05_0221E714
	.public ov05_0221E74C
	.public ov05_0221E7B8
	.public ov05_0221E8A8
	.public ov05_0221E944
	.public ov05_0221E9C4
	.public ov05_0221E9F8
	.public ov05_0221EA18
	.public ov05_0221EA38
	.public _0221EA54
	.public ov05_0221EA58
	.public ov05_0221EA60
	.public ov05_0221EA6C
	.public ov05_0221EA6D
	.public ov05_0221EA78
	.public ov05_0221EA88
	.public ov05_0221EA98
	.public ov05_0221EAAC
	.public ov05_0221EAC0
	.public ov05_0221EAD4
	.public ov05_0221EAEC
	.public ov05_0221EB04
	.public ov05_0221EB1C
	.public ov05_0221EB38
	.public ov05_0221EB54
	.public ov05_0221EB70
	.public ov05_0221EB8C
	.public ov05_0221EBA8
	.public ov05_0221EBC4
	.public ov05_0221EBE0
	.public ov05_0221EC00
	.public ov05_0221EC28
	.public ov05_0221EC5C
	.public ov05_0221EC98
	.public ov05_0221ECE4
	.public ov05_0221EDA4
	.public ov05_0221EF2C
	.include "overlay_05.inc"
	.include "global.inc"

	.text

	thumb_func_start ov05_0221D3AC
ov05_0221D3AC: ; 0x0221D3AC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r4, _0221D408 ; =_0221EA54
	str r2, [sp]
	ldrb r5, [r4]
	str r3, [sp, #4]
	add r3, sp, #8
	strb r5, [r3]
	ldrb r5, [r4, #1]
	add r2, sp, #8
	mov r7, #0
	strb r5, [r3, #1]
	ldrb r5, [r4, #2]
	ldrb r4, [r4, #3]
	add r6, r0, r1
	strb r5, [r3, #2]
	strb r4, [r3, #3]
	ldrb r2, [r2, r1]
	add r4, r7, #0
	lsl r2, r2, #2
	add r5, r0, r2
_0221D3D6:
	ldr r1, _0221D40C ; =0x00000B64
	mov r0, #0x66
	ldrb r1, [r6, r1]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r2, r1, r4
	ldr r1, [sp]
	add r1, r1, r2
	ldr r2, _0221D410 ; =0x00000B68
	lsl r1, r1, #0x10
	ldrb r3, [r6, r2]
	ldr r2, [sp, #4]
	asr r1, r1, #0x10
	add r2, r2, r3
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	add r7, r7, #1
	add r4, #0x13
	add r5, r5, #4
	cmp r7, #3
	blo _0221D3D6
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221D408: .word _0221EA54
_0221D40C: .word 0x00000B64
_0221D410: .word 0x00000B68
	thumb_func_end ov05_0221D3AC


	thumb_func_start ov05_0221D414
ov05_0221D414: ; 0x0221D414
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r0, #0
	add r0, r1, #0
	str r1, [sp]
	str r2, [sp, #4]
	add r7, r3, #0
	bl Party_GetCount
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r5, #0
	ldr r0, [sp, #4]
	add r4, r5, #0
	cmp r0, #0
	ble _0221D4CC
	lsl r0, r7, #2
	add r6, r6, r0
_0221D43A:
	lsl r0, r4, #2
	add r1, r6, r0
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetAnim
	ldr r0, [sp, #8]
	cmp r0, r4
	bls _0221D4C0
	ldr r0, [sp]
	add r1, r4, #0
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r7, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _0221D4C0
	add r0, r7, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _0221D4C0
	add r0, r7, #0
	bl Pokemon_GetStatusIconId
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #6
	bne _0221D494
	lsl r0, r5, #2
	add r1, r6, r0
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #3
	bl ManagedSprite_SetAnim
	b _0221D4BA
_0221D494:
	cmp r0, #7
	beq _0221D4AA
	lsl r0, r5, #2
	add r1, r6, r0
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #2
	bl ManagedSprite_SetAnim
	b _0221D4BA
_0221D4AA:
	lsl r0, r5, #2
	add r1, r6, r0
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #1
	bl ManagedSprite_SetAnim
_0221D4BA:
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
_0221D4C0:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r0, [sp, #4]
	cmp r4, r0
	blt _0221D43A
_0221D4CC:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov05_0221D414
