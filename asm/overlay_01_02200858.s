#include "constants/sndseq.h"
#include "constants/moves.h"
#include "constants/std_script.h"
#include "constants/species.h"
#include "constants/sprites.h"
#include "constants/maps.h"
#include "constants/mmodel.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0096_D31R0201.h"
#include "msgdata/msg/msg_0066_D23R0102.h"
	.include "asm/macros.inc"
	.public ov01_02200A08
	.include "overlay_01_02200858.inc"
	.include "global.inc"

	.text
	.public ov01_02209334
	.public ov01_02209340
	.public ov01_02209354
	.public ov01_02200858
	.public ov01_02200874
	.public ov01_02200884
	.public ov01_022008A8
	.public ov01_022008B4
	.public ov01_02200900
	.public ov01_02200938
	.public ov01_0220093C
	.public ov01_02200AB0

	thumb_func_start ov01_02200A08
ov01_02200A08: ; 0x02200A08
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	add r3, r1, #0
	add r6, r0, #0
	ldr r0, [r3]
	cmp r0, #1
	beq _02200AA4
	mov r0, #0
	ldr r1, [r3, #4]
	mvn r0, r0
	cmp r1, r0
	beq _02200AA4
	ldr r5, _02200AA8 ; =ov01_02209334
	add r4, sp, #0
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	mov r7, #0x18
	str r0, [r4]
	ldr r1, [r3, #4]
	ldr r4, _02200AAC ; =ov01_02209354
	add r0, r1, #0
	mul r0, r7
	add r0, r4, r0
	ldr r5, [r3, #0x28]
	ldr r4, [r3, #0x20]
	mov r3, #0xc
	mul r3, r4
	mov r2, #0
	add r5, #0x18
	add r4, r0, r3
	cmp r1, #3
	bhi _02200A6A
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02200A56: ; jump table
	.short _02200A5E - _02200A56 - 2 ; case 0
	.short _02200A6A - _02200A56 - 2 ; case 1
	.short _02200A62 - _02200A56 - 2 ; case 2
	.short _02200A68 - _02200A56 - 2 ; case 3
_02200A5E:
	mov r2, #0xb4
	b _02200A6A
_02200A62:
	add r2, r7, #0
	add r2, #0xf6
	b _02200A6A
_02200A68:
	mov r2, #0x5a
_02200A6A:
	mov r1, #0
	lsl r2, r2, #0x10
	add r0, sp, #0x18
	lsr r2, r2, #0x10
	add r3, r1, #0
	bl sub_02020DA4
	add r0, r6, #0
	add r1, sp, #0xc
	bl sub_02068DB8
	ldr r1, [sp, #0xc]
	ldr r0, [r4]
	add r2, sp, #0
	add r0, r1, r0
	str r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r0, [r4, #4]
	add r3, sp, #0x18
	add r0, r1, r0
	str r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r0, [r4, #8]
	add r0, r1, r0
	str r0, [sp, #0x14]
	add r0, r5, #0
	add r1, sp, #0xc
	bl sub_020699AC
_02200AA4:
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02200AA8: .word ov01_02209334
_02200AAC: .word ov01_02209354
	thumb_func_end ov01_02200A08
