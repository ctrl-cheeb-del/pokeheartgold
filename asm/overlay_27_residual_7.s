	.include "asm/macros.inc"
	.include "overlay_27.inc"
	.include "global.inc"

	.text
	.public _0225CEBC
	.public ov27_02259F80
	.public ov27_0225A19C
	.public ov27_0225A320
	.public ov27_0225A4D0
	.public ov27_0225A530
	.public ov27_0225A594
	.public ov27_0225A61C
	.public ov27_0225A690
	.public ov27_0225A714
	.public ov27_0225A7FC
	.public ov27_0225A89C
	.public ov27_0225A8E8
	.public ov27_0225A9C0
	.public ov27_0225AA7C
	.public ov27_0225AAD4
	.public ov27_0225AC00
	.public ov27_0225AD0C
	.public ov27_0225AEA8
	.public ov27_0225B010
	.public ov27_0225B360
	.public ov27_0225B398
	.public ov27_0225B404
	.public ov27_0225B4D8
	.public ov27_0225B630
	.public ov27_0225BB6C
	.public ov27_0225BC34
	.public ov27_0225BC84
	.public ov27_0225BCE8
	.public ov27_0225BD50
	.public ov27_0225BDFC
	.public ov27_0225BED8
	.public ov27_0225BF84
	.public ov27_0225BFCC
	.public ov27_0225C088
	.public ov27_0225C10C
	.public ov27_0225C170
	.public ov27_0225C1AC
	.public ov27_0225C1EC
	.public ov27_0225C250
	.public ov27_0225C398
	.public ov27_0225C434
	.public ov27_0225C4AC
	.public ov27_0225C540
	.public ov27_0225C618
	.public ov27_0225C72C
	.public ov27_0225C80C
	.public ov27_0225C9F8
	.public ov27_0225CA14
	.public ov27_0225CA98
	.public ov27_0225CD18
	.public ov27_0225CD94
	.public ov27_0225CEAC
	.public ov27_0225CEC4
	.public ov27_0225CECC
	.public ov27_0225CED8
	.public ov27_0225CEEC
	.public ov27_0225CEF0
	.public ov27_0225CEF4
	.public ov27_0225CF10
	.public ov27_0225CF3C
	.public ov27_0225CF68
	.public ov27_0225CF94
	.public ov27_0225CFC8
	.public ov27_0225D000
	.public ov27_0225D01C
	.public ov27_0225D038
	.public ov27_0225D05C
	.public ov27_0225D074
	.public ov27_0225D0B4
	.public ov27_0225D108
	.public ov27_0225D110
	.public ov27_0225D118
	.public ov27_0225D11A
	.public ov27_0225D120
	.public ov27_0225D12C
	.public ov27_0225D138
	.public ov27_0225D144
	.public ov27_0225D154
	.public ov27_0225D164
	.public ov27_0225D174
	.public ov27_0225D188
	.public ov27_0225D19C
	.public ov27_0225D1B4
	.public ov27_0225D1CC
	.public ov27_0225D1E4
	.public ov27_0225D200
	.public ov27_0225D21C
	.public ov27_0225D23C
	.public ov27_0225D25C
	.public ov27_0225D27C
	.public ov27_0225D2A0
	.public ov27_0225D2C8
	.public ov27_0225D2F8
	.public ov27_0225D330
	.public ov27_0225D370
	.public ov27_0225D38C
	.public ov27_0225D3A8
	.public ov27_0225D3C4
	.public ov27_0225D3C5
	.public ov27_0225D3C6
	.public ov27_0225D480
	.public ov27_0225D49C
	.public ov27_0225D4B8
	.public ov27_0225D4D4

	.public ov27_0225A2C8
	.public ov27_0225A2CC
	.public ov27_0225A2EC
	.public ov27_0225A468
	.public ov27_0225A48C
	.public ov27_0225A4B8
	.public ov27_0225A66C
	.public ov27_0225A7B0
	.public ov27_0225A7DC
	.public ov27_0225A86C
	.public ov27_0225AA60
	.public ov27_0225AE8C
	.public ov27_0225B4AC
	.public ov27_0225BB38
	.public ov27_0225BD44
	.public ov27_0225BDAC
	.public ov27_0225BDC8
	.public ov27_0225BDDC
	.public ov27_0225BEB0
	.public ov27_0225C01C
	.public ov27_0225C044
	.public ov27_0225C06C
	.public ov27_0225C0E0
	.public ov27_0225C238
	.public ov27_0225C248
	.public ov27_0225C24C
	.public ov27_0225C418
	.public ov27_0225C41C
	.public ov27_0225C5E4
	.public ov27_0225C6F8
	.public ov27_0225C8D0
	.public ov27_0225C914
	.public ov27_0225C930
	.public ov27_0225C944
	.public ov27_0225C94C
	.public ov27_0225C988
	.public ov27_0225C994
	.public ov27_0225C9CC
	.public ov27_0225C9E4
	.public ov27_0225CA68
	.public ov27_0225CC90
	.public ov27_0225CCBC
	.public ov27_0225CCE0
	.public ov27_0225CD74

	thumb_func_start ov27_0225AA7C
