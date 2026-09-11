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

	thumb_func_start ov80_02237264
ov80_02237264: ; 0x02237264
	push {r3, lr}
	ldrb r1, [r0, #4]
	cmp r1, #0
	bne _02237284
	ldrb r1, [r0, #6]
	lsl r1, r1, #1
	add r1, r0, r1
	ldrh r2, [r1, #0x18]
	ldr r1, _022372B0 ; =0x0000FECB
	add r1, r2, r1
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	cmp r1, #1
	bhi _02237284
	mov r0, #7
	pop {r3, pc}
_02237284:
	bl ov80_022372B4
	add r0, r0, #1
	mov r1, #7
	cmp r0, #4
	bhi _022372AC
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223729C: ; jump table
	.short _022372AC - _0223729C - 2 ; case 0
	.short _022372A6 - _0223729C - 2 ; case 1
	.short _022372A6 - _0223729C - 2 ; case 2
	.short _022372AA - _0223729C - 2 ; case 3
	.short _022372AA - _0223729C - 2 ; case 4
_022372A6:
	mov r1, #0
	b _022372AC
_022372AA:
	mov r1, #1
_022372AC:
	add r0, r1, #0
	pop {r3, pc}
	.balign 4, 0
_022372B0: .word 0x0000FECB
	thumb_func_end ov80_02237264
