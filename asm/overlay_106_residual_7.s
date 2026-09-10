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

	thumb_func_start ov106_021E6520
ov106_021E6520: ; 0x021E6520
	push {r4, r5, r6, r7, lr}
	sub sp, #0x5c
	add r7, r0, #0
	ldr r0, _021E661C ; =0x00000418
	ldr r4, [r7, r0]
	mov r0, #0x99
	bl SpriteSystem_Alloc
	str r0, [r4, #8]
	bl SpriteManager_New
	add r2, sp, #0x3c
	ldr r3, _021E6620 ; =ov106_021E6FC8
	str r0, [r4, #0xc]
	ldmia r3!, {r0, r1}
	add r6, r2, #0
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	ldr r5, _021E6624 ; =ov106_021E6F48
	stmia r2!, {r0, r1}
	add r3, sp, #0x28
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r6, #0
	str r0, [r3]
	ldr r0, [r4, #8]
	mov r3, #0x20
	bl SpriteSystem_Init
	ldr r3, _021E6628 ; =ov106_021E6F5C
	add r2, sp, #0x10
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	mov r2, #1
	bl SpriteSystem_InitSprites
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	add r2, sp, #0x10
	bl SpriteSystem_InitManagerWithCapacities
	ldr r0, [r4, #8]
	bl SpriteSystem_GetRenderer
	mov r2, #1
	mov r1, #0
	lsl r2, r2, #0x16
	bl G2dRenderer_SetSubSurfaceCoords
	mov r0, #1
	str r0, [sp]
	ldr r0, _021E662C ; =0x0000C8E9
	mov r3, #0xcd
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	ldr r2, [r4, #4]
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, _021E662C ; =0x0000C8E9
	mov r3, #0xce
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	ldr r2, [r4, #4]
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, _021E662C ; =0x0000C8E9
	mov r3, #0xcf
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	ldr r2, [r4, #4]
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E662C ; =0x0000C8E9
	mov r3, #0xcc
	str r0, [sp, #8]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	ldr r2, [r4, #4]
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	ldr r2, _021E6630 ; =ov106_021E7010
	bl SpriteSystem_NewSprite
	mov r1, #0
	str r0, [r4, #0x10]
	bl ManagedSprite_SetDrawFlag
	add r0, r7, #0
	bl ov106_021E66FC
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add sp, #0x5c
	pop {r4, r5, r6, r7, pc}
	nop
_021E661C: .word 0x00000418
_021E6620: .word ov106_021E6FC8
_021E6624: .word ov106_021E6F48
_021E6628: .word ov106_021E6F5C
_021E662C: .word 0x0000C8E9
_021E6630: .word ov106_021E7010
	thumb_func_end ov106_021E6520


	thumb_func_start ov106_021E6634
ov106_021E6634: ; 0x021E6634
	push {r3, r4, r5, lr}
	add r4, r0, #0
	lsl r5, r1, #2
	add r4, #0x10
	ldr r0, [r4, r5]
	cmp r0, #0
	beq _021E664A
	bl Sprite_DeleteAndFreeResources
	mov r0, #0
	str r0, [r4, r5]
_021E664A:
	pop {r3, r4, r5, pc}
	thumb_func_end ov106_021E6634
