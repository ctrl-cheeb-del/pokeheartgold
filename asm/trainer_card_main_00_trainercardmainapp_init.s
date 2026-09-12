#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_trainer_card_main.inc"
	.include "global.inc"

	.text

.public TrainerCardMainApp_Exit
.public TrainerCardMainApp_Init
.public TrainerCardMainApp_Main
.public _021E7DB8
.public _021E80A0
.public ov51_021E5F64
.public ov51_021E6038
.public ov51_021E60D4
.public ov51_021E60F4
.public ov51_021E6200
.public ov51_021E6238
.public ov51_021E6354
.public ov51_021E6644
.public ov51_021E66C0
.public ov51_021E6734
.public ov51_021E67A4
.public ov51_021E6888
.public ov51_021E69EC
.public ov51_021E6A54
.public ov51_021E6AAC
.public ov51_021E6B44
.public ov51_021E6B88
.public ov51_021E6C00
.public ov51_021E6C6C
.public ov51_021E6CCC
.public ov51_021E6CF0
.public ov51_021E6D44
.public ov51_021E6DA8
.public ov51_021E6E10
.public ov51_021E6E60
.public ov51_021E6EF0
.public ov51_021E6F18
.public ov51_021E71D0
.public ov51_021E7208
.public ov51_021E74D4
.public ov51_021E74F4
.public ov51_021E7540
.public ov51_021E757C
.public ov51_021E7664
.public ov51_021E76A4
.public ov51_021E76EC
.public ov51_021E77A0
.public ov51_021E7804
.public ov51_021E786C
.public ov51_021E78D0
.public ov51_021E78F8
.public ov51_021E7AF4
.public ov51_021E7BD0
.public ov51_021E7CA4
.public ov51_021E7D44
.public ov51_021E7D68
.public ov51_021E7DA4
.public ov51_021E7DBC
.public ov51_021E7DC0
.public ov51_021E7DC8
.public ov51_021E7DD8
.public ov51_021E7DF0
.public ov51_021E7E08
.public ov51_021E7E20
.public ov51_021E7E38
.public ov51_021E7E54
.public ov51_021E7E70
.public ov51_021E7E8C
.public ov51_021E7EA8
.public ov51_021E7ED0
.public ov51_021E7F08
.public ov51_021E7F48
.public ov51_021E7FB8
.public ov51_021E7FBC
.public ov51_021E7FC4
.public ov51_021E7FCC
.public ov51_021E7FDC
.public ov51_021E801C
.public ov51_021E80A4

	thumb_func_start TrainerCardMainApp_Init
TrainerCardMainApp_Init: ; 0x021E5AC0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0
	add r1, r0, #0
	bl Main_SetHBlankIntrCB
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _021E5D44 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021E5D48 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	mov r0, #0
	add r1, r0, #0
	bl sub_0200FBF4
	mov r0, #1
	mov r1, #0
	bl sub_0200FBF4
	mov r0, #0
	bl ResetVisibleHardwareWindows
	mov r0, #1
	bl ResetVisibleHardwareWindows
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	mov r2, #5
	mov r0, #3
	mov r1, #0x19
	lsl r2, r2, #0x10
	bl Heap_Create
	ldr r1, _021E5D4C ; =0x00003444
	add r0, r5, #0
	mov r2, #0x19
	bl OverlayManager_CreateAndGetData
	ldr r2, _021E5D4C ; =0x00003444
	mov r1, #0
	add r4, r0, #0
	bl memset
	add r0, r5, #0
	bl OverlayManager_GetArgs
	add r1, r4, #0
	add r1, #0xe4
	str r0, [r1]
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	add r0, r4, #0
	add r0, #0xe8
	str r1, [r0]
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _021E5D50 ; =0x0000066C
	ldr r0, [r1, r0]
	bl MenuInputStateMgr_GetState
	ldr r1, _021E5D54 ; =0x0000310C
	str r0, [r4, r1]
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	mov r0, #0x67
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	bl Save_PlayerData_GetOptionsAddr
	add r5, r0, #0
	bl Options_GetTextFrameDelay
	ldr r1, _021E5D58 ; =0x0000343E
	strb r0, [r4, r1]
	add r0, r5, #0
	bl Options_GetFrame
	ldr r1, _021E5D5C ; =0x0000343D
	strb r0, [r4, r1]
	bl sub_02037474
	cmp r0, #1
	bne _021E5B96
	ldr r1, _021E5D60 ; =0x0000343A
	mov r0, #2
	ldrb r2, [r4, r1]
	orr r0, r2
	strb r0, [r4, r1]
