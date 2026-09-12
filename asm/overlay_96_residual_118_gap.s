	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	.public ov96_021EAF78
	.public ov96_022158EC
	.type ov96_02218688, @function

	thumb_func_start ov96_02218598
ov96_02218598: ; 0x02218598
	push {r4, r5, lr}
	sub sp, #0x34
	add r5, r0, #0
	add r4, r1, #0
	ldr r1, [r5, #0x50]
	ldr r0, [r4, #0x50]
	sub r1, r1, r0
	bpl _022185AA
	neg r1, r1
_022185AA:
	mov r0, #5
	lsl r0, r0, #0xc
	cmp r1, r0
	ble _022185B8
	add sp, #0x34
	mov r0, #0
	pop {r4, r5, pc}
_022185B8:
	add r0, sp, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	ldr r0, [r5, #4]
	ldr r1, [r5, #0x2c]
	ldr r0, [r0]
	ldr r2, [r5, #0x30]
	add r3, sp, #0x1c
	bl ov96_021EAF78
	add r0, sp, #0x14
	str r0, [sp]
	add r0, sp, #8
	str r0, [sp, #4]
	ldr r0, [r4, #4]
	ldr r1, [r4, #0x2c]
	ldr r0, [r0]
	ldr r2, [r4, #0x30]
	add r3, sp, #0x10
	bl ov96_021EAF78
	ldr r0, [r5, #0x14]
	cmp r0, #6
	bne _022185F0
	ldr r0, [sp, #0xc]
	add r0, #8
	str r0, [sp, #0xc]
_022185F0:
	ldr r0, [r4, #0x14]
	cmp r0, #6
	bne _022185FC
	ldr r0, [sp, #8]
	add r0, #8
	str r0, [sp, #8]
_022185FC:
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #8]
	add r2, sp, #0x28
	add r0, r1, r0
	lsl r4, r0, #0xc
	mov r0, #0
	str r0, [sp, #0x24]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	add r1, sp, #0x10
	bl VEC_Subtract
	add r0, sp, #0x28
	bl VEC_Mag
	cmp r0, r4
	bgt _02218624
	add sp, #0x34
	mov r0, #1
	pop {r4, r5, pc}
_02218624:
	mov r0, #0
	add sp, #0x34
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_02218598


	thumb_func_start ov96_0221862C
ov96_0221862C: ; 0x0221862C
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	bl ov96_02218688
	cmp r0, #0
	beq _02218676
	add r1, sp, #0
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r0, [r4, #0x60]
	add r4, #0x2c
	lsl r0, r0, #0xa
	lsr r0, r0, #0x1e
	lsl r0, r0, #0x18
	lsr r3, r0, #0x18
	add r2, r3, #0
	mov r0, #6
	mul r2, r0
	ldr r0, _0221867C ; =ov96_0221D708
	ldr r3, _02218680 ; =ov96_0221D70C
	ldrsh r0, [r0, r2]
	lsl r0, r0, #0xc
	str r0, [sp]
	ldr r0, _02218684 ; =ov96_0221D70A
	ldrsh r0, [r0, r2]
	ldrsh r2, [r3, r2]
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	add r0, r4, #0
	lsl r2, r2, #0xc
	bl ov96_022158EC
	add sp, #0xc
	pop {r3, r4, pc}
_02218676:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_0221867C: .word ov96_0221D708
_02218680: .word ov96_0221D70C
_02218684: .word ov96_0221D70A
	thumb_func_end ov96_0221862C
