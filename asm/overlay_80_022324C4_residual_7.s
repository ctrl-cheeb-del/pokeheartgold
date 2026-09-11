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

	thumb_func_start ov80_02233490
ov80_02233490: ; 0x02233490
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	add r4, r0, #0
	ldrb r0, [r5, #0x10]
	bl ov80_02237D8C
	cmp r0, #0
	bne _022334EA
	add r0, r4, #0
	add r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	bne _022334AE
	bl GF_AssertFail
_022334AE:
	ldr r0, [r5, #4]
	bl Save_Frontier_GetStatic
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1F0
	add r7, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1F0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r6, #0
	add r1, r7, #0
	bl FrontierSave_GetStat
	add r6, r0, #0
	ldr r0, [r5, #4]
	bl Save_PlayerData_GetProfile
	add r2, r0, #0
	add r0, r4, #0
	add r4, #0xa8
	ldr r1, [r4]
	add r3, r6, #0
	bl ov80_02233594
	pop {r3, r4, r5, r6, r7, pc}
_022334EA:
	add r0, r4, #0
	add r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	bne _022334F8
	bl GF_AssertFail
_022334F8:
	add r0, r4, #0
	add r0, #0xac
	ldr r0, [r0]
	cmp r0, #0
	bne _02233506
	bl GF_AssertFail
_02233506:
	bl sub_0203769C
	cmp r0, #0
	bne _0223353A
	ldr r0, [r5, #4]
	bl Save_Frontier_GetStatic
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1F0
	add r7, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1F0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r6, #0
	add r1, r7, #0
	bl FrontierSave_GetStat
	add r6, r0, #0
	ldr r0, _02233590 ; =0x00000A1C
	ldrh r5, [r5, r0]
	b _02233564
_0223353A:
	ldr r0, _02233590 ; =0x00000A1C
	ldrh r6, [r5, r0]
	ldr r0, [r5, #4]
	bl Save_Frontier_GetStatic
	add r7, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C1F0
	str r0, [sp]
	ldrb r0, [r5, #0x10]
	bl sub_0205C1F0
	bl sub_0205C268
	add r2, r0, #0
	ldr r1, [sp]
	add r0, r7, #0
	bl FrontierSave_GetStat
	add r5, r0, #0
_02233564:
	mov r0, #0
	bl sub_02034818
	add r1, r4, #0
	add r1, #0xa8
	add r2, r0, #0
	ldr r1, [r1]
	add r0, r4, #0
	add r3, r6, #0
	bl ov80_02233594
	mov r0, #1
	bl sub_02034818
	add r2, r0, #0
	add r0, r4, #0
	add r4, #0xac
	ldr r1, [r4]
	add r3, r5, #0
	bl ov80_02233594
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02233590: .word 0x00000A1C
	thumb_func_end ov80_02233490


	thumb_func_start ov80_02233594
ov80_02233594: ; 0x02233594
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	str r3, [sp, #0x14]
	str r1, [sp, #0xc]
	ldr r1, [r5, #0x34]
	mov r0, #0x14
	str r2, [sp, #0x10]
	bl String_New
	add r4, r0, #0
	ldr r1, [r5, #0x34]
	mov r0, #0x14
	bl String_New
	add r6, r0, #0
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0x1f
	mov r3, #0xb
	bl NewMsgDataFromNarc
	add r7, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [r5, #0x44]
	ldr r2, [sp, #0x14]
	mov r1, #0
	mov r3, #4
	bl BufferIntegerAsString
	add r0, r7, #0
	mov r1, #2
	add r2, r4, #0
	bl ReadMsgDataIntoString
	ldr r0, [r5, #0x44]
	add r1, r6, #0
	add r2, r4, #0
	bl StringExpandPlaceholders
	mov r3, #0x10
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r1, #0
	ldr r0, [sp, #0xc]
	str r1, [sp, #8]
	add r2, r6, #0
	bl AddTextPrinterParameterized
	ldr r0, [r5, #0x44]
	ldr r2, [sp, #0x10]
	mov r1, #0
	bl BufferPlayersName
	add r0, r7, #0
	mov r1, #0
	add r2, r4, #0
	bl ReadMsgDataIntoString
	ldr r0, [r5, #0x44]
	add r1, r6, #0
	add r2, r4, #0
	bl StringExpandPlaceholders
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	ldr r0, [sp, #0xc]
	add r2, r6, #0
	add r3, r1, #0
	str r1, [sp, #8]
	bl AddTextPrinterParameterized
	add r0, r4, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add r0, r7, #0
	bl DestroyMsgData
	ldr r0, [sp, #0xc]
	bl CopyWindowToVram
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov80_02233594
