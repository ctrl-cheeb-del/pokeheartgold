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

	thumb_func_start ov27_0225C434
ov27_0225C434: ; 0x0225C434
	push {r4, lr}
	add r4, r1, #0
	ldr r0, [r4, #0x24]
	bl FieldSystem_TaskIsRunning
	cmp r0, #0
	bne _0225C46C
	ldr r0, [r4, #0x24]
	add r1, r0, #0
	add r1, #0xd2
	ldrb r1, [r1]
	lsl r1, r1, #0x1a
	lsr r1, r1, #0x1a
	cmp r1, #2
	bne _0225C464
	add r1, r0, #0
	add r1, #0xd2
	ldrb r2, [r1]
	mov r1, #0x3f
	add r0, #0xd2
	bic r2, r1
	mov r1, #3
	orr r1, r2
	strb r1, [r0]
_0225C464:
	ldr r0, _0225C4A4 ; =0x04001050
	mov r1, #0
	strh r1, [r0]
	b _0225C496
_0225C46C:
	ldr r1, [r4]
	add r0, r4, #0
	lsl r2, r1, #2
	ldr r1, _0225C4A8 ; =ov27_0225D4D4
	ldr r1, [r1, r2]
	blx r1
	cmp r0, #1
	bne _0225C496
	ldr r2, [r4, #0x24]
	add r0, r2, #0
	add r0, #0xd2
	ldrb r1, [r0]
	mov r0, #0x3f
	add r2, #0xd2
	bic r1, r0
	strb r1, [r2]
	mov r1, #0
	ldr r0, [r4, #0x24]
	add r2, r1, #0
	bl ov01_021F6A9C
_0225C496:
	mov r0, #0x86
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl SpriteList_RenderAndAnimateSprites
	pop {r4, pc}
	nop
_0225C4A4: .word 0x04001050
_0225C4A8: .word ov27_0225D4D4
	thumb_func_end ov27_0225C434


	thumb_func_start ov27_0225C4AC
ov27_0225C4AC: ; 0x0225C4AC
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r5, r0, #0
	mov r0, #0xef
	mov r1, #8
	bl NARC_New
	mov r1, #0
	ldr r2, _0225C53C ; =0x04001050
	add r3, r1, #0
	strh r1, [r2]
	mov r2, #0xa0
	str r2, [sp]
	mov r2, #8
	str r2, [sp, #4]
	mov r2, #4
	add r4, r0, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #8
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x18]
	add r0, r4, #0
	mov r1, #1
	mov r3, #6
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #8
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x18]
	add r0, r4, #0
	mov r1, #9
	mov r3, #6
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #8
	str r0, [sp]
	add r0, r4, #0
	mov r1, #9
	mov r2, #0
	add r3, sp, #0x10
	bl GfGfxLoader_GetScrnDataFromOpenNarc
	ldr r3, [sp, #0x10]
	add r6, r0, #0
	add r2, r3, #0
	ldr r0, [r5, #0x18]
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r5, #0x18]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add r0, r6, #0
	bl Heap_Free
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0225C53C: .word 0x04001050
	thumb_func_end ov27_0225C4AC


	thumb_func_start ov27_0225C540
ov27_0225C540: ; 0x0225C540
	push {r4, r5, lr}
	sub sp, #0x14
	add r5, r0, #0
	mov r0, #0xef
	mov r1, #8
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	mov r1, #8
	str r1, [sp, #0xc]
	ldr r2, [r5, #0x18]
	mov r1, #1
	mov r3, #4
	add r4, r0, #0
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #8
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x18]
	add r0, r4, #0
	mov r1, #0xa
	mov r3, #4
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	mov r0, #8
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	mov r0, #0x80
	str r0, [sp, #0x10]
	add r1, r5, #0
	ldr r0, [r5, #0x18]
	add r1, #0x28
	mov r2, #5
	mov r3, #0xc
	bl AddWindowParameterized
	mov r0, #0xe
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	mov r0, #0x90
	str r0, [sp, #0x10]
	add r1, r5, #0
	ldr r0, [r5, #0x18]
	add r1, #0x38
	mov r2, #5
	mov r3, #0xc
	bl AddWindowParameterized
	add r0, r5, #0
	ldr r1, [r5, #0x4c]
	add r0, #0x28
	mov r2, #0x2e
	bl ov27_0225C8D0
	add r0, r5, #0
	ldr r1, [r5, #0x4c]
	add r0, #0x38
	mov r2, #0x2f
	bl ov27_0225C8D0
	add sp, #0x14
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov27_0225C540
