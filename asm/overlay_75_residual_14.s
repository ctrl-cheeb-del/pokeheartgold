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

	thumb_func_start ov75_02248C84
ov75_02248C84: ; 0x02248C84
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #1
	bne _02248C9A
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_02248C9A:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	beq _02248CAE
	cmp r0, #1
	beq _02248CCC
	cmp r0, #2
	beq _02248CEC
	b _02248D22
_02248CAE:
	ldr r0, _02248D28 ; =0x00000F0F
	mov r2, #0xe
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
	b _02248D22
_02248CCC:
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
	b _02248D22
_02248CEC:
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	bne _02248D10
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	add r0, r4, #0
	mov r1, #0x1a
	mov r2, #0
	bl ov75_02247854
	b _02248D22
_02248D10:
	cmp r0, #2
	bne _02248D22
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	mov r0, #0x13
	str r0, [r4, #8]
_02248D22:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02248D28: .word 0x00000F0F
	thumb_func_end ov75_02248C84


	thumb_func_start ov75_02248D2C
ov75_02248D2C: ; 0x02248D2C
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, [r4]
	bl ov75_02246CE0
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _02248D46
	mov r0, #0x15
	str r0, [r4, #8]
	mov r0, #0
	pop {r3, r4, r5, pc}
_02248D46:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #3
	bls _02248D52
	b _02248F00
_02248D52:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02248D5E: ; jump table
	.short _02248D66 - _02248D5E - 2 ; case 0
	.short _02248D9C - _02248D5E - 2 ; case 1
	.short _02248ECE - _02248D5E - 2 ; case 2
	.short _02248EEC - _02248D5E - 2 ; case 3
_02248D66:
	ldr r0, _02248F04 ; =0x00000F0F
	mov r2, #0x12
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #0
	bl ov75_022494CC
	add r0, r4, #0
	bl ov75_0224785C
	ldr r0, [r4]
	bl ov75_02246CCC
	ldr r1, [r4]
	add r0, r1, #0
	add r0, #0x98
	add r1, #0xfc
	bl ov70_02238304
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02248F00
_02248D9C:
	bl ov70_02237F38
	cmp r0, #0
	bne _02248DA6
	b _02248EAE
_02248DA6:
	bl ov70_02237F58
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #0
	add r0, #0xe8
	str r1, [r0]
	add r0, r4, #0
	bl ov75_02247878
	add r0, r5, #0
	add r0, #0xf
	cmp r0, #0x11
	bhi _02248EA8
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02248DCE: ; jump table
	.short _02248E98 - _02248DCE - 2 ; case 0
	.short _02248EA0 - _02248DCE - 2 ; case 1
	.short _02248EA8 - _02248DCE - 2 ; case 2
	.short _02248E98 - _02248DCE - 2 ; case 3
	.short _02248EA8 - _02248DCE - 2 ; case 4
	.short _02248EA8 - _02248DCE - 2 ; case 5
	.short _02248EA8 - _02248DCE - 2 ; case 6
	.short _02248EA8 - _02248DCE - 2 ; case 7
	.short _02248EA8 - _02248DCE - 2 ; case 8
	.short _02248EA8 - _02248DCE - 2 ; case 9
	.short _02248EA8 - _02248DCE - 2 ; case 10
	.short _02248EA8 - _02248DCE - 2 ; case 11
	.short _02248EA8 - _02248DCE - 2 ; case 12
	.short _02248EA0 - _02248DCE - 2 ; case 13
	.short _02248E90 - _02248DCE - 2 ; case 14
	.short _02248DF2 - _02248DCE - 2 ; case 15
	.short _02248E88 - _02248DCE - 2 ; case 16
	.short _02248E90 - _02248DCE - 2 ; case 17
_02248DF2:
	ldr r1, [r4]
	add r0, r1, #0
	add r0, #0xfc
	ldr r0, [r0]
	cmp r0, #0
	beq _02248E08
	cmp r0, #1
	beq _02248E6A
	cmp r0, #2
	beq _02248E74
	b _02248E7E
_02248E08:
	mov r0, #1
	lsl r0, r0, #8
	ldr r0, [r1, r0]
	cmp r0, #3
	bhi _02248E64
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02248E1E: ; jump table
	.short _02248E26 - _02248E1E - 2 ; case 0
	.short _02248E50 - _02248E1E - 2 ; case 1
	.short _02248E5A - _02248E1E - 2 ; case 2
	.short _02248E34 - _02248E1E - 2 ; case 3
_02248E26:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02248F00
_02248E34:
	ldr r0, _02248F04 ; =0x00000F0F
	mov r2, #0x13
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #1
	bl ov75_022494CC
	add r0, r4, #0
	mov r1, #0x22
	mov r2, #0x15
	bl ov75_02247854
	b _02248F00
_02248E50:
	ldr r0, _02248F08 ; =0xFFFFEC72
	str r0, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248F00
_02248E5A:
	ldr r0, _02248F0C ; =0xFFFFEC71
	str r0, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248F00
_02248E64:
	bl sub_020399EC
	b _02248F00
_02248E6A:
	ldr r0, _02248F10 ; =0xFFFFEC6E
	str r0, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248F00
_02248E74:
	ldr r0, _02248F14 ; =0xFFFFEC6D
	str r0, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248F00
_02248E7E:
	bl GF_AssertFail
	bl sub_020399EC
	b _02248F00
_02248E88:
	str r5, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248F00
_02248E90:
	str r5, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248F00
_02248E98:
	str r5, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248F00
_02248EA0:
	str r5, [r4, #0x10]
	mov r0, #0x20
	str r0, [r4, #8]
	b _02248F00
_02248EA8:
	bl sub_020399EC
	b _02248F00
_02248EAE:
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
	bne _02248F00
	bl sub_020399EC
	b _02248F00
_02248ECE:
	ldr r0, _02248F04 ; =0x00000F0F
	mov r2, #0x14
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
	b _02248F00
_02248EEC:
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #0
	bne _02248F00
	add r0, r4, #0
	mov r1, #0x1a
	mov r2, #0x17
	bl ov75_02247854
_02248F00:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02248F04: .word 0x00000F0F
_02248F08: .word 0xFFFFEC72
_02248F0C: .word 0xFFFFEC71
_02248F10: .word 0xFFFFEC6E
_02248F14: .word 0xFFFFEC6D
	thumb_func_end ov75_02248D2C


	thumb_func_start ov75_02248F18
ov75_02248F18: ; 0x02248F18
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #1
	bne _02248F2E
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_02248F2E:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	beq _02248F3E
	cmp r0, #1
	beq _02248F5C
	b _02248F72
_02248F3E:
	ldr r0, _02248F78 ; =0x00000F0F
	mov r2, #0x15
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
	b _02248F72
_02248F5C:
	ldr r0, [r4]
	mov r1, #3
	mov r2, #2
	bl ov75_02246BCC
	ldr r0, [r4]
	mov r1, #0x18
	bl ov75_02246BE0
	mov r0, #0x1e
	str r0, [r4, #8]
_02248F72:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02248F78: .word 0x00000F0F
	thumb_func_end ov75_02248F18


	thumb_func_start ov75_02248F7C
ov75_02248F7C: ; 0x02248F7C
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #1
	bne _02248F92
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_02248F92:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	beq _02248FA2
	cmp r0, #1
	beq _02248FC0
	b _02248FDC
_02248FA2:
	ldr r0, _02248FE4 ; =0x00000F0F
	mov r2, #0x18
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
	b _02248FDC
_02248FC0:
	ldr r0, [r4]
	bl ov75_02246C3C
	ldr r0, [r4]
	bl ov75_02246C68
	ldr r0, [r4]
	bl ov75_02246C8C
	add r0, r4, #0
	mov r1, #0x19
	mov r2, #0
	bl ov75_02247854
_02248FDC:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	nop
_02248FE4: .word 0x00000F0F
	thumb_func_end ov75_02248F7C


	thumb_func_start ov75_02248FE8
ov75_02248FE8: ; 0x02248FE8
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	add r1, r4, #0
	add r1, #0x94
	ldr r1, [r1]
	cmp r1, #3
	bhi _022490CA
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02249004: ; jump table
	.short _0224900C - _02249004 - 2 ; case 0
	.short _0224902E - _02249004 - 2 ; case 1
	.short _02249090 - _02249004 - 2 ; case 2
	.short _022490A8 - _02249004 - 2 ; case 3
_0224900C:
	ldr r1, _022490D0 ; =0x00000F0F
	mov r2, #0x20
	str r1, [sp]
	ldr r1, [r4, #0x34]
	mov r3, #0
	bl ov75_022494CC
	add r0, r4, #0
	bl ov75_0224785C
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _022490CA
_0224902E:
	ldr r0, [r4]
	ldr r0, [r0, #4]
	bl SaveGameNormal
	cmp r0, #2
	bne _0224906C
	ldr r0, [r4]
	ldr r0, [r0, #4]
	bl Save_PlayerData_GetProfile
	add r2, r0, #0
	ldr r0, [r4, #0x20]
	mov r1, #0
	bl BufferPlayersName
	ldr r0, _022490D0 ; =0x00000F0F
	mov r2, #0x21
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #0
	bl ov75_022494CC
	ldr r0, _022490D4 ; =0x0000061A
	bl PlaySE
	ldr r0, [r4]
	ldr r0, [r0, #4]
	bl Save_ClearStatusFlags
	b _0224907C
_0224906C:
	ldr r0, _022490D0 ; =0x00000F0F
	mov r2, #0x22
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #0
	bl ov75_022494CC
_0224907C:
	add r0, r4, #0
	bl ov75_02247878
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _022490CA
_02249090:
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #0
	bne _022490CA
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _022490CA
_022490A8:
	add r0, #0x98
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x98
	str r1, [r0]
	add r0, r4, #0
	add r0, #0x98
	ldr r0, [r0]
	cmp r0, #0x3c
	ble _022490CA
	add r0, r4, #0
	mov r1, #0
	add r0, #0x98
	str r1, [r0]
	ldr r0, [r4, #0xc]
	str r0, [r4, #8]
_022490CA:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_022490D0: .word 0x00000F0F
_022490D4: .word 0x0000061A
	thumb_func_end ov75_02248FE8


	thumb_func_start ov75_022490D8
ov75_022490D8: ; 0x022490D8
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #1
	bne _022490EE
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_022490EE:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #4
	bhi _022491C2
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02249104: ; jump table
	.short _0224910E - _02249104 - 2 ; case 0
	.short _0224912C - _02249104 - 2 ; case 1
	.short _02249166 - _02249104 - 2 ; case 2
	.short _0224918E - _02249104 - 2 ; case 3
	.short _022491A6 - _02249104 - 2 ; case 4
_0224910E:
	ldr r0, _022491C8 ; =0x00000F0F
	mov r2, #0xf
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
	b _022491C2
_0224912C:
	bl ov00_021EC8D8
	bl sub_0203A914
	bl sub_0203957C
	mov r0, #4
	bl Sys_ClearSleepDisableFlag
	mov r0, #0x46
	ldr r1, [r4]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	cmp r0, #1
	bne _02249158
	bl ov70_02237F2C
	mov r0, #0x46
	ldr r1, [r4]
	mov r2, #0
	lsl r0, r0, #2
	str r2, [r1, r0]
_02249158:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _022491C2
_02249166:
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #0
	bne _022491C2
	ldr r0, _022491C8 ; =0x00000F0F
	mov r2, #0x10
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
	b _022491C2
_0224918E:
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #0
	bne _022491C2
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _022491C2
_022491A6:
	add r0, r4, #0
	add r0, #0x90
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x90
	str r1, [r0]
	add r0, r4, #0
	add r0, #0x90
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _022491C2
	ldr r0, [r4, #0xc]
	str r0, [r4, #8]
_022491C2:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_022491C8: .word 0x00000F0F
	thumb_func_end ov75_022490D8


	thumb_func_start ov75_022491CC
ov75_022491CC: ; 0x022491CC
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x1c]
	neg r0, r0
	bl ov00_021E6A70
	ldr r2, [r4, #0x18]
	add r1, r0, #0
	add r0, r4, #0
	neg r2, r2
	bl ov75_0224971C
	mov r0, #0x1c
	str r0, [r4, #8]
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov75_022491CC


	thumb_func_start ov75_022491F0
ov75_022491F0: ; 0x022491F0
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _02249218 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	bne _02249204
	mov r0, #2
	tst r0, r1
	beq _02249212
_02249204:
	add r0, r4, #0
	add r0, #0x68
	mov r1, #0
	bl sub_0200E5D4
	mov r0, #0
	str r0, [r4, #8]
_02249212:
	mov r0, #0
	pop {r4, pc}
	nop
_02249218: .word gSystem
	thumb_func_end ov75_022491F0
