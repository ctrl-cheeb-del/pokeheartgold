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

thumb_func_start ov28_0225E578
ov28_0225E578: ; 0x0225E578
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	add r6, r0, #0
	str r1, [sp, #0x10]
	cmp r1, #1
	bne _0225E5A2
	mov r1, #0x85
	lsl r1, r1, #2
	ldr r0, [r6, r1]
	lsr r0, r0, #3
	sub r0, r0, #3
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	str r0, [sp, #0x30]
	add r0, r1, #4
	ldr r0, [r6, r0]
	lsr r0, r0, #3
	sub r0, r0, #5
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	str r0, [sp, #0x24]
_0225E5A2:
	ldr r0, _0225E724 ; =ov28_0225EB14
	mov r7, #0
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x30]
	add r4, r6, #0
	sub r0, r0, #3
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x30]
	add r0, r0, #3
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x24]
	sub r0, r0, #3
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	add r0, r0, #3
	str r0, [sp, #0x1c]
_0225E5C2:
	ldr r0, [sp, #0x24]
	mov r5, #0
	sub r0, r0, r7
	str r0, [sp, #0x18]
	lsl r0, r7, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x14]
	add r0, r7, #5
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x3c]
_0225E5D8:
	mov r0, #1
	add r1, r0, #0
	ldr r0, [sp, #0x34]
	lsl r1, r5
	ldrh r0, [r0]
	tst r0, r1
	beq _0225E5E8
	b _0225E6F6
_0225E5E8:
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bne _0225E67E
	ldr r0, [sp, #0x2c]
	cmp r5, r0
	blt _0225E658
	ldr r0, [sp, #0x28]
	cmp r5, r0
	bgt _0225E658
	ldr r0, [sp, #0x20]
	cmp r7, r0
	blt _0225E658
	ldr r0, [sp, #0x1c]
	cmp r7, r0
	bgt _0225E658
	ldr r0, [sp, #0x30]
	sub r0, r0, r5
	bl abs
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x18]
	bl abs
	ldr r1, [sp, #0x38]
	add r0, r1, r0
	cmp r0, #4
	bgt _0225E658
	lsl r1, r5, #0x10
	ldr r2, [sp, #0x14]
	add r0, r6, #0
	lsr r1, r1, #0x10
	bl ov28_0225E51C
	add r2, r0, #0
	mov r0, #0x25
	add r3, r4, r5
	lsl r0, r0, #4
	ldrb r0, [r3, r0]
	cmp r0, r2
	bhs _0225E650
	mov r0, #0x25
	lsl r0, r0, #4
	ldrb r1, [r3, r0]
	add r1, #0xa
	strb r1, [r3, r0]
	ldrb r0, [r3, r0]
	cmp r0, r2
	bls _0225E6A2
	mov r0, #0x25
	lsl r0, r0, #4
	strb r2, [r3, r0]
	b _0225E6A2
_0225E650:
	mov r0, #0x25
	lsl r0, r0, #4
	strb r2, [r3, r0]
	b _0225E6A2
_0225E658:
	mov r0, #0x25
	add r3, r4, r5
	lsl r0, r0, #4
	ldrb r0, [r3, r0]
	cmp r0, #2
	blo _0225E674
	mov r0, #0x25
	lsl r0, r0, #4
	ldrb r0, [r3, r0]
	sub r1, r0, #2
	mov r0, #0x25
	lsl r0, r0, #4
	strb r1, [r3, r0]
	b _0225E6A2
_0225E674:
	mov r0, #0x25
	mov r1, #0
	lsl r0, r0, #4
	strb r1, [r3, r0]
	b _0225E6A2
_0225E67E:
	mov r0, #0x25
	add r3, r4, r5
	lsl r0, r0, #4
	ldrb r0, [r3, r0]
	cmp r0, #2
	blo _0225E69A
	mov r0, #0x25
	lsl r0, r0, #4
	ldrb r0, [r3, r0]
	sub r1, r0, #2
	mov r0, #0x25
	lsl r0, r0, #4
	strb r1, [r3, r0]
	b _0225E6A2
_0225E69A:
	mov r0, #0x25
	mov r1, #0
	lsl r0, r0, #4
	strb r1, [r3, r0]
_0225E6A2:
	mov r0, #0x25
	lsl r0, r0, #4
	ldrb r0, [r3, r0]
	cmp r0, #0
	bne _0225E6CC
	ldr r0, [sp, #0x3c]
	add r3, r5, #3
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x11
	str r0, [sp, #0xc]
	lsl r3, r3, #0x18
	ldr r0, [r6, #0x10]
	ldr r2, _0225E728 ; =0x00001001
	mov r1, #6
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	b _0225E6F6
_0225E6CC:
	mov r1, #0xa
	bl _s32_div_f
	add r2, r0, #0
	ldr r0, [sp, #0x3c]
	lsl r3, r2, #1
	str r0, [sp]
	mov r0, #1
	ldr r2, _0225E72C ; =ov28_0225EB32
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x11
	ldrh r2, [r2, r3]
	add r3, r5, #3
	str r0, [sp, #0xc]
	lsl r3, r3, #0x18
	ldr r0, [r6, #0x10]
	mov r1, #6
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
_0225E6F6:
	add r0, r5, #1
	lsl r0, r0, #0x10
	asr r5, r0, #0x10
	cmp r5, #0xf
	bge _0225E702
	b _0225E5D8
_0225E702:
	ldr r0, [sp, #0x34]
	add r4, #0xf
	add r0, r0, #2
	str r0, [sp, #0x34]
	add r0, r7, #1
	lsl r0, r0, #0x10
	asr r7, r0, #0x10
	cmp r7, #0xf
	bge _0225E716
	b _0225E5C2
_0225E716:
	ldr r0, [r6, #0x10]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225E724: .word ov28_0225EB14
_0225E728: .word 0x00001001
_0225E72C: .word ov28_0225EB32
	thumb_func_end ov28_0225E578

thumb_func_start ov28_0225E730
ov28_0225E730: ; 0x0225E730
	push {r3, r4, r5, r6, r7, lr}
	add r1, sp, #0
	add r1, #2
	add r2, sp, #0
	add r5, r0, #0
	bl ov28_0225E374
	add r0, sp, #0
	ldrh r1, [r0, #2]
	ldrh r0, [r0]
	mov r2, #0x21
	lsl r2, r2, #4
	lsl r0, r0, #1
	add r0, r1, r0
	lsl r1, r0, #6
	mov r0, #0xf
	lsl r0, r0, #6
	sub r0, r1, r0
	lsl r0, r0, #0x10
	asr r4, r0, #0x10
	ldr r0, [r5, r2]
	cmp r0, #4
	bne _0225E798
	add r1, r2, #0
	add r1, #8
	ldr r1, [r5, r1]
	add r0, r2, #4
	lsr r1, r1, #3
	ldr r0, [r5, r0]
	sub r2, #8
	sub r6, r1, #5
	ldrsh r1, [r5, r2]
	lsr r0, r0, #3
	sub r0, r0, #3
	add r1, r1, #7
	sub r0, r1, r0
	bl abs
	add r7, r0, #0
	ldr r0, _0225E7C8 ; =0x0000020A
	ldrsh r0, [r5, r0]
	add r0, r0, #7
	sub r0, r0, r6
	bl abs
	add r1, r7, r0
	mov r0, #0x10
	sub r0, r0, r1
	lsl r0, r0, #6
	add r0, r4, r0
	lsl r0, r0, #0x10
	asr r4, r0, #0x10
_0225E798:
	mov r0, #0xce
	lsl r0, r0, #2
	ldrh r0, [r5, r0]
	cmp r0, #0
	bne _0225E7AA
	ldr r0, _0225E7CC ; =0x0000093D
	add r1, r4, #0
	bl PlaySE_SetPitch
_0225E7AA:
	mov r0, #0xce
	lsl r0, r0, #2
	ldrh r1, [r5, r0]
	cmp r1, #0xa
	bne _0225E7B8
	mov r1, #0
	b _0225E7BA
_0225E7B8:
	add r1, r1, #1
_0225E7BA:
	strh r1, [r5, r0]
	ldr r0, _0225E7D0 ; =0x0000033A
	ldrsh r1, [r5, r0]
	cmp r1, r4
	beq _0225E7C6
	strh r4, [r5, r0]
_0225E7C6:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225E7C8: .word 0x0000020A
_0225E7CC: .word 0x0000093D
_0225E7D0: .word 0x0000033A
	thumb_func_end ov28_0225E730
