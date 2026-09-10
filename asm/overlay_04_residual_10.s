#include "fielddata/script/scr_seq/event_T27GYM0101.h"
#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_04.inc"
	.include "global.inc"

	.text
	.public BeginAzaleaGymSpinarakRide
	.public FlipAzaleaGymSwitch
	.public _02257328
	.public ov04_02253E20
	.public ov04_02253ED4
	.public ov04_02253F38
	.public ov04_02253F94
	.public ov04_02253FF0
	.public ov04_022540C0
	.public ov04_02254190
	.public ov04_0225463C
	.public ov04_02254698
	.public ov04_022546C8
	.public ov04_022546E8
	.public ov04_02254724
	.public ov04_02254CBC
	.public ov04_02254D98
	.public ov04_02254DE0
	.public ov04_02254E20
	.public ov04_02254E50
	.public ov04_02254F44
	.public ov04_02254F8C
	.public ov04_02255090
	.public ov04_022550D4
	.public ov04_02255140
	.public ov04_02255480
	.public ov04_022554FC
	.public ov04_022556AC
	.public ov04_02255708
	.public ov04_02255804
	.public ov04_02255858
	.public ov04_022558B4
	.public ov04_02255910
	.public ov04_02255960
	.public ov04_022559C8
	.public ov04_02255AC4
	.public ov04_02255CBC
	.public ov04_02255D34
	.public ov04_02255D88
	.public ov04_02255FC0
	.public ov04_02256058
	.public ov04_0225609C
	.public ov04_022560D4
	.public ov04_02256278
	.public ov04_02256304
	.public ov04_022563C4
	.public ov04_0225640C
	.public ov04_022564A0
	.public ov04_02256650
	.public ov04_022566A0
	.public ov04_022566EC
	.public ov04_02256758
	.public ov04_0225686C
	.public ov04_02256950
	.public ov04_02256A90
	.public ov04_02256AC4
	.public ov04_02256B64
	.public ov04_02256BA0
	.public ov04_02256BE4
	.public ov04_02256C20
	.public ov04_02256D00
	.public ov04_02256D68
	.public ov04_02256DFC
	.public ov04_02256E60
	.public ov04_02256ED8
	.public ov04_02256F00
	.public ov04_02256F50
	.public ov04_022570EC
	.public ov04_02257148
	.public ov04_02257240
	.public ov04_02257334
	.public ov04_02257344
	.public ov04_02257350
	.public ov04_0225735C
	.public ov04_0225736C
	.public ov04_0225737C
	.public ov04_02257394
	.public ov04_022573AC
	.public ov04_022573C4
	.public ov04_022573E4
	.public ov04_02257404
	.public ov04_02257424
	.public ov04_02257444
	.public ov04_02257464
	.public ov04_02257484
	.public ov04_022574A4
	.public ov04_022574C4
	.public ov04_022574E4
	.public ov04_02257504
	.public ov04_02257524
	.public ov04_02257544
	.public ov04_02257564
	.public ov04_02257584
	.public ov04_022575A4
	.public ov04_022575D4
	.public ov04_02257614
	.public ov04_02257618
	.public ov04_02257620
	.public ov04_0225762C
	.public ov04_02257638
	.public ov04_02257648
	.public ov04_02257660
	.public ov04_0225766C
	.public ov04_02257670
	.public ov04_02257674
	.public ov04_02257676
	.public ov04_02257677
	.public ov04_02257B1C
	.public ov04_02257B28
	.public ov04_02257B40
	.public sMortyGymTrainerObjectIds

	.public ov04_02254710
	.public ov04_02254CA4
	.public ov04_02254D84
	.public ov04_02254DD0
	.public ov04_0225507C
	.public ov04_022554C4
	.public ov04_022554E0
	.public ov04_022558D0
	.public ov04_02256044
	.public ov04_022563B0
	.public ov04_02256734
	.public ov04_022568F0
	.public ov04_02256920
	.public ov04_02256A54
	.public ov04_02256B3C
	.public ov04_02256E48
	.public ov04_02256EB0
	.public ov04_022572E0
	.public ov04_02257308
	.public ov04_MortyGymTrainerObjectToCandleIdx

	thumb_func_start ov04_02256058
ov04_02256058: ; 0x02256058
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	add r4, r0, #0
	bl Save_Gymmick_GetType
	cmp r0, #2
	beq _02256072
	mov r0, #0
	pop {r3, r4, r5, pc}
