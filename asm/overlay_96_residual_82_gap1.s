	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	thumb_func_start ov96_02200EF4
ov96_02200EF4: ; 0x02200EF4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r0, _02200F7C ; =0x000003E5
	add r5, r1, #0
	ldrb r1, [r5, r0]
	add r7, r2, #0
	mov r2, #4
	cmp r1, #4
	bne _02200F0A
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02200F0A:
	sub r1, r0, #3
	ldrb r1, [r5, r1]
	add r3, r1, #1
	sub r1, r0, #3
	strb r3, [r5, r1]
	sub r3, r0, #2
	ldrb r1, [r5, r1]
	ldrb r3, [r5, r3]
	cmp r1, r3
	blo _02200F2C
	add r1, r0, #0
	mov r3, #1
	sub r1, #9
	str r3, [r5, r1]
	mov r1, #0
	sub r0, r0, #3
	strb r1, [r5, r0]
_02200F2C:
	mov r1, #0xf7
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	cmp r0, #0
	beq _02200F76
	add r0, r1, #0
	add r0, #8
	add r1, r1, #5
	ldrb r0, [r5, r0]
	ldrb r1, [r5, r1]
	add r4, r0, r1
	cmp r4, r0
	bge _02200F4A
	bl GF_AssertFail
_02200F4A:
	lsl r2, r4, #0x18
	add r0, r6, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	add r3, r7, #0
	bl ov96_02200F84
	lsl r0, r4, #0x18
	lsr r2, r0, #0x18
	ldr r0, _02200F80 ; =0x000003E1
	ldrb r1, [r5, r0]
	add r1, r1, #1
	strb r1, [r5, r0]
	sub r1, r0, #1
	ldrb r3, [r5, r0]
	ldrb r1, [r5, r1]
	cmp r3, r1
	blo _02200F76
	mov r1, #0
	strb r1, [r5, r0]
	sub r0, r0, #5
	str r1, [r5, r0]
_02200F76:
	add r0, r2, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02200F7C: .word 0x000003E5
_02200F80: .word 0x000003E1
	thumb_func_end ov96_02200EF4

	thumb_func_start ov96_02200F84
