	.include "asm/macros.inc"
	.include "overlay_108.inc"
	.include "global.inc"

	.text
	.public _021EA720
	.public ov108_021E5C54
	.public ov108_021E5D0C
	.public ov108_021E5DB8
	.public ov108_021E5E68
	.public ov108_021E5F38
	.public ov108_021E6090
	.public ov108_021E62B4
	.public ov108_021E63B8
	.public ov108_021E6450
	.public ov108_021E64C0
	.public ov108_021E66AC
	.public ov108_021E6894
	.public ov108_021E69A0
	.public ov108_021E6A58
	.public ov108_021E6B00
	.public ov108_021E6BA0
	.public ov108_021E6C68
	.public ov108_021E6D24
	.public ov108_021E6D80
	.public ov108_021E6F74
	.public ov108_021E7014
	.public ov108_021E7080
	.public ov108_021E7224
	.public ov108_021E733C
	.public ov108_021E756C
	.public ov108_021E767C
	.public ov108_021E7700
	.public ov108_021E77D4
	.public ov108_021E78F4
	.public ov108_021E79A8
	.public ov108_021E7ADC
	.public ov108_021E7B74
	.public ov108_021E7BB4
	.public ov108_021E7C5C
	.public ov108_021E7CD8
	.public ov108_021E7EB0
	.public ov108_021E7F7C
	.public ov108_021E80F4
	.public ov108_021E81A8
	.public ov108_021E8270
	.public ov108_021E82E0
	.public ov108_021E84F8
	.public ov108_021E8540
	.public ov108_021E867C
	.public ov108_021E8758
	.public ov108_021EA724
	.public ov108_021EA738
	.public ov108_021EA748
	.public ov108_021EA74A
	.public ov108_021EA760
	.public ov108_021EA780
	.public ov108_021EA7A8
	.public ov108_021EA7D0
	.public ov108_021EA7F8
	.public ov108_021EA820
	.public ov108_021EA848
	.public ov108_021EA870
	.public ov108_021EA898
	.public ov108_021EA978
	.public ov108_021EA97C
	.public ov108_021EA98C
	.public ov108_021EA9A0

	.public SafariAreaCustomizer_Exit
	.public SafariAreaCustomizer_Init
	.public SafariAreaCustomizer_Main
	.public ov108_021E59E4
	.public ov108_021E5A48
	.public ov108_021E5A78
	.public ov108_021E5A8C
	.public ov108_021E5AA0
	.public ov108_021E5AF0
	.public ov108_021E5B48
	.public ov108_021E5B98
	.public ov108_021E5BFC
	.public ov108_021E5D90
	.public ov108_021E5F10
	.public ov108_021E6010
	.public ov108_021E6068
	.public ov108_021E61E8
	.public ov108_021E6238
	.public ov108_021E6240
	.public ov108_021E6804
	.public ov108_021E6850
	.public ov108_021E6C48
	.public ov108_021E6F58
	.public ov108_021E71EC
	.public ov108_021E72A4
	.public ov108_021E72CC
	.public ov108_021E730C
	.public ov108_021E7510
	.public ov108_021E7650
	.public ov108_021E78C0
	.public ov108_021E7BFC
	.public ov108_021E838C
	.public ov108_021E83C8
	.public ov108_021E83F0
	.public ov108_021E844C
	.public ov108_021E846C
	.public ov108_021E8490
	.public ov108_021E84A4
	.public ov108_021E84DC
	.public ov108_021E852C
	.public ov108_021E853C
	.public ov108_021E8674
	.public ov108_021E8718

	thumb_func_start ov108_021E6894
