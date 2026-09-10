	.include "asm/macros.inc"
	.include "overlay_75.inc"
	.include "global.inc"
	.public gApplication_TitleScreen

	.text
	.public _02249B20
	.public _02249BE0
	.public ov75_02246960
	.public ov75_022469D8
	.public ov75_02246B00
	.public ov75_02246B48
	.public ov75_02246B98
	.public ov75_02246C3C
	.public ov75_02246D08
	.public ov75_02246D40
	.public ov75_02246DB4
	.public ov75_02246DFC
	.public ov75_02246E3C
	.public ov75_02246E78
	.public ov75_02246F0C
	.public ov75_02247118
	.public ov75_02247180
	.public ov75_0224725C
	.public ov75_02247450
	.public ov75_022476E8
	.public ov75_02247790
	.public ov75_02247890
	.public ov75_022478E0
	.public ov75_02247A98
	.public ov75_02247B98
	.public ov75_02247C70
	.public ov75_02247D24
	.public ov75_02248034
	.public ov75_022480B8
	.public ov75_022483EC
	.public ov75_02248584
	.public ov75_02248684
	.public ov75_022486EC
	.public ov75_0224874C
	.public ov75_02248774
	.public ov75_02248800
	.public ov75_022488BC
	.public ov75_02248994
	.public ov75_02248A20
	.public ov75_02248B8C
	.public ov75_02248C84
	.public ov75_02248D2C
	.public ov75_02248F18
	.public ov75_02248F7C
	.public ov75_02248FE8
	.public ov75_022490D8
	.public ov75_022491CC
	.public ov75_022491F0
	.public ov75_02249278
	.public ov75_0224937C
	.public ov75_02249478
	.public ov75_022494CC
	.public ov75_02249534
	.public ov75_02249550
	.public ov75_022495B0
	.public ov75_0224964C
	.public ov75_02249684
	.public ov75_022496B8
	.public ov75_0224971C
	.public ov75_02249780
	.public ov75_02249838
	.public ov75_02249884
	.public ov75_022498E4
	.public ov75_022498F4
	.public ov75_02249904
	.public ov75_02249974
	.public ov75_02249978
	.public ov75_0224997C
	.public ov75_0224998C
	.public ov75_0224999C
	.public ov75_022499BC
	.public ov75_022499DC
	.public ov75_022499FC
	.public ov75_02249A24
	.public ov75_02249A5C
	.public ov75_02249ACC
	.public ov75_02249AD0
	.public ov75_02249ADC
	.public ov75_02249B24
	.public ov75_02249B30
	.public ov75_App_MainMenu_SelectOption_WiiMessageSettings
	.public ov75_02246BCC
	.public ov75_02246BD8
	.public ov75_02246BE0
	.public ov75_02246BE8
	.public ov75_02246BF0
	.public ov75_02246C18
	.public ov75_02246C68
	.public ov75_02246C8C
	.public ov75_02246CA0
	.public ov75_02246CB8
	.public ov75_02246CCC
	.public ov75_02246CD8
	.public ov75_02246CE0
	.public ov75_02246CE8
	.public ov75_02246CF0
	.public ov75_02246CF8
	.public ov75_02246D00
	.public ov75_02246D04
	.public ov75_02246EAC
	.public ov75_02246EDC
	.public ov75_02247234
	.public ov75_0224741C
	.public ov75_02247838
	.public ov75_02247854
	.public ov75_0224785C
	.public ov75_02247878
	.public ov75_02247A78
	.public ov75_02247D0C
	.public ov75_0224852C
	.public ov75_0224854C
	.public ov75_02248714
	.public ov75_022488AC
	.public ov75_022489F8
	.public ov75_02248C64
	.public ov75_0224921C
	.public ov75_02249258
	.public ov75_02249460
	.public ov75_022494A4
	.public ov75_02249758
	.public ov75_0224976C

	thumb_func_start ov75_02246F0C
