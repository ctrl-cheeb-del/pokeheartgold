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

	thumb_func_start ov82_0223EE6C
ov82_0223EE6C: ; 0x0223EE6C
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	add r4, r1, #0
	mov r0, #0x69
	str r0, [sp, #0xc]
	mov r0, #0x22
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	ldr r2, [r5, #0x48]
	mov r1, #0x81
	add r3, r4, #0
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x69
	str r0, [sp, #0xc]
	mov r0, #0x22
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	ldr r2, [r5, #0x48]
	mov r1, #0x82
	add r3, r4, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x69
	str r0, [sp, #4]
	mov r0, #0x22
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0xbe
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end ov82_0223EE6C


	thumb_func_start ov82_0223EECC
ov82_0223EECC: ; 0x0223EECC
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r1, #0
	add r5, r0, #0
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x69
	bl BG_ClearCharDataRange
	mov r1, #1
	str r1, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov r0, #0x69
	str r0, [sp, #0xc]
	mov r0, #0x22
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	ldr r2, [r5, #0x48]
	mov r1, #0x85
	add r3, r4, #0
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r3, #0x20
	str r3, [sp]
	mov r0, #0x69
	str r0, [sp, #4]
	mov r0, #0x22
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0xc0
	mov r2, #4
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov82_0223EECC


	thumb_func_start ov82_0223EF1C
ov82_0223EF1C: ; 0x0223EF1C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	add r1, sp, #0x38
	ldrb r1, [r1]
	add r5, r0, #0
	add r0, r4, #0
	add r6, r2, #0
	add r7, r3, #0
	bl FillWindowPixelBuffer
	ldr r0, [r5, #0x20]
	ldr r2, [r5, #0x2c]
	add r1, r6, #0
	bl ReadMsgDataIntoString
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x2c]
	bl StringExpandPlaceholders
	ldr r0, [sp, #0x28]
	add r2, sp, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	add r3, r7, #0
	str r0, [sp, #4]
	add r0, sp, #0x38
	ldrb r1, [r0]
	ldrb r0, [r2, #0x18]
	ldrb r2, [r2, #0x1c]
	lsl r0, r0, #0x18
	lsl r2, r2, #0x18
	lsr r0, r0, #8
	lsr r2, r2, #0x10
	orr r0, r2
	orr r0, r1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r1, sp, #0x3c
	ldrb r1, [r1]
	ldr r2, [r5, #0x28]
	add r0, r4, #0
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov82_0223EF1C
