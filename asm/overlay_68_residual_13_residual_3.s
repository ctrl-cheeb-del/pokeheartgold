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
	.public ov68_021E7124
	.public ov68_021E7224
	.public ov68_021E734C


	thumb_func_start ov68_021E7288
ov68_021E7288: ; 0x021E7288
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bl NNS_G3dInit
	bl G3X_Init
	bl G3X_InitMtxStack
	ldr r1, _021E7330 ; =0x04000060
	ldr r2, _021E7334 ; =0xFFFFCFFD
	ldrh r0, [r1]
	and r0, r2
	strh r0, [r1]
	ldrh r3, [r1]
	ldr r0, _021E7338 ; =0x0000CFFB
	and r3, r0
	strh r3, [r1]
	add r3, r2, #2
	ldrh r5, [r1]
	add r2, r2, #2
	sub r0, #0x1c
	and r5, r3
	mov r3, #8
	orr r3, r5
	strh r3, [r1]
	ldrh r3, [r1]
	and r3, r2
	mov r2, #0x10
	orr r2, r3
	strh r2, [r1]
	ldrh r2, [r1]
	and r0, r2
	strh r0, [r1]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl G3X_SetFog
	mov r0, #0
	ldr r2, _021E733C ; =0x00007FFF
	add r1, r0, #0
	mov r3, #0x3f
	str r0, [sp]
	bl G3X_SetClearColor
	ldr r1, _021E7340 ; =0x04000540
	mov r0, #2
	str r0, [r1]
	ldr r0, _021E7344 ; =0xBFFF0000
	mov r2, #0x1c
	str r0, [r1, #0x40]
	mov r0, #0x55
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl MI_CpuFill8
	mov r0, #0x55
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0x42
	bl ov68_021E71C4
	ldr r1, [r4]
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r1, [r1]
	add r0, r4, r0
	mov r2, #0x42
	bl ov68_021E7224
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	ldr r1, _021E7348 ; =0x04000008
	mov r0, #3
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #1
	orr r0, r2
	strh r0, [r1]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E7330: .word 0x04000060
_021E7334: .word 0xFFFFCFFD
_021E7338: .word 0x0000CFFB
_021E733C: .word 0x00007FFF
_021E7340: .word 0x04000540
_021E7344: .word 0xBFFF0000
_021E7348: .word 0x04000008
	thumb_func_end ov68_021E7288


