	.include "asm/macros.inc"
	.public ov111_021E5E34
	.extern ov111_021E5DF0
	.extern ov111_021E5CB4
	.extern ov111_021E5CD4
	.extern ov111_021E5C94
	.extern ov111_021E5F50
	.extern ov111_021E6000
	.extern ov111_021E60D4
	.extern ov111_021E6180
	.extern ov111_021E67C4
	.extern ov111_021E67EC
	.extern ov111_021E66DC
	.include "overlay_111.inc"
	.include "global.inc"

	.text

	thumb_func_start ov111_021E5E34
ov111_021E5E34: ; 0x021E5E34
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r0, #0
	bl OverlayManager_GetArgs
	add r5, r0, #0
	bne _021E5E46
	bl GF_AssertFail
_021E5E46:
	mov r0, #3
	mov r1, #0x94
	lsl r2, r0, #0x10
	bl Heap_Create
	add r0, r4, #0
	mov r1, #0x34
	mov r2, #0x94
	bl OverlayManager_CreateAndGetData
	mov r1, #0
	mov r2, #0x34
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x94
	str r0, [r4]
	str r5, [r4, #4]
	ldr r0, [r5, #8]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl ov111_021E5C94
	str r0, [r4, #0x2c]
	bl ov111_021E5CD4
	ldr r2, _021E5EF8 ; =0x04000304
	ldr r0, _021E5EFC ; =0xFFFF7FFF
	ldrh r1, [r2]
	and r0, r1
	strh r0, [r2]
	bl ov111_021E5CB4
	add r0, r4, #0
	bl ov111_021E5F50
	add r0, r4, #0
	bl ov111_021E6000
	add r0, r4, #0
	bl ov111_021E60D4
	add r0, r4, #0
	bl ov111_021E6180
	ldr r0, [r4]
	bl YesNoPrompt_Create
	str r0, [r4, #0x18]
	ldr r0, [r4]
	bl ov111_021E67C4
	str r0, [r4, #0x24]
	ldr r1, [r4, #8]
	ldr r3, [r5, #0xc]
	mov r2, #1
	bl ov111_021E67EC
	ldr r0, [r4, #0x10]
	str r0, [sp]
	mov r0, #0x28
	ldrsb r0, [r4, r0]
	str r0, [sp, #4]
	ldr r0, [r4]
	ldr r1, [r4, #8]
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0xc]
	bl ov111_021E66DC
	str r0, [r4, #0x20]
	mov r0, #0
	bl ResetVisibleHardwareWindows
	mov r0, #1
	bl ResetVisibleHardwareWindows
	mov r0, #1
	bl TextFlags_SetCanABSpeedUpPrint
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r0, _021E5F00 ; =ov111_021E5DF0
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_021E5EF8: .word 0x04000304
_021E5EFC: .word 0xFFFF7FFF
_021E5F00: .word ov111_021E5DF0
	thumb_func_end ov111_021E5E34
