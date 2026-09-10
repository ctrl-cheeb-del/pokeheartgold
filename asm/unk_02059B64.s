	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02059B64
sub_02059B64: ; 0x02059B64
	push {r4, r5, r6, lr}
	add r4, r0, #0
	bl TaskManager_GetFieldSystem
	add r5, r0, #0
	add r0, r4, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	mov r1, #0
	ldr r0, [r4, #0x24]
	add r2, r1, #0
	bl sub_020588DC
	ldr r1, [r4, #0x28]
	add r6, r0, #0
	cmp r1, #7
	bls _02059B8A
	b _02059D32
_02059B8A:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02059B96: ; jump table
	.short _02059BA6 - _02059B96 - 2 ; case 0
	.short _02059C6C - _02059B96 - 2 ; case 1
	.short _02059CBC - _02059B96 - 2 ; case 2
	.short _02059CCC - _02059B96 - 2 ; case 3
	.short _02059CE8 - _02059B96 - 2 ; case 4
	.short _02059CFA - _02059B96 - 2 ; case 5
	.short _02059D08 - _02059B96 - 2 ; case 6
	.short _02059D24 - _02059B96 - 2 ; case 7
_02059BA6:
	mov r0, #4
	bl MessageFormat_New
	str r0, [r4, #0x18]
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xe
	mov r3, #4
	bl NewMsgDataFromNarc
	str r0, [r4, #0x1c]
	mov r0, #0xc8
	mov r1, #4
	bl String_New
	str r0, [r4]
	mov r0, #0xc8
	mov r1, #4
	bl String_New
	str r0, [r4, #4]
	ldrb r0, [r6]
	cmp r0, #0xc
	bhi _02059C0E
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02059BE2: ; jump table
	.short _02059C0E - _02059BE2 - 2 ; case 0
	.short _02059C0E - _02059BE2 - 2 ; case 1
	.short _02059C0E - _02059BE2 - 2 ; case 2
	.short _02059C0E - _02059BE2 - 2 ; case 3
	.short _02059C0E - _02059BE2 - 2 ; case 4
	.short _02059C0E - _02059BE2 - 2 ; case 5
	.short _02059C0E - _02059BE2 - 2 ; case 6
	.short _02059BFC - _02059BE2 - 2 ; case 7
	.short _02059BFC - _02059BE2 - 2 ; case 8
	.short _02059C0E - _02059BE2 - 2 ; case 9
	.short _02059C02 - _02059BE2 - 2 ; case 10
	.short _02059C06 - _02059BE2 - 2 ; case 11
	.short _02059C0A - _02059BE2 - 2 ; case 12
_02059BFC:
	ldrb r0, [r6, #3]
	add r1, r0, #2
	b _02059C10
_02059C02:
	mov r1, #0x19
	b _02059C10
_02059C06:
	mov r1, #0x1a
	b _02059C10
_02059C0A:
	mov r1, #0x1b
	b _02059C10
_02059C0E:
	mov r1, #2
_02059C10:
	ldr r0, [r4, #0x1c]
	ldr r2, [r4]
	bl ReadMsgDataIntoString
	ldr r0, [r4, #0x24]
	bl sub_02034818
	add r2, r0, #0
	ldr r0, [r4, #0x18]
	mov r1, #0
	bl BufferPlayersName
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #4]
	ldr r2, [r4]
	bl StringExpandPlaceholders
	add r1, r4, #0
	ldr r0, [r5, #8]
	add r1, #8
	mov r2, #3
	bl DialogBox_AddWindowToLayer3
	ldr r0, [r5, #0xc]
	bl Save_PlayerData_GetOptionsAddr
	add r1, r0, #0
	add r0, r4, #0
	add r0, #8
	bl DialogBox_LoadFrame
	ldr r0, [r5, #0xc]
	bl Save_PlayerData_GetOptionsAddr
	add r2, r0, #0
	add r0, r4, #0
	ldr r1, [r4, #4]
	add r0, #8
	mov r3, #1
	bl DialogBox_PrintMessage
	str r0, [r4, #0x20]
	ldr r0, [r4, #0x28]
	add r0, r0, #1
	str r0, [r4, #0x28]
	b _02059D36
_02059C6C:
	ldr r0, [r4, #0x20]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl DialogBox_IsPrintFinished
	cmp r0, #0
	beq _02059D36
	ldr r0, _02059D3C ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	beq _02059D36
	ldr r0, [r4, #0x1c]
	bl DestroyMsgData
	ldr r0, [r4, #0x18]
	bl MessageFormat_Delete
	ldr r0, [r4]
	bl String_Delete
	ldr r0, [r4, #4]
	bl String_Delete
	add r0, r4, #0
	add r0, #8
	mov r1, #0
	bl ClearFrameAndWindow2
	add r0, r4, #0
	add r0, #8
	bl RemoveWindow
	mov r0, #0
	bl FieldMap_FadeScreen
	ldr r0, [r4, #0x28]
	add r0, r0, #1
	str r0, [r4, #0x28]
	b _02059D36
_02059CBC:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _02059D36
	ldr r0, [r4, #0x28]
	add r0, r0, #1
	str r0, [r4, #0x28]
	b _02059D36
_02059CCC:
	add r1, r4, #0
	ldr r2, _02059D40 ; =0x0000066C
	add r1, #0x2c
	bl MI_CpuCopy8
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x2c
	bl TrainerCard_LaunchApp
	ldr r0, [r4, #0x28]
	add r0, r0, #1
	str r0, [r4, #0x28]
	b _02059D36
_02059CE8:
	add r0, r5, #0
	bl FieldSystem_ApplicationIsRunning
	cmp r0, #0
	bne _02059D36
	ldr r0, [r4, #0x28]
	add r0, r0, #1
	str r0, [r4, #0x28]
	b _02059D36
_02059CFA:
	add r0, r5, #0
	bl FieldSystem_LoadFieldOverlay
	ldr r0, [r4, #0x28]
	add r0, r0, #1
	str r0, [r4, #0x28]
	b _02059D36
_02059D08:
	add r0, r5, #0
	bl sub_020505C8
	cmp r0, #0
	bne _02059D36
	mov r0, #1
	bl FieldMap_FadeScreen
	bl sub_02056E60
	ldr r0, [r4, #0x28]
	add r0, r0, #1
	str r0, [r4, #0x28]
	b _02059D36
_02059D24:
	bl sub_02057F70
	add r0, r4, #0
	bl Heap_Free
	mov r0, #1
	pop {r4, r5, r6, pc}
_02059D32:
	mov r0, #1
	pop {r4, r5, r6, pc}
_02059D36:
	mov r0, #0
	pop {r4, r5, r6, pc}
	nop
_02059D3C: .word gSystem
_02059D40: .word 0x0000066C
	thumb_func_end sub_02059B64
	thumb_func_start sub_02059D44
sub_02059D44: ; 0x02059D44
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	bl sub_0203769C
	add r5, r0, #0
	bl sub_02057ADC
	add r7, r0, #0
	add r0, r5, #0
	bl sub_02057B14
	add r6, r0, #0
	mov r4, #0
	bl sub_02037454
	cmp r0, #0
	ble _02059DA6
_02059D66:
	cmp r4, r5
	beq _02059D9C
	add r0, r4, #0
	bl sub_02057A34
	cmp r7, r0
	bne _02059D9C
	add r0, r4, #0
	bl sub_02057A88
	cmp r6, r0
	bne _02059D9C
	ldr r1, _02059DA8 ; =0x000006A8
	mov r0, #0xb
	bl Heap_AllocAtEnd
	add r2, r0, #0
	str r4, [r2, #0x24]
	mov r0, #0
	str r0, [r2, #0x28]
	ldr r0, [sp]
	ldr r1, _02059DAC ; =sub_02059B64
	bl FieldSystem_CreateTask
	bl sub_0203E2F4
	pop {r3, r4, r5, r6, r7, pc}
_02059D9C:
	add r4, r4, #1
	bl sub_02037454
	cmp r4, r0
	blt _02059D66
_02059DA6:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02059DA8: .word 0x000006A8
_02059DAC: .word sub_02059B64
	thumb_func_end sub_02059D44
