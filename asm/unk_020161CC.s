	.include "asm/macros.inc"
	.include "unk_02015DD8.inc"
	.include "global.inc"

	.text
	thumb_func_start sub_020161CC
sub_020161CC: ; 0x020161CC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r7, _020162EC ; =0x04000444
	mov r6, #0
	add r5, r0, #0
	str r6, [r7]
	ldrh r1, [r5, #0x3c]
	ldr r0, _020162F0 ; =0x7FFF8000
	orr r0, r1
	str r0, [r7, #0x7c]
	add r0, r7, #0
	ldr r1, _020162F4 ; =0x00004210
	add r0, #0x80
	str r1, [r0]
	ldr r3, [r5, #0x24]
	ldr r4, [r3, #8]
	ldr r2, [r3, #0x10]
	ldr r1, [r3, #4]
	ldr r0, [r3]
	lsl r3, r2, #0x1d
	lsl r2, r1, #0x17
	lsl r1, r0, #0x14
	ldr r0, [r5, #0x28]
	lsl r4, r4, #0x1a
	lsr r0, r0, #3
	orr r4, r0
	mov r0, #1
	lsl r0, r0, #0x1e
	orr r0, r4
	orr r0, r1
	orr r0, r2
	orr r0, r3
	str r0, [r7, #0x64]
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #8]
	cmp r0, #2
	bne _02016218
	mov r6, #1
_02016218:
	ldr r0, [r5, #0x30]
	ldr r1, [r5, #0x2c]
	lsl r0, r0, #5
	add r1, r1, r0
	mov r0, #4
	sub r0, r0, r6
	lsr r1, r0
	ldr r2, _020162F8 ; =0x040004AC
	add r0, r5, #0
	str r1, [r2]
	add r0, #0x3e
	ldrb r0, [r0]
	sub r2, #8
	lsl r1, r0, #0x10
	mov r0, #0xc0
	orr r0, r1
	str r0, [r2]
	ldr r0, [r5, #0x34]
	cmp r0, #0
	beq _0201624A
	mov r0, #8
	ldrsh r0, [r5, r0]
	mov r7, #0
	str r0, [sp, #0x14]
	b _02016252
_0201624A:
	mov r0, #8
	ldrsh r7, [r5, r0]
	mov r0, #0
	str r0, [sp, #0x14]
_02016252:
	ldr r0, [r5, #0x38]
	cmp r0, #0
	beq _02016260
	mov r0, #0xa
	ldrsh r6, [r5, r0]
	mov r4, #0
	b _02016266
_02016260:
	mov r0, #0xa
	ldrsh r4, [r5, r0]
	mov r6, #0
_02016266:
	ldr r0, [r5, #0x14]
	mov r1, #6
	lsl r2, r0, #0xc
	mov r0, #2
	ldrsh r0, [r5, r0]
	ldrsh r1, [r5, r1]
	mov r3, #4
	ldrsh r3, [r5, r3]
	add r0, r0, r1
	lsl r1, r0, #0xc
	mov r0, #0
	ldrsh r0, [r5, r0]
	add r0, r0, r3
	ldr r3, _020162FC ; =0x04000470
	lsl r0, r0, #0xc
	str r0, [r3]
	str r1, [r3]
	str r2, [r3]
	ldr r0, [r5, #0x18]
	ldr r1, _02016300 ; =FX_SinCosTable_
	asr r0, r0, #4
	lsl r2, r0, #1
	lsl r0, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r0, [r1, r0]
	ldrsh r1, [r1, r2]
	bl G3_RotZ
	ldr r2, [r5, #0x10]
	ldr r0, [r5, #0xc]
	ldr r1, _02016304 ; =0x0400046C
	mov r3, #8
	str r0, [r1]
	str r2, [r1]
	lsr r0, r1, #0xe
	str r0, [r1]
	mov r2, #4
	mov r0, #6
	ldrsh r2, [r5, r2]
	ldrsh r0, [r5, r0]
	neg r2, r2
	neg r0, r0
	lsl r2, r2, #0xc
	lsl r0, r0, #0xc
	str r2, [r1, #4]
	str r0, [r1, #4]
	mov r0, #0
	str r0, [r1, #4]
	mov r1, #0xa
	ldrsh r1, [r5, r1]
	add r2, r0, #0
	str r1, [sp]
	ldr r1, [sp, #0x14]
	str r1, [sp, #4]
	str r6, [sp, #8]
	str r7, [sp, #0xc]
	str r4, [sp, #0x10]
	ldrsh r3, [r5, r3]
	add r1, r0, #0
	bl NNS_G2dDrawSpriteFast
	ldr r0, _02016308 ; =0x04000448
	mov r1, #1
	str r1, [r0]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_020162EC: .word 0x04000444
_020162F0: .word 0x7FFF8000
_020162F4: .word 0x00004210
_020162F8: .word 0x040004AC
_020162FC: .word 0x04000470
_02016300: .word FX_SinCosTable_
_02016304: .word 0x0400046C
_02016308: .word 0x04000448
	thumb_func_end sub_020161CC
	thumb_func_start sub_0201630C
sub_0201630C: ; 0x0201630C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	ldr r1, [r5, #4]
	add r7, r0, #0
	ldr r2, [r1, #0x10]
	mov r6, #8
	mov r0, #0
	cmp r2, #0
	ble _0201632A
_0201631E:
	ldr r2, [r5, #4]
	add r0, r0, #1
	ldr r2, [r2, #0x10]
	lsl r6, r6, #1
	cmp r0, r2
	blt _0201631E
_0201632A:
	ldr r1, [r1, #0x14]
	mov r4, #8
	mov r0, #0
	cmp r1, #0
	ble _02016340
_02016334:
	ldr r1, [r5, #4]
	add r0, r0, #1
	ldr r1, [r1, #0x14]
	lsl r4, r4, #1
	cmp r0, r1
	blt _02016334
_02016340:
	mov r1, #0xc
	mov r2, #0xe
	ldrsh r1, [r5, r1]
	ldrsh r2, [r5, r2]
	add r0, r7, #0
	bl sub_02015FC4
	lsr r1, r6, #0x1f
	lsr r2, r4, #0x1f
	add r1, r6, r1
	add r2, r4, r2
	lsl r1, r1, #0xf
	lsl r2, r2, #0xf
	add r0, r7, #0
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	bl sub_02015FD8
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [r7, #0xc]
	str r0, [r7, #0x10]
	add r0, r7, #0
	add r1, r6, #0
	add r2, r4, #0
	bl sub_02015FE0
	ldr r1, [r5, #0x18]
	add r0, r7, #0
	bl sub_02015FF4
	ldr r1, [r5, #0x14]
	add r0, r7, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl sub_02015FFC
	ldr r1, [r5, #4]
	add r0, r7, #0
	add r1, #0x10
	bl sub_02016004
	ldr r0, [r5, #4]
	mov r1, #0
	add r0, r0, #4
	bl NNS_G2dGetImageLocation
	add r1, r0, #0
	add r0, r7, #0
	bl sub_02016008
	ldr r0, [r5, #8]
	mov r1, #0
	add r0, r0, #4
	bl NNS_G2dGetImagePaletteLocation
	add r1, r0, #0
	add r0, r7, #0
	bl sub_0201600C
	ldrh r1, [r5, #0x1c]
	add r0, r7, #0
	bl sub_02016010
	mov r1, #0
	add r0, r7, #0
	add r2, r1, #0
	bl sub_02016014
	add r0, r7, #0
	mov r1, #1
	mov r2, #0
	bl sub_02016014
	ldrh r1, [r5, #0x10]
	add r0, r7, #0
	bl sub_02016020
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0201630C
