	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225E4B0
	.extern ov93_0225E0F4

	thumb_func_start ov93_0225E4B0
ov93_0225E4B0: ; 0x0225E4B0
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0225E538 ; =0x00002FD4
	mov r1, #0
	ldr r2, [r4, r0]
	cmp r2, #6
	bhi _0225E508
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_0225E4CA: ; jump table
	.short _0225E508 - _0225E4CA - 2 ; case 0
	.short _0225E4D8 - _0225E4CA - 2 ; case 1
	.short _0225E4DC - _0225E4CA - 2 ; case 2
	.short _0225E4E0 - _0225E4CA - 2 ; case 3
	.short _0225E4E4 - _0225E4CA - 2 ; case 4
	.short _0225E4F0 - _0225E4CA - 2 ; case 5
	.short _0225E4FC - _0225E4CA - 2 ; case 6
_0225E4D8:
	mov r1, #1
	b _0225E50C
_0225E4DC:
	mov r1, #1
	b _0225E50C
_0225E4E0:
	mov r1, #1
	b _0225E50C
_0225E4E4:
	sub r0, #8
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _0225E50C
	mov r1, #1
	b _0225E50C
_0225E4F0:
	ldr r0, _0225E53C ; =0x0000339C
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0225E50C
	mov r1, #1
	b _0225E50C
_0225E4FC:
	ldr r0, _0225E540 ; =0x00001768
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _0225E50C
	mov r1, #1
	b _0225E50C
_0225E508:
	mov r0, #0
	pop {r4, pc}
_0225E50C:
	cmp r1, #1
	bne _0225E534
	ldr r0, _0225E544 ; =0x00002FD8
	ldr r0, [r4, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl sub_02037AC0
	add r0, r4, #0
	bl ov93_0225E0F4
	cmp r0, #1
	bne _0225E52A
	mov r1, #7
	b _0225E52C
_0225E52A:
	mov r1, #0
_0225E52C:
	ldr r0, _0225E538 ; =0x00002FD4
	str r1, [r4, r0]
	mov r0, #1
	pop {r4, pc}
_0225E534:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_0225E538: .word 0x00002FD4
_0225E53C: .word 0x0000339C
_0225E540: .word 0x00001768
_0225E544: .word 0x00002FD8
	thumb_func_end ov93_0225E4B0
