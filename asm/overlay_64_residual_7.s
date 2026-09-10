	.include "asm/macros.inc"
	.include "overlay_64.inc"
	.include "global.inc"
	.public HallOfFameShowcase_Init
	.public HallOfFameShowcase_Main
	.public _021E6E7C
	.public ov64_021E5B10
	.public ov64_021E5CD0
	.public ov64_021E607C
	.public ov64_021E6170
	.public ov64_021E62C8
	.public ov64_021E652C
	.public ov64_021E677C
	.public ov64_021E6B84
	.public ov64_021E6C1C
	.public ov64_021E6E88
	.public ov64_021E6E98
	.public ov64_021E6EA8
	.public ov64_021E6EB8
	.public ov64_021E6ECC
	.public ov64_021E6ECE
	.public ov64_021E6EE4
	.public ov64_021E6EFC
	.public ov64_021E6F18
	.public ov64_021E6F34
	.public ov64_021E6F50
	.public ov64_021E6F6C
	.public ov64_021E6F8C
	.public ov64_021E6FAC
	.public ov64_021E6FD4
	.public ov64_021E7008
	.public ov64_021E7040
	.public ov64_021E70C8
	.public ov64_021E70FC
	.public ov64_021E73A0
	.public ov64_021E73D4
	.public ov64_021E7408
	.public ov64_021E743C


	.text
	.public HallOfFameShowcase_Exit
	.public ov64_021E5A88
	.public ov64_021E5AAC
	.public ov64_021E5AC8
	.public ov64_021E5AE4
	.public ov64_021E5B00
	.public ov64_021E5CA4
	.public ov64_021E6010
	.public ov64_021E602C
	.public ov64_021E605C
	.public ov64_021E6118
	.public ov64_021E620C
	.public ov64_021E622C
	.public ov64_021E6260
	.public ov64_021E6270
	.public ov64_021E6274
	.public ov64_021E6278
	.public ov64_021E6280
	.public ov64_021E6288
	.public ov64_021E62A8
	.public ov64_021E64F8
	.public ov64_021E6754
	.public ov64_021E6BD8
	.public ov64_021E6E30

	thumb_func_start ov64_021E62C8
ov64_021E62C8: ; 0x021E62C8
	push {r3, r4, r5, lr}
	mov r1, #0x72
	add r4, r0, #0
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	cmp r1, #4
	bhi _021E63A2
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E62E2: ; jump table
	.short _021E62EC - _021E62E2 - 2 ; case 0
	.short _021E649E - _021E62E2 - 2 ; case 1
	.short _021E64B2 - _021E62E2 - 2 ; case 2
	.short _021E64C4 - _021E62E2 - 2 ; case 3
	.short _021E64D4 - _021E62E2 - 2 ; case 4
_021E62EC:
	ldr r0, _021E64E8 ; =_021E6E7C
	bl TouchscreenHitbox_FindRectAtTouchNew
	cmp r0, #0
	bne _021E6324
	mov r1, #0x6d
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	cmp r0, #0
	ble _021E63A2
	add r0, r1, #0
	mov r2, #0xf
	add r0, #8
	str r2, [r4, r0]
	add r0, r1, #0
	mov r2, #2
	add r0, #0x18
	str r2, [r4, r0]
	mov r0, #1
	add r1, #0x14
	str r0, [r4, r1]
	add r0, r4, #0
	bl ov64_021E64F8
	ldr r0, _021E64EC ; =0x000005DC
	bl PlaySE
	b _021E64E2
_021E6324:
	cmp r0, #1
	bne _021E635E
	mov r1, #0x6e
	lsl r1, r1, #2
	ldr r3, [r4, r1]
	cmp r3, #1
	blt _021E63A2
	sub r0, r1, #4
	ldr r2, [r4, r0]
	sub r0, r3, #1
	cmp r2, r0
	beq _021E63A2
	mov r2, #0x10
	add r0, r1, #4
	str r2, [r4, r0]
	add r0, r1, #0
	mov r2, #3
	add r0, #0x14
	str r2, [r4, r0]
	mov r0, #1
	add r1, #0x10
	str r0, [r4, r1]
	add r0, r4, #0
	bl ov64_021E64F8
	ldr r0, _021E64EC ; =0x000005DC
	bl PlaySE
	b _021E64E2
