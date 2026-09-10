	.include "asm/macros.inc"
	.include "overlay_68.inc"
	.include "global.inc"

	.text
	.public MoveRelearner_Exit
	.public MoveRelearner_Init
	.public MoveRelearner_Main
	.public _021E7BE8
	.public ov68_021E5A58
	.public ov68_021E5BA0
	.public ov68_021E5BC0
	.public ov68_021E5D24
	.public ov68_021E5E48
	.public ov68_021E5F68
	.public ov68_021E6078
	.public ov68_021E60D8
	.public ov68_021E614C
	.public ov68_021E61B8
	.public ov68_021E6234
	.public ov68_021E62D4
	.public ov68_021E6320
	.public ov68_021E66A0
	.public ov68_021E66F0
	.public ov68_021E67E0
	.public ov68_021E6820
	.public ov68_021E68D4
	.public ov68_021E6A2C
	.public ov68_021E6C14
	.public ov68_021E6DDC
	.public ov68_021E6EB8
	.public ov68_021E7028
	.public ov68_021E70BC
	.public ov68_021E7124
	.public ov68_021E7178
	.public ov68_021E71C4
	.public ov68_021E7224
	.public ov68_021E7288
	.public ov68_021E734C
	.public ov68_021E73A4
	.public ov68_021E7424
	.public ov68_021E74D8
	.public ov68_021E7568
	.public ov68_021E75C0
	.public ov68_021E7618
	.public ov68_021E773C
	.public ov68_021E7898
	.public ov68_021E7910
	.public ov68_021E797C
	.public ov68_021E7A18
	.public ov68_021E7AD8
	.public ov68_021E7BC8
	.public ov68_021E7BEC
	.public ov68_021E7BF8
	.public ov68_021E7C08
	.public ov68_021E7C18
	.public ov68_021E7C2C
	.public ov68_021E7C44
	.public ov68_021E7C60
	.public ov68_021E7C7C
	.public ov68_021E7C98
	.public ov68_021E7CB4
	.public ov68_021E7CD0
	.public ov68_021E7CF0
	.public ov68_021E7D14
	.public ov68_021E7D3C
	.public ov68_021E7D40
	.public ov68_021E7D64
	.public ov68_021E7DA4
	.public ov68_021E7DFC
	.public ov68_021E7E74
	.public ov68_021E5B14
	.public ov68_021E5B6C
	.public ov68_021E5CD8
	.public ov68_021E5E38
	.public ov68_021E5E94
	.public ov68_021E5EBC
	.public ov68_021E5F18
	.public ov68_021E5F50
	.public ov68_021E6058
	.public ov68_021E61A0
	.public ov68_021E61EC
	.public ov68_021E6204
	.public ov68_021E6678
	.public ov68_021E68C4
	.public ov68_021E6BEC
	.public ov68_021E6BFC
	.public ov68_021E6C74
	.public ov68_021E6C8C
	.public ov68_021E6CD8
	.public ov68_021E6D00
	.public ov68_021E6D20
	.public ov68_021E6D40
	.public ov68_021E6D4C
	.public ov68_021E6D58
	.public ov68_021E6D64
	.public ov68_021E6D80
	.public ov68_021E6D9C
	.public ov68_021E6DB8
	.public ov68_021E6DD0
	.public ov68_021E6E84
	.public ov68_021E7388
	.public ov68_021E74C0
	.public ov68_021E7604
	.public ov68_021E7614
	.public ov68_021E7A90
	.public ov68_021E7AB4
	.public ov68_021E7B6C
	.public ov68_021E7B8C
	.public ov68_021E7B94

	thumb_func_start ov68_021E6234
