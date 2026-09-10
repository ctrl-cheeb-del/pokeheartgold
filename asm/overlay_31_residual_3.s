	.include "asm/macros.inc"
	.include "overlay_31.inc"
	.include "global.inc"

	.text
	.public _0225EE40
	.public _0225EF40
	.public ov31_0225D520
	.public ov31_0225D684
	.public ov31_0225D7A0
	.public ov31_0225D83C
	.public ov31_0225D9D4
	.public ov31_0225DAC4
	.public ov31_0225DB38
	.public ov31_0225DBD4
	.public ov31_0225DCA8
	.public ov31_0225DD14
	.public ov31_0225DE24
	.public ov31_0225DE84
	.public ov31_0225DF98
	.public ov31_0225E060
	.public ov31_0225E184
	.public ov31_0225E20C
	.public ov31_0225E2D4
	.public ov31_0225E54C
	.public ov31_0225E5FC
	.public ov31_0225E700
	.public ov31_0225E7D4
	.public ov31_0225EA08
	.public ov31_0225EA9C
	.public ov31_0225EB30
	.public ov31_0225EBC4
	.public ov31_0225EC58
	.public ov31_0225EE44
	.public ov31_0225EE60
	.public ov31_0225EE88
	.public ov31_0225EED0
	.public ov31_0225EEEC
	.public ov31_0225EF08
	.public ov31_0225EF48
	.public ov31_0225D60C
	.public ov31_0225D654
	.public ov31_0225D710
	.public ov31_0225D758
	.public ov31_0225D75C
	.public ov31_0225DAA4
	.public ov31_0225DBA0
	.public ov31_0225DCF4
	.public ov31_0225DE00
	.public ov31_0225E0E4
	.public ov31_0225E12C
	.public ov31_0225E474
	.public ov31_0225E4BC
	.public ov31_0225E4EC
	.public ov31_0225E51C
	.public ov31_0225E774
	.public ov31_0225E948
	.public ov31_0225E95C
	.public ov31_0225E9CC
	.public ov31_0225EDA0

	thumb_func_start ov31_0225D7A0
ov31_0225D7A0: ; 0x0225D7A0
	push {r3, r4, r5, lr}
	add r5, r1, #0
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0225D7B0
	cmp r0, #1
	beq _0225D7BE
	pop {r3, r4, r5, pc}
