	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205A03C
sub_0205A03C: ; 0x0205A03C
	push {r3, r4, r5, r6, r7, lr}
	str r1, [sp]
	cmp r1, #0
	bne _0205A04A
	bl SysTask_Destroy
	pop {r3, r4, r5, r6, r7, pc}
_0205A04A:
	mov r7, #0x11
	ldr r5, _0205A078 ; =_021D41D8
	mov r6, #0
	add r4, r1, #0
	lsl r7, r7, #4
_0205A054:
	add r0, r6, #0
	bl sub_02035754
	mov r1, #0x11
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r0, [r4, r7]
	add r6, r6, #1
	add r4, r4, #4
	stmia r5!, {r0}
	cmp r6, #0x10
	blt _0205A054
	ldr r0, [sp]
	ldr r1, [r0, #0x10]
	cmp r1, #0
	beq _0205A076
	blx r1
_0205A076:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0205A078: .word _021D41D8
	thumb_func_end sub_0205A03C
