	.include "asm/macros.inc"
	.public FrtCmd_080
	.public FrtCmd_081
	.public FrtCmd_082
	.public FrtCmd_151
	.public FrtCmd_152
	.public FrtCmd_153
	.public FrtCmd_154
	.public FrtCmd_155
	.public FrtCmd_156
	.public FrtCmd_157
	.public FrtCmd_158
	.public FrtCmd_159
	.public FrtCmd_160
	.public FrtCmd_161
	.public FrtCmd_162
	.public FrtCmd_163
	.public FrtCmd_164
	.public FrtCmd_165
	.public FrtCmd_166
	.public FrtCmd_167
	.public FrtCmd_168
	.public FrtCmd_169
	.public _02231CD8
	.public _02231CDC
	.public _02231D2C
	.public _02231D30
	.public _02231D84
	.public _02231DA8
	.public _02231DF4
	.public _02231E44
	.public _02231E48
	.public _02231E6A
	.public _02231E90
	.public _02231F18
	.public _02231F24
	.public _02231F7E
	.public _02231F82
	.public _02231F90
	.public _02231F96
	.public _02231FA4
	.public _02231FAC
	.public _02231FB6
	.public _02231FC0
	.public _02231FCA
	.public _02231FDE
	.public _02231FF4
	.public _02232002
	.public _0223201E
	.public _02232020
	.public _0223202A
	.public _02232036
	.public _0223203E
	.public _02232046
	.public _02232050
	.public _0223205A
	.public _02232062
	.public _02232076
	.public _0223207E
	.public _02232086
	.public _02232094
	.public _02232098
	.public _022320A8
	.public _022320AE
	.public _022320C4
	.public _022320CE
	.public _022320E2
	.public _022320EC
	.public _02232110
	.public _02232118
	.public _0223211A
	.public _02232120
	.public _0223212A
	.public _02232130
	.public _02232136
	.public _0223214A
	.public _02232178
	.public _02232182
	.public _022321B2
	.public _022321CA
	.public _022321D4
	.public _02232200
	.public _02232208
	.public _02232212
	.public _0223226A
	.public _0223228E
	.public _02232294
	.public _02232298
	.public _0223229C
	.public _022322A0
	.public _022322A4
	.public _022322A8
	.public _02232314
	.public _0223233E
	.public _02232344
	.public _02232364
	.public _0223238C
	.public _0223239C
	.public _022324B0
	.public ov80_02231E4C
	.public ov80_02231E94
	.public ov80_02232318
	.public ov80_02232368
	.include "overlay_80_02231BF8.inc"
	.include "global.inc"

    .text
	.public FrtCmd_080
	.public FrtCmd_081
	.public FrtCmd_082
	.public FrtCmd_151
	.public FrtCmd_152
	.public FrtCmd_153
	.public FrtCmd_154
	.public FrtCmd_155
	.public FrtCmd_156
	.public FrtCmd_157
	.public FrtCmd_158
	.public FrtCmd_159
	.public FrtCmd_161
	.public FrtCmd_162
	.public FrtCmd_163
	.public FrtCmd_164
	.public FrtCmd_165
	.public FrtCmd_166
	.public FrtCmd_167
	.public FrtCmd_168
	.public FrtCmd_169
	.public ov80_02231E94
	.public ov80_02232318
	.public ov80_02232368

	thumb_func_start FrtCmd_160
