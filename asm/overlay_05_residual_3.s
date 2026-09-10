	.include "asm/macros.inc"
	.public ov05_0221BA00
	.public ov05_0221BA70
	.public ov05_0221BB00
	.public ov05_0221BB30
	.public ov05_0221BD28
	.public ov05_0221BE04
	.public ov05_0221BE80
	.public ov05_0221BF08
	.public ov05_0221C018
	.public ov05_0221C050
	.public ov05_0221C21C
	.public ov05_0221C430
	.public ov05_0221C558
	.public ov05_0221C568
	.public ov05_0221C5A8
	.public ov05_0221C5C4
	.public ov05_0221C6C8
	.public ov05_0221C7FC
	.public ov05_0221C80C
	.public ov05_0221C8A0
	.public ov05_0221C8E0
	.public ov05_0221C908
	.public ov05_0221CAB8
	.public ov05_0221CB70
	.public ov05_0221CC04
	.public ov05_0221CC58
	.public ov05_0221CC74
	.public ov05_0221CCF4
	.public ov05_0221CD24
	.public ov05_0221CDC4
	.public ov05_0221CE0C
	.public ov05_0221CE50
	.public ov05_0221CE88
	.public ov05_0221CEB8
	.public ov05_0221CFF0
	.public ov05_0221D020
	.public ov05_0221D054
	.public ov05_0221D094
	.public ov05_0221D140
	.public ov05_0221D228
	.public ov05_0221D240
	.public ov05_0221D318
	.public ov05_0221D3AC
	.public ov05_0221D414
	.public ov05_0221D4D0
	.public ov05_0221D530
	.public ov05_0221D5DC
	.public ov05_0221D664
	.public ov05_0221D690
	.public ov05_0221D6C4
	.public ov05_0221D7AC
	.public ov05_0221D890
	.public ov05_0221D904
	.public ov05_0221D9F0
	.public ov05_0221DAE0
	.public ov05_0221DB18
	.public ov05_0221DB4C
	.public ov05_0221DB70
	.public ov05_0221DB94
	.public ov05_0221DC34
	.public ov05_0221DC60
	.public ov05_0221DD08
	.public ov05_0221DDEC
	.public ov05_0221DE38
	.public ov05_0221DE6C
	.public ov05_0221DF38
	.public ov05_0221E07C
	.public ov05_0221E0A8
	.public ov05_0221E110
	.public ov05_0221E274
	.public ov05_0221E2D8
	.public ov05_0221E390
	.public ov05_0221E42C
	.public ov05_0221E4C8
	.public ov05_0221E564
	.public ov05_0221E5E4
	.public ov05_0221E60C
	.public ov05_0221E624
	.public ov05_0221E714
	.public ov05_0221E74C
	.public ov05_0221E7B8
	.public ov05_0221E8A8
	.public ov05_0221E944
	.public ov05_0221E9C4
	.public ov05_0221E9F8
	.public ov05_0221EA18
	.public ov05_0221EA38
	.public _0221EA54
	.public ov05_0221EA58
	.public ov05_0221EA60
	.public ov05_0221EA6C
	.public ov05_0221EA6D
	.public ov05_0221EA78
	.public ov05_0221EA88
	.public ov05_0221EA98
	.public ov05_0221EAAC
	.public ov05_0221EAC0
	.public ov05_0221EAD4
	.public ov05_0221EAEC
	.public ov05_0221EB04
	.public ov05_0221EB1C
	.public ov05_0221EB38
	.public ov05_0221EB54
	.public ov05_0221EB70
	.public ov05_0221EB8C
	.public ov05_0221EBA8
	.public ov05_0221EBC4
	.public ov05_0221EBE0
	.public ov05_0221EC00
	.public ov05_0221EC28
	.public ov05_0221EC5C
	.public ov05_0221EC98
	.public ov05_0221ECE4
	.public ov05_0221EDA4
	.public ov05_0221EF2C
	.include "overlay_05.inc"
	.include "global.inc"

	.text

	thumb_func_start ov05_0221C050