_021E5B96:
	add r0, r4, #0
	add r0, #0xe8
	ldr r0, [r0]
	ldr r1, _021E5D60 ; =0x0000343A
	add r0, #0x33
	ldrb r0, [r0]
	cmp r0, #0
	beq _021E5BB4
	ldrb r2, [r4, r1]
	mov r0, #1
	bic r2, r0
	mov r0, #1
	orr r0, r2
	strb r0, [r4, r1]
	b _021E5BBC
_021E5BB4:
	ldrb r2, [r4, r1]
	mov r0, #1
	bic r2, r0
	strb r2, [r4, r1]
_021E5BBC:
	ldr r2, _021E5D60 ; =0x0000343A
	ldrb r0, [r4, r2]
	lsl r1, r0, #0x1e
	lsr r1, r1, #0x1f
	cmp r1, #1
	bne _021E5BDC
	add r1, r4, #0
	add r1, #0xe4
	ldr r3, [r1]
	ldr r1, _021E5D64 ; =0x00000678
	ldr r1, [r3, r1]
	cmp r1, #0
	bne _021E5BDC
	mov r1, #1
	bic r0, r1
	strb r0, [r4, r2]
_021E5BDC:
	add r0, r4, #0
	add r0, #0xe8
	ldr r0, [r0]
	ldrb r0, [r0]
	add r0, #0xf9
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bhi _021E5C1C
	ldr r7, _021E5D68 ; =0x00003424
	mov r3, #1
	mov r2, #0
	add r0, r2, #0
	add r1, r3, #0
	add r5, r7, #0
