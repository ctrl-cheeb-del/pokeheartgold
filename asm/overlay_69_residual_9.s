	.include "asm/macros.inc"
	.public GeonetGlobe_Init
	.public GeonetGlobe_Main
	.public GeonetGlobe_Exit
	.public ov69_021E60F8
	.public ov69_021E6118
	.public ov69_021E6138
	.public ov69_021E623C
	.public ov69_021E62B0
	.public ov69_021E6300
	.public ov69_021E6308
	.public ov69_021E645C
	.public ov69_021E64CC
	.public ov69_021E67B8
	.public ov69_021E6810
	.public ov69_021E68D8
	.public ov69_021E68EC
	.public ov69_021E6994
	.public ov69_021E6A54
	.public ov69_021E6A8C
	.public ov69_021E6B5C
	.public ov69_021E6C14
	.public ov69_021E6C30
	.public ov69_021E6D5C
	.public ov69_021E6E88
	.public ov69_021E6F48
	.public ov69_021E6F8C
	.public ov69_021E6FE8
	.public ov69_021E706C
	.public ov69_021E70A8
	.public ov69_021E7120
	.public ov69_021E7198
	.public ov69_021E737C
	.public ov69_021E7408
	.public ov69_021E7520
	.public ov69_021E758C
	.public ov69_021E75A0
	.public ov69_021E75F8
	.public _021E7644
	.public ov69_021E764C
	.public ov69_021E7654
	.public ov69_021E765C
	.public ov69_021E7664
	.public ov69_021E766C
	.public ov69_021E7674
	.public ov69_021E767C
	.public ov69_021E7688
	.public ov69_021E7698
	.public ov69_021E76B0
	.public ov69_021E76CC
	.public ov69_021E76E8
	.public ov69_021E7708
	.public ov69_021E7728
	.public ov69_021E774C
	.public ov69_021E7770
	.public ov69_021E7794
	.public ov69_021E77B8
	.include "overlay_69.inc"
	.include "global.inc"

	.text
	.public GeonetGlobe_Exit
	.public ov69_021E6300
	.public ov69_021E67B8
	.public ov69_021E68D8
	.public ov69_021E6A54
	.public ov69_021E6C14
	.public ov69_021E6F48
	.public ov69_021E6F8C
	.public ov69_021E706C
	.public ov69_021E758C
	.public ov69_021E75F8

	thumb_func_start ov69_021E70A8
