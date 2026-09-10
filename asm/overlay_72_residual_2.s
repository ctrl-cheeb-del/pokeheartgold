	.include "asm/macros.inc"
	.include "overlay_72.inc"
	.include "global.inc"

	.text
	.public NintendoWfc_Exit
	.public NintendoWfc_Init
	.public NintendoWfc_Main
	.public _0223B330
	.public _0223B4E0
	.public _0223B820
	.public ov72_022378DC
	.public ov72_02237B54
	.public ov72_02237B80
	.public ov72_02237BD0
	.public ov72_02237C30
	.public ov72_02237CB0
	.public ov72_02237CF4
	.public ov72_02237D50
	.public ov72_02237D88
	.public ov72_022380FC
	.public ov72_02238124
	.public ov72_02238164
	.public ov72_02238194
	.public ov72_02238408
	.public ov72_02238688
	.public ov72_022386F4
	.public ov72_02238730
	.public ov72_02238750
	.public ov72_02238778
	.public ov72_022387D8
	.public ov72_02238800
	.public ov72_0223886C
	.public ov72_0223894C
	.public ov72_0223897C
	.public ov72_022389C8
	.public ov72_02238B18
	.public ov72_02238BEC
	.public ov72_02238E3C
	.public ov72_02238EE4
	.public ov72_02239040
	.public ov72_02239108
	.public ov72_02239198
	.public ov72_022391E8
	.public ov72_02239220
	.public ov72_022392BC
	.public ov72_02239370
	.public ov72_022393CC
	.public ov72_022394A4
	.public ov72_022394D8
	.public ov72_02239638
	.public ov72_022396E8
	.public ov72_02239760
	.public ov72_02239784
	.public ov72_022397E8
	.public ov72_022398BC
	.public ov72_02239A3C
	.public ov72_02239A88
	.public ov72_02239BEC
	.public ov72_02239C14
	.public ov72_02239CB4
	.public ov72_02239CD8
	.public ov72_02239D6C
	.public ov72_02239E58
	.public ov72_02239F04
	.public ov72_02239F60
	.public ov72_02239F8C
	.public ov72_02239FD8
	.public ov72_0223A014
	.public ov72_0223A044
	.public ov72_0223A06C
	.public ov72_0223A0E0
	.public ov72_0223A1AC
	.public ov72_0223A1CC
	.public ov72_0223A200
	.public ov72_0223A280
	.public ov72_0223A2E8
	.public ov72_0223A314
	.public ov72_0223A350
	.public ov72_0223A3A8
	.public ov72_0223A3E0
	.public ov72_0223A420
	.public ov72_0223A460
	.public ov72_0223A4DC
	.public ov72_0223A520
	.public ov72_0223A588
	.public ov72_0223A5B4
	.public ov72_0223A5E0
	.public ov72_0223A680
	.public ov72_0223A738
	.public ov72_0223A760
	.public ov72_0223A7F4
	.public ov72_0223A8A0
	.public ov72_0223A8F0
	.public ov72_0223AA9C
	.public ov72_0223AB84
	.public ov72_0223ABB0
	.public ov72_0223AC00
	.public ov72_0223AC2C
	.public ov72_0223ACA8
	.public ov72_0223AD20
	.public ov72_0223AD64
	.public ov72_0223AD94
	.public ov72_0223AE20
	.public ov72_0223AE6C
	.public ov72_0223AED0
	.public ov72_0223AF1C
	.public ov72_0223AF48
	.public ov72_0223AF7C
	.public ov72_0223B088
	.public ov72_0223B0C4
	.public ov72_0223B1C8
	.public ov72_0223B2C0
	.public ov72_0223B2FC
	.public ov72_0223B338
	.public ov72_0223B344
	.public ov72_0223B354
	.public ov72_0223B364
	.public ov72_0223B366
	.public ov72_0223B37C
	.public ov72_0223B3A4
	.public ov72_0223B3A6
	.public ov72_0223B3D8
	.public ov72_0223B3F4
	.public ov72_0223B410
	.public ov72_0223B42C
	.public ov72_0223B448
	.public ov72_0223B464
	.public ov72_0223B466
	.public ov72_0223B468
	.public ov72_0223B46A
	.public ov72_0223B46C
	.public ov72_0223B478
	.public ov72_0223B479
	.public ov72_0223B48C
	.public ov72_0223B4C0
	.public ov72_0223B4C2
	.public ov72_0223B4C8
	.public ov72_0223B52C
	.public ov72_0223B578
	.public ov72_0223B5C4
	.public ov72_0223B60C
	.public ov72_0223B654
	.public ov72_0223B658
	.public ov72_0223B65C
	.public ov72_0223B660
	.public ov72_0223B744
	.public ov72_0223B774
	.public ov72_0223B7B8
	.public ov72_0223B7FC
	.public ov72_0223B82C
	.public ov72_0223B834
	.public ov72_0223B900
	.public ov72_0223B91B
	.public ov72_0223B920
	.public ov72_0223B923
	.public ov72_0223B92C

	.public ov72_022378C0
	.public ov72_02237B74
	.public ov72_02238144
	.public ov72_02238160
	.public ov72_022383DC
	.public ov72_02238668
	.public ov72_02238680
	.public ov72_022387A0
	.public ov72_022387C4
	.public ov72_022387D0
	.public ov72_02238AEC
	.public ov72_02238FFC
	.public ov72_02239098
	.public ov72_022390D8
	.public ov72_02239168
	.public ov72_022392AC
	.public ov72_022393B0
	.public ov72_02239614
	.public ov72_0223985C
	.public ov72_0223988C
	.public ov72_022399CC
	.public ov72_02239A08
	.public ov72_02239B5C
	.public ov72_02239B98
	.public ov72_02239BC8
	.public ov72_02239C8C
	.public ov72_02239D3C
	.public ov72_02239E94
	.public ov72_02239E9C
	.public ov72_02239EB4
	.public ov72_02239ED4
	.public ov72_02239F30
	.public ov72_02239FBC
	.public ov72_0223A010
	.public ov72_0223A414
	.public ov72_0223A41C
	.public ov72_0223A444
	.public ov72_0223A71C
	.public ov72_0223A8DC
	.public ov72_0223ABF4
	.public ov72_0223ABF8
	.public ov72_0223ABFC
	.public ov72_0223AC6C
	.public ov72_0223AC88
	.public ov72_0223ACA4
	.public ov72_0223AF70
	.public ov72_0223B084
	.public ov72_0223B2E4

	thumb_func_start ov72_02237B80
