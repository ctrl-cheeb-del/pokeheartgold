	.include "asm/macros.inc"
	.public _0225D5C0
	.public _0225D5C4
	.public _0225D5C8
	.public _0225D62C
	.public _0225D630
	.public _0225D796
	.public _0225D82C
	.public _0225D830
	.public _0225D980
	.public _0225D984
	.public _0225D99C
	.public _0225D9A0
	.public _0225D9D4
	.public _0225DA7C
	.public _0225DA80
	.public _0225DA84
	.public _0225DCB2
	.public _0225DCCC
	.public _0225DCD0
	.public _0225DD64
	.public _0225DDA0
	.public _0225DDA4
	.public _0225DDA8
	.public _0225DDDE
	.public _0225DDE6
	.public _0225DDF4
	.public _0225DE02
	.public _0225DE18
	.public _0225DE22
	.public _0225DE56
	.public _0225DE6C
	.public _0225DE8E
	.public _0225DEA0
	.public _0225DEA8
	.public _0225DEB2
	.public _0225DEBA
	.public _0225DEEA
	.public _0225DF0A
	.public _0225DF2A
	.public _0225DF3A
	.public _0225DF50
	.public _0225DF62
	.public _0225DF68
	.public _0225DF6C
	.public _0225DF70
	.public _0225DF74
	.public _0225DF78
	.public _0225DF7C
	.public _0225DFB0
	.public _0225DFBC
	.public _0225DFC6
	.public _0225DFCA
	.public _0225DFE4
	.public _0225E00C
	.public _0225E05E
	.public _0225E070
	.public _0225E092
	.public _0225E0A2
	.public _0225E0F4
	.public _0225E0F8
	.public _0225E158
	.public _0225E15C
	.public ov32_0225D520
	.public ov32_0225D60C
	.public ov32_0225D788
	.public ov32_0225D84C
	.public ov32_0225D988
	.public ov32_0225DA88
	.public ov32_0225DB1C
	.public ov32_0225DBAC
	.public ov32_0225DC0C
	.public ov32_0225DC68
	.public ov32_0225DD24
	.public ov32_0225DD74
	.public ov32_0225DDC4
	.public ov32_0225DE34
	.public ov32_0225DF9C
	.public ov32_0225DFE8
	.public ov32_0225E048
	.public ov32_0225E0A8
	.public ov32_0225E0FC
	.public ov32_0225E168
	.public ov32_0225E178
	.public ov32_0225E188
	.public ov32_0225E1A4
	.public ov32_0225E1C0
	.public ov32_0225E1DC
	.public ov32_0225E204
	.public ov32_0225E24C
	.public _0225E15C
	.public ov32_0225D520
	.public ov32_0225D5CC
	.public ov32_0225D608
	.public ov32_0225D60C
	.public ov32_0225D634
	.public ov32_0225D6C4
	.public ov32_0225D6E0
	.public ov32_0225D748
	.public ov32_0225D76C
	.public ov32_0225D788
	.public ov32_0225D834
	.public ov32_0225D84C
	.public ov32_0225D988
	.public ov32_0225DA88
	.public ov32_0225DAC0
	.public ov32_0225DADC
	.public ov32_0225DB00
	.public ov32_0225DB1C
	.public ov32_0225DBAC
	.public ov32_0225DC0C
	.public ov32_0225DC68
	.public ov32_0225DCD4
	.public ov32_0225DD04
	.public ov32_0225DD24
	.public ov32_0225DD74
	.public ov32_0225DDAC
	.public ov32_0225DDB8
	.public ov32_0225DDBC
	.public ov32_0225DDC4
	.public ov32_0225DE34
	.public ov32_0225DF80
	.public ov32_0225DF9C
	.public ov32_0225DFE8
	.public ov32_0225E048
	.public ov32_0225E0A8
	.public ov32_0225E0FC
	.include "overlay_32.inc"
	.include "global.inc"

	.text
	.public ov32_0225D5CC
	.public ov32_0225D608
	.public ov32_0225D634
	.public ov32_0225D6C4
	.public ov32_0225D6E0
	.public ov32_0225D748
	.public ov32_0225D76C
	.public ov32_0225D834
	.public ov32_0225DAC0
	.public ov32_0225DADC
	.public ov32_0225DB00
	.public ov32_0225DCD4
	.public ov32_0225DD04
	.public ov32_0225DDAC
	.public ov32_0225DDB8
	.public ov32_0225DDBC
	.public ov32_0225DF80

	thumb_func_start ov32_0225DDC4
ov32_0225DDC4: ; 0x0225DDC4
	push {r4, lr}
	mov r0, #0xaa
	add r4, r1, #0
	lsl r0, r0, #2
	ldrb r1, [r4, r0]
	cmp r1, #3
	bhi _0225DE22
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0225DDDE: ; jump table
	.short _0225DDE6 - _0225DDDE - 2 ; case 0
	.short _0225DDF4 - _0225DDDE - 2 ; case 1
	.short _0225DE02 - _0225DDDE - 2 ; case 2
	.short _0225DE18 - _0225DDDE - 2 ; case 3
_0225DDE6:
	add r0, r4, #0
	bl ov32_0225DE34
	mov r1, #0xaa
	lsl r1, r1, #2
	strb r0, [r4, r1]
	b _0225DE22
_0225DDF4:
	add r0, r4, #0
	bl ov32_0225DF80
	mov r1, #0xaa
	lsl r1, r1, #2
	strb r0, [r4, r1]
	b _0225DE22
