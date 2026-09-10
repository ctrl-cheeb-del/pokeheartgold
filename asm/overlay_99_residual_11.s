	.include "asm/macros.inc"
	.include "overlay_99.inc"
	.include "global.inc"

	.text
	.public PokeathlonCourseRecord_Exit
	.public PokeathlonCourseRecord_Init
	.public PokeathlonCourseRecord_Main
	.public PokeathlonEventRecord_Exit
	.public PokeathlonEventRecord_Init
	.public PokeathlonEventRecord_Main
	.public PokeathlonMedals_Exit
	.public PokeathlonMedals_Init
	.public PokeathlonMedals_Main
	.public _021E954C
	.public _021EA5C0
	.public _021EA5CC
	.public _021EA5D8
	.public _021EA5E4
	.public ov99_021E5B90
	.public ov99_021E5BB4
	.public ov99_021E5BD8
	.public ov99_021E5C20
	.public ov99_021E5C4C
	.public ov99_021E5C88
	.public ov99_021E5D2C
	.public ov99_021E5D58
	.public ov99_021E5EB4
	.public ov99_021E5F74
	.public ov99_021E5FE8
	.public ov99_021E6018
	.public ov99_021E6050
	.public ov99_021E607C
	.public ov99_021E6144
	.public ov99_021E6188
	.public ov99_021E6218
	.public ov99_021E6250
	.public ov99_021E6274
	.public ov99_021E6400
	.public ov99_021E6438
	.public ov99_021E64E0
	.public ov99_021E6530
	.public ov99_021E6638
	.public ov99_021E677C
	.public ov99_021E6840
	.public ov99_021E6888
	.public ov99_021E6938
	.public ov99_021E695C
	.public ov99_021E69D8
	.public ov99_021E6A70
	.public ov99_021E6A9C
	.public ov99_021E6C30
	.public ov99_021E6CF4
	.public ov99_021E6D14
	.public ov99_021E6D34
	.public ov99_021E6F70
	.public ov99_021E6FA0
	.public ov99_021E6FD0
	.public ov99_021E7100
	.public ov99_021E7124
	.public ov99_021E7158
	.public ov99_021E71B0
	.public ov99_021E71E4
	.public ov99_021E7208
	.public ov99_021E7258
	.public ov99_021E728C
	.public ov99_021E72C0
	.public ov99_021E738C
	.public ov99_021E73E0
	.public ov99_021E7428
	.public ov99_021E7450
	.public ov99_021E7508
	.public ov99_021E7598
	.public ov99_021E76D8
	.public ov99_021E7758
	.public ov99_021E7794
	.public ov99_021E77D8
	.public ov99_021E7A54
	.public ov99_021E7A78
	.public ov99_021E7AB8
	.public ov99_021E7AD4
	.public ov99_021E7BC8
	.public ov99_021E7C58
	.public ov99_021E7CE4
	.public ov99_021E7D30
	.public ov99_021E7DA4
	.public ov99_021E7EBC
	.public ov99_021E7EF0
	.public ov99_021E7F64
	.public ov99_021E7F90
	.public ov99_021E80D0
	.public ov99_021E810C
	.public ov99_021E8198
	.public ov99_021E8224
	.public ov99_021E82E4
	.public ov99_021E84EC
	.public ov99_021E8518
	.public ov99_021E8544
	.public ov99_021E856C
	.public ov99_021E8590
	.public ov99_021E860C
	.public ov99_021E86D4
	.public ov99_021E875C
	.public ov99_021E8788
	.public ov99_021E87D0
	.public ov99_021E8828
	.public ov99_021E88EC
	.public ov99_021E89A4
	.public ov99_021E89EC
	.public ov99_021E8C04
	.public ov99_021E8C50
	.public ov99_021E8C88
	.public ov99_021E8D5C
	.public ov99_021E8D88
	.public ov99_021E8EBC
	.public ov99_021E8F50
	.public ov99_021E8FEC
	.public ov99_021E9038
	.public ov99_021E90F4
	.public ov99_021E92EC
	.public ov99_021E93DC
	.public ov99_021E9430
	.public ov99_021E9464
	.public ov99_021E94CC
	.public ov99_021E9518
	.public ov99_021E9554
	.public ov99_021E9564
	.public ov99_021E9574
	.public ov99_021E9576
	.public ov99_021E958C
	.public ov99_021E95A4
	.public ov99_021E95BC
	.public ov99_021E95D8
	.public ov99_021E95DC
	.public ov99_021E9600
	.public ov99_021E9628
	.public ov99_021E9650
	.public ov99_021E9690
	.public ov99_021E96D8
	.public ov99_021E9760
	.public ov99_021E9840
	.public ov99_021E9D88
	.public ov99_021E9D8C
	.public ov99_021E9D9C
	.public ov99_021E9DAC
	.public ov99_021E9DBC
	.public ov99_021E9DD4
	.public ov99_021E9DEC
	.public ov99_021E9E04
	.public ov99_021E9E2C
	.public ov99_021E9E60
	.public ov99_021E9ED0
	.public ov99_021E9F4C
	.public ov99_021E9F54
	.public ov99_021E9F60
	.public ov99_021E9F70
	.public ov99_021E9F80
	.public ov99_021E9F90
	.public ov99_021E9FA0
	.public ov99_021E9FB0
	.public ov99_021E9FC4
	.public ov99_021E9FDC
	.public ov99_021EA03C
	.public ov99_021EA0BC
	.public ov99_021EA180
	.public ov99_021EA250
	.public ov99_021EA348
	.public ov99_021EA350
	.public ov99_021EA35A
	.public ov99_021EA364
	.public ov99_021EA374
	.public ov99_021EA384
	.public ov99_021EA38C
	.public ov99_021EA394
	.public ov99_021EA3AC
	.public ov99_021EA3C4
	.public ov99_021EA3F4
	.public ov99_021EA45C
	.public ov99_021EA4F4
	.public ov99_021EA59C

	.public ov99_021E5B54
	.public ov99_021E5B70
	.public ov99_021E5B74
	.public ov99_021E5B7C
	.public ov99_021E6C14
	.public ov99_021E7060
	.public ov99_021E7068
	.public ov99_021E7078
	.public ov99_021E7088
	.public ov99_021E7098
	.public ov99_021E70A8
	.public ov99_021E70B8
	.public ov99_021E70C8
	.public ov99_021E70D8
	.public ov99_021E70E8
	.public ov99_021E714C
	.public ov99_021E7150
	.public ov99_021E7180
	.public ov99_021E718C
	.public ov99_021E7198
	.public ov99_021E71DC
	.public ov99_021E723C
	.public ov99_021E724C
	.public ov99_021E7CA8
	.public ov99_021E7CC8
	.public ov99_021E7CCC
	.public ov99_021E7CD8
	.public ov99_021E8818
	.public ov99_021E88D4
	.public ov99_021E9020
	.public ov99_021E9418
	.public ov99_021E945C
	.public ov99_021E94FC
	.public ov99_021E9508

	thumb_func_start ov99_021E88EC
