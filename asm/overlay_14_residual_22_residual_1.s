#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.public GridInputHandler_GetNextInput
	.public GridInputHandler_SetButtonInputMode
	.public GridInputHandler_SetNextInput
	.public PlaySE
	.public System_GetTouchNew
	.public System_GetTouchNewCoords
	.public gSystem
	.public ov14_021E6070
	.public ov14_021E7588
	.public ov14_021E765C
	.public ov14_021E76B8
	.public ov14_021E8248
	.public ov14_021E82A8
	.public ov14_021E8328
	.public ov14_021E84A4
	.public ov14_021E8544
	.public ov14_021E884C
	.public ov14_021EA180
	.public ov14_021F0234
	.public ov14_021F0244
	.public ov14_021F028C
	.public ov14_021F0314
	.public ov14_021F039C
	.public ov14_021F0530
	.public ov14_021F1128
	.public ov14_021F2270
	.public ov14_021F2330
	.public ov14_021F2A18
	.public ov14_021F40E8
	.public ov14_021F5EE4
	.public ov14_021F6A14
	.public ov14_021F6F94
	.public ov14_021F7AC4
	.public ov14_021F7D3C
	.text

	thumb_func_start ov14_021EB388
ov14_021EB388: ; 0x021EB388
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bl ov14_021F6A14
	add r5, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r5, r0
	beq _021EB490
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xac
	mov r3, #0
	bl ov14_021E6070
	cmp r0, #0
	beq _021EB3F4
	ldr r0, _021EB6E4 ; =0x000005EB
	bl PlaySE
	ldr r2, [r4, #0x34]
	ldr r1, _021EB6E8 ; =0x000040B8
	add r0, r2, r1
	add r1, r1, #4
	add r1, r2, r1
	bl System_GetTouchNewCoords
	mov r0, #0x2f
	ldr r1, [r4, #0x34]
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	bl ov14_021E8544
	cmp r0, #0
	bne _021EB3D8
	ldr r1, _021EB6EC ; =ov14_021F7D3C
	add r0, r4, #0
	mov r2, #5
	bl ov14_021F5EE4
_021EB3D8:
	add r0, r4, #0
	add r1, r5, #0
	bl ov14_021E7588
	ldr r0, [r4, #0x34]
	mov r1, #9
	mov r2, #0
	bl ov14_021F2A18
	add r0, r4, #0
	add r1, r5, #0
	bl ov14_021F039C
	pop {r3, r4, r5, pc}
_021EB3F4:
	mov r0, #0x2f
	ldr r1, [r4, #0x34]
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	bl ov14_021E8544
	cmp r0, #1
	bne _021EB470
	add r0, r4, #0
	add r0, #0x21
	ldrb r5, [r0]
	ldr r0, [r4, #0x34]
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_GetNextInput
	add r2, r0, #0
	ldr r0, [r4, #0x34]
	add r1, r5, #0
	bl ov14_021F7AC4
	ldr r0, [r4, #0x34]
	add r1, r5, #0
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_SetNextInput
	mov r0, #0x2f
	ldr r1, [r4, #0x34]
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	bl ov14_021E84A4
	mov r0, #0x2f
	ldr r1, [r4, #0x34]
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	bl ov14_021E8248
	mov r0, #0x2f
	ldr r1, [r4, #0x34]
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	bl ov14_021E82A8
	mov r0, #0x2f
	ldr r1, [r4, #0x34]
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	bl ov14_021E8328
	ldr r0, [r4, #0x34]
	bl ov14_021E884C
	add r0, r4, #0
	mov r1, #0
	bl ov14_021F40E8
	ldr r1, _021EB6F0 ; =ov14_021EA180
	add r0, r4, #0
	mov r2, #0x4a
	bl ov14_021F0234
	pop {r3, r4, r5, pc}
_021EB470:
	ldr r0, [r4, #0x34]
	lsl r1, r5, #0x18
	ldr r0, [r0, #0x2c]
	lsr r1, r1, #0x18
	bl GridInputHandler_SetNextInput
	ldr r0, [r4, #0x34]
	mov r1, #1
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_SetButtonInputMode
	add r0, r4, #0
	bl ov14_021E765C
	mov r0, #0xc
	pop {r3, r4, r5, pc}
_021EB490:
	add r0, r4, #0
	bl ov14_021F6F94
	mov r1, #2
	add r5, r0, #0
	mvn r1, r1
	cmp r5, r1
	bhi _021EB4DC
	blo _021EB4A4
	b _021EB684
_021EB4A4:
	cmp r5, #0x29
	bhi _021EB4D0
	sub r0, #0x1e
	bmi _021EB4DA
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021EB4B8: ; jump table
	.short _021EB4F2 - _021EB4B8 - 2 ; case 0
	.short _021EB506 - _021EB4B8 - 2 ; case 1
	.short _021EB530 - _021EB4B8 - 2 ; case 2
	.short _021EB55A - _021EB4B8 - 2 ; case 3
	.short _021EB56C - _021EB4B8 - 2 ; case 4
	.short _021EB6C8 - _021EB4B8 - 2 ; case 5
	.short _021EB58C - _021EB4B8 - 2 ; case 6
	.short _021EB5BA - _021EB4B8 - 2 ; case 7
	.short _021EB5D0 - _021EB4B8 - 2 ; case 8
	.short _021EB5E2 - _021EB4B8 - 2 ; case 9
	.short _021EB5F4 - _021EB4B8 - 2 ; case 10
	.short _021EB606 - _021EB4B8 - 2 ; case 11
_021EB4D0:
	mov r0, #3
	mvn r0, r0
	cmp r5, r0
	bne _021EB4DA
	b _021EB714
_021EB4DA:
	b _021EB750
_021EB4DC:
	add r0, r1, #1
	cmp r5, r0
	bhi _021EB4E8
	bne _021EB4E6
	b _021EB6E0
_021EB4E6:
	b _021EB750
_021EB4E8:
	add r0, r1, #2
	cmp r5, r0
	bne _021EB4F0
	b _021EB63A
_021EB4F0:
	b _021EB750
_021EB4F2:
	ldr r0, _021EB6F4 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	bl ov14_021E76B8
	add r0, r4, #0
	bl ov14_021F1128
	pop {r3, r4, r5, pc}
_021EB506:
	ldr r0, _021EB6F8 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	bl ov14_021E76B8
	ldr r0, [r4, #0x34]
	mov r1, #9
	mov r2, #0
	bl ov14_021F2A18
	ldr r0, [r4, #0x34]
	mov r1, #0x1e
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_SetNextInput
	add r0, r4, #0
	mov r1, #0xc
	bl ov14_021F028C
	pop {r3, r4, r5, pc}
_021EB530:
	ldr r0, _021EB6F8 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	bl ov14_021E76B8
	ldr r0, [r4, #0x34]
	mov r1, #9
	mov r2, #0
	bl ov14_021F2A18
	ldr r0, [r4, #0x34]
	mov r1, #0x1e
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_SetNextInput
	add r0, r4, #0
	mov r1, #0xc
	bl ov14_021F0314
	pop {r3, r4, r5, pc}
_021EB55A:
	ldr r0, _021EB6FC ; =0x00000632
	bl PlaySE
	add r0, r4, #0
	mov r1, #8
	mov r2, #0x95
	bl ov14_021F2270
	pop {r3, r4, r5, pc}
_021EB56C:
	ldr r0, _021EB6FC ; =0x00000632
	bl PlaySE
	add r0, r4, #0
	mov r1, #0
	add r0, #0x2a
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x2b
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #9
	mov r2, #0x96
	bl ov14_021F2330
	pop {r3, r4, r5, pc}
_021EB58C:
	ldr r0, _021EB6F4 ; =0x000005DD
	bl PlaySE
	bl System_GetTouchNew
	cmp r0, #0
	bne _021EB5A2
	add r0, r4, #0
	mov r1, #1
	add r0, #0x2a
	strb r1, [r0]
_021EB5A2:
	add r0, r4, #0
	add r0, #0x21
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x2b
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #3
	mov r2, #0xb2
	bl ov14_021F2330
	pop {r3, r4, r5, pc}
_021EB5BA:
	ldr r0, _021EB6F4 ; =0x000005DD
	bl PlaySE
	mov r0, #0x25
	str r0, [r4, #0x2c]
	add r0, r4, #0
	mov r1, #4
	mov r2, #0x97
	bl ov14_021F2270
	pop {r3, r4, r5, pc}
_021EB5D0:
	ldr r0, _021EB6F4 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	mov r1, #5
	mov r2, #0x98
	bl ov14_021F2270
	pop {r3, r4, r5, pc}
_021EB5E2:
	ldr r0, _021EB6F4 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	mov r1, #6
	mov r2, #0x99
	bl ov14_021F2270
	pop {r3, r4, r5, pc}
_021EB5F4:
	ldr r0, _021EB6F4 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	mov r1, #7
	mov r2, #0x9b
	bl ov14_021F2270
	pop {r3, r4, r5, pc}
_021EB606:
	ldr r0, _021EB6F8 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	add r0, #0x21
	ldrb r5, [r0]
	ldr r0, [r4, #0x34]
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_GetNextInput
	add r2, r0, #0
	ldr r0, [r4, #0x34]
	add r1, r5, #0
	bl ov14_021F7AC4
	ldr r0, [r4, #0x34]
	add r1, r5, #0
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_SetNextInput
	add r0, r4, #0
	mov r1, #0xb
	mov r2, #0x9c
	bl ov14_021F2270
	pop {r3, r4, r5, pc}
_021EB63A:
	ldr r0, [r4, #0x34]
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_GetNextInput
	cmp r0, #0x1e
	bne _021EB66C
	ldr r0, _021EB700 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #0x20
	tst r0, r1
	beq _021EB666
	ldr r0, _021EB6F8 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	bl ov14_021E76B8
	add r0, r4, #0
	mov r1, #0xc
	bl ov14_021F028C
	pop {r3, r4, r5, pc}
_021EB666:
	mov r0, #0x10
	tst r0, r1
	bne _021EB66E
_021EB66C:
	b _021EB79E
_021EB66E:
	ldr r0, _021EB6F8 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	bl ov14_021E76B8
	add r0, r4, #0
	mov r1, #0xc
	bl ov14_021F0314
	pop {r3, r4, r5, pc}
_021EB684:
	ldr r0, [r4, #0x34]
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_GetNextInput
	add r1, r0, #0
	cmp r1, #0x1e
	bhs _021EB69A
	add r0, r4, #0
	bl ov14_021E7588
	b _021EB6B8
_021EB69A:
	cmp r1, #0x24
	beq _021EB6B8
	cmp r1, #0x25
	beq _021EB6B8
	cmp r1, #0x26
	beq _021EB6B8
	cmp r1, #0x27
	beq _021EB6B8
	cmp r1, #0x28
	beq _021EB6B8
	cmp r1, #0x29
	beq _021EB6B8
	add r0, r4, #0
	bl ov14_021E765C
_021EB6B8:
	ldr r0, _021EB6F8 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	mov r1, #0x4a
	bl ov14_021F0244
	pop {r3, r4, r5, pc}
_021EB6C8:
	ldr r0, _021EB6F4 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	bl ov14_021E765C
	add r0, r4, #0
	mov r1, #0xa
	mov r2, #0x93
	bl ov14_021F2270
	pop {r3, r4, r5, pc}
_021EB6E0:
	ldr r0, _021EB6F4 ; =0x000005DD
	b _021EB704
	.balign 4, 0
_021EB6E4: .word 0x000005EB
_021EB6E8: .word 0x000040B8
_021EB6EC: .word ov14_021F7D3C
_021EB6F0: .word ov14_021EA180
_021EB6F4: .word 0x000005DD
_021EB6F8: .word 0x000005DC
_021EB6FC: .word 0x00000632
_021EB700: .word gSystem
_021EB704:
	bl PlaySE
	add r0, r4, #0
	mov r1, #0xa
	mov r2, #0x94
	bl ov14_021F2270
	pop {r3, r4, r5, pc}
_021EB714:
	ldr r0, [r4, #0x34]
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_GetNextInput
	add r1, r0, #0
	cmp r1, #0x1e
	bhs _021EB72A
	add r0, r4, #0
	bl ov14_021E7588
	b _021EB748
_021EB72A:
	cmp r1, #0x24
	beq _021EB748
	cmp r1, #0x25
	beq _021EB748
	cmp r1, #0x26
	beq _021EB748
	cmp r1, #0x27
	beq _021EB748
	cmp r1, #0x28
	beq _021EB748
	cmp r1, #0x29
	beq _021EB748
	add r0, r4, #0
	bl ov14_021E765C
_021EB748:
	ldr r0, _021EB7A4 ; =0x000005DC
	bl PlaySE
	b _021EB79E
_021EB750:
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xac
	mov r3, #0
	bl ov14_021E6070
	cmp r0, #0
	beq _021EB79E
	ldr r0, _021EB7A8 ; =0x000005DD
	bl PlaySE
	ldr r1, _021EB7AC ; =ov14_021F7D3C
	add r0, r4, #0
	mov r2, #5
	bl ov14_021F5EE4
	add r0, r4, #0
	add r1, r5, #0
	bl ov14_021E7588
	ldr r0, [r4, #0x34]
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_GetNextInput
	add r2, r0, #0
	ldr r0, [r4, #0x34]
	mov r1, #0x24
	bl ov14_021F7AC4
	ldr r0, [r4, #0x34]
	mov r1, #0x24
	ldr r0, [r0, #0x2c]
	bl GridInputHandler_SetNextInput
	add r0, r4, #0
	add r1, r5, #0
	bl ov14_021F0530
	pop {r3, r4, r5, pc}
_021EB79E:
	mov r0, #0xc
	pop {r3, r4, r5, pc}
	nop
_021EB7A4: .word 0x000005DC
_021EB7A8: .word 0x000005DD
_021EB7AC: .word ov14_021F7D3C
	thumb_func_end ov14_021EB388
