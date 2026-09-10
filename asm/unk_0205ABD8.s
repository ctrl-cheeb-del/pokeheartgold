	.include "asm/macros.inc"
	.include "unk_0205A44C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205ABD8
sub_0205ABD8: ; 0x0205ABD8
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r0, #0
	mov r0, #0
	bl sub_020691A8
	mov r1, #0x61
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0
	bl sub_020691A8
	mov r1, #0x62
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0
	bl sub_020691A8
	mov r1, #0x63
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, #8]
	bl PlayerProfile_GetTrainerGender
	add r5, r0, #0
	ldr r0, [r4, #8]
	bl PlayerProfile_GetAvatar
	add r1, r0, #0
	add r0, r5, #0
	mov r2, #0
	bl GetUnionRoomAvatarAttrBySprite
	add r3, r0, #0
	ldr r0, [r4]
	lsl r3, r3, #0x18
	str r0, [sp]
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	lsr r3, r3, #0x18
	str r0, [sp, #4]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	bl sub_02068FC8
	bl sub_0203769C
	mov r1, #1
	eor r0, r1
	lsl r0, r0, #2
	add r1, r4, r0
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add sp, #8
	pop {r3, r4, r5, pc}
	thumb_func_end sub_0205ABD8