ov96_02200F84: ; 0x02200F84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0xf8
	str r2, [sp, #0xc]
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	str r1, [sp, #8]
	lsl r0, r0, #4
	str r0, [sp, #0x14]
	ldr r0, [r1, r0]
	str r3, [sp, #0x10]
	add r1, r0, #0
	add r1, #0x9d
	ldrb r1, [r1]
	cmp r1, #0
	bne _02200FC0
	add r1, r0, #0
	add r1, #0x8b
	ldrb r2, [r1]
	mov r1, #0x1c
	mul r1, r2
	add r1, r0, r1
	add r1, #0x30
	ldrb r1, [r1]
	cmp r1, #2
	beq _02200FC0
	add r0, #0xa9
	ldrb r0, [r0]
	cmp r0, #0
	beq _02200FC2
_02200FC0:
	b _02201444
_02200FC2:
	mov r1, #0
	add r0, r1, #0
	add r2, sp, #0x4c
	str r0, [sp, #0x2c]
_02200FCA:
	ldr r0, [sp, #0x2c]
	add r1, r1, #1
	stmia r2!, {r0}
	cmp r1, #4
	blt _02200FCA
	ldr r7, [sp, #8]
	add r6, r0, #0
	add r5, sp, #0x5c
_02200FDA:
	add r3, r7, #0
	add r2, r5, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r4, [r5]
	add r0, sp, #0x44
	str r0, [sp]
	ldr r1, [r4, #0x7c]
	add r0, r4, #0
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	asr r1, r2, #0xc
	add r2, r4, #0
	add r0, #0x8b
	add r2, #0x80
	ldrb r0, [r0]
	ldr r3, [r2]
	asr r2, r3, #0xb
	lsl r0, r0, #2
	lsr r2, r2, #0x14
	add r2, r3, r2
	ldr r0, [r4, r0]
	asr r2, r2, #0xc
	add r3, sp, #0x48
	bl ov96_021EB0A4
	add r0, sp, #0x3c
	str r0, [sp]
	add r0, r4, #0
	add r0, #0x8b
	ldrb r0, [r0]
	ldr r1, [sp, #0x48]
	ldr r2, [sp, #0x44]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x40
	bl ov96_021EB03C
	ldr r1, [sp, #0x40]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	ldr r1, [sp, #0x3c]
	str r0, [r5, #8]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	ldr r1, [sp, #8]
	asr r0, r0, #0xc
	str r0, [r5, #0xc]
	add r4, r1, r6
	sub r0, #0x20
	mov r1, #0x28
	bl _s32_div_f
	mov r1, #0xa6
	lsl r1, r1, #2
	strb r0, [r4, r1]
	add r0, r1, #0
	ldrb r0, [r4, r0]
	cmp r0, #4
	bls _02201066
	bl GF_AssertFail
_02201066:
	add r6, r6, #1
	add r7, #0x10
	add r5, #0x10
	cmp r6, #4
	blt _02200FDA
	ldr r0, [sp, #0x14]
	add r1, sp, #0x5c
	add r0, r1, r0
	ldr r2, [sp, #8]
	str r0, [sp, #0x28]
	mov r4, #0
	add r3, sp, #0x9c
_0220107E:
	add r6, r2, #0
	add r6, #0x40
	ldmia r6!, {r0, r1}
	add r5, r3, #0
	stmia r5!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r5!, {r0, r1}
	ldr r0, [r6]
	add r4, r4, #1
	str r0, [r5]
	add r2, #0x14
	add r3, #0x14
	cmp r4, #0x1e
	blt _0220107E
	ldr r0, [sp, #0x28]
	ldr r1, [r0, #8]
	mov r0, #0x36
	lsl r0, r0, #4
	cmp r1, r0
	blt _022010D6
	mov r5, #0
	add r6, r5, #0
	add r4, sp, #0x5c
	sub r6, #0xa0
_022010AE:
	add r0, r4, #0
	add r0, #8
	add r1, r6, #0
	bl ov96_0220144C
	add r5, r5, #1
	add r4, #0x10
	cmp r5, #4
	blt _022010AE
	mov r5, #0
	add r4, sp, #0x9c
	mov r6, #0x50
_022010C6:
	add r0, r4, #4
	add r1, r6, #0
	bl ov96_0220144C
	add r5, r5, #1
	add r4, #0x14
	cmp r5, #0x1e
	blt _022010C6
_022010D6:
	ldr r4, [sp, #8]
	mov r5, #0
_022010DA:
	ldr r0, _02201308 ; =0x000002AE
	lsr r2, r5, #0x1f
	lsl r1, r5, #0x1e
	strh r5, [r4, r0]
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r1, r2, r1
	mov r0, #0x28
	add r6, r1, #0
	mul r6, r0
	ldr r0, [sp, #0x28]
	ldr r0, [r0, #8]
	add r0, #0x14
	add r1, r0, r6
	mov r0, #0xa7
	lsl r0, r0, #2
	str r1, [r4, r0]
	asr r0, r5, #1
	lsr r0, r0, #0x1e
	add r0, r5, r0
	asr r1, r0, #2
	mov r0, #0x28
	add r7, r1, #0
	mul r7, r0
	add r1, r7, #0
	mov r0, #0x2a
	add r1, #0x34
	lsl r0, r0, #4
	str r1, [r4, r0]
	bl LCRandom
	mov r1, #0x28
	bl _s32_div_f
	ldr r0, [sp, #0x28]
	ldr r0, [r0, #8]
	add r0, r0, r6
	add r1, r0, r1
	mov r0, #0xa9
	lsl r0, r0, #2
	str r1, [r4, r0]
	bl LCRandom
	mov r1, #0x28
	bl _s32_div_f
	add r7, #0x20
	mov r0, #0xaa
	add r1, r7, r1
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r5, r5, #1
	add r4, #0x14
	cmp r5, #0x10
	blt _022010DA
	ldr r2, _0220130C ; =ov96_0221C770
	ldr r3, [sp, #8]
	mov r4, #0
	add r0, r0, #4
_02201152:
	ldr r1, [r2]
	add r4, r4, #1
	strh r1, [r3, r0]
	add r2, r2, #4
	add r3, #0x14
	cmp r4, #0x10
	blt _02201152
	mov r0, #0x20
	str r0, [sp, #0x20]
	ldr r1, [sp, #8]
	ldr r0, [sp, #0xc]
	mov r6, #0
	add r0, r1, r0
	add r4, sp, #0x4c
	str r6, [sp, #0x24]
	str r0, [sp, #0x1c]
_02201172:
	ldr r0, [sp, #0x24]
	mov r1, #0x14
	mul r1, r0
	ldr r0, [sp, #8]
	mov r5, #0
	add r0, r0, r1
	add r7, sp, #0x5c
	str r0, [sp, #0x18]
_02201182:
	ldr r0, [sp, #0xc]
	cmp r5, r0
	beq _0220121A
	ldr r1, [sp, #0x28]
	ldr r0, [r7, #8]
	ldr r2, [r1, #8]
	add r1, r2, #0
	add r1, #0xa0
	cmp r1, r0
	blt _0220121A
	sub r0, r0, r2
	bmi _022011F2
	cmp r0, #0xa0
	bge _022011F2
	ldr r1, [sp, #8]
	add r2, r1, r5
	mov r1, #0xa6
	lsl r1, r1, #2
	ldrb r1, [r2, r1]
	cmp r6, r1
	bne _022011C4
	mov r1, #0xa6
	ldr r2, [sp, #0x1c]
	lsl r1, r1, #2
	ldrb r1, [r2, r1]
	cmp r6, r1
	ldr r1, [r4]
	bne _022011C0
	sub r1, r1, #4
	str r1, [r4]
	b _022011C4
_022011C0:
	sub r1, r1, #2
	str r1, [r4]
_022011C4:
	mov r1, #0x28
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	cmp r2, #4
	blo _022011D8
	bl GF_AssertFail
	b _0220121A
_022011D8:
	mov r0, #0x14
	add r1, r2, #0
	mul r1, r0
	ldr r0, [sp, #0x18]
	add r0, r0, r1
	mov r1, #0xab
	lsl r1, r1, #2
	ldrsh r1, [r0, r1]
	sub r2, r1, #3
	mov r1, #0xab
	lsl r1, r1, #2
	strh r2, [r0, r1]
	b _0220121A
_022011F2:
	mov r1, #0x4f
	mvn r1, r1
	cmp r0, r1
	blt _0220121A
	ldr r0, [sp, #8]
	add r1, r0, r5
	mov r0, #0xa6
	lsl r0, r0, #2
	ldrb r0, [r1, r0]
	cmp r6, r0
	bne _0220121A
	mov r0, #0xa6
	ldr r1, [sp, #0x1c]
	lsl r0, r0, #2
	ldrb r0, [r1, r0]
	cmp r6, r0
	bne _0220121A
	ldr r0, [r4]
	add r0, r0, #2
	str r0, [r4]
_0220121A:
	add r5, r5, #1
	add r7, #0x10
	cmp r5, #4
	blt _02201182
	mov r0, #0
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x20]
	add r2, sp, #0x9c
	add r0, #0x28
	mov ip, r0
	ldr r0, [sp, #0x28]
	add r3, sp, #0x4c
	ldr r5, [r0, #8]
_02201234:
	ldr r0, [r2]
	cmp r0, #0
	beq _02201280
	add r0, r5, #0
	ldr r1, [r2, #4]
	add r0, #0xa0
	cmp r0, r1
	blt _02201272
	sub r0, r1, r5
	cmp r0, #0
	ble _02201272
	cmp r0, #0xa0
	bgt _02201272
	ldr r7, [r2, #8]
	ldr r0, [r2, #0x10]
	add r1, r7, r0
	ldr r0, [sp, #0x20]
	cmp r0, r1
	bge _02201272
	mov r0, ip
	cmp r7, r0
	bge _02201272
	ldr r0, [r2, #0xc]
	cmp r0, #3
	ldr r0, [r3]
	bne _0220126E
	sub r0, r0, #1
	str r0, [r3]
	b _02201272
_0220126E:
	sub r0, r0, #6
	str r0, [r3]
_02201272:
	ldr r0, [sp, #0x30]
	add r2, #0x14
	add r0, r0, #1
	add r3, r3, #4
	str r0, [sp, #0x30]
	cmp r0, #0x1e
	blt _02201234
_02201280:
	ldr r0, [sp, #0x24]
	add r6, r6, #1
	add r0, r0, #4
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x20]
	add r4, r4, #4
	add r0, #0x28
	str r0, [sp, #0x20]
	cmp r6, #4
	bge _02201296
	b _02201172
_02201296:
	mov r5, #0xab
	lsl r5, r5, #2
	ldr r3, [sp, #8]
	mov r4, #0
	add r1, sp, #0x4c
	add r0, r5, #0
_022012A2:
	asr r6, r4, #1
	lsr r6, r6, #0x1e
	add r6, r4, r6
	asr r6, r6, #2
	lsl r6, r6, #2
	ldrsh r2, [r3, r5]
	ldr r6, [r1, r6]
	add r4, r4, #1
	add r2, r2, r6
	strh r2, [r3, r0]
	add r3, #0x14
	cmp r4, #0x10
	blt _022012A2
	ldr r1, _02201310 ; =0x00000A8C
	ldr r0, [sp, #0x10]
	cmp r0, r1
	bge _022012F0
	mov r2, #0
	mov r3, #0xab
	add r1, r2, #0
	mov r7, #0x14
	lsl r3, r3, #2
	mov r4, #0x28
	mov r5, #0x3c
_022012D2:
	add r6, r1, #0
	ldr r0, [sp, #8]
	mul r6, r7
	add r0, r0, r6
	add r0, r0, r3
	ldrsh r6, [r0, r4]
	add r2, r2, #1
	add r1, r1, #4
	add r6, r6, #3
	strh r6, [r0, #0x28]
	ldrsh r6, [r0, r5]
	add r6, r6, #3
	strh r6, [r0, #0x3c]
	cmp r2, #4
	blt _022012D2
_022012F0:
	ldr r0, [sp, #0x28]
	ldr r2, [r0]
	add r0, r2, #0
	add r0, #0x8b
	ldrb r1, [r0]
	mov r0, #0x1c
	mul r0, r1
	add r0, r2, r0
	ldr r0, [r0, #0x24]
	ldr r1, _02201314 ; =0x41A00000
	b _02201318
	nop
_02201308: .word 0x000002AE
_0220130C: .word ov96_0221C770
_02201310: .word 0x00000A8C
_02201314: .word 0x41A00000
_02201318:
	bl _fleq
	bhi _02201350
	mov r2, #0
	mov r3, #0xab
	add r1, r2, #0
	mov r7, #0x14
	lsl r3, r3, #2
	mov r4, #0x28
	mov r5, #0x3c
_0220132C:
	add r6, r1, #0
	ldr r0, [sp, #8]
	mul r6, r7
	add r0, r0, r6
	add r0, r0, r3
	ldrsh r6, [r0, r4]
	add r2, r2, #1
	add r1, r1, #4
	sub r6, r6, #2
	strh r6, [r0, #0x28]
	ldrsh r6, [r0, r5]
	sub r6, r6, #2
	strh r6, [r0, #0x3c]
	cmp r2, #4
	blt _0220132C
	ldr r0, [sp, #0x2c]
	add r0, #8
	str r0, [sp, #0x2c]
_02201350:
	ldr r0, [sp, #0x28]
	mov r1, #3
	ldr r4, [r0]
	add r0, r4, #0
	add r0, #0x8b
	ldrb r0, [r0]
	add r0, r0, #1
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r1, r0, #0x18
	mov r0, #0x1c
	mul r0, r1
	add r0, r4, r0
	add r0, #0x30
	ldrb r0, [r0]
	cmp r0, #1
	bne _0220137A
	ldr r0, [sp, #0x2c]
	sub r0, r0, #5
	str r0, [sp, #0x2c]
_0220137A:
	ldr r0, [sp, #8]
	bl ov96_0220146C
	add r4, r0, #0
	mov r0, #0x10
	ldrsh r1, [r4, r0]
	ldr r0, [sp, #0x2c]
	cmp r1, r0
	blt _0220140C
	mov r1, #0xf9
	ldr r0, [sp, #8]
	lsl r1, r1, #2
	ldrb r1, [r0, r1]
	ldr r0, [sp, #0xc]
	cmp r0, r1
	blo _02201444
	ldr r0, [sp, #0x28]
	ldr r2, [sp, #0x28]
	ldr r1, [r0]
	add r0, sp, #0x34
	str r0, [sp]
	add r0, r1, #0
	add r0, #0x8b
	ldrb r0, [r0]
	ldr r2, [r2, #0xc]
	add r3, sp, #0x38
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r1, [sp, #0x28]
	ldr r1, [r1, #8]
	bl ov96_021EB0A4
	ldr r0, [sp, #0x38]
	lsl r1, r0, #0xc
	ldr r0, [sp, #0x28]
	ldr r0, [r0]
	add r0, #0xb0
	str r1, [r0]
	ldr r0, [sp, #0x34]
	lsl r1, r0, #0xc
	ldr r0, [sp, #0x28]
	ldr r0, [r0]
	add r0, #0xb4
	str r1, [r0]
	ldr r1, [sp, #0x28]
	mov r0, #0
	ldr r1, [r1]
	add r1, #0xb8
	str r0, [r1]
	ldr r1, [r4, #8]
	lsl r2, r1, #0xc
	ldr r1, [sp, #0x28]
	ldr r1, [r1]
	add r1, #0xbc
	str r2, [r1]
	ldr r1, [r4, #0xc]
	lsl r2, r1, #0xc
	ldr r1, [sp, #0x28]
	ldr r1, [r1]
	add r1, #0xc0
	str r2, [r1]
	ldr r1, [sp, #0x28]
	ldr r1, [r1]
	add r1, #0xc4
	str r0, [r1]
	ldr r0, [sp, #0x28]
	add sp, #0x1fc
	ldr r0, [r0]
	mov r1, #1
	add r0, #0xaa
	strb r1, [r0]
	add sp, #0xf8
	pop {r4, r5, r6, r7, pc}
_0220140C:
	mov r1, #0xf9
	ldr r0, [sp, #8]
	lsl r1, r1, #2
	ldrb r1, [r0, r1]
	ldr r0, [sp, #0xc]
	cmp r0, r1
	blo _02201444
	ldr r0, [sp, #0x28]
	mov r1, #1
	ldr r0, [r0]
	mov r3, #7
	add r0, #0x9d
	strb r1, [r0]
	ldr r0, [sp, #0x28]
	ldr r0, [r0]
	add r0, #0x9e
	strb r1, [r0]
	ldr r0, [sp, #0x28]
	ldr r2, [r0]
	ldr r0, [sp, #4]
	str r1, [sp]
	add r1, r2, #0
	add r1, #0xd0
	add r2, #0x8b
	ldrb r1, [r1]
	ldrb r2, [r2]
	bl ov96_021E8228
_02201444:
	add sp, #0x1fc
	add sp, #0xf8
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02200F84
