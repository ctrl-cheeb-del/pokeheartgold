#include "constants/mmodel.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "overlay_106.inc"
	.include "global.inc"
	.public _021E6D70
	.public ov106_021E5A44
	.public ov106_021E5A74
	.public ov106_021E5AA8
	.public ov106_021E5BBC
	.public ov106_021E5C30
	.public ov106_021E5CD0
	.public ov106_021E5D70
	.public ov106_021E5E0C
	.public ov106_021E5E5C
	.public ov106_021E5EE4
	.public ov106_021E5F24
	.public ov106_021E5F84
	.public ov106_021E6280
	.public ov106_021E62F4
	.public ov106_021E6418
	.public ov106_021E6520
	.public ov106_021E6634
	.public ov106_021E66B0
	.public ov106_021E66FC
	.public ov106_021E6814
	.public ov106_021E68F4
	.public ov106_021E6988
	.public ov106_021E69F0
	.public ov106_021E6A34
	.public ov106_021E6B30
	.public ov106_021E6D7C
	.public ov106_021E6D8C
	.public ov106_021E6DB0
	.public ov106_021E6DD8
	.public ov106_021E6E04
	.public ov106_021E6E2C
	.public ov106_021E6E50
	.public ov106_021E6E74
	.public ov106_021E6E9C
	.public ov106_021E6EC4
	.public ov106_021E6EE4
	.public ov106_021E6EFC
	.public ov106_021E6F24
	.public ov106_021E6F48
	.public ov106_021E6F5C
	.public ov106_021E6F74
	.public ov106_021E6F90
	.public ov106_021E6FAC
	.public ov106_021E6FC8
	.public ov106_021E6FE8
	.public ov106_021E7010
	.public ov106_021E7044
	.public ov106_021E7090
	.public ov106_021E70E0
	.public sScriptCinematicSubs_Arceus
	.public sScriptCinematicSubs_HoOh
	.public sScriptCinematicSubs_Lugia


	.text
	.public ScriptCinematic_Arceus
	.public ScriptCinematic_HoOh
	.public ScriptCinematic_Lugia
	.public ov106_021E5900
	.public ov106_021E594C
	.public ov106_021E5954
	.public ov106_021E597C
	.public ov106_021E59A4
	.public ov106_021E59D0
	.public ov106_021E59FC
	.public ov106_021E5D08
	.public ov106_021E5D38
	.public ov106_021E5D48
	.public ov106_021E5DFC
	.public ov106_021E601C
	.public ov106_021E6064
	.public ov106_021E60B0
	.public ov106_021E6104
	.public ov106_021E6118
	.public ov106_021E6130
	.public ov106_021E61B8
	.public ov106_021E61F8
	.public ov106_021E62C8
	.public ov106_021E62DC
	.public ov106_021E63E0
	.public ov106_021E6408
	.public ov106_021E64FC
	.public ov106_021E664C
	.public ov106_021E6668
	.public ov106_021E6678
	.public ov106_021E6694
	.public ov106_021E68A8
	.public ov106_021E68DC
	.public ov106_021E6A80
	.public ov106_021E6AB0
	.public ov106_021E6AD0
	.public ov106_021E6AF0
	.public ov106_021E6B10
	.public ov106_021E6B50
	.public ov106_021E6BB0
	.public ov106_021E6BD4
	.public ov106_021E6BF8
	.public ov106_021E6C28
	.public ov106_021E6C5C
	.public ov106_021E6C88
	.public ov106_021E6CA8
	.public ov106_021E6CC4
	.public ov106_021E6CF8
	.public ov106_021E6D1C
	.public ov106_021E6D48
	.public ov106_021E6D6C

	thumb_func_start ov106_021E66B0
ov106_021E66B0: ; 0x021E66B0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	cmp r5, #0
	ble _021E66C2
	ldr r1, _021E66F4 ; =NATIONAL_DEX_COUNT
	cmp r5, r1
	ble _021E66C6
_021E66C2:
	mov r4, #MMODEL_BABYGIRL1
	b _021E66EE
_021E66C6:
	bl SpeciesToOverworldModelIndexOffset
	ldr r1, _021E66F8 ; =MMODEL_FOLLOWER_MON_BULBASAUR
	add r4, r0, r1
	add r0, r5, #0
	bl OverworldModelLookupHasFemaleForm
	cmp r0, #0
	beq _021E66E0
	cmp r7, #1
	bne _021E66EE
	add r4, r4, #1
	b _021E66EE
_021E66E0:
	add r0, r5, #0
	bl OverworldModelLookupFormCount
	cmp r6, r0
	ble _021E66EC
	mov r6, #0
_021E66EC:
	add r4, r4, r6
_021E66EE:
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E66F4: .word NATIONAL_DEX_COUNT
_021E66F8: .word MMODEL_FOLLOWER_MON_BULBASAUR
	thumb_func_end ov106_021E66B0


	thumb_func_start ov106_021E66FC
