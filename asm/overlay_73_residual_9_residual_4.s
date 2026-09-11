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
	.public ov73_021E6CC0
	.public ov73_021E6CDC
	.public ov73_021E6CFC
	.public ov73_021E6D38
	.public ov73_021E6DF8
	.public ov73_021E6E48
	.public ov73_021E6E6C
	.public ov73_021E6E8C
	.public ov73_021E6ECC
	.public ov73_021E6EF8
	.public ov73_021E6FAC
	.public ov73_021E6FE8


	thumb_func_start ov73_021E705C
ov73_021E705C: ; 0x021E705C
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	cmp r4, #0xd
	bgt _021E707E
	bge _021E7092
	cmp r4, #8
	bgt _021E7110
	cmp r4, #2
	blt _021E7110
	beq _021E708C
	cmp r4, #7
	beq _021E710A
	cmp r4, #8
	beq _021E710A
	pop {r4, r5, r6, pc}
_021E707E:
	cmp r4, #0x13
	bgt _021E7086
	beq _021E70D0
	pop {r4, r5, r6, pc}
_021E7086:
	cmp r4, #0x19
	beq _021E7098
	pop {r4, r5, r6, pc}
_021E708C:
	bl ov73_021E761C
	b _021E710A
_021E7092:
	bl ov73_021E6830
	b _021E710A
