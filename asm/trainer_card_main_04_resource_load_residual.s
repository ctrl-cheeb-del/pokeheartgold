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
