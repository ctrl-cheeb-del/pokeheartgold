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
	thumb_func_start sub_02089D68
sub_02089D68: ; 0x02089D68
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r1, #0
	ldr r1, _02089E10 ; =0x000007BC
	add r5, r0, #0
	ldrsb r1, [r5, r1]
	cmp r1, r4
	beq _02089E0C
	bl sub_0208C4E0
	ldr r0, _02089E10 ; =0x000007BC
	strb r4, [r5, r0]
	add r0, r5, #0
	bl sub_0208B448
	add r0, r5, #0
	bl sub_0208B5A8
	add r0, r5, #0
	bl sub_0208B89C
	add r0, r5, #0
	bl sub_0208B9C8
	add r0, r5, #0
	bl sub_0208C2A0
	add r0, r5, #0
	bl sub_0208BCD4
	add r0, r5, #0
	bl sub_0208C42C
	mov r0, #3
	str r0, [sp]
	mov r0, #0x12
	str r0, [sp, #4]
	mov r0, #0x14
	mov r2, #0
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [r5]
	mov r1, #1
	add r3, r2, #0
	bl FillBgTilemapRect
	ldr r0, [r5]
	mov r1, #1
	bl BgCommitTilemapBufferToVram
	mov r0, #3
	str r0, [sp]
	mov r0, #0x12
	str r0, [sp, #4]
	mov r0, #0x14
	mov r2, #0
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [r5]
	mov r1, #4
	add r3, r2, #0
	bl FillBgTilemapRect
	ldr r0, [r5]
	mov r1, #4
	bl BgCommitTilemapBufferToVram
	add r0, r5, #0
	bl sub_0208CBD4
	add r0, r5, #0
	bl sub_02089F98
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #2
	bne _02089E0C
	add r0, r5, #0
	bl sub_0208A950
_02089E0C:
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02089E10: .word 0x000007BC
	thumb_func_end sub_02089D68
	thumb_func_start sub_02089E14
sub_02089E14: ; 0x02089E14
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _02089E2C ; =0x000005E1
	add r4, r1, #0
	bl PlaySE
	lsl r1, r4, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl sub_02089D68
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02089E2C: .word 0x000005E1
	thumb_func_end sub_02089E14
	thumb_func_start sub_02089E30
sub_02089E30: ; 0x02089E30
	push {r3, r4, r5, r6, r7, lr}
	add r3, r0, #0
	ldr r0, _02089E7C ; =0x000007BC
	add r2, r1, #0
	ldrsb r1, [r3, r0]
	mov r0, #0xa
	lsl r0, r0, #6
	ldr r4, [r3, r0]
	mov ip, r1
	lsl r4, r4, #3
	lsr r4, r4, #0x1f
	bne _02089E7A
	sub r0, #0x54
	ldr r0, [r3, r0]
	mov r7, #0
	ldrb r0, [r0, #0x15]
	mov r6, #2
	mov r4, #1
_02089E54:
	add r1, r1, r2
	lsl r1, r1, #0x18
	asr r1, r1, #0x18
	bpl _02089E60
	add r1, r6, #0
	b _02089E66
_02089E60:
	cmp r1, #2
	ble _02089E66
	add r1, r7, #0
_02089E66:
	add r5, r4, #0
	lsl r5, r1
	tst r5, r0
	beq _02089E54
	mov r0, ip
	cmp r1, r0
	beq _02089E7A
	add r0, r3, #0
	bl sub_02089E14
_02089E7A:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02089E7C: .word 0x000007BC
	thumb_func_end sub_02089E30
