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

	thumb_func_start ov04_02254DE0
ov04_02254DE0: ; 0x02254DE0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r2, [r5, #4]
	ldr r4, [r2, #0x24]
	bl FieldSysGetAttrAddr
	add r6, r0, #0
	ldr r0, [r6]
	bl ov04_MortyGymTrainerObjectToCandleIdx
	str r0, [r4, #0x10]
	ldr r0, [r6]
	mov r1, #0x10
	str r0, [r4, #0x18]
	mov r0, #0xb
	bl Heap_AllocAtEnd
	add r2, r0, #0
	mov r1, #0
	str r1, [r2]
	mov r0, #1
	str r0, [r2, #4]
	str r1, [r2, #8]
	str r5, [r2, #0xc]
	ldr r0, [r5, #0x10]
	ldr r1, _02254E1C ; =ov04_02254E50
	bl TaskManager_Call
	pop {r4, r5, r6, pc}
	nop
_02254E1C: .word ov04_02254E50
	thumb_func_end ov04_02254DE0


	thumb_func_start ov04_02254E20
ov04_02254E20: ; 0x02254E20
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r1, #0
	ldr r0, [r5, #4]
	add r1, sp, #0
	ldr r4, [r0, #0x24]
	ldr r0, [r4, #0x18]
	bl MapObject_CopyPositionVector
	ldr r1, [r4, #0x10]
	add r5, #0x9c
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	ldr r0, [r5]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl MapPropManager_GetMapPropByIndex
	add r1, sp, #0
	bl MapProp_SetTranslation
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov04_02254E20


	thumb_func_start ov04_02254E50
ov04_02254E50: ; 0x02254E50
	push {r4, r5, r6, lr}
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldr r1, [r4, #0xc]
	ldr r0, [r1, #4]
	ldr r5, [r0, #0x24]
	ldr r0, [r4]
	cmp r0, #0
	beq _02254E6E
	cmp r0, #1
	beq _02254E86
	cmp r0, #2
	beq _02254EFE
	b _02254F18
_02254E6E:
	ldr r1, [r4, #8]
	add r0, r1, #1
	str r0, [r4, #8]
	cmp r1, #0x1e
	blt _02254F18
	ldr r0, _02254F1C ; =SEQ_SE_GS_ROUSOKU_KIERU
	bl PlaySE
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02254F18
_02254E86:
	add r1, #0x9c
	ldr r0, [r1]
	ldr r1, [r5, #0x10]
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl MapPropManager_GetMapPropByIndex
	ldr r1, [r4, #4]
	add r6, r0, #0
	cmp r1, #4
	blt _02254ECC
	mov r1, #1
	bl MapProp_SetCulled
	ldr r0, [r4, #0xc]
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #1
	bl Save_Gymmick_AssertMagic_GetData
	ldr r1, [r5, #0x10]
	mov r2, #1
	strb r2, [r0, r1]
	ldr r0, [r5, #0x18]
	mov r1, #0xfa
	bl ov01_021FA930
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02254ED0
_02254ECC:
	add r0, r1, #1
	str r0, [r4, #4]
_02254ED0:
	add r0, r6, #0
	bl MapProp_GetScale
	add r5, r0, #0
	mov r0, #1
	ldr r1, [r4, #4]
	lsl r0, r0, #0xc
	bl _s32_div_f
	str r0, [r5]
	mov r0, #1
	ldr r1, [r4, #4]
	lsl r0, r0, #0xc
	bl _s32_div_f
	str r0, [r5, #4]
	mov r0, #1
	ldr r1, [r4, #4]
	lsl r0, r0, #0xc
	bl _s32_div_f
	str r0, [r5, #8]
	b _02254F18
_02254EFE:
	ldr r0, [r5, #0x18]
	bl ov01_021FA2D4
	cmp r0, #0
	bne _02254F18
	ldr r0, [r4, #0xc]
	bl ov04_02254F44
	add r0, r4, #0
	bl Heap_Free
	mov r0, #1
	pop {r4, r5, r6, pc}
_02254F18:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02254F1C: .word SEQ_SE_GS_ROUSOKU_KIERU
	thumb_func_end ov04_02254E50
