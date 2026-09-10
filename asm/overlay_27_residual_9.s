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

	thumb_func_start ov27_0225B4D8
ov27_0225B4D8: ; 0x0225B4D8
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x10]
	ldr r0, [r0, #0x40]
	bl PlayerAvatar_GetPlayerMoveState
	cmp r0, #0
	bne _0225B4F2
	ldr r0, _0225B624 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #0xf0
	tst r0, r1
	beq _0225B4F6
_0225B4F2:
	mov r0, #1
	pop {r4, r5, r6, pc}
_0225B4F6:
	ldr r0, _0225B628 ; =0x0000051C
	ldr r0, [r5, r0]
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x1c
	cmp r0, #5
	bne _0225B53E
	bl sub_0203769C
	add r4, r0, #0
	bl sub_02058740
	cmp r0, #0
	beq _0225B53A
	bl sub_02058258
	cmp r0, #0
	beq _0225B53A
	bl sub_02056EE0
	cmp r0, #0
	beq _0225B53A
	bl sub_02057A0C
	cmp r0, #0
	beq _0225B53A
	add r0, r4, #0
	bl sub_02057F18
	cmp r0, #0
	bne _0225B53A
	bl sub_02037958
	cmp r0, #0
	beq _0225B53E
_0225B53A:
	mov r0, #1
	pop {r4, r5, r6, pc}
_0225B53E:
	bl IsPaletteFadeFinished
	cmp r0, #0
	bne _0225B54A
	mov r0, #1
	pop {r4, r5, r6, pc}
_0225B54A:
	ldr r0, _0225B628 ; =0x0000051C
	ldr r0, [r5, r0]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0225B55A
	mov r0, #1
	pop {r4, r5, r6, pc}
_0225B55A:
	ldr r0, _0225B62C ; =ov27_0225CF68
	bl TouchscreenHitbox_FindRectAtTouchNew
	add r4, r0, #0
	cmp r4, #0
	ble _0225B57E
	cmp r4, #8
	bge _0225B57E
	sub r0, r4, #1
	lsl r0, r0, #3
	add r1, r5, r0
	mov r0, #0x47
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _0225B57E
	mov r0, #0
	pop {r4, r5, r6, pc}
_0225B57E:
	ldr r0, [r5, #0x10]
	ldr r0, [r0, #0xc]
	bl Save_Bag_Get
	add r6, r0, #0
	add r0, r4, #0
	sub r0, #8
	cmp r0, #1
	bhi _0225B5AC
	ldr r0, _0225B628 ; =0x0000051C
	ldr r0, [r5, r0]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	bne _0225B59E
	mov r0, #1
	pop {r4, r5, r6, pc}
_0225B59E:
	add r0, r5, #0
	bl ov27_0225BDAC
	cmp r0, #0
	bne _0225B5AC
	mov r0, #1
	pop {r4, r5, r6, pc}
_0225B5AC:
	cmp r4, #8
	bne _0225B5BE
	add r0, r6, #0
	bl Bag_GetRegisteredItem1
	cmp r0, #0
	bne _0225B5D0
	mov r0, #1
	pop {r4, r5, r6, pc}
_0225B5BE:
	cmp r4, #9
	bne _0225B5D0
	add r0, r6, #0
	bl Bag_GetRegisteredItem2
	cmp r0, #0
	bne _0225B5D0
	mov r0, #1
	pop {r4, r5, r6, pc}
_0225B5D0:
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _0225B620
	cmp r4, #0
	bne _0225B5E4
	ldr r0, [r5, #0xc]
	mov r1, #1
	strh r1, [r0]
	b _0225B61C
_0225B5E4:
	sub r1, r4, #1
	lsl r0, r1, #2
	add r2, r5, r0
	mov r0, #0x39
	lsl r0, r0, #4
	ldr r0, [r2, r0]
	cmp r0, #0
	beq _0225B61C
	cmp r4, #8
	bge _0225B60E
	str r1, [r5, #0x14]
	add r0, r5, #0
	bl ov27_0225C170
	ldr r1, [r5, #0x10]
	add r1, #0xd3
	strb r0, [r1]
	ldr r1, [r5, #0x14]
	add r0, r5, #0
	bl ov27_0225B398
_0225B60E:
	add r0, r5, #0
	sub r1, r4, #1
	bl ov27_0225C170
	add r1, r0, #2
	ldr r0, [r5, #0xc]
	strh r1, [r0]
_0225B61C:
	mov r0, #0
	pop {r4, r5, r6, pc}
_0225B620:
	mov r0, #1
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0225B624: .word gSystem
_0225B628: .word 0x0000051C
_0225B62C: .word ov27_0225CF68
	thumb_func_end ov27_0225B4D8


	thumb_func_start ov27_0225B630
ov27_0225B630: ; 0x0225B630
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r7, r0, #0
	str r1, [sp, #0x10]
	ldr r6, [r7]
	bl GetWindowX
	add r5, r0, #0
	add r0, r7, #0
	bl GetWindowY
	add r4, r0, #0
	add r0, r7, #0
	bl GetWindowWidth
	str r0, [sp, #0x14]
	add r0, r7, #0
	bl GetWindowHeight
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	cmp r0, #1
	beq _0225B666
	cmp r0, #2
	bne _0225B664
	b _0225B8C2
_0225B664:
	b _0225BB1E
_0225B666:
	sub r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #3
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0xa9
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	sub r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #2
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0xaa
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	sub r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #1
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0xab
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	sub r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x14]
	lsl r3, r5, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #5
	mov r2, #0xac
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x14]
	mov r1, #5
	add r7, r5, r0
	sub r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r7, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r2, #0xad
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #3
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0x64
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #2
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0x65
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #1
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0x66
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r7, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #5
	mov r2, #0x68
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #3
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0x84
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #2
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0x85
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #1
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0x86
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r7, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #5
	mov r2, #0x88
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x18]
	sub r3, r5, #3
	add r4, r4, r0
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0xa4
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #2
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0xa5
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #1
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #0xa6
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x14]
	lsl r3, r5, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #5
	mov r2, #0xa7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r7, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #5
	mov r2, #0xa8
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	b _0225BB22
_0225B8C2:
	sub r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #3
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	sub r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #2
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	sub r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #1
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	sub r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x14]
	lsl r3, r5, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #5
	mov r2, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x14]
	mov r1, #5
	add r7, r5, r0
	sub r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r7, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r2, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #3
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #2
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #1
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r7, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #5
	mov r2, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #3
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #2
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #1
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r7, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #5
	mov r2, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x18]
	sub r3, r5, #3
	add r4, r4, r0
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #2
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	sub r3, r5, #1
	str r0, [sp, #8]
	mov r0, #0
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #4
	mov r2, #7
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x14]
	lsl r3, r5, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #5
	mov r2, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #2
	lsl r3, r7, #0x18
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #5
	mov r2, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	b _0225BB22
_0225BB1E:
	bl GF_AssertFail
_0225BB22:
	add r0, r6, #0
	mov r1, #4
	bl ScheduleBgTilemapBufferTransfer
	add r0, r6, #0
	mov r1, #5
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov27_0225B630
