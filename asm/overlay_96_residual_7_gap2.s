	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	.public ov96_021E786C
	.public ov96_021E7938
	.public ov96_021E7A2C

	thumb_func_start ov96_021E786C
ov96_021E786C: ; 0x021E786C
	push {r3, r4, r5, r6, r7, lr}
	mov r2, #0x7e
	lsl r2, r2, #2
	str r0, [sp]
	ldr r0, [r0, r2]
	ldrb r2, [r0, #0xc]
	mov r0, #0x2c
	mul r0, r2
	add r4, r1, r0
	ldr r1, _021E7918 ; =0x000008FE
	ldr r0, [sp]
	ldrh r1, [r0, r1]
	ldrh r0, [r4, #6]
	cmp r1, r0
	bls _021E7914
	strh r1, [r4, #6]
	ldrh r1, [r4, #6]
	ldr r0, _021E791C ; =0x000003E7
	cmp r1, r0
	bls _021E7896
	strh r0, [r4, #6]
_021E7896:
	ldr r1, _021E791C ; =0x000003E7
	ldr r5, [sp]
	ldr r7, _021E7920 ; =0x000008B4
	mov r3, #0
	add r6, r4, #0
	add r0, r1, #0
_021E78A2:
	ldrh r2, [r5, r7]
	strh r2, [r6]
	cmp r2, r0
	bls _021E78AC
	strh r1, [r6]
_021E78AC:
	add r3, r3, #1
	add r5, r5, #2
	add r6, r6, #2
	cmp r3, #3
	blt _021E78A2
	ldr r0, [sp]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetParticipantUnk04
	add r1, r4, #0
	ldr r3, _021E7924 ; =0xFFFEFFFF
	mov r2, #0
	add r1, #8
_021E78CC:
	ldr r6, [r1]
	ldr r5, _021E7928 ; =0xFFFFFE00
	ldrh r7, [r0]
	and r5, r6
	ldr r6, _021E792C ; =0x000001FF
	add r2, r2, #1
	and r6, r7
	orr r6, r5
	ldr r5, _021E7930 ; =0xFFFFC1FF
	str r6, [r1]
	and r5, r6
	ldrh r6, [r0, #2]
	lsl r6, r6, #0x1b
	lsr r6, r6, #0x12
	orr r6, r5
	ldr r5, _021E7934 ; =0xFFFF3FFF
	str r6, [r1]
	and r5, r6
	ldrb r6, [r0, #0x11]
	lsl r6, r6, #0x1e
	lsr r6, r6, #0x10
	orr r5, r6
	str r5, [r1]
	ldrb r6, [r0, #0x10]
	and r5, r3
	lsl r6, r6, #0x1f
	lsr r6, r6, #0xf
	orr r5, r6
	str r5, [r1]
	ldr r5, [r0, #4]
	add r0, #0x28
	str r5, [r4, #0xc]
	add r1, #0xc
	add r4, #0xc
	cmp r2, #3
	blt _021E78CC
_021E7914:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7918: .word 0x000008FE
_021E791C: .word 0x000003E7
_021E7920: .word 0x000008B4
_021E7924: .word 0xFFFEFFFF
_021E7928: .word 0xFFFFFE00
_021E792C: .word 0x000001FF
_021E7930: .word 0xFFFFC1FF
_021E7934: .word 0xFFFF3FFF
	thumb_func_end ov96_021E786C

	thumb_func_start ov96_021E7938
ov96_021E7938: ; 0x021E7938
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xd0
	str r0, [sp]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
_021E7944:
	ldr r0, [sp, #8]
	lsl r1, r0, #2
	ldr r0, [sp]
	add r1, r0, r1
	mov r0, #0xf6
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0x2c
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r2, r0, #0
	mul r2, r1
	ldr r1, [sp, #4]
	add r7, r1, r2
	ldr r2, [r7, #0x28]
	ldr r1, _021E7A20 ; =0x0098967F
	cmp r2, r1
	bhs _021E796C
	add r1, r2, #1
	str r1, [r7, #0x28]
_021E796C:
	ldr r1, _021E7A24 ; =_0221A7D8
	mov r3, #0
	ldrb r0, [r1, r0]
	add r2, sp, #0x30
	str r0, [sp, #0xc]
_021E7976:
	lsl r0, r3, #3
	add r5, r7, r0
	ldrh r0, [r7, r0]
	lsl r1, r3, #5
	add r6, r2, r1
	strh r0, [r2, r1]
	mov r4, #0
_021E7984:
	lsl r1, r4, #1
	add r0, r5, r1
	ldrh r0, [r0, #2]
	add r1, r6, r1
	strh r0, [r1, #2]
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021E7984
	add r0, r3, #1
	lsl r0, r0, #0x18
	lsr r3, r0, #0x18
	cmp r3, #5
	blo _021E7976
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r2, r0, #0x15
	ldr r0, [sp, #8]
	lsl r1, r0, #1
	ldr r0, [sp]
	add r0, r0, r2
	add r1, r1, r0
	ldr r0, _021E7A28 ; =0x000008D4
	ldrh r1, [r1, r0]
	add r0, sp, #0x10
	strh r1, [r0]
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	mov r1, #0x3f
	ldr r0, [sp]
	lsl r1, r1, #4
	add r1, r0, r1
	mov r0, #0x7c
	mul r0, r2
	add r0, r1, r0
	mov r1, #0
	add r3, sp, #0x10
	mov r2, #0x28
_021E79DC:
	add r5, r1, #0
	mul r5, r2
	add r4, r0, r5
	ldrh r4, [r4, #2]
	ldrh r5, [r0, r5]
	lsl r4, r4, #0xa
	add r4, r4, r5
	lsl r5, r1, #1
	add r1, r1, #1
	lsl r1, r1, #0x18
	add r5, r3, r5
	lsr r1, r1, #0x18
	strh r4, [r5, #2]
	cmp r1, #3
	blo _021E79DC
	ldr r0, [sp, #0xc]
	add r1, r3, #0
	add r2, sp, #0x30
	bl ov96_021E7C04
	ldr r0, [sp]
	add r1, r7, #0
	add r2, sp, #0x30
	bl ov96_021E7C94
	ldr r0, [sp, #8]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	cmp r0, #3
	blo _021E7944
	add sp, #0xd0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E7A20: .word 0x0098967F
_021E7A24: .word _0221A7D8
_021E7A28: .word 0x000008D4
	thumb_func_end ov96_021E7938

	thumb_func_start ov96_021E7A2C
ov96_021E7A2C: ; 0x021E7A2C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xe0
	str r0, [sp]
	str r1, [sp, #4]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp, #8]
_021E7A42:
	ldr r0, [sp, #8]
	lsl r1, r0, #2
	ldr r0, [sp]
	add r1, r0, r1
	mov r0, #0xf6
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0xa4
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r2, r0, #0
	mul r2, r1
	ldr r1, [sp, #4]
	add r1, r1, r2
	str r1, [sp, #0x14]
	ldr r2, [r1, #0x28]
	ldr r1, _021E7B9C ; =0x0098967F
	cmp r2, r1
	bhs _021E7A6E
	ldr r1, [sp, #0x14]
	add r2, r2, #1
	str r2, [r1, #0x28]
_021E7A6E:
	ldr r1, _021E7BA0 ; =_0221A7D8
	add r4, sp, #0x40
	ldrb r0, [r1, r0]
	mov r1, #0
	mov r7, #0x18
	str r0, [sp, #0x18]
_021E7A7A:
	ldr r2, [sp, #0x14]
	lsl r3, r1, #3
	add r6, r2, r3
	ldrh r2, [r2, r3]
	lsl r5, r1, #5
	add r0, r4, r5
	strh r2, [r4, r5]
	mov r5, #0
_021E7A8A:
	lsl r3, r5, #1
	add r2, r6, r3
	ldrh r2, [r2, #2]
	add r3, r0, r3
	strh r2, [r3, #2]
	add r2, r5, #1
	lsl r2, r2, #0x18
	lsr r5, r2, #0x18
	cmp r5, #3
	blo _021E7A8A
	add r3, r1, #0
	ldr r2, [sp, #0x14]
	mul r3, r7
	add r6, r2, r3
	ldr r2, [r6, #0x2c]
	mov r5, #0
	str r2, [r0, #8]
_021E7AAC:
	lsl r3, r5, #1
	add r2, r6, r3
	ldrh r2, [r2, #0x30]
	add r3, r0, r3
	strh r2, [r3, #0xc]
	add r2, r5, #1
	lsl r2, r2, #0x18
	lsr r5, r2, #0x18
	cmp r5, #8
	blo _021E7AAC
	add r6, #0x40
	ldrb r2, [r6]
	strb r2, [r0, #0x1c]
	add r0, r1, #1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	cmp r1, #5
	blo _021E7A7A
	ldr r0, [sp, #8]
	mov r7, #0
	lsl r1, r0, #1
	ldr r0, [sp]
	add r5, sp, #0x20
	add r0, r0, r1
	str r0, [sp, #0xc]
	mov r1, #0x3f
	ldr r0, [sp]
	lsl r1, r1, #4
	add r0, r0, r1
	str r0, [sp, #0x1c]
	mov r4, #0x28
_021E7AEA:
	ldr r0, [sp, #0x10]
	add r0, r0, r7
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0xc]
	lsl r2, r1, #3
	add r2, r0, r2
	ldr r0, _021E7BA4 ; =0x000008D4
	ldrh r2, [r2, r0]
	add r0, sp, #0x20
	strh r2, [r0]
	mov r0, #0x7c
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #0x1c]
	add r0, r0, r2
	mov r2, #0
_021E7B18:
	add r6, r2, #0
	mul r6, r4
	add r3, r0, r6
	ldrh r3, [r3, #2]
	ldrh r6, [r0, r6]
	lsl r3, r3, #0xa
	add r3, r3, r6
	lsl r6, r2, #1
	add r2, r2, #1
	lsl r2, r2, #0x18
	add r6, r5, r6
	lsr r2, r2, #0x18
	strh r3, [r6, #2]
	cmp r2, #3
	blo _021E7B18
	ldr r0, [sp]
	bl PokeathlonCourse_GetPlayerProfileFromData
	add r6, r0, #0
	bl PlayerProfile_GetTrainerID
	str r0, [sp, #0x28]
	add r0, r6, #0
	bl PlayerProfile_GetNamePtr
	mov r1, #0
_021E7B4C:
	lsl r2, r1, #1
	ldrh r3, [r0, r2]
	add r1, r1, #1
	lsl r1, r1, #0x18
	add r2, r5, r2
	lsr r1, r1, #0x18
	strh r3, [r2, #0xc]
	cmp r1, #8
	blo _021E7B4C
	add r0, r6, #0
	bl PlayerProfile_GetLanguage
	add r1, sp, #0x20
	strb r0, [r1, #0x1c]
	ldr r0, [sp, #0x18]
	add r1, r5, #0
	add r2, sp, #0x40
	bl ov96_021E7C04
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	cmp r7, #4
	blo _021E7AEA
	ldr r0, [sp]
	ldr r1, [sp, #0x14]
	add r2, sp, #0x40
	bl ov96_021E7CC8
	ldr r0, [sp, #8]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	cmp r0, #4
	bhs _021E7B96
	b _021E7A42
_021E7B96:
	add sp, #0xe0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7B9C: .word 0x0098967F
_021E7BA0: .word _0221A7D8
_021E7BA4: .word 0x000008D4
	thumb_func_end ov96_021E7A2C
