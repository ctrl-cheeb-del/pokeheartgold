	.include "asm/macros.inc"
	.include "overlay_99.inc"
	.include "global.inc"

	.text
	.public PokeathlonCourseRecord_Exit
	.public PokeathlonCourseRecord_Init
	.public PokeathlonCourseRecord_Main
	.public PokeathlonEventRecord_Exit
	.public PokeathlonEventRecord_Init
	.public PokeathlonEventRecord_Main
	.public PokeathlonMedals_Exit
	.public PokeathlonMedals_Init
	.public PokeathlonMedals_Main
	.public _021E954C
	.public _021EA5C0
	.public _021EA5CC
	.public _021EA5D8
	.public _021EA5E4
	.public ov99_021E5B90
	.public ov99_021E5BB4
	.public ov99_021E5BD8
	.public ov99_021E5C20
	.public ov99_021E5C4C
	.public ov99_021E5C88
	.public ov99_021E5D2C
	.public ov99_021E5D58
	.public ov99_021E5EB4
	.public ov99_021E5F74
	.public ov99_021E5FE8
	.public ov99_021E6018
	.public ov99_021E6050
	.public ov99_021E607C
	.public ov99_021E6144
	.public ov99_021E6188
	.public ov99_021E6218
	.public ov99_021E6250
	.public ov99_021E6274
	.public ov99_021E6400
	.public ov99_021E6438
	.public ov99_021E64E0
	.public ov99_021E6530
	.public ov99_021E6638
	.public ov99_021E677C
	.public ov99_021E6840
	.public ov99_021E6888
	.public ov99_021E6938
	.public ov99_021E695C
	.public ov99_021E69D8
	.public ov99_021E6A70
	.public ov99_021E6A9C
	.public ov99_021E6C30
	.public ov99_021E6CF4
	.public ov99_021E6D14
	.public ov99_021E6D34
	.public ov99_021E6F70
	.public ov99_021E6FA0
	.public ov99_021E6FD0
	.public ov99_021E7100
	.public ov99_021E7124
	.public ov99_021E7158
	.public ov99_021E71B0
	.public ov99_021E71E4
	.public ov99_021E7208
	.public ov99_021E7258
	.public ov99_021E728C
	.public ov99_021E72C0
	.public ov99_021E738C
	.public ov99_021E73E0
	.public ov99_021E7428
	.public ov99_021E7450
	.public ov99_021E7508
	.public ov99_021E7598
	.public ov99_021E76D8
	.public ov99_021E7758
	.public ov99_021E7794
	.public ov99_021E77D8
	.public ov99_021E7A54
	.public ov99_021E7A78
	.public ov99_021E7AB8
	.public ov99_021E7AD4
	.public ov99_021E7BC8
	.public ov99_021E7C58
	.public ov99_021E7CE4
	.public ov99_021E7D30
	.public ov99_021E7DA4
	.public ov99_021E7EBC
	.public ov99_021E7EF0
	.public ov99_021E7F64
	.public ov99_021E7F90
	.public ov99_021E80D0
	.public ov99_021E810C
	.public ov99_021E8198
	.public ov99_021E8224
	.public ov99_021E82E4
	.public ov99_021E84EC
	.public ov99_021E8518
	.public ov99_021E8544
	.public ov99_021E856C
	.public ov99_021E8590
	.public ov99_021E860C
	.public ov99_021E86D4
	.public ov99_021E875C
	.public ov99_021E8788
	.public ov99_021E87D0
	.public ov99_021E8828
	.public ov99_021E88EC
	.public ov99_021E89A4
	.public ov99_021E89EC
	.public ov99_021E8C04
	.public ov99_021E8C50
	.public ov99_021E8C88
	.public ov99_021E8D5C
	.public ov99_021E8D88
	.public ov99_021E8EBC
	.public ov99_021E8F50
	.public ov99_021E8FEC
	.public ov99_021E9038
	.public ov99_021E90F4
	.public ov99_021E92EC
	.public ov99_021E93DC
	.public ov99_021E9430
	.public ov99_021E9464
	.public ov99_021E94CC
	.public ov99_021E9518
	.public ov99_021E9554
	.public ov99_021E9564
	.public ov99_021E9574
	.public ov99_021E9576
	.public ov99_021E958C
	.public ov99_021E95A4
	.public ov99_021E95BC
	.public ov99_021E95D8
	.public ov99_021E95DC
	.public ov99_021E9600
	.public ov99_021E9628
	.public ov99_021E9650
	.public ov99_021E9690
	.public ov99_021E96D8
	.public ov99_021E9760
	.public ov99_021E9840
	.public ov99_021E9D88
	.public ov99_021E9D8C
	.public ov99_021E9D9C
	.public ov99_021E9DAC
	.public ov99_021E9DBC
	.public ov99_021E9DD4
	.public ov99_021E9DEC
	.public ov99_021E9E04
	.public ov99_021E9E2C
	.public ov99_021E9E60
	.public ov99_021E9ED0
	.public ov99_021E9F4C
	.public ov99_021E9F54
	.public ov99_021E9F60
	.public ov99_021E9F70
	.public ov99_021E9F80
	.public ov99_021E9F90
	.public ov99_021E9FA0
	.public ov99_021E9FB0
	.public ov99_021E9FC4
	.public ov99_021E9FDC
	.public ov99_021EA03C
	.public ov99_021EA0BC
	.public ov99_021EA180
	.public ov99_021EA250
	.public ov99_021EA348
	.public ov99_021EA350
	.public ov99_021EA35A
	.public ov99_021EA364
	.public ov99_021EA374
	.public ov99_021EA384
	.public ov99_021EA38C
	.public ov99_021EA394
	.public ov99_021EA3AC
	.public ov99_021EA3C4
	.public ov99_021EA3F4
	.public ov99_021EA45C
	.public ov99_021EA4F4
	.public ov99_021EA59C

	.public ov99_021E5B54
	.public ov99_021E5B70
	.public ov99_021E5B74
	.public ov99_021E5B7C
	.public ov99_021E6C14
	.public ov99_021E7060
	.public ov99_021E7068
	.public ov99_021E7078
	.public ov99_021E7088
	.public ov99_021E7098
	.public ov99_021E70A8
	.public ov99_021E70B8
	.public ov99_021E70C8
	.public ov99_021E70D8
	.public ov99_021E70E8
	.public ov99_021E714C
	.public ov99_021E7150
	.public ov99_021E7180
	.public ov99_021E718C
	.public ov99_021E7198
	.public ov99_021E71DC
	.public ov99_021E723C
	.public ov99_021E724C
	.public ov99_021E7CA8
	.public ov99_021E7CC8
	.public ov99_021E7CCC
	.public ov99_021E7CD8
	.public ov99_021E8818
	.public ov99_021E88D4
	.public ov99_021E9020
	.public ov99_021E9418
	.public ov99_021E945C
	.public ov99_021E94FC
	.public ov99_021E9508

	thumb_func_start ov99_021E7CE4