_021E5BFA:
	add r6, r4, #0
	add r6, #0xe8
	ldr r6, [r6]
	ldrh r6, [r6, #6]
	tst r6, r3
	beq _021E5C0C
	add r6, r4, r2
	strb r1, [r6, r5]
	b _021E5C10
_021E5C0C:
	add r6, r4, r2
	strb r0, [r6, r7]
_021E5C10:
	lsl r3, r3, #0x11
	add r2, r2, #1
	lsr r3, r3, #0x10
	cmp r2, #0x10
	blt _021E5BFA
	b _021E5C2C
_021E5C1C:
	mov r3, #0
	ldr r0, _021E5D68 ; =0x00003424
	add r2, r3, #0
_021E5C22:
	add r1, r4, r3
	add r3, r3, #1
	strb r2, [r1, r0]
	cmp r3, #0x10
	blt _021E5C22
_021E5C2C:
	mov r0, #0x19
	bl BgConfig_Alloc
	str r0, [r4]
	add r0, r4, #0
	bl ov51_021E5F64
	bl ov51_021E60D4
	ldr r0, [r4]
	bl ov51_021E6238
	add r0, r4, #0
	bl ov51_021E6354
	bl sub_020210BC
	mov r0, #4
	bl sub_02021148
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	mov r0, #1
	bl TextFlags_SetCanABSpeedUpPrint
	mov r1, #0
	mov r0, #0x38
	add r2, r1, #0
	bl Sound_SetSceneAndPlayBGM
	ldr r0, _021E5D6C ; =0x000033A0
	add r0, r4, r0
	bl ov51_021E7DA4
	ldr r0, _021E5D70 ; =SEQ_SE_DP_CARD3
	bl PlaySE
	ldr r0, _021E5D74 ; =0x0000311C
	add r0, r4, r0
	bl ov51_021E78F8
	ldr r2, _021E5D68 ; =0x00003424
	ldr r0, _021E5D74 ; =0x0000311C
	add r1, r4, r2
	add r2, #0x16
	ldrb r2, [r4, r2]
	add r0, r4, r0
	lsl r2, r2, #0x1f
	lsr r2, r2, #0x1f
	bl ov51_021E7AF4
	ldr r0, _021E5D74 ; =0x0000311C
	add r0, r4, r0
	bl ov51_021E7BD0
	add r0, r4, #0
	bl ov51_021E6E60
	ldr r2, _021E5D78 ; =0x000033CC
	add r0, r4, #0
	ldr r2, [r4, r2]
	add r0, #0x54
	mov r1, #1
	bl ov51_021E7664
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _021E5D7C ; =0x00000674
	ldr r0, [r1, r0]
	cmp r0, #0
	beq _021E5CC2
	mov r1, #1
	b _021E5CC4
_021E5CC2:
	mov r1, #0
_021E5CC4:
	ldr r0, _021E5D80 ; =0x000030F4
	str r1, [r4, r0]
	add r1, r4, #0
	add r1, #0xe4
	ldr r2, [r1]
	mov r0, #0
	ldr r1, _021E5D7C ; =0x00000674
	sub r3, r0, #1
	str r0, [r2, r1]
	ldr r1, _021E5D84 ; =0x00003434
	ldr r2, _021E5D88 ; =0x00003108
	strb r0, [r4, r1]
	str r3, [r4, r2]
	add r2, r1, #0
	sub r2, #0x98
	str r0, [r4, r2]
	add r1, r1, #4
	strb r0, [r4, r1]
	bl ov51_021E6C00
	add r0, r4, #0
	bl ov51_021E6734
	add r0, r4, #0
	mov r1, #0
	bl ov51_021E76A4
	ldr r0, _021E5D8C ; =ov51_021E6B88
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	bl sub_0203A964
	mov r0, #1
	mov r1, #0x2a
	bl GF_SndHandleSetPlayerVolume
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x19
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #2
	add r2, r1, #0
	mov r3, #0
	bl BeginNormalPaletteFade
	add r4, #0xe8
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, #7
	beq _021E5D3C
	cmp r0, #8
	beq _021E5D3C
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
_021E5D3C:
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_021E5D44: .word 0xFFFFE0FF
_021E5D48: .word 0x04001000
_021E5D4C: .word 0x00003444
_021E5D50: .word 0x0000066C
_021E5D54: .word 0x0000310C
_021E5D58: .word 0x0000343E
_021E5D5C: .word 0x0000343D
_021E5D60: .word 0x0000343A
_021E5D64: .word 0x00000678
_021E5D68: .word 0x00003424
_021E5D6C: .word 0x000033A0
_021E5D70: .word SEQ_SE_DP_CARD3
_021E5D74: .word 0x0000311C
_021E5D78: .word 0x000033CC
_021E5D7C: .word 0x00000674
_021E5D80: .word 0x000030F4
_021E5D84: .word 0x00003434
_021E5D88: .word 0x00003108
_021E5D8C: .word ov51_021E6B88
	thumb_func_end TrainerCardMainApp_Init

	thumb_func_start TrainerCardMainApp_Main
TrainerCardMainApp_Main: ; 0x021E5D90
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r5]
	add r4, r0, #0
	cmp r1, #5
	bhi _021E5E96
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E5DAE: ; jump table
	.short _021E5DBA - _021E5DAE - 2 ; case 0
	.short _021E5DC8 - _021E5DAE - 2 ; case 1
	.short _021E5E3A - _021E5DAE - 2 ; case 2
	.short _021E5E48 - _021E5DAE - 2 ; case 3
	.short _021E5E56 - _021E5DAE - 2 ; case 4
	.short _021E5E70 - _021E5DAE - 2 ; case 5
_021E5DBA:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5E96
	mov r0, #1
	str r0, [r5]
	b _021E5E96
_021E5DC8:
	bl ov51_021E6B44
	cmp r0, #3
	bne _021E5DDC
	ldr r0, _021E5EB8 ; =0x00003436
	mov r1, #0
	strb r1, [r4, r0]
	mov r0, #3
	str r0, [r5]
	b _021E5E26
_021E5DDC:
	cmp r0, #4
	bne _021E5DFA
	ldr r0, _021E5EBC ; =0x0000311C
	mov r1, #1
	add r0, r4, r0
	mov r2, #3
	add r3, r1, #0
	bl ov51_021E7D44
	ldr r0, _021E5EB8 ; =0x00003436
	mov r1, #0
	strb r1, [r4, r0]
	mov r0, #4
	str r0, [r5]
	b _021E5E26
