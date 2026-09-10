	.include "asm/macros.inc"
	.include "unk_0205A44C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205A904
sub_0205A904: ; 0x0205A904
	push {r4, lr}
	sub sp, #0x20
	add r4, r0, #0
	add r0, sp, #0
	mov r1, #0
	mov r2, #0x20
	bl MI_CpuFill8
	cmp r4, #0xd
	bhi _0205A98E
	add r0, r4, r4
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0205A924: ; jump table
	.short _0205A98E - _0205A924 - 2 ; case 0
	.short _0205A95E - _0205A924 - 2 ; case 1
	.short _0205A972 - _0205A924 - 2 ; case 2
	.short _0205A986 - _0205A924 - 2 ; case 3
	.short _0205A98E - _0205A924 - 2 ; case 4
	.short _0205A94A - _0205A924 - 2 ; case 5
	.short _0205A94A - _0205A924 - 2 ; case 6
	.short _0205A94A - _0205A924 - 2 ; case 7
	.short _0205A954 - _0205A924 - 2 ; case 8
	.short _0205A968 - _0205A924 - 2 ; case 9
	.short _0205A97C - _0205A924 - 2 ; case 10
	.short _0205A940 - _0205A924 - 2 ; case 11
	.short _0205A97C - _0205A924 - 2 ; case 12
	.short _0205A986 - _0205A924 - 2 ; case 13
_0205A940:
	add r0, sp, #0
	mov r1, #2
	bl sub_0205A8B4
	b _0205A98E
_0205A94A:
	add r0, sp, #0
	mov r1, #2
	bl sub_0205A8B4
	b _0205A98E
_0205A954:
	add r0, sp, #0
	mov r1, #5
	bl sub_0205A8B4
	b _0205A98E
_0205A95E:
	add r0, sp, #0
	mov r1, #4
	bl sub_0205A8B4
	b _0205A98E
_0205A968:
	add r0, sp, #0
	mov r1, #5
	bl sub_0205A8B4
	b _0205A98E
_0205A972:
	add r0, sp, #0
	mov r1, #4
	bl sub_0205A8B4
	b _0205A98E
_0205A97C:
	add r0, sp, #0
	mov r1, #5
	bl sub_0205A8B4
	b _0205A98E
_0205A986:
	add r0, sp, #0
	mov r1, #4
	bl sub_0205A8B4
_0205A98E:
	add r0, sp, #0
	strb r4, [r0, #0x1c]
	add r0, sp, #0
	bl sub_02035854
	bl sub_0203588C
	add sp, #0x20
	pop {r4, pc}
	thumb_func_end sub_0205A904
	thumb_func_start sub_0205A9A0
sub_0205A9A0: ; 0x0205A9A0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r3, #0
	mov r0, #0x11
	add r6, r1, #0
	add r2, r3, #0
	add r4, r5, #0
	lsl r0, r0, #4
_0205A9B0:
	ldr r1, [r4, r0]
	cmp r1, #0
	beq _0205A9B8
	add r3, r3, #1
_0205A9B8:
	add r2, r2, #1
	add r4, r4, #4
	cmp r2, #0xa
	blt _0205A9B0
	cmp r3, #0
	beq _0205A9C8
	mov r0, #0xa6
	pop {r4, r5, r6, pc}
_0205A9C8:
	mov r0, #0x5e
	lsl r0, r0, #2
	add r0, r5, r0
	bl MailMsg_IsInit
	cmp r0, #0
	bne _0205A9DA
	mov r0, #0xa7
	pop {r4, r5, r6, pc}
_0205A9DA:
	mov r0, #0x5e
	lsl r0, r0, #2
	add r0, r5, r0
	bl MailMsg_GetMsgBank
	cmp r0, #4
	beq _0205AA0C
	ldr r0, [r5, #8]
	bl PlayerProfile_GetAvatar
	add r4, r0, #0
	ldr r0, [r5, #8]
	bl PlayerProfile_GetTrainerGender
	add r1, r4, #0
	mov r2, #2
	bl GetUnionRoomAvatarAttrBySprite
	add r2, r0, #0
	add r0, r6, #0
	mov r1, #0
	bl BufferTrainerClassName
	mov r0, #0xa8
	pop {r4, r5, r6, pc}
_0205AA0C:
	mov r0, #0x5e
	lsl r0, r0, #2
	add r0, r5, r0
	bl MailMsg_GetMsgNo
	add r4, r0, #0
	cmp r4, #0x14
	blt _0205AA1E
	mov r4, #0
_0205AA1E:
	mov r0, #0x5e
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0
	bl MailMsg_GetFieldI
	add r2, r0, #0
	ldr r0, _0205AA44 ; =0x0000FFFF
	cmp r2, r0
	beq _0205AA3A
	add r0, r6, #0
	mov r1, #0
	bl BufferECWord
_0205AA3A:
	ldr r0, _0205AA48 ; =_020FC9D4
	lsl r1, r4, #2
	ldr r0, [r0, r1]
	pop {r4, r5, r6, pc}
	nop
_0205AA44: .word 0x0000FFFF
_0205AA48: .word _020FC9D4
	thumb_func_end sub_0205A9A0
