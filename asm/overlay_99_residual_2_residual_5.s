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
	.public ov99_021E5B90
	.public ov99_021E5BB4
	.public ov99_021E5C20
	.public ov99_021E5C4C
	.public ov99_021E5D2C
	.public ov99_021E5F74
	.public ov99_021E5FE8
	.public ov99_021E6018
	.public ov99_021E6050
	.public ov99_021E6144
	.public ov99_021E6218
	.public ov99_021E6250
	.public ov99_021E6400
	.public ov99_021E64E0
	.public ov99_021E6840
	.public ov99_021E6938
	.public ov99_021E69D8
	.public ov99_021E6A70


	thumb_func_start ov99_021E6188
ov99_021E6188: ; 0x021E6188
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r4, [r5, #0x10]
	add r6, r1, #0
	add r0, r4, #0
	bl ov98_0221EEFC
	lsl r2, r6, #0x18
	mov r1, #0
	lsr r2, r2, #0x18
	add r7, r0, #0
	bl BufferPokeathlonMedalName
	mov r0, #0
	str r0, [sp]
	mov r1, #1
	ldr r0, [r5, #0x10]
	mov r2, #4
	add r3, r1, #0
	bl ov98_0221EC08
	lsl r2, r6, #0x18
	add r0, r7, #0
	mov r1, #0
	lsr r2, r2, #0x18
	bl BufferPokeathlonCourseName
	mov r1, #3
	ldr r0, [r5, #0x10]
	add r2, r1, #0
	mov r3, #1
	bl ov98_0221EBD8
	ldr r0, [r5]
	bl ov99_021E5B70
	cmp r0, #0
	beq _021E6216
	ldr r0, [r5]
	add r1, r6, #0
	bl ov99_021E5B90
	bl ov98_0221EF64
	cmp r0, #0
	bne _021E61F2
	ldr r0, [r5, #0x10]
	mov r1, #4
	mov r2, #5
	mov r3, #1
	bl ov98_0221EBD8
	pop {r3, r4, r5, r6, r7, pc}
_021E61F2:
	cmp r0, #1
	bne _021E6204
	ldr r0, [r5, #0x10]
	mov r1, #4
	mov r2, #6
	mov r3, #1
	bl ov98_0221EBD8
	pop {r3, r4, r5, r6, r7, pc}
_021E6204:
	ldr r0, [r4, #4]
	mov r1, #0
	add r0, #0x40
	bl FillWindowPixelBuffer
	ldr r0, [r4, #4]
	add r0, #0x40
	bl ScheduleWindowCopyToVram
_021E6216:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov99_021E6188
