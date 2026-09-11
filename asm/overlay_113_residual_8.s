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

	thumb_func_start ov113_021E6300
ov113_021E6300: ; 0x021E6300
	push {r3, r4, r5, lr}
	sub sp, #0xb8
	add r4, r0, #0
	bl ov113_021E62E0
	ldr r0, [r4]
	bl BgConfig_Alloc
	add r3, sp, #0xa8
	ldr r5, _021E646C ; =ov113_021E6B94
	str r0, [r4, #0x40]
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r2, _021E6470 ; =0x04000304
	ldr r0, _021E6474 ; =0xFFFF7FFF
	ldrh r1, [r2]
	ldr r5, _021E6478 ; =ov113_021E6C3C
	add r3, sp, #0x8c
	and r0, r1
	strh r0, [r2]
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #5
	str r0, [r3]
	ldr r0, [r4, #0x40]
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r4, #0x40]
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E647C ; =ov113_021E6C74
	add r3, sp, #0x70
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #6
	str r0, [r3]
	ldr r0, [r4, #0x40]
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r4, #0x40]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E6480 ; =ov113_021E6BE8
	add r3, sp, #0x54
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #7
	str r0, [r3]
	ldr r0, [r4, #0x40]
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r4, #0x40]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E6484 ; =ov113_021E6C04
	add r3, sp, #0x38
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	str r0, [r3]
	ldr r0, [r4, #0x40]
	mov r1, #1
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r4, #0x40]
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E6488 ; =ov113_021E6C20
	add r3, sp, #0x1c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #2
	str r0, [r3]
	ldr r0, [r4, #0x40]
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r4, #0x40]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E648C ; =ov113_021E6C58
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #3
	str r0, [r3]
	ldr r0, [r4, #0x40]
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r4, #0x40]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r3, [r4]
	mov r0, #5
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	ldr r3, [r4]
	mov r0, #6
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	ldr r3, [r4]
	mov r0, #7
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	ldr r3, [r4]
	mov r0, #1
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	ldr r3, [r4]
	mov r0, #2
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	ldr r3, [r4]
	mov r0, #3
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	add sp, #0xb8
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E646C: .word ov113_021E6B94
_021E6470: .word 0x04000304
_021E6474: .word 0xFFFF7FFF
_021E6478: .word ov113_021E6C3C
_021E647C: .word ov113_021E6C74
_021E6480: .word ov113_021E6BE8
_021E6484: .word ov113_021E6C04
_021E6488: .word ov113_021E6C20
_021E648C: .word ov113_021E6C58
	thumb_func_end ov113_021E6300


	thumb_func_start ov113_021E6490
ov113_021E6490: ; 0x021E6490
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x40]
	mov r1, #3
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x40]
	mov r1, #2
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x40]
	mov r1, #1
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x40]
	mov r1, #7
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x40]
	mov r1, #6
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x40]
	mov r1, #5
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x40]
	bl Heap_Free
	ldr r2, _021E64D8 ; =0x04000304
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	orr r0, r1
	strh r0, [r2]
	pop {r4, pc}
	nop
_021E64D8: .word 0x04000304
	thumb_func_end ov113_021E6490

