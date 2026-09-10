	.include "asm/macros.inc"
	.public ov05_0221BA00
	.public ov05_0221BA70
	.public ov05_0221BB00
	.public ov05_0221BB30
	.public ov05_0221BD28
	.public ov05_0221BE04
	.public ov05_0221BE80
	.public ov05_0221BF08
	.public ov05_0221C018
	.public ov05_0221C050
	.public ov05_0221C21C
	.public ov05_0221C430
	.public ov05_0221C558
	.public ov05_0221C568
	.public ov05_0221C5A8
	.public ov05_0221C5C4
	.public ov05_0221C6C8
	.public ov05_0221C7FC
	.public ov05_0221C80C
	.public ov05_0221C8A0
	.public ov05_0221C8E0
	.public ov05_0221C908
	.public ov05_0221CAB8
	.public ov05_0221CB70
	.public ov05_0221CC04
	.public ov05_0221CC58
	.public ov05_0221CC74
	.public ov05_0221CCF4
	.public ov05_0221CD24
	.public ov05_0221CDC4
	.public ov05_0221CE0C
	.public ov05_0221CE50
	.public ov05_0221CE88
	.public ov05_0221CEB8
	.public ov05_0221CFF0
	.public ov05_0221D020
	.public ov05_0221D054
	.public ov05_0221D094
	.public ov05_0221D140
	.public ov05_0221D228
	.public ov05_0221D240
	.public ov05_0221D318
	.public ov05_0221D3AC
	.public ov05_0221D414
	.public ov05_0221D4D0
	.public ov05_0221D530
	.public ov05_0221D5DC
	.public ov05_0221D664
	.public ov05_0221D690
	.public ov05_0221D6C4
	.public ov05_0221D7AC
	.public ov05_0221D890
	.public ov05_0221D904
	.public ov05_0221D9F0
	.public ov05_0221DAE0
	.public ov05_0221DB18
	.public ov05_0221DB4C
	.public ov05_0221DB70
	.public ov05_0221DB94
	.public ov05_0221DC34
	.public ov05_0221DC60
	.public ov05_0221DD08
	.public ov05_0221DDEC
	.public ov05_0221DE38
	.public ov05_0221DE6C
	.public ov05_0221DF38
	.public ov05_0221E07C
	.public ov05_0221E0A8
	.public ov05_0221E110
	.public ov05_0221E274
	.public ov05_0221E2D8
	.public ov05_0221E390
	.public ov05_0221E42C
	.public ov05_0221E4C8
	.public ov05_0221E564
	.public ov05_0221E5E4
	.public ov05_0221E60C
	.public ov05_0221E624
	.public ov05_0221E714
	.public ov05_0221E74C
	.public ov05_0221E7B8
	.public ov05_0221E8A8
	.public ov05_0221E944
	.public ov05_0221E9C4
	.public ov05_0221E9F8
	.public ov05_0221EA18
	.public ov05_0221EA38
	.public _0221EA54
	.public ov05_0221EA58
	.public ov05_0221EA60
	.public ov05_0221EA6C
	.public ov05_0221EA6D
	.public ov05_0221EA78
	.public ov05_0221EA88
	.public ov05_0221EA98
	.public ov05_0221EAAC
	.public ov05_0221EAC0
	.public ov05_0221EAD4
	.public ov05_0221EAEC
	.public ov05_0221EB04
	.public ov05_0221EB1C
	.public ov05_0221EB38
	.public ov05_0221EB54
	.public ov05_0221EB70
	.public ov05_0221EB8C
	.public ov05_0221EBA8
	.public ov05_0221EBC4
	.public ov05_0221EBE0
	.public ov05_0221EC00
	.public ov05_0221EC28
	.public ov05_0221EC5C
	.public ov05_0221EC98
	.public ov05_0221ECE4
	.public ov05_0221EDA4
	.public ov05_0221EF2C
	.include "overlay_05.inc"
	.include "global.inc"

	.text

	thumb_func_start ov05_0221CD24
