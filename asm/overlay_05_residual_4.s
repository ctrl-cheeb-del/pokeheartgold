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

	thumb_func_start ov05_0221C5A8
ov05_0221C5A8: ; 0x0221C5A8
	push {r3, lr}
	ldr r1, _0221C5C0 ; =0x00000B7E
	ldrb r1, [r0, r1]
	cmp r1, #0
	bne _0221C5B8
	bl ov05_0221C5C4
	pop {r3, pc}
_0221C5B8:
	bl ov05_0221C6C8
	pop {r3, pc}
	nop
_0221C5C0: .word 0x00000B7E
	thumb_func_end ov05_0221C5A8


	thumb_func_start ov05_0221C5C4
ov05_0221C5C4: ; 0x0221C5C4
	push {r3, r4, r5, lr}
	ldr r3, _0221C6B8 ; =0x00000B82
	add r4, r0, #0
	ldrb r3, [r4, r3]
	mov r1, #2
	ldr r0, [r4, #0xc]
	lsl r5, r3, #1
	ldr r3, _0221C6BC ; =ov05_0221EA6C
	add r2, r1, #0
	ldrb r3, [r3, r5]
	bl ScheduleSetBgPosText
	ldr r3, _0221C6B8 ; =0x00000B82
	ldr r0, [r4, #0xc]
	ldrb r3, [r4, r3]
	mov r1, #3
	mov r2, #2
	lsl r5, r3, #1
	ldr r3, _0221C6BC ; =ov05_0221EA6C
	ldrb r3, [r3, r5]
	bl ScheduleSetBgPosText
	ldr r2, _0221C6B8 ; =0x00000B82
	mov r1, #0
	ldrb r2, [r4, r2]
	add r0, r4, #0
	lsl r3, r2, #1
	ldr r2, _0221C6C0 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	add r3, r1, #0
	bl ov05_0221D3AC
	ldr r2, _0221C6B8 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #1
	lsl r3, r2, #1
	ldr r2, _0221C6C0 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	bl ov05_0221D3AC
	ldr r2, _0221C6B8 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #2
	lsl r3, r2, #1
	ldr r2, _0221C6C0 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	bl ov05_0221D3AC
	ldr r2, _0221C6B8 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #3
	lsl r3, r2, #1
	ldr r2, _0221C6C0 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	bl ov05_0221D3AC
	ldr r2, _0221C6B8 ; =0x00000B82
	mov r1, #0
	ldrb r2, [r4, r2]
	add r0, r4, #0
	lsl r3, r2, #1
	ldr r2, _0221C6C0 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	add r3, r1, #0
	bl ov05_0221D664
	ldr r2, _0221C6B8 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #1
	lsl r3, r2, #1
	ldr r2, _0221C6C0 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	bl ov05_0221D664
	ldr r2, _0221C6B8 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #2
	lsl r3, r2, #1
	ldr r2, _0221C6C0 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	bl ov05_0221D664
	ldr r2, _0221C6B8 ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #3
	lsl r3, r2, #1
	ldr r2, _0221C6C0 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	bl ov05_0221D664
	ldr r0, _0221C6B8 ; =0x00000B82
	ldrb r0, [r4, r0]
	cmp r0, #0
	bne _0221C69E
	ldr r0, _0221C6C4 ; =0x00000853
	bl PlaySE
_0221C69E:
	ldr r0, _0221C6B8 ; =0x00000B82
	ldrb r1, [r4, r0]
	cmp r1, #5
	bne _0221C6AE
	mov r1, #0
	strb r1, [r4, r0]
	mov r0, #1
	pop {r3, r4, r5, pc}
_0221C6AE:
	add r1, r1, #1
	strb r1, [r4, r0]
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0221C6B8: .word 0x00000B82
_0221C6BC: .word ov05_0221EA6C
_0221C6C0: .word ov05_0221EA6D
_0221C6C4: .word 0x00000853
	thumb_func_end ov05_0221C5C4


	thumb_func_start ov05_0221C6C8
ov05_0221C6C8: ; 0x0221C6C8
	push {r3, r4, r5, lr}
	ldr r3, _0221C7EC ; =0x00000B82
	add r4, r0, #0
	ldrb r3, [r4, r3]
	ldr r0, [r4, #0xc]
	mov r1, #2
	lsl r5, r3, #1
	ldr r3, _0221C7F0 ; =ov05_0221EA6C
	mov r2, #1
	ldrb r3, [r3, r5]
	bl ScheduleSetBgPosText
	ldr r3, _0221C7EC ; =0x00000B82
	ldr r0, [r4, #0xc]
	ldrb r3, [r4, r3]
	mov r1, #3
	mov r2, #1
	lsl r5, r3, #1
	ldr r3, _0221C7F0 ; =ov05_0221EA6C
	ldrb r3, [r3, r5]
	bl ScheduleSetBgPosText
	ldr r2, _0221C7EC ; =0x00000B82
	mov r1, #0
	ldrb r2, [r4, r2]
	add r0, r4, #0
	lsl r3, r2, #1
	ldr r2, _0221C7F4 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	add r3, r1, #0
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D3AC
	ldr r2, _0221C7EC ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #1
	lsl r3, r2, #1
	ldr r2, _0221C7F4 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D3AC
	ldr r2, _0221C7EC ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #2
	lsl r3, r2, #1
	ldr r2, _0221C7F4 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D3AC
	ldr r2, _0221C7EC ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #3
	lsl r3, r2, #1
	ldr r2, _0221C7F4 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D3AC
	ldr r2, _0221C7EC ; =0x00000B82
	mov r1, #0
	ldrb r2, [r4, r2]
	add r0, r4, #0
	lsl r3, r2, #1
	ldr r2, _0221C7F4 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	add r3, r1, #0
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D664
	ldr r2, _0221C7EC ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #1
	lsl r3, r2, #1
	ldr r2, _0221C7F4 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D664
	ldr r2, _0221C7EC ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #2
	lsl r3, r2, #1
	ldr r2, _0221C7F4 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D664
	ldr r2, _0221C7EC ; =0x00000B82
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #3
	lsl r3, r2, #1
	ldr r2, _0221C7F4 ; =ov05_0221EA6D
	ldrb r2, [r2, r3]
	mov r3, #0
	neg r2, r2
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ov05_0221D664
	ldr r0, _0221C7EC ; =0x00000B82
	ldrb r0, [r4, r0]
	cmp r0, #0
	bne _0221C7D2
	ldr r0, _0221C7F8 ; =0x00000853
	bl PlaySE
_0221C7D2:
	ldr r0, _0221C7EC ; =0x00000B82
	ldrb r1, [r4, r0]
	cmp r1, #5
	bne _0221C7E2
	mov r1, #0
	strb r1, [r4, r0]
	mov r0, #1
	pop {r3, r4, r5, pc}
_0221C7E2:
	add r1, r1, #1
	strb r1, [r4, r0]
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0221C7EC: .word 0x00000B82
_0221C7F0: .word ov05_0221EA6C
_0221C7F4: .word ov05_0221EA6D
_0221C7F8: .word 0x00000853
	thumb_func_end ov05_0221C6C8
