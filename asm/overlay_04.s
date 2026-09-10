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

	thumb_func_start ov04_02253E20
ov04_02253E20: ; 0x02253E20
	push {r3, r4, r5, r6, lr}
	sub sp, #0x24
	add r5, r0, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #4
	bl Save_Gymmick_AssertMagic_GetData
	add r3, sp, #0x18
	ldr r6, _02253ECC ; =_02257328
	add r4, r0, #0
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	mov r1, #0x6f
	str r0, [r3]
	ldr r0, [r5, #0x54]
	mov r3, #0
	str r0, [sp]
	add r0, r5, #0
	add r0, #0x9c
	ldr r0, [r0]
	bl MapPropManager_LoadOne
	mov r3, #3
	mov r0, #2
	str r3, [sp]
	lsl r0, r0, #0x10
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0x98
	ldr r0, [r0]
	mov r1, #0xe
	str r0, [sp, #8]
	mov r0, #0
	mov r2, #0x13
	bl ov01_021FB3E4
	ldr r0, [r4]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _02253E80
	cmp r0, #1
	beq _02253E86
	b _02253E8C
_02253E80:
	mov r4, #2
	lsl r4, r4, #0x10
	b _02253E94
_02253E86:
	mov r4, #0x1f
	lsl r4, r4, #0x10
	b _02253E94
_02253E8C:
	bl GF_AssertFail
	mov r4, #2
	lsl r4, r4, #0x10
_02253E94:
	add r0, r5, #0
	add r0, #0x9c
	ldr r0, [r0]
	mov r1, #0x6f
	bl MapPropManager_FindMapPropByBuildModel
	add r6, r0, #0
	add r0, sp, #0xc
	add r1, r6, #0
	bl MapProp_GetTranslation
	add r0, r6, #0
	add r1, sp, #0xc
	str r4, [sp, #0x10]
	bl MapProp_SetTranslation
	add r5, #0x98
	ldr r2, [r5]
	mov r0, #0
	add r1, r4, #0
	bl ov01_021FB4A0
	ldr r0, _02253ED0 ; =ov04_02257334
	bl G3X_SetEdgeColorTable
	add sp, #0x24
	pop {r3, r4, r5, r6, pc}
	nop
_02253ECC: .word _02257328
_02253ED0: .word ov04_02257334
	thumb_func_end ov04_02253E20


	thumb_func_start ov04_02253ED4
ov04_02253ED4: ; 0x02253ED4
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0xb
	mov r1, #8
	bl Heap_AllocAtEnd
	add r4, r0, #0
	mov r0, #0
	str r0, [r4]
	add r0, r5, #0
	str r5, [r4, #4]
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #4
	bl Save_Gymmick_AssertMagic_GetData
	add r6, r0, #0
	ldr r0, [r5, #0x40]
	add r1, sp, #0
	bl PlayerAvatar_CopyPositionVector
	mov r0, #2
	ldr r1, [sp, #4]
	lsl r0, r0, #0x10
	cmp r1, r0
	ldr r0, [r5, #0x10]
	bne _02253F20
	ldr r1, _02253F30 ; =ov04_02253F38
	add r2, r4, #0
	bl TaskManager_Call
	mov r0, #1
	add sp, #0xc
	str r0, [r6]
	pop {r3, r4, r5, r6, pc}
_02253F20:
	ldr r1, _02253F34 ; =ov04_02253F94
	add r2, r4, #0
	bl TaskManager_Call
	mov r0, #0
	str r0, [r6]
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_02253F30: .word ov04_02253F38
_02253F34: .word ov04_02253F94
	thumb_func_end ov04_02253ED4


	thumb_func_start ov04_02253F38
ov04_02253F38: ; 0x02253F38
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bl TaskManager_GetFieldSystem
	add r5, r0, #0
	add r0, r4, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldr r1, [r4]
	cmp r1, #0
	beq _02253F5A
	cmp r1, #1
	beq _02253F6C
	cmp r1, #5
	beq _02253F7E
	b _02253F86
_02253F5A:
	ldr r0, [r5, #0x10]
	ldr r1, _02253F8C ; =ov01_02205A60
	mov r2, #0
	bl TaskManager_Call
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02253F86
_02253F6C:
	ldr r0, _02253F90 ; =ov04_02253FF0
	add r1, r4, #0
	mov r2, #0
	bl SysTask_CreateOnMainQueue
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02253F86
_02253F7E:
	bl Heap_Free
	mov r0, #1
	pop {r3, r4, r5, pc}
_02253F86:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_02253F8C: .word ov01_02205A60
_02253F90: .word ov04_02253FF0
	thumb_func_end ov04_02253F38


	thumb_func_start ov04_02253F94
ov04_02253F94: ; 0x02253F94
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bl TaskManager_GetFieldSystem
	add r5, r0, #0
	add r0, r4, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldr r1, [r4]
	cmp r1, #0
	beq _02253FB6
	cmp r1, #1
	beq _02253FC8
	cmp r1, #5
	beq _02253FDA
	b _02253FE2
_02253FB6:
	ldr r0, [r5, #0x10]
	ldr r1, _02253FE8 ; =ov01_02205A60
	mov r2, #0
	bl TaskManager_Call
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02253FE2
_02253FC8:
	ldr r0, _02253FEC ; =ov04_022540C0
	add r1, r4, #0
	mov r2, #0
	bl SysTask_CreateOnMainQueue
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02253FE2
_02253FDA:
	bl Heap_Free
	mov r0, #1
	pop {r3, r4, r5, pc}
_02253FE2:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_02253FE8: .word ov01_02205A60
_02253FEC: .word ov04_022540C0
	thumb_func_end ov04_02253F94


	thumb_func_start ov04_02253FF0
ov04_02253FF0: ; 0x02253FF0
	push {r4, r5, r6, lr}
	sub sp, #0x18
	add r5, r1, #0
	add r6, r0, #0
	ldr r0, [r5]
	ldr r4, [r5, #4]
	cmp r0, #2
	beq _0225400C
	cmp r0, #3
	beq _02254026
	cmp r0, #4
	beq _0225408C
	add sp, #0x18
	pop {r4, r5, r6, pc}
_0225400C:
	ldr r0, [r4, #0x40]
	mov r1, #0
	bl PlayerAvatar_ToggleAutomaticHeightUpdating
	mov r0, #SEQ_SE_DP_ELEBETA>>4
	lsl r0, r0, #4
	bl PlaySE
	ldr r0, [r5]
	add sp, #0x18
	add r0, r0, #1
	str r0, [r5]
	pop {r4, r5, r6, pc}
_02254026:
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	mov r1, #0x6f
	bl MapPropManager_FindMapPropByBuildModel
	add r6, r0, #0
	add r0, sp, #0xc
	add r1, r6, #0
	bl MapProp_GetTranslation
	mov r0, #1
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0x10
	add r1, r1, r0
	mov r0, #0x1f
	lsl r0, r0, #0x10
	str r1, [sp, #0x10]
	cmp r1, r0
	blt _02254060
	str r0, [sp, #0x10]
	mov r0, #0x61
	lsl r0, r0, #4
	mov r1, #0
	bl StopSE
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
_02254060:
	ldr r0, [r4, #0x40]
	add r1, sp, #0
	bl PlayerAvatar_CopyPositionVector
	mov r0, #1
	ldr r1, [sp, #4]
	lsl r0, r0, #0x10
	add r1, r1, r0
	str r1, [sp, #4]
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_SetMapObjectYPosition
	ldr r1, [sp, #4]
	add r0, r4, #0
	bl ov01_02205A34
	add r0, r6, #0
	add r1, sp, #0xc
	bl MapProp_SetTranslation
	add sp, #0x18
	pop {r4, r5, r6, pc}
_0225408C:
	add r2, r4, #0
	add r2, #0x98
	mov r1, #0x1f
	ldr r2, [r2]
	mov r0, #0
	lsl r1, r1, #0x10
	bl ov01_021FB4A0
	ldr r0, [r4, #0x40]
	mov r1, #1
	bl PlayerAvatar_ToggleAutomaticHeightUpdatingImmediate
	ldr r0, _022540BC ; =SEQ_SE_DP_KI_GASYAN
	bl PlaySE
	add r0, r6, #0
	bl SysTask_Destroy
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	add sp, #0x18
	pop {r4, r5, r6, pc}
	nop
_022540BC: .word SEQ_SE_DP_KI_GASYAN
	thumb_func_end ov04_02253FF0


	thumb_func_start ov04_022540C0
ov04_022540C0: ; 0x022540C0
	push {r4, r5, r6, lr}
	sub sp, #0x18
	add r5, r1, #0
	add r6, r0, #0
	ldr r0, [r5]
	ldr r4, [r5, #4]
	cmp r0, #2
	beq _022540DC
	cmp r0, #3
	beq _022540F6
	cmp r0, #4
	beq _0225415C
	add sp, #0x18
	pop {r4, r5, r6, pc}
_022540DC:
	ldr r0, [r4, #0x40]
	mov r1, #0
	bl PlayerAvatar_ToggleAutomaticHeightUpdating
	mov r0, #SEQ_SE_DP_ELEBETA>>4
	lsl r0, r0, #4
	bl PlaySE
	ldr r0, [r5]
	add sp, #0x18
	add r0, r0, #1
	str r0, [r5]
	pop {r4, r5, r6, pc}
_022540F6:
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	mov r1, #0x6f
	bl MapPropManager_FindMapPropByBuildModel
	add r6, r0, #0
	add r0, sp, #0xc
	add r1, r6, #0
	bl MapProp_GetTranslation
	mov r0, #1
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0x10
	sub r2, r1, r0
	lsl r1, r0, #1
	str r2, [sp, #0x10]
	cmp r2, r1
	bgt _02254130
	lsl r0, r0, #1
	str r0, [sp, #0x10]
	mov r0, #0x61
	lsl r0, r0, #4
	mov r1, #0
	bl StopSE
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
_02254130:
	ldr r0, [r4, #0x40]
	add r1, sp, #0
	bl PlayerAvatar_CopyPositionVector
	mov r0, #1
	ldr r1, [sp, #4]
	lsl r0, r0, #0x10
	sub r1, r1, r0
	str r1, [sp, #4]
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_SetMapObjectYPosition
	ldr r1, [sp, #4]
	add r0, r4, #0
	bl ov01_02205A34
	add r0, r6, #0
	add r1, sp, #0xc
	bl MapProp_SetTranslation
	add sp, #0x18
	pop {r4, r5, r6, pc}
_0225415C:
	add r2, r4, #0
	add r2, #0x98
	mov r1, #2
	ldr r2, [r2]
	mov r0, #0
	lsl r1, r1, #0x10
	bl ov01_021FB4A0
	ldr r0, [r4, #0x40]
	mov r1, #1
	bl PlayerAvatar_ToggleAutomaticHeightUpdatingImmediate
	ldr r0, _0225418C ; =SEQ_SE_DP_KI_GASYAN
	bl PlaySE
	add r0, r6, #0
	bl SysTask_Destroy
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	add sp, #0x18
	pop {r4, r5, r6, pc}
	nop
_0225418C: .word SEQ_SE_DP_KI_GASYAN
	thumb_func_end ov04_022540C0


	thumb_func_start ov04_02254190
ov04_02254190: ; 0x02254190
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r0, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #5
	bl Save_Gymmick_AssertMagic_GetData
	add r7, r0, #0
	mov r0, #4
	mov r1, #0x54
	bl Heap_Alloc
	ldr r1, [r4, #4]
	mov r2, #0x54
	str r0, [r1, #0x24]
	ldr r0, [r4, #4]
	mov r1, #0
	ldr r0, [r0, #0x24]
	bl MI_CpuFill8
	ldr r0, [r4, #4]
	mov r6, #0
	ldr r5, [r0, #0x24]
_022541C4:
	mov r1, #0
	add r0, sp, #4
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldrb r0, [r7, r6]
	ldr r1, _02254400 ; =ov04_022575D4
	mov r3, #0
	lsl r2, r0, #2
	ldr r0, _02254400 ; =ov04_022575D4
	ldrh r1, [r1, r2]
	add r0, r0, r2
	ldrh r0, [r0, #2]
	lsl r2, r1, #0x10
	mov r1, #2
	lsl r1, r1, #0xe
	lsl r0, r0, #0x10
	str r2, [sp, #4]
	add r1, r2, r1
	str r1, [sp, #4]
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x54]
	mov r1, #0x76
	str r0, [sp]
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	add r2, sp, #4
	bl MapPropManager_LoadOne
	str r0, [r5, #4]
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #4
	blt _022541C4
	ldr r0, [r7, #4]
	cmp r0, #3
	bls _02254212
	b _022543F6
_02254212:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225421E: ; jump table
	.short _02254226 - _0225421E - 2 ; case 0
	.short _0225429A - _0225421E - 2 ; case 1
	.short _0225430E - _0225421E - 2 ; case 2
	.short _02254382 - _0225421E - 2 ; case 3
_02254226:
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x73
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x73
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x74
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x74
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x7a
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x7a
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x75
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x75
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_0225429A:
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x73
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x73
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x74
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x74
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x7a
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x7a
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x75
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x75
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_0225430E:
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x73
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x73
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x74
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x74
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x7a
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x7a
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x75
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x75
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_02254382:
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x73
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x73
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x74
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x74
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x7a
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x7a
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x75
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x75
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_022543F6:
	bl GF_AssertFail
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02254400: .word ov04_022575D4
	thumb_func_end ov04_02254190


	thumb_func_start FlipAzaleaGymSwitch
FlipAzaleaGymSwitch: ; 0x02254404
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r6, r1, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #5
	bl Save_Gymmick_AssertMagic_GetData
	add r4, r0, #0
	ldr r0, _02254560 ; =SEQ_SE_DP_KI_GASYAN
	bl PlaySE
	cmp r6, #0
	bne _022544B6
	ldr r2, [r4, #4]
	mov r1, #1
	add r0, r2, #0
	and r0, r1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r2, #0
	eor r0, r1
	str r0, [r4, #4]
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x74
	bl Field3dObjectList_GetRenderObjectByID
	add r7, r0, #0
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x75
	bl Field3dObjectList_GetRenderObjectByID
	str r0, [sp, #4]
	ldr r0, [r5, #0x54]
	add r1, r7, #0
	mov r2, #0x74
	add r3, r6, #0
	bl MapPropAnimationManager_RemoveAnimationFromRenderObj
	ldr r0, [r5, #0x54]
	ldr r1, [sp, #4]
	mov r2, #0x75
	add r3, r6, #0
	bl MapPropAnimationManager_RemoveAnimationFromRenderObj
	ldr r0, [r4, #4]
	mov r2, #1
	and r0, r2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	ldr r0, [r5, #0x54]
	beq _02254498
	str r0, [sp]
	mov r0, #0x74
	add r1, r2, #0
	add r3, r7, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	ldr r0, [r5, #0x54]
	mov r1, #1
	str r0, [sp]
	ldr r3, [sp, #4]
	mov r0, #0x75
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	b _02254550
_02254498:
	str r0, [sp]
	mov r0, #0x74
	mov r1, #0
	add r3, r7, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	ldr r0, [r5, #0x54]
	ldr r3, [sp, #4]
	str r0, [sp]
	mov r0, #0x75
	mov r1, #0
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	b _02254550
_022544B6:
	cmp r6, #1
	bne _0225454C
	ldr r1, [r4, #4]
	mov r0, #1
	asr r2, r1, #1
	and r0, r2
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	mov r0, #2
	eor r0, r1
	str r0, [r4, #4]
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x73
	bl Field3dObjectList_GetRenderObjectByID
	add r7, r0, #0
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x7a
	bl Field3dObjectList_GetRenderObjectByID
	str r0, [sp, #8]
	ldr r0, [r5, #0x54]
	add r1, r7, #0
	mov r2, #0x73
	add r3, r6, #0
	bl MapPropAnimationManager_RemoveAnimationFromRenderObj
	ldr r0, [r5, #0x54]
	ldr r1, [sp, #8]
	mov r2, #0x7a
	add r3, r6, #0
	bl MapPropAnimationManager_RemoveAnimationFromRenderObj
	ldr r0, [r4, #4]
	mov r2, #1
	asr r0, r0, #1
	and r0, r2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	ldr r0, [r5, #0x54]
	beq _0225452E
	str r0, [sp]
	mov r0, #0x73
	add r1, r2, #0
	add r3, r7, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	ldr r0, [r5, #0x54]
	mov r1, #1
	str r0, [sp]
	ldr r3, [sp, #8]
	mov r0, #0x7a
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	b _02254550
_0225452E:
	str r0, [sp]
	mov r0, #0x73
	mov r1, #0
	add r3, r7, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	ldr r0, [r5, #0x54]
	ldr r3, [sp, #8]
	str r0, [sp]
	mov r0, #0x7a
	mov r1, #0
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	b _02254550
_0225454C:
	bl GF_AssertFail
_02254550:
	ldr r0, [r5, #0x10]
	ldr r1, _02254564 ; =ov04_02254CA4
	mov r2, #0
	bl TaskManager_Call
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_02254560: .word SEQ_SE_DP_KI_GASYAN
_02254564: .word ov04_02254CA4
	thumb_func_end FlipAzaleaGymSwitch


	thumb_func_start BeginAzaleaGymSpinarakRide
BeginAzaleaGymSpinarakRide: ; 0x02254568
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r0, [r6, #4]
	add r5, r1, #0
	ldr r4, [r0, #0x24]
	mov r0, #0xb
	mov r1, #8
	bl Heap_AllocAtEnd
	add r7, r0, #0
	mov r1, #0
	str r1, [r7]
	str r6, [r7, #4]
	strb r5, [r4, #0x18]
	str r1, [r4, #0x30]
	strb r1, [r4, #0x14]
	mov r0, #1
	strb r0, [r4, #0x16]
	add r0, r6, #0
	str r1, [r4, #0x1c]
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #5
	bl Save_Gymmick_AssertMagic_GetData
	add r2, r0, #0
	ldr r0, [r2, #4]
	mov r1, #0
	strb r0, [r4, #0x15]
_022545A6:
	ldrb r0, [r2, r1]
	cmp r5, r0
	bne _022545B0
	strb r1, [r4, #0x17]
	b _022545B6
_022545B0:
	add r1, r1, #1
	cmp r1, #4
	blt _022545A6
_022545B6:
	cmp r1, #4
	bne _022545C0
	bl GF_AssertFail
	pop {r3, r4, r5, r6, r7, pc}
_022545C0:
	cmp r5, #0xb
	bhi _02254600
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022545D0: ; jump table
	.short _02254600 - _022545D0 - 2 ; case 0
	.short _02254600 - _022545D0 - 2 ; case 1
	.short _02254600 - _022545D0 - 2 ; case 2
	.short _022545E8 - _022545D0 - 2 ; case 3
	.short _022545E8 - _022545D0 - 2 ; case 4
	.short _022545E8 - _022545D0 - 2 ; case 5
	.short _02254600 - _022545D0 - 2 ; case 6
	.short _02254600 - _022545D0 - 2 ; case 7
	.short _02254600 - _022545D0 - 2 ; case 8
	.short _022545E8 - _022545D0 - 2 ; case 9
	.short _022545E8 - _022545D0 - 2 ; case 10
	.short _022545E8 - _022545D0 - 2 ; case 11
_022545E8:
	mov r1, #1
	ldr r0, _02254634 ; =ov04_022575A4
	lsl r2, r5, #2
	strb r1, [r4, #0x19]
	ldr r0, [r0, r2]
	ldrb r2, [r4, #0x15]
	lsl r2, r2, #3
	ldrh r0, [r0, r2]
	sub r0, r0, #1
	strb r0, [r4, #0x1a]
	strb r1, [r4, #0x1b]
	b _02254608
_02254600:
	mov r0, #0
	strb r0, [r4, #0x19]
	strb r0, [r4, #0x1a]
	strb r0, [r4, #0x1b]
_02254608:
	ldr r0, _02254634 ; =ov04_022575A4
	lsl r1, r5, #2
	ldr r1, [r0, r1]
	ldrb r0, [r4, #0x15]
	lsl r0, r0, #3
	add r0, r1, r0
	ldr r2, [r0, #4]
	ldrb r0, [r4, #0x1a]
	lsl r1, r0, #2
	add r0, r2, r1
	ldrh r1, [r2, r1]
	add r2, r7, #0
	lsl r1, r1, #0x10
	str r1, [r4, #0x2c]
	ldrh r0, [r0, #2]
	ldr r1, _02254638 ; =ov04_0225463C
	lsl r0, r0, #0x10
	str r0, [r4, #0x34]
	ldr r0, [r6, #0x10]
	bl TaskManager_Call
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02254634: .word ov04_022575A4
_02254638: .word ov04_0225463C
	thumb_func_end BeginAzaleaGymSpinarakRide


	thumb_func_start ov04_0225463C
ov04_0225463C: ; 0x0225463C
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bl TaskManager_GetFieldSystem
	add r5, r0, #0
	add r0, r4, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldr r1, [r4]
	cmp r1, #0
	beq _0225465E
	cmp r1, #1
	beq _02254670
	cmp r1, #0xa
	beq _02254682
	b _0225468A
_0225465E:
	ldr r0, [r5, #0x10]
	ldr r1, _02254690 ; =ov01_02205A60
	mov r2, #0
	bl TaskManager_Call
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225468A
_02254670:
	ldr r0, _02254694 ; =ov04_02254724
	add r1, r4, #0
	mov r2, #0
	bl SysTask_CreateOnMainQueue
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0225468A
_02254682:
	bl Heap_Free
	mov r0, #1
	pop {r3, r4, r5, pc}
_0225468A:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_02254690: .word ov01_02205A60
_02254694: .word ov04_02254724
	thumb_func_end ov04_0225463C


	thumb_func_start ov04_02254698
ov04_02254698: ; 0x02254698
	push {r4}
	sub sp, #0xc
	add r3, r0, #0
	ldrh r4, [r2]
	ldrh r0, [r1]
	ldrh r2, [r2, #2]
	sub r0, r4, r0
	lsl r0, r0, #0xc
	str r0, [sp]
	ldrh r0, [r1, #2]
	sub r0, r2, r0
	lsl r0, r0, #0xc
	str r0, [sp, #8]
	mov r0, #0
	add r2, sp, #0
	str r0, [sp, #4]
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	str r0, [r3]
	add sp, #0xc
	pop {r4}
	bx lr
	.balign 4, 0
	thumb_func_end ov04_02254698


	thumb_func_start ov04_022546C8
ov04_022546C8: ; 0x022546C8
	ldr r2, [r0]
	cmp r2, #0
	blt _022546D2
	mov r2, #1
	b _022546D4
_022546D2:
	mov r2, #0
_022546D4:
	str r2, [r1]
	ldr r0, [r0, #8]
	cmp r0, #0
	blt _022546E2
	mov r0, #1
	str r0, [r1, #4]
	bx lr
_022546E2:
	mov r0, #0
	str r0, [r1, #4]
	bx lr
	thumb_func_end ov04_022546C8


	thumb_func_start ov04_022546E8
ov04_022546E8: ; 0x022546E8
	push {r3, r4}
	lsl r3, r3, #0x10
	add r1, r1, r2
	mov r4, #0
	cmp r3, r1
	bne _022546F8
	mov r4, #1
	b _0225470A
_022546F8:
	cmp r0, #0
	beq _02254704
	cmp r1, r3
	ble _0225470A
	mov r4, #2
	b _0225470A
_02254704:
	cmp r1, r3
	bge _0225470A
	mov r4, #2
_0225470A:
	add r0, r4, #0
	pop {r3, r4}
	bx lr
	thumb_func_end ov04_022546E8