ov99_021E7CE4: ; 0x021E7CE4
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r3, #0
	cmp r4, r2
	beq _021E7D2A
	cmp r4, #0x20
	bhs _021E7D2A
	bl ov99_021E7C58
	cmp r4, #0x1e
	bge _021E7D0C
	mov r1, #0xfd
	lsl r1, r1, #2
	mov r0, #2
	ldr r2, [r5, r1]
	lsl r0, r0, #0x1c
	orr r0, r2
	str r0, [r5, r1]
	b _021E7D12
_021E7D0C:
	add r0, r5, #0
	bl ov99_021E77D8
_021E7D12:
	cmp r4, #0x1e
	bne _021E7D1A
	mov r1, #0xc
	b _021E7D1C
_021E7D1A:
	mov r1, #0xe
_021E7D1C:
	cmp r6, #0
	beq _021E7D22
	add r1, r1, #1
_021E7D22:
	ldr r0, _021E7D2C ; =0x00000408
	ldr r0, [r5, r0]
	bl ManagedSprite_SetAnim
_021E7D2A:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E7D2C: .word 0x00000408
	thumb_func_end ov99_021E7CE4


	thumb_func_start ov99_021E7D30
ov99_021E7D30: ; 0x021E7D30
	push {r4, r5, r6, r7, lr}
	sub sp, #0xd4
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	bl BgConfig_Alloc
	add r3, sp, #0
	ldr r4, _021E7D98 ; =ov99_021E9F80
	str r0, [r5]
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r4, _021E7D9C ; =ov99_021EA0BC
	add r3, sp, #0x10
	mov r2, #0x18
