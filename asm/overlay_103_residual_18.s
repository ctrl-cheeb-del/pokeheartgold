	.include "asm/macros.inc"
	.include "overlay_103.inc"
	.include "global.inc"

	.text
	.public _021EEB34
	.public ov103_021EC9B4
	.public ov103_021EC9E8
	.public ov103_021ECC1C
	.public ov103_021ECD68
	.public ov103_021ECF68
	.public ov103_021ED00C
	.public ov103_021ED0C0
	.public ov103_021ED144
	.public ov103_021ED4D4
	.public ov103_021ED5B4
	.public ov103_021ED7E4
	.public ov103_021ED9AC
	.public ov103_021EDA98
	.public ov103_021EDD54
	.public ov103_021EDD98
	.public ov103_021EDE7C
	.public ov103_021EDEA8
	.public ov103_021EDF88
	.public ov103_021EE078
	.public ov103_021EE160
	.public ov103_021EE210
	.public ov103_021EE2E0
	.public ov103_021EE468
	.public ov103_021EE550
	.public ov103_021EE644
	.public ov103_021EE7DC
	.public ov103_021EE8A8
	.public ov103_021EE930
	.public ov103_021EE9C8
	.public ov103_021EEB40
	.public ov103_021EEB50
	.public ov103_021EEB6C
	.public ov103_021EEB88
	.public ov103_021EEBA4
	.public ov103_021EEBC0
	.public ov103_021EEBDC
	.public ov103_021EEBF8
	.public ov103_021EEC14
	.public ov103_021EEC30
	.public ov103_021EEC58
	.public ov103_021EEC68
	.public ov103_021EEC78
	.public ov103_021EECA8
	.public ov103_021EED0C
	.public ov103_021EED20
	.public ov103_021EED38
	.public ov103_021EED58
	.public ov103_021EEEC4
	.public ov103_021EEFB4
	.public ov103_021EEFBC
	.public ov103_021EEFC8
	.public ov103_021EEFD8
	.public ov103_021EF008
	.public ov103_021EC940
	.public ov103_021EC988
	.public ov103_021EC9A4
	.public ov103_021EC9D8
	.public ov103_021ECBBC
	.public ov103_021ECD18
	.public ov103_021ECE0C
	.public ov103_021ECE18
	.public ov103_021ECE54
	.public ov103_021ECE80
	.public ov103_021ECE94
	.public ov103_021ECEA4
	.public ov103_021ECEEC
	.public ov103_021ECF48
	.public ov103_021ECFFC
	.public ov103_021ED0A0
	.public ov103_021ED124
	.public ov103_021ED23C
	.public ov103_021ED2B8
	.public ov103_021ED2D4
	.public ov103_021ED314
	.public ov103_021ED3E8
	.public ov103_021ED460
	.public ov103_021ED47C
	.public ov103_021ED53C
	.public ov103_021ED550
	.public ov103_021ED568
	.public ov103_021ED5A8
	.public ov103_021ED750
	.public ov103_021ED760
	.public ov103_021ED7A4
	.public ov103_021ED7D8
	.public ov103_021ED8D0
	.public ov103_021ED8F8
	.public ov103_021ED930
	.public ov103_021ED93C
	.public ov103_021ED954
	.public ov103_021ED960
	.public ov103_021ED97C
	.public ov103_021ED99C
	.public ov103_021ED9D8
	.public ov103_021EDA14
	.public ov103_021EDA40
	.public ov103_021EDA70
	.public ov103_021EDA84
	.public ov103_021EDB18
	.public ov103_021EDB60
	.public ov103_021EDBB0
	.public ov103_021EDBC8
	.public ov103_021EDC00
	.public ov103_021EDC58
	.public ov103_021EDC68
	.public ov103_021EDCC8
	.public ov103_021EDCE0
	.public ov103_021EDD14
	.public ov103_021EDD48
	.public ov103_021EDDE4
	.public ov103_021EDE5C
	.public ov103_021EDF50
	.public ov103_021EDF68
	.public ov103_021EE028
	.public ov103_021EE048
	.public ov103_021EE094
	.public ov103_021EE0AC
	.public ov103_021EE0CC
	.public ov103_021EE0F8
	.public ov103_021EE110
	.public ov103_021EE13C
	.public ov103_021EE150
	.public ov103_021EE374
	.public ov103_021EE390
	.public ov103_021EE3C0
	.public ov103_021EE3E4
	.public ov103_021EE430
	.public ov103_021EE60C
	.public ov103_021EE628
	.public ov103_021EE784
	.public ov103_021EE824
	.public ov103_021EE860
	.public ov103_021EE888
	.public ov103_021EEA24
	.public ov103_021EEA48
	.public ov103_021EEAA0
	.public ov103_021EEAB0
	.public ov103_021EEAB4
	.public ov103_021EEAB8
	.public ov103_021EEAC0
	.public ov103_021EEAC8
	.public ov103_021EEB04

	thumb_func_start ov103_021EE160
