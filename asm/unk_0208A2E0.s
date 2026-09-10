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
	thumb_func_start sub_0208A2E0
sub_0208A2E0: ; 0x0208A2E0
	push {r3, lr}
	mov r2, #0x8b
	lsl r2, r2, #2
	ldr r2, [r0, r2]
	ldrb r2, [r2, #0x11]
	cmp r2, #0
	beq _0208A2F8
	cmp r2, #1
	beq _0208A2FE
	cmp r2, #2
	beq _0208A304
	b _0208A30A
_0208A2F8:
	bl sub_0208A3F4
	pop {r3, pc}
_0208A2FE:
	bl sub_0208A45C
	pop {r3, pc}
_0208A304:
	bl sub_0208A4B8
	pop {r3, pc}
_0208A30A:
	mov r0, #0
	mvn r0, r0
	pop {r3, pc}
	thumb_func_end sub_0208A2E0
	thumb_func_start sub_0208A310
sub_0208A310: ; 0x0208A310
	push {r4, r5, r6, lr}
	add r4, r0, #0
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r2, [r4, r0]
	add r5, r1, #0
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	beq _0208A32C
	cmp r0, #1
	beq _0208A35C
	cmp r0, #2
	beq _0208A396
	b _0208A3C6
_0208A32C:
	bl sub_02070D90
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r6, r5, #0
	ldr r4, [r1]
	mul r6, r0
	add r0, r4, r6
	mov r1, #5
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _0208A3C6
	add r0, r4, r6
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _0208A3C6
	mov r0, #1
	pop {r4, r5, r6, pc}
_0208A35C:
	ldrb r0, [r2, #0x13]
	cmp r5, r0
	bge _0208A3C6
	ldr r0, [r2]
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r5, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _0208A3C6
	add r0, r5, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _0208A392
	add r0, r4, #0
	bl sub_0208A3CC
	cmp r0, #1
	bne _0208A3C6
	mov r0, #1
	pop {r4, r5, r6, pc}
_0208A392:
	mov r0, #1
	pop {r4, r5, r6, pc}
_0208A396:
	bl sub_02070D94
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r6, r5, #0
	ldr r4, [r1]
	mul r6, r0
	add r0, r4, r6
	mov r1, #5
	mov r2, #0
	bl GetBoxMonData
	cmp r0, #0
	beq _0208A3C6
	add r0, r4, r6
	mov r1, #0x4c
	mov r2, #0
	bl GetBoxMonData
	cmp r0, #0
	beq _0208A3C6
	mov r0, #1
	pop {r4, r5, r6, pc}
_0208A3C6:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_0208A310
