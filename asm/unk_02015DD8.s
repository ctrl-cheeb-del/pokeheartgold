	.include "asm/macros.inc"
	.include "unk_02015DD8.inc"
	.include "global.inc"

	.text
	thumb_func_start sub_02016118
sub_02016118: ; 0x02016118
	push {r3, r4}
	ldr r4, [r0, #4]
	mov r1, #0
	cmp r4, #0
	ble _0201613E
	ldr r3, [r0, #8]
	add r2, r3, #0
_02016126:
	ldr r0, [r2]
	cmp r0, #0
	bne _02016136
	mov r0, #0x28
	mul r0, r1
	add r0, r3, r0
	pop {r3, r4}
	bx lr
_02016136:
	add r1, r1, #1
	add r2, #0x28
	cmp r1, r4
	blt _02016126
_0201613E:
	mov r0, #0
	pop {r3, r4}
	bx lr
	thumb_func_end sub_02016118
	thumb_func_start sub_02016144
sub_02016144: ; 0x02016144
	push {r3, r4}
	ldr r4, [r0, #4]
	mov r1, #0
	cmp r4, #0
	ble _0201616A
	ldr r3, [r0, #0x10]
	add r2, r3, #0
_02016152:
	ldr r0, [r2]
	cmp r0, #0
	bne _02016162
	mov r0, #0x18
	mul r0, r1
	add r0, r3, r0
	pop {r3, r4}
	bx lr
_02016162:
	add r1, r1, #1
	add r2, #0x18
	cmp r1, r4
	blt _02016152
_0201616A:
	mov r0, #0
	pop {r3, r4}
	bx lr
	thumb_func_end sub_02016144
