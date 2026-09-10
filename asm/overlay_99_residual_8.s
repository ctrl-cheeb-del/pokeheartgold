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

	thumb_func_start ov99_021E7258
ov99_021E7258: ; 0x021E7258
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bl ov99_021E7180
	add r5, r0, #0
	mov r4, #0
	mov r7, #1
_021E7266:
	lsl r0, r4, #2
	add r1, r6, r0
	ldr r0, _021E7288 ; =0x00000444
	ldr r0, [r1, r0]
	add r1, r5, #0
	and r1, r7
	bl ManagedSprite_SetDrawFlag
	lsl r0, r5, #0x17
	lsr r5, r0, #0x18
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #5
	blo _021E7266
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7288: .word 0x00000444
	thumb_func_end ov99_021E7258


	thumb_func_start ov99_021E728C
ov99_021E728C: ; 0x021E728C
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r4, r1, #0
	bl ov99_021E714C
	add r1, r0, #0
	mov r2, #0
	lsl r3, r1, #2
	ldr r1, _021E72BC ; =ov99_021E9F4C
	str r2, [sp]
	add r0, sp, #8
	str r0, [sp, #4]
	ldr r1, [r1, r3]
	ldr r0, [r5, #8]
	ldr r3, [r5, #0xc]
	bl GfGfxLoader_LoadFromOpenNarc_GetSizeOut
	ldr r1, [sp, #8]
	lsr r1, r1, #1
	str r1, [r4]
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_021E72BC: .word ov99_021E9F4C
	thumb_func_end ov99_021E728C


	thumb_func_start ov99_021E72C0
ov99_021E72C0: ; 0x021E72C0
	push {r3, r4, r5, r6, r7, lr}
	add r1, sp, #0
	add r5, r0, #0
	bl ov99_021E728C
	mov r1, #0x3f
	lsl r1, r1, #4
	str r0, [r5, r1]
	ldr r0, [sp]
	mov r7, #0
	cmp r0, #0
	bls _021E7332
	add r6, r7, #0
_021E72DA:
	mov r0, #0x3f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	ldrh r4, [r0, r6]
	cmp r4, #0
	beq _021E72EC
	ldr r0, _021E7384 ; =0x000001ED
	cmp r4, r0
	bls _021E72F0
_021E72EC:
	bl GF_AssertFail
_021E72F0:
	add r0, r5, #0
	add r1, r4, #0
	bl ov99_021E7180
	cmp r0, #0
	beq _021E7328
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	lsl r0, r0, #0x12
	lsr r0, r0, #0x17
	lsl r0, r0, #1
	add r0, r5, r0
	strh r4, [r0, #0x14]
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	ldr r0, _021E7388 ; =0xFFFFC01F
	and r0, r1
	lsl r1, r1, #0x12
	lsr r1, r1, #0x17
	add r1, r1, #1
	lsl r1, r1, #0x17
	lsr r1, r1, #0x12
	orr r1, r0
	mov r0, #0xfd
	lsl r0, r0, #2
	str r1, [r5, r0]
_021E7328:
	ldr r0, [sp]
	add r7, r7, #1
	add r6, r6, #2
	cmp r7, r0
	blo _021E72DA
_021E7332:
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	lsl r0, r0, #0x12
	lsr r0, r0, #0x17
	beq _021E7380
	mov r1, #0x1e
	bl _u32_div_f
	mov r2, #0xfd
	lsl r2, r2, #2
	ldr r3, [r5, r2]
	mov r1, #0x1f
	bic r3, r1
	mov r1, #0x1f
	and r0, r1
	orr r0, r3
	str r0, [r5, r2]
	ldr r0, [r5, r2]
	mov r1, #0x1e
	lsl r0, r0, #0x12
	lsr r0, r0, #0x17
	bl _u32_div_f
	cmp r1, #0
	bne _021E7380
	mov r2, #0xfd
	lsl r2, r2, #2
	ldr r3, [r5, r2]
	mov r1, #0x1f
	add r0, r3, #0
	bic r0, r1
	lsl r1, r3, #0x1b
	lsr r1, r1, #0x1b
	sub r3, r1, #1
	mov r1, #0x1f
	and r1, r3
	orr r0, r1
	str r0, [r5, r2]
_021E7380:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7384: .word 0x000001ED
_021E7388: .word 0xFFFFC01F
	thumb_func_end ov99_021E72C0


	thumb_func_start ov99_021E738C
ov99_021E738C: ; 0x021E738C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	str r1, [sp, #0xc]
	mov r5, #0
	add r7, r0, #0
	str r2, [sp, #0x10]
	str r5, [sp, #0x14]
_021E739A:
	ldr r0, [sp, #0x10]
	mov r4, #0
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
_021E73A2:
	add r0, r4, r5
	add r1, r0, #1
	add r0, sp, #0x18
	strh r1, [r0]
	str r6, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0xc]
	ldr r0, [r7]
	add r3, r3, r4
	lsl r3, r3, #0x18
	mov r1, #3
	add r2, sp, #0x18
	lsr r3, r3, #0x18
	bl LoadRectToBgTilemapRect
	add r4, r4, #1
	cmp r4, #2
	blt _021E73A2
	ldr r0, [sp, #0x10]
	add r5, r5, #2
	add r0, r0, #1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, #2
	blt _021E739A
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov99_021E738C


	thumb_func_start ov99_021E73E0
ov99_021E73E0: ; 0x021E73E0
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r1, r2, #0
	add r5, r0, #0
	bl ov99_021E7198
	cmp r0, #0
	beq _021E7424
	add r0, r4, #0
	mov r1, #6
	bl _s32_div_f
	add r6, r1, #0
	add r0, r4, #0
	mov r1, #6
	bl _s32_div_f
	add r2, r0, #0
	lsl r3, r2, #1
	lsl r1, r6, #2
	add r2, r2, r3
	add r1, r1, #6
	add r2, r2, #4
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	add r0, r5, #0
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	bl ov99_021E738C
	ldr r0, [r5]
	mov r1, #3
	bl BgCommitTilemapBufferToVram
_021E7424:
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov99_021E73E0


	thumb_func_start ov99_021E7428
ov99_021E7428: ; 0x021E7428
	push {r3, r4, r5, r6, r7, lr}
	ldr r7, _021E744C ; =0x00000408
	add r5, r0, #0
	add r6, r1, #0
	mov r4, #0
_021E7432:
	add r0, r4, #0
	add r0, #0x14
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, r7]
	add r1, r6, #0
	bl ManagedSprite_SetDrawFlag
	add r4, r4, #1
	cmp r4, #0x1e
	blt _021E7432
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E744C: .word 0x00000408
	thumb_func_end ov99_021E7428


	thumb_func_start ov99_021E7450
ov99_021E7450: ; 0x021E7450
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	bl ov99_021E7158
	str r0, [sp, #4]
	add r1, sp, #8
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r0, [r5]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	add r0, r5, #0
	mov r1, #0
	bl ov99_021E7428
	ldr r0, [sp, #4]
	mov r4, #0
	cmp r0, #0
	ble _021E74F2
_021E747E:
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	lsl r0, r0, #0xd
	lsr r1, r0, #0x1b
	mov r0, #0x1e
	mul r0, r1
	add r0, r4, r0
	lsl r0, r0, #1
	add r0, r5, r0
	ldrh r6, [r0, #0x14]
	ldr r1, [sp, #8]
	ldr r0, _021E74F8 ; =0xFFFFFE00
	and r1, r0
	lsr r0, r0, #0x17
	and r0, r6
	orr r0, r1
	str r0, [sp, #8]
	add r0, r5, #0
	add r1, r6, #0
	bl ov99_021E71E4
	lsl r0, r0, #0x1b
	ldr r2, [sp, #8]
	ldr r1, _021E74FC ; =0xFFFFC1FF
	lsr r0, r0, #0x12
	and r1, r2
	orr r0, r1
	str r0, [sp, #8]
	add r0, r4, #0
	add r0, #0x14
	lsl r0, r0, #2
	add r7, r5, r0
	mov r0, #0
	str r0, [sp]
	ldr r0, _021E7500 ; =0x00000404
	ldr r1, _021E7504 ; =0x00000408
	ldr r0, [r5, r0]
	ldr r1, [r7, r1]
	add r2, sp, #8
	mov r3, #1
	bl ov98_0221E970
	ldr r0, _021E7504 ; =0x00000408
	mov r1, #1
	ldr r0, [r7, r0]
	bl ManagedSprite_SetDrawFlag
	lsl r1, r4, #0x10
	add r0, r5, #0
	lsr r1, r1, #0x10
	add r2, r6, #0
	bl ov99_021E73E0
	ldr r0, [sp, #4]
	add r4, r4, #1
	cmp r4, r0
	blt _021E747E
_021E74F2:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_021E74F8: .word 0xFFFFFE00
_021E74FC: .word 0xFFFFC1FF
_021E7500: .word 0x00000404
_021E7504: .word 0x00000408
	thumb_func_end ov99_021E7450


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


	thumb_func_start ov99_021E76D8
ov99_021E76D8: ; 0x021E76D8
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r3, sp, #4
	mov r2, #0
	str r2, [r3]
	str r2, [r3, #4]
	str r2, [r3, #8]
	ldr r2, [sp, #4]
	ldr r3, _021E7744 ; =0xFFFFFE00
	add r4, r1, #0
	and r2, r3
	lsr r3, r3, #0x17
	and r3, r4
	orr r2, r3
	str r2, [sp, #4]
	add r5, r0, #0
	bl ov99_021E71E4
	lsl r0, r0, #0x1b
	ldr r2, [sp, #4]
	ldr r1, _021E7748 ; =0xFFFFC1FF
	lsr r0, r0, #0x12
	and r1, r2
	orr r0, r1
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, r4, #0
	bl ov99_021E7208
	lsl r0, r0, #0x1e
	ldr r2, [sp, #4]
	ldr r1, _021E774C ; =0xFFFF3FFF
	lsr r0, r0, #0x10
	and r1, r2
	orr r0, r1
	str r0, [sp, #4]
	ldr r0, _021E7750 ; =0x00000147
	cmp r4, r0
	bne _021E772E
	add r0, r5, #0
	bl ov99_021E723C
	str r0, [sp, #8]
_021E772E:
	ldr r0, [r5, #0xc]
	mov r2, #0
	str r0, [sp]
	ldr r0, _021E7754 ; =0x00000414
	add r1, sp, #4
	ldr r0, [r5, r0]
	add r3, r2, #0
	bl ov98_0221E7E8
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E7744: .word 0xFFFFFE00
_021E7748: .word 0xFFFFC1FF
_021E774C: .word 0xFFFF3FFF
_021E7750: .word 0x00000147
_021E7754: .word 0x00000414
	thumb_func_end ov99_021E76D8


	thumb_func_start ov99_021E7758
ov99_021E7758: ; 0x021E7758
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #1
	lsl r0, r0, #0xa
	ldr r0, [r5, r0]
	add r4, r1, #0
	bl ov98_0221EEFC
	cmp r4, #0
	beq _021E7786
	mov r1, #0
	add r2, r4, #0
	bl BufferSpeciesName
	mov r0, #1
	lsl r0, r0, #0xa
	ldr r0, [r5, r0]
	mov r1, #5
	mov r2, #0x7c
	mov r3, #0
	bl ov98_0221EBD8
	pop {r3, r4, r5, pc}
_021E7786:
	mov r0, #1
	lsl r0, r0, #0xa
	ldr r0, [r5, r0]
	mov r1, #5
	bl ov98_0221EE84
	pop {r3, r4, r5, pc}
	thumb_func_end ov99_021E7758


	thumb_func_start ov99_021E7794
ov99_021E7794: ; 0x021E7794
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl ov99_021E71B0
	add r4, r0, #0
	ldr r0, _021E77D4 ; =0x000001ED
	cmp r4, r0
	bls _021E77A6
	mov r4, #0
_021E77A6:
	add r0, r5, #0
	add r1, r4, #0
	bl ov99_021E76D8
	add r0, r5, #0
	add r1, r4, #0
	bl ov99_021E7758
	add r0, r5, #0
	add r1, r4, #0
	bl ov99_021E7258
	add r0, r5, #0
	add r1, r4, #0
	bl ov99_021E7198
	add r1, r0, #0
	lsl r1, r1, #0x18
	mov r0, #4
	lsr r1, r1, #0x18
	bl GfGfx_EngineBTogglePlanes
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E77D4: .word 0x000001ED
	thumb_func_end ov99_021E7794


	thumb_func_start ov99_021E77D8
ov99_021E77D8: ; 0x021E77D8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _021E7810 ; =0x00000414
	mov r1, #0
	ldr r0, [r5, r0]
	bl ManagedSprite_SetDrawFlag
	add r0, r5, #0
	mov r1, #0
	bl ov99_021E7758
	mov r4, #0
	ldr r6, _021E7814 ; =0x00000444
	add r7, r4, #0
_021E77F4:
	ldr r0, [r5, r6]
	add r1, r7, #0
	bl ManagedSprite_SetDrawFlag
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #5
	blt _021E77F4
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7810: .word 0x00000414
_021E7814: .word 0x00000444
	thumb_func_end ov99_021E77D8


	thumb_func_start PokeathlonMedals_Init
PokeathlonMedals_Init: ; 0x021E7818
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, _021E78E0 ; =FS_OVERLAY_ID(OVY_98)
	mov r1, #2
	bl HandleLoadOverlay
	add r0, r4, #0
	bl OverlayManager_GetArgs
	add r5, r0, #0
	bl GfGfx_DisableEngineBPlanes
	bl GfGfx_DisableEngineAPlanes
	cmp r5, #0
	bne _021E783C
	bl GF_AssertFail
_021E783C:
	mov r0, #3
	mov r1, #0x84
	lsl r2, r0, #0x10
	bl Heap_Create
	mov r1, #0x4d
	add r0, r4, #0
	lsl r1, r1, #4
	mov r2, #0x84
	bl OverlayManager_CreateAndGetData
	mov r2, #0x4d
	mov r1, #0
	lsl r2, r2, #4
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x84
	str r0, [r4, #0xc]
	str r5, [r4, #0x10]
	bl ov98_0221F090
	ldr r1, [r4, #0xc]
	mov r0, #0xb1
	bl NARC_New
	str r0, [r4, #4]
	ldr r1, [r4, #0xc]
	mov r0, #0x4a
	bl NARC_New
	str r0, [r4, #8]
	add r0, r4, #0
	bl ov99_021E72C0
	add r0, r4, #0
	bl ov99_021E7D30
	add r0, r4, #0
	bl ov99_021E7DA4
	ldr r0, _021E78E4 ; =0x0000013A
	ldr r3, _021E78E8 ; =ov99_021E9FDC
	str r0, [sp]
	ldr r0, [r4, #0xc]
	ldr r1, [r4]
	mov r2, #0xc
	bl ov98_0221EABC
	mov r1, #1
	lsl r1, r1, #0xa
	str r0, [r4, r1]
	add r0, r4, #0
	bl ov99_021E7EF0
	add r0, r4, #0
	bl ov99_021E7A78
	add r0, r4, #0
	bl ov99_021E7508
	add r0, r4, #0
	bl ov99_021E7450
	add r0, r4, #0
	bl ov99_021E7794
	add r0, r4, #0
	bl ov99_021E8224
	mov r0, #0
	bl ResetVisibleHardwareWindows
	mov r0, #1
	bl ResetVisibleHardwareWindows
	ldr r0, _021E78EC ; =ov99_021E7A54
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E78E0: .word FS_OVERLAY_ID(OVY_98)
_021E78E4: .word 0x0000013A
_021E78E8: .word ov99_021E9FDC
_021E78EC: .word ov99_021E7A54
	thumb_func_end PokeathlonMedals_Init


	thumb_func_start PokeathlonMedals_Exit
PokeathlonMedals_Exit: ; 0x021E78F0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl Heap_Free
	add r0, r4, #0
	bl ov99_021E7AB8
	ldr r1, _021E7944 ; =0x00000404
	mov r2, #0x32
	ldr r0, [r4, r1]
	add r1, r1, #4
	add r1, r4, r1
	bl ov98_0221E684
	mov r0, #1
	lsl r0, r0, #0xa
	ldr r0, [r4, r0]
	mov r1, #0xc
	bl ov98_0221EB84
	add r0, r4, #0
	bl ov99_021E7EBC
	bl ov98_0221F0EC
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x84
	bl Heap_Destroy
	ldr r0, _021E7948 ; =FS_OVERLAY_ID(OVY_98)
	bl UnloadOverlayByID
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E7944: .word 0x00000404
_021E7948: .word FS_OVERLAY_ID(OVY_98)
	thumb_func_end PokeathlonMedals_Exit


	thumb_func_start PokeathlonMedals_Main
PokeathlonMedals_Main: ; 0x021E794C
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r5]
	add r4, r0, #0
	cmp r1, #4
	bhi _021E7A28
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E796A: ; jump table
	.short _021E7974 - _021E796A - 2 ; case 0
	.short _021E7990 - _021E796A - 2 ; case 1
	.short _021E799E - _021E796A - 2 ; case 2
	.short _021E7A14 - _021E796A - 2 ; case 3
	.short _021E7A22 - _021E796A - 2 ; case 4
_021E7974:
	mov r0, #6
	mov r1, #1
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r4, #0xc]
	add r2, r1, #0
	str r0, [sp, #8]
	mov r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #1
	str r0, [r5]
	b _021E7A32
_021E7990:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E7A32
	mov r0, #2
	str r0, [r5]
	b _021E7A32
_021E799E:
	mov r1, #0xfd
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	lsl r1, r1, #2
	lsr r1, r1, #0x1f
	beq _021E79BA
	bl ov99_021E7794
	mov r1, #0xfd
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	ldr r0, _021E7A40 ; =0xDFFFFFFF
	and r0, r2
	str r0, [r4, r1]
_021E79BA:
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	beq _021E79DE
	add r0, r4, #0
	bl ov99_021E7598
	cmp r0, #0
	beq _021E7A32
	mov r1, #0xfd
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	ldr r0, _021E7A44 ; =0xEFFFFFFF
	and r0, r2
	str r0, [r4, r1]
	b _021E7A32
_021E79DE:
	add r0, r4, #0
	bl ov99_021E7BC8
	cmp r0, #0
	bne _021E79F0
	bl ov98_0221EF24
	cmp r0, #0
	beq _021E7A32
_021E79F0:
	ldr r0, _021E7A48 ; =0x000005DC
	bl PlaySE
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4, #0xc]
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #3
	str r0, [r5]
	b _021E7A32
_021E7A14:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E7A32
	mov r0, #4
	str r0, [r5]
	b _021E7A32
_021E7A22:
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, pc}
_021E7A28:
	ldr r0, _021E7A4C ; =_021EA5D8
	cmp r0, #0
	beq _021E7A32
	bl GF_AssertFail
_021E7A32:
	ldr r0, _021E7A50 ; =0x00000404
	ldr r0, [r4, r0]
	bl ov98_0221E6CC
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_021E7A40: .word 0xDFFFFFFF
_021E7A44: .word 0xEFFFFFFF
_021E7A48: .word 0x000005DC
_021E7A4C: .word _021EA5D8
_021E7A50: .word 0x00000404
	thumb_func_end PokeathlonMedals_Main


	thumb_func_start ov99_021E7A54
ov99_021E7A54: ; 0x021E7A54
	push {r4, lr}
	add r4, r0, #0
	bl SpriteSystem_TransferOam
	ldr r0, [r4]
	bl DoScheduledBgGpuUpdates
	ldr r3, _021E7A70 ; =0x027E0000
	ldr r1, _021E7A74 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_021E7A70: .word 0x027E0000
_021E7A74: .word 0x00003FF8
	thumb_func_end ov99_021E7A54


	thumb_func_start ov99_021E7A78
ov99_021E7A78: ; 0x021E7A78
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r1, _021E7AAC ; =ov99_021EA250
	lsl r0, r0, #5
	lsr r0, r0, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r4, #0xc]
	ldr r2, _021E7AB0 ; =ov99_021E9FA0
	str r0, [sp, #8]
	ldr r0, _021E7AB4 ; =ov99_021EA03C
	add r3, r4, #0
	bl GridInputHandler_Create
	mov r1, #0xff
	lsl r1, r1, #2
	str r0, [r4, r1]
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_021E7AAC: .word ov99_021EA250
_021E7AB0: .word ov99_021E9FA0
_021E7AB4: .word ov99_021EA03C
	thumb_func_end ov99_021E7A78


	thumb_func_start ov99_021E7AB8
ov99_021E7AB8: ; 0x021E7AB8
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0xff
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021E7AD2
	bl GridInputHandler_Free
	mov r0, #0xff
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
_021E7AD2:
	pop {r4, pc}
	thumb_func_end ov99_021E7AB8


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


	thumb_func_start ov99_021E7C58
ov99_021E7C58: ; 0x021E7C58
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0xff
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r4, r1, #0
	bl GridInputHandler_GetDpadBox
	add r1, sp, #0
	add r1, #1
	add r2, sp, #0
	bl DpadMenuBox_GetPosition
	ldr r0, _021E7C9C ; =0x00000408
	add r2, sp, #0
	ldrb r1, [r2, #1]
	ldrb r2, [r2]
	ldr r0, [r5, r0]
	bl ManagedSprite_SetPositionXY
	mov r1, #0xfd
	lsl r1, r1, #2
	ldr r2, [r5, r1]
	ldr r0, _021E7CA0 ; =0xF807FFFF
	and r2, r0
	lsl r0, r4, #0x18
	lsr r0, r0, #5
	orr r0, r2
	str r0, [r5, r1]
	ldr r0, _021E7CA4 ; =0x000005DC
	bl PlaySE
	pop {r3, r4, r5, pc}
	nop
_021E7C9C: .word 0x00000408
_021E7CA0: .word 0xF807FFFF
_021E7CA4: .word 0x000005DC
	thumb_func_end ov99_021E7C58
