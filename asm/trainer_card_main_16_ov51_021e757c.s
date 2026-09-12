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

	thumb_func_start ov51_021E757C
ov51_021E757C: ; 0x021E757C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r1, #0
	add r7, r0, #0
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _021E758E
	bl GF_AssertFail
_021E758E:
	ldr r0, [r5, #0x18]
	bl GetIGTHours
	mov r0, #0x28
	str r0, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	add r0, r7, #0
	mov r1, #0
	add r0, #0x50
	mov r2, #0xb8
	add r3, r1, #0
	bl FillWindowPixelRect
	ldr r2, _021E765C ; =0x000002D7
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x19
	bl NewMsgDataFromNarc
	str r0, [sp, #0x10]
	mov r0, #0x20
	mov r1, #0x19
	bl String_New
	add r4, r0, #0
	mov r0, #0x20
	mov r1, #0x19
	bl String_New
	str r0, [sp, #0x14]
	mov r0, #2
	mov r1, #0x20
	mov r2, #0x19
	bl MessageFormat_New_Custom
	add r6, r0, #0
	ldr r0, [r5, #0x18]
	bl GetIGTHours
	add r2, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r6, #0
	mov r1, #0
	mov r3, #3
	bl BufferIntegerAsString
	ldr r0, [r5, #0x18]
	bl GetIGTMinutes
	mov r3, #2
	add r2, r0, #0
	str r3, [sp]
	mov r1, #1
	add r0, r6, #0
	str r1, [sp, #4]
	bl BufferIntegerAsString
	ldr r0, [sp, #0x10]
	ldr r2, [sp, #0x14]
	mov r1, #0x15
	bl ReadMsgDataIntoString
	ldr r2, [sp, #0x14]
	add r0, r6, #0
	add r1, r4, #0
	bl StringExpandPlaceholders
	mov r0, #0
	add r1, r4, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0xe0
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E7660 ; =0x00010200
	str r1, [sp, #4]
	str r0, [sp, #8]
	add r7, #0x50
	add r0, r7, #0
	add r2, r4, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x10]
	bl DestroyMsgData
	add r0, r4, #0
	bl String_Delete
	ldr r0, [sp, #0x14]
	bl String_Delete
	add r0, r6, #0
	bl MessageFormat_Delete
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E765C: .word 0x000002D7
_021E7660: .word 0x00010200
	thumb_func_end ov51_021E757C
