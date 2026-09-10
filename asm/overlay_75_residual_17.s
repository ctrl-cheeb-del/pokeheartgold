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

	thumb_func_start ov75_022494CC
ov75_022494CC: ; 0x022494CC
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r0, r1, #0
	add r1, r2, #0
	add r4, r3, #0
	bl NewString_ReadMsgData
	add r6, r0, #0
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x38]
	add r2, r6, #0
	bl StringExpandPlaceholders
	add r0, r6, #0
	bl String_Delete
	add r0, r5, #0
	add r0, #0x48
	mov r1, #0xf
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #0x48
	mov r1, #0
	mov r2, #1
	mov r3, #0xa
	bl DrawFrameAndWindow2
	mov r3, #0
	str r3, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	add r0, r5, #0
	ldr r2, [r5, #0x38]
	add r0, #0x48
	mov r1, #1
	bl AddTextPrinterParameterized
	str r0, [r5, #0x44]
	add r0, r5, #0
	mov r1, #0
	add r0, #0x90
	str r1, [r0]
	cmp r4, #0xff
	beq _0224952C
	cmp r4, #0
	bne _02249530
_0224952C:
	mov r0, #0xff
	str r0, [r5, #0x44]
_02249530:
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	thumb_func_end ov75_022494CC


	thumb_func_start ov75_02249534
ov75_02249534: ; 0x02249534
	push {r3, lr}
	cmp r0, #0xff
	beq _02249546
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _0224954A
_02249546:
	mov r0, #0
	pop {r3, pc}
_0224954A:
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov75_02249534


	thumb_func_start ov75_02249550
ov75_02249550: ; 0x02249550
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #1
	bne _02249566
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_02249566:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	beq _02249576
	cmp r0, #1
	beq _022495A2
	b _022495A6
_02249576:
	ldr r0, [r4]
	bl ov75_02246CF8
	cmp r0, #2
	bne _02249584
	mov r2, #0x26
	b _02249586
_02249584:
	mov r2, #0x27
_02249586:
	ldr r0, _022495AC ; =0x00000F0F
	mov r3, #1
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	bl ov75_022494CC
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _022495A6
_022495A2:
	mov r0, #5
	str r0, [r4, #8]
_022495A6:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_022495AC: .word 0x00000F0F
	thumb_func_end ov75_02249550


	thumb_func_start ov75_022495B0
ov75_022495B0: ; 0x022495B0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r6, r0, #0
	ldr r0, [r6, #0x44]
	ldr r4, [r6]
	bl ov75_02249534
	cmp r0, #1
	bne _022495C8
	add sp, #0x18
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_022495C8:
	add r0, r6, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	beq _022495D8
	cmp r0, #1
	beq _0224963C
	b _02249640
_022495D8:
	add r0, r4, #0
	bl ov75_02246CE8
	add r5, r0, #0
	ldr r0, [r4, #4]
	mov r1, #3
	bl sub_020317BC
	cmp r5, r0
	bne _0224961E
	ldr r0, [r4, #4]
	bl sub_02031774
	add r1, sp, #8
	mov r2, #0x73
	bl ov75_02249884
	mov r4, #0
	add r5, sp, #8
	mov r7, #2
_02249600:
	str r7, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x20]
	ldr r2, [r5]
	add r1, r4, #0
	mov r3, #4
	bl BufferIntegerAsString
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blo _02249600
	mov r2, #0x29
	b _02249620
_0224961E:
	mov r2, #0x28
_02249620:
	ldr r0, _02249648 ; =0x00000F0F
	mov r3, #1
	str r0, [sp]
	ldr r1, [r6, #0x34]
	add r0, r6, #0
	bl ov75_022494CC
	add r0, r6, #0
	add r0, #0x94
	ldr r0, [r0]
	add r6, #0x94
	add r0, r0, #1
	str r0, [r6]
	b _02249640
_0224963C:
	mov r0, #0
	str r0, [r6, #8]
_02249640:
	mov r0, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02249648: .word 0x00000F0F
	thumb_func_end ov75_022495B0


	thumb_func_start ov75_0224964C
ov75_0224964C: ; 0x0224964C
	push {r4, lr}
	add r4, r0, #0
	cmp r3, #1
	beq _0224965A
	cmp r3, #2
	beq _02249670
	b _0224967E
_0224965A:
	ldr r0, [sp, #0xc]
	mov r2, #0
	bl FontID_String_GetWidth
	ldrb r1, [r4, #7]
	lsl r1, r1, #3
	sub r1, r1, r0
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r2, r0, #1
	b _0224967E
_02249670:
	ldr r0, [sp, #0xc]
	mov r2, #0
	bl FontID_String_GetWidth
	ldrb r1, [r4, #7]
	lsl r1, r1, #3
	sub r2, r1, r0
_0224967E:
	add r0, r2, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov75_0224964C


	thumb_func_start ov75_02249684
ov75_02249684: ; 0x02249684
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r4, r3, #0
	ldr r3, [sp, #0x24]
	add r5, r0, #0
	str r3, [sp]
	mov r3, #1
	str r3, [sp, #4]
	ldr r3, [sp, #0x20]
	add r6, r1, #0
	bl ov75_0224964C
	add r3, r0, #0
	str r4, [sp]
	mov r1, #0
	ldr r0, [sp, #0x24]
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r5, #0
	mov r1, #1
	add r2, r6, #0
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x10
	pop {r4, r5, r6, pc}
	thumb_func_end ov75_02249684


	thumb_func_start ov75_022496B8
ov75_022496B8: ; 0x022496B8
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #1
	add r6, r1, #0
	lsl r0, r0, #8
	mov r1, #0x74
	bl String_New
	add r4, r0, #0
	ldr r0, [r5, #0x30]
	add r1, r6, #0
	add r2, r4, #0
	bl ReadMsgDataIntoString
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x40]
	add r2, r4, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	add r0, #0x68
	mov r1, #0xf
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #0x68
	mov r1, #1
	mov r2, #0x1f
	mov r3, #0xb
	bl DrawFrameAndWindow1
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	add r0, r5, #0
	ldr r2, [r5, #0x40]
	add r0, #0x68
	mov r1, #1
	bl AddTextPrinterParameterized
	mov r0, #0xff
	str r0, [r5, #0x44]
	add r0, r4, #0
	bl String_Delete
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov75_022496B8


	thumb_func_start ov75_0224971C
ov75_0224971C: ; 0x0224971C
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r0, #0
	mov r0, #0
	add r4, r1, #0
	mvn r0, r0
	cmp r4, r0
	bne _0224972E
	mov r4, #0xb
_0224972E:
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r5, #0x20]
	mov r1, #0
	mov r3, #5
	bl BufferIntegerAsString
	add r0, r5, #0
	add r0, #0x48
	mov r1, #1
	bl ClearFrameAndWindow2
	add r0, r5, #0
	add r1, r4, #0
	bl ov75_022496B8
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov75_0224971C
