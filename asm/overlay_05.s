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

	thumb_func_start ov05_0221BA00
ov05_0221BA00: ; 0x0221BA00
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _0221BA5C ; =ov05_0221BA70
	ldr r1, _0221BA60 ; =0x00000BD4
	ldr r3, [r5, #0x24]
	mov r2, #0x64
	bl CreateSysTaskAndEnvironment
	bl SysTask_GetData
	ldr r2, _0221BA60 ; =0x00000BD4
	mov r1, #0
	add r4, r0, #0
	bl memset
	ldr r0, _0221BA64 ; =0x00000B7F
	str r5, [r4]
	mov r1, #0
	strb r1, [r4, r0]
	bl sub_020304B4
	ldr r1, _0221BA68 ; =0x00000BC8
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	cmp r0, #1
	bne _0221BA58
	ldr r0, [r4]
	ldr r1, [r0]
	cmp r1, #0
	beq _0221BA58
	mov r0, #7
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	cmp r0, #0
	beq _0221BA58
	bl Save_Bag_Get
	ldr r1, _0221BA6C ; =0x000001D1
	ldr r3, [r5, #0x24]
	mov r2, #1
	bl Bag_HasItem
	ldr r1, _0221BA68 ; =0x00000BC8
	str r0, [r4, r1]
_0221BA58:
	pop {r3, r4, r5, pc}
	nop
_0221BA5C: .word ov05_0221BA70
_0221BA60: .word 0x00000BD4
_0221BA64: .word 0x00000B7F
_0221BA68: .word 0x00000BC8
_0221BA6C: .word 0x000001D1
	thumb_func_end ov05_0221BA00


	thumb_func_start ov05_0221BA70
ov05_0221BA70: ; 0x0221BA70
	push {r4, r5, r6, lr}
	ldr r2, _0221BAF8 ; =0x00000B7F
	add r5, r1, #0
	ldrb r2, [r5, r2]
	cmp r2, #0
	beq _0221BA86
	cmp r2, #1
	beq _0221BA92
	cmp r2, #2
	beq _0221BAC4
	b _0221BACC
_0221BA86:
	add r0, r5, #0
	bl ov05_0221BD28
	ldr r1, _0221BAF8 ; =0x00000B7F
	strb r0, [r5, r1]
	b _0221BACC
_0221BA92:
	mov r4, #0x2e
	lsl r4, r4, #6
	add r6, r4, #0
_0221BA98:
	ldrb r1, [r5, r6]
	ldr r2, [r5, #4]
	add r0, r5, #0
	lsl r1, r1, #2
	ldr r1, [r2, r1]
	blx r1
	cmp r0, #0
	beq _0221BAAE
	ldrb r1, [r5, r4]
	add r1, r1, #1
	strb r1, [r5, r4]
_0221BAAE:
	cmp r0, #2
	beq _0221BA98
	ldr r0, [r5]
	add r0, #0x28
	ldrb r0, [r0]
	cmp r0, #2
	bne _0221BACC
	add r0, r5, #0
	bl ov05_0221BB30
	b _0221BACC
_0221BAC4:
	bl ov05_0221CC74
	cmp r0, #1
	beq _0221BAF6
_0221BACC:
	mov r0, #0x2e
	lsl r0, r0, #6
	ldrb r0, [r5, r0]
	cmp r0, #0
	beq _0221BAE6
	add r0, r5, #0
	bl ov05_0221CE50
	mov r0, #0x65
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteSystem_DrawSprites
_0221BAE6:
	ldr r0, [r5]
	add r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _0221BAF6
	ldr r0, _0221BAFC ; =0x04000540
	mov r1, #1
	str r1, [r0]
_0221BAF6:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0221BAF8: .word 0x00000B7F
_0221BAFC: .word 0x04000540
	thumb_func_end ov05_0221BA70
