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

	thumb_func_start ov51_021E6CF0
ov51_021E6CF0: ; 0x021E6CF0
	push {r4, r5, r6, r7}
	mov r2, #3
	mov r4, #0
	lsl r2, r2, #0xc
_021E6CF8:
	asr r3, r4, #2
	lsr r3, r3, #0x1d
	add r3, r4, r3
	asr r3, r3, #3
	lsr r6, r3, #0x1f
	lsl r5, r3, #0x1d
	sub r5, r5, r6
	mov r3, #0x1d
	ror r5, r3
	add r3, r6, r5
	asr r5, r4, #5
	lsr r5, r5, #0x1a
	lsl r3, r3, #0x18
	add r5, r4, r5
	lsr r3, r3, #0x18
	asr r5, r5, #6
	lsl r5, r5, #3
	add r3, r0, r3
	ldrb r3, [r5, r3]
	lsr r7, r4, #0x1f
	lsl r6, r4, #0x1d
	sub r6, r6, r7
	mov r5, #0x1d
	ror r6, r5
	add r5, r7, r6
	lsl r5, r5, #0x18
	add r6, r3, #0
	lsr r5, r5, #0x18
	asr r6, r5
	mov r3, #1
	and r3, r6
	strb r3, [r1, r4]
	add r4, r4, #1
	cmp r4, r2
	blt _021E6CF8
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
	thumb_func_end ov51_021E6CF0

	thumb_func_start ov51_021E6D44
ov51_021E6D44: ; 0x021E6D44
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r1, #0
	mov r1, #1
	str r1, [sp]
	lsl r1, r7, #0x18
	mov r3, #3
	str r0, [sp, #4]
	lsr r1, r1, #0x18
	lsl r3, r3, #0xc
	bl BG_LoadCharTilesData
	lsl r1, r7, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	bl GetBgTilemapBuffer
	mov r4, #0
	add r1, r0, #0
	add r3, r4, #0
	add r0, r4, #0
_021E6D6E:
	add r5, r3, #0
	add r5, #0xc
	lsl r5, r5, #6
	add r2, r0, #0
	add r5, r1, r5
_021E6D78:
	lsl r6, r2, #1
	add r4, r4, #1
	add r2, r2, #1
	lsl r4, r4, #0x10
	lsl r2, r2, #0x18
	lsr r4, r4, #0x10
	add r6, r5, r6
	lsr r2, r2, #0x18
	strh r4, [r6, #8]
	cmp r2, #0x18
	blo _021E6D78
	add r2, r3, #1
	lsl r2, r2, #0x18
	lsr r3, r2, #0x18
	cmp r3, #8
	blo _021E6D6E
	lsl r1, r7, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov51_021E6D44
