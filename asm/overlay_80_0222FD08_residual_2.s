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

	thumb_func_start ov80_0222FF00
ov80_0222FF00: ; 0x0222FF00
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0xd8
	add r4, r0, #0
	bl ov80_022372B4
	add r1, r0, #0
	add r2, r4, #0
	ldrb r0, [r4, #4]
	add r2, #0x18
	mov r3, #0xe
	bl ov80_02236BE4
	add r0, r4, #0
	bl ov80_022372B4
	mov r3, #0x26
	lsl r3, r3, #4
	add r1, r4, r3
	str r1, [sp]
	add r1, r3, #0
	add r2, r3, #0
	add r1, #8
	add r1, r4, r1
	str r1, [sp, #4]
	ldrh r1, [r4, #8]
	sub r2, #0xc
	add r3, #0x20
	str r1, [sp, #8]
	mov r1, #0
	str r1, [sp, #0xc]
	str r1, [sp, #0x10]
	ldrb r1, [r4, #5]
	add r2, r4, r2
	add r3, r4, r3
	bl ov80_02236E24
	add r0, r4, #0
	mov r1, #4
	mov r2, #0
	bl ov80_022300D4
	add r0, r4, #0
	mov r1, #5
	mov r2, #0
	bl ov80_022300D4
	mov r0, #6
	str r0, [sp, #0x18]
	mov r0, #0
	mov ip, r0
	add r3, r4, #0
	add r5, sp, #0x34
_0222FF6A:
	mov r0, #0xa
	lsl r0, r0, #6
	add r2, r3, r0
	add r7, r5, #0
	mov r6, #7
_0222FF74:
	ldmia r2!, {r0, r1}
	stmia r7!, {r0, r1}
	sub r6, r6, #1
	bne _0222FF74
	mov r0, ip
	add r0, r0, #1
	add r3, #0x38
	add r5, #0x38
	mov ip, r0
	cmp r0, #6
	blt _0222FF6A
	ldrb r0, [r4, #4]
	bl ov80_02237254
	cmp r0, #1
	bne _02230038
	mov r0, #0xa
	lsl r0, r0, #6
	ldr r7, _022300C4 ; =0x00000282
	mov r5, #0
	add r0, r4, r0
	add r1, sp, #0x28
	add r2, r4, #0
	add r3, sp, #0x1c
_0222FFA4:
	ldrh r6, [r0]
	add r5, r5, #1
	add r0, #0x38
	lsl r6, r6, #0x15
	lsr r6, r6, #0x15
	strh r6, [r1]
	ldrh r6, [r2, r7]
	add r1, r1, #2
	add r2, #0x38
	strh r6, [r3]
	add r3, r3, #2
	cmp r5, #6
	blt _0222FFA4
	add r0, r4, #0
	bl ov80_022372B4
	mov r3, #0x59
	lsl r3, r3, #4
	add r1, r4, r3
	str r1, [sp]
	add r1, r3, #0
	add r1, #8
	add r1, r4, r1
	str r1, [sp, #4]
	add r1, r3, #0
	add r2, r3, #0
	sub r1, #0x10
	ldrh r1, [r4, r1]
	sub r2, #0xc
	add r3, #0x20
	str r1, [sp, #8]
	add r1, sp, #0x28
	str r1, [sp, #0xc]
	add r1, sp, #0x1c
	str r1, [sp, #0x10]
	ldrb r1, [r4, #5]
	add r2, r4, r2
	add r3, r4, r3
	bl ov80_02236E24
	add r0, r4, #0
	mov r1, #4
	mov r2, #1
	bl ov80_022300D4
	add r0, r4, #0
	mov r1, #5
	mov r2, #1
	bl ov80_022300D4
	mov r0, #0xc
	str r0, [sp, #0x18]
	mov r0, #0
	str r0, [sp, #0x14]
	add r5, r4, #0
	add r6, sp, #0x34
_02230014:
	mov r0, #0x5b
	lsl r0, r0, #4
	add r3, r5, r0
	mov r0, #0x15
	lsl r0, r0, #4
	add r2, r6, r0
	mov r7, #7
_02230022:
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	sub r7, r7, #1
	bne _02230022
	ldr r0, [sp, #0x14]
	add r5, #0x38
	add r0, r0, #1
	add r6, #0x38
	str r0, [sp, #0x14]
	cmp r0, #6
	blt _02230014
_02230038:
	ldrb r0, [r4, #4]
	mov r1, #1
	bl ov80_02236DF8
	ldr r2, _022300C8 ; =0x000003D2
	add r3, sp, #0x34
	add r1, r4, r2
	str r1, [sp]
	add r1, r2, #0
	add r1, #0x1e
	add r1, r4, r1
	str r1, [sp, #4]
	add r1, r2, #0
	add r1, #8
	add r1, r4, r1
	add r2, #0xe
	str r1, [sp, #8]
	add r1, r4, r2
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x18]
	str r1, [sp, #0x10]
	ldrb r1, [r4, #6]
	ldrb r2, [r4, #5]
	lsl r1, r1, #1
	add r1, r4, r1
	ldrh r1, [r1, #0x18]
	bl ov80_02236E90
	mov r0, #0xa
	lsl r0, r0, #6
	mov r7, #0
	add r6, r4, r0
_02230078:
	mov r0, #0xb
	bl AllocMonZeroed
	add r5, r0, #0
	add r0, r4, #0
	bl ov80_02237120
	add r2, r0, #0
	add r0, r6, #0
	add r1, r5, #0
	bl ov80_0222A140
	ldr r0, _022300CC ; =0x000004F8
	ldr r1, _022300D0 ; =0x000004D4
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	add r2, r5, #0
	bl ov80_0222A3BC
	add r0, r5, #0
	bl Heap_Free
	add r7, r7, #1
	add r6, #0x38
	cmp r7, #6
	blt _02230078
	ldr r6, _022300D0 ; =0x000004D4
	mov r5, #0
_022300B0:
	ldr r0, [r4, r6]
	add r1, r5, #0
	bl Party_GetMonByIndex
	add r5, r5, #1
	cmp r5, #6
	blt _022300B0
	add sp, #0x1fc
	add sp, #0xd8
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022300C4: .word 0x00000282
_022300C8: .word 0x000003D2
_022300CC: .word 0x000004F8
_022300D0: .word 0x000004D4
	thumb_func_end ov80_0222FF00


	thumb_func_start ov80_022300D4
ov80_022300D4: ; 0x022300D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xdc
	add r4, r0, #0
	add r5, r1, #0
	add r6, r2, #0
	bl LCRandom
	mov r1, #6
	bl _s32_div_f
	lsl r0, r1, #0x10
	lsr r2, r0, #0x10
	cmp r6, #0
	bne _022301B0
	mov r0, #0x95
	lsl r0, r0, #2
	add r1, r4, r0
	lsl r3, r5, #1
	str r1, [sp, #0x5c]
	ldrh r1, [r1, r3]
	str r3, [sp, #0x20]
	add r6, sp, #0xa4
	str r1, [sp, #0x1c]
	add r1, r0, #0
	add r1, #0xc
	add r1, r4, r1
	str r1, [sp, #0x24]
	ldrb r1, [r1, r5]
	mov r7, #7
	str r1, [sp, #0x18]
	add r1, r0, #0
	add r1, #0x14
	add r1, r4, r1
	str r1, [sp, #0x28]
	lsl r1, r5, #2
	ldr r3, [sp, #0x28]
	str r1, [sp, #0x2c]
	ldr r1, [r3, r1]
	add r0, #0x2c
	str r1, [sp, #0x14]
	add r1, r4, r0
	mov r0, #0x38
	mul r0, r5
	add r0, r1, r0
	str r0, [sp, #0x10]
	str r0, [sp, #0x30]
_02230130:
	ldr r3, [sp, #0x30]
	sub r7, r7, #1
	ldmia r3!, {r0, r1}
	str r3, [sp, #0x30]
	stmia r6!, {r0, r1}
	bne _02230130
	mov r0, #0x95
	lsl r0, r0, #2
	add r1, r4, r0
	str r1, [sp, #0x34]
	ldr r3, [sp, #0x34]
	lsl r1, r2, #1
	ldrh r6, [r3, r1]
	str r1, [sp, #0x38]
	ldr r3, [sp, #0x20]
	ldr r1, [sp, #0x5c]
	strh r6, [r1, r3]
	add r1, r0, #0
	add r1, #0xc
	add r1, r4, r1
	ldrb r3, [r1, r2]
	str r1, [sp, #0x3c]
	ldr r1, [sp, #0x24]
	strb r3, [r1, r5]
	add r1, r0, #0
	add r1, #0x14
	add r7, r4, r1
	lsl r1, r2, #2
	str r1, [sp, #0x60]
	ldr r5, [r7, r1]
	ldr r3, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	add r0, #0x2c
	str r5, [r3, r1]
	add r1, r4, r0
	mov r0, #0x38
	mul r0, r2
	add r6, r1, r0
	add r5, r6, #0
	mov r4, #7
_02230180:
	ldr r3, [sp, #0x10]
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	str r3, [sp, #0x10]
	sub r4, r4, #1
	bne _02230180
	ldr r3, [sp, #0x1c]
	ldr r1, [sp, #0x34]
	ldr r0, [sp, #0x38]
	strh r3, [r1, r0]
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x3c]
	add r3, sp, #0xa4
	strb r1, [r0, r2]
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x60]
	mov r2, #7
	str r1, [r7, r0]
_022301A4:
	ldmia r3!, {r0, r1}
	stmia r6!, {r0, r1}
	sub r2, r2, #1
	bne _022301A4
	add sp, #0xdc
	pop {r4, r5, r6, r7, pc}
_022301B0:
	ldr r0, _0223026C ; =0x00000584
	lsl r3, r5, #1
	add r1, r4, r0
	str r1, [sp, #0x64]
	ldrh r1, [r1, r3]
	str r3, [sp, #0x40]
	add r6, sp, #0x6c
	str r1, [sp, #8]
	add r1, r0, #0
	add r1, #0xc
	add r1, r4, r1
	str r1, [sp, #0x44]
	ldrb r1, [r1, r5]
	mov r7, #7
	str r1, [sp, #4]
	add r1, r0, #0
	add r1, #0x14
	add r1, r4, r1
	str r1, [sp, #0x48]
	lsl r1, r5, #2
	ldr r3, [sp, #0x48]
	str r1, [sp, #0x4c]
	ldr r1, [r3, r1]
	add r0, #0x2c
	str r1, [sp]
	add r1, r4, r0
	mov r0, #0x38
	mul r0, r5
	add r0, r1, r0
	str r0, [sp, #0xc]
	str r0, [sp, #0x50]
_022301EE:
	ldr r3, [sp, #0x50]
	sub r7, r7, #1
	ldmia r3!, {r0, r1}
	str r3, [sp, #0x50]
	stmia r6!, {r0, r1}
	bne _022301EE
	ldr r3, _0223026C ; =0x00000584
	add r0, r4, r3
	str r0, [sp, #0x54]
	ldr r1, [sp, #0x54]
	lsl r0, r2, #1
	ldrh r6, [r1, r0]
	str r0, [sp, #0x58]
	ldr r1, [sp, #0x40]
	ldr r0, [sp, #0x64]
	strh r6, [r0, r1]
	add r0, r3, #0
	add r0, #0xc
	add r0, r4, r0
	ldrb r1, [r0, r2]
	mov ip, r0
	ldr r0, [sp, #0x44]
	strb r1, [r0, r5]
	add r0, r3, #0
	add r0, #0x14
	add r7, r4, r0
	lsl r0, r2, #2
	str r0, [sp, #0x68]
	ldr r5, [r7, r0]
	ldr r1, [sp, #0x48]
	ldr r0, [sp, #0x4c]
	add r3, #0x2c
	str r5, [r1, r0]
	mov r0, #0x38
	add r1, r4, r3
	mul r0, r2
	add r5, r1, r0
	add r6, r5, #0
	mov r4, #7
_0223023C:
	ldr r3, [sp, #0xc]
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	str r3, [sp, #0xc]
	sub r4, r4, #1
	bne _0223023C
	ldr r3, [sp, #8]
	ldr r1, [sp, #0x54]
	ldr r0, [sp, #0x58]
	strh r3, [r1, r0]
	ldr r1, [sp, #4]
	mov r0, ip
	strb r1, [r0, r2]
	ldr r1, [sp]
	ldr r0, [sp, #0x68]
	add r3, sp, #0x6c
	str r1, [r7, r0]
	mov r2, #7
_02230260:
	ldmia r3!, {r0, r1}
	stmia r5!, {r0, r1}
	sub r2, r2, #1
	bne _02230260
	add sp, #0xdc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0223026C: .word 0x00000584
	thumb_func_end ov80_022300D4


	thumb_func_start ov80_02230270
ov80_02230270: ; 0x02230270
	push {r4, r5, r6, r7, lr}
	sub sp, #0x19c
	add r5, r0, #0
	ldrb r0, [r5, #4]
	bl ov80_02236DD4
	ldr r7, _0223040C ; =0x000004F4
	mov r4, #0
	add r6, r5, #0
_02230282:
	lsl r2, r4, #0x18
	ldr r0, [r5, r7]
	mov r1, #3
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030A24
	strh r0, [r6, #0x18]
	add r4, r4, #1
	add r6, r6, #2
	cmp r4, #0xe
	blt _02230282
	add r0, sp, #0x28
	mov r4, #0
	add r6, sp, #0x40
	str r0, [sp, #0x14]
	add r7, sp, #0x20
	str r5, [sp, #0x10]
_022302A6:
	ldr r0, _0223040C ; =0x000004F4
	lsl r2, r4, #0x18
	ldr r0, [r5, r0]
	mov r1, #4
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030A24
	strh r0, [r6]
	ldr r0, _0223040C ; =0x000004F4
	lsl r2, r4, #0x18
	ldr r0, [r5, r0]
	mov r1, #6
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030A24
	ldr r1, [sp, #0x14]
	lsl r2, r4, #0x18
	str r0, [r1]
	ldr r0, _0223040C ; =0x000004F4
	mov r1, #5
	ldr r0, [r5, r0]
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030A24
	strb r0, [r7]
	ldrh r2, [r6]
	ldr r1, [sp, #0x10]
	ldr r0, _02230410 ; =0x000004E8
	add r4, r4, #1
	strh r2, [r1, r0]
	ldr r0, [sp, #0x14]
	add r6, r6, #2
	add r0, r0, #4
	str r0, [sp, #0x14]
	add r0, r1, #0
	add r0, r0, #2
	add r7, r7, #1
	str r0, [sp, #0x10]
	cmp r4, #4
	blt _022302A6
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #0xb
	str r0, [sp, #8]
	mov r0, #0xcd
	str r0, [sp, #0xc]
	add r0, sp, #0x4c
	add r1, sp, #0x40
	add r2, sp, #0x20
	add r3, sp, #0x28
	bl ov80_0222A52C
	mov r0, #0xb
	bl AllocMonZeroed
	add r6, r0, #0
	mov r7, #0
	add r4, sp, #0x4c
_02230324:
	add r0, r5, #0
	bl ov80_02237120
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl ov80_0222A140
	ldr r0, _02230414 ; =0x000004F8
	ldr r1, _02230418 ; =0x000004D4
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl ov80_0222A3BC
	add r7, r7, #1
	add r4, #0x38
	cmp r7, #4
	blt _02230324
	add r0, r6, #0
	bl Heap_Free
	add r0, sp, #0x28
	mov r4, #0
	add r6, sp, #0x40
	str r0, [sp, #0x1c]
	add r7, sp, #0x20
	str r5, [sp, #0x18]
_0223035C:
	ldr r0, _0223040C ; =0x000004F4
	lsl r2, r4, #0x18
	ldr r0, [r5, r0]
	mov r1, #7
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030A24
	strh r0, [r6]
	ldr r0, _0223040C ; =0x000004F4
	lsl r2, r4, #0x18
	ldr r0, [r5, r0]
	mov r1, #9
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030A24
	ldr r1, [sp, #0x1c]
	lsl r2, r4, #0x18
	str r0, [r1]
	ldr r0, _0223040C ; =0x000004F4
	mov r1, #8
	ldr r0, [r5, r0]
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030A24
	strb r0, [r7]
	ldrh r2, [r6]
	ldr r1, [sp, #0x18]
	ldr r0, _0223041C ; =0x000003D2
	add r4, r4, #1
	strh r2, [r1, r0]
	ldr r0, [sp, #0x1c]
	add r6, r6, #2
	add r0, r0, #4
	str r0, [sp, #0x1c]
	add r0, r1, #0
	add r0, r0, #2
	add r7, r7, #1
	str r0, [sp, #0x18]
	cmp r4, #4
	blt _0223035C
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #0xb
	str r0, [sp, #8]
	mov r0, #0xcd
	str r0, [sp, #0xc]
	add r0, sp, #0x4c
	add r1, sp, #0x40
	add r2, sp, #0x20
	add r3, sp, #0x28
	bl ov80_0222A52C
	mov r0, #0xb
	bl AllocMonZeroed
	add r6, r0, #0
	mov r7, #0
	add r4, sp, #0x4c
_022303DA:
	add r0, r5, #0
	bl ov80_02237120
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl ov80_0222A140
	ldr r0, _02230414 ; =0x000004F8
	ldr r1, _02230420 ; =0x000004D8
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl ov80_0222A3BC
	add r7, r7, #1
	add r4, #0x38
	cmp r7, #4
	blt _022303DA
	add r0, r6, #0
	bl Heap_Free
	add sp, #0x19c
	pop {r4, r5, r6, r7, pc}
	nop
_0223040C: .word 0x000004F4
_02230410: .word 0x000004E8
_02230414: .word 0x000004F8
_02230418: .word 0x000004D4
_0223041C: .word 0x000003D2
_02230420: .word 0x000004D8
	thumb_func_end ov80_02230270
