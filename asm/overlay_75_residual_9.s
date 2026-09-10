	.include "asm/macros.inc"
	.include "overlay_75.inc"
	.include "global.inc"
	.public gApplication_TitleScreen

	.text
	.public _02249B20
	.public _02249BE0
	.public ov75_02246960
	.public ov75_022469D8
	.public ov75_02246B00
	.public ov75_02246B48
	.public ov75_02246B98
	.public ov75_02246C3C
	.public ov75_02246D08
	.public ov75_02246D40
	.public ov75_02246DB4
	.public ov75_02246DFC
	.public ov75_02246E3C
	.public ov75_02246E78
	.public ov75_02246F0C
	.public ov75_02247118
	.public ov75_02247180
	.public ov75_0224725C
	.public ov75_02247450
	.public ov75_022476E8
	.public ov75_02247790
	.public ov75_02247890
	.public ov75_022478E0
	.public ov75_02247A98
	.public ov75_02247B98
	.public ov75_02247C70
	.public ov75_02247D24
	.public ov75_02248034
	.public ov75_022480B8
	.public ov75_022483EC
	.public ov75_02248584
	.public ov75_02248684
	.public ov75_022486EC
	.public ov75_0224874C
	.public ov75_02248774
	.public ov75_02248800
	.public ov75_022488BC
	.public ov75_02248994
	.public ov75_02248A20
	.public ov75_02248B8C
	.public ov75_02248C84
	.public ov75_02248D2C
	.public ov75_02248F18
	.public ov75_02248F7C
	.public ov75_02248FE8
	.public ov75_022490D8
	.public ov75_022491CC
	.public ov75_022491F0
	.public ov75_02249278
	.public ov75_0224937C
	.public ov75_02249478
	.public ov75_022494CC
	.public ov75_02249534
	.public ov75_02249550
	.public ov75_022495B0
	.public ov75_0224964C
	.public ov75_02249684
	.public ov75_022496B8
	.public ov75_0224971C
	.public ov75_02249780
	.public ov75_02249838
	.public ov75_02249884
	.public ov75_022498E4
	.public ov75_022498F4
	.public ov75_02249904
	.public ov75_02249974
	.public ov75_02249978
	.public ov75_0224997C
	.public ov75_0224998C
	.public ov75_0224999C
	.public ov75_022499BC
	.public ov75_022499DC
	.public ov75_022499FC
	.public ov75_02249A24
	.public ov75_02249A5C
	.public ov75_02249ACC
	.public ov75_02249AD0
	.public ov75_02249ADC
	.public ov75_02249B24
	.public ov75_02249B30
	.public ov75_App_MainMenu_SelectOption_WiiMessageSettings
	.public ov75_02246BCC
	.public ov75_02246BD8
	.public ov75_02246BE0
	.public ov75_02246BE8
	.public ov75_02246BF0
	.public ov75_02246C18
	.public ov75_02246C68
	.public ov75_02246C8C
	.public ov75_02246CA0
	.public ov75_02246CB8
	.public ov75_02246CCC
	.public ov75_02246CD8
	.public ov75_02246CE0
	.public ov75_02246CE8
	.public ov75_02246CF0
	.public ov75_02246CF8
	.public ov75_02246D00
	.public ov75_02246D04
	.public ov75_02246EAC
	.public ov75_02246EDC
	.public ov75_02247234
	.public ov75_0224741C
	.public ov75_02247838
	.public ov75_02247854
	.public ov75_0224785C
	.public ov75_02247878
	.public ov75_02247A78
	.public ov75_02247D0C
	.public ov75_0224852C
	.public ov75_0224854C
	.public ov75_02248714
	.public ov75_022488AC
	.public ov75_022489F8
	.public ov75_02248C64
	.public ov75_0224921C
	.public ov75_02249258
	.public ov75_02249460
	.public ov75_022494A4
	.public ov75_02249758
	.public ov75_0224976C

	thumb_func_start ov75_02247D24
