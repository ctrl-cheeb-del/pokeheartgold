	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02059820
sub_02059820: ; 0x02059820
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	str r0, [sp, #0x20]
	add r0, #0x54
	str r1, [sp, #0x14]
	str r0, [sp, #0x20]
	bl WindowIsInUse
	cmp r0, #0
	bne _020598EC
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xed
	mov r3, #4
	bl NewMsgDataFromNarc
	str r0, [sp, #0x18]
	bl sub_02070D90
	str r0, [sp, #0x1c]
	mov r0, #9
	str r0, [sp]
	mov r1, #0xa
	str r1, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, [r5, #0x24]
	ldr r1, [sp, #0x20]
	ldr r0, [r0, #8]
	mov r2, #3
	mov r3, #0x15
	bl AddWindowParameterized
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, [r5, #0x24]
	mov r1, #3
	ldr r0, [r0, #8]
	mov r2, #1
	mov r3, #0xb
	bl LoadUserFrameGfx1
	ldr r0, [sp, #0x20]
	mov r1, #0xf
	bl FillWindowPixelBuffer
	mov r7, #0
	add r6, r7, #0
	add r4, r7, #0
_0205988E:
	ldr r0, [r5, #0x48]
	mov r1, #5
	add r0, r0, r6
	mov r2, #0
	bl GetMonData
	add r1, r0, #0
	ldr r0, [sp, #0x18]
	ldr r2, [r5, #0xc]
	bl ReadMsgDataIntoString
	str r4, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x20]
	ldr r2, [r5, #0xc]
	mov r1, #0
	mov r3, #0x10
	bl AddTextPrinterParameterized
	ldr r0, [sp, #0x1c]
	add r7, r7, #1
	add r6, r6, r0
	add r4, #0x10
	cmp r7, #3
	blt _0205988E
	ldr r0, [r5, #0x2c]
	ldr r2, [r5, #0xc]
	mov r1, #0x15
	bl ReadMsgDataIntoString
	lsl r0, r7, #4
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	ldr r0, [sp, #0x20]
	ldr r2, [r5, #0xc]
	mov r3, #0x10
	bl AddTextPrinterParameterized
	ldr r0, [sp, #0x18]
	bl DestroyMsgData
_020598EC:
	mov r0, #0x10
	str r0, [sp]
	ldr r0, [sp, #0x20]
	mov r2, #0
	ldrb r0, [r0, #8]
	mov r1, #0xf
	add r3, r2, #0
	lsl r0, r0, #0x13
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	ldr r0, [sp, #0x20]
	bl FillWindowPixelRect
	ldr r3, [sp, #0x14]
	add r1, r5, #0
	ldr r0, [r5, #0x78]
	add r1, #0x54
	mov r2, #0
	lsl r3, r3, #4
	bl ListMenuUpdateCursorObj
	add r0, r5, #0
	add r0, #0x54
	mov r1, #0
	mov r2, #1
	mov r3, #0xb
	bl DrawFrameAndWindow1
	add r1, r5, #0
	ldr r0, [sp, #0x14]
	add r1, #0x81
	strb r0, [r1]
	add r0, r5, #0
	mov r1, #4
	add r0, #0x80
	strb r1, [r0]
	ldr r0, [sp, #0x20]
	str r0, [r5, #0x7c]
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	thumb_func_end sub_02059820
	thumb_func_start sub_0205993C
sub_0205993C: ; 0x0205993C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r7, r5, #0
	add r7, #0x64
	add r0, r7, #0
	str r1, [sp, #0x14]
	bl WindowIsInUse
	cmp r0, #0
	bne _020599BE
	mov r0, #0xb
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x5a
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x24]
	add r1, r7, #0
	ldr r0, [r0, #8]
	mov r2, #3
	mov r3, #0x14
	bl AddWindowParameterized
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, [r5, #0x24]
	mov r1, #3
	ldr r0, [r0, #8]
	mov r2, #1
	mov r3, #0xb
	bl LoadUserFrameGfx1
	add r0, r7, #0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	mov r6, #0
	add r4, r6, #0
_02059994:
	add r1, r6, #0
	ldr r0, [r5, #0x2c]
	ldr r2, [r5, #0xc]
	add r1, #0x16
	bl ReadMsgDataIntoString
	str r4, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r2, [r5, #0xc]
	add r0, r7, #0
	mov r1, #0
	mov r3, #0x10
	bl AddTextPrinterParameterized
	add r6, r6, #1
	add r4, #0x10
	cmp r6, #3
	blt _02059994
_020599BE:
	add r0, r5, #0
	mov r1, #3
	add r0, #0x80
	strb r1, [r0]
	add r1, r5, #0
	ldr r0, [sp, #0x14]
	str r7, [r5, #0x7c]
	add r1, #0x81
	strb r0, [r1]
	mov r0, #0x10
	str r0, [sp]
	ldrb r0, [r7, #8]
	mov r2, #0
	mov r1, #0xf
	lsl r0, r0, #0x13
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	add r0, r7, #0
	add r3, r2, #0
	bl FillWindowPixelRect
	ldr r3, [sp, #0x14]
	ldr r0, [r5, #0x78]
	ldr r1, [r5, #0x7c]
	mov r2, #0
	lsl r3, r3, #4
	bl ListMenuUpdateCursorObj
	ldr r0, [r5, #0x7c]
	mov r1, #0
	mov r2, #1
	mov r3, #0xb
	bl DrawFrameAndWindow1
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0205993C
	thumb_func_start sub_02059A08
sub_02059A08: ; 0x02059A08
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	ldr r0, _02059AD0 ; =gSystem
	mov r1, #0x40
	ldr r0, [r0, #0x48]
	tst r1, r0
	beq _02059A32
	mov r0, #0x81
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _02059A28
	add r0, r4, #0
	add r0, #0x80
	ldrb r0, [r0]
	b _02059A28
_02059A28:
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x81
	strb r1, [r0]
	b _02059A94
_02059A32:
	mov r1, #0x80
	tst r1, r0
	beq _02059A56
	mov r0, #0x81
	ldrsb r1, [r4, r0]
	add r0, r4, #0
	add r0, #0x80
	ldrb r0, [r0]
	sub r0, r0, #1
	cmp r1, r0
	bne _02059A4C
	mov r1, #0
	b _02059A4E
_02059A4C:
	add r1, r1, #1
_02059A4E:
	add r0, r4, #0
	add r0, #0x81
	strb r1, [r0]
	b _02059A94
_02059A56:
	mov r1, #1
	tst r1, r0
	beq _02059A7C
	ldr r0, _02059AD4 ; =0x000005DC
	bl PlaySE
	mov r0, #0x81
	ldrsb r1, [r4, r0]
	add r4, #0x80
	ldrb r0, [r4]
	sub r0, r0, #1
	cmp r1, r0
	bge _02059A76
	add sp, #8
	mov r0, #1
	pop {r4, pc}
_02059A76:
	add sp, #8
	mov r0, #2
	pop {r4, pc}
_02059A7C:
	mov r1, #2
	tst r0, r1
	beq _02059A8E
	ldr r0, _02059AD4 ; =0x000005DC
	bl PlaySE
	add sp, #8
	mov r0, #2
	pop {r4, pc}
_02059A8E:
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_02059A94:
	ldr r0, _02059AD4 ; =0x000005DC
	bl PlaySE
	ldr r0, [r4, #0x7c]
	mov r1, #0x10
	str r1, [sp]
	ldrb r1, [r0, #8]
	mov r2, #0
	add r3, r2, #0
	lsl r1, r1, #0x13
	lsr r1, r1, #0x10
	str r1, [sp, #4]
	mov r1, #0xf
	bl FillWindowPixelRect
	mov r3, #0x81
	ldrsb r3, [r4, r3]
	ldr r0, [r4, #0x78]
	ldr r1, [r4, #0x7c]
	mov r2, #0
	lsl r3, r3, #4
	bl ListMenuUpdateCursorObj
	ldr r0, [r4, #0x7c]
	bl CopyWindowPixelsToVram_TextMode
	mov r0, #0
	add sp, #8
	pop {r4, pc}
	nop
_02059AD0: .word gSystem
_02059AD4: .word 0x000005DC
	thumb_func_end sub_02059A08
