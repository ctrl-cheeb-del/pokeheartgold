	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.extern ov87_021E7F28
	.extern ov87_021E7FD4
	.extern ov87_021E7FEC
	.extern ov87_021E803C
	.extern ov87_021E8078
	.extern ov87_021E80A8
	.extern ov87_021E82C0
	.extern ov87_021E82C2
	.extern ov87_021E82E4
	.public ov87_021E7590
	.public ov87_021E75E0
	.public ov87_021E7698
	.public ov87_021E7734
	.public ov87_021E788C
	.public ov87_021E78D8

	.text

thumb_func_start ov87_021E7590
ov87_021E7590: ; 0x021E7590
	push {r3, r4, r5, r6, r7, lr}
	add r3, r1, #0
	mov r7, #2
	mvn r7, r7
	add r0, r0, r3
	ldr r6, _021E75DC ; =0x000003FA
	str r2, [sp]
	mov lr, r0
	mov r5, #1
	mov ip, r7
_021E75A4:
	ldr r1, [sp]
	mov r2, #0xf0
	add r1, r1, r7
	add r4, r1, #0
	mul r4, r2
	mov r2, lr
	add r2, r2, r4
	mov r0, ip
	sub r4, r2, #3
_021E75B6:
	add r2, r3, r0
	cmp r2, #0
	ble _021E75CA
	cmp r2, #0xf0
	bge _021E75CA
	cmp r1, #0
	ble _021E75CA
	cmp r1, #0xa0
	bge _021E75CA
	strb r5, [r4, r6]
_021E75CA:
	add r0, r0, #1
	add r4, r4, #1
	cmp r0, #3
	blt _021E75B6
	add r7, r7, #1
	cmp r7, #3
	blt _021E75A4
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E75DC: .word 0x000003FA
	thumb_func_end ov87_021E7590

	thumb_func_start ov87_021E75E0
