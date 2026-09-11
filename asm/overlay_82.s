	.include "asm/macros.inc"
	.include "overlay_82.inc"
	.include "global.inc"

	.text
	.public _0223FE20
	.public ov82_0223DD60
	.public ov82_0223DE20
	.public ov82_0223DF74
	.public ov82_0223DFBC
	.public ov82_0223E070
	.public ov82_0223E0B0
	.public ov82_0223E140
	.public ov82_0223E2A4
	.public ov82_0223E2EC
	.public ov82_0223E5D4
	.public ov82_0223E820
	.public ov82_0223E888
	.public ov82_0223E8C4
	.public ov82_0223E974
	.public ov82_0223E9E8
	.public ov82_0223EB3C
	.public ov82_0223EBB8
	.public ov82_0223EC0C
	.public ov82_0223EC68
	.public ov82_0223ED94
	.public ov82_0223EDF0
	.public ov82_0223EE6C
	.public ov82_0223EECC
	.public ov82_0223EF1C
	.public ov82_0223EFCC
	.public ov82_0223F040
	.public ov82_0223F134
	.public ov82_0223F1AC
	.public ov82_0223F224
	.public ov82_0223F300
	.public ov82_0223F488
	.public ov82_0223F5E0
	.public ov82_0223F84C
	.public ov82_0223F95C
	.public ov82_0223FB08
	.public ov82_0223FBBC
	.public ov82_0223FC48
	.public ov82_0223FDC8
	.public ov82_0223FE28
	.public ov82_0223FE38
	.public ov82_0223FE54
	.public ov82_0223FE70
	.public ov82_0223FE8C
	.public ov82_0223FEA8
	.public ov82_0223FEC4
	.public ov82_0223FEEC
	.public ov82_0223FEF0
	.public ov82_0223FF00
	.public ov82_0223E7E8
	.public ov82_0223E9B0
	.public ov82_0223EB9C
	.public ov82_0223EC48
	.public ov82_0223EE38
	.public ov82_0223EF7C
	.public ov82_0223EFB4
	.public ov82_0223F10C
	.public ov82_0223F2F8
	.public ov82_0223F53C
	.public ov82_0223F558
	.public ov82_0223F570
	.public ov82_0223F580
	.public ov82_0223F6C4
	.public ov82_0223F6CC
	.public ov82_0223F6E4
	.public ov82_0223F6E8
	.public ov82_0223F74C
	.public ov82_0223F764
	.public ov82_0223F770
	.public ov82_0223F7B4
	.public ov82_0223F808
	.public ov82_0223F814
	.public ov82_0223F834
	.public ov82_0223F8E4
	.public ov82_0223F90C
	.public ov82_0223F948
	.public ov82_0223FC14
	.public ov82_0223FC9C
	.public ov82_0223FCB0
	.public ov82_0223FCBC
	.public ov82_0223FCFC
	.public ov82_0223FD18
	.public ov82_0223FD2C
	.public ov82_0223FD5C
	.public ov82_0223FD78
	.public ov82_0223FDB8
	.public ov82_0223FDC0
	.public ov82_0223FE18
	.public ov82_0223DD60
	.public ov82_0223DE20
	.public ov82_0223DF74
	.public ov82_0223DFBC
	.public ov82_0223E070
	.public ov82_0223E0B0
	.public ov82_0223E2A4


	thumb_func_start ov82_0223E140
ov82_0223E140: ; 0x0223E140
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	ldr r5, [sp, #0x4c]
	add r6, r3, #0
	str r6, [sp]
	mov r2, #1
	str r2, [sp, #4]
	str r2, [sp, #8]
	lsl r2, r5, #0x18
	lsr r2, r2, #0x18
	str r2, [sp, #0xc]
	add r2, sp, #0x30
	ldrh r2, [r2, #0x18]
	ldr r3, [sp, #0x18]
	str r0, [sp, #0x10]
	bl FillBgTilemapRect
	add r1, sp, #0x30
	ldrh r4, [r1, #0x18]
	ldrb r7, [r1, #0x10]
	ldr r0, [sp, #0x18]
	add r2, r4, #2
	add r0, r0, r7
	sub r0, r0, #1
	str r0, [sp, #0x20]
	ldr r3, [sp, #0x20]
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	str r6, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, sp, #0x30
	ldrb r0, [r0, #0x14]
	add r2, r4, #6
	lsl r2, r2, #0x10
	str r0, [sp, #0x28]
	add r0, r6, r0
	sub r0, r0, #1
	str r0, [sp, #0x24]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r3, [sp, #0x18]
	lsr r2, r2, #0x10
	bl FillBgTilemapRect
	ldr r0, [sp, #0x24]
	add r2, r4, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r3, [sp, #0x20]
	add r2, #8
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	sub r0, r7, #2
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	add r2, r4, #1
	add r7, r0, #1
	ldr r0, [sp, #0x1c]
	lsl r2, r2, #0x10
	lsl r0, r0, #0x18
	lsl r3, r7, #0x18
	str r6, [sp]
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x24]
	add r2, r4, #7
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x1c]
	lsl r2, r2, #0x10
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	lsl r3, r7, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x28]
	add r6, r6, #1
	sub r7, r0, #2
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	add r2, r4, #3
	lsl r2, r2, #0x10
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r3, [sp, #0x18]
	lsr r2, r2, #0x10
	bl FillBgTilemapRect
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r3, [sp, #0x20]
	add r2, r4, #5
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov82_0223E140
