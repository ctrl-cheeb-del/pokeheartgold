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

	thumb_func_start ov68_021E68D4
ov68_021E68D4: ; 0x021E68D4
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	add r4, r1, #0
	add r0, #0x58
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #0x38
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #0x48
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #1
	mvn r0, r0
	cmp r4, r0
	beq _021E69EE
	add r0, r4, #0
	mov r1, #2
	bl GetMoveAttr
	add r2, r0, #0
	cmp r2, #1
	bhi _021E692E
	mov r1, #0x21
	add r0, r5, #0
	add r2, r1, #0
	add r0, #0xf8
	add r2, #0xdf
	ldr r0, [r0]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	b _021E693C
_021E692E:
	mov r0, #0
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0x1d
	mov r3, #3
	bl ov68_021E62D4
_021E693C:
	mov r0, #1
	str r0, [sp]
	mov r2, #0
	ldr r3, _021E6A24 ; =0x00010200
	add r0, r5, #0
	mov r1, #3
	str r2, [sp, #4]
	bl ov68_021E6234
	add r0, r4, #0
	mov r1, #4
	bl GetMoveAttr
	add r2, r0, #0
	bne _021E696E
	mov r1, #0x21
	add r0, r5, #0
	add r2, r1, #0
	add r0, #0xf8
	add r2, #0xdf
	ldr r0, [r0]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	b _021E697C
_021E696E:
	mov r0, #0
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0x1e
	mov r3, #3
	bl ov68_021E62D4
_021E697C:
	mov r0, #1
	str r0, [sp]
	mov r2, #0
	ldr r3, _021E6A24 ; =0x00010200
	add r0, r5, #0
	mov r1, #4
	str r2, [sp, #4]
	bl ov68_021E6234
	ldr r2, _021E6A28 ; =0x000002ED
	mov r0, #1
	mov r1, #0x1b
	mov r3, #0x42
	bl NewMsgDataFromNarc
	mov r2, #1
	lsl r2, r2, #8
	ldr r2, [r5, r2]
	add r1, r4, #0
	add r6, r0, #0
	bl ReadMsgDataIntoString
	mov r2, #0
	str r2, [sp]
	ldr r3, _021E6A24 ; =0x00010200
	add r0, r5, #0
	mov r1, #5
	str r2, [sp, #4]
	bl ov68_021E6234
	add r0, r6, #0
	bl DestroyMsgData
	lsl r1, r4, #0x10
	add r0, r5, #0
	lsr r1, r1, #0x10
	bl ov68_021E7124
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r0, r5, #0
	add r0, #8
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #0x18
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #0x28
	bl ScheduleWindowCopyToVram
	b _021E6A06
_021E69EE:
	add r0, r5, #0
	add r0, #8
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r5, #0
	add r0, #0x18
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r5, #0
	add r0, #0x28
	bl ClearWindowTilemapAndScheduleTransfer
_021E6A06:
	add r0, r5, #0
	add r0, #0x58
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #0x38
	bl ScheduleWindowCopyToVram
	add r5, #0x48
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_021E6A24: .word 0x00010200
_021E6A28: .word 0x000002ED
	thumb_func_end ov68_021E68D4


	thumb_func_start ov68_021E6A2C
ov68_021E6A2C: ; 0x021E6A2C
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r4, r0, #0
	cmp r5, #0xa
	bls _021E6A38
	b _021E6BB0
_021E6A38:
	add r1, r5, r5
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E6A44: ; jump table
	.short _021E6A5A - _021E6A44 - 2 ; case 0
	.short _021E6A72 - _021E6A44 - 2 ; case 1
	.short _021E6A86 - _021E6A44 - 2 ; case 2
	.short _021E6A9E - _021E6A44 - 2 ; case 3
	.short _021E6ACA - _021E6A44 - 2 ; case 4
	.short _021E6AF6 - _021E6A44 - 2 ; case 5
	.short _021E6B22 - _021E6A44 - 2 ; case 6
	.short _021E6B4E - _021E6A44 - 2 ; case 7
	.short _021E6B62 - _021E6A44 - 2 ; case 8
	.short _021E6B8E - _021E6A44 - 2 ; case 9
	.short _021E6B9E - _021E6A44 - 2 ; case 10
_021E6A5A:
	ldr r0, [r4]
	ldr r0, [r0]
	bl Mon_GetBoxMon
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	bl BufferBoxMonNickname
	b _021E6BB0
_021E6A72:
	bl ov68_021E6BEC
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #1
	bl BufferMoveName
	b _021E6BB0
_021E6A86:
	ldr r0, [r4]
	ldr r0, [r0]
	bl Mon_GetBoxMon
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	bl BufferBoxMonNickname
	b _021E6BB0
_021E6A9E:
	ldr r0, [r4]
	ldr r0, [r0]
	bl Mon_GetBoxMon
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	bl BufferBoxMonNickname
	add r0, r4, #0
	bl ov68_021E6BEC
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #1
	bl BufferMoveName
	b _021E6BB0
_021E6ACA:
	ldr r0, [r4]
	ldr r0, [r0]
	bl Mon_GetBoxMon
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	bl BufferBoxMonNickname
	add r0, r4, #0
	bl ov68_021E6BEC
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #1
	bl BufferMoveName
	b _021E6BB0
_021E6AF6:
	ldr r0, [r4]
	ldr r0, [r0]
	bl Mon_GetBoxMon
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	bl BufferBoxMonNickname
	add r0, r4, #0
	bl ov68_021E6BFC
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #1
	bl BufferMoveName
	b _021E6BB0
_021E6B22:
	ldr r0, [r4]
	ldr r0, [r0]
	bl Mon_GetBoxMon
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	bl BufferBoxMonNickname
	add r0, r4, #0
	bl ov68_021E6BEC
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #1
	bl BufferMoveName
	b _021E6BB0
_021E6B4E:
	bl ov68_021E6BEC
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #1
	bl BufferMoveName
	b _021E6BB0
_021E6B62:
	ldr r0, [r4]
	ldr r0, [r0]
	bl Mon_GetBoxMon
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	bl BufferBoxMonNickname
	add r0, r4, #0
	bl ov68_021E6BEC
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #1
	bl BufferMoveName
	b _021E6BB0
_021E6B8E:
	ldr r2, [r4]
	add r0, #0xfc
	ldr r0, [r0]
	ldr r2, [r2, #4]
	mov r1, #2
	bl BufferPlayersName
	b _021E6BB0
_021E6B9E:
	bl ov68_021E6BFC
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	bl BufferMoveName
_021E6BB0:
	ldr r1, [r4]
	add r0, r4, #0
	ldrb r2, [r1, #0x19]
	add r0, #0xf8
	mov r1, #0x2c
	add r3, r2, #0
	mul r3, r1
	ldr r1, _021E6BE8 ; =ov68_021E7DA4
	lsl r2, r5, #2
	add r1, r1, r3
	ldr r0, [r0]
	ldr r1, [r2, r1]
	bl NewString_ReadMsgData
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #1
	add r0, #0xfc
	lsl r1, r1, #8
	ldr r0, [r0]
	ldr r1, [r4, r1]
	add r2, r5, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	bl String_Delete
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E6BE8: .word ov68_021E7DA4
	thumb_func_end ov68_021E6A2C
