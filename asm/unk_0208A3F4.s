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
	thumb_func_start sub_0208A3F4
sub_0208A3F4: ; 0x0208A3F4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x8b
	lsl r0, r0, #2
	str r1, [sp]
	ldr r1, [r5, r0]
	mov r0, #0x14
	ldrsb r4, [r1, r0]
_0208A404:
	ldr r0, [sp]
	add r0, r4, r0
	lsl r0, r0, #0x18
	asr r4, r0, #0x18
	bmi _0208A41A
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldrb r0, [r0, #0x13]
	cmp r4, r0
	blt _0208A420
_0208A41A:
	mov r0, #0
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
_0208A420:
	bl sub_02070D90
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r7, r4, #0
	ldr r6, [r1]
	mul r7, r0
	add r0, r6, r7
	mov r1, #5
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _0208A404
	add r0, r6, r7
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _0208A456
	add r0, r5, #0
	bl sub_0208A3CC
	cmp r0, #1
	bne _0208A404
_0208A456:
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0208A3F4
	thumb_func_start sub_0208A45C
sub_0208A45C: ; 0x0208A45C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x8b
	lsl r0, r0, #2
	add r7, r1, #0
	ldr r1, [r5, r0]
	mov r0, #0x14
	ldrsb r4, [r1, r0]
_0208A46C:
	add r0, r4, r7
	lsl r0, r0, #0x18
	asr r4, r0, #0x18
	bmi _0208A480
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	ldrb r0, [r1, #0x13]
	cmp r4, r0
	blt _0208A486
_0208A480:
	mov r0, #0
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
_0208A486:
	ldr r0, [r1]
	add r1, r4, #0
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r6, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _0208A46C
	add r0, r6, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _0208A4B4
	add r0, r5, #0
	bl sub_0208A3CC
	cmp r0, #1
	bne _0208A46C
_0208A4B4:
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0208A45C
	thumb_func_start sub_0208A4B8
sub_0208A4B8: ; 0x0208A4B8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x8b
	lsl r0, r0, #2
	str r1, [sp]
	ldr r1, [r5, r0]
	mov r0, #0x14
	ldrsb r4, [r1, r0]
_0208A4C8:
	ldr r0, [sp]
	add r0, r4, r0
	lsl r0, r0, #0x18
	asr r4, r0, #0x18
	bmi _0208A4DE
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldrb r0, [r0, #0x13]
	cmp r4, r0
	blt _0208A4E4
_0208A4DE:
	mov r0, #0
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
_0208A4E4:
	bl sub_02070D94
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r7, r4, #0
	ldr r6, [r1]
	mul r7, r0
	add r0, r6, r7
	mov r1, #5
	mov r2, #0
	bl GetBoxMonData
	cmp r0, #0
	beq _0208A4C8
	add r0, r6, r7
	mov r1, #0x4c
	mov r2, #0
	bl GetBoxMonData
	cmp r0, #0
	beq _0208A51A
	add r0, r5, #0
	bl sub_0208A3CC
	cmp r0, #1
	bne _0208A4C8
_0208A51A:
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0208A4B8
	thumb_func_start sub_0208A520
sub_0208A520: ; 0x0208A520
	push {r4, lr}
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r4, [r0, r1]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _0208A538
	cmp r0, #1
	beq _0208A546
	cmp r0, #2
	beq _0208A550
	b _0208A55E
_0208A538:
	bl sub_02070D90
	ldrb r1, [r4, #0x14]
	ldr r2, [r4]
	mul r0, r1
	add r0, r2, r0
	pop {r4, pc}
_0208A546:
	ldrb r1, [r4, #0x14]
	ldr r0, [r4]
	bl Party_GetMonByIndex
	pop {r4, pc}
_0208A550:
	bl sub_02070D94
	ldrb r1, [r4, #0x14]
	ldr r2, [r4]
	mul r0, r1
	add r0, r2, r0
	pop {r4, pc}
_0208A55E:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_0208A520
	thumb_func_start sub_0208A564
sub_0208A564: ; 0x0208A564
	push {r4, lr}
	ldr r1, _0208A630 ; =0x000007BE
	add r4, r0, #0
	ldrb r1, [r4, r1]
	cmp r1, #0
	beq _0208A57A
	cmp r1, #1
	beq _0208A5B6
	cmp r1, #2
	beq _0208A5E2
	b _0208A62A
_0208A57A:
	ldr r0, _0208A634 ; =0x00000428
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0208A634 ; =0x00000428
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	mov r2, #0
	ldr r0, [r4]
	mov r1, #5
	add r3, r2, #0
	bl ScheduleSetBgPosText
	ldr r0, [r4]
	mov r1, #5
	mov r2, #3
	mov r3, #0
	bl ScheduleSetBgPosText
	add r0, r4, #0
	add r0, #0x44
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, _0208A630 ; =0x000007BE
	mov r1, #1
	strb r1, [r4, r0]
	b _0208A62A
_0208A5B6:
	ldr r0, [r4]
	mov r1, #5
	bl Bg_GetXpos
	cmp r0, #0x80
	ldr r0, [r4]
	blt _0208A5D6
	mov r1, #5
	mov r2, #0
	mov r3, #0x80
	bl ScheduleSetBgPosText
	ldr r0, _0208A630 ; =0x000007BE
	mov r1, #2
	strb r1, [r4, r0]
	b _0208A62A
_0208A5D6:
	mov r1, #5
	mov r2, #1
	mov r3, #0x40
	bl ScheduleSetBgPosText
	b _0208A62A
_0208A5E2:
	bl sub_0208DB1C
	add r0, r4, #0
	bl sub_0208A79C
	mov r0, #0x43
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl thunk_Sprite_SetDrawFlag
	add r0, r4, #0
	bl sub_0208C068
	mov r0, #9
	lsl r0, r0, #6
	ldrb r1, [r4, r0]
	add r0, r0, #1
	ldrb r0, [r4, r0]
	cmp r1, r0
	beq _0208A616
	ldr r0, _0208A638 ; =0x00000434
	mov r1, #1
	ldr r0, [r4, r0]
	bl thunk_Sprite_SetDrawFlag
_0208A616:
	ldr r0, _0208A634 ; =0x00000428
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0208A630 ; =0x000007BE
	mov r1, #0
	strb r1, [r4, r0]
	mov r0, #1
	pop {r4, pc}
_0208A62A:
	mov r0, #0
	pop {r4, pc}
	nop
_0208A630: .word 0x000007BE
_0208A634: .word 0x00000428
_0208A638: .word 0x00000434
	thumb_func_end sub_0208A564
	thumb_func_start sub_0208A63C
sub_0208A63C: ; 0x0208A63C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0208A70C ; =0x000007BE
	ldrb r0, [r4, r0]
	cmp r0, #0
	beq _0208A652
	cmp r0, #1
	beq _0208A69C
	cmp r0, #2
	beq _0208A6C8
	b _0208A706
_0208A652:
	mov r0, #0x43
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl thunk_Sprite_SetDrawFlag
	ldr r0, _0208A710 ; =0x00000434
	mov r1, #0
	ldr r0, [r4, r0]
	bl thunk_Sprite_SetDrawFlag
	ldr r0, _0208A714 ; =0x0000044C
	mov r1, #0
	ldr r0, [r4, r0]
	bl thunk_Sprite_SetDrawFlag
	mov r0, #0x45
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl thunk_Sprite_SetDrawFlag
	ldr r0, _0208A718 ; =0x00000428
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	bl sub_0208DB58
	add r0, r4, #0
	bl sub_0208DAD4
	ldr r0, _0208A70C ; =0x000007BE
	mov r1, #1
	strb r1, [r4, r0]
	b _0208A706
_0208A69C:
	ldr r0, [r4]
	mov r1, #5
	bl Bg_GetXpos
	cmp r0, #0x80
	ldr r0, [r4]
	bgt _0208A6BC
	mov r2, #0
	mov r1, #5
	add r3, r2, #0
	bl ScheduleSetBgPosText
	ldr r0, _0208A70C ; =0x000007BE
	mov r1, #2
	strb r1, [r4, r0]
	b _0208A706
_0208A6BC:
	mov r1, #5
	mov r2, #2
	mov r3, #0x40
	bl ScheduleSetBgPosText
	b _0208A706
_0208A6C8:
	mov r0, #0x81
	lsl r0, r0, #2
	add r0, r4, r0
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x64
	bl ScheduleWindowCopyToVram
	mov r0, #0x7d
	lsl r0, r0, #2
	add r0, r4, r0
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x44
	bl ScheduleWindowCopyToVram
	ldr r0, _0208A718 ; =0x00000428
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	bl sub_0208B400
	ldr r0, _0208A70C ; =0x000007BE
	mov r1, #0
	strb r1, [r4, r0]
	mov r0, #1
	pop {r4, pc}
_0208A706:
	mov r0, #0
	pop {r4, pc}
	nop
_0208A70C: .word 0x000007BE
_0208A710: .word 0x00000434
_0208A714: .word 0x0000044C
_0208A718: .word 0x00000428
	thumb_func_end sub_0208A63C
	thumb_func_start sub_0208A71C
sub_0208A71C: ; 0x0208A71C
	push {r4, r5, r6, r7}
	add r5, r0, #0
	ldr r0, _0208A798 ; =0x000007BD
	ldrb r0, [r5, r0]
	lsl r0, r0, #0x1c
	lsr r4, r0, #0x1c
	lsl r0, r4, #0x18
	asr r2, r0, #0x18
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r3, [r5, r0]
	ldrb r0, [r3, #0x12]
	cmp r0, #2
	bne _0208A746
	ldrh r0, [r3, #0x18]
	cmp r0, #0
	beq _0208A742
	mov r3, #4
	b _0208A748
_0208A742:
	mov r3, #3
	b _0208A748
_0208A746:
	mov r3, #3
_0208A748:
	mov r6, #0x99
	mov r0, #0
	lsl r6, r6, #2
_0208A74E:
	add r2, r2, r1
	lsl r2, r2, #0x18
	asr r2, r2, #0x18
	bpl _0208A75A
	add r2, r3, #0
	b _0208A760
_0208A75A:
	cmp r2, r3
	ble _0208A760
	add r2, r0, #0
_0208A760:
	cmp r2, #4
	beq _0208A772
	lsl r7, r2, #1
	add r7, r5, r7
	ldrh r7, [r7, r6]
	cmp r7, #0
	bne _0208A772
	cmp r2, r4
	bne _0208A74E
_0208A772:
	cmp r2, r4
	beq _0208A790
	ldr r3, _0208A798 ; =0x000007BD
	mov r1, #0xf
	ldrb r0, [r5, r3]
	bic r0, r1
	lsl r1, r2, #0x18
	lsr r2, r1, #0x18
	mov r1, #0xf
	and r1, r2
	orr r0, r1
	strb r0, [r5, r3]
	mov r0, #1
	pop {r4, r5, r6, r7}
	bx lr
_0208A790:
	mov r0, #0
	pop {r4, r5, r6, r7}
	bx lr
	nop
_0208A798: .word 0x000007BD
	thumb_func_end sub_0208A71C
	thumb_func_start sub_0208A79C
sub_0208A79C: ; 0x0208A79C
	push {r4, lr}
	add r4, r0, #0
	bl sub_0208BBDC
	ldr r0, _0208A7F4 ; =0x000007BD
	ldrb r0, [r4, r0]
	lsl r0, r0, #0x1c
	lsr r1, r0, #0x1c
	cmp r1, #4
	bne _0208A7D0
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldrh r1, [r0, #0x18]
	cmp r1, #0
	beq _0208A7C4
	add r0, r4, #0
	bl sub_0208A7F8
	pop {r4, pc}
_0208A7C4:
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl sub_0208A7F8
	pop {r4, pc}
_0208A7D0:
	cmp r1, #5
	bne _0208A7E0
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl sub_0208A7F8
	pop {r4, pc}
_0208A7E0:
	lsl r1, r1, #1
	add r2, r4, r1
	mov r1, #0x99
	lsl r1, r1, #2
	ldrh r1, [r2, r1]
	add r0, r4, #0
	bl sub_0208A7F8
	pop {r4, pc}
	nop
_0208A7F4: .word 0x000007BD
	thumb_func_end sub_0208A79C
	thumb_func_start sub_0208A7F8
sub_0208A7F8: ; 0x0208A7F8
	push {r3, r4, r5, lr}
	mov r2, #0
	add r4, r1, #0
	mvn r2, r2
	add r5, r0, #0
	cmp r4, r2
	bne _0208A816
	bl sub_0208DAD4
	ldr r0, _0208A830 ; =0x0000044C
	mov r1, #0
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetDrawFlag
	pop {r3, r4, r5, pc}
_0208A816:
	bl sub_0208D9A0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0208BB8C
	ldr r0, _0208A830 ; =0x0000044C
	mov r1, #1
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetDrawFlag
	pop {r3, r4, r5, pc}
	nop
_0208A830: .word 0x0000044C
	thumb_func_end sub_0208A7F8
	thumb_func_start sub_0208A834
sub_0208A834: ; 0x0208A834
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	bl sub_0208A520
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	ldrb r1, [r1, #0x11]
	cmp r1, #2
	ldr r1, _0208A8F0 ; =0x000007BD
	bne _0208A85A
	ldrb r2, [r4, r1]
	lsl r1, r2, #0x1c
	lsl r2, r2, #0x18
	lsr r1, r1, #0x1c
	lsr r2, r2, #0x1c
	bl BoxMonSwapMoves
	b _0208A868
_0208A85A:
	ldrb r2, [r4, r1]
	lsl r1, r2, #0x1c
	lsl r2, r2, #0x18
	lsr r1, r1, #0x1c
	lsr r2, r2, #0x1c
	bl MonSwapMoves
_0208A868:
	ldr r0, _0208A8F0 ; =0x000007BD
	mov r1, #0x99
	ldrb r6, [r4, r0]
	lsl r1, r1, #2
	add r5, r4, r1
	lsl r2, r6, #0x1c
	lsl r6, r6, #0x18
	lsr r6, r6, #0x1c
	lsl r6, r6, #1
	lsr r3, r2, #0x1b
	add r6, r4, r6
	ldrh r2, [r5, r3]
	ldrh r6, [r6, r1]
	strh r6, [r5, r3]
	ldrb r3, [r4, r0]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x1c
	lsl r3, r3, #1
	add r3, r4, r3
	strh r2, [r3, r1]
	add r2, r1, #0
	add r2, #8
	ldrb r6, [r4, r0]
	add r5, r4, r2
	lsl r2, r6, #0x1c
	lsl r6, r6, #0x18
	lsr r6, r6, #0x1c
	add r7, r4, r6
	add r6, r1, #0
	lsr r3, r2, #0x1c
	add r6, #8
	ldrb r2, [r5, r3]
	ldrb r6, [r7, r6]
	strb r6, [r5, r3]
	ldrb r3, [r4, r0]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x1c
	add r5, r4, r3
	add r3, r1, #0
	add r3, #8
	strb r2, [r5, r3]
	add r2, r1, #0
	add r2, #0xc
	ldrb r6, [r4, r0]
	add r5, r4, r2
	lsl r2, r6, #0x1c
	lsl r6, r6, #0x18
	lsr r6, r6, #0x1c
	add r7, r4, r6
	add r6, r1, #0
	lsr r3, r2, #0x1c
	add r6, #0xc
	ldrb r2, [r5, r3]
	ldrb r6, [r7, r6]
	strb r6, [r5, r3]
	ldrb r0, [r4, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	add r3, r4, r0
	add r0, r1, #0
	add r0, #0xc
	strb r2, [r3, r0]
	sub r1, #0x38
	ldr r0, [r4, r1]
	mov r2, #1
	str r2, [r0, #0x38]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0208A8F0: .word 0x000007BD
	thumb_func_end sub_0208A834
	thumb_func_start sub_0208A8F4
sub_0208A8F4: ; 0x0208A8F4
	push {r4, lr}
	add r4, r0, #0
	mov r2, #0
	ldr r0, [r4]
	mov r1, #2
	add r3, r2, #0
	bl ScheduleSetBgPosText
	add r0, r4, #0
	bl sub_0208DB1C
	add r0, r4, #0
	bl sub_0208A79C
	mov r0, #0x43
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl thunk_Sprite_SetDrawFlag
	add r0, r4, #0
	bl sub_0208C068
	mov r0, #9
	lsl r0, r0, #6
	ldrb r1, [r4, r0]
	add r0, r0, #1
	ldrb r0, [r4, r0]
	cmp r1, r0
	beq _0208A93A
	ldr r0, _0208A948 ; =0x00000434
	mov r1, #1
	ldr r0, [r4, r0]
	bl thunk_Sprite_SetDrawFlag
_0208A93A:
	ldr r0, _0208A94C ; =0x00000428
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	pop {r4, pc}
	nop
_0208A948: .word 0x00000434
_0208A94C: .word 0x00000428
	thumb_func_end sub_0208A8F4
	thumb_func_start sub_0208A950
sub_0208A950: ; 0x0208A950
	push {r4, lr}
	add r4, r0, #0
	bl sub_0208DB1C
	add r0, r4, #0
	bl sub_0208A79C
	add r0, r4, #0
	bl sub_0208C068
	ldr r0, _0208A9BC ; =0x000007BC
	ldrsb r0, [r4, r0]
	cmp r0, #1
	bne _0208A9A4
	add r0, r4, #0
	bl sub_0208C208
	mov r0, #0x43
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl thunk_Sprite_SetDrawFlag
	mov r0, #9
	lsl r0, r0, #6
	ldrb r1, [r4, r0]
	add r0, r0, #1
	ldrb r0, [r4, r0]
	cmp r1, r0
	beq _0208A996
	ldr r0, _0208A9C0 ; =0x00000434
	mov r1, #1
	ldr r0, [r4, r0]
	bl thunk_Sprite_SetDrawFlag
_0208A996:
	ldr r0, [r4]
	mov r1, #2
	mov r2, #3
	mov r3, #0
	bl ScheduleSetBgPosText
	pop {r4, pc}
_0208A9A4:
	add r0, r4, #0
	bl sub_0208C0E8
	mov r2, #3
	add r3, r2, #0
	ldr r0, [r4]
	mov r1, #2
	add r3, #0xfd
	bl ScheduleSetBgPosText
	pop {r4, pc}
	nop
_0208A9BC: .word 0x000007BC
_0208A9C0: .word 0x00000434
	thumb_func_end sub_0208A950
	thumb_func_start sub_0208A9C4
sub_0208A9C4: ; 0x0208A9C4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0208AA8C ; =0x000007BE
	ldrb r0, [r4, r0]
	cmp r0, #0
	beq _0208A9DA
	cmp r0, #1
	beq _0208AA32
	cmp r0, #2
	beq _0208AA5E
	b _0208AA86
_0208A9DA:
	mov r2, #0
	ldr r0, [r4]
	mov r1, #5
	add r3, r2, #0
	bl ScheduleSetBgPosText
	ldr r0, [r4]
	mov r1, #5
	mov r2, #3
	mov r3, #0
	bl ScheduleSetBgPosText
	ldr r0, _0208AA90 ; =0x00000428
	mov r1, #3
	ldr r0, [r4, r0]
	bl Sprite_SetPriority
	ldr r0, _0208AA90 ; =0x00000428
	mov r1, #0
	ldr r0, [r4, r0]
	bl thunk_Sprite_SetPaletteOverride
	mov r0, #0x75
	lsl r0, r0, #2
	add r0, r4, r0
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x5d
	lsl r0, r0, #2
	add r0, r4, r0
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, _0208AA94 ; =0x000007C5
	mov r1, #0
	strb r1, [r4, r0]
	mov r1, #1
	sub r0, r0, #7
	strb r1, [r4, r0]
	b _0208AA86
_0208AA32:
	ldr r0, [r4]
	mov r1, #5
	bl Bg_GetYpos
	cmp r0, #0x48
	ldr r0, [r4]
	blt _0208AA52
	mov r1, #5
	mov r2, #3
	mov r3, #0x48
	bl ScheduleSetBgPosText
	ldr r0, _0208AA8C ; =0x000007BE
	mov r1, #2
	strb r1, [r4, r0]
	b _0208AA86
_0208AA52:
	mov r1, #5
	mov r2, #4
	mov r3, #0x24
	bl ScheduleSetBgPosText
	b _0208AA86
_0208AA5E:
	mov r0, #5
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, _0208AA98 ; =0x0000050C
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	mov r1, #0
	bl sub_0208AB58
	ldr r0, _0208AA8C ; =0x000007BE
	mov r1, #0
	strb r1, [r4, r0]
	mov r0, #1
	pop {r4, pc}
_0208AA86:
	mov r0, #0
	pop {r4, pc}
	nop
_0208AA8C: .word 0x000007BE
_0208AA90: .word 0x00000428
_0208AA94: .word 0x000007C5
_0208AA98: .word 0x0000050C
	thumb_func_end sub_0208A9C4
	thumb_func_start sub_0208AA9C
sub_0208AA9C: ; 0x0208AA9C
	push {r4, lr}
	ldr r1, _0208AB50 ; =0x000007BE
	add r4, r0, #0
	ldrb r0, [r4, r1]
	cmp r0, #0
	beq _0208AAB2
	cmp r0, #1
	beq _0208AAE2
	cmp r0, #2
	beq _0208AB0E
	b _0208AB4A
_0208AAB2:
	mov r2, #0
	add r0, r1, #6
	strb r2, [r4, r0]
	add r0, r1, #7
	strb r2, [r4, r0]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x10
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x20
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	bl sub_0208C2A0
	ldr r0, _0208AB50 ; =0x000007BE
	mov r1, #1
	strb r1, [r4, r0]
	b _0208AB4A
_0208AAE2:
	ldr r0, [r4]
	mov r1, #5
	bl Bg_GetYpos
	cmp r0, #0
	ldr r0, [r4]
	bgt _0208AB02
	mov r1, #5
	mov r2, #3
	mov r3, #0
	bl ScheduleSetBgPosText
	ldr r0, _0208AB50 ; =0x000007BE
	mov r1, #2
	strb r1, [r4, r0]
	b _0208AB4A
_0208AB02:
	mov r1, #5
	add r2, r1, #0
	mov r3, #0x24
	bl ScheduleSetBgPosText
	b _0208AB4A
_0208AB0E:
	mov r0, #0x75
	lsl r0, r0, #2
	add r0, r4, r0
	bl ScheduleWindowCopyToVram
	mov r0, #0x5d
	lsl r0, r0, #2
	add r0, r4, r0
	bl ScheduleWindowCopyToVram
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ScheduleWindowCopyToVram
	ldr r0, _0208AB54 ; =0x00000428
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetPriority
	ldr r0, _0208AB54 ; =0x00000428
	mov r1, #2
	ldr r0, [r4, r0]
	bl thunk_Sprite_SetPaletteOverride
	ldr r0, _0208AB50 ; =0x000007BE
	mov r1, #0
	strb r1, [r4, r0]
	mov r0, #1
	pop {r4, pc}
_0208AB4A:
	mov r0, #0
	pop {r4, pc}
	nop
_0208AB50: .word 0x000007BE
_0208AB54: .word 0x00000428
	thumb_func_end sub_0208AA9C
	thumb_func_start sub_0208AB58
sub_0208AB58: ; 0x0208AB58
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _0208ACC4 ; =0x000007C4
	add r4, r1, #0
	add r1, r0, #1
	ldrb r7, [r5, r0]
	ldrb r6, [r5, r1]
	cmp r4, #1
	bne _0208AB80
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	cmp r1, #2
	beq _0208AB94
	ldr r0, _0208ACC4 ; =0x000007C4
	ldrb r1, [r5, r0]
	add r1, r1, #1
	strb r1, [r5, r0]
	b _0208AC34
_0208AB80:
	mov r2, #0
	mvn r2, r2
	cmp r4, r2
	bne _0208ABA0
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	cmp r1, #0
	bne _0208AB96
_0208AB94:
	b _0208ACC0
_0208AB96:
	ldr r0, _0208ACC4 ; =0x000007C4
	ldrb r1, [r5, r0]
	sub r1, r1, #1
	strb r1, [r5, r0]
	b _0208AC34
_0208ABA0:
	cmp r4, #3
	bne _0208ABD4
	cmp r7, #6
	blo _0208ABCE
	add r2, r6, #1
	lsl r1, r2, #3
	add r1, r2, r1
	add r2, r0, #2
	ldrb r2, [r5, r2]
	cmp r1, r2
	bge _0208AC34
	add r1, r0, #1
	ldrb r1, [r5, r1]
	add r2, r1, #1
	add r1, r0, #1
	strb r2, [r5, r1]
	ldrb r0, [r5, r0]
	mov r1, #3
	bl _s32_div_f
	ldr r0, _0208ACC4 ; =0x000007C4
	strb r1, [r5, r0]
	b _0208AC34
_0208ABCE:
	add r1, r7, #3
	strb r1, [r5, r0]
	b _0208AC34
_0208ABD4:
	sub r1, r2, #2
	cmp r4, r1
	bne _0208AC02
	cmp r7, #2
	bhi _0208ABFC
	cmp r6, #0
	beq _0208AC34
	add r1, r0, #1
	ldrb r1, [r5, r1]
	sub r2, r1, #1
	add r1, r0, #1
	strb r2, [r5, r1]
	ldrb r0, [r5, r0]
	mov r1, #3
	bl _s32_div_f
	ldr r0, _0208ACC4 ; =0x000007C4
	add r1, r1, #6
	strb r1, [r5, r0]
	b _0208AC34
_0208ABFC:
	sub r1, r7, #3
	strb r1, [r5, r0]
	b _0208AC34
_0208AC02:
	cmp r4, #9
	bne _0208AC20
	add r2, r6, #1
	lsl r1, r2, #3
	add r1, r2, r1
	add r2, r0, #2
	ldrb r2, [r5, r2]
	cmp r1, r2
	bge _0208AC34
	add r1, r0, #1
	ldrb r1, [r5, r1]
	add r0, r0, #1
	add r1, r1, #1
	strb r1, [r5, r0]
	b _0208AC34
_0208AC20:
	sub r2, #8
	cmp r4, r2
	bne _0208AC34
	cmp r6, #0
	beq _0208AC34
	add r1, r0, #1
	ldrb r1, [r5, r1]
	add r0, r0, #1
	sub r1, r1, #1
	strb r1, [r5, r0]
_0208AC34:
	ldr r0, _0208ACC4 ; =0x000007C4
	ldrb r1, [r5, r0]
	cmp r7, r1
	bne _0208AC44
	add r0, r0, #1
	ldrb r0, [r5, r0]
	cmp r6, r0
	beq _0208AC56
_0208AC44:
	cmp r4, #9
	beq _0208AC56
	mov r0, #8
	mvn r0, r0
	cmp r4, r0
	beq _0208AC56
	ldr r0, _0208ACC8 ; =0x000005DC
	bl PlaySE
_0208AC56:
	ldr r1, _0208ACC4 ; =0x000007C4
	add r0, r5, #0
	ldrb r1, [r5, r1]
	bl sub_0208ACDC
	ldr r1, _0208ACCC ; =0x000007C7
	strb r0, [r5, r1]
	add r0, r5, #0
	bl sub_0208C380
	ldr r0, _0208ACD0 ; =0x000007C5
	ldrb r0, [r5, r0]
	cmp r6, r0
	beq _0208AC78
	add r0, r5, #0
	bl sub_0208C320
_0208AC78:
	add r0, r5, #0
	bl sub_0208D7C4
	ldr r0, _0208ACD0 ; =0x000007C5
	ldrb r0, [r5, r0]
	cmp r0, #0
	ldr r0, _0208ACD4 ; =0x00000504
	beq _0208AC92
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	b _0208AC9A
_0208AC92:
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0208AC9A:
	ldr r0, _0208ACD0 ; =0x000007C5
	ldrb r1, [r5, r0]
	add r0, r0, #1
	ldrb r0, [r5, r0]
	add r2, r1, #1
	lsl r1, r2, #3
	add r1, r2, r1
	cmp r1, r0
	ldr r0, _0208ACD8 ; =0x00000508
	bge _0208ACB8
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	pop {r3, r4, r5, r6, r7, pc}
_0208ACB8:
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0208ACC0:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0208ACC4: .word 0x000007C4
_0208ACC8: .word 0x000005DC
_0208ACCC: .word 0x000007C7
_0208ACD0: .word 0x000007C5
_0208ACD4: .word 0x00000504
_0208ACD8: .word 0x00000508
	thumb_func_end sub_0208AB58
	thumb_func_start sub_0208ACDC
sub_0208ACDC: ; 0x0208ACDC
	push {r4, r5, r6, r7}
	ldr r2, _0208AD30 ; =0x000007C5
	mov r6, #0
	ldrb r3, [r0, r2]
	add r4, r6, #0
	lsl r2, r3, #3
	add r2, r3, r2
	add r1, r1, r2
	lsl r1, r1, #0x18
	lsr r5, r1, #0x18
	mov r1, #0xa1
	mov r2, #1
	lsl r1, r1, #2
_0208ACF6:
	mov r3, #0x1f
	add r7, r4, #0
	and r7, r3
	add r3, r2, #0
	lsl r3, r7
	lsr r7, r4, #5
	lsl r7, r7, #2
	add r7, r0, r7
	ldr r7, [r7, r1]
	tst r3, r7
	beq _0208AD1E
	cmp r5, r6
	bne _0208AD18
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	pop {r4, r5, r6, r7}
	bx lr
_0208AD18:
	add r3, r6, #1
	lsl r3, r3, #0x18
	lsr r6, r3, #0x18
_0208AD1E:
	add r3, r4, #1
	lsl r3, r3, #0x10
	lsr r4, r3, #0x10
	cmp r4, #0x50
	blo _0208ACF6
	mov r0, #0
	pop {r4, r5, r6, r7}
	bx lr
	nop
_0208AD30: .word 0x000007C5
	thumb_func_end sub_0208ACDC
