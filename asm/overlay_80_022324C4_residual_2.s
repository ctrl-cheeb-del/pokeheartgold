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

	thumb_func_start ov80_02232838
ov80_02232838: ; 0x02232838
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r7, r0, #0
	ldr r0, [r7, #0x28]
	bl Party_GetCount
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov r6, #0
	str r0, [sp, #0x10]
	cmp r0, #0
	ble _022328A0
	add r5, r7, #0
_02232852:
	ldr r0, [r7, #0x28]
	add r1, r6, #0
	bl Party_GetMonByIndex
	mov r1, #0x3a
	mov r2, #0
	add r4, r0, #0
	bl GetMonData
	mov r1, #0xe5
	lsl r1, r1, #2
	strh r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0x3b
	mov r2, #0
	bl GetMonData
	ldr r1, _02232900 ; =0x00000396
	mov r2, #0
	strh r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0x3c
	bl GetMonData
	mov r1, #0xe6
	lsl r1, r1, #2
	strh r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0x3d
	mov r2, #0
	bl GetMonData
	ldr r1, _02232904 ; =0x0000039A
	add r6, r6, #1
	strh r0, [r5, r1]
	ldr r0, [sp, #0x10]
	add r5, #8
	cmp r6, r0
	blt _02232852
_022328A0:
	add r0, r7, #0
	bl ov80_02237ED8
	add r1, r0, #0
	add r2, r7, #0
	ldrb r0, [r7, #0x10]
	add r2, #0x30
	mov r3, #0xe
	bl ov80_02237ADC
	ldrb r0, [r7, #0x10]
	mov r1, #1
	ldrb r4, [r7, #0x11]
	bl ov80_02237B58
	add r5, r0, #0
	ldrb r0, [r7, #0x10]
	bl ov80_02237D8C
	mov r3, #0xa2
	lsl r3, r3, #2
	add r1, r7, r3
	str r1, [sp]
	add r1, r3, #0
	sub r1, #0x14
	add r1, r7, r1
	str r1, [sp, #4]
	add r1, r3, #0
	sub r1, #0x10
	add r1, r7, r1
	lsl r0, r0, #0x18
	add r2, r4, #7
	str r1, [sp, #8]
	lsr r0, r0, #0x18
	lsl r1, r4, #1
	lsl r2, r2, #1
	str r0, [sp, #0xc]
	add r1, r7, r1
	add r2, r7, r2
	sub r3, #0x1c
	ldrh r1, [r1, #0x30]
	ldrh r2, [r2, #0x30]
	add r0, r5, #0
	add r3, r7, r3
	bl ov80_0222A6B8
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02232900: .word 0x00000396
_02232904: .word 0x0000039A
	thumb_func_end ov80_02232838


	thumb_func_start ov80_02232908
ov80_02232908: ; 0x02232908
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18c
	add r5, r0, #0
	bl ov80_022329B4
	mov r4, #0
	add r6, r5, #0
	add r7, r4, #0
_02232918:
	str r7, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #6
	lsr r2, r2, #0x18
	add r3, r7, #0
	bl sub_02030D84
	strh r0, [r6, #0x30]
	add r4, r4, #1
	add r6, r6, #2
	cmp r4, #0xe
	blt _02232918
	mov r6, #0
	add r4, sp, #0x30
	add r7, r5, #0
_02232938:
	mov r0, #0
	str r0, [sp]
	lsl r2, r6, #0x18
	ldr r0, [r5, #8]
	mov r1, #8
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030D84
	strh r0, [r4]
	ldrh r1, [r4]
	mov r0, #0x9b
	lsl r0, r0, #2
	strh r1, [r7, r0]
	add r6, r6, #1
	add r4, r4, #2
	add r7, r7, #2
	cmp r6, #4
	blt _02232938
	add r0, sp, #0x18
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #0xb
	str r0, [sp, #8]
	mov r0, #0xcd
	str r0, [sp, #0xc]
	add r0, sp, #0x3c
	add r1, sp, #0x30
	add r2, sp, #0x10
	mov r3, #0
	bl ov80_0222A52C
	mov r0, #0xb
	bl AllocMonZeroed
	add r6, r0, #0
	mov r7, #0
	add r4, sp, #0x3c
_02232986:
	add r0, r5, #0
	bl ov80_02237D88
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl ov80_0222A140
	ldr r1, [r5, #0x2c]
	add r0, r5, #0
	add r2, r6, #0
	bl ov80_02237E18
	add r7, r7, #1
	add r4, #0x38
	cmp r7, #4
	blt _02232986
	add r0, r6, #0
	bl Heap_Free
	add sp, #0x18c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_02232908


	thumb_func_start ov80_022329B4
ov80_022329B4: ; 0x022329B4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x28]
	bl Party_GetCount
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov r4, #0
	str r0, [sp, #4]
	cmp r0, #0
	ble _02232AB6
	add r7, sp, #8
_022329CE:
	ldr r0, [r5, #0x28]
	add r1, r4, #0
	bl Party_GetMonByIndex
	add r6, r0, #0
	mov r0, #0
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #2
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030D84
	add r2, sp, #8
	strh r0, [r7, #2]
	add r0, r6, #0
	mov r1, #0xa3
	add r2, #2
	bl SetMonData
	mov r0, #0
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #3
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030D84
	strb r0, [r7]
	add r0, r6, #0
	mov r1, #0x3a
	add r2, sp, #8
	bl SetMonData
	mov r0, #0
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #3
	lsr r2, r2, #0x18
	mov r3, #1
	bl sub_02030D84
	strb r0, [r7]
	add r0, r6, #0
	mov r1, #0x3b
	add r2, sp, #8
	bl SetMonData
	mov r0, #0
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #3
	lsr r2, r2, #0x18
	mov r3, #2
	bl sub_02030D84
	strb r0, [r7]
	add r0, r6, #0
	mov r1, #0x3c
	add r2, sp, #8
	bl SetMonData
	mov r0, #0
	str r0, [sp]
	mov r1, #3
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	lsr r2, r2, #0x18
	add r3, r1, #0
	bl sub_02030D84
	strb r0, [r7]
	add r0, r6, #0
	mov r1, #0x3d
	add r2, sp, #8
	bl SetMonData
	mov r0, #0
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #4
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030D84
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #0xa0
	add r2, sp, #0xc
	bl SetMonData
	mov r0, #0
	str r0, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #5
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030D84
	add r2, sp, #8
	strh r0, [r7, #2]
	add r0, r6, #0
	mov r1, #6
	add r2, #2
	bl SetMonData
	ldr r0, [sp, #4]
	add r4, r4, #1
	cmp r4, r0
	blt _022329CE
_02232AB6:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_022329B4
