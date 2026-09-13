	.include "asm/macros.inc"
	.include "overlay_108.inc"
	.include "global.inc"

	.text
	.extern SafariDecoration_Init
	.extern SafariDecoration_Exit
	.extern SafariDecoration_Main
	.extern ov108_021E8968
	.extern ov108_021E8A88
	.extern ov108_021E8AD4
	.extern ov108_021E8B24
	.extern ov108_021E8B68
	.extern ov108_021E8BC0
	.extern ov108_021E8C18
	.extern ov108_021E8C64
	.extern ov108_021E8E10
	.extern ov108_021E8E60
	.extern ov108_021E8EA4
	.extern ov108_021E8ED8
	.extern ov108_021E8F00
	.extern ov108_021E90C4
	.extern ov108_021E9144
	.extern ov108_021E9198
	.extern ov108_021E91D4
	.extern ov108_021E91F8
	.extern ov108_021E9204
	.extern ov108_021E9210
	.extern ov108_021E9230
	.extern ov108_021E929C
	.extern ov108_021E9304
	.extern ov108_021E9388
	.extern ov108_021E93A8
	.extern ov108_021E940C
	.extern ov108_021E9488
	.extern ov108_021E94E8
	.extern ov108_021E9528
	.extern ov108_021E95AC
	.extern ov108_021E96FC
	.extern ov108_021E979C
	.extern ov108_021E9830
	.extern ov108_021E9850
	.extern ov108_021E9A08
	.extern ov108_021E9A60
	.extern ov108_021E9BD4
	.extern ov108_021E9C14
	.extern ov108_021E9C2C
	.extern ov108_021E9C3C
	.extern ov108_021E9CD0
	.extern ov108_021E9D30
	.extern ov108_021E9DE0
	.extern ov108_021E9E10
	.extern ov108_021E9E80
	.extern ov108_021E9EB8
	.extern ov108_021E9F04
	.extern ov108_021E9F20
	.extern ov108_021E9F94
	.extern ov108_021EA040
	.extern ov108_021EA260
	.extern ov108_021EA2EC
	.extern ov108_021EA334
	.extern ov108_021EA418
	.extern ov108_021EA47C
	.extern ov108_021EA50C
	.extern ov108_021EA52C
	.extern ov108_021EA584
	.extern ov108_021EA5E4
	.extern ov108_021EA624
	.extern ov108_021EA63C
	.extern ov108_021EA700
	.extern ov108_021EA9C4
	.extern ov108_021EA9D8
	.extern ov108_021EA9E4
	.extern ov108_021EAAA4
	.extern ov108_021EAAB0
	.extern ov108_021EAAC0
	.extern ov108_021EAAD0
	.extern ov108_021EAAE4
	.extern ov108_021EAB00
	.extern ov108_021EAB1C
	.extern ov108_021EAB38
	.extern ov108_021EAB54
	.extern ov108_021EAB70
	.extern ov108_021EAB8C
	.extern ov108_021EABA8
	.extern ov108_021EABC8
	.extern ov108_021EABF0
	.extern ov108_021EAC18
	.extern ov108_021EAC48
	.extern ov108_021EACE8
	.extern ov108_021EACF0
	.extern ov108_021EACF8
	.extern ov108_021EAD00
	.extern ov108_021EAD08
	.extern ov108_021EAD28


	thumb_func_start ov108_021E8CD4
ov108_021E8CD4: ; 0x021E8CD4
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r6, r1, #0
	add r4, r2, #0
	mov r1, #0
	mov r2, #0xf4
	add r5, r0, #0
	bl MI_CpuFill8
	bl NNS_G3dInit
	bl G3X_Init
	bl G3X_InitMtxStack
	ldr r0, _021E8DF4 ; =0x04000060
	ldr r1, _021E8DF8 ; =0xFFFFCFFD
	ldrh r2, [r0]
	and r2, r1
	strh r2, [r0]
	ldrh r3, [r0]
	ldr r2, _021E8DFC ; =0x0000CFFB
	and r2, r3
	strh r2, [r0]
	ldrh r3, [r0]
	add r2, r1, #2
	and r3, r2
	mov r2, #8
	orr r2, r3
	strh r2, [r0]
	add r2, r1, #2
	ldrh r3, [r0]
	add r1, r1, #2
	and r3, r2
	mov r2, #0x10
	orr r2, r3
	strh r2, [r0]
	ldrh r2, [r0]
	and r2, r1
	mov r1, #0x20
	orr r1, r2
	strh r1, [r0]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl G3X_SetFog
	mov r0, #0
	ldr r2, _021E8E00 ; =0x00007FFF
	add r1, r0, #0
	mov r3, #0x3f
	str r0, [sp]
	bl G3X_SetClearColor
	ldr r1, _021E8E04 ; =0x04000540
	mov r0, #2
	str r0, [r1]
	ldr r0, _021E8E08 ; =0xBFFF0000
	str r0, [r1, #0x40]
	add r0, r5, #0
	str r4, [r5, #0x14]
	add r0, #0xf1
	strb r6, [r0]
	mov r0, #0x80
	bl NNS_GfdGetLnkTexVramManagerWorkSize
	add r6, r0, #0
	ldr r0, [r5, #0x14]
	add r1, r6, #0
	bl Heap_Alloc
	add r1, r5, #0
	add r1, #0xec
	str r0, [r1]
	mov r0, #1
	add r2, r5, #0
	str r0, [sp]
	add r2, #0xec
	ldr r2, [r2]
	lsl r0, r0, #0x11
	mov r1, #0
	add r3, r6, #0
	bl GF_3DVramMan_InitLinkedListTexVramManager
	mov r0, #1
	lsl r0, r0, #8
	bl NNS_GfdGetLnkPlttVramManagerWorkSize
	add r6, r0, #0
	ldr r0, [r5, #0x14]
	add r1, r6, #0
	bl Heap_Alloc
	add r1, r5, #0
	add r1, #0xe8
	str r0, [r1]
	add r1, r5, #0
	add r1, #0xe8
	mov r0, #1
	ldr r1, [r1]
	lsl r0, r0, #0xe
	add r2, r6, #0
	mov r3, #1
	bl GF_3DVramMan_InitLinkedListPlttVramManager
	add r0, r5, #4
	add r1, r4, #0
	mov r2, #0x20
	bl HeapExp_FndInitAllocator
	mov r0, #0x28
	add r1, r4, #0
	bl NARC_New
	str r0, [r5, #0x18]
	mov r0, #0x6b
	add r1, r4, #0
	bl NARC_New
	str r0, [r5, #0x1c]
	mov r0, #0x6a
	add r1, r4, #0
	bl NARC_New
	str r0, [r5, #0x20]
	add r0, r5, #0
	add r1, r4, #0
	bl ov108_021E9230
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	ldr r1, _021E8E0C ; =0x04000008
	mov r0, #3
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #1
	orr r0, r2
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	nop
_021E8DF4: .word 0x04000060
_021E8DF8: .word 0xFFFFCFFD
_021E8DFC: .word 0x0000CFFB
_021E8E00: .word 0x00007FFF
_021E8E04: .word 0x04000540
_021E8E08: .word 0xBFFF0000
_021E8E0C: .word 0x04000008
	thumb_func_end ov108_021E8CD4
