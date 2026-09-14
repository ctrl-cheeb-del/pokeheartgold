	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.extern ov87_021E6AE0
	.extern ov87_021E6AF4
	.extern ov87_021E6B28
	.extern ov87_021E7008
	.extern ov87_021E7048
	.extern ov87_021E708C
	.extern ov87_021E70D0
	.extern ov87_021E7134
	.extern ov87_021E717C
	.extern ov87_021E71B4
	.extern ov87_021E71EC
	.extern ov87_021E7324
	.extern ov87_021E7334
	.extern ov87_021E734C
	.extern ov87_021E73E0
	.extern ov87_021E7460
	.extern ov87_021E7490
	.extern ov87_021E74B8
	.extern ov87_021E74D4
	.extern ov87_021E74F4
	.extern ov87_021E7550
	.extern ov87_021E75E0
	.extern ov87_021E7698
	.extern ov87_021E7734
	.extern ov87_021E788C
	.extern ov87_021E78D8
	.extern ov87_021E7990
	.extern ov87_021E7998
	.extern ov87_021E79A0
	.extern ov87_021E7A2C
	.extern ov87_021E7FD4
	.extern ov87_021E7FE0
	.extern ov87_021E7FEC
	.extern ov87_021E8014
	.extern ov87_021E803C
	.extern ov87_021E8058
	.extern ov87_021E806C
	.extern ov87_021E8078
	.extern ov87_021E8084
	.extern ov87_021E80B4
	.extern ov87_021E8134
	.extern ov87_021E8184
	.extern ov87_021E818C
	.extern ov87_021E81A0
	.extern ov87_021E81A2
	.extern ov87_021E81C0
	.extern ov87_021E82E4
	.extern ov87_021E8308
	.public ov87_021E5B48
	.public ov87_021E5C38
	.public ov87_021E5CEC
	.public ov87_021E5E00
	.public ov87_021E6080
	.public ov87_021E64F8

	.text