ov103_021EE160: ; 0x021EE160
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r4, _021EE208 ; =0x000037F0
	add r5, r0, #0
	mov r6, #0
	mov r7, #2
_021EE16C:
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	bl GetMonIconNaixEx
	str r6, [sp]
	add r3, r0, #0
	str r7, [sp, #4]
	mov r0, #0x25
	mov r1, #0x95
	mov r2, #0x9d
	str r4, [sp, #8]
	lsl r0, r0, #4
	lsl r1, r1, #2
	lsl r2, r2, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	ldr r0, _021EE20C ; =0x000037F2
	add r4, r4, #1
	cmp r4, r0
	bls _021EE16C
	bl sub_02074490
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r0, _021EE208 ; =0x000037F0
	mov r2, #0x25
	lsl r2, r2, #4
	str r0, [sp, #0xc]
	add r1, r2, #4
	ldr r0, [r5, r2]
	add r2, #0x24
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	bl sub_02074494
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _021EE208 ; =0x000037F0
	mov r2, #0x25
	lsl r2, r2, #4
	str r0, [sp, #4]
	add r1, r2, #4
	ldr r0, [r5, r2]
	add r2, #0x24
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	bl sub_02074498
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _021EE208 ; =0x000037F0
	mov r2, #0x25
	lsl r2, r2, #4
	str r0, [sp, #4]
	add r1, r2, #4
	ldr r0, [r5, r2]
	add r2, #0x24
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021EE208: .word 0x000037F0
_021EE20C: .word 0x000037F2
	thumb_func_end ov103_021EE160


	thumb_func_start ov103_021EE210
ov103_021EE210: ; 0x021EE210
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	ldrb r0, [r5, #0x1f]
	mov r4, #0
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	add r1, r1, r0
	mov r0, #0x9f
	lsl r0, r0, #2
	ldr r7, [r1, r0]
	add r6, r4, #0
_021EE228:
	add r0, r7, #0
	bl sub_0202B4E4
	lsl r1, r4, #0x18
	add r3, r0, #0
	add r0, r7, #0
	lsr r1, r1, #0x18
	mov r2, #2
	bl sub_0202B404
	add r1, sp, #0x10
	strh r0, [r1]
	add r0, r1, #0
	ldrh r1, [r0]
	ldr r0, _021EE2DC ; =0x0000FFFF
	cmp r1, r0
	beq _021EE254
	lsl r0, r1, #0x14
	lsr r0, r0, #0x14
	str r0, [sp, #4]
	cmp r0, #7
	bne _021EE260
_021EE254:
	ldr r0, [r5, #0xc]
	add r1, r4, #4
	mov r2, #0
	bl ov103_021EE0CC
	b _021EE2CE
_021EE260:
	ldr r0, [r5, #0xc]
	add r1, r0, r6
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r0, [r0]
	bl Sprite_GetImageProxy
	mov r1, #2
	bl NNS_G2dGetImageLocation
	str r0, [sp, #8]
	mov r0, #0x9d
	str r0, [sp]
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r1, [sp, #4]
	mov r2, #0
	add r3, sp, #0x14
	bl GfGfxLoader_GetCharDataFromOpenNarc
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x14]
	mov r1, #2
	ldr r0, [r0, #0x14]
	lsl r1, r1, #8
	bl DC_FlushRange
	ldr r0, [sp, #0x14]
	mov r2, #2
	ldr r0, [r0, #0x14]
	ldr r1, [sp, #8]
	lsl r2, r2, #8
	bl GXS_LoadOBJ
	ldr r0, [sp, #0xc]
	bl Heap_Free
	ldr r0, [r5, #0xc]
	add r1, r0, r6
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r1, sp, #0x10
	ldrh r1, [r1]
	lsl r1, r1, #0x10
	lsr r1, r1, #0x1c
	bl ManagedSprite_SetPaletteOverride
	ldr r0, [r5, #0xc]
	add r1, r4, #4
	mov r2, #1
	bl ov103_021EE0CC
_021EE2CE:
	add r4, r4, #1
	add r6, r6, #4
	cmp r4, #3
	blo _021EE228
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021EE2DC: .word 0x0000FFFF
	thumb_func_end ov103_021EE210


	thumb_func_start ov103_021EE2E0
ov103_021EE2E0: ; 0x021EE2E0
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0xfc
	mov r1, #0x9d
	bl NARC_New
	add r4, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021EE36C ; =0x000037F3
	mov r1, #0x25
	lsl r1, r1, #4
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #7
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _021EE370 ; =0x000037F1
	mov r1, #0x25
	lsl r1, r1, #4
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0xa
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, _021EE370 ; =0x000037F1
	mov r1, #0x25
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #8
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, _021EE370 ; =0x000037F1
	mov r1, #0x25
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #9
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021EE36C: .word 0x000037F3
_021EE370: .word 0x000037F1
	thumb_func_end ov103_021EE2E0
