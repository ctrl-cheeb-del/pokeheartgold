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

thumb_func_start ov28_0225DC2C
ov28_0225DC2C: ; 0x0225DC2C
	push {r4, lr}
	add r4, r1, #0
	ldr r0, [r4, #0x18]
	add r1, r0, #0
	add r1, #0xd2
	ldrb r1, [r1]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1f
	beq _0225DC56
	bl FieldSystem_IsPlayerMovementAllowed
	cmp r0, #0
	beq _0225DC56
	ldr r2, [r4, #0x18]
	add r0, r2, #0
	add r0, #0xd2
	ldrb r1, [r0]
	mov r0, #0x80
	add r2, #0xd2
	bic r1, r0
	strb r1, [r2]
_0225DC56:
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0225DC76
	ldr r0, _0225DD1C ; =ov28_0225EA88
	bl TouchscreenHitbox_FindHitboxAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0225DC76
	mov r0, #0xcf
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r4, r0]
_0225DC76:
	ldr r0, [r4, #0x18]
	bl FieldSystem_TaskIsRunning
	cmp r0, #1
	beq _0225DC98
	ldr r0, _0225DD1C ; =ov28_0225EA88
	bl TouchscreenHitbox_FindHitboxAtTouchHeld
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0225DC98
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0225DCD0
_0225DC98:
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl ov28_0225E31C
	add r0, r4, #0
	mov r1, #0
	bl ov28_0225E578
	mov r2, #0x93
	lsl r2, r2, #2
	ldrh r1, [r4, r2]
	ldr r0, _0225DD20 ; =0xFFFF7FFF
	and r0, r1
	strh r0, [r4, r2]
	add r0, r2, #0
	mov r1, #0
	add r0, #0xec
	strh r1, [r4, r0]
	add r0, r2, #0
	add r0, #0xee
	strh r1, [r4, r0]
	add r2, #0xf0
	ldr r0, _0225DD24 ; =0x0000093D
	str r1, [r4, r2]
	bl StopSE
	b _0225DCF6
_0225DCD0:
	cmp r0, #1
	bne _0225DCF6
	add r0, r4, #0
	bl ov28_0225E7D4
	add r0, r4, #0
	bl ov28_0225E1A4
	add r0, r4, #0
	mov r1, #1
	bl ov28_0225E31C
	add r0, r4, #0
	mov r1, #1
	bl ov28_0225E578
	add r0, r4, #0
	bl ov28_0225E730
_0225DCF6:
	add r0, r4, #0
	bl ov28_0225E3BC
	add r0, r4, #0
	bl ov28_0225E43C
	add r0, r4, #0
	bl ov28_0225E900
	add r0, r4, #0
	bl ov28_0225E938
	add r0, r4, #0
	bl ov28_0225E9E0
	ldr r0, [r4, #0x24]
	bl SpriteList_RenderAndAnimateSprites
	pop {r4, pc}
	.balign 4, 0
_0225DD1C: .word ov28_0225EA88
_0225DD20: .word 0xFFFF7FFF
_0225DD24: .word 0x0000093D
	thumb_func_end ov28_0225DC2C
