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

	thumb_func_start ov82_0223E820
ov82_0223E820: ; 0x0223E820
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldrb r1, [r4, #8]
	cmp r1, #0
	beq _0223E836
	cmp r1, #1
	beq _0223E842
	cmp r1, #2
	beq _0223E872
	b _0223E880
_0223E836:
	mov r0, #0xa
	strb r0, [r4, #0x1b]
	ldrb r0, [r4, #8]
	add r0, r0, #1
	strb r0, [r4, #8]
	b _0223E880
_0223E842:
	ldrb r1, [r4, #0x1b]
	sub r1, r1, #1
	strb r1, [r4, #0x1b]
	ldrb r1, [r4, #0x1b]
	cmp r1, #0
	bne _0223E880
	bl ov82_0223F90C
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x69
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldrb r0, [r4, #8]
	add r0, r0, #1
	strb r0, [r4, #8]
	b _0223E880
_0223E872:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0223E880
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, pc}
_0223E880:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov82_0223E820


	thumb_func_start ov82_0223E888
ov82_0223E888: ; 0x0223E888
	push {r4, lr}
	add r4, r0, #0
	ldrb r1, [r4, #8]
	cmp r1, #0
	beq _0223E898
	cmp r1, #1
	beq _0223E8BA
	b _0223E8BE
_0223E898:
	bl ov82_0223F834
	mov r0, #0x82
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov82_0223FCB0
	add r0, r4, #0
	add r0, #0x4c
	mov r1, #0
	bl ClearFrameAndWindow2
	ldrb r0, [r4, #8]
	add r0, r0, #1
	strb r0, [r4, #8]
	b _0223E8BE
_0223E8BA:
	mov r0, #1
	pop {r4, pc}
_0223E8BE:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov82_0223E888


	thumb_func_start ov82_0223E8C4
ov82_0223E8C4: ; 0x0223E8C4
	push {r4, r5, r6, lr}
	add r6, r0, #0
	mov r0, #0x81
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	cmp r0, #0
	beq _0223E8D6
	bl ov82_0223FC9C
_0223E8D6:
	mov r0, #0x82
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	cmp r0, #0
	beq _0223E8E4
	bl ov82_0223FC9C
_0223E8E4:
	add r0, r6, #0
	add r0, #0x8c
	ldr r0, [r0]
	bl ov82_0223FDC0
	bl sub_0203A914
	add r0, r6, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #2
	bl PaletteData_FreeBuffers
	add r0, r6, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0
	bl PaletteData_FreeBuffers
	add r0, r6, #0
	add r0, #0x94
	ldr r0, [r0]
	bl PaletteData_Free
	add r0, r6, #0
	mov r1, #0
	add r0, #0x94
	str r1, [r0]
	add r0, r6, #0
	add r0, #0xa8
	bl ov82_0223FBBC
	ldr r0, [r6, #0x20]
	bl DestroyMsgData
	ldr r0, [r6, #0x24]
	bl MessageFormat_Delete
	ldr r0, [r6, #0x28]
	bl String_Delete
	ldr r0, [r6, #0x2c]
	bl String_Delete
	add r0, r6, #0
	add r0, #0x98
	ldr r0, [r0]
	bl MessagePrinter_Delete
	mov r4, #0
	add r5, r6, #0
_0223E94A:
	ldr r0, [r5, #0x30]
	bl String_Delete
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _0223E94A
	add r0, r6, #0
	add r0, #0x4c
	bl ov82_0223FD5C
	ldr r0, [r6, #0x48]
	bl ov82_0223EBB8
	mov r0, #0x22
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	bl NARC_Delete
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov82_0223E8C4


	thumb_func_start ov82_0223E974
ov82_0223E974: ; 0x0223E974
	push {r4, lr}
	add r4, r0, #0
	bl ov82_0223E9B0
	mov r0, #0x69
	bl BgConfig_Alloc
	str r0, [r4, #0x48]
	add r0, r4, #0
	bl ov82_0223E9E8
	ldrb r0, [r4, #0xd]
	bl ov80_02237920
	cmp r0, #0xfe
	bne _0223E9AE
	mov r0, #0x81
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #2
	bl ov82_0223FCFC
	mov r0, #0x81
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x80
	mov r2, #0xa8
	bl ov82_0223FCBC
_0223E9AE:
	pop {r4, pc}
	thumb_func_end ov82_0223E974
