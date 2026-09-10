	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0203981C
sub_0203981C: ; 0x0203981C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _02039864 ; =_021D4150
	ldr r0, [r0]
	cmp r0, #0
	bne _0203982C
	bl GF_AssertFail
_0203982C:
	bl sub_020392A0
	cmp r0, #1
	beq _02039838
	bl GF_AssertFail
_02039838:
	add r0, r4, #0
	bl ov45_0222F274
	cmp r0, #0
	bne _02039854
	add r0, r4, #0
	mov r1, #4
	bl ov45_0222F028
	ldr r0, _02039868 ; =sub_02039DE4
	mov r1, #0
	bl sub_020381C0
	pop {r4, pc}
_02039854:
	add r0, r4, #0
	bl ov45_0222F350
	ldr r0, _02039868 ; =sub_02039DE4
	mov r1, #0
	bl sub_020381C0
	pop {r4, pc}
	.balign 4, 0
_02039864: .word _021D4150
_02039868: .word sub_02039DE4
	thumb_func_end sub_0203981C
