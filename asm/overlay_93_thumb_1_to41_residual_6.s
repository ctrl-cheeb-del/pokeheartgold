	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225D4EC
	.public ov93_0225D5AC
	.extern ov93_0225E3C4
	.extern ov93_02262A68

	thumb_func_start ov93_0225D4EC
ov93_0225D4EC: ; 0x0225D4EC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	bl sub_0203769C
	str r0, [sp, #0x10]
	add r0, r5, #0
	str r0, [sp, #0x18]
	add r0, #0x30
	mov r4, #0
	str r0, [sp, #0x18]
	b _0225D590
_0225D504:
	ldr r0, [r5]
	ldr r2, [sp, #0x10]
	add r1, r0, r4
	add r1, #0x2c
	ldrb r1, [r1]
	cmp r2, r1
	beq _0225D58E
	bl ov90_022588CC
	mov r1, #0x75
	bl PlayerProfile_GetPlayerName_NewString
	ldr r1, [r5]
	add r6, r0, #0
	add r1, r1, r4
	add r1, #0x2c
	ldrb r1, [r1]
	add r0, r5, #0
	bl ov93_0225E3C4
	str r0, [sp, #0x14]
	ldr r0, [r5]
	add r1, r0, r4
	add r1, #0x2c
	ldrb r1, [r1]
	bl ov90_022588A4
	cmp r0, #1
	bne _0225D542
	ldr r7, _0225D5A0 ; =0x0007080F
	b _0225D544
_0225D542:
	ldr r7, _0225D5A4 ; =0x0001020F
_0225D544:
	mov r0, #0
	add r1, r6, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	lsr r1, r0, #0x1f
	add r1, r0, r1
	asr r2, r1, #1
	mov r1, #0x28
	sub r3, r1, r2
	mov r1, #1
	tst r0, r1
	beq _0225D560
	sub r3, r3, #1
_0225D560:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	add r2, r6, #0
	add r0, #0x30
	ldrb r0, [r0]
	lsl r1, r0, #2
	ldr r0, _0225D5A8 ; =ov93_02262A68
	add r1, r0, r1
	ldr r0, [sp, #0x14]
	ldrb r0, [r0, r1]
	lsl r1, r0, #4
	ldr r0, [sp, #0x18]
	add r0, r0, r1
	mov r1, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl Heap_Free
_0225D58E:
	add r4, r4, #1
_0225D590:
	ldr r0, [r5]
	add r0, #0x30
	ldrb r0, [r0]
	cmp r4, r0
	blt _0225D504
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_0225D5A0: .word 0x0007080F
_0225D5A4: .word 0x0001020F
_0225D5A8: .word ov93_02262A68
	thumb_func_end ov93_0225D4EC


	thumb_func_start ov93_0225D5AC
ov93_0225D5AC: ; 0x0225D5AC
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	cmp r1, #1
	bne _0225D604
	mov r0, #0xd
	str r0, [sp]
	mov r0, #0xc
	str r0, [sp, #4]
	mov r1, #4
	str r1, [sp, #8]
	mov r0, #0x11
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x2c]
	ldr r2, _0225D670 ; =0x000003FF
	mov r3, #0
	bl FillBgTilemapRect
	mov r0, #0
	str r0, [sp]
	mov r0, #0xc
	str r0, [sp, #4]
	mov r1, #4
	str r1, [sp, #8]
	mov r3, #0x11
	str r3, [sp, #0xc]
	ldr r0, [r4, #0x2c]
	ldr r2, _0225D670 ; =0x000003FF
	bl FillBgTilemapRect
	mov r0, #0xd
	str r0, [sp]
	mov r0, #0xc
	str r0, [sp, #4]
	mov r1, #4
	str r1, [sp, #8]
	mov r0, #0x11
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x2c]
	ldr r2, _0225D670 ; =0x000003FF
	mov r3, #0x14
	bl FillBgTilemapRect
	b _0225D662
_0225D604:
	ldr r0, [r4]
	add r0, #0x30
	ldrb r0, [r0]
	cmp r0, #2
	beq _0225D614
	cmp r0, #3
	beq _0225D64A
	b _0225D662
_0225D614:
	mov r0, #0xd
	str r0, [sp]
	mov r0, #0xc
	str r0, [sp, #4]
	mov r1, #4
	str r1, [sp, #8]
	mov r0, #0x11
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x2c]
	ldr r2, _0225D670 ; =0x000003FF
	mov r3, #0
	bl FillBgTilemapRect
	mov r0, #0xd
	str r0, [sp]
	mov r0, #0xc
	str r0, [sp, #4]
	mov r1, #4
	str r1, [sp, #8]
	mov r0, #0x11
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x2c]
	ldr r2, _0225D670 ; =0x000003FF
	mov r3, #0x14
	bl FillBgTilemapRect
	b _0225D662
_0225D64A:
	mov r0, #0
	str r0, [sp]
	mov r0, #0xc
	str r0, [sp, #4]
	mov r1, #4
	str r1, [sp, #8]
	mov r3, #0x11
	str r3, [sp, #0xc]
	ldr r0, [r4, #0x2c]
	ldr r2, _0225D670 ; =0x000003FF
	bl FillBgTilemapRect
_0225D662:
	ldr r0, [r4, #0x2c]
	mov r1, #4
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x10
	pop {r4, pc}
	nop
_0225D670: .word 0x000003FF
	thumb_func_end ov93_0225D5AC
