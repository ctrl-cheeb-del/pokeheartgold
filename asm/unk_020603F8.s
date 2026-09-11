#include "constants/sndseq.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/pokemon.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "constants/std_script.h"
#include "fielddata/script/scr_seq/event_D24R0204.h"
#include "constants/field_move_response.h"
	.include "asm/macros.inc"
	.include "unk_0205FD20.inc"
	.include "global.inc"
	.text
	.public sub_020603F8
	.public sub_0206064C
	thumb_func_start sub_02060530
sub_02060530: ; 0x02060530
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r3, #0
	bl MapObject_GetManager
	bl MapObjectManager_NotEndMovement
	cmp r0, #0
	bne _02060546
	b _0206064A
_02060546:
	ldrh r0, [r6]
	lsl r0, r0, #0x19
	lsr r0, r0, #0x1d
	beq _0206064A
	cmp r0, #2
	bne _020605E0
	add r0, r5, #0
	bl sub_0205F524
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	add r0, r4, #0
	bl MetatileBehavior_IsTallGrass
	cmp r0, #1
	beq _020605C8
	add r0, r4, #0
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #1
	beq _020605C8
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	bl MetatileBehavior_IsTallGrass
	cmp r0, #1
	beq _020605C8
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #1
	beq _020605C8
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060E54
	cmp r0, #1
	beq _020605C8
	add r0, r4, #0
	bl MetatileBehavior_IsPuddle
	cmp r0, #1
	beq _020605C8
	add r0, r4, #0
	bl MetatileBehavior_IsShallowWater
	cmp r0, #1
	beq _020605C8
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060EBC
	cmp r0, #1
	beq _020605C8
	add r0, r4, #0
	bl MetatileBehavior_IsMud
	cmp r0, #1
	beq _020605C8
	add r0, r4, #0
	bl MetatileBehavior_IsReflective
	cmp r0, #0
	beq _020605D4
_020605C8:
	mov r1, #1
	add r0, r5, #0
	lsl r1, r1, #0x14
	bl MapObject_SetFlagsBits
	pop {r4, r5, r6, pc}
_020605D4:
	mov r1, #1
	add r0, r5, #0
	lsl r1, r1, #0x14
	bl MapObject_ClearFlagsBits
	pop {r4, r5, r6, pc}
_020605E0:
	add r0, r4, #0
	bl MetatileBehavior_IsTallGrass
	cmp r0, #1
	beq _02060634
	add r0, r4, #0
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #1
	beq _02060634
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060E54
	cmp r0, #1
	beq _02060634
	add r0, r4, #0
	bl MetatileBehavior_IsPuddle
	cmp r0, #1
	beq _02060634
	add r0, r4, #0
	bl MetatileBehavior_IsShallowWater
	cmp r0, #1
	beq _02060634
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060EBC
	cmp r0, #1
	beq _02060634
	add r0, r4, #0
	bl MetatileBehavior_IsMud
	cmp r0, #1
	beq _02060634
	add r0, r4, #0
	bl MetatileBehavior_IsReflective
	cmp r0, #0
	beq _02060640
_02060634:
	mov r1, #1
	add r0, r5, #0
	lsl r1, r1, #0x14
	bl MapObject_SetFlagsBits
	pop {r4, r5, r6, pc}
_02060640:
	mov r1, #1
	add r0, r5, #0
	lsl r1, r1, #0x14
	bl MapObject_ClearFlagsBits
_0206064A:
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02060530
