	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.public AddTextPrinterParameterizedWithColor
	.public CopyRectToBgTilemapRect
	.public CopyWindowToVram
	.public FillWindowPixelBuffer
	.public GF_AssertFail
	.public ManagedSprite_SetPaletteOverride
	.public ManagedSprite_SetPriority
	.public PlayerProfile_GetPlayerName_NewString
	.public PokeathlonCourse_GetPlayerProfileFromData
	.public ScheduleBgTilemapBufferTransfer
	.public String_Delete
	.public _s32_div_f
	.public ov96_022104D8
	.text

	thumb_func_start ov96_0221058C
ov96_0221058C: ; 0x0221058C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r6, r1, #0
	add r5, r0, #0
	add r0, r6, #0
	mov r1, #0x64
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #3]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0]
	mov r0, #0x64
	mul r0, r4
	sub r0, r6, r0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #4]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0, #1]
	add r0, r6, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #5]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0, #2]
	mov r4, #0
	mov r6, #4
	mov r7, #8
_02210616:
	str r6, [sp]
	str r7, [sp, #4]
	ldr r0, [r5, #0x24]
	lsl r2, r4, #0x1a
	add r0, #0xc
	str r0, [sp, #8]
	add r0, sp, #0x1c
	add r0, #3
	ldrb r0, [r0, r4]
	mov r1, #6
	lsr r2, r2, #0x18
	str r0, [sp, #0xc]
	add r0, sp, #0x1c
	ldrb r0, [r0, r4]
	mov r3, #0
	str r0, [sp, #0x10]
	mov r0, #0x14
	str r0, [sp, #0x14]
	mov r0, #0x10
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x10]
	bl CopyRectToBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _02210616
	ldr r0, [r5, #0x10]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0221058C


	thumb_func_start ov96_0221065C
ov96_0221065C: ; 0x0221065C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	mov r6, #0
	mov r4, #0xe6
	add r5, r7, #0
_02210668:
	add r0, r6, #0
	add r0, #9
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	lsl r2, r4, #0x10
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	asr r2, r2, #0x10
	mov r3, #0x4c
	bl ov96_022104D8
	mov r1, #1
	str r0, [r5, #0x6c]
	bl ManagedSprite_SetPaletteOverride
	add r6, r6, #1
	add r4, #0x10
	add r5, r5, #4
	cmp r6, #2
	blt _02210668
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0221065C


	thumb_func_start ov96_0221069C
ov96_0221069C: ; 0x0221069C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	ldr r0, _02210750 ; =0x00000000
	str r0, [sp, #0x1c]
	bne _022106AC
	bl GF_AssertFail
_022106AC:
	add r6, r5, #0
	mov r4, #0
	str r5, [sp, #0x10]
	add r6, #0x28
_022106B4:
	ldrb r0, [r5, #0x1c]
	cmp r4, r0
	bne _022106C6
	mov r0, #8
	str r0, [sp, #0x18]
	mov r0, #0x48
	mov r7, #0
	str r0, [sp, #0x14]
	b _022106E4
_022106C6:
	ldr r0, [sp, #0x1c]
	ldr r1, _02210754 ; =ov96_0221D14C
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0x1c]
	ldr r2, _02210754 ; =ov96_0221D14C
	lsl r0, r0, #2
	add r1, r1, r0
	ldrsh r0, [r2, r0]
	str r0, [sp, #0x18]
	mov r0, #2
	ldrsh r0, [r1, r0]
	str r0, [sp, #0x14]
	str r7, [sp, #0x1c]
_022106E4:
	ldr r0, [r5]
	add r1, r4, #0
	bl PokeathlonCourse_GetPlayerProfileFromData
	ldr r1, [r5, #4]
	bl PlayerProfile_GetPlayerName_NewString
	lsl r7, r7, #4
	str r0, [sp, #0x20]
	add r0, r6, r7
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02210758 ; =0x000F0E00
	mov r1, #0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r2, [sp, #0x20]
	add r0, r6, r7
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, r7
	bl CopyWindowToVram
	ldr r0, [sp, #0x20]
	bl String_Delete
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #0x41
	str r0, [sp, #4]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x14]
	bl ov96_022104D8
	ldr r1, [sp, #0x10]
	add r4, r4, #1
	str r0, [r1, #0x74]
	add r0, r1, #0
	add r0, r0, #4
	str r0, [sp, #0x10]
	cmp r4, #4
	blt _022106B4
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02210750: .word 0x00000000
_02210754: .word ov96_0221D14C
_02210758: .word 0x000F0E00
	thumb_func_end ov96_0221069C


	thumb_func_start ov96_0221075C
ov96_0221075C: ; 0x0221075C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	mov r0, #0
	str r0, [sp, #0x10]
	mov r0, #8
	mov r7, #7
	str r0, [sp, #0xc]
_0221076C:
	ldr r0, [sp, #0x10]
	mov r4, #0
	add r0, r0, #4
	lsl r0, r0, #3
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	str r0, [sp, #0x14]
_0221077E:
	add r0, r4, r7
	cmp r4, #0
	bne _02210788
	mov r2, #1
	b _0221078C
_02210788:
	mov r2, #0
	mvn r2, r2
_0221078C:
	ldr r1, [sp, #8]
	lsl r0, r0, #2
	mul r2, r1
	mov r1, #0x80
	add r6, r5, r0
	mov r0, #0x14
	add r1, r1, r2
	str r0, [sp]
	mov r0, #0x40
	lsl r1, r1, #0x10
	str r0, [sp, #4]
	asr r2, r1, #0x10
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r3, [sp, #0x14]
	bl ov96_022104D8
	mov r1, #3
	str r0, [r6, #0x68]
	bl ManagedSprite_SetPriority
	add r4, r4, #1
	cmp r4, #2
	blt _0221077E
	ldr r0, [sp, #0xc]
	add r7, r7, #2
	add r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #0xc
	blt _0221076C
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0221075C
