	.include "asm/macros.inc"
	.public ov34_0225D520
	.public ov34_0225D558
	.public ov34_0225D5A0
	.public ov34_0225D5F8
	.public ov34_0225D650
	.public ov34_0225D77C
	.public ov34_0225D7A8
	.public ov34_0225D87C
	.public ov34_0225D900
	.public ov34_0225D924
	.public ov34_0225DA50
	.public ov34_0225DB20
	.public ov34_0225DC00
	.public ov34_0225DC0C
	.public ov34_0225DC18
	.public ov34_0225DD04
	.public ov34_0225DDB8
	.public ov34_0225DE04
	.public ov34_0225DE94
	.public ov34_0225E020
	.public ov34_0225E0E4
	.public ov34_0225E164
	.public ov34_0225E1C4
	.public ov34_0225E2BC
	.public ov34_0225E348
	.public ov34_0225E428
	.public ov34_0225E4A8
	.public ov34_0225E4F8
	.public ov34_0225E560
	.public ov34_0225E56C
	.public ov34_0225E58C
	.public ov34_0225E5D4
	.public ov34_0225E5DC
	.public ov34_0225E5E4
	.public ov34_0225E5EC
	.public ov34_0225E630
	.public _0225E694
	.public ov34_0225E6A0
	.public ov34_0225E6AC
	.public ov34_0225E6C0
	.public ov34_0225E6DC
	.public ov34_0225E6F8
	.public ov34_0225E714
	.public ov34_0225E730
	.include "overlay_34.inc"
	.include "global.inc"

	.text

	thumb_func_start ov34_0225D924
