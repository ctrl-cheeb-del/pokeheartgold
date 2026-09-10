	.include "asm/macros.inc"
	.include "overlay_68.inc"
	.include "global.inc"

	.text
	.public MoveRelearner_Exit
	.public MoveRelearner_Init
	.public MoveRelearner_Main
	.public _021E7BE8
	.public ov68_021E5A58
	.public ov68_021E5BA0
	.public ov68_021E5BC0
	.public ov68_021E5D24
	.public ov68_021E5E48
	.public ov68_021E5F68
	.public ov68_021E6078
	.public ov68_021E60D8
	.public ov68_021E614C
	.public ov68_021E61B8
	.public ov68_021E6234
	.public ov68_021E62D4
	.public ov68_021E6320
	.public ov68_021E66A0
	.public ov68_021E66F0
	.public ov68_021E67E0
	.public ov68_021E6820
	.public ov68_021E68D4
	.public ov68_021E6A2C
	.public ov68_021E6C14
	.public ov68_021E6DDC
	.public ov68_021E6EB8
	.public ov68_021E7028
	.public ov68_021E70BC
	.public ov68_021E7124
	.public ov68_021E7178
	.public ov68_021E71C4
	.public ov68_021E7224
	.public ov68_021E7288
	.public ov68_021E734C
	.public ov68_021E73A4
	.public ov68_021E7424
	.public ov68_021E74D8
	.public ov68_021E7568
	.public ov68_021E75C0
	.public ov68_021E7618
	.public ov68_021E773C
	.public ov68_021E7898
	.public ov68_021E7910
	.public ov68_021E797C
	.public ov68_021E7A18
	.public ov68_021E7AD8
	.public ov68_021E7BC8
	.public ov68_021E7BEC
	.public ov68_021E7BF8
	.public ov68_021E7C08
	.public ov68_021E7C18
	.public ov68_021E7C2C
	.public ov68_021E7C44
	.public ov68_021E7C60
	.public ov68_021E7C7C
	.public ov68_021E7C98
	.public ov68_021E7CB4
	.public ov68_021E7CD0
	.public ov68_021E7CF0
	.public ov68_021E7D14
	.public ov68_021E7D3C
	.public ov68_021E7D40
	.public ov68_021E7D64
	.public ov68_021E7DA4
	.public ov68_021E7DFC
	.public ov68_021E7E74
	.public ov68_021E5B14
	.public ov68_021E5B6C
	.public ov68_021E5CD8
	.public ov68_021E5E38
	.public ov68_021E5E94
	.public ov68_021E5EBC
	.public ov68_021E5F18
	.public ov68_021E5F50
	.public ov68_021E6058
	.public ov68_021E61A0
	.public ov68_021E61EC
	.public ov68_021E6204
	.public ov68_021E6678
	.public ov68_021E68C4
	.public ov68_021E6BEC
	.public ov68_021E6BFC
	.public ov68_021E6C74
	.public ov68_021E6C8C
	.public ov68_021E6CD8
	.public ov68_021E6D00
	.public ov68_021E6D20
	.public ov68_021E6D40
	.public ov68_021E6D4C
	.public ov68_021E6D58
	.public ov68_021E6D64
	.public ov68_021E6D80
	.public ov68_021E6D9C
	.public ov68_021E6DB8
	.public ov68_021E6DD0
	.public ov68_021E6E84
	.public ov68_021E7388
	.public ov68_021E74C0
	.public ov68_021E7604
	.public ov68_021E7614
	.public ov68_021E7A90
	.public ov68_021E7AB4
	.public ov68_021E7B6C
	.public ov68_021E7B8C
	.public ov68_021E7B94

	thumb_func_start ov68_021E6EB8
ov68_021E6EB8: ; 0x021E6EB8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0
	add r6, r1, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _021E7014 ; =0x0000B8A8
	mov r1, #0x47
	lsl r1, r1, #2
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r6, #0
	mov r3, #6
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _021E7018 ; =0x0000B8A9
	mov r1, #0x47
	lsl r1, r1, #2
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r6, #0
	mov r3, #0xb
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	ldr r4, _021E701C ; =0x0000B8AB
	add r7, r4, #4
