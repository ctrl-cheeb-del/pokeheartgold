	.include "asm/macros.inc"
	.include "overlay_95.inc"
	.include "global.inc"
	.public HatchEggApp_Exit
	.public HatchEggApp_Init
	.public HatchEggApp_Main
	.public ov95_021E5954
	.public ov95_021E5974
	.public ov95_021E59F8
	.public ov95_021E5A38
	.public ov95_021E5BBC
	.public ov95_021E5C44
	.public ov95_021E5CAC
	.public ov95_021E5D44
	.public ov95_021E5D98
	.public ov95_021E5DB4
	.public ov95_021E5DD0
	.public ov95_021E5E18
	.public ov95_021E5E90
	.public ov95_021E5EC0
	.public ov95_021E5EF8
	.public ov95_021E6000
	.public ov95_021E60A4
	.public ov95_021E619C
	.public ov95_021E623C
	.public ov95_021E62A4
	.public ov95_021E6314
	.public ov95_021E65A0
	.public ov95_021E6838
	.public ov95_021E68A8
	.public ov95_021E6900
	.public ov95_021E6964
	.public ov95_021E6B74
	.public ov95_021E7020
	.public ov95_021E70BC
	.public ov95_021E7258
	.public ov95_021E7308
	.public ov95_021E7328
	.public ov95_021E7388
	.public ov95_021E7410
	.public ov95_021E7450
	.public ov95_021E7538
	.public ov95_021E7548
	.public ov95_021E755C
	.public ov95_021E7574
	.public ov95_021E7594
	.public ov95_021E75B4
	.public ov95_021E75DC
	.public ov95_021E762C
	.public ov95_021E767C
	.public ov95_021E76D0
	.public ov95_021E7770
	.public ov95_021E7810
	.public ov95_021E7818
	.public ov95_021E7820
	.public ov95_021E782C
	.public ov95_021E7860


	.text
	.public ov95_021E5900
	.public ov95_021E5928
	.public ov95_021E5B24
	.public ov95_021E5B58
	.public ov95_021E5B7C
	.public ov95_021E5B9C
	.public ov95_021E5D34
	.public ov95_021E5E40
	.public ov95_021E5E58
	.public ov95_021E5EDC
	.public ov95_021E5EF0
	.public ov95_021E6150
	.public ov95_021E6184
	.public ov95_021E6228
	.public ov95_021E62E4
	.public ov95_021E62F0
	.public ov95_021E6300
	.public ov95_021E67F0
	.public ov95_021E6FC4
	.public ov95_021E7078
	.public ov95_021E7208
	.public ov95_021E72B8
	.public ov95_021E7404
	.public ov95_021E7514

	thumb_func_start ov95_021E70BC
ov95_021E70BC: ; 0x021E70BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	str r1, [sp, #0x10]
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	ldr r7, [r5, #4]
	ldr r6, [r5, #8]
	bne _021E70D2
	bl GF_AssertFail
_021E70D2:
	cmp r7, #0
	bne _021E70DA
	bl GF_AssertFail
_021E70DA:
	cmp r6, #0
	bne _021E70E2
	bl GF_AssertFail
_021E70E2:
	ldr r1, [r5]
	mov r0, #0xef
	bl NARC_New
	add r4, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r0, [sp, #0x18]
	add r1, r6, #0
	str r0, [sp, #0xc]
	add r0, r7, #0
	add r2, r4, #0
	mov r3, #0xb
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [sp, #0x14]
	add r1, r6, #0
	str r0, [sp, #8]
	add r0, r7, #0
	add r2, r4, #0
	mov r3, #0xc
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x30]
	add r1, r6, #0
	str r0, [sp, #4]
	add r0, r7, #0
	add r2, r4, #0
	mov r3, #0xd
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x34]
	add r1, r6, #0
	str r0, [sp, #4]
	add r0, r7, #0
	add r2, r4, #0
	mov r3, #0xe
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x14]
	str r0, [sp]
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x30]
	add r0, r5, #0
	bl ov95_021E7388
	mov r0, #1
	str r0, [sp]
	mov r0, #0xa0
	str r0, [sp, #4]
	mov r2, #0
	ldr r0, [sp, #0x10]
	mov r1, #0xef
	mov r3, #0x46
	str r2, [sp, #8]
	bl PaletteData_LoadNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xf0
	str r0, [sp, #8]
	ldr r0, [sp, #0x10]
	mov r1, #0x10
	mov r2, #9
	mov r3, #0x46
	bl PaletteData_LoadNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x46
	str r0, [sp, #0xc]
	ldr r2, [r5, #0xc]
	add r0, r4, #0
	mov r1, #1
	mov r3, #4
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x46
	str r0, [sp, #0xc]
	ldr r2, [r5, #0xc]
	add r0, r4, #0
	mov r1, #9
	mov r3, #4
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x46
	str r0, [sp, #0xc]
	ldr r2, [r5, #0xc]
	add r0, r4, #0
	mov r1, #1
	mov r3, #5
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x46
	str r0, [sp, #0xc]
	ldr r2, [r5, #0xc]
	add r0, r4, #0
	mov r1, #0xa
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #5
	mov r1, #0
	bl ToggleBgLayer
	mov r0, #6
	mov r1, #0
	bl ToggleBgLayer
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov95_021E70BC
