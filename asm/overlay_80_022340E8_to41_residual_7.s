	.include "asm/macros.inc"
	.include "overlay_80_022340E8.inc"
	.include "global.inc"

    .text

	thumb_func_start ov80_02234DC4
ov80_02234DC4: ; 0x02234DC4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r0, #0
	cmp r1, #0
	bne _02234DD6
	mov r5, #0x1e
	mov r6, #0xa2
	lsl r5, r5, #4
	b _02234DDC
_02234DD6:
	mov r6, #0xa1
	add r5, r6, #0
	add r5, #0x7f
_02234DDC:
	mov r1, #2
	mov r0, #0x65
	lsl r1, r1, #0xc
	bl Heap_Alloc
	mov r2, #2
	mov r1, #0
	lsl r2, r2, #0xc
	add r4, r0, #0
	bl memset
	mov r0, #0xb7
	mov r1, #0x65
	bl NARC_New
	add r1, r6, #0
	add r2, sp, #8
	mov r3, #0x65
	str r0, [sp, #4]
	bl GfGfxLoader_GetPlttDataFromOpenNarc
	add r6, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, [sp, #8]
	mov r2, #1
	ldr r0, [r0, #0xc]
	add r1, r4, #0
	lsl r2, r2, #0xc
	add r3, r7, #0
	bl BlendPalette
	mov r1, #2
	add r0, r4, #0
	lsl r1, r1, #0xc
	bl DC_FlushRange
	bl GX_BeginLoadBGExtPltt
	mov r1, #6
	add r0, r4, #0
	lsl r1, r1, #0xc
	add r2, r5, #0
	bl GX_LoadBGExtPltt
	bl GX_EndLoadBGExtPltt
	ldr r0, [sp, #4]
	bl NARC_Delete
	add r0, r4, #0
	bl Heap_Free
	add r0, r6, #0
	bl Heap_Free
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov80_02234DC4