ov69_021E70A8: ; 0x021E70A8
	push {r4, r5, lr}
	sub sp, #0x24
	add r4, r1, #0
	ldr r1, [r4, #4]
	ldr r3, _021E711C ; =FX_SinCosTable_
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	asr r1, r1, #4
	lsl r2, r1, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r5, r0, #0
	bl MTX_RotY33_
	ldr r0, [r4]
	ldr r3, _021E711C ; =FX_SinCosTable_
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	asr r0, r0, #4
	lsl r2, r0, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0
	bl MTX_RotX33_
	add r0, r5, #0
	add r1, sp, #0
	add r2, r5, #0
	bl MTX_Concat33
	ldr r0, [r4, #8]
	ldr r3, _021E711C ; =FX_SinCosTable_
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	asr r0, r0, #4
	lsl r2, r0, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0
	bl MTX_RotZ33_
	add r0, r5, #0
	add r1, sp, #0
	add r2, r5, #0
	bl MTX_Concat33
	add sp, #0x24
	pop {r4, r5, pc}
	nop
_021E711C: .word FX_SinCosTable_
	thumb_func_end ov69_021E70A8


	thumb_func_start ov69_021E7120
ov69_021E7120: ; 0x021E7120
	push {r4, r5, lr}
	sub sp, #0x24
	add r4, r1, #0
	ldr r1, [r4]
	ldr r3, _021E7194 ; =FX_SinCosTable_
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	asr r1, r1, #4
	lsl r2, r1, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r5, r0, #0
	bl MTX_RotY33_
	ldr r0, [r4, #4]
	ldr r3, _021E7194 ; =FX_SinCosTable_
	neg r0, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	asr r0, r0, #4
	lsl r2, r0, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0
	bl MTX_RotX33_
	add r0, r5, #0
	add r1, sp, #0
	add r2, r5, #0
	bl MTX_Concat33
	ldr r0, [r4, #8]
	ldr r3, _021E7194 ; =FX_SinCosTable_
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	asr r0, r0, #4
	lsl r2, r0, #1
	add r1, r2, #1
	lsl r1, r1, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0
	bl MTX_RotZ33_
	add r0, r5, #0
	add r1, sp, #0
	add r2, r5, #0
	bl MTX_Concat33
	add sp, #0x24
	pop {r4, r5, pc}
	.balign 4, 0
_021E7194: .word FX_SinCosTable_
	thumb_func_end ov69_021E7120


	thumb_func_start ov69_021E7198
ov69_021E7198: ; 0x021E7198
	push {r3, r4, r5, r6, r7, lr}
	add r3, r0, #0
	ldr r0, _021E735C ; =0x0000C2C4
	add r7, r2, #0
	add r4, r0, #4
	ldr r4, [r3, r4]
	ldr r2, [r3, r0]
	lsl r4, r4, #0x10
	asr r4, r4, #0x10
	lsl r2, r2, #0x10
	mov lr, r4
	mov r4, #1
	mov r6, #0
	asr r2, r2, #0x10
	tst r1, r4
	bne _021E71C4
	add r1, r0, #0
	add r1, #0x44
	ldr r1, [r3, r1]
	mov ip, r1
	tst r1, r4
	beq _021E71E8
_021E71C4:
	ldr r1, _021E7360 ; =0x0000C304
	ldrh r0, [r3, r1]
	cmp r0, #1
	bne _021E71E4
	add r0, r1, #0
	sub r0, #0x1c
	ldrh r0, [r3, r0]
	cmp r0, #0
	bne _021E71DE
	mov r0, #1
	sub r1, #0x1c
	strh r0, [r3, r1]
	b _021E71E4
_021E71DE:
	mov r0, #0
	sub r1, #0x1c
	strh r0, [r3, r1]
_021E71E4:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E71E8:
	add r1, r0, #0
	add r1, #0x24
	ldrh r1, [r3, r1]
	cmp r1, #0
	bne _021E7220
	add r1, r0, #0
	add r1, #0x54
	ldr r1, [r3, r1]
	cmp r1, #0
	bne _021E7204
	add r0, #0x58
	ldr r0, [r3, r0]
	cmp r0, #0
	beq _021E721A
_021E7204:
	add r0, r1, #0
	ldr r1, _021E7364 ; =0x0000C31C
	mov r4, #0x55
	ldr r1, [r3, r1]
	mul r0, r4
	mul r4, r1
	lsl r0, r0, #0x10
	lsl r1, r4, #0x10
	lsr r0, r0, #0x10
	lsr r1, r1, #0x10
	b _021E724C
_021E721A:
	lsl r0, r4, #9
	add r1, r0, #0
	b _021E724C
_021E7220:
	add r1, r0, #0
	add r1, #0x54
	ldr r1, [r3, r1]
	cmp r1, #0
	bne _021E7232
	add r0, #0x58
	ldr r0, [r3, r0]
	cmp r0, #0
	beq _021E7248
_021E7232:
	add r0, r1, #0
	ldr r1, _021E7364 ; =0x0000C31C
	mov r4, #0xa
	ldr r1, [r3, r1]
	mul r0, r4
	mul r4, r1
	lsl r0, r0, #0x10
	lsl r1, r4, #0x10
	lsr r0, r0, #0x10
	lsr r1, r1, #0x10
	b _021E724C
_021E7248:
	mov r0, #0x20
	add r1, r0, #0
_021E724C:
	mov r4, #0x20
	tst r4, r7
	bne _021E725A
	mov r5, ip
	mov r4, #0x20
	tst r4, r5
	beq _021E7286
_021E725A:
	ldr r6, _021E7360 ; =0x0000C304
	ldrh r4, [r3, r6]
	cmp r4, #1
	bne _021E7270
	add r4, r6, #0
	sub r4, #0x3c
	ldr r4, [r3, r4]
	sub r6, #0x3c
	add r4, r4, r0
	str r4, [r3, r6]
	b _021E7284
_021E7270:
	ldr r5, _021E7368 ; =0xFFFFD820
	mov r4, lr
	cmp r4, r5
	bge _021E7284
	add r4, r6, #0
	sub r4, #0x3c
	ldr r4, [r3, r4]
	sub r6, #0x3c
	add r4, r4, r0
	str r4, [r3, r6]
_021E7284:
	mov r6, #1
_021E7286:
	mov r4, #0x10
	tst r4, r7
	bne _021E7296
	ldr r4, _021E736C ; =0x0000C308
	ldr r5, [r3, r4]
	mov r4, #0x10
	tst r4, r5
	beq _021E72C2
_021E7296:
	ldr r5, _021E7360 ; =0x0000C304
	ldrh r4, [r3, r5]
	cmp r4, #1
	bne _021E72AC
	add r4, r5, #0
	sub r4, #0x3c
	ldr r4, [r3, r4]
	sub r5, #0x3c
	sub r0, r4, r0
	str r0, [r3, r5]
	b _021E72C0
_021E72AC:
	ldr r4, _021E7370 ; =0xFFFFCC80
	mov r6, lr
	cmp r6, r4
	ble _021E72C0
	add r4, r5, #0
	sub r4, #0x3c
	ldr r4, [r3, r4]
	sub r5, #0x3c
	sub r0, r4, r0
	str r0, [r3, r5]
_021E72C0:
	mov r6, #1
_021E72C2:
	mov r4, #0x40
	add r0, r7, #0
	tst r0, r4
	bne _021E72D2
	ldr r0, _021E736C ; =0x0000C308
	ldr r0, [r3, r0]
	tst r0, r4
	beq _021E730C
_021E72D2:
	ldr r4, _021E7360 ; =0x0000C304
	ldrh r0, [r3, r4]
	cmp r0, #1
	bne _021E72F8
	mov r0, #0x3e
	add r5, r2, r1
	lsl r0, r0, #8
	cmp r5, r0
	bge _021E72F2
	add r0, r4, #0
	sub r0, #0x40
	ldr r0, [r3, r0]
	sub r4, #0x40
	add r0, r0, r1
	str r0, [r3, r4]
	b _021E730A
_021E72F2:
	sub r4, #0x40
	str r0, [r3, r4]
	b _021E730A
_021E72F8:
	ldr r0, _021E7374 ; =0x00002020
	cmp r2, r0
	bge _021E730A
	add r0, r4, #0
	sub r0, #0x40
	ldr r0, [r3, r0]
	sub r4, #0x40
	add r0, r0, r1
	str r0, [r3, r4]
_021E730A:
	mov r6, #1
_021E730C:
	mov r4, #0x80
	add r0, r7, #0
	tst r0, r4
	bne _021E731C
	ldr r0, _021E736C ; =0x0000C308
	ldr r0, [r3, r0]
	tst r0, r4
	beq _021E7356
_021E731C:
	ldr r4, _021E7360 ; =0x0000C304
	ldrh r0, [r3, r4]
	cmp r0, #1
	bne _021E7340
	ldr r0, _021E7378 ; =0xFFFFC200
	sub r2, r2, r1
	cmp r2, r0
	ble _021E733A
	add r0, r4, #0
	sub r0, #0x40
	ldr r0, [r3, r0]
	sub r4, #0x40
	sub r0, r0, r1
	str r0, [r3, r4]
	b _021E7354
_021E733A:
	sub r4, #0x40
	str r0, [r3, r4]
	b _021E7354
_021E7340:
	mov r0, #0x13
	lsl r0, r0, #8
	cmp r2, r0
	ble _021E7354
	add r0, r4, #0
	sub r0, #0x40
	ldr r0, [r3, r0]
	sub r4, #0x40
	sub r0, r0, r1
	str r0, [r3, r4]
_021E7354:
	mov r6, #1
_021E7356:
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E735C: .word 0x0000C2C4
_021E7360: .word 0x0000C304
_021E7364: .word 0x0000C31C
_021E7368: .word 0xFFFFD820
_021E736C: .word 0x0000C308
_021E7370: .word 0xFFFFCC80
_021E7374: .word 0x00002020
_021E7378: .word 0xFFFFC200
	thumb_func_end ov69_021E7198


	thumb_func_start ov69_021E737C
ov69_021E737C: ; 0x021E737C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _021E7400 ; =0x0000C2DC
	ldr r0, [r5, r0]
	bl Camera_GetDistance
	ldr r1, _021E7404 ; =0x0000C2E8
	mov r4, #0
	ldrh r2, [r5, r1]
	cmp r2, #0
	beq _021E73C6
	cmp r2, #1
	bne _021E73F4
	mov r2, #0x16
	lsl r2, r2, #0xe
	cmp r0, r2
	ble _021E73BE
	mov r2, #2
	lsl r2, r2, #0xe
	sub r0, r0, r2
	add r2, r1, #0
	sub r2, #0x18
	ldr r3, [r5, r2]
	add r2, r1, #0
	sub r3, #0x80
	sub r2, #0x18
	str r3, [r5, r2]
	add r2, r1, #0
	sub r2, #0x18
	ldr r2, [r5, r2]
	sub r1, #0x14
	str r2, [r5, r1]
	b _021E73F4
_021E73BE:
	mov r0, #5
	lsl r0, r0, #0x10
	mov r4, #1
	b _021E73F4
_021E73C6:
	mov r2, #0x12
	lsl r2, r2, #0x10
	cmp r0, r2
	bge _021E73EE
	mov r2, #2
	lsl r2, r2, #0xe
	add r0, r0, r2
	add r2, r1, #0
	sub r2, #0x18
	ldr r3, [r5, r2]
	add r2, r1, #0
	add r3, #0x80
	sub r2, #0x18
	str r3, [r5, r2]
	add r2, r1, #0
	sub r2, #0x18
	ldr r2, [r5, r2]
	sub r1, #0x14
	str r2, [r5, r1]
	b _021E73F4
_021E73EE:
	mov r0, #0x4a
	lsl r0, r0, #0xe
	mov r4, #1
_021E73F4:
	ldr r1, _021E7400 ; =0x0000C2DC
	ldr r1, [r5, r1]
	bl Camera_SetDistance
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E7400: .word 0x0000C2DC
_021E7404: .word 0x0000C2E8
	thumb_func_end ov69_021E737C


	thumb_func_start ov69_021E7408
ov69_021E7408: ; 0x021E7408
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x70
	ldr r4, _021E74F8 ; =ov69_021E7728
	add r5, r0, #0
	add r3, sp, #0x4c
	mov r2, #4
_021E7414:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E7414
	ldr r0, [r4]
	str r0, [r3]
	ldr r0, _021E74FC ; =0x0000C2F8
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021E74F2
	cmp r0, #1
	beq _021E7446
	cmp r0, #2
	bne _021E74F2
	bl Thunk_G3X_Reset
	mov r0, #0
	mov r1, #1
	bl RequestSwap3DBuffers
	ldr r0, _021E74FC ; =0x0000C2F8
	mov r1, #0
	add sp, #0x70
	str r1, [r5, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021E7446:
	bl Thunk_G3X_Reset
	bl Camera_PushLookAtToNNSGlb
	ldr r1, _021E7500 ; =0x0000C2C4
	add r0, sp, #0x4c
	add r1, r5, r1
	bl ov69_021E70A8
	ldr r3, _021E7504 ; =0x0000C2AC
	ldr r0, _021E7508 ; =0x0000C084
	add r1, r5, r3
	add r3, #0xc
	add r0, r5, r0
	add r2, sp, #0x4c
	add r3, r5, r3
	bl GF3dRender_DrawModel
	ldr r4, _021E750C ; =ov69_021E7794
	add r3, sp, #0x28
	mov r2, #4
_021E7470:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E7470
	ldr r0, [r4]
	add r2, sp, #0x28
	str r0, [r3]
	ldr r3, _021E7510 ; =0x0000C230
	add r1, r3, #0
	add r0, r5, r3
	add r1, #0x7c
	add r3, #0xa0
	add r1, r5, r1
	add r3, r5, r3
	bl GF3dRender_DrawModel
	ldr r4, _021E7514 ; =ov69_021E774C
	add r3, sp, #4
	mov r2, #4
_021E7496:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E7496
	ldr r0, [r4]
	mov r7, #0
	str r0, [r3]
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bls _021E74EA
	ldr r0, _021E7518 ; =0x0000C0E0
	add r6, r5, #0
	add r0, r5, r0
	add r6, #0x14
	add r4, r5, #0
	str r0, [sp]
_021E74B6:
	add r0, r6, #0
	add r1, sp, #0x4c
	add r2, sp, #4
	bl MTX_Concat33
	ldrh r2, [r4, #0x38]
	cmp r2, #0
	beq _021E74DE
	add r1, r2, #0
	mov r0, #0x54
	mul r1, r0
	ldr r0, [sp]
	ldr r3, _021E751C ; =0x0000C2D0
	add r0, r0, r1
	ldr r1, _021E7504 ; =0x0000C2AC
	add r2, sp, #4
	add r1, r5, r1
	add r3, r5, r3
	bl GF3dRender_DrawModel
_021E74DE:
	ldr r0, [r5, #0xc]
	add r7, r7, #1
	add r6, #0x30
	add r4, #0x30
	cmp r7, r0
	blo _021E74B6
_021E74EA:
	mov r0, #0
	mov r1, #1
	bl RequestSwap3DBuffers
_021E74F2:
	add sp, #0x70
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E74F8: .word ov69_021E7728
_021E74FC: .word 0x0000C2F8
_021E7500: .word 0x0000C2C4
_021E7504: .word 0x0000C2AC
_021E7508: .word 0x0000C084
_021E750C: .word ov69_021E7794
_021E7510: .word 0x0000C230
_021E7514: .word ov69_021E774C
_021E7518: .word 0x0000C0E0
_021E751C: .word 0x0000C2D0
	thumb_func_end ov69_021E7408


	thumb_func_start ov69_021E7520
ov69_021E7520: ; 0x021E7520
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	str r1, [sp]
	add r6, r2, #0
	str r3, [sp, #4]
	bl ov69_021E6300
	ldr r7, [sp, #0x20]
	add r4, r0, #0
	ldr r2, _021E7588 ; =0x0000031E
	mov r0, #0
	mov r1, #0x1b
	add r3, r7, #0
	bl NewMsgDataFromNarc
	str r0, [sp, #8]
	add r1, r5, #0
	add r2, r6, #0
	bl ReadMsgDataIntoString
	ldr r0, [sp, #8]
	bl DestroyMsgData
	cmp r4, #0
	bne _021E755C
	mov r5, #0
	mov r4, #1
	str r5, [sp]
	b _021E755E
_021E755C:
	mov r5, #1
_021E755E:
	add r0, r4, #0
	bl LocationGmmDatGetGmmNo
	add r2, r0, #0
	mov r0, #0
	mov r1, #0x1b
	add r3, r7, #0
	bl NewMsgDataFromNarc
	ldr r1, [sp]
	ldr r2, [sp, #4]
	add r4, r0, #0
	bl ReadMsgDataIntoString
	add r0, r4, #0
	bl DestroyMsgData
	add r0, r5, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_021E7588: .word 0x0000031E
	thumb_func_end ov69_021E7520
