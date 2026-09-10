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

	thumb_func_start ov04_022554FC
ov04_022554FC: ; 0x022554FC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x4c
	add r5, r0, #0
	ldr r0, [r3]
	add r4, r1, #0
	add r6, r2, #0
	str r3, [sp, #4]
	cmp r0, #0
	bne _0225551C
	mov r0, #0xe
	str r0, [sp, #0x44]
	mov r0, #5
	str r0, [sp, #0x20]
	mov r0, #7
	str r0, [sp, #0x24]
	b _02255528
_0225551C:
	mov r0, #0x18
	str r0, [sp, #0x44]
	mov r0, #4
	str r0, [sp, #0x20]
	mov r0, #8
	str r0, [sp, #0x24]
_02255528:
	ldr r3, [sp, #4]
	add r0, r5, #0
	add r3, #0x10
	add r1, r4, #0
	add r2, r6, #0
	str r3, [sp]
	bl ov04_02255480
	ldr r3, [sp, #4]
	add r0, r5, #0
	add r3, #0x18
	add r1, r4, #0
	add r2, r6, #0
	str r3, [sp]
	bl ov04_02255480
	mov r0, #0
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x24]
	cmp r0, #0
	ble _0225557A
	ldr r7, [sp, #4]
	add r7, #0x28
	str r7, [sp, #0x28]
_02255558:
	ldr r3, [sp, #0x28]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	str r7, [sp]
	bl ov04_02255480
	ldr r0, [sp, #0x28]
	add r7, #8
	add r0, #8
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x48]
	add r1, r0, #1
	ldr r0, [sp, #0x24]
	str r1, [sp, #0x48]
	cmp r1, r0
	blt _02255558
_0225557A:
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x24]
	cmp r0, #0
	ble _022555AC
	ldr r7, [sp, #4]
	add r7, #0x68
	str r7, [sp, #0x2c]
_0225558A:
	ldr r3, [sp, #0x2c]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	str r7, [sp]
	bl ov04_02255480
	ldr r0, [sp, #0x2c]
	add r7, #8
	add r0, #8
	str r0, [sp, #0x2c]
	ldr r0, [sp, #8]
	add r1, r0, #1
	ldr r0, [sp, #0x24]
	str r1, [sp, #8]
	cmp r1, r0
	blt _0225558A
_022555AC:
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x20]
	cmp r0, #0
	ble _022555DE
	ldr r7, [sp, #4]
	add r7, #0xa8
	str r7, [sp, #0x30]
_022555BC:
	ldr r3, [sp, #0x30]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	str r7, [sp]
	bl ov04_02255480
	ldr r0, [sp, #0x30]
	add r7, #8
	add r0, #8
	str r0, [sp, #0x30]
	ldr r0, [sp, #0xc]
	add r1, r0, #1
	ldr r0, [sp, #0x20]
	str r1, [sp, #0xc]
	cmp r1, r0
	blt _022555BC
_022555DE:
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x20]
	cmp r0, #0
	ble _02255610
	ldr r7, [sp, #4]
	add r7, #0xd0
	str r7, [sp, #0x34]
_022555EE:
	ldr r3, [sp, #0x34]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	str r7, [sp]
	bl ov04_02255480
	ldr r0, [sp, #0x34]
	add r7, #8
	add r0, #8
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x10]
	add r1, r0, #1
	ldr r0, [sp, #0x20]
	str r1, [sp, #0x10]
	cmp r1, r0
	blt _022555EE
_02255610:
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x44]
	cmp r0, #0
	ble _02255642
	ldr r7, [sp, #4]
	add r7, #0xf8
	str r7, [sp, #0x38]
_02255620:
	ldr r3, [sp, #0x38]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	str r7, [sp]
	bl ov04_02255480
	ldr r0, [sp, #0x38]
	add r7, #8
	add r0, #8
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x14]
	add r1, r0, #1
	ldr r0, [sp, #0x44]
	str r1, [sp, #0x14]
	cmp r1, r0
	blt _02255620
_02255642:
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x20]
	cmp r0, #0
	ble _02255678
	mov r1, #0x6e
	ldr r0, [sp, #4]
	lsl r1, r1, #2
	add r7, r0, r1
	str r7, [sp, #0x3c]
_02255656:
	ldr r3, [sp, #0x3c]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	str r7, [sp]
	bl ov04_02255480
	ldr r0, [sp, #0x3c]
	add r7, #8
	add r0, #8
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x18]
	add r1, r0, #1
	ldr r0, [sp, #0x20]
	str r1, [sp, #0x18]
	cmp r1, r0
	blt _02255656
_02255678:
	mov r0, #0
	str r0, [sp, #0x1c]
	mov r1, #0x1e
	ldr r0, [sp, #4]
	lsl r1, r1, #4
	add r7, r0, r1
	str r7, [sp, #0x40]
_02255686:
	ldr r3, [sp, #0x40]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	str r7, [sp]
	bl ov04_02255480
	ldr r0, [sp, #0x40]
	add r7, #8
	add r0, #8
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #0x12
	blt _02255686
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov04_022554FC


	thumb_func_start ov04_022556AC
ov04_022556AC: ; 0x022556AC
	push {r4, r5, r6, r7}
	mov r6, #0x27
	mov r4, #0
	lsl r6, r6, #4
_022556B4:
	add r5, r4, #0
	mul r5, r6
	add r5, r0, r5
	ldr r7, [r5, #0xc]
	cmp r1, r7
	bne _022556CE
	ldr r7, [r5, #0x10]
	cmp r2, r7
	bne _022556CE
	strb r4, [r3]
	mov r0, #1
	pop {r4, r5, r6, r7}
	bx lr
_022556CE:
	ldr r7, [r5, #0x14]
	cmp r1, r7
	bne _022556E2
	ldr r7, [r5, #0x18]
	cmp r2, r7
	bne _022556E2
	strb r4, [r3]
	mov r0, #2
	pop {r4, r5, r6, r7}
	bx lr
_022556E2:
	ldr r7, [r5, #0x1c]
	cmp r1, r7
	bne _022556F6
	ldr r5, [r5, #0x20]
	cmp r2, r5
	bne _022556F6
	strb r4, [r3]
	mov r0, #3
	pop {r4, r5, r6, r7}
	bx lr
_022556F6:
	add r4, r4, #1
	lsl r4, r4, #0x18
	lsr r4, r4, #0x18
	cmp r4, #3
	blo _022556B4
	mov r0, #0
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
	thumb_func_end ov04_022556AC


	thumb_func_start ov04_02255708
ov04_02255708: ; 0x02255708
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r3, sp, #0
	add r5, r0, #0
	bl ov04_022556AC
	add r6, r0, #0
	bne _0225571E
	add sp, #4
	mov r0, #0
	pop {r3, r4, r5, r6, pc}
_0225571E:
	mov r0, #0xb
	mov r1, #0x74
	bl Heap_AllocAtEnd
	add r4, r0, #0
	ldr r0, [r5]
	add r2, r4, #0
	str r0, [r4, #0x70]
	mov r1, #0
	add r2, #0x4c
	str r1, [r4]
	add r0, sp, #0
	ldrb r3, [r0]
	cmp r6, #1
	strb r3, [r2]
	str r6, [r4, #0x50]
	beq _0225574A
	cmp r6, #2
	beq _02255762
	cmp r6, #3
	beq _022557AA
	b _022557F2
_0225574A:
	mov r0, #8
	str r0, [r4]
	ldr r0, _022557F8 ; =SEQ_SE_GS_GONDORA_IDOU
	bl PlaySE
	ldr r0, [r5]
	ldr r1, _022557FC ; =ov04_02255AC4
	add r2, r4, #0
	bl FieldSystem_CreateTask
	mov r1, #1
	b _022557F2
_02255762:
	add r2, r4, #0
	str r1, [r4]
	add r2, #0x4d
	strb r1, [r2]
	ldrb r2, [r0]
	mov r3, #0x27
	lsl r3, r3, #4
	add r6, r2, #0
	mul r6, r3
	add r2, r5, r6
	ldrb r6, [r2, #8]
	add r2, r4, #0
	add r2, #0x4e
	strb r6, [r2]
	ldrb r0, [r0]
	add r2, r0, #0
	mul r2, r3
	add r0, r5, r2
	ldrb r0, [r0, #0xa]
	bl ov04_022558B4
	add r1, r4, #0
	add r1, #0x58
	str r0, [r4, #0x54]
	bl ov04_022558D0
	ldr r0, _022557F8 ; =SEQ_SE_GS_GONDORA_IDOU
	bl PlaySE
	ldr r0, [r5]
	ldr r1, _02255800 ; =ov04_022559C8
	add r2, r4, #0
	bl FieldSystem_CreateTask
	mov r1, #1
	b _022557F2
_022557AA:
	add r2, r4, #0
	str r1, [r4]
	add r2, #0x4d
	strb r1, [r2]
	ldrb r1, [r0]
	mov r2, #0x27
	lsl r2, r2, #4
	add r3, r1, #0
	mul r3, r2
	add r1, r5, r3
	ldrb r3, [r1, #8]
	add r1, r4, #0
	add r1, #0x4e
	strb r3, [r1]
	ldrb r0, [r0]
	add r1, r0, #0
	mul r1, r2
	add r0, r5, r1
	ldrb r0, [r0, #0xa]
	mov r1, #1
	bl ov04_022558B4
	add r1, r4, #0
	add r1, #0x58
	str r0, [r4, #0x54]
	bl ov04_022558D0
	ldr r0, _022557F8 ; =SEQ_SE_GS_GONDORA_IDOU
	bl PlaySE
	ldr r0, [r5]
	ldr r1, _02255800 ; =ov04_022559C8
	add r2, r4, #0
	bl FieldSystem_CreateTask
	mov r1, #1
_022557F2:
	add r0, r1, #0
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_022557F8: .word SEQ_SE_GS_GONDORA_IDOU
_022557FC: .word ov04_02255AC4
_02255800: .word ov04_022559C8
	thumb_func_end ov04_02255708


	thumb_func_start ov04_02255804
ov04_02255804: ; 0x02255804
	push {r4, r5}
	ldr r2, [r1, #0x50]
	cmp r2, #2
	beq _02255814
	cmp r2, #3
	beq _02255836
	pop {r4, r5}
	bx lr
_02255814:
	ldrb r2, [r0, #5]
	mov r4, #0
	cmp r2, #0
	ble _02255854
	add r5, r0, #0
_0225581E:
	ldr r3, [r5, #0x28]
	ldr r2, [r5, #0x2c]
	add r4, r4, #1
	str r3, [r1, #4]
	str r2, [r1, #8]
	ldrb r2, [r0, #5]
	add r5, #8
	add r1, #8
	cmp r4, r2
	blt _0225581E
	pop {r4, r5}
	bx lr
_02255836:
	ldrb r2, [r0, #5]
	mov r5, #0
	cmp r2, #0
	ble _02255854
	add r4, r0, #0
_02255840:
	ldr r3, [r4, #0x68]
	ldr r2, [r4, #0x6c]
	add r5, r5, #1
	str r3, [r1, #4]
	str r2, [r1, #8]
	ldrb r2, [r0, #5]
	add r4, #8
	add r1, #8
	cmp r5, r2
	blt _02255840
_02255854:
	pop {r4, r5}
	bx lr
	thumb_func_end ov04_02255804


	thumb_func_start ov04_02255858
ov04_02255858: ; 0x02255858
	push {r3, lr}
	add r2, r1, #0
	add r3, r0, #0
	ldr r0, [r2, #0x54]
	cmp r0, #3
	bhi _022558B2
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02255870: ; jump table
	.short _02255878 - _02255870 - 2 ; case 0
	.short _02255886 - _02255870 - 2 ; case 1
	.short _02255894 - _02255870 - 2 ; case 2
	.short _022558A4 - _02255870 - 2 ; case 3
_02255878:
	lsl r1, r3, #0x18
	mov r0, #1
	lsr r1, r1, #0x18
	add r2, r2, #4
	bl ov04_022554C4
	pop {r3, pc}
_02255886:
	lsl r1, r3, #0x18
	mov r0, #1
	lsr r1, r1, #0x18
	add r2, r2, #4
	bl ov04_022554E0
	pop {r3, pc}
_02255894:
	mov r0, #0
	lsl r1, r3, #0x18
	mvn r0, r0
	lsr r1, r1, #0x18
	add r2, r2, #4
	bl ov04_022554C4
	pop {r3, pc}
_022558A4:
	mov r0, #0
	lsl r1, r3, #0x18
	mvn r0, r0
	lsr r1, r1, #0x18
	add r2, r2, #4
	bl ov04_022554E0
_022558B2:
	pop {r3, pc}
	thumb_func_end ov04_02255858


	thumb_func_start ov04_022558B4
ov04_022558B4: ; 0x022558B4
	cmp r1, #0
	bne _022558BC
	mov r1, #0
	b _022558BE
_022558BC:
	mov r1, #2
_022558BE:
	add r0, r1, r0
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	bx lr
	.balign 4, 0
	thumb_func_end ov04_022558B4