ov27_0225AA7C: ; 0x0225AA7C
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r7, _0225AACC ; =0x00000514
	mov r4, #0
	add r5, r6, #0
_0225AA86:
	mov r0, #0x39
	add r1, r6, r4
	lsl r0, r0, #4
	ldrb r1, [r1, r7]
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #7
	blt _0225AA86
	ldr r0, _0225AAD0 ; =0x0000050C
	mov r1, #1
	strb r1, [r6, r0]
	add r0, r6, #0
	bl ov27_0225BDC8
	cmp r0, #0
	bne _0225AACA
	mov r0, #0xef
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0xf1
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, _0225AAD0 ; =0x0000050C
	mov r1, #0
	strb r1, [r6, r0]
_0225AACA:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225AACC: .word 0x00000514
_0225AAD0: .word 0x0000050C
	thumb_func_end ov27_0225AA7C


	thumb_func_start ov27_0225AAD4
ov27_0225AAD4: ; 0x0225AAD4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, _0225ABF4 ; =0x00000514
	mov r1, #7
	add r0, r5, r0
	bl ov27_0225AA60
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x3f
	lsl r0, r0, #4
	add r0, r5, r0
	ldr r4, _0225ABF8 ; =ov27_0225CF10
	mov r6, #0
	add r7, r5, #0
	str r0, [sp, #0xc]
_0225AAF6:
	ldr r0, [r5, #0x10]
	add r1, r6, #0
	bl FieldSystem_ShouldDrawStartMenuIcon
	cmp r0, #1
	bne _0225AB62
	ldr r0, _0225ABF4 ; =0x00000514
	add r1, r5, r6
	ldrb r0, [r1, r0]
	str r1, [sp]
	cmp r0, #0
	bne _0225AB62
	ldrh r0, [r4]
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0x39
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldrh r0, [r4]
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0x39
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	ldrh r1, [r4, #2]
	bl Sprite_SetAnimCtrlSeq
	ldrb r0, [r4, #4]
	lsl r1, r0, #4
	ldr r0, [sp, #0xc]
	add r0, r0, r1
	bl CopyWindowToVram
	ldr r1, [sp]
	ldr r0, _0225ABF4 ; =0x00000514
	mov r2, #1
	strb r2, [r1, r0]
	add r1, r2, #0
	sub r0, #0xa4
	strb r1, [r7, r0]
	ldr r0, [r5, #0x10]
	add r1, r0, #0
	add r1, #0xd2
	ldrb r2, [r1]
	mov r1, #0x80
	add r0, #0xd2
	orr r1, r2
	strb r1, [r0]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
_0225AB62:
	add r6, r6, #1
	add r4, r4, #6
	add r7, #8
	cmp r6, #7
	blt _0225AAF6
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _0225AB8E
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _0225AB8E
	mov r0, #0xf2
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x3e
	lsl r0, r0, #4
	add r0, r5, r0
	bl CopyWindowToVram
_0225AB8E:
	ldr r1, [sp, #4]
	ldr r0, [sp, #8]
	cmp r1, r0
	beq _0225ABB2
	ldr r0, [r5, #0x10]
	mov r1, #0
	add r0, #0xd3
	strb r1, [r0]
	ldr r1, [r5, #0x10]
	add r0, r5, #0
	add r1, #0xd3
	ldrb r1, [r1]
	bl ov27_0225C1AC
	str r0, [r5, #0x14]
	add r0, r5, #0
	bl ov27_0225C1EC
_0225ABB2:
	add r0, r5, #0
	bl ov27_0225BDC8
	cmp r0, #1
	bne _0225ABEE
	ldr r0, _0225ABFC ; =0x0000050C
	ldrb r0, [r5, r0]
	cmp r0, #0
	bne _0225ABEE
	mov r0, #0xef
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0xf1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0xef
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0xa
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _0225ABFC ; =0x0000050C
	mov r1, #1
	strb r1, [r5, r0]
_0225ABEE:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225ABF4: .word 0x00000514
_0225ABF8: .word ov27_0225CF10
_0225ABFC: .word 0x0000050C
	thumb_func_end ov27_0225AAD4


	thumb_func_start ov27_0225AC00
ov27_0225AC00: ; 0x0225AC00
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp, #0x14]
	add r4, r1, #0
	mov r0, #0xc
	mul r4, r0
	mov r0, #0
	str r0, [sp]
	ldr r1, _0225ACFC ; =ov27_0225CEF0
	str r0, [sp, #4]
	mov r0, #1
	add r5, r2, #0
	str r0, [sp, #8]
	mov r0, #8
	add r6, r3, #0
	str r0, [sp, #0xc]
	ldr r1, [r1, r4]
	ldr r2, [sp, #0x14]
	mov r0, #0xe
	mov r3, #4
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	ldr r1, _0225AD00 ; =ov27_0225CEF4
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #8
	str r0, [sp, #0xc]
	ldr r1, [r1, r4]
	ldr r2, [sp, #0x14]
	mov r0, #0xe
	mov r3, #4
	bl GfGfxLoader_LoadScrnData
	mov r0, #2
	ldr r1, _0225AD04 ; =ov27_0225CEEC
	lsl r0, r0, #8
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	ldr r1, [r1, r4]
	mov r0, #0xe
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPal
	mov r0, #0x14
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	mov r0, #0xd2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	add r1, r5, #0
	mov r2, #5
	mov r3, #0x18
	bl AddWindowParameterized
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	mov r0, #0xe2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	add r1, r6, #0
	mov r2, #5
	mov r3, #9
	bl AddWindowParameterized
	add r0, r6, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r4, _0225AD08 ; =ov27_0225D074
	ldr r5, [sp, #0x30]
	mov r7, #0
	mov r6, #0xf6
_0225ACB8:
	ldr r0, [r4, #4]
	add r1, r5, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #9
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	lsl r0, r6, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r3, [r4]
	ldr r0, [sp, #0x14]
	lsl r3, r3, #0x18
	mov r2, #5
	lsr r3, r3, #0x18
	bl AddWindowParameterized
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r7, r7, #1
	add r6, #0x12
	add r4, #8
	add r5, #0x10
	cmp r7, #8
	blt _0225ACB8
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225ACFC: .word ov27_0225CEF0
_0225AD00: .word ov27_0225CEF4
_0225AD04: .word ov27_0225CEEC
_0225AD08: .word ov27_0225D074
	thumb_func_end ov27_0225AC00


	thumb_func_start ov27_0225AD0C
ov27_0225AD0C: ; 0x0225AD0C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r1, r5, #0
	mov r0, #0x10
	add r1, #0x1c
	mov r2, #8
	bl G2dRenderer_Init
	str r0, [r5, #0x18]
	add r0, r5, #0
	mov r2, #1
	add r0, #0x1c
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	mov r7, #0x51
	mov r6, #0
	add r4, r5, #0
	lsl r7, r7, #2
_0225AD36:
	mov r0, #0xb
	add r1, r6, #0
	mov r2, #8
	bl Create2DGfxResObjMan
	str r0, [r4, r7]
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #4
	blt _0225AD36
	mov r0, #0x55
	lsl r0, r0, #2
	mov r4, #0
	add r6, r5, r0
_0225AD52:
	ldr r0, [r5, #0x10]
	ldr r0, [r0, #0xc]
	bl Save_PlayerData_GetProfile
	bl PlayerProfile_GetTrainerGender
	add r7, r0, #0
	ldr r0, [r5, #0x10]
	ldr r0, [r0, #0xc]
	bl Save_Bag_Get
	add r1, r4, #0
	add r1, #0x64
	str r1, [sp]
	str r7, [sp, #4]
	str r0, [sp, #8]
	ldr r0, _0225AE84 ; =0x0000051C
	mov r1, #0x51
	ldr r0, [r5, r0]
	lsl r1, r1, #2
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x1c
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x10]
	add r1, r5, r1
	add r2, r6, #0
	add r3, r4, #0
	bl ov27_0225AEA8
	add r4, r4, #1
	add r6, #0x10
	cmp r4, #0xb
	blt _0225AD52
	mov r1, #0x64
	str r1, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #8
	add r1, #0xe8
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xe
	mov r2, #0x10
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x57
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r1, #0x64
	str r1, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #8
	add r1, #0xec
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xe
	mov r2, #0x11
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x16
	lsl r1, r1, #4
	str r0, [r5, r1]
	mov r1, #0x65
	str r1, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #8
	add r1, #0xe7
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xe
	mov r2, #0x44
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5b
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r1, #0x65
	str r1, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #8
	add r1, #0xeb
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xe
	mov r2, #0x45
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x17
	lsl r1, r1, #4
	str r0, [r5, r1]
	mov r1, #0x66
	str r1, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #8
	add r1, #0xe6
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xe
	mov r2, #0x36
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5f
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r1, #0x66
	str r1, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #8
	add r1, #0xea
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xe
	mov r2, #0x37
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #6
	lsl r1, r1, #6
	str r0, [r5, r1]
	mov r0, #0xe
	add r1, r0, #0
	add r2, sp, #0x10
	mov r3, #8
	bl GfGfxLoader_GetPlttData
	add r4, r0, #0
	ldr r0, [sp, #0x10]
	mov r1, #0x40
	ldr r0, [r0, #0xc]
	bl DC_FlushRange
	ldr r0, [sp, #0x10]
	ldr r1, _0225AE88 ; =0x000004CC
	ldr r0, [r0, #0xc]
	add r1, r5, r1
	mov r2, #0x40
	bl MIi_CpuCopyFast
	add r0, r4, #0
	bl Heap_Free
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0225AE84: .word 0x0000051C
_0225AE88: .word 0x000004CC
	thumb_func_end ov27_0225AD0C
