	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.extern _022629F8
	.extern ov93_0225C730
	.extern ov93_02262A08

	thumb_func_start ov93_0225C574
ov93_0225C574: ; 0x0225C574
	push {r4, r5, r6, lr}
	add r6, r0, #0
	add r4, r1, #0
	bl OverlayManager_GetData
	add r5, r0, #0
	add r0, r6, #0
	bl OverlayManager_GetArgs
	add r6, r0, #0
	add r0, r5, #0
	bl ov93_0225C730
	cmp r0, #1
	bne _0225C596
	mov r0, #1
	pop {r4, r5, r6, pc}
_0225C596:
	ldr r0, [r4]
	cmp r0, #8
	bls _0225C59E
	b _0225C6B0
_0225C59E:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225C5AA: ; jump table
	.short _0225C5BC - _0225C5AA - 2 ; case 0
	.short _0225C5D8 - _0225C5AA - 2 ; case 1
	.short _0225C5F4 - _0225C5AA - 2 ; case 2
	.short _0225C610 - _0225C5AA - 2 ; case 3
	.short _0225C62C - _0225C5AA - 2 ; case 4
	.short _0225C654 - _0225C5AA - 2 ; case 5
	.short _0225C67A - _0225C5AA - 2 ; case 6
	.short _0225C690 - _0225C5AA - 2 ; case 7
	.short _0225C6B0 - _0225C5AA - 2 ; case 8
_0225C5BC:
	add r0, r5, #0
	mov r1, #0
	add r0, #0x31
	strb r1, [r0]
	ldr r0, _0225C6B8 ; =ov93_02262A08
	add r1, r5, #0
	mov r2, #0x75
	bl OverlayManager_New
	str r0, [r5, #0x28]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225C6B4
_0225C5D8:
	ldr r0, [r5, #0x28]
	bl OverlayManager_Run
	cmp r0, #1
	bne _0225C6B4
	ldr r0, [r5, #0x28]
	bl OverlayManager_Delete
	mov r0, #0
	str r0, [r5, #0x28]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225C6B4
_0225C5F4:
	add r0, r5, #0
	mov r1, #1
	add r0, #0x31
	strb r1, [r0]
	ldr r0, _0225C6BC ; =_022629F8
	add r1, r5, #0
	mov r2, #0x75
	bl OverlayManager_New
	str r0, [r5, #0x28]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225C6B4
_0225C610:
	ldr r0, [r5, #0x28]
	bl OverlayManager_Run
	cmp r0, #1
	bne _0225C6B4
	ldr r0, [r5, #0x28]
	bl OverlayManager_Delete
	mov r0, #0
	str r0, [r5, #0x28]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225C6B4
_0225C62C:
	add r6, #0x38
	ldrb r0, [r6]
	cmp r0, #0
	beq _0225C638
	bl ov00_021E6A4C
_0225C638:
	add r0, r5, #0
	mov r1, #2
	add r0, #0x31
	strb r1, [r0]
	ldr r0, _0225C6B8 ; =ov93_02262A08
	add r1, r5, #0
	mov r2, #0x75
	bl OverlayManager_New
	str r0, [r5, #0x28]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225C6B4
_0225C654:
	ldr r0, [r5, #0x28]
	bl OverlayManager_Run
	cmp r0, #1
	bne _0225C6B4
	ldr r0, [r5, #0x28]
	bl OverlayManager_Delete
	mov r1, #0
	str r1, [r5, #0x28]
	ldr r0, [r5, #0x38]
	cmp r0, #1
	bne _0225C672
	str r1, [r4]
	b _0225C6B4
_0225C672:
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225C6B4
_0225C67A:
	mov r0, #0
	mov r1, #1
	bl sub_020398D4
	mov r0, #0xde
	bl sub_02037AC0
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225C6B4
_0225C690:
	mov r0, #0xde
	bl sub_02037B38
	cmp r0, #1
	beq _0225C6A8
	bl sub_02037454
	add r5, r0, #0
	bl sub_020347A0
	cmp r5, r0
	bge _0225C6B4
_0225C6A8:
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225C6B4
_0225C6B0:
	mov r0, #1
	pop {r4, r5, r6, pc}
_0225C6B4:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0225C6B8: .word ov93_02262A08
_0225C6BC: .word _022629F8
	thumb_func_end ov93_0225C574
