	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02038B3C
sub_02038B3C: ; 0x02038B3C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r2, #0
	bl sub_0203769C
	cmp r0, #0
	bne _02038B8A
	ldr r6, _02038B8C ; =_0210F90C
	mov r3, #1
	mov r2, #0
_02038B50:
	ldrb r1, [r6]
	ldrb r0, [r4, r2]
	cmp r1, r0
	beq _02038B5C
	mov r3, #0
	b _02038B64
_02038B5C:
	add r2, r2, #1
	add r6, r6, #1
	cmp r2, #6
	blo _02038B50
_02038B64:
	cmp r3, #0
	beq _02038B80
	ldr r0, _02038B90 ; =_021D4150
	ldr r0, [r0]
	add r0, #0x57
	ldrb r0, [r0]
	cmp r0, #0
	bne _02038B80
	ldr r1, _02038B94 ; =_0210F904
	mov r0, #7
	strb r5, [r1]
	bl sub_02037184
	pop {r4, r5, r6, pc}
_02038B80:
	ldr r1, _02038B98 ; =_0210F914
	mov r0, #7
	strb r5, [r1]
	bl sub_02037184
_02038B8A:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02038B8C: .word _0210F90C
_02038B90: .word _021D4150
_02038B94: .word _0210F904
_02038B98: .word _0210F914
	thumb_func_end sub_02038B3C
