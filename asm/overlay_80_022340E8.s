	.include "asm/macros.inc"
	.include "overlay_80_022340E8.inc"
	.include "global.inc"

    .text

	thumb_func_start BattleArcadeData_Alloc
BattleArcadeData_Alloc: ; 0x022340E8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r7, r1, #0
	add r4, r0, #0
	str r2, [sp, #4]
	ldr r1, _02234370 ; =0x00000A88
	mov r0, #0xb
	str r3, [sp, #8]
	bl Heap_Alloc
	ldr r1, _02234374 ; =ov80_0223DD4C
	ldr r2, _02234370 ; =0x00000A88
	str r0, [r1]
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, _02234374 ; =ov80_0223DD4C
	ldr r5, [r0]
	add r0, r4, #0
	bl sub_02030E88
	str r0, [r5, #8]
	ldr r1, _02234374 ; =ov80_0223DD4C
	str r4, [r5, #4]
	mov r0, #0xb
	str r0, [r5]
	ldr r5, [r1]
	bl SaveArray_Party_Alloc
	str r0, [r5, #0x70]
	mov r0, #0xb
	bl SaveArray_Party_Alloc
	str r0, [r5, #0x74]
	mov r0, #0x2a
	ldr r1, [sp, #0x38]
	lsl r0, r0, #6
	str r1, [r5, r0]
	mov r0, #0x20
	strb r0, [r5, #0x13]
	add r0, r4, #0
	ldr r6, [r5, #8]
	bl sub_02030FA0
	add r4, r0, #0
	cmp r7, #0
	bne _022341EC
	ldr r0, _02234374 ; =ov80_0223DD4C
	mov r1, #0
	ldr r2, [r0]
	ldr r0, [sp, #4]
	strb r0, [r2, #0x10]
	strb r1, [r2, #0x11]
	mov r0, #3
	strb r0, [r2, #0x1c]
	add r0, r6, #0
	strb r1, [r2, #0x12]
	bl sub_02030E7C
	ldr r0, _02234374 ; =ov80_0223DD4C
	ldr r0, [r0]
	ldrb r2, [r0, #0x10]
	cmp r2, #3
	bne _02234174
	ldr r0, [r0, #4]
	bl Save_VarsFlags_Get
	bl Save_VarsFlags_GetVar4052
	b _02234180
_02234174:
	mov r3, #0
	add r0, r4, #0
	mov r1, #8
	str r3, [sp]
	bl sub_02030FE4
_02234180:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bne _022341B8
	ldr r0, _02234374 ; =ov80_0223DD4C
	ldr r5, [r0]
	ldr r0, [r5, #4]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	ldr r0, _02234374 ; =ov80_0223DD4C
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl sub_0205C2C0
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C2C0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl FrontierSave_GetStat
	strh r0, [r5, #0x18]
	b _022341C0
_022341B8:
	ldr r0, _02234374 ; =ov80_0223DD4C
	mov r1, #0
	ldr r0, [r0]
	strh r1, [r0, #0x18]
_022341C0:
	ldr r0, _02234374 ; =ov80_0223DD4C
	mov r1, #7
	ldr r4, [r0]
	ldrh r0, [r4, #0x18]
	bl _s32_div_f
	strh r0, [r4, #0x1a]
	mov r0, #0
	str r0, [r4, #0x24]
	add r1, r4, #0
	ldr r0, [sp, #8]
	add r1, #0x2c
	strb r0, [r1]
	add r0, r4, #0
	add r1, sp, #0x20
	ldrh r2, [r1, #0x10]
	add r0, #0x2d
	add r4, #0x2e
	strb r2, [r0]
	ldrh r0, [r1, #0x14]
	strb r0, [r4]
	b _02234294
_022341EC:
	mov r1, #0
	add r0, r6, #0
	add r2, r1, #0
	add r3, r1, #0
	str r1, [sp]
	bl sub_02030F34
	ldr r1, _02234374 ; =ov80_0223DD4C
	mov r2, #0
	ldr r1, [r1]
	add r3, r2, #0
	strb r0, [r1, #0x10]
	add r0, r6, #0
	mov r1, #2
	str r2, [sp]
	bl sub_02030F34
	ldr r1, _02234374 ; =ov80_0223DD4C
	mov r2, #0
	ldr r4, [r1]
	mov r1, #3
	strb r0, [r4, #0x11]
	str r2, [sp]
	add r0, r6, #0
	add r3, r2, #0
	bl sub_02030F34
	strb r0, [r4, #0x1c]
	mov r2, #0
	str r2, [sp]
	add r0, r6, #0
	mov r1, #1
	add r3, r2, #0
	bl sub_02030F34
	strb r0, [r4, #0x12]
	ldr r0, _02234374 ; =ov80_0223DD4C
	ldr r5, [r0]
	ldr r0, [r5, #4]
	bl Save_Frontier_GetStatic
	add r7, r0, #0
	ldr r0, _02234374 ; =ov80_0223DD4C
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl sub_0205C2C0
	str r0, [sp, #0x10]
	ldrb r0, [r4, #0x10]
	bl sub_0205C2C0
	bl sub_0205C268
	add r2, r0, #0
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	bl FrontierSave_GetStat
	strh r0, [r5, #0x18]
	ldrh r0, [r5, #0x18]
	mov r1, #7
	bl _s32_div_f
	mov r4, #0
	strh r0, [r5, #0x1a]
	add r7, r4, #0
_02234270:
	ldr r0, _02234374 ; =ov80_0223DD4C
	lsl r2, r4, #0x18
	ldr r5, [r0]
	add r0, r6, #0
	mov r1, #6
	lsr r2, r2, #0x18
	add r3, r7, #0
	str r7, [sp]
	bl sub_02030F34
	add r1, r5, r4
	add r1, #0x2c
	strb r0, [r1]
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #3
	blo _02234270
_02234294:
	ldr r6, _02234374 ; =ov80_0223DD4C
	ldr r7, _02234378 ; =0x00000412
	mov r5, #0
_0223429A:
	ldr r4, [r6]
	ldr r0, [r4, #4]
	bl SaveArray_Party_Get
	add r1, r4, r5
	add r1, #0x2c
	ldrb r1, [r1]
	bl Party_GetMonByIndex
	ldr r4, [r6]
	mov r1, #6
	mov r2, #0
	bl GetMonData
	lsl r1, r5, #1
	add r1, r4, r1
	strh r0, [r1, r7]
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #3
	blo _0223429A
	ldr r0, [r4, #4]
	bl SaveArray_Party_Get
	str r0, [sp, #0xc]
	ldr r0, _02234374 ; =ov80_0223DD4C
	mov r1, #0
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl BattleArcade_GetMonCount
	add r7, r0, #0
	mov r5, #0
	cmp r7, #0
	ble _0223434E
	ldr r6, _02234374 ; =ov80_0223DD4C
_022342E4:
	ldr r1, [r6]
	ldr r0, [sp, #0xc]
	add r1, r1, r5
	add r1, #0x2c
	ldrb r1, [r1]
	bl Party_GetMonByIndex
	add r1, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #0x70]
	bl Party_AddMon
	ldr r0, [r6]
	add r1, r5, #0
	ldr r0, [r0, #0x70]
	bl Party_GetMonByIndex
	mov r1, #0
	str r1, [sp, #0x18]
	add r4, r0, #0
	mov r1, #6
	add r2, sp, #0x18
	bl SetMonData
	add r0, r4, #0
	mov r1, #0xa1
	mov r2, #0
	bl GetMonData
	cmp r0, #0x32
	bls _02234344
	add r0, r4, #0
	mov r1, #5
	mov r2, #0
	bl GetMonData
	mov r1, #0x32
	bl GetMonExpBySpeciesAndLevel
	str r0, [sp, #0x14]
	add r0, r4, #0
	mov r1, #8
	add r2, sp, #0x14
	bl SetMonData
	add r0, r4, #0
	bl CalcMonLevelAndStats
_02234344:
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, r7
	blt _022342E4
_0223434E:
	ldr r0, _02234374 ; =ov80_0223DD4C
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	bl BattleArcade_MultiplayerCheck
	cmp r0, #1
	bne _02234366
	ldr r0, _02234374 ; =ov80_0223DD4C
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl ov80_0222A840
_02234366:
	ldr r0, _02234374 ; =ov80_0223DD4C
	ldr r0, [r0]
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_02234370: .word 0x00000A88
_02234374: .word ov80_0223DD4C
_02234378: .word 0x00000412
	thumb_func_end BattleArcadeData_Alloc