ov106_021E66FC: ; 0x021E66FC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	ldr r1, _021E680C ; =0x00000418
	ldr r1, [r0, r1]
	ldr r0, [r0]
	str r1, [sp, #0x18]
	ldr r0, [r0]
	bl SaveArray_Party_Get
	add r4, r0, #0
	bl Party_GetCount
	cmp r0, #0
	bne _021E6720
	mov r5, #0
	mov r4, #2
	str r5, [sp, #0x14]
	b _021E6764
_021E6720:
	add r0, r4, #0
	mov r1, #0
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r6, r0, #0
	bl GetMonData
	ldr r1, _021E6810 ; =0x000001ED
	cmp r0, r1
	bne _021E675E
	add r0, r6, #0
	mov r1, #0x6f
	mov r2, #0
	bl GetMonData
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	add r0, r6, #0
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	add r0, r6, #0
	bl MonIsShiny
	str r0, [sp, #0x14]
	b _021E6764
_021E675E:
	mov r5, #0
	mov r4, #2
	str r5, [sp, #0x14]
_021E6764:
	ldr r0, _021E6810 ; =0x000001ED
	add r1, r5, #0
	add r2, r4, #0
	bl ov106_021E66B0
	add r1, r0, #0
	mov r0, #0x51 ; mmodel.narc
	mov r2, #0x99
	bl AllocAndReadWholeNarcMemberByIdPair
	str r0, [sp, #0xc]
	bl NNS_G3dGetTex
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x18]
	ldr r0, [r0, #0x10]
	ldr r0, [r0]
	bl Sprite_GetImageProxy
	mov r1, #1
	bl NNS_G2dGetImageLocation
	add r5, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [r0, #0x14]
	add r4, r0, r1
	mov r1, #2
	mov r0, #0x99
	lsl r1, r1, #0xa
	bl Heap_Alloc
	add r6, r0, #0
	mov r7, #0
_021E67A6:
	mov r0, #8
	str r0, [sp]
	str r0, [sp, #4]
	mov r2, #0
	add r0, r4, #0
	mov r1, #8
	add r3, r2, #0
	str r6, [sp, #8]
	bl sub_020145B4
	mov r2, #2
	add r0, r6, #0
	add r1, r5, #0
	lsl r2, r2, #0xa
	bl ov106_021E6678
	mov r0, #2
	lsl r0, r0, #0xa
	add r7, r7, #1
	add r4, r4, r0
	add r5, r5, r0
	cmp r7, #8
	blo _021E67A6
	add r0, r6, #0
	bl Heap_Free
	ldr r0, [sp, #0x18]
	ldr r0, [r0, #0x10]
	ldr r0, [r0]
	bl Sprite_GetPaletteProxy
	mov r1, #1
	bl NNS_G2dGetImagePaletteLocation
	add r1, r0, #0
	ldr r0, [sp, #0x10]
	ldr r2, [r0, #0x38]
	add r0, r0, r2
	ldr r2, [sp, #0x14]
	cmp r2, #1
	bne _021E67FA
	add r0, #0x20
_021E67FA:
	mov r2, #0x20
	bl ov106_021E6694
	ldr r0, [sp, #0xc]
	bl Heap_Free
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_021E680C: .word 0x00000418
_021E6810: .word 0x000001ED
	thumb_func_end ov106_021E66FC


	thumb_func_start ov106_021E6814
ov106_021E6814: ; 0x021E6814
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	mov r0, #0
	bl GfGfx_EngineASetPlanes
	mov r0, #0
	bl GfGfx_EngineBSetPlanes
	ldr r0, _021E688C ; =0x04000050
	mov r1, #0
	strh r1, [r0]
	ldr r0, _021E6890 ; =0x04001050
	ldr r2, _021E6894 ; =0x04000304
	strh r1, [r0]
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	orr r0, r1
	strh r0, [r2]
	ldr r1, _021E6898 ; =0x00006040
	mov r0, #0x99
	bl Heap_Alloc
	ldr r1, _021E689C ; =0x00000418
	ldr r2, _021E6898 ; =0x00006040
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, _021E689C ; =0x00000418
	mov r1, #0x99
	ldr r4, [r5, r0]
	ldr r0, _021E68A0 ; =ov106_021E70E0
	str r0, [r4, #0x14]
	mov r0, #0xf7
	bl NARC_New
	str r0, [r4, #4]
	bl ov106_021E6408
	add r0, r4, #0
	bl ov106_021E6418
	add r0, r5, #0
	bl ov106_021E6520
	ldr r1, _021E689C ; =0x00000418
	ldr r0, _021E68A4 ; =ov106_021E63E0
	ldr r1, [r5, r1]
	bl Main_SetVBlankIntrCB
	mov r0, #4
	pop {r3, r4, r5, pc}
	nop
_021E688C: .word 0x04000050
_021E6890: .word 0x04001050
_021E6894: .word 0x04000304
_021E6898: .word 0x00006040
_021E689C: .word 0x00000418
_021E68A0: .word ov106_021E70E0
_021E68A4: .word ov106_021E63E0
	thumb_func_end ov106_021E6814
