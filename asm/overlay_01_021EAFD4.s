#include "constants/sndseq.h"
#include "constants/moves.h"
#include "constants/std_script.h"
#include "constants/species.h"
#include "constants/sprites.h"
#include "constants/maps.h"
#include "constants/mmodel.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0096_D31R0201.h"
#include "msgdata/msg/msg_0066_D23R0102.h"
	.include "asm/macros.inc"
	.public ov01_021EB058
	.public ov01_021EB18C
	.public ov01_02209898
	.include "overlay_01_021EAFD4.inc"
	.include "global.inc"

	.text
	.public FieldTextureManager_Destroy
	.public FieldTextureManager_Free
	.public FieldTextureManager_FreeAllSlots
	.public FieldTextureManager_Init
	.public FieldTextureManager_LoadTexture

	thumb_func_start ov01_021EB058
ov01_021EB058: ; 0x021EB058
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	add r5, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	bne _021EB06E
	mov r0, #0
	add sp, #0x38
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
_021EB06E:
	mov r4, #0
	add r1, r5, #0
_021EB072:
	ldr r0, [r1, #0x14]
	cmp r0, #0
	beq _021EB080
	add r4, r4, #1
	add r1, #0x18
	cmp r4, #0x10
	blt _021EB072
_021EB080:
	cmp r4, #0x10
	beq _021EB08A
	ldr r0, [sp]
	cmp r0, #0
	bne _021EB092
_021EB08A:
	mov r0, #0
	add sp, #0x38
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
_021EB092:
	mov r0, #0x18
	add r6, r4, #0
	mul r6, r0
	add r0, r5, #0
	str r0, [sp, #0xc]
	add r0, #8
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	mov r1, #0x34
	add r7, r0, #0
	mul r7, r1
	ldr r1, [r5, #4]
	ldr r0, [sp]
	add r1, r1, #4
	add r1, r1, r7
	bl sub_020208DC
	ldr r1, [sp, #0xc]
	str r0, [r1, r6]
	add r0, r1, #0
	ldr r0, [r0, r6]
	cmp r0, #0
	bne _021EB0C8
	mov r0, #0
	add sp, #0x38
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
_021EB0C8:
	ldr r1, [r5, #4]
	ldr r0, [sp]
	add r1, r1, #4
	add r1, r1, r7
	bl sub_020209E0
	add r1, r5, r6
	str r0, [r1, #0xc]
	ldr r1, _021EB110 ; =ov01_02209898
	ldr r2, [sp, #4]
	add r0, sp, #0x10
	bl sprintf ; result never used
	ldr r0, [r5, #4]
	mov r2, #4
	add r0, r0, #4
	add r1, r0, r7
	add r0, r5, r6
	str r1, [r0, #0x18]
	ldr r1, [sp, #4]
	add r7, r5, #0
	ldr r0, [sp, #8]
	add r7, #0x14
	add r1, r1, #1
	bl NARC_AllocAndReadWholeMember
	str r0, [r7, r6]
	ldr r0, [r7, r6]
	bl NNS_G3dGetTex
	add r1, r5, r6
	str r0, [r1, #0x10]
	add r0, r4, #0
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021EB110: .word ov01_02209898
	thumb_func_end ov01_021EB058
