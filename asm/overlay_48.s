	.include "asm/macros.inc"
	.include "overlay_48.inc"
	.include "global.inc"

	.text
	.public _0225B164
	.public ov48_02258800
	.public ov48_02258920
	.public ov48_022589FC
	.public ov48_02258A80
	.public ov48_02258B7C
	.public ov48_02258BF4
	.public ov48_02258C6C
	.public ov48_02258CE4
	.public ov48_02258D54
	.public ov48_02258F0C
	.public ov48_02258F64
	.public ov48_0225909C
	.public ov48_02259130
	.public ov48_02259188
	.public ov48_022591D8
	.public ov48_0225932C
	.public ov48_022593B4
	.public ov48_022593F4
	.public ov48_02259464
	.public ov48_022594F0
	.public ov48_02259650
	.public ov48_02259688
	.public ov48_02259750
	.public ov48_02259798
	.public ov48_022598EC
	.public ov48_022599A0
	.public ov48_02259A68
	.public ov48_02259B10
	.public ov48_02259BC0
	.public ov48_02259C78
	.public ov48_02259D00
	.public ov48_02259DA0
	.public ov48_02259EAC
	.public ov48_02259F48
	.public ov48_02259F8C
	.public ov48_0225A00C
	.public ov48_0225A108
	.public ov48_0225A158
	.public ov48_0225A20C
	.public ov48_0225A2A0
	.public ov48_0225A338
	.public ov48_0225A354
	.public ov48_0225A428
	.public ov48_0225A43C
	.public ov48_0225A4C0
	.public ov48_0225A57C
	.public ov48_0225A5C4
	.public ov48_0225A680
	.public ov48_0225A6DC
	.public ov48_0225A768
	.public ov48_0225A790
	.public ov48_0225A868
	.public ov48_0225A894
	.public ov48_0225A928
	.public ov48_0225A95C
	.public ov48_0225AA38
	.public ov48_0225AA5C
	.public ov48_0225AAAC
	.public ov48_0225AC34
	.public ov48_0225ACAC
	.public ov48_0225ACD8
	.public ov48_0225AD54
	.public ov48_0225ADBC
	.public ov48_0225ADF8
	.public ov48_0225AEDC
	.public ov48_0225AFB4
	.public ov48_0225B010
	.public ov48_0225B16C
	.public ov48_0225B178
	.public ov48_0225B184
	.public ov48_0225B190
	.public ov48_0225B1A0
	.public ov48_0225B1B0
	.public ov48_0225B1C4
	.public ov48_0225B1D8
	.public ov48_0225B1EC
	.public ov48_0225B210
	.public ov48_0225B238
	.public ov48_0225B239
	.public ov48_0225B268
	.public ov48_0225B2A4
	.public ov48_0225B330
	.public ov48_02259030
	.public ov48_02259050
	.public ov48_02259090
	.public ov48_022592E0
	.public ov48_022594A8
	.public ov48_022594D0
	.public ov48_022594DC
	.public ov48_02259724
	.public ov48_02259788
	.public ov48_02259824
	.public ov48_02259868
	.public ov48_02259874
	.public ov48_022598AC
	.public ov48_022598BC
	.public ov48_022598CC
	.public ov48_022598DC
	.public ov48_02259984
	.public ov48_02259AD0
	.public ov48_02259B3C
	.public ov48_02259B68
	.public ov48_02259B84
	.public ov48_02259BA0
	.public ov48_02259BBC
	.public ov48_02259C38
	.public ov48_02259C44
	.public ov48_02259C4C
	.public ov48_02259CFC
	.public ov48_02259D94
	.public ov48_02259E5C
	.public ov48_02259E78
	.public ov48_02259E90
	.public ov48_02259F14
	.public ov48_02259FEC
	.public ov48_0225A1D0
	.public ov48_0225A1EC
	.public ov48_0225A244
	.public ov48_0225A288
	.public ov48_0225A294
	.public ov48_0225A2EC
	.public ov48_0225A30C
	.public ov48_0225A41C
	.public ov48_0225A430
	.public ov48_0225A4B4
	.public ov48_0225A634
	.public ov48_0225A650
	.public ov48_0225A668
	.public ov48_0225A834
	.public ov48_0225A858
	.public ov48_0225AA50
	.public ov48_0225AD38
	.public ov48_0225AE3C
	.public ov48_0225AE58
	.public ov48_0225AE5C
	.public ov48_0225AE60
	.public ov48_0225AEA8
	.public ov48_0225AEC4
	.public ov48_0225B038
	.public ov48_0225B050
	.public ov48_0225B068
	.public ov48_0225B0A4
	.public ov48_0225B0C4
	.public ov48_0225B0D4
	.public ov48_0225B0E0
	.public ov48_0225B108
	.public ov48_0225B13C

	thumb_func_start ov48_02258800
