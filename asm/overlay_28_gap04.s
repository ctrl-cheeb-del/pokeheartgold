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

thumb_func_start ov28_0225DB8C
ov28_0225DB8C: ; 0x0225DB8C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x48
	add r5, r0, #0
	add r2, r1, #0
	add r1, sp, #0x20
	mov r0, #0
	strb r0, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	strb r0, [r1, #3]
	mov r0, #7
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	mov r0, #9
	ldr r1, _0225DBF8 ; =0x000001F3
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	add r0, r1, #0
	str r1, [sp, #0x1c]
	sub r0, #0x83
	sub r1, #0xa3
	add r0, r5, r0
	add r1, r5, r1
	mov r3, #4
	bl ov28_0225D92C
	mov r1, #0x17
	lsl r1, r1, #4
	add r0, r5, r1
	sub r1, #0x20
	add r1, r5, r1
	add r2, sp, #0x24
	mov r3, #2
	bl ov28_0225D9BC
	mov r4, #0
	add r6, sp, #0x24
	add r7, sp, #0x20
_0225DBE2:
	add r0, r5, #0
	add r1, r4, #4
	add r2, r6, #0
	add r3, r7, #0
	bl ov28_0225DA1C
	add r4, r4, #1
	cmp r4, #4
	blo _0225DBE2
	add sp, #0x48
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225DBF8: .word 0x000001F3
	thumb_func_end ov28_0225DB8C
