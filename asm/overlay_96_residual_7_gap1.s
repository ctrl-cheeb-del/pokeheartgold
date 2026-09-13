	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	.public ov96_021E7658

	thumb_func_start ov96_021E7658
ov96_021E7658: ; 0x021E7658
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	str r1, [sp]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp]
	mov r4, #0
	lsl r0, r0, #1
	add r6, r5, r0
_021E766E:
	ldr r0, _021E7708 ; =0x00000614
	add r1, r4, #0
	ldr r0, [r5, r0]
	bl ov96_021E9370
	add r3, r0, #0
	lsl r0, r4, #3
	add r2, r6, r0
	ldrh r1, [r3, #0xa]
	ldr r0, _021E770C ; =0x000008B4
	strh r1, [r2, r0]
	ldr r1, [r3, #0xc]
	add r0, #0x20
	strh r1, [r2, r0]
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _021E766E
	mov r4, #0
_021E7696:
	ldr r0, _021E7708 ; =0x00000614
	add r1, r4, #0
	ldr r0, [r5, r0]
	bl ov96_021E94EC
	add r6, r0, #0
	ldr r0, [r6]
	cmp r0, r7
	beq _021E76B2
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _021E7696
_021E76B2:
	cmp r4, #4
	bne _021E76BC
	bl GF_AssertFail
	pop {r3, r4, r5, r6, r7, pc}
_021E76BC:
	ldrb r0, [r6, #9]
	cmp r0, #0
	bne _021E76D4
	ldr r0, [sp]
	mov r1, #1
	add r2, r5, r0
	ldr r0, _021E7710 ; =0x000008F4
	strb r1, [r2, r0]
	mov r1, #0
	add r0, r0, #4
	strb r1, [r2, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021E76D4:
	ldr r0, [sp]
	mov r2, #0
	add r1, r5, r0
	ldr r0, _021E7710 ; =0x000008F4
	strb r2, [r1, r0]
	ldr r0, _021E7708 ; =0x00000614
	mov r1, #3
	ldr r0, [r5, r0]
	bl ov96_021E94EC
	ldrb r1, [r0, #9]
	ldrb r0, [r6, #9]
	cmp r1, r0
	bne _021E76FC
	ldr r0, [sp]
	mov r2, #1
	add r1, r5, r0
	ldr r0, _021E7714 ; =0x000008F8
	strb r2, [r1, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021E76FC:
	ldr r0, [sp]
	mov r2, #0
	add r1, r5, r0
	ldr r0, _021E7714 ; =0x000008F8
	strb r2, [r1, r0]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E7708: .word 0x00000614
_021E770C: .word 0x000008B4
_021E7710: .word 0x000008F4
_021E7714: .word 0x000008F8
	thumb_func_end ov96_021E7658