ov48_02258800: ; 0x02258800
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r0, #0
	bl OverlayManager_GetArgs
	mov r2, #5
	add r5, r0, #0
	mov r0, #3
	mov r1, #0x70
	lsl r2, r2, #0x10
	bl Heap_Create
	ldr r1, _0225890C ; =0x0000C724
	add r0, r4, #0
	mov r2, #0x70
	bl OverlayManager_CreateAndGetData
	ldr r2, _0225890C ; =0x0000C724
	mov r1, #0
	add r4, r0, #0
	bl memset
	ldr r0, [r5, #4]
	bl Save_WiFiHistory_Get
	str r0, [r4, #0xc]
	ldr r0, [r5, #4]
	bl Save_PlayerData_GetOptionsAddr
	str r0, [r4, #0x10]
	ldr r0, [r4, #0xc]
	bl WifiHistory_GetPlayerCountry
	str r0, [r4, #0x14]
	ldr r0, [r4, #0xc]
	bl WiFiHistory_GetPlayerRegion
	str r0, [r4, #0x18]
	ldr r0, [r5, #8]
	add r1, r5, #0
	str r0, [r4, #0x1c]
	add r0, r4, #0
	bl ov48_022593F4
	add r0, r4, #0
	ldr r1, [r4, #0x10]
	add r0, #0x20
	mov r2, #0x70
	bl ov48_02259464
	mov r0, #0x5e
	lsl r0, r0, #2
	add r1, r4, #0
	add r0, r4, r0
	add r1, #0x20
	mov r2, #0x70
	bl ov48_02259824
	mov r0, #0x5a
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0x70
	bl ov48_0225B068
	mov r0, #0x70
	str r0, [sp, #4]
	mov r2, sp
	ldr r1, [r4, #4]
	ldr r0, [r4, #8]
	sub r2, r2, #4
	str r1, [r2]
	str r0, [r2, #4]
	mov r0, #0x89
	ldr r3, [r2]
	lsl r0, r0, #2
	add r2, r4, #0
	ldr r1, [r5]
	add r0, r4, r0
	add r2, #0x20
	bl ov48_022598EC
	add r3, r4, #4
	ldr r0, _02258910 ; =0x0000C3CC
	ldmia r3!, {r1, r2}
	add r0, r4, r0
	mov r3, #0x70
	bl ov48_02259BC0
	ldr r0, _02258914 ; =0x0000C3E0
	mov r2, #0x5a
	add r1, r4, #0
	lsl r2, r2, #2
	add r0, r4, r0
	add r1, #0x20
	add r2, r4, r2
	mov r3, #0x70
	bl ov48_02259D00
	mov r2, #0x70
	str r2, [sp]
	mov r0, #0xc7
	lsl r0, r0, #8
	add r1, r4, #0
	add r2, #0xf8
	ldr r3, [r5, #4]
	add r0, r4, r0
	add r1, #0x20
	add r2, r4, r2
	bl ov48_02259EAC
	ldr r0, _02258918 ; =0x0000C40C
	mov r2, #0x5a
	add r1, r4, #0
	lsl r2, r2, #2
	add r0, r4, r0
	add r1, #0x20
	add r2, r4, r2
	mov r3, #0x70
	bl ov48_0225A00C
	add r0, r4, #0
	add r1, r5, #0
	bl ov48_02259130
	ldr r0, _0225891C ; =ov48_02259090
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	mov r0, #1
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_0225890C: .word 0x0000C724
_02258910: .word 0x0000C3CC
_02258914: .word 0x0000C3E0
_02258918: .word 0x0000C40C
_0225891C: .word ov48_02259090
	thumb_func_end ov48_02258800


	thumb_func_start ov48_02258920
ov48_02258920: ; 0x02258920
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r4, r1, #0
	bl OverlayManager_GetData
	add r7, r0, #0
	add r0, r5, #0
	bl OverlayManager_GetArgs
	add r5, r0, #0
	ldr r0, [r4]
	cmp r0, #6
	bhi _022589EE
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02258948: ; jump table
	.short _02258956 - _02258948 - 2 ; case 0
	.short _0225897C - _02258948 - 2 ; case 1
	.short _0225898C - _02258948 - 2 ; case 2
	.short _022589EE - _02258948 - 2 ; case 3
	.short _022589EE - _02258948 - 2 ; case 4
	.short _022589C0 - _02258948 - 2 ; case 5
	.short _022589E0 - _02258948 - 2 ; case 6
_02258956:
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r5, #0xc]
	mov r1, #1
	bl ov45_0222A520
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _022589EE
_0225897C:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _022589EE
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _022589EE
_0225898C:
	add r0, r7, #0
	bl ov48_02258F64
	add r6, r0, #0
	add r0, r7, #0
	bl ov48_02259030
	ldr r0, [r5, #0xc]
	bl ov45_0222A330
	cmp r0, #1
	bne _022589AC
	ldr r0, [r5, #0xc]
	bl ov45_0222A4A8
	mov r6, #1
_022589AC:
	bl ov45_0222D844
	cmp r0, #1
	bne _022589B6
	mov r6, #1
_022589B6:
	cmp r6, #1
	bne _022589EE
	mov r0, #5
	str r0, [r4]
	b _022589EE
_022589C0:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _022589EE
_022589E0:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _022589EE
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_022589EE:
	add r0, r7, #0
	bl ov48_02259050
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov48_02258920


	thumb_func_start ov48_022589FC
ov48_022589FC: ; 0x022589FC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r0, r5, #0
	bl OverlayManager_GetArgs
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	ldr r0, _02258A74 ; =0x0000C40C
	add r1, r4, #0
	add r0, r4, r0
	add r1, #0x20
	bl ov48_0225A108
	mov r0, #0xc7
	lsl r0, r0, #8
	add r0, r4, r0
	bl ov48_02259F14
	ldr r0, _02258A78 ; =0x0000C3E0
	add r0, r4, r0
	bl ov48_02259D94
	ldr r0, _02258A7C ; =0x0000C3CC
	add r0, r4, r0
	bl ov48_02259C38
	mov r0, #0x5e
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov48_02259868
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov48_02259984
	mov r0, #0x5a
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov48_0225B0A4
	add r4, #0x20
	add r0, r4, #0
	bl ov48_022594A8
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x70
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02258A74: .word 0x0000C40C
_02258A78: .word 0x0000C3E0
_02258A7C: .word 0x0000C3CC
	thumb_func_end ov48_022589FC


	thumb_func_start ov48_02258A80
ov48_02258A80: ; 0x02258A80
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	add r5, r0, #0
	str r1, [sp, #0xc]
	mov r0, #0x62
	add r1, r2, #0
	str r2, [sp, #0x10]
	bl NARC_New
	mov r2, #0
	str r2, [r5]
	str r2, [sp]
	add r1, sp, #0x2c
	str r1, [sp, #4]
	ldr r3, [sp, #0x10]
	mov r1, #0x12
	str r0, [sp, #0x24]
	bl GfGfxLoader_LoadFromOpenNarc_GetSizeOut
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x2c]
	mov r1, #6
	bl _u32_div_f
	add r7, r0, #0
	ldr r0, [sp, #0x20]
	mov r6, #1
	add r4, r0, #6
	cmp r7, #1
	ble _02258AEE
_02258ABC:
	ldrh r0, [r4]
	cmp r0, #2
	beq _02258AE6
	lsl r0, r6, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	mov r2, #2
	str r0, [sp, #8]
	mov r3, #4
	ldrsh r2, [r4, r2]
	ldrsh r3, [r4, r3]
	ldr r1, [r5]
	add r0, r5, #0
	bl ov48_02258B7C
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
_02258AE6:
	add r6, r6, #1
	add r4, r4, #6
	cmp r6, r7
	blt _02258ABC
_02258AEE:
	ldr r0, [sp, #0x20]
	bl Heap_Free
	mov r7, #1
	bl LocationGmmDatCountGet
	str r0, [sp, #0x18]
	cmp r0, #1
	ble _02258B72
_02258B00:
	add r0, r7, #0
	bl LocationGmmDatGetEarthPlaceDatId
	add r1, r0, #0
	mov r0, #0
	str r0, [sp]
	add r0, sp, #0x28
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	ldr r3, [sp, #0x10]
	mov r2, #0
	bl GfGfxLoader_LoadFromOpenNarc_GetSizeOut
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x28]
	mov r6, #1
	lsr r0, r0, #2
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x1c]
	add r4, r0, #4
	ldr r0, [sp, #0x14]
	cmp r0, #1
	ble _02258B64
_02258B2E:
	add r0, r7, #0
	bl LocationGmmDatGetCountryMsgNo
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	lsl r0, r6, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	mov r2, #0
	str r0, [sp, #8]
	mov r3, #2
	ldrsh r2, [r4, r2]
	ldrsh r3, [r4, r3]
	ldr r1, [r5]
	add r0, r5, #0
	bl ov48_02258B7C
	ldr r0, [r5]
	add r6, r6, #1
	add r0, r0, #1
	str r0, [r5]
	ldr r0, [sp, #0x14]
	add r4, r4, #4
	cmp r6, r0
	blt _02258B2E
_02258B64:
	ldr r0, [sp, #0x1c]
	bl Heap_Free
	ldr r0, [sp, #0x18]
	add r7, r7, #1
	cmp r7, r0
	blt _02258B00
_02258B72:
	ldr r0, [sp, #0x24]
	bl NARC_Delete
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov48_02258A80


	thumb_func_start ov48_02258B7C
ov48_02258B7C: ; 0x02258B7C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	ldr r5, _02258BF0 ; =ov48_0225B1EC
	add r7, r2, #0
	add r6, r3, #0
	add r4, r0, #0
	mov ip, r1
	add r3, sp, #0xc
	mov r2, #4
_02258B8E:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02258B8E
	ldr r0, [r5]
	mov r1, #0x30
	str r0, [r3]
	mov r0, ip
	add r5, r0, #0
	mul r5, r1
	add r0, r4, r5
	strh r7, [r0, #4]
	strh r6, [r0, #6]
	mov r0, #0
	str r0, [sp, #8]
	add r0, sp, #0xc
	add r1, sp, #0
	str r7, [sp]
	str r6, [sp, #4]
	bl ov48_02258C6C
	add r3, r4, r5
	add r6, sp, #0xc
	add r3, #8
	mov r2, #4
_02258BC0:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02258BC0
	ldr r0, [r6]
	str r0, [r3]
	ldr r0, [sp, #0x50]
	cmp r0, #0
	beq _02258BE0
	add r2, sp, #0x38
	ldrh r1, [r2, #0x10]
	ldrh r2, [r2, #0x14]
	bl ov48_02259A68
	add r1, r4, r5
	strh r0, [r1, #0x2c]
_02258BE0:
	add r0, sp, #0x38
	ldrh r2, [r0, #0x10]
	add r1, r4, r5
	strh r2, [r1, #0x2e]
	ldrh r0, [r0, #0x14]
	strh r0, [r1, #0x30]
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02258BF0: .word ov48_0225B1EC
	thumb_func_end ov48_02258B7C


	thumb_func_start ov48_02258BF4
ov48_02258BF4: ; 0x02258BF4
	push {r4, r5, lr}
	sub sp, #0x24
	add r4, r1, #0
	ldr r1, [r4, #4]
	ldr r3, _02258C68 ; =FX_SinCosTable_
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	asr r1, r1, #4
	lsl r2, r1, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r5, r0, #0
	bl MTX_RotY33_
	ldr r0, [r4]
	ldr r3, _02258C68 ; =FX_SinCosTable_
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	asr r0, r0, #4
	lsl r2, r0, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0
	bl MTX_RotX33_
	add r0, r5, #0
	add r1, sp, #0
	add r2, r5, #0
	bl MTX_Concat33
	ldr r0, [r4, #8]
	ldr r3, _02258C68 ; =FX_SinCosTable_
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	asr r0, r0, #4
	lsl r2, r0, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0
	bl MTX_RotZ33_
	add r0, r5, #0
	add r1, sp, #0
	add r2, r5, #0
	bl MTX_Concat33
	add sp, #0x24
	pop {r4, r5, pc}
	nop
_02258C68: .word FX_SinCosTable_
	thumb_func_end ov48_02258BF4


	thumb_func_start ov48_02258C6C
ov48_02258C6C: ; 0x02258C6C
	push {r4, r5, lr}
	sub sp, #0x24
	add r4, r1, #0
	ldr r1, [r4]
	ldr r3, _02258CE0 ; =FX_SinCosTable_
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	asr r1, r1, #4
	lsl r2, r1, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r5, r0, #0
	bl MTX_RotY33_
	ldr r0, [r4, #4]
	ldr r3, _02258CE0 ; =FX_SinCosTable_
	neg r0, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	asr r0, r0, #4
	lsl r2, r0, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0
	bl MTX_RotX33_
	add r0, r5, #0
	add r1, sp, #0
	add r2, r5, #0
	bl MTX_Concat33
	ldr r0, [r4, #8]
	ldr r3, _02258CE0 ; =FX_SinCosTable_
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	asr r0, r0, #4
	lsl r2, r0, #1
	add r1, r2, #1
	lsl r1, r1, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0
	bl MTX_RotZ33_
	add r0, r5, #0
	add r1, sp, #0
	add r2, r5, #0
	bl MTX_Concat33
	add sp, #0x24
	pop {r4, r5, pc}
	.balign 4, 0
_02258CE0: .word FX_SinCosTable_
	thumb_func_end ov48_02258C6C


	thumb_func_start ov48_02258CE4
ov48_02258CE4: ; 0x02258CE4
	push {r3, r4, r5, r6, r7, lr}
	mov lr, r0
	ldr r0, _02258D4C ; =gSystem + 0x40
	mov ip, r1
	ldrh r5, [r0, #0x20]
	mov r1, #0
	add r7, r2, #0
	add r6, r3, #0
	ldr r0, _02258D50 ; =0x0000FFFF
	add r2, r1, #0
	add r3, r1, #0
	add r4, r1, #0
	cmp r5, r0
	beq _02258D14
	mov r0, lr
	sub r3, r5, r0
	bpl _02258D0E
	sub r0, r1, #1
	eor r3, r0
	mov r1, #0x10
	b _02258D14
_02258D0E:
	cmp r3, #0
	ble _02258D14
	mov r1, #0x20
_02258D14:
	str r1, [r7]
	mov r1, #0x3f
	add r0, r3, #0
	and r0, r1
	str r0, [r6]
	ldr r0, _02258D4C ; =gSystem + 0x40
	ldrh r3, [r0, #0x22]
	ldr r0, _02258D50 ; =0x0000FFFF
	cmp r3, r0
	beq _02258D3C
	mov r0, ip
	sub r4, r3, r0
	bpl _02258D36
	sub r1, #0x40
	eor r4, r1
	mov r2, #0x80
	b _02258D3C
_02258D36:
	cmp r4, #0
	ble _02258D3C
	mov r2, #0x40
_02258D3C:
	ldr r0, [sp, #0x18]
	add r1, r4, #0
	str r2, [r0]
	mov r0, #0x3f
	and r1, r0
	ldr r0, [sp, #0x1c]
	str r1, [r0]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02258D4C: .word gSystem + 0x40
_02258D50: .word 0x0000FFFF
	thumb_func_end ov48_02258CE4


	thumb_func_start ov48_02258D54
ov48_02258D54: ; 0x02258D54
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r0, #0
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #0x5e
	lsl r0, r0, #2
	str r1, [sp]
	add r0, r4, r0
	add r1, sp, #0xc
	add r7, r2, #0
	bl ov48_022598CC
	ldr r0, _02258EF4 ; =0x0000C3E0
	mov r1, #0
	add r0, r4, r0
	bl ov48_02259E5C
	add r6, r0, #0
	ldr r0, _02258EF4 ; =0x0000C3E0
	mov r1, #1
	add r0, r4, r0
	bl ov48_02259E5C
	str r0, [sp, #4]
	ldr r0, _02258EF4 ; =0x0000C3E0
	mov r1, #2
	add r0, r4, r0
	bl ov48_02259E5C
	add r5, r0, #0
	ldr r0, _02258EF8 ; =0x0000C3CC
	add r0, r4, r0
	bl ov48_02259CFC
	ldr r2, [sp, #0x10]
	add r1, r0, #0
	lsl r2, r2, #0x10
	ldr r0, [sp, #0xc]
	asr r2, r2, #0x10
	mov ip, r2
	lsl r0, r0, #0x10
	ldr r2, [sp]
	mov r3, #1
	asr r0, r0, #0x10
	tst r2, r3
	bne _02258DB8
	add r2, r6, #0
	tst r2, r3
	beq _02258DCC
_02258DB8:
	ldr r0, [r4, #4]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _02258DC6
	mov r0, #1
	str r0, [sp, #8]
_02258DC6:
	ldr r0, [sp, #8]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
_02258DCC:
	cmp r1, #0
	bne _02258DF4
	ldr r1, [sp, #4]
	cmp r1, #0
	bne _02258DDA
	cmp r5, #0
	beq _02258DEE
_02258DDA:
	ldr r2, [sp, #4]
	mov r1, #0x55
	mul r1, r2
	lsl r1, r1, #0x10
	lsr r3, r1, #0x10
	mov r1, #0x55
	mul r1, r5
	lsl r1, r1, #0x10
	lsr r5, r1, #0x10
	b _02258E16
_02258DEE:
	lsl r3, r3, #9
	add r5, r3, #0
	b _02258E16
_02258DF4:
	ldr r1, [sp, #4]
	cmp r1, #0
	bne _02258DFE
	cmp r5, #0
	beq _02258E12
_02258DFE:
	ldr r2, [sp, #4]
	mov r1, #0xa
	mul r1, r2
	lsl r1, r1, #0x10
	lsr r3, r1, #0x10
	mov r1, #0xa
	mul r1, r5
	lsl r1, r1, #0x10
	lsr r5, r1, #0x10
	b _02258E16
_02258E12:
	mov r3, #0x20
	add r5, r3, #0
_02258E16:
	mov r2, #0x20
	add r1, r7, #0
	tst r1, r2
	bne _02258E24
	add r1, r6, #0
	tst r1, r2
	beq _02258E44
_02258E24:
	ldr r1, [r4, #4]
	lsl r1, r1, #0x1f
	lsr r1, r1, #0x1f
	cmp r1, #1
	bne _02258E36
	ldr r1, [sp, #0x10]
	add r1, r1, r3
	str r1, [sp, #0x10]
	b _02258E44
_02258E36:
	ldr r2, _02258EFC ; =0xFFFFD820
	mov r1, ip
	cmp r1, r2
	bge _02258E44
	ldr r1, [sp, #0x10]
	add r1, r1, r3
	str r1, [sp, #0x10]
_02258E44:
	mov r2, #0x10
	add r1, r7, #0
	tst r1, r2
	bne _02258E52
	add r1, r6, #0
	tst r1, r2
	beq _02258E72
_02258E52:
	ldr r1, [r4, #4]
	lsl r1, r1, #0x1f
	lsr r1, r1, #0x1f
	cmp r1, #1
	bne _02258E64
	ldr r1, [sp, #0x10]
	sub r1, r1, r3
	str r1, [sp, #0x10]
	b _02258E72
_02258E64:
	ldr r2, _02258F00 ; =0xFFFFCC80
	mov r1, ip
	cmp r1, r2
	ble _02258E72
	ldr r1, [sp, #0x10]
	sub r1, r1, r3
	str r1, [sp, #0x10]
_02258E72:
	mov r1, #0x40
	add r2, r7, #0
	tst r2, r1
	bne _02258E7E
	tst r1, r6
	beq _02258EAA
_02258E7E:
	ldr r1, [r4, #4]
	lsl r1, r1, #0x1f
	lsr r1, r1, #0x1f
	cmp r1, #1
	bne _02258E9E
	mov r1, #0x3e
	add r2, r0, r5
	lsl r1, r1, #8
	cmp r2, r1
	bge _02258E9A
	ldr r1, [sp, #0xc]
	add r1, r1, r5
	str r1, [sp, #0xc]
	b _02258EAA
_02258E9A:
	str r1, [sp, #0xc]
	b _02258EAA
_02258E9E:
	ldr r1, _02258F04 ; =0x00002020
	cmp r0, r1
	bge _02258EAA
	ldr r1, [sp, #0xc]
	add r1, r1, r5
	str r1, [sp, #0xc]
_02258EAA:
	mov r1, #0x80
	add r2, r7, #0
	tst r2, r1
	bne _02258EB6
	tst r1, r6
	beq _02258EE2
_02258EB6:
	ldr r1, [r4, #4]
	lsl r1, r1, #0x1f
	lsr r1, r1, #0x1f
	cmp r1, #1
	bne _02258ED4
	sub r1, r0, r5
	ldr r0, _02258F08 ; =0xFFFFC200
	cmp r1, r0
	ble _02258ED0
	ldr r0, [sp, #0xc]
	sub r0, r0, r5
	str r0, [sp, #0xc]
	b _02258EE2
_02258ED0:
	str r0, [sp, #0xc]
	b _02258EE2
_02258ED4:
	mov r1, #0x13
	lsl r1, r1, #8
	cmp r0, r1
	ble _02258EE2
	ldr r0, [sp, #0xc]
	sub r0, r0, r5
	str r0, [sp, #0xc]
_02258EE2:
	mov r0, #0x5e
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, sp, #0xc
	bl ov48_022598DC
	mov r0, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02258EF4: .word 0x0000C3E0
_02258EF8: .word 0x0000C3CC
_02258EFC: .word 0xFFFFD820
_02258F00: .word 0xFFFFCC80
_02258F04: .word 0x00002020
_02258F08: .word 0xFFFFC200
	thumb_func_end ov48_02258D54


	thumb_func_start ov48_02258F0C
ov48_02258F0C: ; 0x02258F0C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	blt _02258F20
	ldr r1, _02258F60 ; =0x0000FFFF
	bl _s32_div_f
	str r1, [r4]
	b _02258F36
_02258F20:
	bge _02258F24
	neg r0, r0
_02258F24:
	ldr r1, _02258F60 ; =0x0000FFFF
	bl _s32_div_f
	add r1, r0, #1
	ldr r0, _02258F60 ; =0x0000FFFF
	ldr r2, [r4]
	mul r0, r1
	add r0, r2, r0
	str r0, [r4]
_02258F36:
	ldr r0, [r4, #4]
	cmp r0, #0
	blt _02258F46
	ldr r1, _02258F60 ; =0x0000FFFF
	bl _s32_div_f
	str r1, [r4, #4]
	pop {r4, pc}
_02258F46:
	bge _02258F4A
	neg r0, r0
_02258F4A:
	ldr r1, _02258F60 ; =0x0000FFFF
	bl _s32_div_f
	add r1, r0, #1
	ldr r0, _02258F60 ; =0x0000FFFF
	ldr r2, [r4, #4]
	mul r0, r1
	add r0, r2, r0
	str r0, [r4, #4]
	pop {r4, pc}
	nop
_02258F60: .word 0x0000FFFF
	thumb_func_end ov48_02258F0C


	thumb_func_start ov48_02258F64
ov48_02258F64: ; 0x02258F64
	push {r4, lr}
	add r4, r0, #0
	ldrh r1, [r4]
	cmp r1, #3
	bhi _0225901C
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02258F7A: ; jump table
	.short _02258F82 - _02258F7A - 2 ; case 0
	.short _02258FA8 - _02258F7A - 2 ; case 1
	.short _02258FC0 - _02258F7A - 2 ; case 2
	.short _02258FE2 - _02258F7A - 2 ; case 3
_02258F82:
	bl ov48_0225909C
	cmp r0, #0
	beq _02259020
	cmp r0, #1
	beq _02258F94
	cmp r0, #2
	beq _02258FA2
	b _02259020
_02258F94:
	ldr r0, _02259024 ; =0x0000C3CC
	add r0, r4, r0
	bl ov48_02259C4C
	mov r0, #1
	strh r0, [r4]
	b _02259020
_02258FA2:
	mov r0, #2
	strh r0, [r4]
	b _02259020
_02258FA8:
	ldr r0, _02259024 ; =0x0000C3CC
	mov r1, #0x89
	lsl r1, r1, #2
	add r0, r4, r0
	add r1, r4, r1
	bl ov48_02259C78
	cmp r0, #1
	bne _02259020
	mov r0, #0
	strh r0, [r4]
	b _02259020
_02258FC0:
	mov r0, #0xc7
	lsl r0, r0, #8
	add r0, r4, r0
	bl ov48_02259F48
	ldr r0, _02259028 ; =0x0000C40C
	add r0, r4, r0
	bl ov48_0225A1D0
	ldr r0, _0225902C ; =0x0000C3E0
	add r0, r4, r0
	bl ov48_02259E78
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	b _02259020
_02258FE2:
	mov r0, #0xc7
	lsl r0, r0, #8
	add r0, r4, r0
	bl ov48_02259F8C
	cmp r0, #0
	beq _02259020
	cmp r0, #1
	beq _02259018
	cmp r0, #2
	bne _02259018
	ldr r0, _02259028 ; =0x0000C40C
	add r0, r4, r0
	bl ov48_0225A1EC
	mov r0, #0xc7
	lsl r0, r0, #8
	add r0, r4, r0
	bl ov48_02259FEC
	ldr r0, _0225902C ; =0x0000C3E0
	add r0, r4, r0
	bl ov48_02259E90
	mov r0, #0
	strh r0, [r4]
	b _02259020
_02259018:
	mov r0, #1
	pop {r4, pc}
_0225901C:
	bl GF_AssertFail
_02259020:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_02259024: .word 0x0000C3CC
_02259028: .word 0x0000C40C
_0225902C: .word 0x0000C3E0
	thumb_func_end ov48_02258F64
