	.include "asm/macros.inc"
	.public ov29_0225D520
	.public ov29_0225D5EC
	.public ov29_0225D61C
	.public ov29_0225D620
	.public ov29_0225D648
	.public ov29_0225D6B4
	.public ov29_0225D6C8
	.public ov29_0225D714
	.public ov29_0225D7D4
	.public ov29_0225D7F0
	.public ov29_0225D828
	.public ov29_0225D840
	.public ov29_0225D864
	.public ov29_0225D880
	.public ov29_0225D910
	.public ov29_0225D970
	.public ov29_0225D9C8
	.public ov29_0225DB38
	.public ov29_0225DB7C
	.public ov29_0225DB9C
	.public ov29_0225DBF0
	.public ov29_0225DC34
	.public ov29_0225DC44
	.public ov29_0225DC48
	.public ov29_0225DC50
	.public ov29_0225DC84
	.public ov29_0225DCD0
	.public ov29_0225DEB8
	.public ov29_0225DEF4
	.public ov29_0225DF18
	.public ov29_0225DF74
	.public ov29_0225E028
	.public ov29_0225E078
	.public ov29_0225E0E0
	.public ov29_0225E114
	.public ov29_0225E115
	.public ov29_0225E11D
	.public ov29_0225E129
	.public ov29_0225E13C
	.public ov29_0225E14C
	.public ov29_0225E160
	.public ov29_0225E178
	.public ov29_0225E190
	.public ov29_0225E1AC
	.public ov29_0225E1C8
	.public ov29_0225E1E4
	.public ov29_0225E200
	.public ov29_0225E21C
	.public ov29_0225E220
	.public ov29_0225E224
	.public ov29_0225E228
	.public ov29_0225E22C
	.public ov29_0225E230
	.public ov29_0225E234
	.public ov29_0225E238
	.public ov29_0225E23C
	.public ov29_0225E240
	.public ov29_0225E244
	.public ov29_0225E248
	.public ov29_0225E280
	.public ov29_0225E2E8
	.public ov29_0225E2EC
	.public ov29_0225E2F0
	.public ov29_0225E2F4
	.public ov29_0225E2FC
	.include "overlay_29.inc"
	.include "global.inc"

	.text

	thumb_func_start ov29_0225DCD0
ov29_0225DCD0: ; 0x0225DCD0
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	mov r0, #0x7e
	add r4, r1, #0
	lsl r0, r0, #2
	ldrh r1, [r4, r0]
	cmp r1, #0
	beq _0225DCEA
	cmp r1, #1
	bne _0225DCE6
	b _0225DE86
_0225DCE6:
	cmp r1, #2
	b _0225DE98
_0225DCEA:
	add r0, r0, #4
	ldr r0, [r4, r0]
	lsl r1, r0, #2
	ldr r0, _0225DEA8 ; =ov29_0225E1AC
	ldr r0, [r0, r1]
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	add r5, r0, #0
	mvn r1, r1
	cmp r5, r1
	beq _0225DD42
	mov r0, #0x7d
	lsl r0, r0, #2
	str r5, [r4, r0]
	add r0, r4, #0
	bl ov29_0225DC50
	mov r0, #0x7d
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	sub r0, #0x18
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r3, [r1, r0]
	add r1, r5, #5
	add r2, r3, #0
	add r2, #0xc
	add r3, r3, #1
	mov r0, #0
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsl r3, r3, #0x18
	str r0, [sp]
	add r0, r4, #0
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl ov29_0225E028
	ldr r0, _0225DEAC ; =0x000005DD
	bl PlaySE
	b _0225DE98
