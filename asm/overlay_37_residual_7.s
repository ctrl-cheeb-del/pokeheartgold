	.include "asm/macros.inc"
	.include "overlay_37.inc"
	.include "global.inc"

	.text
	.public _021E7968
	.public ov37_021E5900
	.public ov37_021E5A84
	.public ov37_021E5B94
	.public ov37_021E5CC8
	.public ov37_021E5CF0
	.public ov37_021E5D10
	.public ov37_021E5E30
	.public ov37_021E5F98
	.public ov37_021E6090
	.public ov37_021E60C0
	.public ov37_021E6244
	.public ov37_021E6418
	.public ov37_021E657C
	.public ov37_021E65EC
	.public ov37_021E69DC
	.public ov37_021E6B64
	.public ov37_021E6D14
	.public ov37_021E6F5C
	.public ov37_021E6FC8
	.public ov37_021E70BC
	.public ov37_021E713C
	.public ov37_021E72B4
	.public ov37_021E72E8
	.public ov37_021E73B4
	.public ov37_021E741C
	.public ov37_021E7478
	.public ov37_021E755C
	.public ov37_021E762C
	.public ov37_021E76F0
	.public ov37_021E78E0
	.public ov37_021E7970
	.public ov37_021E7978
	.public ov37_021E7988
	.public ov37_021E7998
	.public ov37_021E79B4
	.public ov37_021E79D0
	.public ov37_021E79EC
	.public ov37_021E7A08
	.public ov37_021E7A24
	.public ov37_021E7A4C
	.public ov37_021E7A80
	.public ov37_021E7AC8
	.public ov37_021E7D20

	.public ov37_021E5F20
	.public ov37_021E5F5C
	.public ov37_021E6540
	.public ov37_021E6818
	.public ov37_021E6848
	.public ov37_021E6860
	.public ov37_021E68AC
	.public ov37_021E68D0
	.public ov37_021E6928
	.public ov37_021E694C
	.public ov37_021E6980
	.public ov37_021E6B40
	.public ov37_021E6BFC
	.public ov37_021E6C38
	.public ov37_021E6C58
	.public ov37_021E6C84
	.public ov37_021E6CC0
	.public ov37_021E6DD0
	.public ov37_021E6E04
	.public ov37_021E6E2C
	.public ov37_021E6E6C
	.public ov37_021E6E70
	.public ov37_021E6E90
	.public ov37_021E6EB4
	.public ov37_021E6F14
	.public ov37_021E745C
	.public ov37_021E75C4
	.public ov37_021E75E0
	.public ov37_021E75E8
	.public ov37_021E76A0
	.public ov37_021E76C0
	.public ov37_021E76D0
	.public ov37_021E7844
	.public ov37_021E784C
	.public ov37_021E7880
	.public ov37_021E78A4
	.public ov37_021E78C4

	thumb_func_start ov37_021E6F5C
ov37_021E6F5C: ; 0x021E6F5C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _021E6FC0 ; =0x000093B0
	add r4, r1, #0
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021E6F7A
	bl sub_02037454
	ldr r1, _021E6FC0 ; =0x000093B0
	ldr r2, [r5, r1]
	cmp r2, r0
	beq _021E6F7A
	mov r0, #0
	str r0, [r5, r1]
_021E6F7A:
	mov r0, #0x31
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	add r1, r1, #1
	str r1, [r5, r0]
	ldr r0, [r5, r0]
	cmp r0, #0x3c
	ble _021E6FB4
	ldr r0, _021E6FC0 ; =0x000093B0
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _021E6FB4
	add r0, r5, #0
	bl ov37_021E76C0
	add r0, r5, #0
	mov r1, #4
	bl ov37_021E7844
	bl sub_0203769C
	cmp r0, #0
	bne _021E6FB4
	ldr r0, _021E6FC4 ; =0x000093F4
	mov r1, #1
	str r1, [r5, r0]
	add r0, r5, #0
	bl ov37_021E76D0