_021E7098:
	ldr r0, [r5, #0x4c]
	bl ov73_021E75FC
	cmp r0, #0
	bne _021E70AC
	ldr r0, [r5, #0x4c]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl RemoveTextPrinter
_021E70AC:
	add r0, r5, #0
	mov r1, #1
	mov r2, #2
	bl ov73_021E71E4
	ldr r0, [r5]
	mov r1, #1
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	mov r1, #0xc
	mov r2, #0
	bl ov73_021E756C
	add r0, r5, #0
	bl ov73_021E6830
	b _021E710A
_021E70D0:
	ldr r0, _021E7114 ; =0x00004A28
	ldrb r0, [r5, r0]
	cmp r0, #1
	beq _021E7110
	add r0, r6, #0
	bl sub_02034818
	add r2, r0, #0
	ldr r0, [r5, #0x24]
	mov r1, #0
	bl BufferPlayersName
	bl sub_0203769C
	cmp r6, r0
	beq _021E7110
	add r0, r5, #0
	bl ov73_021E6830
	bl sub_0203769C
	cmp r0, #0
	bne _021E710A
	ldr r1, _021E7118 ; =0x00004A24
	ldr r0, _021E711C ; =0x0000FFFF
	ldr r2, [r5, r1]
	eor r0, r6
	and r0, r2
	str r0, [r5, r1]
_021E710A:
	mov r0, #0xc6
	lsl r0, r0, #2
	str r4, [r5, r0]
_021E7110:
	pop {r4, r5, r6, pc}
	nop
_021E7114: .word 0x00004A28
_021E7118: .word 0x00004A24
_021E711C: .word 0x0000FFFF
	thumb_func_end ov73_021E705C




	thumb_func_start ov73_021E7120
ov73_021E7120: ; 0x021E7120
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r0, #0
	mov r0, #0xc6
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r4, r1, #0
	add r6, r2, #0
	cmp r0, #3
	bne _021E71C0
	cmp r4, #1
	beq _021E713E
	cmp r4, #0x13
	beq _021E7182
	b _021E71B8
_021E713E:
	add r0, r6, #0
	bl sub_02034818
	add r2, r0, #0
	ldr r0, [r5, #0x24]
	mov r1, #0
	bl BufferPlayersName
	add r0, r5, #0
	mov r1, #1
	bl ov73_021E781C
	mov r0, #0xc6
	lsl r0, r0, #2
	str r4, [r5, r0]
	bl sub_02037454
	ldr r1, _021E71D8 ; =0x00004A1C
	str r0, [r5, r1]
	mov r0, #0
	add r1, #8
	str r0, [r5, r1]
	bl sub_0203769C
	cmp r0, #0
	bne _021E71D2
	mov r2, #1
	mov r0, #0x75
	add r1, sp, #0
	str r2, [sp]
	bl sub_02037030
	add sp, #4
	pop {r3, r4, r5, r6, pc}
_021E7182:
	add r0, r6, #0
	bl sub_02034818
	add r2, r0, #0
	ldr r0, [r5, #0x24]
	mov r1, #0
	bl BufferPlayersName
	bl sub_0203769C
	cmp r6, r0
	beq _021E71D2
	bl sub_0203769C
	cmp r0, #0
	bne _021E71AE
	ldr r1, _021E71DC ; =0x00004A24
	ldr r0, _021E71E0 ; =0x0000FFFF
	ldr r2, [r5, r1]
	eor r0, r6
	and r0, r2
	str r0, [r5, r1]
_021E71AE:
	mov r0, #0xc6
	lsl r0, r0, #2
	add sp, #4
	str r4, [r5, r0]
	pop {r3, r4, r5, r6, pc}
_021E71B8:
	bl GF_AssertFail
	add sp, #4
	pop {r3, r4, r5, r6, pc}
_021E71C0:
	cmp r4, #1
	bne _021E71D2
	ldr r0, _021E71DC ; =0x00004A24
	mov r1, #0
	str r1, [r5, r0]
	bl sub_02037454
	ldr r1, _021E71D8 ; =0x00004A1C
	str r0, [r5, r1]
_021E71D2:
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	nop
_021E71D8: .word 0x00004A1C
_021E71DC: .word 0x00004A24
_021E71E0: .word 0x0000FFFF
	thumb_func_end ov73_021E7120




	thumb_func_start ov73_021E71E4
ov73_021E71E4: ; 0x021E71E4
	push {r3, r4, lr}
	sub sp, #0x1c
	add r3, r1, #0
	mov r1, #0xc3
	lsl r1, r1, #2
	ldr r1, [r0, r1]
	mov r4, #8
	str r4, [sp]
	mov r4, #4
	str r4, [sp, #4]
	add r4, r1, #0
	add r4, #0xc
	str r4, [sp, #8]
	mov r4, #0
	lsl r2, r2, #0x1a
	str r4, [sp, #0xc]
	lsr r2, r2, #0x18
	str r2, [sp, #0x10]
	ldrh r2, [r1]
	lsl r2, r2, #0x15
	lsr r2, r2, #0x18
	str r2, [sp, #0x14]
	ldrh r1, [r1, #2]
	ldr r2, _021E722C ; =_021EA51C
	lsl r1, r1, #0x15
	lsr r1, r1, #0x18
	str r1, [sp, #0x18]
	ldrb r2, [r2, r3]
	ldr r0, [r0]
	mov r1, #1
	mov r3, #0x14
	bl CopyToBgTilemapRect
	add sp, #0x1c
	pop {r3, r4, pc}
	nop
_021E722C: .word _021EA51C
	thumb_func_end ov73_021E71E4




	thumb_func_start ov73_021E7230
ov73_021E7230: ; 0x021E7230
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r4, r0, #0
	bl sub_0203769C
	cmp r0, #0
	bne _021E7286
	mov r1, #0
	add r0, r4, #0
	add r2, r1, #0
	bl ov73_021E71E4
	ldr r0, [r4, #0x28]
	mov r1, #0x15
	bl NewString_ReadMsgData
	add r5, r0, #0
	mov r0, #4
	add r1, r5, #0
	mov r2, #0
	bl FontID_String_GetWidth
	mov r1, #0x40
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp]
	lsr r6, r3, #0x1f
	add r6, r3, r6
	ldr r0, _021E72EC ; =0x00040100
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0xae
	lsl r0, r0, #2
	str r1, [sp, #0xc]
	add r0, r4, r0
	mov r1, #4
	add r2, r5, #0
	asr r3, r6, #1
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl String_Delete
_021E7286:
	mov r1, #0
	ldr r0, _021E72F0 ; =0x00004A38
	mvn r1, r1
	str r1, [r4, r0]
	add r0, r4, #0
	mov r1, #1
	mov r2, #0
	bl ov73_021E71E4
	ldr r0, [r4, #0x28]
	mov r1, #0x16
	bl NewString_ReadMsgData
	add r5, r0, #0
	mov r0, #4
	add r1, r5, #0
	mov r2, #0
	bl FontID_String_GetWidth
	mov r1, #0x40
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp]
	lsr r6, r3, #0x1f
	add r6, r3, r6
	ldr r0, _021E72EC ; =0x00040100
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0xb2
	lsl r0, r0, #2
	str r1, [sp, #0xc]
	add r0, r4, r0
	mov r1, #4
	add r2, r5, #0
	asr r3, r6, #1
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl String_Delete
	ldr r0, [r4]
	mov r1, #1
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, [r4]
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_021E72EC: .word 0x00040100
_021E72F0: .word 0x00004A38
	thumb_func_end ov73_021E7230




	thumb_func_start ov73_021E72F4
ov73_021E72F4: ; 0x021E72F4
	push {r3, lr}
	ldrh r1, [r0]
	add r1, #0xa
	strh r1, [r0]
	ldrh r2, [r0]
	mov r1, #0x5a
	lsl r1, r1, #2
	cmp r2, r1
	bls _021E730A
	mov r1, #0
	strh r1, [r0]
_021E730A:
	ldrh r0, [r0]
	bl GF_SinDeg
	mov r1, #0xa
	add r2, r0, #0
	mul r2, r1
	asr r0, r2, #0xb
	lsr r0, r0, #0x14
	add r0, r2, r0
	asr r0, r0, #0xc
	add r0, #0xf
	lsl r2, r0, #5
	mov r0, #0x1d
	orr r2, r0
	add r0, sp, #0
	strh r2, [r0]
	add r0, sp, #0
	mov r2, #2
	bl GX_LoadOBJPltt
	add r0, sp, #0
	mov r1, #0x2a
	mov r2, #2
	bl GX_LoadOBJPltt
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov73_021E72F4
