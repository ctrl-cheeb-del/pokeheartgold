	.include "asm/macros.inc"
	.include "overlay_37.inc"
	.include "global.inc"

	.text
	.public _021E7968
	.public ov37_021E5900
	.public ov37_021E5A84
	.public ov37_021E5B94
	.public ov37_021E5CC8
	.public ov37_021E5CF0
	.public ov37_021E5D10
	.public ov37_021E5E30
	.public ov37_021E5F98
	.public ov37_021E6090
	.public ov37_021E60C0
	.public ov37_021E6244
	.public ov37_021E6418
	.public ov37_021E657C
	.public ov37_021E65EC
	.public ov37_021E69DC
	.public ov37_021E6B64
	.public ov37_021E6D14
	.public ov37_021E6F5C
	.public ov37_021E6FC8
	.public ov37_021E70BC
	.public ov37_021E713C
	.public ov37_021E72B4
	.public ov37_021E72E8
	.public ov37_021E73B4
	.public ov37_021E741C
	.public ov37_021E7478
	.public ov37_021E755C
	.public ov37_021E762C
	.public ov37_021E76F0
	.public ov37_021E78E0
	.public ov37_021E7970
	.public ov37_021E7978
	.public ov37_021E7988
	.public ov37_021E7998
	.public ov37_021E79B4
	.public ov37_021E79D0
	.public ov37_021E79EC
	.public ov37_021E7A08
	.public ov37_021E7A24
	.public ov37_021E7A4C
	.public ov37_021E7A80
	.public ov37_021E7AC8
	.public ov37_021E7D20

	.public ov37_021E5F20
	.public ov37_021E5F5C
	.public ov37_021E6540
	.public ov37_021E6818
	.public ov37_021E6848
	.public ov37_021E6860
	.public ov37_021E68AC
	.public ov37_021E68D0
	.public ov37_021E6928
	.public ov37_021E694C
	.public ov37_021E6980
	.public ov37_021E6B40
	.public ov37_021E6BFC
	.public ov37_021E6C38
	.public ov37_021E6C58
	.public ov37_021E6C84
	.public ov37_021E6CC0
	.public ov37_021E6DD0
	.public ov37_021E6E04
	.public ov37_021E6E2C
	.public ov37_021E6E6C
	.public ov37_021E6E70
	.public ov37_021E6E90
	.public ov37_021E6EB4
	.public ov37_021E6F14
	.public ov37_021E745C
	.public ov37_021E75C4
	.public ov37_021E75E0
	.public ov37_021E75E8
	.public ov37_021E76A0
	.public ov37_021E76C0
	.public ov37_021E76D0
	.public ov37_021E7844
	.public ov37_021E784C
	.public ov37_021E7880
	.public ov37_021E78A4
	.public ov37_021E78C4

	thumb_func_start ov37_021E657C
ov37_021E657C: ; 0x021E657C
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r0, #0
	add r5, r2, #0
	cmp r1, #0
	ble _021E659A
	lsl r0, r1, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _021E65A8
_021E659A:
	lsl r0, r1, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_021E65A8:
	bl _ffix
	sub r5, #8
	str r0, [sp]
	cmp r5, #0
	ble _021E65C6
	lsl r0, r5, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _021E65D4
_021E65C6:
	lsl r0, r5, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_021E65D4:
	bl _ffix
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, sp, #0
	bl Sprite_SetMatrix
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov37_021E657C


	thumb_func_start ov37_021E65EC
