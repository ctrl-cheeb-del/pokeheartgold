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

	thumb_func_start ov73_021E6444
ov73_021E6444: ; 0x021E6444
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	mov r0, #0
	mov r1, #1
	bl sub_020398D4
	bl sub_0203769C
	cmp r0, #0
	bne _021E646E
	bl sub_02037454
	cmp r0, #2
	blt _021E6478
	add r0, r5, #0
	mov r1, #2
	mov r2, #0
	bl ov73_021E756C
	b _021E6478
_021E646E:
	add r0, r5, #0
	mov r1, #8
	mov r2, #0
	bl ov73_021E756C
_021E6478:
	add r0, r5, #0
	mov r1, #3
	bl ov73_021E670C
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov73_021E6444


	thumb_func_start ov73_021E6484
ov73_021E6484: ; 0x021E6484
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl ov73_021E6508
	bl sub_0203769C
	cmp r0, #0
	bne _021E64A6
	bl ov73_021E7340
	cmp r0, #1
	beq _021E64AC
	add r0, r5, #0
	bl ov73_021E7468
	b _021E64AC
_021E64A6:
	add r0, r5, #0
	bl ov73_021E7468
_021E64AC:
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov73_021E6484


	thumb_func_start ov73_021E64B0
ov73_021E64B0: ; 0x021E64B0
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0xc5
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _021E64DE
	bl System_GetTouchHeld
	cmp r0, #0
	beq _021E64CA
	mov r0, #0
	pop {r4, pc}
