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

	thumb_func_start ov73_021E762C
ov73_021E762C: ; 0x021E762C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #0xbd
	lsl r0, r0, #2
	add r0, r5, r0
	str r0, [sp, #0x14]
	mov r0, #0xc1
	lsl r0, r0, #2
	mov r4, #0
	add r0, r5, r0
	str r4, [sp, #8]
	add r6, r5, #0
	mov r7, #0x1c
	str r0, [sp, #0x18]
_021E764E:
	mov r0, #0x36
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #3
	bhi _021E771A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E7664: ; jump table
	.short _021E771A - _021E7664 - 2 ; case 0
	.short _021E766C - _021E7664 - 2 ; case 1
	.short _021E771A - _021E7664 - 2 ; case 2
	.short _021E76E2 - _021E7664 - 2 ; case 3
_021E766C:
	mov r0, #0xce
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	cmp r0, #0
	bne _021E767A
	bl GF_AssertFail
_021E767A:
	mov r0, #0xce
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl PlayerProfile_GetTrainerGender
	str r0, [sp, #0xc]
	mov r0, #0xce
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl PlayerProfile_GetAvatar
	str r0, [sp, #0x10]
	bl sub_0203769C
	cmp r4, r0
	bne _021E76AC
	mov r0, #0x8b
	ldr r1, [sp, #0xc]
	lsl r0, r0, #2
	lsl r1, r1, #1
	ldr r0, [r5, r0]
	add r1, #0x26
	bl Sprite_SetAnimCtrlSeq
	b _021E76C8
_021E76AC:
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x18]
	str r0, [sp]
	ldr r0, [sp, #0x14]
	ldr r3, [sp, #0x10]
	add r2, r4, #0
	bl ov73_021E77A4
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [sp, #4]
	bl Sprite_SetAnimCtrlSeq
_021E76C8:
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x36
	mov r1, #2
	lsl r0, r0, #4
	str r1, [r5, r0]
	mov r0, #1
	str r0, [sp, #8]
	b _021E771A
_021E76E2:
	bl sub_0203769C
	cmp r4, r0
	bne _021E7706
	mov r0, #0xce
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl PlayerProfile_GetTrainerGender
	add r1, r0, #0
	mov r0, #0x8b
	lsl r0, r0, #2
	lsl r1, r1, #1
	ldr r0, [r5, r0]
	add r1, #0x27
	bl Sprite_SetAnimCtrlSeq
	b _021E7712
_021E7706:
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r7, #0
	bl Sprite_SetAnimCtrlSeq
_021E7712:
	mov r0, #0x36
	mov r1, #0
	lsl r0, r0, #4
	str r1, [r5, r0]
_021E771A:
	ldr r0, [sp, #4]
	add r4, r4, #1
	add r0, r0, #2
	add r5, r5, #4
	add r6, #8
	add r7, r7, #2
	str r0, [sp, #4]
	cmp r4, #5
	blt _021E764E
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _021E7738
	ldr r0, _021E773C ; =0x0000064E
	bl PlaySE
_021E7738:
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E773C: .word 0x0000064E
	thumb_func_end ov73_021E762C


	thumb_func_start ov73_021E7740
ov73_021E7740: ; 0x021E7740
	push {r3, r4, r5, lr}
	mov r2, #0xc1
	add r5, r0, #0
	lsl r2, r2, #2
	add r4, r1, #0
	mov r0, #0x64
	mov r1, #9
	add r2, r5, r2
	mov r3, #0x32
	bl GfGfxLoader_GetPlttData
	mov r2, #0xbf
	lsl r2, r2, #2
	str r0, [r5, r2]
	add r2, #0xc
	add r0, r4, #0
	mov r1, #0xb
	add r2, r5, r2
	mov r3, #0x32
	bl GfGfxLoader_GetPlttDataFromOpenNarc
	mov r3, #3
	lsl r3, r3, #8
	str r0, [r5, r3]
	mov r0, #0x32
	sub r3, #0xc
	str r0, [sp]
	mov r0, #0x64
	mov r1, #0x2b
	mov r2, #1
	add r3, r5, r3
	bl GfGfxLoader_GetCharData
	mov r3, #0xbb
	lsl r3, r3, #2
	str r0, [r5, r3]
	mov r0, #0x32
	add r3, #0xc
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0xc
	mov r2, #1
	add r3, r5, r3
	bl GfGfxLoader_GetCharDataFromOpenNarc
	mov r1, #0x2f
	lsl r1, r1, #4
	str r0, [r5, r1]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov73_021E7740


	thumb_func_start ov73_021E77A4
ov73_021E77A4: ; 0x021E77A4
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r6, r1, #0
	ldr r0, [sp, #0x18]
	add r1, r3, #0
	add r5, r2, #0
	bl SpriteToUnionRoomAvatarIdx
	add r4, r0, #0
	ldr r0, [r6, #4]
	mov r2, #6
	ldr r6, [r0, #0xc]
	ldr r0, [r7, #4]
	lsl r2, r2, #8
	ldr r1, [r0, #0x14]
	add r0, r4, #0
	mul r0, r2
	add r0, r1, r0
	ldr r1, _021E77E4 ; =ov73_021EA520
	lsl r3, r5, #1
	ldrh r1, [r1, r3]
	bl GX_LoadOBJ
	lsl r0, r4, #5
	add r1, r5, #7
	add r0, r6, r0
	lsl r1, r1, #5
	mov r2, #0x20
	bl GX_LoadOBJPltt
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E77E4: .word ov73_021EA520
	thumb_func_end ov73_021E77A4
