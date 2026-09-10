	.include "asm/macros.inc"
	.include "unk_02034B0C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020351AC
sub_020351AC: ; 0x020351AC
	ldr r1, _020351D4 ; =_021D4134
	ldr r3, [r1, #8]
	lsl r1, r0, #1
	add r2, r3, r1
	ldr r1, _020351D8 ; =0x00000D44
	ldrh r1, [r2, r1]
	cmp r1, #0
	beq _020351D0
	mov r1, #0xc0
	add r2, r0, #0
	mul r2, r1
	add r0, r3, r2
	add r1, #0xaa
	ldrb r0, [r0, r1]
	cmp r0, #0
	bne _020351D2
	mov r0, #1
	bx lr
_020351D0:
	mov r0, #0
_020351D2:
	bx lr
	.balign 4, 0
_020351D4: .word _021D4134
_020351D8: .word 0x00000D44
	thumb_func_end sub_020351AC
	thumb_func_start sub_020351DC
sub_020351DC: ; 0x020351DC
	push {r4, r5, r6, lr}
	add r4, r1, #0
	ldr r1, _02035210 ; =_021D4134
	mov r5, #0
	ldr r6, [r1, #8]
	ldr r1, _02035214 ; =0x00000D44
	add r3, r5, #0
_020351EA:
	ldrh r2, [r6, r1]
	cmp r2, #0
	beq _02035204
	cmp r0, r5
	bne _02035202
	add r0, r3, #0
	bl sub_02035798
	add r1, r4, #0
	bl PlayerProfile_Copy
	pop {r4, r5, r6, pc}
_02035202:
	add r5, r5, #1
_02035204:
	add r3, r3, #1
	add r6, r6, #2
	cmp r3, #0x10
	blt _020351EA
	pop {r4, r5, r6, pc}
	nop
_02035210: .word _021D4134
_02035214: .word 0x00000D44
	thumb_func_end sub_020351DC
	thumb_func_start sub_02035218
sub_02035218: ; 0x02035218
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl sub_02033298
	cmp r0, #2
	bne _0203522C
	bl sub_02032E24
	mov r0, #0
	pop {r3, r4, r5, pc}
_0203522C:
	bl sub_02033298
	cmp r0, #1
	bne _02035282
	bl sub_0203993C
	ldr r2, _02035288 ; =_021D4134
	mov r1, #0xc0
	add r4, r5, #0
	mul r4, r1
	ldr r3, [r2, #8]
	add r1, #0x8a
	add r2, r3, r4
	ldrh r2, [r2, r1]
	mov r1, #0xd9
	lsl r1, r1, #4
	strb r2, [r3, r1]
	bl sub_0203401C
	cmp r0, #0
	beq _0203526C
	ldr r1, _02035288 ; =_021D4134
	mov r0, #1
	ldr r2, [r1, #8]
	mov r1, #0x46
	lsl r1, r1, #2
	add r1, r2, r1
	add r1, r1, r4
	mov r2, #0
	bl sub_02032B84
	b _0203527E
_0203526C:
	ldr r1, _02035288 ; =_021D4134
	mov r0, #1
	ldr r2, [r1, #8]
	mov r1, #0x45
	lsl r1, r1, #2
	add r1, r2, r1
	add r1, r1, r4
	bl sub_0203373C
_0203527E:
	mov r0, #1
	pop {r3, r4, r5, pc}
_02035282:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_02035288: .word _021D4134
	thumb_func_end sub_02035218
	thumb_func_start sub_0203528C
sub_0203528C: ; 0x0203528C
	push {r3, r4, r5, r6, r7, lr}
	bl sub_02034C94
	mov r4, #0
	ldr r1, _020352CC ; =_021D4134
	ldr r0, _020352D0 ; =0x00000D44
	add r5, r4, #0
	mov r2, #1
_0203529C:
	ldr r3, [r1, #8]
	add r3, r3, r5
	ldrh r6, [r3, r0]
	cmp r6, #0
	beq _020352C0
	beq _020352C0
	ldr r6, _020352D0 ; =0x00000D44
	ldrh r6, [r3, r6]
	sub r7, r6, #1
	ldr r6, _020352D0 ; =0x00000D44
	strh r7, [r3, r6]
	ldr r3, [r1, #8]
	add r7, r3, r5
	ldrh r6, [r7, r6]
	cmp r6, #0
	bne _020352C0
	ldr r6, _020352D4 ; =0x00000D74
	strb r2, [r3, r6]
_020352C0:
	add r4, r4, #1
	add r5, r5, #2
	cmp r4, #0x10
	blt _0203529C
	pop {r3, r4, r5, r6, r7, pc}
	nop
_020352CC: .word _021D4134
_020352D0: .word 0x00000D44
_020352D4: .word 0x00000D74
	thumb_func_end sub_0203528C
	thumb_func_start sub_020352D8
sub_020352D8: ; 0x020352D8
	push {r3, r4, r5, lr}
	bl sub_0203993C
	add r5, r0, #0
	bl sub_02035784
	add r4, r0, #0
	cmp r5, #0xf
	beq _02035360
	ldr r0, _020353A8 ; =_021D4134
	ldr r1, [r0, #8]
	ldr r0, _020353AC ; =0x00000D88
	ldr r5, [r1, r0]
	bl LinkBattleRuleset_sizeof
	cmp r0, #0x20
	ble _020352FE
	bl GF_AssertFail
_020352FE:
	bl PlayerProfile_sizeof
	cmp r0, #0x20
	beq _0203530A
	bl GF_AssertFail
_0203530A:
	bl PlayerProfile_sizeof
	add r1, r5, #0
	add r2, r0, #0
	add r0, r4, #0
	add r1, #0x10
	bl MI_CpuCopy8
	bl LinkBattleRuleset_sizeof
	add r2, r0, #0
	ldr r0, _020353A8 ; =_021D4134
	ldr r1, [r0, #8]
	ldr r0, _020353B0 ; =0x00000D7C
	ldr r0, [r1, r0]
	add r1, r5, #0
	add r1, #0x30
	bl MI_CpuCopy8
	add r0, r4, #0
	bl PlayerProfile_GetTrainerID
	str r0, [r5]
	bl sub_0203993C
	strb r0, [r5, #4]
	bl sub_02039954
	strb r0, [r5, #5]
	ldr r0, _020353A8 ; =_021D4134
	mov r2, #8
	ldr r1, [r0, #8]
	ldr r0, _020353B4 ; =0x00000D68
	add r0, r1, r0
	add r1, r5, #0
	add r1, #8
	bl MI_CpuCopy8
	bl sub_02033AB8
	add r5, #0x54
	strb r0, [r5]
	b _02035388
_02035360:
	ldr r1, _020353A8 ; =_021D4134
	ldr r2, [r1, #8]
	ldr r1, _020353AC ; =0x00000D88
	ldr r4, [r2, r1]
	bl PlayerProfile_GetTrainerID
	str r0, [r4]
	bl sub_0203993C
	strb r0, [r4, #4]
	bl sub_02039954
	strb r0, [r4, #5]
	ldr r0, _020353A8 ; =_021D4134
	add r4, #8
	ldr r0, [r0, #8]
	add r1, r4, #0
	mov r2, #0x54
	bl MI_CpuCopy8
_02035388:
	ldr r0, _020353A8 ; =_021D4134
	ldr r1, [r0, #8]
	ldr r0, _020353AC ; =0x00000D88
	ldr r0, [r1, r0]
	mov r1, #0x5c
	bl DC_FlushRange
	ldr r0, _020353A8 ; =_021D4134
	ldr r1, [r0, #8]
	ldr r0, _020353AC ; =0x00000D88
	ldr r0, [r1, r0]
	mov r1, #0x5c
	bl sub_02033240
	pop {r3, r4, r5, pc}
	nop
_020353A8: .word _021D4134
_020353AC: .word 0x00000D88
_020353B0: .word 0x00000D7C
_020353B4: .word 0x00000D68
	thumb_func_end sub_020352D8
