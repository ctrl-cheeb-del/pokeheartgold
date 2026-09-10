	.include "asm/macros.inc"
	.include "unk_0203A3B0.inc"
	.include "global.inc"

	.bss

	.public _021D4154
_021D4154:
	.space 0x4

	.rodata

	.public _020F6A9C
_020F6A9C:
	.byte 0xFC, 0x01, 0x14, 0x00
	.byte 0xFF, 0xFF, 0x00, 0x00
	.public _020F6AA4
_020F6AA4:
	.byte 0xF8, 0x01, 0x14, 0x00
	.byte 0xFF, 0xFF, 0x00, 0x00
	.public _020F6AAC
_020F6AAC:
	.byte 0xF4, 0x01, 0x14, 0x00
	.byte 0xFF, 0xFF, 0x00, 0x00
	.public _020F6AB4
_020F6AB4:
	.byte 0xF0, 0x01, 0x14, 0x00
	.byte 0xFF, 0xFF, 0x00, 0x00
	.public _020F6ABC
_020F6ABC:
	.byte 0xF0, 0x01, 0x14, 0x00
	.byte 0xF4, 0x01, 0x14, 0x00
	.byte 0xF8, 0x01, 0x14, 0x00
	.byte 0xFC, 0x01, 0x14, 0x00
	.byte 0xFF, 0xFF, 0x00, 0x00

	.data

	.balign 4, 0
	.public _0210F91C
_0210F91C:
	.word _020F6AB4
	.word _020F6AAC
	.word _020F6AA4
	.word _020F6A9C
	.word _020F6ABC

	.balign 4, 0
	.public _0210F930
_0210F930:
	.asciz "data/pl_wm.NCLR"

	.balign 4, 0
	.public _0210F940
_0210F940:
	.asciz "data/pl_wifi.NCGR"

	.balign 4, 0
	.public _0210F954
_0210F954:
	.asciz "data/pl_wm.NCGR"

	.balign 4, 0
	.public _0210F964
_0210F964:
	.asciz "data/wm256k.NCGR"

	.text

	thumb_func_start sub_0203A700
