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
	.public CallFieldTask_RockClimb
	.public CallFieldTask_Surf
	.public CallFieldTask_Waterfall
	.public CallFieldTask_Whirlpool
	.public Field_PlayerAvatar_ApplyTransitionFlags
	.public Field_PlayerAvatar_OrrTransitionFlags
	.public Field_PlayerCanSurfOnTile
	.public Field_PlayerMovementSavingClear
	.public Field_PlayerMovementSavingSet
	.public MetatileBehavior_IsRockClimbInDirection
	.public _021F1B00
	.public _021F1B12
	.public _021F1B1E
	.public _021F1B34
	.public _021F1B6C
	.public _021F1BAC
	.public _021F1BBC
	.public _021F1BF6
	.public _021F1C64
	.public _021F1C78
	.public _021F1DBA
	.public _021F1DBE
	.public _021F1DCE
	.public _021F1DDA
	.public _021F1DEE
	.public _021F1E22
	.public _021F1E3C
	.public _021F1E50
	.public _021F1E64
	.public _021F1E74
	.public _021F1E80
	.public _021F1E92
	.public _021F1EC8
	.public _021F1EF0
	.public _021F1F0E
	.public _021F1F3C
	.public _021F1F62
	.public _021F1F7E
	.public _021F1F82
	.public _021F1F88
	.public _021F1F96
	.public _021F1FF4
	.public _021F2000
	.public _021F2018
	.public _021F2028
	.public _021F2064
	.public _021F2098
	.public _021F20B0
	.public _021F20F0
	.public _021F20FE
	.public _021F210E
	.public _021F2112
	.public _021F2134
	.public _021F2148
	.public _021F2172
	.public _021F217C
	.public _021F2192
	.public _021F21A8
	.public _021F21C4
	.public _021F21C6
	.public _021F21D2
	.public _021F21FC
	.public _021F2210
	.public _021F221C
	.public _021F221E
	.public _021F222A
	.public _021F2274
	.public _021F22A0
	.public _021F22C2
	.public _021F2312
	.public _021F2324
	.public _021F2328
	.public _021F2342
	.public _021F2346
	.public _021F235E
	.public _021F2368
	.public _021F23A6
	.public _021F23B4
	.public _021F23D0
	.public _021F23DC
	.public _021F2412
	.public _021F2476
	.public _021F249A
	.public _021F24AE
	.public _021F24B8
	.public _021F24D2
	.public _021F24F0
	.public _021F250E
	.public _021F2512
	.public _021F252A
	.public _021F257C
	.public _021F257E
	.public _021F258C
	.public _021F25C0
	.public _021F25D8
	.public _021F25FA
	.public _021F2602
	.public _021F2612
	.public _021F2622
	.public _021F2634
	.public _021F2648
	.public _021F2656
	.public _021F2686
	.public _021F268C
	.public _021F2690
	.public _021F26C6
	.public _021F26EE
	.public _021F26F0
	.public _021F2746
	.public _021F27A2
	.public _021F27BC
	.public _021F27E4
	.public _021F2804
	.public _021F282C
	.public _021F2842
	.public _021F2868
	.public _021F28A6
	.public _021F28E8
	.public _021F2904
	.public _021F2940
	.public _021F2950
	.public _021F2962
	.public _021F296C
	.public _021F298A
	.public _021F2990
	.public _021F2994
	.public _021F29B6
	.public _021F29DA
	.public _021F29E0
	.public _021F2A3C
	.public _021F2A62
	.public _021F2A6E
	.public _021F2AD6
	.public _021F2AF2
	.public _021F2B16
	.public _021F2B26
	.public _021F2B3E
	.public _021F2B4A
	.public _021F2B56
	.public _021F2B9E
	.public _021F2BBE
	.public _021F2BC4
	.public _021F2C32
	.public _021F2C3E
	.public _021F2CA8
	.public _021F2CB0
	.public _021F2CCC
	.public _021F2CF2
	.public _021F2D04
	.public _021F2D0C
	.public _021F2D24
	.public _021F2D30
	.public _021F2D3C
	.public _021F2DA0
	.public _021F2DDA
	.public _021F2E00
	.public _021F2E04
	.public _021F2E34
	.public _021F2E50
	.public _021F2E68
	.public _021F2E90
	.public _021F2EA6
	.public _021F2EC6
	.public _021F2F22
	.public _021F2F4E
	.public _021F2F6C
	.public _021F2F88
	.public _021F2FAC
	.public _021F2FB6
	.public _021F2FBC
	.public _021F2FE2
	.public _021F2FE8
	.public _021F2FEC
	.public _021F300C
	.public _021F3018
	.public _021F3022
	.public _021F302E
	.public _021F3080
	.public _021F30E4
	.public _021F30FC
	.public ov01_021F1B38
	.public ov01_021F1B78
	.public ov01_021F1BC0
	.public ov01_021F1C30
	.public ov01_021F1C70
	.public ov01_021F1C7C
	.public ov01_021F1C98
	.public ov01_021F1CB4
	.public ov01_021F1CD0
	.public ov01_021F1CEC
	.public ov01_021F1D08
	.public ov01_021F1D24
	.public ov01_021F1D40
	.public ov01_021F1D5C
	.public ov01_021F1D78
	.public ov01_021F1D94
	.public ov01_021F1DF4
	.public ov01_021F1E54
	.public ov01_021F1EA4
	.public ov01_021F1ECC
	.public ov01_021F1F8C
	.public ov01_021F2004
	.public ov01_021F202C
	.public ov01_021F2118
	.public ov01_021F232C
	.public ov01_021F2378
	.public ov01_021F23B8
	.public ov01_021F24F4
	.public ov01_021F2538
	.public ov01_021F2548
	.public ov01_021F2628
	.public ov01_021F2694
	.public ov01_021F26AC
	.public ov01_021F26CC
	.public ov01_021F2700
	.public ov01_021F2734
	.public ov01_021F2758
	.public ov01_021F27C0
	.public ov01_021F27E8
	.public ov01_021F2808
	.public ov01_021F2830
	.public ov01_021F2894
	.public ov01_021F28B8
	.public ov01_021F28EC
	.public ov01_021F2944
	.public ov01_021F2998
	.public ov01_021F29C0
	.public ov01_021F29E4
	.public ov01_021F2AB8
	.public ov01_021F2AF8
	.public ov01_021F2B80
	.public ov01_021F2BA4
	.public ov01_021F2BC8
	.public ov01_021F2C88
	.public ov01_021F2CD4
	.public ov01_021F2D68
	.public ov01_021F2DD0
	.public ov01_021F2E08
	.public ov01_021F2E20
	.public ov01_021F2E38
	.public ov01_021F2E6C
	.public ov01_021F2E94
	.public ov01_021F2EDC
	.public ov01_021F2F24
	.public ov01_021F3030
	.public ov01_021F3040
	.public ov01_021F3054
	.public ov01_021F3068
	.public ov01_021F3084
	.public ov01_021F3094
	.public ov01_021F30D0
	.public ov01_021F30F4
	.public ov01_021F3100
	.public ov01_02206994
	.public ov01_022069A8
	.public ov01_022069BC
	.public ov01_022069D0
	.public ov01_022069F0
	.public ov01_02206A14
	.public sPlayerAvatarBitUpdateFuncs
	.include "overlay_01_021F1AFC.inc"
	.include "global.inc"

	.text
	.public CallFieldTask_RockClimb
	.public CallFieldTask_Surf
	.public CallFieldTask_Waterfall
	.public CallFieldTask_Whirlpool
	.public Field_PlayerAvatar_OrrTransitionFlags
	.public Field_PlayerCanSurfOnTile
	.public Field_PlayerMovementSavingClear
	.public Field_PlayerMovementSavingSet
	.public MetatileBehavior_IsRockClimbInDirection
	.public ov01_021F1B38
	.public ov01_021F1B78
	.public ov01_021F1BC0
	.public ov01_021F1C30
	.public ov01_021F1C70
	.public ov01_021F1C7C
	.public ov01_021F1C98
	.public ov01_021F1CB4
	.public ov01_021F1CD0
	.public ov01_021F1CEC
	.public ov01_021F1D08
	.public ov01_021F1D24
	.public ov01_021F1D40
	.public ov01_021F1D5C
	.public ov01_021F1D78
	.public ov01_021F1D94
	.public ov01_021F1DF4
	.public ov01_021F1E54
	.public ov01_021F1EA4
	.public ov01_021F2004
	.public ov01_021F2538
	.public ov01_021F2548
	.public ov01_021F2694
	.public ov01_021F26AC
	.public ov01_021F2734
	.public ov01_021F27C0
	.public ov01_021F27E8
	.public ov01_021F2808
	.public ov01_021F2894
	.public ov01_021F28B8
	.public ov01_021F28EC
	.public ov01_021F2998
	.public ov01_021F29C0
	.public ov01_021F2B80
	.public ov01_021F2BA4
	.public ov01_021F2E08
	.public ov01_021F2E20
	.public ov01_021F2E38
	.public ov01_021F2E6C
	.public ov01_021F2E94
	.public ov01_021F2EDC
	.public ov01_021F2F24
	.public ov01_021F3030
	.public ov01_021F3040
	.public ov01_021F3054
	.public ov01_021F3068
	.public ov01_021F3084
	.public ov01_021F3094
	.public ov01_021F30D0
	.public ov01_021F30F4
	.public ov01_021F3100

	thumb_func_start ov01_021F2118
