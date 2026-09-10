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

	thumb_func_start ov97_0221EEA4
ov97_0221EEA4: ; 0x0221EEA4
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r5, r0, #0
	str r1, [r5, #4]
	add r0, r1, #0
	ldr r1, [r5]
	add r4, r2, #0
	add r6, r3, #0
	bl ov97_0221F14C
	mov r3, #1
	add r1, r5, #0
	str r3, [sp]
	mov r0, #0x11
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xf
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, [r5, #4]
	add r1, #8
	mov r2, #4
	bl AddWindowParameterized
	mov r0, #1
	str r0, [sp]
	mov r0, #9
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xf
	str r0, [sp, #0xc]
	mov r0, #0x23
	str r0, [sp, #0x10]
	add r1, r5, #0
	ldr r0, [r5, #4]
	add r1, #0x18
	mov r2, #4
	mov r3, #0x16
	bl AddWindowParameterized
	mov r1, #0xf
	str r1, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, #0x35
	str r0, [sp, #0x10]
	add r1, r5, #0
	ldr r0, [r5, #4]
	add r1, #0x28
	mov r2, #5
	mov r3, #1
	bl AddWindowParameterized
	mov r1, #0xf
	str r1, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, #0x45
	str r0, [sp, #0x10]
	add r1, r5, #0
	ldr r0, [r5, #4]
	add r1, #0x38
	mov r2, #5
	mov r3, #9
	bl AddWindowParameterized
	mov r2, #5
	add r1, r5, #0
	str r2, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0xf
	str r0, [sp, #0xc]
	mov r0, #0x4b
	str r0, [sp, #0x10]
	ldr r0, [r5, #4]
	add r1, #0x48
	mov r3, #0xd
	bl AddWindowParameterized
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0xc
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xf
	str r0, [sp, #0xc]
	mov r0, #0xaf
	str r0, [sp, #0x10]
	add r1, r5, #0
	ldr r0, [r5, #4]
	add r1, #0x58
	mov r2, #5
	mov r3, #1
	bl AddWindowParameterized
	mov r1, #0x1b
	add r2, r1, #0
	ldr r3, [r5]
	mov r0, #1
	add r2, #0xfb
	bl NewMsgDataFromNarc
	str r0, [r5, #0x6c]
	ldr r0, [r5]
	bl MessageFormat_New
	str r0, [r5, #0x70]
	ldr r1, [r5]
	mov r0, #0xb
	bl String_New
	str r0, [r5, #0x74]
	add r0, r5, #0
	add r0, #0x68
	strh r4, [r0]
	add r0, r5, #0
	add r0, #0x6a
	strh r6, [r0]
	add r0, r5, #0
	add r0, #0x78
	bl ov97_0221F7DC
	add r0, r5, #0
	add r0, #0x78
	bl ov97_0221F9E0
	add r0, r5, #0
	bl ov97_0221F294
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	thumb_func_end ov97_0221EEA4


	thumb_func_start ov97_0221EFD0
ov97_0221EFD0: ; 0x0221EFD0
	push {r3, r4, r5, lr}
	add r4, r1, #0
	ldrb r2, [r4, #9]
	add r5, r0, #0
	cmp r2, #2
	bne _0221EFFA
	bl ov97_0221F56C
	add r0, r5, #0
	add r1, r4, #0
	bl ov97_0221F428
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	pop {r3, r4, r5, pc}
_0221EFFA:
	bl ov97_0221F74C
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	pop {r3, r4, r5, pc}
	thumb_func_end ov97_0221EFD0
