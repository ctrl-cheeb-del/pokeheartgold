	.include "asm/macros.inc"
	.public _02232520
	.public _02232546
	.public _02232552
	.public _02232592
	.public _022325F2
	.public _02232630
	.public _022326BA
	.public _0223271C
	.public _0223273E
	.public _02232744
	.public _0223278E
	.public _022327EE
	.public _022327F8
	.public _02232810
	.public _02232818
	.public _0223281C
	.public _02232820
	.public _02232830
	.public _02232852
	.public _022328A0
	.public _02232900
	.public _02232904
	.public _02232918
	.public _02232938
	.public _02232986
	.public _022329CE
	.public _02232AB6
	.public _02232ACC
	.public _02232AD6
	.public _02232AE6
	.public _02232AE8
	.public _02232AF6
	.public _02232B12
	.public _02232B40
	.public _02232B52
	.public _02232C6E
	.public _02232C94
	.public _02232CCA
	.public _02232CD0
	.public _02232CF8
	.public _02232D2A
	.public _02232E10
	.public _02232E1E
	.public _02232E4E
	.public _02232E54
	.public _02232EA2
	.public _02232EF2
	.public _02232EFC
	.public _02232F04
	.public _02232F74
	.public _02232F78
	.public _02232F96
	.public _02232FEA
	.public _02233002
	.public _02233018
	.public _0223301C
	.public _0223302E
	.public _02233048
	.public _0223304C
	.public _02233070
	.public _022330B6
	.public _022330C6
	.public _022330CC
	.public _022330E2
	.public _022330E6
	.public _02233116
	.public _02233122
	.public _02233130
	.public _0223313E
	.public _02233146
	.public _02233154
	.public _02233158
	.public _0223316E
	.public _0223317E
	.public _0223318C
	.public _02233198
	.public _022331E0
	.public _02233244
	.public _0223326A
	.public _0223327C
	.public _02233292
	.public _022332A0
	.public _022332A6
	.public _022332AC
	.public _022332B2
	.public _022332B8
	.public _022332C0
	.public _022332C8
	.public _022332CC
	.public _022332EC
	.public _022332FA
	.public _02233342
	.public _022333BA
	.public _022333C8
	.public _022333CC
	.public _022333EC
	.public _0223340C
	.public _02233424
	.public _02233432
	.public _02233440
	.public _02233454
	.public _0223345E
	.public _02233480
	.public _022334AE
	.public _022334EA
	.public _022334F8
	.public _02233506
	.public _0223353A
	.public _02233564
	.public _02233590
	.public _02233658
	.public _0223365E
	.public _02233666
	.public _0223366A
	.public _02233678
	.public _0223367A
	.public _02233680
	.public _02233684
	.public ov80_022324C4
	.public ov80_02232824
	.public ov80_02232838
	.public ov80_02232908
	.public ov80_022329B4
	.public ov80_02232ABC
	.public ov80_02232AEC
	.public ov80_02232B44
	.public ov80_02232B58
	.public ov80_02232E58
	.public ov80_02232E64
	.public ov80_02232E68
	.public ov80_02232E9C
	.public ov80_02232EE0
	.public ov80_02232F00
	.public ov80_02232F08
	.public ov80_02232F60
	.public ov80_02233020
	.public ov80_022331E8
	.public ov80_02233280
	.public ov80_022332D0
	.public ov80_022333D0
	.public ov80_022333F0
	.public ov80_02233490
	.public ov80_02233594
	.public ov80_02233648
	.public ov80_0223DD48
	.include "overlay_80_022324C4.inc"
	.include "global.inc"

    .text
	.public ov80_02232824
	.public ov80_02232ABC
	.public ov80_02232B44
	.public ov80_02232E58
	.public ov80_02232E64
	.public ov80_02232E68
	.public ov80_02232E9C
	.public ov80_02232EE0
	.public ov80_02232F00
	.public ov80_022331E8
	.public ov80_02233280
	.public ov80_022333D0
	.public ov80_022333F0
	.public ov80_02233648

	thumb_func_start ov80_02232B58
