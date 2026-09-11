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


	thumb_func_start ov99_021E7AD4
ov99_021E7AD4: ; 0x021E7AD4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0xfd
	lsl r0, r0, #2
	add r4, r1, #0
	ldr r1, [r5, r0]
	add r7, r2, #0
	lsl r2, r1, #0xd
	lsr r2, r2, #0x1b
	cmp r4, #0
	beq _021E7AFA
	ldr r3, _021E7BB8 ; =0xFFF83FFF
	and r1, r3
	add r3, r2, #1
	lsl r3, r3, #0x1b
	lsr r3, r3, #0xd
	orr r1, r3
	str r1, [r5, r0]
	b _021E7B0C
_021E7AFA:
	cmp r2, #0
	beq _021E7B0C
	ldr r3, _021E7BB8 ; =0xFFF83FFF
	and r1, r3
	sub r3, r2, #1
	lsl r3, r3, #0x1b
	lsr r3, r3, #0xd
	orr r1, r3
	str r1, [r5, r0]
_021E7B0C:
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	lsl r1, r0, #0x1b
	lsl r0, r0, #0xd
	lsr r3, r1, #0x1b
	lsr r0, r0, #0x1b
	cmp r0, r3
	bhi _021E7B20
	add r3, r0, #0
_021E7B20:
	mov r6, #0xfd
	lsl r6, r6, #2
	ldr r1, [r5, r6]
	ldr r0, _021E7BB8 ; =0xFFF83FFF
	and r0, r1
	lsl r1, r3, #0x1b
	lsr r1, r1, #0xd
	orr r0, r1
	str r0, [r5, r6]
	ldr r0, [r5, r6]
	lsl r0, r0, #0xd
	lsr r0, r0, #0x1b
	cmp r0, r2
	beq _021E7BB4
	ldr r0, _021E7BBC ; =0x000005DC
	bl PlaySE
	cmp r4, #0
	bne _021E7B4A
	mov r2, #1
	b _021E7B4C
_021E7B4A:
	mov r2, #0
_021E7B4C:
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r3, [r5, r0]
	ldr r1, _021E7BC0 ; =0xF7FFFFFF
	lsl r2, r2, #0x1f
	and r1, r3
	lsr r2, r2, #4
	orr r1, r2
	str r1, [r5, r0]
	mov r1, #1
	ldr r2, [r5, r0]
	lsl r1, r1, #0x1c
	orr r1, r2
	str r1, [r5, r0]
	add r0, #8
	ldr r0, [r5, r0]
	mov r6, #0
	bl GridInputHandler_GetNextInput
	cmp r7, #0
	beq _021E7B80
	cmp r0, #0x1e
	bne _021E7B96
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	b _021E7B96
_021E7B80:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r4, #0
	beq _021E7B90
	sub r0, r0, #5
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	b _021E7B96
_021E7B90:
	add r0, r0, #5
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
_021E7B96:
	mov r0, #0xff
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r6, #0
	bl GridInputHandler_SetNextInput
	add r0, r5, #0
	add r1, r6, #0
	bl ov99_021E7C58
	ldr r0, _021E7BC4 ; =0x00000408
	mov r1, #0
	ldr r0, [r5, r0]
	bl ManagedSprite_SetDrawFlag
_021E7BB4:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7BB8: .word 0xFFF83FFF
_021E7BBC: .word 0x000005DC
_021E7BC0: .word 0xF7FFFFFF
_021E7BC4: .word 0x00000408
	thumb_func_end ov99_021E7AD4




	thumb_func_start ov99_021E7BC8
ov99_021E7BC8: ; 0x021E7BC8
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r0, #0xff
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl GridInputHandler_HandleInput_AllowHold
	add r6, r0, #0
	mov r0, #0xff
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl GridInputHandler_GetNextInput
	add r4, r0, #0
	ldr r0, _021E7C50 ; =ov99_021E9F54
	bl TouchscreenHitbox_FindHitboxAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _021E7C12
	cmp r0, #0
	bne _021E7C02
	add r0, r5, #0
	mov r1, #0
	mov r2, #1
	bl ov99_021E7AD4
	b _021E7C4C
_021E7C02:
	cmp r0, #1
	bne _021E7C4C
	mov r1, #1
	add r0, r5, #0
	add r2, r1, #0
	bl ov99_021E7AD4
	b _021E7C4C
_021E7C12:
	cmp r6, r1
	bne _021E7C3E
	cmp r4, #0x1e
	bhs _021E7C3E
	ldr r0, _021E7C54 ; =gSystem
	ldr r0, [r0, #0x4c]
	cmp r0, #0x20
	bne _021E7C2E
	mov r1, #0
	add r0, r5, #0
	add r2, r1, #0
	bl ov99_021E7AD4
	b _021E7C4C
_021E7C2E:
	cmp r0, #0x10
	bne _021E7C4C
	add r0, r5, #0
	mov r1, #1
	mov r2, #0
	bl ov99_021E7AD4
	b _021E7C4C
_021E7C3E:
	cmp r4, #0x1e
	bne _021E7C4C
	ldr r0, _021E7C54 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r1, r0
	bne _021E7C4E
_021E7C4C:
	mov r0, #0
_021E7C4E:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E7C50: .word ov99_021E9F54
_021E7C54: .word gSystem
	thumb_func_end ov99_021E7BC8


