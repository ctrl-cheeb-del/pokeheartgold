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

	thumb_func_start ov68_021E74D8
ov68_021E74D8: ; 0x021E74D8
	push {r3, r4, lr}
	sub sp, #4
	ldr r2, _021E7560 ; =_021E7BE8
	add r1, sp, #0
	ldrb r3, [r2]
	ldrb r2, [r2, #1]
	add r4, r0, #0
	strb r3, [r1]
	strb r2, [r1, #1]
	bl ov68_021E5B14
	ldr r0, [r4]
	mov r1, #0x17
	ldr r0, [r0]
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r0, [r4]
	ldr r2, [r0, #8]
	add r0, r1, #4
	str r2, [r4, r0]
	add r0, r1, #0
	mov r2, #0
	add r0, #0x11
	strb r2, [r4, r0]
	add r0, r1, #0
	add r0, #0x14
	strb r2, [r4, r0]
	mov r0, #1
	add r1, #0x13
	strb r0, [r4, r1]
	add r0, r4, #0
	bl ov68_021E6BEC
	mov r1, #0x62
	lsl r1, r1, #2
	strh r0, [r4, r1]
	mov r2, #2
	sub r0, r1, #6
	strb r2, [r4, r0]
	add r0, r1, #0
	mov r2, #1
	add r0, #0x14
	str r2, [r4, r0]
	add r0, r1, #0
	mov r2, #0
	add r0, #0x10
	str r2, [r4, r0]
	add r0, r1, #0
	add r0, #0x18
	sub r1, #0x18
	str r2, [r4, r0]
	add r0, r4, r1
	add r1, sp, #0
	bl sub_02089D40
	mov r1, #0x17
	lsl r1, r1, #4
	ldr r0, _021E7564 ; =gOverlayTemplate_PokemonSummary
	add r1, r4, r1
	mov r2, #0x42
	bl OverlayManager_New
	mov r1, #0x6b
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0xc
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_021E7560: .word _021E7BE8
_021E7564: .word gOverlayTemplate_PokemonSummary
	thumb_func_end ov68_021E74D8


	thumb_func_start ov68_021E7568
ov68_021E7568: ; 0x021E7568
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl OverlayManager_Run
	cmp r0, #0
	beq _021E75B6
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl OverlayManager_Delete
	add r0, r4, #0
	bl ov68_021E5A58
	ldr r1, [r4]
	add r0, r4, #0
	ldrh r1, [r1, #0x14]
	bl ov68_021E7A18
	ldr r1, [r4]
	add r0, r4, #0
	ldrh r1, [r1, #0x14]
	mov r2, #3
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov68_021E73A4
	ldr r0, _021E75BC ; =0x00000186
	ldr r1, [r4]
	ldrb r2, [r4, r0]
	add r0, #0x2a
	strb r2, [r1, #0x1b]
	mov r1, #7
	str r1, [r4, r0]
	mov r0, #0
	pop {r4, pc}
_021E75B6:
	mov r0, #0xc
	pop {r4, pc}
	nop
_021E75BC: .word 0x00000186
	thumb_func_end ov68_021E7568


	thumb_func_start ov68_021E75C0
ov68_021E75C0: ; 0x021E75C0
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #0x42
	str r0, [sp, #8]
	ldr r0, _021E75F8 ; =ov68_021E7CF0
	ldr r1, _021E75FC ; =ov68_021E7D64
	ldr r2, _021E7600 ; =ov68_021E7C08
	add r3, r4, #0
	bl GridInputHandler_Create
	mov r1, #0x72
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r4, #0
	mov r1, #0
	bl ov68_021E7898
	add r0, r4, #0
	bl ov68_021E7910
	add sp, #0xc
	pop {r3, r4, pc}
	nop
_021E75F8: .word ov68_021E7CF0
_021E75FC: .word ov68_021E7D64
_021E7600: .word ov68_021E7C08
	thumb_func_end ov68_021E75C0
