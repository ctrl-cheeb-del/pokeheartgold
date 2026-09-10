	.include "asm/macros.inc"
	.public ov98_0221E5C0
	.public ov98_0221E5D0
	.public ov98_0221E5E0
	.public ov98_0221E684
	.public ov98_0221E6CC
	.public ov98_0221E6E0
	.public ov98_0221E6F0
	.public ov98_0221E784
	.public ov98_0221E7E8
	.public ov98_0221E8A8
	.public ov98_0221E970
	.public ov98_0221E9FC
	.public ov98_0221EA4C
	.public ov98_0221EAA8
	.public ov98_0221EABC
	.public ov98_0221EB84
	.public ov98_0221EBD8
	.public ov98_0221EBEC
	.public ov98_0221EC08
	.public ov98_0221EC24
	.public ov98_0221EC3C
	.public ov98_0221ECD0
	.public ov98_0221ED3C
	.public ov98_0221ED48
	.public ov98_0221EDA4
	.public ov98_0221EDC4
	.public ov98_0221EE28
	.public ov98_0221EE84
	.public ov98_0221EE9C
	.public ov98_0221EEDC
	.public ov98_0221EEEC
	.public ov98_0221EEFC
	.public ov98_0221EF14
	.public ov98_0221EF24
	.public ov98_0221EF64
	.public ov98_0221EF80
	.public ov98_0221EFA4
	.public ov98_0221EFB4
	.public ov98_0221EFE8
	.public ov98_0221F01C
	.public ov98_0221F024
	.public ov98_0221F058
	.public ov98_0221F090
	.public ov98_0221F0EC
	.public ov98_0221F120
	.public ov98_0221F150
	.public ov98_0221F174
	.public _0221F194
	.public ov98_0221F19C
	.public ov98_0221F1AC
	.public ov98_0221F1C0
	.public ov98_0221F1E0
	.public ov98_0221F1E4
	.public ov98_0221F1F8
	.public ov98_0221F220
	.public ov98_0221F248
	.include "overlay_98.inc"
	.include "global.inc"

	.text

	thumb_func_start ov98_0221EC3C
ov98_0221EC3C: ; 0x0221EC3C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	ldr r0, [r5, #0x18]
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp, #0x10]
	mov r4, #0
	cmp r6, r0
	blo _0221EC54
	bl GF_AssertFail
_0221EC54:
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #8]
	ldr r3, [r5]
	add r2, r7, #0
	bl ReadMsgData_ExpandPlaceholders
	add r7, r0, #0
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _0221EC8A
	ldr r1, [r5, #4]
	lsl r0, r6, #4
	add r0, r1, r0
	bl GetWindowWidth
	lsl r0, r0, #0x1b
	lsr r4, r0, #0x18
	ldr r0, [sp, #0x30]
	add r1, r7, #0
	mov r2, #0
	bl FontID_String_GetWidthMultiline
	sub r0, r4, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	lsl r0, r0, #0x17
	lsr r4, r0, #0x18
_0221EC8A:
	add r1, sp, #0x18
	ldr r0, [r5, #4]
	lsl r6, r6, #4
	ldrb r1, [r1, #0x1c]
	add r0, r0, r6
	bl FillWindowPixelBuffer
	add r3, sp, #0x18
	ldrb r0, [r3, #0x14]
	ldr r1, [sp, #0x30]
	add r2, r7, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0221ECCC ; =0x00010200
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldrb r3, [r3, #0x10]
	ldr r0, [r5, #4]
	add r0, r0, r6
	add r3, r4, r3
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [r5, #4]
	add r0, r0, r6
	bl ScheduleWindowCopyToVram
	add r0, r7, #0
	bl String_Delete
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221ECCC: .word 0x00010200
	thumb_func_end ov98_0221EC3C