ov108_021E6894: ; 0x021E6894
	push {r3, r4, r5, r6, r7, lr}
	ldr r1, _021E698C ; =gSystem
	add r5, r0, #0
	ldr r4, [r1, #0x48]
	mov r1, #2
	tst r1, r4
	beq _021E68B4
	bl ov108_021E6850
	mov r0, #2
	str r0, [r5, #0xc]
	ldr r0, _021E6990 ; =0x000005DC
	bl PlaySE
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_021E68B4:
	mov r0, #1
	tst r0, r4
	beq _021E68E8
	ldr r0, _021E6994 ; =0x000184E0
	ldrb r1, [r5, r0]
	cmp r1, #6
	bhs _021E68CA
	sub r0, r0, #1
	ldrb r0, [r5, r0]
	cmp r0, r1
	bne _021E68DE
_021E68CA:
	add r0, r5, #0
	bl ov108_021E6850
	mov r0, #2
	str r0, [r5, #0xc]
	ldr r0, _021E6990 ; =0x000005DC
	bl PlaySE
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_021E68DE:
	ldr r0, _021E6998 ; =0x0000069C
	bl PlaySE
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_021E68E8:
	mov r0, #0xf0
	tst r0, r4
	bne _021E68F2
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E68F2:
	ldr r0, _021E6994 ; =0x000184E0
	mov r1, #3
	ldrb r6, [r5, r0]
	add r0, r6, #0
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r7, r0, #0x18
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, #2
	bhs _021E6938
	mov r0, #0x10
	tst r0, r4
	beq _021E6926
	add r0, r7, #1
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r7, r0, #0x18
	b _021E6938
_021E6926:
	mov r0, #0x20
	tst r0, r4
	beq _021E6938
	add r0, r7, #2
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r7, r0, #0x18
_021E6938:
	mov r0, #0x40
	tst r0, r4
	beq _021E694C
	add r0, r6, #2
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	b _021E695E
_021E694C:
	mov r0, #0x80
	tst r0, r4
	beq _021E695E
	add r0, r6, #1
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
_021E695E:
	lsl r0, r6, #1
	add r0, r6, r0
	add r1, r7, r0
	ldr r0, _021E6994 ; =0x000184E0
	cmp r6, #2
	strb r1, [r5, r0]
	blo _021E6976
	ldr r0, _021E698C ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #0xc0
	tst r0, r1
	beq _021E697C
_021E6976:
	ldr r0, _021E699C ; =0x000005E5
	bl PlaySE
_021E697C:
	ldr r2, _021E6994 ; =0x000184E0
	add r0, r5, #0
	ldrb r2, [r5, r2]
	mov r1, #0
	bl ov108_021E78F4
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E698C: .word gSystem
_021E6990: .word 0x000005DC
_021E6994: .word 0x000184E0
_021E6998: .word 0x0000069C
_021E699C: .word 0x000005E5
	thumb_func_end ov108_021E6894


	thumb_func_start ov108_021E69A0
ov108_021E69A0: ; 0x021E69A0
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	ldr r0, _021E6A3C ; =ov108_021EA760
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _021E69BA
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_021E69BA:
	cmp r0, #6
	bne _021E6A00
	ldr r1, _021E6A40 ; =0x0000FFFE
	add r0, sp, #4
	strh r1, [r0]
	add r0, sp, #4
	str r0, [sp]
	ldr r3, _021E6A44 ; =gSystem + 0x40
	mov r0, #0xd
	lsl r0, r0, #6
	ldrh r2, [r3, #0x20]
	ldrh r3, [r3, #0x22]
	ldr r0, [r4, r0]
	mov r1, #3
	bl DoesPixelAtScreenXYMatchPtrVal
	cmp r0, #0
	bne _021E69E4
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_021E69E4:
	ldr r0, _021E6A48 ; =0x000184E0
	mov r1, #6
	strb r1, [r4, r0]
	add r0, r4, #0
	bl ov108_021E6850
	mov r0, #2
	str r0, [r4, #0xc]
	ldr r0, _021E6A4C ; =0x000005DC
	bl PlaySE
	add sp, #8
	mov r0, #4
	pop {r4, pc}
_021E6A00:
	ldr r2, _021E6A50 ; =0x000184DF
	ldrb r1, [r4, r2]
	cmp r1, r0
	bne _021E6A1E
	add r0, r4, #0
	bl ov108_021E6850
	mov r0, #2
	str r0, [r4, #0xc]
	ldr r0, _021E6A4C ; =0x000005DC
	bl PlaySE
	add sp, #8
	mov r0, #4
	pop {r4, pc}
_021E6A1E:
	add r1, r2, #1
	strb r0, [r4, r1]
	add r2, r2, #1
	ldrb r2, [r4, r2]
	add r0, r4, #0
	mov r1, #0
	bl ov108_021E78F4
	ldr r0, _021E6A54 ; =0x0000069C
	bl PlaySE
	mov r0, #3
	add sp, #8
	pop {r4, pc}
	nop
_021E6A3C: .word ov108_021EA760
_021E6A40: .word 0x0000FFFE
_021E6A44: .word gSystem + 0x40
_021E6A48: .word 0x000184E0
_021E6A4C: .word 0x000005DC
_021E6A50: .word 0x000184DF
_021E6A54: .word 0x0000069C
	thumb_func_end ov108_021E69A0


	thumb_func_start ov108_021E6A58
ov108_021E6A58: ; 0x021E6A58
	push {r4, r5, lr}
	sub sp, #0x24
	add r4, r0, #0
	add r0, sp, #0xc
	mov r1, #0
	mov r2, #0x18
	bl MI_CpuFill8
	ldr r0, _021E6AE8 ; =_021EA720
	add r2, sp, #0xc
	ldrh r3, [r0, #0xc]
	ldr r5, _021E6AEC ; =ov108_021EA748
	add r1, sp, #0xc
	strh r3, [r2]
	ldrh r3, [r0, #0xe]
	strh r3, [r2, #2]
	ldrh r3, [r0, #0x10]
	strh r3, [r2, #4]
	ldrh r3, [r0, #0x12]
	strh r3, [r2, #6]
	ldrh r3, [r0, #0x14]
	ldrh r0, [r0, #0x16]
	strh r3, [r2, #8]
	strh r0, [r2, #0xa]
	ldr r0, _021E6AF0 ; =0x000004B4
	ldr r0, [r4, r0]
	str r0, [sp, #0x18]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r3, [r4, r0]
	add r0, r0, #4
	str r3, [sp, #0x1c]
	mov r3, #3
	strb r3, [r2, #0x14]
	ldr r2, _021E6AF4 ; =0x000184DF
	ldrb r2, [r4, r2]
	lsl r3, r2, #2
	ldr r2, _021E6AF8 ; =ov108_021EA74A
	ldrh r2, [r2, r3]
	ldrh r3, [r5, r3]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	str r2, [sp]
	mov r2, #0
	str r2, [sp, #4]
	str r2, [sp, #8]
	ldr r2, [r4, #0x10]
	lsl r3, r3, #0x18
	lsl r2, r2, #0x18
	ldr r0, [r4, r0]
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl TouchscreenListMenu_Create
	ldr r1, _021E6AFC ; =0x000004BC
	ldr r2, _021E6AF4 ; =0x000184DF
	str r0, [r4, r1]
	mov r1, #1
	ldrb r2, [r4, r2]
	add r0, r4, #0
	add r3, r1, #0
	bl ov108_021E79A8
	ldr r2, _021E6AF4 ; =0x000184DF
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #4
	mov r3, #1
	bl ov108_021E79A8
	add sp, #0x24
	pop {r4, r5, pc}
	.balign 4, 0
_021E6AE8: .word _021EA720
_021E6AEC: .word ov108_021EA748
_021E6AF0: .word 0x000004B4
_021E6AF4: .word 0x000184DF
_021E6AF8: .word ov108_021EA74A
_021E6AFC: .word 0x000004BC
	thumb_func_end ov108_021E6A58


	thumb_func_start ov108_021E6B00
ov108_021E6B00: ; 0x021E6B00
	push {r4, r5, lr}
	sub sp, #0x14
	add r4, r0, #0
	add r0, sp, #0
	mov r1, #0
	mov r2, #0x14
	bl MI_CpuFill8
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r1, [r4, r0]
	add r0, #0x39
	str r1, [sp]
	mov r1, #0
	str r0, [sp, #8]
	mov r0, #0xd
	str r1, [sp, #4]
	str r0, [sp, #0xc]
	mov r0, #0x1a
	add r2, sp, #0
	strb r0, [r2, #0x10]
	mov r0, #0x10
	strb r0, [r2, #0x11]
	ldrb r0, [r2, #0x12]
	mov r1, #0xf
	bic r0, r1
	ldr r1, [r4, #0x10]
	lsl r1, r1, #0x18
	lsr r3, r1, #0x18
	mov r1, #0xf
	and r1, r3
	orr r0, r1
	strb r0, [r2, #0x12]
	ldrb r1, [r2, #0x12]
	mov r0, #0xf0
	bic r1, r0
	mov r0, #0x13
	strb r1, [r2, #0x12]
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	add r1, sp, #0
	bl YesNoPrompt_InitFromTemplate
	ldr r2, _021E6B98 ; =0x000184E0
	mov r1, #1
	ldrb r2, [r4, r2]
	add r0, r4, #0
	add r3, r1, #0
	bl ov108_021E79A8
	ldr r3, _021E6B9C ; =0x000184DF
	add r0, r4, #0
	add r2, r3, #1
	ldrb r1, [r4, r3]
	sub r3, r3, #1
	ldrb r5, [r4, r3]
	mov r3, #6
	ldrb r2, [r4, r2]
	mul r3, r5
	add r2, r2, r3
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	bl ov108_021E7BB4
	add r0, r4, #0
	mov r1, #1
	bl ov108_021E767C
	mov r1, #1
	add r0, r4, #0
	mov r2, #3
	add r3, r1, #0
	bl ov108_021E7700
	add sp, #0x14
	pop {r4, r5, pc}
	.balign 4, 0
_021E6B98: .word 0x000184E0
_021E6B9C: .word 0x000184DF
	thumb_func_end ov108_021E6B00


	thumb_func_start ov108_021E6BA0
ov108_021E6BA0: ; 0x021E6BA0
	push {r4, lr}
	add r4, r0, #0
	bl ov108_021E8490
	ldr r3, _021E6C34 ; =0x000184E2
	ldrb r0, [r4, r3]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _021E6C16
	mov r0, #0xd
	add r3, r3, #2
	lsl r0, r0, #6
	ldrsh r3, [r4, r3]
	ldr r0, [r4, r0]
	mov r1, #1
	mov r2, #3
	bl BgSetPosTextAndCommit
	ldr r3, _021E6C38 ; =0x000184E4
	mov r0, #0xd
	lsl r0, r0, #6
	ldrsh r3, [r4, r3]
	ldr r0, [r4, r0]
	mov r1, #2
	mov r2, #3
	bl BgSetPosTextAndCommit
	ldr r3, _021E6C3C ; =0x000184E6
	mov r0, #0xd
	lsl r0, r0, #6
	ldrsh r3, [r4, r3]
	ldr r0, [r4, r0]
	mov r1, #4
	mov r2, #3
	bl BgSetPosTextAndCommit
	ldr r3, _021E6C3C ; =0x000184E6
	mov r0, #0xd
	lsl r0, r0, #6
	ldrsh r3, [r4, r3]
	ldr r0, [r4, r0]
	mov r1, #6
	mov r2, #3
	bl BgSetPosTextAndCommit
	ldr r3, _021E6C3C ; =0x000184E6
	mov r0, #0xd
	lsl r0, r0, #6
	ldrsh r3, [r4, r3]
	ldr r0, [r4, r0]
	mov r1, #5
	mov r2, #3
	bl BgSetPosTextAndCommit
	ldr r1, _021E6C34 ; =0x000184E2
	mov r0, #1
	ldrb r2, [r4, r1]
	bic r2, r0
	strb r2, [r4, r1]
_021E6C16:
	bl GF_RunVramTransferTasks
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl DoScheduledBgGpuUpdates
	ldr r3, _021E6C40 ; =0x027E0000
	ldr r1, _021E6C44 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	nop
_021E6C34: .word 0x000184E2
_021E6C38: .word 0x000184E4
_021E6C3C: .word 0x000184E6
_021E6C40: .word 0x027E0000
_021E6C44: .word 0x00003FF8
	thumb_func_end ov108_021E6BA0
