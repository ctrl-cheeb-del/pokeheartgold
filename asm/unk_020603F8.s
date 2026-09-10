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
	thumb_func_start sub_020603F8
sub_020603F8: ; 0x020603F8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl MapObject_GetManager
	bl MapObjectManager_NotEndMovement
	cmp r0, #0
	beq _02060416
	ldrh r0, [r7]
	lsl r0, r0, #0x19
	lsr r0, r0, #0x1d
	bne _02060418
_02060416:
	b _0206052E
_02060418:
	cmp r0, #2
	bne _020604B0
	add r0, r4, #0
	bl MetatileBehavior_IsTallGrass
	cmp r0, #1
	beq _02060484
	add r0, r4, #0
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #1
	beq _02060484
	add r0, r6, #0
	bl MetatileBehavior_IsTallGrass
	cmp r0, #1
	beq _02060484
	add r0, r6, #0
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #1
	beq _02060484
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060E54
	cmp r0, #1
	beq _02060484
	add r0, r4, #0
	bl MetatileBehavior_IsPuddle
	cmp r0, #1
	beq _02060484
	add r0, r4, #0
	bl MetatileBehavior_IsShallowWater
	cmp r0, #1
	beq _02060484
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060EBC
	cmp r0, #1
	beq _02060484
	add r0, r4, #0
	bl MetatileBehavior_IsMud
	cmp r0, #1
	beq _02060484
	add r0, r4, #0
	bl MetatileBehavior_IsReflective
	cmp r0, #0
	beq _02060490
_02060484:
	mov r1, #1
	add r0, r5, #0
	lsl r1, r1, #0x14
	bl MapObject_SetFlagsBits
	pop {r3, r4, r5, r6, r7, pc}
_02060490:
	mov r1, #2
	add r0, r5, #0
	lsl r1, r1, #0xe
	bl MapObject_GetFlagsBitsMask
	cmp r0, #0
	bne _0206052E
	add r0, r5, #0
	bl ov01_021FD684
	mov r1, #2
	add r0, r5, #0
	lsl r1, r1, #0xe
	bl MapObject_SetFlagsBits
	pop {r3, r4, r5, r6, r7, pc}
_020604B0:
	add r0, r4, #0
	bl MetatileBehavior_IsTallGrass
	cmp r0, #1
	beq _02060504
	add r0, r4, #0
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #1
	beq _02060504
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060E54
	cmp r0, #1
	beq _02060504
	add r0, r4, #0
	bl MetatileBehavior_IsPuddle
	cmp r0, #1
	beq _02060504
	add r0, r4, #0
	bl MetatileBehavior_IsShallowWater
	cmp r0, #1
	beq _02060504
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060EBC
	cmp r0, #1
	beq _02060504
	add r0, r4, #0
	bl MetatileBehavior_IsMud
	cmp r0, #1
	beq _02060504
	add r0, r4, #0
	bl MetatileBehavior_IsReflective
	cmp r0, #0
	beq _02060510
_02060504:
	mov r1, #1
	add r0, r5, #0
	lsl r1, r1, #0x14
	bl MapObject_SetFlagsBits
	pop {r3, r4, r5, r6, r7, pc}
_02060510:
	mov r1, #2
	add r0, r5, #0
	lsl r1, r1, #0xe
	bl MapObject_GetFlagsBitsMask
	cmp r0, #0
	bne _0206052E
	add r0, r5, #0
	bl ov01_021FD640
	mov r1, #2
	add r0, r5, #0
	lsl r1, r1, #0xe
	bl MapObject_SetFlagsBits
_0206052E:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_020603F8
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
	thumb_func_start sub_0206064C
sub_0206064C: ; 0x0206064C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl sub_02060E54
	cmp r0, #1
	beq _02060694
	add r0, r4, #0
	bl MetatileBehavior_IsShallowWater
	cmp r0, #1
	beq _02060694
	add r0, r4, #0
	bl MetatileBehavior_IsIce
	cmp r0, #1
	beq _02060694
	add r0, r4, #0
	bl MetatileBehavior_IsMud
	cmp r0, #1
	beq _02060694
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060EBC
	cmp r0, #1
	beq _02060694
	add r0, r5, #0
	bl MapObject_CheckVisible
	cmp r0, #0
	bne _02060694
	add r0, r5, #0
	bl ov01_021FF74C
_02060694:
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0206064C
