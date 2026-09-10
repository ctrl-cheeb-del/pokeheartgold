	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02058D4C
sub_02058D4C: ; 0x02058D4C
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r0, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	add r0, r5, #0
	bl TaskManager_GetFieldSystem
	ldr r1, [r4, #0x34]
	cmp r1, #0x2c
	bls _02058D66
	b _02059472
_02058D66:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02058D72: ; jump table
	.short _02058DCC - _02058D72 - 2 ; case 0
	.short _02058DEE - _02058D72 - 2 ; case 1
	.short _02058E08 - _02058D72 - 2 ; case 2
	.short _02058E22 - _02058D72 - 2 ; case 3
	.short _02058E5E - _02058D72 - 2 ; case 4
	.short _02058EAE - _02058D72 - 2 ; case 5
	.short _02059472 - _02058D72 - 2 ; case 6
	.short _02058E9C - _02058D72 - 2 ; case 7
	.short _02058EC4 - _02058D72 - 2 ; case 8
	.short _02058EEA - _02058D72 - 2 ; case 9
	.short _02058EF6 - _02058D72 - 2 ; case 10
	.short _02058F22 - _02058D72 - 2 ; case 11
	.short _02058F40 - _02058D72 - 2 ; case 12
	.short _02058F54 - _02058D72 - 2 ; case 13
	.short _02058F60 - _02058D72 - 2 ; case 14
	.short _02058F82 - _02058D72 - 2 ; case 15
	.short _02058F98 - _02058D72 - 2 ; case 16
	.short _02058FC6 - _02058D72 - 2 ; case 17
	.short _02058FEC - _02058D72 - 2 ; case 18
	.short _02058FFE - _02058D72 - 2 ; case 19
	.short _02059042 - _02058D72 - 2 ; case 20
	.short _02059022 - _02058D72 - 2 ; case 21
	.short _0205905E - _02058D72 - 2 ; case 22
	.short _0205906E - _02058D72 - 2 ; case 23
	.short _0205908C - _02058D72 - 2 ; case 24
	.short _020590AA - _02058D72 - 2 ; case 25
	.short _020590BE - _02058D72 - 2 ; case 26
	.short _0205912A - _02058D72 - 2 ; case 27
	.short _02059162 - _02058D72 - 2 ; case 28
	.short _02059178 - _02058D72 - 2 ; case 29
	.short _020591C2 - _02058D72 - 2 ; case 30
	.short _020591FA - _02058D72 - 2 ; case 31
	.short _02059220 - _02058D72 - 2 ; case 32
	.short _02059340 - _02058D72 - 2 ; case 33
	.short _02059370 - _02058D72 - 2 ; case 34
	.short _02059388 - _02058D72 - 2 ; case 35
	.short _02059274 - _02058D72 - 2 ; case 36
	.short _020592B2 - _02058D72 - 2 ; case 37
	.short _020592CE - _02058D72 - 2 ; case 38
	.short _02059398 - _02058D72 - 2 ; case 39
	.short _02059472 - _02058D72 - 2 ; case 40
	.short _020593BC - _02058D72 - 2 ; case 41
	.short _020593FE - _02058D72 - 2 ; case 42
	.short _02059420 - _02058D72 - 2 ; case 43
	.short _02059452 - _02058D72 - 2 ; case 44
_02058DCC:
	add r0, r4, #0
	add r0, #0x43
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x43
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x43
	ldrb r0, [r0]
	cmp r0, #0
	bne _02058E94
	mov r0, #1
	str r0, [r4, #0x34]
	bl sub_02057E08
	b _02059472
_02058DEE:
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0xc]
	mov r1, #1
	bl ReadMsgDataIntoString
	ldr r1, [r4, #0xc]
	add r0, r4, #0
	bl sub_02059478
	str r0, [r4, #0x30]
	mov r0, #2
	str r0, [r4, #0x34]
	b _02059472
_02058E08:
	ldr r0, [r4, #0x30]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl DialogBox_IsPrintFinished
	cmp r0, #0
	beq _02058E94
	mov r0, #0x5d
	bl sub_02037AC0
	mov r0, #3
	str r0, [r4, #0x34]
	b _02059472
_02058E22:
	mov r0, #0x5d
	bl sub_02037B38
	cmp r0, #0
	beq _02058E42
	mov r0, #7
	str r0, [r4, #0x34]
	ldr r0, [r4, #0x24]
	ldr r0, [r0, #0x3c]
	bl sub_0205F55C
	ldr r1, [r4, #0x50]
	ldr r2, [r4, #8]
	mov r0, #1
	blx r2
	b _02059472
_02058E42:
	ldr r0, _02059148 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	beq _02058E94
	mov r0, #4
	str r0, [r4, #0x34]
	mov r0, #0x5c
	bl sub_02037AC0
	mov r0, #5
	add r4, #0x43
	strb r0, [r4]
	b _02059472
_02058E5E:
	mov r0, #0x5d
	bl sub_02037B38
	cmp r0, #0
	beq _02058E7C
	mov r0, #7
	str r0, [r4, #0x34]
	ldr r0, [r4, #0x24]
	ldr r0, [r0, #0x3c]
	bl sub_0205F55C
	ldr r1, [r4, #0x50]
	ldr r2, [r4, #8]
	mov r0, #1
	blx r2
_02058E7C:
	add r0, r4, #0
	add r0, #0x43
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x43
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x43
	ldrb r0, [r0]
	cmp r0, #0
	beq _02058E96
_02058E94:
	b _02059472
_02058E96:
	mov r0, #8
	str r0, [r4, #0x34]
	b _02059472
_02058E9C:
	add r0, r4, #0
	bl sub_02059650
	add r0, r4, #0
	bl Heap_Free
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, pc}
_02058EAE:
	add r0, r4, #0
	bl sub_02059650
	add r0, r4, #0
	bl Heap_Free
	bl sub_02057F70
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, pc}
_02058EC4:
	mov r0, #0x5d
	bl sub_02037B38
	cmp r0, #0
	beq _02058EDC
	mov r0, #5
	str r0, [r4, #0x34]
	ldr r1, [r4, #0x50]
	ldr r2, [r4, #8]
	mov r0, #1
	blx r2
	b _02059472
_02058EDC:
	ldr r1, [r4, #0x50]
	ldr r2, [r4, #8]
	mov r0, #0
	blx r2
	mov r0, #5
	str r0, [r4, #0x34]
	b _02059472
_02058EEA:
	mov r0, #0xa
	str r0, [r4, #0x34]
	mov r0, #5
	add r4, #0x44
	strb r0, [r4]
	b _02059472
_02058EF6:
	add r1, r4, #0
	add r1, #0x44
	ldrb r1, [r1]
	cmp r1, #0
	beq _02058F0E
	add r0, r4, #0
	add r0, #0x44
	ldrb r0, [r0]
	add r4, #0x44
	sub r0, r0, #1
	strb r0, [r4]
	b _02059472
_02058F0E:
	ldr r0, [r0, #0x40]
	bl PlayerAvatar_GetMapObject
	bl MapObject_IsMovementPaused
	cmp r0, #0
	beq _02058FB2
	mov r0, #0xb
	str r0, [r4, #0x34]
	b _02059472
_02058F22:
	bl sub_02057E08
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0xc]
	mov r1, #0xd
	bl ReadMsgDataIntoString
	ldr r1, [r4, #0xc]
	add r0, r4, #0
	bl sub_02059478
	str r0, [r4, #0x30]
	mov r0, #0xc
	str r0, [r4, #0x34]
	b _02059472
_02058F40:
	ldr r0, [r4, #0x30]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl DialogBox_IsPrintFinished
	cmp r0, #0
	beq _02058FB2
	mov r0, #0xd
	str r0, [r4, #0x34]
	b _02059472
_02058F54:
	mov r0, #0
	bl FieldMap_FadeScreen
	mov r0, #0xe
	str r0, [r4, #0x34]
	b _02059472
_02058F60:
	add r0, r4, #0
	add r0, #0x43
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x43
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x43
	ldrb r0, [r0]
	cmp r0, #0
	bne _02058FB2
	bl sub_02057E08
	mov r0, #0xf
	str r0, [r4, #0x34]
	b _02059472
_02058F82:
	add r0, r4, #0
	mov r1, #0
	bl sub_020594C8
	add r0, r4, #0
	mov r1, #0xb
	bl sub_02058B84
	mov r0, #0x10
	str r0, [r4, #0x34]
	b _02059472
_02058F98:
	ldr r1, [r4, #0x24]
	add r0, r4, #0
	bl sub_02058C80
	cmp r0, #0
	beq _02058FB2
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _02058FB4
	cmp r0, #1
	beq _02058FBA
	cmp r0, #2
	beq _02058FC0
_02058FB2:
	b _02059472
_02058FB4:
	mov r0, #0x14
	str r0, [r4, #0x34]
	b _02059472
_02058FBA:
	mov r0, #0x13
	str r0, [r4, #0x34]
	b _02059472
_02058FC0:
	mov r0, #0x11
	str r0, [r4, #0x34]
	b _02059472
_02058FC6:
	ldr r0, [r4, #0x24]
	ldr r0, [r0, #0xc]
	bl SaveArray_Party_Get
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #0xb
	str r0, [sp, #4]
	add r3, r4, #0
	add r3, #0x3c
	ldrb r3, [r3]
	ldr r1, [r4, #0x24]
	add r0, r4, #0
	bl sub_02058AEC
	mov r0, #0x12
	str r0, [r4, #0x34]
	b _02059472
_02058FEC:
	ldr r1, [r4, #0x24]
	add r0, r4, #0
	bl sub_02058CD8
	cmp r0, #0
	beq _020590C8
	mov r0, #0xf
	str r0, [r4, #0x34]
	b _02059472
_02058FFE:
	ldr r0, [r4, #0x24]
	bl FieldSystem_LoadFieldOverlay
	add r0, r4, #0
	add r0, #0x88
	ldrb r0, [r0]
	cmp r0, #3
	beq _0205901C
	add r0, r4, #0
	mov r1, #5
	add r0, #0x43
	strb r1, [r0]
	mov r0, #0x15
	str r0, [r4, #0x34]
	b _02059472
_0205901C:
	mov r0, #0x1a
	str r0, [r4, #0x34]
	b _02059472
_02059022:
	add r0, r4, #0
	add r0, #0x3d
	bl sub_0203996C
	add r0, r4, #0
	bl sub_02058D04
	cmp r0, #0
	beq _020590C8
	add r0, r4, #0
	mov r1, #5
	add r0, #0x43
	strb r1, [r0]
	mov r0, #0
	str r0, [r4, #0x34]
	b _02059472
_02059042:
	ldr r0, [r4, #0x24]
	bl FieldSystem_LoadFieldOverlay
	add r0, r4, #0
	add r0, #0x88
	ldrb r0, [r0]
	cmp r0, #3
	beq _02059058
	mov r0, #0x16
	str r0, [r4, #0x34]
	b _02059472
_02059058:
	mov r0, #0x1a
	str r0, [r4, #0x34]
	b _02059472
_0205905E:
	add r0, r4, #0
	bl sub_02058D04
	cmp r0, #0
	beq _020590C8
	mov r0, #8
	str r0, [r4, #0x34]
	b _02059472
_0205906E:
	add r0, r4, #0
	add r0, #0x44
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x44
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x44
	ldrb r0, [r0]
	cmp r0, #0
	bne _020590C8
	mov r0, #0x18
	str r0, [r4, #0x34]
	b _02059472
_0205908C:
	bl sub_02057E08
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0xc]
	mov r1, #0x13
	bl ReadMsgDataIntoString
	ldr r1, [r4, #0xc]
	add r0, r4, #0
	bl sub_02059478
	str r0, [r4, #0x30]
	mov r0, #0x19
	str r0, [r4, #0x34]
	b _02059472
_020590AA:
	ldr r0, [r4, #0x30]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl DialogBox_IsPrintFinished
	cmp r0, #0
	beq _020590C8
	mov r0, #0xd
	str r0, [r4, #0x34]
	b _02059472
_020590BE:
	add r0, r4, #0
	bl sub_02058D04
	cmp r0, #0
	bne _020590CA
_020590C8:
	b _02059472
_020590CA:
	bl sub_02058D24
	cmp r0, #0
	beq _020590D8
	mov r0, #5
	str r0, [r4, #0x34]
	b _02059472
_020590D8:
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _020590E2
	mov r1, #1
	b _020590E4
_020590E2:
	mov r1, #0
_020590E4:
	add r0, r4, #0
	add r0, #0x82
	strb r1, [r0]
	add r1, r4, #0
	add r1, #0x82
	ldrb r1, [r1]
	add r0, r4, #0
	bl sub_020596A8
	mov r0, #0
	bl sub_02037AC0
	ldr r0, [r4, #0x28]
	ldr r2, [r4, #0x74]
	mov r1, #0
	bl BufferPlayersName
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0xc]
	mov r1, #0xe
	bl ReadMsgDataIntoString
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x10]
	ldr r2, [r4, #0xc]
	bl StringExpandPlaceholders
	ldr r1, [r4, #0x10]
	add r0, r4, #0
	bl sub_02059478
	str r0, [r4, #0x30]
	mov r0, #0x1b
	str r0, [r4, #0x34]
	b _02059472
_0205912A:
	ldr r0, [r4, #0x30]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl DialogBox_IsPrintFinished
	cmp r0, #0
	beq _0205922E
	bl sub_02058D24
	cmp r0, #0
	beq _0205914C
	mov r0, #5
	str r0, [r4, #0x34]
	b _02059472
	nop
_02059148: .word gSystem
_0205914C:
	mov r0, #0
	bl sub_02037B38
	cmp r0, #0
	beq _0205922E
	add r0, r4, #0
	bl sub_020596F0
	mov r0, #0x1c
	str r0, [r4, #0x34]
	b _02059472
_02059162:
	add r0, r4, #0
	bl sub_02059738
	cmp r0, #0
	beq _0205922E
	mov r0, #1
	bl sub_02037AC0
	mov r0, #0x1d
	str r0, [r4, #0x34]
	b _02059472
_02059178:
	mov r0, #1
	bl sub_02037B38
	cmp r0, #0
	beq _0205922E
	add r0, r4, #0
	bl sub_02059748
	add r1, r4, #0
	add r1, #0x83
	strb r0, [r1]
	add r0, r4, #0
	add r0, #0x82
	ldrb r0, [r0]
	cmp r0, #0
	beq _020591BC
	add r0, r4, #0
	add r0, #0x83
	ldrb r0, [r0]
	cmp r0, #0
	beq _020591BC
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0xc]
	mov r1, #0x14
	bl ReadMsgDataIntoString
	ldr r1, [r4, #0xc]
	add r0, r4, #0
	bl sub_02059478
	str r0, [r4, #0x30]
	mov r0, #0x1e
	str r0, [r4, #0x34]
	b _02059472
_020591BC:
	mov r0, #0x2a
	str r0, [r4, #0x34]
	b _02059472
_020591C2:
	ldr r0, [r4, #0x30]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl DialogBox_IsPrintFinished
	cmp r0, #0
	beq _0205922E
	add r0, r4, #0
	mov r1, #0
	add r0, #0x89
	strb r1, [r0]
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0xc]
	mov r1, #0x11
	bl ReadMsgDataIntoString
	ldr r1, [r4, #0xc]
	add r0, r4, #0
	bl sub_02059478
	str r0, [r4, #0x30]
	add r0, r4, #0
	mov r1, #0
	add r0, #0x84
	strb r1, [r0]
	mov r0, #0x1f
	str r0, [r4, #0x34]
	b _02059472
_020591FA:
	ldr r0, [r4, #0x30]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl DialogBox_IsPrintFinished
	cmp r0, #0
	beq _0205922E
	add r0, r4, #0
	bl sub_020597A8
	add r1, r4, #0
	add r1, #0x84
	ldrb r1, [r1]
	add r0, r4, #0
	bl sub_02059820
	mov r0, #0x20
	str r0, [r4, #0x34]
	b _02059472
_02059220:
	add r0, r4, #0
	bl sub_02059A08
	cmp r0, #1
	beq _02059230
	cmp r0, #2
	beq _02059246
_0205922E:
	b _02059472
_02059230:
	add r0, r4, #0
	bl sub_02059AD8
	mov r0, #0x81
	ldrsb r1, [r4, r0]
	add r0, r4, #0
	add r0, #0x84
	strb r1, [r0]
	mov r0, #0x24
	str r0, [r4, #0x34]
	b _02059472
_02059246:
	add r0, r4, #0
	bl sub_02059AD8
	add r0, r4, #0
	mov r1, #0xff
	add r0, #0x84
	strb r1, [r0]
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0xc]
	mov r1, #0xf
	bl ReadMsgDataIntoString
	ldr r1, [r4, #0xc]
	add r0, r4, #0
	bl sub_02059478
	str r0, [r4, #0x30]
	mov r0, #2
	bl sub_02037AC0
	mov r0, #0x27
	str r0, [r4, #0x34]
	b _02059472
_02059274:
	add r1, r4, #0
	add r1, #0x84
	ldrb r1, [r1]
	ldr r0, [r4, #0x50]
	bl Party_GetMonByIndex
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [r4, #0x28]
	mov r1, #1
	bl BufferBoxMonSpeciesName
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0xc]
	mov r1, #0x12
	bl ReadMsgDataIntoString
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x10]
	ldr r2, [r4, #0xc]
	bl StringExpandPlaceholders
	ldr r1, [r4, #0x10]
	add r0, r4, #0
	bl sub_02059478
	str r0, [r4, #0x30]
	mov r0, #0x25
	str r0, [r4, #0x34]
	b _02059472
_020592B2:
	ldr r0, [r4, #0x30]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl DialogBox_IsPrintFinished
	cmp r0, #0
	beq _02059348
	add r0, r4, #0
	mov r1, #0
	bl sub_0205993C
	mov r0, #0x26
	str r0, [r4, #0x34]
	b _02059472
_020592CE:
	add r0, r4, #0
	bl sub_02059A08
	cmp r0, #1
	beq _020592FC
	cmp r0, #2
	bne _02059348
	add r0, r4, #0
	bl sub_02059AD8
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0xc]
	mov r1, #0x11
	bl ReadMsgDataIntoString
	ldr r1, [r4, #0xc]
	add r0, r4, #0
	bl sub_02059478
	str r0, [r4, #0x30]
	mov r0, #0x1f
	str r0, [r4, #0x34]
	b _02059472
_020592FC:
	mov r0, #0x81
	ldrsb r0, [r4, r0]
	cmp r0, #1
	bne _02059334
	add r0, r4, #0
	bl sub_02059AD8
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0xc]
	mov r1, #0xe
	bl ReadMsgDataIntoString
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x10]
	ldr r2, [r4, #0xc]
	bl StringExpandPlaceholders
	ldr r1, [r4, #0x10]
	add r0, r4, #0
	bl sub_02059478
	str r0, [r4, #0x30]
	mov r0, #2
	bl sub_02037AC0
	mov r0, #0x27
	str r0, [r4, #0x34]
	b _02059472
_02059334:
	mov r0, #0
	bl FieldMap_FadeScreen
	mov r0, #0x21
	str r0, [r4, #0x34]
	b _02059472
_02059340:
	bl IsPaletteFadeFinished
	cmp r0, #0
	bne _0205934A
_02059348:
	b _02059472
_0205934A:
	add r0, r4, #0
	mov r1, #0
	bl sub_020594C8
	mov r0, #1
	str r0, [sp]
	mov r0, #0xb
	str r0, [sp, #4]
	add r3, r4, #0
	add r3, #0x84
	ldrb r3, [r3]
	ldr r1, [r4, #0x24]
	ldr r2, [r4, #0x50]
	add r0, r4, #0
	bl sub_02058AEC
	mov r0, #0x22
	str r0, [r4, #0x34]
	b _02059472
_02059370:
	ldr r1, [r4, #0x24]
	add r0, r4, #0
	bl sub_02058CD8
	cmp r0, #0
	beq _02059472
	ldr r0, [r4, #0x24]
	bl FieldSystem_LoadFieldOverlay
	mov r0, #0x23
	str r0, [r4, #0x34]
	b _02059472
_02059388:
	add r0, r4, #0
	bl sub_02058D04
	cmp r0, #0
	beq _02059472
	mov r0, #0x24
	str r0, [r4, #0x34]
	b _02059472
_02059398:
	ldr r0, [r4, #0x30]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl DialogBox_IsPrintFinished
	cmp r0, #0
	beq _02059472
	mov r0, #2
	bl sub_02037B38
	cmp r0, #0
	beq _02059472
	add r0, r4, #0
	bl sub_0205975C
	mov r0, #0x29
	str r0, [r4, #0x34]
	b _02059472
_020593BC:
	add r0, r4, #0
	bl sub_02059798
	cmp r0, #0
	beq _02059472
	add r0, r4, #0
	add r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _020593DC
	mov r0, #4
	bl sub_02037AC0
	mov r0, #0x2c
	str r0, [r4, #0x34]
	b _02059472
_020593DC:
	add r0, r4, #0
	add r0, #0x85
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _020593EC
	mov r0, #0x2a
	str r0, [r4, #0x34]
	b _02059472
_020593EC:
	add r0, r4, #0
	bl sub_020597D4
	mov r0, #0x5d
	bl sub_02037AC0
	mov r0, #2
	str r0, [r4, #0x34]
	b _02059472
_020593FE:
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0xc]
	mov r1, #0xf
	bl ReadMsgDataIntoString
	ldr r1, [r4, #0xc]
	add r0, r4, #0
	bl sub_02059478
	str r0, [r4, #0x30]
	add r0, r4, #0
	mov r1, #0
	add r0, #0x43
	strb r1, [r0]
	mov r0, #0x2b
	str r0, [r4, #0x34]
	b _02059472
_02059420:
	ldr r0, [r4, #0x30]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl DialogBox_IsPrintFinished
	cmp r0, #0
	beq _02059472
	add r0, r4, #0
	add r0, #0x43
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x43
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x43
	ldrb r0, [r0]
	cmp r0, #0x3c
	bls _02059472
	mov r0, #4
	bl sub_02037AC0
	mov r0, #0x2c
	str r0, [r4, #0x34]
	b _02059472
_02059452:
	mov r0, #4
	bl sub_02037B38
	cmp r0, #0
	beq _02059472
	add r0, r4, #0
	add r0, #0x14
	mov r1, #0
	bl ClearFrameAndWindow2
	mov r0, #0
	ldr r2, [r4, #8]
	add r1, r0, #0
	blx r2
	mov r0, #5
	str r0, [r4, #0x34]
_02059472:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, pc}
	thumb_func_end sub_02058D4C
	thumb_func_start sub_02059478
sub_02059478: ; 0x02059478
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r5, #0
	add r4, #0x14
	add r0, r4, #0
	add r6, r1, #0
	bl WindowIsInUse
	cmp r0, #0
	bne _020594AA
	ldr r0, [r5, #0x24]
	add r1, r4, #0
	ldr r0, [r0, #8]
	mov r2, #3
	bl DialogBox_AddWindowToLayer3
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #0xc]
	bl Save_PlayerData_GetOptionsAddr
	add r1, r0, #0
	add r0, r4, #0
	bl DialogBox_LoadFrame
	b _020594B0
_020594AA:
	add r0, r4, #0
	bl DialogBox_Clear
_020594B0:
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #0xc]
	bl Save_PlayerData_GetOptionsAddr
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #1
	bl DialogBox_PrintMessage
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_02059478
	thumb_func_start sub_020594C8
sub_020594C8: ; 0x020594C8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, #0x14
	add r4, r1, #0
	bl WindowIsInUse
	cmp r0, #0
	beq _020594FE
	cmp r4, #0
	beq _020594EE
	add r0, r5, #0
	add r0, #0x14
	mov r1, #0
	bl ClearFrameAndWindow2
	add r0, r5, #0
	add r0, #0x14
	bl ClearWindowTilemapAndCopyToVram
_020594EE:
	add r0, r5, #0
	add r0, #0x14
	bl RemoveWindow
	add r0, r5, #0
	add r0, #0x14
	bl InitWindow
_020594FE:
	add r0, r5, #0
	add r0, #0x54
	bl WindowIsInUse
	cmp r0, #0
	beq _0205951A
	add r0, r5, #0
	add r0, #0x54
	bl RemoveWindow
	add r0, r5, #0
	add r0, #0x54
	bl InitWindow
_0205951A:
	add r0, r5, #0
	add r0, #0x64
	bl WindowIsInUse
	cmp r0, #0
	beq _02059536
	add r0, r5, #0
	add r0, #0x64
	bl RemoveWindow
	add r5, #0x64
	add r0, r5, #0
	bl InitWindow
_02059536:
	pop {r3, r4, r5, pc}
	thumb_func_end sub_020594C8
	thumb_func_start sub_02059538
sub_02059538: ; 0x02059538
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x10]
	add r6, r1, #0
	cmp r0, #0
	beq _02059546
	b _0205964A
_02059546:
	mov r0, #0xb
	mov r1, #0x8c
	bl Heap_AllocAtEnd
	add r4, r0, #0
	mov r1, #0
	mov r2, #0x8c
	bl MI_CpuFill8
	add r0, r4, #0
	mov r1, #5
	add r0, #0x43
	strb r1, [r0]
	str r5, [r4, #0x24]
	str r6, [r4, #8]
	mov r0, #0xb
	bl MessageFormat_New
	str r0, [r4, #0x28]
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xe
	mov r3, #0xb
	bl NewMsgDataFromNarc
	str r0, [r4, #0x2c]
	mov r0, #0xc8
	mov r1, #0xb
	bl String_New
	str r0, [r4, #0xc]
	mov r0, #0xc8
	mov r1, #0xb
	bl String_New
	str r0, [r4, #0x10]
	add r0, r4, #0
	add r0, #0x14
	bl InitWindow
	add r0, r4, #0
	add r0, #0x54
	bl InitWindow
	add r0, r4, #0
	add r0, #0x64
	bl InitWindow
	mov r0, #0xb
	bl ListMenuCursorNew
	str r0, [r4, #0x78]
	bl sub_0203993C
	add r1, r4, #0
	add r1, #0x88
	strb r0, [r1]
	mov r1, #0
	str r1, [r4, #0x4c]
	str r1, [r4, #0x48]
	add r0, r4, #0
	str r1, [r4, #0x50]
	add r0, #0x89
	strb r1, [r0]
	bl sub_0203769C
	add r1, r4, #0
	add r1, #0x86
	strh r0, [r1]
	add r0, r4, #0
	add r0, #0x86
	ldrh r1, [r0]
	mov r0, #1
	eor r0, r1
	bl sub_02034818
	str r0, [r4, #0x74]
	add r0, r4, #0
	add r0, #0x88
	ldrb r0, [r0]
	cmp r0, #3
	beq _020595F0
	cmp r0, #4
	beq _02059626
	b _0205962C
_020595F0:
	bl sub_02059B08
	add r6, r0, #0
	mov r0, #0xb
	add r1, r6, #0
	bl Heap_AllocAtEnd
	str r0, [r4, #0x4c]
	mov r0, #0xb
	add r1, r6, #0
	bl Heap_AllocAtEnd
	str r0, [r4, #0x48]
	mov r0, #0xb
	bl SaveArray_Party_Alloc
	mov r1, #3
	str r0, [r4, #0x50]
	bl Party_InitWithMaxSize
	add r0, r4, #0
	mov r1, #5
	add r0, #0x44
	strb r1, [r0]
	mov r0, #0x17
	str r0, [r4, #0x34]
	b _02059640
_02059626:
	mov r0, #9
	str r0, [r4, #0x34]
	b _02059640
_0205962C:
	ldr r0, [r4, #0x24]
	add r0, #0xa4
	ldr r0, [r0]
	cmp r0, #0
	beq _0205963C
	mov r0, #9
	str r0, [r4, #0x34]
	b _02059640
_0205963C:
	mov r0, #0
	str r0, [r4, #0x34]
_02059640:
	ldr r1, _0205964C ; =sub_02058D4C
	add r0, r5, #0
	add r2, r4, #0
	bl FieldSystem_CreateTask
_0205964A:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0205964C: .word sub_02058D4C
	thumb_func_end sub_02059538