ov75_02247D24: ; 0x02247D24
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r0, #0
	add r0, #0xbc
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xbc
	str r1, [r0]
	add r0, r4, #0
	add r0, #0xbc
	ldr r0, [r0]
	cmp r0, #8
	beq _02247D42
	b _02248030
_02247D42:
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #1
	add r2, r0, #0
	add r0, r4, #0
	eor r2, r1
	add r0, #0xc0
	str r2, [r0]
	add r0, r4, #0
	mov r2, #0
	add r0, #0xbc
	str r2, [r0]
	add r0, r4, #0
	add r0, #0xac
	ldr r0, [r0]
	add r3, r0, #6
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r3, r0
	bne _02247D70
	b _02247EAE
_02247D70:
	mov r0, #0x11
	str r0, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #1
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xe
	bl FillBgTilemapRect
	mov r0, #0x11
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #2
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xf
	bl FillBgTilemapRect
	mov r0, #0x11
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #3
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0x10
	bl FillBgTilemapRect
	mov r3, #0x11
	add r2, r4, #0
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r5, [r2]
	mov r2, #0x14
	mul r2, r5
	add r2, r2, #4
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	bl FillBgTilemapRect
	mov r0, #0x12
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0xb
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xe
	bl FillBgTilemapRect
	mov r0, #0x12
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0xc
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xf
	bl FillBgTilemapRect
	mov r0, #0x12
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0xd
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0x10
	bl FillBgTilemapRect
	mov r0, #0x12
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0xe
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0x11
	bl FillBgTilemapRect
	b _02247EC8
_02247EAE:
	mov r0, #0x11
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	mov r1, #3
	mov r3, #0xe
	bl FillBgTilemapRect
_02247EC8:
	add r0, r4, #0
	add r0, #0xac
	ldr r0, [r0]
	cmp r0, #0
	bne _02247ED4
	b _0224800E
_02247ED4:
	mov r1, #3
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #5
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	lsr r2, r2, #0x10
	mov r3, #0xe
	bl FillBgTilemapRect
	mov r1, #3
	add r2, r4, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #6
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	lsr r2, r2, #0x10
	mov r3, #0xf
	bl FillBgTilemapRect
	mov r1, #3
	add r2, r4, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #7
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	lsr r2, r2, #0x10
	mov r3, #0x10
	bl FillBgTilemapRect
	mov r1, #3
	add r2, r4, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #8
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	lsr r2, r2, #0x10
	mov r3, #0x11
	bl FillBgTilemapRect
	mov r0, #4
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0xf
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xe
	bl FillBgTilemapRect
	mov r0, #4
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xf
	bl FillBgTilemapRect
	mov r0, #4
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0x11
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0x10
	bl FillBgTilemapRect
	mov r0, #4
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0x12
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0x11
	bl FillBgTilemapRect
	b _02248028
_0224800E:
	mov r1, #3
	str r1, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	mov r2, #0
	mov r3, #0xe
	bl FillBgTilemapRect
