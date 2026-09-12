#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_trainer_card_main.inc"
	.include "global.inc"

	.text

.public TrainerCardMainApp_Exit
.public TrainerCardMainApp_Init
.public TrainerCardMainApp_Main
.public _021E7DB8
.public _021E80A0
.public ov51_021E5F64
.public ov51_021E6038
.public ov51_021E60D4
.public ov51_021E60F4
.public ov51_021E6200
.public ov51_021E6238
.public ov51_021E6354
.public ov51_021E6644
.public ov51_021E66C0
.public ov51_021E6734
.public ov51_021E67A4
.public ov51_021E6888
.public ov51_021E69EC
.public ov51_021E6A54
.public ov51_021E6AAC
.public ov51_021E6B44
.public ov51_021E6B88
.public ov51_021E6C00
.public ov51_021E6C6C
.public ov51_021E6CCC
.public ov51_021E6CF0
.public ov51_021E6D44
.public ov51_021E6DA8
.public ov51_021E6E10
.public ov51_021E6E60
.public ov51_021E6EF0
.public ov51_021E6F18
.public ov51_021E71D0
.public ov51_021E7208
.public ov51_021E74D4
.public ov51_021E74F4
.public ov51_021E7540
.public ov51_021E757C
.public ov51_021E7664
.public ov51_021E76A4
.public ov51_021E76EC
.public ov51_021E77A0
.public ov51_021E7804
.public ov51_021E786C
.public ov51_021E78D0
.public ov51_021E78F8
.public ov51_021E7AF4
.public ov51_021E7BD0
.public ov51_021E7CA4
.public ov51_021E7D44
.public ov51_021E7D68
.public ov51_021E7DA4
.public ov51_021E7DBC
.public ov51_021E7DC0
.public ov51_021E7DC8
.public ov51_021E7DD8
.public ov51_021E7DF0
.public ov51_021E7E08
.public ov51_021E7E20
.public ov51_021E7E38
.public ov51_021E7E54
.public ov51_021E7E70
.public ov51_021E7E8C
.public ov51_021E7EA8
.public ov51_021E7ED0
.public ov51_021E7F08
.public ov51_021E7F48
.public ov51_021E7FB8
.public ov51_021E7FBC
.public ov51_021E7FC4
.public ov51_021E7FCC
.public ov51_021E7FDC
.public ov51_021E801C
.public ov51_021E80A4

	thumb_func_start ov51_021E76A4
ov51_021E76A4: ; 0x021E76A4
	push {r3, r4, r5, lr}
	sub sp, #0x10
	ldr r1, _021E76E4 ; =0x000033D8
	add r5, r0, #0
	ldr r1, [r5, r1]
	mov r0, #4
	mov r2, #0
	bl FontID_String_GetWidth
	mov r1, #0x30
	sub r4, r1, r0
	add r0, r5, #0
	add r0, #0xd4
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #4
	str r1, [sp]
	mov r2, #0
	ldr r0, _021E76E8 ; =0x00050400
	str r2, [sp, #4]
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	ldr r2, _021E76E4 ; =0x000033D8
	add r0, r5, #0
	ldr r2, [r5, r2]
	add r0, #0xd4
	lsr r3, r4, #1
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E76E4: .word 0x000033D8
_021E76E8: .word 0x00050400
	thumb_func_end ov51_021E76A4

	thumb_func_start ov51_021E76EC
ov51_021E76EC: ; 0x021E76EC
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r4, r5, #0
	add r4, #0xc4
	cmp r1, #0
	bne _021E7706
	ldr r0, _021E778C ; =0x0000343A
	ldrb r0, [r5, r0]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	beq _021E7706
	mov r1, #1
_021E7706:
	cmp r1, #0
	beq _021E7712
	cmp r1, #1
	beq _021E7756
	add sp, #0x10
	pop {r3, r4, r5, pc}
_021E7712:
	add r0, r4, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r1, _021E7790 ; =0x000033E0
	mov r0, #4
	ldr r1, [r5, r1]
	mov r2, #0
	bl FontID_String_GetWidth
	mov r1, #0x60
	sub r3, r1, r0
	mov r1, #4
	str r1, [sp]
	mov r2, #0
	ldr r0, _021E7794 ; =0x00050400
	str r2, [sp, #4]
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	ldr r2, _021E7790 ; =0x000033E0
	add r0, r4, #0
	ldr r2, [r5, r2]
	lsr r3, r3, #1
	bl AddTextPrinterParameterizedWithColor
	ldr r0, _021E7798 ; =0x0000311C
	mov r1, #1
	add r0, r5, r0
	mov r2, #2
	add r3, r1, #0
	bl ov51_021E7D44
	add sp, #0x10
	pop {r3, r4, r5, pc}
_021E7756:
	add r0, r4, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #4
	str r0, [sp]
	mov r1, #0
	ldr r0, _021E7794 ; =0x00050400
	str r1, [sp, #4]
	str r0, [sp, #8]
	ldr r2, _021E779C ; =0x000033DC
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r4, #0
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	ldr r0, _021E7798 ; =0x0000311C
	mov r1, #1
	add r0, r5, r0
	mov r2, #4
	add r3, r1, #0
	bl ov51_021E7D44
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_021E778C: .word 0x0000343A
_021E7790: .word 0x000033E0
_021E7794: .word 0x00050400
_021E7798: .word 0x0000311C
_021E779C: .word 0x000033DC
	thumb_func_end ov51_021E76EC
