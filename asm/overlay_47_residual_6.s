	.include "asm/macros.inc"
	.include "overlay_47.inc"
	.include "global.inc"
	.include "overlay47_exact_bank.inc"

	.text
	.public ov47_02258A14
	.public ov47_02258A1C
	.public ov47_02258A60
	.public ov47_02258A80
	.public ov47_02258A8C
	.public ov47_02258B8C
	.public ov47_02258C44
	.public ov47_02258CC0
	.public ov47_02258CEC
	.public ov47_02258D18
	.public ov47_02258D44
	.public ov47_02258D78
	.public ov47_02258DA8
	.public ov47_02258DB4
	.public ov47_022591F8
	.public ov47_0225921C
	.public ov47_02259228
	.public ov47_02259278
	.public ov47_022592B4
	.public ov47_02259318
	.public ov47_02259384
	.public ov47_022593A0
	.public ov47_022593B4
	.public ov47_022593CC
	.public ov47_02259404
	.public ov47_02259430
	.public ov47_02259448
	.public ov47_0225945C
	.public ov47_0225946C
	.public ov47_02259968
	.public ov47_0225999C
	.public ov47_02259B30
	.public ov47_02259D24
	.public ov47_02259D40
	.public ov47_02259D58
	.public ov47_02259DA4
	.public ov47_02259DCC
	.public ov47_02259480


	thumb_func_start ov47_02259488
