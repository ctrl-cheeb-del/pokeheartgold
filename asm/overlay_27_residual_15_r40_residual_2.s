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
	.public ov27_0225C170


	thumb_func_start ov27_0225C1AC
ov27_0225C1AC: ; 0x0225C1AC
	push {r4, r5, r6, r7}
	mov r5, #0
	mov r6, #0
	mov r2, #0x47
	mvn r5, r5
	add r4, r6, #0
	add r7, r0, #0
	lsl r2, r2, #4
_0225C1BC:
	ldrb r3, [r7, r2]
	cmp r3, #0
	beq _0225C1CC
	cmp r1, r6
	bne _0225C1CA
	add r5, r4, #0
	b _0225C1D4
_0225C1CA:
	add r6, r6, #1
_0225C1CC:
	add r4, r4, #1
	add r7, #8
	cmp r4, #7
	blt _0225C1BC
_0225C1D4:
	mov r1, #0
	mvn r1, r1
	cmp r5, r1
	bne _0225C1E4
	ldr r0, [r0, #0x10]
	mov r5, #0
	add r0, #0xd3
	strb r5, [r0]
_0225C1E4:
	add r0, r5, #0
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
	thumb_func_end ov27_0225C1AC




	thumb_func_start ov27_0225C1EC
ov27_0225C1EC: ; 0x0225C1EC
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne _0225C1FA
	bl GF_AssertFail
_0225C1FA:
	ldr r0, [r4, #0x14]
	lsl r0, r0, #3
	add r1, r4, r0
	mov r0, #0x47
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _0225C236
	mov r0, #0x47
	mov r2, #0
	add r3, r4, #0
	lsl r0, r0, #4
_0225C212:
	ldrb r1, [r3, r0]
	cmp r1, #0
	beq _0225C22E
	ldr r0, [r4, #0x10]
	add r0, #0xd3
	strb r2, [r0]
	ldr r1, [r4, #0x10]
	add r0, r4, #0
	add r1, #0xd3
	ldrb r1, [r1]
	bl ov27_0225C1AC
	str r0, [r4, #0x14]
	pop {r4, pc}
_0225C22E:
	add r2, r2, #1
	add r3, #8
	cmp r2, #7
	blt _0225C212
_0225C236:
	pop {r4, pc}
	thumb_func_end ov27_0225C1EC
