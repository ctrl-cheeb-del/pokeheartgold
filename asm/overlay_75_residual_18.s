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

	thumb_func_start ov75_02249780
ov75_02249780: ; 0x02249780
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r2, #0
	mov r4, #0
	add r5, r1, #0
	ldr r2, _02249828 ; =ov75_02249ACC
	str r0, [sp]
	add r1, r4, #0
	add r0, r2, #0
	add r3, r4, #0
_02249794:
	add r6, r1, #0
	ldrsb r6, [r0, r6]
	add r2, r2, #1
	add r1, r1, #1
	strb r6, [r5, r4]
	ldrsb r6, [r2, r3]
	add r4, r4, #1
	cmp r6, #0
	bne _02249794
	add r0, r7, #0
	mov r1, #0xc8
	bl Heap_Alloc
	str r0, [sp, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	mov r2, #0x64
	bl CopyStringToU16Array
	ldr r7, [sp, #4]
	mov r6, #0
_022497BE:
	ldrh r1, [r7]
	ldr r0, _0224982C ; =0x0000FFFF
	cmp r1, r0
	bne _022497CC
	mov r2, #0
	strb r2, [r5, r4]
	b _02249802
_022497CC:
	ldr r2, [sp, #4]
	lsl r3, r6, #1
	ldrh r3, [r2, r3]
	ldr r1, _02249830 ; =ov75_02249ADC
	mov r0, #0
_022497D6:
	ldrh r2, [r1]
	cmp r2, r3
	bne _022497EA
	ldr r1, _02249830 ; =ov75_02249ADC
	lsl r2, r0, #2
	add r2, r1, r2
	mov r1, #2
	ldrsb r1, [r2, r1]
	strb r1, [r5, r4]
	b _022497F2
_022497EA:
	add r0, r0, #1
	add r1, r1, #4
	cmp r0, #0xa
	blo _022497D6
_022497F2:
	cmp r0, #0xa
	blo _022497FA
	bl GF_AssertFail
_022497FA:
	add r4, r4, #1
	add r7, r7, #2
	add r6, r6, #1
	b _022497BE
_02249802:
	ldr r1, _02249834 ; =ov75_02249AD0
	add r3, r2, #0
	add r0, r1, #0
_02249808:
	add r6, r2, #0
	ldrsb r6, [r0, r6]
	add r1, r1, #1
	add r2, r2, #1
	strb r6, [r5, r4]
	ldrsb r6, [r1, r3]
	add r4, r4, #1
	cmp r6, #0
	bne _02249808
	mov r0, #0
	strb r0, [r5, r4]
	ldr r0, [sp, #4]
	bl Heap_Free
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02249828: .word ov75_02249ACC
_0224982C: .word 0x0000FFFF
_02249830: .word ov75_02249ADC
_02249834: .word ov75_02249AD0
	thumb_func_end ov75_02249780


	thumb_func_start ov75_02249838
ov75_02249838: ; 0x02249838
	push {r4, r5, r6, lr}
	add r6, r0, #0
	add r0, r1, #0
	mov r1, #0xc8
	mov r5, #1
	bl Heap_Alloc
	add r4, r0, #0
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x64
	bl CopyStringToU16Array
	ldrh r1, [r4]
	ldr r0, _0224987C ; =0x0000FFFF
	cmp r1, r0
	beq _02249870
	ldr r1, _02249880 ; =0x00000121
	add r3, r4, #0
_0224985E:
	ldrh r2, [r3]
	cmp r2, r1
	beq _02249868
	mov r5, #0
	b _02249870
_02249868:
	add r3, r3, #2
	ldrh r2, [r3]
	cmp r2, r0
	bne _0224985E
_02249870:
	add r0, r4, #0
	bl Heap_Free
	add r0, r5, #0
	pop {r4, r5, r6, pc}
	nop
_0224987C: .word 0x0000FFFF
_02249880: .word 0x00000121
	thumb_func_end ov75_02249838


	thumb_func_start ov75_02249884
ov75_02249884: ; 0x02249884
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	mov r4, #0
	add r5, r0, #0
	add r7, r1, #0
	str r4, [sp, #4]
_02249890:
	mov r0, #0
	str r0, [r7]
	str r0, [sp]
	b _022498CC
_02249898:
	cmp r0, #0
	bne _022498A4
	bne _022498B2
	bl GF_AssertFail
	b _022498B2
_022498A4:
	add r4, r4, #1
_022498A6:
	ldrsb r0, [r5, r4]
	add r6, r5, r4
	cmp r0, #0x30
	blt _02249898
	cmp r0, #0x39
	bgt _02249898
_022498B2:
	ldr r1, [r7]
	mov r0, #0xa
	mul r0, r1
	str r0, [r7]
	mov r1, #0
	ldrsb r1, [r6, r1]
	add r4, r4, #1
	sub r1, #0x30
	add r0, r0, r1
	str r0, [r7]
	ldr r0, [sp]
	add r0, r0, #1
	str r0, [sp]
_022498CC:
	ldr r0, [sp]
	cmp r0, #4
	blt _022498A6
	ldr r0, [sp, #4]
	add r7, r7, #4
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #4
	blt _02249890
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov75_02249884

	.rodata

ov75_022498E4:
	.word ov44_0222A4B4, ov44_0222A60C, ov44_0222A758, FS_OVERLAY_ID(OVY_44)
ov75_022498F4:
	.word ov75_02246F0C, ov75_02247118, ov75_02247180, 0xFFFFFFFF

ov75_02249904: ; 0x02249904
	.word ov75_02246D00, ov75_02246D04, ov75_022498F4, 0
	.word ov75_02246D08, ov75_02246D40, _02102620, 0
	.word ov75_02246DB4, ov75_02246DFC, _02102620, 0
	.word ov75_02246E3C, ov75_02246E78, _02102620, 0
	.word ov75_02246E3C, ov75_02246E78, _02102620, 0
	.word ov75_02246EAC, ov75_02246EDC, ov75_022498E4, 1

	.public ov75_App_MainMenu_SelectOption_WiiMessageSettings
ov75_App_MainMenu_SelectOption_WiiMessageSettings:
	.word ov75_02246960, ov75_022469D8, ov75_02246B00, 0xFFFFFFFF
ov75_02249974:
	.byte 0x0B, 0x07, 0x14, 0x08

ov75_02249978: ; 0x02249978
	.byte 0x0B, 0x0D, 0x14, 0x04

ov75_0224997C: ; 0x0224997C
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov75_0224998C: ; 0x0224998C
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1D, 0x00, 0x00, 0x00

ov75_0224999C: ; 0x0224999C
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov75_0224976C
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00
	.byte 0x00, 0x08, 0x00, 0x10, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov75_022499BC: ; 0x022499BC
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1D, 0x00, 0x00, 0x00

ov75_022499DC: ; 0x022499DC
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov75_02249758
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x00
	.byte 0x00, 0x08, 0x00, 0x10, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov75_022499FC: ; 0x022499FC
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x60, 0x00, 0x00, 0x00

ov75_02249A24: ; 0x02249A24
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x1B, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov75_02249A5C: ; 0x02249A5C
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1F, 0x00
	.byte 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1E, 0x02, 0x00, 0x03, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1D, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x1C, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov75_02249ACC: ; 0x02249ACC
	.byte 0x77, 0x00, 0x00, 0x00

	.balign 4, 0
ov75_02249AD0: ; 0x02249AD0
	.asciz "@wii.com"

	.balign 4, 0
ov75_02249ADC: ; 0x02249ADC
	.byte 0x21, 0x01, 0x30, 0x00
	.byte 0x22, 0x01, 0x31, 0x00, 0x23, 0x01, 0x32, 0x00, 0x24, 0x01, 0x33, 0x00, 0x25, 0x01, 0x34, 0x00
	.byte 0x26, 0x01, 0x35, 0x00, 0x27, 0x01, 0x36, 0x00, 0x28, 0x01, 0x37, 0x00, 0x29, 0x01, 0x38, 0x00
	.byte 0x2A, 0x01, 0x39, 0x00

	.data

_02249B20:
	.byte 0x04, 0x00, 0x00, 0x00

ov75_02249B24: ; 0x02249B24
	.byte 0x08, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00

ov75_02249B30: ; 0x02249B30
	.word ov75_022478E0
	.word ov75_02247A78
	.word ov75_02247A98
	.word ov75_02247B98
	.word ov75_022483EC
	.word ov75_0224852C
	.word ov75_0224854C
	.word ov75_02248584
	.word ov75_02248684
	.word ov75_022486EC
	.word ov75_02248714
	.word ov75_0224874C
	.word ov75_02248774
	.word ov75_02248800
	.word ov75_022488AC
	.word ov75_022488BC
	.word ov75_02248994
	.word ov75_022489F8
	.word ov75_02248A20
	.word ov75_02248B8C
	.word ov75_02248C64
	.word ov75_02248C84
	.word ov75_02248D2C
	.word ov75_02248F18
	.word ov75_02248F7C
	.word ov75_02248FE8
	.word ov75_022490D8
	.word ov75_022491CC
	.word ov75_022491F0
	.word ov75_0224921C
	.word ov75_0224921C
	.word ov75_02249258
	.word ov75_02249278
	.word ov75_0224937C
	.word ov75_02249460
	.word ov75_02249478
	.word ov75_022494A4
	.word ov75_02249550
	.word ov75_022495B0

	.bss

_02249BE0:
	.space 0x20
