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

	thumb_func_start ov51_021E6E60
ov51_021E6E60: ; 0x021E6E60
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r7, _021E6EE4 ; =ov51_021E7F48
	mov r4, #0
	add r6, r5, #4
_021E6E6C:
	lsl r1, r4, #4
	lsl r2, r4, #3
	ldr r0, [r5]
	add r1, r6, r1
	add r2, r7, r2
	bl AddWindow
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #0xe
	blo _021E6E6C
	mov r2, #0
	str r2, [sp]
	ldr r0, [r5]
	mov r1, #7
	mov r3, #1
	bl BG_FillCharDataRange
	mov r2, #0
	str r2, [sp]
	ldr r0, [r5]
	mov r1, #4
	mov r3, #1
	bl BG_FillCharDataRange
	ldr r0, _021E6EE8 ; =0x0000343D
	ldr r2, _021E6EEC ; =0x000003E1
	ldrb r0, [r5, r0]
	mov r1, #4
	mov r3, #0xd
	str r0, [sp]
	mov r0, #0x19
	str r0, [sp, #4]
	ldr r0, [r5]
	bl LoadUserFrameGfx2
	mov r1, #7
	mov r0, #4
	lsl r1, r1, #6
	mov r2, #0x19
	bl LoadFontPal0
	mov r0, #0x19
	bl YesNoPrompt_Create
	mov r1, #0xcf
	lsl r1, r1, #6
	str r0, [r5, r1]
	ldr r0, [r5]
	mov r1, #7
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, [r5]
	mov r1, #4
	bl ScheduleBgTilemapBufferTransfer
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6EE4: .word ov51_021E7F48
_021E6EE8: .word 0x0000343D
_021E6EEC: .word 0x000003E1
	thumb_func_end ov51_021E6E60

	thumb_func_start ov51_021E6EF0
ov51_021E6EF0: ; 0x021E6EF0
	push {r3, r4, r5, lr}
	add r4, r0, #0
	mov r0, #0xcf
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl YesNoPrompt_Destroy
	mov r5, #0
	add r4, r4, #4
_021E6F02:
	lsl r0, r5, #4
	add r0, r4, r0
	bl RemoveWindow
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #0xe
	blo _021E6F02
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov51_021E6EF0

	thumb_func_start ov51_021E6F18
ov51_021E6F18: ; 0x021E6F18
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r7, r0, #0
	ldr r0, _021E71BC ; =0x000033C4
	add r6, r1, #0
	ldr r0, [r7, r0]
	add r5, r2, #0
	str r0, [sp, #0x20]
	mov r4, #0
_021E6F2A:
	lsl r0, r4, #4
	str r0, [sp, #0x24]
	add r0, r6, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	cmp r4, #3
	bne _021E6F44
	bne _021E6F68
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1f
	beq _021E6F68
_021E6F44:
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E71C0 ; =0x00010200
	lsl r2, r4, #2
	str r0, [sp, #8]
	mov r0, #0
	add r3, r7, r2
	str r0, [sp, #0xc]
	ldr r2, _021E71C4 ; =0x000033EC
	ldr r0, [sp, #0x24]
	mov r1, #0
	ldr r2, [r3, r2]
	add r0, r6, r0
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
_021E6F68:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #7
	blo _021E6F2A
	mov r0, #0x20
	mov r1, #0x19
	bl String_New
	str r0, [sp, #0x1c]
	ldr r0, _021E71C8 ; =0x000033D0
	mov r1, #0x20
	ldr r0, [r7, r0]
	mov r2, #0x19
	str r0, [sp, #0x18]
	mov r0, #6
	bl MessageFormat_New_Custom
	add r4, r0, #0
	ldr r0, _021E71CC ; =0x000033D4
	mov r2, #0
	ldr r0, [r7, r0]
	mov r1, #0x60
	str r0, [sp, #0x14]
	str r0, [sp]
	ldrh r0, [r5, #0x28]
	add r3, r2, #0
	str r0, [sp, #4]
	mov r0, #5
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r0, #0xff
	str r0, [sp, #0x10]
	add r0, r6, #0
	bl ov51_021E74F4
	ldr r0, _021E71C8 ; =0x000033D0
	add r1, r5, #0
	ldr r0, [r7, r0]
	add r1, #8
	bl CopyU16ArrayToString
	ldr r0, _021E71C8 ; =0x000033D0
	mov r2, #0
	ldr r0, [r7, r0]
	mov r1, #0x68
	str r0, [sp]
	add r0, r6, #0
	add r0, #0x10
	add r3, r2, #0
	bl ov51_021E7540
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r2, [r5, #0x1c]
	add r0, r4, #0
	mov r1, #5
	mov r3, #6
	bl BufferIntegerAsString
	ldr r0, [sp, #0x20]
	ldr r2, [sp, #0x1c]
	mov r1, #0x13
	bl ReadMsgDataIntoString
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0x1c]
	add r0, r4, #0
	bl StringExpandPlaceholders
	mov r0, #0
	ldr r1, [sp, #0x18]
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0x88
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E71C0 ; =0x00010200
	ldr r2, [sp, #0x18]
	str r0, [sp, #8]
	add r0, r6, #0
	add r0, #0x20
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1f
	beq _021E7076
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r2, [r5, #0x20]
	add r0, r4, #0
	mov r1, #5
	mov r3, #3
	bl BufferIntegerAsString
	ldr r0, [sp, #0x20]
	ldr r2, [sp, #0x1c]
	mov r1, #0x1a
	bl ReadMsgDataIntoString
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0x1c]
	add r0, r4, #0
	bl StringExpandPlaceholders
	mov r0, #0
	ldr r1, [sp, #0x18]
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0x88
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E71C0 ; =0x00010200
	ldr r2, [sp, #0x18]
	str r0, [sp, #8]
	add r0, r6, #0
	add r0, #0x30
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
_021E7076:
	ldr r0, [sp, #0x14]
	mov r2, #0
	str r0, [sp]
	ldr r0, [r5, #0x24]
	mov r1, #0x88
	str r0, [sp, #4]
	mov r0, #9
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	mov r0, #0xff
	str r0, [sp, #0x10]
	add r0, r6, #0
	add r0, #0x40
	add r3, r2, #0
	bl ov51_021E74F4
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	beq _021E70DA
	ldr r0, [r5, #0x18]
	bl GetIGTHours
	add r2, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0
	mov r3, #3
	bl BufferIntegerAsString
	ldr r0, [r5, #0x18]
	bl GetIGTMinutes
	mov r3, #2
	add r2, r0, #0
	str r3, [sp]
	mov r1, #1
	add r0, r4, #0
	str r1, [sp, #4]
	bl BufferIntegerAsString
	ldr r0, [sp, #0x20]
	ldr r2, [sp, #0x1c]
	mov r1, #0x15
	bl ReadMsgDataIntoString
	b _021E710A
_021E70DA:
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldrh r2, [r5, #0x2a]
	add r0, r4, #0
	mov r1, #0
	mov r3, #3
	bl BufferIntegerAsString
	mov r3, #2
	add r2, r5, #0
	str r3, [sp]
	mov r1, #1
	str r1, [sp, #4]
	add r2, #0x2e
	ldrb r2, [r2]
	add r0, r4, #0
	bl BufferIntegerAsString
	ldr r0, [sp, #0x20]
	ldr r2, [sp, #0x1c]
	mov r1, #0x14
	bl ReadMsgDataIntoString
_021E710A:
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0x1c]
	add r0, r4, #0
	bl StringExpandPlaceholders
	mov r0, #0
	ldr r1, [sp, #0x18]
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0xe0
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E71C0 ; =0x00010200
	ldr r2, [sp, #0x18]
	str r0, [sp, #8]
	add r0, r6, #0
	add r0, #0x50
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	mov r1, #2
	add r2, r5, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r2, #0x2f
	ldrb r2, [r2]
	add r0, r4, #0
	add r3, r1, #0
	bl BufferIntegerAsString
	add r2, r5, #0
	add r2, #0x30
	ldrb r2, [r2]
	add r0, r4, #0
	mov r1, #3
	bl BufferMonthNameAbbr
	mov r3, #2
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r5, #0x31
	ldrb r2, [r5]
	add r0, r4, #0
	mov r1, #4
	bl BufferIntegerAsString
	ldr r0, [sp, #0x20]
	ldr r2, [sp, #0x1c]
	mov r1, #0x16
	bl ReadMsgDataIntoString
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0x1c]
	add r0, r4, #0
	bl StringExpandPlaceholders
	mov r0, #0
	ldr r1, [sp, #0x18]
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0xe0
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E71C0 ; =0x00010200
	add r6, #0x60
	str r0, [sp, #8]
	ldr r2, [sp, #0x18]
	add r0, r6, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x1c]
	bl String_Delete
	add r0, r4, #0
	bl MessageFormat_Delete
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E71BC: .word 0x000033C4
_021E71C0: .word 0x00010200
_021E71C4: .word 0x000033EC
_021E71C8: .word 0x000033D0
_021E71CC: .word 0x000033D4
	thumb_func_end ov51_021E6F18
