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

	thumb_func_start ov68_021E7618
ov68_021E7618: ; 0x021E7618
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	mov r1, #0
	add r6, r2, #0
	bl ov68_021E7898
	add r0, r5, #0
	mov r1, #5
	bl ov68_021E7A18
	cmp r4, #3
	bgt _021E766A
	ldr r0, _021E7738 ; =0x000005DD
	bl PlaySE
	ldr r0, [r5]
	strh r4, [r0, #0x14]
	ldr r0, [r5]
	ldrh r1, [r0, #0x16]
	ldrh r0, [r0, #0x14]
	add r1, r1, r0
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r0, [r5, r0]
	cmp r1, r0
	bge _021E765E
	add r0, r5, #0
	bl ov68_021E6BEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov68_021E68D4
	b _021E7728
_021E765E:
	mov r1, #1
	add r0, r5, #0
	mvn r1, r1
	bl ov68_021E68D4
	b _021E7728
_021E766A:
	cmp r4, #6
	bne _021E7722
	cmp r6, #3
	bne _021E76C2
	ldr r0, [r5]
	ldrh r0, [r0, #0x16]
	add r1, r0, #4
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r0, [r5, r0]
	cmp r1, r0
	bge _021E76C2
	ldr r0, _021E7738 ; =0x000005DD
	bl PlaySE
	mov r0, #0x72
	lsl r0, r0, #2
	mov r4, #3
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl GridInputHandler_SetNextInput
	ldr r1, [r5]
	ldrh r0, [r1, #0x16]
	add r0, r0, #1
	strh r0, [r1, #0x16]
	add r0, r5, #0
	bl ov68_021E67E0
	add r0, r5, #0
	bl ov68_021E6BEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov68_021E68D4
	add r0, r5, #0
	bl ov68_021E7910
	add r0, r5, #0
	mov r1, #1
	bl ov68_021E797C
	b _021E7728
_021E76C2:
	cmp r6, #0
	bne _021E7710
	ldr r0, [r5]
	ldrh r0, [r0, #0x16]
	cmp r0, #0
	beq _021E7700
	ldr r0, _021E7738 ; =0x000005DD
	bl PlaySE
	ldr r1, [r5]
	ldrh r0, [r1, #0x16]
	sub r0, r0, #1
	strh r0, [r1, #0x16]
	add r0, r5, #0
	bl ov68_021E67E0
	add r0, r5, #0
	bl ov68_021E6BEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov68_021E68D4
	add r0, r5, #0
	bl ov68_021E7910
	mov r1, #0
	add r0, r5, #0
	mvn r1, r1
	bl ov68_021E797C
_021E7700:
	mov r0, #0x72
	lsl r0, r0, #2
	mov r4, #0
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl GridInputHandler_SetNextInput
	b _021E7728
_021E7710:
	ldr r0, _021E7738 ; =0x000005DD
	bl PlaySE
	mov r1, #1
	add r0, r5, #0
	mvn r1, r1
	bl ov68_021E68D4
	b _021E7728
_021E7722:
	ldr r0, _021E7738 ; =0x000005DD
	bl PlaySE
_021E7728:
	lsl r1, r4, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #3
	bl ov68_021E73A4
	pop {r4, r5, r6, pc}
	nop
_021E7738: .word 0x000005DD
	thumb_func_end ov68_021E7618


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


	thumb_func_start ov68_021E7898
ov68_021E7898: ; 0x021E7898
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	cmp r1, #1
	bne _021E78D6
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #7
	bl GridInputHandler_SetEnabledFlag
	add r0, r4, #0
	add r0, #0x88
	bl ScheduleWindowCopyToVram
	mov r0, #4
	str r0, [sp]
	mov r3, #8
	str r3, [sp, #4]
	mov r0, #0xc
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0xf
	mov r2, #0x14
	bl ov68_021E66A0
	ldr r0, _021E790C ; =0x000001CE
	mov r1, #1
	add sp, #0xc
	strh r1, [r4, r0]
	pop {r3, r4, pc}
_021E78D6:
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #7
	bl GridInputHandler_ClearEnabledFlag
	add r0, r4, #0
	add r0, #0x88
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #4
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #0xc
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0xf
	mov r2, #0x14
	mov r3, #8
	bl ov68_021E66A0
	mov r1, #0
	ldr r0, _021E790C ; =0x000001CE
	strh r1, [r4, r0]
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_021E790C: .word 0x000001CE
	thumb_func_end ov68_021E7898


	thumb_func_start ov68_021E7910
ov68_021E7910: ; 0x021E7910
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r1, [r4, r0]
	cmp r1, #4
	bhs _021E7936
	add r0, #0x10
	ldr r0, [r4, r0]
	mov r1, #4
	bl GridInputHandler_ClearEnabledFlag
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #5
	bl GridInputHandler_ClearEnabledFlag
	pop {r4, pc}
_021E7936:
	ldr r1, [r4]
	ldrh r1, [r1, #0x16]
	cmp r1, #0
	bne _021E794A
	add r0, #0x10
	ldr r0, [r4, r0]
	mov r1, #5
	bl GridInputHandler_ClearEnabledFlag
	b _021E7954
_021E794A:
	add r0, #0x10
	ldr r0, [r4, r0]
	mov r1, #5
	bl GridInputHandler_SetEnabledFlag
_021E7954:
	ldr r0, [r4]
	ldrh r0, [r0, #0x16]
	add r2, r0, #4
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r1, [r4, r0]
	cmp r2, r1
	blt _021E7970
	add r0, #0x10
	ldr r0, [r4, r0]
	mov r1, #4
	bl GridInputHandler_ClearEnabledFlag
	pop {r4, pc}
_021E7970:
	add r0, #0x10
	ldr r0, [r4, r0]
	mov r1, #4
	bl GridInputHandler_SetEnabledFlag
	pop {r4, pc}
	thumb_func_end ov68_021E7910


	thumb_func_start ov68_021E797C
ov68_021E797C: ; 0x021E797C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0x4a
	lsl r0, r0, #2
	add r4, r1, #0
	ldr r0, [r5, r0]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	mov r0, #0x49
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetAnimationFrame
	mov r0, #0x49
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetAnimationFrame
	cmp r4, #0
	ldr r0, [r5]
	ble _021E79EA
	ldrh r0, [r0, #0x16]
	add r2, r0, #4
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r1, [r5, r0]
	cmp r2, r1
	bge _021E79D2
	sub r0, #0x94
	ldr r0, [r5, r0]
	mov r1, #1
	bl ManagedSprite_SetAnim
	b _021E79DC
_021E79D2:
	sub r0, #0x94
	ldr r0, [r5, r0]
	mov r1, #3
	bl ManagedSprite_SetAnim
_021E79DC:
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #4
	bl ManagedSprite_SetAnim
	pop {r3, r4, r5, pc}
_021E79EA:
	ldrh r0, [r0, #0x16]
	cmp r0, #0
	bne _021E79FE
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #7
	bl ManagedSprite_SetAnim
	b _021E7A0A
_021E79FE:
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #5
	bl ManagedSprite_SetAnim
_021E7A0A:
	mov r0, #0x49
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetAnim
	pop {r3, r4, r5, pc}
	thumb_func_end ov68_021E797C


	thumb_func_start ov68_021E7A18
ov68_021E7A18: ; 0x021E7A18
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r7, r1, #0
	mov r6, #0
	mov r4, #4
_021E7A24:
	cmp r6, r7
	bne _021E7A44
	mov r0, #4
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #8
	lsl r2, r4, #0x18
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #0
	lsr r2, r2, #0x18
	mov r3, #0x10
	bl ov68_021E66A0
	b _021E7A82
_021E7A44:
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r0, [r5, r0]
	cmp r6, r0
	blo _021E7A6A
	mov r0, #4
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #4
	lsl r2, r4, #0x18
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #0
	lsr r2, r2, #0x18
	mov r3, #0x10
	bl ov68_021E66A0
	b _021E7A82
_021E7A6A:
	mov r0, #4
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	lsl r2, r4, #0x18
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #0
	lsr r2, r2, #0x18
	mov r3, #0x10
	bl ov68_021E66A0
_021E7A82:
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #4
	blo _021E7A24
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov68_021E7A18
