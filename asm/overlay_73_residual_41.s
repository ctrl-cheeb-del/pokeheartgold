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

	thumb_func_start ov73_021EA374
ov73_021EA374: ; 0x021EA374
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	mov r0, #0
	ldr r6, _021EA3C8 ; =0x00000BB8
	ldr r5, _021EA3CC ; =ov73_021EA744
	str r1, [sp, #4]
	str r0, [sp, #8]
_021EA384:
	ldr r0, [sp]
	ldr r1, [r5]
	blx r1
	add r4, r0, #0
	ldr r0, [sp]
	ldr r3, [r5, #4]
	mov r1, #0x32
	add r2, r4, #0
	blx r3
	add r7, r0, #0
	cmp r6, r4
	bhi _021EA3A0
	bl GF_AssertFail
_021EA3A0:
	ldr r1, [sp, #4]
	add r0, r7, #0
	add r2, r4, #0
	bl MIi_CpuCopyFast
	add r0, r7, #0
	bl Heap_Free
	ldr r0, [sp, #4]
	sub r6, r6, r4
	add r0, r0, r4
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	add r5, #0xc
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #0xa
	blt _021EA384
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021EA3C8: .word 0x00000BB8
_021EA3CC: .word ov73_021EA744
	thumb_func_end ov73_021EA374


	thumb_func_start ov73_021EA3D0
ov73_021EA3D0: ; 0x021EA3D0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x68
	str r0, [sp]
	ldr r0, _021EA514 ; =0x00000BB8
	str r1, [sp, #4]
	str r0, [sp, #0x14]
	mov r0, #0x32
	str r0, [sp, #0x50]
	ldr r0, [sp]
	mov r7, #0
	str r0, [sp, #0x54]
	bl sub_0203769C
	add r5, r7, #0
	str r0, [sp, #0x5c]
	mov r0, #5
	str r0, [sp, #0x58]
	add r0, sp, #0x3c
	str r0, [sp, #0x60]
	add r0, sp, #0x28
	ldr r4, _021EA518 ; =ov73_021EA744
	str r0, [sp, #0x64]
	str r5, [sp, #0x1c]
	str r5, [sp, #0x20]
	str r5, [sp, #0x24]
_021EA402:
	ldr r0, [sp]
	ldr r1, [r4]
	blx r1
	ldr r1, [sp, #0x1c]
	add r5, r5, #1
	add r0, r1, r0
	add r4, #0xc
	str r0, [sp, #0x1c]
	cmp r5, #2
	blt _021EA402
	ldr r4, _021EA518 ; =ov73_021EA744
	mov r5, #0
_021EA41A:
	ldr r0, [sp]
	ldr r1, [r4]
	blx r1
	ldr r1, [sp, #0x20]
	add r5, r5, #1
	add r0, r1, r0
	add r4, #0xc
	str r0, [sp, #0x20]
	cmp r5, #3
	blt _021EA41A
	ldr r4, _021EA518 ; =ov73_021EA744
	mov r5, #0
_021EA432:
	ldr r0, [sp]
	ldr r1, [r4]
	blx r1
	ldr r1, [sp, #0x24]
	add r5, r5, #1
	add r0, r1, r0
	add r4, #0xc
	str r0, [sp, #0x24]
	cmp r5, #4
	blt _021EA432
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, _021EA518 ; =ov73_021EA744
	str r0, [sp, #0x10]
	add r0, sp, #0x1c
	str r0, [sp, #0xc]
_021EA452:
	ldr r1, [sp, #0x10]
	ldr r0, [sp]
	ldr r1, [r1]
	blx r1
	ldr r1, [sp, #0x14]
	str r0, [sp, #0x18]
	cmp r1, r0
	bhi _021EA466
	bl GF_AssertFail
_021EA466:
	mov r6, #0
	ldr r4, [sp, #4]
	add r5, r6, #0
_021EA46C:
	add r0, r6, #0
	bl sub_02034818
	cmp r0, #0
	beq _021EA47E
	ldr r0, [sp, #0x60]
	add r1, r4, r7
	str r1, [r0, r5]
	b _021EA484
_021EA47E:
	ldr r1, [sp, #0x60]
	mov r0, #0
	str r0, [r1, r5]
_021EA484:
	mov r0, #0x2f
	lsl r0, r0, #6
	add r6, r6, #1
	add r4, r4, r0
	add r5, r5, #4
	cmp r6, #5
	blt _021EA46C
	ldr r0, [sp, #8]
	cmp r0, #7
	beq _021EA4A0
	cmp r0, #8
	beq _021EA4A0
	cmp r0, #9
	bne _021EA4D2
_021EA4A0:
	mov r6, #0
	ldr r4, [sp, #4]
	add r5, r6, #0
_021EA4A6:
	add r0, r6, #0
	bl sub_02034818
	cmp r0, #0
	beq _021EA4BE
	ldr r0, [sp, #0xc]
	sub r0, #0x1c
	ldr r0, [r0]
	add r1, r4, r0
	ldr r0, [sp, #0x64]
	str r1, [r0, r5]
	b _021EA4C4
_021EA4BE:
	ldr r1, [sp, #0x64]
	mov r0, #0
	str r0, [r1, r5]
_021EA4C4:
	mov r0, #0x2f
	lsl r0, r0, #6
	add r6, r6, #1
	add r4, r4, r0
	add r5, r5, #4
	cmp r6, #5
	blt _021EA4A6
_021EA4D2:
	ldr r0, [sp, #0x10]
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _021EA4DE
	add r0, sp, #0x50
	blx r1
_021EA4DE:
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x14]
	add r7, r7, r0
	sub r0, r1, r0
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, #0xc
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	add r0, r0, #4
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #0xa
	blo _021EA452
	ldr r0, [sp]
	bl sub_020270C4
	add r4, r0, #0
	bl sub_0202E43C
	add r0, r4, #0
	bl sub_0202E474
	add sp, #0x68
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021EA514: .word 0x00000BB8
_021EA518: .word ov73_021EA744
	thumb_func_end ov73_021EA3D0

	.rodata

_021EA51C:
	.byte 0x10, 0x18, 0x00, 0x00

ov73_021EA520: ; 0x021EA520
	.byte 0xA0, 0x01, 0xA0, 0x07, 0xA0, 0x0D, 0xA0, 0x13, 0xA0, 0x19

ov73_021EA52A: ; 0x021EA52A
	.byte 0x08

ov73_021EA52B: ; 0x021EA52B
	.byte 0x02, 0x08, 0x03, 0x08, 0x04
	.byte 0x18, 0x00, 0x00, 0xFF

ov73_021EA534: ; 0x021EA534
	.byte 0xA0, 0xC0, 0x80, 0xC0, 0xA0, 0xC0, 0xC0, 0x00, 0xFF, 0x00, 0x00, 0x00

ov73_021EA540: ; 0x021EA540
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov73_021EA550: ; 0x021EA550
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00

ov73_021EA560: ; 0x021EA560
	.byte 0x54, 0x00, 0x68, 0x00, 0x55, 0x00, 0x48, 0x00, 0x72, 0x00, 0x58, 0x00, 0x67, 0x00, 0x75, 0x00
	.byte 0x42, 0x00, 0x75, 0x00, 0x37, 0x00, 0x58, 0x00

ov73_021EA578: ; 0x021EA578
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

ov73_021EA594: ; 0x021EA594
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1E, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov73_021EA5B0: ; 0x021EA5B0
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x1F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov73_021EA5CC: ; 0x021EA5CC
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1E, 0x00
	.byte 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov73_021EA5E8: ; 0x021EA5E8
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov73_021EA610:
	.byte 0x01, 0x03, 0x04, 0x06, 0x08, 0x09, 0xFF, 0x00

ov73_021EA618:
	.byte 0x01, 0x03, 0x04, 0x05, 0x08, 0x09, 0x0A, 0x0B, 0xFF, 0x00, 0x00, 0x00

ov73_021EA624:
	.byte 0x02, 0x04, 0x06, 0x07, 0x09, 0x0A, 0x0B, 0x0D, 0xFF, 0x00, 0x00, 0x00

ov73_021EA630:
	.byte 0x02, 0x04, 0x06, 0x07, 0x09, 0x0A, 0x0B, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0xFF, 0x00

ov73_021EA640:
	.byte 0x01, 0x02, 0x03, 0x04, 0x06, 0x0A, 0x0D, 0x0F, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0xFF

ov73_021EA650:
	.byte 0x01, 0x02, 0x03, 0x04, 0x06, 0x07, 0x08, 0x0A, 0x0D, 0x0F, 0x10, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x19, 0x1A, 0xFF

ov73_021EA664: ; 0x021EA664
	.word ov73_021EA630
	.word ov73_021EA650
	.word ov73_021EA618
	.word ov73_021EA624
	.word ov73_021EA640
	.word ov73_021EA610
	.byte 0x00, 0x17, 0x0D, 0x07
	.byte 0x04, 0x0D, 0x00, 0x00

ov73_021EA684: ; 0x021EA684
	.byte 0xE0, 0x00, 0x6F, 0x00, 0xE0, 0x00, 0x81, 0x00

ov73_021EA68C: ; 0x021EA68C
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov73_021EA69C: ; 0x021EA69C
	.byte 0x14, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00

ov73_021EA6AC: ; 0x021EA6AC
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x60, 0x00, 0x00, 0x00

ov73_021EA6D4: ; 0x021EA6D4
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1B, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov73_021EA6F0: ; 0x021EA6F0
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x1E, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov73_021EA70C: ; 0x021EA70C
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1F, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov73_021EA728: ; 0x021EA728
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1E, 0x04, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

ov73_021EA744: ; 0x021EA744
	.word ov73_021EA25C, ov73_021EA268, ov73_021EA290
	.word ov73_021EA2A8, ov73_021EA2B4, ov73_021EA2E0
	.word ov73_021E7A7C, ov73_021E7B84, 0
	.word ov73_021E7A84, ov73_021E7BC8, 0
	.word ov73_021E7A74, ov73_021E7B3C, 0
	.word Save_Rankings_GetMixingSize, ov73_021EA31C, ov73_021EA324
	.word sub_0202D230, ov73_021EA348, ov73_021EA370
	.word ov73_021E7A7C, ov73_021E7C50, 0
	.word ov73_021E7A84, ov73_021E7C94, 0
	.word ov73_021E7A74, ov73_021E7C0C, ov73_021EA2FC

	.data

_021EA7C0:
	.word ov73_021E6444
	.word ov73_021E66F4
	.word ov73_021E6778
	.word ov73_021E6484
	.word ov73_021E6890
	.word ov73_021E68AC
	.word ov73_021E69D0
	.word ov73_021E69E8
	.word ov73_021E6A70
	.word ov73_021E6CDC
	.word ov73_021E6CFC
	.word ov73_021E6D38
	.word ov73_021E6D54
	.word ov73_021E6DF8
	.word ov73_021E6E48
	.word ov73_021E6E6C
	.word ov73_021E6E8C
	.word ov73_021E6ECC
	.word ov73_021E6EF8
	.word ov73_021E6F1C
	.word ov73_021E6FAC
	.word ov73_021E6FE8
	.word ov73_021E6A90
	.word ov73_021E6AAC
	.word ov73_021E6B6C
	.word ov73_021E6BC8
	.word ov73_021E6BF8
	.word ov73_021E6C20
	.word ov73_021E6C50
	.word ov73_021E6CC0
	.word ov73_021E671C

ov73_021EA83C: ; 0x021EA83C
	.word ov73_021E84D0

ov73_021EA840: ; 0x021EA840
	.word ov73_021E85AC

ov73_021EA844: ; 0x021EA844
	.word ov73_021E85DC

ov73_021EA848: ; 0x021EA848
	.word ov73_021E8BFC
	.word ov73_021E8C2C
	.word ov73_021E8D0C
	.word ov73_021E8D2C
	.word ov73_021E8DB8
	.word ov73_021E8DC8
	.word ov73_021E8E7C
	.word ov73_021E8EBC
	.word ov73_021E8ED8
	.word ov73_021E8FB0
	.word ov73_021E8FE4
	.word ov73_021E9120
	.word ov73_021E9144
	.word ov73_021E91F4
	.word ov73_021E9224
	.word ov73_021E926C
	.word ov73_021E9378
	.word ov73_021E941C
	.word ov73_021E944C
	.word ov73_021E955C
	.word ov73_021E93EC
	.word ov73_021E9BD4
	.word ov73_021E9C04
	.word ov73_021E9C30
	.word ov73_021E9C60
	.word ov73_021E9598
	.word ov73_021E95CC
	.word ov73_021E9618
	.word ov73_021E96EC
	.word ov73_021E9728
	.word ov73_021E9758
	.word ov73_021E97A8
	.word ov73_021E987C
	.word ov73_021E98AC
	.word ov73_021E98FC
	.word ov73_021E99D4
	.word ov73_021E9A3C
	.word ov73_021E9A6C
	.word ov73_021E9B58
	.word ov73_021E9B9C
	.word ov73_021E9BB4
	.word ov73_021E9C8C
	.word ov73_021E9CBC
	.word ov73_021E9CD8
	.word ov73_021E9D10
	.word ov73_021E9B94
	.word ov73_021E9D14
	.word ov73_021E9EAC
	.word ov73_021E9F00
	.word ov73_021E9ECC
	.word ov73_021E9D44
	.word ov73_021E8C8C
	.word ov73_021E8CBC
	.word ov73_021E9D6C
	.word ov73_021E9DE0
	.word ov73_021E9F9C
	.word ov73_021E9FC8

	.bss

_021EA940:
	.space 0x8
