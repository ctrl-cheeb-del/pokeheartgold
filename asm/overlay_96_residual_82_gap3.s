	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	thumb_func_start ov96_02201B98
ov96_02201B98: ; 0x02201B98
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	bl sub_0203A914
	add r0, r7, #0
	bl PokeathlonCourse_ResetField3A4
	ldr r0, [r4]
	mov r1, #0
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #1
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #3
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #4
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #5
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #6
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #7
	bl FreeBgTilemapBuffer
	add r0, r4, #4
	bl RemoveWindow
	add r5, r4, #0
	mov r6, #0
	add r5, #0x14
_02201BF0:
	add r0, r5, #0
	bl RemoveWindow
	add r6, r6, #1
	add r5, #0x10
	cmp r6, #3
	blt _02201BF0
	ldr r0, [r4]
	bl Heap_Free
	ldr r0, [r4, #0x48]
	bl ov96_021EB21C
	ldr r0, _02201C78 ; =0x000005D8
	ldr r0, [r4, r0]
	bl ov96_021EA894
	ldr r0, _02201C7C ; =0x000005D4
	ldr r0, [r4, r0]
	bl ov96_021E9C0C
	bl OamManager_Free
	bl ObjCharTransfer_Destroy
	bl ObjPlttTransfer_Destroy
	ldr r0, _02201C80 ; =0x000005DC
	ldr r0, [r4, r0]
	bl ov96_022043B8
	mov r0, #0x5e
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ov96_02203A30
	mov r0, #4
	bl FontID_Release
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0
	add r1, r0, #0
	bl Main_SetHBlankIntrCB
	ldr r0, _02201C84 ; =0x00000598
	ldr r0, [r4, r0]
	bl Heap_Free
	add r0, r7, #0
	bl PokeathlonCourse_FreePtr4HeapAlloc
	ldr r0, _02201C88 ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	ldr r0, _02201C8C ; =0x04000050
	mov r1, #0
	strh r1, [r0]
	mov r0, #0x92
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02201C78: .word 0x000005D8
_02201C7C: .word 0x000005D4
_02201C80: .word 0x000005DC
_02201C84: .word 0x00000598
_02201C88: .word gSystem + 0x60
_02201C8C: .word 0x04000050
	thumb_func_end ov96_02201B98
