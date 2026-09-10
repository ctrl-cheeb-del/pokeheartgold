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

	thumb_func_start ov95_021E5954
ov95_021E5954: ; 0x021E5954
	push {r3, lr}
	sub sp, #8
	mov r2, #2
	mov r1, #0
	ldr r0, _021E5970 ; =ov95_021E5974
	str r2, [sp]
	str r0, [sp, #4]
	mov r0, #0x46
	add r3, r1, #0
	bl GF_3DVramMan_Create
	add sp, #8
	pop {r3, pc}
	nop
_021E5970: .word ov95_021E5974
	thumb_func_end ov95_021E5954


	thumb_func_start ov95_021E5974
ov95_021E5974: ; 0x021E5974
	push {r3, lr}
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, _021E59E0 ; =0x04000008
	mov r1, #3
	ldrh r2, [r0]
	bic r2, r1
	mov r1, #1
	orr r1, r2
	strh r1, [r0]
	add r0, #0x58
	ldrh r2, [r0]
	ldr r1, _021E59E4 ; =0xFFFFCFFD
	and r2, r1
	strh r2, [r0]
	add r2, r1, #2
	ldrh r3, [r0]
	add r1, r1, #2
	and r3, r2
	mov r2, #0x10
	orr r2, r3
	strh r2, [r0]
	ldrh r3, [r0]
	ldr r2, _021E59E8 ; =0x0000CFFB
	and r3, r2
	strh r3, [r0]
	ldrh r3, [r0]
	sub r2, #0x1c
	and r3, r1
	mov r1, #8
	orr r1, r3
	strh r1, [r0]
	ldrh r1, [r0]
	and r1, r2
	strh r1, [r0]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl G3X_SetFog
	mov r0, #0
	ldr r2, _021E59EC ; =0x00007FFF
	add r1, r0, #0
	mov r3, #0x3f
	str r0, [sp]
	bl G3X_SetClearColor
	ldr r1, _021E59F0 ; =0xBFFF0000
	ldr r0, _021E59F4 ; =0x04000580
	str r1, [r0]
	pop {r3, pc}
	.balign 4, 0
_021E59E0: .word 0x04000008
_021E59E4: .word 0xFFFFCFFD
_021E59E8: .word 0x0000CFFB
_021E59EC: .word 0x00007FFF
_021E59F0: .word 0xBFFF0000
_021E59F4: .word 0x04000580
	thumb_func_end ov95_021E5974


	thumb_func_start ov95_021E59F8
ov95_021E59F8: ; 0x021E59F8
	push {r3, r4, r5, lr}
	ldr r3, _021E5A30 ; =NNS_GfdDefaultFuncAllocTexVram
	mov r0, #2
	mov r1, #0
	ldr r3, [r3]
	lsl r0, r0, #0xe
	add r2, r1, #0
	blx r3
	ldr r3, _021E5A34 ; =NNS_GfdDefaultFuncAllocPlttVram
	mov r1, #0
	add r4, r0, #0
	ldr r3, [r3]
	mov r0, #0x80
	add r2, r1, #0
	blx r3
	add r5, r0, #0
	cmp r4, #0
	bne _021E5A20
	bl GF_AssertFail
_021E5A20:
	cmp r5, #0
	bne _021E5A28
	bl GF_AssertFail
_021E5A28:
	bl sub_02014DA0
	pop {r3, r4, r5, pc}
	nop
_021E5A30: .word NNS_GfdDefaultFuncAllocTexVram
_021E5A34: .word NNS_GfdDefaultFuncAllocPlttVram
	thumb_func_end ov95_021E59F8


	thumb_func_start ov95_021E5A38
ov95_021E5A38: ; 0x021E5A38
	push {r4, r5, lr}
	sub sp, #0x8c
	add r4, r0, #0
	bl GfGfx_DisableEngineAPlanes
	ldr r5, _021E5B14 ; =ov95_021E75B4
	add r3, sp, #0x10
	mov r2, #5
_021E5A48:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E5A48
	add r0, sp, #0x10
	bl GfGfx_SetBanks
	mov r1, #6
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x18
	lsl r2, r2, #0x12
	bl MIi_CpuClear32
	mov r1, #0x62
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x14
	lsl r2, r2, #0x10
	bl MIi_CpuClear32
	mov r1, #0x19
	mov r2, #1
	mov r0, #0
	lsl r1, r1, #0x16
	lsl r2, r2, #0x12
	bl MIi_CpuClear32
	mov r1, #0x66
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x14
	lsl r2, r2, #0x10
	bl MIi_CpuClear32
	ldr r5, _021E5B18 ; =ov95_021E7538
	add r3, sp, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _021E5B1C ; =ov95_021E767C
	add r3, sp, #0x38
	mov r2, #0xa
_021E5AA8:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E5AA8
	ldr r0, [r5]
	mov r1, #1
	str r0, [r3]
	add r0, r4, #0
	add r2, sp, #0x38
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #2
	add r2, sp, #0x54
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #3
	add r2, sp, #0x70
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r1, _021E5B20 ; =0x04000008
	mov r0, #3
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #1
	orr r2, r0
	strh r2, [r1]
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	bl GfGfx_BothDispOn
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add sp, #0x8c
	pop {r4, r5, pc}
	.balign 4, 0
_021E5B14: .word ov95_021E75B4
_021E5B18: .word ov95_021E7538
_021E5B1C: .word ov95_021E767C
_021E5B20: .word 0x04000008
	thumb_func_end ov95_021E5A38
