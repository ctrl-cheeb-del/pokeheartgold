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

	thumb_func_start ov99_021E9038
ov99_021E9038: ; 0x021E9038
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	mov r0, #0
	str r0, [sp, #0x18]
	str r0, [sp, #0x10]
	mov r0, #6
	str r0, [sp, #0xc]
_021E9048:
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [sp, #0xc]
	mov r7, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	str r0, [sp, #8]
_021E905A:
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, r1, r0
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r5, #0
	add r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	beq _021E9072
	mov r6, #1
	b _021E9084
_021E9072:
	lsl r1, r4, #2
	add r1, r5, r1
	add r1, #0xbc
	ldr r1, [r1]
	cmp r1, #0
	bne _021E9082
	mov r6, #1
	b _021E9084
_021E9082:
	mov r6, #0
_021E9084:
	add r2, r4, #0
	add r2, #0xc
	cmp r0, #0
	beq _021E9090
	mov r1, #0
	b _021E9092
_021E9090:
	add r1, r6, #0
_021E9092:
	lsl r0, r2, #2
	add r0, r5, r0
	ldr r0, [r0, #0x18]
	bl ManagedSprite_SetDrawFlag
	lsl r1, r4, #0x18
	add r0, r5, #0
	asr r1, r1, #0x18
	mov r2, #1
	bl ov99_021E8518
	add r1, r0, #0
	lsl r0, r4, #2
	add r0, r5, r0
	ldr r0, [r0, #0x20]
	bl ManagedSprite_SetDrawFlag
	lsl r2, r7, #0x10
	lsr r2, r2, #0x10
	lsl r2, r2, #0x10
	str r6, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r3, [sp, #8]
	add r0, r5, #0
	add r1, r4, #0
	asr r2, r2, #0x10
	bl ov99_021E86D4
	ldr r0, [sp, #0x14]
	add r7, r7, #6
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, #5
	blo _021E905A
	ldr r0, [sp, #0x10]
	add r0, r0, #5
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	add r0, #8
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #2
	blo _021E9048
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov99_021E9038


	thumb_func_start ov99_021E90F4
ov99_021E90F4: ; 0x021E90F4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0xac
	ldrsb r4, [r5, r0]
	ldr r0, _021E92DC ; =gSystem + 0x40
	ldrh r0, [r0, #0x24]
	cmp r0, #0
	beq _021E9154
	ldr r0, _021E92E0 ; =ov99_021EA3C4
	bl TouchscreenHitbox_FindHitboxAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _021E9114
	b _021E923A
_021E9114:
	sub r1, r0, #1
	add r0, r5, #0
	add r0, #0xac
	strb r1, [r0]
	ldr r0, [r5, #0x18]
	mov r1, #0xb
	bl ManagedSprite_SetAnim
	ldr r0, _021E92E4 ; =0x000005DC
	bl PlaySE
	mov r0, #0xac
	ldrsb r1, [r5, r0]
	sub r0, #0xad
	cmp r1, r0
	bne _021E914A
	add r0, r5, #0
	mov r1, #1
	add r0, #0xb4
	str r1, [r0]
	ldr r0, [r5, #0x18]
	mov r1, #0xd
	bl ManagedSprite_SetAnim
	ldr r0, _021E92E4 ; =0x000005DC
	bl PlaySE
_021E914A:
	ldr r0, [r5, #0x18]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	b _021E923A
_021E9154:
	ldr r0, _021E92E8 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r1, r0
	beq _021E9176
	cmp r4, #0xa
	bne _021E9164
	b _021E92D8
_021E9164:
	sub r1, r0, #2
	cmp r4, r1
	bne _021E9176
	add r1, r5, #0
	add r1, #0xb4
	str r0, [r1]
	ldr r0, _021E92E4 ; =0x000005DC
	bl PlaySE
_021E9176:
	mov r0, #0xac
	ldrsb r1, [r5, r0]
	sub r0, #0xad
	cmp r1, r0
	bne _021E9196
	ldr r0, _021E92E8 ; =gSystem
	ldr r1, [r0, #0x40]
	mov r0, #0x80
	tst r0, r1
	beq _021E923A
	mov r0, #0xad
	ldrsb r1, [r5, r0]
	add r0, r5, #0
	add r0, #0xac
	strb r1, [r0]
	b _021E923A
_021E9196:
	cmp r1, #0xa
	bne _021E91B2
	ldr r0, _021E92E8 ; =gSystem
	ldr r1, [r0, #0x40]
	mov r0, #0x40
	tst r0, r1
	beq _021E923A
	mov r0, #0xad
	ldrsb r0, [r5, r0]
	add r1, r0, #5
	add r0, r5, #0
	add r0, #0xac
	strb r1, [r0]
	b _021E923A
_021E91B2:
	ldr r0, _021E92E8 ; =gSystem
	mov r2, #0x10
	ldr r0, [r0, #0x40]
	tst r2, r0
	beq _021E91C6
	add r0, r5, #0
	add r1, r1, #1
	add r0, #0xac
	strb r1, [r0]
	b _021E9202
_021E91C6:
	mov r2, #0x20
	tst r2, r0
	beq _021E91D6
	add r0, r5, #0
	sub r1, r1, #1
	add r0, #0xac
	strb r1, [r0]
	b _021E9202
_021E91D6:
	mov r2, #0x80
	tst r2, r0
	beq _021E91E6
	add r0, r5, #0
	add r1, r1, #5
	add r0, #0xac
	strb r1, [r0]
	b _021E9202
_021E91E6:
	mov r2, #0x40
	tst r0, r2
	beq _021E9202
	cmp r1, #0xa
	bne _021E91F4
	mov r1, #1
	b _021E91F6
_021E91F4:
	mov r1, #5
_021E91F6:
	mov r0, #0xac
	ldrsb r0, [r5, r0]
	sub r1, r0, r1
	add r0, r5, #0
	add r0, #0xac
	strb r1, [r0]
_021E9202:
	mov r1, #0xac
	ldrsb r2, [r5, r1]
	cmp r2, #0xa
	ble _021E920E
	mov r2, #0xa
	b _021E921A
_021E920E:
	add r0, r1, #0
	sub r0, #0xad
	cmp r2, r0
	bge _021E921A
	add r2, r1, #0
	sub r2, #0xad
_021E921A:
	add r0, r5, #0
	add r0, #0xac
	mov r1, #0xac
	strb r2, [r0]
	ldrsb r0, [r5, r1]
	sub r1, #0xad
	cmp r0, r1
	beq _021E923A
	cmp r0, #0xa
	beq _021E923A
	mov r1, #5
	bl _s32_div_f
	add r0, r5, #0
	add r0, #0xad
	strb r1, [r0]
_021E923A:
	mov r0, #0xac
	ldrsb r0, [r5, r0]
	cmp r4, r0
	beq _021E92D6
	ldr r0, _021E92E4 ; =0x000005DC
	bl PlaySE
	mov r0, #0xac
	ldrsb r1, [r5, r0]
	sub r0, #0xad
	cmp r1, r0
	bne _021E9266
	ldr r0, [r5, #0x18]
	mov r1, #0xe0
	mov r2, #0x10
	bl ManagedSprite_SetPositionXY
	ldr r0, [r5, #0x18]
	mov r1, #0xc
	bl ManagedSprite_SetAnim
	b _021E92D6
_021E9266:
	cmp r1, #0xa
	bne _021E927E
	ldr r0, [r5, #0x18]
	mov r1, #0xe0
	mov r2, #0xb0
	bl ManagedSprite_SetPositionXY
	ldr r0, [r5, #0x18]
	mov r1, #0xc
	bl ManagedSprite_SetAnim
	b _021E92D6
_021E927E:
	cmp r1, #5
	blt _021E9286
	mov r2, #1
	b _021E9288
_021E9286:
	mov r2, #0
_021E9288:
	cmp r2, #0
	beq _021E9292
	sub r0, r1, #5
	lsl r0, r0, #0x18
	asr r1, r0, #0x18
_021E9292:
	mov r3, #0x30
	mul r3, r1
	lsl r2, r2, #6
	add r3, #0x20
	add r2, #0x48
	lsl r1, r3, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r5, #0x18]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	ldr r0, [r5, #0x18]
	bl ManagedSprite_GetActiveAnim
	cmp r0, #0xb
	beq _021E92BC
	ldr r0, [r5, #0x18]
	mov r1, #0xa
	bl ManagedSprite_SetAnim
_021E92BC:
	cmp r4, #0xa
	bne _021E92C8
	mov r0, #0xac
	ldrsb r0, [r5, r0]
	cmp r0, #9
	beq _021E92D6
_021E92C8:
	add r0, r5, #0
	mov r1, #0
	bl ov99_021E8FEC
	mov r0, #1
	add r5, #0xb8
	str r0, [r5]
_021E92D6:
	mov r0, #0
_021E92D8:
	pop {r3, r4, r5, pc}
	nop
_021E92DC: .word gSystem + 0x40
_021E92E0: .word ov99_021EA3C4
_021E92E4: .word 0x000005DC
_021E92E8: .word gSystem
	thumb_func_end ov99_021E90F4


	thumb_func_start ov99_021E92EC
ov99_021E92EC: ; 0x021E92EC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	str r0, [sp]
	str r1, [sp, #4]
	add r0, r1, #0
	str r2, [sp, #8]
	add r1, r2, #0
	mov r2, #0x6e
	lsl r2, r2, #2
	bl MI_CpuCopy8
	ldr r1, _021E93D8 ; =ov99_021EA350
	mov r0, #0
	str r0, [sp, #0xc]
	ldrh r2, [r1, #4]
	add r0, sp, #0x20
	strh r2, [r0]
	ldrh r2, [r1, #6]
	ldrh r1, [r1, #8]
	strh r2, [r0, #2]
	strh r1, [r0, #4]
_021E9316:
	ldr r0, [sp, #0xc]
	mov r6, #0
	lsl r0, r0, #0x18
	ldr r4, [sp, #4]
	lsr r5, r0, #0x18
	add r7, r6, #0
_021E9322:
	ldrh r2, [r4]
	add r0, r5, #0
	add r1, r7, #0
	bl ov98_0221EFB4
	cmp r0, #0
	beq _021E9338
	add r6, r6, #1
	add r4, #8
	cmp r6, #5
	blt _021E9322
_021E9338:
	cmp r6, #0
	bne _021E9344
	ldr r0, [sp]
	mov r1, #1
	add r0, #0xbc
	str r1, [r0]
_021E9344:
	add r0, sp, #0x20
	ldrh r0, [r0]
	ldr r4, [sp, #8]
	ldr r5, [sp, #4]
	str r0, [sp, #0x10]
	add r0, sp, #0x20
	ldrh r0, [r0, #2]
	mov r7, #0
	str r0, [sp, #0x14]
	add r0, sp, #0x20
	ldrh r0, [r0, #4]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0xc]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x1c]
_021E9364:
	cmp r7, r6
	bne _021E938E
	ldr r1, [sp, #0x10]
	add r0, sp, #0x20
	strh r1, [r0, #6]
	ldr r1, [sp, #0x14]
	mov r2, #6
	strh r1, [r0, #8]
	ldr r1, [sp, #0x18]
	strh r1, [r0, #0xa]
	add r0, sp, #0x24
	add r0, #2
	add r1, r4, #2
	bl MI_CpuCopy8
	ldr r0, [sp, #0x1c]
	mov r1, #0
	bl ov98_0221EFA4
	strh r0, [r4]
	b _021E93AC
_021E938E:
	cmp r7, r6
	ble _021E93AC
	add r0, r5, #0
	sub r0, #8
	ldrh r0, [r0]
	strh r0, [r4]
	sub r0, r5, #6
	ldrh r0, [r0]
	strh r0, [r4, #2]
	sub r0, r5, #4
	ldrh r0, [r0]
	strh r0, [r4, #4]
	sub r0, r5, #2
	ldrh r0, [r0]
	strh r0, [r4, #6]
_021E93AC:
	add r7, r7, #1
	add r4, #8
	add r5, #8
	cmp r7, #5
	blt _021E9364
	ldr r0, [sp, #4]
	add r0, #0x2c
	str r0, [sp, #4]
	ldr r0, [sp]
	add r0, r0, #4
	str r0, [sp]
	ldr r0, [sp, #8]
	add r0, #0x2c
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #0xa
	blt _021E9316
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	nop
_021E93D8: .word ov99_021EA350
	thumb_func_end ov99_021E92EC


	thumb_func_start ov99_021E93DC
ov99_021E93DC: ; 0x021E93DC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	mov r1, #7
	ldr r0, [r5, #0xc]
	lsl r1, r1, #6
	bl Heap_Alloc
	mov r2, #7
	add r4, r0, #0
	mov r1, #0
	lsl r2, r2, #6
	bl MI_CpuFill8
	str r6, [r4]
	ldr r1, [r6]
	add r0, r5, #0
	add r2, r4, #4
	bl ov99_021E92EC
	ldr r1, [r5, #0xc]
	mov r0, #8
	bl String_New
	mov r1, #0x6f
	lsl r1, r1, #2
	str r0, [r4, r1]
	str r4, [r5]
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov99_021E93DC
