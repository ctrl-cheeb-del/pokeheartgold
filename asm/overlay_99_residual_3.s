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

	thumb_func_start ov99_021E6C30
ov99_021E6C30: ; 0x021E6C30
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x48
	str r0, [sp]
	ldr r0, [sp, #0x64]
	add r5, r2, #0
	str r0, [sp, #0x64]
	ldr r0, [sp, #0x6c]
	str r1, [sp, #4]
	str r0, [sp, #0x6c]
	mov r0, #0
	add r2, sp, #0x14
	add r1, r0, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [r2]
	ldr r0, [sp, #4]
	add r7, r3, #0
	bl ov98_0221F150
	mov r4, #0
	cmp r7, #0
	bls _021E6CE6
	add r1, sp, #0x50
	ldrb r2, [r1, #0x18]
	sub r0, r7, r0
	lsl r3, r5, #2
	str r2, [sp, #8]
	ldr r2, [sp]
	add r6, r4, #0
	add r5, r2, r3
	mov r2, #0x10
	ldrsh r1, [r1, r2]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
_021E6C7C:
	sub r1, r7, r4
	lsl r1, r1, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	bl ov98_0221F120
	add r1, sp, #0x14
	strh r0, [r1, #6]
	ldr r0, [sp, #0x6c]
	cmp r0, #0
	beq _021E6C96
	ldr r0, _021E6CEC ; =ov99_021E9DBC
	b _021E6C98
_021E6C96:
	ldr r0, _021E6CF0 ; =ov99_021E9DD4
_021E6C98:
	add r1, sp, #0x28
	mov r2, #0x18
	bl MI_CpuCopy8
	ldr r0, [sp, #0x6c]
	cmp r0, #0
	beq _021E6CAA
	mov r0, #1
	b _021E6CAC
_021E6CAA:
	mov r0, #2
_021E6CAC:
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x10]
	add r1, r0, r6
	add r0, sp, #0x14
	strh r1, [r0]
	ldr r1, [sp, #0x64]
	strh r1, [r0, #2]
	ldr r0, [sp]
	add r1, sp, #0x14
	ldr r0, [r0, #0x14]
	bl ov98_0221E6E0
	mov r1, #1
	str r0, [r5, #0x18]
	bl ManagedSprite_SetAnimateFlag
	ldr r0, [sp, #0xc]
	cmp r0, r4
	bls _021E6CDA
	ldr r0, [r5, #0x18]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_021E6CDA:
	ldr r0, [sp, #8]
	add r4, r4, #1
	add r6, r6, r0
	add r5, r5, #4
	cmp r4, r7
	blo _021E6C7C
_021E6CE6:
	add sp, #0x48
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6CEC: .word ov99_021E9DBC
_021E6CF0: .word ov99_021E9DD4
	thumb_func_end ov99_021E6C30


	thumb_func_start ov99_021E6CF4
ov99_021E6CF4: ; 0x021E6CF4
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0x28
	bls _021E6D02
	bl GF_AssertFail
_021E6D02:
	lsr r2, r4, #1
	ldr r0, [r5, #0x10]
	mov r1, #6
	add r2, #0x21
	mov r3, #0
	bl ov98_0221EBD8
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov99_021E6CF4


	thumb_func_start ov99_021E6D14
ov99_021E6D14: ; 0x021E6D14
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0xa
	bls _021E6D22
	bl GF_AssertFail
_021E6D22:
	add r4, #0x11
	ldr r0, [r5, #0x10]
	mov r1, #9
	add r2, r4, #0
	mov r3, #0
	bl ov98_0221EBD8
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov99_021E6D14


	thumb_func_start ov99_021E6D34
ov99_021E6D34: ; 0x021E6D34
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	add r5, r0, #0
	ldr r0, [r5]
	bl ov99_021E70C8
	str r0, [sp, #0x1c]
	ldr r0, [r5]
	bl ov99_021E70B8
	str r0, [sp, #0x20]
	ldr r0, [r5]
	bl ov99_021E70A8
	str r0, [sp, #0x24]
	ldr r0, [r5]
	bl ov99_021E70D8
	str r0, [sp, #0x18]
	ldr r0, [r5]
	bl ov99_021E7088
	str r0, [sp, #0x28]
	add r0, r5, #0
	bl ov99_021E7124
	str r0, [sp, #0x14]
	ldr r0, [r5]
	bl ov99_021E7078
	bl ov98_0221EF80
	str r0, [sp, #0x10]
	ldr r0, [r5]
	bl ov99_021E7068
	add r7, r0, #0
	ldr r0, [sp, #0x18]
	bl ov99_021E7100
	add r4, r0, #0
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, r1, r0
	add r0, r7, r0
	add r0, r4, r0
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	ldr r0, [r5, #0x10]
	bl ov98_0221EEFC
	str r0, [sp, #0x2c]
	ldr r0, [r5]
	bl ov99_021E7098
	add r2, r0, #0
	ldr r0, [sp, #0x2c]
	mov r1, #0
	bl BufferPlayersName
	mov r1, #0
	str r1, [sp]
	ldr r0, [r5, #0x10]
	mov r2, #0xb
	mov r3, #1
	bl ov98_0221EC08
	ldr r0, [r5, #0x10]
	mov r1, #1
	mov r2, #0xc
	mov r3, #0
	bl ov98_0221EBD8
	ldr r0, [r5, #0x10]
	mov r1, #2
	mov r2, #0xd
	mov r3, #0
	bl ov98_0221EBD8
	ldr r0, [r5, #0x10]
	mov r1, #3
	mov r2, #0xe
	mov r3, #0
	bl ov98_0221EBD8
	ldr r0, [r5, #0x10]
	mov r1, #4
	mov r2, #0xf
	mov r3, #0
	bl ov98_0221EBD8
	mov r0, #0
	str r0, [sp]
	ldr r0, [r5, #0x10]
	mov r1, #5
	mov r2, #0x20
	mov r3, #2
	bl ov98_0221EC08
	mov r2, #0
	str r2, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, [r5, #0x10]
	mov r1, #7
	mov r3, #1
	bl ov98_0221EBEC
	add r0, r5, #0
	add r1, r6, #0
	bl ov99_021E6CF4
	ldr r0, [r5, #0x10]
	mov r1, #8
	mov r2, #0x10
	mov r3, #0
	bl ov98_0221EBD8
	ldr r0, [r5, #0x10]
	mov r1, #0xd
	mov r2, #0x1f
	mov r3, #0
	bl ov98_0221EBD8
	ldr r0, [r5, #0x10]
	mov r1, #0xe
	mov r2, #1
	mov r3, #0
	bl ov98_0221EBD8
	mov r0, #4
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [r5, #0x10]
	ldr r3, [sp, #0x1c]
	mov r1, #0xa
	mov r2, #0x1c
	bl ov98_0221ECD0
	mov r0, #4
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [r5, #0x10]
	ldr r3, [sp, #0x20]
	mov r1, #0xb
	mov r2, #0x1d
	bl ov98_0221ECD0
	mov r0, #4
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [r5, #0x10]
	ldr r3, [sp, #0x24]
	mov r1, #0xc
	mov r2, #0x1e
	bl ov98_0221ECD0
	add r0, r5, #0
	add r1, r4, #0
	bl ov99_021E6D14
	add r0, r5, #0
	bl ov99_021E6C14
	ldr r0, [sp, #0x28]
	cmp r0, #1
	bne _021E6E98
	ldr r0, [r5, #0x18]
	mov r1, #1
	bl ManagedSprite_SetAnim
	ldr r0, [r5, #0x18]
	mov r1, #1
	bl ManagedSprite_SetPaletteOverride
_021E6E98:
	mov r0, #0xc8
	str r0, [sp]
	mov r0, #0x70
	str r0, [sp, #4]
	mov r0, #0x20
	str r0, [sp, #8]
	mov r2, #1
	add r0, r5, #0
	add r1, r6, #0
	mov r3, #2
	str r2, [sp, #0xc]
	bl ov99_021E6C30
	mov r0, #0x50
	str r0, [sp]
	mov r0, #0xa0
	str r0, [sp, #4]
	mov r0, #0x20
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r1, [sp, #0x18]
	add r0, r5, #0
	mov r2, #3
	mov r3, #4
	bl ov99_021E6C30
	mov r0, #7
	str r0, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	mov r0, #0x28
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r1, r5, #0
	ldr r0, [r5, #0x14]
	ldr r2, _021E6F68 ; =ov99_021E9DAC
	ldr r3, [sp, #0x14]
	add r1, #0x18
	bl ov98_0221E6F0
	mov r0, #0x11
	str r0, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	mov r0, #0x48
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r1, r5, #0
	ldr r0, [r5, #0x14]
	ldr r2, _021E6F68 ; =ov99_021E9DAC
	ldr r3, [sp, #0x10]
	add r1, #0x18
	bl ov98_0221E6F0
	mov r0, #0x1b
	str r0, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	mov r0, #0x68
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r1, r5, #0
	ldr r0, [r5, #0x14]
	ldr r2, _021E6F68 ; =ov99_021E9DAC
	add r1, #0x18
	add r3, r7, #0
	bl ov98_0221E6F0
	mov r0, #0x25
	str r0, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	mov r0, #0x88
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r1, r5, #0
	ldr r0, [r5, #0x14]
	ldr r2, _021E6F68 ; =ov99_021E9DAC
	add r1, #0x18
	add r3, r4, #0
	bl ov98_0221E6F0
	mov r0, #0x39
	str r0, [sp]
	mov r0, #0x60
	str r0, [sp, #4]
	mov r0, #0x78
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x14]
	add r5, #0x18
	ldr r2, _021E6F6C ; =ov99_021E9D8C
	add r1, r5, #0
	add r3, r4, #0
	bl ov98_0221E6F0
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6F68: .word ov99_021E9DAC
_021E6F6C: .word ov99_021E9D8C
	thumb_func_end ov99_021E6D34


	thumb_func_start ov99_021E6F70
ov99_021E6F70: ; 0x021E6F70
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r4, _021E6F9C ; =0x00000000
	bne _021E6F7C
	bl GF_AssertFail
_021E6F7C:
	add r0, r5, #0
	bl PokeathlonSave_GetUnkAEC
	mov r2, #0
_021E6F84:
	lsl r1, r2, #1
	ldrh r1, [r0, r1]
	add r1, r4, r1
	lsl r1, r1, #0x10
	lsr r4, r1, #0x10
	add r1, r2, #1
	lsl r1, r1, #0x18
	lsr r2, r1, #0x18
	cmp r2, #0xa
	blo _021E6F84
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E6F9C: .word 0x00000000
	thumb_func_end ov99_021E6F70


	thumb_func_start ov99_021E6FA0
ov99_021E6FA0: ; 0x021E6FA0
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r5, _021E6FC8 ; =0x00000000
	bne _021E6FAC
	bl GF_AssertFail
_021E6FAC:
	ldr r7, _021E6FCC ; =0x000001ED
	mov r4, #0
_021E6FB0:
	ldrb r0, [r6, r4]
	bl MATH_CountPopulation
	add r0, r5, r0
	lsl r0, r0, #0x10
	add r4, r4, #1
	lsr r5, r0, #0x10
	cmp r4, r7
	blt _021E6FB0
	add r0, r5, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6FC8: .word 0x00000000
_021E6FCC: .word 0x000001ED
	thumb_func_end ov99_021E6FA0


	thumb_func_start ov99_021E6FD0
ov99_021E6FD0: ; 0x021E6FD0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r0, #0
	ldr r0, [r7, #0xc]
	add r5, r1, #0
	mov r1, #0x1c
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x1c
	add r4, r0, #0
	bl MI_CpuFill8
	ldr r0, [r5, #4]
	ldr r6, [r5]
	str r0, [sp, #8]
	add r0, r6, #0
	bl PokeathlonSave_dummy1
	add r5, r0, #0
	add r0, r6, #0
	bl PokeathlonSave_GetRecordsSolo
	str r0, [sp, #4]
	add r0, r6, #0
	bl PokeathlonSave_GetUnkDC
	str r0, [sp]
	mov r2, #0
	add r3, r4, #0
_021E700C:
	ldrh r1, [r5, #6]
	add r2, r2, #1
	add r5, #0x2c
	strh r1, [r3, #0xc]
	ldrh r0, [r4, #4]
	add r3, r3, #2
	add r0, r0, r1
	strh r0, [r4, #4]
	cmp r2, #5
	blt _021E700C
	ldr r0, [sp, #8]
	str r0, [r4]
	add r0, r6, #0
	bl ov99_021E6F70
	strh r0, [r4, #6]
	ldr r0, [sp]
	bl ov99_021E6FA0
	strh r0, [r4, #0xa]
	ldr r0, [sp]
	bl ov98_0221F024
	strb r0, [r4, #0x16]
	ldr r0, [sp, #4]
	bl ov98_0221F058
	strb r0, [r4, #0x17]
	ldrh r1, [r4, #4]
	ldrh r0, [r4, #6]
	ldrh r2, [r4, #0xa]
	add r0, r1, r0
	add r0, r2, r0
	strh r0, [r4, #8]
	ldr r0, [sp, #8]
	bl PlayerProfile_GetTrainerGender
	strb r0, [r4, #0x18]
	str r4, [r7]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov99_021E6FD0
