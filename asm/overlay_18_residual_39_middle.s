	.include "asm/macros.inc"
	.include "overlay_18.inc"
	.include "global.inc"

	.extern ov18_021E590C
	.extern ov18_021E595C
	.extern ov18_021E59A8
	.extern ov18_021F95FC
	.extern ov18_021F9648
	.extern ov18_021FBDB4

	.text

	thumb_func_start ov18_021F8CCC
ov18_021F8CCC: ; 0x021F8CCC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r4, r5, #0
	ldr r6, _021F8F04 ; =ov18_021FBDB4
	mov r7, #0
	add r4, #0x24
_021F8CDA:
	ldr r0, [r5]
	add r1, r4, #0
	add r2, r6, #0
	bl AddWindow
	add r0, r4, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r7, r7, #1
	add r6, #8
	add r4, #0x10
	cmp r7, #9
	blo _021F8CDA
	ldr r2, _021F8F08 ; =0x00000322
	ldr r3, [r5, #0x14]
	mov r0, #0
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	add r4, r0, #0
	ldr r0, [r5, #0x14]
	bl MessageFormat_New
	add r6, r0, #0
	mov r0, #1
	ldr r1, [r5, #0x14]
	lsl r0, r0, #0xa
	bl String_New
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _021F8F0C ; =0x00020100
	add r1, r4, #0
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r0, #0x24
	mov r2, #0x90
	mov r3, #0x70
	bl ov18_021F9648
	mov r1, #0x91
	lsl r1, r1, #2
	ldr r0, [r5, #0x10]
	ldr r1, [r5, r1]
	bl Pokedex_ConvertToCurrentDexNo
	add r2, r0, #0
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r6, #0
	mov r1, #0
	mov r3, #3
	bl BufferIntegerAsString
	add r0, r4, #0
	mov r1, #9
	bl NewString_ReadMsgData
	add r7, r0, #0
	ldr r1, [sp, #0x10]
	add r0, r6, #0
	add r2, r7, #0
	bl StringExpandPlaceholders
	mov r0, #4
	str r0, [sp]
	ldr r0, _021F8F0C ; =0x00020100
	ldr r1, [sp, #0x10]
	str r0, [sp, #4]
	add r0, r5, #0
	mov r3, #0
	add r0, #0x34
	mov r2, #1
	str r3, [sp, #8]
	bl ov18_021F95FC
	add r0, r7, #0
	bl String_Delete
	mov r0, #0x91
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r2, [r5, #0x14]
	mov r1, #2
	bl ov18_021E590C
	add r7, r0, #0
	mov r0, #4
	str r0, [sp]
	ldr r0, _021F8F0C ; =0x00020100
	mov r2, #0
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0x44
	add r1, r7, #0
	add r3, r2, #0
	str r2, [sp, #8]
	bl ov18_021F95FC
	add r0, r7, #0
	bl String_Delete
	mov r0, #0x91
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r2, [r5, #0x14]
	mov r1, #2
	bl ov18_021E595C
	add r7, r0, #0
	add r0, r5, #0
	add r0, #0x54
	bl GetWindowWidth
	lsl r0, r0, #3
	sub r2, r0, #4
	mov r0, #4
	str r0, [sp]
	ldr r0, _021F8F0C ; =0x00020100
	add r1, r7, #0
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x54
	mov r3, #0
	bl ov18_021F95FC
	add r0, r7, #0
	bl String_Delete
	mov r0, #0x91
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r3, [r5, #0x14]
	mov r1, #2
	mov r2, #0
	bl ov18_021E59A8
	add r7, r0, #0
	add r0, r5, #0
	add r0, #0x64
	bl GetWindowWidth
	str r0, [sp, #0x14]
	mov r0, #0
	add r1, r7, #0
	add r2, r0, #0
	bl FontID_String_GetWidthMultiline
	ldr r1, [sp, #0x14]
	mov r3, #0
	lsl r1, r1, #3
	sub r0, r1, r0
	lsr r2, r0, #1
	ldr r0, _021F8F0C ; =0x00020100
	str r3, [sp]
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0x64
	add r1, r7, #0
	str r3, [sp, #8]
	bl ov18_021F95FC
	add r0, r7, #0
	bl String_Delete
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021F8F0C ; =0x00020100
	add r1, r4, #0
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r0, #0x74
	mov r2, #0xa
	mov r3, #0x14
	bl ov18_021F9648
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021F8F0C ; =0x00020100
	add r1, r4, #0
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r0, #0x94
	mov r2, #0xb
	mov r3, #0x14
	bl ov18_021F9648
	add r0, r6, #0
	bl MessageFormat_Delete
	add r0, r4, #0
	bl DestroyMsgData
	bl GetDexHeightMsgBank
	add r2, r0, #0
	ldr r3, [r5, #0x14]
	mov r0, #0
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	mov r1, #0
	add r4, r0, #0
	str r1, [sp]
	mov r2, #0x91
	ldr r0, _021F8F0C ; =0x00020100
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	lsl r2, r2, #2
	add r0, r5, #0
	ldr r2, [r5, r2]
	add r0, #0x84
	add r1, r4, #0
	mov r3, #4
	bl ov18_021F9648
	add r0, r4, #0
	bl DestroyMsgData
	bl GetDexWeightMsgBank
	add r2, r0, #0
	ldr r3, [r5, #0x14]
	mov r0, #0
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	mov r1, #0
	add r4, r0, #0
	str r1, [sp]
	mov r2, #0x91
	ldr r0, _021F8F0C ; =0x00020100
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	lsl r2, r2, #2
	add r0, r5, #0
	ldr r2, [r5, r2]
	add r0, #0xa4
	add r1, r4, #0
	mov r3, #4
	bl ov18_021F9648
	add r0, r4, #0
	bl DestroyMsgData
	ldr r0, [sp, #0x10]
	bl String_Delete
	mov r4, #0
	add r5, #0x24
_021F8EF2:
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #9
	blo _021F8EF2
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F8F04: .word ov18_021FBDB4
_021F8F08: .word 0x00000322
_021F8F0C: .word 0x00020100
	thumb_func_end ov18_021F8CCC
