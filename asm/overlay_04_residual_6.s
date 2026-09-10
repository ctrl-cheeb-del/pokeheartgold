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

	thumb_func_start ov04_02254F44
ov04_02254F44: ; 0x02254F44
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x3c]
	bl MapObjectManager_GetObjectCount
	add r5, r0, #0
	ldr r0, [r4, #0x3c]
	bl MapObjectManager_GetObjects
	mov r4, #0
	str r0, [sp]
	cmp r5, #0
	ble _02254F88
	add r6, r4, #0
	add r7, sp, #0
_02254F62:
	ldr r0, [sp]
	bl MapObject_CheckActive
	cmp r0, #1
	bne _02254F7C
	ldr r0, [sp]
	bl ov01_021F72DC
	bl sub_02023F90
	add r1, r6, #0
	bl NNS_G3dMdlSetMdlFogEnableFlagAll
_02254F7C:
	add r0, r7, #0
	bl MapObjectArray_NextObject2
	add r4, r4, #1
	cmp r4, r5
	blt _02254F62
_02254F88:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov04_02254F44


	thumb_func_start ov04_02254F8C
ov04_02254F8C: ; 0x02254F8C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	ldr r3, _02255070 ; =ov04_0225762C
	str r0, [sp, #4]
	ldmia r3!, {r0, r1}
	add r2, sp, #0x38
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [sp, #4]
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #6
	bl Save_Gymmick_AssertMagic_GetData
	str r0, [sp, #0x10]
	ldr r1, _02255074 ; =0x00000754
	mov r0, #4
	bl Heap_Alloc
	ldr r1, [sp, #4]
	ldr r2, _02255074 ; =0x00000754
	ldr r1, [r1, #4]
	str r0, [r1, #0x24]
	ldr r0, [sp, #4]
	mov r1, #0
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x24]
	bl MI_CpuFill8
	ldr r0, [sp, #4]
	ldr r2, _02255078 ; =ov04_02257620
	ldr r0, [r0, #4]
	add r3, sp, #0x14
	ldr r6, [r0, #0x24]
	ldr r0, [sp, #4]
	ldr r4, [sp, #0x10]
	str r0, [r6]
	add r0, sp, #0x38
	str r0, [sp, #0xc]
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	mov r5, #0
	add r7, r6, #4
	str r0, [r3]
_02254FEC:
	add r3, sp, #0x14
	ldmia r3!, {r0, r1}
	add r2, sp, #0x2c
	mov ip, r2
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #0
	str r0, [r2]
	add r0, sp, #0x20
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [sp, #0x10]
	mov r2, ip
	add r0, r0, r5
	str r0, [sp, #8]
	ldrb r0, [r0, #0xc]
	add r3, sp, #0x20
	lsl r0, r0, #0xe
	neg r0, r0
	str r0, [sp, #0x24]
	ldrh r0, [r4]
	lsl r1, r0, #0x10
	mov r0, #2
	lsl r0, r0, #0xe
	add r0, r1, r0
	str r0, [sp, #0x2c]
	ldrh r0, [r4, #6]
	lsl r1, r0, #0x10
	mov r0, #2
	lsl r0, r0, #0xe
	add r0, r1, r0
	str r0, [sp, #0x34]
	ldr r0, [sp, #4]
	ldr r1, [sp, #0xc]
	ldr r0, [r0, #0x54]
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, [r1]
	add r0, #0x9c
	ldr r0, [r0]
	bl MapPropManager_LoadOne
	strb r0, [r6, #0xb]
	str r7, [sp]
	ldr r1, [sp, #8]
	lsl r0, r5, #0x18
	ldrb r1, [r1, #0xc]
	ldrh r2, [r4]
	ldrh r3, [r4, #6]
	lsr r0, r0, #0x18
	bl ov04_02255140
	ldr r0, [sp, #0xc]
	add r5, r5, #1
	add r0, r0, #4
	str r0, [sp, #0xc]
	mov r0, #0x27
	lsl r0, r0, #4
	add r4, r4, #2
	add r6, r6, r0
	add r7, r7, r0
	cmp r5, #3
	blt _02254FEC
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02255070: .word ov04_0225762C
_02255074: .word 0x00000754
_02255078: .word ov04_02257620
	thumb_func_end ov04_02254F8C
