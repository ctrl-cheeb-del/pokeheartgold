	.include "asm/macros.inc"
	.public ReadMsgDataIntoString
	.public AddTextPrinterParameterizedWithColor
	.public ScheduleWindowCopyToVram
	.public FillWindowPixelBuffer
	.public BufferIntegerAsString
	.public StringExpandPlaceholders
	.public ov59_0223C3AC
	.public ov59_0223C380
	.public ov59_0223BE18
	.public ov59_0223C94C
	.public Sprite_SetDrawFlag
	.public Sprite_SetAnimCtrlSeq
	.public ov59_0223BE44
	.text

	thumb_func_start ov59_0223BBD4
ov59_0223BBD4: ; 0x0223BBD4
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r0, #0
	cmp r1, #0xb
	bhi _0223BC42
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223BBEA: ; jump table
	.short _0223BC02 - _0223BBEA - 2 ; case 0
	.short _0223BC24 - _0223BBEA - 2 ; case 1
	.short _0223BC2E - _0223BBEA - 2 ; case 2
	.short _0223BC2E - _0223BBEA - 2 ; case 3
	.short _0223BC2E - _0223BBEA - 2 ; case 4
	.short _0223BC2E - _0223BBEA - 2 ; case 5
	.short _0223BC2E - _0223BBEA - 2 ; case 6
	.short _0223BC38 - _0223BBEA - 2 ; case 7
	.short _0223BC38 - _0223BBEA - 2 ; case 8
	.short _0223BC38 - _0223BBEA - 2 ; case 9
	.short _0223BC38 - _0223BBEA - 2 ; case 10
	.short _0223BC38 - _0223BBEA - 2 ; case 11