ov75_02246F0C: ; 0x02246F0C
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r1, #1
	lsl r1, r1, #0x1a
	ldr r0, [r1]
	ldr r2, _022470F4 ; =0xFFFFE0FF
	and r0, r2
	str r0, [r1]
	ldr r0, _022470F8 ; =0x04001000
	ldr r3, [r0]
	and r2, r3
	str r2, [r0]
	ldr r3, [r1]
	ldr r2, _022470FC ; =0xFFFF1FFF
	and r3, r2
	str r3, [r1]
	ldr r3, [r0]
	add r1, #0x50
	and r2, r3
	str r2, [r0]
	mov r2, #0
	strh r2, [r1]
	add r0, #0x50
	strh r2, [r0]
	mov r2, #7
	mov r0, #3
	mov r1, #0x74
	lsl r2, r2, #0x10
	bl Heap_Create
	ldr r1, _02247100 ; =0x0000041C
	add r0, r4, #0
	mov r2, #0x74
	bl OverlayManager_CreateAndGetData
	ldr r2, _02247100 ; =0x0000041C
	mov r1, #0
	add r5, r0, #0
	bl MI_CpuFill8
	add r0, r4, #0
	bl OverlayManager_GetArgs
	str r0, [r5]
	mov r0, #0x74
	bl BgConfig_Alloc
	str r0, [r5, #4]
	mov r0, #0x40
	mov r1, #0x74
	bl GF_CreateVramTransferManager
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	ldr r0, [r5, #4]
	bl ov75_0224725C
	bl sub_020210BC
	mov r0, #4
	bl sub_02021148
	mov r0, #0xb
	mov r1, #0x40
	mov r2, #0x74
	bl MessageFormat_New_Custom
	str r0, [r5, #0x20]
	ldr r2, _02247104 ; =0x00000307
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x74
	bl NewMsgDataFromNarc
	str r0, [r5, #0x24]
	ldr r2, _02247108 ; =0x0000030A
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x74
	bl NewMsgDataFromNarc
	mov r2, #0x32
	str r0, [r5, #0x2c]
	mov r0, #0
	mov r1, #0x1b
	lsl r2, r2, #4
	mov r3, #0x74
	bl NewMsgDataFromNarc
	str r0, [r5, #0x30]
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xed
	mov r3, #0x74
	bl NewMsgDataFromNarc
	str r0, [r5, #0x28]
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xbc
	mov r3, #0x74
	bl NewMsgDataFromNarc
	str r0, [r5, #0x34]
	ldr r0, _0224710C ; =0x0000010E
	mov r1, #0x74
	bl String_New
	str r0, [r5, #0x38]
	mov r0, #1
	lsl r0, r0, #8
	mov r1, #0x74
	bl String_New
	str r0, [r5, #0x40]
	ldr r0, [r5, #0x24]
	mov r1, #0x1f
	bl NewString_ReadMsgData
	str r0, [r5, #0x3c]
	add r0, r5, #0
	bl ov75_02247450
	add r0, r5, #0
	bl ov75_02247790
	ldr r0, [r5]
	bl ov75_02246BE8
	cmp r0, #0xc
	beq _02247032
	cmp r0, #0x16
	beq _0224705E
	b _02247074
_02247032:
	bl ov00_021EC5B4
	cmp r0, #0
	bne _02247058
	ldr r0, [r5]
	ldr r0, [r0, #4]
	bl sub_0203A05C
	cmp r0, #1
	bne _02247058
	mov r0, #0xc
	str r0, [r5, #8]
	ldr r0, [r5]
	ldr r0, [r0, #4]
	bl sub_02039528
	bl sub_0203A880
	b _0224707C
_02247058:
	mov r0, #0
	str r0, [r5, #8]
	b _0224707C
_0224705E:
	add r0, r5, #0
	mov r1, #0
	add r0, #0xe8
	str r1, [r0]
	bl sub_0203A880
	ldr r0, [r5]
	bl ov75_02246BE8
	str r0, [r5, #8]
	b _0224707C
_02247074:
	ldr r0, [r5]
	bl ov75_02246BE8
	str r0, [r5, #8]
_0224707C:
	ldr r0, [r5]
	mov r1, #0
	bl ov75_02246BE0
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x74
	str r0, [sp, #8]
	mov r0, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, _02247110 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #1
	bl TextFlags_SetCanABSpeedUpPrint
	mov r0, #0
	bl TextFlags_SetAutoScrollParam
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r0, _02247114 ; =ov75_02247234
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_022470F4: .word 0xFFFFE0FF
_022470F8: .word 0x04001000
_022470FC: .word 0xFFFF1FFF
_02247100: .word 0x0000041C
_02247104: .word 0x00000307
_02247108: .word 0x0000030A
_0224710C: .word 0x0000010E
_02247110: .word gSystem + 0x60
_02247114: .word ov75_02247234
	thumb_func_end ov75_02246F0C


	thumb_func_start ov75_02247118
ov75_02247118: ; 0x02247118
	push {r4, r5, r6, lr}
	add r5, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r5]
	add r4, r0, #0
	cmp r1, #0
	beq _02247132
	cmp r1, #1
	beq _02247140
	cmp r1, #2
	beq _0224716C
	b _02247178
_02247132:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _02247178
	mov r0, #1
	str r0, [r5]
	b _02247178
_02247140:
	ldr r6, [r4, #8]
	ldr r1, _0224717C ; =ov75_02249B30
	lsl r2, r6, #2
	ldr r1, [r1, r2]
	blx r1
	ldr r1, [r4, #8]
	cmp r6, r1
	beq _02247162
	add r1, r4, #0
	mov r2, #0
	add r1, #0x94
	str r2, [r1]
	add r1, r4, #0
	add r1, #0x9c
	str r2, [r1]
	add r4, #0x98
	str r2, [r4]
_02247162:
	cmp r0, #1
	bne _02247178
	mov r0, #2
	str r0, [r5]
	b _02247178
_0224716C:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _02247178
	mov r0, #1
	pop {r4, r5, r6, pc}
_02247178:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0224717C: .word ov75_02249B30
	thumb_func_end ov75_02247118


	thumb_func_start ov75_02247180
ov75_02247180: ; 0x02247180
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r0, #0xec
	ldr r0, [r0]
	cmp r0, #0
	beq _022471A4
	bl SysTask_Destroy
	add r0, r4, #0
	mov r1, #0
	add r0, #0xec
	str r1, [r0]
	add r0, r4, #0
	add r0, #0xf0
	str r1, [r0]
_022471A4:
	ldr r0, [r4, #0x34]
	bl DestroyMsgData
	ldr r0, [r4, #0x28]
	bl DestroyMsgData
	ldr r0, [r4, #0x30]
	bl DestroyMsgData
	ldr r0, [r4, #0x2c]
	bl DestroyMsgData
	ldr r0, [r4, #0x24]
	bl DestroyMsgData
	ldr r0, [r4, #0x20]
	bl MessageFormat_Delete
	ldr r0, [r4, #0x3c]
	bl String_Delete
	ldr r0, [r4, #0x40]
	bl String_Delete
	ldr r0, [r4, #0x38]
	bl String_Delete
	add r0, r4, #0
	bl ov75_02247838
	ldr r0, [r4, #4]
	bl Heap_Free
	ldr r0, [r4, #4]
	bl ov75_0224741C
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GF_DestroyVramTransferManager
	bl sub_02021238
	mov r0, #0
	bl TextFlags_SetCanABSpeedUpPrint
	mov r0, #0
	bl TextFlags_SetAutoScrollParam
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	bl sub_0203A914
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x74
	bl Heap_Destroy
	ldr r0, _02247230 ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02247230: .word gSystem + 0x60
	thumb_func_end ov75_02247180