_02256072:
	add r0, r4, #0
	mov r1, #2
	bl Save_Gymmick_AssertMagic_GetData
	ldr r1, [r5, #4]
	ldr r1, [r1, #0x24]
	cmp r1, #0
	bne _02256086
	mov r0, #0
	pop {r3, r4, r5, pc}
_02256086:
	ldr r0, [r0]
	cmp r0, #0
	bne _02256096
	add r0, r1, #0
	bl ov04_0225609C
	mov r0, #1
	pop {r3, r4, r5, pc}
_02256096:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov04_02256058


	thumb_func_start ov04_0225609C
ov04_0225609C: ; 0x0225609C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5]
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #2
	bl Save_Gymmick_AssertMagic_GetData
	add r4, r0, #0
	mov r0, #0xb
	mov r1, #0xc
	bl Heap_AllocAtEnd
	add r2, r0, #0
	mov r0, #0
	str r0, [r2]
	mov r0, #1
	str r0, [r4]
	ldr r0, [r5]
	ldr r1, _022560D0 ; =ov04_022560D4
	ldr r0, [r0, #0x10]
	bl TaskManager_Call
	pop {r3, r4, r5, pc}
	.balign 4, 0
_022560D0: .word ov04_022560D4
	thumb_func_end ov04_0225609C


	thumb_func_start ov04_022560D4
ov04_022560D4: ; 0x022560D4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x58
	add r4, r0, #0
	bl TaskManager_GetFieldSystem
	add r6, r0, #0
	add r0, r4, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	ldr r0, [r4]
	cmp r0, #6
	bls _022560F6
	b _0225626C
_022560F6:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02256102: ; jump table
	.short _02256110 - _02256102 - 2 ; case 0
	.short _02256168 - _02256102 - 2 ; case 1
	.short _02256180 - _02256102 - 2 ; case 2
	.short _022561CE - _02256102 - 2 ; case 3
	.short _022561E8 - _02256102 - 2 ; case 4
	.short _02256248 - _02256102 - 2 ; case 5
	.short _02256260 - _02256102 - 2 ; case 6
_02256110:
	ldr r1, [r6, #0x24]
	add r0, sp, #0xc
	bl Camera_GetAngle
	add r0, sp, #4
	ldrh r1, [r0, #8]
	strh r1, [r0, #0x18]
	ldrh r1, [r0, #0xa]
	strh r1, [r0, #0x1a]
	ldrh r1, [r0, #0xc]
	strh r1, [r0, #0x1c]
	ldrh r1, [r0, #0xe]
	strh r1, [r0, #0x1e]
	ldrh r1, [r0, #0x18]
	add r0, sp, #0x44
	strh r1, [r0]
	ldr r0, [r6, #0x24]
	bl Camera_GetPerspectiveAngle
	add r1, sp, #0x44
	ldr r3, _02256274 ; =ov04_02257660
	strh r0, [r1, #2]
	ldmia r3!, {r0, r1}
	add r2, sp, #0x48
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r6, #0x24]
	bl Camera_GetDistance
	str r0, [sp, #0x54]
	ldr r1, [r6, #0x24]
	mov r0, #4
	bl CreateCameraTranslationWrapper
	str r0, [r4, #8]
	add r1, sp, #0x44
	mov r2, #0x18
	bl SetCameraTranslationPath
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225626C
_02256168:
	ldr r0, [r4, #8]
	bl IsCameraTranslationFinished
	cmp r0, #0
	beq _0225626C
	ldr r0, [r4, #8]
	bl DeleteCameraTranslationWrapper
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225626C
_02256180:
	add r0, r6, #0
	bl ov04_02256278
	mov r5, #0
	str r0, [sp]
	cmp r0, #0
	ble _022561AE
_0225618E:
	ldr r2, [r6, #0x54]
	mov r0, #0xae
	add r1, r5, #0
	bl MapPropAnimationManager_GetAnimationData
	add r7, r0, #0
	mov r1, #1
	bl MapPropAnimationData_SetAnimationLoopCount
	add r0, r7, #0
	bl MapPropAnimationData_GoToFirstAnimationFrame
	ldr r0, [sp]
	add r5, r5, #1
	cmp r5, r0
	blt _0225618E
_022561AE:
	ldr r2, [r6, #0x54]
	mov r0, #0xaf
	mov r1, #0
	bl MapPropAnimationManager_GetAnimationData
	add r5, r0, #0
	mov r1, #1
	bl MapPropAnimationData_SetAnimationLoopCount
	add r0, r5, #0
	bl MapPropAnimationData_GoToFirstAnimationFrame
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225626C
_022561CE:
	ldr r2, [r6, #0x54]
	mov r0, #0xaf
	mov r1, #0
	bl MapPropAnimationManager_GetAnimationData
	bl MapPropAnimationData_IsAnimationLoopFinished
	cmp r0, #0
	beq _0225626C
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225626C
_022561E8:
	add r1, sp, #0x24
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r1, [r6, #0x24]
	add r0, sp, #4
	bl Camera_GetAngle
	add r0, sp, #4
	ldrh r1, [r0]
	strh r1, [r0, #0x10]
	ldrh r1, [r0, #2]
	strh r1, [r0, #0x12]
	ldrh r1, [r0, #4]
	strh r1, [r0, #0x14]
	ldrh r1, [r0, #6]
	strh r1, [r0, #0x16]
	ldrh r1, [r0, #0x10]
	strh r1, [r0, #0x2c]
	ldr r0, [r6, #0x24]
	bl Camera_GetPerspectiveAngle
	add r1, sp, #4
	add r3, sp, #0x24
	strh r0, [r1, #0x2e]
	ldmia r3!, {r0, r1}
	add r2, sp, #0x34
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r6, #0x24]
	bl Camera_GetDistance
	str r0, [sp, #0x40]
	ldr r1, [r6, #0x24]
	mov r0, #4
	bl CreateCameraTranslationWrapper
	str r0, [r4, #8]
	add r1, sp, #0x30
	mov r2, #0x18
	bl SetCameraTranslationPath
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225626C
_02256248:
	ldr r0, [r4, #8]
	bl IsCameraTranslationFinished
	cmp r0, #0
	beq _0225626C
	ldr r0, [r4, #8]
	bl DeleteCameraTranslationWrapper
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225626C
_02256260:
	add r0, r4, #0
	bl Heap_Free
	add sp, #0x58
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0225626C:
	mov r0, #0
	add sp, #0x58
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02256274: .word ov04_02257660
	thumb_func_end ov04_022560D4


	thumb_func_start ov04_02256278
ov04_02256278: ; 0x02256278
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r0, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0xad
	bl Field3dObjectList_GetRenderObjectByID
	add r6, r0, #0
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0xae
	bl Field3dObjectList_GetRenderObjectByID
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0xaf
	bl Field3dObjectList_GetRenderObjectByID
	str r0, [sp, #4]
	ldr r0, [r4, #0x54]
	mov r1, #0xad
	bl MapPropAnimationManager_GetPropAnimationCount
	add r7, r0, #0
	mov r5, #0
	cmp r7, #0
	ble _022562C6
_022562B4:
	ldr r0, [r4, #0x54]
	add r1, r6, #0
	mov r2, #0xad
	add r3, r5, #0
	bl MapPropAnimationManager_RemoveAnimationFromRenderObj
	add r5, r5, #1
	cmp r5, r7
	blt _022562B4
_022562C6:
	ldr r0, [r4, #0x54]
	mov r1, #0xae
	bl MapPropAnimationManager_GetPropAnimationCount
	add r7, r0, #0
	mov r5, #0
	cmp r7, #0
	ble _022562EC
_022562D6:
	ldr r0, [r4, #0x54]
	add r1, r5, #0
	str r0, [sp]
	mov r0, #0xae
	mov r2, #1
	add r3, r6, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r5, r5, #1
	cmp r5, r7
	blt _022562D6
_022562EC:
	ldr r0, [r4, #0x54]
	ldr r3, [sp, #4]
	str r0, [sp]
	mov r0, #0xaf
	mov r1, #0
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r7, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov04_02256278


	thumb_func_start ov04_02256304
ov04_02256304: ; 0x02256304
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #3
	bl Save_Gymmick_AssertMagic_GetData
	str r0, [sp]
	mov r0, #4
	add r1, r0, #0
	bl Heap_Alloc
	ldr r1, [r5, #4]
	mov r2, #4
	str r0, [r1, #0x24]
	ldr r0, [r5, #4]
	mov r1, #0
	ldr r0, [r0, #0x24]
	bl MI_CpuFill8
	ldr r0, [r5, #4]
	ldr r0, [r0, #0x24]
	str r5, [r0]
	ldr r0, [sp]
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq _02256370
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0xc7
	bl Field3dObjectList_GetRenderObjectByID
	add r7, r0, #0
	ldr r0, [r5, #0x54]
	mov r1, #0xc7
	bl MapPropAnimationManager_GetPropAnimationCount
	add r6, r0, #0
	ldr r4, _022563AC ; =0x00000000
	beq _02256370
_0225635A:
	ldr r0, [r5, #0x54]
	add r1, r7, #0
	mov r2, #0xc7
	add r3, r4, #0
	bl MapPropAnimationManager_RemoveAnimationFromRenderObj
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, r6
	blo _0225635A
_02256370:
	ldr r0, [sp]
	ldrb r0, [r0, #3]
	cmp r0, #0
	beq _022563AA
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0xc8
	bl Field3dObjectList_GetRenderObjectByID
	add r7, r0, #0
	ldr r0, [r5, #0x54]
	mov r1, #0xc8
	bl MapPropAnimationManager_GetPropAnimationCount
	add r6, r0, #0
	ldr r4, _022563AC ; =0x00000000
	beq _022563AA
_02256394:
	ldr r0, [r5, #0x54]
	add r1, r7, #0
	mov r2, #0xc8
	add r3, r4, #0
	bl MapPropAnimationManager_RemoveAnimationFromRenderObj
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, r6
	blo _02256394
_022563AA:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022563AC: .word 0x00000000
	thumb_func_end ov04_02256304
