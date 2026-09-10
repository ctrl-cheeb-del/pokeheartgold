	.include "asm/macros.inc"
	.include "overlay_64.inc"
	.include "global.inc"
	.public HallOfFameShowcase_Init
	.public HallOfFameShowcase_Main
	.public _021E6E7C
	.public ov64_021E5B10
	.public ov64_021E5CD0
	.public ov64_021E607C
	.public ov64_021E6170
	.public ov64_021E62C8
	.public ov64_021E652C
	.public ov64_021E677C
	.public ov64_021E6B84
	.public ov64_021E6C1C
	.public ov64_021E6E88
	.public ov64_021E6E98
	.public ov64_021E6EA8
	.public ov64_021E6EB8
	.public ov64_021E6ECC
	.public ov64_021E6ECE
	.public ov64_021E6EE4
	.public ov64_021E6EFC
	.public ov64_021E6F18
	.public ov64_021E6F34
	.public ov64_021E6F50
	.public ov64_021E6F6C
	.public ov64_021E6F8C
	.public ov64_021E6FAC
	.public ov64_021E6FD4
	.public ov64_021E7008
	.public ov64_021E7040
	.public ov64_021E70C8
	.public ov64_021E70FC
	.public ov64_021E73A0
	.public ov64_021E73D4
	.public ov64_021E7408
	.public ov64_021E743C


	.text
	.public HallOfFameShowcase_Exit
	.public ov64_021E5A88
	.public ov64_021E5AAC
	.public ov64_021E5AC8
	.public ov64_021E5AE4
	.public ov64_021E5B00
	.public ov64_021E5CA4
	.public ov64_021E6010
	.public ov64_021E602C
	.public ov64_021E605C
	.public ov64_021E6118
	.public ov64_021E620C
	.public ov64_021E622C
	.public ov64_021E6260
	.public ov64_021E6270
	.public ov64_021E6274
	.public ov64_021E6278
	.public ov64_021E6280
	.public ov64_021E6288
	.public ov64_021E62A8
	.public ov64_021E64F8
	.public ov64_021E6754
	.public ov64_021E6BD8
	.public ov64_021E6E30

	thumb_func_start ov64_021E607C
ov64_021E607C: ; 0x021E607C
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xb5
	mov r3, #0x3b
	bl NewMsgDataFromNarc
	mov r1, #0x46
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xed
	mov r3, #0x3b
	bl NewMsgDataFromNarc
	mov r1, #0x47
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r2, _021E6114 ; =0x000002EE
	mov r0, #1
	mov r1, #0x1b
	mov r3, #0x3b
	bl NewMsgDataFromNarc
	mov r1, #0x12
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r0, #0x3b
	bl MessageFormat_New
	mov r1, #0x49
	lsl r1, r1, #2
	str r0, [r4, r1]
	sub r1, #0x24
	add r0, r1, #0
	mov r1, #0x3b
	bl String_New
	mov r1, #0x4a
	lsl r1, r1, #2
	str r0, [r4, r1]
	sub r1, #0x28
	add r0, r1, #0
	mov r1, #0x3b
	bl String_New
	mov r1, #0x4b
	lsl r1, r1, #2
	str r0, [r4, r1]
	sub r1, #0x2c
	add r0, r1, #0
	mov r1, #0x3b
	bl String_New
	mov r1, #0x69
	lsl r1, r1, #2
	str r0, [r4, r1]
	sub r1, #0xa4
	add r0, r1, #0
	mov r1, #0x3b
	bl String_New
	mov r1, #0x6a
	lsl r1, r1, #2
	str r0, [r4, r1]
	sub r0, r1, #4
	ldr r2, [r4, r0]
	add r0, r1, #0
	sub r0, #0x20
	str r2, [r4, r0]
	ldr r0, [r4, r1]
	sub r1, #0x1c
	str r0, [r4, r1]
	pop {r4, pc}
	.balign 4, 0
_021E6114: .word 0x000002EE
	thumb_func_end ov64_021E607C
