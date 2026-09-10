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

	thumb_func_start ov27_0225CA98
ov27_0225CA98: ; 0x0225CA98
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x85
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	sub r0, r0, #2
	lsl r1, r0, #2
	ldr r0, _0225CC84 ; =ov27_0225D49C
	ldr r0, [r0, r1]
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0225CAF6
	mov r2, #0xe5
	lsl r2, r2, #2
	str r0, [r4, r2]
	mov r1, #0x85
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	add r0, r4, #0
	bl ov27_0225CD18
	ldr r0, _0225CC88 ; =0x000005DC
	bl PlaySE
	mov r0, #9
	mov r1, #0x85
	str r0, [r4]
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r4, #0
	bl ov27_0225CD74
	mov r1, #0xe7
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	cmp r2, #0
	beq _0225CB60
	add r0, r1, #4
	sub r1, #8
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	blx r2
	b _0225CC80
_0225CAF6:
	ldr r0, _0225CC8C ; =gSystem
	mov r1, #0x40
	ldr r0, [r0, #0x48]
	tst r1, r0
	beq _0225CB44
	mov r1, #0x85
	mov r0, #0xe5
	lsl r1, r1, #2
	lsl r0, r0, #2
	ldr r1, [r4, r1]
	add r0, r4, r0
	mov r2, #0
	bl ov27_0225CA68
	cmp r0, #0
	beq _0225CB60
	mov r1, #0x85
	mov r2, #0xe5
	lsl r1, r1, #2
	lsl r2, r2, #2
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	add r0, r4, #0
	bl ov27_0225CD18
	ldr r0, _0225CC88 ; =0x000005DC
	bl PlaySE
	mov r1, #0xe7
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	cmp r2, #0
	beq _0225CB60
	add r0, r1, #4
	sub r1, #8
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	blx r2
	b _0225CC80
_0225CB44:
	mov r1, #0x80
	tst r1, r0
	beq _0225CB90
	mov r1, #0x85
	mov r0, #0xe5
	lsl r1, r1, #2
	lsl r0, r0, #2
	ldr r1, [r4, r1]
	add r0, r4, r0
	mov r2, #1
	bl ov27_0225CA68
	cmp r0, #0
	bne _0225CB62
_0225CB60:
	b _0225CC80
_0225CB62:
	mov r1, #0x85
	mov r2, #0xe5
	lsl r1, r1, #2
	lsl r2, r2, #2
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	add r0, r4, #0
	bl ov27_0225CD18
	ldr r0, _0225CC88 ; =0x000005DC
	bl PlaySE
	mov r1, #0xe7
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	cmp r2, #0
	beq _0225CC80
	add r0, r1, #4
	sub r1, #8
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	blx r2
	b _0225CC80
_0225CB90:
	mov r1, #0x20
	tst r1, r0
	beq _0225CBDA
	mov r1, #0x85
	mov r0, #0xe5
	lsl r1, r1, #2
	lsl r0, r0, #2
	ldr r1, [r4, r1]
	add r0, r4, r0
	mov r2, #2
	bl ov27_0225CA68
	cmp r0, #0
	beq _0225CC80
	mov r1, #0x85
	mov r2, #0xe5
	lsl r1, r1, #2
	lsl r2, r2, #2
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	add r0, r4, #0
	bl ov27_0225CD18
	ldr r0, _0225CC88 ; =0x000005DC
	bl PlaySE
	mov r1, #0xe7
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	cmp r2, #0
	beq _0225CC80
	add r0, r1, #4
	sub r1, #8
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	blx r2
	b _0225CC80
_0225CBDA:
	mov r1, #0x10
	tst r1, r0
	beq _0225CC24
	mov r1, #0x85
	mov r0, #0xe5
	lsl r1, r1, #2
	lsl r0, r0, #2
	ldr r1, [r4, r1]
	add r0, r4, r0
	mov r2, #3
	bl ov27_0225CA68
	cmp r0, #0
	beq _0225CC80
	mov r1, #0x85
	mov r2, #0xe5
	lsl r1, r1, #2
	lsl r2, r2, #2
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	add r0, r4, #0
	bl ov27_0225CD18
	ldr r0, _0225CC88 ; =0x000005DC
	bl PlaySE
	mov r1, #0xe7
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	cmp r2, #0
	beq _0225CC80
	add r0, r1, #4
	sub r1, #8
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	blx r2
	b _0225CC80
_0225CC24:
	mov r1, #1
	tst r1, r0
	beq _0225CC42
	mov r1, #0x85
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r4, #0
	bl ov27_0225CD74
	mov r0, #9
	str r0, [r4]
	ldr r0, _0225CC88 ; =0x000005DC
	bl PlaySE
	b _0225CC80
_0225CC42:
	mov r1, #2
	tst r0, r1
	beq _0225CC80
	ldr r0, [r4, #0xc]
	bl ov01_021EF00C
	cmp r0, #0
	beq _0225CC80
	mov r1, #0x85
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	mov r2, #0xe5
	sub r0, r0, #1
	lsl r2, r2, #2
	str r0, [r4, r2]
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	add r0, r4, #0
	bl ov27_0225CD18
	mov r1, #0x85
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r4, #0
	bl ov27_0225CD74
	mov r0, #9
	str r0, [r4]
	ldr r0, _0225CC88 ; =0x000005DC
	bl PlaySE
_0225CC80:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_0225CC84: .word ov27_0225D49C
_0225CC88: .word 0x000005DC
_0225CC8C: .word gSystem
	thumb_func_end ov27_0225CA98
