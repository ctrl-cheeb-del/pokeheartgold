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

	thumb_func_start ov29_0225D9C8
ov29_0225D9C8: ; 0x0225D9C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r6, r0, #0
	mov r0, #4
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #7
	str r0, [sp, #8]
	add r4, r1, #0
	mov r0, #2
	str r0, [sp, #0xc]
	ldr r0, _0225DB04 ; =0x00000399
	mov r1, #0x55
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	lsl r1, r1, #2
	str r0, [sp, #0x1c]
	add r0, r6, r1
	sub r1, #0x10
	add r1, r6, r1
	add r2, r4, #0
	mov r3, #5
	bl ov29_0225D880
	mov r1, #0x55
	lsl r1, r1, #2
	add r0, r6, r1
	sub r1, #0x10
	add r1, r6, r1
	add r2, sp, #0x20
	mov r3, #1
	bl ov29_0225D910
	ldr r3, _0225DB08 ; =ov29_0225E21C
	add r0, r6, #0
	mov r1, #0
	add r2, sp, #0x20
	bl ov29_0225D970
	ldr r3, _0225DB0C ; =ov29_0225E220
	add r0, r6, #0
	mov r1, #1
	add r2, sp, #0x20
	bl ov29_0225D970
	ldr r3, _0225DB10 ; =ov29_0225E224
	add r0, r6, #0
	mov r1, #2
	add r2, sp, #0x20
	bl ov29_0225D970
	ldr r3, _0225DB14 ; =ov29_0225E228
	add r0, r6, #0
	mov r1, #3
	add r2, sp, #0x20
	bl ov29_0225D970
	ldr r3, _0225DB18 ; =ov29_0225E22C
	add r0, r6, #0
	mov r1, #4
	add r2, sp, #0x20
	bl ov29_0225D970
	mov r0, #0
	str r0, [sp]
	mov r1, #2
	str r1, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, _0225DB1C ; =0x0000039A
	mov r1, #0x59
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	lsl r1, r1, #2
	str r0, [sp, #0x1c]
	add r0, r6, r1
	sub r1, #0x20
	add r1, r6, r1
	add r2, r4, #0
	mov r3, #1
	bl ov29_0225D880
	mov r1, #0x59
	lsl r1, r1, #2
	add r0, r6, r1
	sub r1, #0x20
	add r1, r6, r1
	add r2, sp, #0x20
	mov r3, #1
	bl ov29_0225D910
	ldr r3, _0225DB20 ; =ov29_0225E230
	add r0, r6, #0
	mov r1, #5
	add r2, sp, #0x20
	bl ov29_0225D970
	ldr r3, _0225DB24 ; =ov29_0225E234
	add r0, r6, #0
	mov r1, #6
	add r2, sp, #0x20
	bl ov29_0225D970
	ldr r3, _0225DB28 ; =ov29_0225E238
	add r0, r6, #0
	mov r1, #7
	add r2, sp, #0x20
	bl ov29_0225D970
	ldr r3, _0225DB2C ; =ov29_0225E23C
	add r0, r6, #0
	mov r1, #8
	add r2, sp, #0x20
	bl ov29_0225D970
	ldr r3, _0225DB30 ; =ov29_0225E240
	add r0, r6, #0
	mov r1, #9
	add r2, sp, #0x20
	bl ov29_0225D970
	ldr r3, _0225DB34 ; =ov29_0225E244
	add r0, r6, #0
	mov r1, #0xa
	add r2, sp, #0x20
	bl ov29_0225D970
	mov r7, #0x7f
	mov r4, #0
	add r5, r6, #0
	lsl r7, r7, #2
_0225DAD6:
	ldr r0, [r6, r7]
	cmp r4, r0
	bhs _0225DAEA
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	b _0225DAF6
_0225DAEA:
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0225DAF6:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #6
	blo _0225DAD6
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_0225DB04: .word 0x00000399
_0225DB08: .word ov29_0225E21C
_0225DB0C: .word ov29_0225E220
_0225DB10: .word ov29_0225E224
_0225DB14: .word ov29_0225E228
_0225DB18: .word ov29_0225E22C
_0225DB1C: .word 0x0000039A
_0225DB20: .word ov29_0225E230
_0225DB24: .word ov29_0225E234
_0225DB28: .word ov29_0225E238
_0225DB2C: .word ov29_0225E23C
_0225DB30: .word ov29_0225E240
_0225DB34: .word ov29_0225E244
	thumb_func_end ov29_0225D9C8
