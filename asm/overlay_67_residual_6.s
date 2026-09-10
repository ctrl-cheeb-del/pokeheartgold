	.include "asm/macros.inc"
	.include "overlay_67.inc"
	.include "global.inc"

	.public ov67_021E6D50
	.public ov67_021E6D5C
	.public ov67_021E6D6C
	.public ov67_021E6D7C
	.public ov67_021E6D90
	.public ov67_021E6DA8
	.public ov67_021E6DC4
	.public ov67_021E6DE0
	.public ov67_021E6DFC
	.public ov67_021E6E18
	.public ov67_021E6E38
	.public ov67_021E6E60
	.public ov67_021E6E98
	.public ov67_021E6EE8
	.public ov67_021E6F50
	.public ov67_021E7020

	.public _021E6D4C

	.text
	.public ov67_021E5900
	.public ov67_021E5968
	.public ov67_021E5984
	.public ov67_021E5A6C
	.public ov67_021E5B44
	.public ov67_021E5BC0
	.public ov67_021E5BE0
	.public ov67_021E5C04
	.public ov67_021E5C44
	.public ov67_021E5DA0
	.public ov67_021E5E84
	.public ov67_021E5EB0
	.public ov67_021E6008
	.public ov67_021E6080
	.public ov67_021E60B4
	.public ov67_021E60F4
	.public ov67_021E6118
	.public ov67_021E6164
	.public ov67_021E61A0
	.public ov67_021E61E8
	.public ov67_021E6220
	.public ov67_021E63E8
	.public ov67_021E6474
	.public ov67_021E6490
	.public ov67_021E6530
	.public ov67_021E65C0
	.public ov67_021E6688
	.public ov67_021E681C
	.public ov67_021E6820
	.public ov67_021E6990
	.public ov67_021E69D8
	.public ov67_021E6A00
	.public ov67_021E6A08
	.public ov67_021E6A28
	.public ov67_021E6A40
	.public ov67_021E6B6C
	.public ov67_021E6BB8
	.public ov67_021E6BC4
	.public ov67_021E6C04
	.public ov67_021E6C14
	.public ov67_021E6C5C
	.public ov67_021E6C60
	.public ov67_021E6D20
	thumb_func_start ov67_021E6220
ov67_021E6220: ; 0x021E6220
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r6, #0
	add r4, r5, #0
	add r4, #0x6c
	add r7, r6, #0
_021E622E:
	add r0, r4, #0
	add r1, r7, #0
	bl FillWindowPixelBuffer
	add r6, r6, #1
	add r4, #0x10
	cmp r6, #0xa
	blo _021E622E
	add r0, r5, #0
	bl ov67_021E61E8
	add r0, r5, #0
	add r0, #0x7c
	bl GetWindowWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	lsl r4, r3, #3
	str r0, [sp, #4]
	ldr r0, _021E63E0 ; =0x000F0200
	lsr r3, r4, #0x1f
	add r3, r4, r3
	str r0, [sp, #8]
	mov r2, #2
	add r0, r5, #0
	mov r1, #1
	asr r3, r3, #1
	str r2, [sp, #0xc]
	bl ov67_021E6164
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E63E4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #2
	mov r2, #5
	str r3, [sp, #0xc]
	bl ov67_021E6164
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E63E4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #3
	mov r2, #8
	str r3, [sp, #0xc]
	bl ov67_021E6164
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E63E4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r5, #0
	mov r1, #4
	mov r2, #0xc
	bl ov67_021E6164
	ldr r0, [r5, #0x20]
	mov r1, #0xc
	mov r2, #0
	bl sub_0202D5DC
	cmp r0, #0
	ldr r0, _021E63E4 ; =0x00010200
	bne _021E62D4
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #6
	mov r2, #9
	str r3, [sp, #0xc]
	bl ov67_021E6164
	b _021E62E8
_021E62D4:
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #6
	mov r2, #0xa
	str r3, [sp, #0xc]
	bl ov67_021E6164
_021E62E8:
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E63E4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r5, #0
	mov r1, #8
	mov r2, #0xb
	bl ov67_021E6164
	ldr r0, [r5, #0x20]
	mov r1, #0
	bl sub_0202D488
	mov r1, #0
	add r2, r0, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r5, #0x2c]
	mov r3, #2
	bl BufferIntegerAsString
	add r0, r5, #0
	add r0, #0xbc
	bl GetWindowWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E63E4 ; =0x00010200
	mov r1, #5
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r2, #0xe
	lsl r3, r3, #3
	bl ov67_021E61A0
	ldr r0, [r5, #0x1c]
	mov r1, #9
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [r5, #0x2c]
	mov r1, #0
	mov r3, #4
	bl BufferIntegerAsString
	add r0, r5, #0
	add r0, #0xdc
	bl GetWindowWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E63E4 ; =0x00010200
	lsl r4, r3, #3
	lsr r3, r4, #0x1f
	str r0, [sp, #8]
	mov r0, #2
	add r3, r4, r3
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r1, #7
	mov r2, #0xf
	asr r3, r3, #1
	bl ov67_021E61A0
	ldr r0, [r5, #0x1c]
	mov r1, #8
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [r5, #0x2c]
	mov r1, #0
	mov r3, #4
	bl BufferIntegerAsString
	add r0, r5, #0
	add r0, #0xfc
	bl GetWindowWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E63E4 ; =0x00010200
	lsl r4, r3, #3
	lsr r3, r4, #0x1f
	str r0, [sp, #8]
	mov r0, #2
	add r3, r4, r3
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r1, #9
	mov r2, #0xf
	asr r3, r3, #1
	bl ov67_021E61A0
	mov r4, #0
	add r5, #0x6c
_021E63CC:
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #0xa
	blo _021E63CC
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E63E0: .word 0x000F0200
_021E63E4: .word 0x00010200
	thumb_func_end ov67_021E6220


	thumb_func_start ov67_021E63E8
ov67_021E63E8: ; 0x021E63E8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	ldr r0, [r7, #0x24]
	ldr r1, [r7]
	bl sub_0202D8E4
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp]
	mov r0, #0xa7
	ldr r5, [sp, #4]
	lsl r0, r0, #2
	add r4, r7, r0
	add r6, r5, #0
_021E6406:
	add r0, r5, #0
	add r0, #0x20
	ldrb r0, [r0]
	add r1, r4, #0
	add r1, #8
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	strb r0, [r4, #4]
	ldrb r0, [r5, #0x12]
	mov r2, #8
	strb r0, [r4, #5]
	ldrb r0, [r5, #0x13]
	strb r0, [r4, #6]
	add r0, r5, #0
	add r0, #0x20
	ldrb r0, [r0]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	strb r0, [r4, #7]
	add r0, r5, #0
	add r0, #0x18
	bl MI_CpuCopy8
	ldr r1, [r7]
	mov r0, #8
	bl String_New
	str r0, [r4]
	ldrb r0, [r4, #7]
	cmp r0, #0
	ldr r0, [r4]
	beq _021E6454
	ldrb r1, [r4, #4]
	lsl r1, r1, #2
	add r1, r7, r1
	ldr r1, [r1, #0x64]
	bl String_Copy
	b _021E645A
_021E6454:
	add r1, r6, #0
	bl CopyU16ArrayToString
_021E645A:
	ldr r0, [sp]
	add r4, #0x10
	add r0, r0, #1
	add r5, #0x22
	add r6, #0x22
	str r0, [sp]
	cmp r0, #0x1e
	blt _021E6406
	ldr r0, [sp, #4]
	bl Heap_Free
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov67_021E63E8

