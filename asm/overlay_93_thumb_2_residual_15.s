	.include "asm/macros.inc"
	.include "overlay_93_thumb_2.inc"
	.include "global.inc"

	.text
	.public _02262C6C
	.public ov93_0225FBF0
	.public ov93_0225FCA4
	.public ov93_0225FD8C
	.public ov93_0225FE08
	.public ov93_0225FEC4
	.public ov93_0225FF1C
	.public ov93_0225FFF8
	.public ov93_02260080
	.public ov93_0226027C
	.public ov93_02260314
	.public ov93_02260608
	.public ov93_02260660
	.public ov93_02260908
	.public ov93_02260984
	.public ov93_02260A8C
	.public ov93_02260AD8
	.public ov93_02260BB0
	.public ov93_02260BF0
	.public ov93_02260CF8
	.public ov93_02260E1C
	.public ov93_02260F3C
	.public ov93_02260FB8
	.public ov93_022610B0
	.public ov93_02261164
	.public ov93_02261310
	.public ov93_02261354
	.public ov93_02261554
	.public ov93_02261744
	.public ov93_022618C4
	.public ov93_02261BBC
	.public ov93_02261C58
	.public ov93_02261D3C
	.public ov93_02261EB8
	.public ov93_02261FC8
	.public ov93_02262034
	.public ov93_02262098
	.public ov93_022620D4
	.public ov93_02262130
	.public ov93_02262250
	.public ov93_02262374
	.public ov93_0226249C
	.public ov93_02262540
	.public ov93_022625BC
	.public ov93_02262760
	.public ov93_022627C0
	.public ov93_02262C72
	.public ov93_02262C7A
	.public ov93_02262C82
	.public ov93_02262C8A
	.public ov93_02262C94
	.public ov93_02262CA4
	.public ov93_02262CB4
	.public ov93_02262CB6
	.public ov93_02262CC4
	.public ov93_02262CC5
	.public ov93_02262CC6
	.public ov93_02262CD8
	.public ov93_02262CEC
	.public ov93_02262CEE
	.public ov93_02262CF0
	.public ov93_02262D04
	.public ov93_02262D2C
	.public ov93_02262D54
	.public ov93_02262D7C
	.public ov93_02262DA4
	.public ov93_02262DCC
	.public ov93_02262E00
	.public ov93_02262E34
	.public ov93_02262E68
	.public ov93_02262E9C
	.public ov93_02262ED0
	.public ov93_02262F04
	.public ov93_02262F38
	.public ov93_02262F6C
	.public ov93_02262FA0
	.public ov93_02262FD4
	.public ov93_02263010
	.public ov93_022630D8
	.public ov93_022630E4
	.public ov93_02263114
	.public ov93_0225FC8C
	.public ov93_0225FDF4
	.public ov93_0225FE5C
	.public ov93_0225FE80
	.public ov93_0225FEAC
	.public ov93_022602E4
	.public ov93_022609E0
	.public ov93_02260A14
	.public ov93_02260A30
	.public ov93_02260A58
	.public ov93_02260B70
	.public ov93_02260B84
	.public ov93_02260F14
	.public ov93_02260F84
	.public ov93_0226114C
	.public ov93_022612E0
	.public ov93_022614F4
	.public ov93_02261528
	.public ov93_02261538
	.public ov93_0226154C
	.public ov93_02261C3C
	.public ov93_02261D1C
	.public ov93_02261FB0
	.public ov93_02262108
	.public ov93_02262230
	.public ov93_02262310
	.public ov93_02262338
	.public ov93_02262344
	.public ov93_02262368
	.public ov93_02262444
	.public ov93_02262484
	.public ov93_02262598
	.public ov93_022626E8
	.public ov93_022626FC
	.public ov93_02262710
	.public ov93_02262714
	.public ov93_02262718
	.public ov93_02262724
	.public ov93_0226273C
	.public ov93_02262748
	.public ov93_022627A4
	.public ov93_022627E8
	.public ov93_02262814
	.public ov93_02262830
	.public ov93_02262860
	.public ov93_02262884
	.public ov93_022628B8
	.public ov93_022628F4
	.public ov93_02262920
	.public ov93_02262934
	.public ov93_02262960
	.public ov93_0226297C
	.public ov93_022629A8
	.public ov93_022629B8
	.public ov93_022629E4

	thumb_func_start ov93_02261FC8
ov93_02261FC8: ; 0x02261FC8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	mov r7, #0
	add r5, r0, #0
