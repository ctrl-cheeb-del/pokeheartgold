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

	thumb_func_start ov80_022318D0
ov80_022318D0: ; 0x022318D0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r1, #0
	add r5, r2, #0
	add r6, r3, #0
	ldr r4, [sp, #0x20]
	bl Save_Frontier_GetStatic
	str r0, [sp]
	add r0, r7, #0
	add r1, r5, #0
	bl sub_0205C0A0
	str r0, [sp, #4]
	add r0, r7, #0
	add r1, r5, #0
	bl sub_0205C0A0
	bl sub_0205C268
	add r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FrontierSave_GetStat
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	mov r0, #0xf
	and r0, r1
	strh r0, [r6]
	asr r0, r1, #4
	strh r0, [r4]
	lsr r2, r5, #0x1f
	lsl r1, r5, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	bne _02231928
	add sp, #8
	ldrh r0, [r6]
	pop {r3, r4, r5, r6, r7, pc}
_02231928:
	ldrh r0, [r4]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_022318D0


	thumb_func_start ov80_02231930
ov80_02231930: ; 0x02231930
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r3, #0
	add r3, sp, #0xc
	str r3, [sp]
	add r3, sp, #0xc
	add r3, #2
	str r0, [sp, #4]
	add r6, r1, #0
	add r5, r2, #0
	bl ov80_022318D0
	add r0, sp, #0xc
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsr r3, r5, #0x1f
	lsl r1, r1, #4
	orr r0, r1
	lsl r2, r5, #0x1f
	lsl r0, r0, #0x18
	sub r2, r2, r3
	mov r1, #0x1f
	ror r2, r1
	add r1, r3, r2
	lsl r1, r1, #0x18
	lsr r0, r0, #0x18
	lsr r1, r1, #0x18
	bne _0223196C
	mov r2, #0xf0
	b _0223196E
_0223196C:
	mov r2, #0xf
_0223196E:
	and r0, r2
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	lsl r0, r1, #2
	add r1, r7, #0
	lsl r1, r0
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	orr r4, r0
	ldr r0, [sp, #4]
	bl Save_Frontier_GetStatic
	add r7, r0, #0
	add r0, r6, #0
	add r1, r5, #0
	bl sub_0205C0A0
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r5, #0
	bl sub_0205C0A0
	bl sub_0205C268
	add r2, r0, #0
	ldr r1, [sp, #8]
	add r0, r7, #0
	add r3, r4, #0
	bl sub_02031108
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_02231930
