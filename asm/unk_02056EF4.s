	.include "asm/macros.inc"
	.include "unk_02056D7C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02056EF4
sub_02056EF4: ; 0x02056EF4
	push {r4, lr}
	bl sub_0203769C
	ldr r1, _02056FCC ; =_021D41C4
	lsl r0, r0, #2
	ldr r2, [r1]
	ldr r1, [r2, #0x30]
	add r0, r2, r0
	ldr r1, [r1, #0x40]
	str r1, [r0, #4]
	bl sub_0203769C
	ldr r1, _02056FCC ; =_021D41C4
	mov r2, #1
	ldr r1, [r1]
	add r0, r1, r0
	add r0, #0x24
	strb r2, [r0]
	bl sub_0203769C
	add r4, r0, #0
	ldr r0, _02056FCC ; =_021D41C4
	ldr r0, [r0]
	ldr r0, [r0, #0x30]
	ldr r0, [r0, #0x40]
	bl PlayerAvatar_GetXCoord
	ldr r1, _02056FCC ; =_021D41C4
	ldr r2, [r1]
	lsl r1, r4, #3
	add r1, r2, r1
	add r1, #0x74
	strh r0, [r1]
	bl sub_0203769C
	add r4, r0, #0
	ldr r0, _02056FCC ; =_021D41C4
	ldr r0, [r0]
	ldr r0, [r0, #0x30]
	ldr r0, [r0, #0x40]
	bl PlayerAvatar_GetZCoord
	ldr r1, _02056FCC ; =_021D41C4
	ldr r2, [r1]
	lsl r1, r4, #3
	add r1, r2, r1
	add r1, #0x76
	strh r0, [r1]
	bl sub_0203769C
	add r4, r0, #0
	ldr r0, _02056FCC ; =_021D41C4
	ldr r0, [r0]
	ldr r0, [r0, #0x30]
	ldr r0, [r0, #0x40]
	bl PlayerAvatar_GetFacingDirection
	ldr r1, _02056FCC ; =_021D41C4
	ldr r2, [r1]
	lsl r1, r4, #3
	add r1, r2, r1
	add r1, #0x78
	strb r0, [r1]
	bl sub_0203769C
	add r4, r0, #0
	ldr r0, _02056FCC ; =_021D41C4
	ldr r0, [r0]
	ldr r0, [r0, #0x30]
	ldr r0, [r0, #0x40]
	bl PlayerAvatar_GetXCoord
	ldr r1, _02056FCC ; =_021D41C4
	ldr r2, [r1]
	lsl r1, r4, #3
	add r1, r2, r1
	strh r0, [r1, #0x34]
	bl sub_0203769C
	add r4, r0, #0
	ldr r0, _02056FCC ; =_021D41C4
	ldr r0, [r0]
	ldr r0, [r0, #0x30]
	ldr r0, [r0, #0x40]
	bl PlayerAvatar_GetZCoord
	ldr r1, _02056FCC ; =_021D41C4
	ldr r2, [r1]
	lsl r1, r4, #3
	add r1, r2, r1
	strh r0, [r1, #0x36]
	bl sub_0203769C
	add r4, r0, #0
	ldr r0, _02056FCC ; =_021D41C4
	ldr r0, [r0]
	ldr r0, [r0, #0x30]
	ldr r0, [r0, #0x40]
	bl PlayerAvatar_GetFacingDirection
	ldr r1, _02056FCC ; =_021D41C4
	ldr r2, [r1]
	lsl r1, r4, #3
	add r1, r2, r1
	add r1, #0x38
	strb r0, [r1]
	pop {r4, pc}
	nop
_02056FCC: .word _021D41C4
	thumb_func_end sub_02056EF4
