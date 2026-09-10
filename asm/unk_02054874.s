	.include "asm/macros.inc"
	.include "unk_02054648.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02054874
sub_02054874: ; 0x02054874
	push {r3, r4, lr}
	sub sp, #4
	ldr r4, [r0, #0x2c]
	add r3, sp, #0
	add r0, r4, #0
	bl ov01_021F654C
	cmp r0, #0
	bne _0205488C
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_0205488C:
	add r1, sp, #0
	ldrb r1, [r1]
	add r0, r4, #0
	bl ov01_021F6600
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end sub_02054874
