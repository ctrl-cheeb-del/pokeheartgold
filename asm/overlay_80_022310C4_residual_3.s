	.include "asm/macros.inc"
	.public _02231158
	.public _02231164
	.public _022311A6
	.public _022311B0
	.public _022311CA
	.public _022311E0
	.public _0223124C
	.public _02231272
	.public _02231276
	.public _0223129C
	.public _022312CA
	.public _022312D2
	.public _02231304
	.public _02231324
	.public _0223133E
	.public _02231344
	.public _0223137E
	.public _02231398
	.public _022313A0
	.public _022313A4
	.public _022313A8
	.public _022313AC
	.public _022313B0
	.public _022313B4
	.public _022313B8
	.public _022313BC
	.public _022313C4
	.public _022313DA
	.public _02231444
	.public _02231450
	.public _0223145A
	.public _02231490
	.public _02231494
	.public _02231498
	.public _0223149C
	.public _022314B4
	.public _022314C0
	.public _022314D0
	.public _022314D4
	.public _022314D8
	.public _0223150E
	.public _02231510
	.public _02231514
	.public _0223156E
	.public _02231578
	.public _02231658
	.public _0223167C
	.public _0223169A
	.public _022316C8
	.public _022316CE
	.public _022316F8
	.public _02231726
	.public _02231758
	.public _022317B4
	.public _022317B8
	.public _022317BC
	.public _02231824
	.public _02231836
	.public _02231840
	.public _02231856
	.public _02231866
	.public _0223186C
	.public _02231872
	.public _02231878
	.public _02231882
	.public _02231886
	.public _02231898
	.public _0223189E
	.public _022318A6
	.public _022318AA
	.public _022318B8
	.public _022318BC
	.public _022318C2
	.public _022318C8
	.public _022318CC
	.public _02231928
	.public _0223196C
	.public _0223196E
	.public _022319C0
	.public _022319DA
	.public _022319E6
	.public _022319FE
	.public _02231A00
	.public _02231A48
	.public _02231A60
	.public _02231A6E
	.public _02231AC2
	.public _02231ADC
	.public _02231AEA
	.public _02231B00
	.public _02231B08
	.public _02231B26
	.public _02231B4E
	.public _02231B7C
	.public _02231BC8
	.public _02231BD0
	.public _02231BD6
	.public _02231BE0
	.public _02231BE4
	.public _02231BE8
	.public _02231BEC
	.public _02231BF0
	.public _02231BF4
	.public ov80_022310C4
	.public ov80_022313C0
	.public ov80_022313C8
	.public ov80_022314A0
	.public ov80_022314DC
	.public ov80_02231518
	.public ov80_0223151C
	.public ov80_0223157C
	.public ov80_022317C0
	.public ov80_022317CC
	.public ov80_022317D0
	.public ov80_02231804
	.public ov80_02231828
	.public ov80_02231844
	.public ov80_02231888
	.public ov80_022318D0
	.public ov80_02231930
	.public ov80_022319B0
	.public ov80_02231A04
	.public ov80_02231A14
	.public ov80_0223DD44
	.include "overlay_80_022310C4.inc"
	.include "global.inc"

    .text
	.public ov80_022313C0
	.public ov80_022314A0
	.public ov80_022314DC
	.public ov80_02231518
	.public ov80_022317C0
	.public ov80_022317CC
	.public ov80_022317D0
	.public ov80_02231804
	.public ov80_02231828
	.public ov80_02231844
	.public ov80_02231888
	.public ov80_022319B0
	.public ov80_02231A04

	thumb_func_start ov80_0223151C