_0225DD42:
	ldr r0, _0225DEB0 ; =gSystem
	ldr r2, [r0, #0x48]
	mov r0, #8
	tst r0, r2
	beq _0225DD68
	mov r0, #0x1d
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0xb
	bl GridInputHandler_SetNextInput
	add r0, r4, #0
	mov r1, #0xb
	bl ov29_0225DB9C
	ldr r0, _0225DEAC ; =0x000005DD
	bl PlaySE
	b _0225DE98
_0225DD68:
	mov r0, #2
	tst r0, r2
	beq _0225DD80
	add r0, r4, #0
	bl ov29_0225DEB8
	cmp r0, #1
	bne _0225DD90
	ldr r0, _0225DEAC ; =0x000005DD
	bl PlaySE
	b _0225DE98
_0225DD80:
	mov r0, #0x1d
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl GridInputHandler_HandleInput_AllowHold
	add r5, r0, #0
	cmp r5, #0xc
	bls _0225DD92
_0225DD90:
	b _0225DE98
_0225DD92:
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225DD9E: ; jump table
	.short _0225DDB8 - _0225DD9E - 2 ; case 0
	.short _0225DDB8 - _0225DD9E - 2 ; case 1
	.short _0225DDB8 - _0225DD9E - 2 ; case 2
	.short _0225DDB8 - _0225DD9E - 2 ; case 3
	.short _0225DDB8 - _0225DD9E - 2 ; case 4
	.short _0225DDB8 - _0225DD9E - 2 ; case 5
	.short _0225DDB8 - _0225DD9E - 2 ; case 6
	.short _0225DDB8 - _0225DD9E - 2 ; case 7
	.short _0225DDB8 - _0225DD9E - 2 ; case 8
	.short _0225DDB8 - _0225DD9E - 2 ; case 9
	.short _0225DE00 - _0225DD9E - 2 ; case 10
	.short _0225DE22 - _0225DD9E - 2 ; case 11
	.short _0225DE68 - _0225DD9E - 2 ; case 12
_0225DDB8:
	add r0, r4, #0
	add r1, r5, #0
	bl ov29_0225DEF4
	add r0, r4, #0
	mov r1, #1
	bl ov29_0225DEB8
	add r0, r5, #0
	mov r1, #5
	bl _u32_div_f
	add r6, r1, #0
	add r0, r5, #0
	mov r1, #5
	bl _u32_div_f
	add r2, r0, #0
	mov r3, #6
	add r1, r6, #0
	mul r1, r3
	mul r3, r2
	add r2, r3, #7
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #0
	bl ov29_0225E078
	ldr r0, _0225DEAC ; =0x000005DD
	bl PlaySE
	b _0225DE98
_0225DE00:
	mov r0, #0
	str r0, [sp]
	add r0, r4, #0
	mov r1, #2
	mov r2, #4
	mov r3, #3
	bl ov29_0225E028
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl ov29_0225DEB8
	ldr r0, _0225DEAC ; =0x000005DD
	bl PlaySE
	b _0225DE98
_0225DE22:
	add r0, r4, #0
	bl ov29_0225E0E0
	mov r0, #2
	lsl r0, r0, #8
	ldr r2, [r4, #0x10]
	ldr r1, [r4, r0]
	ldr r0, [r2]
	cmp r1, r0
	bls _0225DE4E
	mov r0, #0
	mov r1, #3
	str r0, [sp]
	add r0, r4, #0
	mov r2, #4
	add r3, r1, #0
	bl ov29_0225E028
	ldr r0, _0225DEAC ; =0x000005DD
	bl PlaySE
	b _0225DE98
_0225DE4E:
	str r1, [r2, #4]
	mov r0, #2
	mov r1, #3
	str r0, [sp]
	add r0, r4, #0
	mov r2, #4
	add r3, r1, #0
	bl ov29_0225E028
	ldr r0, _0225DEAC ; =0x000005DD
	bl PlaySE
	b _0225DE98
_0225DE68:
	ldr r0, [r4, #0x10]
	mov r1, #0
	str r1, [r0, #4]
	mov r0, #2
	mov r1, #4
	str r0, [sp]
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #3
	bl ov29_0225E028
	ldr r0, _0225DEAC ; =0x000005DD
	bl PlaySE
	b _0225DE98
_0225DE86:
	add r0, r4, #0
	bl ov29_0225DF74
	cmp r0, #0
	bne _0225DE98
	ldr r0, _0225DEB4 ; =0x000001FA
	ldrh r1, [r4, r0]
	sub r0, r0, #2
	strh r1, [r4, r0]
_0225DE98:
	add r0, r4, #0
	bl ov29_0225DB7C
	ldr r0, [r4, #0x18]
	bl SpriteList_RenderAndAnimateSprites
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0225DEA8: .word ov29_0225E1AC
_0225DEAC: .word 0x000005DD
_0225DEB0: .word gSystem
_0225DEB4: .word 0x000001FA
	thumb_func_end ov29_0225DCD0
