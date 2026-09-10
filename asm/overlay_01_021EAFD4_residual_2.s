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

	thumb_func_start ov01_021EB18C
ov01_021EB18C: ; 0x021EB18C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	beq _021EB1BA
	mov r0, #0x18
	add r4, r1, #0
	mul r4, r0
	add r0, r5, r4
	ldr r0, [r0, #0x14]
	cmp r0, #0
	beq _021EB1A4
	bl Heap_Free
_021EB1A4:
	add r1, r5, #0
	add r1, #0x18
	ldr r0, [r1, r4]
	cmp r0, #0
	beq _021EB1B2
	mov r0, #0
	str r0, [r1, r4]
_021EB1B2:
	mov r1, #0
	add r0, r5, r4
	strh r1, [r0, #0x1c]
	strh r1, [r0, #0x1e]
_021EB1BA:
	pop {r3, r4, r5, pc}
	thumb_func_end ov01_021EB18C