ov34_0225D924: ; 0x0225D924
	push {r3, r4, r5, lr}
	sub sp, #0x80
	add r4, r0, #0
	bl ov34_0225D900
	ldr r5, _0225DA40 ; =ov34_0225E714
	add r3, sp, #0x64
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
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	ldr r5, _0225DA44 ; =ov34_0225E6F8
	add r3, sp, #0x48
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
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	ldr r5, _0225DA48 ; =ov34_0225E6C0
	add r3, sp, #0x2c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #6
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	ldr r5, _0225DA4C ; =ov34_0225E6DC
	add r3, sp, #0x10
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #7
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #8
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0x60
	mov r1, #0
	str r0, [sp]
	mov r2, #4
	mov r0, #0x49
	add r3, r1, #0
	str r2, [sp, #4]
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	mov r0, #5
	lsl r0, r0, #0xa
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	mov r0, #0x49
	mov r1, #2
	add r2, r4, #0
	mov r3, #7
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r1, #4
	mov r0, #0x49
	add r2, r4, #0
	mov r3, #7
	str r1, [sp, #0xc]
	bl GfGfxLoader_LoadScrnData
	mov r0, #4
	mov r1, #0
	bl FieldMessage_LoadTextPalettes
	add sp, #0x80
	pop {r3, r4, r5, pc}
	nop
_0225DA40: .word ov34_0225E714
_0225DA44: .word ov34_0225E6F8
_0225DA48: .word ov34_0225E6C0
_0225DA4C: .word ov34_0225E6DC
	thumb_func_end ov34_0225D924


	thumb_func_start ov34_0225DA50
ov34_0225DA50: ; 0x0225DA50
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r0, #0
	add r1, r6, #0
	mov r0, #0xa
	add r1, #0x2c
	mov r2, #4
	bl G2dRenderer_Init
	mov r7, #0x55
	str r0, [r6, #0x28]
	mov r4, #0
	add r5, r6, #0
	lsl r7, r7, #2
_0225DA6C:
	mov r0, #1
	add r1, r4, #0
	mov r2, #4
	bl Create2DGfxResObjMan
	str r0, [r5, r7]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _0225DA6C
	ldr r0, _0225DB1C ; =0x000003E7
	mov r1, #0x49
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r2, #5
	mov r3, #1
	bl AddCharResObjFromNarc
	mov r1, #0x59
	lsl r1, r1, #2
	str r0, [r6, r1]
	ldr r0, _0225DB1C ; =0x000003E7
	mov r2, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	str r2, [sp, #8]
	mov r0, #4
	sub r1, #0xc
	str r0, [sp, #0xc]
	ldr r0, [r6, r1]
	mov r1, #0x49
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #0x5a
	lsl r1, r1, #2
	str r0, [r6, r1]
	ldr r0, _0225DB1C ; =0x000003E7
	sub r1, #0xc
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	ldr r0, [r6, r1]
	mov r1, #0x49
	mov r2, #6
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5b
	lsl r1, r1, #2
	str r0, [r6, r1]
	ldr r0, _0225DB1C ; =0x000003E7
	sub r1, #0xc
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	ldr r0, [r6, r1]
	mov r1, #0x49
	mov r2, #7
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x17
	lsl r1, r1, #4
	str r0, [r6, r1]
	sub r1, #0xc
	ldr r0, [r6, r1]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
	mov r0, #0x5a
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl SpriteTransfer_CreatePlttTransferTask
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225DB1C: .word 0x000003E7
	thumb_func_end ov34_0225DA50


	thumb_func_start ov34_0225DB20
ov34_0225DB20: ; 0x0225DB20
	push {r4, r5, r6, r7, lr}
	sub sp, #0x5c
	ldr r1, _0225DBF8 ; =0x000003E7
	add r5, r0, #0
	mov r0, #0
	str r1, [sp]
	mvn r0, r0
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r3, #0x55
	str r0, [sp, #0x10]
	lsl r3, r3, #2
	ldr r2, [r5, r3]
	str r2, [sp, #0x14]
	add r2, r3, #4
	ldr r2, [r5, r2]
	str r2, [sp, #0x18]
	add r2, r3, #0
	add r2, #8
	ldr r2, [r5, r2]
	str r2, [sp, #0x1c]
	add r2, r3, #0
	add r2, #0xc
	ldr r2, [r5, r2]
	add r3, #0x20
	str r2, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	add r0, r5, r3
	add r2, r1, #0
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	ldr r0, [r5, #0x28]
	mov r4, #0
	str r0, [sp, #0x2c]
	mov r0, #0x5d
	lsl r0, r0, #2
	add r0, r5, r0
	str r0, [sp, #0x30]
	mov r0, #1
	lsl r0, r0, #0xc
	mov r7, #0x3f
	str r4, [sp, #0x3c]
	str r0, [sp, #0x40]
	str r0, [sp, #0x44]
	str r0, [sp, #0x48]
	add r0, sp, #0x2c
	strh r4, [r0, #0x20]
	mov r0, #2
	str r0, [sp, #0x54]
	mov r0, #4
	ldr r6, _0225DBFC ; =ov34_0225E6A0
	str r4, [sp, #0x50]
	str r0, [sp, #0x58]
	lsl r7, r7, #0x18
_0225DB94:
	mov r0, #0x3a
	lsl r0, r0, #0xe
	str r0, [sp, #0x34]
	ldr r0, [r6]
	cmp r0, #0
	ble _0225DBB0
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	b _0225DBBC
_0225DBB0:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fsub
_0225DBBC:
	bl _ffix
	mov r1, #3
	lsl r1, r1, #0x12
	add r0, r0, r1
	str r0, [sp, #0x38]
	add r0, sp, #0x2c
	bl Sprite_CreateAffine
	mov r1, #0x66
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl Sprite_SetAnimCtrlSeq
	add r4, r4, #1
	add r6, r6, #4
	add r5, r5, #4
	cmp r4, #3
	blt _0225DB94
	add sp, #0x5c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0225DBF8: .word 0x000003E7
_0225DBFC: .word ov34_0225E6A0
	thumb_func_end ov34_0225DB20
