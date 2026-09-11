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

	thumb_func_start ov80_0223049C
ov80_0223049C: ; 0x0223049C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r0, #0
	ldr r0, _02230768 ; =0x000004F8
	add r6, r1, #0
	ldr r0, [r5, r0]
	bl sub_02030AE8
	str r0, [sp]
	ldr r0, _02230768 ; =0x000004F8
	ldr r0, [r5, r0]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	ldrb r0, [r5, #4]
	bl ov80_02236DD4
	ldrb r0, [r5, #4]
	mov r1, #1
	bl ov80_02236DF8
	ldrb r1, [r5, #5]
	add r0, sp, #4
	add r3, sp, #0xc
	strb r1, [r0, #8]
	ldr r0, _0223076C ; =0x000004F4
	mov r1, #0
	ldr r0, [r5, r0]
	add r2, r1, #0
	bl sub_02030978
	ldrb r1, [r5, #4]
	add r0, sp, #4
	mov r2, #0
	strb r1, [r0, #8]
	ldr r0, _0223076C ; =0x000004F4
	mov r1, #1
	ldr r0, [r5, r0]
	add r3, sp, #0xc
	bl sub_02030978
	ldr r0, _0223076C ; =0x000004F4
	mov r1, #1
	ldr r0, [r5, r0]
	bl sub_02030964
	ldrb r1, [r5, #6]
	add r0, sp, #4
	mov r2, #0
	strb r1, [r0, #8]
	ldr r0, _0223076C ; =0x000004F4
	mov r1, #2
	ldr r0, [r5, r0]
	add r3, sp, #0xc
	bl sub_02030978
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C048
	add r7, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C048
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #8]
	add r0, r4, #0
	add r1, r7, #0
	bl sub_02031108
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205BFF0
	add r7, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205BFF0
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #0xc]
	add r0, r4, #0
	add r1, r7, #0
	bl sub_02031108
	cmp r6, #2
	beq _02230648
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C01C
	add r6, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C01C
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl FrontierSave_GetStat
	add r6, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C01C
	add r7, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C01C
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #0xc]
	add r0, r4, #0
	add r1, r7, #0
	bl sub_0203126C
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C01C
	add r7, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C01C
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r7, #0
	bl FrontierSave_GetStat
	ldrh r1, [r5, #0xc]
	cmp r1, r6
	bne _022305E2
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C074
	add r6, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C074
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	bl sub_0203126C
	b _02230608
_022305E2:
	cmp r6, r0
	bhs _02230608
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C074
	add r6, r0, #0
	ldrb r0, [r5, #5]
	ldrb r1, [r5, #4]
	bl sub_0205C074
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #8]
	add r0, r4, #0
	add r1, r6, #0
	bl sub_02031108
_02230608:
	ldrb r1, [r5, #0xa]
	add r0, sp, #4
	strb r1, [r0, #8]
	ldrb r2, [r5, #5]
	ldrb r3, [r5, #4]
	ldr r0, [sp]
	lsl r2, r2, #2
	add r2, r3, r2
	lsl r2, r2, #0x18
	mov r1, #0xa
	lsr r2, r2, #0x18
	add r3, sp, #0xc
	bl sub_02030AA4
	ldrb r0, [r5, #4]
	cmp r0, #3
	bne _02230648
	ldrb r0, [r5, #5]
	cmp r0, #0
	bne _02230634
	mov r6, #0x66
	b _02230636
_02230634:
	mov r6, #0x68
_02230636:
	add r0, r6, #0
	bl sub_0205C268
	add r2, r0, #0
	ldrb r3, [r5, #0xa]
	add r0, r4, #0
	add r1, r6, #0
	bl sub_02031108
_02230648:
	ldr r7, _0223076C ; =0x000004F4
	mov r4, #0
	add r6, sp, #4
_0223064E:
	lsl r0, r4, #1
	add r0, r5, r0
	ldrh r0, [r0, #0x18]
	lsl r2, r4, #0x18
	mov r1, #3
	strh r0, [r6]
	ldr r0, [r5, r7]
	lsr r2, r2, #0x18
	add r3, sp, #4
	bl sub_02030978
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #0xe
	blo _0223064E
	ldr r0, _02230770 ; =0x000004D4
	ldr r0, [r5, r0]
	bl Party_GetCount
	add r7, r0, #0
	ldr r4, _02230774 ; =0x00000000
	beq _022306E8
_0223067C:
	ldr r0, _02230770 ; =0x000004D4
	add r1, r4, #0
	ldr r0, [r5, r0]
	bl Party_GetMonByIndex
	add r6, r0, #0
	lsl r0, r4, #1
	add r1, r5, r0
	ldr r0, _02230778 ; =0x000004E8
	lsl r2, r4, #0x18
	ldrh r1, [r1, r0]
	add r0, sp, #4
	lsr r2, r2, #0x18
	strh r1, [r0]
	ldr r0, _0223076C ; =0x000004F4
	mov r1, #4
	ldr r0, [r5, r0]
	add r3, sp, #4
	bl sub_02030978
	add r0, r6, #0
	mov r1, #0x47
	mov r2, #0
	bl GetMonData
	add r1, sp, #4
	strb r0, [r1, #8]
	ldr r0, _0223076C ; =0x000004F4
	lsl r2, r4, #0x18
	ldr r0, [r5, r0]
	mov r1, #5
	lsr r2, r2, #0x18
	add r3, sp, #0xc
	bl sub_02030978
	mov r1, #0
	add r0, r6, #0
	add r2, r1, #0
	bl GetMonData
	str r0, [sp, #0x10]
	ldr r0, _0223076C ; =0x000004F4
	lsl r2, r4, #0x18
	ldr r0, [r5, r0]
	mov r1, #6
	lsr r2, r2, #0x18
	add r3, sp, #0x10
	bl sub_02030978
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, r7
	blo _0223067C
_022306E8:
	ldr r0, _0223077C ; =0x000004D8
	ldr r0, [r5, r0]
	bl Party_GetCount
	add r7, r0, #0
	ldr r4, _02230774 ; =0x00000000
	beq _02230762
_022306F6:
	ldr r0, _0223077C ; =0x000004D8
	add r1, r4, #0
	ldr r0, [r5, r0]
	bl Party_GetMonByIndex
	add r6, r0, #0
	lsl r0, r4, #1
	add r1, r5, r0
	ldr r0, _02230780 ; =0x000003D2
	lsl r2, r4, #0x18
	ldrh r1, [r1, r0]
	add r0, sp, #4
	lsr r2, r2, #0x18
	strh r1, [r0]
	ldr r0, _0223076C ; =0x000004F4
	mov r1, #7
	ldr r0, [r5, r0]
	add r3, sp, #4
	bl sub_02030978
	add r0, r6, #0
	mov r1, #0x47
	mov r2, #0
	bl GetMonData
	add r1, sp, #4
	strb r0, [r1, #8]
	ldr r0, _0223076C ; =0x000004F4
	lsl r2, r4, #0x18
	ldr r0, [r5, r0]
	mov r1, #8
	lsr r2, r2, #0x18
	add r3, sp, #0xc
	bl sub_02030978
	mov r1, #0
	add r0, r6, #0
	add r2, r1, #0
	bl GetMonData
	str r0, [sp, #0x10]
	ldr r0, _0223076C ; =0x000004F4
	lsl r2, r4, #0x18
	ldr r0, [r5, r0]
	mov r1, #9
	lsr r2, r2, #0x18
	add r3, sp, #0x10
	bl sub_02030978
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, r7
	blo _022306F6
_02230762:
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02230768: .word 0x000004F8
_0223076C: .word 0x000004F4
_02230770: .word 0x000004D4
_02230774: .word 0x00000000
_02230778: .word 0x000004E8
_0223077C: .word 0x000004D8
_02230780: .word 0x000003D2
	thumb_func_end ov80_0223049C
