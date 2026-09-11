	.include "asm/macros.inc"
	.include "overlay_113.inc"
	.include "asm/include/overlay_113_split.inc"
	.include "global.inc"

	.text
	.public UnownReport_Exit
	.public ov113_021E59F8
	.public ov113_021E5A48
	.public ov113_021E5B60
	.public ov113_021E5B70
	.public ov113_021E5BB0
	.public ov113_021E5C60
	.public ov113_021E5CF8
	.public ov113_021E5D28
	.public ov113_021E5D4C
	.public ov113_021E5EC4
	.public ov113_021E6274
	.public ov113_021E629C
	.public ov113_021E62E0
	.public ov113_021E64DC
	.public ov113_021E663C
	.public ov113_021E66E4
	.public ov113_021E6754
	.public ov113_021E6930
	.public ov113_021E6988
	.public ov113_021E69A8

	thumb_func_start ov113_021E6680
ov113_021E6680: ; 0x021E6680
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4]
	mov r0, #4
	bl FontID_Alloc
	ldr r3, [r4]
	mov r0, #0
	mov r1, #0x1b
	mov r2, #1
	bl NewMsgDataFromNarc
	str r0, [r4, #0x44]
	mov r0, #0x10
	ldr r2, [r4]
	add r1, r0, #0
	bl MessageFormat_New_Custom
	str r0, [r4, #0x48]
	mov r0, #2
	ldr r1, [r4]
	lsl r0, r0, #8
	bl String_New
	str r0, [r4, #0x4c]
	mov r0, #2
	ldr r1, [r4]
	lsl r0, r0, #8
	bl String_New
	str r0, [r4, #0x50]
	ldr r0, [r4, #0x44]
	mov r1, #0
	bl NewString_ReadMsgData
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x44]
	mov r1, #5
	bl NewString_ReadMsgData
	str r0, [r4, #0x58]
	ldr r0, [r4, #4]
	ldr r0, [r0, #4]
	bl Save_PlayerData_GetProfile
	ldr r1, [r4]
	bl PlayerProfile_GetPlayerName_NewString
	str r0, [r4, #0x5c]
	pop {r4, pc}
	thumb_func_end ov113_021E6680

