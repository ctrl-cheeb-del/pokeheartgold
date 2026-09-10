	.include "asm/macros.inc"
	.public ov34_0225D520
	.public ov34_0225D558
	.public ov34_0225D5A0
	.public ov34_0225D5F8
	.public ov34_0225D650
	.public ov34_0225D77C
	.public ov34_0225D7A8
	.public ov34_0225D87C
	.public ov34_0225D900
	.public ov34_0225D924
	.public ov34_0225DA50
	.public ov34_0225DB20
	.public ov34_0225DC00
	.public ov34_0225DC0C
	.public ov34_0225DC18
	.public ov34_0225DD04
	.public ov34_0225DDB8
	.public ov34_0225DE04
	.public ov34_0225DE94
	.public ov34_0225E020
	.public ov34_0225E0E4
	.public ov34_0225E164
	.public ov34_0225E1C4
	.public ov34_0225E2BC
	.public ov34_0225E348
	.public ov34_0225E428
	.public ov34_0225E4A8
	.public ov34_0225E4F8
	.public ov34_0225E560
	.public ov34_0225E56C
	.public ov34_0225E58C
	.public ov34_0225E5D4
	.public ov34_0225E5DC
	.public ov34_0225E5E4
	.public ov34_0225E5EC
	.public ov34_0225E630
	.public _0225E694
	.public ov34_0225E6A0
	.public ov34_0225E6AC
	.public ov34_0225E6C0
	.public ov34_0225E6DC
	.public ov34_0225E6F8
	.public ov34_0225E714
	.public ov34_0225E730
	.include "overlay_34.inc"
	.include "global.inc"

	.text

	thumb_func_start ov34_0225DC18
ov34_0225DC18: ; 0x0225DC18
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r7, r1, #0
	add r5, r0, #0
	mov r0, #0x38
	add r4, r7, #0
	mul r4, r0
	mov r0, #0x7e
	lsl r0, r0, #2
	add r6, r2, #0
	add r1, r5, r0
	ldr r0, [r6, #0x10]
	mov r3, #7
	str r0, [r1, r4]
	mov r0, #0x20
	str r0, [sp]
	str r3, [sp, #4]
	ldr r2, [r5, #0x24]
	add r2, #0xc
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r2, [r1, r4]
	mov r1, #0x18
	mul r1, r2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp, #0x10]
	add r1, r3, #0
	mul r3, r7
	str r0, [sp, #0x14]
	mov r0, #0x30
	add r3, r3, #2
	str r0, [sp, #0x18]
	lsl r3, r3, #0x18
	ldr r0, [r5, #0x14]
	mov r2, #0
	lsr r3, r3, #0x18
	bl CopyToBgTilemapRect
	mov r0, #0x72
	lsl r0, r0, #2
	add r7, r5, r0
	add r0, r7, r4
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x76
	lsl r0, r0, #2
	add r0, r5, r0
	str r0, [sp, #0x1c]
	add r0, r0, r4
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x7a
	lsl r0, r0, #2
	add r5, r5, r0
	add r0, r5, r4
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #1
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225DCFC ; =0x000F0200
	mov r3, #0
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	ldr r2, [r6]
	add r0, r7, r4
	bl AddTextPrinterParameterizedWithColor
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225DD00 ; =0x00010200
	mov r1, #1
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, [sp, #0x1c]
	ldr r2, [r6, #4]
	add r0, r0, r4
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, r4
	bl ScheduleWindowCopyToVram
	ldr r0, [sp, #0x1c]
	add r0, r0, r4
	bl ScheduleWindowCopyToVram
	ldr r2, [r6, #8]
	cmp r2, #0
	beq _0225DCF0
	mov r1, #1
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225DCFC ; =0x000F0200
	mov r3, #0
	str r0, [sp, #8]
	add r0, r5, r4
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
_0225DCF0:
	add r0, r5, r4
	bl ScheduleWindowCopyToVram
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225DCFC: .word 0x000F0200
_0225DD00: .word 0x00010200
	thumb_func_end ov34_0225DC18


	thumb_func_start ov34_0225DD04
ov34_0225DD04: ; 0x0225DD04
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0x27
	add r5, r0, #0
	lsl r1, r1, #4
	add r0, r1, #0
	ldr r2, [r5, r1]
	add r1, #0x18
	add r0, #0xdc
	ldrh r1, [r5, r1]
	ldr r0, [r2, r0]
	bl ov34_0225DC0C
	add r6, r0, #0
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	add r0, #0xd8
	ldr r7, [r1, r0]
	cmp r7, #3
	ble _0225DD2E
	mov r7, #3
_0225DD2E:
	mov r0, #0xa2
	lsl r0, r0, #2
	ldrh r1, [r5, r0]
	add r0, r0, #4
	ldr r0, [r5, r0]
	cmp r1, r0
	beq _0225DD4C
	add r0, r5, #0
	bl ov34_0225E560
	mov r0, #0xa2
	lsl r0, r0, #2
	ldrh r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
_0225DD4C:
	mov r0, #0xa5
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _0225DDB6
	mov r4, #0
	cmp r7, #0
	ble _0225DD84
_0225DD5C:
	mov r2, #0x27
	lsl r2, r2, #4
	mov r3, #0x1c
	ldr r2, [r5, r2]
	mul r3, r6
	add r0, r5, #0
	add r1, r4, #0
	add r2, r2, r3
	bl ov34_0225DC18
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r6, #0
	bl ov34_0225DC00
	add r4, r4, #1
	add r6, r0, #0
	cmp r4, r7
	blt _0225DD5C
_0225DD84:
	ldr r0, [r5, #0x14]
	mov r1, #7
	bl GetBgTilemapBuffer
	mov r1, #6
	lsl r1, r1, #8
	bl DC_FlushRange
	ldr r0, [r5, #0x14]
	mov r1, #7
	bl GetBgTilemapBuffer
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r3, #6
	ldr r0, [r5, #0x14]
	mov r1, #7
	lsl r3, r3, #8
	bl BgCopyOrUncompressTilemapBufferRangeToVram
	mov r0, #0xa5
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r5, r0]
_0225DDB6:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov34_0225DD04