ov99_021E88EC: ; 0x021E88EC
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r0, #0
	ldr r0, _021E89A0 ; =0x0000FFFF
	add r4, r1, #0
	add r6, r2, #0
	cmp r4, r0
	bne _021E8900
	bl GF_AssertFail
_021E8900:
	mov r0, #0xac
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bne _021E8944
	add r0, r4, #0
	mov r1, #0x1e
	bl _s32_div_f
	add r1, r0, #0
	lsl r1, r1, #0x18
	ldr r0, [r5, #0x10]
	lsr r1, r1, #0x18
	mov r2, #3
	mov r3, #0
	bl ov98_0221EDA4
	add r0, r4, #0
	mov r1, #0x1e
	bl _s32_div_f
	mov r0, #0xa
	mul r0, r1
	mov r1, #0x1e
	bl _s32_div_f
	add r1, r0, #0
	lsl r1, r1, #0x18
	mov r2, #1
	ldr r0, [r5, #0x10]
	lsr r1, r1, #0x18
	add r3, r2, #0
	bl ov98_0221EDA4
	b _021E8984
_021E8944:
	cmp r0, #6
	ldr r0, [r5, #0x10]
	bne _021E897A
	lsr r1, r4, #0xa
	mov r2, #3
	mov r3, #0
	bl ov98_0221EDA4
	lsr r3, r4, #0x1f
	lsl r2, r4, #0x16
	sub r2, r2, r3
	mov r1, #0x16
	ror r2, r1
	add r2, r3, r2
	add r3, r2, #0
	mov r1, #0xa
	mul r3, r1
	asr r1, r3, #9
	lsr r1, r1, #0x16
	add r1, r3, r1
	mov r2, #1
	ldr r0, [r5, #0x10]
	asr r1, r1, #0xa
	add r3, r2, #0
	bl ov98_0221EDA4
	b _021E8984
_021E897A:
	add r1, r4, #0
	mov r2, #3
	mov r3, #0
	bl ov98_0221EDA4
_021E8984:
	ldr r0, [sp, #0x18]
	mov r2, #0xac
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldrsb r2, [r5, r2]
	ldr r0, [r5, #0x10]
	add r1, r6, #0
	add r2, #0x56
	mov r3, #0
	bl ov98_0221ED48
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021E89A0: .word 0x0000FFFF
	thumb_func_end ov99_021E88EC


	thumb_func_start ov99_021E89A4
ov99_021E89A4: ; 0x021E89A4
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	mov r1, #0
	add r2, r4, #0
	str r1, [sp]
	add r2, #0xb0
	ldr r2, [r2]
	ldr r0, [r4, #0x10]
	lsl r3, r2, #2
	ldr r2, _021E89E4 ; =ov99_021EA384
	ldr r2, [r2, r3]
	mov r3, #1
	bl ov98_0221EC08
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, [r4, #0x10]
	add r4, #0xb0
	ldr r2, [r4]
	mov r1, #1
	lsl r3, r2, #2
	ldr r2, _021E89E8 ; =ov99_021EA38C
	ldr r2, [r2, r3]
	add r3, r1, #0
	bl ov98_0221EBEC
	add sp, #8
	pop {r4, pc}
	nop
_021E89E4: .word ov99_021EA384
_021E89E8: .word ov99_021EA38C
	thumb_func_end ov99_021E89A4


	thumb_func_start ov99_021E89EC
ov99_021E89EC: ; 0x021E89EC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, [r5, #0x10]
	bl ov98_0221EEFC
	add r2, r5, #0
	add r2, #0xac
	ldrb r2, [r2]
	mov r1, #0
	bl BufferPokeathlonEventName
	mov r3, #1
	str r3, [sp]
	ldr r0, [r5, #0x10]
	mov r1, #2
	mov r2, #0x3e
	bl ov98_0221EC08
	mov r0, #1
	str r0, [sp]
	mov r3, #0
	str r3, [sp, #4]
	mov r2, #0xac
	ldrsb r2, [r5, r2]
	ldr r0, [r5, #0x10]
	mov r1, #5
	add r2, #0x41
	bl ov98_0221EBEC
	ldr r0, [r5, #0x10]
	bl ov98_0221EEFC
	add r1, r5, #0
	add r1, #0xac
	add r2, r5, #0
	add r2, #0xb0
	add r4, r0, #0
	ldrb r1, [r1]
	ldr r0, [r5]
	ldr r2, [r2]
	bl ov99_021E94FC
	add r2, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0
	mov r3, #7
	bl BufferIntegerAsString
	mov r0, #0
	str r0, [sp]
	ldr r0, [r5, #0x10]
	mov r1, #3
	mov r2, #0x36
	mov r3, #1
	bl ov98_0221EC08
	mov r4, #0
	add r7, r4, #0
_021E8A68:
	cmp r4, #0
	bne _021E8A7A
	add r0, r5, #0
	add r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	bne _021E8A7A
	mov r6, #1
	b _021E8A7C
_021E8A7A:
	mov r6, #0
_021E8A7C:
	lsl r1, r4, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl ov99_021E8544
	cmp r0, #0
	bne _021E8AB2
	mov r1, #0xac
	add r3, r5, #0
	add r3, #0xb0
	lsl r2, r4, #0x18
	ldrsb r1, [r5, r1]
	ldr r0, [r5]
	ldr r3, [r3]
	lsr r2, r2, #0x18
	bl ov99_021E94CC
	add r1, r0, #0
	str r6, [sp]
	mov r3, #0xac
	ldrsb r3, [r5, r3]
	add r0, r5, #0
	add r2, r4, #7
	add r3, #0x56
	bl ov99_021E88EC
	b _021E8ACA
_021E8AB2:
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	str r7, [sp, #4]
	mov r2, #0xac
	ldrsb r2, [r5, r2]
	ldr r0, [r5, #0x10]
	add r1, r4, #7
	add r2, #0x60
	add r3, r7, #0
	bl ov98_0221EBEC
_021E8ACA:
	add r4, r4, #1
	cmp r4, #5
	blt _021E8A68
	add r0, r5, #0
	add r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	beq _021E8B2A
	ldr r0, [r5, #0x10]
	mov r1, #6
	mov r2, #0x4b
	mov r3, #0
	bl ov98_0221EBD8
	add r0, r5, #0
	bl ov99_021E9020
	mov r4, #0
	mov r6, #1
	add r7, r4, #0
_021E8AF2:
	lsl r1, r4, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl ov99_021E8544
	cmp r0, #0
	bne _021E8B20
	add r1, r5, #0
	add r1, #0xac
	ldrb r1, [r1]
	lsl r2, r4, #0x18
	ldr r0, [r5]
	lsr r2, r2, #0x18
	bl ov99_021E9518
	add r1, r4, #0
	str r6, [sp]
	add r2, r0, #0
	ldr r0, [r5, #0x10]
	add r1, #0xc
	add r3, r7, #0
	bl ov98_0221EE9C
_021E8B20:
	add r4, r4, #1
	cmp r4, #5
	blt _021E8AF2
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021E8B2A:
	mov r0, #0xac
	ldrsb r1, [r5, r0]
	lsl r0, r1, #2
	add r0, r5, r0
	add r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	beq _021E8B4C
	ldr r0, [r5, #0x10]
	mov r1, #0x11
	bl ov98_0221EE84
	ldr r0, [r5, #0x10]
	mov r1, #0x12
	bl ov98_0221EE84
	b _021E8B76
_021E8B4C:
	lsl r1, r1, #0x18
	ldr r0, [r5]
	lsr r1, r1, #0x18
	bl ov99_021E82E4
	add r3, r0, #0
	mov r0, #3
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [r5, #0x10]
	mov r1, #0x11
	mov r2, #0x6b
	bl ov98_0221ECD0
	ldr r0, [r5, #0x10]
	mov r1, #0x12
	mov r2, #0x6a
	mov r3, #0
	bl ov98_0221EBD8
_021E8B76:
	mov r0, #0xac
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _021E8B86
	ldr r0, [r5, #0x10]
	mov r1, #6
	bl ov98_0221EE84
_021E8B86:
	ldr r0, [r5]
	bl ov99_021E945C
	cmp r0, #0
	bne _021E8BC8
	mov r0, #0xac
	ldrsb r0, [r5, r0]
	lsl r0, r0, #2
	add r0, r5, r0
	add r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	beq _021E8BB0
	ldr r0, [r5, #0x10]
	mov r1, #6
	mov r2, #0x6d
	mov r3, #0
	bl ov98_0221EBD8
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021E8BB0:
	ldr r0, [r5]
	bl ov99_021E9508
	str r0, [sp]
	ldr r0, [r5, #0x10]
	mov r1, #6
	mov r2, #0x6c
	mov r3, #0
	bl ov98_0221EDC4
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021E8BC8:
	mov r1, #0xac
	ldrsb r1, [r5, r1]
	add r0, r5, #0
	bl ov99_021E84EC
	cmp r0, #0
	beq _021E8BEE
	ldr r0, [r5]
	bl ov99_021E9508
	str r0, [sp]
	ldr r0, [r5, #0x10]
	mov r1, #6
	mov r2, #0x6c
	mov r3, #0
	bl ov98_0221EDC4
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021E8BEE:
	mov r2, #0xac
	ldrsb r2, [r5, r2]
	ldr r0, [r5, #0x10]
	mov r1, #6
	add r2, #0x4c
	mov r3, #0
	bl ov98_0221EBD8
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov99_021E89EC


	thumb_func_start ov99_021E8C04
ov99_021E8C04: ; 0x021E8C04
	push {r3, r4, r5, lr}
	sub sp, #0x18
	ldr r5, _021E8C4C ; =ov99_021EA3AC
	add r3, sp, #0
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r1, r2, #0
	ldr r0, [r4, #0xc]
	mov r2, #0x25
	bl ov98_0221E5E0
	str r0, [r4, #0x14]
	add r0, r4, #0
	bl ov99_021E8C88
	add r0, r4, #0
	bl ov99_021E8D5C
	add r0, r4, #0
	bl ov99_021E8D88
	add r0, r4, #0
	bl ov99_021E8EBC
	add r0, r4, #0
	bl ov99_021E8C50
	add sp, #0x18
	pop {r3, r4, r5, pc}
	nop
_021E8C4C: .word ov99_021EA3AC
	thumb_func_end ov99_021E8C04


	thumb_func_start ov99_021E8C50
ov99_021E8C50: ; 0x021E8C50
	push {r3, r4, r5, lr}
	add r4, r0, #0
	add r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	beq _021E8C60
	mov r5, #0
	b _021E8C76
_021E8C60:
	mov r0, #0xac
	ldrsb r0, [r4, r0]
	lsl r0, r0, #2
	add r0, r4, r0
	add r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	bne _021E8C74
	mov r5, #1
	b _021E8C76
_021E8C74:
	mov r5, #0
_021E8C76:
	add r0, r4, #0
	bl ov99_021E8F50
	ldr r0, [r4, #0x1c]
	add r1, r5, #0
	bl ManagedSprite_SetDrawFlag
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov99_021E8C50


	thumb_func_start ov99_021E8C88
ov99_021E8C88: ; 0x021E8C88
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x14]
	bl ov98_0221E5C0
	add r4, r0, #0
	ldr r0, [r5, #0x14]
	bl ov98_0221E5D0
	add r6, r0, #0
	mov r3, #1
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r3, #0
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #2
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #3
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0xc
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r1, #1
	str r1, [sp]
	mov r0, #2
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0xd
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0xe
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r2, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0xf
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x14]
	ldr r1, _021E8D58 ; =ov99_021EA364
	mov r2, #0xf
	mov r3, #0
	bl ov98_0221E8A8
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E8D58: .word ov99_021EA364
	thumb_func_end ov99_021E8C88


	thumb_func_start ov99_021E8D5C
ov99_021E8D5C: ; 0x021E8D5C
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	ldr r4, _021E8D84 ; =ov99_021EA3F4
	mov r6, #0
	add r5, r7, #0
_021E8D66:
	ldr r0, [r7, #0x14]
	add r1, r4, #0
	bl ov98_0221E6E0
	mov r1, #1
	str r0, [r5, #0x18]
	bl ManagedSprite_SetAnimateFlag
	add r6, r6, #1
	add r4, #0x34
	add r5, r5, #4
	cmp r6, #2
	blt _021E8D66
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E8D84: .word ov99_021EA3F4
	thumb_func_end ov99_021E8D5C


	thumb_func_start ov99_021E8D88
ov99_021E8D88: ; 0x021E8D88
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x60
	add r5, r0, #0
	mov r0, #0
	add r2, sp, #0x2c
	add r1, r0, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [sp, #0x20]
	str r0, [r2]
	str r0, [sp, #0x18]
	mov r0, #0x48
	str r0, [sp, #0x14]
	mov r0, #6
	str r0, [sp, #0x10]
_021E8DAE:
	mov r0, #0
	str r0, [sp, #0x1c]
	mov r0, #0x20
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	mov r7, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	str r0, [sp, #8]
	ldr r0, [sp, #0x14]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	str r0, [sp, #0x24]
_021E8DCC:
	ldr r1, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	mov r2, #0x18
	add r0, r1, r0
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r0, _021E8EB8 ; =ov99_021EA394
	add r1, sp, #0x40
	bl MI_CpuCopy8
	mov r0, #1
	str r0, [sp, #0x3c]
	ldr r1, [sp, #0xc]
	add r0, sp, #0x2c
	strh r1, [r0]
	ldr r1, [sp, #0x24]
	strh r1, [r0, #2]
	mov r0, #0
	str r0, [sp, #0x34]
	mov r1, #0x10
	add r0, sp, #0x2c
	strh r1, [r0, #6]
	add r0, r4, #0
	add r0, #0xc
	lsl r0, r0, #2
	add r6, r5, r0
	ldr r0, [r5, #0x14]
	add r1, sp, #0x2c
	bl ov98_0221E6E0
	str r0, [r6, #0x18]
	lsl r0, r4, #2
	str r0, [sp, #0x28]
	add r0, r5, r0
	add r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	bne _021E8E1C
	mov r1, #1
	b _021E8E1E
_021E8E1C:
	mov r1, #0
_021E8E1E:
	ldr r0, [r6, #0x18]
	bl ManagedSprite_SetDrawFlag
	mov r0, #1
	str r0, [sp, #0x34]
	mov r1, #4
	add r0, sp, #0x2c
	strh r1, [r0, #6]
	add r0, r4, #2
	lsl r0, r0, #2
	add r6, r5, r0
	ldr r0, [r5, #0x14]
	add r1, sp, #0x2c
	bl ov98_0221E6E0
	lsl r1, r4, #0x18
	str r0, [r6, #0x18]
	add r0, r5, #0
	asr r1, r1, #0x18
	mov r2, #1
	bl ov99_021E8518
	add r1, r0, #0
	ldr r0, [r6, #0x18]
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r6, #0x18]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	ldr r0, [sp, #0x28]
	add r0, r5, r0
	add r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	bne _021E8E6A
	mov r0, #1
	b _021E8E6C
_021E8E6A:
	mov r0, #0
_021E8E6C:
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	lsl r2, r7, #0x10
	lsr r2, r2, #0x10
	lsl r2, r2, #0x10
	ldr r3, [sp, #8]
	add r0, r5, #0
	add r1, r4, #0
	asr r2, r2, #0x10
	bl ov99_021E86D4
	ldr r0, [sp, #0xc]
	add r7, r7, #6
	add r0, #0x30
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #5
	blo _021E8DCC
	ldr r0, [sp, #0x18]
	add r0, r0, #5
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r0, #0x40
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, #8
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x20]
	add r0, r0, #1
	str r0, [sp, #0x20]
	cmp r0, #2
	bhs _021E8EB4
	b _021E8DAE
_021E8EB4:
	add sp, #0x60
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E8EB8: .word ov99_021EA394
	thumb_func_end ov99_021E8D88


	thumb_func_start ov99_021E8EBC
ov99_021E8EBC: ; 0x021E8EBC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x48
	add r6, r0, #0
	mov r0, #0
	add r2, sp, #0x14
	add r1, r0, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [sp, #0xc]
	str r0, [r2]
	str r0, [sp, #8]
	str r0, [sp, #4]
	mov r0, #0x2c
	str r0, [sp]
_021E8EE0:
	ldr r0, [sp]
	mov r4, #0
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	mov r5, #0x3c
	str r0, [sp, #0x10]
_021E8EEC:
	ldr r0, [sp, #8]
	add r0, r4, r0
	add r1, r0, #2
	str r1, [sp, #0x28]
	mov r1, #2
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
	str r1, [sp, #0x34]
	str r1, [sp, #0x24]
	ldr r1, [sp, #4]
	add r0, #0x16
	add r2, r5, r1
	add r1, sp, #0x14
	strh r2, [r1]
	ldr r2, [sp, #0x10]
	lsl r0, r0, #2
	strh r2, [r1, #2]
	mov r1, #3
	sub r1, r1, r4
	str r1, [sp, #0x1c]
	add r7, r6, r0
	ldr r0, [r6, #0x14]
	add r1, sp, #0x14
	bl ov98_0221E6E0
	mov r1, #1
	str r0, [r7, #0x18]
	bl ManagedSprite_SetAnimateFlag
	add r4, r4, #1
	add r5, #0x18
	cmp r4, #3
	blo _021E8EEC
	ldr r0, [sp, #8]
	add r0, r0, #3
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r0, #8
	str r0, [sp, #4]
	ldr r0, [sp]
	add r0, #0x20
	str r0, [sp]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #5
	blo _021E8EE0
	add sp, #0x48
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov99_021E8EBC


	thumb_func_start ov99_021E8F50
ov99_021E8F50: ; 0x021E8F50
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	mov r7, #0
	add r5, r0, #0
	str r7, [sp, #8]
_021E8F5A:
	mov r1, #0xac
	add r3, r5, #0
	add r3, #0xb0
	lsl r2, r7, #0x18
	ldrsb r1, [r5, r1]
	ldr r0, [r5]
	ldr r3, [r3]
	lsr r2, r2, #0x18
	bl ov99_021E94CC
	ldr r1, _021E8FE8 ; =0x0000FFFF
	cmp r0, r1
	beq _021E8FD6
	mov r4, #0
_021E8F76:
	mov r1, #0
	add r0, sp, #0xc
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [sp, #8]
	str r4, [sp]
	add r6, r4, r0
	add r0, r5, #0
	add r0, #0xb0
	ldr r0, [r0]
	mov r2, #0xac
	str r0, [sp, #4]
	ldrsb r2, [r5, r2]
	ldr r0, [r5]
	add r1, sp, #0xc
	add r3, r7, #0
	add r6, #0x16
	bl ov99_021E9464
	ldr r0, [sp, #0xc]
	lsl r0, r0, #0x17
	lsr r0, r0, #0x17
	beq _021E8FD0
	lsl r0, r6, #2
	add r6, r5, r0
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x14]
	ldr r1, [r6, #0x18]
	add r2, sp, #0xc
	mov r3, #0
	bl ov98_0221E970
	ldr r0, [r6, #0x18]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	cmp r7, #0
	bne _021E8FD0
	mov r1, #6
	ldr r0, [r6, #0x18]
	lsl r1, r1, #0xa
	bl ManagedSprite_SetAnimSpeed
_021E8FD0:
	add r4, r4, #1
	cmp r4, #3
	blt _021E8F76
_021E8FD6:
	ldr r0, [sp, #8]
	add r7, r7, #1
	add r0, r0, #3
	str r0, [sp, #8]
	cmp r7, #5
	blt _021E8F5A
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E8FE8: .word 0x0000FFFF
	thumb_func_end ov99_021E8F50


	thumb_func_start ov99_021E8FEC
ov99_021E8FEC: ; 0x021E8FEC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	mov r4, #0
	str r0, [sp]
	add r7, r1, #0
	str r4, [sp, #4]
_021E8FF8:
	ldr r0, [sp]
	lsl r1, r4, #2
	mov r6, #0
	add r5, r0, r1
_021E9000:
	ldr r0, [r5, #0x70]
	add r1, r7, #0
	bl ManagedSprite_SetDrawFlag
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #3
	blt _021E9000
	ldr r0, [sp, #4]
	add r4, r4, #3
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #5
	blt _021E8FF8
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov99_021E8FEC
