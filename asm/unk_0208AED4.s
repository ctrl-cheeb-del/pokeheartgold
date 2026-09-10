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
	thumb_func_start sub_0208AED4
sub_0208AED4: ; 0x0208AED4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0208AF00 ; =0x00000428
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _0208AF04 ; =0x0000042C
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	bl sub_0208BCB4
	add r0, r4, #0
	mov r1, #1
	bl sub_0208AF08
	mov r0, #9
	pop {r4, pc}
	nop
_0208AF00: .word 0x00000428
_0208AF04: .word 0x0000042C
	thumb_func_end sub_0208AED4
	thumb_func_start sub_0208AF08
sub_0208AF08: ; 0x0208AF08
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #1
	bne _0208AF34
	mov r0, #0x7d
	lsl r0, r0, #4
	mov r1, #0
	ldr r0, [r4, r0]
	add r2, r1, #0
	mov r3, #0x12
	bl sub_020196E8
	ldr r0, _0208AF6C ; =0x00000448
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	mov r1, #1
	bl sub_0208DC68
	pop {r4, pc}
_0208AF34:
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	ldrh r1, [r1, #0x18]
	cmp r1, #0
	beq _0208AF5C
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	mov r2, #0
	mov r3, #0x12
	bl sub_020196E8
	ldr r0, _0208AF6C ; =0x00000448
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	b _0208AF60
_0208AF5C:
	bl sub_0208AF70
_0208AF60:
	add r0, r4, #0
	mov r1, #0
	bl sub_0208DC68
	pop {r4, pc}
	nop
_0208AF6C: .word 0x00000448
	thumb_func_end sub_0208AF08
	thumb_func_start sub_0208AF70
sub_0208AF70: ; 0x0208AF70
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0x12
	str r0, [sp]
	mov r0, #0x11
	str r0, [sp, #4]
	mov r1, #6
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [r4]
	ldr r2, _0208AF9C ; =0x00003006
	mov r3, #0
	bl FillBgTilemapRect
	ldr r0, [r4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x10
	pop {r4, pc}
	nop
_0208AF9C: .word 0x00003006
	thumb_func_end sub_0208AF70
	thumb_func_start sub_0208AFA0
sub_0208AFA0: ; 0x0208AFA0
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #1
	beq _0208AFE6
	cmp r1, #1
	bne _0208AFCE
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #2
	mov r2, #1
	mov r3, #0x10
	bl sub_020196E8
	add r0, r4, #0
	mov r1, #1
	bl sub_0208DD20
	pop {r4, pc}
_0208AFCE:
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #3
	mov r2, #1
	mov r3, #0x10
	bl sub_020196E8
	add r0, r4, #0
	mov r1, #0
	bl sub_0208DD20
_0208AFE6:
	pop {r4, pc}
	thumb_func_end sub_0208AFA0
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
