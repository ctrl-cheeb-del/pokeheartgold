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
	thumb_func_start sub_02088894
sub_02088894: ; 0x02088894
	push {r4, lr}
	ldr r2, _02088940 ; =0x0000012E
	add r4, r0, #0
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x13
	bl NewMsgDataFromNarc
	mov r1, #0x7a
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r2, #0x6a
	mov r0, #1
	mov r1, #0x1b
	lsl r2, r2, #2
	mov r3, #0x13
	bl NewMsgDataFromNarc
	ldr r1, _02088944 ; =0x000007A4
	mov r2, #0
	str r0, [r4, r1]
	mov r0, #1
	mov r1, #2
	mov r3, #0x13
	bl MessagePrinter_New
	ldr r1, _02088948 ; =0x0000079C
	str r0, [r4, r1]
	mov r0, #0x13
	bl MessageFormat_New
	ldr r1, _0208894C ; =0x000007A8
	str r0, [r4, r1]
	mov r0, #0xc
	mov r1, #0x13
	bl String_New
	mov r1, #0x23
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r0, #0xc
	mov r1, #0x13
	bl String_New
	mov r1, #0x8d
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #8
	mov r1, #0x13
	bl String_New
	mov r1, #0x8e
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0x80
	mov r1, #0x13
	bl String_New
	ldr r1, _02088950 ; =0x000007AC
	ldr r2, _02088954 ; =0x000002EE
	str r0, [r4, r1]
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x13
	bl NewMsgDataFromNarc
	ldr r1, _02088958 ; =0x000007B4
	str r0, [r4, r1]
	mov r0, #8
	mov r1, #0x13
	bl String_New
	mov r2, #0x7b
	lsl r2, r2, #4
	str r0, [r4, r2]
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0208893C
	ldr r0, [r4, r2]
	bl CopyU16ArrayToString
_0208893C:
	pop {r4, pc}
	nop
_02088940: .word 0x0000012E
_02088944: .word 0x000007A4
_02088948: .word 0x0000079C
_0208894C: .word 0x000007A8
_02088950: .word 0x000007AC
_02088954: .word 0x000002EE
_02088958: .word 0x000007B4
	thumb_func_end sub_02088894
	thumb_func_start sub_0208895C
sub_0208895C: ; 0x0208895C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _020889BC ; =0x000007B4
	ldr r0, [r4, r0]
	bl DestroyMsgData
	ldr r0, _020889C0 ; =0x000007A4
	ldr r0, [r4, r0]
	bl DestroyMsgData
	mov r0, #0x7a
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl DestroyMsgData
	ldr r0, _020889C4 ; =0x0000079C
	ldr r0, [r4, r0]
	bl MessagePrinter_Delete
	ldr r0, _020889C8 ; =0x000007A8
	ldr r0, [r4, r0]
	bl MessageFormat_Delete
	mov r0, #0x23
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl String_Delete
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl String_Delete
	mov r0, #0x8e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl String_Delete
	ldr r0, _020889CC ; =0x000007AC
	ldr r0, [r4, r0]
	bl String_Delete
	mov r0, #0x7b
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl String_Delete
	pop {r4, pc}
	.balign 4, 0
_020889BC: .word 0x000007B4
_020889C0: .word 0x000007A4
_020889C4: .word 0x0000079C
_020889C8: .word 0x000007A8
_020889CC: .word 0x000007AC
	thumb_func_end sub_0208895C
	thumb_func_start sub_020889D0
sub_020889D0: ; 0x020889D0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	mov r1, #2
	mov r2, #7
	mov r3, #0x13
	bl sub_0201956C
	mov r1, #0x7d
	lsl r1, r1, #4
	str r0, [r5, r1]
	mov r2, #6
	str r2, [sp]
	ldr r0, [r5, r1]
	mov r1, #0
	mov r3, #0x11
	bl sub_020195F4
	mov r1, #0
	mov r0, #0x7d
	str r1, [sp]
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r2, r4, #0
	mov r3, #0x45
	bl sub_020196B8
	mov r2, #6
	mov r0, #0x7d
	str r2, [sp]
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #1
	mov r3, #0x11
	bl sub_020195F4
	mov r0, #0
	str r0, [sp]
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #1
	add r2, r4, #0
	mov r3, #0x46
	bl sub_020196B8
	mov r0, #4
	str r0, [sp]
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #2
	mov r2, #6
	mov r3, #0xa
	bl sub_020195F4
	mov r0, #0
	str r0, [sp]
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #2
	add r2, r4, #0
	mov r3, #0x47
	bl sub_020196B8
	mov r0, #4
	str r0, [sp]
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #3
	mov r2, #6
	mov r3, #0xa
	bl sub_020195F4
	mov r0, #0
	str r0, [sp]
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #3
	add r2, r4, #0
	mov r3, #0x48
	bl sub_020196B8
	mov r0, #0xe
	str r0, [sp]
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #4
	mov r2, #6
	mov r3, #0xb
	bl sub_020195F4
	mov r0, #0
	str r0, [sp]
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #4
	add r2, r4, #0
	mov r3, #0x49
	bl sub_020196B8
	mov r0, #3
	str r0, [sp]
	mov r0, #0x7d
	lsl r0, r0, #4
	mov r2, #6
	ldr r0, [r5, r0]
	mov r1, #5
	add r3, r2, #0
	bl sub_020195F4
	mov r0, #0
	str r0, [sp]
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #5
	add r2, r4, #0
	mov r3, #0x4a
	bl sub_020196B8
	mov r1, #6
	mov r0, #3
	str r0, [sp]
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r2, r1, #0
	add r3, r1, #0
	bl sub_020195F4
	mov r0, #0
	str r0, [sp]
	mov r0, #0x7d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #6
	add r2, r4, #0
	mov r3, #0x4b
	bl sub_020196B8
	pop {r3, r4, r5, pc}
	thumb_func_end sub_020889D0
