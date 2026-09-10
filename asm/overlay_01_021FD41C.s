	.include "asm/macros.inc"
	.include "overlay_01_021FD41C.inc"
	.include "global.inc"

	.text
	.public ov01_02208E90
	.public ov01_02208EA0
	.public ov01_02208EB4
	.public ov01_02208EC8
	.public ov01_02208EDC
	.public ov01_02208EF0
	.public ov01_02208F14
	.public ov01_02208F38
	.public ov01_021FD41C
	.public ov01_021FD440
	.public ov01_021FD458
	.public ov01_021FD47C
	.public ov01_021FD488
	.public ov01_021FD498
	.public ov01_021FD4A4
	.public ov01_021FD4D0
	.public ov01_021FD4F4
	.public ov01_021FD5CC
	.public ov01_021FD60C
	.public ov01_021FD624
	.public ov01_021FD640
	.public ov01_021FD684
	.public ov01_021FD6C8
	.public ov01_021FD714
	.public ov01_021FD718
	.public ov01_021FD784
	.public ov01_021FD7D4
	.public ov01_021FD838
	.public ov01_021FD8E8
	.public ov01_021FD92C
	.public ov01_021FD980
	.public ov01_021FD9CC

	.public ov01_021FD41C
	.public ov01_021FD440
	.public ov01_021FD47C
	.public ov01_021FD488
	.public ov01_021FD498
	.public ov01_021FD4A4
	.public ov01_021FD4D0
	.public ov01_021FD4F4
	.public ov01_021FD5CC
	.public ov01_021FD60C
	.public ov01_021FD624
	.public ov01_021FD640
	.public ov01_021FD684
	.public ov01_021FD6C8
	.public ov01_021FD714
	.public ov01_021FD718
	.public ov01_021FD784
	.public ov01_021FD7D4
	.public ov01_021FD8E8
	.public ov01_021FD92C
	.public ov01_021FD9CC

	thumb_func_start ov01_021FD458
ov01_021FD458: ; 0x021FD458
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x20]
	bl ov01_021F1468
	ldr r0, [r0, #0x3c]
	bl MapObjectManager_GetPriority
	sub r2, r0, #1
	ldr r0, _021FD478 ; =ov01_021FD4F4
	add r1, r4, #0
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #0x24]
	pop {r4, pc}
	nop
_021FD478: .word ov01_021FD4F4
	thumb_func_end ov01_021FD458
