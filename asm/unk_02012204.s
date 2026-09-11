	.include "asm/macros.inc"
	.public _02012226
	.public _02012236
	.public _02012282
	.public _0201228E
	.public _0201229E
	.public _020122B4
	.public _02012310
	.public _0201232C
	.public _0201234C
	.public _02012350
	.public _02012354
	.public _02012448
	.public _0201244C
	.public _02012450
	.public _02012490
	.public _0201249E
	.public _020124A4
	.public _020124A8
	.public sub_02012204
	.public sub_02012238
	.public sub_02012290
	.public sub_020122B8
	.public sub_020122F8
	.public sub_02012358
	.public sub_02012454
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	.public sub_02012204
	.public sub_02012290
	.public sub_020122B8
	.public sub_020122F8
	.public sub_02012358
	.public sub_02012454
	thumb_func_start sub_02012238
sub_02012238: ; 0x02012238
	push {r4, r5, r6, lr}
	add r4, r1, #0
	mov r1, #0
	bl sub_02010EE0
	ldr r2, [r4]
	ldr r3, [r4, #8]
	asr r1, r2, #6
	lsr r1, r1, #0x19
	add r1, r2, r1
	asr r2, r1, #7
	asr r1, r3, #6
	ldr r5, [r4, #0xc]
	lsr r1, r1, #0x19
	add r1, r3, r1
	asr r3, r5, #6
	lsr r3, r3, #0x19
	add r3, r5, r3
	ldr r4, [r4, #4]
	asr r5, r3, #7
	asr r3, r4, #6
	lsr r3, r3, #0x19
	add r3, r4, r3
	asr r3, r3, #7
	asr r1, r1, #7
	cmp r3, r5
	bge _0201228E
	lsl r4, r3, #1
	lsl r1, r1, #0x10
	add r4, r0, r4
	lsl r0, r2, #0x10
	asr r6, r1, #0x10
	mov r1, #3
	mov r2, #0x12
	asr r0, r0, #0x10
	lsl r1, r1, #8
	lsl r2, r2, #6
_02012282:
	strh r0, [r4, r1]
	strh r6, [r4, r2]
	add r3, r3, #1
	add r4, r4, #2
	cmp r3, r5
	blt _02012282
_0201228E:
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02012238
