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

	thumb_func_start ov51_021E6C00
ov51_021E6C00: ; 0x021E6C00
	push {r4, lr}
	sub sp, #0x18
	mov r0, #1
	lsl r0, r0, #0xc
	bl FX_Inv
	add r4, r0, #0
	mov r0, #1
	lsl r0, r0, #0xc
	bl FX_Inv
	mov r1, #0
	str r4, [sp, #8]
	str r1, [sp, #0xc]
	str r1, [sp, #0x10]
	str r0, [sp, #0x14]
	bl OS_WaitVBlankIntr
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6C60 ; =0x04001020
	add r1, sp, #8
	mov r2, #0x80
	mov r3, #0x60
	bl G2x_SetBGyAffine_
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6C64 ; =0x04001030
	add r1, sp, #8
	mov r2, #0x80
	mov r3, #0x60
	bl G2x_SetBGyAffine_
	bl OS_WaitVBlankIntr
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6C68 ; =0x04000030
	add r1, sp, #8
	mov r2, #0x80
	str r3, [sp, #4]
	bl G2x_SetBGyAffine_
	add sp, #0x18
	pop {r4, pc}
	.balign 4, 0
_021E6C60: .word 0x04001020
_021E6C64: .word 0x04001030
_021E6C68: .word 0x04000030
	thumb_func_end ov51_021E6C00

	thumb_func_start ov51_021E6C6C
ov51_021E6C6C: ; 0x021E6C6C
	push {r3, r4, lr}
	sub sp, #0x1c
	add r4, r0, #0
	ldr r0, _021E6CC4 ; =0x000030F0
	mov r1, #7
	ldr r3, [r4, r0]
	mov r0, #0
	str r0, [sp]
	ldr r2, [r3, #0x14]
	ldr r0, [r4]
	ldr r3, [r3, #0x10]
	bl BG_LoadCharTilesData
	ldr r0, _021E6CC8 ; =0x000033B4
	mov r1, #0xa
	ldr r0, [r4, r0]
	mov r2, #0x15
	str r1, [sp]
	mov r1, #0xb
	str r1, [sp, #4]
	add r1, r0, #0
	add r1, #0xc
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	mov r3, #5
	str r3, [sp, #0x10]
	ldrh r1, [r0]
	lsl r1, r1, #0x15
	lsr r1, r1, #0x18
	str r1, [sp, #0x14]
	ldrh r0, [r0, #2]
	mov r1, #7
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r4]
	bl CopyToBgTilemapRect
	ldr r0, [r4]
	mov r1, #7
	bl BgCommitTilemapBufferToVram
	add sp, #0x1c
	pop {r3, r4, pc}
	.balign 4, 0
_021E6CC4: .word 0x000030F0
_021E6CC8: .word 0x000033B4
	thumb_func_end ov51_021E6C6C
