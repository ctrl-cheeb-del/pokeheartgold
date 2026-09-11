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
	.public AreaLightManager_Free
	.public AreaLightManager_New
	.public AreaLightManager_UpdateActiveTemplate
	.public GetDoorSE
	.public LoadAreaOrDungeonLightTxt
	.public _021E90D8
	.public _021E90F6
	.public _021E9106
	.public _021E9112
	.public _021E9118
	.public _021E911A
	.public _021E915E
	.public _021E9190
	.public _021E9198
	.public _021E91B6
	.public _021E91F4
	.public _021E91FA
	.public _021E9210
	.public _021E9218
	.public _021E9238
	.public _021E9256
	.public _021E926A
	.public _021E92A8
	.public _021E92B0
	.public _021E92EE
	.public _021E92F6
	.public _021E9308
	.public _021E9336
	.public _021E934C
	.public _021E9362
	.public _021E9368
	.public _021E936C
	.public _021E9370
	.public _021E9384
	.public _021E9390
	.public _021E939E
	.public _021E93E0
	.public _021E9412
	.public _021E941A
	.public _021E9442
	.public _021E9476
	.public _021E9486
	.public _021E94A2
	.public _021E94AA
	.public _021E94DC
	.public _021E94FA
	.public _021E951A
	.public _021E952E
	.public _021E9572
	.public _021E95A2
	.public _021E95B0
	.public _021E95C0
	.public _021E95C8
	.public _021E95EC
	.public _021E9606
	.public _021E960C
	.public _021E962E
	.public _021E9630
	.public _021E9646
	.public _021E964C
	.public _021E967E
	.public _021E9688
	.public _021E968E
	.public _021E9694
	.public _021E969A
	.public _021E96A0
	.public _021E96AA
	.public _021E96BC
	.public _021E96C6
	.public _021E96CC
	.public _021E96D2
	.public _021E96D8
	.public _021E96DE
	.public _021E96E8
	.public _021E96EC
	.public _021E96F0
	.public _021E96F4
	.public _021E96F8
	.public _021E96FC
	.public _021E970C
	.public _021E9710
	.public _021E9712
	.public _021E9718
	.public _021E972E
	.public _021E973A
	.public _021E9746
	.public _021E9770
	.public _021E9788
	.public _021E97D6
	.public _021E97E0
	.public _021E97FA
	.public _021E97FE
	.public _021E9806
	.public _021E9830
	.public _021E9832
	.public _021E983A
	.public _021E983E
	.public _021E9846
	.public _021E9866
	.public _021E987E
	.public _021E9880
	.public _021E988E
	.public _021E98B4
	.public _021E98E0
	.public _021E98E8
	.public _021E98EC
	.public _021E9902
	.public _021E990E
	.public _021E9918
	.public _021E9942
	.public _021E995A
	.public _021E99AA
	.public _021E99B4
	.public _021E99CE
	.public _021E99D2
	.public _021E99DA
	.public _021E99FE
	.public _021E9A00
	.public _021E9A30
	.public _021E9A34
	.public _021E9A3C
	.public _021E9A62
	.public _021E9A80
	.public _021E9AAC
	.public _021E9AB4
	.public _021E9AB8
	.public _021E9AE4
	.public _021E9B28
	.public _021E9B5A
	.public _021E9B62
	.public _021E9BB0
	.public _021E9BB4
	.public _021E9C1C
	.public _021E9C2C
	.public _021E9C5C
	.public _021E9C68
	.public _021E9C7A
	.public _021E9CF8
	.public _021E9D2A
	.public _021E9D32
	.public _021E9D50
	.public _021E9D88
	.public _021E9DA0
	.public _021E9DAE
	.public _021E9DCC
	.public _021E9DEA
	.public _021E9E04
	.public _021E9E28
	.public _021E9E46
	.public _021E9E58
	.public _021E9E9C
	.public _021E9ECC
	.public _021E9EDC
	.public _021E9EE4
	.public _021E9EE8
	.public _021E9F0C
	.public _021E9F48
	.public _021E9F5C
	.public _021E9F6A
	.public _021E9F70
	.public _021E9F74
	.public _021E9F98
	.public _021E9FCA
	.public _021E9FDE
	.public _021E9FEC
	.public _021E9FF4
	.public _021EA01E
	.public _021EA026
	.public _021EA048
	.public _021EA052
	.public _021EA07A
	.public _021EA082
	.public _021EA086
	.public _021EA08A
	.public _021EA08E
	.public _021EA092
	.public _021EA096
	.public _021EA0B4
	.public _021EA0D2
	.public _021EA0F0
	.public _021EA110
	.public _021EA11E
	.public _021EA124
	.public _021EA14E
	.public _021EA156
	.public _021EA178
	.public _021EA182
	.public _021EA19E
	.public _021EA1BC
	.public _021EA1DA
	.public _021EA1EE
	.public _021EA210
	.public _021EA214
	.public _021EA21C
	.public _021EA22E
	.public _021EA260
	.public _021EA26A
	.public _021EA272
	.public _021EA280
	.public _021EA28E
	.public _021EA2AE
	.public _021EA2CE
	.public _021EA2D0
	.public _021EA2E0
	.public _021EA2F0
	.public _021EA2FC
	.public _021EA30E
	.public _021EA33C
	.public _021EA356
	.public _021EA3AC
	.public _021EA400
	.public _021EA41A
	.public _021EA468
	.public _021EA4AC
	.public _021EA4DE
	.public _021EA4FE
	.public _021EA502
	.public _021EA54E
	.public _021EA560
	.public _021EA5A6
	.public _021EA5DA
	.public _021EA60E
	.public _021EA61A
	.public _021EA628
	.public _021EA634
	.public _021EA642
	.public _021EA650
	.public _021EA656
	.public _021EA660
	.public _021EA664
	.public _021EA688
	.public _021EA6D4
	.public _021EA6F4
	.public _021EA6FE
	.public _021EA706
	.public _021EA720
	.public ov01_021E90C0
	.public ov01_021E90D4
	.public ov01_021E90DC
	.public ov01_021E90E4
	.public ov01_021E9374
	.public ov01_021E95CC
	.public ov01_021E9610
	.public ov01_021E9700
	.public ov01_021E971C
	.public ov01_021E98F0
	.public ov01_021E9ABC
	.public ov01_021E9AE8
	.public ov01_021E9BB8
	.public ov01_021E9BDC
	.public ov01_021E9C00
	.public ov01_021E9C20
	.public ov01_021E9C30
	.public ov01_021E9C40
	.public ov01_021E9EEC
	.public ov01_021E9F78
	.public ov01_021E9FF8
	.public ov01_021EA128
	.public ov01_021EA1F4
	.public ov01_021EA300
	.public ov01_021EA398
	.public ov01_021EA3B0
	.public ov01_021EA3E0
	.public ov01_021EA564
	.public ov01_021EA578
	.public ov01_021EA668
	.public ov01_02206408
	.public ov01_02206418
	.public ov01_02206428
	.public ov01_02206450
	.public ov01_02209820
	.public ov01_02209838
	.public ov01_02209850
	.public ov01_02209868
	.public ov01_02209880
	.include "overlay_01_021E90C0.inc"
	.include "global.inc"

	.text
	.public AreaLightManager_Free
	.public AreaLightManager_UpdateActiveTemplate
	.public GetDoorSE
	.public LoadAreaOrDungeonLightTxt
	.public ov01_021E90C0
	.public ov01_021E90D4
	.public ov01_021E90DC
	.public ov01_021E95CC
	.public ov01_021E9610
	.public ov01_021E9700
	.public ov01_021E9ABC
	.public ov01_021E9BB8
	.public ov01_021E9BDC
	.public ov01_021E9C00
	.public ov01_021E9C20
	.public ov01_021E9C30
	.public ov01_021E9EEC
	.public ov01_021E9F78
	.public ov01_021EA1F4
	.public ov01_021EA300
	.public ov01_021EA398
	.public ov01_021EA3B0
	.public ov01_021EA564
	.public ov01_021EA578
	.public ov01_021EA668

	thumb_func_start ov01_021E9FF8
