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
	.extern ov108_021E8CD4
	.extern ov108_021E8E10
	.extern ov108_021E8E60
	.extern ov108_021E8EA4
	.extern ov108_021E8ED8
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


	thumb_func_start ov108_021E8F00
ov108_021E8F00: ; 0x021E8F00
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp, #4]
	add r4, r2, #0
	mov r2, #0
	add r5, r0, #0
	str r2, [sp]
	ldr r3, [sp, #4]
	str r1, [sp, #8]
	ldrb r1, [r4]
	ldr r0, [r0, #0x18]
	ldr r3, [r3, #0x14]
	add r5, #0x24
	bl GfGfxLoader_LoadFromOpenNarc
	ldr r1, [sp, #4]
	str r0, [r1, #0x24]
	bl NNS_G3dGetMdlSet
	str r0, [r5, #4]
	cmp r0, #0
	beq _021E8F4C
	add r2, r0, #0
	add r2, #8
	beq _021E8F40
	ldrb r1, [r0, #9]
	cmp r1, #0
	bls _021E8F40
	ldrh r1, [r0, #0xe]
	add r1, r2, r1
	add r1, r1, #4
	b _021E8F42
_021E8F40:
	mov r1, #0
_021E8F42:
	cmp r1, #0
	beq _021E8F4C
	ldr r1, [r1]
	add r0, r0, r1
	b _021E8F4E
_021E8F4C:
	mov r0, #0
_021E8F4E:
	str r0, [r5, #8]
	ldr r0, [r5]
	bl NNS_G3dGetTex
	str r0, [r5, #0xc]
	cmp r0, #0
	beq _021E8F68
	bl GF3dRender_AllocAndLoadTexResources
	ldr r0, [r5]
	ldr r1, [r5, #0xc]
	bl GF3dRender_BindModelSet
_021E8F68:
	add r0, r5, #0
	ldr r1, [r5, #8]
	add r0, #0x10
	bl NNS_G3dRenderObjInit
	bl DC_FlushAll
	add r0, r5, #0
	mov r1, #1
	add r0, #0xb4
	strh r1, [r0]
	ldr r0, [sp, #4]
	ldrb r1, [r4]
	ldr r0, [r0, #0x1c]
	add r2, sp, #0x10
	bl NARC_ReadWholeMember
	add r0, sp, #0x10
	ldrb r1, [r0]
	cmp r1, #0
	beq _021E8FEC
	ldrb r0, [r0, #1]
	cmp r0, #8
	beq _021E8FEC
	mov r0, #0
	add r6, r5, #0
	add r7, r5, #0
	str r0, [sp, #0xc]
	add r4, sp, #0x10
	add r6, #0x64
	add r7, #0xb6
_021E8FA6:
	ldr r1, [r4, #8]
	mov r0, #0
	mvn r0, r0
	mov ip, r1
	cmp r1, r0
	beq _021E8FEC
	add r2, r5, #0
	add r2, #0xb6
	ldrh r3, [r2]
	mov r2, #0x14
	ldr r0, [sp, #4]
	mul r2, r3
	add r1, r5, #0
	add r2, r6, r2
	mov r3, ip
	bl ov108_021E9198
	add r1, r5, #0
	add r1, #0xb6
	ldrh r2, [r1]
	mov r1, #0x14
	add r0, r5, #0
	mul r1, r2
	add r1, r6, r1
	bl ov108_021E91F8
	ldrh r0, [r7]
	add r4, r4, #4
	add r0, r0, #1
	strh r0, [r7]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #4
	blt _021E8FA6
_021E8FEC:
	ldr r0, [sp, #8]
	ldr r1, _021E90C0 ; =ov108_021EA9E4
	lsl r0, r0, #3
	add r4, r1, r0
	mov r0, #2
	ldrsh r0, [r4, r0]
	cmp r0, #0
	ble _021E900E
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _021E901C
_021E900E:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_021E901C:
	bl _ffix
	ldr r1, [sp, #4]
	add r1, #0xdc
	str r0, [r1]
	mov r0, #4
	ldrsh r0, [r4, r0]
	cmp r0, #0
	ble _021E9040
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _021E904E
_021E9040:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_021E904E:
	bl _ffix
	ldr r1, [sp, #4]
	add r1, #0xe0
	str r0, [r1]
	mov r0, #6
	ldrsh r0, [r4, r0]
	cmp r0, #0
	ble _021E9072
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _021E9080
_021E9072:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_021E9080:
	bl _ffix
	ldr r1, [sp, #4]
	add r1, #0xe4
	str r0, [r1]
	ldrh r0, [r4]
	cmp r0, #0
	beq _021E90A2
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _021E90B0
_021E90A2:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_021E90B0:
	bl _ffix
	ldr r1, [sp, #4]
	ldr r1, [r1]
	bl Camera_SetDistance
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E90C0: .word ov108_021EA9E4
	thumb_func_end ov108_021E8F00

	thumb_func_start ov108_021E90C4
ov108_021E90C4: ; 0x021E90C4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r1, #0
	add r7, r0, #0
	add r0, r6, #0
	add r0, #0xb6
	ldrh r0, [r0]
	mov r4, #0
	cmp r0, #0
	ble _021E90FA
	add r5, r6, #0
	add r5, #0x64
_021E90DC:
	add r0, r6, #0
	add r1, r5, #0
	bl ov108_021E9204
	add r0, r7, #0
	add r1, r5, #0
	bl ov108_021E91D4
	add r0, r6, #0
	add r0, #0xb6
	ldrh r0, [r0]
	add r4, r4, #1
	add r5, #0x14
	cmp r4, r0
	blt _021E90DC
_021E90FA:
	ldr r0, [r6, #0xc]
	cmp r0, #0
	beq _021E9124
	add r1, sp, #4
	add r2, sp, #0
	bl NNS_G3dTexReleaseTexKey
	ldr r1, _021E913C ; =NNS_GfdDefaultFuncFreeTexVram
	ldr r0, [sp, #4]
	ldr r1, [r1]
	blx r1
	ldr r1, _021E913C ; =NNS_GfdDefaultFuncFreeTexVram
	ldr r0, [sp]
	ldr r1, [r1]
	blx r1
	ldr r0, [r6, #0xc]
	bl NNS_G3dPlttReleasePlttKey
	ldr r1, _021E9140 ; =NNS_GfdDefaultFuncFreePlttVram
	ldr r1, [r1]
	blx r1
_021E9124:
	ldr r0, [r6]
	cmp r0, #0
	beq _021E912E
	bl Heap_Free
_021E912E:
	add r0, r6, #0
	mov r1, #0
	mov r2, #0xb8
	bl MI_CpuFill8
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E913C: .word NNS_GfdDefaultFuncFreeTexVram
_021E9140: .word NNS_GfdDefaultFuncFreePlttVram
	thumb_func_end ov108_021E90C4

	thumb_func_start ov108_021E9144
ov108_021E9144: ; 0x021E9144
	push {r3, r4, r5, r6, lr}
	sub sp, #0x3c
	add r6, r0, #0
	add r0, #0xb6
	ldrh r0, [r0]
	mov r4, #0
	cmp r0, #0
	ble _021E916C
	add r5, r6, #0
	add r5, #0x64
_021E9158:
	add r0, r5, #0
	bl ov108_021E9210
	add r0, r6, #0
	add r0, #0xb6
	ldrh r0, [r0]
	add r4, r4, #1
	add r5, #0x14
	cmp r4, r0
	blt _021E9158
_021E916C:
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r0, sp, #0x18
	bl MTX_Identity33_
	add r6, #0x10
	add r0, r6, #0
	add r1, sp, #0xc
	add r2, sp, #0x18
	add r3, sp, #0
	bl GF3dRender_DrawModel
	add sp, #0x3c
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov108_021E9144
