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
	.public PokeathlonMedals_Exit
	.public ov99_021E7258
	.public ov99_021E728C
	.public ov99_021E7428
	.public ov99_021E7758
	.public ov99_021E7794
	.public ov99_021E77D8
	.public ov99_021E7AB8
	.public ov99_021E7C58
	.public ov99_021E7450
	.public ov99_021E76D8




	thumb_func_start ov99_021E7508
ov99_021E7508: ; 0x021E7508
	push {r3, r4, r5, lr}
	add r4, r0, #0
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r2, [r4, r0]
	mov r1, #0
	lsl r0, r2, #0x1b
	lsr r0, r0, #0x1b
	beq _021E7522
	lsl r2, r2, #0xd
	lsr r2, r2, #0x1b
	beq _021E7522
	mov r1, #1
_021E7522:
	cmp r0, #0
	beq _021E7538
	mov r2, #0xfd
	lsl r2, r2, #2
	ldr r2, [r4, r2]
	lsl r2, r2, #0xd
	lsr r2, r2, #0x1b
	cmp r2, r0
	bhs _021E7538
	mov r5, #1
	b _021E753A
_021E7538:
	mov r5, #0
_021E753A:
	ldr r0, _021E7594 ; =0x0000040C
	ldr r0, [r4, r0]
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x41
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r1, r5, #0
	bl ManagedSprite_SetDrawFlag
	mov r1, #1
	lsl r1, r1, #0xa
	ldr r0, [r4, r1]
	sub r1, #0xc
	ldr r1, [r4, r1]
	mov r2, #2
	lsl r1, r1, #0xd
	lsr r1, r1, #0x1b
	add r1, r1, #1
	mov r3, #0
	bl ov98_0221EDA4
	mov r1, #1
	lsl r1, r1, #0xa
	ldr r0, [r4, r1]
	sub r1, #0xc
	ldr r1, [r4, r1]
	mov r2, #2
	lsl r1, r1, #0x1b
	lsr r1, r1, #0x1b
	add r1, r1, #1
	mov r3, #1
	bl ov98_0221EDA4
	mov r3, #0
	mov r0, #1
	str r3, [sp]
	lsl r0, r0, #0xa
	ldr r0, [r4, r0]
	mov r1, #3
	mov r2, #0x81
	bl ov98_0221ED48
	pop {r3, r4, r5, pc}
	nop
_021E7594: .word 0x0000040C
	thumb_func_end ov99_021E7508








	thumb_func_start ov99_021E7598
ov99_021E7598: ; 0x021E7598
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	lsl r0, r0, #4
	lsr r0, r0, #0x1f
	beq _021E75AE
	mov r0, #1
	b _021E75B2
_021E75AE:
	mov r0, #0
	mvn r0, r0
_021E75B2:
	lsl r0, r0, #6
	str r0, [sp]
	mov r0, #0xfe
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bne _021E75E6
	add r0, r0, #4
	ldr r0, [r5, r0]
	bl GridInputHandler_GetNextInput
	add r4, r0, #0
	add r0, r5, #0
	bl ov99_021E7508
	cmp r4, #0x1e
	bne _021E75DE
	add r0, r5, #0
	bl ov99_021E77D8
	b _021E7636
_021E75DE:
	add r0, r5, #0
	bl ov99_021E7794
	b _021E7636
_021E75E6:
	cmp r1, #4
	bne _021E7636
	add r0, r5, #0
	bl ov99_021E7450
	mov r6, #0
	add r4, r5, #0
_021E75F4:
	mov r0, #0xfe
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r2, sp, #4
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	add r7, r1, #0
	ldr r0, [sp]
	add r1, sp, #4
	mul r7, r0
	ldr r0, _021E76D4 ; =0x00000458
	add r1, #2
	ldr r0, [r4, r0]
	bl ManagedSprite_GetPositionXY
	ldr r0, _021E76D4 ; =0x00000458
	add r2, sp, #4
	mov r1, #2
	ldrsh r2, [r2, r1]
	lsl r1, r7, #1
	add r3, sp, #4
	sub r1, r2, r1
	mov r2, #0
	lsl r1, r1, #0x10
	ldrsh r2, [r3, r2]
	ldr r0, [r4, r0]
	asr r1, r1, #0x10
	bl ManagedSprite_SetPositionXY
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #0x1e
	blt _021E75F4
_021E7636:
	mov r0, #0xfe
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #8
	bhs _021E7680
	ldr r0, [sp]
	mov r1, #2
	neg r4, r0
	ldr r0, [r5]
	mov r2, #1
	add r3, r4, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5]
	mov r1, #3
	mov r2, #1
	add r3, r4, #0
	bl ScheduleSetBgPosText
	ldr r0, [sp]
	mov r6, #0
	lsl r0, r0, #0x10
	add r4, r5, #0
	asr r7, r0, #0x10
_021E766A:
	ldr r0, _021E76D4 ; =0x00000458
	add r1, r7, #0
	ldr r0, [r4, r0]
	mov r2, #0
	bl ManagedSprite_OffsetPositionXY
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #0x1e
	blt _021E766A
	b _021E76B4
_021E7680:
	mov r2, #0
	ldr r0, [r5]
	mov r1, #2
	add r3, r2, #0
	bl ScheduleSetBgPosText
	mov r2, #0
	ldr r0, [r5]
	mov r1, #3
	add r3, r2, #0
	bl ScheduleSetBgPosText
	mov r1, #0xfe
	lsl r1, r1, #2
	ldr r2, [r5, r1]
	mov r0, #0xff
	bic r2, r0
	str r2, [r5, r1]
	add r1, #0x10
	ldr r0, [r5, r1]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E76B4:
	mov r2, #0xfe
	lsl r2, r2, #2
	ldr r3, [r5, r2]
	mov r1, #0xff
	add r0, r3, #0
	bic r0, r1
	lsl r1, r3, #0x18
	lsr r1, r1, #0x18
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	orr r0, r1
	str r0, [r5, r2]
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E76D4: .word 0x00000458
	thumb_func_end ov99_021E7598
