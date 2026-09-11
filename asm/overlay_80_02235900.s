	.include "asm/macros.inc"
	.public FrtCmd_170
	.public FrtCmd_171
	.public FrtCmd_172
	.public FrtCmd_173
	.public FrtCmd_174
	.public FrtCmd_175
	.public FrtCmd_176
	.public FrtCmd_177
	.public FrtCmd_178
	.public FrtCmd_179
	.public FrtCmd_180
	.public FrtCmd_181
	.public FrtCmd_182
	.public FrtCmd_202
	.public _0223598C
	.public _022359AE
	.public _022359D0
	.public _022359F4
	.public _02235A0E
	.public _02235A3A
	.public _02235A3C
	.public _02235ABE
	.public _02235ACC
	.public _02235AF2
	.public _02235B64
	.public _02235B80
	.public _02235B88
	.public _02235B90
	.public _02235BB2
	.public _02235BB8
	.public _02235BD0
	.public _02235BD2
	.public _02235BDA
	.public _02235BF2
	.public _02235BF8
	.public _02235C00
	.public _02235C1E
	.public _02235C24
	.public _02235C3C
	.public _02235C44
	.public _02235C60
	.public _02235C88
	.public _02235C94
	.public _02235CA6
	.public _02235CAC
	.public _02235CB4
	.public _02235CBC
	.public _02235CC4
	.public _02235CF6
	.public _02235CF8
	.public _02235D3E
	.public _02235DA8
	.public _02235DE6
	.public _02235E1A
	.public _02235E50
	.public _02235E6C
	.public _02235E70
	.public _02235E80
	.public _02235EA4
	.public _02235ED8
	.public _02235EE6
	.public _02235F10
	.public _02235F44
	.public _02235F60
	.public _02235F8C
	.public _02235FA6
	.public _02235FB0
	.public ov80_02235990
	.public ov80_022359D4
	.public ov80_02235F90
	.include "overlay_80_02235900.inc"
	.include "global.inc"

    .text
	.public FrtCmd_170
	.public FrtCmd_171
	.public FrtCmd_172
	.public FrtCmd_173
	.public FrtCmd_174
	.public FrtCmd_175
	.public FrtCmd_176
	.public FrtCmd_177
	.public FrtCmd_180
	.public FrtCmd_181
	.public FrtCmd_182
	.public FrtCmd_202
	.public ov80_02235990
	.public ov80_022359D4
	.public ov80_02235F90

	thumb_func_start FrtCmd_178
