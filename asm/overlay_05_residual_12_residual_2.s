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


	thumb_func_start ov05_0221DE6C
ov05_0221DE6C: ; 0x0221DE6C
	push {r3, r4, r5, r6, lr}
	sub sp, #0x1c
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	add r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0221DECC
	mov r0, #0x20
	sub r6, r0, r4
	ldr r1, _0221DF30 ; =0x00000544
	str r4, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	add r1, r5, r1
	str r1, [sp, #8]
	mov r3, #0
	str r3, [sp, #0xc]
	lsl r2, r6, #0x18
	str r3, [sp, #0x10]
	mov r1, #0x10
	str r1, [sp, #0x14]
	str r0, [sp, #0x18]
	ldr r0, [r5, #0xc]
	mov r1, #1
	lsr r2, r2, #0x18
	bl CopyToBgTilemapRect
	ldr r0, _0221DF34 ; =0x00000844
	lsl r2, r6, #0x18
	str r4, [sp]
	mov r1, #0x18
	str r1, [sp, #4]
	add r0, r5, r0
	str r0, [sp, #8]
	mov r3, #0
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	mov r0, #0x10
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r0, [r5, #0xc]
	mov r1, #2
	lsr r2, r2, #0x18
	bl CopyToBgTilemapRect
	b _0221DF1A
_0221DECC:
	ldr r2, _0221DF30 ; =0x00000544
	mov r0, #0x10
	str r4, [sp]
	mov r1, #0x18
	sub r6, r0, r4
	str r1, [sp, #4]
	add r2, r5, r2
	str r2, [sp, #8]
	lsl r2, r6, #0x18
	lsr r2, r2, #0x18
	str r2, [sp, #0xc]
	mov r2, #0
	str r2, [sp, #0x10]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r0, [r5, #0xc]
	mov r1, #1
	add r3, r2, #0
	bl CopyToBgTilemapRect
	ldr r1, _0221DF34 ; =0x00000844
	mov r2, #0
	str r4, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	add r1, r5, r1
	str r1, [sp, #8]
	lsl r1, r6, #0x18
	lsr r1, r1, #0x18
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	mov r1, #0x10
	str r1, [sp, #0x14]
	str r0, [sp, #0x18]
	ldr r0, [r5, #0xc]
	mov r1, #2
	add r3, r2, #0
	bl CopyToBgTilemapRect
_0221DF1A:
	ldr r0, [r5, #0xc]
	mov r1, #1
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, [r5, #0xc]
	mov r1, #2
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x1c
	pop {r3, r4, r5, r6, pc}
	nop
_0221DF30: .word 0x00000544
_0221DF34: .word 0x00000844
	thumb_func_end ov05_0221DE6C




	thumb_func_start ov05_0221DF38
ov05_0221DF38: ; 0x0221DF38
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r4, r0, #0
	add r0, r1, #0
	str r1, [sp]
	add r5, r2, #0
	bl Party_GetCount
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #8]
	mov r0, #0x18
	mul r0, r5
	add r0, r4, r0
	mov r6, #0
	str r0, [sp, #4]
_0221DF58:
	ldr r0, [sp, #8]
	cmp r0, r6
	bhi _0221DF7A
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	bl GetMonIconNaixEx
	mov r1, #0x18
	add r2, r6, #0
	mul r2, r1
	ldr r1, [sp, #4]
	add r2, r1, r2
	mov r1, #0x85
	lsl r1, r1, #2
	str r0, [r2, r1]
	b _0221E054
_0221DF7A:
	ldr r0, [sp]
	add r1, r6, #0
	bl Party_GetMonByIndex
	mov r1, #0x18
	add r2, r6, #0
	mul r2, r1
	ldr r1, [sp, #4]
	add r4, r0, #0
	add r7, r1, r2
	bl Pokemon_GetIconNaix
	mov r1, #0x85
	lsl r1, r1, #2
	str r0, [r7, r1]
	add r0, r4, #0
	mov r1, #5
	mov r2, #0
	bl GetMonData
	mov r1, #0x86
	lsl r1, r1, #2
	strh r0, [r7, r1]
	add r0, r1, #0
	ldrh r0, [r7, r0]
	cmp r0, #0
	beq _0221E054
	mov r0, #0x18
	add r1, r6, #0
	mul r1, r0
	ldr r0, [sp, #4]
	mov r2, #0
	add r5, r0, r1
	add r0, r4, #0
	mov r1, #0x4c
	bl GetMonData
	ldr r1, _0221E064 ; =0x00000223
	mov r2, #0
	strb r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0xa3
	bl GetMonData
	ldr r1, _0221E068 ; =0x0000021A
	mov r2, #0
	strh r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0xa4
	bl GetMonData
	mov r1, #0x87
	lsl r1, r1, #2
	strh r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0xa1
	mov r2, #0
	bl GetMonData
	mov r1, #0x22
	lsl r1, r1, #4
	strb r0, [r5, r1]
	add r0, r4, #0
	mov r1, #6
	mov r2, #0
	bl GetMonData
	ldr r1, _0221E06C ; =0x0000021E
	mov r2, #0
	strh r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0xa2
	bl GetMonData
	mov r1, #0x89
	lsl r1, r1, #2
	strb r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	ldr r1, _0221E070 ; =0x00000225
	mov r2, #0
	strb r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0xb0
	bl GetMonData
	cmp r0, #1
	bne _0221E034
	mov r1, #0
	b _0221E036
_0221E034:
	mov r1, #1
_0221E036:
	ldr r0, _0221E074 ; =0x00000222
	strb r1, [r7, r0]
	add r0, r4, #0
	bl GetMonGender
	ldr r1, _0221E078 ; =0x00000221
	strb r0, [r5, r1]
	add r0, r4, #0
	bl Pokemon_GetStatusIconId
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	mov r0, #0x8a
	lsl r0, r0, #2
	str r1, [r5, r0]
_0221E054:
	add r0, r6, #1
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	cmp r6, #3
	bhs _0221E060
	b _0221DF58
_0221E060:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221E064: .word 0x00000223
_0221E068: .word 0x0000021A
_0221E06C: .word 0x0000021E
_0221E070: .word 0x00000225
_0221E074: .word 0x00000222
_0221E078: .word 0x00000221
	thumb_func_end ov05_0221DF38