ov80_0223151C: ; 0x0223151C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r0, #0
	ldrb r6, [r5, #4]
	add r4, r1, #0
	cmp r6, #3
	beq _0223156E
	add r0, r6, #0
	bl sub_0205C0F4
	add r7, r0, #0
	ldrb r0, [r5, #4]
	bl sub_0205C11C
	str r0, [sp, #0x10]
	ldrb r0, [r5, #4]
	bl sub_0205C0F4
	bl sub_0205C268
	str r0, [sp, #0x14]
	add r0, r6, #0
	bl sub_0205C144
	str r0, [sp]
	mov r0, #0xb
	str r0, [sp, #4]
	add r0, sp, #0x1c
	str r0, [sp, #8]
	add r0, sp, #0x18
	str r0, [sp, #0xc]
	ldr r0, _02231578 ; =0x000006FC
	ldr r2, [sp, #0x10]
	ldr r0, [r5, r0]
	ldr r3, [sp, #0x14]
	add r1, r7, #0
	bl sub_020313C4
	add sp, #0x20
	strh r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_0223156E:
	mov r0, #0
	strh r0, [r4]
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02231578: .word 0x000006FC
	thumb_func_end ov80_0223151C


	thumb_func_start ov80_0223157C
ov80_0223157C: ; 0x0223157C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r0, #0
	ldr r0, _022317B4 ; =0x000006FC
	add r4, r1, #0
	ldr r0, [r5, r0]
	bl sub_02030C5C
	str r0, [sp, #4]
	ldr r0, _022317B4 ; =0x000006FC
	ldr r0, [r5, r0]
	bl Save_Frontier_GetStatic
	str r0, [sp, #0xc]
	ldrb r1, [r5, #4]
	add r0, sp, #0x14
	strb r1, [r0, #8]
	mov r1, #0
	add r0, sp, #0x1c
	str r0, [sp]
	ldr r0, _022317B8 ; =0x000006F8
	add r2, r1, #0
	ldr r0, [r5, r0]
	add r3, r1, #0
	bl sub_02030B30
	ldr r0, _022317B8 ; =0x000006F8
	mov r1, #1
	ldr r0, [r5, r0]
	bl sub_02030B1C
	ldr r0, _022317B4 ; =0x000006FC
	ldr r0, [r5, r0]
	bl SaveArray_Party_Get
	mov r1, #0x26
	lsl r1, r1, #4
	ldrb r1, [r5, r1]
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	str r0, [sp, #8]
	bl GetMonData
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	ldrb r0, [r5, #4]
	bl sub_0205C11C
	add r7, r0, #0
	ldrb r0, [r5, #4]
	bl sub_0205C11C
	bl sub_0205C268
	add r2, r0, #0
	ldr r0, [sp, #0xc]
	add r1, r7, #0
	bl FrontierSave_GetStat
	add r7, r0, #0
	mov r2, #0
	ldrb r1, [r5, #5]
	add r0, sp, #0x14
	add r3, r2, #0
	strb r1, [r0, #8]
	add r0, sp, #0x1c
	str r0, [sp]
	ldr r0, _022317B8 ; =0x000006F8
	mov r1, #1
	ldr r0, [r5, r0]
	bl sub_02030B30
	ldrb r0, [r5, #4]
	bl sub_0205C0CC
	str r0, [sp, #0x10]
	ldrb r0, [r5, #4]
	bl sub_0205C0CC
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #8]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	bl sub_02031108
	cmp r4, #2
	beq _022316C8
	ldrb r4, [r5, #4]
	cmp r4, #3
	beq _02231658
	add r0, r4, #0
	bl sub_0205C0F4
	add r6, r0, #0
	add r0, r4, #0
	bl sub_0205C0F4
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #8]
	ldr r0, [sp, #0xc]
	add r1, r6, #0
	bl sub_02031108
	b _0223169A
_02231658:
	cmp r7, r6
	beq _0223167C
	add r0, r4, #0
	bl sub_0205C0F4
	add r6, r0, #0
	add r0, r4, #0
	bl sub_0205C0F4
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #8]
	ldr r0, [sp, #0xc]
	add r1, r6, #0
	bl sub_02031108
	b _0223169A
_0223167C:
	add r0, r4, #0
	bl sub_0205C0F4
	add r6, r0, #0
	add r0, r4, #0
	bl sub_0205C0F4
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #8]
	ldr r0, [sp, #0xc]
	add r1, r6, #0
	bl sub_0203126C
_0223169A:
	ldrb r1, [r5, #6]
	add r0, sp, #0x14
	mov r3, #0
	strb r1, [r0, #8]
	add r0, sp, #0x1c
	str r0, [sp]
	ldrb r2, [r5, #4]
	ldr r0, [sp, #4]
	mov r1, #5
	bl sub_02030C6C
	ldrb r0, [r5, #4]
	cmp r0, #3
	bne _022316C8
	mov r0, #0x6a
	bl sub_0205C268
	add r2, r0, #0
	ldrb r3, [r5, #6]
	ldr r0, [sp, #0xc]
	mov r1, #0x6a
	bl sub_02031108
_022316C8:
	mov r4, #0
	add r6, sp, #0x14
	add r7, sp, #0x14
_022316CE:
	lsl r0, r4, #1
	add r0, r5, r0
	ldrh r0, [r0, #0x18]
	lsl r2, r4, #0x18
	mov r1, #2
	strh r0, [r7]
	ldr r0, _022317B8 ; =0x000006F8
	str r6, [sp]
	ldr r0, [r5, r0]
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030B30
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #0x14
	blo _022316CE
	mov r4, #0
	add r6, sp, #0x1c
	add r7, sp, #0x14
_022316F8:
	mov r0, #0x26
	add r1, r5, r4
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	lsl r2, r4, #0x18
	mov r1, #3
	strb r0, [r7, #8]
	ldr r0, _022317B8 ; =0x000006F8
	str r6, [sp]
	ldr r0, [r5, r0]
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030B30
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #2
	blo _022316F8
	ldr r0, _022317BC ; =0x00000704
	mov r4, #0
	add r6, r5, r0
	add r7, sp, #0x14
_02231726:
	ldrb r2, [r5, #4]
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	lsl r1, r2, #3
	add r1, r2, r1
	add r1, r6, r1
	bl sub_02030BD0
	strb r0, [r7, #8]
	ldr r0, _022317B4 ; =0x000006FC
	lsl r2, r4, #0x18
	ldrb r1, [r5, #4]
	ldrb r3, [r7, #8]
	ldr r0, [r5, r0]
	lsr r2, r2, #0x18
	bl ov80_02231930
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #0x12
	blo _02231726
	mov r4, #0
	add r6, sp, #0x14
	add r7, sp, #0x14
_02231758:
	lsl r0, r4, #1
	add r1, r5, r0
	mov r0, #0x9a
	lsl r0, r0, #2
	ldrh r0, [r1, r0]
	lsl r2, r4, #0x18
	mov r1, #4
	strh r0, [r7]
	ldr r0, _022317B8 ; =0x000006F8
	str r6, [sp]
	ldr r0, [r5, r0]
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030B30
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #0x14
	blo _02231758
	ldrb r0, [r5, #4]
	bl sub_0205C11C
	add r4, r0, #0
	ldrb r0, [r5, #4]
	bl sub_0205C11C
	bl sub_0205C268
	add r5, r0, #0
	ldr r0, [sp, #8]
	mov r1, #5
	mov r2, #0
	bl GetMonData
	add r3, r0, #0
	lsl r3, r3, #0x10
	ldr r0, [sp, #0xc]
	add r1, r4, #0
	add r2, r5, #0
	lsr r3, r3, #0x10
	bl sub_02031108
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022317B4: .word 0x000006FC
_022317B8: .word 0x000006F8
_022317BC: .word 0x00000704
	thumb_func_end ov80_0223157C
