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

	thumb_func_start ov80_02232F08
ov80_02232F08: ; 0x02232F08
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldrb r0, [r5, #0x10]
	mov r1, #1
	ldrb r4, [r5, #0x11]
	bl ov80_02237B58
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl ov80_02237D8C
	mov r3, #0xa2
	lsl r3, r3, #2
	add r1, r5, r3
	str r1, [sp]
	add r1, r3, #0
	sub r1, #0x14
	add r1, r5, r1
	str r1, [sp, #4]
	add r1, r3, #0
	sub r1, #0x10
	add r1, r5, r1
	lsl r0, r0, #0x18
	add r2, r4, #7
	str r1, [sp, #8]
	lsr r0, r0, #0x18
	lsl r1, r4, #1
	lsl r2, r2, #1
	str r0, [sp, #0xc]
	add r1, r5, r1
	add r2, r5, r2
	sub r3, #0x1c
	ldrh r1, [r1, #0x30]
	ldrh r2, [r2, #0x30]
	add r0, r6, #0
	add r3, r5, r3
	bl ov80_0222A6B8
	add r0, r5, #0
	bl ov80_02237E30
	add sp, #0x10
	pop {r4, r5, r6, pc}
	thumb_func_end ov80_02232F08


	thumb_func_start ov80_02232F60
ov80_02232F60: ; 0x02232F60
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	bl sub_0203769C
	cmp r0, #0
	bne _02232F74
	mov r0, #0
	str r0, [sp]
	b _02232F78
_02232F74:
	mov r0, #2
	str r0, [sp]
_02232F78:
	ldrb r0, [r6, #0x10]
	mov r1, #0
	bl ov80_02237B24
	add r5, r0, #0
	ldr r0, [r6, #0x28]
	bl Party_GetCount
	ldr r4, [sp]
	add r0, r4, #0
	add r0, r5, r0
	add r1, r4, #0
	str r0, [sp, #4]
	cmp r1, r0
	bge _02232FEA
_02232F96:
	ldr r0, [r6, #0x28]
	add r1, r4, #0
	bl Party_GetMonByIndex
	ldr r1, [sp]
	mov r2, #0
	sub r1, r4, r1
	lsl r1, r1, #3
	add r5, r6, r1
	mov r1, #0x3a
	add r7, r0, #0
	bl GetMonData
	mov r1, #0xe5
	lsl r1, r1, #2
	strh r0, [r5, r1]
	add r0, r7, #0
	mov r1, #0x3b
	mov r2, #0
	bl GetMonData
	ldr r1, _02233018 ; =0x00000396
	mov r2, #0
	strh r0, [r5, r1]
	add r0, r7, #0
	mov r1, #0x3c
	bl GetMonData
	mov r1, #0xe6
	lsl r1, r1, #2
	strh r0, [r5, r1]
	add r0, r7, #0
	mov r1, #0x3d
	mov r2, #0
	bl GetMonData
	ldr r1, _0223301C ; =0x0000039A
	add r4, r4, #1
	strh r0, [r5, r1]
	ldr r0, [sp, #4]
	cmp r4, r0
	blt _02232F96
_02232FEA:
	ldr r0, [r6, #0x28]
	bl ov80_02237D9C
	mov r0, #0x37
	lsl r0, r0, #4
	mov r7, #0
	add r2, r0, #0
	add r3, r0, #0
	add r4, r7, #0
	add r1, r0, #4
	add r2, #8
	add r3, #0xc
_02233002:
	add r5, r6, r7
	strb r4, [r5, r0]
	strb r4, [r5, r1]
	strb r4, [r5, r2]
	add r7, r7, #1
	strb r4, [r5, r3]
	cmp r7, #4
	blt _02233002
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02233018: .word 0x00000396
_0223301C: .word 0x0000039A
	thumb_func_end ov80_02232F60


	thumb_func_start ov80_02233020
ov80_02233020: ; 0x02233020
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	add r6, r0, #0
	mov r0, #0
	str r0, [sp, #0x10]
	add r1, sp, #0x18
	add r4, r0, #0
_0223302E:
	add r0, r0, #1
	strb r4, [r1]
	add r1, r1, #1
	cmp r0, #0x14
	blt _0223302E
	strb r4, [r6, #0x12]
	bl sub_0203769C
	cmp r0, #0
	bne _02233048
	mov r0, #0
	str r0, [sp]
	b _0223304C
_02233048:
	mov r0, #2
	str r0, [sp]
_0223304C:
	ldrb r0, [r6, #0x10]
	mov r1, #0
	bl ov80_02237B24
	str r0, [sp, #8]
	ldrb r0, [r6, #0x10]
	mov r1, #1
	bl ov80_02237B58
	str r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r0, [sp]
	add r0, r1, r0
	ldr r1, [sp]
	str r0, [sp, #0xc]
	cmp r1, r0
	bge _02233122
	add r7, sp, #0x18
_02233070:
	ldr r0, [r6, #0x28]
	ldr r1, [sp]
	bl Party_GetMonByIndex
	mov r1, #0xac
	mov r2, #0
	add r5, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _02233116
	add r0, r5, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	str r0, [sp, #0x14]
	add r0, r5, #0
	mov r1, #0xa4
	mov r2, #0
	bl GetMonData
	ldr r1, [sp, #0x14]
	cmp r1, #0
	beq _022330E2
	ldrb r1, [r7]
	add r1, r1, #1
	strb r1, [r7]
	ldr r1, [sp, #0x14]
	cmp r1, r0
	bne _022330B6
	ldrb r0, [r7, #1]
	add r0, r0, #1
	strb r0, [r7, #1]
	b _022330CC
_022330B6:
	lsr r1, r0, #1
	ldr r0, [sp, #0x14]
	cmp r0, r1
	blo _022330C6
	ldrb r0, [r7, #2]
	add r0, r0, #1
	strb r0, [r7, #2]
	b _022330CC
_022330C6:
	ldrb r0, [r7, #3]
	add r0, r0, #1
	strb r0, [r7, #3]
_022330CC:
	add r0, r5, #0
	mov r1, #0xa0
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _022330E6
	ldrb r0, [r7, #4]
	add r0, r0, #1
	strb r0, [r7, #4]
	b _022330E6
_022330E2:
	mov r0, #1
	strb r0, [r6, #0x12]
_022330E6:
	add r0, r5, #0
	mov r1, #0x3a
	mov r2, #0
	bl GetMonData
	add r4, r4, r0
	add r0, r5, #0
	mov r1, #0x3b
	mov r2, #0
	bl GetMonData
	add r4, r4, r0
	add r0, r5, #0
	mov r1, #0x3c
	mov r2, #0
	bl GetMonData
	add r4, r4, r0
	add r0, r5, #0
	mov r1, #0x3d
	mov r2, #0
	bl GetMonData
	add r4, r4, r0
_02233116:
	ldr r0, [sp]
	add r1, r0, #1
	ldr r0, [sp, #0xc]
	str r1, [sp]
	cmp r1, r0
	blt _02233070
_02233122:
	ldr r1, [sp, #4]
	mov r0, #0
	cmp r1, #0
	ble _02233146
	mov r2, #0xdd
	add r3, sp, #0x18
	lsl r2, r2, #2
_02233130:
	add r1, r6, r0
	ldrb r1, [r1, r2]
	cmp r1, #1
	bne _0223313E
	ldrb r1, [r3, #8]
	add r1, r1, #1
	strb r1, [r3, #8]
_0223313E:
	ldr r1, [sp, #4]
	add r0, r0, #1
	cmp r0, r1
	blt _02233130
_02233146:
	ldr r0, [sp, #8]
	mov r3, #0
	add r7, r3, #0
	cmp r0, #0
	ble _0223316E
	mov r0, #0xe5
	lsl r0, r0, #2
_02233154:
	mov r2, #0
	add r5, r6, #0
_02233158:
	ldrh r1, [r5, r0]
	add r2, r2, #1
	add r5, r5, #2
	add r3, r3, r1
	cmp r2, #4
	blt _02233158
	ldr r1, [sp, #8]
	add r7, r7, #1
	add r6, #8
	cmp r7, r1
	blt _02233154
_0223316E:
	sub r0, r3, r4
	cmp r0, #5
	bgt _0223317E
	add r0, sp, #0x18
	ldrb r1, [r0, #5]
	add r1, r1, #1
	strb r1, [r0, #5]
	b _02233198
_0223317E:
	cmp r0, #0xa
	bgt _0223318C
	add r0, sp, #0x18
	ldrb r1, [r0, #6]
	add r1, r1, #1
	strb r1, [r0, #6]
	b _02233198
_0223318C:
	cmp r0, #0xf
	bgt _02233198
	add r0, sp, #0x18
	ldrb r1, [r0, #7]
	add r1, r1, #1
	strb r1, [r0, #7]
_02233198:
	add r1, sp, #0x18
	ldrb r2, [r1]
	lsl r0, r2, #1
	add r2, r2, r0
	ldr r0, [sp, #0x10]
	add r3, r0, r2
	ldrb r2, [r1, #1]
	lsl r0, r2, #1
	add r0, r2, r0
	add r2, r3, r0
	ldrb r0, [r1, #2]
	lsl r0, r0, #1
	add r2, r2, r0
	ldrb r0, [r1, #3]
	add r2, r2, r0
	ldrb r0, [r1, #4]
	add r2, r2, r0
	ldrb r0, [r1, #5]
	lsl r0, r0, #3
	add r3, r2, r0
	ldrb r2, [r1, #6]
	mov r0, #6
	mul r0, r2
	add r2, r3, r0
	ldrb r0, [r1, #7]
	ldrb r1, [r1, #8]
	lsl r0, r0, #2
	add r2, r2, r0
	mov r0, #7
	mul r0, r1
	add r0, r2, r0
	str r0, [sp, #0x10]
	cmp r0, #0
	bgt _022331E0
	mov r0, #1
	str r0, [sp, #0x10]
_022331E0:
	ldr r0, [sp, #0x10]
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_02233020