_021E635E:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl GridInputHandler_HandleInput_AllowHold
	mov r1, #2
	add r5, r0, #0
	mvn r1, r1
	cmp r5, r1
	bhi _021E639A
	bhs _021E63F6
	cmp r5, #6
	bhi _021E6392
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E6384: ; jump table
	.short _021E63AC - _021E6384 - 2 ; case 0
	.short _021E63AC - _021E6384 - 2 ; case 1
	.short _021E63AC - _021E6384 - 2 ; case 2
	.short _021E63AC - _021E6384 - 2 ; case 3
	.short _021E63AC - _021E6384 - 2 ; case 4
	.short _021E63AC - _021E6384 - 2 ; case 5
	.short _021E63D2 - _021E6384 - 2 ; case 6
_021E6392:
	mov r0, #3
	mvn r0, r0
	cmp r5, r0
	b _021E64E2
_021E639A:
	add r0, r1, #1
	cmp r5, r0
	bhi _021E63A4
	beq _021E63D2
_021E63A2:
	b _021E64E2
_021E63A4:
	add r0, r1, #2
	cmp r5, r0
	beq _021E6410
	b _021E64E2
_021E63AC:
	add r0, r4, #0
	add r1, r5, #0
	bl ov64_021E677C
	ldr r0, _021E64F0 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	bne _021E63C8
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r5, r0
	blo _021E63CA
_021E63C8:
	b _021E64E2
_021E63CA:
	ldr r0, _021E64EC ; =0x000005DC
	bl PlaySE
	b _021E64E2
_021E63D2:
	ldr r0, _021E64EC ; =0x000005DC
	bl PlaySE
	mov r1, #0x6f
	mov r0, #0x11
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r1, #0
	mov r2, #4
	add r0, #0x10
	str r2, [r4, r0]
	add r0, r1, #0
	add r0, #0xc
	ldr r0, [r4, r0]
	add r1, #0xc
	add r0, r0, #1
	str r0, [r4, r1]
	b _021E64E2
_021E63F6:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl GridInputHandler_GetNextInput
	add r1, r0, #0
	add r0, r4, #0
	bl ov64_021E677C
	ldr r0, _021E64EC ; =0x000005DC
	bl PlaySE
	b _021E64E2
_021E6410:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl GridInputHandler_GetNextInput
	ldr r1, _021E64F0 ; =gSystem
	ldr r2, [r1, #0x4c]
	mov r1, #0x10
	tst r1, r2
	beq _021E6462
	cmp r0, #2
	beq _021E642C
	cmp r0, #5
	bne _021E64E2
_021E642C:
	mov r1, #0x6e
	lsl r1, r1, #2
	ldr r3, [r4, r1]
	cmp r3, #1
	blt _021E64E2
	sub r0, r1, #4
	ldr r2, [r4, r0]
	sub r0, r3, #1
	cmp r2, r0
	beq _021E64E2
	mov r2, #0x10
	add r0, r1, #4
	str r2, [r4, r0]
	add r0, r1, #0
	mov r2, #3
	add r0, #0x14
	str r2, [r4, r0]
	mov r0, #1
	add r1, #0x10
	str r0, [r4, r1]
	add r0, r4, #0
	bl ov64_021E64F8
	ldr r0, _021E64EC ; =0x000005DC
	bl PlaySE
	b _021E64E2
_021E6462:
	mov r1, #0x20
	tst r1, r2
	beq _021E64E2
	cmp r0, #0
	beq _021E6470
	cmp r0, #3
	bne _021E64E2
_021E6470:
	mov r1, #0x6d
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	cmp r0, #0
	ble _021E64E2
	add r0, r1, #0
	mov r2, #0xf
	add r0, #8
	str r2, [r4, r0]
	add r0, r1, #0
	mov r2, #2
	add r0, #0x18
	str r2, [r4, r0]
	mov r0, #1
	add r1, #0x14
	str r0, [r4, r1]
	add r0, r4, #0
	bl ov64_021E64F8
	ldr r0, _021E64EC ; =0x000005DC
	bl PlaySE
	b _021E64E2
_021E649E:
	bl ov64_021E6B84
	cmp r0, #0
	bne _021E64E2
	mov r0, #0x73
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	sub r0, r0, #4
	str r1, [r4, r0]
	b _021E64E2
_021E64B2:
	mov r1, #0
	mvn r1, r1
	bl ov64_021E652C
	mov r0, #0x72
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	b _021E64E2
_021E64C4:
	mov r1, #1
	bl ov64_021E652C
	mov r0, #0x72
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	b _021E64E2
_021E64D4:
	bl ov64_021E62A8
	ldr r0, _021E64F4 ; =0x0000060D
	bl PlaySE
	mov r0, #0
	pop {r3, r4, r5, pc}
_021E64E2:
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_021E64E8: .word _021E6E7C
_021E64EC: .word 0x000005DC
_021E64F0: .word gSystem
_021E64F4: .word 0x0000060D
	thumb_func_end ov64_021E62C8
