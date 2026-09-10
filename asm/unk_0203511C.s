	.include "asm/macros.inc"
	.include "unk_02034B0C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0203511C
sub_0203511C: ; 0x0203511C
	push {r4, lr}
	bl sub_02037474
	cmp r0, #0
	bne _0203512A
	mov r0, #0
	pop {r4, pc}
_0203512A:
	ldr r1, _02035148 ; =_021D4134
	mov r0, #0
	ldr r4, [r1, #8]
	ldr r1, _0203514C ; =0x00000D44
	add r3, r0, #0
_02035134:
	ldrh r2, [r4, r1]
	cmp r2, #0
	beq _0203513C
	add r0, r0, #1
_0203513C:
	add r3, r3, #1
	add r4, r4, #2
	cmp r3, #0x10
	blt _02035134
	pop {r4, pc}
	nop
_02035148: .word _021D4134
_0203514C: .word 0x00000D44
	thumb_func_end sub_0203511C
	thumb_func_start sub_02035150
sub_02035150: ; 0x02035150
	push {r3, r4, r5, lr}
	ldr r1, _0203517C ; =_021D4134
	mov r4, #0
	ldr r5, [r1, #8]
	ldr r1, _02035180 ; =0x00000D44
	add r3, r4, #0
_0203515C:
	ldrh r2, [r5, r1]
	cmp r2, #0
	beq _0203516C
	cmp r4, r0
	bne _0203516A
	add r0, r3, #0
	pop {r3, r4, r5, pc}
_0203516A:
	add r4, r4, #1
_0203516C:
	add r3, r3, #1
	add r5, r5, #2
	cmp r3, #0x10
	blt _0203515C
	bl GF_AssertFail
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0203517C: .word _021D4134
_02035180: .word 0x00000D44
	thumb_func_end sub_02035150
