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
	.public _021FAC54
	.public _021FAC70
	.public _021FAC88
	.public _021FAC8E
	.public _021FAC94
	.public _021FACB0
	.public _021FACBC
	.public _021FACD0
	.public ov01_021FAC44
	.public ov01_02209B70
	.include "overlay_01_021FAC44.inc"
	.include "global.inc"
	.public ov01_021FACB4
	.public ov01_021FACE4
	.public ov01_021FACEC
	.public ov01_021FACF8

	.text

	thumb_func_start ov01_021FAC44
ov01_021FAC44: ; 0x021FAC44
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	mov r0, #4
	mov r1, #0x20
	bl Heap_Alloc
	add r5, r0, #0
	mov r4, #0
_021FAC54:
	mov r1, #0xf
	lsl r1, r1, #0xc
	add r2, r4, #0
	mul r2, r1
	ldr r1, _021FACB0 ; =ov01_02209B70
	lsl r0, r4, #2
	add r1, r1, r2
	add r6, r5, r0
	str r1, [r5, r0]
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _021FAC70
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021FAC70:
	cmp r7, #0
	beq _021FAC8E
	mov r1, #9
	mov r0, #4
	lsl r1, r1, #0xc
	bl Heap_Alloc
	str r0, [r6, #0x10]
	cmp r0, #0
	bne _021FAC88
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021FAC88:
	mov r2, #9
	lsl r2, r2, #0xc
	b _021FAC94
_021FAC8E:
	mov r0, #0
	str r0, [r6, #0x10]
	add r2, r0, #0
_021FAC94:
	mov r1, #0xf
	add r0, r4, #0
	lsl r1, r1, #0xc
	add r3, r5, #0
	bl ov01_021FACF8
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _021FAC54
	add r0, r5, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FACB0: .word ov01_02209B70
	thumb_func_end ov01_021FAC44