_021E6FB4:
	add r0, r5, #0
	bl ov37_021E68AC
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	nop
_021E6FC0: .word 0x000093B0
_021E6FC4: .word 0x000093F4
	thumb_func_end ov37_021E6F5C


	thumb_func_start ov37_021E6FC8
ov37_021E6FC8: ; 0x021E6FC8
	push {r4, r5, r6, lr}
	add r5, r1, #0
	add r4, r0, #0
	add r6, r2, #0
	cmp r5, #0xf
	bgt _021E6FFA
	bge _021E70A6
	cmp r5, #9
	bhi _021E70AE
	add r1, r5, r5
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E6FE6: ; jump table
	.short _021E70A4 - _021E6FE6 - 2 ; case 0
	.short _021E7000 - _021E6FE6 - 2 ; case 1
	.short _021E70A4 - _021E6FE6 - 2 ; case 2
	.short _021E703E - _021E6FE6 - 2 ; case 3
	.short _021E70A4 - _021E6FE6 - 2 ; case 4
	.short _021E70A4 - _021E6FE6 - 2 ; case 5
	.short _021E70A4 - _021E6FE6 - 2 ; case 6
	.short _021E70A4 - _021E6FE6 - 2 ; case 7
	.short _021E70A6 - _021E6FE6 - 2 ; case 8
	.short _021E70A6 - _021E6FE6 - 2 ; case 9
_021E6FFA:
	cmp r5, #0x15
	beq _021E7044
	pop {r4, r5, r6, pc}
_021E7000:
	mov r0, #0xc1
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #6
	beq _021E700E
	cmp r0, #0xe
	bne _021E7014
_021E700E:
	add r0, r4, #0
	bl ov37_021E78A4
_021E7014:
	mov r0, #0x92
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl ov37_021E6848
	add r0, r6, #0
	bl sub_02034818
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferPlayersName
	mov r0, #0x32
	lsl r0, r0, #4
	str r6, [r4, r0]
	ldr r0, _021E70B0 ; =0x000093B4
	mov r1, #0
	str r1, [r4, r0]
	b _021E70A6
_021E703E:
	bl ov37_021E76C0
	b _021E70A6
_021E7044:
	ldr r0, _021E70B4 ; =0x000093BC
	ldrb r0, [r4, r0]
	cmp r0, #1
	beq _021E70AE
	add r0, r6, #0
	bl sub_02034818
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferPlayersName
	bl sub_0203769C
	cmp r6, r0
	beq _021E70AE
	bl sub_0203769C
	cmp r0, #0
	bne _021E7078
	ldr r1, _021E70B0 ; =0x000093B4
	ldr r0, _021E70B8 ; =0x0000FFFF
	ldr r2, [r4, r1]
	eor r0, r6
	and r0, r2
	str r0, [r4, r1]
_021E7078:
	mov r0, #0xc1
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #6
	beq _021E7086
	cmp r0, #0xe
	bne _021E7096
_021E7086:
	add r0, r4, #0
	bl ov37_021E78A4
	mov r0, #0xb2
	lsl r0, r0, #2
	add r0, r4, r0
	bl CopyWindowToVram
_021E7096:
	mov r0, #0x92
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl ov37_021E6848
	b _021E70A6
_021E70A4:
	pop {r4, r5, r6, pc}
_021E70A6:
	add r0, r4, #0
	add r1, r5, #0
	bl ov37_021E7844
_021E70AE:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E70B0: .word 0x000093B4
_021E70B4: .word 0x000093BC
_021E70B8: .word 0x0000FFFF
	thumb_func_end ov37_021E6FC8


	thumb_func_start ov37_021E70BC
