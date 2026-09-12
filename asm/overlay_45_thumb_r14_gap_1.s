.include "asm/macros.inc"
	.public Heap_Alloc
	.public PlayerProfile_New
	.public memset
	.public ov45_0222B2B4
	.public ov45_0222B470
	.public ov45_0222B530
	.public ov45_0222B5A0
	.public ov45_0222B75C
	.public ov45_0222B8A0
	.public ov45_0222BC3C
	.public ov45_0222BCC8
	.public ov45_0222BD30
	.public ov45_0222BD40
	.public ov45_0222C388
	.public ov45_0222C8AC
	.public ov45_0222C978
	.public ov45_0222CB44
	.public ov45_0222D860
	.public ov45_0222E5D4
	.public ov45_0222EE20
	.public ov45_02254AC4

	.text

	thumb_func_start ov45_02229FF4
ov45_02229FF4: ; 0x02229FF4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r7, r1, #0
	mov r1, #0x53
	add r5, r0, #0
	add r0, r7, #0
	lsl r1, r1, #4
	bl Heap_Alloc
	mov r2, #0x53
	mov r1, #0
	lsl r2, r2, #4
	add r4, r0, #0
	bl memset
	ldr r0, _0222A0CC ; =0x00000528
	str r5, [r4]
	str r7, [r4, r0]
	ldr r0, _0222A0D0 ; =ov45_0222B2B4
	mov r2, #0x94
	str r0, [sp, #4]
	ldr r0, _0222A0D4 ; =ov45_0222B470
	add r3, sp, #4
	str r0, [sp, #8]
	ldr r0, _0222A0D8 ; =ov45_0222B530
	str r0, [sp, #0xc]
	ldr r0, _0222A0DC ; =ov45_0222B5A0
	str r0, [sp, #0x10]
	ldr r0, _0222A0E0 ; =ov45_0222B75C
	str r0, [sp, #0x14]
	str r4, [sp]
	ldr r1, [r4]
	add r0, r7, #0
	bl ov45_0222E5D4
	add r0, r7, #0
	bl ov45_0222D860
	str r0, [r4, #4]
	mov r6, #0
	add r5, r4, #0
_0222A046:
	add r0, r7, #0
	bl PlayerProfile_New
	add r1, r5, #0
	add r1, #0xe8
	add r6, r6, #1
	add r5, r5, #4
	str r0, [r1]
	cmp r6, #4
	blt _0222A046
	mov r0, #0x42
	lsl r0, r0, #2
	ldr r1, [r4]
	add r0, r4, r0
	add r2, r7, #0
	bl ov45_0222B8A0
	mov r0, #7
	lsl r0, r0, #6
	add r0, r4, r0
	bl ov45_0222BD40
	mov r0, #0x7a
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov45_0222BD30
	ldr r0, _0222A0E4 ; =ov45_02254AC4
	mov r1, #8
	add r2, r4, #0
	bl ov45_0222EE20
	mov r0, #0x7f
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov45_0222BC3C
	mov r0, #0x83
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov45_0222C388
	mov r0, #0xeb
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov45_0222C8AC
	mov r0, #0xf9
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, r7, #0
	bl ov45_0222C978
	ldr r0, _0222A0E8 ; =0x000004BC
	ldr r1, [r4]
	add r0, r4, r0
	bl ov45_0222CB44
	ldr r0, _0222A0EC ; =0x00000508
	add r1, r7, #0
	add r0, r4, r0
	bl ov45_0222BCC8
	add r0, r4, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222A0CC: .word 0x00000528
_0222A0D0: .word ov45_0222B2B4
_0222A0D4: .word ov45_0222B470
_0222A0D8: .word ov45_0222B530
_0222A0DC: .word ov45_0222B5A0
_0222A0E0: .word ov45_0222B75C
_0222A0E4: .word ov45_02254AC4
_0222A0E8: .word 0x000004BC
_0222A0EC: .word 0x00000508
	thumb_func_end ov45_02229FF4
