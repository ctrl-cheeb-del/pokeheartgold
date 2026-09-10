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

	thumb_func_start ov103_021EE644
ov103_021EE644: ; 0x021EE644
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0x6e
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	add r0, r1, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r2, #0x8a
	ldr r3, [r5, #0xc]
	lsl r2, r2, #2
	ldr r0, [r3, r2]
	add r2, #8
	ldr r2, [r3, r2]
	mov r1, #2
	bl ReadMsgDataIntoString
	mov r1, #0x6e
	ldr r2, [r5, #0xc]
	mov r3, #0
	ldr r0, _021EE780 ; =0x00010200
	str r3, [sp]
	str r0, [sp, #4]
	mov r0, #2
	lsl r1, r1, #2
	str r0, [sp, #8]
	add r0, r2, r1
	add r1, #0x78
	ldr r1, [r2, r1]
	mov r2, #0x14
	bl ov103_021EE3E4
	mov r1, #0x23
	ldr r2, [r5, #0xc]
	lsl r1, r1, #4
	mov r0, #0
	ldr r1, [r2, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0
	lsl r4, r0, #0x10
	mov r0, #0x8b
	str r1, [sp]
	mov r3, #1
	str r3, [sp, #4]
	ldr r2, [r5, #0xc]
	lsl r0, r0, #2
	ldr r0, [r2, r0]
	ldrh r2, [r5, #0x1c]
	add r2, r2, #1
	bl BufferIntegerAsString
	mov r0, #0x8a
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #1
	bl NewString_ReadMsgData
	mov r1, #0x8b
	ldr r2, [r5, #0xc]
	lsl r1, r1, #2
	add r6, r0, #0
	ldr r0, [r2, r1]
	add r1, r1, #4
	ldr r1, [r2, r1]
	add r2, r6, #0
	bl StringExpandPlaceholders
	add r0, r6, #0
	bl String_Delete
	mov r1, #0x23
	ldr r2, [r5, #0xc]
	lsl r1, r1, #4
	mov r0, #0
	ldr r1, [r2, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	lsl r0, r0, #0x10
	lsr r2, r0, #0x10
	mov r6, #0x6e
	ldr r1, [r5, #0xc]
	mov r3, #0
	ldr r0, _021EE780 ; =0x00010200
	str r3, [sp]
	str r0, [sp, #4]
	lsl r6, r6, #2
	add r0, r1, r6
	str r3, [sp, #8]
	add r6, #0x78
	ldr r1, [r1, r6]
	lsr r4, r4, #0x11
	mov r6, #0x14
	sub r6, r6, r4
	sub r2, r6, r2
	bl ov103_021EE3E4
	ldr r6, [r5, #0xc]
	mov r1, #0
	mov r2, #0x8b
	str r1, [sp]
	mov r3, #1
	str r3, [sp, #4]
	lsl r2, r2, #2
	ldr r0, [r6, r2]
	add r2, #0xb6
	ldrh r2, [r6, r2]
	add r2, r2, #1
	bl BufferIntegerAsString
	mov r0, #0x8a
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #1
	bl NewString_ReadMsgData
	mov r1, #0x8b
	ldr r2, [r5, #0xc]
	lsl r1, r1, #2
	add r6, r0, #0
	ldr r0, [r2, r1]
	add r1, r1, #4
	ldr r1, [r2, r1]
	add r2, r6, #0
	bl StringExpandPlaceholders
	add r0, r6, #0
	bl String_Delete
	mov r1, #0x6e
	ldr r2, [r5, #0xc]
	mov r3, #0
	ldr r0, _021EE780 ; =0x00010200
	str r3, [sp]
	str r0, [sp, #4]
	lsl r1, r1, #2
	add r0, r2, r1
	str r3, [sp, #8]
	add r1, #0x78
	ldr r1, [r2, r1]
	add r4, #0x14
	add r2, r4, #0
	bl ov103_021EE3E4
	mov r0, #0x6e
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	add r0, r1, r0
	bl ScheduleWindowCopyToVram
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021EE780: .word 0x00010200
	thumb_func_end ov103_021EE644
