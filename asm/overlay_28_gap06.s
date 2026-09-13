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

thumb_func_start ov28_0225DD58
ov28_0225DD58: ; 0x0225DD58
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	bl DowsingMchn_GetHiddenItemLocs
	mov r0, #0x83
	mov r4, #0
	lsl r0, r0, #2
	str r4, [r5, r0]
_0225DD6A:
	mov r0, #0x81
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r6, r0, r4
	ldrb r0, [r6, #4]
	cmp r0, #0xff
	beq _0225DDF6
	mov r0, #0x83
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _0225DDBA
	mov r0, #0
	ldrsh r0, [r6, r0]
	str r0, [sp, #4]
	bl abs
	add r7, r0, #0
	mov r0, #2
	ldrsh r0, [r6, r0]
	bl abs
	add r0, r7, r0
	lsl r0, r0, #0x10
	lsr r7, r0, #0x10
	mov r0, #0x82
	ldr r1, [sp, #4]
	lsl r0, r0, #2
	strh r1, [r5, r0]
	sub r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r0, r4
	mov r0, #2
	ldrsh r1, [r1, r0]
	ldr r0, _0225DE00 ; =0x0000020A
	strh r1, [r5, r0]
	mov r1, #1
	add r0, r0, #2
	str r1, [r5, r0]
	b _0225DDF2
_0225DDBA:
	mov r0, #0
	ldrsh r0, [r6, r0]
	str r0, [sp]
	bl abs
	str r0, [sp, #8]
	mov r0, #2
	ldrsh r0, [r6, r0]
	bl abs
	ldr r1, [sp, #8]
	add r0, r1, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	cmp r7, r0
	bls _0225DDF2
	add r7, r0, #0
	mov r0, #0x82
	ldr r1, [sp]
	lsl r0, r0, #2
	strh r1, [r5, r0]
	sub r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r0, r4
	mov r0, #2
	ldrsh r1, [r1, r0]
	ldr r0, _0225DE00 ; =0x0000020A
	strh r1, [r5, r0]
_0225DDF2:
	add r4, r4, #6
	b _0225DD6A
_0225DDF6:
	add r0, r5, #0
	bl DowsingMchn_FreeHiddenItemLocs
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0225DE00: .word 0x0000020A
	thumb_func_end ov28_0225DD58
