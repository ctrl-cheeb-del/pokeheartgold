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
	.include "overlay_01_021FB878.inc"
	.include "global.inc"

	.public ov01_021FB878
	.public AreaDataManager_Alloc
	.public ov01_021FB904
	.public ov01_021FB90C
	.public AreaDataManager_GetMapPropModelFile
	.public AreaDataManager_Free
	.public AreaDataManager_GetMapTexture
	.public ov01_021FB9E0
	.public ov01_021FB9F4
	.public ov01_021FBA00
	.public AreaDataManager_GetAreaLightArchiveID
	.public AreaDataManager_Load
	.public Field3dModel_LoadFromFilesystem
	.public ov01_021FBD38
	.public ov01_021FBD8C
	.public Field3dModel_Unload
	.public ov01_021FBDFC
	.public Field3dModelAnimation_LoadFromFilesystem
	.public ov01_021FBE70
	.public Field3dModelAnimation_Unload
	.public Field3dModelAnimation_FrameAdvanceAndLoop
	.public Field3dModelAnimation_FrameAdvanceAndCheck
	.public Field3dModelAnimation_FrameSet
	.public ov01_021FBF28
	.public Field3dObject_InitFromModel
	.public Field3dObject_AddAnimation
	.public Field3dObject_RemoveAnimation
	.public Field3dObject_Draw
	.public Field3dObject_SetActiveFlag
	.public Field3dObject_GetActiveFlag
	.public Field3dObject_SetPosEx
	.public Field3dObject_SetPos
	.public Field3dObject_SetXRotation
	.public ov01_021FC030
	.public _021FB884
	.public _021FB8D8
	.public _021FB8EE
	.public _021FB8F8
	.public _021FB8FC
	.public _021FB900
	.public _021FB918
	.public _021FB92C
	.public _021FB930
	.public _021FB93E
	.public _021FB962
	.public _021FB968
	.public _021FB976
	.public _021FB9BC
	.public _021FB9C0
	.public _021FB9C4
	.public _021FB9C8
	.public _021FB9D6
	.public _021FB9DC
	.public _021FB9EA
	.public _021FB9F0
	.public _021FB9FC
	.public _021FBA0C
	.public _021FBA10
	.public _021FBA26
	.public _021FBA2A
	.public _021FBA2E
	.public _021FBA32
	.public _021FBA38
	.public _021FBA70
	.public _021FBAB2
	.public _021FBAB8
	.public _021FBAC8
	.public _021FBAE8
	.public _021FBAF6
	.public _021FBB06
	.public _021FBB0E
	.public _021FBB32
	.public _021FBB4C
	.public _021FBB7C
	.public _021FBBB4
	.public _021FBBB6
	.public _021FBBC0
	.public _021FBBC2
	.public _021FBBDA
	.public _021FBBEC
	.public _021FBC1C
	.public _021FBC2C
	.public _021FBC50
	.public _021FBC56
	.public _021FBC70
	.public _021FBC76
	.public _021FBC94
	.public _021FBC98
	.public _021FBC9C
	.public _021FBCA0
	.public _021FBCA4
	.public _021FBCA8
	.public _021FBCAC
	.public _021FBCB0
	.public _021FBCB4
	.public _021FBCB8
	.public _021FBCBC
	.public _021FBCC0
	.public _021FBCC4
	.public _021FBCC8
	.public _021FBCCC
	.public _021FBCD0
	.public _021FBCD4
	.public ov01_02208BA0
	.public ov01_02208BB0
	.public ov01_02209A88
	.public ov01_02209AB4
	.public _021FBD0A
	.public _021FBD0C
	.public _021FBD16
	.public _021FBD18
	.public _021FBD32
	.public _021FBD34
	.public _021FBD5E
	.public _021FBD60
	.public _021FBD6A
	.public _021FBD6C
	.public _021FBD86
	.public _021FBD88
	.public _021FBDD8
	.public _021FBDE2
	.public _021FBDE6
	.public _021FBDF4
	.public _021FBDF8
	.public _021FBE2C
	.public _021FBE30
	.public _021FBE3C
	.public _021FBE40
	.public _021FBE9E
	.public _021FBEA2
	.public _021FBECA
	.public _021FBEDC
	.public _021FBF00
	.public _021FBF06
	.public _021FBF0E
	.public _021FBF12
	.public _021FBF58
	.public _021FBF64
	.public _021FBFFC
	.public _021FC000

	.text
	.public AreaDataManager_Alloc
	.public AreaDataManager_Free
	.public AreaDataManager_GetAreaLightArchiveID
	.public AreaDataManager_GetMapPropModelFile
	.public AreaDataManager_GetMapTexture
	.public Field3dModelAnimation_FrameAdvanceAndCheck
	.public Field3dModelAnimation_FrameSet
	.public Field3dModelAnimation_LoadFromFilesystem
	.public Field3dModelAnimation_Unload
	.public Field3dModel_LoadFromFilesystem
	.public Field3dModel_Unload
	.public Field3dObject_AddAnimation
	.public Field3dObject_Draw
	.public Field3dObject_GetActiveFlag
	.public Field3dObject_InitFromModel
	.public Field3dObject_RemoveAnimation
	.public Field3dObject_SetActiveFlag
	.public Field3dObject_SetPos
	.public Field3dObject_SetPosEx
	.public Field3dObject_SetXRotation
	.public ov01_021FB878
	.public ov01_021FB904
	.public ov01_021FB90C
	.public ov01_021FB9E0
	.public ov01_021FB9F4
	.public ov01_021FBA00
	.public ov01_021FBD38
	.public ov01_021FBD8C
	.public ov01_021FBDFC
	.public ov01_021FBE70
	.public ov01_021FBF28
	.public ov01_021FC030

	thumb_func_start AreaDataManager_Load
