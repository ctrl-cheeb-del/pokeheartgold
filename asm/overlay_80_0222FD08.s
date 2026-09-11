	.include "asm/macros.inc"
	.public _0222FD8E
	.public _0222FDA2
	.public _0222FE0A
	.public _0222FE12
	.public _0222FE1A
	.public _0222FEA8
	.public _0222FECC
	.public _0222FED4
	.public _0222FED8
	.public _0222FEDC
	.public _0222FEE0
	.public _0222FEE4
	.public _0222FEE8
	.public _0222FEF8
	.public _0222FF6A
	.public _0222FF74
	.public _0222FFA4
	.public _02230014
	.public _02230022
	.public _02230038
	.public _02230078
	.public _022300B0
	.public _022300C4
	.public _022300C8
	.public _022300CC
	.public _022300D0
	.public _02230130
	.public _02230180
	.public _022301A4
	.public _022301B0
	.public _022301EE
	.public _0223023C
	.public _02230260
	.public _0223026C
	.public _02230282
	.public _022302A6
	.public _02230324
	.public _0223035C
	.public _022303DA
	.public _0223040C
	.public _02230410
	.public _02230414
	.public _02230418
	.public _0223041C
	.public _02230420
	.public _02230436
	.public _02230442
	.public _02230452
	.public _02230454
	.public _02230458
	.public _0223045C
	.public _0223046A
	.public _02230480
	.public _02230492
	.public _022305E2
	.public _02230608
	.public _02230634
	.public _02230636
	.public _02230648
	.public _0223064E
	.public _0223067C
	.public _022306E8
	.public _022306F6
	.public _02230762
	.public _02230768
	.public _0223076C
	.public _02230770
	.public _02230774
	.public _02230778
	.public _0223077C
	.public _02230780
	.public _022307D0
	.public _022307E2
	.public _022307EC
	.public _0223082A
	.public _0223086E
	.public _0223087C
	.public _022308A4
	.public _022308B0
	.public _022308B4
	.public _022308B8
	.public _022308BC
	.public _022308C0
	.public _022308D2
	.public _022308FE
	.public _0223092C
	.public _0223094A
	.public _0223098A
	.public _022309EC
	.public _022309F0
	.public _022309F4
	.public _02230A4C
	.public _02230A50
	.public _02230A54
	.public _02230A58
	.public _02230A5C
	.public _02230A92
	.public _02230ABC
	.public _02230ACA
	.public _02230AD8
	.public _02230ADC
	.public _02230AE0
	.public _02230AF0
	.public _02230AF4
	.public _02230B0A
	.public _02230B18
	.public _02230B1E
	.public _02230B24
	.public _02230B2A
	.public _02230B30
	.public _02230B3A
	.public _02230B44
	.public _02230B48
	.public _02230B5C
	.public _02230B62
	.public _02230B6A
	.public _02230B6E
	.public _02230B7C
	.public _02230B7E
	.public _02230B84
	.public _02230B88
	.public _0223DD40
	.public ov80_0222FD08
	.public ov80_0222FEEC
	.public ov80_0222FF00
	.public ov80_022300D4
	.public ov80_02230270
	.public ov80_02230424
	.public ov80_02230460
	.public ov80_02230484
	.public ov80_0223049C
	.public ov80_02230784
	.public ov80_02230790
	.public ov80_02230794
	.public ov80_022307C8
	.public ov80_022307D4
	.public ov80_022307F0
	.public ov80_022308C4
	.public ov80_022309F8
	.public ov80_02230A60
	.public ov80_02230AE4
	.public ov80_02230AF8
	.public ov80_02230B4C
	.include "overlay_80_0222FD08.inc"
	.include "global.inc"

    .text
	.public ov80_0222FEEC
	.public ov80_02230424
	.public ov80_02230460
	.public ov80_02230484
	.public ov80_02230784
	.public ov80_02230790
	.public ov80_02230794
	.public ov80_022307C8
	.public ov80_022307D4
	.public ov80_022309F8
	.public ov80_02230A60
	.public ov80_02230AE4
	.public ov80_02230AF8
	.public ov80_02230B4C

	thumb_func_start ov80_0222FD08
