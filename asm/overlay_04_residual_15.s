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

	thumb_func_start ov04_02256B64
ov04_02256B64: ; 0x02256B64
	push {r4, lr}
	add r4, r0, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #8
	bl Save_Gymmick_AssertMagic_GetData
	ldr r1, _02256B9C ; =0x00000708
	mov r0, #4
	bl Heap_Alloc
	ldr r1, [r4, #4]
	ldr r2, _02256B9C ; =0x00000708
	str r0, [r1, #0x24]
	ldr r0, [r4, #4]
	mov r1, #0
	ldr r0, [r0, #0x24]
	bl MI_CpuFill8
	ldr r0, [r4, #4]
	mov r1, #4
	ldr r0, [r0, #0x24]
	bl ov04_02256C20
	pop {r4, pc}
	nop
_02256B9C: .word 0x00000708
	thumb_func_end ov04_02256B64


	thumb_func_start ov04_02256BA0
ov04_02256BA0: ; 0x02256BA0
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	ldr r0, [r0, #4]
	ldr r5, [r0, #0x24]
	add r0, r5, #0
	bl ov04_02256D00
	mov r7, #0xa3
	lsl r7, r7, #2
	add r6, r7, #0
	mov r4, #0
	sub r6, #0x50
_02256BB8:
	add r0, r4, #0
	mul r0, r6
	add r1, r5, r0
	ldr r0, [r1, #0x54]
	cmp r0, #0
	beq _02256BCA
	ldr r0, [r1, r7]
	bl SysTask_Destroy
_02256BCA:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _02256BB8
	add r0, r5, #0
	bl Heap_Free
	ldr r0, [sp]
	mov r1, #0
	ldr r0, [r0, #4]
	str r1, [r0, #0x24]
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov04_02256BA0


	thumb_func_start ov04_02256BE4
ov04_02256BE4: ; 0x02256BE4
	push {r4, r5, r6, lr}
	add r3, r0, #0
	ldr r0, [r3, #4]
	add r2, r1, #0
	ldr r4, [r0, #0x24]
	mov r1, #0x8f
	ldr r5, [r4, #0x50]
	add r0, r4, #0
	lsl r1, r1, #2
	add r6, r5, #0
	add r0, #0x54
	mul r6, r1
	ldr r1, [r0, r6]
	cmp r1, #0
	bne _02256C18
	add r0, r0, r6
	add r1, r3, #0
	bl ov04_02256D68
	ldr r0, [r4, #0x50]
	mov r1, #3
	add r0, r0, #1
	bl _s32_div_f
	str r1, [r4, #0x50]
	pop {r4, r5, r6, pc}
_02256C18:
	bl GF_AssertFail
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov04_02256BE4


	thumb_func_start ov04_02256C20
ov04_02256C20: ; 0x02256C20
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	mov r2, #0x20
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	bl HeapExp_FndInitAllocator
	ldr r4, [sp, #8]
	ldr r6, _02256CFC ; =0x00000101
	mov r5, #0
	add r4, #0x10
_02256C36:
	lsl r0, r5, #4
	ldr r3, [sp, #0xc]
	add r0, r4, r0
	add r1, r6, #0
	add r2, r5, #4
	bl Field3dModel_LoadFromFilesystem
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #4
	blo _02256C36
	mov r0, #0
	str r0, [sp, #0x14]
_02256C52:
	ldr r0, [sp, #8]
	mov r4, #0
	add r2, r0, #0
	str r4, [r0, #0x50]
	mov r1, #0x8f
	ldr r0, [sp, #0x14]
	lsl r1, r1, #2
	add r2, #0x54
	mul r1, r0
	add r7, r2, r1
	str r4, [r2, r1]
	str r4, [r7, #4]
	add r6, r7, #0
	ldr r0, [sp, #0x14]
	mov r1, #0x8c
	mul r1, r0
	ldr r0, [sp, #8]
	add r6, #0x1c
	str r0, [sp, #0x1c]
	add r0, #0x10
	str r1, [sp, #0x18]
	add r7, #8
	str r0, [sp, #0x1c]
_02256C80:
	lsl r0, r4, #4
	str r0, [sp, #0x10]
	mov r0, #0x8c
	add r5, r4, #0
	mul r5, r0
	ldr r0, [sp, #0xc]
	ldr r2, [sp, #0x1c]
	ldr r1, [sp, #0x10]
	str r0, [sp]
	ldr r0, [sp, #8]
	add r1, r2, r1
	str r0, [sp, #4]
	ldr r2, _02256CFC ; =0x00000101
	add r0, r7, r5
	add r3, r4, #0
	bl Field3dModelAnimation_LoadFromFilesystem
	ldr r2, [sp, #0x1c]
	ldr r1, [sp, #0x10]
	add r0, r6, r5
	add r1, r2, r1
	bl Field3dObject_InitFromModel
	add r0, r6, r5
	add r1, r7, r5
	bl Field3dObject_AddAnimation
	add r0, r7, r5
	mov r1, #0
	bl Field3dModelAnimation_FrameSet
	mov r1, #0
	add r0, sp, #0x20
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x20]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	add r0, r6, r0
	bl Field3dObject_SetPosEx
	add r0, r6, r5
	mov r1, #0
	bl Field3dObject_SetActiveFlag
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _02256C80
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x14]
	cmp r0, #3
	blo _02256C52
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	nop
_02256CFC: .word 0x00000101
	thumb_func_end ov04_02256C20


	thumb_func_start ov04_02256D00
ov04_02256D00: ; 0x02256D00
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	add r5, r6, #0
	mov r4, #0
	add r5, #0x10
_02256D0C:
	lsl r0, r4, #4
	add r0, r5, r0
	bl Field3dModel_Unload
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _02256D0C
	mov r0, #0
	str r0, [sp]
	add r0, r6, #0
	str r0, [sp, #4]
	add r0, #0x54
	str r0, [sp, #4]
	mov r7, #0x8c
_02256D2C:
	ldr r1, [sp]
	mov r0, #0x8f
	lsl r0, r0, #2
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #4]
	mov r5, #0
	add r4, r0, r2
	add r4, #8
_02256D3E:
	add r0, r5, #0
	mul r0, r7
	add r0, r4, r0
	add r1, r6, #0
	bl Field3dModelAnimation_Unload
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #4
	blo _02256D3E
	ldr r0, [sp]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	cmp r0, #3
	blo _02256D2C
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov04_02256D00


	thumb_func_start ov04_02256D68
ov04_02256D68: ; 0x02256D68
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r5, #1
	sub r2, #0x40
	add r7, r1, #0
	str r5, [r4]
	cmp r2, #3
	bhi _02256D9A
	add r0, r2, r2
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02256D86: ; jump table
	.short _02256D8E - _02256D86 - 2 ; case 0
	.short _02256D92 - _02256D86 - 2 ; case 1
	.short _02256D96 - _02256D86 - 2 ; case 2
	.short _02256D98 - _02256D86 - 2 ; case 3
_02256D8E:
	mov r5, #2
	b _02256DA2
_02256D92:
	mov r5, #0
	b _02256DA2
_02256D96:
	mov r5, #3
_02256D98:
	b _02256DA2
_02256D9A:
	bl GF_AssertFail
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_02256DA2:
	ldr r0, _02256DF8 ; =ov04_02256DFC
	add r1, r4, #0
	mov r2, #0
	str r5, [r4, #4]
	bl SysTask_CreateOnMainQueue
	mov r1, #0x8e
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r6, r5, #0
	mov r0, #0x8c
	add r5, r4, #0
	mul r6, r0
	add r5, #0x1c
	add r0, r5, r6
	mov r1, #1
	bl Field3dObject_SetActiveFlag
	add r1, sp, #0
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r0, [r7, #0x40]
	bl PlayerAvatar_GetMapObject
	add r1, sp, #0
	bl MapObject_CopyPositionVector
	ldr r1, [sp]
	ldr r2, [sp, #4]
	ldr r3, [sp, #8]
	add r0, r5, r6
	bl Field3dObject_SetPosEx
	add r4, #8
	add r0, r4, r6
	mov r1, #0
	bl Field3dModelAnimation_FrameSet
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_02256DF8: .word ov04_02256DFC
	thumb_func_end ov04_02256D68


	thumb_func_start ov04_02256DFC
ov04_02256DFC: ; 0x02256DFC
	push {r3, r4, r5, lr}
	add r5, r1, #0
	ldr r0, [r5, #4]
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	mov r0, #0x8c
	add r4, r1, #0
	mul r4, r0
	add r0, r5, #0
	add r0, #8
	add r0, r0, r4
	bl ov04_02256E48
	cmp r0, #0
	beq _02256E3E
	add r0, r5, #0
	add r0, #0x1c
	add r0, r0, r4
	mov r1, #0
	bl Field3dObject_SetActiveFlag
	mov r0, #0
	str r0, [r5]
	mov r0, #0x8e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SysTask_Destroy
	mov r0, #0x8e
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r5, r0]
	pop {r3, r4, r5, pc}
_02256E3E:
	add r5, #0x1c
	add r0, r5, r4
	bl Field3dObject_Draw
	pop {r3, r4, r5, pc}
	thumb_func_end ov04_02256DFC
