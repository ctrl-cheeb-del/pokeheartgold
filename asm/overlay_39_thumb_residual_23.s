#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_39_thumb.inc"
	.include "global.inc"

	.text
	.public _0222AB80
	.public ov39_02227088
	.public ov39_022271CC
	.public ov39_02227208
	.public ov39_022272EC
	.public ov39_022273B0
	.public ov39_02227420
	.public ov39_022274D4
	.public ov39_02227534
	.public ov39_02227590
	.public ov39_022275E8
	.public ov39_02227648
	.public ov39_02227778
	.public ov39_022278D4
	.public ov39_02227A5C
	.public ov39_02227B24
	.public ov39_02227B5C
	.public ov39_02227D5C
	.public ov39_02227DE4
	.public ov39_02227DEC
	.public ov39_02227E8C
	.public ov39_02227F14
	.public ov39_02227FEC
	.public ov39_0222801C
	.public ov39_022280D4
	.public ov39_02228140
	.public ov39_02228308
	.public ov39_02228370
	.public ov39_02228418
	.public ov39_02228440
	.public ov39_022285CC
	.public ov39_022287F8
	.public ov39_022288A0
	.public ov39_02228964
	.public ov39_0222899C
	.public ov39_022289D0
	.public ov39_02228A34
	.public ov39_02228AC0
	.public ov39_02228B04
	.public ov39_02228BAC
	.public ov39_02228C78
	.public ov39_02228D0C
	.public ov39_02228DA0
	.public ov39_02228E54
	.public ov39_02228EC8
	.public ov39_02228F18
	.public ov39_02228F54
	.public ov39_02228FC8
	.public ov39_022290A4
	.public ov39_0222915C
	.public ov39_02229224
	.public ov39_0222A8B0
	.public ov39_0222A8B4
	.public ov39_0222A8C0
	.public ov39_0222A8D4
	.public ov39_0222A8E4
	.public ov39_0222A90C
	.public ov39_0222A944
	.public ov39_0222AA20
	.public ov39_02227060
	.public ov39_02227080
	.public ov39_02227188
	.public ov39_022271A4
	.public ov39_022271C0
	.public ov39_02227334
	.public ov39_02227348
	.public ov39_02227364
	.public ov39_0222738C
	.public ov39_022273F8
	.public ov39_0222748C
	.public ov39_022274B4
	.public ov39_022276A4
	.public ov39_022276E0
	.public ov39_02227720
	.public ov39_0222774C
	.public ov39_02227B1C
	.public ov39_02227B20
	.public ov39_02227B50
	.public ov39_02227B54
	.public ov39_02227B58
	.public ov39_02227D44
	.public ov39_02227D50
	.public ov39_02227DB8
	.public ov39_02227E3C
	.public ov39_02227E48
	.public ov39_02227E6C
	.public ov39_02227ECC
	.public ov39_02227EF4
	.public ov39_02227F60
	.public ov39_02227F74
	.public ov39_02227F84
	.public ov39_02227FA8
	.public ov39_02227FC4
	.public ov39_02227FFC
	.public ov39_022280B4
	.public ov39_02228120
	.public ov39_022285A8
	.public ov39_02228948
	.public ov39_02228A70
	.public ov39_02228A8C
	.public ov39_02228AA8
	.public ov39_02228B6C
	.public ov39_02228B74
	.public ov39_02228D90
	.public ov39_02228EA4
	.public ov39_0222908C

	thumb_func_start ov39_022290A4
ov39_022290A4: ; 0x022290A4
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x40]
	bl ov39_02228A70
	cmp r0, #1
	bne _022290BA
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_022290BA:
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #3
	bhi _02229152
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022290D0: ; jump table
	.short _022290D8 - _022290D0 - 2 ; case 0
	.short _022290FA - _022290D0 - 2 ; case 1
	.short _02229110 - _022290D0 - 2 ; case 2
	.short _02229136 - _022290D0 - 2 ; case 3