thumb_func_start ov87_021E5B48
ov87_021E5B48: ; 0x021E5B48
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldrb r0, [r6, #8]
	cmp r0, #0
	beq _021E5B5C
	cmp r0, #1
	beq _021E5BCE
	cmp r0, #2
	beq _021E5C22
	b _021E5C2A
_021E5B5C:
	mov r0, #0xff
	mvn r0, r0
	ldr r4, _021E5C30 ; =ov87_021E81A0
	strh r0, [r6, #0x10]
	mov r7, #0
	add r5, r6, #0
_021E5B68:
	mov r1, #0x10
	mov r2, #0
	ldrsh r1, [r6, r1]
	ldrsh r2, [r4, r2]
	mov r0, #0xcb
	lsl r0, r0, #2
	add r1, r1, r2
	mov r2, #2
	ldrsh r2, [r4, r2]
	ldr r0, [r5, r0]
	bl ov87_021E7FEC
	mov r0, #0xcb
	lsl r0, r0, #2
	add r1, r7, #0
	ldr r0, [r5, r0]
	add r1, #0x14
	bl ov87_021E7FE0
	add r7, r7, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r7, #4
	blt _021E5B68
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl Options_GetFrame
	add r1, r0, #0
	mov r0, #0x53
	lsl r0, r0, #2
	add r0, r6, r0
	bl ov87_021E8134
	add r0, r6, #0
	bl ov87_021E7048
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #3
	strh r0, [r6, #0x12]
	mov r0, #0x56
	lsl r0, r0, #4
	bl PlaySE
	mov r0, #1
	strb r0, [r6, #8]
	b _021E5C2A
_021E5BCE:
	mov r1, #0x10
	ldrsh r0, [r6, r1]
	add r0, #0x20
	strh r0, [r6, #0x10]
	mov r0, #0x12
	ldrsh r0, [r6, r0]
	lsl r2, r0, #2
	mov r0, #0xcb
	add r3, r6, r2
	lsl r0, r0, #2
	ldr r0, [r3, r0]
	ldrsh r3, [r6, r1]
	ldr r1, _021E5C30 ; =ov87_021E81A0
	ldrsh r1, [r1, r2]
	add r1, r3, r1
	ldr r3, _021E5C34 ; =ov87_021E81A2
	ldrsh r2, [r3, r2]
	bl ov87_021E7FEC
	mov r0, #0x10
	ldrsh r0, [r6, r0]
	cmp r0, #0
	blt _021E5C2A
	mov r0, #0x12
	ldrsh r0, [r6, r0]
	cmp r0, #0
	bne _021E5C0A
	mov r0, #2
	strb r0, [r6, #8]
	b _021E5C2A
_021E5C0A:
	mov r0, #0x56
	lsl r0, r0, #4
	bl PlaySE
	mov r0, #0x12
	ldrsh r0, [r6, r0]
	sub r0, r0, #1
	strh r0, [r6, #0x12]
	mov r0, #0xff
	mvn r0, r0
	strh r0, [r6, #0x10]
	b _021E5C2A
_021E5C22:
	mov r0, #0
	strh r0, [r6, #0x10]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E5C2A:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E5C30: .word ov87_021E81A0
_021E5C34: .word ov87_021E81A2
	thumb_func_end ov87_021E5B48

	thumb_func_start ov87_021E5C38
ov87_021E5C38: ; 0x021E5C38
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r0, #0
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _021E5C4E
	cmp r0, #1
	beq _021E5C60
	cmp r0, #2
	beq _021E5CD8
	b _021E5CDE
_021E5C4E:
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x1e
	strb r0, [r5, #0xf]
	mov r0, #1
	strb r0, [r5, #8]
	b _021E5CDE
_021E5C60:
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _021E5C7C
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #0
	bl ov87_021E7FD4
	b _021E5C80
_021E5C7C:
	sub r0, r0, #1
	strb r0, [r5, #0xf]
_021E5C80:
	ldr r0, _021E5CE4 ; =ov87_021E81C0
	bl TouchscreenHitbox_FindRectAtTouchHeld
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _021E5CDE
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #0
	bl ov87_021E7FD4
	ldr r0, _021E5CE8 ; =0x000005E4
	bl PlaySE
	ldrb r0, [r5, #0xe]
	add r1, sp, #0
	add r0, r5, r0
	strb r4, [r0, #0x15]
	ldrb r0, [r5, #0xe]
	add r0, r0, #1
	strb r0, [r5, #0xe]
	add r0, sp, #4
	bl System_GetTouchHeldCoords
	mov r0, #0x53
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0
	bl ClearFrameAndWindow2
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #2
	strb r0, [r5, #8]
	b _021E5CDE
_021E5CD8:
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, pc}
_021E5CDE:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E5CE4: .word ov87_021E81C0
_021E5CE8: .word 0x000005E4
	thumb_func_end ov87_021E5C38

	thumb_func_start ov87_021E5CEC
ov87_021E5CEC: ; 0x021E5CEC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r0, #0
	ldrb r1, [r4, #0xe]
	sub r1, r1, #1
	add r1, r4, r1
	ldrb r7, [r1, #0x15]
	ldrb r1, [r4, #8]
	cmp r1, #3
	bhi _021E5DFA
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E5D0C: ; jump table
	.short _021E5D14 - _021E5D0C - 2 ; case 0
	.short _021E5D40 - _021E5D0C - 2 ; case 1
	.short _021E5D9E - _021E5D0C - 2 ; case 2
	.short _021E5DF0 - _021E5D0C - 2 ; case 3
_021E5D14:
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [r4, #0x1c]
	str r0, [r4, #0x20]
	str r0, [r4, #0x24]
	mov r1, #0
	mov r2, #0x3a
	strh r1, [r4, #0x10]
	lsl r2, r2, #4
	ldrb r3, [r4, r2]
	mov r0, #0xfe
	bic r3, r0
	lsl r0, r7, #2
	strb r3, [r4, r2]
	add r0, r4, r0
	sub r2, #0x74
	ldr r0, [r0, r2]
	bl ov87_021E7FE0
	mov r0, #1
	strb r0, [r4, #8]
	b _021E5DFA
_021E5D40:
	lsl r1, r7, #0x18
	lsr r1, r1, #0x18
	bl ov87_021E73E0
	mov r0, #1
	ldr r2, [r4, #0x1c]
	lsl r0, r0, #8
	add r2, r2, r0
	str r2, [r4, #0x1c]
	ldr r2, [r4, #0x20]
	add r1, r4, #0
	add r2, r2, r0
	str r2, [r4, #0x20]
	ldr r2, [r4, #0x24]
	add r1, #0x1c
	add r0, r2, r0
	str r0, [r4, #0x24]
	mov r0, #0x10
	ldrsh r0, [r4, r0]
	add r0, r0, #1
	strh r0, [r4, #0x10]
	lsl r0, r7, #2
	add r2, r4, r0
	mov r0, #0xcb
	lsl r0, r0, #2
	ldr r0, [r2, r0]
	bl ov87_021E806C
	mov r0, #6
	ldr r1, [r4, #0x1c]
	lsl r0, r0, #0xa
	cmp r1, r0
	bne _021E5DFA
	mov r0, #0
	strh r0, [r4, #0x10]
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [r4, #0x1c]
	str r0, [r4, #0x20]
	str r0, [r4, #0x24]
	mov r0, #0x56
	lsl r0, r0, #4
	bl PlaySE
	mov r0, #2
	strb r0, [r4, #8]
	b _021E5DFA
_021E5D9E:
	mov r0, #0x10
	ldrsh r0, [r4, r0]
	mov r6, #0
	add r5, r4, #0
	add r0, #0x10
	strh r0, [r4, #0x10]
_021E5DAA:
	mov r0, #0xcb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, sp, #4
	add r2, sp, #0
	bl ov87_021E8014
	mov r0, #0xcb
	lsl r0, r0, #2
	ldr r1, [sp, #4]
	ldr r0, [r5, r0]
	ldr r2, [sp]
	add r1, #0x10
	bl ov87_021E7FEC
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #4
	blt _021E5DAA
	mov r0, #0x10
	ldrsh r1, [r4, r0]
	add r0, #0xf0
	cmp r1, r0
	blt _021E5DFA
	lsl r0, r7, #2
	add r1, r4, r0
	mov r0, #0xcb
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0
	bl ov87_021E8058
	mov r0, #3
	strb r0, [r4, #8]
	b _021E5DFA
_021E5DF0:
	mov r0, #0
	strh r0, [r4, #0x10]
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E5DFA:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov87_021E5CEC

	thumb_func_start ov87_021E5E00
ov87_021E5E00: ; 0x021E5E00
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	ldrb r1, [r4, #8]
	cmp r1, #3
	bls _021E5E0C
	b _021E606C
_021E5E0C:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E5E18: ; jump table
	.short _021E5E20 - _021E5E18 - 2 ; case 0
	.short _021E5EDE - _021E5E18 - 2 ; case 1
	.short _021E5FCE - _021E5E18 - 2 ; case 2
	.short _021E6062 - _021E5E18 - 2 ; case 3
_021E5E20:
	bl ov87_021E7A2C
	mov r1, #0
	mov r3, #0xe3
	str r1, [sp]
	lsl r3, r3, #2
	ldr r2, [r4, r3]
	sub r3, r3, #4
	ldr r3, [r4, r3]
	ldr r0, [r4, #0x58]
	ldr r3, [r3, #0x10]
	bl BG_LoadCharTilesData
	ldr r0, [r4, #0x58]
	mov r1, #0
	bl BgCommitTilemapBufferToVram
	mov r0, #1
	lsl r0, r0, #8
	strh r0, [r4, #0x12]
	mov r3, #0x12
	ldrsh r3, [r4, r3]
	ldr r0, [r4, #0x58]
	mov r1, #6
	mov r2, #0
	bl BgSetPosTextAndCommit
	mov r3, #0x12
	mov r1, #0
	ldrsh r3, [r4, r3]
	ldr r0, [r4, #0x58]
	add r2, r1, #0
	bl BgSetPosTextAndCommit
	mov r3, #0x12
	ldrsh r3, [r4, r3]
	ldr r0, [r4, #0x58]
	mov r1, #1
	mov r2, #0
	bl BgSetPosTextAndCommit
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0xff
	mvn r0, r0
	strh r0, [r4, #0x10]
	ldrb r1, [r4, #0xe]
	mov r0, #0
	mov r2, #0x96
	add r1, r4, r1
	strb r0, [r1, #0x19]
	ldr r1, _021E6070 ; =0x000003FA
	add r5, r0, #0
	lsl r2, r2, #8
_021E5EA0:
	add r3, r4, r0
	add r0, r0, #1
	strb r5, [r3, r1]
	cmp r0, r2
	blt _021E5EA0
	ldr r0, _021E6074 ; =0x000003A1
	strb r5, [r4, r0]
	add r0, r4, #0
	bl ov87_021E7334
	ldrb r1, [r4, #0xe]
	add r0, r4, #0
	add r1, r4, r1
	ldrb r1, [r1, #0x19]
	bl ov87_021E7324
	ldrb r1, [r4, #0xe]
	add r0, r4, #0
	add r1, r4, r1
	ldrb r1, [r1, #0x19]
	bl ov87_021E734C
	add r0, r4, #0
	bl ov87_021E74B8
	add r0, r4, #0
	bl ov87_021E74D4
	mov r0, #1
	strb r0, [r4, #8]
	b _021E606C
_021E5EDE:
	mov r7, #0
	mov r6, #0x1a
	add r5, r4, #0
_021E5EE4:
	mov r1, #0x10
	mov r0, #0xbe
	ldrsh r1, [r4, r1]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, #0x3c
	add r2, r6, #0
	bl ov87_021E7FEC
	mov r0, #0xbe
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl ov87_021E7FD4
	add r7, r7, #1
	add r6, #0x2a
	add r5, r5, #4
	cmp r7, #4
	blt _021E5EE4
	mov r7, #0xd1
	mov r6, #0
	add r5, r4, #0
	lsl r7, r7, #2
_021E5F14:
	ldr r0, [r5, r7]
	mov r1, #1
	bl ov87_021E8078
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #3
	blt _021E5F14
	ldr r0, _021E6078 ; =0x0000039D
	mov r7, #0
	strb r7, [r4, r0]
	add r1, r0, #3
	ldrb r2, [r4, r1]
	mov r1, #1
	ldr r6, _021E607C ; =ov87_021E82E4
	bic r2, r1
	add r1, r0, #3
	strb r2, [r4, r1]
	mov r2, #0xb1
	add r1, r0, #5
	strb r2, [r4, r1]
	add r1, r0, #6
	mov r2, #0xb2
	strb r2, [r4, r1]
	mov r1, #0xb3
	add r0, r0, #7
	strb r1, [r4, r0]
	add r5, r4, #0
_021E5F4C:
	mov r1, #0x10
	mov r2, #0
	ldrsh r1, [r4, r1]
	ldrsh r2, [r6, r2]
	mov r0, #0xc2
	lsl r0, r0, #2
	add r1, r1, r2
	mov r2, #2
	ldrsh r2, [r6, r2]
	ldr r0, [r5, r0]
	bl ov87_021E7FEC
	mov r0, #0xc2
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl ov87_021E7FD4
	mov r1, #0x36
	mov r0, #0xc2
	lsl r0, r0, #2
	add r2, r4, r7
	lsl r1, r1, #4
	ldrb r1, [r2, r1]
	ldr r0, [r5, r0]
	bl ov87_021E803C
	add r7, r7, #1
	add r6, r6, #4
	add r5, r5, #4
	cmp r7, #9
	blt _021E5F4C
	mov r0, #0x18
	str r0, [sp]
	ldrb r2, [r4, #0xe]
	add r0, r4, #0
	mov r1, #1
	add r2, r4, r2
	ldrb r2, [r2, #0x15]
	mov r3, #0x20
	add r2, r2, #4
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	bl ov87_021E7460
	mov r0, #0x18
	str r0, [sp]
	ldrb r2, [r4, #0xe]
	add r0, r4, #0
	mov r1, #6
	add r2, r4, r2
	ldrb r2, [r2, #0x15]
	mov r3, #0x20
	add r2, r2, #1
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	bl ov87_021E7460
	mov r0, #0x56
	lsl r0, r0, #4
	bl PlaySE
	mov r0, #2
	strb r0, [r4, #8]
	b _021E606C
_021E5FCE:
	mov r3, #0x12
	ldrsh r3, [r4, r3]
	ldr r0, [r4, #0x58]
	mov r1, #6
	mov r2, #0
	bl BgSetPosTextAndCommit
	mov r3, #0x12
	mov r1, #0
	ldrsh r3, [r4, r3]
	ldr r0, [r4, #0x58]
	add r2, r1, #0
	bl BgSetPosTextAndCommit
	mov r3, #0x12
	ldrsh r3, [r4, r3]
	ldr r0, [r4, #0x58]
	mov r1, #1
	mov r2, #0
	bl BgSetPosTextAndCommit
	mov r0, #0x12
	ldrsh r0, [r4, r0]
	sub r0, #0x10
	strh r0, [r4, #0x12]
	mov r0, #0x10
	ldrsh r0, [r4, r0]
	cmp r0, #0
	blt _021E600E
	mov r0, #3
	strb r0, [r4, #8]
	b _021E6058
_021E600E:
	mov r7, #0
	mov r6, #0x1a
	add r5, r4, #0
_021E6014:
	mov r1, #0x10
	mov r0, #0xbe
	ldrsh r1, [r4, r1]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, #0x3c
	add r2, r6, #0
	bl ov87_021E7FEC
	add r7, r7, #1
	add r6, #0x2a
	add r5, r5, #4
	cmp r7, #4
	blt _021E6014
	ldr r5, _021E607C ; =ov87_021E82E4
	mov r7, #0
	add r6, r4, #0
_021E6036:
	mov r1, #0x10
	mov r2, #0
	ldrsh r1, [r4, r1]
	ldrsh r2, [r5, r2]
	mov r0, #0xc2
	lsl r0, r0, #2
	add r1, r1, r2
	mov r2, #2
	ldrsh r2, [r5, r2]
	ldr r0, [r6, r0]
	bl ov87_021E7FEC
	add r7, r7, #1
	add r5, r5, #4
	add r6, r6, #4
	cmp r7, #9
	blt _021E6036
_021E6058:
	mov r0, #0x10
	ldrsh r0, [r4, r0]
	add r0, #0x10
	strh r0, [r4, #0x10]
	b _021E606C
_021E6062:
	mov r0, #0
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E606C:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6070: .word 0x000003FA
_021E6074: .word 0x000003A1
_021E6078: .word 0x0000039D
_021E607C: .word ov87_021E82E4
	thumb_func_end ov87_021E5E00

	thumb_func_start ov87_021E6080
ov87_021E6080: ; 0x021E6080
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	ldrb r1, [r4, #8]
	cmp r1, #0xb
	bls _021E608C
	b _021E64F4
_021E608C:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E6098: ; jump table
	.short _021E60B0 - _021E6098 - 2 ; case 0
	.short _021E613E - _021E6098 - 2 ; case 1
	.short _021E6154 - _021E6098 - 2 ; case 2
	.short _021E6184 - _021E6098 - 2 ; case 3
	.short _021E633A - _021E6098 - 2 ; case 4
	.short _021E6356 - _021E6098 - 2 ; case 5
	.short _021E636A - _021E6098 - 2 ; case 6
	.short _021E63BA - _021E6098 - 2 ; case 7
	.short _021E63E4 - _021E6098 - 2 ; case 8
	.short _021E6414 - _021E6098 - 2 ; case 9
	.short _021E647E - _021E6098 - 2 ; case 10
	.short _021E64E8 - _021E6098 - 2 ; case 11
_021E60B0:
	ldrb r0, [r4, #0xe]
	cmp r0, #2
	bne _021E60E2
	mov r0, #0x4b
	lsl r0, r0, #2
	add r0, r4, r0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	bl ov87_021E71B4
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x58
	mov r2, #0xa0
	bl ov87_021E7FEC
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov87_021E803C
	b _021E60F2
_021E60E2:
	mov r0, #0x4f
	lsl r0, r0, #2
	add r0, r4, r0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	bl ov87_021E717C
_021E60F2:
	mov r0, #0x1e
	strb r0, [r4, #0xf]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov87_021E7FD4
	add r0, r4, #0
	bl ov87_021E708C
	mov r5, #0
_021E610A:
	lsl r1, r5, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov87_021E71EC
	add r5, r5, #1
	cmp r5, #4
	blt _021E610A
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov87_021E7FD4
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov87_021E8084
	ldr r0, _021E63F4 ; =0x00000562
	bl PlaySE
	mov r0, #1
	strb r0, [r4, #8]
	b _021E64F4
_021E613E:
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #2
	strb r0, [r4, #8]
	b _021E64F4
_021E6154:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _021E617E
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov87_021E7FD4
	add r0, r4, #0
	add r0, #0xfc
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0xfc
	bl ScheduleWindowCopyToVram
	mov r0, #3
	strb r0, [r4, #8]
	b _021E64F4
_021E617E:
	sub r0, r0, #1
	strb r0, [r4, #0xf]
	b _021E64F4
_021E6184:
	mov r0, #0xee
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #4
	mov r2, #2
	bl sub_02021280
	ldr r0, _021E63F8 ; =ov87_021E8308
	bl TouchscreenHitbox_FindRectAtTouchHeld
	add r5, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r5, r0
	beq _021E6290
	add r0, r4, #0
	bl ov87_021E7490
	cmp r0, #3
	bhs _021E61B6
	mov r0, #0xe5
	mov r2, #1
	add r1, r4, r5
	lsl r0, r0, #2
	strb r2, [r1, r0]
_021E61B6:
	mov r0, #0xe5
	add r1, r4, r5
	lsl r0, r0, #2
	ldrb r0, [r1, r0]
	cmp r0, #1
	bne _021E61EA
	add r0, r4, #0
	bl ov87_021E7550
	lsl r1, r5, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov87_021E75E0
	add r0, r4, #0
	add r1, r5, #0
	bl ov87_021E74F4
	ldr r0, _021E63FC ; =0x0000055F
	bl IsSEPlaying
	cmp r0, #0
	bne _021E61EA
	ldr r0, _021E63FC ; =0x0000055F
	bl PlaySE
_021E61EA:
	add r0, r4, #0
	bl ov87_021E7734
	cmp r0, #1
	bne _021E6262
	ldr r0, _021E63FC ; =0x0000055F
	mov r1, #0
	bl StopSE
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov87_021E7FD4
	ldr r1, _021E6400 ; =0x0000039F
	ldrb r0, [r4, r1]
	lsl r0, r0, #1
	add r2, r4, r0
	add r0, r1, #0
	sub r0, #0x35
	ldrh r3, [r2, r0]
	add r0, r1, #0
	sub r0, #0x27
	ldr r2, [r4, r0]
	ldrb r0, [r4, #0xe]
	lsl r0, r0, #1
	strh r3, [r2, r0]
	ldrb r0, [r4, r1]
	lsl r0, r0, #1
	add r2, r4, r0
	add r0, r1, #0
	sub r0, #0x35
	ldrh r0, [r2, r0]
	cmp r0, #0x5c
	bne _021E6236
	mov r2, #1
	b _021E6238
_021E6236:
	mov r2, #3
_021E6238:
	ldrb r0, [r4, #0xe]
	sub r1, #0x23
	ldr r1, [r4, r1]
	lsl r0, r0, #1
	strh r2, [r1, r0]
	add r0, r4, #0
	bl ov87_021E788C
	cmp r0, #1
	bne _021E6250
	mov r0, #0x1e
	b _021E6252
_021E6250:
	mov r0, #0
_021E6252:
	strb r0, [r4, #0xf]
	add r0, r4, #0
	bl ov87_021E70D0
	mov r0, #4
	strb r0, [r4, #8]
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E6262:
	ldr r0, _021E6404 ; =0x000003A1
	ldrb r0, [r4, r0]
	cmp r0, #3
	blo _021E6298
	ldr r0, _021E63FC ; =0x0000055F
	mov r1, #0
	bl StopSE
	mov r0, #0x3c
	strb r0, [r4, #0xf]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov87_021E7FD4
	add r0, r4, #0
	bl ov87_021E7134
	mov r0, #7
	strb r0, [r4, #8]
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E6290:
	ldr r0, _021E63FC ; =0x0000055F
	mov r1, #0
	bl StopSE
_021E6298:
	mov r0, #0x3a
	lsl r0, r0, #4
	ldrb r0, [r4, r0]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _021E62AC
	add r0, r4, #0
	bl ov87_021E7698
_021E62AC:
	ldrb r0, [r4, #0xe]
	cmp r0, #2
	bne _021E62F6
	ldr r0, _021E6408 ; =ov87_021E8184
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _021E6378
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov87_021E8084
	add r0, r4, #0
	bl ov87_021E7008
	ldr r0, _021E640C ; =0x000005E4
	bl PlaySE
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov87_021E803C
	add r0, r4, #0
	bl ov87_021E6AE0
	add r0, r4, #0
	bl ov87_021E6AF4
	mov r0, #0xa
	strb r0, [r4, #8]
	b _021E64F4
_021E62F6:
	ldr r0, _021E6410 ; =ov87_021E818C
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _021E6378
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov87_021E8084
	add r0, r4, #0
	bl ov87_021E7008
	ldr r0, _021E640C ; =0x000005E4
	bl PlaySE
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov87_021E803C
	add r0, r4, #0
	bl ov87_021E6AE0
	add r0, r4, #0
	bl ov87_021E6AF4
	mov r0, #9
	strb r0, [r4, #8]
	b _021E64F4
_021E633A:
	ldrb r1, [r4, #0xf]
	cmp r1, #0
	bne _021E6350
	mov r1, #0
	bl ov87_021E78D8
	cmp r0, #0
	bne _021E6378
	mov r0, #5
	strb r0, [r4, #8]
	b _021E64F4
_021E6350:
	sub r0, r1, #1
	strb r0, [r4, #0xf]
	b _021E64F4
_021E6356:
	mov r1, #1
	bl ov87_021E78D8
	cmp r0, #0
	bne _021E6378
	mov r0, #0
	strb r0, [r4, #0xf]
	mov r0, #6
	strb r0, [r4, #8]
	b _021E64F4
_021E636A:
	mov r0, #0xd7
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov87_021E80B4
	cmp r0, #1
	bne _021E637A
_021E6378:
	b _021E64F4
_021E637A:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _021E63B4
	mov r7, #0x35
	mov r6, #0
	add r5, r4, #0
	lsl r7, r7, #4
_021E6388:
	ldr r0, [r5, r7]
	mov r1, #0
	bl ov87_021E7FD4
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #3
	blt _021E6388
	mov r0, #0xd7
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov87_021E7FD4
	add r0, r4, #0
	bl ov87_021E7998
	add r0, r4, #0
	bl ov87_021E79A0
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E63B4:
	sub r0, r0, #1
	strb r0, [r4, #0xf]
	b _021E64F4
_021E63BA:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _021E63DE
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add r0, r4, #0
	bl ov87_021E7998
	add r0, r4, #0
	bl ov87_021E79A0
	mov r0, #0x1e
	strb r0, [r4, #0xf]
	mov r0, #8
	strb r0, [r4, #8]
	b _021E64F4
_021E63DE:
	sub r0, r0, #1
	strb r0, [r4, #0xf]
	b _021E64F4
_021E63E4:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _021E63EE
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E63EE:
	sub r0, r0, #1
	strb r0, [r4, #0xf]
	b _021E64F4
	.balign 4, 0
_021E63F4: .word 0x00000562
_021E63F8: .word ov87_021E8308
_021E63FC: .word 0x0000055F
_021E6400: .word 0x0000039F
_021E6404: .word 0x000003A1
_021E6408: .word ov87_021E8184
_021E640C: .word 0x000005E4
_021E6410: .word ov87_021E818C
_021E6414:
	mov r0, #0x39
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl YesNoPrompt_HandleInputForSave
	cmp r0, #1
	bne _021E6450
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov87_021E8084
	add r0, r4, #0
	add r0, #0x5c
	mov r1, #0
	bl sub_0200E5D4
	add r0, r4, #0
	add r0, #0x5c
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	bl ov87_021E7998
	add r0, r4, #0
	bl ov87_021E6B28
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E6450:
	cmp r0, #2
	bne _021E64F4
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov87_021E8084
	add r0, r4, #0
	add r0, #0x5c
	mov r1, #0
	bl sub_0200E5D4
	add r0, r4, #0
	add r0, #0x5c
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	bl ov87_021E6B28
	mov r0, #0xb
	strb r0, [r4, #8]
	b _021E64F4
_021E647E:
	mov r0, #0x39
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl YesNoPrompt_HandleInputForSave
	cmp r0, #1
	bne _021E64BA
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov87_021E8084
	add r0, r4, #0
	add r0, #0x5c
	mov r1, #0
	bl sub_0200E5D4
	add r0, r4, #0
	add r0, #0x5c
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	bl ov87_021E7990
	add r0, r4, #0
	bl ov87_021E6B28
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E64BA:
	cmp r0, #2
	bne _021E64F4
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov87_021E8084
	add r0, r4, #0
	add r0, #0x5c
	mov r1, #0
	bl sub_0200E5D4
	add r0, r4, #0
	add r0, #0x5c
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	bl ov87_021E6B28
	mov r0, #0xb
	strb r0, [r4, #8]
	b _021E64F4
_021E64E8:
	bl System_GetTouchHeld
	cmp r0, #0
	bne _021E64F4
	mov r0, #3
	strb r0, [r4, #8]
_021E64F4:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov87_021E6080

	thumb_func_start ov87_021E64F8
ov87_021E64F8: ; 0x021E64F8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _021E650C
	cmp r0, #1
	beq _021E653C
	cmp r0, #2
	beq _021E65EA
	b _021E65F4
_021E650C:
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl ov87_021E7FD4
	mov r0, #0
	strh r0, [r5, #0x10]
	strh r0, [r5, #0x12]
	mov r0, #0x56
	lsl r0, r0, #4
	bl PlaySE
	mov r0, #1
	strb r0, [r5, #8]
	b _021E65F4
_021E653C:
	mov r3, #0x12
	ldrsh r3, [r5, r3]
	ldr r0, [r5, #0x58]
	mov r1, #6
	mov r2, #0
	bl BgSetPosTextAndCommit
	mov r3, #0x12
	mov r1, #0
	ldrsh r3, [r5, r3]
	ldr r0, [r5, #0x58]
	add r2, r1, #0
	bl BgSetPosTextAndCommit
	mov r3, #0x12
	ldrsh r3, [r5, r3]
	ldr r0, [r5, #0x58]
	mov r1, #1
	mov r2, #0
	bl BgSetPosTextAndCommit
	mov r0, #0x12
	ldrsh r0, [r5, r0]
	sub r0, #0x10
	strh r0, [r5, #0x12]
	mov r0, #0x10
	ldrsh r1, [r5, r0]
	add r0, #0xf0
	cmp r1, r0
	blt _021E657E
	mov r0, #2
	strb r0, [r5, #8]
	b _021E65E0
_021E657E:
	mov r7, #0
	mov r6, #0x1a
	add r4, r5, #0
_021E6584:
	mov r1, #0x10
	mov r0, #0xbe
	ldrsh r1, [r5, r1]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, #0x3c
	add r2, r6, #0
	bl ov87_021E7FEC
	add r7, r7, #1
	add r6, #0x2a
	add r4, r4, #4
	cmp r7, #4
	blt _021E6584
	mov r7, #0xd1
	mov r6, #0
	add r4, r5, #0
	lsl r7, r7, #2
_021E65A8:
	ldr r0, [r4, r7]
	mov r1, #0
	bl ov87_021E7FD4
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #3
	blt _021E65A8
	ldr r4, _021E65F8 ; =ov87_021E82E4
	mov r7, #0
	add r6, r5, #0
_021E65BE:
	mov r1, #0x10
	mov r2, #0
	ldrsh r1, [r5, r1]
	ldrsh r2, [r4, r2]
	mov r0, #0xc2
	lsl r0, r0, #2
	add r1, r1, r2
	mov r2, #2
	ldrsh r2, [r4, r2]
	ldr r0, [r6, r0]
	bl ov87_021E7FEC
	add r7, r7, #1
	add r4, r4, #4
	add r6, r6, #4
	cmp r7, #9
	blt _021E65BE
_021E65E0:
	mov r0, #0x10
	ldrsh r0, [r5, r0]
	add r0, #0x10
	strh r0, [r5, #0x10]
	b _021E65F4
_021E65EA:
	mov r0, #0
	strh r0, [r5, #0x10]
	strh r0, [r5, #0x12]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E65F4:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E65F8: .word ov87_021E82E4
	thumb_func_end ov87_021E64F8
