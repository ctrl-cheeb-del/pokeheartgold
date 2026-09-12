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

	thumb_func_start ov51_021E60F4
ov51_021E60F4: ; 0x021E60F4
	push {r4, r5, lr}
	sub sp, #0x64
	add r3, r0, #0
	add r0, r2, #0
	add r0, #0xf9
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bhi _021E6132
	cmp r1, #0
	beq _021E612E
	ldr r5, _021E61F0 ; =ov51_021E7E08
	add r4, sp, #0x4c
	add r2, r4, #0
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	cmp r3, #5
	bls _021E6128
	bl GF_AssertFail
	ldr r1, [sp, #0x4c]
	b _021E61B0
_021E6128:
	lsl r0, r3, #2
	ldr r1, [r2, r0]
	b _021E61B0
_021E612E:
	mov r1, #6
	b _021E61B0
_021E6132:
	cmp r2, #0xa
	bne _021E615A
	ldr r5, _021E61F4 ; =ov51_021E7DF0
	add r4, sp, #0x34
	add r2, r4, #0
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	cmp r3, #5
	bls _021E6154
	bl GF_AssertFail
	ldr r1, [sp, #0x34]
	b _021E61B0
_021E6154:
	lsl r0, r3, #2
	ldr r1, [r2, r0]
	b _021E61B0
_021E615A:
	cmp r2, #0xb
	bne _021E6182
	ldr r5, _021E61F8 ; =ov51_021E7E20
	add r4, sp, #0x1c
	add r2, r4, #0
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	cmp r3, #5
	bls _021E617C
	bl GF_AssertFail
	ldr r1, [sp, #0x1c]
	b _021E61B0
_021E617C:
	lsl r0, r3, #2
	ldr r1, [r2, r0]
	b _021E61B0
_021E6182:
	cmp r2, #0xc
	bne _021E61AA
	ldr r5, _021E61FC ; =ov51_021E7DD8
	add r4, sp, #4
	add r2, r4, #0
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	cmp r3, #5
	bls _021E61A4
	bl GF_AssertFail
	ldr r1, [sp, #4]
	b _021E61B0
_021E61A4:
	lsl r0, r3, #2
	ldr r1, [r2, r0]
	b _021E61B0
_021E61AA:
	bl GF_AssertFail
	mov r1, #0
_021E61B0:
	mov r0, #0x31
	add r2, sp, #0
	mov r3, #0x19
	bl GfGfxLoader_GetPlttData
	add r4, r0, #0
	ldr r0, [sp]
	mov r1, #2
	ldr r0, [r0, #0xc]
	lsl r1, r1, #8
	bl DC_FlushRange
	ldr r0, [sp]
	mov r1, #0x20
	ldr r5, [r0, #0xc]
	add r2, r1, #0
	add r0, r5, #0
	add r0, #0x20
	add r2, #0xe0
	bl GXS_LoadBGPltt
	mov r1, #0x1e
	lsl r1, r1, #4
	add r0, r5, r1
	mov r2, #0x20
	bl GXS_LoadBGPltt
	add r0, r4, #0
	bl Heap_Free
	add sp, #0x64
	pop {r4, r5, pc}
	.balign 4, 0
_021E61F0: .word ov51_021E7E08
_021E61F4: .word ov51_021E7DF0
_021E61F8: .word ov51_021E7E20
_021E61FC: .word ov51_021E7DD8
	thumb_func_end ov51_021E60F4
