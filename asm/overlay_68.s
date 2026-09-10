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

	thumb_func_start MoveRelearner_Init
MoveRelearner_Init: ; 0x021E5900
	push {r3, r4, r5, lr}
	mov r2, #9
	add r5, r0, #0
	mov r0, #3
	mov r1, #0x42
	lsl r2, r2, #0xe
	bl Heap_Create
	mov r1, #0x77
	add r0, r5, #0
	lsl r1, r1, #2
	mov r2, #0x42
	bl OverlayManager_CreateAndGetData
	mov r2, #0x77
	mov r1, #0
	lsl r2, r2, #2
	add r4, r0, #0
	bl memset
	add r0, r5, #0
	bl OverlayManager_GetArgs
	str r0, [r4]
	add r0, r4, #0
	bl ov68_021E5A58
	ldr r1, [r4]
	add r0, r4, #0
	ldrh r1, [r1, #0x14]
	mov r2, #3
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov68_021E73A4
	mov r0, #0x1b
	mov r1, #1
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r1, #0
	add r0, r4, #0
	add r2, r1, #0
	bl ov68_021E7424
	ldr r0, _021E5964 ; =ov68_021E5B6C
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E5964: .word ov68_021E5B6C
	thumb_func_end MoveRelearner_Init


	thumb_func_start MoveRelearner_Main
MoveRelearner_Main: ; 0x021E5968
	push {r3, r4, r5, lr}
	add r4, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r4]
	add r5, r0, #0
	cmp r1, #0xf
	bhi _021E5A22
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E5984: ; jump table
	.short _021E59A4 - _021E5984 - 2 ; case 0
	.short _021E59AC - _021E5984 - 2 ; case 1
	.short _021E59B4 - _021E5984 - 2 ; case 2
	.short _021E59BC - _021E5984 - 2 ; case 3
	.short _021E59C4 - _021E5984 - 2 ; case 4
	.short _021E59CC - _021E5984 - 2 ; case 5
	.short _021E59D4 - _021E5984 - 2 ; case 6
	.short _021E59DC - _021E5984 - 2 ; case 7
	.short _021E59E4 - _021E5984 - 2 ; case 8
	.short _021E59EC - _021E5984 - 2 ; case 9
	.short _021E59F0 - _021E5984 - 2 ; case 10
	.short _021E59F8 - _021E5984 - 2 ; case 11
	.short _021E5A02 - _021E5984 - 2 ; case 12
	.short _021E5A0C - _021E5984 - 2 ; case 13
	.short _021E5A14 - _021E5984 - 2 ; case 14
	.short _021E5A1C - _021E5984 - 2 ; case 15
_021E59A4:
	bl ov68_021E5F50
	str r0, [r4]
	b _021E5A22
_021E59AC:
	bl ov68_021E5F68
	str r0, [r4]
	b _021E5A22
_021E59B4:
	bl ov68_021E6058
	str r0, [r4]
	b _021E5A22
_021E59BC:
	bl ov68_021E6078
	str r0, [r4]
	b _021E5A22
_021E59C4:
	bl ov68_021E60D8
	str r0, [r4]
	b _021E5A22
_021E59CC:
	bl ov68_021E614C
	str r0, [r4]
	b _021E5A22
_021E59D4:
	bl ov68_021E61A0
	str r0, [r4]
	b _021E5A22
_021E59DC:
	bl ov68_021E61B8
	str r0, [r4]
	b _021E5A22
_021E59E4:
	bl ov68_021E61EC
	str r0, [r4]
	b _021E5A22
_021E59EC:
	mov r0, #1
	pop {r3, r4, r5, pc}
_021E59F0:
	bl ov68_021E74C0
	str r0, [r4]
	b _021E5A22
_021E59F8:
	bl ov68_021E74D8
	str r0, [r4]
	mov r0, #0
	pop {r3, r4, r5, pc}
_021E5A02:
	bl ov68_021E7568
	str r0, [r4]
	mov r0, #0
	pop {r3, r4, r5, pc}
_021E5A0C:
	bl ov68_021E7AD8
	str r0, [r4]
	b _021E5A22
_021E5A14:
	bl ov68_021E7B6C
	str r0, [r4]
	b _021E5A22
_021E5A1C:
	bl ov68_021E7B8C
	str r0, [r4]
_021E5A22:
	mov r0, #0x55
	lsl r0, r0, #2
	add r0, r5, r0
	bl ov68_021E734C
	mov r0, #0x12
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl SpriteSystem_DrawSprites
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end MoveRelearner_Main


	thumb_func_start MoveRelearner_Exit
MoveRelearner_Exit: ; 0x021E5A3C
	push {r4, lr}
	add r4, r0, #0
	bl OverlayManager_GetData
	bl ov68_021E5B14
	add r0, r4, #0
	bl OverlayManager_FreeData
	mov r0, #0x42
	bl Heap_Destroy
	mov r0, #1
	pop {r4, pc}
	thumb_func_end MoveRelearner_Exit


	thumb_func_start ov68_021E5A58
ov68_021E5A58: ; 0x021E5A58
	push {r3, r4, r5, lr}
	add r4, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _021E5B08 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021E5B0C ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r0, [r4]
	ldr r0, [r0, #0xc]
	bl MenuInputStateMgr_GetState
	mov r1, #0x6d
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0x42
	bl BgConfig_Alloc
	str r0, [r4, #4]
	mov r0, #0x6e
	mov r1, #0x42
	bl NARC_New
	add r5, r0, #0
	bl ov68_021E5BA0
	ldr r0, [r4, #4]
	bl ov68_021E5BC0
	add r0, r4, #0
	add r1, r5, #0
	bl ov68_021E5D24
	add r0, r4, #0
	add r1, r5, #0
	bl ov68_021E7178
	add r0, r4, #0
	bl ov68_021E7288
	add r0, r4, #0
	bl ov68_021E5EBC
	add r0, r4, #0
	bl ov68_021E5E48
	add r0, r4, #0
	bl ov68_021E6820
	add r0, r4, #0
	bl ov68_021E6204
	add r0, r4, #0
	bl ov68_021E6320
	add r0, r4, #0
	bl ov68_021E75C0
	mov r0, #0
	mov r1, #0x42
	bl sub_020880CC
	ldr r0, _021E5B10 ; =ov68_021E5B6C
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	add r0, r5, #0
	bl NARC_Delete
	pop {r3, r4, r5, pc}
	nop
_021E5B08: .word 0xFFFFE0FF
_021E5B0C: .word 0x04001000
_021E5B10: .word ov68_021E5B6C
	thumb_func_end ov68_021E5A58
