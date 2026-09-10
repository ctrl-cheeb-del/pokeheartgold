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
	thumb_func_start sub_0208B118
sub_0208B118: ; 0x0208B118
	push {r4, lr}
	sub sp, #0x10
	mov r1, #0
	mvn r1, r1
	add r4, r0, #0
	bl sub_0208A2E0
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0208B140
	mov r0, #0x7d
	lsl r0, r0, #4
	mov r1, #5
	ldr r0, [r4, r0]
	mov r2, #0x18
	add r3, r1, #0
	bl sub_020196E8
	b _0208B162
_0208B140:
	mov r0, #5
	str r0, [sp]
	mov r1, #6
	str r1, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, [r4]
	mov r2, #1
	mov r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [r4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
_0208B162:
	add r0, r4, #0
	mov r1, #1
	bl sub_0208A2E0
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0208B186
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #6
	mov r2, #0x18
	mov r3, #0xd
	bl sub_020196E8
	add sp, #0x10
	pop {r4, pc}
_0208B186:
	mov r0, #0xd
	str r0, [sp]
	mov r1, #6
	str r1, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, [r4]
	mov r2, #1
	mov r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [r4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end sub_0208B118
