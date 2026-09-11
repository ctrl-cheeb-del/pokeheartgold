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

	thumb_func_start ov80_022324C4
ov80_022324C4: ; 0x022324C4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r7, r1, #0
	add r5, r0, #0
	ldr r1, _02232818 ; =0x00000A28
	mov r0, #0xb
	add r6, r2, #0
	str r3, [sp, #4]
	bl Heap_Alloc
	ldr r1, _0223281C ; =ov80_0223DD48
	ldr r2, _02232818 ; =0x00000A28
	str r0, [r1]
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r4, [r0]
	add r0, r5, #0
	bl sub_02030CC8
	str r0, [r4, #8]
	ldr r1, _0223281C ; =ov80_0223DD48
	str r5, [r4, #4]
	mov r0, #0xb
	str r0, [r4]
	ldr r4, [r1]
	bl SaveArray_Party_Alloc
	str r0, [r4, #0x28]
	mov r0, #0xb
	bl SaveArray_Party_Alloc
	str r0, [r4, #0x2c]
	mov r0, #0xa2
	ldr r1, [sp, #0x38]
	lsl r0, r0, #4
	str r1, [r4, r0]
	add r0, r5, #0
	ldr r4, [r4, #8]
	bl sub_02030E08
	add r5, r0, #0
	cmp r7, #0
	beq _02232520
	b _022326BA
_02232520:
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r1, [r0]
	mov r0, #0
	strb r6, [r1, #0x10]
	strb r0, [r1, #0x11]
	add r0, r4, #0
	bl sub_02030CBC
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldrb r2, [r0, #0x10]
	cmp r2, #3
	bne _02232546
	ldr r0, [r0, #4]
	bl Save_VarsFlags_Get
	bl Save_VarsFlags_GetVar4052
	b _02232552
_02232546:
	mov r3, #0
	add r0, r5, #0
	mov r1, #9
	str r3, [sp]
	bl sub_02030E58
_02232552:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bne _02232592
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl Save_Frontier_GetStatic
	add r5, r0, #0
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl sub_0205C1A0
	add r4, r0, #0
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl sub_0205C1A0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl FrontierSave_GetStat
	ldr r1, _0223281C ; =ov80_0223DD48
	ldr r1, [r1]
	strh r0, [r1, #0x14]
	b _02232630
_02232592:
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r4, [r0]
	mov r0, #0
	strh r0, [r4, #0x14]
	ldr r0, [r4, #4]
	bl Save_Frontier_GetStatic
	add r5, r0, #0
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl sub_0205C1F0
	add r7, r0, #0
	ldrb r0, [r4, #0x10]
	bl sub_0205C1F0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r5, #0
	add r1, r7, #0
	mov r3, #0
	bl sub_02031108
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	add r0, r6, #0
	bl sub_0205C218
	add r5, r0, #0
	add r0, r6, #0
	bl sub_0205C218
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r5, #0
	mov r3, #0
	bl sub_02031108
	ldr r4, _0223281C ; =ov80_0223DD48
	mov r5, #0
_022325F2:
	ldr r0, [r4]
	ldr r0, [r0, #4]
	bl Save_Frontier_GetStatic
	add r6, r0, #0
	ldr r0, [r4]
	lsl r1, r5, #0x18
	ldrb r0, [r0, #0x10]
	lsr r1, r1, #0x18
	bl sub_0205C174
	add r7, r0, #0
	ldr r0, [r4]
	lsl r1, r5, #0x18
	ldrb r0, [r0, #0x10]
	lsr r1, r1, #0x18
	bl sub_0205C174
	bl sub_0205C268
	add r2, r0, #0
	add r0, r6, #0
	add r1, r7, #0
	mov r3, #1
	bl sub_02031108
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #3
	blo _022325F2
_02232630:
	ldr r0, _0223281C ; =ov80_0223DD48
	mov r1, #7
	ldr r5, [r0]
	ldrh r0, [r5, #0x14]
	bl _s32_div_f
	strh r0, [r5, #0x16]
	mov r0, #0
	str r0, [r5, #0x18]
	add r1, r5, #0
	ldr r0, [sp, #4]
	add r1, #0x24
	strb r0, [r1]
	add r1, sp, #0x20
	add r0, r5, #0
	ldrh r2, [r1, #0x10]
	add r0, #0x25
	strb r2, [r0]
	add r0, r5, #0
	ldrh r1, [r1, #0x14]
	add r0, #0x26
	strb r1, [r0]
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl sub_0205C1F0
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1F0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl FrontierSave_GetStat
	strh r0, [r5, #0x20]
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl sub_0205C1F0
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1F0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0xa
	bl sub_02031228
	b _0223273E
_022326BA:
	ldr r0, _0223281C ; =ov80_0223DD48
	mov r1, #0
	ldr r5, [r0]
	str r1, [sp]
	add r0, r4, #0
	add r2, r1, #0
	add r3, r1, #0
	bl sub_02030D84
	strb r0, [r5, #0x10]
	mov r2, #0
	str r2, [sp]
	add r0, r4, #0
	mov r1, #1
	add r3, r2, #0
	bl sub_02030D84
	strb r0, [r5, #0x11]
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r6, [r0]
	ldr r0, [r6, #4]
	bl Save_Frontier_GetStatic
	add r7, r0, #0
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl sub_0205C1A0
	str r0, [sp, #0xc]
	ldrb r0, [r5, #0x10]
	bl sub_0205C1A0
	bl sub_0205C268
	add r2, r0, #0
	ldr r1, [sp, #0xc]
	add r0, r7, #0
	bl FrontierSave_GetStat
	strh r0, [r6, #0x14]
	ldrh r0, [r6, #0x14]
	mov r1, #7
	bl _s32_div_f
	mov r5, #0
	strh r0, [r6, #0x16]
	ldr r7, _0223281C ; =ov80_0223DD48
	add r6, r5, #0
_0223271C:
	lsl r2, r5, #0x18
	add r0, r4, #0
	mov r1, #7
	lsr r2, r2, #0x18
	add r3, r6, #0
	str r6, [sp]
	bl sub_02030D84
	ldr r1, [r7]
	add r1, r1, r5
	add r1, #0x24
	strb r0, [r1]
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #3
	blo _0223271C
_0223273E:
	ldr r6, _0223281C ; =ov80_0223DD48
	ldr r7, _02232820 ; =0x0000036A
	mov r4, #0
_02232744:
	ldr r5, [r6]
	ldr r0, [r5, #4]
	bl SaveArray_Party_Get
	add r1, r5, r4
	add r1, #0x24
	ldrb r1, [r1]
	bl Party_GetMonByIndex
	ldr r5, [r6]
	mov r1, #6
	mov r2, #0
	bl GetMonData
	lsl r1, r4, #1
	add r1, r5, r1
	strh r0, [r1, r7]
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #3
	blo _02232744
	ldr r0, [r5, #4]
	bl SaveArray_Party_Get
	str r0, [sp, #8]
	ldr r0, _0223281C ; =ov80_0223DD48
	mov r1, #0
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl ov80_02237B24
	add r7, r0, #0
	mov r5, #0
	cmp r7, #0
	ble _022327F8
	ldr r6, _0223281C ; =ov80_0223DD48
_0223278E:
	ldr r1, [r6]
	ldr r0, [sp, #8]
	add r1, r1, r5
	add r1, #0x24
	ldrb r1, [r1]
	bl Party_GetMonByIndex
	add r1, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #0x28]
	bl Party_AddMon
	ldr r0, [r6]
	add r1, r5, #0
	ldr r0, [r0, #0x28]
	bl Party_GetMonByIndex
	mov r1, #0
	str r1, [sp, #0x14]
	add r4, r0, #0
	mov r1, #6
	add r2, sp, #0x14
	bl SetMonData
	add r0, r4, #0
	mov r1, #0xa1
	mov r2, #0
	bl GetMonData
	cmp r0, #0x32
	bls _022327EE
	add r0, r4, #0
	mov r1, #5
	mov r2, #0
	bl GetMonData
	mov r1, #0x32
	bl GetMonExpBySpeciesAndLevel
	str r0, [sp, #0x10]
	add r0, r4, #0
	mov r1, #8
	add r2, sp, #0x10
	bl SetMonData
	add r0, r4, #0
	bl CalcMonLevelAndStats
_022327EE:
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, r7
	blt _0223278E
_022327F8:
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl ov80_02237D8C
	cmp r0, #1
	bne _02232810
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl ov80_0222A840
_02232810:
	ldr r0, _0223281C ; =ov80_0223DD48
	ldr r0, [r0]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02232818: .word 0x00000A28
_0223281C: .word ov80_0223DD48
_02232820: .word 0x0000036A
	thumb_func_end ov80_022324C4

