	.include "asm/macros.inc"
	.public _0225D5C0
	.public _0225D5C4
	.public _0225D5C8
	.public _0225D62C
	.public _0225D630
	.public _0225D796
	.public _0225D82C
	.public _0225D830
	.public _0225D980
	.public _0225D984
	.public _0225D99C
	.public _0225D9A0
	.public _0225D9D4
	.public _0225DA7C
	.public _0225DA80
	.public _0225DA84
	.public _0225DCB2
	.public _0225DCCC
	.public _0225DCD0
	.public _0225DD64
	.public _0225DDA0
	.public _0225DDA4
	.public _0225DDA8
	.public _0225DDDE
	.public _0225DDE6
	.public _0225DDF4
	.public _0225DE02
	.public _0225DE18
	.public _0225DE22
	.public _0225DE56
	.public _0225DE6C
	.public _0225DE8E
	.public _0225DEA0
	.public _0225DEA8
	.public _0225DEB2
	.public _0225DEBA
	.public _0225DEEA
	.public _0225DF0A
	.public _0225DF2A
	.public _0225DF3A
	.public _0225DF50
	.public _0225DF62
	.public _0225DF68
	.public _0225DF6C
	.public _0225DF70
	.public _0225DF74
	.public _0225DF78
	.public _0225DF7C
	.public _0225DFB0
	.public _0225DFBC
	.public _0225DFC6
	.public _0225DFCA
	.public _0225DFE4
	.public _0225E00C
	.public _0225E05E
	.public _0225E070
	.public _0225E092
	.public _0225E0A2
	.public _0225E0F4
	.public _0225E0F8
	.public _0225E158
	.public _0225E15C
	.public ov32_0225D520
	.public ov32_0225D60C
	.public ov32_0225D788
	.public ov32_0225D84C
	.public ov32_0225D988
	.public ov32_0225DA88
	.public ov32_0225DB1C
	.public ov32_0225DBAC
	.public ov32_0225DC0C
	.public ov32_0225DC68
	.public ov32_0225DD24
	.public ov32_0225DD74
	.public ov32_0225DDC4
	.public ov32_0225DE34
	.public ov32_0225DF9C
	.public ov32_0225DFE8
	.public ov32_0225E048
	.public ov32_0225E0A8
	.public ov32_0225E0FC
	.public ov32_0225E168
	.public ov32_0225E178
	.public ov32_0225E188
	.public ov32_0225E1A4
	.public ov32_0225E1C0
	.public ov32_0225E1DC
	.public ov32_0225E204
	.public ov32_0225E24C
	.public _0225E15C
	.public ov32_0225D520
	.public ov32_0225D5CC
	.public ov32_0225D608
	.public ov32_0225D60C
	.public ov32_0225D634
	.public ov32_0225D6C4
	.public ov32_0225D6E0
	.public ov32_0225D748
	.public ov32_0225D76C
	.public ov32_0225D788
	.public ov32_0225D834
	.public ov32_0225D84C
	.public ov32_0225D988
	.public ov32_0225DA88
	.public ov32_0225DAC0
	.public ov32_0225DADC
	.public ov32_0225DB00
	.public ov32_0225DB1C
	.public ov32_0225DBAC
	.public ov32_0225DC0C
	.public ov32_0225DC68
	.public ov32_0225DCD4
	.public ov32_0225DD04
	.public ov32_0225DD24
	.public ov32_0225DD74
	.public ov32_0225DDAC
	.public ov32_0225DDB8
	.public ov32_0225DDBC
	.public ov32_0225DDC4
	.public ov32_0225DE34
	.public ov32_0225DF80
	.public ov32_0225DF9C
	.public ov32_0225DFE8
	.public ov32_0225E048
	.public ov32_0225E0A8
	.public ov32_0225E0FC
	.include "overlay_32.inc"
	.include "global.inc"

	.text
	.public ov32_0225D5CC
	.public ov32_0225D608
	.public ov32_0225D634
	.public ov32_0225D6C4
	.public ov32_0225D6E0
	.public ov32_0225D748
	.public ov32_0225D76C
	.public ov32_0225D834
	.public ov32_0225DAC0
	.public ov32_0225DADC
	.public ov32_0225DB00
	.public ov32_0225DCD4
	.public ov32_0225DD04
	.public ov32_0225DDAC
	.public ov32_0225DDB8
	.public ov32_0225DDBC
	.public ov32_0225DF80

	thumb_func_start ov32_0225DF9C