_022290D8:
	ldr r0, _02229158 ; =0x00000F0F
	add r3, r4, #0
	str r0, [sp]
	add r3, #0x90
	ldr r1, [r4, #0x2c]
	ldr r3, [r3]
	add r0, r4, #0
	mov r2, #0x1a
	bl ov39_02228B04
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02229152
_022290FA:
	bl ov00_021EC8D8
	bl sub_0203946C
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02229152
_02229110:
	bl sub_0203A914
	ldr r0, _02229158 ; =0x00000F0F
	add r3, r4, #0
	str r0, [sp]
	add r3, #0x90
	ldr r1, [r4, #0x2c]
	ldr r3, [r3]
	add r0, r4, #0
	mov r2, #0x1b
	bl ov39_02228B04
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r4, #0x94
	add r0, r0, #1
	str r0, [r4]
	b _02229152
_02229136:
	add r0, r4, #0
	add r0, #0x98
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x98
	str r1, [r0]
	add r0, r4, #0
	add r0, #0x98
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _02229152
	ldr r0, [r4, #0xc]
	str r0, [r4, #8]
_02229152:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02229158: .word 0x00000F0F
	thumb_func_end ov39_022290A4


	thumb_func_start ov39_0222915C
ov39_0222915C: ; 0x0222915C
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x60
	bl MI_CpuFill8
	ldr r0, [r5]
	mov r1, #0
	str r0, [r4]
	ldr r0, [r5, #4]
	add r2, r5, #0
	str r0, [r4, #4]
	ldr r0, [r5, #8]
	add r3, r4, #0
	str r0, [r4, #8]
	ldrh r0, [r5, #0xc]
	strh r0, [r4, #0xc]
_02229182:
	ldrh r0, [r2, #0x24]
	add r1, r1, #1
	add r2, r2, #2
	strh r0, [r3, #0xe]
	add r3, r3, #2
	cmp r1, #8
	blt _02229182
	mov r0, #0x34
	ldrsb r0, [r5, r0]
	mov r2, #0
	strb r0, [r4, #0x1e]
	add r0, r5, #0
	add r0, #0x35
	ldrb r0, [r0]
	strb r0, [r4, #0x1f]
	add r0, r5, #0
	add r0, #0x36
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x20
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0x37
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x21
	strb r1, [r0]
	ldr r0, [r5, #0x3c]
	add r1, r4, #0
	str r0, [r4, #0x24]
	add r0, r5, #0
	add r0, #0x40
	ldrh r0, [r0]
	strh r0, [r4, #0x28]
	add r0, r5, #0
	add r0, #0x42
	ldrh r0, [r0]
	strh r0, [r4, #0x2a]
	add r0, r5, #0
	add r0, #0x44
	ldrh r0, [r0]
	strh r0, [r4, #0x2c]
	add r0, r5, #0
	add r0, #0x46
	ldrh r0, [r0]
	strh r0, [r4, #0x2e]
	add r0, r5, #0
	add r0, #0x48
_022291E2:
	ldrb r6, [r0]
	add r3, r1, #0
	add r3, #0x30
	strb r6, [r3]
	add r3, r1, #0
	ldrb r6, [r0, #1]
	add r3, #0x31
	add r2, r2, #1
	strb r6, [r3]
	add r3, r1, #0
	ldrb r6, [r0, #2]
	add r3, #0x32
	strb r6, [r3]
	add r3, r1, #0
	ldrb r6, [r0, #3]
	add r3, #0x33
	add r0, r0, #4
	add r1, r1, #4
	strb r6, [r3]
	cmp r2, #0xa
	blt _022291E2
	add r0, r5, #0
	add r0, #0x70
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x58
	add r5, #0x71
	strb r1, [r0]
	ldrb r0, [r5]
	add r4, #0x59
	strb r0, [r4]
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov39_0222915C


	thumb_func_start ov39_02229224
ov39_02229224: ; 0x02229224
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	bl sub_0202B994
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r5]
	mov r1, #0
	str r0, [r4]
	ldr r0, [r5, #4]
	add r2, r5, #0
	str r0, [r4, #4]
	ldr r0, [r5, #8]
	add r3, r4, #0
	str r0, [r4, #8]
	ldrh r0, [r5, #0xc]
	strh r0, [r4, #0xc]
_0222924E:
	ldrh r0, [r2, #0xe]
	add r1, r1, #1
	add r2, r2, #2
	strh r0, [r3, #0x24]
	add r3, r3, #2
	cmp r1, #8
	blt _0222924E
	mov r0, #0x1e
	ldrsb r1, [r5, r0]
	add r0, r4, #0
	add r0, #0x34
	strb r1, [r0]
	add r0, r4, #0
	ldrb r1, [r5, #0x1f]
	add r0, #0x35
	mov r2, #0
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0x20
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x36
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0x21
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x37
	strb r1, [r0]
	ldr r0, [r5, #0x24]
	str r0, [r4, #0x3c]
	add r0, r4, #0
	ldrh r1, [r5, #0x28]
	add r0, #0x40
	strh r1, [r0]
	add r0, r4, #0
	ldrh r1, [r5, #0x2a]
	add r0, #0x42
	strh r1, [r0]
	add r0, r4, #0
	ldrh r1, [r5, #0x2c]
	add r0, #0x44
	strh r1, [r0]
	add r0, r4, #0
	ldrh r1, [r5, #0x2e]
	add r0, #0x46
	strh r1, [r0]
	add r0, r5, #0
	add r0, #0x30
	add r1, r4, #0
_022292B2:
	ldrb r6, [r0]
	add r3, r1, #0
	add r3, #0x48
	strb r6, [r3]
	add r3, r1, #0
	ldrb r6, [r0, #1]
	add r3, #0x49
	add r2, r2, #1
	strb r6, [r3]
	add r3, r1, #0
	ldrb r6, [r0, #2]
	add r3, #0x4a
	strb r6, [r3]
	add r3, r1, #0
	ldrb r6, [r0, #3]
	add r3, #0x4b
	add r0, r0, #4
	add r1, r1, #4
	strb r6, [r3]
	cmp r2, #0xa
	blt _022292B2
	add r0, r5, #0
	add r0, #0x58
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x70
	strb r1, [r0]
	add r5, #0x59
	add r0, r4, #0
	ldrb r1, [r5]
	add r0, #0x71
	mov r2, #0
	strb r1, [r0]
	ldr r0, _0222930C ; =0x0000FFFF
	add r1, r4, #0
_022292F8:
	add r2, r2, #1
	strh r0, [r1, #0xe]
	add r1, r1, #2
	cmp r2, #0xb
	blt _022292F8
	mov r0, #0
	add r4, #0x38
	strb r0, [r4]
	pop {r4, r5, r6, pc}
	nop
_0222930C: .word 0x0000FFFF
	thumb_func_end ov39_02229224

	.rodata

ov39_0222A8B0:
	.byte 0x00, 0x00, 0x00, 0x00

ov39_0222A8B4: ; 0x0222A8B4
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov39_0222A8C0
	.word ov39_0222A8B0

ov39_0222A8C0:
	.word ov39_02227348
	.word ov39_02227334
	.word ov39_02227364
	.word ov39_0222738C
	.byte 0x00, 0x00, 0x00, 0x00

ov39_0222A8D4: ; 0x0222A8D4
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

ov39_0222A8E4: ; 0x0222A8E4
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00

ov39_0222A90C: ; 0x0222A90C
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1F, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1E, 0x02, 0x00, 0x01, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

ov39_0222A944: ; 0x0222A944
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x1B, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x06, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00
	.byte 0x08, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00

	.data

ov39_0222AA20:
	.word ov39_02228BAC
	.word ov39_02228C78
	.word ov39_02228D0C
	.word ov39_02228D90
	.word ov39_02228DA0
	.word ov39_02228E54
	.word ov39_02228EA4
	.word ov39_02228EC8
	.word ov39_02228F18
	.word ov39_02228F18
	.word ov39_02228F54
	.word ov39_02228FC8
	.word ov39_0222908C
	.word ov39_022290A4

	.bss

_0222AB80:
	.space 0x4
