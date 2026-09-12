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

	thumb_func_start ov51_021E6AAC
ov51_021E6AAC: ; 0x021E6AAC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl System_GetTouchNew
	cmp r0, #0
	bne _021E6ABE
	mov r0, #0
	pop {r3, r4, r5, pc}
_021E6ABE:
	ldr r0, _021E6B28 ; =_021E7DB8
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	beq _021E6AD8
	mov r0, #1
	str r0, [r4]
	mov r0, #SEQ_SE_GS_GEARCANCEL>>6
	lsl r0, r0, #6
	bl PlaySE
	mov r0, #5
	pop {r3, r4, r5, pc}
_021E6AD8:
	ldr r0, _021E6B2C ; =0x000030F4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021E6B02
	ldr r0, _021E6B30 ; =0x0000343A
	ldrb r0, [r5, r0]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	bne _021E6B02
	ldr r0, _021E6B34 ; =ov51_021E7DBC
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	beq _021E6B02
	mov r0, #1
	str r0, [r4]
	ldr r0, _021E6B38 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	mov r0, #4
	pop {r3, r4, r5, pc}
_021E6B02:
	ldr r0, _021E6B3C ; =ov51_021E7DC0
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	beq _021E6B24
	ldr r1, _021E6B40 ; =gSystem + 0x40
	mov r0, #0xd1
	ldrh r2, [r1, #0x20]
	lsl r0, r0, #6
	strb r2, [r5, r0]
	ldrh r1, [r1, #0x22]
	add r0, r0, #1
	strb r1, [r5, r0]
	mov r0, #1
	str r0, [r4]
	mov r0, #3
	pop {r3, r4, r5, pc}
_021E6B24:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E6B28: .word _021E7DB8
_021E6B2C: .word 0x000030F4
_021E6B30: .word 0x0000343A
_021E6B34: .word ov51_021E7DBC
_021E6B38: .word SEQ_SE_DP_SELECT
_021E6B3C: .word ov51_021E7DC0
_021E6B40: .word gSystem + 0x40
	thumb_func_end ov51_021E6AAC

	thumb_func_start ov51_021E6B44
ov51_021E6B44: ; 0x021E6B44
	push {r3, r4, lr}
	sub sp, #4
	mov r1, #0
	str r1, [sp]
	sub r2, r1, #1
	ldr r1, _021E6B80 ; =0x00003108
	add r4, r0, #0
	str r2, [r4, r1]
	add r1, sp, #0
	bl ov51_021E6AAC
	ldr r1, [sp]
	cmp r1, #0
	beq _021E6B6A
	ldr r1, _021E6B84 ; =0x0000310C
	mov r2, #1
	add sp, #4
	str r2, [r4, r1]
	pop {r3, r4, pc}
_021E6B6A:
	add r0, r4, #0
	bl ov51_021E6A54
	cmp r0, #0
	beq _021E6B7A
	ldr r1, _021E6B84 ; =0x0000310C
	mov r2, #0
	str r2, [r4, r1]
_021E6B7A:
	add sp, #4
	pop {r3, r4, pc}
	nop
_021E6B80: .word 0x00003108
_021E6B84: .word 0x0000310C
	thumb_func_end ov51_021E6B44