ov01_021F2118: ; 0x021F2118
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldr r0, [r4]
	cmp r0, #9
	bhi _021F221C
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021F2134: ; jump table
	.short _021F2148 - _021F2134 - 2 ; case 0
	.short _021F217C - _021F2134 - 2 ; case 1
	.short _021F2192 - _021F2134 - 2 ; case 2
	.short _021F21D2 - _021F2134 - 2 ; case 3
	.short _021F21FC - _021F2134 - 2 ; case 4
	.short _021F2210 - _021F2134 - 2 ; case 5
	.short _021F222A - _021F2134 - 2 ; case 6
	.short _021F2274 - _021F2134 - 2 ; case 7
	.short _021F22A0 - _021F2134 - 2 ; case 8
	.short _021F22C2 - _021F2134 - 2 ; case 9
_021F2148:
	ldr r0, [r4, #0x1c]
	ldr r0, [r0, #0xc]
	bl Save_VarsFlags_Get
	bl CheckFlag99A
	cmp r0, #0
	bne _021F2172
	bl SndRadio_GetSeqNo
	cmp r0, #0
	bne _021F2172
	ldr r0, [r4, #0x1c]
	mov r1, #0
	bl FieldBGM_SetOverride
	ldr r0, [r4, #0x1c]
	ldr r1, _021F2328 ; =0x000003F6
	mov r2, #1
	bl FieldBGM_TryFadeOut
_021F2172:
	ldr r0, [r4]
	add r0, r0, #1
	add r0, r0, #1
	str r0, [r4]
	b _021F2324
_021F217C:
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	cmp r0, #0xa
	ble _021F221C
	mov r0, #0
	str r0, [r4, #8]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021F2324
_021F2192:
	ldr r0, [r4, #0xc]
	cmp r0, #1
	ldr r0, [r4, #0x1c]
	bne _021F21A8
	add r1, r4, #0
	add r1, #0xc
	bl ov01_021F3054
	mov r0, #5
	str r0, [r4]
	b _021F2324
_021F21A8:
	mov r1, #0xb
	bl ov02_02250780
	cmp r0, #0
	beq _021F21C4
	mov r0, #0x42
	ldr r1, [r4, #0x1c]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #1
	bl FieldSystem_UnkSub108_AddMonMood
	mov r1, #2
	b _021F21C6
_021F21C4:
	mov r1, #1
_021F21C6:
	ldr r0, [r4, #0x1c]
	bl ov02_022507B4
	mov r0, #3
	str r0, [r4]
	b _021F2324
_021F21D2:
	ldr r0, [r4, #0x14]
	mov r1, #5
	mov r2, #0
	bl GetMonData
	add r5, r0, #0
	ldr r0, [r4, #0x14]
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	add r1, r0, #0
	lsl r0, r5, #0x10
	lsl r1, r1, #0x18
	lsr r0, r0, #0x10
	lsr r1, r1, #0x18
	bl PlayCry
	mov r0, #4
	str r0, [r4]
	b _021F2324
_021F21FC:
	bl IsCryFinished
	cmp r0, #0
	bne _021F221C
	add r0, r5, #0
	bl ov01_02205EE0
	mov r0, #6
	str r0, [r4]
	b _021F2324
_021F2210:
	add r0, r4, #0
	add r0, #0xc
	bl ov01_021F3068
	cmp r0, #1
	beq _021F221E
_021F221C:
	b _021F2324
_021F221E:
	ldr r0, [r4, #0x1c]
	bl ov01_02205D68
	mov r0, #6
	str r0, [r4]
	b _021F2324
_021F222A:
	ldr r0, [r4, #0x20]
	bl PlayerAvatar_GetXCoord
	add r5, r0, #0
	ldr r0, [r4, #4]
	bl GetDeltaXByFacingDirection
	add r6, r0, #0
	ldr r0, [r4, #0x20]
	bl PlayerAvatar_GetZCoord
	add r7, r0, #0
	ldr r0, [r4, #4]
	bl GetDeltaYByFacingDirection
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, [r4, #0x24]
	ldr r3, [r4, #4]
	add r1, r5, r6
	add r2, r7, r2
	bl ov01_021FE7DC
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x20]
	ldr r1, [r4, #0x28]
	bl PlayerAvatar_SetUnk34
	ldr r0, [r4, #0x20]
	mov r1, #2
	bl PlayerAvatar_SetState
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021F2324
_021F2274:
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	cmp r0, #0xa
	ble _021F2324
	ldr r0, [r4, #0x20]
	bl PlayerAvatar_GetGender
	add r1, r0, #0
	mov r0, #0
	bl PlayerAvatar_GetSpriteByStateAndGender
	add r1, r0, #0
	ldr r0, [r4, #0x20]
	bl ov01_021F3084
	mov r0, #0
	str r0, [r4, #8]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021F2324
_021F22A0:
	ldr r0, [r4, #0x24]
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _021F2324
	ldr r0, [r4, #4]
	mov r1, #0x34
	bl sub_0206234C
	add r1, r0, #0
	ldr r0, [r4, #0x24]
	bl MapObject_SetHeldMovement
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021F2324
_021F22C2:
	ldr r0, [r4, #0x24]
	bl MapObject_IsMovementPaused
	cmp r0, #0
	beq _021F2324
	ldr r0, [r4, #0x24]
	bl MapObject_ClearHeldMovementIfActive
	ldr r0, [r4, #0x28]
	mov r1, #1
	bl ov01_021FE9F4
	ldr r0, [r4, #0x20]
	bl PlayerAvatar_GetGender
	add r1, r0, #0
	mov r0, #2
	bl PlayerAvatar_GetSpriteByStateAndGender
	add r1, r0, #0
	ldr r0, [r4, #0x20]
	bl ov01_021F3084
	ldr r0, [r4, #0x1c]
	bl FollowMon_IsActive
	cmp r0, #0
	beq _021F2312
	ldr r1, [r4, #4]
	ldr r0, [r4, #0x1c]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov01_02205790
	ldr r0, [r4, #0x1c]
	bl FollowMon_GetMapObject
	mov r1, #0x38
	bl sub_0205FC94
_021F2312:
	ldr r0, [r4, #0x1c]
	mov r1, #0
	bl FieldSystem_ProcessSoundplate
	add r0, r4, #0
	bl ov01_021F30F4
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021F2324:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F2328: .word 0x000003F6
	thumb_func_end ov01_021F2118


	thumb_func_start ov01_021F232C
ov01_021F232C: ; 0x021F232C
	push {r4, r5, r6, lr}
	add r6, r0, #0
	add r5, r1, #0
	add r4, r2, #0
	cmp r3, #1
	bne _021F2342
	add r0, r5, #0
	bl PlayerAvatar_GetState
	cmp r0, #2
	beq _021F2346
_021F2342:
	mov r0, #0
	pop {r4, r5, r6, pc}
_021F2346:
	add r0, r5, #0
	bl PlayerAvatar_GetMapObject
	add r1, r0, #0
	add r0, r5, #0
	add r2, r4, #0
	bl sub_0205DA34
	cmp r0, #0x20
	bne _021F235E
	mov r0, #0
	pop {r4, r5, r6, pc}
_021F235E:
	mov r1, #0x20
	bic r0, r1
	beq _021F2368
	mov r0, #0
	pop {r4, r5, r6, pc}
_021F2368:
	add r0, r4, #0
	add r1, r6, #0
	add r2, r5, #0
	bl ov01_021F2378
	mov r0, #1
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov01_021F232C


	thumb_func_start ov01_021F2378
ov01_021F2378: ; 0x021F2378
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r0, #0x18
	add r5, r1, #0
	add r7, r2, #0
	bl ov01_021F30D0
	add r4, r0, #0
	str r6, [r4, #4]
	str r5, [r4, #8]
	str r7, [r4, #0xc]
	add r0, r7, #0
	bl PlayerAvatar_GetMapObject
	str r0, [r4, #0x10]
	add r0, r7, #0
	bl PlayerAvatar_GetUnk34
	str r0, [r4, #0x14]
	cmp r0, #0
	bne _021F23A6
	bl GF_AssertFail
_021F23A6:
	ldr r1, _021F23B4 ; =ov01_021F23B8
	add r0, r5, #0
	add r2, r4, #0
	bl FieldSystem_CreateTask
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F23B4: .word ov01_021F23B8
	thumb_func_end ov01_021F2378


	thumb_func_start ov01_021F23B8
ov01_021F23B8: ; 0x021F23B8
	push {r4, lr}
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldrh r0, [r4]
	cmp r0, #0
	beq _021F23D0
	cmp r0, #1
	beq _021F2412
	cmp r0, #2
	beq _021F24B8
	b _021F24F0
_021F23D0:
	ldr r0, [r4, #0x10]
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	beq _021F23DC
	b _021F24F0
_021F23DC:
	ldr r0, [r4, #0xc]
	bl PlayerAvatar_GetGender
	add r1, r0, #0
	mov r0, #0
	bl PlayerAvatar_GetSpriteByStateAndGender
	add r1, r0, #0
	ldr r0, [r4, #0xc]
	bl ov01_021F3084
	ldr r0, [r4, #4]
	mov r1, #0x34
	bl sub_0206234C
	add r1, r0, #0
	ldr r0, [r4, #0x10]
	bl MapObject_SetHeldMovement
	ldr r0, [r4, #0x14]
	mov r1, #0
	bl ov01_021FE9F4
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	b _021F24F0
_021F2412:
	ldr r0, [r4, #0x10]
	bl MapObject_IsMovementPaused
	cmp r0, #0
	beq _021F24F0
	ldr r0, [r4, #0x10]
	bl MapObject_ClearHeldMovementIfActive
	ldr r0, [r4, #0x14]
	bl ov01_021F1640
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl PlayerAvatar_SetUnk34
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl PlayerAvatar_SetState
	ldr r0, [r4, #8]
	mov r1, #0
	bl FieldSystem_ProcessSoundplate
	ldr r0, [r4, #8]
	bl FollowMon_IsActive
	cmp r0, #0
	beq _021F2476
	ldr r1, [r4, #4]
	ldr r0, [r4, #8]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov01_02205790
	ldr r0, [r4, #8]
	bl FollowMon_GetMapObject
	mov r1, #1
	bl sub_02069DC8
	ldr r0, [r4, #8]
	mov r1, #1
	bl ov01_0220609C
	ldr r0, [r4, #8]
	bl FollowMon_GetMapObject
	mov r1, #0x30
	bl sub_0205FC94
_021F2476:
	ldr r0, [r4, #8]
	ldr r0, [r0, #0xc]
	bl Save_VarsFlags_Get
	bl CheckFlag99A
	cmp r0, #0
	bne _021F249A
	ldr r0, [r4, #8]
	ldr r1, [r0, #0x20]
	ldr r1, [r1]
	bl FieldBGM_GetForMapHeader
	add r1, r0, #0
	ldr r0, [r4, #8]
	mov r2, #4
	bl FieldBGM_TryFadeOut
_021F249A:
	bl SndRadio_GetSeqNo
	cmp r0, #0
	beq _021F24AE
	mov r0, #0x28
	strh r0, [r4, #2]
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	b _021F24F0
_021F24AE:
	add r0, r4, #0
	bl ov01_021F30F4
	mov r0, #1
	pop {r4, pc}
_021F24B8:
	bl SndRadio_GetSeqNo
	cmp r0, #0
	bne _021F24D2
	ldr r0, [r4, #8]
	mov r1, #1
	bl FieldSystem_ProcessSoundplate
	add r0, r4, #0
	bl ov01_021F30F4
	mov r0, #1
	pop {r4, pc}
_021F24D2:
	ldrh r0, [r4, #2]
	sub r0, r0, #1
	strh r0, [r4, #2]
	ldrh r0, [r4, #2]
	cmp r0, #0
	bne _021F24F0
	ldr r0, [r4, #8]
	mov r1, #1
	bl FieldSystem_ProcessSoundplate
	add r0, r4, #0
	bl ov01_021F30F4
	mov r0, #1
	pop {r4, pc}
_021F24F0:
	mov r0, #0
	pop {r4, pc}
	thumb_func_end ov01_021F23B8


	thumb_func_start ov01_021F24F4
ov01_021F24F4: ; 0x021F24F4
	push {r4, r5, r6, lr}
	add r4, r2, #0
	add r6, r0, #0
	add r5, r1, #0
	cmp r4, #1
	bne _021F250E
	cmp r3, #1
	bne _021F250E
	add r0, r5, #0
	bl PlayerAvatar_GetState
	cmp r0, #2
	beq _021F2512
_021F250E:
	mov r0, #0
	pop {r4, r5, r6, pc}
_021F2512:
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0205DFEC
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl MetatileBehavior_IsWaterfall
	cmp r0, #0
	bne _021F252A
	mov r0, #0
	pop {r4, r5, r6, pc}
_021F252A:
	add r0, r6, #0
	add r1, r4, #0
	bl ov01_021F28EC
	mov r0, #1
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov01_021F24F4