_021E64CA:
	ldr r0, _021E6504 ; =gSystem
	ldr r0, [r0, #0x44]
	cmp r0, #0
	beq _021E64FE
	mov r0, #0xc5
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	mov r0, #1
	pop {r4, pc}
_021E64DE:
	ldr r0, _021E6504 ; =gSystem
	ldr r0, [r0, #0x44]
	cmp r0, #0
	beq _021E64EA
	mov r0, #0
	pop {r4, pc}
_021E64EA:
	bl System_GetTouchHeld
	cmp r0, #0
	beq _021E64FE
	mov r0, #0xc5
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r4, r0]
	mov r0, #0
	pop {r4, pc}
_021E64FE:
	mov r0, #0
	pop {r4, pc}
	nop
_021E6504: .word gSystem
	thumb_func_end ov73_021E64B0


	thumb_func_start ov73_021E6508
ov73_021E6508: ; 0x021E6508
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r4, #0
	bl ov73_021E64B0
	ldr r0, _021E66C8 ; =ov73_021EA534
	bl TouchscreenHitbox_FindRectAtTouchNew
	add r6, r0, #0
	ldr r1, _021E66CC ; =0x0000FFD5
	add r0, sp, #4
	strh r1, [r0, #4]
	sub r0, r4, #1
	cmp r6, r0
	beq _021E6544
	add r0, sp, #8
	str r0, [sp]
	ldr r3, _021E66D0 ; =gSystem + 0x40
	ldr r0, [r5]
	ldrh r2, [r3, #0x20]
	ldrh r3, [r3, #0x22]
	mov r1, #1
	bl DoesPixelAtScreenXYMatchPtrVal
	cmp r0, #0
	beq _021E6544
	add r0, r6, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_021E6544:
	ldr r0, _021E66D4 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	bne _021E6552
	cmp r4, #1
	bne _021E65BE
_021E6552:
	bl sub_0203769C
	cmp r0, #0
	beq _021E655C
	b _021E669C
_021E655C:
	bl ov73_021E746C
	ldr r1, _021E66D8 ; =0x00004A1C
	ldr r2, [r5, r1]
	cmp r2, r0
	bne _021E65B6
	add r1, #8
	ldr r0, [r5, r1]
	cmp r0, #0
	bne _021E65B6
	mov r1, #1
	add r0, sp, #4
	strb r1, [r0, #2]
	add r0, r5, #0
	mov r1, #3
	mov r2, #0
	bl ov73_021E756C
	add r0, r5, #0
	mov r1, #0x16
	bl ov73_021E670C
	add r1, sp, #4
	mov r0, #0x75
	add r1, #2
	mov r2, #1
	bl sub_02037030
	add r0, r5, #0
	mov r1, #0
	bl ov73_021E781C
	ldr r0, _021E66DC ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	mov r1, #0
	mov r2, #1
	bl ov73_021E71E4
	ldr r0, [r5]
	mov r1, #1
	bl ScheduleBgTilemapBufferTransfer
	b _021E669C
_021E65B6:
	ldr r0, _021E66E0 ; =0x000005F2
	bl PlaySE
	b _021E669C
_021E65BE:
	mov r0, #2
	tst r0, r1
	bne _021E65C8
	cmp r4, #2
	bne _021E6670
_021E65C8:
	bl sub_0203769C
	cmp r0, #0
	beq _021E660C
	ldr r1, _021E66E4 ; =0x00004A10
	ldr r0, [r5, r1]
	cmp r0, #0
	bne _021E65F4
	add r0, r5, #0
	mov r1, #4
	mov r2, #0
	bl ov73_021E756C
	add r0, r5, #0
	mov r1, #4
	bl ov73_021E670C
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	b _021E669C
_021E65F4:
	add r0, r1, #0
	add r0, #0x28
	ldr r0, [r5, r0]
	cmp r0, #0
	bge _021E669C
	mov r0, #2
	add r1, #0x28
	str r0, [r5, r1]
	ldr r0, _021E66E0 ; =0x000005F2
	bl PlaySE
	b _021E669C
_021E660C:
	bl sub_02037454
	ldr r1, _021E66D8 ; =0x00004A1C
	ldr r2, [r5, r1]
	cmp r2, r0
	bne _021E6668
	add r1, #8
	ldr r0, [r5, r1]
	cmp r0, #0
	bne _021E6668
	mov r1, #1
	add r0, sp, #4
	strb r1, [r0, #1]
	add r0, r5, #0
	mov r1, #4
	mov r2, #0
	bl ov73_021E756C
	add r0, r5, #0
	mov r1, #4
	bl ov73_021E670C
	add r1, sp, #4
	mov r0, #0x75
	add r1, #1
	mov r2, #1
	bl sub_02037030
	add r0, r5, #0
	mov r1, #0
	bl ov73_021E781C
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	mov r1, #1
	add r0, r5, #0
	add r2, r1, #0
	bl ov73_021E71E4
	ldr r0, [r5]
	mov r1, #1
	bl ScheduleBgTilemapBufferTransfer
	b _021E669C
_021E6668:
	ldr r0, _021E66E0 ; =0x000005F2
	bl PlaySE
	b _021E669C
_021E6670:
	ldr r0, _021E66E8 ; =0x00004A20
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _021E669C
	bl sub_0203769C
	cmp r0, #0
	bne _021E669C
	bl sub_02037454
	ldr r1, _021E66D8 ; =0x00004A1C
	ldr r1, [r5, r1]
	cmp r1, r0
	bne _021E669C
	mov r1, #0
	add r0, sp, #4
	strb r1, [r0]
	mov r0, #0x75
	add r1, sp, #4
	mov r2, #1
	bl sub_02037030
_021E669C:
	ldr r0, _021E66EC ; =0x00004A38
	ldr r1, [r5, r0]
	cmp r1, #0
	blt _021E66A8
	sub r1, r1, #1
	str r1, [r5, r0]
_021E66A8:
	ldr r0, _021E66EC ; =0x00004A38
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _021E66C2
	add r0, r5, #0
	mov r1, #1
	mov r2, #0
	bl ov73_021E71E4
	ldr r0, [r5]
	mov r1, #1
	bl ScheduleBgTilemapBufferTransfer
_021E66C2:
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	nop
_021E66C8: .word ov73_021EA534
_021E66CC: .word 0x0000FFD5
_021E66D0: .word gSystem + 0x40
_021E66D4: .word gSystem
_021E66D8: .word 0x00004A1C
_021E66DC: .word 0x000005DC
_021E66E0: .word 0x000005F2
_021E66E4: .word 0x00004A10
_021E66E8: .word 0x00004A20
_021E66EC: .word 0x00004A38
	thumb_func_end ov73_021E6508