ov80_0222FD08: ; 0x0222FD08
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	add r4, r0, #0
	ldr r1, _0222FED4 ; =0x00000708
	mov r0, #0xb
	add r7, r2, #0
	str r3, [sp]
	bl Heap_Alloc
	ldr r1, _0222FED8 ; =_0223DD40
	ldr r2, _0222FED4 ; =0x00000708
	str r0, [r1]
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, _0222FED8 ; =_0223DD40
	ldr r5, [r0]
	add r0, r4, #0
	bl sub_0203094C
	ldr r1, _0222FEDC ; =0x000004F4
	str r0, [r5, r1]
	add r0, r1, #4
	str r4, [r5, r0]
	mov r0, #0xb
	ldr r1, _0222FED8 ; =_0223DD40
	str r0, [r5]
	ldr r5, [r1]
	bl SaveArray_Party_Alloc
	ldr r1, _0222FEE0 ; =0x000004D4
	str r0, [r5, r1]
	mov r0, #0xb
	bl SaveArray_Party_Alloc
	ldr r1, _0222FEE4 ; =0x000004D8
	str r0, [r5, r1]
	add r1, #0x1c
	add r0, r4, #0
	ldr r5, [r5, r1]
	bl sub_02030AE8
	add r4, r0, #0
	cmp r6, #0
	bne _0222FE1A
	ldr r0, _0222FED8 ; =_0223DD40
	ldr r1, [r0]
	strb r7, [r1, #4]
	ldr r0, [sp]
	strb r0, [r1, #5]
	mov r0, #0
	strb r0, [r1, #6]
	add r0, r5, #0
	bl sub_02030940
	ldr r0, _0222FED8 ; =_0223DD40
	ldr r2, [r0]
	ldrb r3, [r2, #4]
	cmp r3, #3
	bne _0222FD8E
	ldr r0, _0222FEE8 ; =0x000004F8
	ldr r0, [r2, r0]
	bl Save_VarsFlags_Get
	bl Save_VarsFlags_GetVar4052
	b _0222FDA2
_0222FD8E:
	ldrb r2, [r2, #5]
	add r0, r4, #0
	mov r1, #0xa
	lsl r2, r2, #2
	add r2, r3, r2
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030AD4
_0222FDA2:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bne _0222FE0A
	ldr r0, _0222FED8 ; =_0223DD40
	ldr r5, [r0]
	ldr r0, _0222FEE8 ; =0x000004F8
	ldr r0, [r5, r0]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205BFF0
	add r6, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205BFF0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl FrontierSave_GetStat
	strh r0, [r5, #0xc]
	ldr r0, _0222FED8 ; =_0223DD40
	ldr r4, [r0]
	ldr r0, _0222FEE8 ; =0x000004F8
	ldr r0, [r4, r0]
	bl Save_Frontier_GetStatic
	add r6, r0, #0
	ldrb r0, [r4, #5]
	ldrb r1, [r4, #4]
	bl sub_0205C048
	add r7, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C048
	bl sub_0205C268
	add r2, r0, #0
	add r0, r6, #0
	add r1, r7, #0
	bl FrontierSave_GetStat
	b _0222FE12
_0222FE0A:
	ldr r0, _0222FED8 ; =_0223DD40
	ldr r4, [r0]
	mov r0, #0
	strh r0, [r4, #0xc]
_0222FE12:
	strh r0, [r4, #8]
	mov r0, #0
	str r0, [r4, #0x10]
	b _0222FEA8
_0222FE1A:
	mov r2, #0
	add r0, r5, #0
	mov r1, #1
	add r3, r2, #0
	bl sub_02030A24
	ldr r1, _0222FED8 ; =_0223DD40
	ldr r4, [r1]
	mov r1, #0
	strb r0, [r4, #4]
	add r0, r5, #0
	add r2, r1, #0
	add r3, r1, #0
	bl sub_02030A24
	mov r2, #0
	strb r0, [r4, #5]
	add r0, r5, #0
	mov r1, #2
	add r3, r2, #0
	bl sub_02030A24
	strb r0, [r4, #6]
	ldr r0, _0222FED8 ; =_0223DD40
	ldr r5, [r0]
	ldr r0, _0222FEE8 ; =0x000004F8
	ldr r0, [r5, r0]
	bl Save_Frontier_GetStatic
	add r6, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205BFF0
	add r7, r0, #0
	ldrb r0, [r4, #5]
	ldrb r1, [r4, #4]
	bl sub_0205BFF0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r6, #0
	add r1, r7, #0
	bl FrontierSave_GetStat
	strh r0, [r5, #0xc]
	ldr r0, _0222FED8 ; =_0223DD40
	ldr r4, [r0]
	ldr r0, _0222FEE8 ; =0x000004F8
	ldr r0, [r4, r0]
	bl Save_Frontier_GetStatic
	add r6, r0, #0
	ldrb r0, [r4, #5]
	ldrb r1, [r4, #4]
	bl sub_0205C048
	add r7, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C048
	bl sub_0205C268
	add r2, r0, #0
	add r0, r6, #0
	add r1, r7, #0
	bl FrontierSave_GetStat
	strh r0, [r4, #8]
_0222FEA8:
	ldr r0, _0222FED8 ; =_0223DD40
	mov r1, #7
	ldr r4, [r0]
	ldrh r0, [r4, #0xc]
	bl _s32_div_f
	strh r0, [r4, #0xe]
	ldrb r0, [r4, #4]
	bl ov80_02237254
	cmp r0, #1
	bne _0222FECC
	ldr r0, _0222FED8 ; =_0223DD40
	ldr r1, [r0]
	ldr r0, _0222FEE8 ; =0x000004F8
	ldr r0, [r1, r0]
	bl ov80_0222A840
_0222FECC:
	ldr r0, _0222FED8 ; =_0223DD40
	ldr r0, [r0]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222FED4: .word 0x00000708
_0222FED8: .word _0223DD40
_0222FEDC: .word 0x000004F4
_0222FEE0: .word 0x000004D4
_0222FEE4: .word 0x000004D8
_0222FEE8: .word 0x000004F8
	thumb_func_end ov80_0222FD08
