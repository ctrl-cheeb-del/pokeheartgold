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

	thumb_func_start ov68_021E66A0
ov68_021E66A0: ; 0x021E66A0
	push {r3, r4, r5, r6, lr}
	sub sp, #0x1c
	add r4, r0, #0
	mov r0, #0x71
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r6, r1, #0
	str r3, [sp]
	add r5, r2, #0
	add r1, sp, #0x20
	ldrb r2, [r1, #0x10]
	add r3, r5, #0
	str r2, [sp, #4]
	add r2, r0, #0
	add r2, #0xc
	str r2, [sp, #8]
	ldrb r2, [r1, #0x14]
	str r2, [sp, #0xc]
	ldrb r1, [r1, #0x18]
	add r2, r6, #0
	str r1, [sp, #0x10]
	ldrh r1, [r0]
	lsl r1, r1, #0x15
	lsr r1, r1, #0x18
	str r1, [sp, #0x14]
	ldrh r0, [r0, #2]
	mov r1, #7
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r4, #4]
	bl CopyToBgTilemapRect
	ldr r0, [r4, #4]
	mov r1, #7
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x1c
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov68_021E66A0


	thumb_func_start ov68_021E66F0
ov68_021E66F0: ; 0x021E66F0
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r3, r1, r2
	mov r1, #0x6e
	add r5, r0, #0
	lsl r1, r1, #2
	ldrb r1, [r5, r1]
	lsl r4, r2, #5
	cmp r3, r1
	blt _021E6720
	mov r3, #4
	lsl r2, r2, #2
	add r2, r2, #4
	lsl r2, r2, #0x18
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	str r3, [sp, #8]
	lsr r2, r2, #0x18
	mov r3, #0x10
	bl ov68_021E66A0
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021E6720:
	str r4, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E67D8 ; =0x000F0E00
	mov r1, #0
	str r0, [sp, #8]
	lsl r6, r3, #3
	add r0, r5, #0
	str r1, [sp, #0xc]
	add r2, #0x11
	ldr r2, [r5, r2]
	add r0, #0xa8
	ldr r2, [r2, r6]
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	add r0, #0x10
	str r0, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E67DC ; =0x00010200
	mov r1, #0
	str r0, [sp, #8]
	add r0, r5, #0
	str r1, [sp, #0xc]
	add r2, r2, #5
	ldr r2, [r5, r2]
	add r0, #0xa8
	mov r3, #0x10
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0x11
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	add r0, r0, r6
	ldr r0, [r0, #4]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GetMoveMaxPP
	add r6, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0
	add r2, r6, #0
	mov r3, #2
	bl BufferIntegerAsString
	mov r0, #0
	str r0, [sp]
	mov r1, #1
	add r0, r5, #0
	str r1, [sp, #4]
	add r0, #0xfc
	ldr r0, [r0]
	add r2, r6, #0
	mov r3, #2
	bl BufferIntegerAsString
	mov r2, #1
	add r0, r5, #0
	lsl r2, r2, #8
	add r0, #0xfc
	ldr r1, [r5, r2]
	add r2, #8
	ldr r0, [r0]
	ldr r2, [r5, r2]
	bl StringExpandPlaceholders
	add r4, #0x10
	str r4, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E67DC ; =0x00010200
	mov r1, #0
	str r0, [sp, #8]
	add r0, r5, #0
	str r1, [sp, #0xc]
	add r2, r2, #1
	ldr r2, [r5, r2]
	add r0, #0xa8
	mov r3, #0x2d
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E67D8: .word 0x000F0E00
_021E67DC: .word 0x00010200
	thumb_func_end ov68_021E66F0


	thumb_func_start ov68_021E67E0
ov68_021E67E0: ; 0x021E67E0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, #0xa8
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r4, #0
_021E67EE:
	ldr r1, [r5]
	lsl r2, r4, #0x18
	ldrh r1, [r1, #0x16]
	add r0, r5, #0
	lsr r2, r2, #0x18
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov68_021E66F0
	add r4, r4, #1
	cmp r4, #4
	blo _021E67EE
	add r0, r5, #0
	add r0, #0xa8
	bl ScheduleWindowCopyToVram
	ldr r0, [r5, #4]
	mov r1, #7
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	bl ov68_021E70BC
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov68_021E67E0


	thumb_func_start ov68_021E6820
ov68_021E6820: ; 0x021E6820
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl ov68_021E6678
	mov r1, #0x6e
	lsl r1, r1, #2
	strb r0, [r5, r1]
	ldrb r0, [r5, r1]
	mov r1, #0x42
	bl ListMenuItems_New
	mov r1, #0x11
	lsl r1, r1, #4
	str r0, [r5, r1]
	ldr r2, _021E68B8 ; =0x000002EE
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x42
	bl NewMsgDataFromNarc
	add r7, r0, #0
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r0, [r5, r0]
	mov r4, #0
	cmp r0, #0
	bls _021E689A
	add r6, r4, #0
_021E6858:
	ldr r0, [r5]
	ldr r0, [r0, #0x10]
	ldrh r2, [r0, r6]
	ldr r0, _021E68BC ; =0x0000FFFF
	cmp r2, r0
	beq _021E6874
	mov r0, #0x11
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r7, #0
	add r3, r2, #0
	bl ListMenuItems_AppendFromMsgData
	b _021E688C
_021E6874:
	mov r0, #0x11
	add r1, r5, #0
	lsl r0, r0, #4
	add r1, #0xf8
	mov r2, #0x20
	add r3, r2, #0
	ldr r0, [r5, r0]
	ldr r1, [r1]
	sub r3, #0x22
	bl ListMenuItems_AppendFromMsgData
	b _021E689A
_021E688C:
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r0, [r5, r0]
	add r4, r4, #1
	add r6, r6, #2
	cmp r4, r0
	blo _021E6858
_021E689A:
	add r0, r7, #0
	bl DestroyMsgData
	ldr r0, _021E68C0 ; =0x000001BB
	mov r1, #0
	strb r1, [r5, r0]
	ldr r1, [r5]
	add r0, r0, #1
	ldrh r1, [r1, #0x14]
	strb r1, [r5, r0]
	add r0, r5, #0
	bl ov68_021E67E0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E68B8: .word 0x000002EE
_021E68BC: .word 0x0000FFFF
_021E68C0: .word 0x000001BB
	thumb_func_end ov68_021E6820
