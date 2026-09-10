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
	.public ov01_021FB788
	.include "overlay_01_021FB5D4.inc"
	.include "global.inc"

	.text
	.public FieldSystem_DoPoisonEffect
	.public ov01_021FB5D4
	.public ov01_021FB610
	.public ov01_021FB6C4
	.public ov01_021FB750
	.public ov01_021FB7CC
	.public ov01_021FB7DC
	.public ov01_021FB7E8
	.public ov01_021FB800
	.public ov01_021FB80C
	.public ov01_021FB82C

	thumb_func_start ov01_021FB788
ov01_021FB788: ; 0x021FB788
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	lsl r0, r1, #1
	add r0, r1, r0
	add r1, r2, #0
	mov r4, #1
	bl _s32_div_f
	neg r1, r0
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	lsl r0, r0, #0x10
	mov r6, #0
	str r1, [sp]
	lsr r7, r0, #0x10
_021FB7A6:
	add r0, r6, #0
	mov r1, #0xa
	bl _s32_div_f
	cmp r1, #0
	bne _021FB7B6
	mov r0, #1
	eor r4, r0
_021FB7B6:
	cmp r4, #0
	beq _021FB7BE
	strh r7, [r5]
	b _021FB7C2
_021FB7BE:
	ldr r0, [sp]
	strh r0, [r5]
_021FB7C2:
	add r6, r6, #1
	add r5, r5, #2
	cmp r6, #0xc0
	blt _021FB7A6
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov01_021FB788
