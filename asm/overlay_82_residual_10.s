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

	thumb_func_start ov82_0223F5E0
ov82_0223F5E0: ; 0x0223F5E0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r0, #0
	add r4, r1, #0
	add r5, r2, #0
	bne _0223F5F0
	mov r1, #0
	b _0223F602
_0223F5F0:
	cmp r5, #1
	bne _0223F5F8
	mov r1, #5
	b _0223F602
_0223F5F8:
	cmp r5, #2
	bne _0223F600
	mov r1, #4
	b _0223F602
_0223F600:
	mov r1, #3
_0223F602:
	lsr r3, r4, #0x1f
	lsl r2, r4, #0x1e
	sub r2, r2, r3
	mov r0, #0x1e
	ror r2, r0
	add r0, r3, r2
	lsl r0, r0, #3
	str r0, [sp, #0xc]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	lsl r2, r4, #0x1d
	mov ip, r0
	sub r2, r2, r3
	mov r0, #0x1d
	ror r2, r0
	add r6, r3, r2
	cmp r6, #4
	bge _0223F62A
	mov r2, #5
	b _0223F62C
_0223F62A:
	mov r2, #4
_0223F62C:
	cmp r4, #4
	bhs _0223F634
	mov r3, #0
	b _0223F64E
_0223F634:
	cmp r4, #8
	bhs _0223F63C
	mov r3, #5
	b _0223F64E
_0223F63C:
	cmp r4, #0xc
	bhs _0223F644
	mov r3, #9
	b _0223F64E
_0223F644:
	cmp r4, #0x10
	bhs _0223F64C
	mov r3, #0xe
	b _0223F64E
_0223F64C:
	mov r3, #0x12
_0223F64E:
	mov r0, #8
	str r0, [sp]
	str r2, [sp, #4]
	str r1, [sp, #8]
	add r0, r7, #0
	mov r1, #3
	mov r2, ip
	bl BgTilemapRectChangePalette
	cmp r5, #0
	bne _0223F6C0
	ldr r0, [sp, #0xc]
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	cmp r6, #4
	bge _0223F672
	mov r1, #2
	b _0223F674
_0223F672:
	mov r1, #3
_0223F674:
	cmp r4, #4
	bhs _0223F67C
	mov r3, #2
	b _0223F696
_0223F67C:
	cmp r4, #8
	bhs _0223F684
	mov r3, #6
	b _0223F696
_0223F684:
	cmp r4, #0xc
	bhs _0223F68C
	mov r3, #0xb
	b _0223F696
_0223F68C:
	cmp r4, #0x10
	bhs _0223F694
	mov r3, #0xf
	b _0223F696
_0223F694:
	mov r3, #0x14
_0223F696:
	cmp r4, #9
	bhs _0223F6AE
	mov r0, #1
	str r0, [sp]
	str r1, [sp, #4]
	str r0, [sp, #8]
	add r0, r7, #0
	mov r1, #3
	bl BgTilemapRectChangePalette
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_0223F6AE:
	mov r0, #1
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	add r0, r7, #0
	mov r1, #3
	bl BgTilemapRectChangePalette
_0223F6C0:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov82_0223F5E0
