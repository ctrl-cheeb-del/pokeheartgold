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
	.public ov01_021F72DC
	.public ov01_021F7504
	.public ov01_021F772C
	.public ov01_021F7810
	.public ov01_021F7894
	.public ov01_021F7918
	.public ov01_021F7A90
	.public ov01_021F7B14
	.public ov01_021F7B90
	.public ov01_021F7C14
	.public ov01_021F7C80
	.public ov01_021F7CE4
	.public ov01_021F7E6C
	.public ov01_021F7EE4
	.public ov01_021F7F54
	.public ov01_021F80C4
	.public ov01_021F8164
	.public ov01_021F81FC
	.public ov01_021F82F0
	.public ov01_021F8374
	.public ov01_021F84F4
	.public ov01_021F85F4
	.public ov01_021F8708
	.public ov01_021F878C
	.public ov01_021F8874
	.public ov01_021F89B8
	.public ov01_021F8AB0
	.public ov01_021F8B30
	.include "overlay_01_021F72DC.inc"
	.include "global.inc"

	.text
	.public ov01_022089CC
	.public ov01_022089D8
	.public ov01_022089E8
	.public ov01_022089F8
	.public ov01_02208A08
	.public ov01_02208A18
	.public ov01_02208A28
	.public ov01_02208A38
	.public ov01_02208A48
	.public ov01_02208A64
	.public ov01_02208A80
	.public ov01_02208AA0
	.public ov01_02208AC0
	.public ov01_02208AE4
	.public ov01_02208B0C
	.public ov01_02208B34
	.public ov01_021F73CC
	.public ov01_021F73F4
	.public ov01_021F7408
	.public ov01_021F7434
	.public ov01_021F7478
	.public ov01_021F74B4
	.public ov01_021F74C8
	.public ov01_021F7704
	.public ov01_021F771C
	.public ov01_021F77A4
	.public ov01_021F77D0
	.public ov01_021F796C
	.public ov01_021F79A0
	.public ov01_021F79DC
	.public ov01_021F7A18
	.public ov01_021F7A54
	.public ov01_021F7CBC
	.public ov01_021F7DA8
	.public ov01_021F7DD0
	.public ov01_021F7DFC
	.public ov01_021F7E28
	.public ov01_021F7FC8
	.public ov01_021F801C
	.public ov01_021F8070
	.public ov01_021F829C
	.public ov01_021F8400
	.public ov01_021F847C
	.public ov01_021F856C
	.public ov01_021F85BC
	.public ov01_021F86B8
	.public ov01_021F8804
	.public ov01_021F883C
	.public ov01_021F88F0
	.public ov01_021F894C
	.public ov01_021F8A4C
	.public ov01_021F8BA8
	.public ov01_021F8BE0
	.public ov01_021F8C00
	.public ov01_021F8C30
	.public ov01_021F8C3C
	.public ov01_021F8C64
	.public ov01_021F8C88
	.public ov01_021F8CC8
	.public ov01_021F8CFC
	.public ov01_021F8D24
	.public ov01_021F8D28
	.public ov01_021F8D40
	.public ov01_021F8D58

	thumb_func_start ov01_021F7504
