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

	thumb_func_start ov80_0223A938
ov80_0223A938: ; 0x0223A938
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	mov r3, #1
	lsl r3, r3, #0x1a
	add r5, r0, #0
	add r4, r1, #0
	ldr r1, [r3]
	ldr r0, _0223AA3C ; =0xFFFF1FFF
	add r2, r3, #0
	and r1, r0
	mov r0, #6
	lsl r0, r0, #0xc
	orr r0, r1
	str r0, [r3]
	add r2, #0x48
	ldrh r6, [r2]
	mov r0, #0x3f
	mov r1, #0x1f
	bic r6, r0
	orr r1, r6
	mov r7, #0x20
	orr r1, r7
	strh r1, [r2]
	ldrh r6, [r2]
	ldr r1, _0223AA40 ; =0xFFFFC0FF
	and r1, r6
	mov r6, #0x1f
	lsl r6, r6, #8
	orr r6, r1
	lsl r1, r7, #8
	orr r1, r6
	strh r1, [r2]
	add r1, r3, #0
	add r1, #0x4a
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #0x1d
	orr r0, r2
	orr r0, r7
	strh r0, [r1]
	add r1, r3, #0
	mov r0, #0
	add r1, #0x40
	strh r0, [r1]
	add r1, r3, #0
	add r1, #0x44
	strh r0, [r1]
	add r1, r3, #0
	add r1, #0x42
	strh r0, [r1]
	add r3, #0x46
	strh r0, [r3]
	str r0, [sp]
	str r7, [sp, #4]
	mov r0, #0xc0
	str r0, [sp, #8]
	ldrb r2, [r4, #8]
	ldr r0, [r5, #0x1c]
	mov r1, #0x6d
	mov r3, #0x65
	bl PaletteData_LoadNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x65
	str r0, [sp, #0xc]
	ldrb r1, [r4, #9]
	ldr r0, [r5, #0x24]
	ldr r2, [r5, #0x10]
	mov r3, #1
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x65
	str r0, [sp, #0xc]
	ldrb r1, [r4, #0xa]
	ldr r0, [r5, #0x24]
	ldr r2, [r5, #0x10]
	mov r3, #1
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add r0, r7, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0xc
	str r0, [sp, #8]
	mov r2, #0
	ldr r0, [r5, #0x10]
	mov r1, #1
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	ldr r0, [r5, #0x10]
	mov r1, #1
	bl ScheduleBgTilemapBufferTransfer
	ldrb r1, [r4, #8]
	mov r0, #0x6d
	add r2, sp, #0x10
	mov r3, #0x65
	bl GfGfxLoader_GetPlttData
	add r4, r0, #0
	ldr r0, [sp, #0x10]
	add r1, r5, #0
	add r2, r7, #0
	ldr r0, [r0, #0xc]
	add r1, #0x40
	add r2, #0xe0
	bl MIi_CpuCopy16
	add r0, r4, #0
	bl Heap_Free
	ldr r0, _0223AA44 ; =ov80_0223AA4C
	ldr r2, _0223AA48 ; =0x0000044C
	add r1, r5, #0
	bl SysTask_CreateOnMainQueue
	mov r1, #5
	lsl r1, r1, #6
	str r0, [r5, r1]
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_0223AA3C: .word 0xFFFF1FFF
_0223AA40: .word 0xFFFFC0FF
_0223AA44: .word ov80_0223AA4C
_0223AA48: .word 0x0000044C
	thumb_func_end ov80_0223A938
