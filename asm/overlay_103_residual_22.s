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

	thumb_func_start ov103_021EE8A8
ov103_021EE8A8: ; 0x021EE8A8
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #4
	bhi _021EE928
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021EE8BC: ; jump table
	.short _021EE8C6 - _021EE8BC - 2 ; case 0
	.short _021EE8DA - _021EE8BC - 2 ; case 1
	.short _021EE8EE - _021EE8BC - 2 ; case 2
	.short _021EE902 - _021EE8BC - 2 ; case 3
	.short _021EE916 - _021EE8BC - 2 ; case 4
_021EE8C6:
	mov r2, #0x8a
	ldr r3, [r4, #0xc]
	lsl r2, r2, #2
	ldr r0, [r3, r2]
	add r2, #8
	ldr r2, [r3, r2]
	mov r1, #0xa
	bl ReadMsgDataIntoString
	b _021EE928
_021EE8DA:
	mov r2, #0x8a
	ldr r3, [r4, #0xc]
	lsl r2, r2, #2
	ldr r0, [r3, r2]
	add r2, #8
	ldr r2, [r3, r2]
	mov r1, #0xb
	bl ReadMsgDataIntoString
	b _021EE928
_021EE8EE:
	mov r2, #0x8a
	ldr r3, [r4, #0xc]
	lsl r2, r2, #2
	ldr r0, [r3, r2]
	add r2, #8
	ldr r2, [r3, r2]
	mov r1, #0xc
	bl ReadMsgDataIntoString
	b _021EE928
_021EE902:
	mov r2, #0x8a
	ldr r3, [r4, #0xc]
	lsl r2, r2, #2
	ldr r0, [r3, r2]
	add r2, #8
	ldr r2, [r3, r2]
	mov r1, #0xd
	bl ReadMsgDataIntoString
	b _021EE928
_021EE916:
	mov r2, #0x8a
	ldr r3, [r4, #0xc]
	lsl r2, r2, #2
	ldr r0, [r3, r2]
	add r2, #8
	ldr r2, [r3, r2]
	mov r1, #0xe
	bl ReadMsgDataIntoString
_021EE928:
	add r0, r4, #0
	bl ov103_021EE7DC
	pop {r4, pc}
	thumb_func_end ov103_021EE8A8


	thumb_func_start ov103_021EE930
ov103_021EE930: ; 0x021EE930
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov r4, #0
	add r5, r0, #0
	add r7, r4, #0
_021EE93A:
	add r0, r4, #0
	add r0, #0x1a
	lsl r6, r0, #4
	ldr r0, [r5, #0xc]
	add r1, r7, #0
	add r0, #0x48
	add r0, r0, r6
	bl FillWindowPixelBuffer
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x1a
	add r2, r4, #0
	bl ov103_021EE9C8
	ldr r0, [r5, #0xc]
	add r0, #0x48
	add r0, r0, r6
	bl ScheduleWindowCopyToVram
	add r4, r4, #1
	cmp r4, #3
	blo _021EE93A
	mov r0, #0x86
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	add r0, r1, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldrb r0, [r5, #0x1f]
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	add r1, r1, r0
	mov r0, #0x9f
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	bl Mail_GetAuthorNamePtr
	add r1, r0, #0
	mov r0, #0x23
	ldr r2, [r5, #0xc]
	lsl r0, r0, #4
	ldr r0, [r2, r0]
	bl CopyU16ArrayToString
	mov r1, #0x86
	ldr r4, [r5, #0xc]
	mov r3, #1
	ldr r0, _021EE9C4 ; =0x00010200
	str r3, [sp]
	str r0, [sp, #4]
	mov r2, #0
	lsl r1, r1, #2
	add r0, r4, r1
	str r2, [sp, #8]
	add r1, #0x18
	ldr r1, [r4, r1]
	bl ov103_021EE3E4
	mov r0, #0x86
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	add r0, r1, r0
	bl ScheduleWindowCopyToVram
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_021EE9C4: .word 0x00010200
	thumb_func_end ov103_021EE930


	thumb_func_start ov103_021EE9C8
ov103_021EE9C8: ; 0x021EE9C8
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldrb r0, [r5, #0x1f]
	add r4, r1, #0
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	add r1, r1, r0
	mov r0, #0x9f
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	bl Mail_GetUnk20Array
	add r6, r0, #0
	bl MailMsg_IsInit
	cmp r0, #0
	beq _021EEA1C
	add r0, r6, #0
	mov r1, #0x9d
	bl MailMsg_GetExpandedString
	add r6, r0, #0
	mov r0, #1
	str r0, [sp]
	ldr r0, _021EEA20 ; =0x00010200
	mov r2, #0
	str r0, [sp, #4]
	str r2, [sp, #8]
	ldr r1, [r5, #0xc]
	lsl r0, r4, #4
	add r1, #0x48
	add r0, r1, r0
	add r1, r6, #0
	add r3, r2, #0
	bl ov103_021EE3E4
	add r0, r6, #0
	bl String_Delete
_021EEA1C:
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021EEA20: .word 0x00010200
	thumb_func_end ov103_021EE9C8
