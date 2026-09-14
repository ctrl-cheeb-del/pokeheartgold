	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	thumb_func_start ov96_0220C9A0
ov96_0220C9A0: ; 0x0220C9A0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x74]
	mov r6, #0
	cmp r0, #0
	bls _0220C9CA
	add r4, r5, #0
	add r4, #8
_0220C9B0:
	add r0, r4, #0
	bl ov96_0220CA28
	add r1, r0, #0
	ldr r2, [r5, #4]
	add r0, r4, #0
	bl ov96_0220CF50
	ldr r0, [r5, #0x74]
	add r6, r6, #1
	add r4, #0x24
	cmp r6, r0
	blo _0220C9B0
_0220C9CA:
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_0220C9A0

	thumb_func_start ov96_0220C9CC
ov96_0220C9CC: ; 0x0220C9CC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x74]
	mov r6, #0
	cmp r0, #0
	bls _0220C9F2
	add r4, r5, #0
	add r4, #8
	add r7, r6, #0
_0220C9DE:
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r7, #0
	bl ov96_0220CF50
	ldr r0, [r5, #0x74]
	add r6, r6, #1
	add r4, #0x24
	cmp r6, r0
	blo _0220C9DE
_0220C9F2:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0220C9CC