ov05_0221CD24: ; 0x0221CD24
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	add r5, r0, #0
	str r1, [sp]
	ldr r1, [r5]
	mov r0, #0x40
	ldr r1, [r1, #0x24]
	add r4, r2, #0
	bl GF_CreateVramTransferManager
	ldr r0, [r5]
	ldr r0, [r0, #0x24]
	bl SpriteSystem_Alloc
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	bl SpriteManager_New
	mov r1, #0x65
	lsl r1, r1, #2
	add r2, sp, #0x18
	ldr r3, _0221CDBC ; =ov05_0221EBE0
	str r0, [r5, r1]
	ldmia r3!, {r0, r1}
	add r6, r2, #0
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _0221CDC0 ; =ov05_0221EAAC
	add r2, sp, #4
	ldmia r3!, {r0, r1}
	add r7, r2, #0
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r1, r6, #0
	str r0, [r2]
	mov r0, #0x65
	lsl r0, r0, #2
	str r4, [sp, #4]
	sub r0, r0, #4
	ldr r0, [r5, r0]
	add r2, r7, #0
	mov r3, #0x10
	bl SpriteSystem_Init
	mov r1, #0x19
	lsl r1, r1, #4
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	bl SpriteSystem_InitSprites
	mov r1, #0x19
	lsl r1, r1, #4
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	ldr r2, [sp]
	bl SpriteSystem_InitManagerWithCapacities
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0221CDBC: .word ov05_0221EBE0
_0221CDC0: .word ov05_0221EAAC
	thumb_func_end ov05_0221CD24


	thumb_func_start ov05_0221CDC4
ov05_0221CDC4: ; 0x0221CDC4
	push {lr}
	sub sp, #0x34
	add r2, r0, #0
	mov r0, #0
	add r3, sp, #0
	strh r0, [r3]
	strh r0, [r3, #2]
	strh r0, [r3, #4]
	strh r0, [r3, #6]
	ldr r3, [r1, #0x14]
	str r3, [sp, #8]
	ldr r3, [r1, #0x18]
	str r3, [sp, #0xc]
	mov r3, #1
	str r3, [sp, #0x10]
	ldr r3, [r1]
	str r3, [sp, #0x14]
	ldr r3, [r1, #4]
	str r3, [sp, #0x18]
	ldr r3, [r1, #8]
	str r3, [sp, #0x1c]
	ldr r3, [r1, #0xc]
	str r3, [sp, #0x20]
	ldr r1, [r1, #0x10]
	str r1, [sp, #0x2c]
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #0x30]
	ldr r0, [r2, r1]
	add r1, r1, #4
	ldr r1, [r2, r1]
	add r2, sp, #0
	bl SpriteSystem_NewSprite
	add sp, #0x34
	pop {pc}
	thumb_func_end ov05_0221CDC4


	thumb_func_start ov05_0221CE0C
ov05_0221CE0C: ; 0x0221CE0C
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r0, #0x21
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r4, #0
	cmp r0, #0
	bls _0221CE36
	mov r7, #0x21
	add r5, r6, #0
	lsl r7, r7, #4
_0221CE22:
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Sprite_DeleteAndFreeResources
	ldr r0, [r6, r7]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r0
	blo _0221CE22
_0221CE36:
	mov r1, #0x19
	lsl r1, r1, #4
	ldr r0, [r6, r1]
	add r1, r1, #4
	ldr r1, [r6, r1]
	bl SpriteSystem_FreeResourcesAndManager
	mov r0, #0x19
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	bl SpriteSystem_Free
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov05_0221CE0C


	thumb_func_start ov05_0221CE50
ov05_0221CE50: ; 0x0221CE50
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x21
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r4, #0
	cmp r0, #0
	bls _0221CE84
	mov r7, #0x66
	lsl r7, r7, #2
	add r6, r7, #0
	add r6, #0x78
_0221CE68:
	lsl r0, r4, #2
	add r0, r5, r0
	ldr r0, [r0, r7]
	mov r1, #1
	ldr r0, [r0]
	lsl r1, r1, #0xc
	bl Sprite_UpdateAnim
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	ldr r0, [r5, r6]
	cmp r4, r0
	blo _0221CE68
_0221CE84:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov05_0221CE50


	thumb_func_start ov05_0221CE88
ov05_0221CE88: ; 0x0221CE88
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0xc]
	bl DoScheduledBgGpuUpdates
	ldr r0, [r4, #8]
	bl PaletteData_PushTransparentBuffers
	bl GF_RunVramTransferTasks
	bl SpriteSystem_TransferOam
	ldr r3, _0221CEB0 ; =0x027E0000
	ldr r1, _0221CEB4 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	nop
_0221CEB0: .word 0x027E0000
_0221CEB4: .word 0x00003FF8
	thumb_func_end ov05_0221CE88


	thumb_func_start ov05_0221CEB8
ov05_0221CEB8: ; 0x0221CEB8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x80
	add r5, r0, #0
	ldr r0, _0221CFD4 ; =0x00000BA8
	add r4, r1, #0
	ldr r6, _0221CFD8 ; =ov05_0221EA78
	str r4, [r5, r0]
	add r3, sp, #0x70
	add r7, r2, #0
	add r2, r3, #0
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	str r4, [sp, #0x7c]
	bl SetBothScreensModesAndDisable
	ldr r6, _0221CFDC ; =ov05_0221EB1C
	add r3, sp, #0x54
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	mov r1, #3
	str r0, [r3]
	ldr r0, [r5, #0xc]
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r5, #0xc]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	mov r1, #3
	add r3, r1, #0
	ldr r0, [r5, #0xc]
	mov r2, #0
	add r3, #0xfd
	bl ScheduleSetBgPosText
	ldr r6, _0221CFE0 ; =ov05_0221EB54
	add r3, sp, #0x38
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	mov r1, #2
	str r0, [r3]
	ldr r0, [r5, #0xc]
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r5, #0xc]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	mov r3, #0xff
	ldr r0, [r5, #0xc]
	mov r1, #2
	mov r2, #0
	mvn r3, r3
	bl ScheduleSetBgPosText
	ldr r6, _0221CFE4 ; =ov05_0221EB70
	add r3, sp, #0x1c
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	mov r1, #1
	str r0, [r3]
	ldr r0, [r5, #0xc]
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r5, #0xc]
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	cmp r7, #1
	bne _0221CF88
	ldr r0, [r5, #0xc]
	mov r1, #1
	mov r2, #3
	mov r3, #0x18
	bl BgSetPosTextAndCommit
_0221CF88:
	cmp r4, #0
	bne _0221CFD0
	ldr r4, _0221CFE8 ; =ov05_0221EBA8
	add r3, sp, #0
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	mov r1, #0
	str r0, [r3]
	ldr r0, [r5, #0xc]
	add r3, r1, #0
	bl InitBgFromTemplate
	ldr r0, [r5, #0xc]
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r0, _0221CFEC ; =0x00000BC8
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _0221CFC8
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	add sp, #0x80
	pop {r3, r4, r5, r6, r7, pc}
_0221CFC8:
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
_0221CFD0:
	add sp, #0x80
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221CFD4: .word 0x00000BA8
_0221CFD8: .word ov05_0221EA78
_0221CFDC: .word ov05_0221EB1C
_0221CFE0: .word ov05_0221EB54
_0221CFE4: .word ov05_0221EB70
_0221CFE8: .word ov05_0221EBA8
_0221CFEC: .word 0x00000BC8
	thumb_func_end ov05_0221CEB8
