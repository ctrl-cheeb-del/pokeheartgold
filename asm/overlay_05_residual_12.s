	.include "asm/macros.inc"
	.public ov05_0221BA00
	.public ov05_0221BA70
	.public ov05_0221BB00
	.public ov05_0221BB30
	.public ov05_0221BD28
	.public ov05_0221BE04
	.public ov05_0221BE80
	.public ov05_0221BF08
	.public ov05_0221C018
	.public ov05_0221C050
	.public ov05_0221C21C
	.public ov05_0221C430
	.public ov05_0221C558
	.public ov05_0221C568
	.public ov05_0221C5A8
	.public ov05_0221C5C4
	.public ov05_0221C6C8
	.public ov05_0221C7FC
	.public ov05_0221C80C
	.public ov05_0221C8A0
	.public ov05_0221C8E0
	.public ov05_0221C908
	.public ov05_0221CAB8
	.public ov05_0221CB70
	.public ov05_0221CC04
	.public ov05_0221CC58
	.public ov05_0221CC74
	.public ov05_0221CCF4
	.public ov05_0221CD24
	.public ov05_0221CDC4
	.public ov05_0221CE0C
	.public ov05_0221CE50
	.public ov05_0221CE88
	.public ov05_0221CEB8
	.public ov05_0221CFF0
	.public ov05_0221D020
	.public ov05_0221D054
	.public ov05_0221D094
	.public ov05_0221D140
	.public ov05_0221D228
	.public ov05_0221D240
	.public ov05_0221D318
	.public ov05_0221D3AC
	.public ov05_0221D414
	.public ov05_0221D4D0
	.public ov05_0221D530
	.public ov05_0221D5DC
	.public ov05_0221D664
	.public ov05_0221D690
	.public ov05_0221D6C4
	.public ov05_0221D7AC
	.public ov05_0221D890
	.public ov05_0221D904
	.public ov05_0221D9F0
	.public ov05_0221DAE0
	.public ov05_0221DB18
	.public ov05_0221DB4C
	.public ov05_0221DB70
	.public ov05_0221DB94
	.public ov05_0221DC34
	.public ov05_0221DC60
	.public ov05_0221DD08
	.public ov05_0221DDEC
	.public ov05_0221DE38
	.public ov05_0221DE6C
	.public ov05_0221DF38
	.public ov05_0221E07C
	.public ov05_0221E0A8
	.public ov05_0221E110
	.public ov05_0221E274
	.public ov05_0221E2D8
	.public ov05_0221E390
	.public ov05_0221E42C
	.public ov05_0221E4C8
	.public ov05_0221E564
	.public ov05_0221E5E4
	.public ov05_0221E60C
	.public ov05_0221E624
	.public ov05_0221E714
	.public ov05_0221E74C
	.public ov05_0221E7B8
	.public ov05_0221E8A8
	.public ov05_0221E944
	.public ov05_0221E9C4
	.public ov05_0221E9F8
	.public ov05_0221EA18
	.public ov05_0221EA38
	.public _0221EA54
	.public ov05_0221EA58
	.public ov05_0221EA60
	.public ov05_0221EA6C
	.public ov05_0221EA6D
	.public ov05_0221EA78
	.public ov05_0221EA88
	.public ov05_0221EA98
	.public ov05_0221EAAC
	.public ov05_0221EAC0
	.public ov05_0221EAD4
	.public ov05_0221EAEC
	.public ov05_0221EB04
	.public ov05_0221EB1C
	.public ov05_0221EB38
	.public ov05_0221EB54
	.public ov05_0221EB70
	.public ov05_0221EB8C
	.public ov05_0221EBA8
	.public ov05_0221EBC4
	.public ov05_0221EBE0
	.public ov05_0221EC00
	.public ov05_0221EC28
	.public ov05_0221EC5C
	.public ov05_0221EC98
	.public ov05_0221ECE4
	.public ov05_0221EDA4
	.public ov05_0221EF2C
	.include "overlay_05.inc"
	.include "global.inc"

	.text

	thumb_func_start ov05_0221DC60
