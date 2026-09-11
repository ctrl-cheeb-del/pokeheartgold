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

	thumb_func_start ov80_022310C4
ov80_022310C4: ; 0x022310C4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r1, #0
	str r0, [sp, #4]
	ldr r1, _022313A0 ; =0x00000D98
	mov r0, #0xb
	add r6, r2, #0
	str r3, [sp, #8]
	bl Heap_Alloc
	ldr r1, _022313A4 ; =ov80_0223DD44
	ldr r2, _022313A0 ; =0x00000D98
	str r0, [r1]
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, _022313A4 ; =ov80_0223DD44
	ldr r4, [r0]
	ldr r0, [sp, #4]
	bl sub_02030B04
	ldr r1, _022313A8 ; =0x000006F8
	str r0, [r4, r1]
	ldr r0, [sp, #4]
	add r1, r1, #4
	str r0, [r4, r1]
	mov r0, #0xb
	ldr r1, _022313A4 ; =ov80_0223DD44
	str r0, [r4]
	ldr r4, [r1]
	bl SaveArray_Party_Alloc
	mov r1, #0x99
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0xb
	bl AllocMonZeroed
	ldr r1, _022313AC ; =0x00000D8C
	str r0, [r4, r1]
	ldr r0, _022313A8 ; =0x000006F8
	ldr r4, [r4, r0]
	ldr r0, [sp, #4]
	bl sub_02030C5C
	str r0, [sp, #0xc]
	cmp r5, #0
	bne _022311E0
	ldr r0, _022313A4 ; =ov80_0223DD44
	ldr r0, [r0]
	strb r6, [r0, #4]
	ldrb r0, [r0, #4]
	bl ov80_0223787C
	add r6, r0, #0
	ldr r0, _022313A4 ; =ov80_0223DD44
	mov r1, #0
	ldr r0, [r0]
	strb r1, [r0, #5]
	add r0, r4, #0
	bl sub_02030AF8
	ldr r0, _022313A4 ; =ov80_0223DD44
	ldr r1, [r0]
	ldrb r2, [r1, #4]
	cmp r2, #3
	bne _02231158
	ldr r0, _022313B0 ; =0x000006FC
	ldr r0, [r1, r0]
	bl Save_VarsFlags_Get
	bl Save_VarsFlags_GetVar4052
	b _02231164
_02231158:
	ldr r0, [sp, #0xc]
	mov r3, #0
	mov r1, #5
	str r3, [sp]
	bl sub_02030CA0
_02231164:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bne _022311A6
	ldr r0, _022313A4 ; =ov80_0223DD44
	ldr r1, [r0]
	ldr r0, _022313B0 ; =0x000006FC
	ldr r0, [r1, r0]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	ldr r0, _022313A4 ; =ov80_0223DD44
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	bl sub_0205C0CC
	add r5, r0, #0
	ldr r0, _022313A4 ; =ov80_0223DD44
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	bl sub_0205C0CC
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r5, #0
	bl FrontierSave_GetStat
	ldr r1, _022313A4 ; =ov80_0223DD44
	ldr r1, [r1]
	strh r0, [r1, #8]
	b _022311CA
_022311A6:
	ldr r5, _022313A4 ; =ov80_0223DD44
	mov r4, #0
	ldr r0, [r5]
	ldr r7, _022313B0 ; =0x000006FC
	strh r4, [r0, #8]
_022311B0:
	ldr r1, [r5]
	lsl r2, r4, #0x18
	ldr r0, [r1, r7]
	ldrb r1, [r1, #4]
	lsr r2, r2, #0x18
	mov r3, #0
	bl ov80_02231930
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #0x12
	blo _022311B0
_022311CA:
	ldr r0, _022313A4 ; =ov80_0223DD44
	mov r1, #0x26
	ldr r3, [r0]
	ldr r0, [sp, #8]
	lsl r1, r1, #4
	strb r0, [r3, r1]
	add r0, sp, #0x20
	ldrb r2, [r0, #0x10]
	add r0, r1, #1
	strb r2, [r3, r0]
	b _022312CA
_022311E0:
	ldr r0, _022313A4 ; =ov80_0223DD44
	mov r1, #0
	ldr r5, [r0]
	str r1, [sp]
	add r0, r4, #0
	add r2, r1, #0
	add r3, r1, #0
	bl sub_02030B88
	strb r0, [r5, #4]
	ldrb r0, [r5, #4]
	bl ov80_0223787C
	mov r2, #0
	add r6, r0, #0
	ldr r0, _022313A4 ; =ov80_0223DD44
	str r2, [sp]
	ldr r5, [r0]
	add r0, r4, #0
	mov r1, #1
	add r3, r2, #0
	bl sub_02030B88
	strb r0, [r5, #5]
	ldr r0, _022313A4 ; =ov80_0223DD44
	ldr r1, [r0]
	ldr r0, _022313B0 ; =0x000006FC
	ldr r0, [r1, r0]
	bl Save_Frontier_GetStatic
	add r7, r0, #0
	ldr r0, _022313A4 ; =ov80_0223DD44
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	bl sub_0205C0CC
	str r0, [sp, #0x10]
	ldrb r0, [r5, #4]
	bl sub_0205C0CC
	bl sub_0205C268
	add r2, r0, #0
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	bl FrontierSave_GetStat
	ldr r1, _022313A4 ; =ov80_0223DD44
	mov r5, #0
	ldr r1, [r1]
	cmp r6, #0
	strh r0, [r1, #8]
	ble _02231272
	add r7, r5, #0
_0223124C:
	lsl r2, r5, #0x18
	add r0, r4, #0
	mov r1, #3
	lsr r2, r2, #0x18
	add r3, r7, #0
	str r7, [sp]
	bl sub_02030B88
	ldr r1, _022313A4 ; =ov80_0223DD44
	ldr r1, [r1]
	add r2, r1, r5
	mov r1, #0x26
	lsl r1, r1, #4
	strb r0, [r2, r1]
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, r6
	blt _0223124C
_02231272:
	mov r5, #0
	add r7, r5, #0
_02231276:
	lsl r2, r5, #0x18
	add r0, r4, #0
	mov r1, #2
	lsr r2, r2, #0x18
	add r3, r7, #0
	str r7, [sp]
	bl sub_02030B88
	ldr r1, _022313A4 ; =ov80_0223DD44
	ldr r2, [r1]
	lsl r1, r5, #1
	add r1, r2, r1
	strh r0, [r1, #0x18]
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #0x14
	blo _02231276
	mov r5, #0
_0223129C:
	ldr r0, _022313A4 ; =ov80_0223DD44
	lsl r2, r5, #0x18
	ldr r7, [r0]
	mov r0, #0
	str r0, [sp]
	add r0, r4, #0
	mov r1, #4
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030B88
	lsl r1, r5, #1
	lsl r0, r0, #0x18
	add r2, r7, r1
	mov r1, #0x9a
	lsr r0, r0, #0x18
	lsl r1, r1, #2
	strh r0, [r2, r1]
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #0x14
	blo _0223129C
_022312CA:
	mov r5, #0
	cmp r6, #0
	ble _02231304
	ldr r7, _022313A4 ; =ov80_0223DD44
_022312D2:
	ldr r4, [r7]
	ldr r0, _022313B0 ; =0x000006FC
	ldr r0, [r4, r0]
	bl SaveArray_Party_Get
	mov r1, #0x26
	add r2, r4, r5
	lsl r1, r1, #4
	ldrb r1, [r2, r1]
	bl Party_GetMonByIndex
	ldr r4, [r7]
	mov r1, #6
	mov r2, #0
	bl GetMonData
	lsl r1, r5, #1
	add r2, r4, r1
	ldr r1, _022313B4 ; =0x00000728
	strh r0, [r2, r1]
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, r6
	blt _022312D2
_02231304:
	ldr r0, _022313A4 ; =ov80_0223DD44
	mov r1, #0xa
	ldr r4, [r0]
	mov r0, #0
	str r0, [r4, #0x10]
	ldrh r0, [r4, #8]
	bl _s32_div_f
	strh r0, [r4, #0xa]
	ldrb r0, [r4, #4]
	cmp r0, #2
	bne _0223133E
	ldr r4, _022313A4 ; =ov80_0223DD44
	ldr r6, _022313B8 ; =0x00000716
	mov r5, #0
	mov r7, #9
_02231324:
	ldr r1, [r4]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	add r1, r1, r6
	add r2, r7, #0
	bl sub_02030BF4
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #0x12
	blo _02231324
	b _0223137E
_0223133E:
	ldr r5, _022313A4 ; =ov80_0223DD44
	mov r4, #0
	add r7, sp, #0x14
_02231344:
	ldr r1, [r5]
	str r7, [sp]
	ldrb r1, [r1, #4]
	lsl r2, r4, #0x18
	add r3, sp, #0x14
	ldr r0, [sp, #4]
	lsr r2, r2, #0x18
	add r3, #2
	bl ov80_022318D0
	add r2, r0, #0
	lsl r0, r4, #0x18
	lsl r2, r2, #0x18
	ldr r1, [r5]
	ldr r3, _022313BC ; =0x00000704
	lsr r0, r0, #0x18
	add r6, r1, r3
	ldrb r3, [r1, #4]
	lsr r2, r2, #0x18
	lsl r1, r3, #3
	add r1, r3, r1
	add r1, r6, r1
	bl sub_02030BF4
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #0x12
	blo _02231344
_0223137E:
	ldr r0, _022313A4 ; =ov80_0223DD44
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	bl ov80_0223792C
	cmp r0, #1
	bne _02231398
	ldr r0, _022313A4 ; =ov80_0223DD44
	ldr r1, [r0]
	ldr r0, _022313B0 ; =0x000006FC
	ldr r0, [r1, r0]
	bl ov80_0222A840
_02231398:
	ldr r0, _022313A4 ; =ov80_0223DD44
	ldr r0, [r0]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022313A0: .word 0x00000D98
_022313A4: .word ov80_0223DD44
_022313A8: .word 0x000006F8
_022313AC: .word 0x00000D8C
_022313B0: .word 0x000006FC
_022313B4: .word 0x00000728
_022313B8: .word 0x00000716
_022313BC: .word 0x00000704
	thumb_func_end ov80_022310C4
