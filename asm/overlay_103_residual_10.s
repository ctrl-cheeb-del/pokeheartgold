	.include "asm/macros.inc"
	.include "overlay_103.inc"
	.include "global.inc"

	.text
	.public _021EEB34
	.public ov103_021EC9B4
	.public ov103_021EC9E8
	.public ov103_021ECC1C
	.public ov103_021ECD68
	.public ov103_021ECF68
	.public ov103_021ED00C
	.public ov103_021ED0C0
	.public ov103_021ED144
	.public ov103_021ED4D4
	.public ov103_021ED5B4
	.public ov103_021ED7E4
	.public ov103_021ED9AC
	.public ov103_021EDA98
	.public ov103_021EDD54
	.public ov103_021EDD98
	.public ov103_021EDE7C
	.public ov103_021EDEA8
	.public ov103_021EDF88
	.public ov103_021EE078
	.public ov103_021EE160
	.public ov103_021EE210
	.public ov103_021EE2E0
	.public ov103_021EE468
	.public ov103_021EE550
	.public ov103_021EE644
	.public ov103_021EE7DC
	.public ov103_021EE8A8
	.public ov103_021EE930
	.public ov103_021EE9C8
	.public ov103_021EEB40
	.public ov103_021EEB50
	.public ov103_021EEB6C
	.public ov103_021EEB88
	.public ov103_021EEBA4
	.public ov103_021EEBC0
	.public ov103_021EEBDC
	.public ov103_021EEBF8
	.public ov103_021EEC14
	.public ov103_021EEC30
	.public ov103_021EEC58
	.public ov103_021EEC68
	.public ov103_021EEC78
	.public ov103_021EECA8
	.public ov103_021EED0C
	.public ov103_021EED20
	.public ov103_021EED38
	.public ov103_021EED58
	.public ov103_021EEEC4
	.public ov103_021EEFB4
	.public ov103_021EEFBC
	.public ov103_021EEFC8
	.public ov103_021EEFD8
	.public ov103_021EF008
	.public ov103_021EC940
	.public ov103_021EC988
	.public ov103_021EC9A4
	.public ov103_021EC9D8
	.public ov103_021ECBBC
	.public ov103_021ECD18
	.public ov103_021ECE0C
	.public ov103_021ECE18
	.public ov103_021ECE54
	.public ov103_021ECE80
	.public ov103_021ECE94
	.public ov103_021ECEA4
	.public ov103_021ECEEC
	.public ov103_021ECF48
	.public ov103_021ECFFC
	.public ov103_021ED0A0
	.public ov103_021ED124
	.public ov103_021ED23C
	.public ov103_021ED2B8
	.public ov103_021ED2D4
	.public ov103_021ED314
	.public ov103_021ED3E8
	.public ov103_021ED460
	.public ov103_021ED47C
	.public ov103_021ED53C
	.public ov103_021ED550
	.public ov103_021ED568
	.public ov103_021ED5A8
	.public ov103_021ED750
	.public ov103_021ED760
	.public ov103_021ED7A4
	.public ov103_021ED7D8
	.public ov103_021ED8D0
	.public ov103_021ED8F8
	.public ov103_021ED930
	.public ov103_021ED93C
	.public ov103_021ED954
	.public ov103_021ED960
	.public ov103_021ED97C
	.public ov103_021ED99C
	.public ov103_021ED9D8
	.public ov103_021EDA14
	.public ov103_021EDA40
	.public ov103_021EDA70
	.public ov103_021EDA84
	.public ov103_021EDB18
	.public ov103_021EDB60
	.public ov103_021EDBB0
	.public ov103_021EDBC8
	.public ov103_021EDC00
	.public ov103_021EDC58
	.public ov103_021EDC68
	.public ov103_021EDCC8
	.public ov103_021EDCE0
	.public ov103_021EDD14
	.public ov103_021EDD48
	.public ov103_021EDDE4
	.public ov103_021EDE5C
	.public ov103_021EDF50
	.public ov103_021EDF68
	.public ov103_021EE028
	.public ov103_021EE048
	.public ov103_021EE094
	.public ov103_021EE0AC
	.public ov103_021EE0CC
	.public ov103_021EE0F8
	.public ov103_021EE110
	.public ov103_021EE13C
	.public ov103_021EE150
	.public ov103_021EE374
	.public ov103_021EE390
	.public ov103_021EE3C0
	.public ov103_021EE3E4
	.public ov103_021EE430
	.public ov103_021EE60C
	.public ov103_021EE628
	.public ov103_021EE784
	.public ov103_021EE824
	.public ov103_021EE860
	.public ov103_021EE888
	.public ov103_021EEA24
	.public ov103_021EEA48
	.public ov103_021EEAA0
	.public ov103_021EEAB0
	.public ov103_021EEAB4
	.public ov103_021EEAB8
	.public ov103_021EEAC0
	.public ov103_021EEAC8
	.public ov103_021EEB04

	thumb_func_start ov103_021ED5B4
ov103_021ED5B4: ; 0x021ED5B4
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bl ov103_021EEA24
	cmp r0, #0
	beq _021ED5C6
	cmp r0, #1
	beq _021ED5E6
	b _021ED60C