sub_0203A700: ; 0x0203A700
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldrb r0, [r5, #0x11]
	cmp r0, #1
	beq _0203A710
	cmp r0, #2
	beq _0203A726
	b _0203A73C
_0203A710:
	ldr r0, _0203A850 ; =0x04000304
	ldrh r1, [r0]
	lsr r0, r0, #0xb
	and r0, r1
	asr r0, r0, #0xf
	cmp r0, #1
	bne _0203A722
	mov r7, #1
	b _0203A742
_0203A722:
	mov r7, #2
	b _0203A742
_0203A726:
	ldr r0, _0203A850 ; =0x04000304
	ldrh r1, [r0]
	lsr r0, r0, #0xb
	and r0, r1
	asr r0, r0, #0xf
	cmp r0, #1
	bne _0203A738
	mov r7, #2
	b _0203A742
_0203A738:
	mov r7, #1
	b _0203A742
_0203A73C:
	add r0, r5, #0
	add r0, #0x21
	ldrb r7, [r0]
_0203A742:
	ldr r4, [r5, #4]
	cmp r7, #1
	bne _0203A75A
	mov r0, #1
	lsl r0, r0, #0x1a
	ldr r1, [r0]
	ldr r0, _0203A854 ; =0x00300010
	add r6, r1, #0
	and r6, r0
	bl GX_GetBankForOBJ
	b _0203A768
_0203A75A:
	ldr r0, _0203A858 ; =0x04001000
	ldr r1, [r0]
	ldr r0, _0203A854 ; =0x00300010
	add r6, r1, #0
	and r6, r0
	bl GX_GetBankForSubOBJ
_0203A768:
	ldr r1, _0203A85C ; =0x00100010
	cmp r6, r1
	bgt _0203A776
	bge _0203A7A4
	cmp r6, #0x10
	beq _0203A788
	b _0203A7F4
_0203A776:
	ldr r1, _0203A860 ; =0x00200010
	cmp r6, r1
	bgt _0203A780
	beq _0203A7BC
	b _0203A7F4
_0203A780:
	ldr r1, _0203A854 ; =0x00300010
	cmp r6, r1
	beq _0203A7E0
	b _0203A7F4
_0203A788:
	cmp r0, #0x40
	beq _0203A790
	cmp r0, #0x20
	bne _0203A79A
_0203A790:
	mov r0, #0x1f
	lsl r1, r4, #2
	lsl r0, r0, #4
	add r3, r1, r0
	b _0203A7FC
_0203A79A:
	mov r0, #0x3f
	lsl r1, r4, #2
	lsl r0, r0, #4
	add r3, r1, r0
	b _0203A7FC
_0203A7A4:
	cmp r0, #0x40
	beq _0203A7B2
	cmp r0, #0x20
	beq _0203A7B2
	lsr r1, r1, #0xc
	cmp r0, r1
	bne _0203A7F4
_0203A7B2:
	mov r0, #0x7e
	lsl r1, r4, #1
	lsl r0, r0, #2
	add r3, r1, r0
	b _0203A7FC
_0203A7BC:
	cmp r0, #0x30
	beq _0203A7C4
	cmp r0, #0x50
	bne _0203A7CC
_0203A7C4:
	mov r0, #0x9f
	lsl r0, r0, #2
	add r3, r4, r0
	b _0203A7FC
_0203A7CC:
	cmp r0, #0x10
	bne _0203A7D8
	mov r0, #0x7f
	lsl r0, r0, #2
	add r3, r4, r0
	b _0203A7FC
_0203A7D8:
	mov r0, #0xff
	lsl r0, r0, #2
	add r3, r4, r0
	b _0203A7FC
_0203A7E0:
	cmp r0, #3
	bne _0203A7EC
	mov r0, #0xff
	lsl r0, r0, #2
	add r3, r4, r0
	b _0203A7FC
_0203A7EC:
	mov r0, #0x7f
	lsl r0, r0, #2
	add r3, r4, r0
	b _0203A7FC
_0203A7F4:
	mov r0, #0xfe
	lsl r1, r4, #1
	lsl r0, r0, #2
	add r3, r1, r0
_0203A7FC:
	cmp r7, #1
	bne _0203A806
	mov r4, #7
	lsl r4, r4, #0x18
	b _0203A808
_0203A806:
	ldr r4, _0203A864 ; =0x07000400
_0203A808:
	add r0, r5, #0
	add r0, #0x20
	ldrb r2, [r0]
	add r0, r5, #0
	add r0, #0x22
	ldrb r1, [r0]
	ldrh r6, [r5, #0xe]
	ldrh r0, [r5, #0xc]
	lsl r1, r1, #0xa
	lsl r6, r6, #0x18
	lsr r6, r6, #0x18
	orr r6, r1
	mov r1, #1
	lsl r0, r0, #0x17
	lsl r1, r1, #0x1e
	lsr r0, r0, #7
	orr r1, r6
	orr r0, r1
	str r0, [r4]
	lsl r0, r2, #0xc
	orr r0, r3
	strh r0, [r4, #4]
	ldr r0, [r5, #0x1c]
	cmp r4, r0
	beq _0203A84E
	add r1, r5, #0
	add r1, #0x22
	ldrb r1, [r1]
	lsl r2, r1, #0xa
	ldr r1, _0203A868 ; =0x40000200
	orr r1, r2
	str r1, [r0]
	mov r1, #0
	strh r1, [r0, #4]
	str r4, [r5, #0x1c]
_0203A84E:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0203A850: .word 0x04000304
_0203A854: .word 0x00300010
_0203A858: .word 0x04001000
_0203A85C: .word 0x00100010
_0203A860: .word 0x00200010
_0203A864: .word 0x07000400
_0203A868: .word 0x40000200
	thumb_func_end sub_0203A700