FrtCmd_178: ; 0x02235B20
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	ldr r1, [r7, #0x1c]
	add r2, r1, #1
	str r2, [r7, #0x1c]
	ldrb r1, [r1]
	str r1, [sp]
	add r1, r2, #1
	str r1, [r7, #0x1c]
	ldrb r6, [r2]
	add r1, r1, #1
	str r1, [r7, #0x1c]
	bl FrontierScript_ReadVarPtr
	add r5, r0, #0
	ldr r0, [r7]
	ldr r0, [r0]
	bl Frontier_GetData
	add r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0]
	bl Frontier_GetLaunchArgs
	add r7, r0, #0
	ldr r0, [sp]
	cmp r0, #0xd
	bhi _02235BD0
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02235B64: ; jump table
	.short _02235B80 - _02235B64 - 2 ; case 0
	.short _02235B88 - _02235B64 - 2 ; case 1
	.short _02235B90 - _02235B64 - 2 ; case 2
	.short _02235C44 - _02235B64 - 2 ; case 3
	.short _02235C60 - _02235B64 - 2 ; case 4
	.short _02235C88 - _02235B64 - 2 ; case 5
	.short _02235C94 - _02235B64 - 2 ; case 6
	.short _02235CA6 - _02235B64 - 2 ; case 7
	.short _02235CAC - _02235B64 - 2 ; case 8
	.short _02235CB4 - _02235B64 - 2 ; case 9
	.short _02235CBC - _02235B64 - 2 ; case 10
	.short _02235CC4 - _02235B64 - 2 ; case 11
	.short _02235D3E - _02235B64 - 2 ; case 12
	.short _02235E6C - _02235B64 - 2 ; case 13
_02235B80:
	add r0, r4, #0
	bl sub_02096910
	b _02235E80
_02235B88:
	add r4, #0x86
	ldrh r0, [r4]
	strh r0, [r5]
	b _02235E80
_02235B90:
	cmp r6, #1
	bne _02235BDA
	mov r0, #0
	strh r0, [r5]
	add r0, r4, #0
	add r0, #0x76
	ldrh r1, [r0]
	add r0, r4, #0
	add r0, #0x86
	ldrh r0, [r0]
	cmp r1, r0
	beq _02235BB2
	add r0, r4, #0
	add r0, #0x88
	ldrh r0, [r0]
	cmp r1, r0
	bne _02235BB8
_02235BB2:
	ldrh r0, [r5]
	add r0, r0, #1
	strh r0, [r5]
_02235BB8:
	add r0, r4, #0
	add r0, #0x78
	ldrh r1, [r0]
	add r0, r4, #0
	add r0, #0x86
	ldrh r0, [r0]
	cmp r1, r0
	beq _02235BD2
	add r4, #0x88
	ldrh r0, [r4]
	cmp r1, r0
	beq _02235BD2
_02235BD0:
	b _02235E80
_02235BD2:
	ldrh r0, [r5]
	add r0, r0, #2
	strh r0, [r5]
	b _02235E80
_02235BDA:
	cmp r6, #5
	bne _02235BF8
	add r0, r4, #0
	add r0, #0x76
	add r4, #0x86
	ldrh r1, [r0]
	ldrh r0, [r4]
	cmp r1, r0
	bne _02235BF2
	mov r0, #0
	strh r0, [r5]
	b _02235E80
_02235BF2:
	mov r0, #1
	strh r0, [r5]
	b _02235E80
_02235BF8:
	cmp r6, #4
	beq _02235C00
	cmp r6, #6
	bne _02235CF6
_02235C00:
	mov r0, #0
	strh r0, [r5]
	add r0, r4, #0
	add r0, #0x76
	ldrh r1, [r0]
	add r0, r4, #0
	add r0, #0x86
	ldrh r0, [r0]
	cmp r1, r0
	beq _02235C1E
	add r0, r4, #0
	add r0, #0x88
	ldrh r0, [r0]
	cmp r1, r0
	bne _02235C24
_02235C1E:
	ldrh r0, [r5]
	add r0, r0, #1
	strh r0, [r5]
_02235C24:
	add r0, r4, #0
	add r0, #0x78
	ldrh r1, [r0]
	add r0, r4, #0
	add r0, #0x86
	ldrh r0, [r0]
	cmp r1, r0
	beq _02235C3C
	add r4, #0x88
	ldrh r0, [r4]
	cmp r1, r0
	bne _02235CF6
_02235C3C:
	ldrh r0, [r5]
	add r0, r0, #2
	strh r0, [r5]
	b _02235E80
_02235C44:
	ldr r0, [r7, #8]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	mov r0, #0x6a
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0x6a
	bl FrontierSave_GetStat
	strh r0, [r5]
	b _02235E80
_02235C60:
	ldr r0, [r7, #8]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	mov r0, #3
	bl sub_0205C11C
	add r6, r0, #0
	mov r0, #3
	bl sub_0205C11C
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl FrontierSave_GetStat
	strh r0, [r5]
	b _02235E80
_02235C88:
	lsl r0, r6, #1
	add r0, r4, r0
	add r0, #0x76
	ldrh r0, [r0]
	strh r0, [r5]
	b _02235E80
_02235C94:
	ldr r0, [r7, #8]
	bl sub_02030C5C
	add r1, r0, #0
	ldr r0, [r7, #8]
	mov r2, #3
	bl sub_0204F878
	b _02235E80
_02235CA6:
	add r4, #0xa0
	strb r6, [r4]
	b _02235E80
_02235CAC:
	add r4, #0x74
	ldrh r0, [r4]
	strh r0, [r5]
	b _02235E80
_02235CB4:
	add r4, #0xa0
	ldrb r0, [r4]
	strh r0, [r5]
	b _02235E80
_02235CBC:
	add r4, #0x71
	ldrb r0, [r4]
	strh r0, [r5]
	b _02235E80
_02235CC4:
	mov r0, #1
	strh r0, [r5]
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	bl ov80_022385D8
	add r6, r0, #0
	ldr r0, [r4]
	bl Save_Frontier_GetStatic
	add r7, r0, #0
	add r0, r6, #0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r7, #0
	add r1, r6, #0
	bl FrontierSave_GetStat
	add r1, r4, #0
	add r1, #0x72
	ldrh r1, [r1]
	cmp r0, r1
	bne _02235CF8
_02235CF6:
	b _02235E80
_02235CF8:
	ldr r0, [r4]
	bl Save_Frontier_GetStatic
	add r7, r0, #0
	add r0, r6, #0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r7, #0
	add r1, r6, #0
	mov r3, #0
	bl sub_02031108
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	bl ov80_02238610
	add r6, r0, #0
	ldr r0, [r4]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	add r0, r6, #0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0
	bl sub_02031108
	mov r0, #0
	strh r0, [r5]
	b _02235E80
_02235D3E:
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	bl ov80_02238610
	add r6, r0, #0
	ldr r0, [r4]
	bl Save_Frontier_GetStatic
	add r7, r0, #0
	add r0, r6, #0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r7, #0
	add r1, r6, #0
	bl FrontierSave_GetStat
	strh r0, [r5]
	ldrh r0, [r5]
	cmp r0, #0
	bne _02235E50
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	bl ov80_022385D8
	add r5, r0, #0
	ldr r0, [r4]
	bl Save_Frontier_GetStatic
	add r6, r0, #0
	add r0, r5, #0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r6, #0
	add r1, r5, #0
	mov r3, #0
	bl sub_02031108
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	cmp r0, #1
	bne _02235DA8
	ldr r0, [r4]
	bl Save_FrontierData_Get
	mov r1, #6
	mov r2, #2
	bl sub_0202D57C
_02235DA8:
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	cmp r0, #4
	bne _02235DE6
	ldr r0, [r4]
	bl Save_Frontier_GetStatic
	add r5, r0, #0
	mov r0, #0x88
	bl sub_0205C268
	add r2, r0, #0
	add r0, r5, #0
	mov r1, #0x88
	mov r3, #0
	bl sub_02031108
	ldr r0, [r4]
	bl Save_Frontier_GetStatic
	add r5, r0, #0
	mov r0, #0x89
	bl sub_0205C268
	add r2, r0, #0
	add r0, r5, #0
	mov r1, #0x89
	mov r3, #0
	bl sub_02031108
_02235DE6:
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	cmp r0, #2
	bne _02235E1A
	ldr r0, [r4]
	bl Save_Frontier_GetStatic
	add r5, r0, #0
	mov r0, #0
	mov r1, #3
	bl sub_0205C048
	add r6, r0, #0
	mov r0, #0
	mov r1, #3
	bl sub_0205C048
	bl sub_0205C268
	add r2, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	mov r3, #0
	bl sub_02031108
_02235E1A:
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	cmp r0, #3
	bne _02235E80
	ldr r0, [r4]
	bl Save_Frontier_GetStatic
	add r5, r0, #0
	mov r0, #1
	mov r1, #3
	bl sub_0205C048
	add r4, r0, #0
	mov r0, #1
	mov r1, #3
	bl sub_0205C048
	bl sub_0205C268
	add r2, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	mov r3, #0
	bl sub_02031108
	b _02235E80
_02235E50:
	ldr r0, [r4]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	add r0, r6, #0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0
	bl sub_02031108
	b _02235E80
_02235E6C:
	mov r2, #0
	add r1, r2, #0
_02235E70:
	add r0, r4, r2
	add r0, #0xa1
	add r2, r2, #1
	strb r1, [r0]
	cmp r2, #2
	blt _02235E70
	add r4, #0x9f
	strb r1, [r4]
_02235E80:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end FrtCmd_178


	thumb_func_start FrtCmd_179
FrtCmd_179: ; 0x02235E84
	push {r4, r5, r6, r7, lr}
	sub sp, #0xb4
	add r5, r0, #0
	ldr r0, [r5]
	ldr r0, [r0]
	bl Frontier_GetLaunchArgs
	add r7, r0, #0
	ldr r0, [r5]
	ldr r0, [r0]
	bl Frontier_GetData
	add r6, r0, #0
	add r4, r6, #0
	add r3, sp, #0
	mov r2, #0x16
_02235EA4:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02235EA4
	ldr r0, [r4]
	str r0, [r3]
	add r0, r6, #0
	bl ov80_02235FEC
	ldr r0, [r7, #8]
	mov r1, #0
	mov r2, #6
	bl FrontierFieldSystem_New
	add r4, r0, #0
	ldr r0, [r5]
	add r1, r4, #0
	ldr r0, [r0]
	bl Frontier_SetData
	ldrb r0, [r4, #0xf]
	cmp r0, #6
	bne _02235ED8
	ldr r0, [r7, #8]
	bl ov80_0222A840
_02235ED8:
	ldrb r0, [r4, #0xe]
	mov r2, #0
	cmp r0, #0
	ble _02235F10
	add r3, sp, #0
	add r5, r3, #0
	add r6, r4, #0
_02235EE6:
	add r0, r3, #0
	add r0, #0x6a
	ldrb r1, [r0]
	add r0, r4, r2
	add r0, #0x2a
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0x76
	ldrh r0, [r0]
	add r2, r2, #1
	add r3, r3, #1
	strh r0, [r6, #0x2e]
	add r0, r5, #0
	add r0, #0x7e
	ldrh r0, [r0]
	add r5, r5, #2
	strh r0, [r6, #0x36]
	ldrb r0, [r4, #0xe]
	add r6, r6, #2
	cmp r2, r0
	blt _02235EE6
_02235F10:
	add r0, sp, #0x80
	ldrh r1, [r0, #6]
	strh r1, [r4, #0x16]
	ldrh r0, [r0, #8]
	mov r1, #0xe0
	strh r0, [r4, #0x18]
	add r0, sp, #0x40
	ldrb r2, [r0, #0x18]
	strb r2, [r4, #0x12]
	ldrb r0, [r4, #0x10]
	bic r0, r1
	add r1, r2, #5
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	lsl r1, r1, #0x1d
	lsr r1, r1, #0x18
	orr r0, r1
	strb r0, [r4, #0x10]
	bl sub_0203769C
	cmp r0, #0
	bne _02235F44
	ldr r1, [r7, #8]
	add r0, r4, #0
	bl FrontierFieldSystem_SetRandomFrontierTrainers
_02235F44:
	ldr r0, [r7, #8]
	bl SaveArray_Party_Get
	bl HealParty
	add r0, r4, #0
	bl sub_02096910
	ldr r1, _02235F60 ; =0x000008D4
	mov r0, #0
	strb r0, [r4, r1]
	add sp, #0xb4
	pop {r4, r5, r6, r7, pc}
	nop
_02235F60: .word 0x000008D4
	thumb_func_end FrtCmd_179
