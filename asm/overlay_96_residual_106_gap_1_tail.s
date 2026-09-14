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
