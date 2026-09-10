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

	thumb_func_start ov05_0221C80C
ov05_0221C80C: ; 0x0221C80C
	push {r4, r5, r6, lr}
	add r4, r0, #0
	ldr r0, _0221C894 ; =0x00000B82
	ldrb r0, [r4, r0]
	cmp r0, #0
	bne _0221C850
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	lsl r0, r0, #0x1a
	add r3, r0, #0
	ldr r2, [r0]
	ldr r1, _0221C898 ; =0xFFFF1FFF
	add r3, #0x48
	and r2, r1
	lsr r1, r0, #0xd
	orr r1, r2
	str r1, [r0]
	ldrh r5, [r3]
	mov r2, #0x3f
	mov r1, #0x1f
	bic r5, r2
	orr r5, r1
	mov r1, #0x20
	orr r1, r5
	strh r1, [r3]
	add r0, #0x4a
	ldrh r3, [r0]
	mov r1, #0x1d
	bic r3, r2
	orr r1, r3
	strh r1, [r0]
_0221C850:
	ldr r3, _0221C894 ; =0x00000B82
	ldrb r1, [r4, r3]
	cmp r1, #0x10
	bne _0221C870
	mov r0, #0
	mov r1, #0x20
	strb r0, [r4, r3]
	sub r0, r3, #1
	strb r1, [r4, r0]
	lsl r2, r1, #0x15
	ldr r1, [r2]
	ldr r0, _0221C898 ; =0xFFFF1FFF
	and r0, r1
	str r0, [r2]
	mov r0, #1
	pop {r4, r5, r6, pc}
_0221C870:
	mov r2, #0x47
	sub r2, r2, r1
	add r1, #0x48
	lsl r1, r1, #0x18
	mov r6, #0xff
	ldr r0, _0221C89C ; =0x04000040
	lsl r5, r2, #8
	lsl r2, r6, #8
	and r2, r5
	lsr r1, r1, #0x18
	strh r6, [r0]
	orr r1, r2
	strh r1, [r0, #4]
	ldrb r0, [r4, r3]
	add r0, r0, #1
	strb r0, [r4, r3]
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0221C894: .word 0x00000B82
_0221C898: .word 0xFFFF1FFF
_0221C89C: .word 0x04000040
	thumb_func_end ov05_0221C80C