ov47_02259488: ; 0x02259488
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r0, [sp, #0x30]
	mov r1, #0x80
	str r1, [sp]
	add r6, r2, #0
	add r1, #0xc0
	str r0, [sp, #0x30]
	str r0, [sp, #4]
	ldr r0, [r6, r1]
	mov r2, #0
	str r3, [sp, #0x18]
	mov r1, #0xc7
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	ldr r0, [sp, #0x30]
	str r3, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, #5
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	ldr r2, [r6]
	mov r1, #0xc8
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	ldr r0, [sp, #0x30]
	str r3, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, #5
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	ldr r2, [r6]
	mov r1, #0xca
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	ldr r4, _02259574 ; =ov47_02259EE8
	ldr r5, [sp, #0x10]
	mov r7, #0
_022594E6:
	ldr r0, [r6]
	add r1, r5, #0
	add r2, r4, #0
	bl AddWindow
	add r7, r7, #1
	add r4, #8
	add r5, #0x10
	cmp r7, #6
	blt _022594E6
	mov r3, #0xc1
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	mov r2, #0x6d
	lsl r3, r3, #0xa
	bl ov47_0225999C
	ldr r0, [sp, #0x30]
	ldr r3, [sp, #0x10]
	str r0, [sp]
	mov r0, #5
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	mov r1, #0xc8
	mov r2, #0
	add r3, #0x84
	bl GfGfxLoader_GetCharDataFromOpenNarc
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x30]
	add r1, #0x80
	str r0, [r1]
	ldr r0, [sp, #0x10]
	mov r1, #1
	add r0, #0x88
	bl ov47_02259C8C
	ldr r0, [sp, #0x10]
	ldr r2, [sp, #0x30]
	add r0, #0xa8
	mov r1, #0
	bl ov47_02259C8C
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x10]
	ldr r0, [r0, #4]
	add r1, #0xc8
	bl ov45_0222B21C
	cmp r0, #0
	bne _02259564
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x10]
	ldr r1, [r1, #4]
	add r0, #0xc8
	bl ov47_02259DCC
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x10]
	ldr r0, [r0, #4]
	add r1, #0xc8
	bl ov45_0222B1FC
_02259564:
	ldr r0, [sp, #0x10]
	add r0, #0xdc
	str r0, [sp, #0x10]
	bl ov47_02259D74
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_02259574: .word ov47_02259EE8
	thumb_func_end ov47_02259488




	thumb_func_start ov47_02259578
ov47_02259578: ; 0x02259578
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r2, [sp, #0x14]
	ldr r2, [sp, #0x44]
	add r4, r0, #0
	str r2, [sp, #0x44]
	add r2, r4, #0
	add r2, #0x60
	ldrh r2, [r2]
	add r7, r1, #0
	add r5, r3, #0
	ldr r6, [sp, #0x40]
	cmp r2, #0x16
	bls _02259596
	b _02259944
_02259596:
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_022595A2: ; jump table
	.short _022595D0 - _022595A2 - 2 ; case 0
	.short _022595FE - _022595A2 - 2 ; case 1
	.short _0225961C - _022595A2 - 2 ; case 2
	.short _0225964A - _022595A2 - 2 ; case 3
	.short _02259678 - _022595A2 - 2 ; case 4
	.short _022596CE - _022595A2 - 2 ; case 5
	.short _022596E0 - _022595A2 - 2 ; case 6
	.short _02259720 - _022595A2 - 2 ; case 7
	.short _02259744 - _022595A2 - 2 ; case 8
	.short _0225976A - _022595A2 - 2 ; case 9
	.short _0225978A - _022595A2 - 2 ; case 10
	.short _022597A6 - _022595A2 - 2 ; case 11
	.short _022597C4 - _022595A2 - 2 ; case 12
	.short _022597D4 - _022595A2 - 2 ; case 13
	.short _02259802 - _022595A2 - 2 ; case 14
	.short _02259820 - _022595A2 - 2 ; case 15
	.short _0225984E - _022595A2 - 2 ; case 16
	.short _0225987C - _022595A2 - 2 ; case 17
	.short _022598DC - _022595A2 - 2 ; case 18
	.short _022598EE - _022595A2 - 2 ; case 19
	.short _02259900 - _022595A2 - 2 ; case 20
	.short _02259922 - _022595A2 - 2 ; case 21
	.short _0225992E - _022595A2 - 2 ; case 22
_022595D0:
	add r0, #0x90
	ldr r0, [r0]
	cmp r0, #0
	bne _022595DC
	mov r2, #0x67
	b _022595DE
_022595DC:
	mov r2, #0x69
_022595DE:
	add r0, r7, #0
	mov r1, #0
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	add r0, r4, #0
	mov r1, #1
	add r0, #0x62
	strh r1, [r0]
	mov r0, #0x16
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_022595FE:
	add r0, #0x88
	bl ov47_02259D40
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	add r0, r4, #0
	mov r1, #2
	add r0, #0x62
	strh r1, [r0]
	mov r0, #0x16
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_0225961C:
	ldr r0, _02259950 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	bne _02259628
	b _02259948
_02259628:
	add r0, r7, #0
	mov r1, #0
	mov r2, #0x68
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	add r0, r4, #0
	mov r1, #3
	add r0, #0x62
	strh r1, [r0]
	mov r0, #0x16
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_0225964A:
	add r0, #0x90
	ldr r0, [r0]
	cmp r0, #0
	bne _02259656
	mov r2, #0x6b
	b _02259658
_02259656:
	mov r2, #0x6c
_02259658:
	add r0, r7, #0
	mov r1, #0
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	add r0, r4, #0
	mov r1, #4
	add r0, #0x62
	strh r1, [r0]
	mov r0, #0x16
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_02259678:
	ldr r0, [r6, #4]
	bl ov45_0222A5C0
	add r1, sp, #0x20
	bl ov45_0222AB0C
	ldr r0, [r6, #4]
	bl ov45_0222A53C
	add r1, r0, #0
	ldr r0, [r6, #4]
	bl ov45_0222AB28
	add r1, sp, #0x20
	str r1, [sp]
	ldr r1, [sp, #0x44]
	ldr r3, [sp, #0x14]
	str r1, [sp, #4]
	ldr r1, _02259954 ; =0x00090A00
	add r2, r7, #0
	str r1, [sp, #8]
	ldr r1, _02259958 ; =0x000D0E00
	str r1, [sp, #0xc]
	add r1, r4, #0
	str r0, [sp, #0x10]
	add r0, r4, #0
	add r1, #0x88
	bl ov47_022599F0
	add r1, r4, #0
	ldr r2, [sp, #0x14]
	add r0, r4, #0
	add r1, #0xc8
	mov r3, #1
	bl ov47_02259B30
	ldr r0, _0225995C ; =0x000005D7
	bl PlaySE
	mov r0, #5
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_022596CE:
	ldr r1, [sp, #0x14]
	bl ov47_02259B74
	cmp r0, #1
	bne _02259758
	mov r0, #6
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_022596E0:
	ldr r0, _02259950 ; =gSystem
	mov r1, #1
	ldr r0, [r0, #0x48]
	tst r0, r1
	beq _02259758
	add r0, r4, #0
	add r0, #0xa8
	ldr r2, [r0]
	sub r0, r1, #2
	cmp r2, r0
	beq _022596FE
	mov r0, #7
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_022596FE:
	add r0, r7, #0
	mov r1, #0
	mov r2, #0x70
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	add r0, r4, #0
	mov r1, #0x14
	add r0, #0x62
	strh r1, [r0]
	mov r0, #0x16
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_02259720:
	add r0, r7, #0
	mov r1, #0
	mov r2, #0x6f
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_02259318
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x44]
	add r0, r5, #0
	bl ov47_02259404
	mov r0, #8
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_02259744:
	ldr r1, [sp, #0x44]
	add r0, r5, #0
	bl ov47_02259430
	cmp r0, #0
	beq _0225975A
	mov r1, #1
	mvn r1, r1
	cmp r0, r1
	beq _02259762
_02259758:
	b _02259948
_0225975A:
	mov r0, #9
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_02259762:
	mov r0, #0x14
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_0225976A:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [sp, #0x44]
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #0xa
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_0225978A:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0225982A
	ldr r2, [sp, #0x14]
	ldr r3, [sp, #0x44]
	add r0, r4, #0
	add r1, r7, #0
	bl ov47_02259C3C
	mov r0, #0xb
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_022597A6:
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	ldr r0, [sp, #0x44]
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #0xc
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_022597C4:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0225982A
	mov r0, #0xd
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_022597D4:
	add r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	bne _022597E0
	mov r2, #0x71
	b _022597E2
_022597E0:
	mov r2, #0x73
_022597E2:
	add r0, r7, #0
	mov r1, #0
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	add r0, r4, #0
	mov r1, #0xe
	add r0, #0x62
	strh r1, [r0]
	mov r0, #0x16
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_02259802:
	add r0, #0xa8
	bl ov47_02259D40
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	add r0, r4, #0
	mov r1, #0xf
	add r0, #0x62
	strh r1, [r0]
	mov r0, #0x16
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_02259820:
	ldr r0, _02259950 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	bne _0225982C
_0225982A:
	b _02259948
_0225982C:
	add r0, r7, #0
	mov r1, #0
	mov r2, #0x72
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	add r0, r4, #0
	mov r1, #0x10
	add r0, #0x62
	strh r1, [r0]
	mov r0, #0x16
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_0225984E:
	add r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	bne _0225985A
	mov r2, #0x75
	b _0225985C
_0225985A:
	mov r2, #0x76
_0225985C:
	add r0, r7, #0
	mov r1, #0
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	add r0, r4, #0
	mov r1, #0x11
	add r0, #0x62
	strh r1, [r0]
	mov r0, #0x16
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_0225987C:
	ldr r0, [r6]
	bl sub_020318E8
	add r5, r0, #0
	bl sub_020318F4
	str r0, [sp, #0x18]
	add r0, r5, #0
	bl sub_020318F8
	str r0, [sp, #0x1c]
	ldr r0, [r6, #4]
	bl ov45_0222A53C
	add r1, r0, #0
	ldr r0, [r6, #4]
	bl ov45_0222AB28
	add r1, sp, #0x18
	str r1, [sp]
	ldr r1, [sp, #0x44]
	ldr r3, [sp, #0x14]
	str r1, [sp, #4]
	ldr r1, _02259960 ; =0x000B0C00
	add r2, r7, #0
	str r1, [sp, #8]
	ldr r1, _02259964 ; =0x000F0E00
	str r1, [sp, #0xc]
	add r1, r4, #0
	str r0, [sp, #0x10]
	add r0, r4, #0
	add r1, #0xa8
	bl ov47_022599F0
	add r1, r4, #0
	ldr r2, [sp, #0x14]
	add r0, r4, #0
	add r1, #0xdc
	mov r3, #2
	bl ov47_02259B30
	ldr r0, _0225995C ; =0x000005D7
	bl PlaySE
	mov r0, #0x12
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_022598DC:
	ldr r1, [sp, #0x14]
	bl ov47_02259B74
	cmp r0, #1
	bne _02259948
	mov r0, #0x13
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_022598EE:
	ldr r0, _02259950 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	beq _02259948
	mov r0, #0x14
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_02259900:
	add r0, r7, #0
	mov r1, #0
	mov r2, #0x78
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	add r0, r4, #0
	mov r1, #0x15
	add r0, #0x62
	strh r1, [r0]
	mov r0, #0x16
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_02259922:
	add r0, r5, #0
	bl ov47_022593CC
	add sp, #0x28
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0225992E:
	add r0, r5, #0
	bl ov47_022593B4
	cmp r0, #1
	bne _02259948
	add r0, r4, #0
	add r0, #0x62
	ldrh r0, [r0]
	add r4, #0x60
	strh r0, [r4]
	b _02259948
_02259944:
	bl GF_AssertFail
_02259948:
	mov r0, #0
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02259950: .word gSystem
_02259954: .word 0x00090A00
_02259958: .word 0x000D0E00
_0225995C: .word 0x000005D7
_02259960: .word 0x000B0C00
_02259964: .word 0x000F0E00
	thumb_func_end ov47_02259578
