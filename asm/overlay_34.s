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

	thumb_func_start ov34_0225D5A0
ov34_0225D5A0: ; 0x0225D5A0
	push {r3, r4, r5, lr}
	add r4, r1, #0
	ldr r0, [r4, #0xc]
	ldr r5, [r4, #0x14]
	add r1, r0, #0
	add r1, #0x84
	ldr r1, [r1]
	cmp r1, #0
	beq _0225D5F4
	ldr r1, [r4]
	cmp r1, #5
	bhi _0225D5F4
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0225D5C4: ; jump table
	.short _0225D5F4 - _0225D5C4 - 2 ; case 0
	.short _0225D5F4 - _0225D5C4 - 2 ; case 1
	.short _0225D5D0 - _0225D5C4 - 2 ; case 2
	.short _0225D5E8 - _0225D5C4 - 2 ; case 3
	.short _0225D5F4 - _0225D5C4 - 2 ; case 4
	.short _0225D5F4 - _0225D5C4 - 2 ; case 5
_0225D5D0:
	bl FieldSystem_TaskIsRunning
	cmp r0, #0
	bne _0225D5E0
	add r0, r4, #0
	add r1, r5, #0
	bl ov34_0225D558
_0225D5E0:
	ldr r0, [r4, #0x28]
	bl SpriteList_RenderAndAnimateSprites
	pop {r3, r4, r5, pc}
_0225D5E8:
	mov r1, #0
	add r2, r1, #0
	bl ov01_021F6A9C
	mov r0, #4
	str r0, [r4]
_0225D5F4:
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov34_0225D5A0
