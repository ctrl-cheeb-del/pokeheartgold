#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_02088288.inc"
	.include "global.inc"
	.text
	.public sub_0208AED4
	.public sub_0208AF08
	.public sub_0208AF70
	.public sub_0208AFA0
	thumb_func_start sub_0208AFE8
sub_0208AFE8: ; 0x0208AFE8
	push {r3, r4, r5, r6}
	ldr r5, _0208B040 ; =0x000007C8
	add r4, r0, #0
	strb r2, [r4, r5]
	add r0, r5, #1
	strb r3, [r4, r0]
	add r2, sp, #0
	ldrb r3, [r2, #0x10]
	add r0, r5, #2
	strb r3, [r4, r0]
	ldrb r3, [r2, #0x14]
	add r0, r5, #3
	strb r3, [r4, r0]
	add r0, r5, #4
	ldrb r3, [r4, r0]
	mov r0, #0xf
	ldrb r6, [r2, #0x18]
	bic r3, r0
	mov r0, #0xf
	and r6, r0
	orr r6, r3
	add r3, r5, #4
	strb r6, [r4, r3]
	ldrb r2, [r2, #0x1c]
	ldrb r3, [r4, r3]
	mov r6, #0xf0
	lsl r2, r2, #0x1c
	bic r3, r6
	lsr r2, r2, #0x18
	orr r3, r2
	add r2, r5, #4
	strb r3, [r4, r2]
	add r2, r5, #5
	strb r1, [r4, r2]
	mov r2, #0
	add r1, r5, #6
	strb r2, [r4, r1]
	add r1, sp, #0x20
	ldrb r2, [r1]
	add r1, r5, #7
	strb r2, [r4, r1]
	pop {r3, r4, r5, r6}
	bx lr
	nop
_0208B040: .word 0x000007C8
	thumb_func_end sub_0208AFE8
