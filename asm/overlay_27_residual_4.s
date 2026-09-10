	.include "asm/macros.inc"
	.include "overlay_27.inc"
	.include "global.inc"

	.text
	.public _0225CEBC
	.public ov27_02259F80
	.public ov27_0225A19C
	.public ov27_0225A320
	.public ov27_0225A4D0
	.public ov27_0225A530
	.public ov27_0225A594
	.public ov27_0225A61C
	.public ov27_0225A690
	.public ov27_0225A714
	.public ov27_0225A7FC
	.public ov27_0225A89C
	.public ov27_0225A8E8
	.public ov27_0225A9C0
	.public ov27_0225AA7C
	.public ov27_0225AAD4
	.public ov27_0225AC00
	.public ov27_0225AD0C
	.public ov27_0225AEA8
	.public ov27_0225B010
	.public ov27_0225B360
	.public ov27_0225B398
	.public ov27_0225B404
	.public ov27_0225B4D8
	.public ov27_0225B630
	.public ov27_0225BB6C
	.public ov27_0225BC34
	.public ov27_0225BC84
	.public ov27_0225BCE8
	.public ov27_0225BD50
	.public ov27_0225BDFC
	.public ov27_0225BED8
	.public ov27_0225BF84
	.public ov27_0225BFCC
	.public ov27_0225C088
	.public ov27_0225C10C
	.public ov27_0225C170
	.public ov27_0225C1AC
	.public ov27_0225C1EC
	.public ov27_0225C250
	.public ov27_0225C398
	.public ov27_0225C434
	.public ov27_0225C4AC
	.public ov27_0225C540
	.public ov27_0225C618
	.public ov27_0225C72C
	.public ov27_0225C80C
	.public ov27_0225C9F8
	.public ov27_0225CA14
	.public ov27_0225CA98
	.public ov27_0225CD18
	.public ov27_0225CD94
	.public ov27_0225CEAC
	.public ov27_0225CEC4
	.public ov27_0225CECC
	.public ov27_0225CED8
	.public ov27_0225CEEC
	.public ov27_0225CEF0
	.public ov27_0225CEF4
	.public ov27_0225CF10
	.public ov27_0225CF3C
	.public ov27_0225CF68
	.public ov27_0225CF94
	.public ov27_0225CFC8
	.public ov27_0225D000
	.public ov27_0225D01C
	.public ov27_0225D038
	.public ov27_0225D05C
	.public ov27_0225D074
	.public ov27_0225D0B4
	.public ov27_0225D108
	.public ov27_0225D110
	.public ov27_0225D118
	.public ov27_0225D11A
	.public ov27_0225D120
	.public ov27_0225D12C
	.public ov27_0225D138
	.public ov27_0225D144
	.public ov27_0225D154
	.public ov27_0225D164
	.public ov27_0225D174
	.public ov27_0225D188
	.public ov27_0225D19C
	.public ov27_0225D1B4
	.public ov27_0225D1CC
	.public ov27_0225D1E4
	.public ov27_0225D200
	.public ov27_0225D21C
	.public ov27_0225D23C
	.public ov27_0225D25C
	.public ov27_0225D27C
	.public ov27_0225D2A0
	.public ov27_0225D2C8
	.public ov27_0225D2F8
	.public ov27_0225D330
	.public ov27_0225D370
	.public ov27_0225D38C
	.public ov27_0225D3A8
	.public ov27_0225D3C4
	.public ov27_0225D3C5
	.public ov27_0225D3C6
	.public ov27_0225D480
	.public ov27_0225D49C
	.public ov27_0225D4B8
	.public ov27_0225D4D4

	.public ov27_0225A2C8
	.public ov27_0225A2CC
	.public ov27_0225A2EC
	.public ov27_0225A468
	.public ov27_0225A48C
	.public ov27_0225A4B8
	.public ov27_0225A66C
	.public ov27_0225A7B0
	.public ov27_0225A7DC
	.public ov27_0225A86C
	.public ov27_0225AA60
	.public ov27_0225AE8C
	.public ov27_0225B4AC
	.public ov27_0225BB38
	.public ov27_0225BD44
	.public ov27_0225BDAC
	.public ov27_0225BDC8
	.public ov27_0225BDDC
	.public ov27_0225BEB0
	.public ov27_0225C01C
	.public ov27_0225C044
	.public ov27_0225C06C
	.public ov27_0225C0E0
	.public ov27_0225C238
	.public ov27_0225C248
	.public ov27_0225C24C
	.public ov27_0225C418
	.public ov27_0225C41C
	.public ov27_0225C5E4
	.public ov27_0225C6F8
	.public ov27_0225C8D0
	.public ov27_0225C914
	.public ov27_0225C930
	.public ov27_0225C944
	.public ov27_0225C94C
	.public ov27_0225C988
	.public ov27_0225C994
	.public ov27_0225C9CC
	.public ov27_0225C9E4
	.public ov27_0225CA68
	.public ov27_0225CC90
	.public ov27_0225CCBC
	.public ov27_0225CCE0
	.public ov27_0225CD74

	thumb_func_start ov27_0225A690