_021E6F00:
	cmp r4, r7
	str r4, [sp]
	bhs _021E6F1C
	mov r0, #0x47
	mov r1, #0x12
	lsl r0, r0, #2
	lsl r1, r1, #4
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	mov r2, #2
	mov r3, #0
	bl sub_020776B8
	b _021E6F30
_021E6F1C:
	mov r0, #0x47
	mov r1, #0x12
	lsl r0, r0, #2
	lsl r1, r1, #4
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	mov r2, #1
	mov r3, #0
	bl sub_020776B8
_021E6F30:
	ldr r0, _021E7020 ; =0x0000B8B2
	add r4, r4, #1
	cmp r4, r0
	bls _021E6F00
	mov r1, #0x47
	sub r0, #8
	lsl r1, r1, #2
	str r0, [sp]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #2
	mov r3, #0
	bl sub_02077834
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r0, _021E7014 ; =0x0000B8A8
	mov r1, #0x47
	lsl r1, r1, #2
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r6, #0
	mov r3, #5
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r1, #0x47
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	ldr r3, _021E7018 ; =0x0000B8A9
	mov r2, #2
	bl sub_020776EC
	mov r1, #0x47
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	ldr r3, _021E7024 ; =0x0000B8AA
	mov r2, #1
	bl sub_020776EC
	mov r0, #0
	str r0, [sp]
	ldr r0, _021E7014 ; =0x0000B8A8
	mov r1, #0x47
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r6, #0
	mov r3, #7
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _021E7018 ; =0x0000B8A9
	mov r1, #0x47
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r6, #0
	mov r3, #0xa
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _021E7014 ; =0x0000B8A8
	mov r1, #0x47
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r6, #0
	mov r3, #8
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _021E7018 ; =0x0000B8A9
	mov r1, #0x47
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r6, #0
	mov r3, #9
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r1, #0x47
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r2, _021E7024 ; =0x0000B8AA
	ldr r1, [r5, r1]
	add r3, r2, #0
	bl sub_0207775C
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7014: .word 0x0000B8A8
_021E7018: .word 0x0000B8A9
_021E701C: .word 0x0000B8AB
_021E7020: .word 0x0000B8B2
_021E7024: .word 0x0000B8AA
	thumb_func_end ov68_021E6EB8


	thumb_func_start ov68_021E7028
