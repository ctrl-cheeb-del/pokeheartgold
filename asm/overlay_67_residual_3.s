	.include "asm/macros.inc"
	.include "overlay_67.inc"
	.include "global.inc"

	.public ov67_021E6D50
	.public ov67_021E6D5C
	.public ov67_021E6D6C
	.public ov67_021E6D7C
	.public ov67_021E6D90
	.public ov67_021E6DA8
	.public ov67_021E6DC4
	.public ov67_021E6DE0
	.public ov67_021E6DFC
	.public ov67_021E6E18
	.public ov67_021E6E38
	.public ov67_021E6E60
	.public ov67_021E6E98
	.public ov67_021E6EE8
	.public ov67_021E6F50
	.public ov67_021E7020

	.public _021E6D4C

	.text
	.public ov67_021E5900
	.public ov67_021E5968
	.public ov67_021E5984
	.public ov67_021E5A6C
	.public ov67_021E5B44
	.public ov67_021E5BC0
	.public ov67_021E5BE0
	.public ov67_021E5C04
	.public ov67_021E5C44
	.public ov67_021E5DA0
	.public ov67_021E5E84
	.public ov67_021E5EB0
	.public ov67_021E6008
	.public ov67_021E6080
	.public ov67_021E60B4
	.public ov67_021E60F4
	.public ov67_021E6118
	.public ov67_021E6164
	.public ov67_021E61A0
	.public ov67_021E61E8
	.public ov67_021E6220
	.public ov67_021E63E8
	.public ov67_021E6474
	.public ov67_021E6490
	.public ov67_021E6530
	.public ov67_021E65C0
	.public ov67_021E6688
	.public ov67_021E681C
	.public ov67_021E6820
	.public ov67_021E6990
	.public ov67_021E69D8
	.public ov67_021E6A00
	.public ov67_021E6A08
	.public ov67_021E6A28
	.public ov67_021E6A40
	.public ov67_021E6B6C
	.public ov67_021E6BB8
	.public ov67_021E6BC4
	.public ov67_021E6C04
	.public ov67_021E6C14
	.public ov67_021E6C5C
	.public ov67_021E6C60
	.public ov67_021E6D20
	thumb_func_start ov67_021E5C44
ov67_021E5C44: ; 0x021E5C44
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _021E5D88 ; =0x000004A4
	ldr r0, [r4, r0]
	bl GridInputHandler_HandleInput_NoHold
	cmp r0, #0xc
	bhi _021E5C58
	beq _021E5C72
	b _021E5CBE
_021E5C58:
	add r0, r0, #4
	cmp r0, #3
	bhi _021E5CBE
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E5C6A: ; jump table
	.short _021E5CCC - _021E5C6A - 2 ; case 0
	.short _021E5C88 - _021E5C6A - 2 ; case 1
	.short _021E5C72 - _021E5C6A - 2 ; case 2
	.short _021E5CCC - _021E5C6A - 2 ; case 3
_021E5C72:
	ldr r0, _021E5D8C ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	bl ov67_021E6BB8
	ldr r0, _021E5D90 ; =0x0000049C
	mov r1, #6
	str r1, [r4, r0]
	mov r0, #5
	pop {r4, pc}
_021E5C88:
	ldr r0, _021E5D94 ; =0x000005DC
	bl PlaySE
	ldr r0, _021E5D98 ; =0x000004A8
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _021E5CA8
	add r0, r4, #0
	mov r1, #2
	bl ov67_021E6B6C
	ldr r0, _021E5D90 ; =0x0000049C
	mov r1, #4
	str r1, [r4, r0]
	mov r0, #5
	pop {r4, pc}
_021E5CA8:
	cmp r0, #2
	bne _021E5CCC
	add r0, r4, #0
	mov r1, #3
	bl ov67_021E6B6C
	ldr r0, _021E5D90 ; =0x0000049C
	mov r1, #4
	str r1, [r4, r0]
	mov r0, #5
	pop {r4, pc}
_021E5CBE:
	bl System_GetTouchNew
	cmp r0, #1
	bne _021E5CCC
	ldr r0, _021E5D94 ; =0x000005DC
	bl PlaySE
_021E5CCC:
	ldr r0, _021E5D9C ; =ov67_021E6D50
	bl TouchscreenHitbox_FindRectAtTouchNew
	cmp r0, #0
	beq _021E5CDC
	cmp r0, #1
	beq _021E5D30
	b _021E5D84
_021E5CDC:
	mov r0, #0x4a
	lsl r0, r0, #4
	ldrh r1, [r4, r0]
	cmp r1, #0
	beq _021E5CEA
	sub r1, r1, #1
	b _021E5CEC
