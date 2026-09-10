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

	thumb_func_start ov68_021E6078
ov68_021E6078: ; 0x021E6078
	push {r4, r5, lr}
	sub sp, #0x14
	add r4, r0, #0
	add r0, sp, #0
	mov r1, #0
	mov r2, #0x14
	bl MI_CpuFill8
	ldr r0, [r4, #4]
	mov r3, #0x6d
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	mov r1, #0x1a
	add r0, sp, #0
	strb r1, [r0, #0x10]
	mov r1, #0xa
	strb r1, [r0, #0x11]
	ldrb r1, [r0, #0x12]
	mov r2, #0xf
	lsl r3, r3, #2
	bic r1, r2
	ldr r2, [r4, r3]
	sub r3, #0x9c
	lsl r2, r2, #0x18
	lsr r5, r2, #0x18
	mov r2, #0xf
	and r2, r5
	orr r1, r2
	strb r1, [r0, #0x12]
	ldrb r2, [r0, #0x12]
	mov r1, #0xf0
	bic r2, r1
	strb r2, [r0, #0x12]
	ldr r0, [r4, r3]
	add r1, sp, #0
	bl YesNoPrompt_InitFromTemplate
	mov r0, #1
	bl ov68_021E7BC8
	mov r0, #4
	add sp, #0x14
	pop {r4, r5, pc}
	thumb_func_end ov68_021E6078


	thumb_func_start ov68_021E60D8
ov68_021E60D8: ; 0x021E60D8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0x46
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	beq _021E60F0
	cmp r0, #2
	beq _021E6108
	b _021E6120
_021E60F0:
	ldr r1, _021E6140 ; =0x000001BA
	add r0, r5, #0
	ldrb r1, [r5, r1]
	lsl r2, r1, #3
	ldr r1, _021E6144 ; =ov68_021E7D3C
	ldr r1, [r1, r2]
	blx r1
	add r4, r0, #0
	mov r0, #0
	bl ov68_021E7BC8
	b _021E6124
_021E6108:
	ldr r1, _021E6140 ; =0x000001BA
	add r0, r5, #0
	ldrb r1, [r5, r1]
	lsl r2, r1, #3
	ldr r1, _021E6148 ; =ov68_021E7D40
	ldr r1, [r1, r2]
	blx r1
	add r4, r0, #0
	mov r0, #0
	bl ov68_021E7BC8
	b _021E6124
_021E6120:
	mov r0, #4
	pop {r3, r4, r5, pc}
_021E6124:
	mov r0, #0x46
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl YesNoPrompt_IsInTouchMode
	mov r1, #0x6d
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #0x9c
	ldr r0, [r5, r1]
	bl YesNoPrompt_Reset
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E6140: .word 0x000001BA
_021E6144: .word ov68_021E7D3C
_021E6148: .word ov68_021E7D40
	thumb_func_end ov68_021E60D8


	thumb_func_start ov68_021E614C
ov68_021E614C: ; 0x021E614C
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	bl ov68_021E6BEC
	str r0, [sp]
	ldr r1, [r4]
	add r2, sp, #0
	ldr r0, [r1]
	ldrb r1, [r1, #0x1b]
	add r1, #0x36
	bl SetMonData
	mov r0, #0
	str r0, [sp]
	ldr r1, [r4]
	add r2, sp, #0
	ldr r0, [r1]
	ldrb r1, [r1, #0x1b]
	add r1, #0x3e
	bl SetMonData
	add r0, r4, #0
	bl ov68_021E6BEC
	mov r1, #0
	bl GetMoveMaxPP
	str r0, [sp]
	ldr r1, [r4]
	add r2, sp, #0
	ldr r0, [r1]
	ldrb r1, [r1, #0x1b]
	add r1, #0x3a
	bl SetMonData
	ldr r0, [r4]
	mov r1, #0
	strb r1, [r0, #0x1a]
	mov r0, #8
	add sp, #4
	pop {r3, r4, pc}
	thumb_func_end ov68_021E614C