ov68_021E7028: ; 0x021E7028
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r2, #0
	ldrb r0, [r0, #0x18]
	cmp r0, #0
	bne _021E7044
	add r0, r1, #0
	mov r1, #3
	bl GetMoveAttr
	add r6, r0, #0
	b _021E7050
_021E7044:
	add r0, r1, #0
	mov r1, #0xb
	bl GetMoveAttr
	add r6, r0, #0
	add r6, #0x12
_021E7050:
	bl sub_020776B4
	add r7, r0, #0
	add r0, r6, #0
	bl sub_02077678
	add r3, r0, #0
	mov r0, #1
	str r0, [sp]
	ldr r0, _021E70B8 ; =0x0000B8AB
	mov r1, #0x47
	add r0, r4, r0
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r7, #0
	bl SpriteSystem_ReplaceCharResObj
	cmp r4, #4
	bhs _021E709A
	add r0, r6, #0
	bl sub_0207769C
	add r1, r0, #0
	add r0, r4, #4
	lsl r0, r0, #2
	add r2, r5, r0
	mov r0, #0x49
	lsl r0, r0, #2
	ldr r0, [r2, r0]
	add r1, r1, #4
	bl ManagedSprite_SetPaletteOverride
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021E709A:
	add r0, r6, #0
	bl sub_0207769C
	add r1, r0, #0
	add r0, r4, #4
	lsl r0, r0, #2
	add r2, r5, r0
	mov r0, #0x49
	lsl r0, r0, #2
	ldr r0, [r2, r0]
	bl ManagedSprite_SetPaletteOverride
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E70B8: .word 0x0000B8AB
	thumb_func_end ov68_021E7028


	thumb_func_start ov68_021E70BC
ov68_021E70BC: ; 0x021E70BC
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r4, #0
	mov r7, #0x28
	add r5, r6, #0
_021E70C6:
	mov r0, #0x4d
	lsl r0, r0, #2
	lsl r2, r7, #0x10
	ldr r0, [r5, r0]
	mov r1, #0x16
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	ldr r0, [r6]
	ldrh r0, [r0, #0x16]
	add r1, r0, r4
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r0, [r6, r0]
	cmp r1, r0
	blo _021E70F4
	mov r0, #0x4d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _021E7116
_021E70F4:
	mov r0, #0x4d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r2, [r6]
	add r0, r6, #0
	ldr r1, [r2, #0x10]
	ldrh r2, [r2, #0x16]
	add r2, r2, r4
	lsl r2, r2, #1
	ldrh r1, [r1, r2]
	lsl r2, r4, #0x10
	lsr r2, r2, #0x10
	bl ov68_021E7028
_021E7116:
	add r4, r4, #1
	add r7, #0x20
	add r5, r5, #4
	cmp r4, #4
	blo _021E70C6
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov68_021E70BC


	thumb_func_start ov68_021E7124
ov68_021E7124: ; 0x021E7124
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	add r0, r1, #0
	mov r1, #1
	bl GetMoveAttr
	add r4, r0, #0
	bl sub_02077830
	add r6, r0, #0
	add r0, r4, #0
	bl sub_02077800
	add r3, r0, #0
	mov r0, #1
	str r0, [sp]
	ldr r0, _021E7174 ; =0x0000B8AA
	mov r1, #0x47
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl SpriteSystem_ReplaceCharResObj
	add r0, r4, #0
	bl sub_02077818
	add r1, r0, #0
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r1, #4
	bl ManagedSprite_SetPaletteOverride
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_021E7174: .word 0x0000B8AA
	thumb_func_end ov68_021E7124


	thumb_func_start ov68_021E7178
ov68_021E7178: ; 0x021E7178
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r4, r1, #0
	bl ov68_021E6DDC
	add r0, r6, #0
	add r1, r4, #0
	bl ov68_021E6EB8
	ldr r4, _021E71C0 ; =ov68_021E7E74
	mov r7, #0
	add r5, r6, #0
_021E7190:
	mov r0, #0x47
	mov r1, #0x12
	lsl r0, r0, #2
	lsl r1, r1, #4
	ldr r0, [r6, r0]
	ldr r1, [r6, r1]
	add r2, r4, #0
	bl SpriteSystem_NewSprite
	mov r1, #0x49
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetAnimateFlag
	add r7, r7, #1
	add r4, #0x34
	add r5, r5, #4
	cmp r7, #0xc
	blo _021E7190
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E71C0: .word ov68_021E7E74
	thumb_func_end ov68_021E7178


	thumb_func_start ov68_021E71C4
ov68_021E71C4: ; 0x021E71C4
	push {r4, r5, lr}
	sub sp, #0x1c
	ldr r5, _021E721C ; =ov68_021E7BEC
	add r4, r0, #0
	add r2, r1, #0
	ldmia r5!, {r0, r1}
	add r3, sp, #0x10
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, sp, #8
	str r0, [r3]
	mov r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	add r0, r2, #0
	bl Camera_New
	str r0, [r4]
	mov r1, #1
	str r1, [sp]
	ldr r0, [r4]
	ldr r3, _021E7220 ; =0x000005C1
	str r0, [sp, #4]
	add r0, sp, #0x10
	lsl r1, r1, #0x10
	add r2, sp, #8
	bl Camera_Init_FromPosDistanceAndAngle
	mov r1, #0x19
	ldr r2, [r4]
	mov r0, #0
	lsl r1, r1, #0xe
	bl Camera_SetPerspectiveClippingPlane
	ldr r0, [r4]
	bl Camera_ClearFixedTarget
	ldr r0, [r4]
	bl Camera_SetStaticPtr
	add sp, #0x1c
	pop {r4, r5, pc}
	.balign 4, 0
_021E721C: .word ov68_021E7BEC
_021E7220: .word 0x000005C1
	thumb_func_end ov68_021E71C4


	thumb_func_start ov68_021E7224
ov68_021E7224: ; 0x021E7224
	push {r4, r5, r6, lr}
	sub sp, #0x20
	add r5, r0, #0
	add r4, r1, #0
	add r0, r2, #0
	bl PokepicManager_Create
	str r0, [r5, #4]
	add r0, sp, #0x10
	add r1, r4, #0
	mov r2, #2
	bl GetPokemonSpriteCharAndPlttNarcIds
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [r5, #4]
	add r1, sp, #0x10
	mov r2, #0x34
	mov r3, #0x80
	bl PokepicManager_CreatePokepic
	str r0, [r5, #0x18]
	add r0, r4, #0
	mov r1, #5
	mov r2, #0
	bl GetMonData
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	add r1, r0, #0
	add r0, r6, #0
	mov r2, #0x1c
	bl GetMonBaseStat_HandleAlternateForm
	add r3, r0, #0
	mov r2, #1
	ldr r0, [r5, #0x18]
	mov r1, #0x23
	eor r2, r3
	bl Pokepic_SetAttr
	add sp, #0x20
	pop {r4, r5, r6, pc}
	thumb_func_end ov68_021E7224


	thumb_func_start ov68_021E7288
ov68_021E7288: ; 0x021E7288
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bl NNS_G3dInit
	bl G3X_Init
	bl G3X_InitMtxStack
	ldr r1, _021E7330 ; =0x04000060
	ldr r2, _021E7334 ; =0xFFFFCFFD
	ldrh r0, [r1]
	and r0, r2
	strh r0, [r1]
	ldrh r3, [r1]
	ldr r0, _021E7338 ; =0x0000CFFB
	and r3, r0
	strh r3, [r1]
	add r3, r2, #2
	ldrh r5, [r1]
	add r2, r2, #2
	sub r0, #0x1c
	and r5, r3
	mov r3, #8
	orr r3, r5
	strh r3, [r1]
	ldrh r3, [r1]
	and r3, r2
	mov r2, #0x10
	orr r2, r3
	strh r2, [r1]
	ldrh r2, [r1]
	and r0, r2
	strh r0, [r1]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl G3X_SetFog
	mov r0, #0
	ldr r2, _021E733C ; =0x00007FFF
	add r1, r0, #0
	mov r3, #0x3f
	str r0, [sp]
	bl G3X_SetClearColor
	ldr r1, _021E7340 ; =0x04000540
	mov r0, #2
	str r0, [r1]
	ldr r0, _021E7344 ; =0xBFFF0000
	mov r2, #0x1c
	str r0, [r1, #0x40]
	mov r0, #0x55
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl MI_CpuFill8
	mov r0, #0x55
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0x42
	bl ov68_021E71C4
	ldr r1, [r4]
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r1, [r1]
	add r0, r4, r0
	mov r2, #0x42
	bl ov68_021E7224
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	ldr r1, _021E7348 ; =0x04000008
	mov r0, #3
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #1
	orr r0, r2
	strh r0, [r1]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E7330: .word 0x04000060
_021E7334: .word 0xFFFFCFFD
_021E7338: .word 0x0000CFFB
_021E733C: .word 0x00007FFF
_021E7340: .word 0x04000540
_021E7344: .word 0xBFFF0000
_021E7348: .word 0x04000008
	thumb_func_end ov68_021E7288


	thumb_func_start ov68_021E734C
ov68_021E734C: ; 0x021E734C
	push {r4, lr}
	add r4, r0, #0
	bl Thunk_G3X_Reset
	bl Camera_PushLookAtToNNSGlb
	ldr r2, _021E7380 ; =0x04000440
	mov r3, #0
	add r1, r2, #0
	str r3, [r2]
	add r1, #0x14
	str r3, [r1]
	mov r0, #2
	str r0, [r2]
	str r3, [r1]
	bl NNS_G3dGlbFlushP
	bl NNS_G2dSetupSoftwareSpriteCamera
	ldr r0, [r4, #4]
	bl PokepicManager_DrawAll
	ldr r0, _021E7384 ; =0x04000540
	mov r1, #1
	str r1, [r0]
	pop {r4, pc}
	.balign 4, 0
_021E7380: .word 0x04000440
_021E7384: .word 0x04000540
	thumb_func_end ov68_021E734C