_021E7D58:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E7D58
	ldr r0, [r4]
	ldr r4, _021E7DA0 ; =ov99_021EA348
	str r0, [r3]
	mov r7, #0
	add r6, sp, #0x10
_021E7D6A:
	ldrb r1, [r4]
	ldr r0, [r5]
	add r2, r6, #0
	mov r3, #0
	bl InitBgFromTemplate
	ldrb r1, [r4]
	ldr r0, [r5]
	bl BgClearTilemapBufferAndCommit
	ldrb r0, [r4]
	ldr r3, [r5, #0xc]
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	add r7, r7, #1
	add r6, #0x1c
	add r4, r4, #1
	cmp r7, #7
	blt _021E7D6A
	add sp, #0xd4
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E7D98: .word ov99_021E9F80
_021E7D9C: .word ov99_021EA0BC
_021E7DA0: .word ov99_021EA348
	thumb_func_end ov99_021E7D30


	thumb_func_start ov99_021E7DA4
ov99_021E7DA4: ; 0x021E7DA4
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0x40
	str r0, [sp]
	ldr r0, [r4, #0xc]
	mov r2, #0
	str r0, [sp, #4]
	ldr r0, [r4, #4]
	mov r1, #0x2a
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x2c
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	ldr r2, [r4]
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x2e
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	ldr r2, [r4]
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x2c
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	ldr r2, [r4]
	mov r3, #2
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x2f
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	ldr r2, [r4]
	mov r3, #2
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r1, #1
	str r1, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x30
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	ldr r2, [r4]
	mov r3, #3
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0x40
	str r0, [sp]
	ldr r0, [r4, #0xc]
	mov r1, #0x2b
	str r0, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x2d
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	ldr r2, [r4]
	mov r3, #4
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x31
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	ldr r2, [r4]
	mov r3, #4
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x2d
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	ldr r2, [r4]
	mov r3, #6
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x32
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	ldr r2, [r4]
	mov r3, #6
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end ov99_021E7DA4


	thumb_func_start ov99_021E7EBC
ov99_021E7EBC: ; 0x021E7EBC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #8]
	bl NARC_Delete
	ldr r0, [r5, #4]
	bl NARC_Delete
	ldr r6, _021E7EEC ; =ov99_021EA348
	mov r4, #0
_021E7ED0:
	ldrb r1, [r6, r4]
	ldr r0, [r5]
	bl FreeBgTilemapBuffer
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #7
	blo _021E7ED0
	ldr r0, [r5]
	bl Heap_Free
	pop {r4, r5, r6, pc}
	nop
_021E7EEC: .word ov99_021EA348
	thumb_func_end ov99_021E7EBC


	thumb_func_start ov99_021E7EF0
ov99_021E7EF0: ; 0x021E7EF0
	push {r3, r4, r5, lr}
	sub sp, #0x28
	ldr r5, _021E7F58 ; =ov99_021E9FC4
	add r3, sp, #0x10
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r1, r2, #0
	ldr r0, [r4, #0xc]
	mov r2, #0x32
	bl ov98_0221E5E0
	ldr r1, _021E7F5C ; =0x00000404
	str r0, [r4, r1]
	add r0, r4, #0
	bl ov99_021E7F90
	add r0, r4, #0
	bl ov99_021E80D0
	add r0, r4, #0
	bl ov99_021E810C
	add r0, r4, #0
	bl ov99_021E8198
	add r0, r4, #0
	bl ov99_021E724C
	add r3, r0, #0
	mov r0, #5
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #0x98
	str r0, [sp, #8]
	mov r0, #1
	ldr r1, _021E7F5C ; =0x00000404
	str r0, [sp, #0xc]
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r2, _021E7F60 ; =ov99_021E9F60
	add r1, r4, r1
	bl ov98_0221E6F0
	add sp, #0x28
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E7F58: .word ov99_021E9FC4
_021E7F5C: .word 0x00000404
_021E7F60: .word ov99_021E9F60
	thumb_func_end ov99_021E7EF0


	thumb_func_start ov99_021E7F64
ov99_021E7F64: ; 0x021E7F64
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _021E7F88 ; =0x00000404
	ldr r0, [r5, r0]
	bl ov98_0221E5C0
	add r4, r0, #0
	ldr r0, _021E7F88 ; =0x00000404
	ldr r0, [r5, r0]
	bl ov98_0221E5D0
	add r1, r0, #0
	ldr r2, _021E7F8C ; =ov99_021E9F70
	add r0, r4, #0
	mov r3, #2
	bl ov98_0221E784
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E7F88: .word 0x00000404
_021E7F8C: .word ov99_021E9F70
	thumb_func_end ov99_021E7F64


	thumb_func_start ov99_021E7F90
ov99_021E7F90: ; 0x021E7F90
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, _021E80C8 ; =0x00000404
	ldr r0, [r5, r0]
	bl ov98_0221E5C0
	add r4, r0, #0
	ldr r0, _021E80C8 ; =0x00000404
	ldr r0, [r5, r0]
	bl ov98_0221E5D0
	add r6, r0, #0
	mov r3, #1
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r3, #0
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r3, #2
	str r3, [sp, #4]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #3
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #3
	str r0, [sp, #0xc]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #4
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x20
	str r0, [sp, #8]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #5
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #6
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #7
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x18
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x19
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x1a
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x1b
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _021E80C8 ; =0x00000404
	ldr r1, _021E80CC ; =ov99_021E9F90
	ldr r0, [r5, r0]
	mov r2, #0x1e
	mov r3, #1
	bl ov98_0221E8A8
	add r0, r5, #0
	bl ov99_021E7F64
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E80C8: .word 0x00000404
_021E80CC: .word ov99_021E9F90
	thumb_func_end ov99_021E7F90


	thumb_func_start ov99_021E80D0
ov99_021E80D0: ; 0x021E80D0
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	ldr r4, _021E8100 ; =ov99_021EA180
	mov r6, #0
	add r5, r7, #0
_021E80DA:
	ldr r0, _021E8104 ; =0x00000404
	add r1, r4, #0
	ldr r0, [r7, r0]
	bl ov98_0221E6E0
	ldr r1, _021E8108 ; =0x00000408
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	add r6, r6, #1
	add r4, #0x34
	add r5, r5, #4
	cmp r6, #4
	blt _021E80DA
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E8100: .word ov99_021EA180
_021E8104: .word 0x00000404
_021E8108: .word 0x00000408
	thumb_func_end ov99_021E80D0


	thumb_func_start ov99_021E810C
ov99_021E810C: ; 0x021E810C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	mov r4, #0
	str r0, [sp]
	add r2, sp, #4
	add r0, r4, #0
	add r1, r4, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r7, _021E818C ; =ov99_021E9FB0
	str r0, [r2]
	mov r6, #0x30
_021E812C:
	add r0, sp, #4
	strh r4, [r0, #6]
	mov r0, #0x20
	str r0, [sp, #0x18]
	mov r0, #3
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	mov r0, #2
	str r0, [sp, #0x14]
	ldr r0, [r7]
	str r4, [sp, #0x10]
	lsl r1, r0, #3
	add r1, #0x68
	add r0, sp, #4
	strh r1, [r0]
	strh r6, [r0, #2]
	add r0, r4, #0
	add r0, #0xf
	lsl r1, r0, #2
	ldr r0, [sp]
	add r5, r0, r1
	add r1, r0, #0
	ldr r0, _021E8190 ; =0x00000404
	ldr r0, [r1, r0]
	add r1, sp, #4
	bl ov98_0221E6E0
	ldr r1, _021E8194 ; =0x00000408
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	ldr r0, _021E8194 ; =0x00000408
	mov r1, #0
	ldr r0, [r5, r0]
	bl ManagedSprite_SetDrawFlag
	add r4, r4, #1
	add r7, r7, #4
	add r6, #0x20
	cmp r4, #5
	blt _021E812C
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E818C: .word ov99_021E9FB0
_021E8190: .word 0x00000404
_021E8194: .word 0x00000408
	thumb_func_end ov99_021E810C


	thumb_func_start ov99_021E8198
ov99_021E8198: ; 0x021E8198
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r6, r0, #0
	mov r0, #0
	add r2, sp, #0x10
	add r1, r0, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [sp, #8]
	str r0, [r2]
	str r0, [sp, #4]
	mov r0, #0x20
	str r0, [sp]
_021E81BA:
	ldr r0, [sp]
	mov r4, #0
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	mov r5, #0x30
	str r0, [sp, #0xc]
_021E81C6:
	ldr r0, [sp, #4]
	ldr r1, [sp, #0xc]
	add r7, r4, r0
	add r0, r7, #2
	str r0, [sp, #0x24]
	mov r0, #1
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
	str r0, [sp, #0x30]
	str r0, [sp, #0x20]
	add r0, sp, #0x10
	strh r5, [r0]
	strh r1, [r0, #2]
	mov r0, #1
	str r0, [sp, #0x3c]
	ldr r0, _021E821C ; =0x00000404
	add r1, sp, #0x10
	ldr r0, [r6, r0]
	bl ov98_0221E6E0
	add r7, #0x14
	lsl r1, r7, #2
	add r2, r6, r1
	ldr r1, _021E8220 ; =0x00000408
	add r4, r4, #1
	add r5, #0x20
	str r0, [r2, r1]
	cmp r4, #6
	blo _021E81C6
	ldr r0, [sp, #4]
	add r0, r0, #6
	str r0, [sp, #4]
	ldr r0, [sp]
	add r0, #0x18
	str r0, [sp]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #5
	blo _021E81BA
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_021E821C: .word 0x00000404
_021E8220: .word 0x00000408
	thumb_func_end ov99_021E8198


	thumb_func_start ov99_021E8224
ov99_021E8224: ; 0x021E8224
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	mov r0, #1
	lsl r0, r0, #0xa
	ldr r0, [r5, r0]
	bl ov98_0221EEFC
	add r6, r0, #0
	mov r0, #1
	lsl r0, r0, #0xa
	ldr r0, [r5, r0]
	mov r1, #0xb
	mov r2, #0x7e
	mov r3, #3
	bl ov98_0221EC24
	mov r1, #0
	mov r0, #1
	str r1, [sp]
	lsl r0, r0, #0xa
	ldr r0, [r5, r0]
	mov r2, #0x7f
	mov r3, #1
	bl ov98_0221EC08
	mov r2, #0
	mov r1, #4
	str r2, [sp]
	str r1, [sp, #4]
	lsl r0, r1, #8
	ldr r0, [r5, r0]
	mov r3, #1
	bl ov98_0221EBEC
	mov r7, #1
	mov r4, #0
	lsl r7, r7, #0xa
_021E8270:
	lsl r2, r4, #0x18
	add r0, r6, #0
	mov r1, #0
	lsr r2, r2, #0x18
	bl BufferPokeathlonMedalName
	ldr r0, [r5, r7]
	add r1, r4, #6
	mov r2, #4
	mov r3, #0
	bl ov98_0221EBD8
	add r4, r4, #1
	cmp r4, #5
	blt _021E8270
	add r0, r5, #0
	bl ov99_021E718C
	add r2, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r6, #0
	mov r1, #0
	mov r3, #3
	bl BufferIntegerAsString
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	lsl r0, r0, #0xa
	mov r1, #1
	ldr r0, [r5, r0]
	mov r2, #0x80
	add r3, r1, #0
	bl ov98_0221EC08
	add r0, r5, #0
	bl ov99_021E7150
	cmp r0, #0
	beq _021E82E0
	add r0, r5, #0
	bl ov99_021E724C
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	lsl r0, r0, #0xa
	ldr r0, [r5, r0]
	mov r1, #2
	add r2, #0x71
	mov r3, #1
	bl ov98_0221EC08
_021E82E0:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov99_021E8224


	thumb_func_start ov99_021E82E4
ov99_021E82E4: ; 0x021E82E4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	cmp r5, #0
	bne _021E82F2
	bl GF_AssertFail
_021E82F2:
	cmp r4, #0xa
	blo _021E82FA
	bl GF_AssertFail
_021E82FA:
	ldr r0, [r5]
	ldr r1, [r0, #8]
	lsl r0, r4, #1
	ldrh r0, [r1, r0]
	pop {r3, r4, r5, pc}
	thumb_func_end ov99_021E82E4


	thumb_func_start PokeathlonEventRecord_Init
PokeathlonEventRecord_Init: ; 0x021E8304
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, _021E839C ; =FS_OVERLAY_ID(OVY_98)
	mov r1, #2
	bl HandleLoadOverlay
	add r0, r4, #0
	bl OverlayManager_GetArgs
	add r5, r0, #0
	bne _021E831E
	bl GF_AssertFail
_021E831E:
	mov r0, #3
	mov r1, #0x84
	lsl r2, r0, #0x10
	bl Heap_Create
	add r0, r4, #0
	mov r1, #0xe4
	mov r2, #0x84
	bl OverlayManager_CreateAndGetData
	mov r1, #0
	mov r2, #0xe4
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x84
	str r0, [r4, #0xc]
	add r0, r4, #0
	add r1, r5, #0
	bl ov99_021E93DC
	bl ov98_0221F090
	add r0, r4, #0
	bl ov99_021E8590
	add r0, r4, #0
	bl ov99_021E860C
	ldr r0, _021E83A0 ; =0x0000013A
	ldr r3, _021E83A4 ; =ov99_021EA45C
	str r0, [sp]
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #4]
	mov r2, #0x13
	bl ov98_0221EABC
	str r0, [r4, #0x10]
	add r0, r4, #0
	bl ov99_021E88D4
	add r0, r4, #0
	bl ov99_021E8788
	add r0, r4, #0
	bl ov99_021E8C04
	add r0, r4, #0
	bl ov99_021E8818
	mov r0, #0
	bl ResetVisibleHardwareWindows
	mov r0, #1
	bl ResetVisibleHardwareWindows
	ldr r0, _021E83A8 ; =ov99_021E856C
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_021E839C: .word FS_OVERLAY_ID(OVY_98)
_021E83A0: .word 0x0000013A
_021E83A4: .word ov99_021EA45C
_021E83A8: .word ov99_021E856C
	thumb_func_end PokeathlonEventRecord_Init


	thumb_func_start PokeathlonEventRecord_Exit
PokeathlonEventRecord_Exit: ; 0x021E83AC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, [r4]
	bl ov99_021E9418
	add r1, r4, #0
	ldr r0, [r4, #0x14]
	add r1, #0x18
	mov r2, #0x25
	bl ov98_0221E684
	ldr r0, [r4, #0x10]
	mov r1, #0x13
	bl ov98_0221EB84
	add r0, r4, #0
	bl ov99_021E875C
	bl ov98_0221F0EC
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x84
	bl Heap_Destroy
	ldr r0, _021E83F0 ; =FS_OVERLAY_ID(OVY_98)
	bl UnloadOverlayByID
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E83F0: .word FS_OVERLAY_ID(OVY_98)
	thumb_func_end PokeathlonEventRecord_Exit


	thumb_func_start PokeathlonEventRecord_Main
PokeathlonEventRecord_Main: ; 0x021E83F4
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r5]
	add r4, r0, #0
	cmp r1, #4
	bhi _021E84CC
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E8412: ; jump table
	.short _021E841C - _021E8412 - 2 ; case 0
	.short _021E8438 - _021E8412 - 2 ; case 1
	.short _021E8446 - _021E8412 - 2 ; case 2
	.short _021E84B8 - _021E8412 - 2 ; case 3
	.short _021E84C6 - _021E8412 - 2 ; case 4
_021E841C:
	mov r0, #6
	mov r1, #1
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r4, #0xc]
	add r2, r1, #0
	str r0, [sp, #8]
	mov r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #1
	str r0, [r5]
	b _021E84D6
_021E8438:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E84D6
	mov r0, #2
	str r0, [r5]
	b _021E84D6
_021E8446:
	add r1, r4, #0
	add r1, #0xb4
	ldr r1, [r1]
	cmp r1, #0
	beq _021E8464
	add r1, r4, #0
	add r1, #0xb0
	ldr r2, [r1]
	mov r1, #1
	eor r2, r1
	add r1, r4, #0
	add r1, #0xb0
	str r2, [r1]
	bl ov99_021E8828
_021E8464:
	add r0, r4, #0
	add r0, #0xb8
	ldr r0, [r0]
	cmp r0, #0
	beq _021E8482
	add r0, r4, #0
	bl ov99_021E8788
	add r0, r4, #0
	bl ov99_021E8C50
	add r0, r4, #0
	mov r1, #0
	add r0, #0xb8
	str r1, [r0]
_021E8482:
	bl ov98_0221EF24
	cmp r0, #0
	bne _021E8494
	add r0, r4, #0
	bl ov99_021E90F4
	cmp r0, #0
	beq _021E84D6
_021E8494:
	ldr r0, _021E84E4 ; =0x000005DC
	bl PlaySE
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4, #0xc]
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #3
	str r0, [r5]
	b _021E84D6
_021E84B8:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E84D6
	mov r0, #4
	str r0, [r5]
	b _021E84D6
_021E84C6:
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, pc}
_021E84CC:
	ldr r0, _021E84E8 ; =_021EA5E4
	cmp r0, #0
	beq _021E84D6
	bl GF_AssertFail
_021E84D6:
	ldr r0, [r4, #0x14]
	bl ov98_0221E6CC
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_021E84E4: .word 0x000005DC
_021E84E8: .word _021EA5E4
	thumb_func_end PokeathlonEventRecord_Main


	thumb_func_start ov99_021E84EC
ov99_021E84EC: ; 0x021E84EC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r3, r5, #0
	add r3, #0xb0
	ldr r0, [r5]
	ldr r3, [r3]
	mov r2, #0
	add r4, r1, #0
	bl ov99_021E94CC
	add r6, r0, #0
	ldr r0, [r5]
	bl ov99_021E945C
	add r1, r0, #0
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	add r2, r6, #0
	bl ov98_0221EFE8
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov99_021E84EC


	thumb_func_start ov99_021E8518
ov99_021E8518: ; 0x021E8518
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r2, #0
	mov r2, #0
	ldr r0, [r5]
	add r3, r2, #0
	add r4, r1, #0
	bl ov99_021E94CC
	add r5, #0xb0
	add r2, r0, #0
	ldr r0, [r5]
	cmp r0, #0
	beq _021E8538
	mov r0, #0
	pop {r4, r5, r6, pc}
_021E8538:
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	add r1, r6, #0
	bl ov98_0221EFE8
	pop {r4, r5, r6, pc}
	thumb_func_end ov99_021E8518


	thumb_func_start ov99_021E8544
ov99_021E8544: ; 0x021E8544
	push {r3, lr}
	add r3, r0, #0
	add r2, r1, #0
	mov r1, #0xac
	ldr r0, [r3]
	ldrsb r1, [r3, r1]
	add r3, #0xb0
	ldr r3, [r3]
	bl ov99_021E94CC
	ldr r1, _021E8568 ; =0x0000FFFF
	cmp r0, r1
	bne _021E8562
	mov r0, #1
	pop {r3, pc}
_021E8562:
	mov r0, #0
	pop {r3, pc}
	nop
_021E8568: .word 0x0000FFFF
	thumb_func_end ov99_021E8544


	thumb_func_start ov99_021E856C
ov99_021E856C: ; 0x021E856C
	push {r4, lr}
	add r4, r0, #0
	bl SpriteSystem_TransferOam
	ldr r0, [r4, #4]
	bl DoScheduledBgGpuUpdates
	ldr r3, _021E8588 ; =0x027E0000
	ldr r1, _021E858C ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_021E8588: .word 0x027E0000
_021E858C: .word 0x00003FF8
	thumb_func_end ov99_021E856C


	thumb_func_start ov99_021E8590
ov99_021E8590: ; 0x021E8590
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xb8
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	bl BgConfig_Alloc
	add r3, sp, #0
	ldr r4, _021E8600 ; =ov99_021EA374
	str r0, [r5, #4]
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r4, _021E8604 ; =ov99_021EA4F4
	add r3, sp, #0x10
	mov r2, #0x15
_021E85B8:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E85B8
	ldr r4, _021E8608 ; =ov99_021EA59C
	mov r7, #0
	add r6, sp, #0x10
_021E85C6:
	ldrb r1, [r4]
	ldr r0, [r5, #4]
	add r2, r6, #0
	mov r3, #0
	bl InitBgFromTemplate
	ldrb r1, [r4]
	ldr r0, [r5, #4]
	bl BgClearTilemapBufferAndCommit
	ldrb r0, [r4]
	ldr r3, [r5, #0xc]
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	add r7, r7, #1
	add r6, #0x1c
	add r4, r4, #1
	cmp r7, #6
	blt _021E85C6
	ldr r1, [r5, #0xc]
	mov r0, #0xb1
	bl NARC_New
	str r0, [r5, #8]
	add sp, #0xb8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E8600: .word ov99_021EA374
_021E8604: .word ov99_021EA4F4
_021E8608: .word ov99_021EA59C
	thumb_func_end ov99_021E8590


	thumb_func_start ov99_021E860C
ov99_021E860C: ; 0x021E860C
	push {r4, lr}
	sub sp, #0x10
	mov r2, #0
	add r4, r0, #0
	str r2, [sp]
	ldr r0, [r4, #0xc]
	mov r1, #0x33
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x34
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x35
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r1, #1
	str r1, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x37
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #2
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r3, #0
	str r3, [sp]
	ldr r0, [r4, #0xc]
	mov r1, #0x33
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	mov r2, #4
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x34
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #4
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x36
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #4
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r1, #1
	str r1, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x37
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #6
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov99_021E860C


	thumb_func_start ov99_021E86D4
ov99_021E86D4: ; 0x021E86D4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r7, r0, #0
	ldr r0, [sp, #0x44]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	cmp r0, #0
	beq _021E86E8
	mov r0, #6
	b _021E86EA
_021E86E8:
	mov r0, #2
_021E86EA:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x1c]
	mov r0, #6
	mul r0, r1
	str r0, [sp, #0x18]
	mov r0, #0x5a
	mov r5, #0
	ldr r1, [sp, #0x40]
	lsl r0, r0, #2
	mul r0, r1
	str r5, [sp, #0x20]
	str r0, [sp, #0x14]
_021E8704:
	ldr r0, [sp, #0x10]
	mov r4, #0
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
_021E870C:
	ldr r0, [sp, #0x18]
	add r1, r4, #1
	add r0, r1, r0
	add r1, r0, r5
	ldr r0, [sp, #0x14]
	add r2, sp, #0x24
	add r1, r0, r1
	add r0, sp, #0x24
	strh r1, [r0]
	str r6, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0xc]
	ldr r0, [r7, #4]
	add r3, r3, r4
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x1c]
	lsr r3, r3, #0x18
	bl LoadRectToBgTilemapRect
	add r4, r4, #1
	cmp r4, #6
	blt _021E870C
	ldr r0, [sp, #0x10]
	add r5, #0x3c
	add r0, r0, #1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x20]
	add r0, r0, #1
	str r0, [sp, #0x20]
	cmp r0, #6
	blt _021E8704
	ldr r0, [r7, #4]
	ldr r1, [sp, #0x1c]
	bl BgCommitTilemapBufferToVram
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov99_021E86D4


	thumb_func_start ov99_021E875C
ov99_021E875C: ; 0x021E875C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #8]
	bl NARC_Delete
	ldr r6, _021E8784 ; =ov99_021EA59C
	mov r4, #0
_021E876A:
	ldrb r1, [r6, r4]
	ldr r0, [r5, #4]
	bl FreeBgTilemapBuffer
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #6
	blo _021E876A
	ldr r0, [r5, #4]
	bl Heap_Free
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E8784: .word ov99_021EA59C
	thumb_func_end ov99_021E875C


	thumb_func_start ov99_021E8788
ov99_021E8788: ; 0x021E8788
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r0, #0
	add r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	beq _021E879A
	mov r5, #1
	b _021E87B0
_021E879A:
	mov r0, #0xac
	ldrsb r0, [r4, r0]
	lsl r0, r0, #2
	add r0, r4, r0
	add r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	bne _021E87AE
	mov r5, #1
	b _021E87B0
_021E87AE:
	mov r5, #0
_021E87B0:
	add r0, r4, #0
	bl ov99_021E89EC
	str r5, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r4, #0
	add r4, #0xac
	ldrb r1, [r4]
	mov r2, #0x1a
	mov r3, #0
	bl ov99_021E86D4
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov99_021E8788


	thumb_func_start ov99_021E87D0
ov99_021E87D0: ; 0x021E87D0
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	beq _021E87E2
	mov r0, #2
	b _021E87E4
_021E87E2:
	mov r0, #1
_021E87E4:
	lsl r0, r0, #0x1d
	lsr r4, r0, #0x18
	mov r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	mov r1, #0x33
	str r0, [sp, #8]
	ldr r0, [r5, #8]
	mov r2, #0
	add r3, r4, #0
	bl GfGfxLoader_GXLoadPalWithSrcOffsetFromOpenNarc
	mov r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	mov r1, #0x33
	str r0, [sp, #8]
	ldr r0, [r5, #8]
	mov r2, #4
	add r3, r4, #0
	bl GfGfxLoader_GXLoadPalWithSrcOffsetFromOpenNarc
	add sp, #0xc
	pop {r4, r5, pc}
	thumb_func_end ov99_021E87D0
