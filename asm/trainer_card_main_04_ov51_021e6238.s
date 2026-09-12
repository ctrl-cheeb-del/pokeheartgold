#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_trainer_card_main.inc"
	.include "global.inc"

	.text

.public TrainerCardMainApp_Exit
.public TrainerCardMainApp_Init
.public TrainerCardMainApp_Main
.public _021E7DB8
.public _021E80A0
.public ov51_021E5F64
.public ov51_021E6038
.public ov51_021E60D4
.public ov51_021E60F4
.public ov51_021E6200
.public ov51_021E6238
.public ov51_021E6354
.public ov51_021E6644
.public ov51_021E66C0
.public ov51_021E6734
.public ov51_021E67A4
.public ov51_021E6888
.public ov51_021E69EC
.public ov51_021E6A54
.public ov51_021E6AAC
.public ov51_021E6B44
.public ov51_021E6B88
.public ov51_021E6C00
.public ov51_021E6C6C
.public ov51_021E6CCC
.public ov51_021E6CF0
.public ov51_021E6D44
.public ov51_021E6DA8
.public ov51_021E6E10
.public ov51_021E6E60
.public ov51_021E6EF0
.public ov51_021E6F18
.public ov51_021E71D0
.public ov51_021E7208
.public ov51_021E74D4
.public ov51_021E74F4
.public ov51_021E7540
.public ov51_021E757C
.public ov51_021E7664
.public ov51_021E76A4
.public ov51_021E76EC
.public ov51_021E77A0
.public ov51_021E7804
.public ov51_021E786C
.public ov51_021E78D0
.public ov51_021E78F8
.public ov51_021E7AF4
.public ov51_021E7BD0
.public ov51_021E7CA4
.public ov51_021E7D44
.public ov51_021E7D68
.public ov51_021E7DA4
.public ov51_021E7DBC
.public ov51_021E7DC0
.public ov51_021E7DC8
.public ov51_021E7DD8
.public ov51_021E7DF0
.public ov51_021E7E08
.public ov51_021E7E20
.public ov51_021E7E38
.public ov51_021E7E54
.public ov51_021E7E70
.public ov51_021E7E8C
.public ov51_021E7EA8
.public ov51_021E7ED0
.public ov51_021E7F08
.public ov51_021E7F48
.public ov51_021E7FB8
.public ov51_021E7FBC
.public ov51_021E7FC4
.public ov51_021E7FCC
.public ov51_021E7FDC
.public ov51_021E801C
.public ov51_021E80A4

	thumb_func_start ov51_021E6238
ov51_021E6238: ; 0x021E6238
	push {r3, r4, r5, lr}
	sub sp, #0xb8
	ldr r2, _021E6338 ; =0x04000304
	add r4, r0, #0
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	ldr r5, _021E633C ; =ov51_021E7DC8
	orr r0, r1
	strh r0, [r2]
	add r3, sp, #0xa8
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _021E6340 ; =ov51_021E7E8C
	add r3, sp, #0x8c
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
	add r0, r4, #0
	mov r3, #2
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E6344 ; =ov51_021E7ED0
	add r3, sp, #0x54
	mov r2, #7
_021E628A:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E628A
	add r0, r4, #0
	mov r1, #4
	add r2, sp, #0x54
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	mov r1, #5
	add r2, sp, #0x70
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E6348 ; =ov51_021E7E70
	add r3, sp, #0x38
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
	add r0, r4, #0
	mov r3, #2
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E634C ; =ov51_021E7E38
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
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E6350 ; =ov51_021E7E54
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
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	add sp, #0xb8
	pop {r3, r4, r5, pc}
	nop
_021E6338: .word 0x04000304
_021E633C: .word ov51_021E7DC8
_021E6340: .word ov51_021E7E8C
_021E6344: .word ov51_021E7ED0
_021E6348: .word ov51_021E7E70
_021E634C: .word ov51_021E7E38
_021E6350: .word ov51_021E7E54
	thumb_func_end ov51_021E6238

	thumb_func_start ov51_021E6354