_0225DE02:
	add r0, r4, #0
	bl ov32_0225D84C
	add r0, r4, #0
	bl ov32_0225D988
	mov r0, #0xaa
	mov r1, #0
	lsl r0, r0, #2
	strb r1, [r4, r0]
	b _0225DE22
_0225DE18:
	add r1, r0, #4
	add r0, #8
	ldr r1, [r4, r1]
	ldr r0, [r4, r0]
	str r1, [r0]
_0225DE22:
	add r0, r4, #0
	bl ov32_0225DD04
	mov r0, #0x53
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl SpriteList_RenderAndAnimateSprites
	pop {r4, pc}
	thumb_func_end ov32_0225DDC4


	thumb_func_start ov32_0225DE34
ov32_0225DE34: ; 0x0225DE34
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _0225DF6C ; =_0225E15C
	bl TouchscreenHitbox_FindRectAtTouchNew
	cmp r0, #0
	bne _0225DE56
	mov r0, #0x5e
	lsl r0, r0, #4
	bl PlaySE
	mov r1, #0
	add r0, r5, #0
	mvn r1, r1
	bl ov32_0225DF9C
	pop {r3, r4, r5, pc}
_0225DE56:
	cmp r0, #1
	bne _0225DE6C
	mov r0, #0x5e
	lsl r0, r0, #4
	bl PlaySE
	add r0, r5, #0
	mov r1, #1
	bl ov32_0225DF9C
	pop {r3, r4, r5, pc}
_0225DE6C:
	ldr r0, [r5, #0x18]
	bl GridInputHandler_HandleInput_AllowHold
	mov r1, #2
	add r4, r0, #0
	mvn r1, r1
	cmp r4, r1
	bhi _0225DEA8
	bhs _0225DF62
	cmp r4, #8
	bhi _0225DEA0
	add r0, r4, r4
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225DE8E: ; jump table
	.short _0225DEBA - _0225DE8E - 2 ; case 0
	.short _0225DEBA - _0225DE8E - 2 ; case 1
	.short _0225DEBA - _0225DE8E - 2 ; case 2
	.short _0225DEBA - _0225DE8E - 2 ; case 3
	.short _0225DEBA - _0225DE8E - 2 ; case 4
	.short _0225DEBA - _0225DE8E - 2 ; case 5
	.short _0225DEBA - _0225DE8E - 2 ; case 6
	.short _0225DEBA - _0225DE8E - 2 ; case 7
	.short _0225DEEA - _0225DE8E - 2 ; case 8
_0225DEA0:
	mov r0, #3
	mvn r0, r0
	cmp r4, r0
	b _0225DF68
_0225DEA8:
	add r0, r1, #1
	cmp r4, r0
	bhi _0225DEB2
	beq _0225DEEA
	b _0225DF68
_0225DEB2:
	add r0, r1, #2
	cmp r4, r0
	beq _0225DF0A
	b _0225DF68
_0225DEBA:
	ldr r0, _0225DF70 ; =0x000005DD
	bl PlaySE
	ldr r0, _0225DF74 ; =0x000002AA
	lsr r3, r4, #1
	ldrsb r1, [r5, r0]
	add r0, r0, #2
	lsl r2, r3, #2
	add r2, r3, r2
	lsl r1, r1, #3
	add r1, r4, r1
	str r1, [r5, r0]
	lsl r1, r4, #0x1f
	lsr r1, r1, #0x1b
	add r1, r1, #2
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #3
	bl ov32_0225E0FC
	pop {r3, r4, r5, pc}
_0225DEEA:
	ldr r0, _0225DF70 ; =0x000005DD
	bl PlaySE
	mov r1, #1
	mov r0, #0xab
	mvn r1, r1
	lsl r0, r0, #2
	str r1, [r5, r0]
	mov r2, #3
	str r2, [sp]
	add r0, r5, #0
	mov r1, #1
	mov r3, #2
	bl ov32_0225E0A8
	pop {r3, r4, r5, pc}
_0225DF0A:
	ldr r0, [r5, #0x18]
	bl GridInputHandler_GetNextInput
	ldr r1, _0225DF78 ; =gSystem
	ldr r2, [r1, #0x4c]
	mov r1, #0x10
	tst r1, r2
	beq _0225DF3A
	cmp r0, #1
	beq _0225DF2A
	cmp r0, #3
	beq _0225DF2A
	cmp r0, #5
	beq _0225DF2A
	cmp r0, #7
	bne _0225DF3A
_0225DF2A:
	ldr r0, _0225DF7C ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	mov r1, #1
	bl ov32_0225DF9C
	pop {r3, r4, r5, pc}
_0225DF3A:
	mov r1, #0x20
	tst r1, r2
	beq _0225DF68
	cmp r0, #0
	beq _0225DF50
	cmp r0, #2
	beq _0225DF50
	cmp r0, #4
	beq _0225DF50
	cmp r0, #6
	bne _0225DF68
_0225DF50:
	ldr r0, _0225DF7C ; =0x000005DC
	bl PlaySE
	mov r1, #0
	add r0, r5, #0
	mvn r1, r1
	bl ov32_0225DF9C
	pop {r3, r4, r5, pc}
_0225DF62:
	ldr r0, _0225DF7C ; =0x000005DC
	bl PlaySE
_0225DF68:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0225DF6C: .word _0225E15C
_0225DF70: .word 0x000005DD
_0225DF74: .word 0x000002AA
_0225DF78: .word gSystem
_0225DF7C: .word 0x000005DC
	thumb_func_end ov32_0225DE34