_021E5DFA:
	cmp r0, #5
	bne _021E5E26
	ldr r0, _021E5EBC ; =0x0000311C
	mov r2, #1
	add r0, r4, r0
	mov r1, #0
	add r3, r2, #0
	bl ov51_021E7D44
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r1, #0x19
	str r1, [sp, #8]
	mov r1, #4
	add r2, r1, #0
	mov r3, #0
	bl BeginNormalPaletteFade
	mov r0, #2
	str r0, [r5]
_021E5E26:
	add r1, r4, #0
	add r1, #0xe8
	ldr r1, [r1]
	add r0, r4, #0
	ldrb r1, [r1, #4]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1f
	bl ov51_021E6DA8
	b _021E5E96
_021E5E3A:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5E96
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, pc}
_021E5E48:
	bl ov51_021E6888
	cmp r0, #0
	beq _021E5E96
	mov r0, #1
	str r0, [r5]
	b _021E5E96
_021E5E56:
	bl ov51_021E67A4
	cmp r0, #1
	beq _021E5E64
	cmp r0, #2
	beq _021E5E6A
	b _021E5E96
_021E5E64:
	mov r0, #1
	str r0, [r5]
	b _021E5E96
_021E5E6A:
	mov r0, #5
	str r0, [r5]
	b _021E5E96
_021E5E70:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r1, #0x19
	str r1, [sp, #8]
	mov r1, #4
	add r2, r1, #0
	mov r3, #0
	bl BeginNormalPaletteFade
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _021E5EC0 ; =0x00000674
	mov r2, #1
	str r2, [r1, r0]
	mov r0, #2
	str r0, [r5]
_021E5E96:
	ldr r0, _021E5EC4 ; =0x0000343F
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	ldrb r1, [r4, r0]
	cmp r1, #0x80
	blo _021E5EA8
	mov r1, #0
	strb r1, [r4, r0]
_021E5EA8:
	ldr r0, _021E5EBC ; =0x0000311C
	ldr r0, [r4, r0]
	bl SpriteList_RenderAndAnimateSprites
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_021E5EB8: .word 0x00003436
_021E5EBC: .word 0x0000311C
_021E5EC0: .word 0x00000674
_021E5EC4: .word 0x0000343F
	thumb_func_end TrainerCardMainApp_Main

	thumb_func_start TrainerCardMainApp_Exit
TrainerCardMainApp_Exit: ; 0x021E5EC8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	bl ov51_021E6C00
	add r0, r4, #0
	bl ov51_021E6038
	ldr r0, _021E5F4C ; =0x0000311C
	add r0, r4, r0
	bl ov51_021E7CA4
	ldr r0, _021E5F50 ; =0x000030EC
	ldr r0, [r4, r0]
	bl Heap_Free
	ldr r0, _021E5F54 ; =0x000033B8
	ldr r0, [r4, r0]
	bl Heap_Free
	ldr r0, _021E5F58 ; =0x000033B0
	ldr r0, [r4, r0]
	bl Heap_Free
	add r0, r4, #0
	bl ov51_021E6EF0
	ldr r0, [r4]
	bl ov51_021E6644
	bl sub_02021238
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	mov r0, #0
	bl TextFlags_SetCanABSpeedUpPrint
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _021E5F5C ; =0x0000066C
	ldr r0, [r1, r0]
	ldr r1, _021E5F60 ; =0x0000310C
	ldr r1, [r4, r1]
	bl MenuInputStateMgr_SetState
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0x19
	bl Heap_Destroy
	mov r0, #1
	mov r1, #0x7f
	bl GF_SndHandleSetPlayerVolume
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_021E5F4C: .word 0x0000311C
_021E5F50: .word 0x000030EC
_021E5F54: .word 0x000033B8
_021E5F58: .word 0x000033B0
_021E5F5C: .word 0x0000066C
_021E5F60: .word 0x0000310C
	thumb_func_end TrainerCardMainApp_Exit

	thumb_func_start ov51_021E5F64
ov51_021E5F64: ; 0x021E5F64
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #4
	mov r1, #0x19
	bl FontID_Alloc
	ldr r2, _021E6014 ; =0x000002D7
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x19
	bl NewMsgDataFromNarc
	ldr r1, _021E6018 ; =0x000033C4
	str r0, [r5, r1]
	mov r0, #4
	mov r1, #0x19
	bl String_New
	ldr r1, _021E601C ; =0x000033C8
	str r0, [r5, r1]
	mov r0, #0x20
	mov r1, #0x19
	bl String_New
	ldr r1, _021E6020 ; =0x000033D0
	str r0, [r5, r1]
	mov r0, #0xa
	mov r1, #0x19
	bl String_New
	ldr r1, _021E6024 ; =0x000033D4
	str r0, [r5, r1]
	mov r0, #5
	mov r1, #0x19
	bl String_New
	ldr r2, _021E6028 ; =0x000033CC
	mov r1, #0xb
	str r0, [r5, r2]
	add r0, r2, #0
	sub r0, #8
	ldr r0, [r5, r0]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	ldr r7, _021E602C ; =0x000033D8
	mov r6, #0
	add r4, r5, #0
_021E5FC4:
	ldr r0, _021E6018 ; =0x000033C4
	add r1, r6, #0
	ldr r0, [r5, r0]
	add r1, #0xe
	bl NewString_ReadMsgData
	str r0, [r4, r7]
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #3
	blt _021E5FC4
	ldr r7, _021E6030 ; =0x000033E4
	mov r4, #0
	add r6, r5, #0
_021E5FE0:
	ldr r0, _021E6018 ; =0x000033C4
	add r1, r4, #0
	ldr r0, [r5, r0]
	add r1, #0x11
	bl NewString_ReadMsgData
	str r0, [r6, r7]
	add r4, r4, #1
	add r6, r6, #4
	cmp r4, #2
	blt _021E5FE0
	ldr r7, _021E6034 ; =0x000033EC
	mov r4, #0
	add r6, r5, #0
_021E5FFC:
	ldr r0, _021E6018 ; =0x000033C4
	add r1, r4, #0
	ldr r0, [r5, r0]
	bl NewString_ReadMsgData
	str r0, [r6, r7]
	add r4, r4, #1
	add r6, r6, #4
	cmp r4, #0xe
	blt _021E5FFC
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6014: .word 0x000002D7
_021E6018: .word 0x000033C4
_021E601C: .word 0x000033C8
_021E6020: .word 0x000033D0
_021E6024: .word 0x000033D4
_021E6028: .word 0x000033CC
_021E602C: .word 0x000033D8
_021E6030: .word 0x000033E4
_021E6034: .word 0x000033EC
	thumb_func_end ov51_021E5F64

	thumb_func_start ov51_021E6038
ov51_021E6038: ; 0x021E6038
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r7, _021E60A8 ; =0x000033EC
	mov r4, #0
	add r5, r6, #0
_021E6042:
	ldr r0, [r5, r7]
	bl String_Delete
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0xe
	blt _021E6042
	ldr r0, _021E60AC ; =0x000033E8
	ldr r0, [r6, r0]
	bl String_Delete
	ldr r0, _021E60B0 ; =0x000033E4
	ldr r0, [r6, r0]
	bl String_Delete
	ldr r0, _021E60B4 ; =0x000033E0
	ldr r0, [r6, r0]
	bl String_Delete
	ldr r0, _021E60B8 ; =0x000033DC
	ldr r0, [r6, r0]
	bl String_Delete
	ldr r0, _021E60BC ; =0x000033D8
	ldr r0, [r6, r0]
	bl String_Delete
	ldr r0, _021E60C0 ; =0x000033CC
	ldr r0, [r6, r0]
	bl String_Delete
	ldr r0, _021E60C4 ; =0x000033D4
	ldr r0, [r6, r0]
	bl String_Delete
	ldr r0, _021E60C8 ; =0x000033D0
	ldr r0, [r6, r0]
	bl String_Delete
	ldr r0, _021E60CC ; =0x000033C8
	ldr r0, [r6, r0]
	bl String_Delete
	ldr r0, _021E60D0 ; =0x000033C4
	ldr r0, [r6, r0]
	bl DestroyMsgData
	mov r0, #4
	bl FontID_Release
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E60A8: .word 0x000033EC
_021E60AC: .word 0x000033E8
_021E60B0: .word 0x000033E4
_021E60B4: .word 0x000033E0
_021E60B8: .word 0x000033DC
_021E60BC: .word 0x000033D8
_021E60C0: .word 0x000033CC
_021E60C4: .word 0x000033D4
_021E60C8: .word 0x000033D0
_021E60CC: .word 0x000033C8
_021E60D0: .word 0x000033C4
	thumb_func_end ov51_021E6038
