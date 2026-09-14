	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	thumb_func_start ov96_0220223C
ov96_0220223C: ; 0x0220223C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xa0
	str r0, [sp, #4]
	bl PokeathlonCourse_GetDataCopyArea
	str r0, [sp, #0x24]
	ldr r0, [sp, #4]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldr r0, [sp, #4]
	bl ov96_021E5F24
	cmp r0, #0
	beq _0220225C
	b _02202706
_0220225C:
	mov r0, #0x5d
	lsl r0, r0, #4
	ldrb r0, [r4, r0]
	cmp r0, #0
	beq _0220227C
	ldr r0, [sp, #0x24]
	add r0, #0x28
	str r0, [sp, #0x24]
	bl ov96_021E8A20
	add r1, r0, #0
	add r0, r4, #0
	bl ov96_02202738
	add sp, #0xa0
	pop {r3, r4, r5, r6, r7, pc}
_0220227C:
	ldr r0, [sp, #0x24]
	add r0, #0x50
	bl ov96_021E8A20
	add r5, r0, #0
	ldr r0, [sp, #0x24]
	bl ov96_021E8A20
	add r3, r0, #0
	mov r2, #4
_02202290:
	ldmia r3!, {r0, r1}
	stmia r5!, {r0, r1}
	sub r2, r2, #1
	bne _02202290
	ldr r0, [r3]
	str r0, [r5]
	ldr r0, _02202598 ; =0x000005E8
	ldrh r1, [r4, r0]
	cmp r1, #0
	beq _022022A8
	sub r1, r1, #1
	strh r1, [r4, r0]
_022022A8:
	ldr r0, [sp, #0x24]
	add r0, #0x28
	bl ov96_021E8A20
	mov r0, #0
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x24]
	add r5, r4, #0
	str r0, [sp, #0x1c]
	add r0, #0x50
	str r0, [sp, #0x1c]
	add r0, r4, #0
	str r0, [sp, #0x34]
	add r0, #0xd4
	str r0, [sp, #0x34]
	add r0, r4, #0
	str r0, [sp, #0x2c]
	add r0, #0xe0
	str r0, [sp, #0x2c]
	add r0, r4, #0
	str r0, [sp, #0x30]
	add r0, #0xec
	str r0, [sp, #0x30]
_022022D6:
	ldr r0, [sp, #0x1c]
	bl ov96_021E8A20
	add r7, r0, #0
	ldr r0, [r7]
	cmp r0, #0
	ldr r0, _0220259C ; =0x0000059C
	beq _02202316
	ldr r1, [r5, r0]
	cmp r1, #0
	beq _022022FC
	add r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _022022FC
	ldr r0, _0220259C ; =0x0000059C
	mov r1, #0
	str r1, [r5, r0]
	b _0220231E
_022022FC:
	cmp r1, #0
	bne _0220231E
	mov r0, #0x5a
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _0220231E
	ldr r0, _0220259C ; =0x0000059C
	mov r1, #1
	str r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
	b _0220231E
_02202316:
	mov r1, #0
	str r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
_0220231E:
	ldr r0, _0220259C ; =0x0000059C
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _022023EA
	add r0, sp, #0x94
	str r0, [sp]
	ldr r1, [sp, #0x28]
	ldrb r2, [r7, #4]
	lsl r1, r1, #0x18
	ldrb r3, [r7, #5]
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_022031A8
	add r6, r0, #0
	cmp r6, #0xc
	beq _022023E2
	lsl r0, r6, #5
	add r1, r4, r0
	mov r0, #0x43
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _02202412
	mov r0, #0x48
	mul r0, r6
	add r0, r4, r0
	add r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	beq _02202360
	cmp r0, #2
	bne _022023E2
_02202360:
	ldr r0, [sp, #0x28]
	add r3, r6, #0
	add r1, r4, r0
	ldr r0, _022025A0 ; =0x000005CC
	strb r6, [r1, r0]
	mov r0, #0x48
	mul r3, r0
	add r0, sp, #0x94
	mov ip, r0
	add r0, r4, r3
	str r0, [sp, #0x48]
	add r0, #0xe0
	mov r2, ip
	str r0, [sp, #0x48]
	ldmia r2!, {r0, r1}
	mov ip, r2
	ldr r2, [sp, #0x48]
	stmia r2!, {r0, r1}
	mov r0, ip
	ldr r1, [r0]
	add r0, r2, #0
	str r1, [r0]
	ldrb r0, [r7, #4]
	str r2, [sp, #0x48]
	add r2, r4, r3
	lsl r0, r0, #0xc
	str r0, [sp, #0x88]
	ldrb r0, [r7, #5]
	add r7, sp, #0x88
	add r2, #0xec
	lsl r0, r0, #0xc
	str r0, [sp, #0x90]
	mov r0, #0
	str r0, [sp, #0x8c]
	ldmia r7!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r7]
	str r0, [r2]
	add r0, r4, r3
	add r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	bne _022023E2
	mov r0, #0xc
	add r1, r6, #0
	mul r1, r0
	ldr r0, _022025A4 ; =ov96_0221C98C
	add r2, r4, r3
	add r6, r0, r1
	ldmia r6!, {r0, r1}
	add r2, #0xc8
	stmia r2!, {r0, r1}
	ldr r0, [r6]
	add r1, r4, r3
	str r0, [r2]
	add r1, #0xc4
	mov r0, #2
	str r0, [r1]
	add r1, r4, r3
	add r1, #0xfc
	mov r0, #0
	strh r0, [r1]
	add r1, r4, r3
	add r1, #0xfe
	strh r0, [r1]
_022023E2:
	ldr r0, _022025A8 ; =0x000005EA
	mov r1, #0
	strb r1, [r4, r0]
	b _022026A4
_022023EA:
	mov r0, #0x5a
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02202420
	ldr r0, [sp, #0x28]
	add r1, r4, r0
	ldr r0, _022025A0 ; =0x000005CC
	ldrb r0, [r1, r0]
	cmp r0, #0xc
	beq _02202412
	ldr r0, _022025A8 ; =0x000005EA
	ldrb r0, [r4, r0]
	bl _dfltu
	ldr r3, _022025AC ; =0x403E0000
	mov r2, #0
	bl _dls
	blo _02202414
_02202412:
	b _022026A4
_02202414:
	ldr r0, _022025A8 ; =0x000005EA
	ldrb r0, [r4, r0]
	add r1, r0, #1
	ldr r0, _022025A8 ; =0x000005EA
	strb r1, [r4, r0]
	b _022026A4
_02202420:
	ldr r0, [sp, #0x28]
	add r1, r4, r0
	ldr r0, _022025A0 ; =0x000005CC
	str r1, [sp, #0x18]
	ldrb r0, [r1, r0]
	cmp r0, #0xc
	bne _02202430
	b _0220269E
_02202430:
	add r0, sp, #0x7c
	str r0, [sp]
	ldr r1, [sp, #0x28]
	ldrb r2, [r7, #4]
	lsl r1, r1, #0x18
	ldrb r3, [r7, #5]
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_022031A8
	cmp r0, #0xc
	beq _022024A8
	ldr r2, [sp, #0x18]
	ldr r1, _022025A0 ; =0x000005CC
	ldrb r1, [r2, r1]
	cmp r0, r1
	bne _022024A8
	mov r1, #0x48
	mul r1, r0
	add r0, r4, r1
	add r0, #0xfc
	ldrh r0, [r0]
	cmp r0, #4
	bhs _022024EE
	add r0, r4, r1
	add r0, #0xfc
	ldrh r0, [r0]
	add r2, r0, #1
	add r0, r4, r1
	add r0, #0xfc
	strh r2, [r0]
	add r0, r4, r1
	add r0, #0xfc
	ldrh r0, [r0]
	cmp r0, #1
	bhi _02202482
	add r1, r4, r1
	add r1, #0xfe
	mov r0, #0
	strh r0, [r1]
	b _02202696
_02202482:
	cmp r0, #2
	bhi _02202490
	add r1, r4, r1
	add r1, #0xfe
	mov r0, #1
	strh r0, [r1]
	b _02202696
_02202490:
	cmp r0, #3
	bhi _0220249E
	add r1, r4, r1
	add r1, #0xfe
	mov r0, #2
	strh r0, [r1]
	b _02202696
_0220249E:
	add r1, r4, r1
	add r1, #0xfe
	mov r0, #3
	strh r0, [r1]
	b _02202696
_022024A8:
	mov r1, #0
	add r0, sp, #0x70
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r1, [sp, #0x18]
	ldr r0, _022025A0 ; =0x000005CC
	add r2, sp, #0x64
	ldrb r1, [r1, r0]
	mov r0, #0x48
	add r6, r1, #0
	str r1, [sp, #0x10]
	mul r6, r0
	ldr r1, [sp, #0x2c]
	add r0, sp, #0x7c
	add r1, r1, r6
	bl VEC_Subtract
	ldrb r0, [r7, #4]
	ldr r1, [sp, #0x30]
	add r2, sp, #0x58
	lsl r0, r0, #0xc
	str r0, [sp, #0x4c]
	ldrb r0, [r7, #5]
	add r1, r1, r6
	lsl r0, r0, #0xc
	str r0, [sp, #0x54]
	mov r0, #0
	str r0, [sp, #0x50]
	add r0, sp, #0x4c
	bl VEC_Subtract
	ldr r0, [sp, #0x60]
	cmp r0, #0
	ble _022024F0
_022024EE:
	b _02202696
_022024F0:
	add r3, sp, #0x64
	add r2, r4, r6
	ldmia r3!, {r0, r1}
	add r2, #0xd4
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [sp, #0x10]
	lsl r0, r0, #5
	add r1, r4, r0
	ldr r0, _022025B0 ; =0x0000042E
	str r1, [sp, #0x14]
	ldrsh r0, [r1, r0]
	cmp r0, #0x3c
	bgt _02202516
	mov r0, #0x3f
	lsl r0, r0, #0x18
	str r0, [sp, #0x20]
	b _0220253A
_02202516:
	cmp r0, #0x46
	bgt _02202520
	ldr r0, _022025B4 ; =0x3F19999A
	str r0, [sp, #0x20]
	b _0220253A
_02202520:
	cmp r0, #0x50
	bgt _0220252A
	ldr r0, _022025B8 ; =0x3F333333
	str r0, [sp, #0x20]
	b _0220253A
_0220252A:
	cmp r0, #0x5a
	bgt _02202534
	ldr r0, _022025BC ; =0x3F4CCCCD
	str r0, [sp, #0x20]
	b _0220253A
_02202534:
	mov r0, #0xfe
	lsl r0, r0, #0x16
	str r0, [sp, #0x20]
_0220253A:
	ldr r0, [sp, #0x34]
	add r0, r0, r6
	bl VEC_Mag
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	bl _fflt
	add r7, r0, #0
	bl _f2d
	mov r3, #1
	mov r2, #0
	lsl r3, r3, #0x1e
	bl _dgr
	bls _02202566
	mov r7, #1
	lsl r7, r7, #0x1e
	b _0220257A
_02202566:
	add r0, r7, #0
	bl _f2d
	ldr r3, _022025C0 ; =0x3FF00000
	mov r2, #0
	bl _dls
	bhs _0220257A
	mov r7, #0xfe
	lsl r7, r7, #0x16
_0220257A:
	ldr r0, _022025A8 ; =0x000005EA
	ldrb r0, [r4, r0]
	bl _ffltu
	bl _f2d
	ldr r3, _022025AC ; =0x403E0000
	mov r2, #0
	bl _ddiv
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _022025C0 ; =0x3FF00000
	b _022025C4
	nop
_02202598: .word 0x000005E8
_0220259C: .word 0x0000059C
_022025A0: .word 0x000005CC
_022025A4: .word ov96_0221C98C
_022025A8: .word 0x000005EA
_022025AC: .word 0x403E0000
_022025B0: .word 0x0000042E
_022025B4: .word 0x3F19999A
_022025B8: .word 0x3F333333
_022025BC: .word 0x3F4CCCCD
_022025C0: .word 0x3FF00000
_022025C4:
	mov r0, #0
	bl _dadd
	bl _d2f
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x20]
	bl _f2d
	str r0, [sp, #0x3c]
	add r0, r7, #0
	str r1, [sp, #0xc]
	bl _f2d
	str r0, [sp, #0x40]
	add r7, r1, #0
	ldr r1, [sp, #0x14]
	ldr r0, _0220270C ; =0x0000041C
	ldr r0, [r1, r0]
	bl _f2d
	add r3, r1, #0
	mov r1, #1
	add r2, r0, #0
	mov r0, #0
	lsl r1, r1, #0x1e
	bl _dsub
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x40]
	add r1, r7, #0
	bl _dmul
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x3c]
	ldr r1, [sp, #0xc]
	bl _dmul
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x38]
	add r7, r1, #0
	bl _f2d
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x44]
	add r1, r7, #0
	bl _ddiv
	bl _d2f
	add r7, r0, #0
	bl _f2d
	ldr r3, _02202710 ; =0x40080000
	mov r2, #0
	bl _dgr
	bls _02202642
	ldr r7, _02202714 ; =0x40400000
	b _02202656
_02202642:
	add r0, r7, #0
	bl _f2d
	ldr r3, _02202718 ; =0x3FF00000
	mov r2, #0
	bl _dls
	bhs _02202656
	mov r7, #0xfe
	lsl r7, r7, #0x16
_02202656:
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x34]
	add r0, r0, r6
	add r1, r1, r6
	bl VEC_Normalize
	ldr r0, _0220271C ; =0x45800000
	add r1, r7, #0
	bl _fmul
	bl _ffix
	ldr r1, [sp, #0x34]
	ldr r3, [sp, #0x34]
	add r1, r1, r6
	add r2, sp, #0x70
	add r3, r3, r6
	bl VEC_MultAdd
	ldr r1, [sp, #0x14]
	ldr r0, _02202720 ; =0x00000428
	ldr r0, [r1, r0]
	ldr r1, [sp, #0x34]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r1, r1, r6
	bl ov96_02204320
	add r1, r4, r6
	add r1, #0xc4
	mov r0, #1
	str r0, [r1]
_02202696:
	ldr r1, [sp, #0x18]
	ldr r0, _02202724 ; =0x000005CC
	mov r2, #0xc
	strb r2, [r1, r0]
_0220269E:
	ldr r0, _02202728 ; =0x000005EA
	mov r1, #0
	strb r1, [r4, r0]
_022026A4:
	ldr r0, [sp, #0x1c]
	add r5, #0xc
	add r0, #0x28
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x28]
	add r0, r0, #1
	str r0, [sp, #0x28]
	cmp r0, #4
	bge _022026B8
	b _022022D6
_022026B8:
	ldr r1, _0220272C ; =0x000005DC
	ldr r0, [r4, r1]
	add r1, #0xc
	ldrh r2, [r4, r1]
	ldr r1, _02202730 ; =0x00000708
	sub r1, r1, r2
	bl ov96_022043C0
	ldr r0, [sp, #4]
	bl ov96_022033FC
	ldr r0, [sp, #4]
	bl ov96_02203468
	add r0, r4, #0
	bl ov96_02203754
	ldr r0, [sp, #4]
	add r1, r4, #0
	bl ov96_02203544
	ldr r0, _02202734 ; =0x000005E8
	ldrh r1, [r4, r0]
	cmp r1, #0
	bne _022026EE
	mov r1, #1
	b _022026F0
_022026EE:
	mov r1, #0
_022026F0:
	sub r0, #0x18
	strb r1, [r4, r0]
	ldr r0, [sp, #0x24]
	add r0, #0x28
	str r0, [sp, #0x24]
	bl ov96_021E8A20
	add r1, r0, #0
	add r0, r4, #0
	bl ov96_02202738
_02202706:
	add sp, #0xa0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220270C: .word 0x0000041C
_02202710: .word 0x40080000
_02202714: .word 0x40400000
_02202718: .word 0x3FF00000
_0220271C: .word 0x45800000
_02202720: .word 0x00000428
_02202724: .word 0x000005CC
_02202728: .word 0x000005EA
_0220272C: .word 0x000005DC
_02202730: .word 0x00000708
_02202734: .word 0x000005E8
	thumb_func_end ov96_0220223C

	thumb_func_start ov96_02202738
ov96_02202738: ; 0x02202738
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, #0
	add r0, sp, #0x2c
	strb r1, [r0]
	strb r1, [r0, #1]
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	add r0, sp, #0x24
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	strh r1, [r0, #6]
	add r0, r1, #0
	ldr r4, [sp]
	str r0, [sp, #0x1c]
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	str r1, [sp, #0x18]
	add r5, r4, #0
	str r0, [sp, #8]
_02202766:
	add r0, r4, #0
	add r0, #0xc4
	ldr r1, [r0]
	ldr r0, [sp, #0xc]
	lsl r1, r0
	ldr r0, [sp, #0x18]
	orr r0, r1
	str r0, [sp, #0x18]
	ldr r0, _022028AC ; =0x00000433
	ldrb r0, [r5, r0]
	str r0, [sp, #0x10]
	add r0, r4, #0
	add r0, #0xfb
	ldrb r0, [r0]
	cmp r0, #0
	beq _0220278A
	mov r0, #1
	b _0220278C
_0220278A:
	mov r0, #0
_0220278C:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r1, r4, #0
	str r0, [sp, #0x14]
	add r1, #0xfb
	mov r0, #0
	strb r0, [r1]
	add r0, r4, #0
	add r0, #0xc8
	ldr r1, [r0]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r7, r0, #0xc
	add r0, r4, #0
	add r0, #0xd0
	ldr r1, [r0]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r6, r0, #0xc
	cmp r7, #1
	bge _022027BE
	mov r7, #1
	b _022027C4
_022027BE:
	cmp r7, #0x40
	ble _022027C4
	mov r7, #0x40
_022027C4:
	cmp r6, #1
	bge _022027CC
	mov r6, #1
	b _022027D2
_022027CC:
	cmp r6, #0x40
	ble _022027D2
	mov r6, #0x40
_022027D2:
	ldr r0, [sp, #0x1c]
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x1c]
	mov r1, #3
	bl _s32_div_f
	ldr r0, [sp, #0x20]
	add r2, sp, #0x2c
	ldrb r2, [r2, r0]
	add r0, r4, #0
	add r0, #0xfe
	sub r3, r6, #1
	ldrh r0, [r0]
	lsl r1, r1, #1
	lsl r3, r3, #6
	lsl r0, r1
	add r2, r2, r0
	ldr r0, [sp, #0x20]
	add r1, sp, #0x2c
	strb r2, [r1, r0]
	ldr r0, [sp, #0x14]
	lsl r2, r0, #0xd
	ldr r0, [sp, #0x10]
	lsl r1, r0, #0xc
	sub r0, r7, #1
	add r0, r0, r3
	add r0, r1, r0
	add r1, r2, r0
	ldr r0, _022028B0 ; =0x00000431
	ldrb r0, [r5, r0]
	lsl r0, r0, #0xe
	add r1, r1, r0
	ldr r0, [sp, #8]
	strh r1, [r0, #8]
	ldr r0, [sp, #0x20]
	add r1, sp, #0x24
	lsl r0, r0, #1
	ldrh r2, [r1, r0]
	ldr r1, _022028B4 ; =0x0000042C
	ldrh r1, [r5, r1]
	add r2, r2, r1
	add r1, sp, #0x24
	strh r2, [r1, r0]
	ldrh r2, [r1, r0]
	ldr r1, _022028B8 ; =0x000003E7
	cmp r2, r1
	bls _0220283C
	add r2, r1, #0
	add r1, sp, #0x24
	strh r2, [r1, r0]
_0220283C:
	ldr r0, [sp, #0xc]
	add r4, #0x48
	add r0, r0, #2
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r5, #0x20
	add r0, r0, #2
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #0xc
	blt _02202766
	ldr r2, [sp, #4]
	mov r3, #0
	add r0, sp, #0x24
	add r1, sp, #0x2c
_0220285E:
	ldrb r4, [r1]
	add r3, r3, #1
	add r1, r1, #1
	lsl r5, r4, #0xa
	ldrh r4, [r0]
	add r0, r0, #2
	add r4, r5, r4
	strh r4, [r2]
	add r2, r2, #2
	cmp r3, #4
	blt _0220285E
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #4]
	str r1, [r0, #0x20]
	mov r1, #0x5d
	ldr r0, [sp]
	lsl r1, r1, #4
	ldrb r0, [r0, r1]
	add r1, #0x18
	lsl r2, r0, #0x18
	ldr r0, [sp, #0x18]
	add r2, r0, r2
	ldr r0, [sp, #4]
	str r2, [r0, #0x20]
	ldr r0, [sp]
	ldrh r0, [r0, r1]
	mov r1, #0x1e
	add r0, #0x1e
	bl _s32_div_f
	ldr r1, [sp, #4]
	lsl r0, r0, #0x19
	ldr r1, [r1, #0x20]
	add r1, r1, r0
	ldr r0, [sp, #4]
	str r1, [r0, #0x20]
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022028AC: .word 0x00000433
_022028B0: .word 0x00000431
_022028B4: .word 0x0000042C
_022028B8: .word 0x000003E7
	thumb_func_end ov96_02202738

	thumb_func_start ov96_022028BC
ov96_022028BC: ; 0x022028BC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r7, r0, #0
	bl ov96_021E8A20
	add r4, r0, #0
	mov r0, #0
	add r7, #0xf0
	str r0, [r4]
	add r0, r7, #0
	bl ov96_021E8A20
	ldr r0, [r0, #0x20]
	mov r1, #1
	asr r0, r0, #0x18
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _0220290A
	ldr r0, [r6, #0x48]
	bl ov96_021EB63C
	ldr r0, _0220294C ; =0x000005D8
	mov r1, #1
	ldr r0, [r6, r0]
	bl ov96_021EB144
	ldr r1, _02202950 ; =ov96_022038D4
	add r0, r5, #0
	bl ov96_021E8324
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0220290A:
	bl System_GetTouchNew
	cmp r0, #0
	beq _0220292C
	add r0, r5, #0
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	lsl r1, r1, #0x18
	str r0, [sp]
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #3
	mov r3, #0
	bl ov96_021E8228
_0220292C:
	bl System_GetTouchHeld
	cmp r0, #0
	beq _02202942
	ldr r0, _02202954 ; =gSystem + 0x40
	ldrh r1, [r0, #0x20]
	strb r1, [r4, #4]
	ldrh r0, [r0, #0x22]
	strb r0, [r4, #5]
	mov r0, #1
	str r0, [r4]
_02202942:
	add r0, r5, #0
	bl ov96_02202958
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220294C: .word 0x000005D8
_02202950: .word ov96_022038D4
_02202954: .word gSystem + 0x40
	thumb_func_end ov96_022028BC

	thumb_func_start ov96_02202958
ov96_02202958: ; 0x02202958
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14c
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	str r0, [sp, #0x58]
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x58]
	ldr r0, [r0, #0x20]
	asr r1, r0, #0x19
	mov r0, #0x7f
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x54]
	bne _02202994
	mov r1, #0
	b _0220299C
_02202994:
	ldr r0, [sp, #0x54]
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
_0220299C:
	add r0, r4, #0
	bl ov96_022038A0
	ldr r1, [sp, #0x2c]
	mov r0, #0x5e
	lsl r2, r1, #1
	ldr r1, [sp, #0x58]
	lsl r0, r0, #4
	ldrh r2, [r1, r2]
	ldr r1, _02202CE8 ; =0x000003FF
	ldr r0, [r4, r0]
	and r1, r2
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	bl ov96_02203BD0
	ldr r0, [sp, #0x2c]
	mov r1, #4
	sub r0, r1, r0
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0x1c]
	ldr r0, _02202CEC ; =FX_SinCosTable_
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	lsl r1, r1, #0xe
	asr r1, r1, #4
	lsl r1, r1, #2
	add r0, r0, r1
	ldr r5, [sp, #0x58]
	mov r6, #0
	str r0, [sp, #0x5c]
_022029DA:
	ldrh r0, [r5, #8]
	asr r1, r0, #0xd
	mov r0, #1
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _02202AD2
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	ldr r1, [sp, #0x2c]
	cmp r1, r0
	bne _02202AD2
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x16
	add r0, r4, r0
	str r0, [sp, #0x30]
	mov r1, #1
	ldr r0, [r0, #0x64]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [sp, #0x30]
	mov r1, #6
	ldr r0, [r0, #0x64]
	bl ov96_021EB564
	ldrh r1, [r5, #8]
	mov r0, #0x3f
	add r2, r1, #0
	asr r1, r1, #6
	and r1, r0
	add r7, r1, #1
	and r2, r0
	ldr r1, [sp, #0x2c]
	add r0, r2, #1
	cmp r1, #0
	beq _02202A8A
	mov r2, #0
	str r2, [sp, #0x108]
	lsl r1, r0, #0xc
	mov r2, #0x21
	lsl r0, r7, #0xc
	lsl r2, r2, #0xc
	str r1, [sp, #0x104]
	sub r1, r1, r2
	str r1, [sp, #0x104]
	add r1, r2, #0
	ldr r2, [sp, #0x5c]
	str r0, [sp, #0x10c]
	sub r0, r0, r1
	mov r1, #0
	str r0, [sp, #0x10c]
	ldrsh r1, [r2, r1]
	add r3, r2, #0
	mov r2, #2
	ldrsh r2, [r3, r2]
	add r0, sp, #0x110
	bl MTX_RotY43_
	add r0, sp, #0x104
	add r1, sp, #0x110
	add r2, sp, #0xf8
	bl MTX_MultVec43
	mov r0, #0x21
	ldr r1, [sp, #0xf8]
	lsl r0, r0, #0xc
	add r0, r1, r0
	mov r1, #0x21
	ldr r2, [sp, #0x100]
	lsl r1, r1, #0xc
	add r1, r2, r1
	asr r2, r0, #0xb
	lsr r2, r2, #0x14
	add r2, r0, r2
	str r0, [sp, #0xf8]
	asr r0, r2, #0xc
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	str r1, [sp, #0x100]
	asr r7, r2, #0xc
_02202A8A:
	bl _fflt
	str r0, [sp, #0x60]
	add r0, r7, #0
	bl _fflt
	add r1, r0, #0
	ldr r0, [sp, #0x60]
	add r2, sp, #0x88
	add r3, sp, #0x84
	bl ov96_02204134
	ldr r0, [sp, #0x88]
	ldr r7, [sp, #0x84]
	lsl r0, r0, #0xc
	str r0, [sp, #0x140]
	lsl r0, r7, #0xc
	str r0, [sp, #0x144]
	mov r0, #0
	str r0, [sp, #0x148]
	add r0, r7, #0
	mov r1, #0x14
	bl _s32_div_f
	sub r7, #8
	sub r0, r7, r0
	lsl r0, r0, #0xc
	str r0, [sp, #0x144]
	ldr r0, [sp, #0x30]
	add r1, sp, #0x140
	ldr r0, [r0, #0x64]
	bl ov96_021EB588
	ldr r0, _02202CF0 ; =0x0000088F
	bl PlaySE
_02202AD2:
	add r6, r6, #1
	add r5, r5, #2
	cmp r6, #0xc
	bge _02202ADC
	b _022029DA
_02202ADC:
	ldr r0, [sp, #0x2c]
	mov r5, #0
	lsl r1, r0, #1
	add r0, r0, r1
	str r0, [sp, #0x34]
_02202AE6:
	ldr r0, [sp, #0x34]
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0x58]
	lsl r1, r7, #1
	add r0, r0, r1
	str r0, [sp, #0x28]
	ldrh r0, [r0, #8]
	asr r1, r0, #0xe
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x50]
	cmp r0, #1
	bne _02202B28
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _02202CF4 ; =0x00000418
	mov r1, #1
	ldr r0, [r6, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #0
	bl ov96_02203BC0
	b _02202B70
_02202B28:
	ldr r0, [sp, #0x50]
	cmp r0, #2
	bne _02202B50
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _02202CF4 ; =0x00000418
	mov r1, #1
	ldr r0, [r6, r0]
	mov r2, #0
	bl ov96_021EB52C
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #1
	bl ov96_02203BC0
	b _02202B70
_02202B50:
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _02202CF4 ; =0x00000418
	mov r1, #1
	ldr r0, [r6, r0]
	mov r2, #0
	bl ov96_021EB52C
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #0
	bl ov96_02203BC0
_02202B70:
	ldr r0, [sp, #0x28]
	ldrh r0, [r0, #8]
	asr r1, r0, #0xc
	mov r0, #1
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x4c]
	ldr r0, [sp, #0x58]
	ldr r1, [r0, #0x20]
	lsl r0, r7, #1
	asr r1, r0
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x50]
	cmp r0, #1
	bne _02202BD2
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #0xa
	bl ov96_02203CA4
	ldr r0, _02202CF8 ; =0x00000434
	mov r1, #0xa
	strh r1, [r6, r0]
	mov r0, #0x89
	lsl r0, r0, #4
	bl IsSEPlaying
	cmp r0, #0
	bne _02202BC2
	mov r0, #0x89
	lsl r0, r0, #4
	bl PlaySE
_02202BC2:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _02202C88
	mov r0, #0x8b
	lsl r0, r0, #4
	bl PlaySE
	b _02202C88
_02202BD2:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _02202C02
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #7
	bl ov96_02203CA4
	ldr r0, _02202CF8 ; =0x00000434
	mov r1, #7
	strh r1, [r6, r0]
	mov r0, #0x8b
	lsl r0, r0, #4
	bl PlaySE
	mov r0, #0x5e
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ov96_02203CD4
	b _02202C88
_02202C02:
	ldr r0, [sp, #0x48]
	cmp r0, #1
	bne _02202C4C
	ldr r0, _02202CFC ; =0x00000436
	ldrh r0, [r6, r0]
	cmp r0, #0
	bne _02202C4C
	ldr r0, [sp, #0x50]
	cmp r0, #1
	bne _02202C1A
	bl GF_AssertFail
_02202C1A:
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #4
	bl ov96_02203CA4
	lsl r0, r7, #5
	ldr r1, _02202CF8 ; =0x00000434
	add r0, r4, r0
	mov r2, #4
	strh r2, [r0, r1]
	mov r2, #1
	add r1, r1, #2
	strh r2, [r0, r1]
	ldr r0, _02202D00 ; =0x000005EF
	add r1, r4, r5
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _02202C88
	ldr r0, _02202D04 ; =0x000008AC
	bl PlaySE
	b _02202C88
_02202C4C:
	ldr r0, _02202CF8 ; =0x00000434
	mov r7, #0
	ldrh r0, [r6, r0]
	cmp r0, #0xa
	bne _02202C5A
	mov r7, #1
	b _02202C6E
_02202C5A:
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	bl ov96_02203CC4
	cmp r0, #0
	bne _02202C6E
	mov r7, #1
_02202C6E:
	cmp r7, #0
	beq _02202C88
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #1
	bl ov96_02203CA4
	ldr r0, _02202CF8 ; =0x00000434
	mov r1, #1
	strh r1, [r6, r0]
_02202C88:
	ldr r0, [sp, #0x48]
	cmp r0, #1
	beq _02202C94
	ldr r0, _02202CFC ; =0x00000436
	mov r1, #0
	strh r1, [r6, r0]
_02202C94:
	ldr r0, [sp, #0x34]
	add r5, r5, #1
	add r0, r0, #1
	str r0, [sp, #0x34]
	cmp r5, #3
	bge _02202CA2
	b _02202AE6
_02202CA2:
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x2c]
	add r1, r0, #1
	lsl r0, r1, #1
	add r0, r1, r0
	mov r1, #0xc
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x38]
	add r5, r4, #0
_02202CBC:
	ldr r0, [sp, #0x38]
	mov r1, #0xc
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0x58]
	lsl r1, r7, #1
	add r0, r0, r1
	ldrh r0, [r0, #8]
	asr r1, r0, #0xe
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x10]
	cmp r0, #1
	bne _02202D1E
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _02202CF4 ; =0x00000418
	b _02202D08
	.balign 4, 0
_02202CE8: .word 0x000003FF
_02202CEC: .word FX_SinCosTable_
_02202CF0: .word 0x0000088F
_02202CF4: .word 0x00000418
_02202CF8: .word 0x00000434
_02202CFC: .word 0x00000436
_02202D00: .word 0x000005EF
_02202D04: .word 0x000008AC
_02202D08:
	mov r1, #1
	ldr r0, [r6, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r5, #0x70]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	b _02202D5A
_02202D1E:
	ldr r0, [sp, #0x10]
	cmp r0, #2
	bne _02202D40
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _0220305C ; =0x00000418
	mov r1, #1
	ldr r0, [r6, r0]
	mov r2, #0
	bl ov96_021EB52C
	mov r1, #1
	ldr r0, [r5, #0x70]
	add r2, r1, #0
	bl ov96_021EB52C
	b _02202D5A
_02202D40:
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _0220305C ; =0x00000418
	mov r1, #1
	ldr r0, [r6, r0]
	mov r2, #0
	bl ov96_021EB52C
	ldr r0, [r5, #0x70]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_02202D5A:
	ldr r0, [sp, #0x58]
	lsl r2, r7, #1
	add r0, r0, r2
	ldrh r0, [r0, #8]
	str r0, [sp, #0x64]
	asr r1, r0, #0xc
	mov r0, #1
	and r0, r1
	ldr r1, [sp, #0x58]
	lsl r0, r0, #0x18
	ldr r1, [r1, #0x20]
	lsr r0, r0, #0x18
	asr r1, r2
	mov r2, #3
	and r1, r2
	lsl r1, r1, #0x18
	lsr r3, r1, #0x18
	ldr r2, [sp, #0x64]
	mov r1, #0x3f
	and r1, r2
	str r1, [sp, #0x78]
	add r1, r2, #0
	asr r2, r1, #6
	mov r1, #0x3f
	and r1, r2
	mov ip, r1
	ldr r1, [sp, #0x10]
	cmp r1, #1
	bne _02202DBC
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0x14
	bl ov96_021EAC5C
	ldr r0, _02203060 ; =0x00000434
	mov r1, #0x14
	strh r1, [r6, r0]
	mov r0, #0x89
	lsl r0, r0, #4
	bl IsSEPlaying
	cmp r0, #0
	bne _02202E58
	mov r0, #0x89
	lsl r0, r0, #4
	bl PlaySE
	b _02202E58
_02202DBC:
	cmp r0, #0
	beq _02202DD4
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0x16
	bl ov96_021EAC5C
	ldr r0, _02203060 ; =0x00000434
	mov r1, #0x16
	strh r1, [r6, r0]
	b _02202E58
_02202DD4:
	cmp r3, #1
	bne _02202E24
	ldr r2, [sp, #0x78]
	mov r0, #0xc
	add r3, r2, #1
	ldr r2, _02203064 ; =ov96_0221C98C
	mul r0, r7
	ldr r1, _02203064 ; =ov96_0221C98C
	ldr r2, [r2, r0]
	add r1, r1, r0
	asr r0, r2, #0xb
	lsr r0, r0, #0x14
	add r0, r2, r0
	asr r0, r0, #0xc
	cmp r3, r0
	bne _02202E24
	ldr r2, [r1, #8]
	mov r0, ip
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	add r0, r0, #1
	asr r1, r1, #0xc
	cmp r0, r1
	bne _02202E24
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bne _02202E10
	bl GF_AssertFail
_02202E10:
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0x10
	bl ov96_021EAC5C
	ldr r0, _02203060 ; =0x00000434
	mov r1, #0x10
	strh r1, [r6, r0]
	b _02202E58
_02202E24:
	ldr r0, _02203060 ; =0x00000434
	mov r7, #0
	ldrh r0, [r6, r0]
	cmp r0, #0x14
	bne _02202E32
	mov r7, #1
	b _02202E42
_02202E32:
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	bl ov96_021EAD78
	cmp r0, #0
	bne _02202E42
	mov r7, #1
_02202E42:
	cmp r7, #0
	beq _02202E58
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0
	bl ov96_021EAC5C
	ldr r0, _02203060 ; =0x00000434
	mov r1, #0
	strh r1, [r6, r0]
_02202E58:
	ldr r0, [sp, #0x38]
	add r5, r5, #4
	add r0, r0, #1
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, #9
	bge _02202E6C
	b _02202CBC
_02202E6C:
	ldr r0, [sp, #0x58]
	ldr r3, _02203068 ; =ov96_0221C7C4
	str r0, [sp, #0x3c]
	add r2, sp, #0x8c
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r1, [sp, #0x1c]
	ldr r0, [r3]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	lsl r1, r1, #0xe
	str r0, [r2]
	asr r1, r1, #4
	mov r6, #0
	ldr r0, _0220306C ; =FX_SinCosTable_
	lsl r1, r1, #2
	add r0, r0, r1
	str r6, [sp, #0x40]
	add r5, r4, #0
	str r0, [sp, #0x68]
_02202E94:
	ldr r0, [sp, #0x58]
	ldr r1, [r0, #0x20]
	ldr r0, [sp, #0x40]
	asr r1, r0
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	add r0, r7, #0
	add r0, #0xff
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bls _02202EB2
	b _022030DE
_02202EB2:
	add r1, r5, #0
	add r1, #0xfa
	mov r0, #0
	strb r0, [r1]
	cmp r7, #2
	beq _02202ECE
	add r0, r5, #0
	add r0, #0xbc
	mov r1, #1
	ldr r0, [r0]
	add r2, r1, #0
	bl ov96_021EB52C
	b _02202EDC
_02202ECE:
	add r0, r5, #0
	add r0, #0xbc
	ldr r0, [r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_02202EDC:
	add r0, r5, #0
	add r0, #0xb8
	mov r1, #1
	ldr r0, [r0]
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #0x24]
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	ldr r0, [sp, #0x24]
	str r1, [sp, #0xc]
	lsl r1, r0, #1
	ldr r0, [sp, #0x58]
	ldrh r0, [r0, r1]
	asr r1, r0, #0xa
	mov r0, #0x3f
	and r0, r1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0xc]
	lsl r0, r0, #1
	asr r1, r0
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0x3c]
	ldrh r1, [r0, #8]
	mov r0, #0x3f
	and r0, r1
	asr r2, r1, #6
	mov r1, #0x3f
	and r1, r2
	add r1, r1, #1
	str r1, [sp, #0x44]
	ldr r1, [sp, #0x2c]
	add r0, r0, #1
	cmp r1, #0
	beq _02202F96
	mov r2, #0
	str r2, [sp, #0xb4]
	lsl r1, r0, #0xc
	mov r2, #0x21
	ldr r0, [sp, #0x44]
	lsl r2, r2, #0xc
	str r1, [sp, #0xb0]
	sub r1, r1, r2
	lsl r0, r0, #0xc
	str r1, [sp, #0xb0]
	add r1, r2, #0
	ldr r2, [sp, #0x68]
	str r0, [sp, #0xb8]
	sub r0, r0, r1
	mov r1, #0
	str r0, [sp, #0xb8]
	ldrsh r1, [r2, r1]
	add r3, r2, #0
	mov r2, #2
	ldrsh r2, [r3, r2]
	add r0, sp, #0xbc
	bl MTX_RotY43_
	add r0, sp, #0xb0
	add r1, sp, #0xbc
	add r2, sp, #0xa4
	bl MTX_MultVec43
	mov r0, #0x21
	ldr r1, [sp, #0xa4]
	lsl r0, r0, #0xc
	add r0, r1, r0
	mov r1, #0x21
	ldr r2, [sp, #0xac]
	lsl r1, r1, #0xc
	add r1, r2, r1
	asr r2, r0, #0xb
	lsr r2, r2, #0x14
	add r2, r0, r2
	str r0, [sp, #0xa4]
	asr r0, r2, #0xc
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	str r1, [sp, #0xac]
	asr r1, r2, #0xc
	str r1, [sp, #0x44]
_02202F96:
	bl _fflt
	str r0, [sp, #0x6c]
	ldr r0, [sp, #0x44]
	bl _fflt
	add r1, r0, #0
	ldr r0, [sp, #0x6c]
	add r2, sp, #0x80
	add r3, sp, #0x7c
	bl ov96_02204134
	ldr r0, [sp, #0x80]
	add r1, sp, #0xec
	lsl r0, r0, #0xc
	str r0, [sp, #0xec]
	ldr r0, [sp, #0x7c]
	lsl r0, r0, #0xc
	str r0, [sp, #0xf0]
	mov r0, #0
	str r0, [sp, #0xf4]
	add r0, r5, #0
	add r0, #0xbc
	ldr r0, [r0]
	bl ov96_021EB588
	ldr r0, [sp, #0x7c]
	mov r1, #0x14
	str r0, [sp, #0x18]
	bl _s32_div_f
	ldr r1, [sp, #0x18]
	sub r1, #8
	sub r0, r1, r0
	lsl r0, r0, #0xc
	str r0, [sp, #0xf0]
	add r0, r5, #0
	add r0, #0xb8
	str r1, [sp, #0x18]
	ldr r0, [r0]
	add r1, sp, #0xec
	bl ov96_021EB588
	add r3, sp, #0x8c
	ldmia r3!, {r0, r1}
	add r2, sp, #0x98
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [sp, #0x7c]
	bl _fflt
	bl _f2d
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _02203070 ; =0x40738000
	mov r0, #0
	bl _dadd
	ldr r3, _02203074 ; =0x40878000
	mov r2, #0
	bl _ddiv
	str r0, [sp, #0x70]
	add r0, r7, #0
	str r1, [sp, #8]
	bl _ffltu
	bl _f2d
	ldr r3, _02203078 ; =0x40080000
	mov r2, #0
	bl _ddiv
	add r2, r0, #0
	add r3, r1, #0
	ldr r1, _0220307C ; =0x3FF00000
	mov r0, #0
	bl _dadd
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x70]
	ldr r1, [sp, #8]
	bl _dmul
	bl _d2f
	str r0, [sp, #0x74]
	ldr r0, _02203080 ; =0x45800000
	ldr r1, [sp, #0x74]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x98]
	ldr r0, _02203080 ; =0x45800000
	b _02203084
	.balign 4, 0
_0220305C: .word 0x00000418
_02203060: .word 0x00000434
_02203064: .word ov96_0221C98C
_02203068: .word ov96_0221C7C4
_0220306C: .word FX_SinCosTable_
_02203070: .word 0x40738000
_02203074: .word 0x40878000
_02203078: .word 0x40080000
_0220307C: .word 0x3FF00000
_02203080: .word 0x45800000
_02203084:
	ldr r1, [sp, #0x74]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x9c]
	add r0, r5, #0
	add r0, #0xbc
	ldr r0, [r0]
	add r1, sp, #0x98
	mov r2, #2
	bl ov96_021EB5A0
	add r0, r5, #0
	add r0, #0xb8
	ldr r0, [r0]
	add r1, sp, #0x98
	mov r2, #2
	bl ov96_021EB5A0
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	add r1, sp, #0x98
	mov r2, #2
	bl ov96_021EB5A0
	ldr r1, [sp, #0x24]
	ldr r0, [sp, #0x2c]
	cmp r1, r0
	bne _02203168
	ldr r0, [sp, #0xc]
	add r1, r4, r0
	ldr r0, _02203198 ; =0x000005EC
	str r1, [sp, #0x20]
	ldrb r0, [r1, r0]
	cmp r7, r0
	beq _02203168
	ldr r0, _0220319C ; =0x000008B1
	bl PlaySE
	ldr r1, [sp, #0x20]
	ldr r0, _02203198 ; =0x000005EC
	strb r7, [r1, r0]
	b _02203168
_022030DE:
	add r0, r5, #0
	add r0, #0xbc
	ldr r0, [r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	add r0, r5, #0
	add r0, #0xb8
	ldr r0, [r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	cmp r7, #3
	bne _02203168
	add r0, r5, #0
	add r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	bne _02203168
	add r1, r5, #0
	add r1, #0xfa
	mov r0, #1
	strb r0, [r1]
	add r0, r5, #0
	add r0, #0xb8
	ldr r0, [r0]
	bl ov96_021EB594
	add r1, r0, #0
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	bl ov96_021EB588
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #3
	bl ov96_021EB564
	add r0, r5, #0
	add r0, #0xc0
	mov r1, #1
	ldr r0, [r0]
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	ldr r1, [sp, #0x2c]
	cmp r0, r1
	bne _02203168
	ldr r0, _022031A0 ; =0x000008B3
	bl PlaySE
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r0, r4, r1
	ldr r1, _022031A4 ; =0x000005EF
	mov r2, #0
	strb r2, [r0, r1]
	sub r1, r1, #3
	strb r2, [r0, r1]
_02203168:
	ldr r0, [sp, #0x40]
	add r6, r6, #1
	add r0, r0, #2
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x3c]
	add r5, #0x48
	add r0, r0, #2
	str r0, [sp, #0x3c]
	cmp r6, #0xc
	bge _0220317E
	b _02202E94
_0220317E:
	ldr r1, [sp, #0x2c]
	add r0, r4, #0
	bl ov96_02203970
	ldr r2, [sp, #0x54]
	mov r1, #0x1e
	ldr r0, [sp]
	mul r1, r2
	bl ov96_021E6454
	add sp, #0x14c
	pop {r4, r5, r6, r7, pc}
	nop
_02203198: .word 0x000005EC
_0220319C: .word 0x000008B1
_022031A0: .word 0x000008B3
_022031A4: .word 0x000005EF
	thumb_func_end ov96_02202958

	thumb_func_start ov96_022031A8
ov96_022031A8: ; 0x022031A8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x68
	add r5, r1, #0
	mov r1, #0x12
	lsl r1, r1, #4
	add r0, r2, #0
	add r1, r3, r1
	add r2, sp, #4
	add r3, sp, #0
	bl ov96_0220404C
	ldr r0, _02203290 ; =0x45800000
	ldr r1, [sp, #4]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x5c]
	ldr r0, _02203290 ; =0x45800000
	ldr r1, [sp]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x64]
	mov r0, #0
	str r0, [sp, #0x60]
	cmp r5, #0
	beq _0220323C
	add r3, sp, #0x5c
	ldmia r3!, {r0, r1}
	add r2, sp, #0x20
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _02203294 ; =FX_SinCosTable_
	str r0, [r2]
	mov r0, #0x21
	ldr r1, [sp, #0x20]
	lsl r0, r0, #0xc
	sub r1, r1, r0
	str r1, [sp, #0x20]
	ldr r1, [sp, #0x28]
	sub r0, r1, r0
	str r0, [sp, #0x28]
	lsl r0, r5, #0xe
	asr r0, r0, #4
	lsl r2, r0, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0x2c
	bl MTX_RotY43_
	add r0, sp, #0x20
	add r1, sp, #0x2c
	add r2, sp, #0x14
	bl MTX_MultVec43
	mov r0, #0x21
	ldr r1, [sp, #0x14]
	lsl r0, r0, #0xc
	add r1, r1, r0
	str r1, [sp, #0x14]
	ldr r1, [sp, #0x1c]
	add r3, sp, #0x14
	add r0, r1, r0
	str r0, [sp, #0x1c]
	ldmia r3!, {r0, r1}
	add r2, sp, #0x5c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
_0220323C:
	add r2, sp, #0x5c
	ldr r3, [sp, #0x80]
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	add r1, r5, #1
	str r0, [r3]
	lsl r0, r5, #1
	add r4, r5, r0
	lsl r0, r1, #1
	add r6, r1, r0
	cmp r4, r6
	bge _02203288
	mov r0, #0xc
	ldr r1, _02203298 ; =ov96_0221C98C
	mul r0, r4
	add r5, r1, r0
	add r7, sp, #8
_02203260:
	add r0, r5, #0
	add r1, sp, #0x5c
	add r2, r7, #0
	bl VEC_Subtract
	add r0, r7, #0
	bl VEC_Mag
	mov r1, #1
	lsl r1, r1, #0xe
	cmp r0, r1
	bgt _02203280
	lsl r0, r4, #0x18
	add sp, #0x68
	lsr r0, r0, #0x18
	pop {r3, r4, r5, r6, r7, pc}
_02203280:
	add r4, r4, #1
	add r5, #0xc
	cmp r4, r6
	blt _02203260
_02203288:
	mov r0, #0xc
	add sp, #0x68
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02203290: .word 0x45800000
_02203294: .word FX_SinCosTable_
_02203298: .word ov96_0221C98C
	thumb_func_end ov96_022031A8