ov72_02237B80: ; 0x02237B80
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	bl ov38_0221BE84
	ldr r0, _02237BC0 ; =_0223B820
	sub r1, r4, #1
	strb r1, [r0, #0x14]
	mov r0, #2
	str r0, [sp]
	ldr r0, _02237BC4 ; =_0223B4E0
	ldr r1, _02237BC8 ; =ov72_0223B834
	ldr r3, _02237BCC ; =ov72_0223B923
	mov r2, #1
	bl ov72_02237D50
	cmp r0, #0
	beq _02237BAE
	ldr r0, _02237BC0 ; =_0223B820
	mov r1, #2
	str r1, [r0]
	add sp, #4
	pop {r3, r4, pc}
_02237BAE:
	ldr r0, _02237BC0 ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	sub r1, #0x11
	str r1, [r0, #4]
	bl ov38_0221BFEC
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02237BC0: .word _0223B820
_02237BC4: .word _0223B4E0
_02237BC8: .word ov72_0223B834
_02237BCC: .word ov72_0223B923
	thumb_func_end ov72_02237B80


	thumb_func_start ov72_02237BD0
ov72_02237BD0: ; 0x02237BD0
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r0, #0
	ldr r0, _02237C1C ; =ov72_0223B920
	add r6, r2, #0
	add r4, r1, #0
	str r6, [r0, #8]
	bl ov38_0221BE84
	ldr r0, _02237C20 ; =_0223B820
	sub r1, r5, #1
	strb r1, [r0, #0x14]
	sub r1, r4, #1
	strb r1, [r0, #0x15]
	ldr r0, _02237C24 ; =0x00000A38
	ldr r1, _02237C28 ; =ov72_0223B834
	str r0, [sp]
	ldr r0, _02237C2C ; =ov72_0223B52C
	mov r2, #2
	add r3, r6, #0
	bl ov72_02237D50
	cmp r0, #0
	beq _02237C0A
	ldr r0, _02237C20 ; =_0223B820
	mov r1, #4
	str r1, [r0]
	add sp, #4
	pop {r3, r4, r5, r6, pc}
_02237C0A:
	ldr r0, _02237C20 ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	sub r1, #0x11
	str r1, [r0, #4]
	bl ov38_0221BFEC
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_02237C1C: .word ov72_0223B920
_02237C20: .word _0223B820
_02237C24: .word 0x00000A38
_02237C28: .word ov72_0223B834
_02237C2C: .word ov72_0223B52C
	thumb_func_end ov72_02237BD0


	thumb_func_start ov72_02237C30
ov72_02237C30: ; 0x02237C30
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	add r4, r3, #0
	bl ov38_0221BE84
	ldr r0, _02237C94 ; =ov72_0223B834
	add r1, r4, #0
	mov r2, #0xe4
	bl memcpy
	ldr r0, _02237C98 ; =ov72_0223B900
	sub r1, r5, #1
	strb r1, [r0, #0x18]
	sub r1, r6, #1
	strb r1, [r0, #0x19]
	ldr r3, _02237C9C ; =ov72_0223B91B
	ldr r2, _02237CA0 ; =ov72_0223B82C
	strb r7, [r0, #0x1a]
	mov r1, #8
_02237C5A:
	ldrb r0, [r2]
	add r2, r2, #1
	strb r0, [r3]
	add r3, r3, #1
	sub r1, r1, #1
	bne _02237C5A
	mov r0, #2
	str r0, [sp]
	ldr r0, _02237CA4 ; =ov72_0223B578
	ldr r1, _02237C94 ; =ov72_0223B834
	ldr r3, _02237CA8 ; =ov72_0223B923
	mov r2, #0xef
	bl ov72_02237D50
	cmp r0, #0
	beq _02237C82
	ldr r0, _02237CAC ; =_0223B820
	mov r1, #6
	str r1, [r0]
	pop {r3, r4, r5, r6, r7, pc}
_02237C82:
	ldr r0, _02237CAC ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	sub r1, #0x11
	str r1, [r0, #4]
	bl ov38_0221BFEC
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02237C94: .word ov72_0223B834
_02237C98: .word ov72_0223B900
_02237C9C: .word ov72_0223B91B
_02237CA0: .word ov72_0223B82C
_02237CA4: .word ov72_0223B578
_02237CA8: .word ov72_0223B923
_02237CAC: .word _0223B820
	thumb_func_end ov72_02237C30


	thumb_func_start ov72_02237CB0
ov72_02237CB0: ; 0x02237CB0
	push {r3, lr}
	bl ov38_0221BE84
	mov r0, #2
	str r0, [sp]
	ldr r0, _02237CE4 ; =ov72_0223B5C4
	ldr r1, _02237CE8 ; =ov72_0223B834
	ldr r3, _02237CEC ; =ov72_0223B923
	mov r2, #0
	bl ov72_02237D50
	cmp r0, #0
	beq _02237CD2
	ldr r0, _02237CF0 ; =_0223B820
	mov r1, #8
	str r1, [r0]
	pop {r3, pc}
_02237CD2:
	ldr r0, _02237CF0 ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	sub r1, #0x11
	str r1, [r0, #4]
	bl ov38_0221BFEC
	pop {r3, pc}
	nop
_02237CE4: .word ov72_0223B5C4
_02237CE8: .word ov72_0223B834
_02237CEC: .word ov72_0223B923
_02237CF0: .word _0223B820
	thumb_func_end ov72_02237CB0


	thumb_func_start ov72_02237CF4
ov72_02237CF4: ; 0x02237CF4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, #0x1c
	add r4, r1, #0
	bl OS_GetMacAddress
	ldr r0, _02237D40 ; =ov72_0223B834
	add r1, r5, #0
	mov r2, #0x64
	bl memcpy
	ldr r0, _02237D44 ; =ov72_0223B920
	str r4, [r0, #8]
	bl ov38_0221BE84
	mov r0, #8
	str r0, [sp]
	ldr r3, _02237D44 ; =ov72_0223B920
	ldr r0, _02237D48 ; =ov72_0223B60C
	ldr r1, _02237D40 ; =ov72_0223B834
	ldr r3, [r3, #8]
	mov r2, #0x64
	bl ov72_02237D50
	cmp r0, #0
	beq _02237D30
	ldr r0, _02237D4C ; =_0223B820
	mov r1, #0xa
	str r1, [r0]
	pop {r3, r4, r5, pc}
_02237D30:
	ldr r0, _02237D4C ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	sub r1, #0x11
	str r1, [r0, #4]
	bl ov38_0221BFEC
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02237D40: .word ov72_0223B834
_02237D44: .word ov72_0223B920
_02237D48: .word ov72_0223B60C
_02237D4C: .word _0223B820
	thumb_func_end ov72_02237CF4


	thumb_func_start ov72_02237D50
ov72_02237D50: ; 0x02237D50
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r1, #0
	ldr r1, [sp, #0x18]
	str r3, [sp]
	str r1, [sp, #4]
	add r4, r2, #0
	ldr r1, _02237D84 ; =_0223B820
	add r2, r5, #0
	ldr r1, [r1, #8]
	add r3, r4, #0
	bl ov38_0221BEA8
	cmp r0, #0
	beq _02237D76
	cmp r0, #1
	beq _02237D7C
	cmp r0, #2
	b _02237D7C
_02237D76:
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, pc}
_02237D7C:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_02237D84: .word _0223B820
	thumb_func_end ov72_02237D50


	thumb_func_start ov72_02237D88
ov72_02237D88: ; 0x02237D88
	push {r4, lr}
	cmp r0, #0x20
	bhi _02237E00
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02237D9A: ; jump table
	.short _02237DDC - _02237D9A - 2 ; case 0
	.short _02237DDC - _02237D9A - 2 ; case 1
	.short _02237DE2 - _02237D9A - 2 ; case 2
	.short _02237DDC - _02237D9A - 2 ; case 3
	.short _02237DDC - _02237D9A - 2 ; case 4
	.short _02237DDC - _02237D9A - 2 ; case 5
	.short _02237DDC - _02237D9A - 2 ; case 6
	.short _02237E00 - _02237D9A - 2 ; case 7
	.short _02237DE2 - _02237D9A - 2 ; case 8
	.short _02237DDC - _02237D9A - 2 ; case 9
	.short _02237DDC - _02237D9A - 2 ; case 10
	.short _02237DE8 - _02237D9A - 2 ; case 11
	.short _02237DEE - _02237D9A - 2 ; case 12
	.short _02237DEE - _02237D9A - 2 ; case 13
	.short _02237DDC - _02237D9A - 2 ; case 14
	.short _02237DFA - _02237D9A - 2 ; case 15
	.short _02237DF4 - _02237D9A - 2 ; case 16
	.short _02237DF4 - _02237D9A - 2 ; case 17
	.short _02237DF4 - _02237D9A - 2 ; case 18
	.short _02237DF4 - _02237D9A - 2 ; case 19
	.short _02237DDC - _02237D9A - 2 ; case 20
	.short _02237DDC - _02237D9A - 2 ; case 21
	.short _02237DDC - _02237D9A - 2 ; case 22
	.short _02237DDC - _02237D9A - 2 ; case 23
	.short _02237E00 - _02237D9A - 2 ; case 24
	.short _02237DE2 - _02237D9A - 2 ; case 25
	.short _02237DF4 - _02237D9A - 2 ; case 26
	.short _02237DF4 - _02237D9A - 2 ; case 27
	.short _02237DF4 - _02237D9A - 2 ; case 28
	.short _02237DF4 - _02237D9A - 2 ; case 29
	.short _02237DFA - _02237D9A - 2 ; case 30
	.short _02237DF4 - _02237D9A - 2 ; case 31
	.short _02237DDC - _02237D9A - 2 ; case 32
_02237DDC:
	mov r4, #4
	mvn r4, r4
	b _02237E04
_02237DE2:
	mov r4, #4
	mvn r4, r4
	b _02237E04
_02237DE8:
	mov r4, #6
	mvn r4, r4
	b _02237E04
_02237DEE:
	mov r4, #6
	mvn r4, r4
	b _02237E04
_02237DF4:
	mov r4, #1
	mvn r4, r4
	b _02237E04
_02237DFA:
	mov r4, #1
	mvn r4, r4
	b _02237E04
_02237E00:
	mov r4, #4
	mvn r4, r4
_02237E04:
	mov r0, #4
	mvn r0, r0
	cmp r4, r0
	beq _02237E1C
	bl WCM_GetPhase
	cmp r0, #9
	beq _02237E18
	mov r4, #5
	mvn r4, r4
_02237E18:
	bl ov00_021EC210
_02237E1C:
	add r0, r4, #0
	pop {r4, pc}
	thumb_func_end ov72_02237D88


	thumb_func_start NintendoWfc_Init
NintendoWfc_Init: ; 0x02237E20
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r1, #0
	add r6, r0, #0
	ldr r0, [r5]
	cmp r0, #0
	beq _02237E36
	cmp r0, #1
	bne _02237E34
	b _02237F4A
_02237E34:
	b _02237F60
_02237E36:
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _02237F68 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _02237F6C ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	mov r2, #5
	mov r0, #3
	mov r1, #0x43
	lsl r2, r2, #0x10
	bl Heap_Create
	bl LoadDwcOverlay
	bl LoadOVY38
	mov r0, #0x43
	bl sub_02039FD8
	ldr r1, _02237F70 ; =0x000013A4
	add r0, r6, #0
	mov r2, #0x43
	bl OverlayManager_CreateAndGetData
	ldr r2, _02237F70 ; =0x000013A4
	mov r1, #0
	add r4, r0, #0
	bl memset
	mov r0, #0x43
	bl BgConfig_Alloc
	str r0, [r4, #4]
	ldr r0, _02237F74 ; =ov72_0223B92C
	add r2, sp, #0
	ldr r3, _02237F78 ; =ov72_0223B354
	str r4, [r0, #4]
	add r7, r2, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	add r0, r7, #0
	bl SetBothScreensModesAndDisable
	mov r0, #0xb
	mov r1, #0x20
	mov r2, #0x43
	bl MessageFormat_New_Custom
	mov r1, #0xbd
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r2, _02237F7C ; =0x00000306
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x43
	bl NewMsgDataFromNarc
	ldr r1, _02237F80 ; =0x00000BD4
	ldr r2, _02237F84 ; =0x0000030A
	str r0, [r4, r1]
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x43
	bl NewMsgDataFromNarc
	ldr r1, _02237F88 ; =0x00000BD8
	str r0, [r4, r1]
	mov r2, #0x32
	mov r0, #0
	mov r1, #0x1b
	lsl r2, r2, #4
	mov r3, #0x43
	bl NewMsgDataFromNarc
	ldr r1, _02237F8C ; =0x00000BDC
	str r0, [r4, r1]
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	add r0, r4, #0
	add r1, r6, #0
	bl ov72_02238144
	add r0, r4, #0
	bl ov72_022387D8
	mov r1, #0
	mov r0, #0x34
	add r2, r1, #0
	bl Sound_SetSceneAndPlayBGM
	ldr r1, _02237F90 ; =0x00020020
	mov r0, #0x43
	bl Heap_Alloc
	str r0, [r4, #0x24]
	add r0, #0x1f
	mov r1, #0x1f
	bic r0, r1
	mov r1, #2
	lsl r1, r1, #0x10
	mov r2, #0
	bl NNS_FndCreateExpHeapEx
	str r0, [r4, #0x28]
	ldr r1, _02237F94 ; =0x0000047D
	mov r0, #0xb
	mov r2, #1
	bl Sound_SetSceneAndPlayBGM
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r2, _02237F98 ; =0x04000304
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	orr r0, r1
	strh r0, [r2]
	mov r0, #1
	str r0, [r5]
	b _02237F60
_02237F4A:
	bl sub_02034D8C
	mov r0, #4
	mov r1, #0x43
	bl FontID_Alloc
	mov r0, #0
	str r0, [r5]
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02237F60:
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02237F68: .word 0xFFFFE0FF
_02237F6C: .word 0x04001000
_02237F70: .word 0x000013A4
_02237F74: .word ov72_0223B92C
_02237F78: .word ov72_0223B354
_02237F7C: .word 0x00000306
_02237F80: .word 0x00000BD4
_02237F84: .word 0x0000030A
_02237F88: .word 0x00000BD8
_02237F8C: .word 0x00000BDC
_02237F90: .word 0x00020020
_02237F94: .word 0x0000047D
_02237F98: .word 0x04000304
	thumb_func_end NintendoWfc_Init


	thumb_func_start NintendoWfc_Main
NintendoWfc_Main: ; 0x02237F9C
	push {r4, r5, r6, lr}
	add r4, r1, #0
	bl OverlayManager_GetData
	add r5, r0, #0
	bl ov00_021ECB40
	bl ov72_022378DC
	bl ov00_021ECB40
	ldr r1, [r4]
	cmp r1, #5
	bhi _02238044
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02237FC4: ; jump table
	.short _02237FD0 - _02237FC4 - 2 ; case 0
	.short _02237FEC - _02237FC4 - 2 ; case 1
	.short _02238000 - _02237FC4 - 2 ; case 2
	.short _0223800E - _02237FC4 - 2 ; case 3
	.short _02238022 - _02237FC4 - 2 ; case 4
	.short _02238040 - _02237FC4 - 2 ; case 5
_02237FD0:
	bl sub_02034DB8
	cmp r0, #0
	beq _02238044
	ldr r1, [r5, #0x28]
	ldr r0, _02238054 ; =ov72_0223B92C
	str r1, [r0]
	ldr r0, _02238058 ; =ov72_02238778
	ldr r1, _0223805C ; =ov72_022387A0
	bl ov00_021EC294
	mov r0, #1
	str r0, [r4]
	b _02238044
_02237FEC:
	ldr r3, [r5, #0x10]
	mov r2, #0xc
	add r6, r3, #0
	mul r6, r2
	ldr r2, _02238060 ; =ov72_0223B654
	add r0, r5, #0
	ldr r2, [r2, r6]
	blx r2
	str r0, [r4]
	b _02238044
_02238000:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _02238044
	mov r0, #3
	str r0, [r4]
	b _02238044
_0223800E:
	ldr r3, [r5, #0x10]
	mov r2, #0xc
	add r6, r3, #0
	mul r6, r2
	ldr r2, _02238064 ; =ov72_0223B658
	add r0, r5, #0
	ldr r2, [r2, r6]
	blx r2
	str r0, [r4]
	b _02238044
_02238022:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _02238044
	ldr r3, [r5, #0x10]
	mov r2, #0xc
	add r6, r3, #0
	mul r6, r2
	ldr r2, _02238068 ; =ov72_0223B65C
	ldr r1, [r4]
	ldr r2, [r2, r6]
	add r0, r5, #0
	blx r2
	str r0, [r4]
	b _02238044
_02238040:
	mov r0, #1
	pop {r4, r5, r6, pc}
_02238044:
	ldr r0, _0223806C ; =0x00000BF8
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02238050
	bl SpriteList_RenderAndAnimateSprites
_02238050:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02238054: .word ov72_0223B92C
_02238058: .word ov72_02238778
_0223805C: .word ov72_022387A0
_02238060: .word ov72_0223B654
_02238064: .word ov72_0223B658
_02238068: .word ov72_0223B65C
_0223806C: .word 0x00000BF8
	thumb_func_end NintendoWfc_Main


	thumb_func_start NintendoWfc_Exit
NintendoWfc_Exit: ; 0x02238070
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	bl IsPaletteFadeFinished
	cmp r0, #0
	bne _02238086
	mov r0, #0
	pop {r3, r4, r5, pc}
_02238086:
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	mov r0, #4
	bl FontID_Release
	ldr r0, [r4, #0x24]
	bl Heap_Free
	bl UnloadOVY38
	bl UnloadDwcOverlay
	add r0, r4, #0
	bl ov72_02238800
	ldr r0, _022380F0 ; =0x00000BDC
	ldr r0, [r4, r0]
	bl DestroyMsgData
	ldr r0, _022380F4 ; =0x00000BD8
	ldr r0, [r4, r0]
	bl DestroyMsgData
	ldr r0, _022380F8 ; =0x00000BD4
	ldr r0, [r4, r0]
	bl DestroyMsgData
	mov r0, #0xbd
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl MessageFormat_Delete
	add r0, r4, #0
	bl ov72_02238160
	bl sub_02034DE0
	ldr r0, [r4, #4]
	bl Heap_Free
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0x43
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_022380F0: .word 0x00000BDC
_022380F4: .word 0x00000BD8
_022380F8: .word 0x00000BD4
	thumb_func_end NintendoWfc_Exit


	thumb_func_start ov72_022380FC
ov72_022380FC: ; 0x022380FC
	push {r4, lr}
	add r4, r0, #0
	bl GF_RunVramTransferTasks
	ldr r0, [r4, #4]
	bl DoScheduledBgGpuUpdates
	bl OamManager_ApplyAndResetBuffers
	ldr r3, _0223811C ; =0x027E0000
	ldr r1, _02238120 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_0223811C: .word 0x027E0000
_02238120: .word 0x00003FF8
	thumb_func_end ov72_022380FC


	thumb_func_start ov72_02238124
ov72_02238124: ; 0x02238124
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _02238140 ; =ov72_0223B37C
	add r3, sp, #0
	mov r2, #5
_0223812E:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0223812E
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_02238140: .word ov72_0223B37C
	thumb_func_end ov72_02238124
