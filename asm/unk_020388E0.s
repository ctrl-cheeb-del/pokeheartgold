	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020388E0
sub_020388E0: ; 0x020388E0
	push {r3, lr}
	ldr r0, _02038914 ; =_021D4150
	mov r1, #0xd
	ldr r0, [r0]
	add r0, #0x4e
	strb r1, [r0]
	bl sub_0203769C
	cmp r0, #0
	add r0, sp, #0
	bne _02038906
	mov r1, #0
	strb r1, [r0, #1]
	add r1, sp, #0
	mov r0, #0xa
	add r1, #1
	bl sub_020376E0
	pop {r3, pc}
_02038906:
	mov r1, #0
	strb r1, [r0]
	mov r0, #0xa
	add r1, sp, #0
	bl sub_020376E0
	pop {r3, pc}
	.balign 4, 0
_02038914: .word _021D4150
	thumb_func_end sub_020388E0
