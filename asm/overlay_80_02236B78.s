	.public _02236B80
	.public _02236B94
	.public _02236B9C
	.public _02236BA4
	.public _02236BB2
	.public _02236BBE
	.public _02236BCC
	.public _02236BD0
	.public _02236BD4
	.public _02236BD8
	.public _02236BDC
	.public _02236BE0
	.public _02236BF4
	.public _02236C0C
	.public _02236C1A
	.public _02236C22
	.public _02236C38
	.public _02236C3C
	.public _02236C4A
	.public _02236C58
	.public _02236C62
	.public _02236C6C
	.public _02236C70
	.public _02236C74
	.public _02236C7E
	.public _02236C8A
	.public _02236C94
	.public _02236C98
	.public _02236CBA
	.public _02236CD6
	.public _02236CE0
	.public _02236CE8
	.public _02236CFC
	.public _02236D30
	.public _02236D4A
	.public _02236D64
	.public _02236D78
	.public _02236D8E
	.public _02236DA4
	.public _02236DC2
	.public _02236DC8
	.public _02236DD0
	.public _02236DE4
	.public _02236DEC
	.public _02236DF0
	.public _02236DF4
	.public _02236E08
	.public _02236E10
	.public _02236E14
	.public _02236E1C
	.public _02236E20
	.public _02236E56
	.public _02236E70
	.public _02236EB4
	.public _02236EBA
	.public _02236EE4
	.public _02236F94
	.public _02236FB6
	.public _02236FFC
	.public _0223701C
	.public _0223703E
	.public _0223704E
	.public _022370B6
	.public _022370DE
	.public _022370E4
	.public _022370EC
	.public _022370F0
	.public _02237104
	.public _0223710C
	.public _02237110
	.public _02237114
	.public _02237118
	.public _0223711C
	.public _0223712A
	.public _02237178
	.public _022371A8
	.public _022371AC
	.public _022371C6
	.public _022371D4
	.public _02237208
	.public _02237248
	.public _0223724C
	.public _02237250
	.public _0223725C
	.public _02237260
	.public _02237284
	.public _0223729C
	.public _022372A6
	.public _022372AA
	.public _022372AC
	.public _022372B0
	.public _022372D0
	.public _022372D4
	.public ov80_02236B78
	.public ov80_02236BE4
	.public ov80_02236C2C
	.public ov80_02236C78
	.public ov80_02236C9C
	.public ov80_02236DD4
	.public ov80_02236DF8
	.public ov80_02236E24
	.public ov80_02236E90
	.public ov80_02236F24
	.public ov80_022370F4
	.public ov80_02237120
	.public ov80_02237130
	.public ov80_022371B0
	.public ov80_02237254
	.public ov80_02237264
	.public ov80_022372B4
	.public ov80_0223DD38
    .include "asm/macros.inc"
	.include "overlay_80_02236B78.inc"
	.include "global.inc"

    .text
	.public ov80_02236B78
	.public ov80_02236BE4
	.public ov80_02236C2C
	.public ov80_02236C78
	.public ov80_02236DD4
	.public ov80_02236DF8
	.public ov80_02236E24
	.public ov80_022370F4
	.public ov80_02237120
	.public ov80_02237130
	.public ov80_022371B0
	.public ov80_02237254
	.public ov80_022372B4

	thumb_func_start ov80_02236C9C
