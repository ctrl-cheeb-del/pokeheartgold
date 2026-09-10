	.include "asm/macros.inc"
	.include "unk_02032844.inc"
	.include "global.inc"

	.text
	thumb_func_start sub_02032E9C
sub_02032E9C: ; 0x02032E9C
	push {lr}
	sub sp, #0x24
	ldr r0, _02032EF8 ; =_021D4124
	ldr r1, [r0, #4]
	ldr r0, _02032EFC ; =0x00001310
	ldr r0, [r1, r0]
	sub r0, r0, #4
	cmp r0, #2
	bhi _02032EB4
	add sp, #0x24
	mov r0, #1
	pop {pc}
_02032EB4:
	mov r0, #3
	bl sub_02032844
	add r1, sp, #4
	ldr r0, _02032F00 ; =_0210F8FC
	add r1, #1
	mov r2, #3
	bl MI_CpuCopy8
	bl sub_0203993C
	add r1, sp, #4
	strb r0, [r1]
	mov r0, #0
	str r0, [sp]
	ldr r1, _02032EF8 ; =_021D4124
	ldr r0, _02032F04 ; =sub_02032F0C
	ldr r2, [r1, #4]
	ldr r1, _02032F08 ; =0x00001220
	mov r3, #1
	add r1, r2, r1
	add r2, sp, #4
	bl WM_StartConnectEx
	cmp r0, #2
	beq _02032EF2
	bl sub_02032858
	add sp, #0x24
	mov r0, #0
	pop {pc}
_02032EF2:
	mov r0, #1
	add sp, #0x24
	pop {pc}
	.balign 4, 0
_02032EF8: .word _021D4124
_02032EFC: .word 0x00001310
_02032F00: .word _0210F8FC
_02032F04: .word sub_02032F0C
_02032F08: .word 0x00001220
	thumb_func_end sub_02032E9C
	thumb_func_start sub_02032F0C
sub_02032F0C: ; 0x02032F0C
	push {r4, lr}
	add r4, r0, #0
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _02032F58
	bl sub_02032858
	ldrh r0, [r4, #2]
	cmp r0, #0xc
	bne _02032F28
	mov r0, #9
	bl sub_02032844
	pop {r4, pc}
_02032F28:
	cmp r0, #0xb
	bne _02032F34
	mov r0, #9
	bl sub_02032844
	pop {r4, pc}
_02032F34:
	cmp r0, #1
	bne _02032F50
	bl sub_02039918
	cmp r0, #0
	beq _02032F48
	mov r0, #9
	bl sub_02032844
	pop {r4, pc}
_02032F48:
	mov r0, #8
	bl sub_02032844
	pop {r4, pc}
_02032F50:
	mov r0, #9
	bl sub_02032844
	pop {r4, pc}
_02032F58:
	ldrh r0, [r4, #8]
	cmp r0, #8
	beq _02032FBE
	cmp r0, #7
	bne _02032F9E
	ldr r0, _02032FC0 ; =_021D4124
	ldr r1, [r0, #4]
	ldr r0, _02032FC4 ; =0x00001335
	ldrb r0, [r1, r0]
	cmp r0, #0
	beq _02032F7C
	mov r0, #0x14
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	pop {r4, pc}
_02032F7C:
	mov r0, #4
	bl sub_02032844
	bl sub_02032FCC
	cmp r0, #0
	bne _02032F92
	mov r0, #3
	bl sub_02032844
	pop {r4, pc}
_02032F92:
	ldr r0, _02032FC0 ; =_021D4124
	ldrh r2, [r4, #0xa]
	ldr r1, [r0, #4]
	ldr r0, _02032FC8 ; =0x0000132C
	strh r2, [r1, r0]
	pop {r4, pc}
_02032F9E:
	cmp r0, #6
	beq _02032FBE
	cmp r0, #9
	bne _02032FB4
	mov r0, #0x14
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	pop {r4, pc}
_02032FB4:
	cmp r0, #0x1a
	beq _02032FBE
	mov r0, #9
	bl sub_02032844
_02032FBE:
	pop {r4, pc}
	.balign 4, 0
_02032FC0: .word _021D4124
_02032FC4: .word 0x00001335
_02032FC8: .word 0x0000132C
	thumb_func_end sub_02032F0C
	thumb_func_start sub_02032FCC
sub_02032FCC: ; 0x02032FCC
	push {r4, lr}
	sub sp, #8
	ldr r0, _0203300C ; =_021D4124
	ldr r2, _02033010 ; =0x00001304
	ldr r4, [r0, #4]
	ldr r3, _02033014 ; =0x00001020
	ldr r0, [r4, r2]
	add r1, r4, r3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r2, r2, #4
	ldr r2, [r4, r2]
	sub r3, #0xe0
	lsl r2, r2, #0x10
	ldr r0, _02033018 ; =sub_0203301C
	lsr r2, r2, #0x10
	add r3, r4, r3
	bl WM_StartMP
	cmp r0, #2
	beq _02033006
	bl sub_02032858
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_02033006:
	mov r0, #1
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
_0203300C: .word _021D4124
_02033010: .word 0x00001304
_02033014: .word 0x00001020
_02033018: .word sub_0203301C
	thumb_func_end sub_02032FCC
	thumb_func_start sub_0203301C
sub_0203301C: ; 0x0203301C
	push {r3, lr}
	ldrh r1, [r0, #2]
	cmp r1, #0
	beq _0203303E
	cmp r1, #0xf
	beq _02033074
	cmp r1, #9
	beq _02033074
	cmp r1, #0xd
	beq _02033074
	add r0, r1, #0
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	pop {r3, pc}
_0203303E:
	ldrh r0, [r0, #4]
	sub r0, #0xa
	cmp r0, #3
	bhi _02033074
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02033052: ; jump table
	.short _0203305A - _02033052 - 2 ; case 0
	.short _02033074 - _02033052 - 2 ; case 1
	.short _02033074 - _02033052 - 2 ; case 2
	.short _02033074 - _02033052 - 2 ; case 3
_0203305A:
	ldr r0, _02033078 ; =_021D4124
	ldr r2, [r0, #4]
	ldr r0, _0203307C ; =0x00001314
	ldr r1, [r2, r0]
	cmp r1, #3
	bne _0203306E
	sub r0, r0, #4
	ldr r0, [r2, r0]
	cmp r0, #6
	beq _02033074
_0203306E:
	mov r0, #4
	bl sub_02032844
_02033074:
	pop {r3, pc}
	nop
_02033078: .word _021D4124
_0203307C: .word 0x00001314
	thumb_func_end sub_0203301C
