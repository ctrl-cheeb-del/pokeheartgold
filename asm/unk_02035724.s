	.include "asm/macros.inc"
	.include "unk_02034B0C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02035724
sub_02035724: ; 0x02035724
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl WM_GetDispersionBeaconPeriod
	add r4, r0, #0
	cmp r5, #0x29
	blo _02035736
	bl GF_AssertFail
_02035736:
	cmp r5, #0xa
	bne _02035740
	lsl r0, r4, #0xe
	lsr r0, r0, #0x10
	pop {r3, r4, r5, pc}
_02035740:
	cmp r5, #9
	beq _02035748
	cmp r5, #0xd
	bne _0203574E
_02035748:
	lsl r0, r4, #0xe
	lsr r0, r0, #0x10
	pop {r3, r4, r5, pc}
_0203574E:
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_02035724
