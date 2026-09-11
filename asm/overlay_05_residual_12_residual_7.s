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


	thumb_func_start ov05_0221E7B8
ov05_0221E7B8: ; 0x0221E7B8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	lsl r0, r1, #2
	add r2, r5, #0
	add r0, r0, #3
	add r2, #0x10
	lsl r0, r0, #4
	add r4, r2, r0
	mov r0, #0x18
	add r6, r1, #0
	mul r6, r0
	mov r0, #0x87
	lsl r0, r0, #2
	add r7, r5, r0
	sub r0, r0, #2
	add r0, r5, r0
	str r0, [sp, #8]
	ldrh r0, [r0, r6]
	ldrh r1, [r7, r6]
	mov r2, #0x30
	bl CalculateHpBarColor
	cmp r0, #4
	bhi _0221E846
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0221E7F6: ; jump table
	.short _0221E846 - _0221E7F6 - 2 ; case 0
	.short _0221E830 - _0221E7F6 - 2 ; case 1
	.short _0221E818 - _0221E7F6 - 2 ; case 2
	.short _0221E800 - _0221E7F6 - 2 ; case 3
	.short _0221E800 - _0221E7F6 - 2 ; case 4
_0221E800:
	ldrb r3, [r4, #9]
	ldr r1, _0221E89C ; =0x000004F6
	mov r0, #1
	lsl r3, r3, #4
	add r3, #9
	lsl r3, r3, #0x11
	add r1, r5, r1
	mov r2, #4
	lsr r3, r3, #0x10
	bl BG_LoadPlttData
	b _0221E846
_0221E818:
	ldrb r3, [r4, #9]
	ldr r1, _0221E8A0 ; =0x00000516
	mov r0, #1
	lsl r3, r3, #4
	add r3, #9
	lsl r3, r3, #0x11
	add r1, r5, r1
	mov r2, #4
	lsr r3, r3, #0x10
	bl BG_LoadPlttData
	b _0221E846
_0221E830:
	ldrb r3, [r4, #9]
	ldr r1, _0221E8A4 ; =0x00000536
	mov r0, #1
	lsl r3, r3, #4
	add r3, #9
	lsl r3, r3, #0x11
	add r1, r5, r1
	mov r2, #4
	lsr r3, r3, #0x10
	bl BG_LoadPlttData
_0221E846:
	ldr r0, [sp, #8]
	ldrh r1, [r7, r6]
	ldrh r0, [r0, r6]
	mov r2, #0x30
	bl CalculateHpBarPixelsLength
	add r5, r0, #0
	lsl r0, r5, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0xa
	mov r2, #0
	mov r3, #2
	bl FillWindowPixelRect
	lsl r0, r5, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #9
	mov r2, #0
	mov r3, #3
	bl FillWindowPixelRect
	lsl r0, r5, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0xa
	mov r2, #0
	mov r3, #5
	bl FillWindowPixelRect
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_0221E89C: .word 0x000004F6
_0221E8A0: .word 0x00000516
_0221E8A4: .word 0x00000536
	thumb_func_end ov05_0221E7B8




	thumb_func_start ov05_0221E8A8
ov05_0221E8A8: ; 0x0221E8A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r7, r0, #0
	ldr r6, [sp, #0x2c]
	add r5, r7, #0
	str r1, [sp, #8]
	add r5, #0x10
	lsl r4, r6, #6
	add r0, r5, r4
	mov r1, #0
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	bl FillWindowPixelBuffer
	add r0, r5, r4
	add r0, #0x10
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, r4
	add r0, #0x20
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, r4
	add r0, #0x30
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #8]
	str r0, [sp]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	add r0, r7, #0
	str r6, [sp, #4]
	bl ov05_0221E624
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #8]
	str r0, [sp]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	add r0, r7, #0
	str r6, [sp, #4]
	bl ov05_0221E714
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #8]
	str r0, [sp]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	add r0, r7, #0
	str r6, [sp, #4]
	bl ov05_0221E74C
	add r0, r7, #0
	add r1, r6, #0
	bl ov05_0221E7B8
	add r0, r5, r4
	bl ScheduleWindowCopyToVram
	add r0, r5, r4
	add r0, #0x10
	bl ScheduleWindowCopyToVram
	add r0, r5, r4
	add r0, #0x20
	bl ScheduleWindowCopyToVram
	add r0, r5, r4
	add r0, #0x30
	bl ScheduleWindowCopyToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov05_0221E8A8




	thumb_func_start ov05_0221E944
ov05_0221E944: ; 0x0221E944
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r0, #0
	ldr r3, [r6]
	mov r2, #0x4b
	ldr r3, [r3, #0x24]
	mov r0, #0
	mov r1, #0x1b
	lsl r2, r2, #2
	bl NewMsgDataFromNarc
	ldr r3, [r6]
	str r0, [sp, #0x10]
	ldr r3, [r3, #0x24]
	mov r0, #0xf
	mov r1, #0xe
	mov r2, #0
	bl MessagePrinter_New
	str r0, [sp, #0xc]
	ldr r0, [r6]
	ldr r0, [r0, #0x24]
	bl MessageFormat_New
	ldr r1, [r6]
	str r0, [sp, #8]
	ldr r1, [r1, #0x24]
	mov r0, #0x20
	bl String_New
	add r7, r0, #0
	mov r4, #0
	add r5, r6, #0
_0221E986:
	mov r0, #0x86
	lsl r0, r0, #2
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _0221E9A0
	ldr r1, [sp, #0x10]
	str r7, [sp]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #8]
	add r0, r6, #0
	str r4, [sp, #4]
	bl ov05_0221E8A8
_0221E9A0:
	add r4, r4, #1
	add r5, #0x18
	cmp r4, #6
	blo _0221E986
	add r0, r7, #0
	bl String_Delete
	ldr r0, [sp, #0x10]
	bl DestroyMsgData
	ldr r0, [sp, #0xc]
	bl MessagePrinter_Delete
	ldr r0, [sp, #8]
	bl MessageFormat_Delete
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov05_0221E944
