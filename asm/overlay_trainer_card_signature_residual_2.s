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

	thumb_func_start ov52_021E83C4
ov52_021E83C4: ; 0x021E83C4
	push {r4, r5, lr}
	sub sp, #0x9c
	ldr r5, _021E84B4 ; =ov52_021E94CC
	add r3, sp, #0x8c
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _021E84B8 ; =ov52_021E9524
	add r3, sp, #0x70
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #0
	str r0, [r3]
	add r0, r4, #0
	add r3, r1, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E84BC ; =ov52_021E9540
	add r3, sp, #0x54
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #1
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E84C0 ; =ov52_021E955C
	add r3, sp, #0x38
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #2
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	ldr r5, _021E84C4 ; =ov52_021E94EC
	add r3, sp, #0x1c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #4
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E84C8 ; =ov52_021E9508
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	str r0, [r3]
	add r0, r4, #0
	mov r1, #5
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #0
	mov r1, #0x20
	add r2, r0, #0
	mov r3, #0x27
	bl BG_ClearCharDataRange
	mov r0, #4
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x27
	bl BG_ClearCharDataRange
	add sp, #0x9c
	pop {r4, r5, pc}
	nop
_021E84B4: .word ov52_021E94CC
_021E84B8: .word ov52_021E9524
_021E84BC: .word ov52_021E9540
_021E84C0: .word ov52_021E955C
_021E84C4: .word ov52_021E94EC
_021E84C8: .word ov52_021E9508
	thumb_func_end ov52_021E83C4


	thumb_func_start ov52_021E84CC
ov52_021E84CC: ; 0x021E84CC
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	ldr r0, _021E8558 ; =0x0000433D
	mov r6, #0
	add r5, r7, r0
	mov r0, #0xf0
	add r4, r7, #0
	str r0, [sp]
_021E84DC:
	mov r0, #8
	mov r1, #0x27
	bl String_New
	str r0, [r4, #0x18]
	ldrb r1, [r5]
	ldr r0, [sp]
	add r6, r6, #1
	bic r1, r0
	strb r1, [r5]
	ldr r0, _021E855C ; =0x00004384
	mov r1, #0
	strh r1, [r4, r0]
	add r4, r4, #4
	add r5, #0x11
	cmp r6, #5
	blt _021E84DC
	mov r0, #0x14
	mov r1, #0x27
	bl String_New
	str r0, [r7, #0x2c]
	mov r0, #0x28
	mov r1, #0x27
	bl String_New
	str r0, [r7, #0x30]
	mov r0, #0x50
	mov r1, #0x27
	bl String_New
	str r0, [r7, #0x34]
	ldr r0, _021E8560 ; =0x0000431A
	mov r1, #0
	strb r1, [r7, r0]
	mov r0, #0xc3
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r7, r0]
	ldr r0, [r7, #0x14]
	ldr r2, [r7, #0x2c]
	mov r1, #msg_0252_00012 ; DONE
	bl ReadMsgDataIntoString
	ldr r0, [r7, #0x14]
	ldr r2, [r7, #0x30]
	mov r1, #msg_0252_00009 ; Sign your autograph!
	bl ReadMsgDataIntoString
	mov r0, #0x27
	bl YesNoPrompt_Create
	ldr r1, _021E8564 ; =0x00005C9C
	mov r2, #5
	str r0, [r7, r1]
	add r1, r1, #4
	mov r0, #0
	add r1, r7, r1
	bl MIi_CpuClearFast
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E8558: .word 0x0000433D
_021E855C: .word 0x00004384
_021E8560: .word 0x0000431A
_021E8564: .word 0x00005C9C
	thumb_func_end ov52_021E84CC
