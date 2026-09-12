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