ov05_0221DC60: ; 0x0221DC60
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #0x15
	ldr r1, [r1, #0x24]
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	ldr r1, [r5]
	mov r3, #3
	ldr r1, [r1, #0x24]
	add r4, r0, #0
	str r1, [sp, #0xc]
	ldr r2, [r5, #0xc]
	mov r1, #0xf
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5]
	mov r1, #0x11
	ldr r0, [r0, #0x24]
	mov r3, #3
	str r0, [sp, #0xc]
	ldr r2, [r5, #0xc]
	add r0, r4, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	ldr r2, [r5]
	add r0, r4, #0
	ldr r2, [r2, #0x24]
	mov r1, #0x10
	bl NARC_AllocAndReadWholeMember
	add r1, sp, #0x10
	add r6, r0, #0
	bl NNS_G2dGetUnpackedPaletteData
	ldr r2, [sp, #0x10]
	mov r0, #3
	ldr r1, [r2, #0xc]
	ldr r2, [r2, #8]
	mov r3, #0
	lsl r2, r2, #0x10
	lsr r2, r2, #0x10
	bl BG_LoadPlttData
	ldr r1, [sp, #0x10]
	ldr r0, _0221DD00 ; =0x000004E4
	ldr r1, [r1, #0xc]
	add r0, r5, r0
	add r1, #0x60
	mov r2, #0x60
	bl memcpy
	add r0, r6, #0
	bl Heap_Free
	ldr r0, [r5]
	mov r2, #0xa9
	lsl r2, r2, #2
	ldr r3, _0221DD04 ; =0x00000424
	add r1, r5, r2
	add r2, #0xc0
	ldr r0, [r0, #0x24]
	add r2, r5, r2
	add r3, r5, r3
	bl sub_0207CAAC
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0221DD00: .word 0x000004E4
_0221DD04: .word 0x00000424
	thumb_func_end ov05_0221DC60


	thumb_func_start ov05_0221DD08
ov05_0221DD08: ; 0x0221DD08
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	ldr r6, _0221DDDC ; =ov05_0221EA60
	mov r4, #0
	add r7, r5, #0
_0221DD14:
	cmp r4, #0
	beq _0221DD1C
	cmp r4, #3
	bne _0221DD24
_0221DD1C:
	mov r0, #0xa9
	lsl r0, r0, #2
	add r1, r5, r0
	b _0221DD3A
_0221DD24:
	mov r0, #0x86
	lsl r0, r0, #2
	ldrh r0, [r7, r0]
	cmp r0, #0
	bne _0221DD34
	ldr r0, _0221DDE0 ; =0x00000424
	add r1, r5, r0
	b _0221DD3A
_0221DD34:
	mov r0, #0xd9
	lsl r0, r0, #2
	add r1, r5, r0
_0221DD3A:
	mov r0, #0x10
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0x10
	str r0, [sp, #0x14]
	mov r0, #6
	str r0, [sp, #0x18]
	ldrb r2, [r6]
	ldrb r3, [r6, #1]
	ldr r0, [r5, #0xc]
	mov r1, #2
	bl CopyToBgTilemapRect
	mov r0, #0x86
	lsl r0, r0, #2
	ldrh r0, [r7, r0]
	cmp r0, #0
	beq _0221DDC6
	mov r0, #0x10
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	add r0, r4, #3
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	ldrb r2, [r6]
	ldrb r3, [r6, #1]
	ldr r0, [r5, #0xc]
	mov r1, #2
	bl BgTilemapRectChangePalette
	cmp r4, #3
	bhs _0221DD92
	ldr r0, [r5]
	add r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	beq _0221DDA0
_0221DD92:
	cmp r4, #3
	blo _0221DDB4
	ldr r0, [r5]
	add r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0221DDB4
_0221DDA0:
	ldr r1, _0221DDE4 ; =0x00000504
	add r3, r4, #3
	lsl r3, r3, #0x15
	mov r0, #2
	add r1, r5, r1
	mov r2, #0x20
	lsr r3, r3, #0x10
	bl BG_LoadPlttData
	b _0221DDC6
_0221DDB4:
	ldr r1, _0221DDE8 ; =0x000004E4
	add r3, r4, #3
	lsl r3, r3, #0x15
	mov r0, #2
	add r1, r5, r1
	mov r2, #0x20
	lsr r3, r3, #0x10
	bl BG_LoadPlttData
_0221DDC6:
	add r4, r4, #1
	add r7, #0x18
	add r6, r6, #2
	cmp r4, #6
	blo _0221DD14
	ldr r0, [r5, #0xc]
	mov r1, #2
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221DDDC: .word ov05_0221EA60
_0221DDE0: .word 0x00000424
_0221DDE4: .word 0x00000504
_0221DDE8: .word 0x000004E4
	thumb_func_end ov05_0221DD08


	thumb_func_start ov05_0221DDEC
ov05_0221DDEC: ; 0x0221DDEC
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	ldr r0, [r4, #0xc]
	str r1, [sp]
	add r1, r2, #0
	bl GetBgTilemapBuffer
	add r6, r0, #0
	ldr r0, [r4]
	add r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0221DE0A
	mov r7, #0x10
	b _0221DE0C
_0221DE0A:
	mov r7, #0
_0221DE0C:
	mov r5, #0
_0221DE0E:
	lsl r0, r5, #5
	add r0, r7, r0
	lsl r4, r0, #1
	ldr r0, [sp]
	lsl r1, r5, #5
	add r0, r0, r1
	add r1, r6, r4
	mov r2, #0x20
	bl memcpy
	add r0, r6, r4
	mov r1, #0
	mov r2, #0x20
	bl memset
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #0x18
	blo _0221DE0E
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov05_0221DDEC


	thumb_func_start ov05_0221DE38
ov05_0221DE38: ; 0x0221DE38
	push {r4, lr}
	ldr r1, _0221DE64 ; =0x00000544
	add r4, r0, #0
	add r1, r4, r1
	mov r2, #1
	bl ov05_0221DDEC
	ldr r1, _0221DE68 ; =0x00000844
	add r0, r4, #0
	add r1, r4, r1
	mov r2, #2
	bl ov05_0221DDEC
	ldr r0, [r4, #0xc]
	mov r1, #1
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, [r4, #0xc]
	mov r1, #2
	bl ScheduleBgTilemapBufferTransfer
	pop {r4, pc}
	.balign 4, 0
_0221DE64: .word 0x00000544
_0221DE68: .word 0x00000844
	thumb_func_end ov05_0221DE38


	thumb_func_start ov05_0221DE6C
ov05_0221DE6C: ; 0x0221DE6C
	push {r3, r4, r5, r6, lr}
	sub sp, #0x1c
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	add r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0221DECC
	mov r0, #0x20
	sub r6, r0, r4
	ldr r1, _0221DF30 ; =0x00000544
	str r4, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	add r1, r5, r1
	str r1, [sp, #8]
	mov r3, #0
	str r3, [sp, #0xc]
	lsl r2, r6, #0x18
	str r3, [sp, #0x10]
	mov r1, #0x10
	str r1, [sp, #0x14]
	str r0, [sp, #0x18]
	ldr r0, [r5, #0xc]
	mov r1, #1
	lsr r2, r2, #0x18
	bl CopyToBgTilemapRect
	ldr r0, _0221DF34 ; =0x00000844
	lsl r2, r6, #0x18
	str r4, [sp]
	mov r1, #0x18
	str r1, [sp, #4]
	add r0, r5, r0
	str r0, [sp, #8]
	mov r3, #0
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	mov r0, #0x10
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r0, [r5, #0xc]
	mov r1, #2
	lsr r2, r2, #0x18
	bl CopyToBgTilemapRect
	b _0221DF1A
_0221DECC:
	ldr r2, _0221DF30 ; =0x00000544
	mov r0, #0x10
	str r4, [sp]
	mov r1, #0x18
	sub r6, r0, r4
	str r1, [sp, #4]
	add r2, r5, r2
	str r2, [sp, #8]
	lsl r2, r6, #0x18
	lsr r2, r2, #0x18
	str r2, [sp, #0xc]
	mov r2, #0
	str r2, [sp, #0x10]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r0, [r5, #0xc]
	mov r1, #1
	add r3, r2, #0
	bl CopyToBgTilemapRect
	ldr r1, _0221DF34 ; =0x00000844
	mov r2, #0
	str r4, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	add r1, r5, r1
	str r1, [sp, #8]
	lsl r1, r6, #0x18
	lsr r1, r1, #0x18
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	mov r1, #0x10
	str r1, [sp, #0x14]
	str r0, [sp, #0x18]
	ldr r0, [r5, #0xc]
	mov r1, #2
	add r3, r2, #0
	bl CopyToBgTilemapRect
_0221DF1A:
	ldr r0, [r5, #0xc]
	mov r1, #1
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, [r5, #0xc]
	mov r1, #2
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x1c
	pop {r3, r4, r5, r6, pc}
	nop
_0221DF30: .word 0x00000544
_0221DF34: .word 0x00000844
	thumb_func_end ov05_0221DE6C


	thumb_func_start ov05_0221DF38
ov05_0221DF38: ; 0x0221DF38
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r4, r0, #0
	add r0, r1, #0
	str r1, [sp]
	add r5, r2, #0
	bl Party_GetCount
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #8]
	mov r0, #0x18
	mul r0, r5
	add r0, r4, r0
	mov r6, #0
	str r0, [sp, #4]
_0221DF58:
	ldr r0, [sp, #8]
	cmp r0, r6
	bhi _0221DF7A
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	bl GetMonIconNaixEx
	mov r1, #0x18
	add r2, r6, #0
	mul r2, r1
	ldr r1, [sp, #4]
	add r2, r1, r2
	mov r1, #0x85
	lsl r1, r1, #2
	str r0, [r2, r1]
	b _0221E054
_0221DF7A:
	ldr r0, [sp]
	add r1, r6, #0
	bl Party_GetMonByIndex
	mov r1, #0x18
	add r2, r6, #0
	mul r2, r1
	ldr r1, [sp, #4]
	add r4, r0, #0
	add r7, r1, r2
	bl Pokemon_GetIconNaix
	mov r1, #0x85
	lsl r1, r1, #2
	str r0, [r7, r1]
	add r0, r4, #0
	mov r1, #5
	mov r2, #0
	bl GetMonData
	mov r1, #0x86
	lsl r1, r1, #2
	strh r0, [r7, r1]
	add r0, r1, #0
	ldrh r0, [r7, r0]
	cmp r0, #0
	beq _0221E054
	mov r0, #0x18
	add r1, r6, #0
	mul r1, r0
	ldr r0, [sp, #4]
	mov r2, #0
	add r5, r0, r1
	add r0, r4, #0
	mov r1, #0x4c
	bl GetMonData
	ldr r1, _0221E064 ; =0x00000223
	mov r2, #0
	strb r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0xa3
	bl GetMonData
	ldr r1, _0221E068 ; =0x0000021A
	mov r2, #0
	strh r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0xa4
	bl GetMonData
	mov r1, #0x87
	lsl r1, r1, #2
	strh r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0xa1
	mov r2, #0
	bl GetMonData
	mov r1, #0x22
	lsl r1, r1, #4
	strb r0, [r5, r1]
	add r0, r4, #0
	mov r1, #6
	mov r2, #0
	bl GetMonData
	ldr r1, _0221E06C ; =0x0000021E
	mov r2, #0
	strh r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0xa2
	bl GetMonData
	mov r1, #0x89
	lsl r1, r1, #2
	strb r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	ldr r1, _0221E070 ; =0x00000225
	mov r2, #0
	strb r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0xb0
	bl GetMonData
	cmp r0, #1
	bne _0221E034
	mov r1, #0
	b _0221E036
_0221E034:
	mov r1, #1
_0221E036:
	ldr r0, _0221E074 ; =0x00000222
	strb r1, [r7, r0]
	add r0, r4, #0
	bl GetMonGender
	ldr r1, _0221E078 ; =0x00000221
	strb r0, [r5, r1]
	add r0, r4, #0
	bl Pokemon_GetStatusIconId
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	mov r0, #0x8a
	lsl r0, r0, #2
	str r1, [r5, r0]
_0221E054:
	add r0, r6, #1
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	cmp r6, #3
	bhs _0221E060
	b _0221DF58
_0221E060:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221E064: .word 0x00000223
_0221E068: .word 0x0000021A
_0221E06C: .word 0x0000021E
_0221E070: .word 0x00000225
_0221E074: .word 0x00000222
_0221E078: .word 0x00000221
	thumb_func_end ov05_0221DF38


	thumb_func_start ov05_0221E07C
ov05_0221E07C: ; 0x0221E07C
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x85
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	mov r2, #0x90
	bl memset
	ldr r1, [r4]
	add r0, r4, #0
	ldr r1, [r1, #4]
	mov r2, #0
	bl ov05_0221DF38
	ldr r1, [r4]
	add r0, r4, #0
	ldr r1, [r1, #0xc]
	mov r2, #3
	bl ov05_0221DF38
	pop {r4, pc}
	thumb_func_end ov05_0221E07C


	thumb_func_start ov05_0221E0A8
ov05_0221E0A8: ; 0x0221E0A8
	push {r4, lr}
	add r3, r0, #0
	add r2, r1, #0
	mov r0, #0x18
	mul r2, r0
	ldr r1, _0221E10C ; =0x0000021A
	add r4, r3, r2
	ldrh r0, [r4, r1]
	cmp r0, #0
	bne _0221E0C0
	mov r0, #0
	pop {r4, pc}
_0221E0C0:
	add r1, #0xe
	ldr r1, [r4, r1]
	cmp r1, #7
	beq _0221E0D0
	cmp r1, #0
	beq _0221E0D0
	mov r0, #5
	pop {r4, pc}
_0221E0D0:
	mov r1, #0x87
	add r2, r3, r2
	lsl r1, r1, #2
	ldrh r1, [r2, r1]
	mov r2, #0x30
	bl CalculateHpBarColor
	cmp r0, #4
	bhi _0221E108
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0221E0EE: ; jump table
	.short _0221E108 - _0221E0EE - 2 ; case 0
	.short _0221E104 - _0221E0EE - 2 ; case 1
	.short _0221E100 - _0221E0EE - 2 ; case 2
	.short _0221E0FC - _0221E0EE - 2 ; case 3
	.short _0221E0F8 - _0221E0EE - 2 ; case 4
_0221E0F8:
	mov r0, #1
	pop {r4, pc}
_0221E0FC:
	mov r0, #2
	pop {r4, pc}
_0221E100:
	mov r0, #3
	pop {r4, pc}
_0221E104:
	mov r0, #4
	pop {r4, pc}
_0221E108:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_0221E10C: .word 0x0000021A
	thumb_func_end ov05_0221E0A8


	thumb_func_start ov05_0221E110
ov05_0221E110: ; 0x0221E110
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0
	str r0, [sp, #8]
	str r1, [sp]
	add r0, r1, #0
	lsl r1, r0, #2
	ldr r0, [sp]
	ldr r2, _0221E268 ; =ov05_0221EC5C
	add r7, r0, r1
	lsl r0, r7, #2
	add r4, r5, r0
	ldr r0, [sp]
	mov r1, #0xa
	mul r1, r0
	str r4, [sp, #4]
	add r6, r2, r1
_0221E134:
	mov r1, #0x1c
	add r2, r7, #0
	mul r2, r1
	ldr r1, _0221E26C ; =ov05_0221EF2C
	add r0, r5, #0
	add r1, r1, r2
	bl ov05_0221CDC4
	mov r1, #0x66
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r1, #0
	ldrb r1, [r6]
	ldrb r2, [r6, #1]
	ldr r0, [r4, r0]
	bl ManagedSprite_SetPositionXY
	ldr r0, [sp, #8]
	add r7, r7, #1
	add r0, r0, #1
	add r4, r4, #4
	add r6, r6, #2
	str r0, [sp, #8]
	cmp r0, #5
	blo _0221E134
	ldr r0, [sp]
	mov r2, #0x86
	mov r1, #0x18
	add r6, r0, #0
	mul r6, r1
	add r3, r5, r6
	lsl r2, r2, #2
	ldrh r0, [r3, r2]
	cmp r0, #0
	bne _0221E19C
	mov r5, #0
	add r4, r2, #0
	add r6, r5, #0
	sub r4, #0x80
_0221E182:
	ldr r0, [sp, #4]
	add r1, r6, #0
	ldr r0, [r0, r4]
	bl ManagedSprite_SetDrawFlag
	ldr r0, [sp, #4]
	add r5, r5, #1
	add r0, r0, #4
	str r0, [sp, #4]
	cmp r5, #5
	blo _0221E182
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_0221E19C:
	ldr r1, [sp]
	mov r4, #0x14
	mul r4, r1
	add r1, r2, #0
	sub r1, #0x80
	add r7, r5, r1
	add r1, r2, #0
	add r1, #0xd
	add r2, #0xb
	ldrb r1, [r3, r1]
	ldrb r2, [r3, r2]
	bl GetMonIconPaletteEx
	add r1, r0, #0
	ldr r0, [r7, r4]
	bl ManagedSprite_SetPaletteOverride
	ldr r1, [sp]
	add r0, r5, #0
	bl ov05_0221E0A8
	add r1, r0, #0
	ldr r0, [r7, r4]
	bl ManagedSprite_SetAnim
	ldr r1, _0221E270 ; =0x0000021E
	add r0, r5, r6
	ldrh r0, [r0, r1]
	cmp r0, #0
	bne _0221E1E6
	add r0, r5, r4
	sub r1, #0x82
	ldr r0, [r0, r1]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _0221E20C
_0221E1E6:
	bl ItemIdIsMail
	cmp r0, #1
	bne _0221E1FE
	mov r0, #0x67
	add r1, r5, r4
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #1
	bl ManagedSprite_SetAnim
	b _0221E20C
_0221E1FE:
	mov r0, #0x67
	add r1, r5, r4
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetAnim
_0221E20C:
	mov r0, #0x89
	add r1, r5, r6
	lsl r0, r0, #2
	ldrb r1, [r1, r0]
	cmp r1, #0
	bne _0221E226
	add r1, r5, r4
	sub r0, #0x84
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _0221E232
_0221E226:
	add r1, r5, r4
	sub r0, #0x84
	ldr r0, [r1, r0]
	mov r1, #2
	bl ManagedSprite_SetAnim
_0221E232:
	mov r3, #0x8a
	add r0, r5, r6
	lsl r3, r3, #2
	ldr r0, [r0, r3]
	cmp r0, #7
	bne _0221E24E
	add r0, r5, r4
	sub r3, #0x84
	ldr r0, [r0, r3]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_0221E24E:
	add r0, r3, #0
	add r1, r5, r4
	sub r0, #0x84
	ldr r0, [r1, r0]
	ldr r1, [sp, #8]
	mov r2, #0x18
	mul r2, r1
	add r1, r5, r2
	ldr r1, [r1, r3]
	bl ManagedSprite_SetAnim
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221E268: .word ov05_0221EC5C
_0221E26C: .word ov05_0221EF2C
_0221E270: .word 0x0000021E
	thumb_func_end ov05_0221E110


	thumb_func_start ov05_0221E274
ov05_0221E274: ; 0x0221E274
	push {r3, r4, r5, lr}
	sub sp, #0x18
	ldr r5, _0221E2D4 ; =ov05_0221EAEC
	add r3, sp, #0
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r1, r2, #0
	add r0, r4, #0
	mov r2, #0x1f
	bl ov05_0221CD24
	add r0, r4, #0
	bl ov05_0221E2D8
	add r0, r4, #0
	bl ov05_0221E390
	add r0, r4, #0
	bl ov05_0221E42C
	add r0, r4, #0
	bl ov05_0221E4C8
	mov r5, #0
_0221E2B0:
	add r0, r4, #0
	add r1, r5, #0
	bl ov05_0221E110
	add r5, r5, #1
	cmp r5, #6
	blo _0221E2B0
	add r0, r4, #0
	mov r1, #0x10
	bl ov05_0221E564
	mov r0, #0x21
	mov r1, #0x1e
	lsl r0, r0, #4
	str r1, [r4, r0]
	add sp, #0x18
	pop {r3, r4, r5, pc}
	nop
_0221E2D4: .word ov05_0221EAEC
	thumb_func_end ov05_0221E274


	thumb_func_start ov05_0221E2D8
ov05_0221E2D8: ; 0x0221E2D8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #0x14
	ldr r1, [r1, #0x24]
	bl NARC_New
	add r7, r0, #0
	bl sub_02074490
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _0221E388 ; =0x0000B808
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r7, #0
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	bl sub_02074498
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _0221E38C ; =0x0000B809
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r7, #0
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	bl sub_020744A4
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _0221E38C ; =0x0000B809
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r7, #0
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r4, #0
	add r6, r5, #0
_0221E350:
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _0221E38C ; =0x0000B809
	mov r1, #0x65
	add r0, r4, r0
	str r0, [sp, #8]
	mov r0, #0x19
	mov r3, #0x85
	lsl r0, r0, #4
	lsl r1, r1, #2
	lsl r3, r3, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r3, [r6, r3]
	add r2, r7, #0
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	add r4, r4, #1
	add r6, #0x18
	cmp r4, #6
	blo _0221E350
	add r0, r7, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221E388: .word 0x0000B808
_0221E38C: .word 0x0000B809
	thumb_func_end ov05_0221E2D8


	thumb_func_start ov05_0221E390
ov05_0221E390: ; 0x0221E390
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #0x15
	ldr r1, [r1, #0x24]
	bl NARC_New
	add r4, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _0221E420 ; =0x0000B80F
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x14
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, _0221E424 ; =0x0000B809
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x15
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0221E428 ; =0x0000B80A
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x13
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0221E428 ; =0x0000B80A
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x12
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_0221E420: .word 0x0000B80F
_0221E424: .word 0x0000B809
_0221E428: .word 0x0000B80A
	thumb_func_end ov05_0221E390


	thumb_func_start ov05_0221E42C
ov05_0221E42C: ; 0x0221E42C
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #0x27
	ldr r1, [r1, #0x24]
	bl NARC_New
	add r4, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _0221E4BC ; =0x0000B810
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x40
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, _0221E4C0 ; =0x0000B80A
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x41
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0221E4C4 ; =0x0000B80B
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x3f
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0221E4C4 ; =0x0000B80B
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x3e
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_0221E4BC: .word 0x0000B810
_0221E4C0: .word 0x0000B80A
_0221E4C4: .word 0x0000B80B
	thumb_func_end ov05_0221E42C


	thumb_func_start ov05_0221E4C8
ov05_0221E4C8: ; 0x0221E4C8
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #0x15
	ldr r1, [r1, #0x24]
	bl NARC_New
	add r4, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _0221E558 ; =0x0000B811
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #2
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _0221E55C ; =0x0000B80B
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #8
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0221E560 ; =0x0000B80C
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #1
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r3, #0
	mov r1, #0x19
	ldr r0, _0221E560 ; =0x0000B80C
	str r3, [sp]
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_0221E558: .word 0x0000B811
_0221E55C: .word 0x0000B80B
_0221E560: .word 0x0000B80C
	thumb_func_end ov05_0221E4C8


	thumb_func_start ov05_0221E564
ov05_0221E564: ; 0x0221E564
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	ldr r0, [r0]
	add r7, r1, #0
	add r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0221E57E
	mov r0, #3
	str r0, [sp, #8]
	lsl r0, r7, #0x13
	b _0221E588
_0221E57E:
	mov r0, #0
	str r0, [sp, #8]
	lsl r0, r7, #3
	neg r0, r0
	lsl r0, r0, #0x10
_0221E588:
	asr r7, r0, #0x10
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	mov r1, #0xa
	ldr r2, _0221E5E0 ; =ov05_0221EC5C
	mul r1, r0
	add r0, r2, r1
	str r0, [sp, #4]
_0221E59A:
	ldr r1, [sp, #8]
	ldr r0, [sp, #0xc]
	ldr r4, [sp, #4]
	add r1, r1, r0
	lsl r0, r1, #2
	add r0, r1, r0
	lsl r1, r0, #2
	ldr r0, [sp]
	mov r6, #0
	add r5, r0, r1
_0221E5AE:
	ldrb r1, [r4]
	mov r0, #0x66
	lsl r0, r0, #2
	add r1, r7, r1
	lsl r1, r1, #0x10
	ldrb r2, [r4, #1]
	ldr r0, [r5, r0]
	asr r1, r1, #0x10
	bl ManagedSprite_SetPositionXY
	add r6, r6, #1
	add r4, r4, #2
	add r5, r5, #4
	cmp r6, #5
	blt _0221E5AE
	ldr r0, [sp, #4]
	add r0, #0xa
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #3
	blt _0221E59A
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221E5E0: .word ov05_0221EC5C
	thumb_func_end ov05_0221E564


	thumb_func_start ov05_0221E5E4
ov05_0221E5E4: ; 0x0221E5E4
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r5, r7, #0
	ldr r4, _0221E608 ; =ov05_0221ECE4
	mov r6, #0
	add r5, #0x10
_0221E5F0:
	ldr r0, [r7, #0xc]
	add r1, r5, #0
	add r2, r4, #0
	bl AddWindow
	add r6, r6, #1
	add r4, #8
	add r5, #0x10
	cmp r6, #0x18
	blo _0221E5F0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0221E608: .word ov05_0221ECE4
	thumb_func_end ov05_0221E5E4


	thumb_func_start ov05_0221E60C
ov05_0221E60C: ; 0x0221E60C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r4, #0
	add r5, #0x10
_0221E614:
	add r0, r5, #0
	bl RemoveWindow
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #0x18
	blo _0221E614
	pop {r3, r4, r5, pc}
	thumb_func_end ov05_0221E60C


	thumb_func_start ov05_0221E624
ov05_0221E624: ; 0x0221E624
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	ldr r4, [sp, #0x3c]
	add r5, r0, #0
	add r7, r5, #0
	lsl r0, r4, #6
	add r7, #0x10
	str r0, [sp, #0x1c]
	str r1, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r6, [sp, #0x38]
	cmp r4, #3
	ldr r0, [r5]
	bhs _0221E64C
	ldr r0, [r0, #4]
	add r1, r4, #0
	bl Party_GetMonByIndex
	str r0, [sp, #0x18]
	b _0221E656
_0221E64C:
	ldr r0, [r0, #0xc]
	sub r1, r4, #3
	bl Party_GetMonByIndex
	str r0, [sp, #0x18]
_0221E656:
	add r1, r4, #0
	ldr r0, [sp, #0x10]
	add r1, #8
	bl NewString_ReadMsgData
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x18]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [sp, #0x14]
	mov r1, #0
	bl BufferBoxMonNickname
	ldr r0, [sp, #0x14]
	ldr r2, [sp, #0x20]
	add r1, r6, #0
	bl StringExpandPlaceholders
	ldr r0, [sp, #0x20]
	bl String_Delete
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0221E708 ; =0x000F0E00
	add r2, r6, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	add r3, r1, #0
	add r0, r7, r0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0x18
	mul r0, r4
	add r2, r5, r0
	ldr r0, _0221E70C ; =0x00000222
	ldrb r1, [r2, r0]
	cmp r1, #0
	bne _0221E704
	sub r0, r0, #1
	ldrb r0, [r2, r0]
	cmp r0, #0
	bne _0221E6DC
	ldr r0, [sp, #0x10]
	mov r1, #0x1b
	add r2, r6, #0
	bl ReadMsgDataIntoString
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0xc1
	lsl r0, r0, #0xa
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	add r2, r6, #0
	add r0, r7, r0
	mov r3, #0x40
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
_0221E6DC:
	cmp r0, #1
	bne _0221E704
	ldr r0, [sp, #0x10]
	mov r1, #0x1c
	add r2, r6, #0
	bl ReadMsgDataIntoString
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0221E710 ; =0x00050600
	add r2, r6, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	mov r3, #0x40
	add r0, r7, r0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
_0221E704:
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221E708: .word 0x000F0E00
_0221E70C: .word 0x00000222
_0221E710: .word 0x00050600
	thumb_func_end ov05_0221E624


	thumb_func_start ov05_0221E714
ov05_0221E714: ; 0x0221E714
	push {r3, r4, r5, lr}
	sub sp, #0x10
	ldr r3, [sp, #0x24]
	add r4, r0, #0
	lsl r5, r3, #2
	add r5, r5, #1
	mov r1, #0
	add r0, #0x10
	lsl r5, r5, #4
	str r1, [sp]
	add r0, r0, r5
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r2, #0
	mov r2, #0x18
	mul r2, r3
	add r3, r4, r2
	mov r2, #0x22
	lsl r2, r2, #4
	ldrb r2, [r3, r2]
	mov r1, #1
	mov r3, #3
	bl sub_0200CE7C
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end ov05_0221E714


	thumb_func_start ov05_0221E74C
ov05_0221E74C: ; 0x0221E74C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r1, [sp, #0x24]
	add r5, r0, #0
	lsl r0, r1, #2
	add r7, r2, #0
	add r2, r5, #0
	add r0, r0, #2
	add r6, r1, #0
	add r2, #0x10
	lsl r0, r0, #4
	add r4, r2, r0
	mov r0, #0x18
	mul r6, r0
	str r4, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r1, _0221E7B4 ; =0x0000021A
	add r2, r5, r6
	ldrh r1, [r2, r1]
	add r0, r7, #0
	mov r2, #3
	mov r3, #1
	bl PrintUIntOnWindow
	mov r0, #2
	str r0, [sp]
	add r0, r7, #0
	mov r1, #0
	add r2, r4, #0
	mov r3, #0x18
	bl sub_0200CDAC
	mov r1, #0x87
	str r4, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	add r2, r5, r6
	lsl r1, r1, #2
	ldrh r1, [r2, r1]
	add r0, r7, #0
	mov r2, #3
	mov r3, #0
	bl PrintUIntOnWindow
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_0221E7B4: .word 0x0000021A
	thumb_func_end ov05_0221E74C


	thumb_func_start ov05_0221E7B8
ov05_0221E7B8: ; 0x0221E7B8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	lsl r0, r1, #2
	add r2, r5, #0
	add r0, r0, #3
	add r2, #0x10
	lsl r0, r0, #4
	add r4, r2, r0
	mov r0, #0x18
	add r6, r1, #0
	mul r6, r0
	mov r0, #0x87
	lsl r0, r0, #2
	add r7, r5, r0
	sub r0, r0, #2
	add r0, r5, r0
	str r0, [sp, #8]
	ldrh r0, [r0, r6]
	ldrh r1, [r7, r6]
	mov r2, #0x30
	bl CalculateHpBarColor
	cmp r0, #4
	bhi _0221E846
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0221E7F6: ; jump table
	.short _0221E846 - _0221E7F6 - 2 ; case 0
	.short _0221E830 - _0221E7F6 - 2 ; case 1
	.short _0221E818 - _0221E7F6 - 2 ; case 2
	.short _0221E800 - _0221E7F6 - 2 ; case 3
	.short _0221E800 - _0221E7F6 - 2 ; case 4
_0221E800:
	ldrb r3, [r4, #9]
	ldr r1, _0221E89C ; =0x000004F6
	mov r0, #1
	lsl r3, r3, #4
	add r3, #9
	lsl r3, r3, #0x11
	add r1, r5, r1
	mov r2, #4
	lsr r3, r3, #0x10
	bl BG_LoadPlttData
	b _0221E846
_0221E818:
	ldrb r3, [r4, #9]
	ldr r1, _0221E8A0 ; =0x00000516
	mov r0, #1
	lsl r3, r3, #4
	add r3, #9
	lsl r3, r3, #0x11
	add r1, r5, r1
	mov r2, #4
	lsr r3, r3, #0x10
	bl BG_LoadPlttData
	b _0221E846
_0221E830:
	ldrb r3, [r4, #9]
	ldr r1, _0221E8A4 ; =0x00000536
	mov r0, #1
	lsl r3, r3, #4
	add r3, #9
	lsl r3, r3, #0x11
	add r1, r5, r1
	mov r2, #4
	lsr r3, r3, #0x10
	bl BG_LoadPlttData
_0221E846:
	ldr r0, [sp, #8]
	ldrh r1, [r7, r6]
	ldrh r0, [r0, r6]
	mov r2, #0x30
	bl CalculateHpBarPixelsLength
	add r5, r0, #0
	lsl r0, r5, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0xa
	mov r2, #0
	mov r3, #2
	bl FillWindowPixelRect
	lsl r0, r5, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #9
	mov r2, #0
	mov r3, #3
	bl FillWindowPixelRect
	lsl r0, r5, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0xa
	mov r2, #0
	mov r3, #5
	bl FillWindowPixelRect
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_0221E89C: .word 0x000004F6
_0221E8A0: .word 0x00000516
_0221E8A4: .word 0x00000536
	thumb_func_end ov05_0221E7B8


	thumb_func_start ov05_0221E8A8
ov05_0221E8A8: ; 0x0221E8A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r7, r0, #0
	ldr r6, [sp, #0x2c]
	add r5, r7, #0
	str r1, [sp, #8]
	add r5, #0x10
	lsl r4, r6, #6
	add r0, r5, r4
	mov r1, #0
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	bl FillWindowPixelBuffer
	add r0, r5, r4
	add r0, #0x10
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, r4
	add r0, #0x20
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, r4
	add r0, #0x30
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #8]
	str r0, [sp]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	add r0, r7, #0
	str r6, [sp, #4]
	bl ov05_0221E624
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #8]
	str r0, [sp]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	add r0, r7, #0
	str r6, [sp, #4]
	bl ov05_0221E714
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #8]
	str r0, [sp]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	add r0, r7, #0
	str r6, [sp, #4]
	bl ov05_0221E74C
	add r0, r7, #0
	add r1, r6, #0
	bl ov05_0221E7B8
	add r0, r5, r4
	bl ScheduleWindowCopyToVram
	add r0, r5, r4
	add r0, #0x10
	bl ScheduleWindowCopyToVram
	add r0, r5, r4
	add r0, #0x20
	bl ScheduleWindowCopyToVram
	add r0, r5, r4
	add r0, #0x30
	bl ScheduleWindowCopyToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov05_0221E8A8


	thumb_func_start ov05_0221E944
ov05_0221E944: ; 0x0221E944
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r0, #0
	ldr r3, [r6]
	mov r2, #0x4b
	ldr r3, [r3, #0x24]
	mov r0, #0
	mov r1, #0x1b
	lsl r2, r2, #2
	bl NewMsgDataFromNarc
	ldr r3, [r6]
	str r0, [sp, #0x10]
	ldr r3, [r3, #0x24]
	mov r0, #0xf
	mov r1, #0xe
	mov r2, #0
	bl MessagePrinter_New
	str r0, [sp, #0xc]
	ldr r0, [r6]
	ldr r0, [r0, #0x24]
	bl MessageFormat_New
	ldr r1, [r6]
	str r0, [sp, #8]
	ldr r1, [r1, #0x24]
	mov r0, #0x20
	bl String_New
	add r7, r0, #0
	mov r4, #0
	add r5, r6, #0
_0221E986:
	mov r0, #0x86
	lsl r0, r0, #2
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _0221E9A0
	ldr r1, [sp, #0x10]
	str r7, [sp]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #8]
	add r0, r6, #0
	str r4, [sp, #4]
	bl ov05_0221E8A8
_0221E9A0:
	add r4, r4, #1
	add r5, #0x18
	cmp r4, #6
	blo _0221E986
	add r0, r7, #0
	bl String_Delete
	ldr r0, [sp, #0x10]
	bl DestroyMsgData
	ldr r0, [sp, #0xc]
	bl MessagePrinter_Delete
	ldr r0, [sp, #8]
	bl MessageFormat_Delete
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov05_0221E944