ov32_0225DF9C: ; 0x0225DF9C
	push {r3, lr}
	ldr r2, _0225DFE4 ; =0x000002AA
	ldrsb r3, [r0, r2]
	add r3, r3, r1
	strb r3, [r0, r2]
	ldrsb r3, [r0, r2]
	cmp r3, #0
	bge _0225DFB0
	mov r3, #3
	strb r3, [r0, r2]
_0225DFB0:
	ldr r2, _0225DFE4 ; =0x000002AA
	ldrsb r3, [r0, r2]
	cmp r3, #3
	ble _0225DFBC
	mov r3, #0
	strb r3, [r0, r2]
_0225DFBC:
	cmp r1, #0
	ble _0225DFC6
	mov r2, #3
	mov r3, #6
	b _0225DFCA
_0225DFC6:
	mov r2, #2
	mov r3, #4
_0225DFCA:
	mov r1, #2
	str r1, [sp]
	lsl r1, r2, #0x18
	add r2, r3, #1
	lsl r2, r2, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl ov32_0225E0A8
	pop {r3, pc}
	nop
_0225DFE4: .word 0x000002AA
	thumb_func_end ov32_0225DF9C


	thumb_func_start ov32_0225DFE8
ov32_0225DFE8: ; 0x0225DFE8
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldrb r0, [r4, #0x1c]
	lsl r2, r0, #0x1f
	lsr r2, r2, #0x1f
	bne _0225E00C
	lsl r0, r0, #0x18
	lsr r0, r0, #0x19
	lsl r0, r0, #2
	add r2, r4, r0
	mov r0, #0xa6
	lsl r0, r0, #2
	ldr r0, [r2, r0]
	bl Sprite_SetAnimCtrlSeq
	add sp, #0xc
	pop {r3, r4, pc}
_0225E00C:
	add r0, r4, #0
	add r0, #0x22
	ldrb r0, [r0]
	add r2, r4, #0
	add r3, r4, #0
	str r0, [sp]
	add r0, r4, #0
	add r0, #0x23
	ldrb r0, [r0]
	add r2, #0x20
	add r3, #0x21
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldrb r1, [r4, #0x1c]
	ldrb r2, [r2]
	ldrb r3, [r3]
	lsl r1, r1, #0x18
	ldr r0, [r4]
	lsr r1, r1, #0x19
	bl BgTilemapRectChangePalette
	ldrb r1, [r4, #0x1c]
	ldr r0, [r4]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x19
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov32_0225DFE8


	thumb_func_start ov32_0225E048
ov32_0225E048: ; 0x0225E048
	push {r4, lr}
	add r4, r0, #0
	add r4, #0x1c
	ldrb r1, [r4, #2]
	cmp r1, #0
	beq _0225E05E
	cmp r1, #1
	beq _0225E070
	cmp r1, #2
	beq _0225E092
	b _0225E0A2
_0225E05E:
	ldrb r1, [r4, #1]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	bl ov32_0225DFE8
	ldrb r0, [r4, #2]
	add r0, r0, #1
	strb r0, [r4, #2]
	b _0225E0A2
_0225E070:
	ldrb r1, [r4, #3]
	add r1, r1, #1
	strb r1, [r4, #3]
	ldrb r1, [r4, #3]
	cmp r1, #4
	bne _0225E0A2
	ldrb r1, [r4, #1]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	bl ov32_0225DFE8
	mov r0, #0
	strb r0, [r4, #3]
	ldrb r0, [r4, #2]
	add r0, r0, #1
	strb r0, [r4, #2]
	b _0225E0A2
_0225E092:
	ldrb r0, [r4, #3]
	add r0, r0, #1
	strb r0, [r4, #3]
	ldrb r0, [r4, #3]
	cmp r0, #2
	bne _0225E0A2
	mov r0, #0
	pop {r4, pc}
_0225E0A2:
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov32_0225E048


	thumb_func_start ov32_0225E0A8
ov32_0225E0A8: ; 0x0225E0A8
	push {r4, r5}
	ldrb r5, [r0, #0x1c]
	mov r4, #1
	lsl r1, r1, #0x19
	bic r5, r4
	strb r5, [r0, #0x1c]
	mov r4, #0
	strb r4, [r0, #0x1f]
	strb r4, [r0, #0x1e]
	ldrb r5, [r0, #0x1c]
	mov r4, #0xfe
	lsr r1, r1, #0x18
	bic r5, r4
	orr r1, r5
	strb r1, [r0, #0x1c]
	ldrb r4, [r0, #0x1d]
	mov r1, #0xf
	bic r4, r1
	mov r1, #0xf
	and r1, r2
	orr r1, r4
	strb r1, [r0, #0x1d]
	ldrb r2, [r0, #0x1d]
	mov r1, #0xf0
	bic r2, r1
	lsl r1, r3, #0x1c
	lsr r1, r1, #0x18
	orr r1, r2
	strb r1, [r0, #0x1d]
	ldr r1, _0225E0F4 ; =0xFFFFFFF8
	add r1, sp
	ldrb r2, [r1, #0x10]
	ldr r1, _0225E0F8 ; =0x000002A9
	strb r2, [r0, r1]
	mov r0, #1
	pop {r4, r5}
	bx lr
	nop
_0225E0F4: .word 0xFFFFFFF8
_0225E0F8: .word 0x000002A9
	thumb_func_end ov32_0225E0A8


	thumb_func_start ov32_0225E0FC
ov32_0225E0FC: ; 0x0225E0FC
	push {r3, r4, r5, r6}
	ldrb r5, [r0, #0x1c]
	mov r4, #1
	bic r5, r4
	mov r4, #1
	orr r5, r4
	strb r5, [r0, #0x1c]
	mov r5, #0
	strb r5, [r0, #0x1f]
	strb r5, [r0, #0x1e]
	ldrb r6, [r0, #0x1c]
	mov r5, #0xfe
	bic r6, r5
	mov r5, #0xa
	orr r5, r6
	strb r5, [r0, #0x1c]
	ldrb r6, [r0, #0x1d]
	mov r5, #0xf
	bic r6, r5
	add r5, r6, #0
	orr r5, r4
	strb r5, [r0, #0x1d]
	ldrb r6, [r0, #0x1d]
	mov r5, #0xf0
	bic r6, r5
	add r5, r0, #0
	strb r6, [r0, #0x1d]
	add r5, #0x20
	strb r1, [r5]
	add r1, r0, #0
	add r1, #0x21
	strb r2, [r1]
	add r1, r0, #0
	mov r2, #0xc
	add r1, #0x22
	strb r2, [r1]
	add r1, r0, #0
	mov r2, #4
	add r1, #0x23
	strb r2, [r1]
	ldr r1, _0225E158 ; =0x000002A9
	strb r3, [r0, r1]
	add r0, r4, #0
	pop {r3, r4, r5, r6}
	bx lr
	nop
_0225E158: .word 0x000002A9
	thumb_func_end ov32_0225E0FC

	.rodata

_0225E15C:
	.byte 0xA0, 0xBF, 0x08, 0x27
	.byte 0xA0, 0xBF, 0x28, 0x47, 0xFF, 0x00, 0x00, 0x00

ov32_0225E168: ; 0x0225E168
	.word ov32_0225DDB8
	.word ov32_0225DDB8
	.word ov32_0225DDBC
	.word ov32_0225DDBC

ov32_0225E178: ; 0x0225E178
	.byte 0x20, 0x20, 0x00, 0x00, 0xD8, 0xB0, 0x01, 0x02
	.byte 0x18, 0xB0, 0x01, 0x04, 0x38, 0xB0, 0x01, 0x06

ov32_0225E188: ; 0x0225E188
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0D, 0x01, 0x00, 0x02, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

ov32_0225E1A4: ; 0x0225E1A4
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov32_0225E1C0: ; 0x0225E1C0
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x0E, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov32_0225E1DC: ; 0x0225E1DC
	.byte 0x08, 0x17, 0x18, 0x67
	.byte 0x08, 0x17, 0x98, 0xE7, 0x30, 0x3F, 0x18, 0x67, 0x30, 0x3F, 0x98, 0xE7, 0x58, 0x67, 0x18, 0x67
	.byte 0x58, 0x67, 0x98, 0xE7, 0x80, 0x8F, 0x18, 0x67, 0x80, 0x8F, 0x98, 0xE7, 0xA0, 0xBF, 0xB0, 0xFF
	.byte 0xFF, 0x00, 0x00, 0x00

ov32_0225E204: ; 0x0225E204
	.byte 0x40, 0x10, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0xC0, 0x10, 0x00, 0x00
	.byte 0x01, 0x03, 0x00, 0x01, 0x40, 0x38, 0x00, 0x00, 0x00, 0x04, 0x02, 0x03, 0xC0, 0x38, 0x00, 0x00
	.byte 0x01, 0x05, 0x02, 0x03, 0x40, 0x60, 0x00, 0x00, 0x02, 0x06, 0x04, 0x05, 0xC0, 0x60, 0x00, 0x00
	.byte 0x03, 0x07, 0x04, 0x05, 0x40, 0x88, 0x00, 0x00, 0x04, 0x08, 0x06, 0x07, 0xC0, 0x88, 0x00, 0x00
	.byte 0x05, 0x08, 0x06, 0x07, 0xD8, 0xB0, 0x00, 0x00, 0x87, 0x08, 0x08, 0x08

ov32_0225E24C: ; 0x0225E24C
	.byte 0x04, 0x17, 0x15, 0x08
	.byte 0x02, 0x02, 0x01, 0x00, 0x04, 0x0E, 0x15, 0x04, 0x02, 0x02, 0x11, 0x00, 0x04, 0x03, 0x01, 0x0A
	.byte 0x02, 0x02, 0x19, 0x00, 0x04, 0x13, 0x01, 0x0A, 0x02, 0x02, 0x2D, 0x00, 0x04, 0x03, 0x06, 0x0A
	.byte 0x02, 0x02, 0x41, 0x00, 0x04, 0x13, 0x06, 0x0A, 0x02, 0x02, 0x55, 0x00, 0x04, 0x03, 0x0B, 0x0A
	.byte 0x02, 0x02, 0x69, 0x00, 0x04, 0x13, 0x0B, 0x0A, 0x02, 0x02, 0x7D, 0x00, 0x04, 0x03, 0x10, 0x0A
	.byte 0x02, 0x02, 0x91, 0x00, 0x04, 0x13, 0x10, 0x0A, 0x02, 0x02, 0xA5, 0x00, 0x04, 0x03, 0x01, 0x0A
	.byte 0x02, 0x02, 0xB9, 0x00, 0x04, 0x13, 0x01, 0x0A, 0x02, 0x02, 0xCD, 0x00, 0x04, 0x03, 0x06, 0x0A
	.byte 0x02, 0x02, 0xE1, 0x00, 0x04, 0x13, 0x06, 0x0A, 0x02, 0x02, 0xF5, 0x00, 0x04, 0x03, 0x0B, 0x0A
	.byte 0x02, 0x02, 0x09, 0x01, 0x04, 0x13, 0x0B, 0x0A, 0x02, 0x02, 0x1D, 0x01, 0x04, 0x03, 0x10, 0x0A
	.byte 0x02, 0x02, 0x31, 0x01, 0x04, 0x13, 0x10, 0x0A, 0x02, 0x02, 0x45, 0x01
