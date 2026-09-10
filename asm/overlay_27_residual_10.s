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

	thumb_func_start ov27_0225BB6C
ov27_0225BB6C: ; 0x0225BB6C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x10]
	ldr r0, [r0, #0xc]
	bl Save_PlayerData_GetProfile
	add r2, r0, #0
	ldr r0, _0225BC10 ; =0x000004AC
	mov r1, #0
	ldr r0, [r5, r0]
	bl BufferPlayersName
	ldr r7, _0225BC14 ; =ov27_0225CFC8
	mov r4, #0
	add r6, r5, #0
_0225BB8A:
	ldr r0, _0225BC18 ; =0x0000051C
	ldr r0, [r5, r0]
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x1c
	lsl r0, r0, #3
	add r0, r7, r0
	ldrb r2, [r4, r0]
	cmp r2, #0xd
	beq _0225BBBA
	lsl r3, r2, #2
	ldr r2, _0225BC1C ; =ov27_0225CF94
	ldr r0, _0225BC10 ; =0x000004AC
	add r2, r2, r3
	ldrh r2, [r2, #2]
	ldr r1, _0225BC20 ; =0x000004A8
	ldr r0, [r5, r0]
	lsl r2, r2, #0x11
	ldr r1, [r5, r1]
	lsr r2, r2, #0x11
	mov r3, #8
	bl ReadMsgData_ExpandPlaceholders
	ldr r1, _0225BC24 ; =0x00000474
	str r0, [r6, r1]
_0225BBBA:
	add r4, r4, #1
	add r6, #8
	cmp r4, #7
	blt _0225BB8A
	ldr r4, _0225BC28 ; =ov27_0225CED8
	mov r7, #0
	add r6, r5, #0
_0225BBC8:
	ldr r0, _0225BC20 ; =0x000004A8
	ldr r1, [r4]
	ldr r0, [r5, r0]
	bl NewString_ReadMsgData
	mov r1, #0x4b
	lsl r1, r1, #4
	str r0, [r6, r1]
	add r7, r7, #1
	add r4, r4, #4
	add r6, r6, #4
	cmp r7, #5
	blt _0225BBC8
	sub r1, r1, #4
	ldr r0, [r5, r1]
	sub r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xc
	mov r3, #8
	bl ReadMsgData_ExpandPlaceholders
	ldr r1, _0225BC2C ; =0x000004C4
	mov r2, #0xd
	str r0, [r5, r1]
	add r0, r1, #0
	sub r0, #0x18
	sub r1, #0x1c
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	mov r3, #8
	bl ReadMsgData_ExpandPlaceholders
	ldr r1, _0225BC30 ; =0x000004C8
	str r0, [r5, r1]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225BC10: .word 0x000004AC
_0225BC14: .word ov27_0225CFC8
_0225BC18: .word 0x0000051C
_0225BC1C: .word ov27_0225CF94
_0225BC20: .word 0x000004A8
_0225BC24: .word 0x00000474
_0225BC28: .word ov27_0225CED8
_0225BC2C: .word 0x000004C4
_0225BC30: .word 0x000004C8
	thumb_func_end ov27_0225BB6C


	thumb_func_start ov27_0225BC34
ov27_0225BC34: ; 0x0225BC34
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _0225BC78 ; =0x000004C8
	ldr r0, [r5, r0]
	bl String_Delete
	ldr r0, _0225BC7C ; =0x000004C4
	ldr r0, [r5, r0]
	bl String_Delete
	mov r7, #0x4b
	mov r6, #0
	add r4, r5, #0
	lsl r7, r7, #4
_0225BC50:
	ldr r0, [r4, r7]
	bl String_Delete
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #5
	blt _0225BC50
	ldr r6, _0225BC80 ; =0x00000474
	mov r4, #0
_0225BC62:
	ldr r0, [r5, r6]
	cmp r0, #0
	beq _0225BC6C
	bl String_Delete
_0225BC6C:
	add r4, r4, #1
	add r5, #8
	cmp r4, #7
	blt _0225BC62
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225BC78: .word 0x000004C8
_0225BC7C: .word 0x000004C4
_0225BC80: .word 0x00000474
	thumb_func_end ov27_0225BC34


	thumb_func_start ov27_0225BC84
ov27_0225BC84: ; 0x0225BC84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	mov r7, #0
	str r0, [sp]
	add r4, r7, #0
	add r5, sp, #4
_0225BC90:
	ldr r0, [sp]
	add r1, r4, #0
	ldr r0, [r0, #0x10]
	bl FieldSystem_ShouldDrawStartMenuIcon
	add r4, r4, #1
	stmia r5!, {r0}
	cmp r4, #8
	blt _0225BC90
	mov r1, #0x3f
	ldr r0, [sp]
	lsl r1, r1, #4
	mov r6, #0
	add r4, sp, #4
	add r5, r0, r1
_0225BCAE:
	ldr r0, [r4]
	cmp r0, #0
	beq _0225BCBC
	add r0, r5, #0
	bl CopyWindowToVram
	add r7, r7, #1
_0225BCBC:
	add r6, r6, #1
	add r4, r4, #4
	add r5, #0x10
	cmp r6, #8
	blt _0225BCAE
	cmp r7, #0
	beq _0225BCE4
	mov r1, #0xf2
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r1, #0x3e
	ldr r0, [sp]
	lsl r1, r1, #4
	add r0, r0, r1
	bl CopyWindowToVram
_0225BCE4:
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov27_0225BC84


	thumb_func_start ov27_0225BCE8
ov27_0225BCE8: ; 0x0225BCE8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #4
	mov r6, #0
	add r4, r5, r0
_0225BCF6:
	ldr r0, _0225BD3C ; =0x00000474
	ldr r1, [r5, r0]
	cmp r1, #0
	beq _0225BD2C
	mov r0, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0x48
	sub r3, r1, r0
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225BD40 ; =0x000E0200
	lsr r7, r3, #0x1f
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r2, _0225BD3C ; =0x00000474
	add r7, r3, r7
	ldr r2, [r5, r2]
	add r0, r4, #0
	mov r1, #0
	asr r3, r7, #1
	bl AddTextPrinterParameterizedWithColor
_0225BD2C:
	add r6, r6, #1
	add r5, #8
	add r4, #0x10
	cmp r6, #7
	blt _0225BCF6
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225BD3C: .word 0x00000474
_0225BD40: .word 0x000E0200
	thumb_func_end ov27_0225BCE8
