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
	thumb_func_start ov67_021E6490
ov67_021E6490: ; 0x021E6490
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r1, _021E6528 ; =0x000004A2
	str r0, [sp, #0xc]
	ldrb r0, [r0, r1]
	cmp r0, #0
	bne _021E64A6
	mov r1, #0x47
	lsl r1, r1, #2
	ldr r0, [sp, #0xc]
	b _021E64AC
_021E64A6:
	mov r1, #0x77
	ldr r0, [sp, #0xc]
	lsl r1, r1, #2
_021E64AC:
	add r5, r0, r1
	mov r1, #0x4a
	ldr r0, [sp, #0xc]
	lsl r1, r1, #4
	ldrh r1, [r0, r1]
	mov r0, #0xc
	mov r6, #0
	mul r0, r1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
_021E64C0:
	lsl r7, r6, #4
	add r0, r5, r7
	mov r1, #0
	bl FillWindowPixelBuffer
	cmp r4, #0x1e
	bhs _021E64FE
	ldr r0, [sp, #0xc]
	lsl r1, r4, #4
	add r1, r0, r1
	mov r0, #0x2a
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _021E64E2
	ldr r2, _021E652C ; =0x00070800
	b _021E64E6
_021E64E2:
	mov r2, #0xc1
	lsl r2, r2, #0xa
_021E64E6:
	mov r0, #0
	str r0, [sp]
	str r2, [sp, #4]
	mov r2, #0xa7
	str r0, [sp, #8]
	lsl r2, r2, #2
	ldr r1, [r1, r2]
	mov r2, #0
	add r0, r5, r7
	add r3, r2, #0
	bl ov67_021E6118
_021E64FE:
	add r0, r5, r7
	bl ScheduleWindowCopyToVram
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	add r0, r6, #1
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	cmp r6, #0xc
	blo _021E64C0
	ldr r1, _021E6528 ; =0x000004A2
	ldr r0, [sp, #0xc]
	ldrb r2, [r0, r1]
	mov r0, #1
	eor r2, r0
	ldr r0, [sp, #0xc]
	strb r2, [r0, r1]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6528: .word 0x000004A2
_021E652C: .word 0x00070800
	thumb_func_end ov67_021E6490


	thumb_func_start ov67_021E6530
ov67_021E6530: ; 0x021E6530
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	add r0, #0xac
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	mov r2, #0x4a
	str r1, [sp]
	mov r3, #1
	str r3, [sp, #4]
	lsl r2, r2, #4
	ldrh r2, [r4, r2]
	ldr r0, [r4, #0x2c]
	add r2, r2, #1
	bl BufferIntegerAsString
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E65BC ; =0x00010200
	mov r1, #4
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x14
	mov r3, #8
	bl ov67_021E61A0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E65BC ; =0x00010200
	mov r1, #4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x15
	mov r3, #0x10
	bl ov67_021E6164
	mov r1, #0
	str r1, [sp]
	mov r3, #1
	str r3, [sp, #4]
	ldr r0, [r4, #0x2c]
	mov r2, #3
	bl BufferIntegerAsString
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E65BC ; =0x00010200
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r4, #0
	mov r1, #4
	mov r2, #0x14
	mov r3, #0x18
	bl ov67_021E61A0
	add r4, #0xac
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_021E65BC: .word 0x00010200
	thumb_func_end ov67_021E6530


	thumb_func_start ov67_021E65C0
ov67_021E65C0: ; 0x021E65C0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r0, #0
	mov r4, #0
	add r5, r6, #0
	add r5, #0x6c
	add r7, r4, #0
_021E65CE:
	add r0, r5, #0
	add r1, r7, #0
	bl FillWindowPixelBuffer
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #3
	bls _021E65CE
	add r0, r6, #0
	bl ov67_021E61E8
	ldr r0, [r6, #0x24]
	add r1, sp, #0x10
	bl sub_0202D8D0
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r2, sp, #0x10
	ldrb r2, [r2]
	ldr r0, [r6, #0x2c]
	mov r3, #2
	bl BufferIntegerAsString
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6684 ; =0x000F0200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r6, #0
	mov r1, #1
	mov r2, #0x11
	str r3, [sp, #0xc]
	bl ov67_021E61A0
	mov r0, #2
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	add r2, sp, #0x10
	ldrb r2, [r2, #1]
	ldr r0, [r6, #0x2c]
	mov r3, #3
	bl BufferIntegerAsString
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6684 ; =0x000F0200
	mov r1, #2
	str r0, [sp, #8]
	add r0, r6, #0
	mov r2, #0x12
	mov r3, #0x3c
	str r1, [sp, #0xc]
	bl ov67_021E61A0
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6684 ; =0x000F0200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r6, #0
	mov r1, #3
	mov r2, #0x13
	str r3, [sp, #0xc]
	bl ov67_021E6164
	add r4, r6, #0
	mov r5, #0
	add r4, #0x6c
_021E665E:
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	add r5, r5, #1
	add r4, #0x10
	cmp r5, #3
	bls _021E665E
	add r0, r6, #0
	bl ov67_021E6490
	add r0, r6, #0
	mov r1, #0
	bl ov67_021E6688
	add r0, r6, #0
	bl ov67_021E6530
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6684: .word 0x000F0200
	thumb_func_end ov67_021E65C0


	thumb_func_start ov67_021E6688
ov67_021E6688: ; 0x021E6688
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r6, r0, #0
	ldr r0, _021E680C ; =0x000004A3
	str r1, [sp, #0x10]
	ldrb r0, [r6, r0]
	cmp r0, #0
	bne _021E669C
	mov r7, #5
	b _021E669E
_021E669C:
	mov r7, #8
_021E669E:
	add r1, r6, #0
	add r1, #0x6c
	lsl r0, r7, #4
	add r4, r1, r0
	mov r5, #0
_021E66A8:
	lsl r0, r5, #4
	add r0, r4, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #3
	blo _021E66A8
	ldr r0, [sp, #0x10]
	cmp r0, #0x1e
	blo _021E66C4
	b _021E67E8
_021E66C4:
	mov r2, #0x2a
	lsl r2, r2, #4
	lsl r5, r0, #4
	add r0, r6, r2
	str r0, [sp, #0x14]
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	add r3, r6, r5
	sub r2, r2, #4
	ldr r2, [r3, r2]
	ldr r3, [sp, #0x14]
	ldr r0, [r6, #0x2c]
	ldrb r3, [r3, r5]
	mov r1, #0
	bl BufferString
	ldr r0, [sp, #0x14]
	ldrb r0, [r0, r5]
	cmp r0, #0
	ldr r0, _021E6810 ; =0x00010200
	bne _021E6708
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r7, #0
	mov r2, #0x16
	str r3, [sp, #0xc]
	bl ov67_021E61A0
	b _021E671C
_021E6708:
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r7, #0
	mov r2, #0x17
	str r3, [sp, #0xc]
	bl ov67_021E61A0
_021E671C:
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6810 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r7, #1
	mov r2, #0x1c
	str r3, [sp, #0xc]
	bl ov67_021E6164
	ldr r0, _021E6814 ; =0x000002A1
	add r0, r6, r0
	ldrb r2, [r0, r5]
	str r0, [sp, #0x18]
	cmp r2, #0
	bne _021E6758
	mov r0, #0x10
	str r0, [sp]
	mov r3, #0
	ldr r0, _021E6810 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r7, #1
	mov r2, #0x1f
	str r3, [sp, #0xc]
	bl ov67_021E6164
	b _021E6778
_021E6758:
	ldr r0, [r6, #0x2c]
	mov r1, #0
	bl BufferCountryName
	mov r0, #0x10
	str r0, [sp]
	mov r3, #0
	ldr r0, _021E6810 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r7, #1
	mov r2, #0x1d
	str r3, [sp, #0xc]
	bl ov67_021E61A0
_021E6778:
	ldr r0, _021E6818 ; =0x000002A2
	add r1, r6, r5
	ldrb r3, [r1, r0]
	cmp r3, #0
	beq _021E67A6
	ldr r2, [sp, #0x18]
	ldr r0, [r6, #0x2c]
	ldrb r2, [r2, r5]
	mov r1, #0
	bl BufferCityName
	mov r0, #0x20
	str r0, [sp]
	mov r3, #0
	ldr r0, _021E6810 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r7, #1
	mov r2, #0x1e
	str r3, [sp, #0xc]
	bl ov67_021E61A0
_021E67A6:
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6810 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r7, #2
	mov r2, #0x20
	str r3, [sp, #0xc]
	bl ov67_021E6164
	mov r0, #0xa9
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r1, [r6]
	add r0, r0, r5
	bl MailMsg_GetExpandedString
	add r5, r0, #0
	mov r2, #0
	ldr r0, _021E6810 ; =0x00010200
	str r2, [sp]
	str r0, [sp, #4]
	add r0, r4, #0
	add r0, #0x20
	add r1, r5, #0
	mov r3, #0x10
	str r2, [sp, #8]
	bl ov67_021E6118
	add r0, r5, #0
	bl String_Delete
_021E67E8:
	mov r5, #0
_021E67EA:
	lsl r0, r5, #4
	add r0, r4, r0
	bl ScheduleWindowCopyToVram
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #3
	blo _021E67EA
	ldr r1, _021E680C ; =0x000004A3
	mov r0, #1
	ldrb r2, [r6, r1]
	eor r0, r2
	strb r0, [r6, r1]
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_021E680C: .word 0x000004A3
_021E6810: .word 0x00010200
_021E6814: .word 0x000002A1
_021E6818: .word 0x000002A2
	thumb_func_end ov67_021E6688