_0225D7B0:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0225D836
	mov r0, #1
	str r0, [r5, #0xc]
	pop {r3, r4, r5, pc}
_0225D7BE:
	ldr r1, [r5, #0x14]
	ldr r0, _0225D838 ; =0x00000272
	ldrb r0, [r1, r0]
	cmp r0, #3
	beq _0225D7D2
	cmp r0, #7
	beq _0225D7FA
	cmp r0, #0xb
	beq _0225D814
	b _0225D81A
_0225D7D2:
	add r0, r5, #0
	mov r1, #0
	bl ov31_0225DAA4
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _0225D81A
	add r0, r5, #0
	add r1, r4, #0
	bl ov31_0225D75C
	cmp r0, #0
	beq _0225D81A
	mov r0, #0xa5
	ldr r1, [r5, #0x14]
	lsl r0, r0, #2
	str r4, [r1, r0]
	b _0225D81A
_0225D7FA:
	add r0, r5, #0
	mov r1, #1
	bl ov31_0225DAA4
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0225D81A
	mov r1, #0xa5
	ldr r2, [r5, #0x14]
	lsl r1, r1, #2
	str r0, [r2, r1]
	b _0225D81A
_0225D814:
	add r0, r5, #0
	bl ov31_0225E774
_0225D81A:
	mov r0, #0xa6
	ldr r1, [r5, #0x14]
	lsl r0, r0, #2
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _0225D836
	add r0, r5, #0
	bl ov31_0225D83C
	mov r0, #0xa6
	ldr r1, [r5, #0x14]
	mov r2, #0
	lsl r0, r0, #2
	str r2, [r1, r0]
_0225D836:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0225D838: .word 0x00000272
	thumb_func_end ov31_0225D7A0


	thumb_func_start ov31_0225D83C
ov31_0225D83C: ; 0x0225D83C
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #0xd
	bls _0225D846
	b _0225D9CC
_0225D846:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0225D852: ; jump table
	.short _0225D9CC - _0225D852 - 2 ; case 0
	.short _0225D86E - _0225D852 - 2 ; case 1
	.short _0225D882 - _0225D852 - 2 ; case 2
	.short _0225D8D2 - _0225D852 - 2 ; case 3
	.short _0225D910 - _0225D852 - 2 ; case 4
	.short _0225D950 - _0225D852 - 2 ; case 5
	.short _0225D974 - _0225D852 - 2 ; case 6
	.short _0225D980 - _0225D852 - 2 ; case 7
	.short _0225D998 - _0225D852 - 2 ; case 8
	.short _0225D99E - _0225D852 - 2 ; case 9
	.short _0225D9A4 - _0225D852 - 2 ; case 10
	.short _0225D9AA - _0225D852 - 2 ; case 11
	.short _0225D9C2 - _0225D852 - 2 ; case 12
	.short _0225D9C8 - _0225D852 - 2 ; case 13
_0225D86E:
	bl ov31_0225DD14
	add r0, r4, #0
	bl ov31_0225DF98
	add r0, r4, #0
	mov r1, #0
	bl ov31_0225D684
	pop {r4, pc}
_0225D882:
	mov r1, #1
	bl ov31_0225D9D4
	add r0, r4, #0
	bl ov31_0225DCF4
	add r0, r4, #0
	add r0, #0x54
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	bl ov31_0225EC58
	add r0, r4, #0
	bl ov31_0225E184
	mov r1, #0xa1
	ldr r2, [r4, #0x14]
	lsl r1, r1, #2
	ldrh r1, [r2, r1]
	add r0, r4, #0
	bl ov31_0225E20C
	ldr r2, [r4, #0x14]
	ldr r1, _0225D9D0 ; =0x00000286
	add r0, r4, #0
	ldrsh r1, [r2, r1]
	bl ov31_0225E2D4
	add r0, r4, #0
	bl ov31_0225E474
	add r0, r4, #0
	mov r1, #1
	bl ov31_0225D684
	add r0, r4, #0
	bl ov31_0225E54C
	pop {r4, pc}
_0225D8D2:
	mov r1, #2
	bl ov31_0225D9D4
	add r0, r4, #0
	bl ov31_0225DCF4
	add r0, r4, #0
	bl ov31_0225EC58
	add r0, r4, #0
	bl ov31_0225E184
	mov r1, #0xa1
	ldr r2, [r4, #0x14]
	lsl r1, r1, #2
	ldrh r1, [r2, r1]
	add r0, r4, #0
	bl ov31_0225E20C
	add r0, r4, #0
	bl ov31_0225E5FC
	add r0, r4, #0
	add r0, #0x54
	bl ClearWindowTilemapAndScheduleTransfer
	add r4, #0x64
	add r0, r4, #0
	bl ClearWindowTilemapAndScheduleTransfer
	pop {r4, pc}
_0225D910:
	mov r1, #0
	bl ov31_0225D9D4
	add r0, r4, #0
	bl ov31_0225EDA0
	add r0, r4, #0
	bl ov31_0225DF98
	add r0, r4, #0
	mov r1, #0
	bl ov31_0225D684
	add r0, r4, #0
	bl ov31_0225DCA8
	add r0, r4, #0
	add r0, #0x44
	mov r1, #1
	bl ClearFrameAndWindow2
	add r0, r4, #0
	bl ov31_0225DD14
	add r0, r4, #0
	bl ov31_0225DE84
	add r4, #0x64
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	pop {r4, pc}
_0225D950:
	mov r1, #0
	bl ov31_0225D9D4
	add r0, r4, #0
	bl ov31_0225DF98
	add r0, r4, #0
	add r0, #0x44
	mov r1, #0
	bl ClearFrameAndWindow2
	add r0, r4, #0
	bl ov31_0225DD14
	add r0, r4, #0
	bl ov31_0225DE84
	pop {r4, pc}
_0225D974:
	ldr r2, [r4, #0x14]
	ldr r1, _0225D9D0 ; =0x00000286
	ldrsh r1, [r2, r1]
	bl ov31_0225E2D4
	pop {r4, pc}
_0225D980:
	add r0, #0x64
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x45
	lsl r0, r0, #2
	add r0, r4, r0
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	bl ov31_0225E5FC
	pop {r4, pc}
_0225D998:
	bl ov31_0225E700
	pop {r4, pc}
_0225D99E:
	bl ov31_0225E7D4
	pop {r4, pc}
_0225D9A4:
	bl ov31_0225EA08
	pop {r4, pc}
_0225D9AA:
	add r0, #0x64
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x45
	lsl r0, r0, #2
	add r0, r4, r0
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	bl ov31_0225EA9C
	pop {r4, pc}
_0225D9C2:
	bl ov31_0225EB30
	pop {r4, pc}
_0225D9C8:
	bl ov31_0225EBC4
_0225D9CC:
	pop {r4, pc}
	nop
_0225D9D0: .word 0x00000286
	thumb_func_end ov31_0225D83C


	thumb_func_start ov31_0225D9D4
ov31_0225D9D4: ; 0x0225D9D4
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r0, #0
	cmp r1, #0
	beq _0225D9EA
	cmp r1, #1
	beq _0225DA26
	cmp r1, #2
	beq _0225DA64
	add sp, #8
	pop {r3, r4, r5, pc}
_0225D9EA:
	mov r0, #8
	str r0, [sp]
	mov r0, #0x3c
	mov r1, #0x11
	mov r2, #0
	add r3, sp, #4
	bl GfGfxLoader_GetScrnData
	ldr r3, [sp, #4]
	add r5, r0, #0
	add r2, r3, #0
	ldr r0, [r4, #4]
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r4, #4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	bl Heap_Free
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add sp, #8
	pop {r3, r4, r5, pc}
_0225DA26:
	ldr r0, [r4, #4]
	mov r1, #5
	mov r2, #0
	bl BgFillTilemapBufferAndSchedule
	mov r0, #8
	str r0, [sp]
	mov r0, #0x3c
	mov r1, #0x13
	mov r2, #0
	add r3, sp, #4
	bl GfGfxLoader_GetScrnData
	ldr r3, [sp, #4]
	add r5, r0, #0
	add r2, r3, #0
	ldr r0, [r4, #4]
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r4, #4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	bl Heap_Free
	add sp, #8
	pop {r3, r4, r5, pc}
_0225DA64:
	ldr r0, [r4, #4]
	mov r1, #5
	mov r2, #0
	bl BgFillTilemapBufferAndSchedule
	mov r0, #8
	str r0, [sp]
	mov r0, #0x3c
	mov r1, #0x14
	mov r2, #0
	add r3, sp, #4
	bl GfGfxLoader_GetScrnData
	ldr r3, [sp, #4]
	add r5, r0, #0
	add r2, r3, #0
	ldr r0, [r4, #4]
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r4, #4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	bl Heap_Free
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov31_0225D9D4