ov80_02232B58: ; 0x02232B58
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	add r5, r0, #0
	ldr r0, [r5, #4]
	add r6, r1, #0
	bl sub_02030E08
	str r0, [sp, #4]
	ldr r0, [r5, #4]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	ldrb r0, [r5, #0x10]
	mov r1, #1
	bl ov80_02237B58
	ldrb r1, [r5, #0x10]
	add r0, sp, #0x10
	strb r1, [r0, #8]
	mov r1, #0
	add r0, sp, #0x18
	str r0, [sp]
	ldr r0, [r5, #8]
	add r2, r1, #0
	add r3, r1, #0
	bl sub_02030CF4
	ldr r0, [r5, #8]
	mov r1, #1
	bl sub_02030CE0
	mov r2, #0
	ldrb r1, [r5, #0x11]
	add r0, sp, #0x10
	add r3, r2, #0
	strb r1, [r0, #8]
	add r0, sp, #0x18
	str r0, [sp]
	ldr r0, [r5, #8]
	mov r1, #1
	bl sub_02030CF4
	ldrb r0, [r5, #0x10]
	bl sub_0205C1A0
	add r7, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1A0
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #0x14]
	add r0, r4, #0
	add r1, r7, #0
	bl sub_02031108
	cmp r6, #2
	beq _02232CCA
	ldrb r0, [r5, #0x10]
	bl sub_0205C1C8
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1C8
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl FrontierSave_GetStat
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1C8
	add r7, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1C8
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #0x14]
	add r0, r4, #0
	add r1, r7, #0
	bl sub_0203126C
	ldrb r0, [r5, #0x10]
	bl sub_0205C1C8
	add r7, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1C8
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r7, #0
	bl FrontierSave_GetStat
	str r0, [sp, #0xc]
	ldrb r0, [r5, #0x10]
	bl sub_0205C1F0
	add r7, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1F0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r7, #0
	bl FrontierSave_GetStat
	add r7, r0, #0
	ldrh r0, [r5, #0x14]
	cmp r0, r6
	bne _02232C6E
	ldrb r0, [r5, #0x10]
	bl sub_0205C240
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C240
	bl sub_0205C268
	lsl r3, r7, #0x10
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	lsr r3, r3, #0x10
	bl sub_0203126C
	b _02232C94
_02232C6E:
	ldr r0, [sp, #0xc]
	cmp r6, r0
	bhs _02232C94
	ldrb r0, [r5, #0x10]
	bl sub_0205C240
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C240
	bl sub_0205C268
	lsl r3, r7, #0x10
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	lsr r3, r3, #0x10
	bl sub_02031108
_02232C94:
	add r0, r5, #0
	add r0, #0x27
	ldrb r1, [r0]
	add r0, sp, #0x10
	mov r3, #0
	strb r1, [r0, #8]
	add r0, sp, #0x18
	str r0, [sp]
	ldrb r2, [r5, #0x10]
	ldr r0, [sp, #4]
	mov r1, #9
	bl sub_02030E18
	ldrb r0, [r5, #0x10]
	cmp r0, #3
	bne _02232CCA
	mov r0, #0x6c
	bl sub_0205C268
	add r3, r5, #0
	add r3, #0x27
	add r2, r0, #0
	ldrb r3, [r3]
	add r0, r4, #0
	mov r1, #0x6c
	bl sub_02031108
_02232CCA:
	mov r4, #0
	add r6, sp, #0x10
	add r7, sp, #0x10
_02232CD0:
	lsl r0, r4, #1
	add r0, r5, r0
	ldrh r0, [r0, #0x30]
	lsl r2, r4, #0x18
	mov r1, #6
	strh r0, [r7]
	str r6, [sp]
	ldr r0, [r5, #8]
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030CF4
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #0xe
	blo _02232CD0
	mov r4, #0
	add r6, sp, #0x18
	add r7, sp, #0x10
_02232CF8:
	add r0, r5, r4
	add r0, #0x24
	ldrb r0, [r0]
	lsl r2, r4, #0x18
	mov r1, #7
	strb r0, [r7, #8]
	str r6, [sp]
	ldr r0, [r5, #8]
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030CF4
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #3
	blo _02232CF8
	ldr r0, [r5, #0x28]
	bl Party_GetCount
	mov r4, #0
	str r0, [sp, #8]
	cmp r0, #0
	bls _02232E10
	add r7, sp, #0x10
_02232D2A:
	ldr r0, [r5, #0x28]
	add r1, r4, #0
	bl Party_GetMonByIndex
	mov r1, #0xa3
	mov r2, #0
	add r6, r0, #0
	bl GetMonData
	strh r0, [r7]
	add r0, sp, #0x10
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #2
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030CF4
	add r0, r6, #0
	mov r1, #0x3a
	mov r2, #0
	bl GetMonData
	strb r0, [r7, #8]
	add r0, sp, #0x18
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #3
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030CF4
	add r0, r6, #0
	mov r1, #0x3b
	mov r2, #0
	bl GetMonData
	strb r0, [r7, #8]
	add r0, sp, #0x18
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #3
	lsr r2, r2, #0x18
	mov r3, #1
	bl sub_02030CF4
	add r0, r6, #0
	mov r1, #0x3c
	mov r2, #0
	bl GetMonData
	strb r0, [r7, #8]
	add r0, sp, #0x18
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #3
	lsr r2, r2, #0x18
	mov r3, #2
	bl sub_02030CF4
	add r0, r6, #0
	mov r1, #0x3d
	mov r2, #0
	bl GetMonData
	strb r0, [r7, #8]
	add r0, sp, #0x18
	str r0, [sp]
	mov r1, #3
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	lsr r2, r2, #0x18
	add r3, r1, #0
	bl sub_02030CF4
	add r0, r6, #0
	mov r1, #0xa0
	mov r2, #0
	bl GetMonData
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #4
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030CF4
	add r0, r6, #0
	mov r1, #6
	mov r2, #0
	bl GetMonData
	strh r0, [r7]
	add r0, sp, #0x10
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #5
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030CF4
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	ldr r0, [sp, #8]
	cmp r4, r0
	blo _02232D2A
_02232E10:
	ldr r0, [r5, #0x2c]
	bl Party_GetCount
	add r6, r0, #0
	ldr r4, _02232E54 ; =0x00000000
	beq _02232E4E
	add r7, sp, #0x10
_02232E1E:
	ldr r0, [r5, #0x2c]
	add r1, r4, #0
	bl Party_GetMonByIndex
	lsl r0, r4, #1
	add r1, r5, r0
	mov r0, #0x9b
	lsl r0, r0, #2
	ldrh r1, [r1, r0]
	add r0, sp, #0x10
	lsl r2, r4, #0x18
	strh r1, [r0]
	str r7, [sp]
	ldr r0, [r5, #8]
	mov r1, #8
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030CF4
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, r6
	blo _02232E1E
_02232E4E:
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	nop
_02232E54: .word 0x00000000
	thumb_func_end ov80_02232B58