_0223BC02:
	ldrh r0, [r4, #0x20]
	lsl r0, r0, #0x1c
	lsr r1, r0, #0x1c
	cmp r1, #6
	bne _0223BC10
	mov r1, #0xc
	b _0223BC20
_0223BC10:
	cmp r1, #5
	bne _0223BC1E
	add r0, r4, #0
	add r0, #0x26
	ldrb r1, [r0]
	add r1, #0xd
	b _0223BC20
_0223BC1E:
	add r1, #0xd
_0223BC20:
	mov r5, #0
	b _0223BC48
_0223BC24:
	add r0, r4, #0
	add r0, #0x4b
	mov r1, #0x12
	ldrb r5, [r0]
	b _0223BC48
_0223BC2E:
	add r0, r4, #0
	add r0, #0x4b
	add r1, #0x11
	ldrb r5, [r0]
	b _0223BC48
_0223BC38:
	add r0, r4, #0
	add r0, #0x4b
	add r1, #0x11
	ldrb r5, [r0]
	b _0223BC48
_0223BC42:
	add r0, r4, #0
	add r0, #0x4b
	ldrb r5, [r0]
_0223BC48:
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x68]
	bl ReadMsgDataIntoString
	mov r3, #0
	str r3, [sp]
	ldr r0, _0223BC84 ; =0x0001020F
	str r5, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	mov r0, #0x6d
	lsl r0, r0, #2
	ldr r2, [r4, #0x68]
	add r0, r4, r0
	mov r1, #1
	bl AddTextPrinterParameterizedWithColor
	add r1, r4, #0
	add r1, #0x4d
	strb r0, [r1]
	cmp r5, #0
	bne _0223BC7E
	mov r0, #0x6d
	lsl r0, r0, #2
	add r0, r4, r0
	bl ScheduleWindowCopyToVram
_0223BC7E:
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_0223BC84: .word 0x0001020F
	thumb_func_end ov59_0223BBD4


	thumb_func_start ov59_0223BC88
ov59_0223BC88: ; 0x0223BC88
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r2, r5, #0
	mov r0, #0x34
	mul r0, r1
	add r2, #0x7c
	add r4, r2, r0
	mov r0, #0x7d
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _0223BD40 ; =0x000F0200
	add r2, #0xf5
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r5, r2
	ldr r2, [r4, #0xc]
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	ldrb r0, [r4, #7]
	cmp r0, #2
	beq _0223BCE4
	lsl r2, r0, #2
	ldr r0, _0223BD44 ; =ov59_0223C94C
	mov r1, #0
	ldr r0, [r0, r2]
	str r1, [sp]
	mov r3, #0xff
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r3, #0xf5
	add r0, r5, r3
	str r1, [sp, #0xc]
	add r2, r5, r2
	ldr r2, [r2, #0x70]
	mov r3, #0x40
	bl AddTextPrinterParameterizedWithColor
_0223BCE4:
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldrb r2, [r4, #6]
	ldr r0, [r5, #0x60]
	mov r3, #3
	bl BufferIntegerAsString
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x68]
	ldr r2, [r5, #0x6c]
	bl StringExpandPlaceholders
	mov r3, #0x10
	str r3, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _0223BD48 ; =0x00010200
	mov r1, #0
	str r0, [sp, #8]
	add r2, #0xf5
	str r1, [sp, #0xc]
	add r0, r5, r2
	ldr r2, [r5, #0x68]
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0x7d
	lsl r0, r0, #2
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	ldr r0, [r5, #0x78]
	bl ov59_0223C3AC
	ldr r0, [r5, #0x78]
	add r1, r4, #0
	bl ov59_0223C380
	add r0, r5, #0
	add r1, r4, #0
	bl ov59_0223BE18
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_0223BD40: .word 0x000F0200
_0223BD44: .word ov59_0223C94C
_0223BD48: .word 0x00010200
	thumb_func_end ov59_0223BC88


	thumb_func_start ov59_0223BD4C
ov59_0223BD4C: ; 0x0223BD4C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r1, [sp]
	add r7, r2, #0
	add r1, #0x10
	add r6, r0, #0
	add r0, r1, r7
	str r0, [sp, #4]
	ldrsb r0, [r1, r7]
	cmp r0, #0
	bne _0223BD76
	add r0, r7, #3
	lsl r0, r0, #2
	add r1, r6, r0
	mov r0, #0x26
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	b _0223BDA2
_0223BD76:
	mov r0, #0x26
	lsl r0, r0, #4
	add r4, r6, r0
	add r0, r7, #3
	lsl r5, r0, #2
	ldr r0, [r4, r5]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, [sp, #4]
	mov r1, #0
	ldrsb r0, [r0, r1]
	cmp r0, #0
	ldr r0, [r4, r5]
	ble _0223BD9C
	mov r1, #8
	bl Sprite_SetAnimCtrlSeq
	b _0223BDA2
_0223BD9C:
	mov r1, #9
	bl Sprite_SetAnimCtrlSeq
_0223BDA2:
	lsl r0, r7, #2
	str r0, [sp, #0x10]
	add r5, r7, r0
	ldr r0, [sp]
	mov r4, #0
	str r0, [sp, #0xc]
	add r0, #0x1e
	str r0, [sp, #0xc]
	ldr r0, [sp]
	ldrh r1, [r0, #0x16]
	lsl r0, r7, #1
	add r0, r7, r0
	asr r1, r0
	mov r0, #7
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	ldr r0, [sp]
	add r7, r0, r7
_0223BDCA:
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldrh r0, [r1, r0]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1d
	cmp r4, r0
	ble _0223BDE6
	add r0, r6, #0
	add r1, r5, #0
	mov r2, #0xff
	mov r3, #0
	bl ov59_0223BE44
	b _0223BE0C
_0223BDE6:
	ldr r0, [sp, #8]
	cmp r4, r0
	ble _0223BDFA
	add r0, r6, #0
	add r1, r5, #0
	mov r2, #7
	mov r3, #1
	bl ov59_0223BE44
	b _0223BE0C
_0223BDFA:
	ldrb r2, [r7, #0x18]
	add r0, r6, #0
	add r1, r5, #0
	add r2, r2, #4
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	mov r3, #1
	bl ov59_0223BE44
_0223BE0C:
	add r4, r4, #1
	add r5, r5, #1
	cmp r4, #5
	blt _0223BDCA
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov59_0223BD4C
