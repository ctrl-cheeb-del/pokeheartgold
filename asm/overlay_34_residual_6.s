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
	.public ov34_0225E164
	.public ov34_0225E2BC
	.public ov34_0225E428
	.public ov34_0225E4A8
	.public ov34_0225E4F8


	thumb_func_start ov34_0225E1C4
ov34_0225E1C4: ; 0x0225E1C4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x40]
	str r1, [sp, #0x20]
	add r5, r2, #0
	mov r1, #0
	str r0, [sp, #0x40]
	ldr r4, [sp, #0x44]
	cmp r0, #3
	ble _0225E1DE
	mov r0, #3
	str r0, [sp, #0x40]
_0225E1DE:
	ldr r2, [sp, #0x40]
	mov r0, #0
	cmp r2, #0
	ble _0225E204
	add r2, r5, #0
_0225E1E8:
	cmp r3, r0
	beq _0225E1F6
	ldr r6, [r2, #0x34]
	cmp r6, #0
	beq _0225E1F6
	sub r6, r6, #1
	str r6, [r2, #0x34]
_0225E1F6:
	ldr r6, [r2, #0x34]
	add r0, r0, #1
	add r1, r1, r6
	ldr r6, [sp, #0x40]
	add r2, #0x38
	cmp r0, r6
	blt _0225E1E8
_0225E204:
	cmp r1, #0
	bne _0225E214
	ldr r0, [r4]
	cmp r0, #0
	bne _0225E214
	add sp, #0x28
	str r1, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_0225E214:
	ldr r0, [sp, #0x40]
	str r1, [r4]
	mov r4, #0
	cmp r0, #0
	ble _0225E28A
	ldr r0, [sp, #0x20]
	mov r7, #2
	add r0, #0xc
	str r0, [sp, #0x20]
_0225E226:
	ldr r1, [r5, #0x34]
	lsl r3, r7, #0x18
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	str r0, [sp, #0x24]
	mov r0, #0x20
	str r0, [sp]
	mov r0, #7
	str r0, [sp, #4]
	ldr r0, [sp, #0x20]
	lsr r3, r3, #0x18
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x24]
	ldr r1, [r5, #0x30]
	lsl r2, r0, #3
	mov r0, #0x18
	mul r0, r1
	add r0, r2, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x10]
	mov r0, #0x20
	str r0, [sp, #0x14]
	mov r0, #0x30
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	mov r1, #7
	mov r2, #0
	bl CopyToBgTilemapRect
	ldr r3, [sp, #0x24]
	add r1, r4, #4
	lsl r6, r3, #2
	ldr r3, _0225E2B8 ; =_0225E694
	lsl r1, r1, #0x18
	ldr r0, [sp, #0x1c]
	ldr r3, [r3, r6]
	lsr r1, r1, #0x18
	mov r2, #3
	bl BgSetPosTextAndCommit
	ldr r0, [sp, #0x40]
	add r4, r4, #1
	add r5, #0x38
	add r7, r7, #7
	cmp r4, r0
	blt _0225E226
_0225E28A:
	ldr r0, [sp, #0x1c]
	mov r1, #7
	bl GetBgTilemapBuffer
	mov r1, #6
	lsl r1, r1, #8
	bl DC_FlushRange
	ldr r0, [sp, #0x1c]
	mov r1, #7
	bl GetBgTilemapBuffer
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r3, #6
	ldr r0, [sp, #0x1c]
	mov r1, #7
	lsl r3, r3, #8
	bl BgCopyOrUncompressTilemapBufferRangeToVram
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225E2B8: .word _0225E694
	thumb_func_end ov34_0225E1C4
