	.include "asm/macros.inc"
	.include "overlay_68.inc"
	.include "global.inc"

	.text
	.public MoveRelearner_Exit
	.public MoveRelearner_Init
	.public MoveRelearner_Main
	.public _021E7BE8
	.public ov68_021E5A58
	.public ov68_021E5BA0
	.public ov68_021E5BC0
	.public ov68_021E5D24
	.public ov68_021E5E48
	.public ov68_021E5F68
	.public ov68_021E6078
	.public ov68_021E60D8
	.public ov68_021E614C
	.public ov68_021E61B8
	.public ov68_021E6234
	.public ov68_021E62D4
	.public ov68_021E6320
	.public ov68_021E66A0
	.public ov68_021E66F0
	.public ov68_021E67E0
	.public ov68_021E6820
	.public ov68_021E68D4
	.public ov68_021E6A2C
	.public ov68_021E6C14
	.public ov68_021E6DDC
	.public ov68_021E6EB8
	.public ov68_021E7028
	.public ov68_021E70BC
	.public ov68_021E7124
	.public ov68_021E7178
	.public ov68_021E71C4
	.public ov68_021E7224
	.public ov68_021E7288
	.public ov68_021E734C
	.public ov68_021E73A4
	.public ov68_021E7424
	.public ov68_021E74D8
	.public ov68_021E7568
	.public ov68_021E75C0
	.public ov68_021E7618
	.public ov68_021E773C
	.public ov68_021E7898
	.public ov68_021E7910
	.public ov68_021E797C
	.public ov68_021E7A18
	.public ov68_021E7AD8
	.public ov68_021E7BC8
	.public ov68_021E7BEC
	.public ov68_021E7BF8
	.public ov68_021E7C08
	.public ov68_021E7C18
	.public ov68_021E7C2C
	.public ov68_021E7C44
	.public ov68_021E7C60
	.public ov68_021E7C7C
	.public ov68_021E7C98
	.public ov68_021E7CB4
	.public ov68_021E7CD0
	.public ov68_021E7CF0
	.public ov68_021E7D14
	.public ov68_021E7D3C
	.public ov68_021E7D40
	.public ov68_021E7D64
	.public ov68_021E7DA4
	.public ov68_021E7DFC
	.public ov68_021E7E74
	.public ov68_021E5B14
	.public ov68_021E5B6C
	.public ov68_021E5CD8
	.public ov68_021E5E38
	.public ov68_021E5E94
	.public ov68_021E5EBC
	.public ov68_021E5F18
	.public ov68_021E5F50
	.public ov68_021E6058
	.public ov68_021E61A0
	.public ov68_021E61EC
	.public ov68_021E6204
	.public ov68_021E6678
	.public ov68_021E68C4
	.public ov68_021E6BEC
	.public ov68_021E6BFC
	.public ov68_021E6C74
	.public ov68_021E6C8C
	.public ov68_021E6CD8
	.public ov68_021E6D00
	.public ov68_021E6D20
	.public ov68_021E6D40
	.public ov68_021E6D4C
	.public ov68_021E6D58
	.public ov68_021E6D64
	.public ov68_021E6D80
	.public ov68_021E6D9C
	.public ov68_021E6DB8
	.public ov68_021E6DD0
	.public ov68_021E6E84
	.public ov68_021E7388
	.public ov68_021E74C0
	.public ov68_021E7604
	.public ov68_021E7614
	.public ov68_021E7A90
	.public ov68_021E7AB4
	.public ov68_021E7B6C
	.public ov68_021E7B8C
	.public ov68_021E7B94

	thumb_func_start ov68_021E5F68
ov68_021E5F68: ; 0x021E5F68
	push {r3, r4, r5, lr}
	add r4, r0, #0
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl GridInputHandler_GetNextInput
	mov r1, #0x73
	lsl r1, r1, #2
	strh r0, [r4, r1]
	sub r0, r1, #4
	ldr r0, [r4, r0]
	bl GridInputHandler_HandleInput_AllowHold
	mov r1, #2
	add r5, r0, #0
	mvn r1, r1
	cmp r5, r1
	bhi _021E5FB8
	bhs _021E604E
	cmp r5, #7
	bhi _021E5FB0
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E5FA0: ; jump table
	.short _021E5FC8 - _021E5FA0 - 2 ; case 0
	.short _021E5FC8 - _021E5FA0 - 2 ; case 1
	.short _021E5FC8 - _021E5FA0 - 2 ; case 2
	.short _021E5FC8 - _021E5FA0 - 2 ; case 3
	.short _021E604E - _021E5FA0 - 2 ; case 4
	.short _021E604E - _021E5FA0 - 2 ; case 5
	.short _021E601E - _021E5FA0 - 2 ; case 6
	.short _021E603E - _021E5FA0 - 2 ; case 7
_021E5FB0:
	mov r0, #3
	mvn r0, r0
	cmp r5, r0
	b _021E604E
_021E5FB8:
	add r0, r1, #1
	cmp r5, r0
	bhi _021E5FC2
	beq _021E601E
	b _021E604E
_021E5FC2:
	add r0, r1, #2
	cmp r5, r0
	b _021E604E
_021E5FC8:
	bl System_GetTouchNew
	cmp r0, #0
	ldr r0, [r4]
	bne _021E5FF6
	ldrh r0, [r0, #0x16]
	add r1, r0, r5
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r0, [r4, r0]
	cmp r1, r0
	bhs _021E604E
	ldr r0, _021E6054 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	add r1, r5, #0
	bl ov68_021E7A18
	add r0, r4, #0
	bl ov68_021E7B94
	pop {r3, r4, r5, pc}
_021E5FF6:
	ldrh r0, [r0, #0x16]
	add r1, r0, r5
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r0, [r4, r0]
	cmp r1, r0
	bhs _021E6014
	ldr r0, _021E6054 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	add r1, r5, #0
	bl ov68_021E7A18
	b _021E604E
_021E6014:
	add r0, r4, #0
	mov r1, #5
	bl ov68_021E7A18
	b _021E604E
_021E601E:
	ldr r0, _021E6054 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	mov r1, #5
	bl ov68_021E7A18
	add r0, r4, #0
	mov r1, #0
	bl ov68_021E7898
	add r0, r4, #0
	mov r1, #0xe
	bl ov68_021E7A90
	pop {r3, r4, r5, pc}
_021E603E:
	ldr r0, _021E6054 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	mov r1, #0xf
	bl ov68_021E7AB4
	pop {r3, r4, r5, pc}
_021E604E:
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_021E6054: .word 0x000005DD
	thumb_func_end ov68_021E5F68
