	.include "asm/macros.inc"
	.include "overlay_103.inc"
	.include "global.inc"

	.text
	.public _021EEB34
	.public ov103_021EC9B4
	.public ov103_021EC9E8
	.public ov103_021ECC1C
	.public ov103_021ECD68
	.public ov103_021ECF68
	.public ov103_021ED00C
	.public ov103_021ED0C0
	.public ov103_021ED144
	.public ov103_021ED4D4
	.public ov103_021ED5B4
	.public ov103_021ED7E4
	.public ov103_021ED9AC
	.public ov103_021EDA98
	.public ov103_021EDD54
	.public ov103_021EDD98
	.public ov103_021EDE7C
	.public ov103_021EDEA8
	.public ov103_021EDF88
	.public ov103_021EE078
	.public ov103_021EE160
	.public ov103_021EE210
	.public ov103_021EE2E0
	.public ov103_021EE468
	.public ov103_021EE550
	.public ov103_021EE644
	.public ov103_021EE7DC
	.public ov103_021EE8A8
	.public ov103_021EE930
	.public ov103_021EE9C8
	.public ov103_021EEB40
	.public ov103_021EEB50
	.public ov103_021EEB6C
	.public ov103_021EEB88
	.public ov103_021EEBA4
	.public ov103_021EEBC0
	.public ov103_021EEBDC
	.public ov103_021EEBF8
	.public ov103_021EEC14
	.public ov103_021EEC30
	.public ov103_021EEC58
	.public ov103_021EEC68
	.public ov103_021EEC78
	.public ov103_021EECA8
	.public ov103_021EED0C
	.public ov103_021EED20
	.public ov103_021EED38
	.public ov103_021EED58
	.public ov103_021EEEC4
	.public ov103_021EEFB4
	.public ov103_021EEFBC
	.public ov103_021EEFC8
	.public ov103_021EEFD8
	.public ov103_021EF008
	.public ov103_021EC940
	.public ov103_021EC988
	.public ov103_021EC9A4
	.public ov103_021EC9D8
	.public ov103_021ECBBC
	.public ov103_021ECD18
	.public ov103_021ECE0C
	.public ov103_021ECE18
	.public ov103_021ECE54
	.public ov103_021ECE80
	.public ov103_021ECE94
	.public ov103_021ECEA4
	.public ov103_021ECEEC
	.public ov103_021ECF48
	.public ov103_021ECFFC
	.public ov103_021ED0A0
	.public ov103_021ED124
	.public ov103_021ED23C
	.public ov103_021ED2B8
	.public ov103_021ED2D4
	.public ov103_021ED314
	.public ov103_021ED3E8
	.public ov103_021ED460
	.public ov103_021ED47C
	.public ov103_021ED53C
	.public ov103_021ED550
	.public ov103_021ED568
	.public ov103_021ED5A8
	.public ov103_021ED750
	.public ov103_021ED760
	.public ov103_021ED7A4
	.public ov103_021ED7D8
	.public ov103_021ED8D0
	.public ov103_021ED8F8
	.public ov103_021ED930
	.public ov103_021ED93C
	.public ov103_021ED954
	.public ov103_021ED960
	.public ov103_021ED97C
	.public ov103_021ED99C
	.public ov103_021ED9D8
	.public ov103_021EDA14
	.public ov103_021EDA40
	.public ov103_021EDA70
	.public ov103_021EDA84
	.public ov103_021EDB18
	.public ov103_021EDB60
	.public ov103_021EDBB0
	.public ov103_021EDBC8
	.public ov103_021EDC00
	.public ov103_021EDC58
	.public ov103_021EDC68
	.public ov103_021EDCC8
	.public ov103_021EDCE0
	.public ov103_021EDD14
	.public ov103_021EDD48
	.public ov103_021EDDE4
	.public ov103_021EDE5C
	.public ov103_021EDF50
	.public ov103_021EDF68
	.public ov103_021EE028
	.public ov103_021EE048
	.public ov103_021EE094
	.public ov103_021EE0AC
	.public ov103_021EE0CC
	.public ov103_021EE0F8
	.public ov103_021EE110
	.public ov103_021EE13C
	.public ov103_021EE150
	.public ov103_021EE374
	.public ov103_021EE390
	.public ov103_021EE3C0
	.public ov103_021EE3E4
	.public ov103_021EE430
	.public ov103_021EE60C
	.public ov103_021EE628
	.public ov103_021EE784
	.public ov103_021EE824
	.public ov103_021EE860
	.public ov103_021EE888
	.public ov103_021EEA24
	.public ov103_021EEA48
	.public ov103_021EEAA0
	.public ov103_021EEAB0
	.public ov103_021EEAB4
	.public ov103_021EEAB8
	.public ov103_021EEAC0
	.public ov103_021EEAC8
	.public ov103_021EEB04

	thumb_func_start ov103_021EE468
