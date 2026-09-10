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

	thumb_func_start ov73_021E781C
ov73_021E781C: ; 0x021E781C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl sub_0203769C
	cmp r0, #0
	bne _021E7868
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	bne _021E783A
	mov r0, #1
	bl sub_02038C1C
	b _021E784A
_021E783A:
	bl sub_02037454
	add r0, r4, r0
	cmp r0, #5
	ble _021E7846
	mov r0, #5
_021E7846:
	bl sub_02038C1C
_021E784A:
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	ldr r0, _021E786C ; =0x00004A29
	bne _021E785A
	mov r1, #2
	strb r1, [r5, r0]
	pop {r3, r4, r5, pc}
_021E785A:
	cmp r4, #0
	bne _021E7864
	mov r1, #1
	strb r1, [r5, r0]
	pop {r3, r4, r5, pc}
_021E7864:
	mov r1, #0
	strb r1, [r5, r0]
_021E7868:
	pop {r3, r4, r5, pc}
	nop
_021E786C: .word 0x00004A29
	thumb_func_end ov73_021E781C


	thumb_func_start ov73_021E7870
ov73_021E7870: ; 0x021E7870
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r4, r0, #0
	add r6, r1, #0
	bl ov73_021E746C
	add r5, r0, #0
	ldr r0, _021E7950 ; =0x00004A1C
	ldr r1, [r4, r0]
	cmp r5, r1
	ble _021E789A
	mov r2, #1
	add r0, sp, #0
	strb r2, [r0]
	mov r0, #0x75
	add r1, sp, #0
	bl sub_02037030
	mov r1, #1
	ldr r0, _021E7954 ; =0x00004A20
	b _021E789E
_021E789A:
	mov r1, #0
	add r0, r0, #4
_021E789E:
	str r1, [r4, r0]
	ldr r0, _021E7958 ; =0x00004A18
	ldr r0, [r4, r0]
	cmp r5, r0
	bne _021E78AE
	add sp, #4
	mov r0, #1
	pop {r3, r4, r5, r6, pc}
_021E78AE:
	cmp r5, #5
	bhi _021E7942
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E78BE: ; jump table
	.short _021E7942 - _021E78BE - 2 ; case 0
	.short _021E78CA - _021E78BE - 2 ; case 1
	.short _021E78FC - _021E78BE - 2 ; case 2
	.short _021E78FC - _021E78BE - 2 ; case 3
	.short _021E78FC - _021E78BE - 2 ; case 4
	.short _021E7934 - _021E78BE - 2 ; case 5
_021E78CA:
	bl sub_02037454
	cmp r0, #1
	bgt _021E78DA
	bl sub_02033250
	cmp r0, #1
	bls _021E78E0
_021E78DA:
	add sp, #4
	mov r0, #1
	pop {r3, r4, r5, r6, pc}
_021E78E0:
	mov r0, #0xc6
	mov r1, #0x11
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r0, r4, #0
	sub r1, #0x12
	bl ov73_021E781C
	add r0, r4, #0
	bl ov73_021E6830
	add sp, #4
	mov r0, #2
	pop {r3, r4, r5, r6, pc}
_021E78FC:
	mov r0, #2
	bl sub_0205A904
	ldr r0, _021E7958 ; =0x00004A18
	ldr r1, [r4, r0]
	cmp r5, r1
	bge _021E7942
	add r0, #0x11
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq _021E7918
	cmp r0, #1
	beq _021E7922
	b _021E792A
_021E7918:
	add r0, r4, #0
	add r1, r6, #0
	bl ov73_021E781C
	b _021E792A
_021E7922:
	add r0, r4, #0
	mov r1, #0
	bl ov73_021E781C
_021E792A:
	bl sub_02037454
	ldr r1, _021E7950 ; =0x00004A1C
	str r0, [r4, r1]
	b _021E7942
_021E7934:
	mov r0, #9
	bl sub_0205A904
	add r0, r4, #0
	add r1, r6, #0
	bl ov73_021E781C
_021E7942:
	bl ov73_021E746C
	ldr r1, _021E7958 ; =0x00004A18
	str r0, [r4, r1]
	mov r0, #1
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021E7950: .word 0x00004A1C
_021E7954: .word 0x00004A20
_021E7958: .word 0x00004A18
	thumb_func_end ov73_021E7870
