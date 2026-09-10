	.include "asm/macros.inc"
	.include "unk_02016EDC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020172C8
sub_020172C8: ; 0x020172C8
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r0, #0
	add r4, r2, #0
	add r6, r3, #0
	bl sub_02017294
	add r0, r5, #0
	add r1, sp, #0
	bl sub_02017280
	add r0, sp, #0
	ldrb r0, [r0]
	cmp r0, #0x12
	bne _02017308
	add r1, sp, #0
	add r0, r5, #0
	add r1, #2
	bl sub_02017294
	add r0, sp, #0
	ldrb r0, [r0, #2]
	add r1, r6, #0
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x24]
	str r0, [r4]
	add r0, r5, #0
	bl sub_0201726C
	add sp, #4
	pop {r3, r4, r5, r6, pc}
_02017308:
	cmp r0, #0x13
	bne _02017334
	add r1, sp, #0
	add r2, sp, #0
	add r0, r5, #0
	add r1, #2
	add r2, #1
	bl sub_020172B4
	add r0, sp, #0
	ldrb r1, [r0, #2]
	add sp, #4
	lsl r1, r1, #2
	add r1, r5, r1
	ldr r1, [r1, #0x24]
	str r1, [r4]
	ldrb r0, [r0, #1]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x24]
	str r0, [r6]
	pop {r3, r4, r5, r6, pc}
_02017334:
	bl GF_AssertFail
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	thumb_func_end sub_020172C8
	thumb_func_start sub_0201733C
sub_0201733C: ; 0x0201733C
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r0, #0
	add r4, r2, #0
	add r6, r3, #0
	bl sub_02017294
	add r1, sp, #0
	add r0, r5, #0
	add r1, #1
	bl sub_02017280
	add r0, r5, #0
	add r1, sp, #0
	bl sub_02017280
	add r0, sp, #0
	ldrb r0, [r0, #1]
	cmp r0, #0x12
	bne _0201736E
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0201726C
	b _0201738E
_0201736E:
	cmp r0, #0x13
	bne _0201738A
	add r1, sp, #0
	add r0, r5, #0
	add r1, #3
	bl sub_02017294
	add r0, sp, #0
	ldrb r0, [r0, #3]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x24]
	str r0, [r4]
	b _0201738E
_0201738A:
	bl GF_AssertFail
_0201738E:
	add r0, sp, #0
	ldrb r0, [r0]
	cmp r0, #0x12
	bne _020173A2
	add r0, r5, #0
	add r1, r6, #0
	bl sub_0201726C
	add sp, #4
	pop {r3, r4, r5, r6, pc}
_020173A2:
	cmp r0, #0x13
	bne _020173C0
	add r1, sp, #0
	add r0, r5, #0
	add r1, #2
	bl sub_02017294
	add r0, sp, #0
	ldrb r0, [r0, #2]
	add sp, #4
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x24]
	str r0, [r6]
	pop {r3, r4, r5, r6, pc}
_020173C0:
	bl GF_AssertFail
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	thumb_func_end sub_0201733C
	thumb_func_start sub_020173C8
sub_020173C8: ; 0x020173C8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r2, #0
	add r2, sp, #0
	add r2, #3
	add r5, r0, #0
	add r6, r3, #0
	bl sub_020172B4
	add r0, sp, #0
	ldrb r0, [r0, #3]
	add r1, sp, #0
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r7, [r0, #0x24]
	add r0, r5, #0
	bl sub_02017280
	add r0, sp, #0
	ldrb r0, [r0]
	cmp r0, #0x14
	bne _020173FE
	add r0, r5, #0
	add r1, r6, #0
	bl sub_0201726C
	b _0201741E
_020173FE:
	cmp r0, #0x15
	bne _0201741A
	add r1, sp, #0
	add r0, r5, #0
	add r1, #2
	bl sub_02017294
	add r0, sp, #0
	ldrb r0, [r0, #2]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x24]
	str r0, [r6]
	b _0201741E
_0201741A:
	bl GF_AssertFail
_0201741E:
	add r0, r5, #0
	add r1, sp, #0
	bl sub_02017280
	add r0, sp, #0
	ldrb r0, [r0]
	cmp r0, #0x14
	bne _02017438
	add r0, r5, #0
	add r1, sp, #4
	bl sub_0201726C
	b _02017458
_02017438:
	cmp r0, #0x15
	bne _02017454
	add r1, sp, #0
	add r0, r5, #0
	add r1, #1
	bl sub_02017294
	add r0, sp, #0
	ldrb r0, [r0, #1]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x24]
	str r0, [sp, #4]
	b _02017458
_02017454:
	bl GF_AssertFail
_02017458:
	ldr r0, [sp, #4]
	add r0, r7, r0
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x10
	sub r1, r1, r2
	mov r0, #0x10
	ror r1, r0
	add r0, r2, r1
	str r0, [r4]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_020173C8
	thumb_func_start sub_02017470
sub_02017470: ; 0x02017470
	ldr r2, [r0]
	ldr r0, [r1]
	sub r0, r2, r0
	bpl _0201747C
	mov r0, #0xf
	bx lr
_0201747C:
	cmp r0, #0
	ble _02017484
	mov r0, #0x10
	bx lr
_02017484:
	mov r0, #0x11
	bx lr
	thumb_func_end sub_02017470
	thumb_func_start sub_02017488
sub_02017488: ; 0x02017488
	add r2, r0, #0
	ldr r0, [r2]
	ldr r2, [r2, #0x74]
	mov r1, #1
	neg r3, r2
	asr r2, r3, #2
	lsr r2, r2, #0x1d
	add r2, r3, r2
	ldr r3, _020174A0 ; =Pokepic_AddAttr
	asr r2, r2, #3
	bx r3
	nop
_020174A0: .word Pokepic_AddAttr
	thumb_func_end sub_02017488
	thumb_func_start sub_020174A4
sub_020174A4: ; 0x020174A4
	push {r4, lr}
	add r4, r0, #0
	bl sub_020174BC
	mov r0, #1
	str r0, [r4, #0x18]
	str r0, [r4, #0x1c]
	pop {r4, pc}
	thumb_func_end sub_020174A4
	thumb_func_start sub_020174B4
sub_020174B4: ; 0x020174B4
	mov r1, #1
	str r1, [r0, #0x18]
	bx lr
	.balign 4, 0
	thumb_func_end sub_020174B4
	thumb_func_start sub_020174BC
sub_020174BC: ; 0x020174BC
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	ldr r2, [r4, #0x58]
	mov r1, #0
	bl Pokepic_SetAttr
	ldr r0, [r4]
	ldr r2, [r4, #0x5c]
	mov r1, #1
	bl Pokepic_SetAttr
	ldr r0, [r4]
	mov r1, #9
	mov r2, #0
	bl Pokepic_SetAttr
	ldr r0, [r4]
	mov r1, #0xa
	mov r2, #0
	bl Pokepic_SetAttr
	mov r1, #0xc
	add r2, r1, #0
	ldr r0, [r4]
	add r2, #0xf4
	bl Pokepic_SetAttr
	mov r1, #0xd
	add r2, r1, #0
	ldr r0, [r4]
	add r2, #0xf3
	bl Pokepic_SetAttr
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_020174BC
