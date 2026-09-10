	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02059F78
sub_02059F78: ; 0x02059F78
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x14]
	cmp r0, #0
	ble _02059F88
	sub r0, r0, #1
	str r0, [r4, #0x14]
	pop {r3, r4, r5, pc}
_02059F88:
	ldr r0, _02059FEC ; =_021D41CC
	ldr r1, [r0]
	add r1, r1, #1
	str r1, [r0]
	bl sub_02035878
	add r5, r0, #0
	bl sub_020376F8
	cmp r0, #0
	beq _02059FC8
	bl sub_02059F54
	cmp r0, #1
	bne _02059FC8
	ldrb r0, [r5, #0x1c]
	cmp r0, #4
	beq _02059FC8
	bl sub_02034434
	mov r0, #1
	add r1, r0, #0
	bl sub_020398D4
	mov r0, #0xb
	bl sub_0205A904
	ldr r1, _02059FF0 ; =sub_02059FF8
	add r0, r4, #0
	mov r2, #0
	bl sub_0205A034
_02059FC8:
	bl sub_02037FCC
	cmp r0, #0
	bne _02059FEA
	bl sub_02037FF0
	add r0, r4, #0
	bl sub_0205ABBC
	mov r0, #0
	bl sub_0205A904
	ldr r1, _02059FF4 ; =sub_02059F30
	add r0, r4, #0
	mov r2, #2
	bl sub_0205A034
_02059FEA:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02059FEC: .word _021D41CC
_02059FF0: .word sub_02059FF8
_02059FF4: .word sub_02059F30
	thumb_func_end sub_02059F78
	thumb_func_start sub_02059FF8
sub_02059FF8: ; 0x02059FF8
	push {r4, lr}
	add r4, r0, #0
	bl sub_02039918
	cmp r0, #0
	beq _0205A00C
	bl sub_020376F8
	cmp r0, #0
	beq _0205A02E
_0205A00C:
	bl sub_020376F8
	cmp r0, #0
	bne _0205A02E
	bl sub_02037FF0
	add r0, r4, #0
	bl sub_0205ABBC
	mov r0, #0
	bl sub_0205A904
	ldr r1, _0205A030 ; =sub_02059F30
	add r0, r4, #0
	mov r2, #2
	bl sub_0205A034
_0205A02E:
	pop {r4, pc}
	.balign 4, 0
_0205A030: .word sub_02059F30
	thumb_func_end sub_02059FF8