_021ED5C6:
	ldrh r0, [r4, #0x1c]
	cmp r0, #0
	beq _021ED5E2
	sub r0, r0, #1
	strh r0, [r4, #0x1c]
	ldr r0, _021ED740 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	mov r1, #0
	mov r2, #0xb
	bl ov103_021EDB18
	pop {r3, r4, r5, pc}
_021ED5E2:
	mov r0, #9
	pop {r3, r4, r5, pc}
_021ED5E6:
	ldr r1, [r4, #0xc]
	ldr r0, _021ED744 ; =0x000002E2
	ldrh r2, [r4, #0x1c]
	ldrh r0, [r1, r0]
	cmp r2, r0
	beq _021ED608
	add r0, r2, #1
	strh r0, [r4, #0x1c]
	ldr r0, _021ED740 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	mov r1, #1
	mov r2, #0xb
	bl ov103_021EDB18
	pop {r3, r4, r5, pc}
_021ED608:
	mov r0, #9
	pop {r3, r4, r5, pc}
_021ED60C:
	mov r0, #0x9e
	ldr r1, [r4, #0xc]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	bl GridInputHandler_HandleInput_NoHold
	mov r1, #2
	add r5, r0, #0
	mvn r1, r1
	cmp r5, r1
	bhi _021ED654
	blo _021ED626
	b _021ED734
_021ED626:
	cmp r5, #0xa
	bhi _021ED64C
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021ED636: ; jump table
	.short _021ED666 - _021ED636 - 2 ; case 0
	.short _021ED666 - _021ED636 - 2 ; case 1
	.short _021ED666 - _021ED636 - 2 ; case 2
	.short _021ED666 - _021ED636 - 2 ; case 3
	.short _021ED666 - _021ED636 - 2 ; case 4
	.short _021ED666 - _021ED636 - 2 ; case 5
	.short _021ED666 - _021ED636 - 2 ; case 6
	.short _021ED666 - _021ED636 - 2 ; case 7
	.short _021ED666 - _021ED636 - 2 ; case 8
	.short _021ED666 - _021ED636 - 2 ; case 9
	.short _021ED6A0 - _021ED636 - 2 ; case 10
_021ED64C:
	mov r0, #3
	mvn r0, r0
	cmp r5, r0
	b _021ED73A
_021ED654:
	add r0, r1, #1
	cmp r5, r0
	bhi _021ED65E
	beq _021ED6A0
	b _021ED73A
_021ED65E:
	add r0, r1, #2
	cmp r5, r0
	beq _021ED6B2
	b _021ED73A
_021ED666:
	ldrh r1, [r4, #0x1c]
	ldr r0, [r4, #0xc]
	add r3, r0, r5
	add r2, r1, #0
	mov r0, #0xa
	mul r2, r0
	mov r1, #0xb3
	add r2, r3, r2
	lsl r1, r1, #2
	ldrb r2, [r2, r1]
	cmp r2, #0xff
	beq _021ED73A
	strb r5, [r4, #0x1e]
	ldr r2, [r4, #0xc]
	add r3, r2, r5
	ldrh r2, [r4, #0x1c]
	mul r0, r2
	add r0, r3, r0
	ldrb r0, [r0, r1]
	strb r0, [r4, #0x1f]
	ldr r0, _021ED748 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xc
	bl ov103_021EDA98
	pop {r3, r4, r5, pc}
_021ED6A0:
	ldr r0, _021ED748 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	mov r1, #3
	mov r2, #0xa
	bl ov103_021EDB18
	pop {r3, r4, r5, pc}
_021ED6B2:
	mov r0, #0x9e
	ldr r1, [r4, #0xc]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	bl GridInputHandler_GetNextInput
	ldr r1, _021ED74C ; =gSystem
	mov r2, #0x10
	ldr r1, [r1, #0x4c]
	tst r2, r1
	beq _021ED6FE
	cmp r0, #1
	beq _021ED6DC
	cmp r0, #3
	beq _021ED6DC
	cmp r0, #5
	beq _021ED6DC
	cmp r0, #7
	beq _021ED6DC
	cmp r0, #9
	bne _021ED6FE
_021ED6DC:
	ldr r3, [r4, #0xc]
	ldr r2, _021ED744 ; =0x000002E2
	ldrh r5, [r4, #0x1c]
	ldrh r2, [r3, r2]
	cmp r5, r2
	beq _021ED6FE
	add r0, r5, #1
	strh r0, [r4, #0x1c]
	ldr r0, _021ED740 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	mov r1, #1
	mov r2, #0xb
	bl ov103_021EDB18
	pop {r3, r4, r5, pc}
_021ED6FE:
	mov r2, #0x20
	tst r1, r2
	beq _021ED73A
	cmp r0, #0
	beq _021ED718
	cmp r0, #2
	beq _021ED718
	cmp r0, #4
	beq _021ED718
	cmp r0, #6
	beq _021ED718
	cmp r0, #8
	bne _021ED73A
_021ED718:
	ldrh r0, [r4, #0x1c]
	cmp r0, #0
	beq _021ED73A
	sub r0, r0, #1
	strh r0, [r4, #0x1c]
	ldr r0, _021ED740 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	mov r1, #0
	mov r2, #0xb
	bl ov103_021EDB18
	pop {r3, r4, r5, pc}
_021ED734:
	ldr r0, _021ED740 ; =0x000005DC
	bl PlaySE
_021ED73A:
	mov r0, #9
	pop {r3, r4, r5, pc}
	nop
_021ED740: .word 0x000005DC
_021ED744: .word 0x000002E2
_021ED748: .word 0x000005DD
_021ED74C: .word gSystem
	thumb_func_end ov103_021ED5B4
