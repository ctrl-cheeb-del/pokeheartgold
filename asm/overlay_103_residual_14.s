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

	thumb_func_start ov103_021EDD54
ov103_021EDD54: ; 0x021EDD54
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldrh r0, [r4, #0x22]
	bl ItemToMailId
	add r3, r0, #0
	mov r0, #0x9c
	add r2, r4, #0
	str r0, [sp]
	add r2, #0x21
	ldrb r2, [r2]
	ldr r0, [r4, #8]
	mov r1, #2
	lsl r2, r2, #0x19
	ldr r0, [r0]
	lsr r2, r2, #0x19
	bl sub_02090E68
	ldr r1, [r4, #8]
	mov r2, #0x9c
	ldr r1, [r1, #8]
	str r1, [r0, #0x1c]
	str r0, [r4, #0x14]
	ldr r0, _021EDD94 ; =ov103_021EEC58
	ldr r1, [r4, #0x14]
	bl OverlayManager_New
	str r0, [r4, #0x10]
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_021EDD94: .word ov103_021EEC58
	thumb_func_end ov103_021EDD54


	thumb_func_start ov103_021EDD98
ov103_021EDD98: ; 0x021EDD98
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x14]
	bl sub_02090F6C
	str r0, [r4, #0x24]
	cmp r0, #1
	bne _021EDDD8
	ldr r0, [r4, #8]
	ldr r0, [r0]
	bl SaveArray_Party_Get
	add r1, r4, #0
	add r1, #0x21
	ldrb r1, [r1]
	lsl r1, r1, #0x19
	lsr r1, r1, #0x19
	bl Party_GetMonByIndex
	add r1, r0, #0
	ldr r0, [r4, #0x14]
	bl sub_02090F70
	ldr r0, [r4, #8]
	ldr r0, [r0]
	bl Save_Bag_Get
	ldrh r1, [r4, #0x22]
	mov r2, #1
	mov r3, #0x9c
	bl Bag_TakeItem
_021EDDD8:
	ldr r0, [r4, #0x14]
	bl sub_02090F90
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov103_021EDD98
