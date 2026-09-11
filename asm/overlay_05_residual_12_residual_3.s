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
	.public ov05_0221DC60
	.public ov05_0221DE38
	.public ov05_0221E07C
	.public ov05_0221E274
	.public ov05_0221E390
	.public ov05_0221E42C
	.public ov05_0221E4C8
	.public ov05_0221E5E4
	.public ov05_0221E60C
	.public ov05_0221E714
	.public ov05_0221E74C


	thumb_func_start ov05_0221E0A8
ov05_0221E0A8: ; 0x0221E0A8
	push {r4, lr}
	add r3, r0, #0
	add r2, r1, #0
	mov r0, #0x18
	mul r2, r0
	ldr r1, _0221E10C ; =0x0000021A
	add r4, r3, r2
	ldrh r0, [r4, r1]
	cmp r0, #0
	bne _0221E0C0
	mov r0, #0
	pop {r4, pc}
_0221E0C0:
	add r1, #0xe
	ldr r1, [r4, r1]
	cmp r1, #7
	beq _0221E0D0
	cmp r1, #0
	beq _0221E0D0
	mov r0, #5
	pop {r4, pc}
_0221E0D0:
	mov r1, #0x87
	add r2, r3, r2
	lsl r1, r1, #2
	ldrh r1, [r2, r1]
	mov r2, #0x30
	bl CalculateHpBarColor
	cmp r0, #4
	bhi _0221E108
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0221E0EE: ; jump table
	.short _0221E108 - _0221E0EE - 2 ; case 0
	.short _0221E104 - _0221E0EE - 2 ; case 1
	.short _0221E100 - _0221E0EE - 2 ; case 2
	.short _0221E0FC - _0221E0EE - 2 ; case 3
	.short _0221E0F8 - _0221E0EE - 2 ; case 4
_0221E0F8:
	mov r0, #1
	pop {r4, pc}
_0221E0FC:
	mov r0, #2
	pop {r4, pc}
_0221E100:
	mov r0, #3
	pop {r4, pc}
_0221E104:
	mov r0, #4
	pop {r4, pc}
_0221E108:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_0221E10C: .word 0x0000021A
	thumb_func_end ov05_0221E0A8




	thumb_func_start ov05_0221E110
ov05_0221E110: ; 0x0221E110
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0
	str r0, [sp, #8]
	str r1, [sp]
	add r0, r1, #0
	lsl r1, r0, #2
	ldr r0, [sp]
	ldr r2, _0221E268 ; =ov05_0221EC5C
	add r7, r0, r1
	lsl r0, r7, #2
	add r4, r5, r0
	ldr r0, [sp]
	mov r1, #0xa
	mul r1, r0
	str r4, [sp, #4]
	add r6, r2, r1
_0221E134:
	mov r1, #0x1c
	add r2, r7, #0
	mul r2, r1
	ldr r1, _0221E26C ; =ov05_0221EF2C
	add r0, r5, #0
	add r1, r1, r2
	bl ov05_0221CDC4
	mov r1, #0x66
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r1, #0
	ldrb r1, [r6]
	ldrb r2, [r6, #1]
	ldr r0, [r4, r0]
	bl ManagedSprite_SetPositionXY
	ldr r0, [sp, #8]
	add r7, r7, #1
	add r0, r0, #1
	add r4, r4, #4
	add r6, r6, #2
	str r0, [sp, #8]
	cmp r0, #5
	blo _0221E134
	ldr r0, [sp]
	mov r2, #0x86
	mov r1, #0x18
	add r6, r0, #0
	mul r6, r1
	add r3, r5, r6
	lsl r2, r2, #2
	ldrh r0, [r3, r2]
	cmp r0, #0
	bne _0221E19C
	mov r5, #0
	add r4, r2, #0
	add r6, r5, #0
	sub r4, #0x80
_0221E182:
	ldr r0, [sp, #4]
	add r1, r6, #0
	ldr r0, [r0, r4]
	bl ManagedSprite_SetDrawFlag
	ldr r0, [sp, #4]
	add r5, r5, #1
	add r0, r0, #4
	str r0, [sp, #4]
	cmp r5, #5
	blo _0221E182
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_0221E19C:
	ldr r1, [sp]
	mov r4, #0x14
	mul r4, r1
	add r1, r2, #0
	sub r1, #0x80
	add r7, r5, r1
	add r1, r2, #0
	add r1, #0xd
	add r2, #0xb
	ldrb r1, [r3, r1]
	ldrb r2, [r3, r2]
	bl GetMonIconPaletteEx
	add r1, r0, #0
	ldr r0, [r7, r4]
	bl ManagedSprite_SetPaletteOverride
	ldr r1, [sp]
	add r0, r5, #0
	bl ov05_0221E0A8
	add r1, r0, #0
	ldr r0, [r7, r4]
	bl ManagedSprite_SetAnim
	ldr r1, _0221E270 ; =0x0000021E
	add r0, r5, r6
	ldrh r0, [r0, r1]
	cmp r0, #0
	bne _0221E1E6
	add r0, r5, r4
	sub r1, #0x82
	ldr r0, [r0, r1]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _0221E20C
_0221E1E6:
	bl ItemIdIsMail
	cmp r0, #1
	bne _0221E1FE
	mov r0, #0x67
	add r1, r5, r4
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #1
	bl ManagedSprite_SetAnim
	b _0221E20C
_0221E1FE:
	mov r0, #0x67
	add r1, r5, r4
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetAnim
_0221E20C:
	mov r0, #0x89
	add r1, r5, r6
	lsl r0, r0, #2
	ldrb r1, [r1, r0]
	cmp r1, #0
	bne _0221E226
	add r1, r5, r4
	sub r0, #0x84
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _0221E232
_0221E226:
	add r1, r5, r4
	sub r0, #0x84
	ldr r0, [r1, r0]
	mov r1, #2
	bl ManagedSprite_SetAnim
_0221E232:
	mov r3, #0x8a
	add r0, r5, r6
	lsl r3, r3, #2
	ldr r0, [r0, r3]
	cmp r0, #7
	bne _0221E24E
	add r0, r5, r4
	sub r3, #0x84
	ldr r0, [r0, r3]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_0221E24E:
	add r0, r3, #0
	add r1, r5, r4
	sub r0, #0x84
	ldr r0, [r1, r0]
	ldr r1, [sp, #8]
	mov r2, #0x18
	mul r2, r1
	add r1, r5, r2
	ldr r1, [r1, r3]
	bl ManagedSprite_SetAnim
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221E268: .word ov05_0221EC5C
_0221E26C: .word ov05_0221EF2C
_0221E270: .word 0x0000021E
	thumb_func_end ov05_0221E110