ov05_0221C050: ; 0x0221C050
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #3
	bl Bg_GetXpos
	cmp r0, #0x18
	bgt _0221C0EC
	ldr r1, _0221C214 ; =0x00000B82
	mov r2, #0
	add r0, r1, #0
	strb r2, [r4, r1]
	sub r0, #0xa
	strh r2, [r4, r0]
	sub r1, #8
	strh r2, [r4, r1]
	ldr r0, [r4, #0xc]
	mov r1, #3
	mov r3, #0x18
	bl ScheduleSetBgPosText
	mov r2, #0
	add r3, r2, #0
	ldr r0, [r4, #0xc]
	mov r1, #2
	sub r3, #0x18
	bl ScheduleSetBgPosText
	mov r1, #0
	add r0, r4, #0
	add r2, r1, #0
	add r3, r1, #0
	bl ov05_0221D3AC
	mov r2, #0
	add r0, r4, #0
	mov r1, #1
	add r3, r2, #0
	bl ov05_0221D3AC
	mov r2, #0
	add r0, r4, #0
	mov r1, #2
	add r3, r2, #0
	bl ov05_0221D3AC
	mov r2, #0
	add r0, r4, #0
	mov r1, #3
	add r3, r2, #0
	bl ov05_0221D3AC
	mov r1, #0
	add r0, r4, #0
	add r2, r1, #0
	add r3, r1, #0
	bl ov05_0221D664
	mov r2, #0
	add r0, r4, #0
	mov r1, #1
	add r3, r2, #0
	bl ov05_0221D664
	mov r2, #0
	add r0, r4, #0
	mov r1, #2
	add r3, r2, #0
	bl ov05_0221D664
	mov r2, #0
	add r0, r4, #0
	mov r1, #3
	add r3, r2, #0
	bl ov05_0221D664
	mov r0, #1
	pop {r3, r4, r5, pc}
_0221C0EC:
	ldr r3, _0221C218 ; =0x00000B74
	ldr r0, [r4, #0xc]
	ldr r3, [r4, r3]
	mov r1, #3
	mov r2, #2
	bl ScheduleSetBgPosText
	ldr r3, _0221C218 ; =0x00000B74
	ldr r0, [r4, #0xc]
	ldr r3, [r4, r3]
	mov r1, #2
	mov r2, #1
	bl ScheduleSetBgPosText
	ldr r3, _0221C214 ; =0x00000B82
	mov r1, #0
	ldrb r0, [r4, r3]
	add r2, r3, #0
	sub r2, #0xe
	add r0, r0, #1
	strb r0, [r4, r3]
	ldr r5, [r4, r2]
	ldrb r2, [r4, r3]
	add r3, r5, #0
	add r0, r4, #0
	mul r3, r2
	mov r2, #1
	lsl r2, r2, #8
	sub r2, r3, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add r3, r1, #0
	bl ov05_0221D3AC
	ldr r2, _0221C218 ; =0x00000B74
	mov r1, #1
	ldr r3, [r4, r2]
	add r2, #0xe
	add r5, r3, #0
	ldrb r2, [r4, r2]
	add r0, r4, #0
	mov r3, #0
	mul r5, r2
	add r2, r1, #0
	add r2, #0xff
	sub r2, r5, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D3AC
	ldr r2, _0221C218 ; =0x00000B74
	mov r1, #2
	ldr r3, [r4, r2]
	add r2, #0xe
	add r5, r3, #0
	ldrb r2, [r4, r2]
	add r0, r4, #0
	mov r3, #0
	mul r5, r2
	add r2, r1, #0
	add r2, #0xfe
	sub r2, r2, r5
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D3AC
	ldr r2, _0221C218 ; =0x00000B74
	mov r1, #3
	ldr r3, [r4, r2]
	add r2, #0xe
	add r5, r3, #0
	ldrb r2, [r4, r2]
	add r0, r4, #0
	mov r3, #0
	mul r5, r2
	add r2, r1, #0
	add r2, #0xfd
	sub r2, r2, r5
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D3AC
	ldr r2, _0221C218 ; =0x00000B74
	mov r1, #0
	ldr r3, [r4, r2]
	add r2, #0xe
	add r5, r3, #0
	ldrb r2, [r4, r2]
	add r0, r4, #0
	add r3, r1, #0
	mul r5, r2
	mov r2, #1
	lsl r2, r2, #8
	sub r2, r5, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D664
	ldr r2, _0221C218 ; =0x00000B74
	mov r1, #1
	ldr r3, [r4, r2]
	add r2, #0xe
	add r5, r3, #0
	ldrb r2, [r4, r2]
	add r0, r4, #0
	mov r3, #0
	mul r5, r2
	add r2, r1, #0
	add r2, #0xff
	sub r2, r5, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D664
	ldr r2, _0221C218 ; =0x00000B74
	mov r1, #2
	ldr r3, [r4, r2]
	add r2, #0xe
	add r5, r3, #0
	ldrb r2, [r4, r2]
	add r0, r4, #0
	mov r3, #0
	mul r5, r2
	add r2, r1, #0
	add r2, #0xfe
	sub r2, r2, r5
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D664
	ldr r2, _0221C218 ; =0x00000B74
	add r0, r4, #0
	ldr r3, [r4, r2]
	add r2, #0xe
	ldrb r2, [r4, r2]
	add r4, r3, #0
	mov r1, #3
	mul r4, r2
	add r2, r1, #0
	add r2, #0xfd
	sub r2, r2, r4
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	mov r3, #0
	bl ov05_0221D664
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0221C214: .word 0x00000B82
_0221C218: .word 0x00000B74
	thumb_func_end ov05_0221C050


	thumb_func_start ov05_0221C21C
ov05_0221C21C: ; 0x0221C21C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl ov05_0221DAE0
	cmp r0, #0
	bne _0221C238
	ldr r0, _0221C418 ; =0x00000B82
	ldrb r1, [r5, r0]
	cmp r1, #0x18
	bls _0221C238
	mov r1, #0
	strb r1, [r5, r0]
	mov r0, #1
	pop {r4, r5, r6, pc}
_0221C238:
	ldr r0, _0221C418 ; =0x00000B82
	ldrb r0, [r5, r0]
	cmp r0, #0
	bne _0221C258
	ldr r0, [r5]
	add r0, #0x28
	ldrb r0, [r0]
	cmp r0, #1
	bne _0221C252
	ldr r0, _0221C41C ; =0x00000715
	bl PlaySE
	b _0221C258
_0221C252:
	ldr r0, _0221C420 ; =0x00000852
	bl PlaySE
_0221C258:
	ldr r0, _0221C418 ; =0x00000B82
	ldrb r1, [r5, r0]
	cmp r1, #0x18
	bne _0221C2F4
	ldr r0, [r5, #0xc]
	mov r1, #3
	mov r2, #0
	mov r3, #0x18
	bl ScheduleSetBgPosText
	mov r2, #0
	add r3, r2, #0
	ldr r0, [r5, #0xc]
	mov r1, #2
	sub r3, #0x18
	bl ScheduleSetBgPosText
	mov r1, #3
	ldr r0, [r5, #0xc]
	add r2, r1, #0
	mov r3, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5, #0xc]
	mov r1, #2
	mov r2, #3
	mov r3, #0
	bl ScheduleSetBgPosText
	mov r1, #0
	add r0, r5, #0
	add r2, r1, #0
	add r3, r1, #0
	bl ov05_0221D3AC
	mov r2, #0
	add r0, r5, #0
	mov r1, #1
	add r3, r2, #0
	bl ov05_0221D3AC
	mov r2, #0
	add r0, r5, #0
	mov r1, #2
	add r3, r2, #0
	bl ov05_0221D3AC
	mov r2, #0
	add r0, r5, #0
	mov r1, #3
	add r3, r2, #0
	bl ov05_0221D3AC
	mov r1, #0
	add r0, r5, #0
	add r2, r1, #0
	add r3, r1, #0
	bl ov05_0221D664
	mov r2, #0
	add r0, r5, #0
	mov r1, #1
	add r3, r2, #0
	bl ov05_0221D664
	mov r2, #0
	add r0, r5, #0
	mov r1, #2
	add r3, r2, #0
	bl ov05_0221D664
	mov r2, #0
	add r0, r5, #0
	mov r1, #3
	add r3, r2, #0
	bl ov05_0221D664
	b _0221C40C
_0221C2F4:
	blo _0221C2F8
	b _0221C40C
_0221C2F8:
	sub r0, r0, #6
	ldrsb r4, [r5, r0]
	bl LCRandom
	add r1, r4, #0
	bl _s32_div_f
	lsr r0, r4, #0x1f
	add r0, r4, r0
	asr r0, r0, #1
	sub r0, r1, r0
	lsl r0, r0, #0x10
	asr r6, r0, #0x10
	ldr r0, _0221C424 ; =0x00000B7D
	ldrsb r4, [r5, r0]
	bl LCRandom
	add r1, r4, #0
	bl _s32_div_f
	lsr r0, r4, #0x1f
	add r0, r4, r0
	asr r0, r0, #1
	sub r0, r1, r0
	lsl r0, r0, #0x10
	asr r4, r0, #0x10
	cmp r6, #0
	bge _0221C338
	ldr r0, _0221C428 ; =0x00000B78
	ldrsh r0, [r5, r0]
	cmp r0, #0
	blt _0221C344
_0221C338:
	cmp r6, #0
	ble _0221C34E
	ldr r0, _0221C428 ; =0x00000B78
	ldrsh r0, [r5, r0]
	cmp r0, #0
	ble _0221C34E
_0221C344:
	mov r0, #0
	mvn r0, r0
	mul r0, r6
	lsl r0, r0, #0x10
	asr r6, r0, #0x10
_0221C34E:
	cmp r4, #0
	bge _0221C35A
	ldr r0, _0221C42C ; =0x00000B7A
	ldrsh r0, [r5, r0]
	cmp r0, #0
	blt _0221C366
_0221C35A:
	cmp r4, #0
	ble _0221C370
	ldr r0, _0221C42C ; =0x00000B7A
	ldrsh r0, [r5, r0]
	cmp r0, #0
	ble _0221C370
_0221C366:
	mov r0, #0
	mvn r0, r0
	mul r0, r4
	lsl r0, r0, #0x10
	asr r4, r0, #0x10
_0221C370:
	add r3, r6, #0
	ldr r0, [r5, #0xc]
	mov r1, #3
	mov r2, #0
	add r3, #0x18
	bl ScheduleSetBgPosText
	add r3, r6, #0
	ldr r0, [r5, #0xc]
	mov r1, #2
	mov r2, #0
	sub r3, #0x18
	bl ScheduleSetBgPosText
	mov r1, #3
	ldr r0, [r5, #0xc]
	add r2, r1, #0
	add r3, r4, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5, #0xc]
	mov r1, #2
	mov r2, #3
	add r3, r4, #0
	bl ScheduleSetBgPosText
	add r0, r5, #0
	mov r1, #0
	add r2, r6, #0
	add r3, r4, #0
	bl ov05_0221D3AC
	add r0, r5, #0
	mov r1, #1
	add r2, r6, #0
	add r3, r4, #0
	bl ov05_0221D3AC
	add r0, r5, #0
	mov r1, #2
	add r2, r6, #0
	add r3, r4, #0
	bl ov05_0221D3AC
	add r0, r5, #0
	mov r1, #3
	add r2, r6, #0
	add r3, r4, #0
	bl ov05_0221D3AC
	add r0, r5, #0
	mov r1, #0
	add r2, r6, #0
	add r3, r4, #0
	bl ov05_0221D664
	add r0, r5, #0
	mov r1, #1
	add r2, r6, #0
	add r3, r4, #0
	bl ov05_0221D664
	add r0, r5, #0
	mov r1, #2
	add r2, r6, #0
	add r3, r4, #0
	bl ov05_0221D664
	add r0, r5, #0
	mov r1, #3
	add r2, r6, #0
	add r3, r4, #0
	bl ov05_0221D664
	ldr r0, _0221C428 ; =0x00000B78
	strh r6, [r5, r0]
	add r0, r0, #2
	strh r4, [r5, r0]
_0221C40C:
	ldr r0, _0221C418 ; =0x00000B82
	ldrb r1, [r5, r0]
	add r1, r1, #1
	strb r1, [r5, r0]
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0221C418: .word 0x00000B82
_0221C41C: .word 0x00000715
_0221C420: .word 0x00000852
_0221C424: .word 0x00000B7D
_0221C428: .word 0x00000B78
_0221C42C: .word 0x00000B7A
	thumb_func_end ov05_0221C21C


	thumb_func_start ov05_0221C430
ov05_0221C430: ; 0x0221C430
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldr r0, _0221C548 ; =0x00000B82
	ldrb r0, [r4, r0]
	cmp r0, #8
	bne _0221C458
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	ldr r3, _0221C54C ; =0x00007FFF
	ldr r0, [r0, #0x24]
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	bl BeginNormalPaletteFade
_0221C458:
	ldr r0, _0221C548 ; =0x00000B82
	ldrb r0, [r4, r0]
	cmp r0, #8
	blo _0221C474
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0221C474
	ldr r0, _0221C550 ; =0x00000B7F
	mov r1, #2
	strb r1, [r4, r0]
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, pc}
_0221C474:
	ldr r0, _0221C548 ; =0x00000B82
	ldrb r0, [r4, r0]
	cmp r0, #0
	bne _0221C482
	ldr r0, _0221C554 ; =0x00000719
	bl PlaySE
_0221C482:
	ldr r0, [r4, #0xc]
	mov r1, #3
	mov r2, #1
	mov r3, #0x10
	bl ScheduleSetBgPosText
	mov r1, #2
	ldr r0, [r4, #0xc]
	add r2, r1, #0
	mov r3, #0x10
	bl ScheduleSetBgPosText
	ldr r2, _0221C548 ; =0x00000B82
	mov r1, #0
	ldrb r0, [r4, r2]
	add r3, r1, #0
	add r0, r0, #1
	strb r0, [r4, r2]
	ldrb r2, [r4, r2]
	add r0, r4, #0
	lsl r2, r2, #4
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D3AC
	ldr r2, _0221C548 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #1
	mov r3, #0
	lsl r2, r2, #4
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D3AC
	ldr r2, _0221C548 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #2
	mov r3, #0
	lsl r2, r2, #0x14
	asr r2, r2, #0x10
	bl ov05_0221D3AC
	ldr r2, _0221C548 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #3
	mov r3, #0
	lsl r2, r2, #0x14
	asr r2, r2, #0x10
	bl ov05_0221D3AC
	ldr r2, _0221C548 ; =0x00000B82
	mov r1, #0
	ldrb r2, [r4, r2]
	add r0, r4, #0
	add r3, r1, #0
	lsl r2, r2, #4
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D664
	ldr r2, _0221C548 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #1
	mov r3, #0
	lsl r2, r2, #4
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D664
	ldr r2, _0221C548 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #2
	mov r3, #0
	lsl r2, r2, #0x14
	asr r2, r2, #0x10
	bl ov05_0221D664
	ldr r2, _0221C548 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #3
	mov r3, #0
	lsl r2, r2, #0x14
	asr r2, r2, #0x10
	bl ov05_0221D664
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	nop
_0221C548: .word 0x00000B82
_0221C54C: .word 0x00007FFF
_0221C550: .word 0x00000B7F
_0221C554: .word 0x00000719
	thumb_func_end ov05_0221C430
