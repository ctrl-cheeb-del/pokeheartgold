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

	thumb_func_start ov27_0225BED8
ov27_0225BED8: ; 0x0225BED8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	ldr r5, [sp, #0x44]
	add r4, r0, #0
	str r3, [sp]
	add r0, sp, #0x28
	add r7, r1, #0
	ldrb r1, [r0, #0x10]
	add r6, r2, #0
	mov r2, #5
	str r1, [sp, #4]
	ldrb r0, [r0, #0x14]
	add r1, sp, #0x14
	add r3, r6, #0
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x40]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [r4, #4]
	bl AddWindowParameterized
	add r0, sp, #0x14
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r1, _0225BF7C ; =0x000004AC
	add r2, r7, #0
	ldr r0, [r4, r1]
	sub r1, r1, #4
	ldr r1, [r4, r1]
	mov r3, #8
	bl ReadMsgData_ExpandPlaceholders
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r5, r0
	bne _0225BF48
	mov r0, #0
	add r1, r4, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	add r1, sp, #0x28
	ldrb r1, [r1, #0x10]
	lsl r1, r1, #3
	sub r0, r1, r0
	lsl r0, r0, #0x10
	asr r1, r0, #0x10
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0xf
	asr r5, r0, #0x10
_0225BF48:
	add r1, sp, #0x28
	mov r0, #0x20
	ldrsh r0, [r1, r0]
	mov r1, #0
	add r2, r4, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225BF80 ; =0x000E0200
	add r3, r5, #0
	str r0, [sp, #8]
	add r0, sp, #0x14
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	add r0, sp, #0x14
	bl CopyWindowToVram
	add r0, sp, #0x14
	bl RemoveWindow
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0225BF7C: .word 0x000004AC
_0225BF80: .word 0x000E0200
	thumb_func_end ov27_0225BED8


	thumb_func_start ov27_0225BF84
ov27_0225BF84: ; 0x0225BF84
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r4, r1, #0
	mov r1, #0
	add r5, r0, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _0225BFC4 ; =0x000004AC
	add r6, r2, #0
	add r2, r3, #0
	ldr r0, [r5, r0]
	mov r3, #2
	bl BufferIntegerAsString
	mov r0, #6
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _0225BFC8 ; =0x00000186
	mov r1, #0x1f
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	add r0, r5, #0
	add r2, r4, #0
	add r3, r6, #0
	bl ov27_0225BED8
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0225BFC4: .word 0x000004AC
_0225BFC8: .word 0x00000186
	thumb_func_end ov27_0225BF84


	thumb_func_start ov27_0225BFCC
ov27_0225BFCC: ; 0x0225BFCC
	push {r3, r4, lr}
	sub sp, #0x14
	add r4, r0, #0
	ldr r0, [r1, #0x10]
	mov r1, #0xa1
	mov r2, #0
	bl GetMonData
	mov r1, #0
	add r2, r0, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _0225C014 ; =0x000004AC
	mov r3, #3
	ldr r0, [r4, r0]
	bl BufferIntegerAsString
	mov r0, #6
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _0225C018 ; =0x00000192
	mov r1, #0x21
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	add r0, r4, #0
	mov r2, #0xc
	mov r3, #0x15
	bl ov27_0225BED8
	add sp, #0x14
	pop {r3, r4, pc}
	.balign 4, 0
_0225C014: .word 0x000004AC
_0225C018: .word 0x00000192
	thumb_func_end ov27_0225BFCC
