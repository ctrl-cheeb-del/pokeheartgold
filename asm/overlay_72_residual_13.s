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

	thumb_func_start ov72_02239638
ov72_02239638: ; 0x02239638
	push {r4, lr}
	add r4, r0, #0
	bl ov72_02237B54
	cmp r0, #0
	beq _022396CA
	bl ov72_02237B74
	ldr r1, _022396E4 ; =0x00000FD4
	mov r2, #0
	str r2, [r4, r1]
	add r2, r0, #7
	cmp r2, #6
	bhi _022396B4
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_02239660: ; jump table
	.short _02239696 - _02239660 - 2 ; case 0
	.short _0223968C - _02239660 - 2 ; case 1
	.short _022396A0 - _02239660 - 2 ; case 2
	.short _02239696 - _02239660 - 2 ; case 3
	.short _02239682 - _02239660 - 2 ; case 4
	.short _02239678 - _02239660 - 2 ; case 5
	.short _0223966E - _02239660 - 2 ; case 6
_0223966E:
	sub r1, #0x78
	str r0, [r4, r1]
	mov r0, #0x35
	str r0, [r4, #0x1c]
	b _022396C2
_02239678:
	sub r1, #0x78
	str r0, [r4, r1]
	mov r0, #0x35
	str r0, [r4, #0x1c]
	b _022396C2
_02239682:
	sub r1, #0x78
	str r0, [r4, r1]
	mov r0, #0x35
	str r0, [r4, #0x1c]
	b _022396C2
_0223968C:
	sub r1, #0x78
	str r0, [r4, r1]
	mov r0, #0x35
	str r0, [r4, #0x1c]
	b _022396C2
_02239696:
	sub r1, #0x78
	str r0, [r4, r1]
	mov r0, #0x35
	str r0, [r4, #0x1c]
	b _022396C2
_022396A0:
	sub r1, #0x78
	str r0, [r4, r1]
	mov r0, #0x35
	str r0, [r4, #0x1c]
	add r0, r4, #0
	bl ov72_0223A444
	bl sub_020399EC
	b _022396C2
_022396B4:
	cmp r0, #0
	ble _022396C2
	add r1, r4, #0
	add r1, #0x98
	str r0, [r1]
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x1c]
_022396C2:
	add r0, r4, #0
	bl ov72_0223A444
	b _022396E0
_022396CA:
	ldr r0, _022396E4 ; =0x00000FD4
	ldr r1, [r4, r0]
	add r1, r1, #1
	str r1, [r4, r0]
	ldr r1, [r4, r0]
	mov r0, #0xe1
	lsl r0, r0, #4
	cmp r1, r0
	bne _022396E0
	bl sub_020399EC
_022396E0:
	mov r0, #3
	pop {r4, pc}
	.balign 4, 0
_022396E4: .word 0x00000FD4
	thumb_func_end ov72_02239638


	thumb_func_start ov72_022396E8
ov72_022396E8: ; 0x022396E8
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	add r0, #0x98
	ldr r2, [r0]
	cmp r2, #0x64
	blt _02239720
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0xbd
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	mov r3, #3
	bl BufferIntegerAsString
	ldr r0, _02239758 ; =0x00000F0F
	ldr r1, _0223975C ; =0x00000BD4
	str r0, [sp]
	ldr r1, [r4, r1]
	add r0, r4, #0
	mov r2, #0xb
	mov r3, #1
	bl ov72_0223A280
	b _02239746
_02239720:
	mov r3, #2
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0xbd
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl BufferIntegerAsString
	ldr r0, _02239758 ; =0x00000F0F
	ldr r1, _0223975C ; =0x00000BD4
	str r0, [sp]
	ldr r1, [r4, r1]
	add r0, r4, #0
	mov r2, #0
	mov r3, #1
	bl ov72_0223A280
_02239746:
	add r0, r4, #0
	mov r1, #0x2f
	mov r2, #0xe
	bl ov72_02238680
	mov r0, #3
	add sp, #8
	pop {r4, pc}
	nop
_02239758: .word 0x00000F0F
_0223975C: .word 0x00000BD4
	thumb_func_end ov72_022396E8


	thumb_func_start ov72_02239760
ov72_02239760: ; 0x02239760
	push {r4, lr}
	add r4, r0, #0
	add r2, r4, #0
	add r2, #0x98
	ldr r2, [r2]
	mov r1, #1
	bl ov72_0223A520
	mov r0, #0xf
	str r0, [r4, #0x1c]
	add r0, r4, #0
	mov r1, #0
	mov r2, #1
	bl ov72_0223A41C
	mov r0, #3
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov72_02239760


	thumb_func_start ov72_02239784
ov72_02239784: ; 0x02239784
	push {r4, r5, lr}
	sub sp, #0x1c
	add r5, r0, #0
	bl ov72_0223A588
	add r4, r0, #0
	beq _022397E0
	cmp r4, #0
	ble _022397D2
	add r0, sp, #0
	add r1, sp, #0x10
	bl ov00_021ECB94
	add r0, r5, #0
	add r0, #0x9c
	add r1, r5, #0
	add r2, r5, #0
	str r4, [r0]
	add r1, #0x94
	add r2, #0x9c
	ldr r0, [r5]
	ldr r1, [r1]
	ldr r2, [r2]
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	ldr r0, [r0, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	add r3, sp, #0
	bl sub_0202D720
	cmp r0, #0
	beq _022397CC
	mov r0, #0x14
	str r0, [r5, #0x1c]
	b _022397E0
_022397CC:
	mov r0, #0x10
	str r0, [r5, #0x1c]
	b _022397E0
_022397D2:
	mov r1, #0
	add r0, r5, #0
	add r2, r1, #0
	bl ov72_0223A41C
	mov r0, #0x15
	str r0, [r5, #0x1c]
_022397E0:
	mov r0, #3
	add sp, #0x1c
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov72_02239784


	thumb_func_start ov72_022397E8
ov72_022397E8: ; 0x022397E8
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0xbd
	add r2, r4, #0
	lsl r0, r0, #4
	add r2, #0x9c
	ldr r0, [r4, r0]
	ldr r2, [r2]
	mov r1, #0
	mov r3, #3
	bl BufferIntegerAsString
	mov r3, #2
	mov r0, #0xbd
	add r2, r4, #0
	str r3, [sp]
	mov r1, #1
	str r1, [sp, #4]
	lsl r0, r0, #4
	add r2, #0x94
	ldr r0, [r4, r0]
	ldr r2, [r2]
	bl BufferIntegerAsString
	ldr r0, _02239850 ; =0x00000F0F
	mov r2, #1
	str r0, [sp]
	ldr r1, _02239854 ; =0x00000BD4
	add r0, r4, #0
	ldr r1, [r4, r1]
	add r3, r2, #0
	bl ov72_0223A280
	add r0, r4, #0
	mov r1, #0x2f
	mov r2, #0x11
	bl ov72_02238680
	add r4, #0xa0
	ldr r2, _02239858 ; =0x00000A38
	mov r0, #0
	add r1, r4, #0
	bl MIi_CpuClearFast
	mov r0, #3
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
_02239850: .word 0x00000F0F
_02239854: .word 0x00000BD4
_02239858: .word 0x00000A38
	thumb_func_end ov72_022397E8
