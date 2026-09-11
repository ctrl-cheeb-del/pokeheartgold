	.include "asm/macros.inc"
	.public _02229F00
	.public _02229F68
	.public _02229FC2
	.public _02229FCC
	.public _02229FD0
	.public _02229FDC
	.public _02229FE8
	.public _02229FF8
	.public _0222A026
	.public _0222A028
	.public _0222A068
	.public _0222A078
	.public _0222A08C
	.public _0222A092
	.public _0222A0A4
	.public _0222A0D4
	.public _0222A0E8
	.public _0222A0FA
	.public _0222A118
	.public _0222A11C
	.public _0222A120
	.public _0222A124
	.public _0222A128
	.public _0222A12C
	.public _0222A130
	.public _0222A134
	.public _0222A138
	.public _0222A13C
	.public _0222A158
	.public _0222A15E
	.public _0222A1BC
	.public _0222A2E4
	.public _0222A2F0
	.public _0222A308
	.public _0222A310
	.public _0222A31E
	.public _0222A32C
	.public _0222A330
	.public _0222A3B8
	.public _0222A3FC
	.public _0222A428
	.public _0222A42E
	.public _0222A454
	.public _0222A45E
	.public _0222A462
	.public _0222A466
	.public _0222A46A
	.public _0222A46E
	.public _0222A554
	.public _0222A55E
	.public _0222A560
	.public _0222A56E
	.public _0222A570
	.public _0222A58C
	.public _0222A5A0
	.public _0222A5AC
	.public _0222A5B4
	.public _0222A5BC
	.public _0222A5C4
	.public _0222A5CC
	.public _0222A5D4
	.public _0222A5DC
	.public _0222A5F8
	.public _0222A60A
	.public _0222A63A
	.public _0222A64E
	.public _0222A66A
	.public _0222A680
	.public _0222A68C
	.public _0222A6A0
	.public _0222A6A6
	.public _0222A6B2
	.public _0222A6DC
	.public _0222A6EE
	.public _0222A710
	.public _0222A738
	.public _0222A75C
	.public _0222A796
	.public _0222A7A6
	.public _0222A804
	.public _0222A816
	.public _0222A81E
	.public _0222A822
	.public _0222A82A
	.public _0222A82E
	.public _0222A836
	.public _0222A83C
	.public _0223B620
	.public ov80_02229EE0
	.public ov80_02229EF4
	.public ov80_02229F04
	.public ov80_02229F6C
	.public ov80_0222A140
	.public ov80_0222A30C
	.public ov80_0222A334
	.public ov80_0222A3BC
	.public ov80_0222A3D4
	.public ov80_0222A400
	.public ov80_0222A43C
	.public ov80_0222A474
	.public ov80_0222A480
	.public ov80_0222A4EC
	.public ov80_0222A52C
	.public ov80_0222A5A4
	.public ov80_0222A5E0
	.public ov80_0222A6B8
	.public ov80_0222A7CC
	.public ov80_0222A7EC
	.public ov80_0222A840
	.public ov80_0223B628
	.public ov80_0223B62A
	.include "overlay_80_02229EE0.inc"
	.include "global.inc"

	.text
	.public ov80_02229EE0
	.public ov80_02229EF4
	.public ov80_02229F04
	.public ov80_0222A334
	.public ov80_0222A3BC
	.public ov80_0222A3D4
	.public ov80_0222A400
	.public ov80_0222A43C
	.public ov80_0222A474
	.public ov80_0222A480
	.public ov80_0222A5A4
	.public ov80_0222A7CC
	.public ov80_0222A7EC
	.public ov80_0222A840

	thumb_func_start ov80_02229F6C
