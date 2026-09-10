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

	thumb_func_start ov99_021E5B90
ov99_021E5B90: ; 0x021E5B90
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	cmp r5, #0
	bne _021E5B9E
	bl GF_AssertFail
_021E5B9E:
	cmp r4, #5
	blt _021E5BA6
	bl GF_AssertFail
_021E5BA6:
	mov r0, #0x2c
	ldr r1, [r5]
	mul r0, r4
	add r0, r1, r0
	ldrh r0, [r0, #6]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov99_021E5B90


	thumb_func_start ov99_021E5BB4
ov99_021E5BB4: ; 0x021E5BB4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	cmp r5, #0
	bne _021E5BC2
	bl GF_AssertFail
_021E5BC2:
	add r0, r5, #0
	add r1, r4, #0
	bl ov99_021E5B90
	cmp r0, #0
	beq _021E5BD2
	mov r0, #1
	pop {r3, r4, r5, pc}
_021E5BD2:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov99_021E5BB4


	thumb_func_start ov99_021E5BD8
ov99_021E5BD8: ; 0x021E5BD8
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	cmp r5, #0
	bne _021E5BE8
	bl GF_AssertFail
_021E5BE8:
	cmp r6, #3
	bne _021E5C12
	mov r0, #0x2c
	add r3, r4, #0
	ldr r1, [r5]
	mul r3, r0
	add r0, r1, r3
	ldrh r2, [r0, #6]
	ldrh r1, [r1, r3]
	sub r1, r2, r1
	lsl r1, r1, #0x10
	lsr r2, r1, #0x10
	ldrh r1, [r0, #2]
	ldrh r0, [r0, #4]
	sub r1, r2, r1
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	sub r0, r1, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	pop {r4, r5, r6, pc}
_021E5C12:
	mov r0, #0x2c
	ldr r2, [r5]
	mul r0, r4
	lsl r1, r6, #1
	add r0, r2, r0
	ldrh r0, [r1, r0]
	pop {r4, r5, r6, pc}
	thumb_func_end ov99_021E5BD8


	thumb_func_start ov99_021E5C20
ov99_021E5C20: ; 0x021E5C20
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r4, r2, #0
	cmp r0, #0
	bne _021E5C2E
	bl GF_AssertFail
_021E5C2E:
	cmp r5, #0xa
	blt _021E5C36
	bl GF_AssertFail
_021E5C36:
	cmp r4, #4
	blo _021E5C3E
	bl GF_AssertFail
_021E5C3E:
	ldr r0, _021E5C48 ; =ov99_021E9600
	lsl r1, r5, #2
	add r0, r0, r1
	ldrb r0, [r4, r0]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E5C48: .word ov99_021E9600
	thumb_func_end ov99_021E5C20


	thumb_func_start ov99_021E5C4C
ov99_021E5C4C: ; 0x021E5C4C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	cmp r5, #0
	bne _021E5C5C
	bl GF_AssertFail
_021E5C5C:
	cmp r6, #3
	blo _021E5C64
	bl GF_AssertFail
_021E5C64:
	cmp r4, #5
	blo _021E5C6C
	bl GF_AssertFail
_021E5C6C:
	mov r0, #0x2c
	ldr r1, [r5]
	mul r0, r4
	add r1, r1, r0
	mov r0, #0xc
	mul r0, r6
	add r0, r1, r0
	ldr r0, [r0, #8]
	lsl r0, r0, #0x17
	lsr r0, r0, #0x17
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov99_021E5C4C


	thumb_func_start ov99_021E5C88
ov99_021E5C88: ; 0x021E5C88
	push {r4, r5, r6, r7, lr}
	sub sp, #0xf4
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	bl BgConfig_Alloc
	add r3, sp, #4
	ldr r4, _021E5D18 ; =ov99_021E9564
	str r0, [r5, #4]
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r4, _021E5D1C ; =ov99_021E9760
	add r3, sp, #0x14
	mov r2, #0x1c
_021E5CB0:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E5CB0
	ldr r4, _021E5D20 ; =_021E954C
	mov r7, #0
	add r6, sp, #0x14
_021E5CBE:
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
	cmp r7, #8
	blt _021E5CBE
	mov r0, #0
	str r0, [sp]
	ldr r0, _021E5D24 ; =0x04000050
	mov r1, #8
	mov r2, #4
	mov r3, #0xf
	bl G2x_SetBlendAlpha_
	mov r0, #0
	str r0, [sp]
	ldr r0, _021E5D28 ; =0x04001050
	mov r1, #8
	mov r2, #2
	mov r3, #0xf
	bl G2x_SetBlendAlpha_
	ldr r1, [r5, #0xc]
	mov r0, #0xb1
	bl NARC_New
	str r0, [r5, #8]
	add sp, #0xf4
	pop {r4, r5, r6, r7, pc}
	nop
_021E5D18: .word ov99_021E9564
_021E5D1C: .word ov99_021E9760
_021E5D20: .word _021E954C
_021E5D24: .word 0x04000050
_021E5D28: .word 0x04001050
	thumb_func_end ov99_021E5C88


	thumb_func_start ov99_021E5D2C
ov99_021E5D2C: ; 0x021E5D2C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #8]
	bl NARC_Delete
	ldr r6, _021E5D54 ; =_021E954C
	mov r4, #0
_021E5D3A:
	ldrb r1, [r6, r4]
	ldr r0, [r5, #4]
	bl FreeBgTilemapBuffer
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #8
	blo _021E5D3A
	ldr r0, [r5, #4]
	bl Heap_Free
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E5D54: .word _021E954C
	thumb_func_end ov99_021E5D2C


	thumb_func_start ov99_021E5D58
ov99_021E5D58: ; 0x021E5D58
	push {r4, lr}
	sub sp, #0x10
	mov r2, #0
	add r4, r0, #0
	str r2, [sp]
	ldr r0, [r4, #0xc]
	mov r1, #0x1e
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x1f
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x20
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x3e
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #2
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r4, #0xc]
	mov r3, #0x1e
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	mov r1, #0x24
	mov r2, #0
	lsl r3, r3, #4
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x25
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #3
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x26
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #3
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r3, #0
	str r3, [sp]
	ldr r0, [r4, #0xc]
	mov r1, #0x21
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
	mov r1, #0x22
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
	mov r1, #0x23
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #4
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x44
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #5
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r4, #0xc]
	mov r3, #0x1e
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	mov r1, #0x27
	mov r2, #4
	lsl r3, r3, #4
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x28
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #7
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x29
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #7
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov99_021E5D58


	thumb_func_start ov99_021E5EB4
ov99_021E5EB4: ; 0x021E5EB4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r4, r1, #0
	cmp r2, #0
	beq _021E5EC6
	mov r6, #0xff
	mvn r6, r6
	b _021E5ECA
_021E5EC6:
	mov r6, #1
	lsl r6, r6, #8
_021E5ECA:
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5, #0xc]
	ldr r1, _021E5F68 ; =ov99_021E95D8
	str r0, [sp, #0xc]
	lsl r4, r4, #3
	ldr r0, [r5, #8]
	ldr r1, [r1, r4]
	ldr r2, [r5, #4]
	mov r3, #2
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5, #0xc]
	ldr r1, _021E5F6C ; =ov99_021E95DC
	str r0, [sp, #0xc]
	ldr r0, [r5, #8]
	ldr r1, [r1, r4]
	ldr r2, [r5, #4]
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	ldr r0, [r5, #4]
	mov r1, #2
	mov r2, #0
	add r3, r6, #0
	bl BgSetPosTextAndCommit
	ldr r0, [r5, #4]
	mov r1, #5
	mov r2, #0
	add r3, r6, #0
	bl BgSetPosTextAndCommit
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	neg r0, r6
	lsl r0, r0, #0x10
	ldr r7, _021E5F70 ; =ov99_021E9690
	mov r4, #0
	asr r6, r0, #0x10
_021E5F46:
	mov r0, #0xc
	mul r0, r4
	ldr r0, [r7, r0]
	add r1, r6, #0
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x18]
	mov r2, #0
	bl ManagedSprite_OffsetPositionXY
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #6
	blo _021E5F46
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E5F68: .word ov99_021E95D8
_021E5F6C: .word ov99_021E95DC
_021E5F70: .word ov99_021E9690
	thumb_func_end ov99_021E5EB4


	thumb_func_start ov99_021E5F74
ov99_021E5F74: ; 0x021E5F74
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r0, #0x8c
	ldr r0, [r0]
	cmp r0, #0
	beq _021E5FE0
	ldr r0, [r5, #4]
	mov r1, #2
	bl Bg_GetXpos
	asr r6, r0, #2
	cmp r0, r6
	bne _021E5F90
	mov r6, #0
_021E5F90:
	ldr r0, [r5, #4]
	mov r1, #2
	mov r2, #0
	add r3, r6, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5, #4]
	mov r1, #5
	mov r2, #0
	add r3, r6, #0
	bl ScheduleSetBgPosText
	ldr r7, _021E5FE4 ; =ov99_021E9690
	mov r4, #0
_021E5FAC:
	mov r0, #0xc
	mul r0, r4
	add r2, r7, r0
	ldr r1, [r2, #4]
	ldr r0, [r7, r0]
	ldr r2, [r2, #8]
	lsl r0, r0, #2
	add r0, r5, r0
	sub r1, r1, r6
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r0, #0x18]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #6
	blo _021E5FAC
	cmp r6, #0
	bne _021E5FE0
	mov r0, #0
	add r5, #0x8c
	str r0, [r5]
_021E5FE0:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E5FE4: .word ov99_021E9690
	thumb_func_end ov99_021E5F74


	thumb_func_start ov99_021E5FE8
ov99_021E5FE8: ; 0x021E5FE8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	bl ov99_021E5BB4
	cmp r0, #0
	beq _021E6006
	add r0, r5, #0
	add r5, #0x84
	ldr r2, [r5]
	add r1, r4, #0
	bl ov99_021E5EB4
	pop {r3, r4, r5, pc}
_021E6006:
	ldr r0, [r5, #4]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #4]
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	pop {r3, r4, r5, pc}
	thumb_func_end ov99_021E5FE8


	thumb_func_start ov99_021E6018
ov99_021E6018: ; 0x021E6018
	push {r4, lr}
	sub sp, #8
	mov r1, #0
	add r4, r0, #0
	str r1, [sp]
	ldr r0, [r4, #0x10]
	mov r2, #2
	mov r3, #1
	bl ov98_0221EC08
	mov r2, #0
	str r2, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, [r4, #0x10]
	mov r1, #2
	mov r3, #1
	bl ov98_0221EBEC
	ldr r0, [r4, #0x10]
	mov r1, #0xb
	mov r2, #7
	mov r3, #0
	bl ov98_0221EBD8
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov99_021E6018


	thumb_func_start ov99_021E6050
ov99_021E6050: ; 0x021E6050
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl ov99_021E6188
	add r0, r5, #0
	add r1, r4, #0
	bl ov99_021E607C
	ldr r0, [r5]
	add r1, r4, #0
	bl ov99_021E5BB4
	add r1, r0, #0
	add r0, r5, #0
	bl ov99_021E6144
	add r0, r5, #0
	bl ov99_021E6218
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov99_021E6050


	thumb_func_start ov99_021E607C
ov99_021E607C: ; 0x021E607C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, [r5, #0x10]
	add r7, r1, #0
	bl ov98_0221EEFC
	ldr r4, _021E6140 ; =ov99_021E958C
	str r0, [sp, #8]
	mov r6, #0
_021E6090:
	lsl r2, r6, #0x18
	ldr r0, [r5]
	add r1, r7, #0
	lsr r2, r2, #0x18
	bl ov99_021E5C20
	add r2, r0, #0
	lsl r2, r2, #0x18
	ldr r0, [sp, #8]
	mov r1, #1
	lsr r2, r2, #0x18
	bl BufferPokeathlonEventName
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [r5, #0x10]
	ldr r1, [r4]
	mov r2, #0xa
	add r3, r6, #1
	bl ov98_0221ECD0
	ldr r0, [r5]
	add r1, r7, #0
	bl ov99_021E5BB4
	cmp r0, #0
	beq _021E60EC
	lsl r2, r6, #0x10
	ldr r0, [r5]
	add r1, r7, #0
	lsr r2, r2, #0x10
	bl ov99_021E5BD8
	add r3, r0, #0
	mov r0, #3
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [r5, #0x10]
	ldr r1, [r4, #4]
	mov r2, #8
	bl ov98_0221ECD0
	b _021E60F8
_021E60EC:
	ldr r0, [r5, #0x10]
	ldr r1, [r4, #4]
	mov r2, #9
	mov r3, #0
	bl ov98_0221EBD8
_021E60F8:
	add r6, r6, #1
	add r4, #8
	cmp r6, #3
	blt _021E6090
	ldr r0, [r5]
	add r1, r7, #0
	bl ov99_021E5BB4
	cmp r0, #0
	beq _021E612E
	ldr r0, [r5]
	add r1, r7, #0
	mov r2, #3
	bl ov99_021E5BD8
	add r3, r0, #0
	mov r0, #3
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [r5, #0x10]
	mov r1, #0xc
	mov r2, #8
	bl ov98_0221ECD0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_021E612E:
	ldr r0, [r5, #0x10]
	mov r1, #0xc
	mov r2, #9
	mov r3, #0
	bl ov98_0221EBD8
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_021E6140: .word ov99_021E958C
	thumb_func_end ov99_021E607C


	thumb_func_start ov99_021E6144
ov99_021E6144: ; 0x021E6144
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r5, [r6, #0x10]
	add r7, r1, #0
	mov r4, #0
_021E614E:
	cmp r7, #0
	beq _021E6174
	add r1, r6, #0
	add r1, #0x88
	ldr r1, [r1]
	lsl r2, r4, #0x18
	lsl r1, r1, #0x18
	ldr r0, [r6]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov99_021E5C4C
	add r1, r4, #0
	add r2, r0, #0
	add r0, r5, #0
	add r1, #0xe
	bl ov98_0221EE28
	b _021E617E
_021E6174:
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0xe
	bl ov98_0221EE84
_021E617E:
	add r4, r4, #1
	cmp r4, #3
	blt _021E614E
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov99_021E6144


	thumb_func_start ov99_021E6188
ov99_021E6188: ; 0x021E6188
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r4, [r5, #0x10]
	add r6, r1, #0
	add r0, r4, #0
	bl ov98_0221EEFC
	lsl r2, r6, #0x18
	mov r1, #0
	lsr r2, r2, #0x18
	add r7, r0, #0
	bl BufferPokeathlonMedalName
	mov r0, #0
	str r0, [sp]
	mov r1, #1
	ldr r0, [r5, #0x10]
	mov r2, #4
	add r3, r1, #0
	bl ov98_0221EC08
	lsl r2, r6, #0x18
	add r0, r7, #0
	mov r1, #0
	lsr r2, r2, #0x18
	bl BufferPokeathlonCourseName
	mov r1, #3
	ldr r0, [r5, #0x10]
	add r2, r1, #0
	mov r3, #1
	bl ov98_0221EBD8
	ldr r0, [r5]
	bl ov99_021E5B70
	cmp r0, #0
	beq _021E6216
	ldr r0, [r5]
	add r1, r6, #0
	bl ov99_021E5B90
	bl ov98_0221EF64
	cmp r0, #0
	bne _021E61F2
	ldr r0, [r5, #0x10]
	mov r1, #4
	mov r2, #5
	mov r3, #1
	bl ov98_0221EBD8
	pop {r3, r4, r5, r6, r7, pc}
_021E61F2:
	cmp r0, #1
	bne _021E6204
	ldr r0, [r5, #0x10]
	mov r1, #4
	mov r2, #6
	mov r3, #1
	bl ov98_0221EBD8
	pop {r3, r4, r5, r6, r7, pc}
_021E6204:
	ldr r0, [r4, #4]
	mov r1, #0
	add r0, #0x40
	bl FillWindowPixelBuffer
	ldr r0, [r4, #4]
	add r0, #0x40
	bl ScheduleWindowCopyToVram
_021E6216:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov99_021E6188


	thumb_func_start ov99_021E6218
ov99_021E6218: ; 0x021E6218
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r1, r5, #0
	add r1, #0x88
	ldr r0, [r5]
	ldr r1, [r1]
	ldr r4, [r5, #0x10]
	bl ov99_021E5BB4
	cmp r0, #0
	beq _021E623C
	ldr r0, [r5, #0x10]
	mov r1, #0xd
	mov r2, #1
	mov r3, #0
	bl ov98_0221EBD8
	pop {r3, r4, r5, pc}
_021E623C:
	ldr r0, [r4, #4]
	mov r1, #0
	add r0, #0xd0
	bl FillWindowPixelBuffer
	ldr r0, [r4, #4]
	add r0, #0xd0
	bl ScheduleWindowCopyToVram
	pop {r3, r4, r5, pc}
	thumb_func_end ov99_021E6218


	thumb_func_start ov99_021E6250
ov99_021E6250: ; 0x021E6250
	push {r4, lr}
	add r4, r0, #0
	bl SpriteSystem_TransferOam
	ldr r0, [r4, #4]
	bl DoScheduledBgGpuUpdates
	ldr r3, _021E626C ; =0x027E0000
	ldr r1, _021E6270 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_021E626C: .word 0x027E0000
_021E6270: .word 0x00003FF8
	thumb_func_end ov99_021E6250


	thumb_func_start ov99_021E6274
ov99_021E6274: ; 0x021E6274
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x14]
	bl ov98_0221E5C0
	add r4, r0, #0
	ldr r0, [r5, #0x14]
	bl ov98_0221E5D0
	add r6, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x15
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x14
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x16
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x17
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r3, #1
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r3, #0
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #2
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #3
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #5
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #4
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #6
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #7
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #9
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #3
	str r0, [sp, #0xc]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #8
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0xa
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0xb
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r5, #0
	bl ov99_021E6400
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x14]
	ldr r1, _021E63FC ; =ov99_021E9554
	mov r2, #3
	mov r3, #0
	bl ov98_0221E8A8
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E63FC: .word ov99_021E9554
	thumb_func_end ov99_021E6274


	thumb_func_start ov99_021E6400
ov99_021E6400: ; 0x021E6400
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x14]
	bl ov98_0221E5C0
	add r6, r0, #0
	ldr r0, [r4, #0x14]
	bl ov98_0221E5D0
	ldr r7, _021E6434 ; =ov99_021E9650
	add r5, r0, #0
	mov r4, #0
_021E6418:
	lsl r2, r4, #4
	add r0, r6, #0
	add r1, r5, #0
	add r2, r7, r2
	mov r3, #1
	bl ov98_0221E784
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021E6418
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6434: .word ov99_021E9650
	thumb_func_end ov99_021E6400


	thumb_func_start ov99_021E6438
ov99_021E6438: ; 0x021E6438
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r4, _021E64DC ; =ov99_021E9840
	mov r7, #0
	add r5, r6, #0
_021E6442:
	ldr r0, [r6, #0x14]
	add r1, r4, #0
	bl ov98_0221E6E0
	mov r1, #1
	str r0, [r5, #0x18]
	bl ManagedSprite_SetAnimateFlag
	add r7, r7, #1
	add r4, #0x34
	add r5, r5, #4
	cmp r7, #0x1a
	blt _021E6442
	mov r5, #0
	add r4, r6, #0
	mov r7, #0x1f
_021E6462:
	ldr r0, [r6]
	add r1, r5, #0
	bl ov99_021E5BB4
	cmp r0, #0
	bne _021E6476
	ldr r0, [r4, #0x1c]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_021E6476:
	ldr r0, [r6]
	add r1, r5, #0
	bl ov99_021E5B90
	bl ov98_0221EF64
	cmp r0, #2
	bne _021E64A4
	lsr r1, r5, #0x1f
	lsl r0, r5, #0x1f
	sub r0, r0, r1
	ror r0, r7
	add r0, r1, r0
	ldr r0, [r4, #0x30]
	bne _021E649C
	mov r1, #5
	bl ManagedSprite_SetAnim
	b _021E64D0
_021E649C:
	mov r1, #6
	bl ManagedSprite_SetAnim
	b _021E64D0
_021E64A4:
	cmp r0, #1
	bne _021E64C8
	lsr r2, r5, #0x1f
	lsl r1, r5, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	ldr r0, [r4, #0x30]
	bne _021E64C0
	mov r1, #2
	bl ManagedSprite_SetAnim
	b _021E64D0
_021E64C0:
	mov r1, #3
	bl ManagedSprite_SetAnim
	b _021E64D0
_021E64C8:
	ldr r0, [r4, #0x30]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_021E64D0:
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #5
	blt _021E6462
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E64DC: .word ov99_021E9840
	thumb_func_end ov99_021E6438


	thumb_func_start ov99_021E64E0
ov99_021E64E0: ; 0x021E64E0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x50]
	add r4, r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x54]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x58]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x44]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x48]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x4c]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x5c]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x60]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x64]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov99_021E64E0


	thumb_func_start ov99_021E6530
ov99_021E6530: ; 0x021E6530
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5]
	add r7, r1, #0
	bl ov99_021E5B90
	str r0, [sp, #8]
	mov r4, #0
_021E6542:
	ldr r0, [r5]
	add r1, r7, #0
	bl ov99_021E5BB4
	cmp r0, #1
	bne _021E658C
	add r1, r4, #1
	lsl r1, r1, #0x18
	ldr r0, [sp, #8]
	lsr r1, r1, #0x18
	bl ov98_0221F120
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	lsl r0, r4, #2
	add r6, r5, r0
	ldr r0, [r6, #0x68]
	ldr r1, [sp, #4]
	bl ManagedSprite_SetAnim
	ldr r1, [sp, #4]
	ldr r0, [r6, #0x50]
	lsl r2, r1, #2
	ldr r1, _021E6634 ; =ov99_021E9628
	ldr r1, [r1, r2]
	bl ManagedSprite_SetAnim
	ldr r0, [r6, #0x50]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r6, #0x68]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	b _021E65A0
_021E658C:
	lsl r0, r4, #2
	add r6, r5, r0
	ldr r0, [r6, #0x50]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r6, #0x68]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_021E65A0:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021E6542
	mov r4, #0
_021E65AC:
	ldr r0, [r5]
	add r1, r7, #0
	add r2, r4, #0
	bl ov99_021E5B7C
	str r0, [sp, #0xc]
	ldr r0, [r5]
	add r1, r7, #0
	bl ov99_021E5BB4
	cmp r0, #1
	bne _021E65FA
	lsl r0, r4, #2
	add r6, r5, r0
	ldr r0, [r5, #0xc]
	ldr r1, [sp, #0xc]
	str r0, [sp]
	ldr r0, [r6, #0x44]
	mov r2, #1
	mov r3, #0
	bl ov98_0221E7E8
	ldr r0, [r6, #0x44]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x14]
	ldr r1, [r6, #0x74]
	ldr r2, [sp, #0xc]
	mov r3, #0
	bl ov98_0221E970
	ldr r0, [r6, #0x74]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	b _021E6606
_021E65FA:
	lsl r0, r4, #2
	add r0, r5, r0
	ldr r0, [r0, #0x74]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_021E6606:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021E65AC
	mov r4, #0
_021E6612:
	ldr r0, [r5]
	add r1, r7, #0
	bl ov99_021E5BB4
	add r1, r0, #0
	lsl r0, r4, #2
	add r0, r5, r0
	ldr r0, [r0, #0x5c]
	bl ManagedSprite_SetDrawFlag
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021E6612
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6634: .word ov99_021E9628
	thumb_func_end ov99_021E6530


	thumb_func_start ov99_021E6638
ov99_021E6638: ; 0x021E6638
	push {r3, r4, r5, r6, r7, lr}
	ldr r2, _021E6764 ; =gSystem
	mov r1, #0
	add r5, r0, #0
	str r1, [sp]
	add r4, r5, #0
	mov r0, #0x80
	ldr r1, [r2, #0x48]
	mov r3, #2
	add r4, #0x80
	ldrsb r6, [r5, r0]
	tst r3, r1
	beq _021E6656
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E6656:
	ldr r3, _021E6768 ; =gSystem + 0x40
	ldrh r3, [r3, #0x24]
	cmp r3, #0
	beq _021E669E
	ldr r0, _021E676C ; =ov99_021E95BC
	bl TouchscreenHitbox_FindHitboxAtTouchNew
	add r7, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r7, r0
	beq _021E66EE
	cmp r7, #5
	bne _021E6678
	mov r0, #1
	str r0, [sp]
	b _021E669A
_021E6678:
	mov r1, #0
	ldrsb r0, [r4, r1]
	cmp r0, r7
	bge _021E6682
	mov r1, #1
_021E6682:
	str r1, [r4, #4]
	ldr r0, [r5, #0x18]
	mov r1, #9
	bl ManagedSprite_SetAnim
	ldr r0, [r5, #0x18]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	ldr r0, _021E6770 ; =0x000005DC
	bl PlaySE
_021E669A:
	strb r7, [r4]
	b _021E66EE
_021E669E:
	ldr r2, [r2, #0x4c]
	mov r3, #0x10
	tst r3, r2
	bne _021E66AA
	tst r0, r2
	beq _021E66C2
_021E66AA:
	cmp r6, #5
	bge _021E66EE
	mov r0, #0
	ldrsb r0, [r4, r0]
	add r0, r0, #1
	strb r0, [r4]
	mov r0, #1
	str r0, [r4, #4]
	ldr r0, _021E6770 ; =0x000005DC
	bl PlaySE
	b _021E66EE
_021E66C2:
	mov r0, #0x20
	tst r0, r2
	bne _021E66CE
	mov r0, #0x40
	tst r0, r2
	beq _021E66E4
_021E66CE:
	cmp r6, #0
	ble _021E66EE
	mov r0, #0
	ldrsb r1, [r4, r0]
	sub r1, r1, #1
	strb r1, [r4]
	str r0, [r4, #4]
	ldr r0, _021E6770 ; =0x000005DC
	bl PlaySE
	b _021E66EE
_021E66E4:
	mov r0, #1
	tst r1, r0
	beq _021E66EE
	cmp r6, #5
	beq _021E6760
_021E66EE:
	mov r0, #0
	ldrsb r1, [r4, r0]
	cmp r1, #5
	ble _021E66FA
	mov r1, #5
	b _021E6700
_021E66FA:
	cmp r1, #0
	bge _021E6700
	add r1, r0, #0
_021E6700:
	strb r1, [r4]
	mov r1, #0
	add r0, r5, #0
	ldrsb r2, [r4, r1]
	add r0, #0x88
	str r2, [r0]
	ldrsb r0, [r4, r1]
	cmp r6, r0
	beq _021E675E
	ldr r1, _021E6774 ; =ov99_021E9574
	lsl r2, r0, #2
	ldr r3, _021E6778 ; =ov99_021E9576
	ldrsh r1, [r1, r2]
	ldrsh r2, [r3, r2]
	ldr r0, [r5, #0x18]
	bl ManagedSprite_SetPositionXY
	mov r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	ldr r0, [r5, #0x18]
	bne _021E6734
	mov r1, #0xc
	bl ManagedSprite_SetAnim
	b _021E675E
_021E6734:
	bl ManagedSprite_GetActiveAnim
	cmp r0, #9
	beq _021E6744
	ldr r0, [r5, #0x18]
	mov r1, #8
	bl ManagedSprite_SetAnim
_021E6744:
	cmp r6, #5
	bne _021E6750
	mov r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #4
	beq _021E675E
_021E6750:
	add r0, r5, #0
	mov r1, #0
	bl ov99_021E64E0
	mov r0, #1
	add r5, #0x90
	str r0, [r5]
_021E675E:
	ldr r0, [sp]
_021E6760:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6764: .word gSystem
_021E6768: .word gSystem + 0x40
_021E676C: .word ov99_021E95BC
_021E6770: .word 0x000005DC
_021E6774: .word ov99_021E9574
_021E6778: .word ov99_021E9576
	thumb_func_end ov99_021E6638


	thumb_func_start ov99_021E677C
ov99_021E677C: ; 0x021E677C
	push {r4, r5, lr}
	sub sp, #0x1c
	add r4, r0, #0
	ldr r0, _021E682C ; =FS_OVERLAY_ID(OVY_98)
	mov r1, #2
	bl HandleLoadOverlay
	add r0, r4, #0
	bl OverlayManager_GetArgs
	add r5, r0, #0
	bne _021E6798
	bl GF_AssertFail
_021E6798:
	mov r0, #3
	mov r1, #0x84
	lsl r2, r0, #0x10
	bl Heap_Create
	mov r1, #0x49
	add r0, r4, #0
	lsl r1, r1, #2
	mov r2, #0x84
	bl OverlayManager_CreateAndGetData
	mov r2, #0x49
	mov r1, #0
	lsl r2, r2, #2
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x84
	str r0, [r4, #0xc]
	add r0, r4, #0
	add r1, r5, #0
	bl ov99_021E6FD0
	bl ov98_0221F090
	add r0, r4, #0
	bl ov99_021E695C
	add r0, r4, #0
	bl ov99_021E69D8
	ldr r0, _021E6830 ; =0x0000013A
	ldr r3, _021E6834 ; =ov99_021E9ED0
	str r0, [sp]
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #4]
	mov r2, #0xf
	bl ov98_0221EABC
	add r3, sp, #4
	ldr r5, _021E6838 ; =ov99_021E9DEC
	str r0, [r4, #0x10]
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r1, r2, #0
	ldr r0, [r4, #0xc]
	mov r2, #0x43
	bl ov98_0221E5E0
	str r0, [r4, #0x14]
	add r0, r4, #0
	bl ov99_021E6A9C
	add r0, r4, #0
	bl ov99_021E6D34
	mov r0, #0
	bl ResetVisibleHardwareWindows
	mov r0, #1
	bl ResetVisibleHardwareWindows
	ldr r0, _021E683C ; =ov99_021E6938
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	mov r0, #1
	add sp, #0x1c
	pop {r4, r5, pc}
	.balign 4, 0
_021E682C: .word FS_OVERLAY_ID(OVY_98)
_021E6830: .word 0x0000013A
_021E6834: .word ov99_021E9ED0
_021E6838: .word ov99_021E9DEC
_021E683C: .word ov99_021E6938
	thumb_func_end ov99_021E677C


	thumb_func_start ov99_021E6840
ov99_021E6840: ; 0x021E6840
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, [r4]
	bl ov99_021E7060
	add r1, r4, #0
	ldr r0, [r4, #0x14]
	add r1, #0x18
	mov r2, #0x43
	bl ov98_0221E684
	ldr r0, [r4, #0x10]
	mov r1, #0xf
	bl ov98_0221EB84
	add r0, r4, #0
	bl ov99_021E6A70
	bl ov98_0221F0EC
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x84
	bl Heap_Destroy
	ldr r0, _021E6884 ; =FS_OVERLAY_ID(OVY_98)
	bl UnloadOverlayByID
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E6884: .word FS_OVERLAY_ID(OVY_98)
	thumb_func_end ov99_021E6840


	thumb_func_start ov99_021E6888
ov99_021E6888: ; 0x021E6888
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r1, #0
	bl OverlayManager_GetData
	add r5, r0, #0
	ldr r0, [r4]
	cmp r0, #4
	bhi _021E691A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E68A6: ; jump table
	.short _021E68B0 - _021E68A6 - 2 ; case 0
	.short _021E68CC - _021E68A6 - 2 ; case 1
	.short _021E68DA - _021E68A6 - 2 ; case 2
	.short _021E6906 - _021E68A6 - 2 ; case 3
	.short _021E6914 - _021E68A6 - 2 ; case 4
_021E68B0:
	mov r0, #6
	mov r1, #1
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r5, #0xc]
	add r2, r1, #0
	str r0, [sp, #8]
	mov r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #1
	str r0, [r4]
	b _021E6924
_021E68CC:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E6924
	mov r0, #2
	str r0, [r4]
	b _021E6924
_021E68DA:
	bl ov98_0221EF24
	cmp r0, #0
	beq _021E6924
	ldr r0, _021E6930 ; =0x000005DC
	bl PlaySE
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #3
	str r0, [r4]
	b _021E6924
_021E6906:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E6924
	mov r0, #4
	str r0, [r4]
	b _021E6924
_021E6914:
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, pc}
_021E691A:
	ldr r0, _021E6934 ; =_021EA5CC
	cmp r0, #0
	beq _021E6924
	bl GF_AssertFail
_021E6924:
	ldr r0, [r5, #0x14]
	bl ov98_0221E6CC
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_021E6930: .word 0x000005DC
_021E6934: .word _021EA5CC
	thumb_func_end ov99_021E6888


	thumb_func_start ov99_021E6938
ov99_021E6938: ; 0x021E6938
	push {r4, lr}
	add r4, r0, #0
	bl SpriteSystem_TransferOam
	ldr r0, [r4, #4]
	bl DoScheduledBgGpuUpdates
	ldr r3, _021E6954 ; =0x027E0000
	ldr r1, _021E6958 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_021E6954: .word 0x027E0000
_021E6958: .word 0x00003FF8
	thumb_func_end ov99_021E6938


	thumb_func_start ov99_021E695C
ov99_021E695C: ; 0x021E695C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x80
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	bl BgConfig_Alloc
	add r3, sp, #0
	ldr r4, _021E69CC ; =ov99_021E9D9C
	str r0, [r5, #4]
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r4, _021E69D0 ; =ov99_021E9E60
	add r3, sp, #0x10
	mov r2, #0xe
_021E6984:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E6984
	ldr r4, _021E69D4 ; =ov99_021E9D88
	mov r7, #0
	add r6, sp, #0x10
_021E6992:
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
	cmp r7, #4
	blt _021E6992
	ldr r1, [r5, #0xc]
	mov r0, #0xb1
	bl NARC_New
	str r0, [r5, #8]
	add sp, #0x80
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E69CC: .word ov99_021E9D9C
_021E69D0: .word ov99_021E9E60
_021E69D4: .word ov99_021E9D88
	thumb_func_end ov99_021E695C


	thumb_func_start ov99_021E69D8
ov99_021E69D8: ; 0x021E69D8
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0x40
	str r0, [sp]
	ldr r0, [r4, #0xc]
	mov r2, #0
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	mov r1, #0x38
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x39
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
	mov r1, #0x3a
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0x40
	str r0, [sp]
	ldr r0, [r4, #0xc]
	mov r1, #0x3b
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0x3c
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
	mov r1, #0x3d
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #4
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov99_021E69D8


	thumb_func_start ov99_021E6A70
ov99_021E6A70: ; 0x021E6A70
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #8]
	bl NARC_Delete
	ldr r6, _021E6A98 ; =ov99_021E9D88
	mov r4, #0
_021E6A7E:
	ldrb r1, [r6, r4]
	ldr r0, [r5, #4]
	bl FreeBgTilemapBuffer
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _021E6A7E
	ldr r0, [r5, #4]
	bl Heap_Free
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E6A98: .word ov99_021E9D88
	thumb_func_end ov99_021E6A70


	thumb_func_start ov99_021E6A9C
ov99_021E6A9C: ; 0x021E6A9C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x14]
	bl ov98_0221E5C0
	add r4, r0, #0
	ldr r0, [r5, #0x14]
	bl ov98_0221E5D0
	add r6, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x11
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r1, #0
	str r1, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x10
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x12
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0x13
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #9
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #8
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #9
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #8
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0xa
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0xb
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r3, #1
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r3, #0
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r3, #1
	str r3, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r3, #0
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #3
	str r0, [sp, #0xc]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r3, #2
	str r3, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #3
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add sp, #0x10
	pop {r4, r5, r6, pc}
	thumb_func_end ov99_021E6A9C
