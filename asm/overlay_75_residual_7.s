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

	thumb_func_start ov75_02247890
ov75_02247890: ; 0x02247890
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	mov r0, #0x74
	add r4, r1, #0
	add r6, r2, #0
	bl YesNoPrompt_Create
	mov r3, #0
	mov r1, #0xe
	str r1, [sp, #0xc]
	str r5, [sp]
	str r3, [sp, #4]
	str r4, [sp, #8]
	mov r2, #0x19
	add r1, sp, #0
	strb r2, [r1, #0x10]
	mov r2, #0xa
	strb r2, [r1, #0x11]
	ldrb r4, [r1, #0x12]
	mov r2, #0xf
	add r7, r0, #0
	bic r4, r2
	strb r4, [r1, #0x12]
	ldrb r2, [r1, #0x12]
	mov r4, #0xf0
	bic r2, r4
	lsl r4, r6, #0x18
	lsr r4, r4, #0x18
	lsl r4, r4, #0x1c
	lsr r4, r4, #0x18
	orr r2, r4
	strb r2, [r1, #0x12]
	strb r3, [r1, #0x13]
	add r1, sp, #0
	bl YesNoPrompt_InitFromTemplate
	add r0, r7, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov75_02247890


	thumb_func_start ov75_022478E0
ov75_022478E0: ; 0x022478E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	add r5, r0, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	beq _022478F4
	cmp r0, #1
	beq _022479C0
	b _02247A1C
_022478F4:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	bl sub_02031744
	cmp r0, #1
	bne _0224790A
	ldr r3, _02247A5C ; =ov75_02249974
	ldr r4, _02247A60 ; =ov75_022499BC
	mov r7, #4
	ldr r2, _02247A64 ; =ov75_022499DC
	b _02247912
_0224790A:
	ldr r3, _02247A68 ; =ov75_02249978
	ldr r4, _02247A6C ; =ov75_0224998C
	ldr r2, _02247A70 ; =ov75_0224999C
	mov r7, #2
_02247912:
	add r6, sp, #0x14
	ldmia r2!, {r0, r1}
	stmia r6!, {r0, r1}
	ldmia r2!, {r0, r1}
	stmia r6!, {r0, r1}
	ldmia r2!, {r0, r1}
	stmia r6!, {r0, r1}
	ldmia r2!, {r0, r1}
	stmia r6!, {r0, r1}
	ldrb r0, [r3, #1]
	add r1, r5, #0
	add r1, #0x78
	str r0, [sp]
	ldrb r0, [r3, #2]
	mov r2, #0
	str r0, [sp, #4]
	ldrb r0, [r3, #3]
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x94
	str r0, [sp, #0x10]
	ldrb r3, [r3]
	ldr r0, [r5, #4]
	bl AddWindowParameterized
	add r0, r7, #0
	mov r1, #0x74
	bl ListMenuItems_New
	add r1, r5, #0
	add r1, #0xa0
	mov r6, #0
	str r0, [r1]
	cmp r7, #0
	ble _02247972
_0224795A:
	add r0, r5, #0
	add r0, #0xa0
	ldr r0, [r0]
	ldr r1, [r5, #0x34]
	ldr r2, [r4]
	ldr r3, [r4, #4]
	bl ListMenuItems_AppendFromMsgData
	add r6, r6, #1
	add r4, #8
	cmp r6, r7
	blt _0224795A
_02247972:
	add r0, r5, #0
	add r0, #0x78
	str r0, [sp, #0x20]
	add r0, r5, #0
	add r0, #0xa0
	ldr r0, [r0]
	mov r1, #0
	str r0, [sp, #0x14]
	add r0, sp, #0x14
	add r2, r1, #0
	mov r3, #0x74
	bl ListMenuInit
	add r1, r5, #0
	add r1, #0xa4
	str r0, [r1]
	add r0, r5, #0
	add r0, #0x78
	mov r1, #1
	mov r2, #0x1f
	mov r3, #0xb
	bl DrawFrameAndWindow1
	add r0, r5, #0
	add r0, #0x48
	mov r1, #1
	bl ClearFrameAndWindow2
	add r0, r5, #0
	add r0, #0x78
	bl CopyWindowToVram
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	add r5, #0x94
	add r0, r0, #1
	str r0, [r5]
	b _02247A56
_022479C0:
	add r0, r5, #0
	add r0, #0xa4
	ldr r0, [r0]
	bl ListMenu_ProcessInput
	add r4, r0, #0
	mov r0, #1
	mvn r0, r0
	cmp r4, r0
	beq _022479DC
	add r0, r0, #1
	cmp r4, r0
	beq _02247A56
	b _02247A02
_022479DC:
	ldr r0, _02247A74 ; =0x000005DC
	bl PlaySE
	ldr r0, [r5]
	mov r1, #6
	mov r2, #0
	bl ov75_02246BCC
	add r0, r5, #0
	mov r1, #0x1d
	add r0, #0x9c
	str r1, [r0]
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	add r5, #0x94
	add r0, r0, #1
	str r0, [r5]
	b _02247A56
_02247A02:
	ldr r0, _02247A74 ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	add r0, #0x9c
	str r4, [r0]
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	add r5, #0x94
	add r0, r0, #1
	str r0, [r5]
	b _02247A56
_02247A1C:
	add r0, r5, #0
	add r0, #0xa0
	ldr r0, [r0]
	bl ListMenuItems_Delete
	add r0, r5, #0
	add r0, #0xa4
	mov r1, #0
	ldr r0, [r0]
	add r2, r1, #0
	bl DestroyListMenu
	add r0, r5, #0
	add r0, #0x78
	mov r1, #1
	bl sub_0200E5D4
	add r0, r5, #0
	add r0, #0x78
	bl ClearWindowTilemapAndCopyToVram
	add r0, r5, #0
	add r0, #0x78
	bl RemoveWindow
	add r0, r5, #0
	add r0, #0x9c
	ldr r0, [r0]
	str r0, [r5, #8]
_02247A56:
	mov r0, #0
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02247A5C: .word ov75_02249974
_02247A60: .word ov75_022499BC
_02247A64: .word ov75_022499DC
_02247A68: .word ov75_02249978
_02247A6C: .word ov75_0224998C
_02247A70: .word ov75_0224999C
_02247A74: .word 0x000005DC
	thumb_func_end ov75_022478E0