_02261FD2:
	ldr r0, [sp]
	add r1, r0, r7
	mov r0, #6
	lsl r0, r0, #6
	ldrb r1, [r1, r0]
	cmp r1, #0x40
	bge _02261FEA
	mov r0, #0x40
	sub r6, r0, r1
	add r4, r6, #0
	sub r4, #0x50
	b _02262004
_02261FEA:
	cmp r1, #0x80
	bge _02261FFA
	mov r0, #0xa0
	sub r4, r0, r1
	sub r4, #0x10
	add r6, r4, #0
	sub r6, #0x50
	b _02262004
_02261FFA:
	sub r1, #0xa0
	mov r0, #0x40
	sub r6, r0, r1
	add r4, r6, #0
	sub r4, #0x50
_02262004:
	ldr r0, [r5, #4]
	add r1, sp, #8
	add r2, sp, #4
	bl sub_02013794
	mov r2, #0xa8
	ldr r0, [r5, #4]
	ldr r1, [sp, #8]
	sub r2, r2, r6
	bl sub_020136B4
	mov r2, #0xa8
	ldr r0, [r5, #0x18]
	ldr r1, [sp, #8]
	sub r2, r2, r4
	bl sub_020136B4
	add r7, r7, #1
	add r5, #0x28
	cmp r7, #6
	blt _02261FD2
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov93_02261FC8


	thumb_func_start ov93_02262034
ov93_02262034: ; 0x02262034
	push {r3, r4, r5, lr}
	ldr r0, _02262094 ; =0x0000019E
	add r4, r1, #0
	ldrsb r1, [r4, r0]
	cmp r1, #0
	ble _02262046
	sub r1, r1, #1
	strb r1, [r4, r0]
	pop {r3, r4, r5, pc}
_02262046:
	add r0, r0, #2
	ldrb r0, [r4, r0]
	cmp r0, #0
	beq _02262054
	cmp r0, #1
	beq _02262070
	pop {r3, r4, r5, pc}
_02262054:
	add r0, r4, #0
	bl ov93_02262108
	cmp r0, #1
	bne _02262066
	add r0, r4, #0
	bl ov93_022620D4
	pop {r3, r4, r5, pc}
_02262066:
	mov r0, #0x1a
	lsl r0, r0, #4
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
_02262070:
	add r0, r4, #0
	bl ov93_02262130
	add r5, r0, #0
	add r0, r4, #0
	bl ov93_02261FC8
	cmp r5, #1
	bne _02262092
	ldr r0, _02262094 ; =0x0000019E
	mov r1, #0xf
	strb r1, [r4, r0]
	add r1, r0, #2
	ldrb r1, [r4, r1]
	add r0, r0, #2
	sub r1, r1, #1
	strb r1, [r4, r0]
_02262092:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02262094: .word 0x0000019E
	thumb_func_end ov93_02262034


	thumb_func_start ov93_02262098
ov93_02262098: ; 0x02262098
	push {r3, r4, r5, r6, r7, lr}
	ldr r5, _022620D0 ; =0x000186A0
	add r7, r0, #0
	add r6, r1, #0
	mov r4, #0
_022620A2:
	add r0, r6, #0
	add r1, r5, #0
	bl _s32_div_f
	add r3, r0, #0
	mov r0, #0x63
	lsl r2, r3, #4
	add r1, r7, r4
	lsl r0, r0, #2
	strb r2, [r1, r0]
	add r0, r3, #0
	mul r0, r5
	sub r6, r6, r0
	add r0, r5, #0
	mov r1, #0xa
	bl _s32_div_f
	add r4, r4, #1
	add r5, r0, #0
	cmp r4, #6
	blt _022620A2
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022620D0: .word 0x000186A0
	thumb_func_end ov93_02262098


	thumb_func_start ov93_022620D4
ov93_022620D4: ; 0x022620D4
	push {r4, r5, r6, r7}
	mov r1, #0x66
	mov r5, #0
	lsl r1, r1, #2
	add r3, r5, #0
	sub r2, r1, #6
_022620E0:
	mov r6, #0x63
	add r4, r0, r5
	lsl r6, r6, #2
	ldrb r7, [r4, r6]
	sub r6, r6, #6
	strb r7, [r4, r6]
	mov r6, #5
	sub r6, r6, r5
	lsl r6, r6, #1
	strb r6, [r4, r1]
	add r5, r5, #1
	strb r3, [r4, r2]
	cmp r5, #6
	blt _022620E0
	ldr r1, _02262104 ; =0x0000019F
	strb r3, [r0, r1]
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
_02262104: .word 0x0000019F
	thumb_func_end ov93_022620D4
