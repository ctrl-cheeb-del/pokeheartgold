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
	.public ov68_021E7618
	.public ov68_021E7898
	.public ov68_021E7910
	.public ov68_021E797C


	thumb_func_start ov68_021E773C
ov68_021E773C: ; 0x021E773C
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #3
	bgt _021E7792
	ldr r1, [r5]
	strh r4, [r1, #0x14]
	ldr r2, [r5]
	ldrh r1, [r2, #0x16]
	ldrh r2, [r2, #0x14]
	add r3, r1, r2
	mov r2, #0x6e
	lsl r2, r2, #2
	ldrb r2, [r5, r2]
	cmp r3, r2
	bge _021E7778
	bl ov68_021E7A18
	add r0, r5, #0
	mov r1, #1
	bl ov68_021E7898
	add r0, r5, #0
	bl ov68_021E6BEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov68_021E68D4
	b _021E7884
_021E7778:
	mov r1, #5
	bl ov68_021E7A18
	add r0, r5, #0
	mov r1, #0
	bl ov68_021E7898
	mov r1, #1
	add r0, r5, #0
	mvn r1, r1
	bl ov68_021E68D4
	b _021E7884
_021E7792:
	cmp r4, #4
	bne _021E77E8
	ldr r0, _021E7894 ; =0x000005DD
	bl PlaySE
	ldr r1, [r5]
	ldrh r0, [r1, #0x16]
	ldrh r4, [r1, #0x14]
	add r0, r0, #1
	strh r0, [r1, #0x16]
	add r0, r5, #0
	bl ov68_021E6BEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov68_021E68D4
	add r0, r5, #0
	bl ov68_021E67E0
	add r0, r5, #0
	mov r1, #5
	bl ov68_021E7A18
	add r0, r5, #0
	mov r1, #0
	bl ov68_021E7898
	add r0, r5, #0
	bl ov68_021E7910
	add r0, r5, #0
	mov r1, #1
	bl ov68_021E797C
	mov r0, #0x72
	lsl r0, r0, #2
	lsl r1, r4, #0x18
	ldr r0, [r5, r0]
	lsr r1, r1, #0x18
	bl GridInputHandler_SetNextInput
	b _021E7884
_021E77E8:
	cmp r4, #5
	bne _021E7840
	ldr r0, _021E7894 ; =0x000005DD
	bl PlaySE
	ldr r1, [r5]
	ldrh r0, [r1, #0x16]
	ldrh r4, [r1, #0x14]
	sub r0, r0, #1
	strh r0, [r1, #0x16]
	add r0, r5, #0
	bl ov68_021E6BEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov68_021E68D4
	add r0, r5, #0
	bl ov68_021E67E0
	add r0, r5, #0
	mov r1, #5
	bl ov68_021E7A18
	add r0, r5, #0
	mov r1, #0
	bl ov68_021E7898
	add r0, r5, #0
	bl ov68_021E7910
	mov r1, #0
	add r0, r5, #0
	mvn r1, r1
	bl ov68_021E797C
	mov r0, #0x72
	lsl r0, r0, #2
	lsl r1, r4, #0x18
	ldr r0, [r5, r0]
	lsr r1, r1, #0x18
	bl GridInputHandler_SetNextInput
	b _021E7884
_021E7840:
	cmp r4, #6
	bne _021E786E
	mov r1, #5
	bl ov68_021E7A18
	add r0, r5, #0
	mov r1, #0
	bl ov68_021E7898
	mov r0, #0x73
	lsl r0, r0, #2
	ldrh r1, [r5, r0]
	cmp r1, #6
	beq _021E7884
	ldr r1, [r5]
	sub r0, r0, #4
	ldrh r4, [r1, #0x14]
	ldr r0, [r5, r0]
	lsl r1, r4, #0x18
	lsr r1, r1, #0x18
	bl GridInputHandler_SetNextInput
	b _021E7884
_021E786E:
	cmp r4, #7
	bne _021E7884
	ldr r0, [r5]
	ldrh r4, [r0, #0x14]
	mov r0, #0x72
	lsl r0, r0, #2
	lsl r1, r4, #0x18
	ldr r0, [r5, r0]
	lsr r1, r1, #0x18
	bl GridInputHandler_SetNextInput
_021E7884:
	lsl r1, r4, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #3
	bl ov68_021E73A4
	pop {r3, r4, r5, pc}
	nop
_021E7894: .word 0x000005DD
	thumb_func_end ov68_021E773C