ov87_021E75E0: ; 0x021E75E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r1, [sp, #4]
	str r0, [sp]
	ldr r0, [sp, #4]
	mov r4, #0
	lsl r1, r0, #2
	ldr r0, _021E7680 ; =ov87_021E82C0
	ldrsh r7, [r0, r1]
	ldr r0, _021E7684 ; =ov87_021E82C2
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	add r0, #0x14
	ldr r1, [sp, #8]
	mov ip, r0
	cmp r1, r0
	bge _021E763A
	ldr r0, [sp, #8]
	add r2, r7, #0
	add r6, r0, #0
	mov r1, #0xf0
	ldr r0, _021E7688 ; =0x000003FA
	mul r6, r1
	add r2, #0x19
_021E7610:
	add r3, r7, #0
	cmp r7, r2
	bge _021E762C
	ldr r1, [sp]
	add r1, r1, r6
	add r5, r1, r7
_021E761C:
	ldrb r1, [r5, r0]
	cmp r1, #1
	bne _021E7624
	add r4, r4, #1
_021E7624:
	add r3, r3, #1
	add r5, r5, #1
	cmp r3, r2
	blt _021E761C
_021E762C:
	ldr r1, [sp, #8]
	add r6, #0xf0
	add r3, r1, #1
	mov r1, ip
	str r3, [sp, #8]
	cmp r3, r1
	blt _021E7610
_021E763A:
	mov r0, #0x5f
	lsl r0, r0, #2
	cmp r4, r0
	blt _021E7678
	ldr r1, _021E768C ; =0x000003A5
	ldr r0, [sp]
	add r4, r0, r1
	ldr r0, [sp, #4]
	ldrb r0, [r4, r0]
	cmp r0, #0
	bne _021E766E
	ldr r0, _021E7690 ; =0x000005E2
	bl PlaySE
	ldr r0, _021E7694 ; =0x000003A1
	ldr r1, [sp]
	ldrb r2, [r1, r0]
	add r3, r1, r2
	ldr r1, [sp, #4]
	add r2, r0, #1
	strb r1, [r3, r2]
	ldr r1, [sp]
	ldrb r1, [r1, r0]
	add r2, r1, #1
	ldr r1, [sp]
	strb r2, [r1, r0]
_021E766E:
	ldr r1, [sp, #4]
	mov r0, #1
	add sp, #0xc
	strb r0, [r4, r1]
	pop {r4, r5, r6, r7, pc}
_021E7678:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_021E7680: .word ov87_021E82C0
_021E7684: .word ov87_021E82C2
_021E7688: .word 0x000003FA
_021E768C: .word 0x000003A5
_021E7690: .word 0x000005E2
_021E7694: .word 0x000003A1
	thumb_func_end ov87_021E75E0

	thumb_func_start ov87_021E7698
ov87_021E7698: ; 0x021E7698
	push {r3, r4, r5, r6, r7, lr}
	ldr r2, _021E7720 ; =0x0000039E
	add r6, r0, #0
	ldrb r0, [r6, r2]
	add r0, r0, #1
	strb r0, [r6, r2]
	ldrb r0, [r6, r2]
	cmp r0, #1
	blo _021E771C
	mov r0, #0
	strb r0, [r6, r2]
	sub r1, r2, #1
	ldrb r1, [r6, r1]
	add r3, r1, #1
	sub r1, r2, #1
	strb r3, [r6, r1]
	ldrb r1, [r6, r1]
	cmp r1, #8
	blo _021E76C2
	sub r1, r2, #1
	strb r0, [r6, r1]
_021E76C2:
	ldr r0, _021E7724 ; =0x000003A1
	ldrb r0, [r6, r0]
	cmp r0, #2
	bne _021E770E
	ldr r7, _021E7728 ; =ov87_021E82E4
	mov r4, #0
	add r5, r6, #0
_021E76D0:
	mov r0, #0xd1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #3
	bl ov87_021E8078
	mov r0, #0xd1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl ov87_021E7FD4
	ldr r0, _021E772C ; =0x000003A2
	add r1, r6, r4
	ldrb r0, [r1, r0]
	mov r2, #2
	lsl r1, r0, #2
	add r3, r7, r1
	mov r0, #0xd1
	ldrsh r1, [r7, r1]
	ldrsh r2, [r3, r2]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	sub r1, #0x24
	sub r2, #0xa
	bl ov87_021E7FEC
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _021E76D0
_021E770E:
	ldr r1, _021E7730 ; =0x0000039D
	mov r0, #0x5b
	ldrb r1, [r6, r1]
	lsl r0, r0, #2
	add r0, r6, r0
	bl ov87_021E7F28
_021E771C:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7720: .word 0x0000039E
_021E7724: .word 0x000003A1
_021E7728: .word ov87_021E82E4
_021E772C: .word 0x000003A2
_021E7730: .word 0x0000039D
	thumb_func_end ov87_021E7698

	thumb_func_start ov87_021E7734
ov87_021E7734: ; 0x021E7734
	push {r4, r5}
	ldr r1, _021E7880 ; =0x000003A1
	mov r3, #0
	ldrb r2, [r0, r1]
	cmp r2, #1
	bhi _021E7746
	add r0, r3, #0
	pop {r4, r5}
	bx lr
_021E7746:
	add r2, r1, #2
	ldrb r2, [r0, r2]
	add r4, r0, r2
	add r2, r1, #0
	sub r2, #0x41
	ldrb r2, [r4, r2]
	add r4, r1, #1
	ldrb r4, [r0, r4]
	add r5, r0, r4
	add r4, r1, #0
	sub r4, #0x41
	ldrb r4, [r5, r4]
	cmp r4, r2
	bne _021E7774
	sub r2, r1, #1
	ldrb r4, [r0, r2]
	mov r2, #1
	sub r1, r1, #1
	bic r4, r2
	mov r2, #1
	orr r2, r4
	strb r2, [r0, r1]
	b _021E779E
_021E7774:
	cmp r4, #4
	bne _021E778A
	sub r2, r1, #1
	ldrb r4, [r0, r2]
	mov r2, #1
	sub r1, r1, #1
	bic r4, r2
	mov r2, #1
	orr r2, r4
	strb r2, [r0, r1]
	b _021E779E
_021E778A:
	cmp r2, #4
	bne _021E779E
	sub r2, r1, #1
	ldrb r4, [r0, r2]
	mov r2, #1
	sub r1, r1, #1
	bic r4, r2
	mov r2, #1
	orr r2, r4
	strb r2, [r0, r1]
_021E779E:
	ldr r1, _021E7880 ; =0x000003A1
	ldrb r2, [r0, r1]
	cmp r2, #2
	bhi _021E77AC
	mov r0, #0
	pop {r4, r5}
	bx lr
_021E77AC:
	add r2, r1, #2
	ldrb r2, [r0, r2]
	add r4, r0, r2
	add r2, r1, #0
	sub r2, #0x41
	ldrb r4, [r4, r2]
	add r2, r1, #1
	ldrb r2, [r0, r2]
	add r5, r0, r2
	add r2, r1, #0
	sub r2, #0x41
	ldrb r2, [r5, r2]
	cmp r2, r4
	bne _021E77D8
	add r5, r1, #3
	ldrb r5, [r0, r5]
	sub r1, #0x41
	add r5, r0, r5
	ldrb r1, [r5, r1]
	cmp r2, r1
	bne _021E77D8
	mov r3, #1
_021E77D8:
	cmp r2, #4
	bne _021E77E2
	cmp r4, #4
	bne _021E77E2
	mov r3, #1
_021E77E2:
	cmp r2, #4
	bne _021E77F8
	mov r1, #0xe9
	lsl r1, r1, #2
	ldrb r5, [r0, r1]
	sub r1, #0x44
	add r5, r0, r5
	ldrb r1, [r5, r1]
	cmp r1, #4
	bne _021E77F8
	mov r3, #1
_021E77F8:
	cmp r4, #4
	bne _021E780E
	mov r1, #0xe9
	lsl r1, r1, #2
	ldrb r5, [r0, r1]
	sub r1, #0x44
	add r5, r0, r5
	ldrb r1, [r5, r1]
	cmp r1, #4
	bne _021E780E
	mov r3, #1
_021E780E:
	cmp r2, #4
	bne _021E7824
	mov r1, #0xe9
	lsl r1, r1, #2
	ldrb r5, [r0, r1]
	sub r1, #0x44
	add r5, r0, r5
	ldrb r1, [r5, r1]
	cmp r4, r1
	bne _021E7824
	mov r3, #1
_021E7824:
	cmp r4, #4
	bne _021E783A
	mov r1, #0xe9
	lsl r1, r1, #2
	ldrb r5, [r0, r1]
	sub r1, #0x44
	add r5, r0, r5
	ldrb r1, [r5, r1]
	cmp r2, r1
	bne _021E783A
	mov r3, #1
_021E783A:
	mov r1, #0xe9
	lsl r1, r1, #2
	ldrb r5, [r0, r1]
	sub r1, #0x44
	add r5, r0, r5
	ldrb r1, [r5, r1]
	cmp r1, #4
	bne _021E7850
	cmp r2, r4
	bne _021E7850
	mov r3, #1
_021E7850:
	cmp r3, #1
	bne _021E787A
	ldr r1, _021E7884 ; =0x000003A2
	mov r4, #0
	add r2, r1, #0
	sub r2, #0x42
_021E785C:
	add r3, r0, r4
	ldrb r3, [r3, r1]
	add r3, r0, r3
	ldrb r3, [r3, r2]
	cmp r3, #4
	beq _021E786E
	ldr r1, _021E7888 ; =0x0000039F
	strb r3, [r0, r1]
	b _021E7874
_021E786E:
	add r4, r4, #1
	cmp r4, #3
	blt _021E785C
_021E7874:
	mov r0, #1
	pop {r4, r5}
	bx lr
_021E787A:
	mov r0, #0
	pop {r4, r5}
	bx lr
	.balign 4, 0
_021E7880: .word 0x000003A1
_021E7884: .word 0x000003A2
_021E7888: .word 0x0000039F
	thumb_func_end ov87_021E7734

	thumb_func_start ov87_021E788C
ov87_021E788C: ; 0x021E788C
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r0, #0
	mov r7, #0x36
	add r4, r0, #0
	add r5, r6, #0
	lsl r7, r7, #4
_021E789A:
	ldr r1, _021E78D0 ; =0x000003A2
	add r2, r6, r4
	ldrb r1, [r2, r1]
	add r1, r6, r1
	ldrb r1, [r1, r7]
	cmp r1, #4
	bne _021E78B6
	mov r0, #0x35
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #1
	bl ov87_021E80A8
	mov r0, #1
_021E78B6:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _021E789A
	mov r1, #0
	strb r1, [r6, #0x14]
	ldrb r2, [r6, #0x14]
	lsl r1, r2, #4
	orr r2, r1
	ldr r1, _021E78D4 ; =0x0400004D
	strb r2, [r1]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E78D0: .word 0x000003A2
_021E78D4: .word 0x0400004D
	thumb_func_end ov87_021E788C

	thumb_func_start ov87_021E78D8
ov87_021E78D8: ; 0x021E78D8
	push {r3, r4, r5, r6, r7, lr}
	ldr r2, _021E7980 ; =0x000003A2
	add r5, r0, #0
	add r3, r2, #0
	mov r0, #0
	sub r3, #0x42
_021E78E4:
	add r4, r5, r0
	ldrb r4, [r4, r2]
	add r4, r5, r4
	ldrb r4, [r4, r3]
	cmp r4, #4
	beq _021E78F6
	add r0, r0, #1
	cmp r0, #3
	blt _021E78E4
_021E78F6:
	cmp r0, #3
	bne _021E78FE
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E78FE:
	cmp r1, #0
	ldrb r0, [r5, #0x14]
	bne _021E794A
	cmp r0, #0
	bne _021E790E
	ldr r0, _021E7984 ; =0x00000563
	bl PlaySE
_021E790E:
	ldrb r0, [r5, #0x14]
	cmp r0, #4
	bhs _021E791A
	add r0, r0, #1
	strb r0, [r5, #0x14]
	b _021E7970
_021E791A:
	mov r7, #0x36
	mov r4, #0
	add r6, r5, #0
	lsl r7, r7, #4
_021E7922:
	ldr r0, _021E7980 ; =0x000003A2
	add r1, r5, r4
	ldrb r0, [r1, r0]
	add r0, r5, r0
	ldrb r0, [r0, r7]
	cmp r0, #4
	bne _021E793E
	ldr r1, _021E7988 ; =0x0000039F
	mov r0, #0x35
	lsl r0, r0, #4
	ldrb r1, [r5, r1]
	ldr r0, [r6, r0]
	bl ov87_021E803C
_021E793E:
	add r4, r4, #1
	add r6, r6, #4
	cmp r4, #3
	blt _021E7922
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E794A:
	cmp r0, #0
	beq _021E7954
	sub r0, r0, #1
	strb r0, [r5, #0x14]
	b _021E7970
_021E7954:
	mov r4, #0
	mov r6, #0x35
	add r7, r4, #0
	lsl r6, r6, #4
_021E795C:
	ldr r0, [r5, r6]
	add r1, r7, #0
	bl ov87_021E80A8
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _021E795C
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E7970:
	ldrb r1, [r5, #0x14]
	lsl r0, r1, #4
	orr r1, r0
	ldr r0, _021E798C ; =0x0400004D
	strb r1, [r0]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7980: .word 0x000003A2
_021E7984: .word 0x00000563
_021E7988: .word 0x0000039F
_021E798C: .word 0x0400004D
	thumb_func_end ov87_021E78D8