ov37_021E70BC: ; 0x021E70BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	ldr r4, [sp, #0x38]
	mov ip, r1
	add r6, r2, #0
	add r7, r3, #0
	str r0, [sp, #0x18]
	ldr r3, [sp, #0x3c]
	ldr r2, [sp, #0x40]
	ldr r1, [sp, #0x44]
	cmp r4, #0
	bge _021E70E8
	neg r0, r4
	cmp r0, r2
	ble _021E70DC
	add r0, r2, #0
_021E70DC:
	ldr r5, [sp, #0x30]
	mov r4, #0
	sub r5, r5, r0
	add r6, r6, r0
	str r5, [sp, #0x30]
	sub r2, r2, r0
_021E70E8:
	cmp r3, #0
	bge _021E7100
	neg r0, r3
	cmp r0, r1
	ble _021E70F4
	add r0, r1, #0
_021E70F4:
	ldr r5, [sp, #0x34]
	mov r3, #0
	sub r5, r5, r0
	add r7, r7, r0
	str r5, [sp, #0x34]
	sub r1, r1, r0
_021E7100:
	ldr r0, [sp, #0x30]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [sp, #0x34]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #8]
	lsl r0, r3, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0xc]
	lsl r0, r2, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	lsl r0, r1, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x14]
	lsl r2, r6, #0x10
	lsl r3, r7, #0x10
	ldr r0, [sp, #0x18]
	mov r1, ip
	lsr r2, r2, #0x10
	lsr r3, r3, #0x10
	bl BlitBitmapRectToWindow
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov37_021E70BC


	thumb_func_start ov37_021E713C
ov37_021E713C: ; 0x021E713C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x50]
	str r1, [sp, #0x1c]
	str r0, [sp, #0x50]
	ldr r0, [sp, #0x54]
	str r2, [sp, #0x20]
	str r0, [sp, #0x54]
	ldr r0, [sp, #0x50]
	str r3, [sp, #0x24]
	ldr r4, [r0]
	ldr r0, [sp, #0x54]
	ldr r5, [r0]
	add r0, r2, #0
	str r0, [sp, #0x38]
	add r0, r3, #0
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x58]
	cmp r0, #0
	bne _021E717C
	ldr r0, [sp, #0x5c]
	cmp r0, #0
	bne _021E717C
	ldr r0, [sp, #0x50]
	add r1, r2, #0
	str r1, [r0]
	ldr r0, [sp, #0x54]
	add r1, r3, #0
	str r1, [r0]
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
_021E717C:
	ldr r0, [sp, #0x20]
	sub r0, r0, r4
	str r0, [sp, #0x34]
	bpl _021E7188
	neg r0, r0
	str r0, [sp, #0x34]
_021E7188:
	ldr r0, [sp, #0x24]
	sub r7, r0, r5
	bpl _021E7190
	neg r7, r7
_021E7190:
	ldr r0, [sp, #0x34]
	cmp r0, r7
	ble _021E721E
	ldr r0, [sp, #0x20]
	cmp r4, r0
	ble _021E71B6
	ldr r0, [sp, #0x24]
	cmp r5, r0
	ble _021E71A8
	mov r0, #1
	str r0, [sp, #0x2c]
	b _021E71AE
_021E71A8:
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x2c]
_021E71AE:
	str r4, [sp, #0x38]
	ldr r4, [sp, #0x20]
	ldr r5, [sp, #0x24]
	b _021E71C8
_021E71B6:
	ldr r0, [sp, #0x24]
	cmp r5, r0
	bge _021E71C2
	mov r0, #1
	str r0, [sp, #0x2c]
	b _021E71C8
_021E71C2:
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x2c]
_021E71C8:
	mov r0, #6
	str r0, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	mov r2, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	add r3, r2, #0
	bl ov37_021E70BC
	ldr r0, [sp, #0x34]
	add r4, r4, #1
	asr r6, r0, #1
	ldr r0, [sp, #0x38]
	cmp r4, r0
	bgt _021E72A2
_021E71EE:
	sub r6, r6, r7
	bpl _021E71FA
	ldr r0, [sp, #0x34]
	add r6, r6, r0
	ldr r0, [sp, #0x2c]
	add r5, r5, r0
_021E71FA:
	mov r0, #6
	str r0, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	mov r2, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	add r3, r2, #0
	bl ov37_021E70BC
	ldr r0, [sp, #0x38]
	add r4, r4, #1
	cmp r4, r0
	ble _021E71EE
	b _021E72A2
_021E721E:
	ldr r0, [sp, #0x24]
	cmp r5, r0
	ble _021E723E
	ldr r0, [sp, #0x20]
	cmp r4, r0
	ble _021E7230
	mov r0, #1
	str r0, [sp, #0x28]
	b _021E7236
_021E7230:
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x28]
_021E7236:
	str r5, [sp, #0x30]
	ldr r5, [sp, #0x24]
	ldr r4, [sp, #0x20]
	b _021E7250
_021E723E:
	ldr r0, [sp, #0x20]
	cmp r4, r0
	bge _021E724A
	mov r0, #1
	str r0, [sp, #0x28]
	b _021E7250
_021E724A:
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x28]
_021E7250:
	mov r0, #6
	str r0, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	mov r2, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	add r3, r2, #0
	bl ov37_021E70BC
	ldr r0, [sp, #0x30]
	add r5, r5, #1
	asr r6, r7, #1
	cmp r5, r0
	bgt _021E72A2
_021E7274:
	ldr r0, [sp, #0x34]
	sub r6, r6, r0
	bpl _021E7280
	ldr r0, [sp, #0x28]
	add r6, r6, r7
	add r4, r4, r0
_021E7280:
	mov r0, #6
	str r0, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	mov r2, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	add r3, r2, #0
	bl ov37_021E70BC
	ldr r0, [sp, #0x30]
	add r5, r5, #1
	cmp r5, r0
	ble _021E7274
_021E72A2:
	ldr r1, [sp, #0x20]
	ldr r0, [sp, #0x50]
	str r1, [r0]
	ldr r1, [sp, #0x24]
	ldr r0, [sp, #0x54]
	str r1, [r0]
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov37_021E713C


	thumb_func_start ov37_021E72B4
ov37_021E72B4: ; 0x021E72B4
	mov r2, #0
_021E72B6:
	ldrb r3, [r0, #8]
	lsl r3, r3, #0x1a
	lsr r3, r3, #0x1d
	strh r3, [r1, #2]
	ldrb r3, [r0, #8]
	lsl r3, r3, #0x1a
	lsr r3, r3, #0x1d
	beq _021E72DA
	add r3, r0, r3
	sub r3, r3, #1
	ldrb r3, [r3]
	strb r3, [r1]
	ldrb r3, [r0, #8]
	lsl r3, r3, #0x1a
	lsr r3, r3, #0x1d
	add r3, r0, r3
	ldrb r3, [r3, #3]
	strb r3, [r1, #1]
_021E72DA:
	add r2, r2, #1
	add r0, #0xa
	add r1, r1, #4
	cmp r2, #5
	blt _021E72B6
	bx lr
	.balign 4, 0
	thumb_func_end ov37_021E72B4


	thumb_func_start ov37_021E72E8
ov37_021E72E8: ; 0x021E72E8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	str r0, [sp, #0x10]
	mov r0, #0
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	add r5, r1, #0
	add r7, r2, #0
_021E72FE:
	ldrb r0, [r5, #8]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1d
	beq _021E736E
	ldrh r0, [r7, #2]
	cmp r0, #0
	beq _021E7318
	ldrb r0, [r7]
	sub r0, #9
	str r0, [sp, #0x2c]
	ldrb r0, [r7, #1]
	sub r0, #0x11
	str r0, [sp, #0x28]
_021E7318:
	ldrb r0, [r5, #8]
	mov r4, #0
	lsl r0, r0, #0x1a
	lsr r1, r0, #0x1d
	cmp r1, #0
	ble _021E736E
	mov r0, #1
	str r0, [sp, #0x20]
	cmp r1, #0
	ble _021E736E
_021E732C:
	add r0, sp, #0x2c
	str r0, [sp]
	add r0, sp, #0x28
	str r0, [sp, #4]
	str r4, [sp, #8]
	ldrh r0, [r7, #2]
	mov r6, #0xc0
	add r3, r5, r4
	str r0, [sp, #0xc]
	ldrb r1, [r5, #8]
	ldrb r3, [r3, #4]
	ldr r0, [sp, #0x10]
	lsl r2, r1, #0x18
	lsr r2, r2, #0x1e
	mul r6, r2
	ldr r2, _021E73B0 ; =ov37_021E7AC8
	lsl r1, r1, #0x1d
	add r2, r2, r6
	lsr r6, r1, #0x1d
	mov r1, #0x18
	mul r1, r6
	add r1, r2, r1
	ldrb r2, [r5, r4]
	sub r3, #0x11
	sub r2, #9
	bl ov37_021E713C
	ldrb r0, [r5, #8]
	add r4, r4, #1
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1d
	cmp r4, r0
	blt _021E732C
_021E736E:
	ldr r0, [sp, #0x24]
	add r5, #0xa
	add r0, r0, #1
	add r7, r7, #4
	str r0, [sp, #0x24]
	cmp r0, #5
	blt _021E72FE
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _021E738E
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq _021E738E
	ldr r0, [sp, #0x10]
	bl CopyWindowToVram
_021E738E:
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	bl ov37_021E72B4
	mov r3, #0
	mov r1, #0x38
_021E739A:
	ldr r0, [sp, #0x14]
	add r3, r3, #1
	ldrb r2, [r0, #8]
	bic r2, r1
	strb r2, [r0, #8]
	add r0, #0xa
	str r0, [sp, #0x14]
	cmp r3, #5
	blt _021E739A
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E73B0: .word ov37_021E7AC8
	thumb_func_end ov37_021E72E8


	thumb_func_start ov37_021E73B4
ov37_021E73B4: ; 0x021E73B4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _021E7418 ; =0x00004382
	mov r7, #0x76
	mov r6, #0
	add r4, r5, r0
	lsl r7, r7, #2
_021E73C2:
	bl sub_0203769C
	cmp r6, r0
	beq _021E740A
	ldrb r0, [r4, #8]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1d
	beq _021E73FE
	add r0, r6, #0
	bl sub_02034818
	cmp r0, #0
	beq _021E73FE
	mov r0, #0x76
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldrb r0, [r4, #8]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1d
	add r2, r4, r0
	sub r1, r2, #1
	ldrb r1, [r1]
	ldrb r2, [r2, #3]
	ldr r0, [r5, r7]
	bl ov37_021E657C
	b _021E740A
_021E73FE:
	mov r0, #0x76
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_021E740A:
	add r6, r6, #1
	add r4, #0xa
	add r5, r5, #4
	cmp r6, #5
	blt _021E73C2
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7418: .word 0x00004382
	thumb_func_end ov37_021E73B4


	thumb_func_start ov37_021E741C
ov37_021E741C: ; 0x021E741C
	push {r3, lr}
	ldrh r1, [r0]
	add r1, #0x14
	strh r1, [r0]
	ldrh r2, [r0]
	mov r1, #0x5a
	lsl r1, r1, #2
	cmp r2, r1
	bls _021E7432
	mov r1, #0
	strh r1, [r0]
_021E7432:
	ldrh r0, [r0]
	bl GF_SinDeg
	mov r1, #0xa
	mul r1, r0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	add r0, #0xf
	lsl r1, r0, #5
	mov r0, #0x1d
	orr r1, r0
	add r0, sp, #0
	strh r1, [r0]
	add r0, sp, #0
	mov r1, #0x18
	mov r2, #2
	bl GX_LoadOBJPltt
	pop {r3, pc}
	thumb_func_end ov37_021E741C
