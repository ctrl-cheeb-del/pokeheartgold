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
	thumb_func_start sub_02089478
sub_02089478: ; 0x02089478
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r1, _020895E8 ; =gSystem
	add r5, r0, #0
	ldr r2, [r1, #0x48]
	mov r1, #3
	tst r1, r2
	bne _0208948A
	b _020895E0
_0208948A:
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	ldrb r1, [r1, #0x11]
	cmp r1, #2
	bne _020894AE
	bl sub_0208A520
	add r6, r0, #0
	mov r0, #0x13
	bl AllocMonZeroed
	add r4, r0, #0
	add r0, r6, #0
	add r1, r4, #0
	bl CopyBoxPokemonToPokemon
	b _020894B4
_020894AE:
	bl sub_0208A520
	add r4, r0, #0
_020894B4:
	ldr r0, _020895EC ; =0x000007BE
	mov r2, #0
	strb r2, [r5, r0]
	ldr r0, _020895F0 ; =0x00000275
	mov r1, #0x13
	ldrb r6, [r5, r0]
	add r0, r4, #0
	bl GetMonData
	ldr r1, _020895F0 ; =0x00000275
	strb r0, [r5, r1]
	ldrb r0, [r5, r1]
	cmp r6, r0
	beq _020894DA
	ldr r1, _020895EC ; =0x000007BE
	mov r0, #1
	ldrb r2, [r5, r1]
	orr r0, r2
	strb r0, [r5, r1]
_020894DA:
	ldr r0, _020895F4 ; =0x00000276
	mov r1, #0x14
	ldrb r6, [r5, r0]
	add r0, r4, #0
	mov r2, #0
	bl GetMonData
	ldr r1, _020895F4 ; =0x00000276
	strb r0, [r5, r1]
	ldrb r0, [r5, r1]
	cmp r6, r0
	beq _020894FC
	ldr r1, _020895EC ; =0x000007BE
	mov r0, #2
	ldrb r2, [r5, r1]
	orr r0, r2
	strb r0, [r5, r1]
_020894FC:
	ldr r0, _020895F8 ; =0x00000277
	mov r1, #0x15
	ldrb r6, [r5, r0]
	add r0, r4, #0
	mov r2, #0
	bl GetMonData
	ldr r1, _020895F8 ; =0x00000277
	strb r0, [r5, r1]
	ldrb r0, [r5, r1]
	cmp r6, r0
	beq _0208951E
	ldr r1, _020895EC ; =0x000007BE
	mov r0, #4
	ldrb r2, [r5, r1]
	orr r0, r2
	strb r0, [r5, r1]
_0208951E:
	mov r0, #0x9e
	lsl r0, r0, #2
	ldrb r6, [r5, r0]
	add r0, r4, #0
	mov r1, #0x16
	mov r2, #0
	bl GetMonData
	mov r1, #0x9e
	lsl r1, r1, #2
	strb r0, [r5, r1]
	ldrb r0, [r5, r1]
	cmp r6, r0
	beq _02089544
	ldr r1, _020895EC ; =0x000007BE
	mov r0, #8
	ldrb r2, [r5, r1]
	orr r0, r2
	strb r0, [r5, r1]
_02089544:
	ldr r0, _020895FC ; =0x00000279
	mov r1, #0x17
	ldrb r6, [r5, r0]
	add r0, r4, #0
	mov r2, #0
	bl GetMonData
	ldr r1, _020895FC ; =0x00000279
	strb r0, [r5, r1]
	ldrb r0, [r5, r1]
	cmp r6, r0
	beq _02089566
	ldr r1, _020895EC ; =0x000007BE
	mov r0, #0x10
	ldrb r2, [r5, r1]
	orr r0, r2
	strb r0, [r5, r1]
_02089566:
	add r0, r4, #0
	mov r1, #0x18
	mov r2, #0
	bl GetMonData
	ldr r1, _02089600 ; =0x0000027A
	strb r0, [r5, r1]
	sub r1, #0x4e
	ldr r0, [r5, r1]
	ldrb r0, [r0, #0x11]
	cmp r0, #2
	bne _02089584
	add r0, r4, #0
	bl Heap_Free
_02089584:
	mov r1, #7
	mov r0, #0
	lsl r1, r1, #6
	mov r2, #0x13
	bl LoadFontPal1
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0, #4]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x13
	str r0, [sp, #4]
	ldr r0, [r5]
	ldr r2, _02089604 ; =0x000003E2
	mov r1, #1
	mov r3, #0xd
	bl LoadUserFrameGfx2
	ldr r0, _020895EC ; =0x000007BE
	ldrb r0, [r5, r0]
	cmp r0, #0
	bne _020895C8
	add r0, r5, #0
	mov r1, #0xfe
	bl sub_0208DDA0
	add sp, #8
	mov r0, #0x12
	pop {r4, r5, r6, pc}
_020895C8:
	add r0, r5, #0
	bl sub_0208E174
	add r0, r5, #0
	bl sub_0208BCD4
	add r0, r5, #0
	bl sub_0208BDC8
	add sp, #8
	mov r0, #0x11
	pop {r4, r5, r6, pc}
_020895E0:
	mov r0, #0x10
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_020895E8: .word gSystem
_020895EC: .word 0x000007BE
_020895F0: .word 0x00000275
_020895F4: .word 0x00000276
_020895F8: .word 0x00000277
_020895FC: .word 0x00000279
_02089600: .word 0x0000027A
_02089604: .word 0x000003E2
	thumb_func_end sub_02089478