ov68_021E6234: ; 0x021E6234
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	ldr r0, [sp, #0x28]
	add r4, r1, #0
	add r7, r2, #0
	str r3, [sp, #0x10]
	cmp r0, #0
	beq _021E6250
	cmp r0, #1
	beq _021E6254
	cmp r0, #2
	beq _021E627E
	b _021E62AA
_021E6250:
	mov r3, #0
	b _021E62AA
_021E6254:
	mov r1, #1
	lsl r1, r1, #8
	ldr r1, [r5, r1]
	add r0, r7, #0
	mov r2, #0
	bl FontID_String_GetWidth
	lsl r0, r0, #0x18
	add r1, r5, #0
	lsr r6, r0, #0x18
	add r1, #8
	lsl r0, r4, #4
	add r0, r1, r0
	bl GetWindowWidth
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x18
	sub r0, r0, r6
	lsl r0, r0, #0x18
	lsr r3, r0, #0x18
	b _021E62AA
_021E627E:
	mov r1, #1
	lsl r1, r1, #8
	ldr r1, [r5, r1]
	add r0, r7, #0
	mov r2, #0
	bl FontID_String_GetWidth
	lsl r0, r0, #0x18
	add r1, r5, #0
	lsr r6, r0, #0x18
	add r1, #8
	lsl r0, r4, #4
	add r0, r1, r0
	bl GetWindowWidth
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x18
	sub r1, r0, r6
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0x17
	lsr r3, r0, #0x18
_021E62AA:
	add r0, sp, #0x18
	ldrb r0, [r0, #0x14]
	add r1, r5, #0
	mov r2, #0xff
	str r0, [sp]
	str r2, [sp, #4]
	ldr r0, [sp, #0x10]
	add r2, r2, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r1, #8
	lsl r0, r4, #4
	add r0, r1, r0
	ldr r2, [r5, r2]
	add r1, r7, #0
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov68_021E6234


	thumb_func_start ov68_021E62D4
ov68_021E62D4: ; 0x021E62D4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r0, #0xf8
	ldr r0, [r0]
	add r6, r2, #0
	add r7, r3, #0
	bl NewString_ReadMsgData
	add r4, r0, #0
	add r0, sp, #0x10
	ldrb r0, [r0, #0x10]
	mov r1, #0
	add r2, r6, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0xfc
	ldr r0, [r0]
	add r3, r7, #0
	bl BufferIntegerAsString
	add r0, r5, #0
	mov r1, #1
	add r0, #0xfc
	lsl r1, r1, #8
	ldr r0, [r0]
	ldr r1, [r5, r1]
	add r2, r4, #0
	bl StringExpandPlaceholders
	add r0, r4, #0
	bl String_Delete
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov68_021E62D4


	thumb_func_start ov68_021E6320
ov68_021E6320: ; 0x021E6320
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	mov r1, #0x24
	add r2, r1, #0
	add r5, r0, #0
	add r0, #0xf8
	add r2, #0xdc
	ldr r0, [r0]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	mov r2, #0
	str r2, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r3, _021E666C ; =0x00010200
	add r0, r5, #0
	mov r1, #7
	bl ov68_021E6234
	add r0, r5, #0
	add r0, #0x78
	bl ScheduleWindowCopyToVram
	mov r1, #0x23
	add r0, r5, #0
	add r2, r1, #0
	add r0, #0xf8
	add r2, #0xdd
	ldr r0, [r0]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	mov r0, #2
	str r0, [sp]
	mov r2, #4
	ldr r3, _021E6670 ; =0x000F0E00
	add r0, r5, #0
	mov r1, #8
	str r2, [sp, #4]
	bl ov68_021E6234
	mov r1, #0x22
	add r0, r5, #0
	add r2, r1, #0
	add r0, #0xf8
	add r2, #0xde
	ldr r0, [r0]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	mov r0, #2
	str r0, [sp]
	mov r2, #4
	ldr r3, _021E6670 ; =0x000F0E00
	add r0, r5, #0
	mov r1, #9
	str r2, [sp, #4]
	bl ov68_021E6234
	add r0, r5, #0
	add r0, #0x98
	bl ScheduleWindowCopyToVram
	mov r1, #0x16
	add r0, r5, #0
	add r2, r1, #0
	add r0, #0xf8
	add r2, #0xea
	ldr r0, [r0]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	mov r1, #0
	str r1, [sp]
	ldr r3, _021E6670 ; =0x000F0E00
	add r0, r5, #0
	add r2, r1, #0
	str r1, [sp, #4]
	bl ov68_021E6234
	add r0, r5, #0
	add r0, #8
	bl ScheduleWindowCopyToVram
	mov r1, #0x17
	add r0, r5, #0
	add r2, r1, #0
	add r0, #0xf8
	add r2, #0xe9
	ldr r0, [r0]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	mov r2, #0
	str r2, [sp]
	ldr r3, _021E6670 ; =0x000F0E00
	add r0, r5, #0
	mov r1, #1
	str r2, [sp, #4]
	bl ov68_021E6234
	add r0, r5, #0
	add r0, #0x18
	bl ScheduleWindowCopyToVram
	mov r1, #0x18
	add r0, r5, #0
	add r2, r1, #0
	add r0, #0xf8
	add r2, #0xe8
	ldr r0, [r0]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	mov r2, #0
	str r2, [sp]
	ldr r3, _021E6670 ; =0x000F0E00
	add r0, r5, #0
	mov r1, #2
	str r2, [sp, #4]
	bl ov68_021E6234
	add r0, r5, #0
	add r0, #0x28
	bl ScheduleWindowCopyToVram
	mov r0, #1
	lsl r0, r0, #8
	mov r1, #0x42
	bl String_New
	str r0, [sp, #0x20]
	add r0, r5, #0
	add r0, #0xf8
	ldr r0, [r0]
	ldr r2, [sp, #0x20]
	mov r1, #0x27
	bl ReadMsgDataIntoString
	ldr r0, [r5]
	ldr r0, [r0]
	bl Mon_GetBoxMon
	add r2, r0, #0
	add r0, r5, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	bl BufferBoxMonNickname
	add r0, r5, #0
	mov r1, #1
	add r0, #0xfc
	lsl r1, r1, #8
	ldr r0, [r0]
	ldr r1, [r5, r1]
	ldr r2, [sp, #0x20]
	bl StringExpandPlaceholders
	mov r2, #0
	str r2, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r3, _021E666C ; =0x00010200
	add r0, r5, #0
	mov r1, #0xc
	bl ov68_021E6234
	add r0, r5, #0
	add r0, #0xc8
	bl ScheduleWindowCopyToVram
	ldr r2, _021E6674 ; =0x000002EE
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x42
	bl NewMsgDataFromNarc
	str r0, [sp, #0x1c]
	ldr r0, [r5]
	ldr r0, [r0]
	bl Mon_GetBoxMon
	str r0, [sp, #0x18]
	add r0, r5, #0
	mov r4, #0
	str r0, [sp, #0x24]
	add r0, #0xd8
	add r7, r5, #0
	str r4, [sp, #0x10]
	mov r6, #0x10
	str r0, [sp, #0x24]
_021E64A2:
	add r1, r4, #0
	ldr r0, [sp, #0x18]
	add r1, #0x36
	mov r2, #0
	bl GetBoxMonData
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x14]
	bne _021E64C4
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _021E659C
_021E64C4:
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r2, r4, #4
	lsl r2, r2, #0x10
	ldr r1, [sp, #0x14]
	add r0, r5, #0
	lsr r2, r2, #0x10
	bl ov68_021E7028
	mov r2, #1
	lsl r2, r2, #8
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x14]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	mov r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x10]
	ldr r3, _021E6670 ; =0x000F0E00
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #0xd
	mov r2, #0
	bl ov68_021E6234
	mov r2, #0x41
	str r6, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E666C ; =0x00010200
	lsl r2, r2, #2
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x24]
	ldr r2, [r5, r2]
	mov r1, #0
	mov r3, #0x10
	bl AddTextPrinterParameterizedWithColor
	add r1, r4, #0
	ldr r0, [sp, #0x18]
	add r1, #0x3a
	mov r2, #0
	bl GetBoxMonData
	add r2, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	mov r3, #2
	bl BufferIntegerAsString
	add r1, r4, #0
	ldr r0, [sp, #0x18]
	add r1, #0x42
	mov r2, #0
	bl GetBoxMonData
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #1
	mov r3, #2
	bl BufferIntegerAsString
	add r0, r5, #0
	mov r1, #1
	mov r2, #0x42
	add r0, #0xfc
	lsl r1, r1, #8
	lsl r2, r2, #2
	ldr r0, [r0]
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	bl StringExpandPlaceholders
	mov r2, #1
	str r6, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E666C ; =0x00010200
	lsl r2, r2, #8
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x24]
	ldr r2, [r5, r2]
	mov r1, #0
	mov r3, #0x2d
	bl AddTextPrinterParameterizedWithColor
_021E659C:
	ldr r0, [sp, #0x10]
	add r4, r4, #1
	add r0, #0x20
	add r7, r7, #4
	add r6, #0x20
	str r0, [sp, #0x10]
	cmp r4, #4
	bhs _021E65AE
	b _021E64A2
_021E65AE:
	add r0, r5, #0
	add r0, #0xd8
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #0xf8
	ldr r0, [r0]
	ldr r2, [sp, #0x20]
	mov r1, #0x25
	bl ReadMsgDataIntoString
	add r0, r5, #0
	add r0, #0xfc
	ldr r0, [r0]
	ldr r2, [sp, #0x18]
	mov r1, #0
	bl BufferBoxMonSpeciesName
	add r0, r5, #0
	mov r1, #1
	add r0, #0xfc
	lsl r1, r1, #8
	ldr r0, [r0]
	ldr r1, [r5, r1]
	ldr r2, [sp, #0x20]
	bl StringExpandPlaceholders
	mov r1, #0
	str r1, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E666C ; =0x00010200
	add r2, r2, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r5, #0
	ldr r2, [r5, r2]
	add r0, #0xe8
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #0xf8
	ldr r0, [r0]
	ldr r2, [sp, #0x20]
	mov r1, #0x26
	bl ReadMsgDataIntoString
	ldr r0, [sp, #0x18]
	mov r1, #0xa1
	mov r2, #0
	bl GetBoxMonData
	add r2, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	mov r3, #3
	bl BufferIntegerAsString
	add r0, r5, #0
	mov r1, #1
	add r0, #0xfc
	lsl r1, r1, #8
	ldr r0, [r0]
	ldr r1, [r5, r1]
	ldr r2, [sp, #0x20]
	bl StringExpandPlaceholders
	mov r0, #1
	str r0, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	ldr r3, _021E666C ; =0x00010200
	add r0, r5, #0
	mov r1, #0xe
	mov r2, #0
	bl ov68_021E6234
	add r5, #0xe8
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	ldr r0, [sp, #0x1c]
	bl DestroyMsgData
	ldr r0, [sp, #0x20]
	bl String_Delete
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E666C: .word 0x00010200
_021E6670: .word 0x000F0E00
_021E6674: .word 0x000002EE
	thumb_func_end ov68_021E6320
