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

	thumb_func_start ov75_02246960
ov75_02246960: ; 0x02246960
	push {r3, r4, r5, lr}
	mov r2, #0xa
	add r5, r0, #0
	mov r0, #3
	mov r1, #0x73
	lsl r2, r2, #0xe
	bl Heap_Create
	mov r2, #0x57
	mov r0, #0
	mov r1, #0x59
	lsl r2, r2, #4
	bl Heap_Create
	mov r1, #0x47
	add r0, r5, #0
	lsl r1, r1, #2
	mov r2, #0x73
	bl OverlayManager_CreateAndGetData
	mov r2, #0x47
	mov r1, #0
	lsl r2, r2, #2
	add r4, r0, #0
	bl MI_CpuFill8
	add r0, r5, #0
	bl OverlayManager_GetArgs
	ldr r0, [r0, #8]
	str r0, [r4, #4]
	bl Save_PlayerData_GetOptionsAddr
	str r0, [r4, #8]
	mov r0, #0x64
	mov r1, #0x73
	bl String_New
	mov r1, #0x11
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r0, #0x64
	mov r1, #0x73
	bl String_New
	mov r1, #0x45
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r1, _022469D4 ; =0x0000047D
	mov r0, #0x11
	mov r2, #1
	bl Sound_SetSceneAndPlayBGM
	mov r0, #0
	add r4, #0x88
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_022469D4: .word 0x0000047D
	thumb_func_end ov75_02246960


	thumb_func_start ov75_022469D8
ov75_022469D8: ; 0x022469D8
	push {r3, r4, r5, lr}
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, [r4, #0x7c]
	cmp r0, #1
	bne _022469FC
	bl ov00_021ECB40
	bl ov70_022378DC
	bl ov00_021EC9D4
	mov r1, #3
	sub r0, r1, r0
	bl sub_0203A930
_022469FC:
	ldr r0, [r5]
	cmp r0, #4
	bhi _02246ADE
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02246A0E: ; jump table
	.short _02246A18 - _02246A0E - 2 ; case 0
	.short _02246A24 - _02246A0E - 2 ; case 1
	.short _02246A44 - _02246A0E - 2 ; case 2
	.short _02246A82 - _02246A0E - 2 ; case 3
	.short _02246ADA - _02246A0E - 2 ; case 4
_02246A18:
	add r0, r4, #0
	bl ov75_02246B48
	mov r0, #1
	str r0, [r5]
	b _02246ADE
_02246A24:
	bl sub_02034DB8
	cmp r0, #0
	beq _02246ADE
	ldr r1, [r4, #0x10]
	ldr r0, _02246AE4 ; =_02249BE0
	str r1, [r0]
	ldr r0, _02246AE8 ; =ov75_02246BF0
	ldr r1, _02246AEC ; =ov75_02246C18
	bl ov00_021EC294
	mov r0, #1
	str r0, [r4, #0x7c]
	mov r0, #2
	str r0, [r5]
	b _02246ADE
_02246A44:
	add r1, r4, #0
	add r1, #0x88
	ldr r1, [r1]
	add r0, r4, #0
	lsl r2, r1, #4
	ldr r1, _02246AF0 ; =ov75_02249904
	ldr r1, [r1, r2]
	blx r1
	add r1, r0, #0
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	lsl r2, r0, #4
	ldr r0, _02246AF4 ; =ov75_02249904 + 8
	ldr r0, [r0, r2]
	mov r2, #0x73
	bl OverlayManager_New
	str r0, [r4]
	add r0, r4, #0
	add r0, #0x88
	ldr r1, [r0]
	add r0, r4, #0
	add r0, #0x80
	str r1, [r0]
	mov r0, #6
	add r4, #0x88
	str r0, [r4]
	mov r0, #3
	str r0, [r5]
	b _02246ADE
_02246A82:
	ldr r0, [r4]
	bl OverlayManager_Run
	cmp r0, #1
	bne _02246ADE
	add r1, r4, #0
	add r1, #0x80
	ldr r1, [r1]
	add r0, r4, #0
	lsl r2, r1, #4
	ldr r1, _02246AF8 ; =ov75_02249904 + 4
	ldr r1, [r1, r2]
	blx r1
	ldr r0, [r4]
	bl OverlayManager_Delete
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	cmp r0, #6
	bne _02246AB2
	mov r0, #4
	str r0, [r5]
	b _02246ADE
_02246AB2:
	lsl r1, r0, #4
	ldr r0, _02246AFC ; =ov75_02249904 + 12
	ldr r0, [r0, r1]
	cmp r0, #1
	bne _02246AC8
	add r0, r4, #0
	bl ov75_02246B98
	mov r0, #2
	str r0, [r5]
	b _02246ADE
_02246AC8:
	ldr r0, [r4, #0x7c]
	cmp r0, #1
	bne _02246AD4
	mov r0, #2
	str r0, [r5]
	b _02246ADE
_02246AD4:
	mov r0, #0
	str r0, [r5]
	b _02246ADE
_02246ADA:
	mov r0, #1
	pop {r3, r4, r5, pc}
_02246ADE:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_02246AE4: .word _02249BE0
_02246AE8: .word ov75_02246BF0
_02246AEC: .word ov75_02246C18
_02246AF0: .word ov75_02249904
_02246AF4: .word ov75_02249904 + 8
_02246AF8: .word ov75_02249904 + 4
_02246AFC: .word ov75_02249904 + 12
	thumb_func_end ov75_022469D8


	thumb_func_start ov75_02246B00
ov75_02246B00: ; 0x02246B00
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	bl ov75_02246B98
	mov r0, #0x45
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl String_Delete
	mov r0, #0x11
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl String_Delete
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x73
	bl Heap_Destroy
	mov r0, #0x59
	bl Heap_Destroy
	ldr r0, _02246B40 ; =FS_OVERLAY_ID(intro_title)
	ldr r1, _02246B44 ; =gApplication_TitleScreen
	bl RegisterMainOverlay
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02246B40: .word FS_OVERLAY_ID(intro_title)
_02246B44: .word gApplication_TitleScreen
	thumb_func_end ov75_02246B00


	thumb_func_start ov75_02246B48
ov75_02246B48: ; 0x02246B48
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x7c]
	cmp r0, #0
	bne _02246B8E
	ldr r0, _02246B90 ; =FS_OVERLAY_ID(OVY_70)
	mov r1, #2
	bl HandleLoadOverlay
	bl LoadDwcOverlay
	bl LoadOVY38
	mov r0, #0x73
	bl sub_02039FD8
	ldr r1, _02246B94 ; =0x00020020
	mov r0, #0x73
	bl Heap_Alloc
	str r0, [r4, #0xc]
	add r0, #0x1f
	mov r1, #0x1f
	bic r0, r1
	mov r1, #2
	lsl r1, r1, #0x10
	mov r2, #0
	bl NNS_FndCreateExpHeapEx
	str r0, [r4, #0x10]
	bl sub_02034D8C
	mov r0, #4
	bl Sys_ClearSleepDisableFlag
_02246B8E:
	pop {r4, pc}
	.balign 4, 0
_02246B90: .word FS_OVERLAY_ID(OVY_70)
_02246B94: .word 0x00020020
	thumb_func_end ov75_02246B48


	thumb_func_start ov75_02246B98
ov75_02246B98: ; 0x02246B98
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x7c]
	cmp r0, #1
	bne _02246BC4
	ldr r0, [r4, #0x10]
	bl NNS_FndDestroyExpHeap
	ldr r0, [r4, #0xc]
	bl Heap_Free
	bl UnloadOVY38
	bl UnloadDwcOverlay
	bl sub_02034DE0
	ldr r0, _02246BC8 ; =FS_OVERLAY_ID(OVY_70)
	bl UnloadOverlayByID
	mov r0, #0
	str r0, [r4, #0x7c]
_02246BC4:
	pop {r4, pc}
	nop
_02246BC8: .word FS_OVERLAY_ID(OVY_70)
	thumb_func_end ov75_02246B98
