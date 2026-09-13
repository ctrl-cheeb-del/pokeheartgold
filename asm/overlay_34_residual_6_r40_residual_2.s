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


	thumb_func_start ov34_0225E348
ov34_0225E348: ; 0x0225E348
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r0, #0
	add r6, r2, #0
	ldr r2, [r7, #4]
	ldr r0, _0225E424 ; =0x000004D8
	str r1, [sp, #4]
	mov r1, #0x27
	ldr r0, [r2, r0]
	lsl r1, r1, #4
	str r0, [sp, #0xc]
	add r0, r1, #0
	ldr r4, [r7, r1]
	add r0, #0xd8
	ldr r0, [r4, r0]
	str r3, [sp, #8]
	cmp r0, #0x1e
	bne _0225E370
	add r1, #0xdc
	b _0225E372
_0225E370:
	add r1, #0xd8
_0225E372:
	add r5, r4, r1
	ldr r1, [r5]
	mov r0, #0x1c
	mul r0, r1
	add r0, r4, r0
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _0225E386
	bl String_Delete
_0225E386:
	ldr r1, [r5]
	mov r0, #0x1c
	mul r0, r1
	add r0, r4, r0
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0225E398
	bl String_Delete
_0225E398:
	ldr r0, [sp, #8]
	bl PlayerProfile_GetNamePtr
	add r1, r0, #0
	ldr r2, [r5]
	mov r0, #0x1c
	mul r0, r2
	ldr r0, [r4, r0]
	bl CopyU16ArrayToString
	ldr r0, [r5]
	mov r1, #0x1c
	add r2, r0, #0
	mul r2, r1
	add r0, r4, r2
	ldrh r2, [r6]
	strh r2, [r0, #0x14]
	ldrh r2, [r6, #2]
	strh r2, [r0, #0x16]
	ldrh r2, [r6, #4]
	strh r2, [r0, #0x18]
	ldrh r2, [r6, #6]
	strh r2, [r0, #0x1a]
	ldr r0, [r5]
	mul r1, r0
	ldr r0, [sp, #4]
	add r1, r4, r1
	str r0, [r1, #0xc]
	ldr r0, [sp, #8]
	bl PlayerProfile_GetTrainerGender
	ldr r2, [r5]
	mov r1, #0x1c
	mul r1, r2
	add r1, r4, r1
	str r0, [r1, #0x10]
	add r0, r6, #0
	mov r1, #0x57
	bl MailMsg_GetExpandedString
	ldr r2, [r5]
	mov r1, #0x1c
	mul r1, r2
	add r1, r4, r1
	str r0, [r1, #4]
	ldr r0, [r7, #0x10]
	ldr r1, [sp, #4]
	str r0, [sp]
	ldr r0, [sp, #0xc]
	ldr r2, [r7, #0x18]
	ldr r3, [r7, #0x1c]
	bl ov34_0225E2BC
	ldr r2, [r5]
	mov r1, #0x1c
	mul r1, r2
	add r1, r4, r1
	str r0, [r1, #8]
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	mov r0, #0xd3
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	cmp r1, #0x1e
	bne _0225E420
	mov r1, #0
	str r1, [r4, r0]
_0225E420:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225E424: .word 0x000004D8
	thumb_func_end ov34_0225E348