ov01_021F7504: ; 0x021F7504
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	add r5, r0, #0
	bl sub_0205F40C
	add r4, r0, #0
	ldrb r0, [r4, #0x17]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	bne _021F7522
	add r0, r5, #0
	bl MapObject_GetID
	cmp r0, #0xfd
	beq _021F7524
_021F7522:
	b _021F7654
_021F7524:
	add r0, r5, #0
	bl MapObject_GetManager
	bl MapObjectManager_GetFieldSystem
	str r0, [sp, #0x10]
	ldr r0, [r0, #0xc]
	bl SaveArray_Party_Get
	bl GetFirstAliveMonInParty_CrashIfNone
	str r0, [sp, #0xc]
	mov r1, #5
	mov r2, #0
	bl GetMonData
	add r7, r0, #0
	ldr r0, [sp, #0xc]
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	add r6, r0, #0
	ldr r0, [sp, #0xc]
	bl GetMonGender
	str r0, [sp, #8]
	lsl r1, r6, #0x10
	ldr r2, [sp, #8]
	add r0, r7, #0
	lsr r1, r1, #0x10
	bl FollowMon_GetSpriteID
	str r0, [sp, #0x14]
	ldr r0, [sp, #0xc]
	bl MonIsShiny
	str r0, [sp, #4]
	lsl r2, r6, #0x18
	ldrb r1, [r4, #0x17]
	mov r0, #2
	lsr r2, r2, #0x18
	orr r0, r1
	strb r0, [r4, #0x17]
	ldr r3, [sp, #4]
	add r0, r5, #0
	add r1, r7, #0
	bl FollowMon_SetObjectParams
	ldr r1, [sp, #0x14]
	add r0, r5, #0
	bl MapObject_SetSpriteID
	add r0, r5, #0
	bl sub_0205FCD4
	add r0, r5, #0
	mov r1, #4
	bl MapObject_SetFlagsBits
	add r0, r5, #0
	add r1, sp, #0x30
	bl MapObject_CopyPositionVector
	add r0, r5, #0
	bl MapObject_GetXCoord
	add r1, r0, #0
	mov r0, #2
	lsl r2, r1, #0x10
	lsl r0, r0, #0xe
	add r0, r2, r0
	str r0, [sp, #0x30]
	add r0, r5, #0
	bl MapObject_SetPreviousX
	add r0, r5, #0
	bl MapObject_GetYCoord
	add r1, r0, #0
	add r0, r5, #0
	bl MapObject_SetPreviousY
	add r0, r5, #0
	bl MapObject_GetZCoord
	add r1, r0, #0
	mov r0, #2
	lsl r2, r1, #0x10
	lsl r0, r0, #0xe
	add r0, r2, r0
	str r0, [sp, #0x38]
	add r0, r5, #0
	bl MapObject_SetPreviousZ
	add r0, r5, #0
	add r1, sp, #0x30
	bl MapObject_SetPositionVector
	add r0, r5, #0
	bl MapObject_ClearHeldMovement
	ldr r0, [sp, #0x10]
	add r0, #0xf4
	ldr r0, [r0]
	cmp r0, r7
	bne _021F761C
	ldr r0, [sp, #0x10]
	add r0, #0xfc
	ldrh r0, [r0]
	cmp r0, r6
	bne _021F761C
	ldr r0, [sp, #0x10]
	add r0, #0xfb
	ldrb r1, [r0]
	ldr r0, [sp, #4]
	cmp r1, r0
	bne _021F761C
	ldr r0, [sp, #0x10]
	add r0, #0xf8
	ldrb r1, [r0]
	ldr r0, [sp, #8]
	cmp r1, r0
	beq _021F7636
_021F761C:
	ldr r0, [sp, #8]
	lsl r2, r6, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x10]
	ldr r3, [sp, #4]
	add r1, r7, #0
	lsr r2, r2, #0x18
	bl FieldSystem_SetFollowerPokeParam
	add r0, r5, #0
	mov r1, #1
	bl MapObject_SetFacingDirectionDirect
_021F7636:
	mov r1, #0
	ldr r0, [sp, #0xc]
	add r2, r1, #0
	bl GetMonData
	add r3, r0, #0
	mov r1, #0x42
	lsl r2, r7, #0x10
	ldr r0, [sp, #0x10]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	ldr r1, [sp, #0xc]
	lsr r2, r2, #0x10
	bl FieldSystem_UnkSub108_Set
_021F7654:
	add r0, r5, #0
	bl ov01_021FA2D4
	cmp r0, #1
	beq _021F7700
	ldr r0, [r4]
	cmp r0, #0
	bne _021F766C
	add r0, r5, #0
	add r1, r4, #0
	bl ov01_021F9510
_021F766C:
	ldr r0, [r4]
	cmp r0, #0
	beq _021F7700
	ldrb r1, [r4, #0x17]
	mov r0, #1
	bic r1, r0
	mov r0, #1
	orr r0, r1
	strb r0, [r4, #0x17]
	add r1, sp, #0x18
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	add r0, r5, #0
	add r1, sp, #0x24
	bl MapObject_CopyFacingVector
	add r0, r5, #0
	bl MapObject_GetSpriteID
	add r0, r5, #0
	bl MapObject_GetFacingDirection
	add r1, r0, #0
	add r0, r5, #0
	add r2, sp, #0x18
	bl ov01_021F8E70
	ldr r0, [sp, #0x18]
	add r1, sp, #0x24
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x2c]
	add r0, r5, #0
	bl MapObject_SetFacingVector
	add r0, r5, #0
	bl ov01_02205564
	cmp r0, #0
	beq _021F76CC
	ldr r2, [r4]
	mov r0, #1
	add r1, r5, #0
	bl ov01_0220589C
	b _021F76E0
_021F76CC:
	add r0, r5, #0
	bl ov01_0220553C
	cmp r0, #0
	beq _021F76E0
	ldr r2, [r4]
	mov r0, #1
	add r1, r5, #0
	bl ov01_02205808
_021F76E0:
	ldr r0, [r4]
	add r1, r4, #4
	bl ov01_021F9630
	ldr r1, [r4]
	add r0, r5, #0
	bl ov01_021FA3E8
	mov r1, #2
	add r0, r5, #0
	lsl r1, r1, #0x14
	bl MapObject_ClearFlagsBits
	add r0, r5, #0
	bl sub_0205F484
_021F7700:
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov01_021F7504
