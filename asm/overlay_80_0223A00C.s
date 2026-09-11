	.include "asm/macros.inc"
	.public _0223A05E
	.public _0223A0B4
	.public _0223A0B8
	.public _0223A0BC
	.public _0223A13C
	.public _0223A140
	.public _0223A16C
	.public _0223A170
	.public _0223A188
	.public _0223A194
	.public _0223A1BA
	.public _0223A3AA
	.public _0223A3BA
	.public _0223A3D4
	.public _0223A3E2
	.public _0223A410
	.public _0223A42E
	.public _0223A43E
	.public _0223A458
	.public _0223A468
	.public _0223A476
	.public _0223A48A
	.public _0223A4A6
	.public _0223A4AC
	.public _0223A4C4
	.public _0223A4D0
	.public _0223A4F4
	.public _0223A4FC
	.public _0223A4FE
	.public _0223A50C
	.public _0223A510
	.public _0223A514
	.public _0223A518
	.public _0223A51C
	.public _0223A520
	.public _0223A524
	.public _0223A528
	.public _0223A52C
	.public _0223A530
	.public _0223A534
	.public _0223A57A
	.public _0223A594
	.public _0223A5A8
	.public _0223A5B8
	.public _0223A5D8
	.public _0223A5E8
	.public _0223A5FA
	.public _0223A620
	.public _0223A628
	.public _0223A646
	.public _0223A660
	.public _0223A668
	.public _0223A6A6
	.public _0223A6B2
	.public _0223A6D6
	.public _0223A732
	.public _0223A784
	.public _0223A79E
	.public _0223A7C0
	.public _0223A7FA
	.public _0223A808
	.public _0223A818
	.public _0223A822
	.public _0223A862
	.public _0223A876
	.public _0223A8A8
	.public _0223A8BE
	.public _0223A914
	.public _0223AA3C
	.public _0223AA40
	.public _0223AA44
	.public _0223AA48
	.public _0223AA66
	.public _0223AA7E
	.public _0223AAAE
	.public _0223AAC8
	.public _0223AACC
	.public _0223AB00
	.public _0223AB28
	.public _0223AB60
	.public _0223AB88
	.public _0223ABA8
	.public _0223ABE4
	.public _0223ABFE
	.public _0223AC1C
	.public _0223AC20
	.public ov80_0223A00C
	.public ov80_0223A0C0
	.public ov80_0223A0EC
	.public ov80_0223A144
	.public ov80_0223A174
	.public ov80_0223A62C
	.public ov80_0223A748
	.public ov80_0223A75C
	.public ov80_0223A78C
	.public ov80_0223A81C
	.public ov80_0223A834
	.public ov80_0223A8C4
	.public ov80_0223A8D4
	.public ov80_0223A91C
	.public ov80_0223A938
	.public ov80_0223AA4C
	.public ov80_0223AA80
	.public ov80_0223AAD0
	.public ov80_0223AB34
	.public ov80_0223AB94
	.public ov80_0223DB30
	.public ov80_0223DB64
	.public ov80_0223DB98
	.include "overlay_80_0223A00C.inc"
	.include "global.inc"

    .text
	.public ov80_0223A00C
	.public ov80_0223A0C0
	.public ov80_0223A144
	.public ov80_0223A748
	.public ov80_0223A75C
	.public ov80_0223A78C
	.public ov80_0223A81C
	.public ov80_0223A8C4
	.public ov80_0223A8D4
	.public ov80_0223A91C
	.public ov80_0223AA4C
	.public ov80_0223AA80
	.public ov80_0223AAD0
	.public ov80_0223AB34
	.public ov80_0223AB94

	thumb_func_start ov80_0223A0EC
ov80_0223A0EC: ; 0x0223A0EC
	push {r3, r4, r5, r6}
	add r0, r1, #0
	ldr r1, _0223A13C ; =0x00000151
	sub r2, r1, #2
	ldrb r3, [r0, r2]
	sub r2, r1, #3
	ldrb r2, [r0, r2]
	ldrb r4, [r0, r1]
	lsl r3, r3, #8
	lsl r5, r2, #8
	add r6, r5, #0
	sub r5, r1, #1
	mov r2, #0xff
	lsl r2, r2, #8
	and r3, r2
	ldrb r5, [r0, r5]
	and r6, r2
	orr r3, r4
	orr r5, r6
	ldr r6, _0223A140 ; =0x04000040
	strh r5, [r6]
	strh r3, [r6, #4]
	add r3, r1, #4
	ldrb r5, [r0, r3]
	add r3, r1, #2
	ldrb r4, [r0, r3]
	add r3, r1, #1
	ldrb r3, [r0, r3]
	add r1, r1, #3
	ldrb r0, [r0, r1]
	lsl r3, r3, #8
	and r3, r2
	orr r0, r3
	strh r0, [r6, #2]
	lsl r0, r4, #8
	and r0, r2
	orr r0, r5
	strh r0, [r6, #6]
	pop {r3, r4, r5, r6}
	bx lr
	.balign 4, 0
_0223A13C: .word 0x00000151
_0223A140: .word 0x04000040
	thumb_func_end ov80_0223A0EC
