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

	thumb_func_start ov51_021E7208
ov51_021E7208: ; 0x021E7208
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r1, #0
	ldr r1, _021E74C4 ; =0x000033C4
	str r0, [sp, #0x14]
	ldr r0, [r0, r1]
	str r2, [sp, #0x18]
	str r0, [sp, #0x1c]
	mov r4, #7
	mov r6, #0
_021E721C:
	lsl r7, r4, #4
	add r0, r5, r7
	mov r1, #0
	bl FillWindowPixelBuffer
	str r6, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E74C8 ; =0x00010200
	ldr r2, [sp, #0x14]
	str r0, [sp, #8]
	lsl r3, r4, #2
	add r3, r2, r3
	ldr r2, _021E74CC ; =0x000033EC
	str r6, [sp, #0xc]
	ldr r2, [r3, r2]
	add r0, r5, r7
	add r1, r6, #0
	add r3, r6, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #0xb
	blo _021E721C
	mov r0, #0x20
	mov r1, #0x19
	bl String_New
	add r7, r0, #0
	ldr r1, _021E74D0 ; =0x000033D0
	ldr r0, [sp, #0x14]
	mov r2, #0x19
	ldr r4, [r0, r1]
	mov r0, #6
	mov r1, #0x20
	bl MessageFormat_New_Custom
	ldr r1, [sp, #0x18]
	add r6, r0, #0
	add r1, #0x33
	ldrb r1, [r1]
	cmp r1, #0
	beq _021E72EC
	mov r1, #2
	str r1, [sp]
	mov r2, #1
	str r2, [sp, #4]
	ldr r2, [sp, #0x18]
	add r3, r1, #0
	add r2, #0x32
	ldrb r2, [r2]
	bl BufferIntegerAsString
	ldr r2, [sp, #0x18]
	add r0, r6, #0
	add r2, #0x33
	ldrb r2, [r2]
	mov r1, #3
	bl BufferMonthNameAbbr
	mov r3, #2
	ldr r2, [sp, #0x18]
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r2, #0x34
	ldrb r2, [r2]
	add r0, r6, #0
	mov r1, #4
	bl BufferIntegerAsString
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r2, [sp, #0x18]
	add r0, r6, #0
	ldrh r2, [r2, #0x2c]
	mov r1, #0
	mov r3, #3
	bl BufferIntegerAsString
	mov r3, #2
	ldr r2, [sp, #0x18]
	str r3, [sp]
	mov r1, #1
	str r1, [sp, #4]
	add r2, #0x35
	ldrb r2, [r2]
	add r0, r6, #0
	bl BufferIntegerAsString
	ldr r0, [sp, #0x1c]
	mov r1, #0x16
	add r2, r7, #0
	bl ReadMsgDataIntoString
	add r0, r6, #0
	add r1, r4, #0
	add r2, r7, #0
	bl StringExpandPlaceholders
	b _021E7324
_021E72EC:
	ldr r0, [sp, #0x1c]
	mov r1, #0xc
	add r2, r7, #0
	bl ReadMsgDataIntoString
	mov r1, #0
	str r1, [sp]
	mov r0, #2
	str r0, [sp, #4]
	add r0, r6, #0
	add r2, r7, #0
	add r3, r1, #0
	bl BufferString
	mov r3, #0
	str r3, [sp]
	mov r0, #2
	str r0, [sp, #4]
	add r0, r6, #0
	mov r1, #1
	add r2, r7, #0
	bl BufferString
	ldr r0, [sp, #0x1c]
	mov r1, #0x19
	add r2, r4, #0
	bl ReadMsgDataIntoString
_021E7324:
	mov r0, #0
	add r1, r4, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0xe0
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E74C8 ; =0x00010200
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x70
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x1c]
	mov r1, #0x14
	add r2, r7, #0
	bl ReadMsgDataIntoString
	add r0, r6, #0
	add r1, r4, #0
	add r2, r7, #0
	bl StringExpandPlaceholders
	mov r0, #0
	add r1, r4, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0xe0
	sub r3, r1, r0
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E74C8 ; =0x00010200
	mov r1, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x70
	add r2, r4, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r2, [sp, #0x18]
	add r0, r6, #0
	ldr r2, [r2, #0x38]
	mov r1, #5
	mov r3, #6
	bl BufferIntegerAsString
	ldr r0, [sp, #0x1c]
	mov r1, #0x1b
	add r2, r7, #0
	bl ReadMsgDataIntoString
	add r0, r6, #0
	add r1, r4, #0
	add r2, r7, #0
	bl StringExpandPlaceholders
	mov r0, #0
	add r1, r4, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0xe0
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E74C8 ; =0x00010200
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x80
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x1c]
	mov r1, #0x17
	add r2, r4, #0
	bl ReadMsgDataIntoString
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E74C8 ; =0x00010200
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x90
	mov r3, #0x70
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	mov r2, #0
	ldr r0, [sp, #0x18]
	str r4, [sp]
	ldr r0, [r0, #0x40]
	mov r1, #0xe0
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	mov r0, #0xff
	str r0, [sp, #0x10]
	add r0, r5, #0
	add r0, #0x90
	add r3, r2, #0
	bl ov51_021E74F4
	ldr r0, [sp, #0x1c]
	mov r1, #0x18
	add r2, r4, #0
	bl ReadMsgDataIntoString
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E74C8 ; =0x00010200
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x90
	mov r3, #0xb0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x18]
	str r4, [sp]
	ldr r0, [r0, #0x3c]
	mov r1, #0xe0
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	mov r0, #0xff
	str r0, [sp, #0x10]
	add r0, r5, #0
	add r0, #0x90
	mov r2, #0x40
	mov r3, #0
	bl ov51_021E74F4
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r2, [sp, #0x18]
	add r0, r6, #0
	ldr r2, [r2, #0x44]
	mov r1, #5
	mov r3, #6
	bl BufferIntegerAsString
	ldr r0, [sp, #0x1c]
	mov r1, #0x1b
	add r2, r7, #0
	bl ReadMsgDataIntoString
	add r0, r6, #0
	add r1, r4, #0
	add r2, r7, #0
	bl StringExpandPlaceholders
	mov r0, #0
	add r1, r4, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0xe0
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E74C8 ; =0x00010200
	add r5, #0xa0
	str r0, [sp, #8]
	add r0, r5, #0
	add r2, r4, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl MessageFormat_Delete
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E74C4: .word 0x000033C4
_021E74C8: .word 0x00010200
_021E74CC: .word 0x000033EC
_021E74D0: .word 0x000033D0
	thumb_func_end ov51_021E7208
