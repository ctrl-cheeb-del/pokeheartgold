	.include "asm/macros.inc"
	.include "unk_0205A44C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205AA9C
sub_0205AA9C: ; 0x0205AA9C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r2, #0
	add r5, r0, #0
	add r4, r1, #0
	str r3, [sp, #8]
	ldr r2, _0205AB80 ; =0x000002E2
	mov r0, #1
	mov r1, #0x1b
	mov r3, #4
	bl NewMsgDataFromNarc
	add r6, r0, #0
	cmp r4, #0
	bne _0205AAC2
	sub r0, r7, #1
	bl sub_02035798
	b _0205AACE
_0205AAC2:
	bl sub_0203769C
	mov r1, #1
	eor r0, r1
	bl sub_02034818
_0205AACE:
	add r4, r0, #0
	cmp r4, #0
	bne _0205AADE
	add r0, r6, #0
	bl DestroyMsgData
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_0205AADE:
	add r0, r5, #0
	mov r1, #0
	add r2, r4, #0
	bl BufferPlayersName
	ldr r2, [sp, #8]
	add r0, r5, #0
	mov r1, #1
	bl BufferPlayersName
	add r0, r4, #0
	bl PlayerProfile_GetLanguage
	add r4, r0, #0
	cmp r4, #1
	blt _0205AB1C
	cmp r4, #7
	bgt _0205AB1C
	sub r0, r4, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	cmp r0, #7
	bhs _0205AB1C
	lsl r1, r0, #2
	ldr r0, _0205AB84 ; =_020FC898
	ldr r1, [r0, r1]
	cmp r1, #0
	blt _0205AB1C
	ldr r0, [sp, #0x20]
	bl Save_EasyChat_SetGreetingFlag
_0205AB1C:
	cmp r4, #7
	bhi _0205AB54
	add r0, r4, r4
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0205AB2C: ; jump table
	.short _0205AB54 - _0205AB2C - 2 ; case 0
	.short _0205AB3C - _0205AB2C - 2 ; case 1
	.short _0205AB40 - _0205AB2C - 2 ; case 2
	.short _0205AB44 - _0205AB2C - 2 ; case 3
	.short _0205AB48 - _0205AB2C - 2 ; case 4
	.short _0205AB4C - _0205AB2C - 2 ; case 5
	.short _0205AB54 - _0205AB2C - 2 ; case 6
	.short _0205AB50 - _0205AB2C - 2 ; case 7
_0205AB3C:
	mov r1, #0xd3
	b _0205AB56
_0205AB40:
	mov r1, #0xd4
	b _0205AB56
_0205AB44:
	mov r1, #0xd5
	b _0205AB56
_0205AB48:
	mov r1, #0xd6
	b _0205AB56
_0205AB4C:
	mov r1, #0xd7
	b _0205AB56
_0205AB50:
	mov r1, #0xd8
	b _0205AB56
_0205AB54:
	mov r1, #0xd9
_0205AB56:
	add r0, r6, #0
	bl NewString_ReadMsgData
	add r7, r0, #0
	mov r0, #1
	str r0, [sp]
	add r0, r5, #0
	mov r1, #2
	add r2, r7, #0
	mov r3, #0
	str r4, [sp, #4]
	bl BufferString
	add r0, r7, #0
	bl Heap_Free
	add r0, r6, #0
	bl DestroyMsgData
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0205AB80: .word 0x000002E2
_0205AB84: .word _020FC898
	thumb_func_end sub_0205AA9C