ov51_021E6354: ; 0x021E6354
	push {r4, r5, lr}
	sub sp, #0x24
	add r4, r0, #0
	mov r0, #0x31
	mov r1, #0
	add r2, sp, #0x20
	mov r3, #0x19
	bl GfGfxLoader_GetPlttData
	add r5, r0, #0
	ldr r0, [sp, #0x20]
	mov r1, #2
	ldr r0, [r0, #0xc]
	lsl r1, r1, #8
	bl DC_FlushRange
	ldr r0, [sp, #0x20]
	mov r2, #2
	ldr r0, [r0, #0xc]
	mov r1, #0
	lsl r2, r2, #8
	bl GXS_LoadBGPltt
	add r0, r5, #0
	bl Heap_Free
	add r0, r4, #0
	add r0, #0xe8
	ldr r2, [r0]
	ldrb r1, [r2, #4]
	ldrb r0, [r2, #3]
	ldrb r2, [r2]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1f
	bl ov51_021E60F4
	mov r0, #0x31
	mov r1, #0x1c
	add r2, sp, #0x1c
	mov r3, #0x19
	bl GfGfxLoader_GetPlttData
	add r5, r0, #0
	ldr r0, [sp, #0x1c]
	mov r1, #2
	ldr r0, [r0, #0xc]
	lsl r1, r1, #8
	bl DC_FlushRange
	ldr r0, [sp, #0x1c]
	mov r2, #2
	ldr r0, [r0, #0xc]
	mov r1, #0
	lsl r2, r2, #8
	bl GX_LoadBGPltt
	add r0, r5, #0
	bl Heap_Free
	add r0, r4, #0
	add r0, #0xe8
	ldr r0, [r0]
	ldrb r1, [r0, #5]
	cmp r1, #0xff
	bne _021E6442
	mov r2, #0
	mov r0, #0x31
	mov r1, #0x2c
	mov r3, #0x19
	str r2, [sp]
	bl GfGfxLoader_LoadFromNarc
	ldr r1, _021E6624 ; =0x000030EC
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	cmp r0, #0
	bne _021E63F2
	bl GF_AssertFail
_021E63F2:
	ldr r1, _021E6624 ; =0x000030EC
	ldr r0, [r4, r1]
	add r1, r1, #4
	add r1, r4, r1
	bl NNS_G2dGetUnpackedBGCharacterData
	cmp r0, #0
	bne _021E6406
	bl GF_AssertFail
_021E6406:
	add r0, r4, #0
	add r0, #0xe8
	ldr r0, [r0]
	ldr r3, _021E6628 ; =0x000033B4
	ldrb r0, [r0, #4]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1f
	bne _021E642C
	mov r0, #0x19
	str r0, [sp]
	mov r0, #0x31
	mov r1, #0x36
	mov r2, #0
	add r3, r4, r3
	bl GfGfxLoader_GetScrnData
	ldr r1, _021E662C ; =0x000033B0
	str r0, [r4, r1]
	b _021E6498
_021E642C:
	mov r0, #0x19
	str r0, [sp]
	mov r0, #0x31
	mov r1, #0x37
	mov r2, #0
	add r3, r4, r3
	bl GfGfxLoader_GetScrnData
	ldr r1, _021E662C ; =0x000033B0
	str r0, [r4, r1]
	b _021E6498
_021E6442:
	lsl r3, r1, #2
	ldr r1, _021E6630 ; =ov51_021E7F08
	mov r2, #0
	ldr r1, [r1, r3]
	mov r0, #0x31
	mov r3, #0x19
	str r2, [sp]
	bl GfGfxLoader_LoadFromNarc
	ldr r1, _021E6624 ; =0x000030EC
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	cmp r0, #0
	bne _021E6462
	bl GF_AssertFail
_021E6462:
	ldr r1, _021E6624 ; =0x000030EC
	ldr r0, [r4, r1]
	add r1, r1, #4
	add r1, r4, r1
	bl NNS_G2dGetUnpackedBGCharacterData
	cmp r0, #0
	bne _021E6476
	bl GF_AssertFail
_021E6476:
	ldr r3, _021E6628 ; =0x000033B4
	mov r0, #0x19
	str r0, [sp]
	mov r0, #0x31
	mov r1, #0x3d
	mov r2, #0
	add r3, r4, r3
	bl GfGfxLoader_GetScrnData
	ldr r1, _021E662C ; =0x000033B0
	str r0, [r4, r1]
	add r0, r4, #0
	add r0, #0xe8
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	bl ov51_021E6200
_021E6498:
	add r0, r4, #0
	bl ov51_021E6C6C
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x19
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0x31
	mov r1, #0x29
	mov r3, #6
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x19
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0x31
	mov r1, #0x2f
	mov r3, #6
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x19
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0x31
	mov r1, #0x2a
	mov r3, #5
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x19
	str r0, [sp, #0xc]
	mov r0, #0x31
	ldr r2, [r4]
	add r1, r0, #0
	mov r3, #5
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x19
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0x31
	mov r1, #0x2b
	mov r3, #2
	bl GfGfxLoader_LoadCharData
	ldr r3, _021E6634 ; =0x000033BC
	mov r0, #0x19
	str r0, [sp]
	mov r0, #0x31
	mov r1, #0x35
	mov r2, #0
	add r3, r4, r3
	bl GfGfxLoader_GetScrnData
	ldr r1, _021E6638 ; =0x000033B8
	str r0, [r4, r1]
	add r1, #0x82
	ldrb r0, [r4, r1]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _021E6550
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x19
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0x31
	mov r1, #0x34
	mov r3, #2
	bl GfGfxLoader_LoadScrnData
	b _021E6568
_021E6550:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x19
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0x31
	mov r1, #0x33
	mov r3, #2
	bl GfGfxLoader_LoadScrnData
_021E6568:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x19
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0x31
	mov r1, #0x32
	mov r3, #3
	bl GfGfxLoader_LoadScrnData
	ldr r1, _021E663C ; =0x0000343A
	ldrb r0, [r4, r1]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	bne _021E65C8
	add r0, r4, #0
	add r0, #0xe8
	ldr r0, [r0]
	ldrh r0, [r0, #6]
	cmp r0, #0xff
	blo _021E65C8
	sub r1, #0x7e
	ldr r0, [r4, r1]
	mov r3, #7
	str r3, [sp]
	mov r1, #9
	str r1, [sp, #4]
	add r1, r0, #0
	add r1, #0xc
	str r1, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	str r2, [sp, #0x10]
	ldrh r1, [r0]
	lsl r1, r1, #0x15
	lsr r1, r1, #0x18
	str r1, [sp, #0x14]
	ldrh r0, [r0, #2]
	mov r1, #2
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r4]
	bl CopyToBgTilemapRect
	b _021E6608
_021E65C8:
	add r0, r4, #0
	add r0, #0xe8
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	ldr r0, _021E6640 ; =0x0000FFFF
	cmp r1, r0
	bne _021E6608
	ldr r0, _021E6634 ; =0x000033BC
	mov r2, #7
	ldr r0, [r4, r0]
	mov r1, #9
	str r2, [sp]
	str r1, [sp, #4]
	add r1, r0, #0
	add r1, #0xc
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	mov r2, #0
	str r2, [sp, #0x10]
	ldrh r1, [r0]
	mov r3, #0xe
	lsl r1, r1, #0x15
	lsr r1, r1, #0x18
	str r1, [sp, #0x14]
	ldrh r0, [r0, #2]
	mov r1, #2
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r4]
	bl CopyToBgTilemapRect
_021E6608:
	ldr r0, [r4]
	mov r1, #2
	bl BgCommitTilemapBufferToVram
	add r0, r4, #0
	add r0, #0xe8
	ldr r0, [r0]
	add r4, #0xec
	add r0, #0x68
	add r1, r4, #0
	bl ov51_021E6CF0
	add sp, #0x24
	pop {r4, r5, pc}
	.balign 4, 0
_021E6624: .word 0x000030EC
_021E6628: .word 0x000033B4
_021E662C: .word 0x000033B0
_021E6630: .word ov51_021E7F08
_021E6634: .word 0x000033BC
_021E6638: .word 0x000033B8
_021E663C: .word 0x0000343A
_021E6640: .word 0x0000FFFF
	thumb_func_end ov51_021E6354

	thumb_func_start ov51_021E6644
ov51_021E6644: ; 0x021E6644
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x1f
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x1f
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r2, #0
	add r0, r4, #0
	mov r1, #5
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	add r0, r4, #0
	mov r1, #5
	mov r2, #3
	mov r3, #0
	bl BgSetPosTextAndCommit
	mov r2, #0
	add r0, r4, #0
	mov r1, #3
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	mov r1, #3
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0
	bl BgSetPosTextAndCommit
	add r0, r4, #0
	mov r1, #7
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #6
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #4
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #5
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #2
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #3
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	bl Heap_Free
	pop {r4, pc}
	thumb_func_end ov51_021E6644

	thumb_func_start ov51_021E66C0
ov51_021E66C0: ; 0x021E66C0
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	ldr r0, _021E6730 ; =0x000030F4
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _021E66FC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x19
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0x31
	mov r1, #0x2f
	mov r3, #6
	bl GfGfxLoader_LoadScrnData
	add r0, r4, #4
	mov r1, #7
	mov r2, #0xa
	bl ov51_021E74D4
	ldr r0, [r4]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	add sp, #0x10
	pop {r4, pc}
_021E66FC:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x19
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0x31
	mov r1, #0x30
	mov r3, #6
	bl GfGfxLoader_LoadScrnData
	add r0, r4, #4
	mov r1, #0
	mov r2, #6
	bl ov51_021E74D4
	add r0, r4, #0
	bl ov51_021E6CCC
	ldr r0, [r4]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_021E6730: .word 0x000030F4
	thumb_func_end ov51_021E66C0

	thumb_func_start ov51_021E6734
ov51_021E6734: ; 0x021E6734
	push {r4, lr}
	add r4, r0, #0
	bl ov51_021E66C0
	ldr r0, _021E679C ; =0x0000311C
	mov r1, #0
	add r0, r4, r0
	add r2, r1, #0
	mov r3, #1
	bl ov51_021E7D44
	ldr r0, _021E67A0 ; =0x000030F4
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _021E6762
	add r0, r4, #0
	bl ov51_021E6C6C
	add r0, r4, #0
	mov r1, #1
	bl ov51_021E76EC
	b _021E6776
_021E6762:
	add r2, r4, #0
	ldr r0, [r4]
	mov r1, #7
	add r2, #0xec
	bl ov51_021E6D44
	add r0, r4, #0
	mov r1, #0
	bl ov51_021E76EC
_021E6776:
	add r2, r4, #0
	add r2, #0xe8
	ldr r2, [r2]
	add r0, r4, #0
	add r1, r4, #4
	bl ov51_021E6F18
	add r2, r4, #0
	add r2, #0xe8
	ldr r2, [r2]
	add r0, r4, #0
	add r1, r4, #4
	bl ov51_021E7208
	add r0, r4, #0
	add r1, r4, #4
	bl ov51_021E71D0
	pop {r4, pc}
	.balign 4, 0
_021E679C: .word 0x0000311C
_021E67A0: .word 0x000030F4
	thumb_func_end ov51_021E6734

	thumb_func_start ov51_021E67A4
ov51_021E67A4: ; 0x021E67A4
	push {r4, lr}
	ldr r1, _021E6884 ; =0x00003436
	add r4, r0, #0
	ldrb r2, [r4, r1]
	cmp r2, #4
	bhi _021E6880
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021E67BC: ; jump table
	.short _021E67C6 - _021E67BC - 2 ; case 0
	.short _021E67D6 - _021E67BC - 2 ; case 1
	.short _021E6800 - _021E67BC - 2 ; case 2
	.short _021E683E - _021E67BC - 2 ; case 3
	.short _021E6860 - _021E67BC - 2 ; case 4
_021E67C6:
	mov r1, #0
	bl ov51_021E77A0
	ldr r0, _021E6884 ; =0x00003436
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _021E6880
_021E67D6:
	add r0, r1, #6
	ldrb r0, [r4, r0]
	bl TextPrinterCheckActive
	cmp r0, #0
	beq _021E67E6
	mov r0, #0
	pop {r4, pc}
_021E67E6:
	add r0, r4, #0
	mov r1, #0
	bl ov51_021E7804
	add r0, r4, #0
	mov r1, #1
	bl ov51_021E6E10
	ldr r0, _021E6884 ; =0x00003436
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _021E6880
_021E6800:
	mov r1, #0
	bl ov51_021E786C
	cmp r0, #0
	blt _021E6880
	bne _021E6818
	add r0, r4, #0
	mov r1, #0
	bl ov51_021E6E10
	mov r0, #1
	pop {r4, pc}
_021E6818:
	add r0, r4, #0
	add r0, #0xe8
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x1f
	beq _021E6830
	add r0, r4, #0
	mov r1, #1
	bl ov51_021E77A0
	b _021E6834
_021E6830:
	mov r0, #2
	pop {r4, pc}
_021E6834:
	ldr r0, _021E6884 ; =0x00003436
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _021E6880
_021E683E:
	add r0, r1, #6
	ldrb r0, [r4, r0]
	bl TextPrinterCheckActive
	cmp r0, #0
	beq _021E684E
	mov r0, #0
	pop {r4, pc}
_021E684E:
	add r0, r4, #0
	mov r1, #1
	bl ov51_021E7804
	ldr r0, _021E6884 ; =0x00003436
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _021E6880
_021E6860:
	mov r1, #1
	bl ov51_021E786C
	cmp r0, #0
	beq _021E6870
	cmp r0, #1
	beq _021E687C
	b _021E6880
_021E6870:
	add r0, r4, #0
	mov r1, #0
	bl ov51_021E6E10
	mov r0, #1
	pop {r4, pc}
_021E687C:
	mov r0, #2
	pop {r4, pc}
_021E6880:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_021E6884: .word 0x00003436
	thumb_func_end ov51_021E67A4

	thumb_func_start ov51_021E6888
ov51_021E6888: ; 0x021E6888
	push {r3, r4, r5, r6, r7, lr}
	ldr r1, _021E69D4 ; =0x00003436
	add r4, r0, #0
	ldrb r2, [r4, r1]
	mov r5, #0
	cmp r2, #5
	bls _021E6898
	b _021E69C4
_021E6898:
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021E68A4: ; jump table
	.short _021E68B0 - _021E68A4 - 2 ; case 0
	.short _021E68DE - _021E68A4 - 2 ; case 1
	.short _021E6918 - _021E68A4 - 2 ; case 2
	.short _021E6930 - _021E68A4 - 2 ; case 3
	.short _021E696E - _021E68A4 - 2 ; case 4
	.short _021E697E - _021E68A4 - 2 ; case 5
_021E68B0:
	mov r0, #8
	sub r1, #0xa2
	str r0, [r4, r1]
	ldr r1, _021E69D8 ; =0x000030FC
	lsl r2, r0, #9
	str r2, [r4, r1]
	add r0, r1, #4
	str r2, [r4, r0]
	ldr r0, [r4, r1]
	add r0, #0x80
	str r0, [r4, r1]
	add r0, r1, #4
	ldr r2, [r4, r0]
	add r2, #0x80
	str r2, [r4, r0]
	ldr r0, _021E69DC ; =SEQ_SE_DP_CARD5
	bl PlaySE
	ldr r0, _021E69D4 ; =0x00003436
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _021E69C4
_021E68DE:
	add r3, r1, #0
	sub r3, #0xa2
	ldr r7, [r4, r3]
	ldr r6, _021E69D8 ; =0x000030FC
	mov r3, #0xc
	mov r0, #2
	sub r3, r3, r7
	ldr r2, [r4, r6]
	lsl r0, r3
	sub r0, r2, r0
	str r0, [r4, r6]
	ldr r0, [r4, r6]
	cmp r0, #0
	bgt _021E6904
	mov r0, #0x24
	str r0, [r4, r6]
	ldrb r0, [r4, r1]
	add r0, r0, #1
	strb r0, [r4, r1]
_021E6904:
	ldr r0, _021E69E0 ; =0x00003394
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r1, [r4, r0]
	cmp r1, #1
	bgt _021E69C4
	mov r1, #1
	str r1, [r4, r0]
	b _021E69C4
_021E6918:
	ldr r2, _021E69E4 ; =0x000030F4
	mov r1, #1
	ldr r3, [r4, r2]
	eor r1, r3
	str r1, [r4, r2]
	bl ov51_021E66C0
	ldr r0, _021E69D4 ; =0x00003436
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _021E69C4
_021E6930:
	ldr r1, _021E69E4 ; =0x000030F4
	ldr r1, [r4, r1]
	cmp r1, #0
	bne _021E6946
	bl ov51_021E6C6C
	add r0, r4, #0
	mov r1, #1
	bl ov51_021E76EC
	b _021E6964
_021E6946:
	add r2, r4, #0
	ldr r0, [r4]
	mov r1, #7
	add r2, #0xec
	bl ov51_021E6D44
	ldr r0, _021E69E8 ; =0x0000343A
	ldrb r0, [r4, r0]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	bne _021E6964
	add r0, r4, #0
	add r1, r5, #0
	bl ov51_021E76EC
_021E6964:
	ldr r0, _021E69D4 ; =0x00003436
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _021E69C4
_021E696E:
	add r1, r4, #4
	bl ov51_021E71D0
	ldr r0, _021E69D4 ; =0x00003436
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _021E69C4
_021E697E:
	add r0, r1, #0
	sub r0, #0xa2
	ldr r0, [r4, r0]
	add r2, r0, #1
	add r0, r1, #0
	sub r0, #0xa2
	str r2, [r4, r0]
	add r0, r1, #0
	sub r0, #0xa2
	ldr r0, [r4, r0]
	cmp r0, #8
	ble _021E699C
	mov r0, #8
	sub r1, #0xa2
	str r0, [r4, r1]
_021E699C:
	ldr r2, _021E69E0 ; =0x00003394
	ldr r3, _021E69D8 ; =0x000030FC
	ldr r6, [r4, r2]
	mov r2, #0xc
	mov r0, #2
	sub r2, r2, r6
	add r6, r0, #0
	ldr r1, [r4, r3]
	lsl r6, r2
	add r1, r1, r6
	str r1, [r4, r3]
	ldr r2, [r4, r3]
	lsl r1, r0, #0xb
	cmp r2, r1
	blt _021E69C4
	str r1, [r4, r3]
	str r1, [r4, r3]
	add r0, r3, #4
	str r1, [r4, r0]
	mov r5, #1
_021E69C4:
	ldr r1, _021E69E8 ; =0x0000343A
	mov r0, #4
	ldrb r2, [r4, r1]
	orr r0, r2
	strb r0, [r4, r1]
	add r0, r5, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E69D4: .word 0x00003436
_021E69D8: .word 0x000030FC
_021E69DC: .word SEQ_SE_DP_CARD5
_021E69E0: .word 0x00003394
_021E69E4: .word 0x000030F4
_021E69E8: .word 0x0000343A
	thumb_func_end ov51_021E6888
