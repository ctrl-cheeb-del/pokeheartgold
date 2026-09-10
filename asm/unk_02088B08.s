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
	thumb_func_start sub_02088B08
sub_02088B08: ; 0x02088B08
	push {r4, lr}
	add r4, r0, #0
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _02088B3C
	add r0, r4, #0
	bl sub_0208E444
	add r0, r4, #0
	bl sub_02089C50
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #2
	bne _02088B30
	mov r0, #8
	pop {r4, pc}
_02088B30:
	cmp r0, #4
	bne _02088B38
	mov r0, #0x10
	pop {r4, pc}
_02088B38:
	mov r0, #2
	pop {r4, pc}
_02088B3C:
	mov r0, #1
	pop {r4, pc}
	thumb_func_end sub_02088B08
	thumb_func_start sub_02088B40
sub_02088B40: ; 0x02088B40
	push {r4, r5, r6, lr}
	ldr r2, _02088CF8 ; =0x000007BF
	add r5, r0, #0
	ldrb r1, [r5, r2]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	cmp r1, #1
	bne _02088B5E
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	strb r1, [r0, #0x17]
	mov r0, #0x15
	pop {r4, r5, r6, pc}
_02088B5E:
	ldr r3, _02088CFC ; =gSystem
	mov r1, #0x20
	ldr r4, [r3, #0x4c]
	add r6, r4, #0
	tst r6, r1
	beq _02088B74
	sub r1, #0x21
	bl sub_02089E30
	mov r0, #2
	pop {r4, r5, r6, pc}
_02088B74:
	mov r1, #0x10
	tst r1, r4
	beq _02088B84
	mov r1, #1
	bl sub_02089E30
	mov r0, #2
	pop {r4, r5, r6, pc}
_02088B84:
	mov r1, #0x40
	add r6, r4, #0
	tst r6, r1
	beq _02088B96
	sub r1, #0x41
	bl sub_0208A2C0
	mov r0, #0x13
	pop {r4, r5, r6, pc}
_02088B96:
	mov r1, #0x80
	tst r1, r4
	beq _02088BA6
	mov r1, #1
	bl sub_0208A2C0
	mov r0, #0x13
	pop {r4, r5, r6, pc}
_02088BA6:
	ldr r1, [r3, #0x48]
	mov r0, #2
	tst r0, r1
	beq _02088BD2
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	strb r1, [r0, #0x17]
	add r0, r5, #0
	mov r1, #0
	bl sub_0208ADB8
	add r0, r5, #0
	mov r1, #0x15
	bl sub_0208B044
	pop {r4, r5, r6, pc}
_02088BD2:
	mov r0, #1
	tst r0, r1
	beq _02088C12
	sub r0, r2, #3
	ldrsb r0, [r5, r0]
	cmp r0, #1
	beq _02088BE6
	cmp r0, #2
	beq _02088BFA
	b _02088C12
_02088BE6:
	ldr r0, _02088D00 ; =0x0000069B
	bl PlaySE
	ldr r1, _02088D04 ; =0x000007BD
	mov r0, #0xf
	ldrb r2, [r5, r1]
	bic r2, r0
	strb r2, [r5, r1]
	mov r0, #3
	pop {r4, r5, r6, pc}
_02088BFA:
	add r0, r2, #7
	ldrb r0, [r5, r0]
	cmp r0, #0
	beq _02088C12
	ldr r0, _02088D08 ; =0x000005DD
	bl PlaySE
	ldr r0, _02088D0C ; =0x000007C4
	mov r1, #0
	strb r1, [r5, r0]
	mov r0, #0xa
	pop {r4, r5, r6, pc}
_02088C12:
	ldr r0, _02088D10 ; =0x000007BC
	ldrsb r0, [r5, r0]
	cmp r0, #1
	bne _02088C56
	add r0, r5, #0
	bl sub_0208ADCC
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _02088C56
	lsl r0, r4, #1
	add r1, r5, r0
	mov r0, #0x99
	lsl r0, r0, #2
	ldrh r0, [r1, r0]
	cmp r0, #0
	beq _02088C56
	ldr r0, _02088D00 ; =0x0000069B
	bl PlaySE
	ldr r2, _02088D04 ; =0x000007BD
	mov r1, #0xf
	ldrb r0, [r5, r2]
	bic r0, r1
	lsl r1, r4, #0x18
	lsr r3, r1, #0x18
	mov r1, #0xf
	and r1, r3
	orr r0, r1
	strb r0, [r5, r2]
	mov r0, #3
	pop {r4, r5, r6, pc}
_02088C56:
	ldr r0, _02088D10 ; =0x000007BC
	ldrsb r0, [r5, r0]
	cmp r0, #2
	bne _02088C88
	add r0, r5, #0
	bl sub_0208AEC4
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _02088C88
	cmp r4, #9
	bge _02088C88
	ldr r0, _02088D14 ; =0x000007C6
	ldrb r0, [r5, r0]
	cmp r4, r0
	bge _02088C88
	ldr r0, _02088D08 ; =0x000005DD
	bl PlaySE
	ldr r0, _02088D0C ; =0x000007C4
	strb r4, [r5, r0]
	mov r0, #0xa
	pop {r4, r5, r6, pc}
_02088C88:
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldrb r0, [r0, #0x11]
	cmp r0, #2
	bne _02088CF0
	add r0, r5, #0
	bl sub_0208AEB4
	cmp r0, #0
	bne _02088CC6
	mov r1, #0
	add r0, r5, #0
	mvn r1, r1
	bl sub_0208A2E0
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _02088CC2
	ldr r0, _02088D08 ; =0x000005DD
	bl PlaySE
	add r0, r5, #0
	mov r1, #0
	mov r2, #0x14
	bl sub_0208B0B0
	pop {r4, r5, r6, pc}
_02088CC2:
	mov r0, #2
	pop {r4, r5, r6, pc}
_02088CC6:
	cmp r0, #1
	bne _02088CF0
	add r0, r5, #0
	mov r1, #1
	bl sub_0208A2E0
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _02088CEC
	ldr r0, _02088D08 ; =0x000005DD
	bl PlaySE
	add r0, r5, #0
	mov r1, #1
	mov r2, #0x14
	bl sub_0208B0B0
	pop {r4, r5, r6, pc}
_02088CEC:
	mov r0, #2
	pop {r4, r5, r6, pc}
_02088CF0:
	add r0, r5, #0
	bl sub_02089E98
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02088CF8: .word 0x000007BF
_02088CFC: .word gSystem
_02088D00: .word 0x0000069B
_02088D04: .word 0x000007BD
_02088D08: .word 0x000005DD
_02088D0C: .word 0x000007C4
_02088D10: .word 0x000007BC
_02088D14: .word 0x000007C6
	thumb_func_end sub_02088B40
