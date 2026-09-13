#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222CA10

thumb_func_start ov45_0222CA10
ov45_0222CA10: ; 0x0222CA10
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r4, r1, #0
	add r6, r0, #0
	add r5, r2, #0
	bl WallpaperPasswordBank_GetCount
	add r7, r0, #0
	str r4, [sp, #8]
	add r0, sp, #8
	ldrb r4, [r0]
	ldrb r0, [r0, #3]
	add r1, r7, #0
	str r0, [sp]
	add r0, r0, r4
	bl _u32_div_f
	add r0, r6, #0
	bl WallpaperPasswordBank_GetWordAtIndex
	strh r0, [r5]
	add r0, sp, #8
	ldrb r0, [r0, #1]
	add r1, r7, #0
	str r0, [sp, #4]
	add r0, r4, r0
	bl _u32_div_f
	add r0, r6, #0
	bl WallpaperPasswordBank_GetWordAtIndex
	strh r0, [r5, #2]
	add r0, sp, #8
	ldrb r4, [r0, #2]
	ldr r0, [sp, #4]
	add r1, r7, #0
	add r0, r0, r4
	bl _u32_div_f
	add r0, r6, #0
	bl WallpaperPasswordBank_GetWordAtIndex
	strh r0, [r5, #4]
	ldr r0, [sp]
	add r1, r7, #0
	add r0, r4, r0
	bl _u32_div_f
	add r0, r6, #0
	bl WallpaperPasswordBank_GetWordAtIndex
	strh r0, [r5, #6]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov45_0222CA10
