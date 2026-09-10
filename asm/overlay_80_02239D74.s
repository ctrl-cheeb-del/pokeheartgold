	.include "asm/macros.inc"
	.include "overlay_80_02239D74.inc"
	.include "global.inc"
	.public ov80_02239DD0
	.public ov80_02239ED8
	.public ov80_0223DB2C


    .text
	.public ov80_02239D74
	.public ov80_02239DB8
	.public ov80_02239EC4
	.public ov80_02239F48
	.public ov80_02239F94
	.public ov80_02239FA8

	thumb_func_start ov80_02239DD0
ov80_02239DD0: ; 0x02239DD0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	ldr r1, _02239EAC ; =0x0002200C
	add r4, r0, #0
	mov r0, #0x65
	bl Heap_Alloc
	ldr r2, _02239EAC ; =0x0002200C
	str r0, [sp, #8]
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [sp, #8]
	mov r1, #0x65
	str r4, [r0, #4]
	mov r0, #0xb7
	bl NARC_New
	ldr r5, [sp, #8]
	ldr r4, _02239EB0 ; =ov80_0223DB2C
	str r0, [sp, #4]
	mov r6, #0
	add r5, #8
_02239DFE:
	mov r0, #0x65
	str r0, [sp]
	ldrh r1, [r4]
	ldr r0, [sp, #4]
	mov r2, #1
	add r3, sp, #0x10
	bl GfGfxLoader_GetScrnDataFromOpenNarc
	add r7, r0, #0
	ldr r0, [sp, #0x10]
	mov r2, #1
	add r0, #0xc
	add r1, r5, #0
	lsl r2, r2, #0xc
	bl MIi_CpuCopy32
	add r0, r7, #0
	bl Heap_Free
	mov r0, #1
	lsl r0, r0, #0xc
	add r6, r6, #1
	add r4, r4, #2
	add r5, r5, r0
	cmp r6, #2
	blt _02239DFE
	ldr r0, [sp, #4]
	bl NARC_Delete
	mov r0, #0xb7
	mov r1, #0x65
	bl NARC_New
	mov r1, #0x65
	str r1, [sp]
	mov r1, #0xe
	mov r2, #1
	add r3, sp, #0xc
	add r4, r0, #0
	bl GfGfxLoader_GetCharDataFromOpenNarc
	ldr r3, [sp, #0xc]
	add r5, r0, #0
	ldr r2, _02239EB4 ; =0x00002008
	ldr r1, [sp, #8]
	ldr r0, [r3, #0x14]
	add r1, r1, r2
	ldr r2, [r3, #0x10]
	bl MIi_CpuCopy32
	add r0, r5, #0
	bl Heap_Free
	mov r0, #0x65
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0xf
	mov r2, #1
	add r3, sp, #0xc
	bl GfGfxLoader_GetCharDataFromOpenNarc
	ldr r3, [sp, #0xc]
	add r5, r0, #0
	ldr r2, _02239EB8 ; =0x00012008
	ldr r1, [sp, #8]
	ldr r0, [r3, #0x14]
	add r1, r1, r2
	ldr r2, [r3, #0x10]
	bl MIi_CpuCopy32
	add r0, r5, #0
	bl Heap_Free
	add r0, r4, #0
	bl NARC_Delete
	ldr r0, _02239EBC ; =ov80_02239ED8
	ldr r1, [sp, #8]
	ldr r2, _02239EC0 ; =0x0001368C
	bl SysTask_CreateOnMainQueue
	ldr r1, [sp, #8]
	str r0, [r1]
	add r0, r1, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_02239EAC: .word 0x0002200C
_02239EB0: .word ov80_0223DB2C
_02239EB4: .word 0x00002008
_02239EB8: .word 0x00012008
_02239EBC: .word ov80_02239ED8
_02239EC0: .word 0x0001368C
	thumb_func_end ov80_02239DD0
