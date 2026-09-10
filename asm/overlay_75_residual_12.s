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

	thumb_func_start ov75_022488BC
ov75_022488BC: ; 0x022488BC
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	bl ov00_021ECDC8
	cmp r0, #5
	bhi _02248984
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022488D6: ; jump table
	.short _022488E8 - _022488D6 - 2 ; case 0
	.short _02248984 - _022488D6 - 2 ; case 1
	.short _02248984 - _022488D6 - 2 ; case 2
	.short _022488E2 - _022488D6 - 2 ; case 3
	.short _022488E8 - _022488D6 - 2 ; case 4
	.short _022488E8 - _022488D6 - 2 ; case 5
_022488E2:
	mov r0, #0x10
	str r0, [r4, #8]
	b _02248984
_022488E8:
	add r0, r4, #0
	bl ov75_02247878
	add r0, sp, #4
	add r1, sp, #0
	bl ov00_021EC11C
	str r0, [r4, #0x14]
	ldr r0, [sp, #4]
	str r0, [r4, #0x18]
	bl ov00_021EC210
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
	bne _0224892C
	bl ov70_02237F2C
	mov r0, #0x46
	ldr r1, [r4]
	mov r2, #0
	lsl r0, r0, #2
	str r2, [r1, r0]
_0224892C:
	mov r0, #0x1b
	str r0, [r4, #8]
	ldr r1, [sp]
	cmp r1, #7
	bhi _02248972
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02248942: ; jump table
	.short _02248972 - _02248942 - 2 ; case 0
	.short _02248952 - _02248942 - 2 ; case 1
	.short _02248952 - _02248942 - 2 ; case 2
	.short _02248964 - _02248942 - 2 ; case 3
	.short _02248956 - _02248942 - 2 ; case 4
	.short _0224896E - _02248942 - 2 ; case 5
	.short _02248960 - _02248942 - 2 ; case 6
	.short _0224896E - _02248942 - 2 ; case 7
_02248952:
	str r0, [r4, #8]
	b _02248972
_02248956:
	bl ov00_021FA0D8
	mov r0, #0x1b
	str r0, [r4, #8]
	b _02248972
_02248960:
	str r0, [r4, #8]
	b _02248972
_02248964:
	bl ov00_021ED9B4
	mov r0, #0x1b
	str r0, [r4, #8]
	b _02248972
_0224896E:
	bl sub_020399EC
_02248972:
	ldr r1, [sp, #4]
	ldr r0, _0224898C ; =0xFFFFB1E0
	cmp r1, r0
	bge _02248984
	ldr r0, _02248990 ; =0xFFFF8AD1
	cmp r1, r0
	blt _02248984
	mov r0, #0x1b
	str r0, [r4, #8]
_02248984:
	mov r0, #0
	add sp, #8
	pop {r4, pc}
	nop
_0224898C: .word 0xFFFFB1E0
_02248990: .word 0xFFFF8AD1
	thumb_func_end ov75_022488BC


	thumb_func_start ov75_02248994
ov75_02248994: ; 0x02248994
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	bl sub_0202C6F4
	add r6, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	bl Save_SysInfo_Get
	add r4, r0, #0
	add r0, r6, #0
	bl sub_0202C08C
	add r7, r0, #0
	add r0, r4, #0
	bl Save_SysInfo_GetDwcProfileId
	cmp r0, #0
	bne _022489CC
	add r0, r6, #0
	bl sub_0203A040
	add r1, r0, #0
	add r0, r4, #0
	bl Save_SysInfo_SetDwcProfileId
_022489CC:
	add r0, r4, #0
	bl Save_SysInfo_GetDwcProfileId
	add r4, r0, #0
	add r0, r7, #0
	bl DWC_CreateFriendKey
	add r3, r0, #0
	add r2, r1, #0
	add r0, r4, #0
	add r1, r3, #0
	bl ov70_022378C0
	mov r0, #0x46
	ldr r1, [r5]
	mov r2, #1
	lsl r0, r0, #2
	str r2, [r1, r0]
	mov r0, #0x11
	str r0, [r5, #8]
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov75_02248994
