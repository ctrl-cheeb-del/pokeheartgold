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

	thumb_func_start ov108_021E62B4
ov108_021E62B4: ; 0x021E62B4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _021E63A8 ; =gSystem
	ldr r4, [r0, #0x48]
	mov r0, #2
	tst r0, r4
	beq _021E62D0
	ldr r0, _021E63AC ; =0x000005DC
	bl PlaySE
	mov r0, #6
	str r0, [r5, #0xc]
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_021E62D0:
	mov r0, #1
	tst r0, r4
	beq _021E62FA
	ldr r0, _021E63B0 ; =0x000184DF
	ldrb r0, [r5, r0]
	cmp r0, #6
	ldr r0, _021E63AC ; =0x000005DC
	blo _021E62EC
	bl PlaySE
	mov r0, #6
	str r0, [r5, #0xc]
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_021E62EC:
	bl PlaySE
	add r0, r5, #0
	bl ov108_021E6A58
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E62FA:
	mov r0, #0xf0
	tst r0, r4
	bne _021E6304
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E6304:
	ldr r0, _021E63B0 ; =0x000184DF
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
	bhs _021E634A
	mov r0, #0x10
	tst r0, r4
	beq _021E6338
	add r0, r7, #1
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r7, r0, #0x18
	b _021E634A
_021E6338:
	mov r0, #0x20
	tst r0, r4
	beq _021E634A
	add r0, r7, #2
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r7, r0, #0x18
_021E634A:
	mov r0, #0x40
	tst r0, r4
	beq _021E635E
	add r0, r6, #2
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	b _021E6370
_021E635E:
	mov r0, #0x80
	tst r0, r4
	beq _021E6370
	add r0, r6, #1
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
_021E6370:
	lsl r0, r6, #1
	add r0, r6, r0
	add r1, r7, r0
	ldr r0, _021E63B0 ; =0x000184DF
	cmp r6, #2
	strb r1, [r5, r0]
	blo _021E6388
	ldr r0, _021E63A8 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #0xc0
	tst r0, r1
	beq _021E638E
_021E6388:
	ldr r0, _021E63B4 ; =0x000005E5
	bl PlaySE
_021E638E:
	ldr r2, _021E63B0 ; =0x000184DF
	add r0, r5, #0
	ldrb r2, [r5, r2]
	mov r1, #0
	bl ov108_021E78F4
	ldr r1, _021E63B0 ; =0x000184DF
	add r0, r5, #0
	ldrb r1, [r5, r1]
	bl ov108_021E7CD8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E63A8: .word gSystem
_021E63AC: .word 0x000005DC
_021E63B0: .word 0x000184DF
_021E63B4: .word 0x000005E5
	thumb_func_end ov108_021E62B4


	thumb_func_start ov108_021E63B8
ov108_021E63B8: ; 0x021E63B8
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	ldr r0, _021E643C ; =ov108_021EA760
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _021E63D2
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_021E63D2:
	cmp r0, #6
	bne _021E640C
	ldr r1, _021E6440 ; =0x0000FFFE
	add r0, sp, #4
	strh r1, [r0]
	add r0, sp, #4
	str r0, [sp]
	ldr r3, _021E6444 ; =gSystem + 0x40
	mov r0, #0xd
	lsl r0, r0, #6
	ldrh r2, [r3, #0x20]
	ldrh r3, [r3, #0x22]
	ldr r0, [r4, r0]
	mov r1, #3
	bl DoesPixelAtScreenXYMatchPtrVal
	cmp r0, #0
	bne _021E63FC
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_021E63FC:
	ldr r0, _021E6448 ; =0x000005DC
	bl PlaySE
	mov r0, #6
	str r0, [r4, #0xc]
	add sp, #8
	mov r0, #4
	pop {r4, pc}
_021E640C:
	ldr r2, _021E644C ; =0x000184DF
	mov r1, #0
	strb r0, [r4, r2]
	add r0, r2, #1
	strb r1, [r4, r0]
	ldrb r2, [r4, r2]
	add r0, r4, #0
	bl ov108_021E78F4
	ldr r1, _021E644C ; =0x000184DF
	add r0, r4, #0
	ldrb r1, [r4, r1]
	bl ov108_021E7CD8
	ldr r0, _021E6448 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	bl ov108_021E6A58
	mov r0, #1
	add sp, #8
	pop {r4, pc}
	nop
_021E643C: .word ov108_021EA760
_021E6440: .word 0x0000FFFE
_021E6444: .word gSystem + 0x40
_021E6448: .word 0x000005DC
_021E644C: .word 0x000184DF
	thumb_func_end ov108_021E63B8


	thumb_func_start ov108_021E6450
ov108_021E6450: ; 0x021E6450
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _021E64B4 ; =0x000005DC
	bl PlaySE
	ldr r1, _021E64B8 ; =0x000184E3
	ldrb r0, [r4, r1]
	cmp r0, #0
	beq _021E646C
	add r0, r4, #0
	bl ov108_021E6B00
	mov r0, #1
	pop {r4, pc}
_021E646C:
	sub r0, r1, #3
	ldrb r3, [r4, r0]
	sub r0, r1, #5
	ldrb r2, [r4, r0]
	mov r0, #6
	mul r0, r2
	add r0, r3, r0
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	add r0, r1, #5
	mov r3, #1
	str r3, [r4, r0]
	sub r1, r1, #4
	add r0, r4, #0
	ldrb r1, [r4, r1]
	add r0, #0x1c
	bl SafariZone_InitAreaInSet
	ldr r0, _021E64BC ; =0x000184DF
	mov r2, #0x7a
	ldrb r1, [r4, r0]
	add r0, r4, #0
	mul r2, r1
	add r2, r4, r2
	ldrb r2, [r2, #0x1c]
	bl ov108_021E7BB4
	mov r2, #0
	add r0, r4, #0
	mov r1, #1
	add r3, r2, #0
	bl ov108_021E79A8
	mov r0, #2
	pop {r4, pc}
	nop
_021E64B4: .word 0x000005DC
_021E64B8: .word 0x000184E3
_021E64BC: .word 0x000184DF
	thumb_func_end ov108_021E6450


	thumb_func_start ov108_021E64C0
ov108_021E64C0: ; 0x021E64C0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r1, _021E6694 ; =0x000184E0
	add r5, r0, #0
	ldrb r2, [r5, r1]
	str r2, [sp]
	ldr r2, _021E6698 ; =gSystem
	ldr r7, [r2, #0x48]
	mov r2, #2
	tst r2, r7
	beq _021E64E2
	ldr r0, _021E669C ; =0x000005DC
	bl PlaySE
	add sp, #8
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_021E64E2:
	mov r2, #1
	tst r2, r7
	beq _021E6526
	ldr r2, [sp]
	cmp r2, #6
	blo _021E64FA
	ldr r0, _021E669C ; =0x000005DC
	bl PlaySE
	add sp, #8
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_021E64FA:
	sub r2, r1, #2
	ldrb r3, [r5, r2]
	sub r1, r1, #1
	mov r2, #6
	add r4, r3, #0
	ldrb r3, [r5, r1]
	mov r1, #0x7a
	mul r4, r2
	mul r1, r3
	add r1, r5, r1
	ldr r2, [sp]
	ldrb r1, [r1, #0x1c]
	add r2, r2, r4
	cmp r2, r1
	bne _021E651E
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E651E:
	bl ov108_021E6450
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021E6526:
	mov r0, #0xf0
	tst r0, r7
	bne _021E6532
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E6532:
	ldr r0, [sp]
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	ldr r0, [sp]
	mov r1, #3
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #0x10
	tst r0, r7
	beq _021E65B6
	cmp r4, #2
	bhs _021E65B6
	cmp r6, #2
	bne _021E65A8
	cmp r4, #0
	bne _021E6576
	mov r0, #1
	eor r0, r4
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r6, #1
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	b _021E6644
_021E6576:
	cmp r4, #2
	bhs _021E6644
	ldr r1, _021E66A0 ; =0x000184DE
	ldrb r0, [r5, r1]
	cmp r0, #1
	bhs _021E6644
	mov r0, #1
	str r0, [sp, #4]
	add r0, r1, #4
	ldrb r2, [r5, r0]
	mov r0, #2
	bic r2, r0
	add r0, r1, #4
	strb r2, [r5, r0]
	ldr r0, [sp, #4]
	mov r1, #3
	eor r0, r4
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r6, #1
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	b _021E6644
_021E65A8:
	add r0, r6, #1
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	b _021E6644
_021E65B6:
	mov r0, #0x20
	tst r0, r7
	beq _021E661E
	cmp r4, #2
	bhs _021E661E
	cmp r6, #0
	bne _021E6610
	cmp r4, #1
	bne _021E65DE
	mov r0, #1
	eor r0, r4
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r6, #2
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	b _021E6644
_021E65DE:
	cmp r4, #2
	bhs _021E6644
	ldr r1, _021E66A0 ; =0x000184DE
	ldrb r0, [r5, r1]
	cmp r0, #0
	beq _021E6644
	mov r0, #1
	str r0, [sp, #4]
	add r0, r1, #4
	ldrb r2, [r5, r0]
	mov r0, #2
	orr r2, r0
	add r0, r1, #4
	strb r2, [r5, r0]
	ldr r0, [sp, #4]
	mov r1, #3
	eor r0, r4
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r6, #2
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	b _021E6644
_021E6610:
	add r0, r6, #2
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	b _021E6644
_021E661E:
	mov r0, #0x40
	tst r0, r7
	beq _021E6632
	add r0, r4, #2
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	b _021E6644
_021E6632:
	mov r0, #0x80
	tst r0, r7
	beq _021E6644
	add r0, r4, #1
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
_021E6644:
	lsl r0, r4, #1
	add r0, r4, r0
	ldr r2, _021E6694 ; =0x000184E0
	add r0, r6, r0
	strb r0, [r5, r2]
	ldrb r2, [r5, r2]
	add r0, r5, #0
	mov r1, #1
	bl ov108_021E78F4
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _021E6676
	ldr r0, _021E66A4 ; =0x000005E1
	bl PlaySE
	mov r2, #0
	add r0, r5, #0
	mov r1, #1
	add r3, r2, #0
	bl ov108_021E78C0
	add sp, #8
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_021E6676:
	ldr r0, _021E6694 ; =0x000184E0
	ldrb r1, [r5, r0]
	ldr r0, [sp]
	cmp r0, r1
	beq _021E6686
	ldr r0, _021E66A8 ; =0x000005E5
	bl PlaySE
_021E6686:
	add r0, r5, #0
	bl ov108_021E7EB0
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6694: .word 0x000184E0
_021E6698: .word gSystem
_021E669C: .word 0x000005DC
_021E66A0: .word 0x000184DE
_021E66A4: .word 0x000005E1
_021E66A8: .word 0x000005E5
	thumb_func_end ov108_021E64C0


	thumb_func_start ov108_021E66AC
ov108_021E66AC: ; 0x021E66AC
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	ldr r0, _021E67E8 ; =ov108_021EA7D0
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _021E66C6
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_021E66C6:
	cmp r0, #6
	beq _021E66D4
	cmp r0, #7
	beq _021E670C
	cmp r0, #8
	beq _021E675A
	b _021E67A6
_021E66D4:
	ldr r1, _021E67EC ; =0x0000FFFE
	add r0, sp, #4
	strh r1, [r0]
	add r0, sp, #4
	str r0, [sp]
	ldr r3, _021E67F0 ; =gSystem + 0x40
	mov r0, #0xd
	lsl r0, r0, #6
	ldrh r2, [r3, #0x20]
	ldrh r3, [r3, #0x22]
	ldr r0, [r4, r0]
	mov r1, #3
	bl DoesPixelAtScreenXYMatchPtrVal
	cmp r0, #0
	bne _021E66FA
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_021E66FA:
	ldr r0, _021E67F4 ; =0x000184E0
	mov r1, #6
	strb r1, [r4, r0]
	ldr r0, _021E67F8 ; =0x000005DC
	bl PlaySE
	add sp, #8
	mov r0, #2
	pop {r4, pc}
_021E670C:
	ldr r1, _021E67FC ; =0x000184DE
	ldrb r0, [r4, r1]
	cmp r0, #0
	bne _021E671A
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_021E671A:
	add r0, r1, #4
	ldrb r2, [r4, r0]
	mov r0, #2
	orr r2, r0
	add r0, r1, #4
	strb r2, [r4, r0]
	add r0, r1, #2
	mov r2, #5
	strb r2, [r4, r0]
	mov r2, #0
	add r0, r4, #0
	mov r1, #1
	add r3, r2, #0
	bl ov108_021E78C0
	mov r0, #0xd9
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0xd9
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_ResetAnimCtrlState
	ldr r0, _021E6800 ; =0x000005E1
	bl PlaySE
	add sp, #8
	mov r0, #3
	pop {r4, pc}
_021E675A:
	ldr r1, _021E67FC ; =0x000184DE
	ldrb r0, [r4, r1]
	cmp r0, #1
	bne _021E6768
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_021E6768:
	add r0, r1, #4
	ldrb r2, [r4, r0]
	mov r0, #2
	bic r2, r0
	add r0, r1, #4
	strb r2, [r4, r0]
	mov r2, #0
	add r0, r1, #2
	strb r2, [r4, r0]
	add r0, r4, #0
	mov r1, #1
	add r3, r2, #0
	bl ov108_021E78C0
	mov r0, #0xda
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0xda
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_ResetAnimCtrlState
	ldr r0, _021E6800 ; =0x000005E1
	bl PlaySE
	add sp, #8
	mov r0, #3
	pop {r4, pc}
_021E67A6:
	ldr r2, _021E67F4 ; =0x000184E0
	mov r1, #1
	strb r0, [r4, r2]
	ldrb r2, [r4, r2]
	add r0, r4, #0
	bl ov108_021E78F4
	add r0, r4, #0
	bl ov108_021E7EB0
	ldr r1, _021E67F4 ; =0x000184E0
	sub r0, r1, #2
	ldrb r2, [r4, r0]
	ldrb r3, [r4, r1]
	mov r0, #6
	mul r0, r2
	sub r1, r1, #1
	ldrb r2, [r4, r1]
	mov r1, #0x7a
	add r0, r3, r0
	mul r1, r2
	add r1, r4, r1
	ldrb r1, [r1, #0x1c]
	cmp r0, r1
	bne _021E67DE
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_021E67DE:
	add r0, r4, #0
	bl ov108_021E6450
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
_021E67E8: .word ov108_021EA7D0
_021E67EC: .word 0x0000FFFE
_021E67F0: .word gSystem + 0x40
_021E67F4: .word 0x000184E0
_021E67F8: .word 0x000005DC
_021E67FC: .word 0x000184DE
_021E6800: .word 0x000005E1
	thumb_func_end ov108_021E66AC
