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
