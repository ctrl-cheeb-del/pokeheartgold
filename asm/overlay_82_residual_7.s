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

	thumb_func_start ov82_0223EFCC
ov82_0223EFCC: ; 0x0223EFCC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r1, #0
	mov r1, #0x85
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	mov r1, #0
	add r7, r2, #0
	add r4, r3, #0
	bl Party_GetMonByIndex
	mov r1, #0xb3
	add r2, sp, #0x10
	bl GetMonData
	add r1, sp, #0x30
	ldrb r1, [r1, #0x18]
	add r0, r5, #0
	bl FillWindowPixelBuffer
	mov r0, #0xb
	mov r1, #0x69
	bl String_New
	add r1, sp, #0x10
	add r6, r0, #0
	bl CopyU16ArrayToString
	str r4, [sp]
	mov r4, #0
	str r4, [sp, #4]
	add r2, sp, #0x30
	ldrb r0, [r2, #0x10]
	ldrb r3, [r2, #0x14]
	ldrb r1, [r2, #0x18]
	lsl r0, r0, #0x18
	lsl r3, r3, #0x18
	lsr r0, r0, #8
	lsr r3, r3, #0x10
	orr r0, r3
	orr r0, r1
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	ldrb r1, [r2, #0x1c]
	add r0, r5, #0
	add r2, r6, #0
	add r3, r7, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	add r0, r5, #0
	bl CopyWindowToVram
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov82_0223EFCC


	thumb_func_start ov82_0223F040
ov82_0223F040: ; 0x0223F040
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	str r1, [sp, #0x10]
	add r0, r1, #0
	add r1, sp, #0x30
	ldrb r1, [r1, #0x10]
	add r4, r2, #0
	add r6, r3, #0
	bl FillWindowPixelBuffer
	ldr r2, _0223F108 ; =0x000002DF
	mov r0, #1
	mov r1, #0x1b
	mov r3, #0x69
	bl NewMsgDataFromNarc
	str r0, [sp, #0x24]
	mov r0, #0xb
	mov r1, #0x69
	bl String_New
	add r5, r0, #0
	mov r0, #0
	lsl r2, r4, #0x18
	lsr r3, r2, #8
	lsl r2, r6, #0x18
	lsr r2, r2, #0x10
	str r0, [sp, #0x28]
	str r0, [sp, #0x20]
	mov r0, #0x10
	add r1, sp, #0x30
	str r0, [sp, #0x14]
	ldrb r0, [r1, #0x10]
	orr r2, r3
	orr r0, r2
	str r0, [sp, #0x1c]
	ldrb r0, [r1, #0x14]
	str r0, [sp, #0x18]
_0223F08C:
	mov r4, #0
	mov r6, #1
_0223F090:
	ldr r0, [sp, #0x20]
	add r7, r4, r0
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	bl ov80_02237920
	cmp r0, #0xfe
	beq _0223F0D4
	add r0, r5, #0
	bl String_SetEmpty
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	bl ov80_02237920
	add r1, r0, #0
	ldr r0, [sp, #0x24]
	add r2, r5, #0
	bl ReadMsgDataIntoString
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x1c]
	add r2, r5, #0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r3, r6, #0
	bl AddTextPrinterParameterizedWithColor
_0223F0D4:
	add r4, r4, #1
	add r6, #0x40
	cmp r4, #4
	blt _0223F090
	ldr r0, [sp, #0x20]
	add r0, r0, #4
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x14]
	add r0, #0x24
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x28]
	add r0, r0, #1
	str r0, [sp, #0x28]
	cmp r0, #5
	blt _0223F08C
	add r0, r5, #0
	bl String_Delete
	ldr r0, [sp, #0x24]
	bl DestroyMsgData
	ldr r0, [sp, #0x10]
	bl CopyWindowToVram
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0223F108: .word 0x000002DF
	thumb_func_end ov82_0223F040
