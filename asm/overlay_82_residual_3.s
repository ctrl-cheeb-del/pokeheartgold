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

	thumb_func_start ov82_0223E9E8
ov82_0223E9E8: ; 0x0223E9E8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	mov r0, #0xb7
	mov r1, #0x69
	bl NARC_New
	mov r1, #0x22
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r5, #0
	bl ov82_0223EB3C
	add r0, r5, #0
	bl ov82_0223EB9C
	ldr r2, _0223EB2C ; =0x000001B9
	mov r0, #1
	mov r1, #0x1b
	mov r3, #0x69
	bl NewMsgDataFromNarc
	str r0, [r5, #0x20]
	mov r0, #0x69
	bl MessageFormat_New
	str r0, [r5, #0x24]
	mov r0, #0x96
	lsl r0, r0, #2
	mov r1, #0x69
	bl String_New
	str r0, [r5, #0x28]
	mov r0, #0x96
	lsl r0, r0, #2
	mov r1, #0x69
	bl String_New
	str r0, [r5, #0x2c]
	mov r6, #0
	add r4, r5, #0
	mov r7, #0x20
_0223EA3C:
	add r0, r7, #0
	mov r1, #0x69
	bl String_New
	str r0, [r4, #0x30]
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #2
	blt _0223EA3C
	mov r1, #0x1a
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #0x69
	bl LoadFontPal0
	mov r1, #6
	mov r0, #0
	lsl r1, r1, #6
	mov r2, #0x69
	bl LoadFontPal1
	mov r0, #4
	mov r1, #0x40
	mov r2, #0x69
	bl LoadFontPal0
	mov r0, #0xf
	mov r1, #0xe
	mov r2, #0
	mov r3, #0x69
	bl MessagePrinter_New
	add r1, r5, #0
	add r1, #0x98
	str r0, [r1]
	add r1, r5, #0
	ldr r0, [r5, #0x48]
	add r1, #0x4c
	bl ov82_0223FD2C
	ldr r1, [r5, #0x48]
	add r0, r5, #0
	bl ov82_0223F580
	ldr r2, _0223EB30 ; =0x04000304
	ldr r0, _0223EB34 ; =0xFFFF7FFF
	ldrh r1, [r2]
	and r0, r1
	strh r0, [r2]
	bl GfGfx_BothDispOn
	add r0, r5, #0
	bl ov82_0223F558
	add r4, r0, #0
	add r0, r5, #0
	bl ov82_0223F570
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0
	add r0, #0xa8
	mov r2, #1
	add r3, r4, #0
	str r1, [sp, #4]
	bl ov82_0223FC48
	mov r1, #0x81
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r3, #0xa0
	mov r1, #1
	str r3, [sp]
	mov r0, #0
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0xa8
	add r2, r1, #0
	bl ov82_0223FC48
	mov r1, #0x82
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r1, #0xc
	ldr r0, [r5, r1]
	mov r1, #0
	bl Party_GetMonByIndex
	add r1, r0, #0
	mov r0, #0x82
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl ov82_0223FD18
	bl sub_02037474
	cmp r0, #0
	beq _0223EB12
	mov r0, #1
	mov r1, #0x10
	bl G2dRenderer_SetObjCharTransferReservedRegion
	mov r0, #1
	bl G2dRenderer_SetPlttTransferReservedRegion
	bl sub_0203A880
_0223EB12:
	mov r0, #0x69
	bl ov82_0223FDB8
	add r1, r5, #0
	add r1, #0x8c
	str r0, [r1]
	ldr r0, _0223EB38 ; =ov82_0223EC0C
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0223EB2C: .word 0x000001B9
_0223EB30: .word 0x04000304
_0223EB34: .word 0xFFFF7FFF
_0223EB38: .word ov82_0223EC0C
	thumb_func_end ov82_0223E9E8


	thumb_func_start ov82_0223EB3C
ov82_0223EB3C: ; 0x0223EB3C
	push {r4, lr}
	add r4, r0, #0
	bl ov82_0223EC48
	ldr r0, [r4, #0x48]
	bl ov82_0223EC68
	add r0, r4, #0
	bl ov82_0223ED94
	mov r0, #0x69
	bl PaletteData_Init
	add r1, r4, #0
	add r1, #0x94
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x94
	mov r1, #2
	ldr r0, [r0]
	lsl r2, r1, #8
	mov r3, #0x69
	bl PaletteData_AllocBuffers
	add r0, r4, #0
	add r0, #0x94
	mov r2, #2
	ldr r0, [r0]
	mov r1, #0
	lsl r2, r2, #8
	mov r3, #0x69
	bl PaletteData_AllocBuffers
	add r0, r4, #0
	mov r1, #3
	bl ov82_0223EDF0
	bl ov82_0223EE38
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add r0, r4, #0
	mov r1, #5
	bl ov82_0223EE6C
	pop {r4, pc}
	thumb_func_end ov82_0223EB3C
