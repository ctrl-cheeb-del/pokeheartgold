	.include "asm/macros.inc"
	.include "overlay_95.inc"
	.include "global.inc"
	.public HatchEggApp_Exit
	.public HatchEggApp_Init
	.public HatchEggApp_Main
	.public ov95_021E5954
	.public ov95_021E5974
	.public ov95_021E59F8
	.public ov95_021E5A38
	.public ov95_021E5BBC
	.public ov95_021E5C44
	.public ov95_021E5CAC
	.public ov95_021E5D44
	.public ov95_021E5D98
	.public ov95_021E5DB4
	.public ov95_021E5DD0
	.public ov95_021E5E18
	.public ov95_021E5E90
	.public ov95_021E5EC0
	.public ov95_021E5EF8
	.public ov95_021E6000
	.public ov95_021E60A4
	.public ov95_021E619C
	.public ov95_021E623C
	.public ov95_021E62A4
	.public ov95_021E6314
	.public ov95_021E65A0
	.public ov95_021E6838
	.public ov95_021E68A8
	.public ov95_021E6900
	.public ov95_021E6964
	.public ov95_021E6B74
	.public ov95_021E7020
	.public ov95_021E70BC
	.public ov95_021E7258
	.public ov95_021E7308
	.public ov95_021E7328
	.public ov95_021E7388
	.public ov95_021E7410
	.public ov95_021E7450
	.public ov95_021E7538
	.public ov95_021E7548
	.public ov95_021E755C
	.public ov95_021E7574
	.public ov95_021E7594
	.public ov95_021E75B4
	.public ov95_021E75DC
	.public ov95_021E762C
	.public ov95_021E767C
	.public ov95_021E76D0
	.public ov95_021E7770
	.public ov95_021E7810
	.public ov95_021E7818
	.public ov95_021E7820
	.public ov95_021E782C
	.public ov95_021E7860


	.text
	.public ov95_021E5900
	.public ov95_021E5928
	.public ov95_021E5B24
	.public ov95_021E5B58
	.public ov95_021E5B7C
	.public ov95_021E5B9C
	.public ov95_021E5D34
	.public ov95_021E5E40
	.public ov95_021E5E58
	.public ov95_021E5EDC
	.public ov95_021E5EF0
	.public ov95_021E6150
	.public ov95_021E6184
	.public ov95_021E6228
	.public ov95_021E62E4
	.public ov95_021E62F0
	.public ov95_021E6300
	.public ov95_021E67F0
	.public ov95_021E6FC4
	.public ov95_021E7078
	.public ov95_021E7208
	.public ov95_021E72B8
	.public ov95_021E7404
	.public ov95_021E7514

	thumb_func_start ov95_021E5BBC
ov95_021E5BBC: ; 0x021E5BBC
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r6, r2, #0
	add r4, r1, #0
	lsl r1, r6, #0x18
	lsr r1, r1, #0x18
	str r1, [sp]
	mov r1, #0x46
	str r1, [sp, #4]
	mov r1, #1
	mov r2, #0x14
	mov r3, #0xf
	add r5, r0, #0
	bl LoadUserFrameGfx2
	add r0, r6, #0
	bl sub_0200E640
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xc0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x26
	mov r3, #0x46
	bl PaletteData_LoadNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #0x46
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #1
	mov r2, #0x32
	mov r3, #0xd
	bl LoadUserFrameGfx1
	bl sub_0200E3D8
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xd0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x26
	mov r3, #0x46
	bl PaletteData_LoadNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xe0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x10
	mov r2, #8
	mov r3, #0x46
	bl PaletteData_LoadNarc
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	thumb_func_end ov95_021E5BBC


	thumb_func_start ov95_021E5C44
ov95_021E5C44: ; 0x021E5C44
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r1, #0
	add r7, r0, #0
	add r0, r5, #0
	add r4, r2, #0
	add r6, r3, #0
	bl InitWindow
	ldr r0, [sp, #0x28]
	lsl r2, r4, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	lsl r3, r6, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [sp, #0x30]
	add r1, r5, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	ldr r0, [sp, #0x38]
	lsr r2, r2, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x34]
	lsr r3, r3, #0x18
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	add r0, r7, #0
	bl AddWindowParameterized
	add r0, r5, #0
	mov r1, #1
	mov r2, #0x14
	mov r3, #0xc
	bl DrawFrameAndWindow2
	add r0, r5, #0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	add r0, r5, #0
	bl CopyWindowToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov95_021E5C44


	thumb_func_start ov95_021E5CAC
ov95_021E5CAC: ; 0x021E5CAC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r1, #0
	mov r1, #0xf
	str r0, [sp, #0xc]
	str r2, [sp, #0x10]
	add r6, r3, #0
	bl FillWindowPixelBuffer
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xbb
	mov r3, #0x46
	bl NewMsgDataFromNarc
	add r7, r0, #0
	mov r0, #0x46
	bl MessageFormat_New
	add r5, r0, #0
	add r0, r7, #0
	add r1, r4, #0
	bl NewString_ReadMsgData
	str r0, [sp, #0x14]
	mov r0, #0xff
	mov r1, #0x46
	bl String_New
	add r4, r0, #0
	ldr r0, [sp, #0x10]
	bl Mon_GetBoxMon
	add r2, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl BufferBoxMonSpeciesName
	ldr r2, [sp, #0x14]
	add r0, r5, #0
	add r1, r4, #0
	bl StringExpandPlaceholders
	mov r3, #0
	str r3, [sp]
	str r6, [sp, #4]
	ldr r0, [sp, #0xc]
	mov r1, #1
	add r2, r4, #0
	str r3, [sp, #8]
	bl AddTextPrinterParameterized
	add r6, r0, #0
	add r0, r7, #0
	bl DestroyMsgData
	add r0, r4, #0
	bl String_Delete
	ldr r0, [sp, #0x14]
	bl String_Delete
	add r0, r5, #0
	bl MessageFormat_Delete
	add r0, r6, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov95_021E5CAC
