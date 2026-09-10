#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_73.inc"
	.include "global.inc"

	.text
	.public _021EA51C
	.public _021EA7C0
	.public _021EA940
	.public ov73_021E5900
	.public ov73_021E5AB8
	.public ov73_021E5BAC
	.public ov73_021E5C74
	.public ov73_021E5CD8
	.public ov73_021E5D00
	.public ov73_021E5D20
	.public ov73_021E5E0C
	.public ov73_021E5ED4
	.public ov73_021E5F38
	.public ov73_021E6060
	.public ov73_021E6090
	.public ov73_021E6184
	.public ov73_021E629C
	.public ov73_021E63BC
	.public ov73_021E6444
	.public ov73_021E6484
	.public ov73_021E64B0
	.public ov73_021E6508
	.public ov73_021E66F4
	.public ov73_021E671C
	.public ov73_021E6778
	.public ov73_021E67A8
	.public ov73_021E6830
	.public ov73_021E6890
	.public ov73_021E68AC
	.public ov73_021E69E8
	.public ov73_021E6A70
	.public ov73_021E6A90
	.public ov73_021E6AAC
	.public ov73_021E6B6C
	.public ov73_021E6BC8
	.public ov73_021E6C50
	.public ov73_021E6CC0
	.public ov73_021E6CDC
	.public ov73_021E6CFC
	.public ov73_021E6D38
	.public ov73_021E6D54
	.public ov73_021E6DF8
	.public ov73_021E6E48
	.public ov73_021E6E6C
	.public ov73_021E6E8C
	.public ov73_021E6ECC
	.public ov73_021E6EF8
	.public ov73_021E6F1C
	.public ov73_021E6FAC
	.public ov73_021E6FE8
	.public ov73_021E705C
	.public ov73_021E7120
	.public ov73_021E71E4
	.public ov73_021E7230
	.public ov73_021E72F4
	.public ov73_021E735C
	.public ov73_021E7490
	.public ov73_021E756C
	.public ov73_021E762C
	.public ov73_021E7740
	.public ov73_021E77A4
	.public ov73_021E781C
	.public ov73_021E7870
	.public ov73_021E7964
	.public ov73_021E79A8
	.public ov73_021E79F4
	.public ov73_021E7A8C
	.public ov73_021E7AC0
	.public ov73_021E7B3C
	.public ov73_021E7B84
	.public ov73_021E7BC8
	.public ov73_021E7C0C
	.public ov73_021E7C50
	.public ov73_021E7C94
	.public ov73_021E7CD8
	.public ov73_021E7D74
	.public ov73_021E7E24
	.public ov73_021E7E4C
	.public ov73_021E7FB8
	.public ov73_021E808C
	.public ov73_021E8100
	.public ov73_021E8128
	.public ov73_021E8168
	.public ov73_021E8198
	.public ov73_021E82D4
	.public ov73_021E8390
	.public ov73_021E847C
	.public ov73_021E84D0
	.public ov73_021E85AC
	.public ov73_021E85DC
	.public ov73_021E8628
	.public ov73_021E8730
	.public ov73_021E8960
	.public ov73_021E8A08
	.public ov73_021E8B20
	.public ov73_021E8B64
	.public ov73_021E8BBC
	.public ov73_021E8CBC
	.public ov73_021E8D2C
	.public ov73_021E8DC8
	.public ov73_021E8E7C
	.public ov73_021E8ED8
	.public ov73_021E8FE4
	.public ov73_021E9144
	.public ov73_021E9224
	.public ov73_021E926C
	.public ov73_021E9378
	.public ov73_021E944C
	.public ov73_021E95CC
	.public ov73_021E9618
	.public ov73_021E9758
	.public ov73_021E97A8
	.public ov73_021E98AC
	.public ov73_021E98FC
	.public ov73_021E9A6C
	.public ov73_021E9D14
	.public ov73_021E9D6C
	.public ov73_021E9DE0
	.public ov73_021E9ECC
	.public ov73_021E9F34
	.public ov73_021E9F9C
	.public ov73_021E9FC8
	.public ov73_021E9FF8
	.public ov73_021EA050
	.public ov73_021EA088
	.public ov73_021EA0BC
	.public ov73_021EA0F0
	.public ov73_021EA19C
	.public ov73_021EA218
	.public ov73_021EA268
	.public ov73_021EA2B4
	.public ov73_021EA2E0
	.public ov73_021EA324
	.public ov73_021EA374
	.public ov73_021EA3D0
	.public ov73_021EA520
	.public ov73_021EA52A
	.public ov73_021EA52B
	.public ov73_021EA534
	.public ov73_021EA540
	.public ov73_021EA550
	.public ov73_021EA560
	.public ov73_021EA578
	.public ov73_021EA594
	.public ov73_021EA5B0
	.public ov73_021EA5CC
	.public ov73_021EA5E8
	.public ov73_021EA610
	.public ov73_021EA618
	.public ov73_021EA624
	.public ov73_021EA630
	.public ov73_021EA640
	.public ov73_021EA650
	.public ov73_021EA664
	.public ov73_021EA684
	.public ov73_021EA68C
	.public ov73_021EA69C
	.public ov73_021EA6AC
	.public ov73_021EA6D4
	.public ov73_021EA6F0
	.public ov73_021EA70C
	.public ov73_021EA728
	.public ov73_021EA744
	.public ov73_021EA83C
	.public ov73_021EA840
	.public ov73_021EA844
	.public ov73_021EA848

	.public ov73_021E5F0C
	.public ov73_021E6048
	.public ov73_021E6400
	.public ov73_021E66F0
	.public ov73_021E670C
	.public ov73_021E69D0
	.public ov73_021E6B98
	.public ov73_021E6BF8
	.public ov73_021E6C20
	.public ov73_021E7340
	.public ov73_021E7468
	.public ov73_021E746C
	.public ov73_021E7488
	.public ov73_021E75FC
	.public ov73_021E761C
	.public ov73_021E77E8
	.public ov73_021E7818
	.public ov73_021E795C
	.public ov73_021E7960
	.public ov73_021E7A74
	.public ov73_021E7A7C
	.public ov73_021E7A84
	.public ov73_021E7D54
	.public ov73_021E8148
	.public ov73_021E8164
	.public ov73_021E82A8
	.public ov73_021E83D4
	.public ov73_021E83EC
	.public ov73_021E83F4
	.public ov73_021E841C
	.public ov73_021E8440
	.public ov73_021E844C
	.public ov73_021E8454
	.public ov73_021E870C
	.public ov73_021E8BFC
	.public ov73_021E8C2C
	.public ov73_021E8C8C
	.public ov73_021E8D0C
	.public ov73_021E8DB8
	.public ov73_021E8EBC
	.public ov73_021E8FB0
	.public ov73_021E9120
	.public ov73_021E91F4
	.public ov73_021E93EC
	.public ov73_021E941C
	.public ov73_021E955C
	.public ov73_021E9598
	.public ov73_021E96EC
	.public ov73_021E9728
	.public ov73_021E987C
	.public ov73_021E99D4
	.public ov73_021E9A3C
	.public ov73_021E9B58
	.public ov73_021E9B94
	.public ov73_021E9B9C
	.public ov73_021E9BB4
	.public ov73_021E9BD4
	.public ov73_021E9C04
	.public ov73_021E9C30
	.public ov73_021E9C60
	.public ov73_021E9C8C
	.public ov73_021E9CBC
	.public ov73_021E9CD8
	.public ov73_021E9D10
	.public ov73_021E9D44
	.public ov73_021E9EAC
	.public ov73_021E9F00
	.public ov73_021EA12C
	.public ov73_021EA134
	.public ov73_021EA15C
	.public ov73_021EA180
	.public ov73_021EA25C
	.public ov73_021EA290
	.public ov73_021EA2A8
	.public ov73_021EA2FC
	.public ov73_021EA31C
	.public ov73_021EA348
	.public ov73_021EA370

	thumb_func_start ov73_021E7D74
