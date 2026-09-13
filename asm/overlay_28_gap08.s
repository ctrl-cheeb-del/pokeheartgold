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

thumb_func_start ov28_0225E43C
ov28_0225E43C: ; 0x0225E43C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0x93
	lsl r0, r0, #2
	ldrh r1, [r5, r0]
	lsl r2, r1, #0x11
	lsr r4, r2, #0x11
	beq _0225E50E
	ldr r2, _0225E514 ; =0xFFFF8000
	lsr r3, r2, #0x10
	add r3, r4, r3
	lsl r3, r3, #0x10
	and r1, r2
	lsr r3, r3, #0x10
	lsr r2, r2, #0x11
	and r2, r3
	orr r1, r2
	strh r1, [r5, r0]
	ldrh r1, [r5, r0]
	lsl r1, r1, #0x11
	lsr r1, r1, #0x11
	bne _0225E4B0
	mov r6, #0
	add r4, r5, #0
	add r7, sp, #4
_0225E470:
	mov r0, #0x22
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	sub r0, r0, #4
	str r1, [r5, r0]
	mov r1, #0x87
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r0, r7, #0
	bl ov28_0225DE04
	mov r0, #0x19
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r1, r7, #0
	bl Sprite_SetMatrix
	mov r0, #0x19
	mov r1, #0x87
	lsl r0, r0, #4
	lsl r1, r1, #2
	ldr r0, [r4, r0]
	ldr r1, [r5, r1]
	bl ov28_0225E424
	add r6, r6, #1
	add r5, #0xc
	add r4, r4, #4
	cmp r6, #4
	blo _0225E470
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_0225E4B0:
	mov r1, #0
	sub r0, #0x30
	str r1, [sp]
	add r4, r5, #0
	add r6, r5, #0
	add r7, r5, r0
_0225E4BC:
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	sub r0, #8
	str r1, [r4, r0]
	mov r1, #0x87
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, sp, #4
	bl ov28_0225DE04
	mov r0, #0x19
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	add r1, sp, #4
	bl Sprite_SetMatrix
	mov r0, #0x19
	mov r1, #0x87
	lsl r0, r0, #4
	lsl r1, r1, #2
	ldr r0, [r6, r0]
	ldr r1, [r4, r1]
	bl ov28_0225E424
	mov r1, #0x21
	lsl r1, r1, #4
	ldr r1, [r5, r1]
	add r0, r7, #0
	lsl r2, r1, #2
	ldr r1, _0225E518 ; =ov28_0225EAAC
	ldr r1, [r1, r2]
	blx r1
	ldr r0, [sp]
	add r4, #0xc
	add r0, r0, #1
	add r6, r6, #4
	add r7, #0xc
	str r0, [sp]
	cmp r0, #4
	blo _0225E4BC
_0225E50E:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225E514: .word 0xFFFF8000
_0225E518: .word ov28_0225EAAC
	thumb_func_end ov28_0225E43C
