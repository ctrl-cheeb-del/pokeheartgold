	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.extern ov87_021E6F98
	.extern ov87_021E8388
	.public ov87_021E71EC

	.text

thumb_func_start ov87_021E71EC
ov87_021E71EC: ; 0x021E71EC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r7, r1, #0
	add r6, r0, #0
	lsl r2, r7, #1
	add r3, r6, r2
	ldr r2, _021E723C ; =0x0000036A
	ldr r0, [r6, #0x3c]
	ldrh r2, [r3, r2]
	mov r1, #0
	bl BufferItemName
	add r0, r7, #2
	lsl r4, r0, #4
	ldr r0, _021E7240 ; =ov87_021E8388
	add r5, r6, #0
	ldrb r0, [r0, r7]
	mov r1, #0
	mov r2, #1
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r5, #0x5c
	str r1, [sp, #0x14]
	add r0, r6, #0
	add r1, r5, r4
	mov r3, #0x2c
	bl ov87_021E6F98
	add r6, r0, #0
	add r0, r5, r4
	bl ScheduleWindowCopyToVram
	add r0, r6, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E723C: .word 0x0000036A
_021E7240: .word ov87_021E8388
	thumb_func_end ov87_021E71EC
