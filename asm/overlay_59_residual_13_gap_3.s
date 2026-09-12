	.include "asm/macros.inc"
	.public ov59_0223C3C0
	.public PlaySE
	.public Pokepic_StartPaletteFade
	.public Pokepic_ResumePaletteFade
	.public ov59_0223C3DC
	.public sub_020154B8
	.public BeginNormalPaletteFade
	.public Pokepic_SetAttr
	.public Heap_Free
	.public SysTask_Destroy
	.public IsPaletteFadeFinished
	.text

	thumb_func_start ov59_0223C16C
ov59_0223C16C: ; 0x0223C16C
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r4, r1, #0
	add r6, r0, #0
	ldrb r0, [r4, #5]
	ldr r5, [r4]
	cmp r0, #4
	bhi _0223C25C
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223C188: ; jump table
	.short _0223C192 - _0223C188 - 2 ; case 0
	.short _0223C1AE - _0223C188 - 2 ; case 1
	.short _0223C1E8 - _0223C188 - 2 ; case 2
	.short _0223C202 - _0223C188 - 2 ; case 3
	.short _0223C22A - _0223C188 - 2 ; case 4
_0223C192:
	ldr r0, [r5, #0x78]
	mov r1, #2
	bl ov59_0223C3C0
	ldr r0, _0223C28C ; =0x00000923
	bl PlaySE
	mov r0, #0x14
	strb r0, [r4, #4]
	ldrb r0, [r4, #5]
	add sp, #0xc
	add r0, r0, #1
	strb r0, [r4, #5]
	pop {r3, r4, r5, r6, pc}
_0223C1AE:
	ldrb r1, [r4, #4]
	sub r0, r1, #1
	strb r0, [r4, #4]
	cmp r1, #0
	bne _0223C288
	ldr r0, _0223C290 ; =0x00007FFF
	mov r1, #0
	str r0, [sp]
	ldr r0, [r5, #0x78]
	mov r2, #0x10
	ldr r0, [r0, #0x20]
	mov r3, #4
	bl Pokepic_StartPaletteFade
	ldr r0, [r5, #0x78]
	mov r1, #1
	bl ov59_0223C3C0
	ldr r0, [r5, #0x78]
	mov r1, #0
	bl ov59_0223C3C0
	mov r0, #0x19
	strb r0, [r4, #4]
	ldrb r0, [r4, #5]
	add sp, #0xc
	add r0, r0, #1
	strb r0, [r4, #5]
	pop {r3, r4, r5, r6, pc}
_0223C1E8:
	ldrb r1, [r4, #4]
	sub r0, r1, #1
	strb r0, [r4, #4]
	cmp r1, #0
	bne _0223C288
	ldr r0, _0223C294 ; =0x00000924
	bl PlaySE
	ldrb r0, [r4, #5]
	add sp, #0xc
	add r0, r0, #1
	strb r0, [r4, #5]
	pop {r3, r4, r5, r6, pc}
_0223C202:
	ldr r0, [r5, #0x78]
	ldr r0, [r0, #0x20]
	bl Pokepic_ResumePaletteFade
	cmp r0, #0
	bne _0223C288
	ldr r0, [r5, #0x78]
	bl ov59_0223C3DC
	cmp r0, #0
	bne _0223C288
	ldr r0, [r5, #0x78]
	ldr r0, [r0, #0x24]
	bl sub_020154B8
	ldrb r0, [r4, #5]
	add sp, #0xc
	add r0, r0, #1
	strb r0, [r4, #5]
	pop {r3, r4, r5, r6, pc}
_0223C22A:
	mov r0, #6
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [r5]
	mov r1, #1
	str r0, [sp, #8]
	ldr r3, _0223C290 ; =0x00007FFF
	mov r0, #0
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, _0223C290 ; =0x00007FFF
	mov r1, #0x10
	str r0, [sp]
	ldr r0, [r5, #0x78]
	mov r2, #0
	ldr r0, [r0, #0x20]
	mov r3, #4
	bl Pokepic_StartPaletteFade
	ldrb r0, [r4, #5]
	add sp, #0xc
	add r0, r0, #1
	strb r0, [r4, #5]
	pop {r3, r4, r5, r6, pc}
_0223C25C:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0223C288
	ldr r0, [r5, #0x78]
	ldr r0, [r0, #0x20]
	bl Pokepic_ResumePaletteFade
	cmp r0, #0
	bne _0223C288
	add r0, r5, #0
	add r0, #0x4f
	ldrb r0, [r0]
	add r5, #0x4f
	sub r0, r0, #1
	strb r0, [r5]
	add r0, r4, #0
	bl Heap_Free
	add r0, r6, #0
	bl SysTask_Destroy
_0223C288:
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0223C28C: .word 0x00000923
_0223C290: .word 0x00007FFF
_0223C294: .word 0x00000924
	thumb_func_end ov59_0223C16C