FrtCmd_160: ; 0x02231ED0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	ldr r3, [r0, #0x1c]
	add r1, r0, #0
	add r2, r3, #1
	str r2, [r1, #0x1c]
	ldrb r1, [r3]
	add r3, r2, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x18]
	add r1, r0, #0
	str r3, [r1, #0x1c]
	ldrb r6, [r2]
	add r2, r3, #1
	str r2, [r1, #0x1c]
	ldrb r1, [r3]
	str r1, [sp, #0x14]
	bl FrontierScript_ReadVarPtr
	add r5, r0, #0
	ldr r0, [sp, #0x10]
	ldr r0, [r0]
	ldr r0, [r0]
	bl Frontier_GetData
	add r4, r0, #0
	ldr r0, [sp, #0x10]
	ldr r0, [r0]
	ldr r0, [r0]
	bl Frontier_GetLaunchArgs
	add r7, r0, #0
	ldr r0, [sp, #0x18]
	cmp r0, #0x2c
	bls _02231F18
	b _0223228E
_02231F18:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02231F24: ; jump table
	.short _0223228E - _02231F24 - 2 ; case 0
	.short _0223228E - _02231F24 - 2 ; case 1
	.short _02231F7E - _02231F24 - 2 ; case 2
	.short _02231F82 - _02231F24 - 2 ; case 3
	.short _02231F90 - _02231F24 - 2 ; case 4
	.short _02231F96 - _02231F24 - 2 ; case 5
	.short _0223228E - _02231F24 - 2 ; case 6
	.short _02231FA4 - _02231F24 - 2 ; case 7
	.short _0223228E - _02231F24 - 2 ; case 8
	.short _02231FAC - _02231F24 - 2 ; case 9
	.short _02231FB6 - _02231F24 - 2 ; case 10
	.short _0223228E - _02231F24 - 2 ; case 11
	.short _0223228E - _02231F24 - 2 ; case 12
	.short _0223228E - _02231F24 - 2 ; case 13
	.short _02231FC0 - _02231F24 - 2 ; case 14
	.short _02231FCA - _02231F24 - 2 ; case 15
	.short _02231FDE - _02231F24 - 2 ; case 16
	.short _0223212A - _02231F24 - 2 ; case 17
	.short _02231FF4 - _02231F24 - 2 ; case 18
	.short _02232020 - _02231F24 - 2 ; case 19
	.short _0223202A - _02231F24 - 2 ; case 20
	.short _02232036 - _02231F24 - 2 ; case 21
	.short _0223203E - _02231F24 - 2 ; case 22
	.short _02232046 - _02231F24 - 2 ; case 23
	.short _02232050 - _02231F24 - 2 ; case 24
	.short _02232130 - _02231F24 - 2 ; case 25
	.short _0223205A - _02231F24 - 2 ; case 26
	.short _02232062 - _02231F24 - 2 ; case 27
	.short _02232076 - _02231F24 - 2 ; case 28
	.short _0223207E - _02231F24 - 2 ; case 29
	.short _02232086 - _02231F24 - 2 ; case 30
	.short _02232098 - _02231F24 - 2 ; case 31
	.short _022320A8 - _02231F24 - 2 ; case 32
	.short _022320AE - _02231F24 - 2 ; case 33
	.short _022320EC - _02231F24 - 2 ; case 34
	.short _02232120 - _02231F24 - 2 ; case 35
	.short _02232136 - _02231F24 - 2 ; case 36
	.short _0223214A - _02231F24 - 2 ; case 37
	.short _02232178 - _02231F24 - 2 ; case 38
	.short _02232182 - _02231F24 - 2 ; case 39
	.short _022321B2 - _02231F24 - 2 ; case 40
	.short _022321D4 - _02231F24 - 2 ; case 41
	.short _02232200 - _02231F24 - 2 ; case 42
	.short _02232208 - _02231F24 - 2 ; case 43
	.short _02232212 - _02231F24 - 2 ; case 44
_02231F7E:
	strb r6, [r4, #0x10]
	b _0223228E
_02231F82:
	lsl r0, r6, #1
	add r1, r4, r0
	mov r0, #0xe
	lsl r0, r0, #6
	ldrh r0, [r1, r0]
	strh r0, [r5]
	b _0223228E
_02231F90:
	ldrh r0, [r4, #0x14]
	strh r0, [r5]
	b _0223228E
_02231F96:
	ldrh r1, [r4, #0x14]
	ldr r0, _02232294 ; =0x0000270F
	cmp r1, r0
	bhs _0223201E
	add r0, r1, #1
	strh r0, [r4, #0x14]
	b _0223228E
_02231FA4:
	mov r0, #0
	bl OS_ResetSystem
	b _0223228E
_02231FAC:
	ldr r0, [r4, #8]
	bl sub_02030CD8
	strh r0, [r5]
	b _0223228E
_02231FB6:
	add r0, r4, #0
	mov r1, #2
	bl ov80_02232B58
	b _0223228E
_02231FC0:
	add r0, r4, #0
	bl ov80_02232E58
	strh r0, [r5]
	b _0223228E
_02231FCA:
	mov r0, #0x38
	mul r0, r6
	add r1, r4, r0
	mov r0, #0xa2
	lsl r0, r0, #2
	ldrh r0, [r1, r0]
	lsl r0, r0, #0x15
	lsr r0, r0, #0x15
	strh r0, [r5]
	b _0223228E
_02231FDE:
	mov r0, #0x38
	mul r0, r6
	add r1, r4, r0
	ldr r0, [sp, #0x14]
	lsl r0, r0, #1
	add r1, r1, r0
	mov r0, #0xa3
	lsl r0, r0, #2
	ldrh r0, [r1, r0]
	strh r0, [r5]
	b _0223228E
_02231FF4:
	ldr r0, [r7, #8]
	bl SaveArray_Party_Get
	add r7, r0, #0
	ldr r0, _02232298 ; =0x0000036A
	mov r5, #0
	add r6, r4, r0
_02232002:
	add r1, r4, r5
	add r1, #0x24
	ldrb r1, [r1]
	add r0, r7, #0
	bl Party_GetMonByIndex
	mov r1, #6
	add r2, r6, #0
	bl SetMonData
	add r5, r5, #1
	add r6, r6, #2
	cmp r5, #3
	blt _02232002
_0223201E:
	b _0223228E
_02232020:
	add r0, r4, #0
	bl ov80_02237ED8
	strh r0, [r5]
	b _0223228E
_0223202A:
	add r0, r4, #0
	add r1, r6, #0
	bl ov80_02232E68
	strh r0, [r5]
	b _0223228E
_02232036:
	add r0, r4, #0
	bl ov80_02232E9C
	b _0223228E
_0223203E:
	add r0, r4, #0
	bl ov80_02232EE0
	b _0223228E
_02232046:
	add r0, r4, #0
	bl ov80_02232E64
	strh r0, [r5]
	b _0223228E
_02232050:
	mov r0, #0xa1
	lsl r0, r0, #4
	ldrb r0, [r4, r0]
	strh r0, [r5]
	b _0223228E
_0223205A:
	ldr r0, _0223229C ; =0x00000A11
	ldrb r0, [r4, r0]
	strh r0, [r5]
	b _0223228E
_02232062:
	add r0, r4, #0
	bl ov80_02233020
	strh r0, [r5]
	ldrb r1, [r4, #0x10]
	ldrh r2, [r5]
	ldr r0, [r4, #4]
	bl ov80_022331E8
	b _0223228E
_02232076:
	add r0, r4, #0
	bl ov80_02232F60
	b _0223228E
_0223207E:
	add r0, r4, #0
	bl sub_02096910
	b _0223228E
_02232086:
	ldr r0, _022322A0 ; =0x00000A1B
	ldrb r0, [r4, r0]
	cmp r0, #6
	blo _02232094
	sub r0, r0, #6
	strh r0, [r5]
	b _0223228E
_02232094:
	strh r0, [r5]
	b _0223228E
_02232098:
	ldr r0, _022322A0 ; =0x00000A1B
	mov r2, #0
	strb r2, [r4, r0]
	sub r1, r0, #2
	strb r2, [r4, r1]
	sub r0, r0, #3
	strb r2, [r4, r0]
	b _0223228E
_022320A8:
	ldr r0, _022322A4 ; =0x00000A18
	strb r6, [r4, r0]
	b _0223228E
_022320AE:
	ldr r0, _022322A0 ; =0x00000A1B
	mov r5, #0
	ldrb r0, [r4, r0]
	cmp r0, #6
	blo _022320C4
	bl sub_0203769C
	cmp r0, #0
	beq _022320CE
	mov r5, #1
	b _022320CE
_022320C4:
	bl sub_0203769C
	cmp r0, #0
	bne _022320CE
	mov r5, #1
_022320CE:
	cmp r5, #1
	bne _022320E2
	ldr r0, [r7, #8]
	bl Save_Frontier_GetStatic
	ldrb r1, [r4, #0x10]
	mov r2, #0x32
	bl ov80_02237FA4
	b _0223228E
_022320E2:
	ldr r0, _022322A8 ; =0x00000A1C
	ldrh r1, [r4, r0]
	sub r1, #0x32
	strh r1, [r4, r0]
	b _0223228E
_022320EC:
	mov r0, #0
	strh r0, [r5]
	ldrb r0, [r4, #0x10]
	bl ov80_02237D8C
	cmp r0, #1
	bne _02232118
	ldr r0, _022322A0 ; =0x00000A1B
	ldrb r0, [r4, r0]
	cmp r0, #6
	blo _02232110
	bl sub_0203769C
	cmp r0, #0
	bne _02232118
	mov r0, #1
	strh r0, [r5]
	b _0223228E
_02232110:
	bl sub_0203769C
	cmp r0, #0
	bne _0223211A
_02232118:
	b _0223228E
_0223211A:
	mov r0, #1
	strh r0, [r5]
	b _0223228E
_02232120:
	ldrb r0, [r4, #0x10]
	bl ov80_02237D8C
	strh r0, [r5]
	b _0223228E
_0223212A:
	ldrb r0, [r4, #0x10]
	strh r0, [r5]
	b _0223228E
_02232130:
	ldrb r0, [r4, #0x12]
	strh r0, [r5]
	b _0223228E
_02232136:
	ldr r0, [sp, #0x10]
	ldr r0, [r0]
	bl FrontierSystem_GetFrontierMap
	ldr r0, [r0]
	add r1, r4, #0
	mov r2, #3
	bl ov80_02237EFC
	b _0223228E
_0223214A:
	ldrb r1, [r4, #0x11]
	add r0, r4, #0
	add r0, #0x4c
	lsl r1, r1, #1
	add r1, r4, r1
	ldrh r1, [r1, #0x30]
	mov r2, #0xb
	mov r3, #0xcc
	bl ov80_0222A474
	ldrb r1, [r4, #0x11]
	mov r0, #0x57
	lsl r0, r0, #2
	add r1, r1, #7
	lsl r1, r1, #1
	add r1, r4, r1
	ldrh r1, [r1, #0x30]
	add r0, r4, r0
	mov r2, #0xb
	mov r3, #0xcc
	bl ov80_0222A474
	b _0223228E
_02232178:
	add r0, r4, #0
	bl ov80_02233648
	strh r0, [r5]
	b _0223228E
_02232182:
	ldr r0, [r7, #8]
	bl sub_02030E08
	mov r2, #0
	str r2, [sp]
	mov r1, #0xa
	add r3, r2, #0
	bl sub_02030E58
	strh r0, [r5]
	mov r1, #1
	add r0, sp, #0x20
	strb r1, [r0]
	ldr r0, [r7, #8]
	bl sub_02030E08
	add r1, sp, #0x20
	mov r2, #0
	str r1, [sp]
	mov r1, #0xa
	add r3, r2, #0
	bl sub_02030E18
	b _0223228E
_022321B2:
	mov r0, #0
	strh r0, [r5]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0223228E
	ldrh r0, [r4, #0x14]
	add r0, r0, #1
	cmp r0, #0x15
	bne _022321CA
	mov r0, #1
	strh r0, [r5]
	b _0223228E
_022321CA:
	cmp r0, #0x31
	bne _0223228E
	mov r0, #2
	strh r0, [r5]
	b _0223228E
_022321D4:
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	mov r3, #0xa2
	lsl r3, r3, #2
	str r0, [sp, #4]
	mov r0, #0xb
	str r0, [sp, #8]
	mov r0, #0xcd
	add r1, r3, #0
	add r2, r3, #0
	str r0, [sp, #0xc]
	add r0, r4, r3
	sub r1, #0x1c
	sub r2, #0x14
	sub r3, #0x10
	add r1, r4, r1
	add r2, r4, r2
	add r3, r4, r3
	bl ov80_0222A52C
	b _0223228E
_02232200:
	add r0, r4, #0
	bl ov80_02237E30
	b _0223228E
_02232208:
	ldrb r0, [r4, #0x13]
	strh r0, [r5]
	mov r0, #1
	strb r0, [r4, #0x13]
	b _0223228E
_02232212:
	ldrb r5, [r4, #0x10]
	cmp r5, #3
	bne _0223228E
	cmp r6, #0
	ldr r0, [r7, #8]
	bne _0223226A
	bl Save_Frontier_GetStatic
	add r6, r0, #0
	ldrb r0, [r4, #0x10]
	bl sub_0205C1F0
	str r0, [sp, #0x1c]
	add r0, r5, #0
	bl sub_0205C1F0
	bl sub_0205C268
	add r2, r0, #0
	ldr r1, [sp, #0x1c]
	add r0, r6, #0
	bl FrontierSave_GetStat
	strh r0, [r4, #0x22]
	ldr r0, [r7, #8]
	bl Save_Frontier_GetStatic
	add r5, r0, #0
	ldrb r0, [r4, #0x10]
	bl sub_0205C1F0
	add r6, r0, #0
	ldrb r0, [r4, #0x10]
	bl sub_0205C1F0
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r4, #0x20]
	add r0, r5, #0
	add r1, r6, #0
	bl sub_02031108
	b _0223228E
_0223226A:
	bl Save_Frontier_GetStatic
	add r6, r0, #0
	ldrb r0, [r4, #0x10]
	bl sub_0205C1F0
	add r7, r0, #0
	add r0, r5, #0
	bl sub_0205C1F0
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r4, #0x22]
	add r0, r6, #0
	add r1, r7, #0
	bl sub_02031108
_0223228E:
	mov r0, #0
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02232294: .word 0x0000270F
_02232298: .word 0x0000036A
_0223229C: .word 0x00000A11
_022322A0: .word 0x00000A1B
_022322A4: .word 0x00000A18
_022322A8: .word 0x00000A1C
	thumb_func_end FrtCmd_160