ov80_02229F6C: ; 0x02229F6C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r1, [sp]
	add r7, r2, #0
	mov r1, #0
	mov r2, #0x38
	add r4, r0, #0
	add r6, r3, #0
	ldr r5, [sp, #0x34]
	bl MI_CpuFill8
	ldr r1, [sp]
	ldr r2, [sp, #0x40]
	add r0, sp, #8
	bl ov80_02229EF4
	ldrh r1, [r4]
	add r3, sp, #8
	ldr r0, _0222A118 ; =0xFFFFF800
	add r2, r1, #0
	and r2, r0
	ldrh r1, [r3]
	lsr r0, r0, #0x15
	and r0, r1
	orr r0, r2
	strh r0, [r4]
	ldrh r1, [r4]
	ldr r0, _0222A11C ; =0xFFFF07FF
	and r0, r1
	ldrh r1, [r3, #0xe]
	lsl r1, r1, #0x1b
	lsr r1, r1, #0x10
	orr r0, r1
	strh r0, [r4]
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _02229FCC
	cmp r5, #4
	blo _02229FC2
	mov r0, #3
	and r0, r5
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
_02229FC2:
	ldr r0, _0222A120 ; =_0223B620
	lsl r1, r5, #1
	ldrh r0, [r0, r1]
	strh r0, [r4, #2]
	b _02229FD0
_02229FCC:
	ldrh r0, [r3, #0xc]
	strh r0, [r4, #2]
_02229FD0:
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0
	add r1, sp, #8
	add r2, r4, #0
	add r5, r0, #0
_02229FDC:
	ldrh r3, [r1, #2]
	strh r3, [r2, #4]
	ldrh r3, [r1, #2]
	cmp r3, #0xda
	bne _02229FE8
	str r5, [sp, #4]
_02229FE8:
	add r0, r0, #1
	add r1, r1, #2
	add r2, r2, #2
	cmp r0, #4
	blt _02229FDC
	str r7, [r4, #0xc]
	cmp r6, #0
	bne _0222A026
_02229FF8:
	bl LCRandom
	add r5, r0, #0
	bl LCRandom
	lsl r0, r0, #0x10
	add r6, r5, #0
	orr r6, r0
	add r0, r6, #0
	bl GetNatureFromPersonality
	add r1, sp, #8
	ldrb r1, [r1, #0xb]
	cmp r1, r0
	bne _02229FF8
	add r0, r7, #0
	add r1, r6, #0
	bl CalcShininessByOtIdAndPersonality
	cmp r0, #1
	beq _02229FF8
	str r6, [r4, #0x10]
	b _0222A028
_0222A026:
	str r6, [r4, #0x10]
_0222A028:
	add r0, sp, #0x20
	ldrb r1, [r0, #0x10]
	ldr r2, [r4, #0x14]
	mov r0, #0x1f
	bic r2, r0
	mov r0, #0x1f
	and r0, r1
	orr r2, r0
	ldr r0, _0222A124 ; =0xFFFFFC1F
	mov r7, #0
	and r2, r0
	lsl r0, r1, #0x1b
	lsr r1, r0, #0x16
	orr r2, r1
	ldr r1, _0222A128 ; =0xFFFF83FF
	add r5, r7, #0
	and r2, r1
	lsr r1, r0, #0x11
	orr r2, r1
	ldr r1, _0222A12C ; =0xFFF07FFF
	and r2, r1
	lsr r1, r0, #0xc
	orr r2, r1
	ldr r1, _0222A130 ; =0xFE0FFFFF
	and r2, r1
	lsr r1, r0, #7
	orr r2, r1
	ldr r1, _0222A134 ; =0xC1FFFFFF
	lsr r0, r0, #2
	and r1, r2
	orr r0, r1
	str r0, [r4, #0x14]
_0222A068:
	add r0, r5, #0
	bl MaskOfFlagNo
	add r1, sp, #8
	ldrb r1, [r1, #0xa]
	tst r0, r1
	beq _0222A078
	add r7, r7, #1
_0222A078:
	add r5, r5, #1
	cmp r5, #6
	blt _0222A068
	ldr r0, _0222A138 ; =0x000001FE
	add r1, r7, #0
	bl _s32_div_f
	cmp r0, #0xff
	ble _0222A08C
	mov r0, #0xff
_0222A08C:
	lsl r0, r0, #0x18
	mov r5, #0
	lsr r7, r0, #0x18
_0222A092:
	add r0, r5, #0
	bl MaskOfFlagNo
	add r1, sp, #8
	ldrb r1, [r1, #0xa]
	tst r0, r1
	beq _0222A0A4
	add r0, r4, r5
	strb r7, [r0, #0x18]
_0222A0A4:
	add r5, r5, #1
	cmp r5, #6
	blt _0222A092
	mov r0, #0
	strb r0, [r4, #0x1e]
	ldr r0, _0222A13C ; =gGameLanguage
	mov r1, #0x19
	ldrb r0, [r0]
	strb r0, [r4, #0x1f]
	ldrh r0, [r4]
	lsl r0, r0, #0x15
	lsr r0, r0, #0x15
	bl GetMonBaseStat
	cmp r0, #0
	beq _0222A0E8
	ldr r2, [r4, #0x10]
	mov r1, #1
	tst r1, r2
	beq _0222A0D4
	add r1, r4, #0
	add r1, #0x20
	strb r0, [r1]
	b _0222A0FA
_0222A0D4:
	ldrh r0, [r4]
	mov r1, #0x18
	lsl r0, r0, #0x15
	lsr r0, r0, #0x15
	bl GetMonBaseStat
	add r1, r4, #0
	add r1, #0x20
	strb r0, [r1]
	b _0222A0FA
_0222A0E8:
	ldrh r0, [r4]
	mov r1, #0x18
	lsl r0, r0, #0x15
	lsr r0, r0, #0x15
	bl GetMonBaseStat
	add r1, r4, #0
	add r1, #0x20
	strb r0, [r1]
_0222A0FA:
	add r1, r4, #0
	ldr r0, [sp, #4]
	add r1, #0x21
	strb r0, [r1]
	ldrh r0, [r4]
	add r4, #0x22
	ldr r1, [sp, #0x3c]
	lsl r0, r0, #0x15
	lsr r0, r0, #0x15
	add r2, r4, #0
	bl GetSpeciesNameIntoArray
	add r0, r6, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222A118: .word 0xFFFFF800
_0222A11C: .word 0xFFFF07FF
_0222A120: .word _0223B620
_0222A124: .word 0xFFFFFC1F
_0222A128: .word 0xFFFF83FF
_0222A12C: .word 0xFFF07FFF
_0222A130: .word 0xFE0FFFFF
_0222A134: .word 0xC1FFFFFF
_0222A138: .word 0x000001FE
_0222A13C: .word gGameLanguage
	thumb_func_end ov80_02229F6C


	thumb_func_start ov80_0222A140
ov80_0222A140: ; 0x0222A140
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r1, #0
	add r6, r0, #0
	add r0, r5, #0
	add r4, r2, #0
	bl ZeroMonData
	cmp r4, #0x78
	bne _0222A158
	mov r4, #0x32
	b _0222A15E
_0222A158:
	cmp r4, #0x79
	bne _0222A15E
	mov r4, #0x64
_0222A15E:
	ldr r1, [r6, #0x14]
	ldr r0, _0222A308 ; =0x3FFFFFFF
	add r2, r4, #0
	and r0, r1
	str r0, [sp, #0x1c]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r6, #0x10]
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldrh r1, [r6]
	ldr r3, [sp, #0x1c]
	add r0, r5, #0
	lsl r1, r1, #0x15
	lsr r1, r1, #0x15
	bl CreateMon
	add r0, r5, #0
	mov r1, #0xaf
	add r2, sp, #0x1c
	bl SetMonData
	add r0, r5, #0
	bl CalcMonLevelAndStats
	ldrh r0, [r6]
	add r2, sp, #0x14
	add r2, #1
	lsl r0, r0, #0x10
	lsr r1, r0, #0x1b
	add r0, sp, #0x14
	strb r1, [r0, #1]
	add r0, r5, #0
	mov r1, #0x70
	bl SetMonData
	add r0, r5, #0
	mov r1, #6
	add r2, r6, #2
	bl SetMonData
	mov r4, #0
	str r6, [sp, #0x10]
	add r7, r4, #0
_0222A1BC:
	ldr r0, [sp, #0x10]
	add r2, sp, #0x14
	ldrh r1, [r0, #4]
	add r0, sp, #0x14
	add r2, #2
	strh r1, [r0, #2]
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x36
	bl SetMonData
	ldrb r0, [r6, #0x1e]
	add r2, sp, #0x14
	add r2, #1
	add r1, r0, #0
	asr r1, r7
	mov r0, #3
	and r1, r0
	add r0, sp, #0x14
	strb r1, [r0, #1]
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x3e
	bl SetMonData
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x42
	mov r2, #0
	bl GetMonData
	add r1, sp, #0x14
	strb r0, [r1]
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x3a
	add r2, sp, #0x14
	bl SetMonData
	ldr r0, [sp, #0x10]
	add r4, r4, #1
	add r0, r0, #2
	add r7, r7, #2
	str r0, [sp, #0x10]
	cmp r4, #4
	blt _0222A1BC
	ldr r0, [r6, #0xc]
	mov r1, #7
	str r0, [sp, #0x18]
	add r0, r5, #0
	add r2, sp, #0x18
	bl SetMonData
	add r2, sp, #0x14
	ldrb r1, [r6, #0x18]
	add r0, sp, #0x14
	add r2, #1
	strb r1, [r0, #1]
	add r0, r5, #0
	mov r1, #0xd
	bl SetMonData
	add r2, sp, #0x14
	ldrb r1, [r6, #0x19]
	add r0, sp, #0x14
	add r2, #1
	strb r1, [r0, #1]
	add r0, r5, #0
	mov r1, #0xe
	bl SetMonData
	add r2, sp, #0x14
	ldrb r1, [r6, #0x1a]
	add r0, sp, #0x14
	add r2, #1
	strb r1, [r0, #1]
	add r0, r5, #0
	mov r1, #0xf
	bl SetMonData
	add r2, sp, #0x14
	ldrb r1, [r6, #0x1b]
	add r0, sp, #0x14
	add r2, #1
	strb r1, [r0, #1]
	add r0, r5, #0
	mov r1, #0x10
	bl SetMonData
	add r2, sp, #0x14
	ldrb r1, [r6, #0x1c]
	add r0, sp, #0x14
	add r2, #1
	strb r1, [r0, #1]
	add r0, r5, #0
	mov r1, #0x11
	bl SetMonData
	add r2, sp, #0x14
	ldrb r1, [r6, #0x1d]
	add r0, sp, #0x14
	add r2, #1
	strb r1, [r0, #1]
	add r0, r5, #0
	mov r1, #0x12
	bl SetMonData
	add r2, r6, #0
	add r0, r5, #0
	mov r1, #0xa
	add r2, #0x20
	bl SetMonData
	add r2, r6, #0
	add r0, r5, #0
	mov r1, #9
	add r2, #0x21
	bl SetMonData
	ldr r0, [r6, #0x14]
	lsl r0, r0, #1
	lsr r0, r0, #0x1f
	beq _0222A2E4
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xed
	mov r3, #4
	bl NewMsgDataFromNarc
	ldrh r1, [r6]
	add r4, r0, #0
	lsl r1, r1, #0x15
	lsr r1, r1, #0x15
	bl NewString_ReadMsgData
	add r7, r0, #0
	add r0, r5, #0
	mov r1, #0x77
	add r2, r7, #0
	bl SetMonData
	add r0, r7, #0
	bl String_Delete
	add r0, r4, #0
	bl DestroyMsgData
	b _0222A2F0
_0222A2E4:
	add r2, r6, #0
	add r0, r5, #0
	mov r1, #0x75
	add r2, #0x22
	bl SetMonData
_0222A2F0:
	add r6, #0x1f
	add r0, r5, #0
	mov r1, #0xc
	add r2, r6, #0
	bl SetMonData
	add r0, r5, #0
	bl CalcMonLevelAndStats
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222A308: .word 0x3FFFFFFF
	thumb_func_end ov80_0222A140


	thumb_func_start ov80_0222A30C
ov80_0222A30C: ; 0x0222A30C
	ldr r3, _0222A32C ; =ov80_0223B628
	mov r2, #0
_0222A310:
	ldrh r1, [r3]
	cmp r0, r1
	bne _0222A31E
	ldr r0, _0222A330 ; =ov80_0223B62A
	lsl r1, r2, #2
	ldrh r0, [r0, r1]
	bx lr
_0222A31E:
	add r2, r2, #1
	add r3, r3, #4
	cmp r2, #0x3f
	blo _0222A310
	mov r0, #3
	bx lr
	nop
_0222A32C: .word ov80_0223B628
_0222A330: .word ov80_0223B62A
	thumb_func_end ov80_0222A30C

