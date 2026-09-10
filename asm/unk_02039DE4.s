	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02039DE4
sub_02039DE4: ; 0x02039DE4
	push {r3, lr}
	bl ov45_0222F254
	cmp r0, #1
	bne _02039DFC
	bl ov45_0222F70C
	ldr r0, _02039E24 ; =sub_02039E30
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02039DFC:
	add r0, sp, #0
	bl sub_02039D54
	ldr r0, [sp]
	cmp r0, #0
	beq _02039E22
	cmp r0, #0x14
	bne _02039E16
	ldr r0, _02039E28 ; =sub_02039DC4
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02039E16:
	bl ov45_0222F70C
	ldr r0, _02039E2C ; =sub_02039C60
	mov r1, #0
	bl sub_020381C0
_02039E22:
	pop {r3, pc}
	.balign 4, 0
_02039E24: .word sub_02039E30
_02039E28: .word sub_02039DC4
_02039E2C: .word sub_02039C60
	thumb_func_end sub_02039DE4
	thumb_func_start sub_02039E30
sub_02039E30: ; 0x02039E30
	push {r3, lr}
	mov r0, #1
	bl ov00_021E5E54
	cmp r0, #0
	bge _02039E46
	ldr r0, _02039E74 ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02039E46:
	bl sub_02039D08
	cmp r0, #0
	beq _02039E72
	mov r0, #0
	bl ov00_021E6BE4
	cmp r0, #0
	beq _02039E72
	bl ov00_021E6C68
	cmp r0, #0
	beq _02039E72
	bl sub_0203622C
	mov r0, #0
	bl sub_020378E4
	ldr r0, _02039E78 ; =sub_02039C60
	mov r1, #0
	bl sub_020381C0
_02039E72:
	pop {r3, pc}
	.balign 4, 0
_02039E74: .word sub_02038E90
_02039E78: .word sub_02039C60
	thumb_func_end sub_02039E30
