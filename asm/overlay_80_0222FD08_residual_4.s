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

	thumb_func_start ov80_022307F0
ov80_022307F0: ; 0x022307F0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldrb r0, [r5, #4]
	bl ov80_02236DD4
	str r0, [sp, #4]
	ldrb r0, [r5, #4]
	mov r1, #1
	bl ov80_02236DF8
	str r0, [sp]
	ldr r0, _022308B0 ; =0x000004D4
	ldr r0, [r5, r0]
	bl SaveArray_Party_Init
	mov r0, #0xb
	bl AllocMonZeroed
	add r6, r0, #0
	ldr r0, [sp, #4]
	mov r7, #0
	cmp r0, #0
	ble _0223086E
	mov r0, #0xa
	lsl r0, r0, #6
	add r0, r5, r0
	add r4, r5, #0
	str r0, [sp, #8]
_0223082A:
	add r0, r5, #0
	bl ov80_02237120
	add r2, r0, #0
	ldr r0, _022308B4 ; =0x000004DC
	mov r1, #0x38
	ldrh r0, [r4, r0]
	mul r1, r0
	ldr r0, [sp, #8]
	add r0, r0, r1
	add r1, r6, #0
	bl ov80_0222A140
	ldr r0, _022308B8 ; =0x000004F8
	ldr r1, _022308B0 ; =0x000004D4
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl ov80_0222A3BC
	ldr r0, _022308B4 ; =0x000004DC
	add r7, r7, #1
	ldrh r0, [r4, r0]
	lsl r0, r0, #1
	add r1, r5, r0
	mov r0, #0x95
	lsl r0, r0, #2
	ldrh r1, [r1, r0]
	ldr r0, _022308BC ; =0x000004E8
	strh r1, [r4, r0]
	ldr r0, [sp, #4]
	add r4, r4, #2
	cmp r7, r0
	blt _0223082A
_0223086E:
	ldr r0, [sp]
	mov r7, #0
	cmp r0, #0
	ble _022308A4
	mov r0, #0x3f
	lsl r0, r0, #4
	add r4, r5, r0
_0223087C:
	add r0, r5, #0
	bl ov80_02237120
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl ov80_0222A140
	ldr r0, _022308B8 ; =0x000004F8
	ldr r1, _022308C0 ; =0x000004D8
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl ov80_0222A3BC
	ldr r0, [sp]
	add r7, r7, #1
	add r4, #0x38
	cmp r7, r0
	blt _0223087C
_022308A4:
	add r0, r6, #0
	bl Heap_Free
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_022308B0: .word 0x000004D4
_022308B4: .word 0x000004DC
_022308B8: .word 0x000004F8
_022308BC: .word 0x000004E8
_022308C0: .word 0x000004D8
	thumb_func_end ov80_022307F0


	thumb_func_start ov80_022308C4
ov80_022308C4: ; 0x022308C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x4c
	mov r1, #0
	add r5, r0, #0
	add r2, sp, #0x3c
	add r3, sp, #0x2c
	add r0, r1, #0
_022308D2:
	add r1, r1, #1
	strh r0, [r2]
	strh r0, [r3]
	add r2, r2, #2
	add r3, r3, #2
	cmp r1, #8
	blt _022308D2
	ldrb r0, [r5, #4]
	mov r1, #1
	bl ov80_02236DF8
	str r0, [sp, #0x1c]
	ldr r0, _022309EC ; =0x000004D4
	ldr r0, [r5, r0]
	bl Party_GetCount
	mov r7, #0
	str r0, [sp, #0x20]
	cmp r0, #0
	ble _0223092C
	add r6, sp, #0x3c
	add r4, sp, #0x2c
_022308FE:
	ldr r0, _022309EC ; =0x000004D4
	add r1, r7, #0
	ldr r0, [r5, r0]
	bl Party_GetMonByIndex
	str r0, [sp, #0x24]
	mov r1, #5
	mov r2, #0
	bl GetMonData
	strh r0, [r6]
	ldr r0, [sp, #0x24]
	mov r1, #6
	mov r2, #0
	bl GetMonData
	strh r0, [r4]
	ldr r0, [sp, #0x20]
	add r7, r7, #1
	add r6, r6, #2
	add r4, r4, #2
	cmp r7, r0
	blt _022308FE
_0223092C:
	ldr r0, _022309F0 ; =0x000004D8
	ldr r0, [r5, r0]
	bl Party_GetCount
	mov r7, #0
	str r0, [sp, #0x14]
	cmp r0, #0
	ble _0223098A
	ldr r0, [sp, #0x20]
	str r5, [sp, #0x18]
	lsl r1, r0, #1
	add r0, sp, #0x3c
	add r6, r0, r1
	add r0, sp, #0x2c
	add r4, r0, r1
_0223094A:
	ldr r0, _022309F0 ; =0x000004D8
	add r1, r7, #0
	ldr r0, [r5, r0]
	bl Party_GetMonByIndex
	str r0, [sp, #0x28]
	mov r1, #5
	mov r2, #0
	bl GetMonData
	strh r0, [r6]
	ldr r0, [sp, #0x28]
	mov r1, #6
	mov r2, #0
	bl GetMonData
	strh r0, [r4]
	ldr r1, [sp, #0x18]
	ldr r0, _022309F4 ; =0x000003D2
	add r7, r7, #1
	ldrh r2, [r1, r0]
	mov r0, #0x95
	lsl r0, r0, #2
	strh r2, [r1, r0]
	add r0, r1, #0
	add r0, r0, #2
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r6, r6, #2
	add r4, r4, #2
	cmp r7, r0
	blt _0223094A
_0223098A:
	ldrb r0, [r5, #6]
	ldrb r1, [r5, #5]
	lsl r0, r0, #1
	add r0, r5, r0
	ldrh r0, [r0, #0x18]
	bl ov80_02236C2C
	ldr r1, _022309F4 ; =0x000003D2
	ldr r3, [sp, #0x20]
	add r2, r5, r1
	str r2, [sp]
	mov r2, #0xb
	str r2, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	ldr r2, [sp, #0x14]
	add r1, #8
	str r0, [sp, #0xc]
	add r0, r5, r1
	str r0, [sp, #0x10]
	add r2, r3, r2
	ldr r3, [sp, #0x1c]
	add r0, sp, #0x3c
	add r1, sp, #0x2c
	bl ov80_02236C9C
	mov r2, #0x3e
	lsl r2, r2, #4
	add r0, r5, r2
	str r0, [sp]
	ldr r0, [sp, #0x1c]
	add r1, r2, #0
	str r0, [sp, #4]
	mov r0, #0xb
	str r0, [sp, #8]
	mov r0, #0xcd
	str r0, [sp, #0xc]
	add r0, r2, #0
	add r0, #0x10
	sub r1, #0xe
	sub r2, r2, #6
	add r0, r5, r0
	add r1, r5, r1
	add r2, r5, r2
	mov r3, #0
	bl ov80_0222A52C
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022309EC: .word 0x000004D4
_022309F0: .word 0x000004D8
_022309F4: .word 0x000003D2
	thumb_func_end ov80_022308C4
