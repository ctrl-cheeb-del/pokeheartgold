	.include "asm/macros.inc"
	.include "overlay_28.inc"
	.include "global.inc"

	.public ov28_0225D520
	.public ov28_0225D5EC
	.public ov28_0225D624
	.public ov28_0225D628
	.public ov28_0225D650
	.public ov28_0225D6E0
	.public ov28_0225D6FC
	.public ov28_0225D764
	.public ov28_0225D7C4
	.public ov28_0225D7E0
	.public ov28_0225D878
	.public ov28_0225D898
	.public ov28_0225D8D0
	.public ov28_0225D8EC
	.public ov28_0225D910
	.public ov28_0225D92C
	.public ov28_0225D9BC
	.public ov28_0225DA1C
	.public ov28_0225DA74
	.public ov28_0225DB54
	.public ov28_0225DB8C
	.public ov28_0225DBFC
	.public ov28_0225DC2C
	.public DowsingMchn_GetHiddenItemLocs
	.public DowsingMchn_FreeHiddenItemLocs
	.public ov28_0225DD58
	.public ov28_0225DE04
	.public ov28_0225DE64
	.public ov28_0225DE78
	.public ov28_0225DE88
	.public ov28_0225DE98
	.public ov28_0225DEB0
	.public ov28_0225DF04
	.public ov28_0225DF14
	.public ov28_0225DFA4
	.public ov28_0225DFBC
	.public ov28_0225E054
	.public ov28_0225E060
	.public ov28_0225E0DC
	.public ov28_0225E0F4
	.public ov28_0225E1A4
	.public ov28_0225E31C
	.public ov28_0225E374
	.public ov28_0225E3BC
	.public ov28_0225E424
	.public ov28_0225E43C
	.public ov28_0225E51C
	.public ov28_0225E578
	.public ov28_0225E730
	.public ov28_0225E7D4
	.public ov28_0225E810
	.public ov28_0225E8B8
	.public ov28_0225E900
	.public ov28_0225E938
	.public ov28_0225E9E0
	.public ov28_0225EA58
	.public _0225EA7C
	.public ov28_0225EA80
	.public ov28_0225EA84
	.public ov28_0225EA88
	.public ov28_0225EA90
	.public ov28_0225EA91
	.public ov28_0225EA9A
	.public ov28_0225EA9E
	.public ov28_0225EAA2
	.public ov28_0225EAA6
	.public ov28_0225EAAC
	.public ov28_0225EAC0
	.public ov28_0225EADC
	.public ov28_0225EAF8
	.public ov28_0225EB14
	.public ov28_0225EB32
	.public ov28_0225EB52
	.public ov28_0225EB7C
	.public ov28_0225EB84

	.text

thumb_func_start ov28_0225D7E0
ov28_0225D7E0: ; 0x0225D7E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r7, r0, #0
	mov r0, #4
	mov r1, #8
	bl FontID_Alloc
	mov r0, #0
	str r0, [sp, #0x10]
	mov r0, #0x6d
	lsl r0, r0, #2
	ldr r6, _0225D86C ; =ov28_0225EB52
	add r4, r7, r0
	add r5, r7, #0
_0225D7FC:
	ldr r0, [r7, #0x10]
	add r1, r4, #0
	add r2, r6, #0
	bl AddWindow
	add r0, r4, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225D870 ; =0x000F0100
	mov r2, #0x1a
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	lsl r2, r2, #4
	ldr r2, [r5, r2]
	add r0, r4, #0
	mov r1, #4
	mov r3, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl CopyWindowPixelsToVram_TextMode
	ldr r0, [sp, #0x10]
	add r6, #8
	add r0, r0, #1
	add r4, #0x10
	add r5, r5, #4
	str r0, [sp, #0x10]
	cmp r0, #5
	blo _0225D7FC
	mov r0, #0x6d
	lsl r0, r0, #2
	add r2, r7, r0
	mov r0, #0xcd
	lsl r0, r0, #2
	ldr r1, [r7, r0]
	ldr r0, _0225D874 ; =ov28_0225EB7C
	ldrb r0, [r0, r1]
	lsl r0, r0, #4
	add r0, r2, r0
	bl ScheduleWindowCopyToVram
	mov r0, #0x7d
	lsl r0, r0, #2
	add r0, r7, r0
	bl ScheduleWindowCopyToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_0225D86C: .word ov28_0225EB52
_0225D870: .word 0x000F0100
_0225D874: .word ov28_0225EB7C
	thumb_func_end ov28_0225D7E0