_021E5CEA:
	mov r1, #2
_021E5CEC:
	strh r1, [r4, r0]
	mov r0, #0x5e
	lsl r0, r0, #4
	bl PlaySE
	add r0, r4, #0
	bl ov67_021E6490
	ldr r0, _021E5D88 ; =0x000004A4
	ldr r0, [r4, r0]
	bl GridInputHandler_GetNextInput
	mov r1, #0x4a
	lsl r1, r1, #4
	ldrh r2, [r4, r1]
	mov r1, #0xc
	add r3, r0, #0
	mul r1, r2
	add r0, r4, #0
	add r1, r1, r3
	bl ov67_021E6688
	add r0, r4, #0
	bl ov67_021E6530
	add r0, r4, #0
	mov r1, #2
	bl ov67_021E6B6C
	ldr r0, _021E5D90 ; =0x0000049C
	mov r1, #4
	str r1, [r4, r0]
	mov r0, #5
	pop {r4, pc}
_021E5D30:
	mov r0, #0x4a
	lsl r0, r0, #4
	ldrh r1, [r4, r0]
	cmp r1, #2
	bhs _021E5D3E
	add r1, r1, #1
	b _021E5D40
_021E5D3E:
	mov r1, #0
_021E5D40:
	strh r1, [r4, r0]
	mov r0, #0x5e
	lsl r0, r0, #4
	bl PlaySE
	add r0, r4, #0
	bl ov67_021E6490
	ldr r0, _021E5D88 ; =0x000004A4
	ldr r0, [r4, r0]
	bl GridInputHandler_GetNextInput
	mov r1, #0x4a
	lsl r1, r1, #4
	ldrh r2, [r4, r1]
	mov r1, #0xc
	add r3, r0, #0
	mul r1, r2
	add r0, r4, #0
	add r1, r1, r3
	bl ov67_021E6688
	add r0, r4, #0
	bl ov67_021E6530
	add r0, r4, #0
	mov r1, #3
	bl ov67_021E6B6C
	ldr r0, _021E5D90 ; =0x0000049C
	mov r1, #4
	str r1, [r4, r0]
	mov r0, #5
	pop {r4, pc}
_021E5D84:
	mov r0, #4
	pop {r4, pc}
	.balign 4, 0
_021E5D88: .word 0x000004A4
_021E5D8C: .word 0x000005DD
_021E5D90: .word 0x0000049C
_021E5D94: .word 0x000005DC
_021E5D98: .word 0x000004A8
_021E5D9C: .word ov67_021E6D50
	thumb_func_end ov67_021E5C44


	thumb_func_start ov67_021E5DA0
ov67_021E5DA0: ; 0x021E5DA0
	push {r3, r4, r5, lr}
	sub sp, #0x80
	add r4, r0, #0
	ldr r0, [r4]
	bl BgConfig_Alloc
	add r3, sp, #0x70
	ldr r5, _021E5E70 ; =ov67_021E6D5C
	str r0, [r4, #0x10]
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _021E5E74 ; =ov67_021E6DA8
	add r3, sp, #0x54
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #0
	str r0, [r3]
	ldr r0, [r4, #0x10]
	add r3, r1, #0
	bl InitBgFromTemplate
	mov r0, #0
	ldr r3, [r4]
	mov r1, #0x20
	add r2, r0, #0
	bl BG_ClearCharDataRange
	ldr r0, [r4, #0x10]
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E5E78 ; =ov67_021E6DFC
	add r3, sp, #0x38
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #1
	str r0, [r3]
	ldr r0, [r4, #0x10]
	mov r3, #0
	bl InitBgFromTemplate
	ldr r5, _021E5E7C ; =ov67_021E6DC4
	add r3, sp, #0x1c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #4
	str r0, [r3]
	ldr r0, [r4, #0x10]
	mov r3, #0
	bl InitBgFromTemplate
	ldr r3, [r4]
	mov r0, #4
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	ldr r0, [r4, #0x10]
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E5E80 ; =ov67_021E6DE0
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #5
	str r0, [r3]
	ldr r0, [r4, #0x10]
	mov r3, #0
	bl InitBgFromTemplate
	add sp, #0x80
	pop {r3, r4, r5, pc}
	nop
_021E5E70: .word ov67_021E6D5C
_021E5E74: .word ov67_021E6DA8
_021E5E78: .word ov67_021E6DFC
_021E5E7C: .word ov67_021E6DC4
_021E5E80: .word ov67_021E6DE0
	thumb_func_end ov67_021E5DA0

