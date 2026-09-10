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

	thumb_func_start ov75_02247A98
ov75_02247A98: ; 0x02247A98
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #1
	bne _02247AAE
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_02247AAE:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #3
	bhi _02247B8E
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02247AC4: ; jump table
	.short _02247ACC - _02247AC4 - 2 ; case 0
	.short _02247AEA - _02247AC4 - 2 ; case 1
	.short _02247B0A - _02247AC4 - 2 ; case 2
	.short _02247B84 - _02247AC4 - 2 ; case 3
_02247ACC:
	ldr r0, _02247B94 ; =0x00000F0F
	mov r2, #0x19
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
	b _02247B8E
_02247AEA:
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
	b _02247B8E
_02247B0A:
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	bne _02247B4C
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	ldr r0, _02247B94 ; =0x00000F0F
	mov r2, #0x1a
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #1
	bl ov75_022494CC
	ldr r0, [r4]
	mov r1, #0
	ldr r0, [r0, #4]
	mov r2, #1
	bl sub_02031780
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02247B8E
_02247B4C:
	cmp r0, #2
	bne _02247B8E
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	ldr r0, _02247B94 ; =0x00000F0F
	mov r2, #0x1b
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #1
	bl ov75_022494CC
	ldr r0, [r4]
	mov r1, #0
	ldr r0, [r0, #4]
	add r2, r1, #0
	bl sub_02031780
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02247B8E
_02247B84:
	add r0, r4, #0
	mov r1, #0x19
	mov r2, #0
	bl ov75_02247854
_02247B8E:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02247B94: .word 0x00000F0F
	thumb_func_end ov75_02247A98


	thumb_func_start ov75_02247B98
ov75_02247B98: ; 0x02247B98
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #1
	bne _02247BAE
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_02247BAE:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #3
	bhi _02247C66
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02247BC4: ; jump table
	.short _02247BCC - _02247BC4 - 2 ; case 0
	.short _02247BEA - _02247BC4 - 2 ; case 1
	.short _02247C0A - _02247BC4 - 2 ; case 2
	.short _02247C5C - _02247BC4 - 2 ; case 3
_02247BCC:
	ldr r0, _02247C6C ; =0x00000F0F
	mov r2, #0x1c
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
	b _02247C66
_02247BEA:
	mov r1, #0x8d
	ldr r0, [r4, #4]
	lsl r1, r1, #2
	mov r2, #1
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
	b _02247C66
_02247C0A:
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	bne _02247C48
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	ldr r0, _02247C6C ; =0x00000F0F
	mov r2, #0x1d
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #1
	bl ov75_022494CC
	ldr r0, [r4]
	ldr r0, [r0, #4]
	bl sub_02031734
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02247C66
_02247C48:
	cmp r0, #2
	bne _02247C66
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	mov r0, #0
	str r0, [r4, #8]
	b _02247C66
_02247C5C:
	add r0, r4, #0
	mov r1, #0x19
	mov r2, #0
	bl ov75_02247854
_02247C66:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02247C6C: .word 0x00000F0F
	thumb_func_end ov75_02247B98


	thumb_func_start ov75_02247C70
ov75_02247C70: ; 0x02247C70
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r0, #0
	add r0, #0xd4
	mov r1, #0xf
	bl FillWindowPixelBuffer
	ldr r0, [r4, #0x34]
	mov r1, #0x2a
	bl NewString_ReadMsgData
	add r5, r0, #0
	ldr r3, _02247D00 ; =_02249B20
	mov r1, #0
	ldr r0, [r3, #4]
	add r2, r5, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r3, [r3]
	add r0, r4, #0
	add r0, #0xd4
	add r3, #0xc
	bl AddTextPrinterParameterized
	add r0, r5, #0
	bl String_Delete
	ldr r0, [r4, #0x34]
	mov r1, #0x2b
	bl NewString_ReadMsgData
	add r5, r0, #0
	ldr r3, _02247D00 ; =_02249B20
	mov r1, #0
	ldr r0, [r3, #0xc]
	add r2, r5, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r3, [r3, #8]
	add r0, r4, #0
	add r0, #0xd4
	add r3, #0xc
	bl AddTextPrinterParameterized
	add r0, r5, #0
	bl String_Delete
	add r0, r4, #0
	add r0, #0xb0
	ldr r0, [r0]
	add r1, r4, #0
	lsl r3, r0, #3
	add r0, r4, #0
	ldr r2, _02247D04 ; =_02249B20
	add r0, #0xe4
	ldr r5, _02247D08 ; =ov75_02249B24
	ldr r2, [r2, r3]
	ldr r0, [r0]
	ldr r3, [r5, r3]
	add r1, #0xd4
	bl ListMenuUpdateCursorObj
	add r4, #0xd4
	add r0, r4, #0
	bl CopyWindowToVram
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_02247D00: .word _02249B20
_02247D04: .word _02249B20
_02247D08: .word ov75_02249B24
	thumb_func_end ov75_02247C70
