	.include "asm/macros.inc"
	.include "overlay_80_02239D74.inc"
	.include "global.inc"
	.public ov80_02239DD0
	.public ov80_02239ED8
	.public ov80_0223DB2C


    .text
	.public ov80_02239D74
	.public ov80_02239DB8
	.public ov80_02239EC4
	.public ov80_02239F48
	.public ov80_02239F94
	.public ov80_02239FA8

	thumb_func_start ov80_02239ED8
ov80_02239ED8: ; 0x02239ED8
	push {r3, r4, lr}
	sub sp, #4
	ldr r3, _02239F3C ; =0x00022008
	add r4, r1, #0
	ldrb r0, [r4, r3]
	cmp r0, #0xc
	bhs _02239EEE
	add r0, r0, #1
	add sp, #4
	strb r0, [r4, r3]
	pop {r3, r4, pc}
_02239EEE:
	mov r0, #0
	strb r0, [r4, r3]
	str r0, [sp]
	add r3, r3, #1
	ldrb r3, [r4, r3]
	ldr r2, _02239F40 ; =0x00002008
	ldr r0, [r4, #4]
	add r2, r4, r2
	lsl r3, r3, #0x10
	add r2, r2, r3
	mov r3, #1
	mov r1, #3
	lsl r3, r3, #0x10
	bl BG_LoadCharTilesData
	ldr r2, _02239F44 ; =0x00022009
	add r3, r4, #0
	ldrb r2, [r4, r2]
	add r3, #8
	ldr r0, [r4, #4]
	lsl r2, r2, #0xc
	add r2, r3, r2
	mov r3, #1
	mov r1, #3
	lsl r3, r3, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r4, #4]
	mov r1, #3
	bl ScheduleBgTilemapBufferTransfer
	ldr r1, _02239F44 ; =0x00022009
	mov r0, #1
	ldrb r2, [r4, r1]
	eor r0, r2
	strb r0, [r4, r1]
	add sp, #4
	pop {r3, r4, pc}
	nop
_02239F3C: .word 0x00022008
_02239F40: .word 0x00002008
_02239F44: .word 0x00022009
	thumb_func_end ov80_02239ED8
