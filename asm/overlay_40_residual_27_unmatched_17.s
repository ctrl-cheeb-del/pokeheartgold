	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public ov40_02235940
	.text

	thumb_func_start ov40_02235940
ov40_02235940: ; 0x02235940
	push {r4, r5}
	mov r0, #1
	lsl r0, r0, #0x1a
	ldr r2, [r0]
	ldr r1, _02235988 ; =0xFFFF1FFF
	add r4, r0, #0
	and r2, r1
	lsr r1, r0, #0xd
	orr r1, r2
	str r1, [r0]
	add r4, #0x48
	ldrh r3, [r4]
	mov r2, #0x3f
	mov r1, #0x1f
	bic r3, r2
	orr r1, r3
	mov r3, #0x20
	orr r1, r3
	strh r1, [r4]
	add r4, r0, #0
	add r4, #0x4a
	ldrh r5, [r4]
	mov r1, #0x1e
	bic r5, r2
	orr r1, r5
	orr r1, r3
	strh r1, [r4]
	add r1, r0, #0
	ldr r2, _0223598C ; =0x000048B8
	add r1, #0x40
	strh r2, [r1]
	ldr r1, _02235990 ; =0x00001090
	add r0, #0x44
	strh r1, [r0]
	pop {r4, r5}
	bx lr
	.balign 4, 0
_02235988: .word 0xFFFF1FFF
_0223598C: .word 0x000048B8
_02235990: .word 0x00001090
	thumb_func_end ov40_02235940
