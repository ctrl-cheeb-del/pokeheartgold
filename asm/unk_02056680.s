	.include "asm/macros.inc"
	.include "unk_02056680.inc"
	.include "global.inc"

	.text
	.public sub_02056680
	.public sub_020566F8
	.public sub_020567B4
	.public sub_0205681C
	.public sub_02056938
	.public sub_02056A54
	.public sub_02056AEC
	.public sub_02056BC8
	.public sub_02056C64
	.public sub_02056D00
	.public sub_02056D30
	.public sub_020566F8
	.public sub_020567B4
	.public sub_0205681C
	.public sub_02056938
	.public sub_02056BC8
	.public sub_02056C64
	.public sub_02056D00
	.public sub_02056D30

	thumb_func_start sub_02056680
sub_02056680: ; 0x02056680
	push {r4, r5, r6, lr}
	add r4, r0, #0
	bl TaskManager_GetFieldSystem
	add r5, r0, #0
	add r0, r4, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _020566A2
	cmp r0, #1
	beq _020566C8
	cmp r0, #2
	beq _020566F0
	b _020566F4
_020566A2:
	bl ov01_021E90C0
	str r0, [r4, #0x18]
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetXCoord
	add r6, r0, #0
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetZCoord
	add r1, r0, #0
	ldr r2, [r4, #0x18]
	add r0, r6, #0
	bl ov01_021E90DC
	ldrh r0, [r4, #2]
	add r0, r0, #1
	strh r0, [r4, #2]
	b _020566F4
_020566C8:
	ldr r0, [r5, #0x40]
	ldr r6, [r4, #0x18]
	bl PlayerAvatar_GetFacingDirection
	add r2, r0, #0
	lsl r2, r2, #0x18
	add r0, r5, #0
	add r1, r6, #0
	lsr r2, r2, #0x18
	bl ov01_021E971C
	cmp r0, #0
	beq _020566F4
	ldr r0, [r4, #0x18]
	bl ov01_021E90D4
	ldrh r0, [r4, #2]
	add r0, r0, #1
	strh r0, [r4, #2]
	b _020566F4
_020566F0:
	mov r0, #1
	pop {r4, r5, r6, pc}
_020566F4:
	mov r0, #0
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02056680