ov103_021EE468: ; 0x021EE468
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	str r1, [sp, #0x18]
	ldr r1, [r5, #0xc]
	lsl r0, r3, #2
	add r6, r1, #0
	add r1, r1, r0
	mov r0, #0x9f
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r6, #0x48
	lsl r7, r2, #4
	str r0, [sp, #0x20]
	bl Mail_GetAuthorNamePtr
	add r1, r0, #0
	mov r0, #0x23
	ldr r2, [r5, #0xc]
	lsl r0, r0, #4
	ldr r0, [r2, r0]
	bl CopyU16ArrayToString
	mov r4, #0
	str r4, [sp, #0x1c]
_021EE49A:
	mov r0, #8
	str r0, [sp]
	str r0, [sp, #4]
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r0, #8
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	ldr r1, [r5, #0xc]
	mov r2, #0
	add r0, r6, r7
	add r1, #8
	add r3, r2, #0
	bl BlitBitmapRectToWindow
	mov r0, #8
	str r0, [sp]
	str r0, [sp, #4]
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #8]
	mov r0, #8
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	ldr r1, [r5, #0xc]
	mov r2, #0
	add r0, r6, r7
	add r1, #0x28
	add r3, r2, #0
	bl BlitBitmapRectToWindow
	ldr r0, [sp, #0x1c]
	add r4, #8
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #8
	blo _021EE49A
	ldr r0, [sp, #0x20]
	bl Mail_GetAuthorGender
	cmp r0, #0
	bne _021EE514
	mov r0, #4
	str r0, [sp]
	ldr r0, _021EE548 ; =0x00030200
	mov r2, #0
	str r0, [sp, #4]
	str r2, [sp, #8]
	mov r1, #0x23
	ldr r3, [r5, #0xc]
	lsl r1, r1, #4
	ldr r1, [r3, r1]
	add r0, r6, r7
	add r3, r2, #0
	bl ov103_021EE3E4
	b _021EE530
_021EE514:
	mov r0, #4
	str r0, [sp]
	ldr r0, _021EE54C ; =0x00050400
	mov r2, #0
	str r0, [sp, #4]
	str r2, [sp, #8]
	mov r1, #0x23
	ldr r3, [r5, #0xc]
	lsl r1, r1, #4
	ldr r1, [r3, r1]
	add r0, r6, r7
	add r3, r2, #0
	bl ov103_021EE3E4
_021EE530:
	add r0, r6, r7
	bl CopyWindowPixelsToVram_TextMode
	ldr r0, [r5, #0xc]
	ldr r1, [sp, #0x18]
	ldr r0, [r0, #4]
	add r2, r6, r7
	bl sub_02019A60
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_021EE548: .word 0x00030200
_021EE54C: .word 0x00050400
	thumb_func_end ov103_021EE468


	thumb_func_start ov103_021EE550
ov103_021EE550: ; 0x021EE550
	push {r3, r4, lr}
	sub sp, #0x14
	add r4, r0, #0
	mov r0, #0x76
	ldr r1, [r4, #0xc]
	lsl r0, r0, #2
	add r0, r1, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [r4, #0xc]
	mov r1, #0x2c
	str r1, [sp]
	mov r3, #0
	str r3, [sp, #4]
	ldr r1, _021EE604 ; =0x00010200
	str r3, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, #2
	str r1, [sp, #0x10]
	mov r1, #0x8a
	lsl r1, r1, #2
	ldr r1, [r0, r1]
	mov r2, #0x19
	bl ov103_021EE430
	mov r0, #0x76
	ldr r1, [r4, #0xc]
	lsl r0, r0, #2
	add r0, r1, r0
	bl ScheduleWindowCopyToVram
	mov r0, #0x66
	ldr r1, [r4, #0xc]
	lsl r0, r0, #2
	add r0, r1, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [r4, #0xc]
	mov r1, #0x18
	str r1, [sp]
	mov r1, #0
	str r1, [sp, #4]
	mov r1, #4
	str r1, [sp, #8]
	ldr r1, _021EE608 ; =0x000F0100
	mov r2, #0x15
	str r1, [sp, #0xc]
	mov r1, #2
	str r1, [sp, #0x10]
	mov r1, #0x8a
	lsl r1, r1, #2
	ldr r1, [r0, r1]
	mov r3, #3
	bl ov103_021EE430
	mov r0, #0x66
	ldr r1, [r4, #0xc]
	lsl r0, r0, #2
	add r0, r1, r0
	bl ScheduleWindowCopyToVram
	mov r0, #0x6a
	ldr r1, [r4, #0xc]
	lsl r0, r0, #2
	add r0, r1, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [r4, #0xc]
	mov r1, #0x18
	str r1, [sp]
	mov r1, #0
	str r1, [sp, #4]
	mov r3, #4
	ldr r1, _021EE608 ; =0x000F0100
	str r3, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, #2
	str r1, [sp, #0x10]
	mov r1, #0x8a
	lsl r1, r1, #2
	ldr r1, [r0, r1]
	mov r2, #0x16
	bl ov103_021EE430
	add sp, #0x14
	pop {r3, r4, pc}
	nop
_021EE604: .word 0x00010200
_021EE608: .word 0x000F0100
	thumb_func_end ov103_021EE550
