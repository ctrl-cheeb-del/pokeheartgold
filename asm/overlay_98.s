	.include "asm/macros.inc"
	.public ov98_0221E5C0
	.public ov98_0221E5D0
	.public ov98_0221E5E0
	.public ov98_0221E684
	.public ov98_0221E6CC
	.public ov98_0221E6E0
	.public ov98_0221E6F0
	.public ov98_0221E784
	.public ov98_0221E7E8
	.public ov98_0221E8A8
	.public ov98_0221E970
	.public ov98_0221E9FC
	.public ov98_0221EA4C
	.public ov98_0221EAA8
	.public ov98_0221EABC
	.public ov98_0221EB84
	.public ov98_0221EBD8
	.public ov98_0221EBEC
	.public ov98_0221EC08
	.public ov98_0221EC24
	.public ov98_0221EC3C
	.public ov98_0221ECD0
	.public ov98_0221ED3C
	.public ov98_0221ED48
	.public ov98_0221EDA4
	.public ov98_0221EDC4
	.public ov98_0221EE28
	.public ov98_0221EE84
	.public ov98_0221EE9C
	.public ov98_0221EEDC
	.public ov98_0221EEEC
	.public ov98_0221EEFC
	.public ov98_0221EF14
	.public ov98_0221EF24
	.public ov98_0221EF64
	.public ov98_0221EF80
	.public ov98_0221EFA4
	.public ov98_0221EFB4
	.public ov98_0221EFE8
	.public ov98_0221F01C
	.public ov98_0221F024
	.public ov98_0221F058
	.public ov98_0221F090
	.public ov98_0221F0EC
	.public ov98_0221F120
	.public ov98_0221F150
	.public ov98_0221F174
	.public _0221F194
	.public ov98_0221F19C
	.public ov98_0221F1AC
	.public ov98_0221F1C0
	.public ov98_0221F1E0
	.public ov98_0221F1E4
	.public ov98_0221F1F8
	.public ov98_0221F220
	.public ov98_0221F248
	.include "overlay_98.inc"
	.include "global.inc"

	.text

	thumb_func_start ov98_0221E6F0
ov98_0221E6F0: ; 0x0221E6F0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	str r0, [sp]
	ldr r0, [sp, #0x58]
	add r5, r2, #0
	str r0, [sp, #0x58]
	ldr r0, [sp, #0x5c]
	add r4, r1, #0
	str r0, [sp, #0x5c]
	mov r0, #0
	add r2, sp, #8
	add r1, r0, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [r2]
	add r0, r3, #0
	str r3, [sp, #4]
	cmp r0, #0xa
	bls _0221E722
	bl GF_AssertFail
_0221E722:
	add r1, sp, #0x40
	mov r0, #0x14
	ldrsh r6, [r1, r0]
	ldr r0, [sp, #0x50]
	mov r7, #0
	lsl r0, r0, #2
	add r4, r4, r0
_0221E730:
	ldr r0, [sp, #4]
	cmp r7, r0
	bhs _0221E73A
	mov r1, #1
	b _0221E73C
_0221E73A:
	mov r1, #0
_0221E73C:
	add r0, sp, #8
	strh r1, [r0, #6]
	ldr r0, [r5]
	str r0, [sp, #0x1c]
	ldr r0, [r5, #4]
	str r0, [sp, #0x20]
	ldr r0, [r5, #8]
	str r0, [sp, #0x24]
	ldr r0, [r5, #0xc]
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x5c]
	cmp r0, #0
	beq _0221E75A
	mov r0, #1
	b _0221E75C
_0221E75A:
	mov r0, #2
_0221E75C:
	str r0, [sp, #0x18]
	add r0, sp, #8
	strh r6, [r0]
	ldr r1, [sp, #0x58]
	strh r1, [r0, #2]
	ldr r0, [sp]
	add r1, sp, #8
	bl ov98_0221E6E0
	mov r1, #1
	stmia r4!, {r0}
	bl ManagedSprite_SetAnimateFlag
	add r7, r7, #1
	add r6, #0x10
	cmp r7, #0xa
	blo _0221E730
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov98_0221E6F0
