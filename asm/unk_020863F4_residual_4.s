#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_020863F4.inc"
	.include "global.inc"

	.public gOverlayTemplate_Battle
	.public gNatureStatMods

	.text
	.public _021027C8
	.public _021027DC
	.public _021027F4
	.public sub_020863F4
	.public sub_02086490
	.public sub_020866CC
	.public sub_02086758
	.public sub_020868A0
	.public sub_020869BC
	.public sub_02086AB4
	.public sub_02086AE4
	.public sub_02086B2C
	.public sub_02086B6C
	.public sub_02086BB4
	.public sub_02086C80
	.public sub_02086C8C
	.public sub_02086D98
	.public sub_02086DA4
	.public sub_02086DE4
	.public sub_02086F44
	.public sub_02086FCC
	.public sub_02086FE8
	.public sub_02087028
	.public sub_02087064
	.public sub_02087090
	.public sub_020871C4
	.public sub_02087230

	thumb_func_start sub_02087090
sub_02087090: ; 0x02087090
	push {r4, r5, r6, r7, lr}
	sub sp, #0x5c
	add r5, r0, #0
	add r4, r1, #0
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0x26
	mov r3, #0x6c
	bl NewMsgDataFromNarc
	add r1, r4, #2
	str r0, [sp, #0x14]
	bl NewString_ReadMsgData
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	bl InitWindow
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0xbe
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, sp, #0x1c
	mov r2, #0xa
	mov r3, #2
	bl AddTextWindowTopLeftCorner
	ldr r1, [sp, #0x18]
	mov r0, #2
	mov r2, #0
	mov r3, #0x50
	bl FontID_String_GetCenterAlignmentX
	mov r1, #0
	add r3, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _020871BC ; =0x000F0D02
	ldr r2, [sp, #0x18]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, sp, #0x1c
	mov r1, #2
	bl AddTextPrinterParameterizedWithColor
	add r0, sp, #0x1c
	mov r1, #1
	mov r2, #0x6c
	bl sub_02013688
	mov r3, #0xe1
	lsl r3, r3, #2
	mov r1, #0xc
	add r6, r4, #0
	mul r6, r1
	mov r1, #1
	add r3, r5, r3
	add r2, r1, #0
	add r3, r3, r6
	bl sub_02021AC8
	add r0, r4, #0
	add r0, #0x1a
	lsl r0, r0, #2
	add r3, r5, r0
	ldr r0, _020871C0 ; =0x00000306
	add r2, r0, #1
	ldrb r1, [r3, r0]
	ldrb r2, [r3, r2]
	add r2, r1, r2
	lsr r1, r2, #0x1f
	add r1, r2, r1
	lsl r1, r1, #0xf
	asr r7, r1, #0x10
	sub r1, r0, #2
	ldrb r2, [r3, r1]
	sub r1, r0, #1
	ldrb r1, [r3, r1]
	add r2, r2, r1
	lsr r1, r2, #0x1f
	add r1, r2, r1
	lsl r1, r1, #0xf
	asr r1, r1, #0x10
	str r1, [sp, #0x10]
	add r1, r0, #0
	add r1, #0x72
	ldr r1, [r5, r1]
	sub r0, #0x12
	str r1, [sp, #0x2c]
	add r1, sp, #0x1c
	str r1, [sp, #0x30]
	ldr r0, [r5, r0]
	bl SpriteManager_GetSpriteList
	mov r1, #0xbd
	lsl r1, r1, #2
	str r0, [sp, #0x34]
	ldr r0, [r5, r1]
	add r1, #0xf7
	bl SpriteManager_FindPlttResourceProxy
	str r0, [sp, #0x38]
	mov r1, #0
	mov r0, #0xe2
	str r1, [sp, #0x3c]
	add r2, r5, r6
	lsl r0, r0, #2
	ldr r2, [r2, r0]
	sub r0, #0xc
	add r5, r5, r0
	sub r7, #0x28
	str r2, [sp, #0x40]
	lsl r2, r7, #0x10
	asr r2, r2, #0x10
	str r2, [sp, #0x44]
	ldr r2, [sp, #0x10]
	lsl r4, r4, #2
	sub r2, r2, #7
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	str r1, [sp, #0x4c]
	str r1, [sp, #0x50]
	mov r1, #1
	str r1, [sp, #0x54]
	mov r1, #0x6c
	str r2, [sp, #0x48]
	str r1, [sp, #0x58]
	add r0, sp, #0x2c
	bl sub_020135D8
	str r0, [r5, r4]
	ldr r0, [r5, r4]
	ldr r1, [sp, #0x70]
	bl sub_020138E0
	ldr r0, [sp, #0x18]
	bl String_Delete
	ldr r0, [sp, #0x14]
	bl DestroyMsgData
	add r0, sp, #0x1c
	bl RemoveWindow
	add sp, #0x5c
	pop {r4, r5, r6, r7, pc}
	nop
_020871BC: .word 0x000F0D02
_020871C0: .word 0x00000306
	thumb_func_end sub_02087090
