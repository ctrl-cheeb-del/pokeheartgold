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

	thumb_func_start ov75_02249278
ov75_02249278: ; 0x02249278
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	mov r1, #0
	ldr r0, [r4, #0x10]
	sub r2, r1, #5
	cmp r0, r2
	bgt _022492D6
	bge _0224930A
	add r2, r1, #0
	sub r2, #0xf
	cmp r0, r2
	bgt _022492C4
	add r2, r1, #0
	sub r2, #0xf
	cmp r0, r2
	bge _0224930A
	ldr r2, _02249374 ; =0x00001393
	add r2, r0, r2
	cmp r2, #0xa
	bhi _0224930A
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_022492AE: ; jump table
	.short _0224933E - _022492AE - 2 ; case 0
	.short _02249338 - _022492AE - 2 ; case 1
	.short _0224930A - _022492AE - 2 ; case 2
	.short _0224930A - _022492AE - 2 ; case 3
	.short _02249332 - _022492AE - 2 ; case 4
	.short _0224932C - _022492AE - 2 ; case 5
	.short _02249326 - _022492AE - 2 ; case 6
	.short _02249320 - _022492AE - 2 ; case 7
	.short _0224931A - _022492AE - 2 ; case 8
	.short _02249314 - _022492AE - 2 ; case 9
	.short _0224930E - _022492AE - 2 ; case 10
_022492C4:
	mov r2, #0xd
	mvn r2, r2
	cmp r0, r2
	bgt _022492D0
	beq _02249306
	b _0224930A
_022492D0:
	add r2, r2, #2
	cmp r0, r2
	b _0224930A
_022492D6:
	sub r2, r1, #1
	cmp r0, r2
	bgt _022492F0
	bge _02249302
	sub r2, r1, #3
	cmp r0, r2
	bgt _022492E8
	cmp r0, r2
	b _0224930A
_022492E8:
	sub r2, r1, #2
	cmp r0, r2
	beq _02249306
	b _0224930A
_022492F0:
	cmp r0, #1
	bgt _022492F8
	beq _022492FE
	b _0224930A
_022492F8:
	cmp r0, #2
	beq _02249302
	b _0224930A
_022492FE:
	mov r2, #0x36
	b _02249342
_02249302:
	mov r2, #0x37
	b _02249342
_02249306:
	mov r2, #0x39
	b _02249342
_0224930A:
	mov r2, #0x38
	b _02249342
_0224930E:
	mov r2, #0xb5
	add r1, r1, #1
	b _02249342
_02249314:
	mov r2, #0xb6
	add r1, r1, #1
	b _02249342
_0224931A:
	mov r2, #0xb6
	add r1, r1, #1
	b _02249342
_02249320:
	mov r2, #0xb7
	add r1, r1, #1
	b _02249342
_02249326:
	mov r2, #0xb8
	add r1, r1, #1
	b _02249342
_0224932C:
	mov r2, #0xb6
	add r1, r1, #1
	b _02249342
_02249332:
	mov r2, #0xb6
	add r1, r1, #1
	b _02249342
_02249338:
	mov r2, #0xb7
	add r1, r1, #1
	b _02249342
_0224933E:
	mov r2, #0xb8
	add r1, r1, #1
_02249342:
	cmp r1, #0
	ldr r0, _02249378 ; =0x00000F0F
	bne _02249356
	str r0, [sp]
	ldr r1, [r4, #0x34]
	add r0, r4, #0
	mov r3, #1
	bl ov75_022494CC
	b _02249362
_02249356:
	str r0, [sp]
	ldr r1, [r4, #0x24]
	add r0, r4, #0
	mov r3, #1
	bl ov75_022494CC
_02249362:
	add r0, r4, #0
	mov r1, #0x22
	mov r2, #0x21
	bl ov75_02247854
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	nop
_02249374: .word 0x00001393
_02249378: .word 0x00000F0F
	thumb_func_end ov75_02249278


	thumb_func_start ov75_0224937C
ov75_0224937C: ; 0x0224937C
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	add r1, r4, #0
	add r1, #0x94
	ldr r1, [r1]
	cmp r1, #3
	bhi _02249434
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02249398: ; jump table
	.short _022493A0 - _02249398 - 2 ; case 0
	.short _022493BC - _02249398 - 2 ; case 1
	.short _02249400 - _02249398 - 2 ; case 2
	.short _0224941C - _02249398 - 2 ; case 3
_022493A0:
	ldr r1, _0224945C ; =0x00000F0F
	mov r2, #0xf
	str r1, [sp]
	ldr r1, [r4, #0x34]
	mov r3, #1
	bl ov75_022494CC
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02249456
_022493BC:
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #0
	bne _02249456
	bl sub_0203957C
	bl ov00_021EC8D8
	bl sub_0203A914
	mov r0, #4
	bl Sys_ClearSleepDisableFlag
	mov r0, #0x46
	ldr r1, [r4]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	cmp r0, #1
	bne _022493F2
	bl ov70_02237F2C
	mov r0, #0x46
	ldr r1, [r4]
	mov r2, #0
	lsl r0, r0, #2
	str r2, [r1, r0]
_022493F2:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02249456
_02249400:
	ldr r1, _0224945C ; =0x00000F0F
	mov r2, #0x10
	str r1, [sp]
	ldr r1, [r4, #0x34]
	mov r3, #1
	bl ov75_022494CC
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02249456
_0224941C:
	ldr r0, [r4, #0x44]
	bl ov75_02249534
	cmp r0, #0
	bne _02249456
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02249456
_02249434:
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
	ble _02249456
	ldr r0, [r4]
	bl ov75_02246BD8
	mov r0, #0x1d
	str r0, [r4, #8]
_02249456:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_0224945C: .word 0x00000F0F
	thumb_func_end ov75_0224937C
