#include "msgdata/msg/msg_0252.h"
	.include "asm/macros.inc"
	.include "overlay_trainer_card_signature.inc"
	.include "global.inc"

	.text
	.public TrainerCardSignature_Exit
	.public TrainerCardSignature_Init
	.public TrainerCardSignature_Main
	.public _021E94AC
	.public ov52_021E83C4
	.public ov52_021E84CC
	.public ov52_021E85DC
	.public ov52_021E870C
	.public ov52_021E888C
	.public ov52_021E8994
	.public ov52_021E89D4
	.public ov52_021E8BDC
	.public ov52_021E8DC4
	.public ov52_021E8E64
	.public ov52_021E8F2C
	.public ov52_021E8FAC
	.public ov52_021E9124
	.public ov52_021E9158
	.public ov52_021E9260
	.public ov52_021E927C
	.public ov52_021E9300
	.public ov52_021E9364
	.public ov52_021E94B2
	.public ov52_021E94BA
	.public ov52_021E94CC
	.public ov52_021E94DC
	.public ov52_021E94EC
	.public ov52_021E9508
	.public ov52_021E9524
	.public ov52_021E9540
	.public ov52_021E955C
	.public ov52_021E9578
	.public ov52_021E95A0
	.public ov52_021E96C0
	.public ov52_021E837C
	.public ov52_021E83A4
	.public ov52_021E8568
	.public ov52_021E85A0
	.public ov52_021E86DC
	.public ov52_021E8B94
	.public ov52_021E8BD8
	.public ov52_021E8CBC
	.public ov52_021E8CDC
	.public ov52_021E8CF4
	.public ov52_021E8D3C
	.public ov52_021E8D64
	.public ov52_021E8D8C
	.public ov52_021E8EDC
	.public ov52_021E8EFC
	.public ov52_021E9218
	.public ov52_021E921C
	.public ov52_021E925C
	.public ov52_021E92E8
	.public ov52_021E9424
	.public ov52_021E9488

	thumb_func_start ov52_021E8DC4
ov52_021E8DC4: ; 0x021E8DC4
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, _021E8E5C ; =0x00005C9C
	add r4, r1, #0
	ldr r0, [r5, r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	beq _021E8DDE
	cmp r0, #2
	beq _021E8E20
	b _021E8E46
_021E8DDE:
	ldr r0, [r5, #8]
	mov r1, #4 ; SCORE_EVENT_TRAINER_CARD_SIGNED
	bl GameStats_AddScore
	ldr r0, [r5, #8]
	mov r1, #0x73 ; GAME_STAT_TRAINER_CARDS_SIGNED
	bl GameStats_Inc
	mov r0, #0xb5
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #1
	bl ClearFrameAndWindow2
	ldr r0, _021E8E5C ; =0x00005C9C
	ldr r0, [r5, r0]
	bl YesNoPrompt_Reset
	mov r0, #0x10
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x27
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	add sp, #0xc
	mov r0, #2
	pop {r4, r5, pc}
_021E8E20:
	mov r0, #0xc3
	mov r1, #4
	lsl r0, r0, #2
	str r1, [r5, r0]
	sub r0, #0xbc
	add r0, r5, r0
	mov r1, #0
	bl ov52_021E8CDC
	mov r0, #0xb5
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #1
	bl ClearFrameAndWindow2
	ldr r0, _021E8E5C ; =0x00005C9C
	ldr r0, [r5, r0]
	bl YesNoPrompt_Reset
_021E8E46:
	ldr r1, _021E8E60 ; =0x0000432C
	mov r0, #0xf0
	ldrb r2, [r5, r1]
	bic r2, r0
	add r0, r5, #0
	strb r2, [r5, r1]
	bl ov52_021E8D3C
	add r0, r4, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_021E8E5C: .word 0x00005C9C
_021E8E60: .word 0x0000432C
	thumb_func_end ov52_021E8DC4


	thumb_func_start ov52_021E8E64
ov52_021E8E64: ; 0x021E8E64
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _021E8ED8 ; =0x00005C9C
	add r4, r1, #0
	ldr r0, [r5, r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	beq _021E8E7C
	cmp r0, #2
	beq _021E8EB4
	b _021E8ED4
_021E8E7C:
	mov r0, #0xc3
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r5, r0]
	sub r0, #0x38
	add r0, r5, r0
	bl ClearFrameAndWindow2
	ldr r0, _021E8ED8 ; =0x00005C9C
	ldr r0, [r5, r0]
	bl YesNoPrompt_Reset
	add r0, r5, #0
	mov r1, #0
	bl ov52_021E9488
	mov r0, #0xb1
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #2
	bl FillWindowPixelBuffer
	mov r0, #0xb1
	lsl r0, r0, #2
	add r0, r5, r0
	bl CopyWindowToVram
	b _021E8ED4
_021E8EB4:
	mov r0, #0xc3
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r5, r0]
	sub r0, #0x38
	add r0, r5, r0
	bl ClearFrameAndWindow2
	ldr r0, _021E8ED8 ; =0x00005C9C
	ldr r0, [r5, r0]
	bl YesNoPrompt_Reset
	add r0, r5, #0
	mov r1, #0
	bl ov52_021E9488
_021E8ED4:
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E8ED8: .word 0x00005C9C
	thumb_func_end ov52_021E8E64