AreaDataManager_Load: ; 0x021FBA3C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x13c
	str r1, [sp, #0xc]
	add r5, r0, #0
	ldr r1, _021FBC94 ; =0x000008B8
	ldr r0, [sp, #0x150]
	ldr r6, [r5, r1]
	sub r1, #8
	str r2, [sp, #0x10]
	str r0, [sp, #0x150]
	ldrh r1, [r5, r1]
	mov r0, #0x2b
	mov r2, #4
	add r4, r3, #0
	bl AllocAndReadWholeNarcMemberByIdPair
	ldr r1, _021FBC98 ; =0x000008BC
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	ldrh r1, [r0]
	ldr r0, _021FBC9C ; =0x00000226
	strh r1, [r6, #0xc]
	cmp r1, r0
	blo _021FBA70
	bl GF_AssertFail
_021FBA70:
	ldr r1, _021FBCA0 ; =0x000008B2
	mov r0, #0x2c
	ldrh r1, [r5, r1]
	mov r2, #4
	bl AllocAndReadWholeNarcMemberByIdPair
	ldr r1, _021FBCA4 ; =0x0000089C
	mov r2, #4
	str r0, [r5, r1]
	add r1, #0x14
	ldrh r1, [r5, r1]
	mov r0, #0x46
	bl AllocAndReadWholeNarcMemberByIdPair
	mov r1, #0x8a
	lsl r1, r1, #4
	str r0, [r5, r1]
	sub r0, r1, #4
	ldr r0, [r5, r0]
	bl NNS_G3dGetTex
	ldr r1, _021FBCA8 ; =0x000008A4
	str r0, [r5, r1]
	ldrh r0, [r6, #0xc]
	cmp r0, #0
	beq _021FBAB2
	sub r0, r1, #4
	ldr r0, [r5, r0]
	bl NNS_G3dGetTex
	ldr r1, _021FBCAC ; =0x000008A8
	str r0, [r5, r1]
	b _021FBAB8
_021FBAB2:
	mov r2, #0
	add r0, r1, #4
	str r2, [r5, r0]
_021FBAB8:
	ldr r0, _021FBCA8 ; =0x000008A4
	ldr r0, [r5, r0]
	bl GF3dRender_AllocAndLoadTexResources
	cmp r0, #0
	bne _021FBAC8
	bl GF_AssertFail
_021FBAC8:
	ldr r1, _021FBCA4 ; =0x0000089C
	ldr r0, [r5, r1]
	add r1, #8
	ldr r1, [r5, r1]
	bl ov01_021FB878
	ldr r0, _021FBCAC ; =0x000008A8
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021FBAF6
	bl GF3dRender_AllocAndLoadTexResources
	cmp r0, #0
	bne _021FBAE8
	bl GF_AssertFail
_021FBAE8:
	mov r1, #0x8a
	lsl r1, r1, #4
	ldr r0, [r5, r1]
	add r1, #8
	ldr r1, [r5, r1]
	bl ov01_021FB878
_021FBAF6:
	ldr r0, _021FBCB0 ; =0x000008B4
	ldrh r1, [r5, r0]
	ldr r0, _021FBCB4 ; =0x0000FFFF
	cmp r1, r0
	beq _021FBB06
	add r0, r4, #0
	bl ov01_0220463C
_021FBB06:
	mov r2, #0
	ldr r0, _021FBC9C ; =0x00000226
	add r3, r5, #0
	add r1, r2, #0
_021FBB0E:
	add r2, r2, #1
	str r1, [r3, #4]
	add r3, r3, #4
	cmp r2, r0
	blt _021FBB0E
	ldr r0, _021FBCB8 ; =0x000008AC
	str r1, [r5, r0]
	ldr r0, [sp, #0x10]
	bl MapPropAnimationManager_GetAnimListNARCFileCount
	str r0, [sp, #0x1c]
	mov r0, #0
	str r0, [sp, #0x20]
	ldrh r0, [r6, #0xc]
	cmp r0, #0
	ble _021FBBEC
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x18]
_021FBB32:
	ldr r0, _021FBC98 ; =0x000008BC
	ldr r1, [r5, r0]
	ldr r0, [sp, #0x18]
	add r0, r1, r0
	ldrh r4, [r0, #2]
	lsl r0, r4, #2
	add r0, r5, r0
	str r0, [sp, #0x14]
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _021FBB4C
	bl GF_AssertFail
_021FBB4C:
	lsl r0, r4, #2
	add r7, r5, r0
	ldr r0, [r6, #8]
	add r1, r4, #0
	mov r2, #4
	bl NARC_AllocAndReadWholeMember
	str r0, [r7, #4]
	mov r0, #0x23
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	add r1, r4, #0
	add r2, sp, #0x24
	bl NARC_ReadWholeMember
	ldr r1, _021FBCAC ; =0x000008A8
	ldr r0, [r7, #4]
	ldr r1, [r5, r1]
	bl GF3dRender_BindModelSet
	cmp r0, #0
	bne _021FBB7C
	bl GF_AssertFail
_021FBB7C:
	add r0, sp, #0x24
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _021FBBDA
	ldr r0, [sp, #0xc]
	add r1, r4, #0
	bl ov01_022040A4
	add r7, r0, #0
	ldr r0, [sp, #0x1c]
	cmp r4, r0
	bge _021FBBDA
	ldr r0, [sp, #0x14]
	ldr r0, [r0, #4]
	bl NNS_G3dGetMdlSet
	cmp r0, #0
	beq _021FBBC0
	add r1, r0, #0
	add r1, #8
	beq _021FBBB4
	ldrb r2, [r0, #9]
	cmp r2, #0
	bls _021FBBB4
	ldrh r2, [r0, #0xe]
	add r1, r1, r2
	add r1, r1, #4
	b _021FBBB6
_021FBBB4:
	mov r1, #0
_021FBBB6:
	cmp r1, #0
	beq _021FBBC0
	ldr r1, [r1]
	add r1, r0, r1
	b _021FBBC2
_021FBBC0:
	mov r1, #0
_021FBBC2:
	add r0, sp, #0x24
	str r0, [sp]
	ldr r0, [sp, #0x10]
	ldr r3, _021FBCAC ; =0x000008A8
	str r0, [sp, #4]
	ldr r0, [sp, #0x150]
	add r2, r7, #0
	str r0, [sp, #8]
	ldr r3, [r5, r3]
	add r0, r4, #0
	bl ov01_021E8F3C
_021FBBDA:
	ldr r0, [sp, #0x18]
	ldrh r1, [r6, #0xc]
	add r0, r0, #2
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r0, r0, #1
	str r0, [sp, #0x20]
	cmp r0, r1
	blt _021FBB32
_021FBBEC:
	ldr r0, [r5, #4]
	cmp r0, #0
	bne _021FBC2C
	ldr r0, [r6, #8]
	mov r1, #0
	mov r2, #4
	bl NARC_AllocAndReadWholeMember
	str r0, [r5, #4]
	ldr r0, [sp, #0xc]
	mov r1, #0
	bl ov01_022040A4
	ldr r0, [r5, #4]
	bl NNS_G3dGetTex
	add r4, r0, #0
	beq _021FBC2C
	bl GF3dRender_AllocAndLoadTexResources
	cmp r0, #0
	bne _021FBC1C
	bl GF_AssertFail
_021FBC1C:
	ldr r0, [r5, #4]
	add r1, r4, #0
	bl GF3dRender_BindModelSet
	cmp r0, #0
	bne _021FBC2C
	bl GF_AssertFail
_021FBC2C:
	ldr r0, [r6, #8]
	bl NARC_Delete
	ldr r2, _021FBCBC ; =0x04000060
	ldr r0, _021FBCC0 ; =0xFFFFCFFF
	ldrh r1, [r2]
	and r1, r0
	mov r0, #0x20
	orr r0, r1
	strh r0, [r2]
	ldr r0, _021FBCC4 ; =0x000008B7
	ldrb r0, [r5, r0]
	cmp r0, #0
	bne _021FBC50
	ldr r0, _021FBCC8 ; =ov01_02208BA0
	bl G3X_SetEdgeColorTable
	b _021FBC56
_021FBC50:
	ldr r0, _021FBCCC ; =ov01_02208BB0
	bl G3X_SetEdgeColorTable
_021FBC56:
	bl ov01_021EA724
	ldr r1, _021FBCB8 ; =0x000008AC
	str r0, [r5, r1]
	add r1, #0xa
	ldrb r0, [r5, r1]
	cmp r0, #0
	add r0, sp, #0x3c
	beq _021FBC70
	ldr r1, _021FBCD0 ; =ov01_02209A88
	bl sprintf
	b _021FBC76
_021FBC70:
	ldr r1, _021FBCD4 ; =ov01_02209AB4
	bl sprintf
_021FBC76:
	ldr r1, _021FBCB8 ; =0x000008AC
	add r0, sp, #0x3c
	ldr r1, [r5, r1]
	bl ov01_021EA73C
	ldr r0, _021FBC94 ; =0x000008B8
	ldr r0, [r5, r0]
	bl Heap_Free
	ldr r0, _021FBC94 ; =0x000008B8
	mov r1, #0
	str r1, [r5, r0]
	add sp, #0x13c
	pop {r4, r5, r6, r7, pc}
	nop
_021FBC94: .word 0x000008B8
_021FBC98: .word 0x000008BC
_021FBC9C: .word 0x00000226
_021FBCA0: .word 0x000008B2
_021FBCA4: .word 0x0000089C
_021FBCA8: .word 0x000008A4
_021FBCAC: .word 0x000008A8
_021FBCB0: .word 0x000008B4
_021FBCB4: .word 0x0000FFFF
_021FBCB8: .word 0x000008AC
_021FBCBC: .word 0x04000060
_021FBCC0: .word 0xFFFFCFFF
_021FBCC4: .word 0x000008B7
_021FBCC8: .word ov01_02208BA0
_021FBCCC: .word ov01_02208BB0
_021FBCD0: .word ov01_02209A88
_021FBCD4: .word ov01_02209AB4
	thumb_func_end AreaDataManager_Load
