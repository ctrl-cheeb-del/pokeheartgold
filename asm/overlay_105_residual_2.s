	.include "asm/macros.inc"
	.include "overlay_105.inc"
	.include "global.inc"

	.text
	.public ov105_021E5900
	.public ov105_021E5B14
	.public ov105_021E5B68
	.public ov105_021E5C84
	.public ov105_021E5BCC
	.public ov105_021E5CA4
	.public ov105_021E5DD4
	.public ov105_021E5E08
	.public ov105_021E59DC

	thumb_func_start ov105_021E5B14
ov105_021E5B14: ; 0x021E5B14
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r0, [sp]
	bl OverlayManager_GetData
	add r7, r0, #0
	str r0, [sp, #4]
	add r6, r0, #4
	mov r4, #0
	add r7, #0x80
_021E5B28:
	lsl r0, r4, #2
	add r5, r6, r0
	ldr r1, [r5, #0x6c]
	add r0, r7, #0
	bl NNS_G3dFreeAnmObj
	ldr r0, [r5, #0x5c]
	bl Heap_Free
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _021E5B28
	ldr r0, [r6, #0x58]
	bl Heap_Free
	ldr r0, [sp, #4]
	ldr r0, [r0]
	bl Camera_Delete
	ldr r0, [sp]
	bl OverlayManager_FreeData
	bl GF3dRender_DeleteSimpleManager
	mov r0, #0x97
	bl Heap_Destroy
	mov r0, #1
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov105_021E5B14


	thumb_func_start ov105_021E5B68
ov105_021E5B68: ; 0x021E5B68
	push {r3, lr}
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _021E5BB8 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021E5BBC ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	bl ov105_021E5C84
	mov r0, #0x97
	bl GF3dRender_InitSimpleManager
	ldr r2, _021E5BC0 ; =0x04000060
	ldr r0, _021E5BC4 ; =0xFFFFCFFF
	ldrh r1, [r2]
	and r1, r0
	mov r0, #0x20
	orr r0, r1
	strh r0, [r2]
	ldr r0, _021E5BC8 ; =ov105_021E5DE0
	bl G3X_SetEdgeColorTable
	bl GfGfx_SwapDisplay
	pop {r3, pc}
	nop
_021E5BB8: .word 0xFFFFE0FF
_021E5BBC: .word 0x04001000
_021E5BC0: .word 0x04000060
_021E5BC4: .word 0xFFFFCFFF
_021E5BC8: .word ov105_021E5DE0
	thumb_func_end ov105_021E5B68


	thumb_func_start ov105_021E5BCC
ov105_021E5BCC: ; 0x021E5BCC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r0, #0
	add r5, sp, #0xc
	mov r0, #0
	str r0, [r5]
	str r0, [r5, #4]
	str r0, [r5, #8]
	add r2, r4, #0
	add r2, #0x90
	ldmia r5!, {r0, r1}
	add r3, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r5]
	mov r1, #0x14
	str r0, [r2]
	add r0, r4, #0
	add r0, #0x9f
	ldrb r7, [r0]
	add r0, r4, #0
	add r0, #0x9c
	ldrb r0, [r0]
	add r6, r7, #0
	mul r6, r1
	add r5, r0, #0
	ldr r0, _021E5C6C ; =ov105_021E5E2C
	mul r5, r1
	add r1, r0, r5
	ldr r0, _021E5C70 ; =ov105_021E5E38
	add r2, r1, r6
	add r0, r0, r5
	ldrb r0, [r6, r0]
	add r2, r2, #4
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	str r0, [sp, #8]
	add r0, r3, #0
	ldr r3, _021E5C74 ; =ov105_021E5E3A
	ldr r1, [r1, r6]
	add r3, r3, r5
	ldrh r3, [r6, r3]
	bl Camera_Init_FromTargetDistanceAndAngle
	add r0, r4, #0
	add r0, #0x9c
	ldrb r1, [r0]
	ldr r3, _021E5C78 ; =ov105_021E5DF0
	mov r0, #0xc
	add r2, r1, #0
	mul r2, r0
	add r1, r3, r2
	mul r0, r7
	add r0, r1, r0
	ldr r1, [r4]
	bl Camera_OffsetLookAtPosAndTarget
	add r0, r4, #0
	add r0, #0x9c
	ldrb r0, [r0]
	ldr r3, _021E5C7C ; =ov105_021E5DCE
	lsl r2, r7, #2
	lsl r1, r0, #2
	ldr r0, _021E5C80 ; =ov105_021E5DCC
	add r0, r0, r1
	add r1, r3, r1
	ldrh r0, [r2, r0]
	ldrh r1, [r2, r1]
	ldr r2, [r4]
	lsl r0, r0, #0xc
	lsl r1, r1, #0xc
	bl Camera_SetPerspectiveClippingPlane
	ldr r0, [r4]
	bl Camera_SetStaticPtr
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E5C6C: .word ov105_021E5E2C
_021E5C70: .word ov105_021E5E38
_021E5C74: .word ov105_021E5E3A
_021E5C78: .word ov105_021E5DF0
_021E5C7C: .word ov105_021E5DCE
_021E5C80: .word ov105_021E5DCC
	thumb_func_end ov105_021E5BCC


	thumb_func_start ov105_021E5C84
ov105_021E5C84: ; 0x021E5C84
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _021E5CA0 ; =ov105_021E5E54
	add r3, sp, #0
	mov r2, #5
_021E5C8E:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E5C8E
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_021E5CA0: .word ov105_021E5E54
	thumb_func_end ov105_021E5C84


	thumb_func_start ov105_021E5CA4
ov105_021E5CA4: ; 0x021E5CA4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r0, #0
	mov r0, #0xf0
	mov r1, #0x97
	bl NARC_New
	str r0, [sp, #4]
	add r0, r7, #0
	add r0, #0x80
	mov r1, #0x97
	mov r2, #4
	bl HeapExp_FndInitAllocator
	add r0, r7, #0
	add r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #0
	bne _021E5CE8
	add r0, r7, #0
	add r0, #0x9d
	ldrb r0, [r0]
	cmp r0, #0
	bne _021E5CDA
	ldr r0, _021E5DAC ; =ov105_021E5E8C
	str r0, [sp]
	b _021E5CDE
_021E5CDA:
	ldr r0, _021E5DB0 ; =_021E5E80
	str r0, [sp]
_021E5CDE:
	add r0, r7, #0
	ldr r1, _021E5DB4 ; =ov105_021E5DC8
	add r0, #0xa4
	str r1, [r0]
	b _021E5D04
_021E5CE8:
	add r0, r7, #0
	add r0, #0x9d
	ldrb r0, [r0]
	cmp r0, #0
	bne _021E5CF8
	ldr r0, _021E5DB8 ; =ov105_021E5EA4
	str r0, [sp]
	b _021E5CFC
_021E5CF8:
	ldr r0, _021E5DBC ; =ov105_021E5E98
	str r0, [sp]
_021E5CFC:
	add r0, r7, #0
	ldr r1, _021E5DC0 ; =_021E5DC4
	add r0, #0xa4
	str r1, [r0]
_021E5D04:
	ldr r1, [sp]
	ldr r0, [sp, #4]
	ldr r1, [r1]
	add r5, r7, #4
	mov r2, #0x97
	bl NARC_AllocAndReadWholeMember
	add r1, r5, #0
	add r2, r5, #0
	str r0, [r5, #0x58]
	add r0, r5, #0
	add r1, #0x54
	add r2, #0x58
	bl GF3dRender_InitObjFromHeader
	ldr r0, [r7, #0x5c]
	bl NNS_G3dGetTex
	str r0, [sp, #8]
	ldr r0, [r5, #0x54]
	mov r1, #0
	mov r2, #0x40
	bl NNSi_G3dModifyMatFlag
	ldr r0, [r5, #0x54]
	mov r1, #0
	mov r2, #0x80
	bl NNSi_G3dModifyMatFlag
	mov r2, #2
	ldr r0, [r5, #0x54]
	mov r1, #0
	lsl r2, r2, #8
	bl NNSi_G3dModifyMatFlag
	mov r2, #1
	ldr r0, [r5, #0x54]
	mov r1, #0
	lsl r2, r2, #0xa
	bl NNSi_G3dModifyMatFlag
	mov r4, #0
	add r7, #0x80
_021E5D5A:
	ldr r1, [sp]
	lsl r2, r4, #1
	add r1, r1, r2
	lsl r0, r4, #2
	add r6, r5, r0
	ldrh r1, [r1, #4]
	ldr r0, [sp, #4]
	mov r2, #0x97
	bl NARC_AllocAndReadWholeMember
	mov r1, #0
	str r0, [r6, #0x5c]
	bl NNS_G3dGetAnmByIdx
	str r0, [sp, #0xc]
	ldr r1, [sp, #0xc]
	ldr r2, [r5, #0x54]
	add r0, r7, #0
	bl NNS_G3dAllocAnmObj
	str r0, [r6, #0x6c]
	ldr r1, [sp, #0xc]
	ldr r2, [r5, #0x54]
	ldr r3, [sp, #8]
	bl NNS_G3dAnmObjInit
	ldr r1, [r6, #0x6c]
	add r0, r5, #0
	bl NNS_G3dRenderObjAddAnmObj
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _021E5D5A
	ldr r0, [sp, #4]
	bl NARC_Delete
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E5DAC: .word ov105_021E5E8C
_021E5DB0: .word _021E5E80
_021E5DB4: .word ov105_021E5DC8
_021E5DB8: .word ov105_021E5EA4
_021E5DBC: .word ov105_021E5E98
_021E5DC0: .word _021E5DC4
	thumb_func_end ov105_021E5CA4

	.rodata

_021E5DC4:
	.byte 0x5C, 0x08, 0x00, 0x00

ov105_021E5DC8: ; 0x021E5DC8
	.byte 0x5C, 0x08, 0x00, 0x00

ov105_021E5DCC: ; 0x021E5DCC
	.byte 0x96, 0x00

ov105_021E5DCE: ; 0x021E5DCE
	.byte 0xA4, 0x06
	.byte 0x96, 0x00, 0xA4, 0x06

ov105_021E5DD4: ; 0x021E5DD4
	.byte 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00

ov105_021E5DE0: ; 0x021E5DE0
	.byte 0x00, 0x00, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10

ov105_021E5DF0: ; 0x021E5DF0
	.byte 0x79, 0xF2, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4F, 0x27, 0x00, 0x00, 0x79, 0xF2, 0x10, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x4F, 0x27, 0x00, 0x00

ov105_021E5E08: ; 0x021E5E08
	.byte 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00

ov105_021E5E2C: ; 0x021E5E2C
	.byte 0x52, 0x71, 0x1B, 0x00
	.byte 0x62, 0xE1, 0x60, 0x13, 0x00, 0x00, 0x00, 0x00

ov105_021E5E38: ; 0x021E5E38
	.byte 0x00, 0x00

ov105_021E5E3A: ; 0x021E5E3A
	.byte 0x81, 0x0B, 0x00, 0x00, 0x00, 0x00
	.byte 0x52, 0x71, 0x1B, 0x00, 0x62, 0xE1, 0x60, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x0B
	.byte 0x00, 0x00, 0x00, 0x00

ov105_021E5E54: ; 0x021E5E54
	.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00

	.data

_021E5E80:
	.byte 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0x00, 0x09, 0x00

ov105_021E5E8C: ; 0x021E5E8C
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00

ov105_021E5E98: ; 0x021E5E98
	.byte 0x0F, 0x00, 0x00, 0x00, 0x10, 0x00, 0x11, 0x00
	.byte 0x12, 0x00, 0x13, 0x00

ov105_021E5EA4: ; 0x021E5EA4
	.byte 0x0A, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x0C, 0x00, 0x0D, 0x00, 0x0E, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	; 0x021E5EC0