ov73_021E7D74: ; 0x021E7D74
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	str r0, [sp]
	ldr r0, [sp, #0x44]
	str r1, [sp, #4]
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x48]
	add r7, r2, #0
	str r0, [sp, #0x48]
	add r0, sp, #0x1c
	mov r1, #0
	mov r2, #0x10
	str r3, [sp, #8]
	ldr r5, [sp, #0x40]
	bl MI_CpuFill8
	mov r4, #0
	add r6, r4, #0
	cmp r7, #0
	ble _021E7E18
	str r5, [sp, #0x14]
_021E7D9E:
	ldr r0, [sp, #0x14]
	ldr r0, [r0]
	cmp r0, #0
	beq _021E7E0C
	mov r0, #0
	str r0, [sp, #0x18]
	str r0, [sp, #0x10]
	b _021E7E06
_021E7DAE:
	add r0, r4, #1
	add r1, r7, #0
	bl _s32_div_f
	add r4, r1, #0
_021E7DB8:
	lsl r0, r4, #2
	str r0, [sp, #0xc]
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021E7DAE
	cmp r4, r6
	beq _021E7DAE
	add r0, sp, #0x1c
	ldrb r0, [r0, r4]
	cmp r0, #4
	beq _021E7DAE
	add r1, r0, #1
	add r0, sp, #0x1c
	strb r1, [r0, r4]
	ldr r0, [sp, #8]
	cmp r4, r0
	beq _021E7DFA
	ldr r2, [sp, #0x44]
	add r0, r4, #0
	add r1, r5, #0
	bl ov73_021E7D54
	add r3, r0, #0
	beq _021E7DFA
	ldr r2, [sp, #0xc]
	ldr r0, [sp]
	ldr r3, [r3, r2]
	ldr r2, [sp, #0x10]
	ldr r1, [sp, #4]
	add r2, r3, r2
	ldr r3, [sp, #0x48]
	bl ov73_021E7CD8
_021E7DFA:
	ldr r0, [sp, #0x10]
	add r0, #0x48
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
_021E7E06:
	ldr r0, [sp, #0x18]
	cmp r0, #4
	blt _021E7DB8
_021E7E0C:
	ldr r0, [sp, #0x14]
	add r6, r6, #1
	add r0, r0, #4
	str r0, [sp, #0x14]
	cmp r6, r7
	blt _021E7D9E
_021E7E18:
	mov r0, #0x17
	bl SaveSubstruct_UpdateCRC
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov73_021E7D74


	thumb_func_start ov73_021E7E24
ov73_021E7E24: ; 0x021E7E24
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r1, #0
	ldr r1, [sp, #0x18]
	str r3, [sp]
	str r1, [sp, #4]
	add r4, r2, #0
	mov r1, #0
	str r1, [sp, #8]
	ldr r1, _021E7E48 ; =0x0000090C
	add r2, r5, #0
	add r0, r0, r1
	mov r1, #8
	add r3, r4, #0
	bl ov73_021E7D74
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_021E7E48: .word 0x0000090C
	thumb_func_end ov73_021E7E24


	thumb_func_start ov73_021E7E4C
ov73_021E7E4C: ; 0x021E7E4C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r1, #0
	add r6, r0, #0
	ldr r0, [r5]
	cmp r0, #0
	beq _021E7E62
	cmp r0, #1
	bne _021E7E60
	b _021E7F62
_021E7E60:
	b _021E7F78
_021E7E62:
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _021E7F80 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021E7F84 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	mov r2, #5
	mov r0, #3
	mov r1, #0x96
	lsl r2, r2, #0x10
	bl Heap_Create
	ldr r1, _021E7F88 ; =0x000012CC
	add r0, r6, #0
	mov r2, #0x96
	bl OverlayManager_CreateAndGetData
	ldr r2, _021E7F88 ; =0x000012CC
	mov r1, #0
	add r4, r0, #0
	bl memset
	mov r0, #0x96
	bl BgConfig_Alloc
	str r0, [r4, #4]
	ldr r0, _021E7F8C ; =_021EA940
	add r2, sp, #0
	ldr r3, _021E7F90 ; =ov73_021EA68C
	str r4, [r0]
	add r7, r2, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	add r0, r7, #0
	bl SetBothScreensModesAndDisable
	mov r0, #0xb
	mov r1, #0x20
	mov r2, #0x96
	bl MessageFormat_New_Custom
	mov r1, #0xbd
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r2, _021E7F94 ; =0x0000031F
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x96
	bl NewMsgDataFromNarc
	ldr r1, _021E7F98 ; =0x00000BD4
	ldr r2, _021E7F9C ; =0x0000030A
	str r0, [r4, r1]
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x96
	bl NewMsgDataFromNarc
	ldr r1, _021E7FA0 ; =0x00000BD8
	mov r2, #0x32
	str r0, [r4, r1]
	mov r0, #0
	mov r1, #0x1b
	lsl r2, r2, #4
	mov r3, #0x96
	bl NewMsgDataFromNarc
	ldr r1, _021E7FA4 ; =0x00000BDC
	str r0, [r4, r1]
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	add r0, r4, #0
	add r1, r6, #0
	bl ov73_021E8148
	add r0, r4, #0
	bl ov73_021E8454
	mov r1, #0
	mov r0, #0x34
	add r2, r1, #0
	bl Sound_SetSceneAndPlayBGM
	ldr r1, _021E7FA8 ; =0x00020020
	mov r0, #0x96
	bl Heap_Alloc
	str r0, [r4, #0x24]
	add r0, #0x1f
	mov r1, #0x1f
	bic r0, r1
	mov r1, #2
	lsl r1, r1, #0x10
	mov r2, #0
	bl NNS_FndCreateExpHeapEx
	str r0, [r4, #0x28]
	ldr r1, _021E7FAC ; =0x0000047D
	mov r0, #0xb
	mov r2, #1
	bl Sound_SetSceneAndPlayBGM
	ldr r2, _021E7FB0 ; =0x04000304
	ldr r0, _021E7FB4 ; =0xFFFF7FFF
	ldrh r1, [r2]
	and r0, r1
	strh r0, [r2]
	mov r0, #1
	str r0, [r5]
	b _021E7F78
_021E7F62:
	bl LoadDwcOverlay
	bl LoadOVY38
	bl sub_02034D8C
	mov r0, #0
	str r0, [r5]
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E7F78:
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7F80: .word 0xFFFFE0FF
_021E7F84: .word 0x04001000
_021E7F88: .word 0x000012CC
_021E7F8C: .word _021EA940
_021E7F90: .word ov73_021EA68C
_021E7F94: .word 0x0000031F
_021E7F98: .word 0x00000BD4
_021E7F9C: .word 0x0000030A
_021E7FA0: .word 0x00000BD8
_021E7FA4: .word 0x00000BDC
_021E7FA8: .word 0x00020020
_021E7FAC: .word 0x0000047D
_021E7FB0: .word 0x04000304
_021E7FB4: .word 0xFFFF7FFF
	thumb_func_end ov73_021E7E4C


	thumb_func_start ov73_021E7FB8
ov73_021E7FB8: ; 0x021E7FB8
	push {r4, r5, r6, lr}
	add r4, r1, #0
	bl OverlayManager_GetData
	add r5, r0, #0
	bl ov00_021ECB40
	bl ov72_022378DC
	bl ov00_021ECB40
	ldr r1, [r4]
	cmp r1, #5
	bhi _021E8060
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E7FE0: ; jump table
	.short _021E7FEC - _021E7FE0 - 2 ; case 0
	.short _021E8008 - _021E7FE0 - 2 ; case 1
	.short _021E801C - _021E7FE0 - 2 ; case 2
	.short _021E802A - _021E7FE0 - 2 ; case 3
	.short _021E803E - _021E7FE0 - 2 ; case 4
	.short _021E805C - _021E7FE0 - 2 ; case 5
_021E7FEC:
	bl sub_02034DB8
	cmp r0, #0
	beq _021E8060
	ldr r1, [r5, #0x28]
	ldr r0, _021E8070 ; =_021EA940
	str r1, [r0, #4]
	ldr r0, _021E8074 ; =ov73_021E83F4
	ldr r1, _021E8078 ; =ov73_021E841C
	bl ov00_021EC294
	mov r0, #1
	str r0, [r4]
	b _021E8060
_021E8008:
	ldr r3, [r5, #0x10]
	mov r2, #0xc
	add r6, r3, #0
	mul r6, r2
	ldr r2, _021E807C ; =ov73_021EA83C
	add r0, r5, #0
	ldr r2, [r2, r6]
	blx r2
	str r0, [r4]
	b _021E8060
_021E801C:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E8060
	mov r0, #3
	str r0, [r4]
	b _021E8060
_021E802A:
	ldr r3, [r5, #0x10]
	mov r2, #0xc
	add r6, r3, #0
	mul r6, r2
	ldr r2, _021E8080 ; =ov73_021EA840
	add r0, r5, #0
	ldr r2, [r2, r6]
	blx r2
	str r0, [r4]
	b _021E8060
_021E803E:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E8060
	ldr r3, [r5, #0x10]
	mov r2, #0xc
	add r6, r3, #0
	mul r6, r2
	ldr r2, _021E8084 ; =ov73_021EA844
	ldr r1, [r4]
	ldr r2, [r2, r6]
	add r0, r5, #0
	blx r2
	str r0, [r4]
	b _021E8060
_021E805C:
	mov r0, #1
	pop {r4, r5, r6, pc}
_021E8060:
	ldr r0, _021E8088 ; =0x00000BF8
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021E806C
	bl SpriteList_RenderAndAnimateSprites
_021E806C:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E8070: .word _021EA940
_021E8074: .word ov73_021E83F4
_021E8078: .word ov73_021E841C
_021E807C: .word ov73_021EA83C
_021E8080: .word ov73_021EA840
_021E8084: .word ov73_021EA844
_021E8088: .word 0x00000BF8
	thumb_func_end ov73_021E7FB8


	thumb_func_start ov73_021E808C
ov73_021E808C: ; 0x021E808C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, [r4, #0x24]
	bl Heap_Free
	bl UnloadOVY38
	bl UnloadDwcOverlay
	add r0, r4, #0
	bl ov73_021E847C
	ldr r0, _021E80F4 ; =0x00000BDC
	ldr r0, [r4, r0]
	bl DestroyMsgData
	ldr r0, _021E80F8 ; =0x00000BD8
	ldr r0, [r4, r0]
	bl DestroyMsgData
	ldr r0, _021E80FC ; =0x00000BD4
	ldr r0, [r4, r0]
	bl DestroyMsgData
	mov r0, #0xbd
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl MessageFormat_Delete
	add r0, r4, #0
	bl ov73_021E8164
	bl sub_02034DE0
	ldr r0, [r4, #4]
	bl Heap_Free
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0x96
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E80F4: .word 0x00000BDC
_021E80F8: .word 0x00000BD8
_021E80FC: .word 0x00000BD4
	thumb_func_end ov73_021E808C


	thumb_func_start ov73_021E8100
ov73_021E8100: ; 0x021E8100
	push {r4, lr}
	add r4, r0, #0
	bl GF_RunVramTransferTasks
	ldr r0, [r4, #4]
	bl DoScheduledBgGpuUpdates
	bl OamManager_ApplyAndResetBuffers
	ldr r3, _021E8120 ; =0x027E0000
	ldr r1, _021E8124 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_021E8120: .word 0x027E0000
_021E8124: .word 0x00003FF8
	thumb_func_end ov73_021E8100


	thumb_func_start ov73_021E8128
ov73_021E8128: ; 0x021E8128
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _021E8144 ; =ov73_021EA6AC
	add r3, sp, #0
	mov r2, #5
_021E8132:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E8132
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_021E8144: .word ov73_021EA6AC
	thumb_func_end ov73_021E8128