ov27_0225A690: ; 0x0225A690
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #0
	beq _0225A6C0
	ldr r2, _0225A710 ; =0x0000051C
	mov r1, #1
	ldr r3, [r4, r2]
	bic r3, r1
	mov r1, #1
	orr r1, r3
	str r1, [r4, r2]
	bl ov27_0225A4D0
	add r0, r4, #0
	mov r1, #1
	bl ov27_0225A9C0
	mov r0, #0xf
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	pop {r4, pc}
_0225A6C0:
	ldr r1, _0225A710 ; =0x0000051C
	mov r0, #1
	ldr r2, [r4, r1]
	bic r2, r0
	mov r0, #0x3d
	lsl r0, r0, #4
	str r2, [r4, r1]
	add r0, r4, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x3d
	lsl r0, r0, #4
	add r0, r4, r0
	bl CopyWindowToVram
	mov r0, #0xf
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0xef
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0xf1
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	mov r1, #0
	bl ov27_0225A9C0
	pop {r4, pc}
	nop
_0225A710: .word 0x0000051C
	thumb_func_end ov27_0225A690


	thumb_func_start ov27_0225A714
ov27_0225A714: ; 0x0225A714
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne _0225A722
	bl GF_AssertFail
_0225A722:
	ldr r4, [r5, #0x10]
	ldr r6, [r5, #0xc]
	add r0, r4, #0
	add r0, #0xd2
	ldrb r0, [r0]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1a
	cmp r0, #4
	bne _0225A75C
	mov r0, #0x43
	lsl r0, r0, #2
	add r0, r4, r0
	bl MenuInputStateMgr_GetState
	cmp r0, #0
	bne _0225A74C
	add r0, r5, #0
	mov r1, #1
	bl ov27_0225A8E8
	b _0225A7AC
_0225A74C:
	add r0, r4, #0
	add r0, #0xd2
	ldrb r1, [r0]
	mov r0, #0x3f
	add r4, #0xd2
	bic r1, r0
	strb r1, [r4]
	b _0225A7AC
_0225A75C:
	cmp r0, #3
	bne _0225A7AC
	mov r0, #0x43
	lsl r0, r0, #2
	add r0, r4, r0
	bl MenuInputStateMgr_GetState
	cmp r0, #1
	bne _0225A792
	mov r0, #1
	strh r0, [r6]
	add r0, r4, #0
	add r0, #0xd2
	ldrb r1, [r0]
	mov r0, #0x3f
	bic r1, r0
	add r0, r4, #0
	add r0, #0xd2
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0xd2
	ldrb r1, [r0]
	mov r0, #0x80
	add r4, #0xd2
	orr r0, r1
	strb r0, [r4]
	b _0225A7AC
_0225A792:
	ldr r1, [r5, #0x14]
	add r0, r5, #0
	bl ov27_0225B398
	add r0, r4, #0
	add r0, #0xd2
	ldrb r1, [r0]
	mov r0, #0x3f
	add r4, #0xd2
	bic r1, r0
	mov r0, #1
	orr r0, r1
	strb r0, [r4]
_0225A7AC:
	mov r0, #1
	pop {r4, r5, r6, pc}
	thumb_func_end ov27_0225A714