ov80_02236C9C: ; 0x02236C9C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x84
	str r0, [sp]
	ldr r0, [sp, #0xa0]
	str r1, [sp, #4]
	str r0, [sp, #0xa0]
	ldr r0, [sp, #0xa8]
	add r7, r2, #0
	str r0, [sp, #0xa8]
	add r0, r3, #0
	str r3, [sp, #8]
	cmp r0, #6
	ble _02236CBA
	bl GF_AssertFail
_02236CBA:
	ldr r0, [sp, #0xa0]
	mov r4, #0
	ldrh r1, [r0, #4]
	ldrh r0, [r0, #2]
	sub r0, r1, r0
	add r1, sp, #0x88
	ldrh r5, [r1, #0x1c]
	str r0, [sp, #0x1c]
	add r0, r4, #0
	cmp r5, #0
	beq _02236CE8
	ldr r3, _02236DD0 ; =ov80_0223C464
	mov r0, #5
	add r2, r4, #0
_02236CD6:
	ldr r1, [r3]
	cmp r5, r1
	bgt _02236CE0
	add r0, r2, #0
	b _02236CE8
_02236CE0:
	add r2, r2, #1
	add r3, r3, #4
	cmp r2, #5
	blo _02236CD6
_02236CE8:
	ldr r1, [sp, #8]
	cmp r1, #0
	beq _02236DC8
	add r1, sp, #0x24
	str r1, [sp, #0x14]
	ldr r1, [sp, #0x98]
	str r1, [sp, #0x10]
	ldr r1, [sp, #8]
	sub r0, r1, r0
	str r0, [sp, #0xc]
_02236CFC:
	ldr r0, [sp, #0xc]
	cmp r4, r0
	blt _02236D30
	ldr r0, [sp, #0xa0]
	ldrb r0, [r0, #7]
	cmp r0, #1
	bne _02236D30
	ldr r0, [sp, #0xa0]
	ldrh r1, [r0, #0xc]
	ldrh r0, [r0, #0xa]
	sub r0, r1, r0
	str r0, [sp, #0x1c]
	bl LCRandom
	ldr r1, [sp, #0x1c]
	add r1, r1, #1
	bl _s32_div_f
	ldr r0, [sp, #0xa0]
	ldrh r0, [r0, #0xc]
	sub r0, r0, r1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0xa0]
	ldrb r0, [r0, #0xe]
	str r0, [sp, #0x20]
	b _02236D4A
_02236D30:
	bl LCRandom
	ldr r1, [sp, #0x1c]
	add r1, r1, #1
	bl _s32_div_f
	ldr r0, [sp, #0xa0]
	ldrh r0, [r0, #4]
	sub r0, r0, r1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0xa0]
	ldrb r0, [r0, #6]
	str r0, [sp, #0x20]
_02236D4A:
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	mov r2, #0xcd
	bl ov80_02229EF4
	mov r2, #0
	cmp r4, #0
	ble _02236D78
	ldr r1, [sp, #0x14]
	ldr r3, [sp, #0x14]
	ldrh r1, [r1]
	ldrh r3, [r3, #0xc]
	add r0, sp, #0x24
_02236D64:
	ldrh r5, [r0]
	cmp r5, r1
	beq _02236D78
	ldrh r5, [r0, #0xc]
	cmp r5, r3
	beq _02236D78
	add r2, r2, #1
	add r0, #0x10
	cmp r2, r4
	blt _02236D64
_02236D78:
	cmp r2, r4
	bne _02236DC2
	mov r3, #0
	cmp r7, #0
	ble _02236DA4
	ldr r2, [sp, #0x14]
	ldr r5, [sp, #0x14]
	ldrh r2, [r2]
	ldrh r6, [r5, #0xc]
	ldr r0, [sp]
	ldr r1, [sp, #4]
_02236D8E:
	ldrh r5, [r0]
	cmp r2, r5
	beq _02236DA4
	ldrh r5, [r1]
	cmp r6, r5
	beq _02236DA4
	add r3, r3, #1
	add r0, r0, #2
	add r1, r1, #2
	cmp r3, r7
	blt _02236D8E
_02236DA4:
	cmp r3, r7
	bne _02236DC2
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x10]
	strh r1, [r0]
	ldr r1, [sp, #0x20]
	ldr r0, [sp, #0xa8]
	strb r1, [r0, r4]
	ldr r0, [sp, #0x14]
	add r4, r4, #1
	add r0, #0x10
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, r0, #2
	str r0, [sp, #0x10]
_02236DC2:
	ldr r0, [sp, #8]
	cmp r4, r0
	bne _02236CFC
_02236DC8:
	mov r0, #0
	add sp, #0x84
	pop {r4, r5, r6, r7, pc}
	nop
_02236DD0: .word ov80_0223C464
	thumb_func_end ov80_02236C9C
