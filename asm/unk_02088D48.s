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
	thumb_func_start sub_02088D48
sub_02088D48: ; 0x02088D48
	push {r4, lr}
	ldr r1, _02088E58 ; =gSystem
	add r4, r0, #0
	ldr r2, [r1, #0x48]
	mov r1, #0x40
	add r3, r2, #0
	tst r3, r1
	beq _02088D72
	sub r1, #0x41
	bl sub_0208A71C
	cmp r0, #1
	bne _02088D6E
	ldr r0, _02088E5C ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	bl sub_0208A79C
_02088D6E:
	mov r0, #5
	pop {r4, pc}
_02088D72:
	mov r1, #0x80
	tst r1, r2
	beq _02088D92
	mov r1, #1
	bl sub_0208A71C
	cmp r0, #1
	bne _02088D8E
	ldr r0, _02088E5C ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	bl sub_0208A79C
_02088D8E:
	mov r0, #5
	pop {r4, pc}
_02088D92:
	mov r0, #1
	tst r0, r2
	beq _02088DB4
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #1
	beq _02088DB4
	ldr r0, _02088E60 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	mov r1, #7
	bl sub_0208B08C
	pop {r4, pc}
_02088DB4:
	mov r0, #2
	tst r0, r2
	beq _02088DD4
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	add r0, r4, #0
	mov r1, #0
	bl sub_0208AFA0
	add r0, r4, #0
	mov r1, #4
	bl sub_0208B044
	pop {r4, pc}
_02088DD4:
	add r0, r4, #0
	bl sub_0208AE08
	cmp r0, #4
	bne _02088DFA
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #1
	beq _02088E52
	ldr r0, _02088E60 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	mov r1, #7
	bl sub_0208B08C
	pop {r4, pc}
_02088DFA:
	cmp r0, #5
	bne _02088E18
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	add r0, r4, #0
	mov r1, #0
	bl sub_0208AFA0
	add r0, r4, #0
	mov r1, #4
	bl sub_0208B044
	pop {r4, pc}
_02088E18:
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _02088E52
	lsl r1, r0, #1
	add r2, r4, r1
	mov r1, #0x99
	lsl r1, r1, #2
	ldrh r1, [r2, r1]
	cmp r1, #0
	beq _02088E52
	ldr r3, _02088E64 ; =0x000007BD
	mov r2, #0xf
	ldrb r1, [r4, r3]
	lsl r0, r0, #0x18
	bic r1, r2
	lsr r2, r0, #0x18
	mov r0, #0xf
	and r0, r2
	orr r0, r1
	strb r0, [r4, r3]
	ldr r0, _02088E5C ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	bl sub_0208A79C
	mov r0, #5
	pop {r4, pc}
_02088E52:
	mov r0, #5
	pop {r4, pc}
	nop
_02088E58: .word gSystem
_02088E5C: .word 0x000005DC
_02088E60: .word 0x000005DD
_02088E64: .word 0x000007BD
	thumb_func_end sub_02088D48
	thumb_func_start sub_02088E68
sub_02088E68: ; 0x02088E68
	push {r4, lr}
	add r4, r0, #0
	mov r1, #0
	bl sub_0208AFA0
	add r0, r4, #0
	bl sub_0208BC78
	ldr r2, _02088E94 ; =0x000007BD
	mov r1, #0xf0
	ldrb r3, [r4, r2]
	add r0, r3, #0
	bic r0, r1
	lsl r1, r3, #0x1c
	lsr r1, r1, #0x1c
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x18
	orr r0, r1
	strb r0, [r4, r2]
	mov r0, #6
	pop {r4, pc}
	nop
_02088E94: .word 0x000007BD
	thumb_func_end sub_02088E68
	thumb_func_start sub_02088E98
sub_02088E98: ; 0x02088E98
	push {r3, r4, r5, lr}
	ldr r1, _02089014 ; =gSystem
	add r5, r0, #0
	ldr r2, [r1, #0x48]
	mov r1, #0x40
	add r3, r2, #0
	tst r3, r1
	beq _02088EC2
	sub r1, #0x41
	bl sub_0208A71C
	cmp r0, #1
	bne _02088EBE
	ldr r0, _02089018 ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	bl sub_0208A79C
_02088EBE:
	mov r0, #6
	pop {r3, r4, r5, pc}
_02088EC2:
	mov r1, #0x80
	tst r1, r2
	beq _02088EE2
	mov r1, #1
	bl sub_0208A71C
	cmp r0, #1
	bne _02088EDE
	ldr r0, _02089018 ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	bl sub_0208A79C
_02088EDE:
	mov r0, #6
	pop {r3, r4, r5, pc}
_02088EE2:
	mov r1, #1
	add r3, r2, #0
	tst r3, r1
	beq _02088F3E
	bl sub_0208AFA0
	ldr r0, _0208901C ; =0x0000042C
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _02089020 ; =0x000007BD
	ldrb r0, [r5, r0]
	lsl r1, r0, #0x1c
	lsl r0, r0, #0x18
	lsr r1, r1, #0x1c
	lsr r0, r0, #0x1c
	cmp r1, r0
	beq _02088F34
	ldr r0, _02089024 ; =0x000005DD
	bl PlaySE
	add r0, r5, #0
	bl sub_0208A834
	ldr r1, _02089020 ; =0x000007BD
	add r0, r5, #0
	ldrb r2, [r5, r1]
	lsl r1, r2, #0x1c
	lsl r2, r2, #0x18
	lsr r1, r1, #0x1c
	lsr r2, r2, #0x1c
	bl sub_0208BB24
	add r0, r5, #0
	bl sub_0208DB64
	add r0, r5, #0
	bl sub_0208A79C
	b _02088F3A
_02088F34:
	ldr r0, _02089018 ; =0x000005DC
	bl PlaySE
_02088F3A:
	mov r0, #5
	pop {r3, r4, r5, pc}
_02088F3E:
	mov r1, #2
	tst r1, r2
	beq _02088F68
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	add r0, r5, #0
	mov r1, #1
	bl sub_0208AFA0
	ldr r0, _0208901C ; =0x0000042C
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	add r0, r5, #0
	mov r1, #5
	bl sub_0208B044
	pop {r3, r4, r5, pc}
_02088F68:
	bl sub_0208ADDC
	add r4, r0, #0
	cmp r4, #4
	bne _02088F96
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	add r0, r5, #0
	mov r1, #1
	bl sub_0208AFA0
	ldr r0, _0208901C ; =0x0000042C
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	add r0, r5, #0
	mov r1, #5
	bl sub_0208B044
	pop {r3, r4, r5, pc}
_02088F96:
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _02089010
	lsl r0, r4, #1
	add r1, r5, r0
	mov r0, #0x99
	lsl r0, r0, #2
	ldrh r0, [r1, r0]
	cmp r0, #0
	beq _02089010
	add r0, r5, #0
	mov r1, #1
	bl sub_0208AFA0
	ldr r0, _0208901C ; =0x0000042C
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r2, _02089020 ; =0x000007BD
	ldrb r0, [r5, r2]
	lsl r1, r0, #0x18
	lsr r1, r1, #0x1c
	cmp r4, r1
	beq _02089006
	mov r1, #0xf
	bic r0, r1
	lsl r1, r4, #0x18
	lsr r3, r1, #0x18
	mov r1, #0xf
	and r1, r3
	orr r0, r1
	strb r0, [r5, r2]
	ldr r0, _02089024 ; =0x000005DD
	bl PlaySE
	add r0, r5, #0
	bl sub_0208A834
	ldr r1, _02089020 ; =0x000007BD
	add r0, r5, #0
	ldrb r2, [r5, r1]
	lsl r1, r2, #0x1c
	lsl r2, r2, #0x18
	lsr r1, r1, #0x1c
	lsr r2, r2, #0x1c
	bl sub_0208BB24
	add r0, r5, #0
	bl sub_0208DB64
	add r0, r5, #0
	bl sub_0208A79C
	b _0208900C
_02089006:
	ldr r0, _02089018 ; =0x000005DC
	bl PlaySE
_0208900C:
	mov r0, #5
	pop {r3, r4, r5, pc}
_02089010:
	mov r0, #6
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02089014: .word gSystem
_02089018: .word 0x000005DC
_0208901C: .word 0x0000042C
_02089020: .word 0x000007BD
_02089024: .word 0x000005DD
	thumb_func_end sub_02088E98
	thumb_func_start sub_02089028
sub_02089028: ; 0x02089028
	push {r3, r4, r5, r6, r7, lr}
	ldr r1, _020891F4 ; =gSystem
	add r5, r0, #0
	ldr r2, [r1, #0x48]
	mov r1, #0x40
	add r3, r2, #0
	tst r3, r1
	beq _02089052
	sub r1, #0x41
	bl sub_0208A71C
	cmp r0, #1
	bne _0208904E
	ldr r0, _020891F8 ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	bl sub_0208A79C
_0208904E:
	mov r0, #8
	pop {r3, r4, r5, r6, r7, pc}
_02089052:
	mov r1, #0x80
	tst r1, r2
	beq _02089072
	mov r1, #1
	bl sub_0208A71C
	cmp r0, #1
	bne _0208906E
	ldr r0, _020891F8 ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	bl sub_0208A79C
_0208906E:
	mov r0, #8
	pop {r3, r4, r5, r6, r7, pc}
_02089072:
	mov r1, #1
	tst r1, r2
	beq _020890D8
	ldr r0, _020891FC ; =0x000005DD
	bl PlaySE
	ldr r0, _02089200 ; =0x000007BD
	ldrb r0, [r5, r0]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	cmp r0, #4
	bne _0208909E
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	mov r2, #4
	strb r2, [r1, #0x16]
	ldr r0, [r5, r0]
	mov r1, #0
	strb r1, [r0, #0x17]
	mov r0, #0x15
	pop {r3, r4, r5, r6, r7, pc}
_0208909E:
	lsl r0, r0, #1
	add r1, r5, r0
	mov r0, #0x99
	lsl r0, r0, #2
	ldrh r0, [r1, r0]
	bl MoveIsHM
	cmp r0, #1
	bne _020890D0
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldrh r0, [r0, #0x18]
	cmp r0, #0
	beq _020890D0
	ldr r0, _02089204 ; =0x0000044C
	mov r1, #0
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetDrawFlag
	add r0, r5, #0
	bl sub_0208DBF0
	mov r0, #8
	pop {r3, r4, r5, r6, r7, pc}
_020890D0:
	add r0, r5, #0
	bl sub_0208AED4
	pop {r3, r4, r5, r6, r7, pc}
_020890D8:
	mov r1, #2
	tst r1, r2
	beq _02089100
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	mov r2, #4
	strb r2, [r1, #0x16]
	ldr r0, [r5, r0]
	mov r1, #1
	strb r1, [r0, #0x17]
	add r0, r5, #0
	mov r1, #0x15
	bl sub_0208B044
	pop {r3, r4, r5, r6, r7, pc}
_02089100:
	bl sub_0208AE48
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _020891F0
	cmp r4, #4
	beq _02089118
	cmp r4, #5
	beq _02089140
	b _02089170
_02089118:
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldrh r0, [r0, #0x18]
	cmp r0, #0
	beq _020891F0
	ldr r0, _020891FC ; =0x000005DD
	bl PlaySE
	ldr r1, _02089200 ; =0x000007BD
	mov r0, #0xf
	ldrb r2, [r5, r1]
	bic r2, r0
	mov r0, #4
	orr r0, r2
	strb r0, [r5, r1]
	add r0, r5, #0
	bl sub_0208A79C
	b _020891F0
_02089140:
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	ldr r1, _02089200 ; =0x000007BD
	mov r0, #0xf
	ldrb r2, [r5, r1]
	bic r2, r0
	mov r0, #5
	orr r0, r2
	strb r0, [r5, r1]
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	mov r2, #4
	strb r2, [r1, #0x16]
	ldr r0, [r5, r0]
	mov r1, #0
	strb r1, [r0, #0x17]
	add r0, r5, #0
	mov r1, #0x15
	bl sub_0208B044
	pop {r3, r4, r5, r6, r7, pc}
_02089170:
	mov r0, #0x99
	lsl r0, r0, #2
	add r6, r5, r0
	lsl r7, r4, #1
	ldrh r0, [r6, r7]
	bl MoveIsHM
	cmp r0, #1
	bne _020891C2
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldrh r0, [r0, #0x18]
	cmp r0, #0
	beq _020891C2
	ldr r0, _020891FC ; =0x000005DD
	bl PlaySE
	ldr r2, _02089200 ; =0x000007BD
	mov r1, #0xf
	ldrb r0, [r5, r2]
	bic r0, r1
	lsl r1, r4, #0x18
	lsr r3, r1, #0x18
	mov r1, #0xf
	and r1, r3
	orr r0, r1
	strb r0, [r5, r2]
	ldr r0, _02089204 ; =0x0000044C
	mov r1, #0
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetDrawFlag
	add r0, r5, #0
	bl sub_0208BBDC
	add r0, r5, #0
	bl sub_0208DBF0
	mov r0, #8
	pop {r3, r4, r5, r6, r7, pc}
_020891C2:
	ldrh r0, [r6, r7]
	cmp r0, #0
	beq _020891F0
	ldr r0, _020891FC ; =0x000005DD
	bl PlaySE
	ldr r2, _02089200 ; =0x000007BD
	mov r1, #0xf
	ldrb r0, [r5, r2]
	bic r0, r1
	lsl r1, r4, #0x18
	lsr r3, r1, #0x18
	mov r1, #0xf
	and r1, r3
	orr r0, r1
	strb r0, [r5, r2]
	add r0, r5, #0
	bl sub_0208A79C
	add r0, r5, #0
	bl sub_0208AED4
	pop {r3, r4, r5, r6, r7, pc}
_020891F0:
	mov r0, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_020891F4: .word gSystem
_020891F8: .word 0x000005DC
_020891FC: .word 0x000005DD
_02089200: .word 0x000007BD
_02089204: .word 0x0000044C
	thumb_func_end sub_02089028
	thumb_func_start sub_02089208
sub_02089208: ; 0x02089208
	push {r4, lr}
	ldr r1, _020892E0 ; =gSystem
	add r4, r0, #0
	ldr r2, [r1, #0x48]
	mov r1, #1
	tst r1, r2
	beq _0208923C
	ldr r0, _020892E4 ; =0x000005DD
	bl PlaySE
	ldr r0, _020892E8 ; =0x000007BD
	ldrb r0, [r4, r0]
	lsl r0, r0, #0x1c
	lsr r2, r0, #0x1c
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	strb r2, [r1, #0x16]
	ldr r0, [r4, r0]
	mov r1, #0
	strb r1, [r0, #0x17]
	add r0, r4, #0
	mov r1, #0x15
	bl sub_0208B068
	pop {r4, pc}
_0208923C:
	mov r1, #2
	tst r1, r2
	beq _02089270
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	ldr r0, _020892EC ; =0x00000428
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _020892F0 ; =0x0000042C
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	mov r1, #0
	bl sub_0208AF08
	add r0, r4, #0
	mov r1, #8
	bl sub_0208B044
	pop {r4, pc}
_02089270:
	bl sub_0208AE88
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _020892DA
	cmp r0, #0
	beq _02089286
	cmp r0, #1
	beq _020892AC
	b _020892DA
_02089286:
	ldr r0, _020892E4 ; =0x000005DD
	bl PlaySE
	ldr r0, _020892E8 ; =0x000007BD
	ldrb r0, [r4, r0]
	lsl r0, r0, #0x1c
	lsr r2, r0, #0x1c
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	strb r2, [r1, #0x16]
	ldr r0, [r4, r0]
	mov r1, #0
	strb r1, [r0, #0x17]
	add r0, r4, #0
	mov r1, #0x15
	bl sub_0208B068
	pop {r4, pc}
_020892AC:
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	ldr r0, _020892EC ; =0x00000428
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _020892F0 ; =0x0000042C
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	mov r1, #0
	bl sub_0208AF08
	add r0, r4, #0
	mov r1, #8
	bl sub_0208B044
	pop {r4, pc}
_020892DA:
	mov r0, #9
	pop {r4, pc}
	nop
_020892E0: .word gSystem
_020892E4: .word 0x000005DD
_020892E8: .word 0x000007BD
_020892EC: .word 0x00000428
_020892F0: .word 0x0000042C
	thumb_func_end sub_02089208
