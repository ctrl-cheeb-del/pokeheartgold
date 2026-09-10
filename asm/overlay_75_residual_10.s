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

	thumb_func_start ov75_02248584
ov75_02248584: ; 0x02248584
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #1
	bne _0224859A
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_0224859A:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #4
	bhi _02248678
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022485B0: ; jump table
	.short _022485BA - _022485B0 - 2 ; case 0
	.short _022485C8 - _022485B0 - 2 ; case 1
	.short _022485E6 - _022485B0 - 2 ; case 2
	.short _02248606 - _022485B0 - 2 ; case 3
	.short _02248646 - _022485B0 - 2 ; case 4
_022485BA:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02248678
_022485C8:
	ldr r0, _02248680 ; =0x00000F0F
	mov r2, #0xb
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
	b _02248678
_022485E6:
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
	b _02248678
_02248606:
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	bne _0224862C
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
	b _02248678
_0224862C:
	cmp r0, #2
	bne _02248678
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	add r0, r4, #0
	mov r1, #0x22
	mov r2, #0
	bl ov75_02247854
	b _02248678
_02248646:
	ldr r0, [r4]
	ldr r0, [r0, #4]
	bl sub_0203A05C
	cmp r0, #0
	bne _0224866E
	ldr r0, [r4]
	mov r1, #5
	mov r2, #0
	bl ov75_02246BCC
	ldr r0, [r4]
	mov r1, #0xc
	bl ov75_02246BE0
	mov r0, #0x1d
	str r0, [r4, #8]
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_0224866E:
	add r0, r4, #0
	mov r1, #0x22
	mov r2, #0xc
	bl ov75_02247854
_02248678:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	nop
_02248680: .word 0x00000F0F
	thumb_func_end ov75_02248584


	thumb_func_start ov75_02248684
ov75_02248684: ; 0x02248684
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	bne _022486C2
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	ldr r0, _022486E8 ; =0x00000F0F
	mov r2, #1
	str r0, [sp]
	ldr r1, [r4, #0x2c]
	add r0, r4, #0
	add r3, r2, #0
	bl ov75_022494CC
	add r0, r4, #0
	mov r1, #0x22
	mov r2, #0xc
	bl ov75_02247854
	add r0, r4, #0
	bl ov75_0224785C
	b _022486E2
_022486C2:
	cmp r0, #2
	bne _022486E2
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	bl sub_0203957C
	ldr r0, [r4]
	mov r1, #6
	mov r2, #0
	bl ov75_02246BCC
	mov r0, #0x1d
	str r0, [r4, #8]
_022486E2:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_022486E8: .word 0x00000F0F
	thumb_func_end ov75_02248684


	thumb_func_start ov75_022486EC
ov75_022486EC: ; 0x022486EC
	push {r3, r4, lr}
	sub sp, #4
	ldr r1, _02248710 ; =0x00000F0F
	add r4, r0, #0
	str r1, [sp]
	ldr r1, [r4, #0x30]
	mov r2, #0x1a
	mov r3, #1
	bl ov75_022494CC
	add r0, r4, #0
	mov r1, #0x22
	mov r2, #0xa
	bl ov75_02247854
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02248710: .word 0x00000F0F
	thumb_func_end ov75_022486EC
