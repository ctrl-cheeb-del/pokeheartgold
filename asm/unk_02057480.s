	.include "asm/macros.inc"
	.include "unk_02056D7C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02057480
sub_02057480: ; 0x02057480
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _020574C0 ; =_021D41C4
	add r6, r1, #0
	ldr r0, [r0]
	ldr r0, [r0, #0x30]
	bl Field_GetNumObjectEvents
	add r4, r0, #0
	ldr r0, _020574C0 ; =_021D41C4
	ldr r0, [r0]
	ldr r0, [r0, #0x30]
	bl Field_GetObjectEvents
	mov r2, #0
	cmp r4, #0
	ble _020574BA
_020574A2:
	ldrh r1, [r0, #0x18]
	cmp r5, r1
	bne _020574B2
	ldrh r1, [r0, #0x1a]
	cmp r6, r1
	bne _020574B2
	mov r0, #1
	pop {r4, r5, r6, pc}
_020574B2:
	add r2, r2, #1
	add r0, #0x20
	cmp r2, r4
	blt _020574A2
_020574BA:
	mov r0, #0
	pop {r4, r5, r6, pc}
	nop
_020574C0: .word _021D41C4
	thumb_func_end sub_02057480
