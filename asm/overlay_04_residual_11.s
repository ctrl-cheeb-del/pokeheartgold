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

	thumb_func_start ov04_022563C4
ov04_022563C4: ; 0x022563C4
	push {r4, lr}
	add r4, r1, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #3
	bl Save_Gymmick_AssertMagic_GetData
	ldrb r2, [r0, #2]
	cmp r2, #0
	beq _022563E6
	ldrb r1, [r0, #3]
	cmp r1, #0
	beq _022563E6
	mov r0, #4
	pop {r4, pc}
_022563E6:
	cmp r2, #0
	beq _022563F8
	ldrb r0, [r0, #1]
	cmp r4, r0
	bne _022563F4
	mov r0, #2
	pop {r4, pc}
_022563F4:
	mov r0, #3
	pop {r4, pc}
_022563F8:
	ldrb r0, [r0]
	cmp r4, r0
	bne _02256402
	mov r0, #1
	b _02256404
_02256402:
	mov r0, #0
_02256404:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov04_022563C4


	thumb_func_start ov04_0225640C
ov04_0225640C: ; 0x0225640C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r7, r1, #0
	str r2, [sp]
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #3
	bl Save_Gymmick_AssertMagic_GetData
	add r6, r0, #0
	mov r0, #0xb
	mov r1, #0x18
	bl Heap_AllocAtEnd
	add r4, r0, #0
	cmp r7, #0
	beq _02256438
	cmp r7, #1
	beq _0225646A
	b _02256494
_02256438:
	mov r0, #0xc7
	str r0, [r4, #0x10]
	ldr r0, [sp]
	cmp r0, #0
	beq _02256456
	mov r0, #2
	strb r0, [r4, #0x16]
	ldr r0, [r5, #0x10]
	ldr r1, _0225649C ; =ov04_022564A0
	add r2, r4, #0
	bl TaskManager_Call
	mov r0, #0
	strb r0, [r6, #2]
	pop {r3, r4, r5, r6, r7, pc}
_02256456:
	mov r0, #1
	strb r0, [r4, #0x16]
	ldr r0, [r5, #0x10]
	ldr r1, _0225649C ; =ov04_022564A0
	add r2, r4, #0
	bl TaskManager_Call
	mov r0, #1
	strb r0, [r6, #2]
	pop {r3, r4, r5, r6, r7, pc}
_0225646A:
	mov r0, #0xc8
	str r0, [r4, #0x10]
	ldr r0, [sp]
	cmp r0, #0
	beq _02256480
	bl GF_AssertFail
	add r0, r4, #0
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
_02256480:
	mov r0, #1
	strb r0, [r4, #0x16]
	ldr r0, [r5, #0x10]
	ldr r1, _0225649C ; =ov04_022564A0
	add r2, r4, #0
	bl TaskManager_Call
	mov r0, #1
	strb r0, [r6, #3]
	pop {r3, r4, r5, r6, r7, pc}
_02256494:
	bl GF_AssertFail
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225649C: .word ov04_022564A0
	thumb_func_end ov04_0225640C


	thumb_func_start ov04_022564A0
ov04_022564A0: ; 0x022564A0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	bl TaskManager_GetFieldSystem
	add r6, r0, #0
	add r0, r5, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	add r0, r5, #0
	bl TaskManager_GetStatePtr
	str r0, [sp, #0xc]
	ldr r0, [r0]
	cmp r0, #6
	bls _022564C4
	b _02256642
_022564C4:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022564D0: ; jump table
	.short _022564DE - _022564D0 - 2 ; case 0
	.short _0225652A - _022564D0 - 2 ; case 1
	.short _0225654A - _022564D0 - 2 ; case 2
	.short _0225656A - _022564D0 - 2 ; case 3
	.short _022565B2 - _022564D0 - 2 ; case 4
	.short _022565F2 - _022564D0 - 2 ; case 5
	.short _02256636 - _022564D0 - 2 ; case 6
_022564DE:
	ldr r0, [r4, #0x10]
	cmp r0, #0xc7
	ldr r0, [r6, #0x3c]
	bne _02256502
	mov r1, #3
	bl MapObjectManager_GetFirstActiveObjectByID
	str r0, [r4, #4]
	ldr r0, [r6, #0x3c]
	mov r1, #4
	bl MapObjectManager_GetFirstActiveObjectByID
	str r0, [r4, #8]
	ldr r0, [r6, #0x3c]
	mov r1, #5
	bl MapObjectManager_GetFirstActiveObjectByID
	b _0225651C
_02256502:
	mov r1, #0
	bl MapObjectManager_GetFirstActiveObjectByID
	str r0, [r4, #4]
	ldr r0, [r6, #0x3c]
	mov r1, #1
	bl MapObjectManager_GetFirstActiveObjectByID
	str r0, [r4, #8]
	ldr r0, [r6, #0x3c]
	mov r1, #2
	bl MapObjectManager_GetFirstActiveObjectByID
_0225651C:
	str r0, [r4, #0xc]
	mov r0, #0
	strh r0, [r4, #0x14]
	ldrb r1, [r4, #0x16]
	ldr r0, [sp, #0xc]
	str r1, [r0]
	b _02256642
_0225652A:
	ldr r0, [r4, #4]
	mov r1, #0x16
	bl MapObject_SetHeldMovement
	ldr r0, [r4, #8]
	mov r1, #0x16
	bl MapObject_SetHeldMovement
	ldr r0, [r4, #0xc]
	mov r1, #0x17
	bl MapObject_SetHeldMovement
	ldr r0, [sp, #0xc]
	mov r1, #3
	str r1, [r0]
	b _02256642
_0225654A:
	ldr r0, [r4, #4]
	mov r1, #0x17
	bl MapObject_SetHeldMovement
	ldr r0, [r4, #8]
	mov r1, #0x17
	bl MapObject_SetHeldMovement
	ldr r0, [r4, #0xc]
	mov r1, #0x16
	bl MapObject_SetHeldMovement
	ldr r0, [sp, #0xc]
	mov r1, #3
	str r1, [r0]
	b _02256642
_0225656A:
	mov r5, #0
_0225656C:
	lsl r0, r5, #2
	add r0, r4, r0
	ldr r0, [r0, #4]
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #0
	beq _02256584
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #3
	blo _0225656C
_02256584:
	cmp r5, #3
	bne _02256642
	ldrh r0, [r4, #0x14]
	add r0, r0, #1
	strh r0, [r4, #0x14]
	ldrh r0, [r4, #0x14]
	cmp r0, #2
	blo _022565AA
	ldrb r0, [r4, #0x16]
	cmp r0, #1
	bne _022565A2
	ldr r0, [sp, #0xc]
	mov r1, #4
	str r1, [r0]
	b _02256642
_022565A2:
	ldr r0, [sp, #0xc]
	mov r1, #5
	str r1, [r0]
	b _02256642
_022565AA:
	ldrb r1, [r4, #0x16]
	ldr r0, [sp, #0xc]
	str r1, [r0]
	b _02256642
_022565B2:
	add r0, r6, #0
	add r0, #0xc0
	ldr r0, [r0]
	ldr r1, [r4, #0x10]
	bl Field3dObjectList_GetRenderObjectByID
	str r0, [sp, #8]
	ldr r0, [r6, #0x54]
	ldr r1, [r4, #0x10]
	bl MapPropAnimationManager_GetPropAnimationCount
	add r7, r0, #0
	ldr r5, _02256648 ; =0x00000000
	beq _022565E4
_022565CE:
	ldr r0, [r6, #0x54]
	ldr r1, [sp, #8]
	ldr r2, [r4, #0x10]
	add r3, r5, #0
	bl MapPropAnimationManager_RemoveAnimationFromRenderObj
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, r7
	blo _022565CE
_022565E4:
	ldr r0, _0225664C ; =SEQ_SE_DP_UG_020
	bl PlaySE
	ldr r0, [sp, #0xc]
	mov r1, #6
	str r1, [r0]
	b _02256642
_022565F2:
	add r0, r6, #0
	add r0, #0xc0
	ldr r0, [r0]
	ldr r1, [r4, #0x10]
	bl Field3dObjectList_GetRenderObjectByID
	str r0, [sp, #4]
	ldr r0, [r6, #0x54]
	ldr r1, [r4, #0x10]
	bl MapPropAnimationManager_GetPropAnimationCount
	add r7, r0, #0
	ldr r5, _02256648 ; =0x00000000
	beq _02256628
_0225660E:
	ldr r0, [r6, #0x54]
	ldr r3, [sp, #4]
	str r0, [sp]
	ldr r0, [r4, #0x10]
	add r1, r5, #0
	mov r2, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, r7
	blo _0225660E
_02256628:
	ldr r0, _0225664C ; =SEQ_SE_DP_UG_020
	bl PlaySE
	ldr r0, [sp, #0xc]
	mov r1, #6
	str r1, [r0]
	b _02256642
_02256636:
	add r0, r4, #0
	bl Heap_Free
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02256642:
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02256648: .word 0x00000000
_0225664C: .word SEQ_SE_DP_UG_020
	thumb_func_end ov04_022564A0


	thumb_func_start ov04_02256650
ov04_02256650: ; 0x02256650
	push {r4, lr}
	add r4, r0, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #7
	bl Save_Gymmick_AssertMagic_GetData
	ldr r1, _02256698 ; =0x00001DD8
	mov r0, #4
	bl Heap_Alloc
	ldr r1, [r4, #4]
	ldr r2, _02256698 ; =0x00001DD8
	str r0, [r1, #0x24]
	ldr r0, [r4, #4]
	mov r1, #0
	ldr r0, [r0, #0x24]
	bl MI_CpuFill8
	ldr r0, [r4, #4]
	mov r1, #4
	ldr r4, [r0, #0x24]
	add r0, r4, #0
	bl ov04_02256758
	mov r2, #0
	ldr r0, _0225669C ; =0x00001DB6
	sub r1, r2, #1
_0225668C:
	add r2, r2, #1
	strh r1, [r4, r0]
	add r4, #0xc
	cmp r2, #3
	blt _0225668C
	pop {r4, pc}
	.balign 4, 0
_02256698: .word 0x00001DD8
_0225669C: .word 0x00001DB6
	thumb_func_end ov04_02256650


	thumb_func_start ov04_022566A0
ov04_022566A0: ; 0x022566A0
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	ldr r0, [r0, #4]
	ldr r5, [r0, #0x24]
	add r0, r5, #0
	bl ov04_0225686C
	ldr r6, _022566E4 ; =0x00001DB4
	mov r4, #0
	mov r7, #0xc
_022566B4:
	add r0, r4, #0
	mul r0, r7
	add r1, r5, r0
	ldrh r0, [r1, r6]
	cmp r0, #0
	beq _022566C8
	ldr r0, _022566E8 ; =0x00001DBC
	ldr r0, [r1, r0]
	bl SysTask_Destroy
_022566C8:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _022566B4
	add r0, r5, #0
	bl Heap_Free
	ldr r0, [sp]
	mov r1, #0
	ldr r0, [r0, #4]
	str r1, [r0, #0x24]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022566E4: .word 0x00001DB4
_022566E8: .word 0x00001DBC
	thumb_func_end ov04_022566A0


	thumb_func_start ov04_022566EC
ov04_022566EC: ; 0x022566EC
	push {r4, r5, r6, lr}
	add r6, r0, #0
	ldr r0, [r6, #4]
	ldr r5, [r0, #0x24]
	add r0, r1, #0
	add r1, r2, #0
	bl ov04_022568F0
	add r4, r0, #0
	bpl _0225670A
	mov r0, #SEQ_SE_DP_WALL_HIT>>8
	lsl r0, r0, #8
	bl PlaySE
	pop {r4, r5, r6, pc}
_0225670A:
	ldr r0, _0225672C ; =0x00001DB4
	add r1, r4, #0
	add r0, r5, r0
	bl ov04_02256920
	cmp r0, #0
	bne _0225672A
	lsl r2, r4, #0x18
	add r0, r5, #0
	add r1, r6, #0
	lsr r2, r2, #0x18
	bl ov04_02256950
	ldr r0, _02256730 ; =SEQ_SE_GS_TOUMEINAKABEHIT
	bl PlaySE
_0225672A:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0225672C: .word 0x00001DB4
_02256730: .word SEQ_SE_GS_TOUMEINAKABEHIT
	thumb_func_end ov04_022566EC