ov37_021E65EC: ; 0x021E65EC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x54
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, _021E67E8 ; =ov37_021E7A4C
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	str r0, [sp, #8]
	cmp r0, r1
	beq _021E663A
	cmp r0, #0xb
	bhi _021E663A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E6616: ; jump table
	.short _021E662E - _021E6616 - 2 ; case 0
	.short _021E662E - _021E6616 - 2 ; case 1
	.short _021E662E - _021E6616 - 2 ; case 2
	.short _021E662E - _021E6616 - 2 ; case 3
	.short _021E662E - _021E6616 - 2 ; case 4
	.short _021E662E - _021E6616 - 2 ; case 5
	.short _021E662E - _021E6616 - 2 ; case 6
	.short _021E662E - _021E6616 - 2 ; case 7
	.short _021E6656 - _021E6616 - 2 ; case 8
	.short _021E66FA - _021E6616 - 2 ; case 9
	.short _021E66FA - _021E6616 - 2 ; case 10
	.short _021E66FA - _021E6616 - 2 ; case 11
_021E662E:
	ldr r2, _021E67EC ; =0x00004376
	ldr r0, [sp]
	ldrb r1, [r0, r2]
	ldr r0, [sp, #8]
	cmp r1, r0
	bne _021E663C
_021E663A:
	b _021E6752
_021E663C:
	add r1, r0, #0
	ldr r0, [sp]
	strb r1, [r0, r2]
	mov r1, #0x92
	lsl r1, r1, #2
	add r0, r0, r1
	ldr r1, [sp, #8]
	bl ov37_021E6818
	ldr r0, _021E67F0 ; =0x000005DC
	bl PlaySE
	b _021E6752
_021E6656:
	mov r1, #0xc1
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	cmp r0, #4
	bne _021E6752
	bl sub_0203769C
	cmp r0, #0
	bne _021E66BC
	bl sub_02033250
	mov r2, #0xc7
	ldr r1, [sp]
	lsl r2, r2, #2
	ldr r1, [r1, r2]
	cmp r1, r0
	beq _021E6682
	ldr r0, _021E67F4 ; =0x000005F2
	bl PlaySE
	b _021E6752
_021E6682:
	bl sub_02037454
	bl sub_02038C1C
	ldr r1, _021E67F8 ; =0x000093F4
	ldr r0, [sp]
	mov r2, #2
	str r2, [r0, r1]
	mov r1, #1
	add r2, r1, #0
	bl ov37_021E762C
	ldr r0, [sp]
	mov r1, #5
	bl ov37_021E7844
	mov r1, #0x92
	ldr r0, [sp]
	lsl r1, r1, #2
	add r0, r0, r1
	mov r1, #1
	bl ov37_021E6848
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _021E67F0 ; =0x000005DC
	bl PlaySE
	b _021E6752
_021E66BC:
	ldr r1, _021E67FC ; =0x0000438B
	ldr r0, [sp]
	ldrb r0, [r0, r1]
	cmp r0, #2
	bne _021E66CE
	ldr r0, _021E67F4 ; =0x000005F2
	bl PlaySE
	b _021E6752
_021E66CE:
	mov r1, #1
	ldr r0, [sp]
	add r2, r1, #0
	bl ov37_021E762C
	ldr r0, [sp]
	mov r1, #5
	bl ov37_021E7844
	mov r1, #0x92
	ldr r0, [sp]
	lsl r1, r1, #2
	add r0, r0, r1
	mov r1, #1
	bl ov37_021E6848
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _021E67F0 ; =0x000005DC
	bl PlaySE
	b _021E6752
_021E66FA:
	ldr r0, [sp, #8]
	ldr r5, [sp]
	str r0, [sp, #0xc]
	sub r0, #9
	mov r4, #0
	mov r7, #0x1e
	mov r6, #0x1d
	str r0, [sp, #0xc]
_021E670A:
	ldr r0, [sp, #0xc]
	cmp r0, r4
	bne _021E671E
	mov r0, #0x9b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r7, #0
	bl Sprite_SetAnimCtrlSeq
	b _021E672A
_021E671E:
	mov r0, #0x9b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r6, #0
	bl Sprite_SetAnimCtrlSeq
_021E672A:
	add r4, r4, #1
	add r7, r7, #2
	add r5, r5, #4
	add r6, r6, #2
	cmp r4, #3
	blt _021E670A
	ldr r2, _021E6800 ; =0x00004377
	ldr r0, [sp]
	ldrb r1, [r0, r2]
	ldr r0, [sp, #8]
	sub r0, #9
	str r0, [sp, #8]
	cmp r1, r0
	beq _021E6752
	add r1, r0, #0
	ldr r0, [sp]
	strb r1, [r0, r2]
	ldr r0, _021E6804 ; =0x000005E5
	bl PlaySE
_021E6752:
	ldr r0, _021E6808 ; =ov37_021E7970
	bl TouchscreenHitbox_FindRectAtTouchHeld
	add r4, r0, #0
	bl sub_0203769C
	lsl r1, r0, #2
	ldr r0, [sp]
	add r1, r0, r1
	mov r0, #0x76
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _021E67A8
	bl sub_0203769C
	lsl r1, r0, #2
	ldr r0, [sp]
	ldr r2, _021E680C ; =gSystem + 0x40
	add r1, r0, r1
	mov r0, #0x76
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldrh r1, [r2, #0x20]
	ldrh r2, [r2, #0x22]
	bl ov37_021E657C
	bl sub_0203769C
	lsl r1, r0, #2
	ldr r0, [sp]
	add r1, r0, r1
	mov r0, #0x76
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
_021E67A8:
	add r0, sp, #0x10
	mov r1, #4
	mov r2, #0x40
	bl sub_02021280
	cmp r0, #1
	bne _021E67E2
	ldr r3, _021E6810 ; =0x00004378
	ldr r0, [sp]
	ldr r2, [sp]
	sub r4, r3, #2
	ldrb r2, [r2, r4]
	add r0, r0, r3
	sub r4, r3, #1
	ldr r3, [sp]
	add r1, sp, #0x10
	ldrb r3, [r3, r4]
	bl ov37_021E78E0
	ldr r0, [sp, #4]
	cmp r0, #1
	bne _021E67E2
	ldr r1, _021E6814 ; =0x00004380
	ldr r0, [sp]
	ldrb r2, [r0, r1]
	mov r0, #0x38
	bic r2, r0
	ldr r0, [sp]
	strb r2, [r0, r1]
_021E67E2:
	add sp, #0x54
	pop {r4, r5, r6, r7, pc}
	nop
_021E67E8: .word ov37_021E7A4C
_021E67EC: .word 0x00004376
_021E67F0: .word 0x000005DC
_021E67F4: .word 0x000005F2
_021E67F8: .word 0x000093F4
_021E67FC: .word 0x0000438B
_021E6800: .word 0x00004377
_021E6804: .word 0x000005E5
_021E6808: .word ov37_021E7970
_021E680C: .word gSystem + 0x40
_021E6810: .word 0x00004378
_021E6814: .word 0x00004380
	thumb_func_end ov37_021E65EC
