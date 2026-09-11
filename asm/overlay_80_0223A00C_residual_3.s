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

	thumb_func_start ov80_0223A834
ov80_0223A834: ; 0x0223A834
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r7, r0, #0
	mov r0, #1
	mov r1, #2
	str r0, [sp]
	ldrsh r0, [r7, r1]
	cmp r0, #4
	bge _0223A862
	mov r0, #0
	str r0, [sp]
	ldrsh r0, [r7, r0]
	sub r0, r0, #1
	strh r0, [r7]
	ldr r0, [sp]
	ldrsh r0, [r7, r0]
	cmp r0, #0
	bgt _0223A862
	mov r0, #3
	strh r0, [r7]
	ldrsh r0, [r7, r1]
	add r0, r0, #1
	strh r0, [r7, #2]
_0223A862:
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #2
	ldrsh r0, [r7, r0]
	cmp r0, #0
	ble _0223A8BE
	add r6, r7, #0
	add r6, #0x14
	add r4, r7, #0
	add r5, r7, #0
_0223A876:
	add r0, r6, #0
	bl ov80_0223A8D4
	ldr r1, [r4, #0x14]
	str r0, [sp, #8]
	add r0, sp, #0xc
	add r2, r1, #0
	add r3, r1, #0
	bl ov80_0223A91C
	ldr r0, [r5, #4]
	add r1, sp, #0xc
	ldr r0, [r0]
	bl Sprite_SetAffineScale
	ldr r0, [r5, #4]
	mov r1, #1
	ldr r0, [r0]
	bl Sprite_SetDrawFlag
	ldr r0, [sp, #8]
	cmp r0, #0
	bne _0223A8A8
	mov r0, #0
	str r0, [sp]
_0223A8A8:
	ldr r0, [sp, #4]
	add r6, #0x14
	add r0, r0, #1
	str r0, [sp, #4]
	mov r0, #2
	ldrsh r1, [r7, r0]
	ldr r0, [sp, #4]
	add r4, #0x14
	add r5, r5, #4
	cmp r0, r1
	blt _0223A876
_0223A8BE:
	ldr r0, [sp]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov80_0223A834
