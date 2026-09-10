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

	thumb_func_start ov75_02248A20
ov75_02248A20: ; 0x02248A20
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bl ov70_02237F38
	cmp r0, #0
	bne _02248A2E
	b _02248B56
_02248A2E:
	bl ov70_02237F58
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #0
	add r0, #0xe8
	str r1, [r0]
	add r0, r5, #0
	add r0, #0xf
	cmp r0, #0x11
	bls _02248A46
	b _02248B4A
_02248A46:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02248A52: ; jump table
	.short _02248B2E - _02248A52 - 2 ; case 0
	.short _02248B3C - _02248A52 - 2 ; case 1
	.short _02248B4A - _02248A52 - 2 ; case 2
	.short _02248B2E - _02248A52 - 2 ; case 3
	.short _02248B4A - _02248A52 - 2 ; case 4
	.short _02248B4A - _02248A52 - 2 ; case 5
	.short _02248B4A - _02248A52 - 2 ; case 6
	.short _02248B4A - _02248A52 - 2 ; case 7
	.short _02248B4A - _02248A52 - 2 ; case 8
	.short _02248B4A - _02248A52 - 2 ; case 9
	.short _02248B4A - _02248A52 - 2 ; case 10
	.short _02248B4A - _02248A52 - 2 ; case 11
	.short _02248B4A - _02248A52 - 2 ; case 12
	.short _02248B3C - _02248A52 - 2 ; case 13
	.short _02248B20 - _02248A52 - 2 ; case 14
	.short _02248A76 - _02248A52 - 2 ; case 15
	.short _02248B12 - _02248A52 - 2 ; case 16
	.short _02248B20 - _02248A52 - 2 ; case 17
_02248A76:
	ldr r1, [r4]
	add r0, r1, #0
	add r0, #0xfc
	ldr r0, [r0]
	cmp r0, #0
	beq _02248A8C
	cmp r0, #1
	beq _02248AE6
	cmp r0, #2
	beq _02248AF6
	b _02248B06
_02248A8C:
	mov r0, #1
	lsl r0, r0, #8
	ldr r0, [r1, r0]
	cmp r0, #3
	bhi _02248AE0
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02248AA2: ; jump table
	.short _02248AC0 - _02248AA2 - 2 ; case 0
	.short _02248AAA - _02248AA2 - 2 ; case 1
	.short _02248AB0 - _02248AA2 - 2 ; case 2
	.short _02248AD0 - _02248AA2 - 2 ; case 3
_02248AAA:
	mov r0, #0x13
	str r0, [r4, #8]
	b _02248B74
_02248AB0:
	add r0, r4, #0
	bl ov75_02247878
	ldr r0, _02248B78 ; =0xFFFFEC77
	str r0, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248B74
_02248AC0:
	add r0, r4, #0
	bl ov75_02247878
	ldr r0, _02248B7C ; =0xFFFFEC76
	str r0, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248B74
_02248AD0:
	add r0, r4, #0
	bl ov75_02247878
	ldr r0, _02248B80 ; =0xFFFFEC75
	str r0, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248B74
_02248AE0:
	bl sub_020399EC
	b _02248B74
_02248AE6:
	add r0, r4, #0
	bl ov75_02247878
	ldr r0, _02248B84 ; =0xFFFFEC74
	str r0, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248B74
_02248AF6:
	add r0, r4, #0
	bl ov75_02247878
	ldr r0, _02248B88 ; =0xFFFFEC73
	str r0, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248B74
_02248B06:
	add r0, r4, #0
	bl ov75_02247878
	bl sub_020399EC
	b _02248B74
_02248B12:
	add r0, r4, #0
	bl ov75_02247878
	str r5, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248B74
_02248B20:
	add r0, r4, #0
	bl ov75_02247878
	str r5, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248B74
_02248B2E:
	add r0, r4, #0
	bl ov75_02247878
	str r5, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248B74
_02248B3C:
	add r0, r4, #0
	bl ov75_02247878
	str r5, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248B74
_02248B4A:
	add r0, r4, #0
	bl ov75_02247878
	bl sub_020399EC
	b _02248B74
_02248B56:
	add r0, r4, #0
	add r0, #0xe8
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xe8
	str r1, [r0]
	add r4, #0xe8
	mov r0, #0xe1
	ldr r1, [r4]
	lsl r0, r0, #4
	cmp r1, r0
	bne _02248B74
	bl sub_020399EC
_02248B74:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02248B78: .word 0xFFFFEC77
_02248B7C: .word 0xFFFFEC76
_02248B80: .word 0xFFFFEC75
_02248B84: .word 0xFFFFEC74
_02248B88: .word 0xFFFFEC73
	thumb_func_end ov75_02248A20


	thumb_func_start ov75_02248B8C
ov75_02248B8C: ; 0x02248B8C
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #1
	bne _02248BA2
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_02248BA2:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #3
	bhi _02248C58
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02248BB8: ; jump table
	.short _02248BC0 - _02248BB8 - 2 ; case 0
	.short _02248BE4 - _02248BB8 - 2 ; case 1
	.short _02248C04 - _02248BB8 - 2 ; case 2
	.short _02248C3E - _02248BB8 - 2 ; case 3
_02248BC0:
	add r0, r4, #0
	bl ov75_02247878
	ldr r0, _02248C60 ; =0x00000F0F
	mov r2, #0xd
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
	b _02248C58
_02248BE4:
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
	b _02248C58
_02248C04:
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	bne _02248C2A
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
	b _02248C58
_02248C2A:
	cmp r0, #2
	bne _02248C58
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	mov r0, #0x15
	str r0, [r4, #8]
	b _02248C58
_02248C3E:
	ldr r0, _02248C60 ; =0x00000F0F
	mov r2, #0x11
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #1
	bl ov75_022494CC
	add r0, r4, #0
	mov r1, #0x22
	mov r2, #0x14
	bl ov75_02247854
_02248C58:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	nop
_02248C60: .word 0x00000F0F
	thumb_func_end ov75_02248B8C