_02248028:
	ldr r0, [r4, #4]
	mov r1, #3
	bl ScheduleBgTilemapBufferTransfer
_02248030:
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end ov75_02247D24


	thumb_func_start ov75_02248034
ov75_02248034: ; 0x02248034
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r7, r0, #0
	add r0, #0xc4
	mov r1, #0xf
	bl FillWindowPixelBuffer
	ldr r0, [r7, #0x34]
	mov r1, #0x2c
	bl NewString_ReadMsgData
	str r0, [sp, #0xc]
	bl String_GetLength
	mov r1, #0x74
	bl String_New
	add r6, r0, #0
	add r0, r7, #0
	add r0, #0xac
	ldr r4, [r0]
	add r0, r4, #6
	cmp r4, r0
	bge _0224809E
	add r0, r7, #0
	str r0, [sp, #0x10]
	add r0, #0xc4
	mov r5, #0
	str r0, [sp, #0x10]
_0224806E:
	ldr r1, [sp, #0xc]
	add r0, r6, #0
	add r2, r4, #0
	bl String_GetLineN
	str r5, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x10]
	mov r1, #0
	add r2, r6, #0
	mov r3, #4
	bl AddTextPrinterParameterized
	add r0, r7, #0
	add r0, #0xac
	ldr r0, [r0]
	add r4, r4, #1
	add r0, r0, #6
	add r5, #0x10
	cmp r4, r0
	blt _0224806E
_0224809E:
	ldr r0, [sp, #0xc]
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add r7, #0xc4
	add r0, r7, #0
	bl CopyWindowToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov75_02248034


	thumb_func_start ov75_022480B8
ov75_022480B8: ; 0x022480B8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	add r1, r5, #0
	add r1, #0xa8
	ldr r1, [r1]
	cmp r1, #0
	beq _022480D6
	cmp r1, #1
	bne _022480CE
	b _02248220
_022480CE:
	cmp r1, #2
	bne _022480D4
	b _022482CE
_022480D4:
	b _0224837C
_022480D6:
	ldr r0, [r5, #0x34]
	mov r1, #0x2c
	bl NewString_ReadMsgData
	str r0, [sp, #0x14]
	bl String_CountLines
	add r1, r5, #0
	mov r2, #0
	add r1, #0xac
	str r2, [r1]
	add r1, r5, #0
	add r1, #0xb0
	str r2, [r1]
	add r1, r5, #0
	add r1, #0xb8
	str r2, [r1]
	add r1, r5, #0
	add r1, #0xb4
	str r0, [r1]
	mov r0, #5
	str r0, [sp]
	mov r0, #0x1e
	str r0, [sp, #4]
	mov r0, #0xc
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x94
	str r0, [sp, #0x10]
	add r1, r5, #0
	ldr r0, [r5, #4]
	add r1, #0xc4
	mov r2, #2
	mov r3, #1
	bl AddWindowParameterized
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1e
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x7f
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	add r1, r5, #0
	ldr r0, [r5, #4]
	add r1, #0xd4
	mov r2, #2
	mov r3, #1
	bl AddWindowParameterized
	add r0, r5, #0
	add r0, #0xc4
	mov r1, #0xf
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x14]
	bl String_GetLength
	mov r1, #0x74
	bl String_New
	add r7, r0, #0
	add r0, r5, #0
	mov r6, #0
	str r0, [sp, #0x18]
	add r0, #0xc4
	add r4, r6, #0
	str r0, [sp, #0x18]
_02248168:
	ldr r1, [sp, #0x14]
	add r0, r7, #0
	add r2, r6, #0
	bl String_GetLineN
	str r4, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x18]
	mov r1, #0
	add r2, r7, #0
	mov r3, #4
	bl AddTextPrinterParameterized
	add r6, r6, #1
	add r4, #0x10
	cmp r6, #6
	blt _02248168
	ldr r0, [sp, #0x14]
	bl String_Delete
	add r0, r7, #0
	bl String_Delete
	add r0, r5, #0
	add r0, #0xc4
	mov r1, #1
	mov r2, #0x1f
	mov r3, #0xb
	bl DrawFrameAndWindow1
	add r0, r5, #0
	add r0, #0xc4
	bl CopyWindowToVram
	add r0, r5, #0
	add r0, #0xd4
	mov r1, #0xf
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #0xd4
	mov r1, #1
	mov r2, #0x1f
	mov r3, #0xb
	bl DrawFrameAndWindow1
	add r0, r5, #0
	add r0, #0xd4
	bl CopyWindowToVram
	mov r0, #0x74
	bl ListMenuCursorNew
	add r1, r5, #0
	add r1, #0xe4
	str r0, [r1]
	add r0, r5, #0
	add r0, #0x48
	mov r1, #0xf
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #0x48
	mov r1, #1
	bl ClearFrameAndWindow2
	add r0, r5, #0
	add r0, #0x48
	bl ClearWindowTilemapAndCopyToVram
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add r0, r5, #0
	mov r1, #0
	add r0, #0xbc
	str r1, [r0]
	add r0, r5, #0
	add r0, #0xc0
	str r1, [r0]
	add r0, r5, #0
	add r0, #0xa8
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r5, #0
	add r0, #0xa8
	str r1, [r0]
	b _022483D8
_02248220:
	ldr r1, _022483E4 ; =gSystem
	add r0, #0xac
	ldr r2, [r1, #0x4c]
	ldr r4, [r0]
	mov r0, #0x40
	tst r0, r2
	beq _02248248
	cmp r4, #0
	beq _022482BA
	add r0, r5, #0
	add r0, #0xac
	ldr r0, [r0]
	sub r1, r0, #1
	add r0, r5, #0
	add r0, #0xac
	str r1, [r0]
	ldr r0, _022483E8 ; =0x000005DC
	bl PlaySE
	b _022482BA
_02248248:
	mov r0, #0x80
	tst r0, r2
	beq _0224829C
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r1, r4, #6
	cmp r1, r0
	bge _0224826E
	add r0, r5, #0
	add r0, #0xac
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r5, #0
	add r0, #0xac
	str r1, [r0]
	ldr r0, _022483E8 ; =0x000005DC
	bl PlaySE
_0224826E:
	add r0, r5, #0
	add r0, #0xac
	ldr r0, [r0]
	add r1, r0, #6
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r1, r0
	bne _022482BA
	add r0, r5, #0
	bl ov75_02247C70
	add r0, r5, #0
	add r0, #0xa8
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r5, #0
	add r0, #0xa8
	str r1, [r0]
	ldr r0, _022483E8 ; =0x000005DC
	bl PlaySE
	b _022482BA
_0224829C:
	ldr r1, [r1, #0x48]
	mov r0, #2
	tst r0, r1
	beq _022482BA
	ldr r0, _022483E8 ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	mov r1, #2
	add r0, #0xb8
	str r1, [r0]
	add r0, r5, #0
	mov r1, #0xff
	add r0, #0xa8
	str r1, [r0]
_022482BA:
	add r0, r5, #0
	add r0, #0xac
	ldr r0, [r0]
	cmp r4, r0
	bne _022482C6
	b _022483D8
_022482C6:
	add r0, r5, #0
	bl ov75_02248034
	b _022483D8
_022482CE:
	ldr r1, _022483E4 ; =gSystem
	mov r2, #0x10
	ldr r1, [r1, #0x48]
	tst r2, r1
	bne _022482DE
	mov r2, #0x20
	tst r2, r1
	beq _022482FC
_022482DE:
	add r0, r5, #0
	add r0, #0xb0
	ldr r1, [r0]
	mov r0, #1
	eor r1, r0
	add r0, r5, #0
	add r0, #0xb0
	str r1, [r0]
	ldr r0, _022483E8 ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	bl ov75_02247C70
	b _022483D8
_022482FC:
	mov r2, #1
	tst r2, r1
	beq _02248326
	add r0, #0xb0
	ldr r1, [r0]
	mov r0, #2
	sub r1, r0, r1
	add r0, r5, #0
	add r0, #0xb8
	str r1, [r0]
	ldr r0, _022483E8 ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	add r0, #0xa8
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r5, #0
	add r0, #0xa8
	str r1, [r0]
	b _022483D8
_02248326:
	mov r2, #2
	add r3, r1, #0
	tst r3, r2
	beq _02248348
	add r0, #0xb8
	str r2, [r0]
	ldr r0, _022483E8 ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	add r0, #0xa8
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r5, #0
	add r0, #0xa8
	str r1, [r0]
	b _022483D8
_02248348:
	mov r2, #0x40
	tst r1, r2
	beq _022483D8
	bl ov75_02247D0C
	ldr r0, _022483E8 ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	add r0, #0xa8
	ldr r0, [r0]
	sub r1, r0, #1
	add r0, r5, #0
	add r0, #0xa8
	str r1, [r0]
	add r0, r5, #0
	add r0, #0xac
	ldr r0, [r0]
	sub r1, r0, #1
	add r0, r5, #0
	add r0, #0xac
	str r1, [r0]
	add r0, r5, #0
	bl ov75_02248034
	b _022483D8
_0224837C:
	add r0, #0xc4
	mov r1, #0
	bl sub_0200E5D4
	add r0, r5, #0
	add r0, #0xc4
	bl ClearWindowTilemapAndCopyToVram
	add r0, r5, #0
	add r0, #0xc4
	bl RemoveWindow
	add r0, r5, #0
	add r0, #0xd4
	mov r1, #0
	bl sub_0200E5D4
	add r0, r5, #0
	add r0, #0xd4
	bl ClearWindowTilemapAndCopyToVram
	add r0, r5, #0
	add r0, #0xd4
	bl RemoveWindow
	add r0, r5, #0
	add r0, #0xe4
	ldr r0, [r0]
	bl DestroyListMenuCursorObj
	ldr r0, [r5, #4]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	mov r0, #8
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add r0, r5, #0
	mov r1, #0
	add r0, #0xa8
	str r1, [r0]
	add r5, #0xb8
	add sp, #0x1c
	ldr r0, [r5]
	pop {r4, r5, r6, r7, pc}
_022483D8:
	add r0, r5, #0
	bl ov75_02247D24
	mov r0, #0
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022483E4: .word gSystem
_022483E8: .word 0x000005DC
	thumb_func_end ov75_022480B8


	thumb_func_start ov75_022483EC
ov75_022483EC: ; 0x022483EC
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #1
	bne _02248402
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_02248402:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #4
	bhi _022484DC
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02248418: ; jump table
	.short _02248422 - _02248418 - 2 ; case 0
	.short _0224842A - _02248418 - 2 ; case 1
	.short _02248438 - _02248418 - 2 ; case 2
	.short _02248484 - _02248418 - 2 ; case 3
	.short _022484BC - _02248418 - 2 ; case 4
_02248422:
	mov r0, #3
	add r4, #0x94
	str r0, [r4]
	b _02248522
_0224842A:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02248522
_02248438:
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	bne _02248468
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	ldr r0, _02248528 ; =0x00000F0F
	mov r2, #9
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #1
	bl ov75_022494CC
	mov r0, #4
	add r4, #0x94
	str r0, [r4]
	b _02248522
_02248468:
	cmp r0, #2
	bne _02248522
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02248522
_02248484:
	add r0, r4, #0
	bl ov75_022480B8
	cmp r0, #1
	bne _022484AC
	ldr r0, _02248528 ; =0x00000F0F
	mov r2, #9
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #1
	bl ov75_022494CC
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02248522
_022484AC:
	cmp r0, #2
	bne _02248522
	add r0, r4, #0
	mov r1, #0x22
	mov r2, #0
	bl ov75_02247854
	b _02248522
_022484BC:
	mov r1, #0x8d
	ldr r0, [r4, #4]
	lsl r1, r1, #2
	mov r2, #0
	bl ov75_02247890
	add r1, r4, #0
	add r1, #0x88
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02248522
_022484DC:
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	bne _022484FA
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	mov r0, #5
	str r0, [r4, #8]
	b _02248522
_022484FA:
	cmp r0, #2
	bne _02248522
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	ldr r0, _02248528 ; =0x00000F0F
	mov r2, #0xa
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #1
	bl ov75_022494CC
	add r0, r4, #0
	mov r1, #0x22
	mov r2, #0
	bl ov75_02247854
_02248522:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02248528: .word 0x00000F0F
	thumb_func_end ov75_022483EC