ov01_021E9FF8: ; 0x021E9FF8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp, #0x10]
	bl TaskManager_GetFieldSystem
	add r5, r0, #0
	ldr r0, [sp, #0x10]
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #3
	bhi _021EA110
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021EA01E: ; jump table
	.short _021EA026 - _021EA01E - 2 ; case 0
	.short _021EA0B4 - _021EA01E - 2 ; case 1
	.short _021EA0D2 - _021EA01E - 2 ; case 2
	.short _021EA0F0 - _021EA01E - 2 ; case 3
_021EA026:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	str r0, [sp, #0x14]
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetFacingDirection
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	cmp r7, #1
	bne _021EA048
	ldr r0, [sp, #0x14]
	mov r1, #1
	bl MapObject_SetVisible
	mov r0, #1
	b _021EA052
_021EA048:
	ldr r0, [sp, #0x14]
	mov r1, #0
	bl MapObject_SetVisible
	mov r0, #3
_021EA052:
	strb r0, [r4]
	mov r0, #0
	str r0, [r4, #4]
	strb r0, [r4, #1]
	ldr r0, [r5, #0x24]
	bl Camera_GetPerspectiveAngle
	strh r0, [r4, #2]
	ldr r0, _021EA124 ; =0x0000FFA0
	ldr r1, [r5, #0x24]
	bl Camera_AdjustPerspectiveAngle
	cmp r7, #3
	bhi _021EA092
	add r0, r7, r7
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021EA07A: ; jump table
	.short _021EA082 - _021EA07A - 2 ; case 0
	.short _021EA086 - _021EA07A - 2 ; case 1
	.short _021EA08A - _021EA07A - 2 ; case 2
	.short _021EA08E - _021EA07A - 2 ; case 3
_021EA082:
	mov r6, #3
	b _021EA096
_021EA086:
	mov r6, #5
	b _021EA096
_021EA08A:
	mov r6, #7
	b _021EA096
_021EA08E:
	mov r6, #0x27
	b _021EA096
_021EA092:
	bl GF_AssertFail
_021EA096:
	mov r1, #0
	str r1, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r2, r6, #0
	bl NewFieldFadeEnvironment
	mov r0, #1
	str r0, [r4, #4]
	b _021EA110
_021EA0B4:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	add r6, r0, #0
	mov r1, #0
	bl MapObject_SetVisible
	add r0, r6, #0
	mov r1, #0xd
	bl MapObject_SetHeldMovement
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	b _021EA110
_021EA0D2:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	add r6, r0, #0
	bl MapObject_IsMovementPaused
	cmp r0, #1
	bne _021EA110
	add r0, r6, #0
	bl MapObject_ClearHeldMovementIfActive
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	b _021EA110
_021EA0F0:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021EA110
	ldr r0, [r5, #0x24]
	bl Camera_GetPerspectiveAngle
	ldrh r1, [r4, #2]
	cmp r1, r0
	bne _021EA110
	add r0, r4, #0
	bl Heap_Free
	add sp, #0x18
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021EA110:
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _021EA11E
	ldr r0, [r5, #0x24]
	add r1, r4, #1
	bl ov01_021E9610
_021EA11E:
	mov r0, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021EA124: .word 0x0000FFA0
	thumb_func_end ov01_021E9FF8


	thumb_func_start ov01_021EA128
ov01_021EA128: ; 0x021EA128
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r0, #0
	bl TaskManager_GetFieldSystem
	add r5, r0, #0
	add r0, r7, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #3
	bhi _021EA1EE
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021EA14E: ; jump table
	.short _021EA156 - _021EA14E - 2 ; case 0
	.short _021EA19E - _021EA14E - 2 ; case 1
	.short _021EA1BC - _021EA14E - 2 ; case 2
	.short _021EA1DA - _021EA14E - 2 ; case 3
_021EA156:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	add r6, r0, #0
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetFacingDirection
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bne _021EA178
	add r0, r6, #0
	mov r1, #1
	bl MapObject_SetVisible
	mov r0, #1
	b _021EA182
_021EA178:
	add r0, r6, #0
	mov r1, #0
	bl MapObject_SetVisible
	mov r0, #3
_021EA182:
	strb r0, [r4]
	mov r1, #0
	mov r2, #1
	str r1, [sp]
	mov r0, #6
	str r0, [sp, #4]
	str r2, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	add r0, r7, #0
	add r3, r2, #0
	bl NewFieldFadeEnvironment
	b _021EA1EE
_021EA19E:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	add r5, r0, #0
	mov r1, #0
	bl MapObject_SetVisible
	add r0, r5, #0
	mov r1, #0xd
	bl MapObject_SetHeldMovement
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	b _021EA1EE
_021EA1BC:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	add r5, r0, #0
	bl MapObject_IsMovementPaused
	cmp r0, #1
	bne _021EA1EE
	add r0, r5, #0
	bl MapObject_ClearHeldMovementIfActive
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	b _021EA1EE
_021EA1DA:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021EA1EE
	add r0, r4, #0
	bl Heap_Free
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021EA1EE:
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov01_021EA128
