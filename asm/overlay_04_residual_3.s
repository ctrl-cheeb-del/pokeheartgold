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

	thumb_func_start ov04_02254CBC
ov04_02254CBC: ; 0x02254CBC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	add r5, r0, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #1
	bl Save_Gymmick_AssertMagic_GetData
	add r7, r0, #0
	mov r0, #4
	mov r1, #0x1c
	bl Heap_Alloc
	ldr r1, [r5, #4]
	mov r2, #0x1c
	str r0, [r1, #0x24]
	ldr r0, [r5, #4]
	mov r1, #0
	ldr r0, [r0, #0x24]
	bl MI_CpuFill8
	ldr r0, [r5, #4]
	mov r1, #1
	lsl r1, r1, #8
	ldr r4, [r0, #0x24]
	add r0, r1, #0
	add r0, #0x1c
	str r1, [r5, r0]
	mov r0, #0xa
	mov r3, #0
	str r0, [sp]
	str r3, [sp, #4]
	ldr r0, [r5, #0x4c]
	sub r1, r3, #1
	mov r2, #1
	bl ov01_021EA864
	mov r1, #0
	ldr r0, [r5, #0x4c]
	mvn r1, r1
	mov r2, #0
	mov r3, #0x1f
	bl ov01_021EA89C
	mov r1, #0
	add r2, sp, #0x14
	sub r0, r1, #1
_02254D1E:
	add r1, r1, #1
	strb r0, [r2]
	add r2, r2, #1
	cmp r1, #0x20
	blt _02254D1E
	ldr r0, [r5, #0x4c]
	add r1, sp, #0x14
	bl ov01_021EA8C4
	add r0, r5, #0
	bl ov04_02254F44
	mov r6, #0
_02254D38:
	ldr r0, [r5, #0x3c]
	add r1, r6, #2
	bl MapObjectManager_GetFirstActiveObjectByID
	add r1, sp, #8
	bl MapObject_CopyPositionVector
	ldr r0, [r5, #0x54]
	mov r1, #0x80
	str r0, [sp]
	add r0, r5, #0
	add r0, #0x9c
	ldr r0, [r0]
	add r2, sp, #8
	mov r3, #0
	bl MapPropManager_LoadOne
	str r0, [r4]
	ldrb r0, [r7, r6]
	cmp r0, #0
	beq _02254D78
	add r0, r5, #0
	ldr r1, [r4]
	add r0, #0x9c
	lsl r1, r1, #0x18
	ldr r0, [r0]
	lsr r1, r1, #0x18
	bl MapPropManager_GetMapPropByIndex
	mov r1, #1
	bl MapProp_SetCulled
_02254D78:
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #4
	blt _02254D38
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov04_02254CBC
