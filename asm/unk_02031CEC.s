	.include "asm/macros.inc"
	.include "unk_02031B0C.inc"
	.include "global.inc"

	.text

	thumb_func_start sub_02031CEC
sub_02031CEC: ; 0x02031CEC
	push {r3, r4, r5, lr}
	add r5, r2, #0
	cmp r1, #9
	blt _02031CF6
	mov r1, #0
_02031CF6:
	cmp r1, #4
	bgt _02031D12
	ldr r0, _02031D68 ; =_020F6902
	lsl r2, r1, #3
	add r1, r0, r2
	ldrh r0, [r0, r2]
	strh r0, [r5]
	ldrh r0, [r1, #2]
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	strh r0, [r5, #4]
	ldrh r0, [r1, #6]
	strh r0, [r5, #6]
	b _02031D64
_02031D12:
	cmp r1, #7
	bgt _02031D44
	sub r1, r1, #5
	add r0, #0x38
	lsl r1, r1, #5
	add r4, r0, r1
	add r0, r4, #0
	bl sub_02031D80
	cmp r0, #0
	bne _02031D32
	add r0, r5, #0
	bl sub_02031B5C
	mov r0, #0
	pop {r3, r4, r5, pc}
_02031D32:
	ldrh r0, [r4]
	strh r0, [r5]
	ldrh r0, [r4, #2]
	strh r0, [r5, #2]
	ldrh r0, [r4, #4]
	strh r0, [r5, #4]
	ldrh r0, [r4, #6]
	strh r0, [r5, #6]
	b _02031D64
_02031D44:
	ldrb r1, [r0, #9]
	cmp r1, #0
	bne _02031D54
	add r0, r5, #0
	bl sub_02031B5C
	mov r0, #0
	pop {r3, r4, r5, pc}
_02031D54:
	ldrh r1, [r0, #0xc]
	strh r1, [r5]
	ldrh r1, [r0, #0xe]
	strh r1, [r5, #2]
	ldrh r1, [r0, #0x10]
	strh r1, [r5, #4]
	ldrh r0, [r0, #0x12]
	strh r0, [r5, #6]
_02031D64:
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02031D68: .word _020F6902
	thumb_func_end sub_02031CEC
