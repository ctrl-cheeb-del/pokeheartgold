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

	thumb_func_start ov01_021E971C
ov01_021E971C: ; 0x021E971C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	add r4, r1, #0
	add r6, r0, #0
	ldr r0, [r4]
	add r5, r2, #0
	cmp r0, #5
	bls _021E972E
	b _021E98E0
_021E972E:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E973A: ; jump table
	.short _021E9746 - _021E973A - 2 ; case 0
	.short _021E9806 - _021E973A - 2 ; case 1
	.short _021E9846 - _021E973A - 2 ; case 2
	.short _021E9866 - _021E973A - 2 ; case 3
	.short _021E988E - _021E973A - 2 ; case 4
	.short _021E98B4 - _021E973A - 2 ; case 5
_021E9746:
	ldr r3, _021E98E8 ; =ov01_02206408
	add r2, sp, #0x20
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	cmp r5, #2
	bne _021E9770
	mov r0, #2
	str r0, [sp]
	mov r2, #1
	str r2, [sp, #4]
	add r0, sp, #0x30
	str r0, [sp, #8]
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	sub r2, r2, #2
	mov r3, #0
	bl sub_02054A60
	b _021E9788
_021E9770:
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, sp, #0x30
	str r0, [sp, #8]
	mov r2, #0
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	add r3, r2, #0
	bl sub_02054A60
_021E9788:
	mov r0, #2
	strb r0, [r4, #0xc]
	add r0, sp, #0x1c
	str r0, [sp]
	add r0, sp, #0x18
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, sp, #0x20
	mov r2, #4
	add r3, sp, #0x30
	bl sub_02054B74
	cmp r0, #0
	beq _021E97D6
	ldr r0, [r6, #0x34]
	bl ov01_021FB9E0
	add r7, r0, #0
	ldr r0, [sp, #0x1c]
	bl MapProp_GetRenderSurface
	add r5, r0, #0
	ldr r0, [sp, #0x1c]
	bl MapProp_GetResModel
	str r5, [sp]
	str r0, [sp, #4]
	str r7, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r3, [sp, #0x18]
	mov r2, #2
	bl MapPropOneShotAnimationManager_LoadPropAnimations
	b _021E97E0
_021E97D6:
	bl GF_AssertFail
	add sp, #0x40
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E97E0:
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	add r5, r0, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _021E97FA
	add r0, r5, #0
	mov r1, #0x49
	bl MapObject_SetHeldMovement
	b _021E97FE
_021E97FA:
	bl GF_AssertFail
_021E97FE:
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E98E0
_021E9806:
	mov r0, #1
	bl FieldMap_FadeScreen
	ldr r0, [r6, #0x58]
	ldr r3, _021E98EC ; =SEQ_SE_DP_ESUKA
	mov r1, #2
	mov r2, #0
	bl MapPropOneShotAnimationManager_PlayAnimationWithSoundEffect
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	add r6, r0, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _021E983A
	cmp r5, #3
	bne _021E9830
	mov r1, #0xb
	b _021E9832
_021E9830:
	mov r1, #0xa
_021E9832:
	add r0, r6, #0
	bl MapObject_SetHeldMovement
	b _021E983E
_021E983A:
	bl GF_AssertFail
_021E983E:
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E98E0
_021E9846:
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	add r5, r0, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _021E98E0
	add r0, r5, #0
	mov r1, #0x4a
	bl MapObject_SetHeldMovement
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E98E0
_021E9866:
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	add r6, r0, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _021E98E0
	cmp r5, #3
	bne _021E987E
	mov r1, #0xb
	b _021E9880
_021E987E:
	mov r1, #0xa
_021E9880:
	add r0, r6, #0
	bl MapObject_SetHeldMovement
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E98E0
_021E988E:
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	add r7, r0, #0
	bl MapObject_IsMovementPaused
	cmp r0, #1
	bne _021E98E0
	add r0, r7, #0
	bl MapObject_ClearHeldMovementIfActive
	add r0, r6, #0
	add r1, r5, #0
	bl ov01_02205790
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E98E0
_021E98B4:
	ldr r0, [r6, #0x58]
	mov r1, #2
	bl MapPropOneShotAnimationManager_IsAnimationLoopFinished
	cmp r0, #0
	beq _021E98E0
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E98E0
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	mov r2, #2
	bl MapPropOneShotAnimationManager_UnloadAnimation
	ldr r0, _021E98EC ; =SEQ_SE_DP_ESUKA
	mov r1, #0
	bl StopSE
	add sp, #0x40
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E98E0:
	mov r0, #0
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E98E8: .word ov01_02206408
_021E98EC: .word SEQ_SE_DP_ESUKA
	thumb_func_end ov01_021E971C


	thumb_func_start ov01_021E98F0
ov01_021E98F0: ; 0x021E98F0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r4, r1, #0
	add r6, r0, #0
	ldr r0, [r4]
	add r5, r2, #0
	cmp r0, #4
	bls _021E9902
	b _021E9AAC
_021E9902:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E990E: ; jump table
	.short _021E9918 - _021E990E - 2 ; case 0
	.short _021E99DA - _021E990E - 2 ; case 1
	.short _021E9A3C - _021E990E - 2 ; case 2
	.short _021E9A62 - _021E990E - 2 ; case 3
	.short _021E9A80 - _021E990E - 2 ; case 4
_021E9918:
	ldr r3, _021E9AB4 ; =ov01_02206418
	add r2, sp, #0x24
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	cmp r5, #2
	bne _021E9942
	mov r0, #2
	str r0, [sp]
	mov r2, #1
	str r2, [sp, #4]
	add r0, sp, #0x34
	str r0, [sp, #8]
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	sub r2, r2, #2
	mov r3, #0
	bl sub_02054A60
	b _021E995A
_021E9942:
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, sp, #0x34
	str r0, [sp, #8]
	mov r2, #0
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	add r3, r2, #0
	bl sub_02054A60
_021E995A:
	mov r0, #2
	strb r0, [r4, #0xc]
	add r0, sp, #0x20
	str r0, [sp]
	add r0, sp, #0x1c
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, sp, #0x24
	mov r2, #4
	add r3, sp, #0x34
	bl sub_02054B74
	cmp r0, #0
	beq _021E99AA
	ldr r0, [r6, #0x34]
	bl ov01_021FB9E0
	add r7, r0, #0
	ldr r0, [sp, #0x20]
	bl MapProp_GetRenderSurface
	add r5, r0, #0
	ldr r0, [sp, #0x20]
	bl MapProp_GetResModel
	str r5, [sp]
	str r0, [sp, #4]
	str r7, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r3, [sp, #0x1c]
	mov r2, #2
	bl MapPropOneShotAnimationManager_LoadPropAnimations
	b _021E99B4
_021E99AA:
	bl GF_AssertFail
	add sp, #0x44
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_021E99B4:
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	add r5, r0, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _021E99CE
	add r0, r5, #0
	mov r1, #0x49
	bl MapObject_SetHeldMovement
	b _021E99D2
_021E99CE:
	bl GF_AssertFail
_021E99D2:
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E9AAC
_021E99DA:
	ldr r0, [r6, #0x58]
	ldr r3, _021E9AB8 ; =SEQ_SE_DP_ESUKA
	mov r1, #2
	mov r2, #0
	bl MapPropOneShotAnimationManager_PlayAnimationWithSoundEffect
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	add r7, r0, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _021E9A30
	cmp r5, #2
	bne _021E99FE
	mov r5, #0xa
	b _021E9A00
_021E99FE:
	mov r5, #0xb
_021E9A00:
	add r0, r7, #0
	add r1, r5, #0
	bl MapObject_SetHeldMovement
	add r0, r6, #0
	bl FollowMon_IsActive
	cmp r0, #0
	beq _021E9A34
	add r0, r7, #0
	bl MapObject_GetPreviousXCoord
	str r0, [sp, #0x18]
	add r0, r7, #0
	bl MapObject_GetPreviousZCoord
	add r6, #0xe4
	add r2, r0, #0
	ldr r1, [sp, #0x18]
	add r0, r5, #0
	add r3, r6, #0
	bl ov01_02205990
	b _021E9A34
_021E9A30:
	bl GF_AssertFail
_021E9A34:
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E9AAC
_021E9A3C:
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	add r5, r0, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _021E9AAC
	add r0, r5, #0
	mov r1, #0x4a
	bl MapObject_SetHeldMovement
	mov r0, #0
	bl FieldMap_FadeScreen
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E9AAC
_021E9A62:
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	add r5, r0, #0
	bl MapObject_IsMovementPaused
	cmp r0, #1
	bne _021E9AAC
	add r0, r5, #0
	bl MapObject_ClearHeldMovementIfActive
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E9AAC
_021E9A80:
	ldr r0, [r6, #0x58]
	mov r1, #2
	bl MapPropOneShotAnimationManager_IsAnimationLoopFinished
	cmp r0, #0
	beq _021E9AAC
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E9AAC
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	mov r2, #2
	bl MapPropOneShotAnimationManager_UnloadAnimation
	ldr r0, _021E9AB8 ; =SEQ_SE_DP_ESUKA
	mov r1, #0
	bl StopSE
	add sp, #0x44
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_021E9AAC:
	mov r0, #0
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_021E9AB4: .word ov01_02206418
_021E9AB8: .word SEQ_SE_DP_ESUKA
	thumb_func_end ov01_021E98F0
