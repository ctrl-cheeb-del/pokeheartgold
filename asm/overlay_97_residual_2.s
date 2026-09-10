	.include "asm/macros.inc"
	.include "overlay_97.inc"
	.include "global.inc"

	.text
	.public _0221FC98
	.public ov97_0221E5D4
	.public ov97_0221E700
	.public ov97_0221E898
	.public ov97_0221E91C
	.public ov97_0221E98C
	.public ov97_0221EA88
	.public ov97_0221EB38
	.public ov97_0221EC14
	.public ov97_0221EDE4
	.public ov97_0221EEA4
	.public ov97_0221EFD0
	.public ov97_0221F020
	.public ov97_0221F0E0
	.public ov97_0221F14C
	.public ov97_0221F1D8
	.public ov97_0221F294
	.public ov97_0221F428
	.public ov97_0221F56C
	.public ov97_0221F5F8
	.public ov97_0221F74C
	.public ov97_0221F7DC
	.public ov97_0221F9E0
	.public ov97_0221FAEC
	.public ov97_0221FBDC
	.public ov97_0221FCA8
	.public ov97_0221FCB8
	.public ov97_0221FCCC
	.public ov97_0221FCF4
	.public ov97_0221FCFC
	.public ov97_0221FD04
	.public ov97_0221FD20
	.public ov97_0221FD3C
	.public ov97_0221FD58
	.public ov97_0221E5C0
	.public ov97_0221E69C
	.public ov97_0221E6DC
	.public ov97_0221E7F4
	.public ov97_0221E814
	.public ov97_0221E834
	.public ov97_0221E864
	.public ov97_0221E88C
	.public ov97_0221E97C
	.public ov97_0221EBD8
	.public ov97_0221EE84
	.public ov97_0221F010
	.public ov97_0221FB80
	.public ov97_0221FBA0
	.public ov97_0221FC54

	thumb_func_start ov97_0221E700
ov97_0221E700: ; 0x0221E700
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r4, r0, #0
	bl OverlayManager_GetArgs
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #0x34
	mov r2, #0x5c
	ldr r5, [r7]
	bl OverlayManager_CreateAndGetData
	mov r1, #0
	mov r2, #0x34
	add r4, r0, #0
	bl memset
	mov r0, #0x5c
	bl BgConfig_Alloc
	str r0, [r4]
	ldr r0, [r5]
	str r0, [r4, #0x2c]
	add r0, r7, #0
	add r0, #0x84
	ldr r0, [r0]
	str r0, [r4, #0x30]
	bl ov97_0221E7F4
	mov r0, #0x5c
	mov r1, #3
	mov r2, #0x13
	bl sub_020932E0
	str r0, [r4, #8]
	mov r0, #0x5c
	bl ov97_0221EE84
	str r0, [r4, #0xc]
	ldr r0, [r4]
	bl ov97_0221E814
	bl ov97_0221E834
	add r0, r4, #0
	bl ov97_0221E864
	ldr r0, [r7]
	mov r6, #0
	ldr r0, [r0, #4]
	cmp r0, #0
	bne _0221E76A
	mov r6, #1
_0221E76A:
	ldr r0, [r5]
	bl SaveArray_PCStorage_Get
	add r7, r0, #0
	ldr r0, [r5]
	bl SaveArray_Party_Get
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, #0x12
	str r0, [sp, #0xc]
	ldr r0, _0221E7E4 ; =ov97_0221E91C
	add r2, r7, #0
	str r0, [sp, #0x10]
	ldr r0, _0221E7E8 ; =ov97_0221E97C
	str r0, [sp, #0x14]
	add r0, r4, #0
	add r0, #0x10
	str r0, [sp, #0x18]
	ldr r0, _0221E7EC ; =ov97_0221EC14
	str r0, [sp, #0x1c]
	str r4, [sp, #0x20]
	ldr r0, [r4, #8]
	ldr r1, [r4]
	bl sub_02093440
	mov r0, #2
	bl sub_0203A994
	ldr r2, [r4, #0x30]
	ldrb r3, [r5, #0xf]
	lsl r2, r2, #0x18
	ldr r0, [r4, #0xc]
	ldr r1, [r4]
	lsr r2, r2, #0x18
	bl ov97_0221EEA4
	ldr r0, _0221E7F0 ; =ov97_0221E88C
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0
	str r0, [r4, #4]
	bl ResetAllTextPrinters
	mov r1, #0x1e
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #0x5c
	bl LoadFontPal0
	mov r0, #2
	mov r1, #0x5c
	bl FontID_Alloc
	mov r0, #1
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221E7E4: .word ov97_0221E91C
_0221E7E8: .word ov97_0221E97C
_0221E7EC: .word ov97_0221EC14
_0221E7F0: .word ov97_0221E88C
	thumb_func_end ov97_0221E700
