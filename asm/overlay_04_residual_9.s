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

	thumb_func_start ov04_02255910
ov04_02255910: ; 0x02255910
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0xff
	add r7, r1, #0
	add r4, r2, #0
	mov r6, #0
	str r0, [sp]
	cmp r7, #0
	ble _0225595A
_02255922:
	ldr r1, [r4]
	ldr r2, [r4, #4]
	add r0, r5, #0
	bl sub_020548C0
	cmp r0, #0
	beq _02255938
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	b _0225595A
_02255938:
	ldr r1, [r4]
	ldr r2, [r4, #4]
	add r0, r5, #0
	bl GetMetatileBehavior
	bl MetatileBehavior_IsMagma
	cmp r0, #0
	bne _02255952
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	b _0225595A
_02255952:
	add r6, r6, #1
	add r4, #8
	cmp r6, r7
	blt _02255922
_0225595A:
	ldr r0, [sp]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov04_02255910


	thumb_func_start ov04_02255960
ov04_02255960: ; 0x02255960
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	mov r0, #1
	lsl r0, r0, #0xe
	add r7, r1, #0
	add r5, r2, #0
	mov r4, #0
	str r3, [sp]
	str r0, [sp, #4]
	cmp r7, #0
	ble _022559C0
_02255978:
	ldr r1, [r5]
	ldr r2, [r5, #4]
	add r0, r6, #0
	bl sub_020548C0
	cmp r0, #0
	bne _0225599E
	ldr r1, [r5]
	ldr r2, [r5, #4]
	add r0, r6, #0
	bl GetMetatileBehavior
	bl MetatileBehavior_IsMagma
	cmp r0, #0
	bne _0225599C
	mov r0, #1
	b _0225599E
_0225599C:
	mov r0, #0
_0225599E:
	cmp r0, #0
	beq _022559B8
	ldr r0, [sp]
	ldrb r0, [r0, r4]
	lsl r1, r0, #8
	mov r0, #1
	lsl r0, r0, #0xe
	cmp r1, r0
	bge _022559B8
	lsl r0, r1, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	b _022559C0
_022559B8:
	add r4, r4, #1
	add r5, #8
	cmp r4, r7
	blt _02255978
_022559C0:
	ldr r0, [sp, #4]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov04_02255960


	thumb_func_start ov04_022559C8
ov04_022559C8: ; 0x022559C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r4, r0, #0
	bl TaskManager_GetFieldSystem
	add r6, r0, #0
	add r0, r4, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldr r0, [r6, #4]
	ldr r5, [r0, #0x24]
	ldr r0, [r4]
	cmp r0, #0
	beq _022559F0
	cmp r0, #3
	beq _02255A16
	cmp r0, #7
	beq _02255AA2
	b _02255AB6
_022559F0:
	add r0, r4, #0
	add r0, #0x4c
	ldrb r1, [r0]
	mov r0, #0x27
	lsl r0, r0, #4
	mul r0, r1
	add r2, r5, #4
	add r0, r2, r0
	add r1, r4, #0
	bl ov04_02255804
	ldr r0, _02255ABC ; =ov04_02255D88
	add r1, r4, #0
	mov r2, #0
	bl SysTask_CreateOnMainQueue
	mov r0, #1
	str r0, [r4]
	b _02255AB6
_02255A16:
	add r1, r4, #0
	add r1, #0x4c
	ldrb r2, [r1]
	mov r1, #0x27
	lsl r1, r1, #4
	mul r1, r2
	add r0, r6, #0
	add r1, r5, r1
	add r0, #0x9c
	ldrb r1, [r1, #0xb]
	ldr r0, [r0]
	bl MapPropManager_GetMapPropByIndex
	add r1, r0, #0
	add r0, sp, #8
	bl MapProp_GetTranslation
	ldr r1, [sp, #8]
	asr r0, r1, #0xf
	lsr r0, r0, #0x10
	add r0, r1, r0
	asr r0, r0, #0x10
	ldr r1, [sp, #0x10]
	str r0, [sp, #4]
	asr r0, r1, #0xf
	lsr r0, r0, #0x10
	add r0, r1, r0
	add r1, r4, #0
	add r1, #0x4c
	ldrb r2, [r1]
	mov r1, #0x27
	lsl r1, r1, #4
	asr r7, r0, #0x10
	add r0, r5, #4
	mul r1, r2
	add r5, r0, r1
	add r0, r6, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #6
	bl Save_Gymmick_AssertMagic_GetData
	ldr r1, [sp, #4]
	lsl r1, r1, #0x10
	lsr r2, r1, #0x10
	add r1, r4, #0
	add r1, #0x4c
	ldrb r1, [r1]
	lsl r1, r1, #1
	strh r2, [r0, r1]
	lsl r1, r7, #0x10
	lsr r3, r1, #0x10
	add r1, r4, #0
	add r1, #0x4c
	ldrb r1, [r1]
	lsl r1, r1, #1
	add r0, r0, r1
	strh r3, [r0, #6]
	add r0, r4, #0
	str r5, [sp]
	add r0, #0x4c
	ldrb r0, [r0]
	ldrb r1, [r5, #6]
	bl ov04_02255140
	mov r0, #7
	str r0, [r4]
	b _02255AB6
_02255AA2:
	ldr r0, _02255AC0 ; =SEQ_SE_GS_GONDORA_IDOU
	mov r1, #0
	bl StopSE
	add r0, r4, #0
	bl Heap_Free
	add sp, #0x14
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02255AB6:
	mov r0, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02255ABC: .word ov04_02255D88
_02255AC0: .word SEQ_SE_GS_GONDORA_IDOU
	thumb_func_end ov04_022559C8


	thumb_func_start ov04_02255AC4
ov04_02255AC4: ; 0x02255AC4
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	bl TaskManager_GetFieldSystem
	add r5, r0, #0
	add r0, r4, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldr r0, [r5, #4]
	ldr r6, [r0, #0x24]
	ldr r0, [r4]
	sub r0, #8
	cmp r0, #4
	bhi _02255BA4
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02255AEE: ; jump table
	.short _02255AF8 - _02255AEE - 2 ; case 0
	.short _02255B64 - _02255AEE - 2 ; case 1
	.short _02255C26 - _02255AEE - 2 ; case 2
	.short _02255C64 - _02255AEE - 2 ; case 3
	.short _02255C9E - _02255AEE - 2 ; case 4
_02255AF8:
	add r0, r4, #0
	add r0, #0x4c
	ldrb r3, [r0]
	mov r0, #0x27
	lsl r0, r0, #4
	add r1, r3, #0
	mul r1, r0
	add r0, r4, #0
	add r2, r6, #4
	add r1, r2, r1
	mov r3, #0
	add r0, #0x4f
	strb r3, [r0]
	add r0, r5, #0
	add r2, sp, #0
	bl ov04_02255CBC
	cmp r0, #2
	bne _02255B24
	mov r0, #9
	str r0, [r4]
	b _02255CB0
_02255B24:
	cmp r0, #1
	bne _02255B5E
	add r1, r4, #0
	add r1, #0x4c
	ldrb r2, [r1]
	mov r1, #0x27
	lsl r1, r1, #4
	mul r1, r2
	add r1, r6, r1
	add r5, #0x9c
	ldrb r1, [r1, #0xb]
	ldr r0, [r5]
	bl MapPropManager_GetMapPropByIndex
	bl MapProp_GetRotation
	add r1, sp, #0
	ldrh r1, [r1]
	str r1, [r4, #0x68]
	ldr r0, [r0, #4]
	str r0, [r4, #0x6c]
	mov r0, #0
	str r0, [r4, #0x64]
	mov r0, #0xa
	str r0, [r4]
	ldr r0, _02255CB4 ; =SEQ_SE_GS_GONDORA_KABEHIT
	bl PlaySE
	b _02255CB0
_02255B5E:
	mov r0, #0xc
	str r0, [r4]
	b _02255CB0
_02255B64:
	add r1, r4, #0
	add r1, #0x4c
	ldrb r2, [r1]
	mov r1, #0x27
	lsl r1, r1, #4
	mul r1, r2
	add r0, r5, #0
	add r1, r6, r1
	add r0, #0x9c
	ldrb r1, [r1, #0xb]
	ldr r0, [r0]
	bl MapPropManager_GetMapPropByIndex
	bl MapProp_GetRotation
	mov r1, #1
	ldr r2, [r0, #4]
	lsl r1, r1, #0xa
	sub r1, r2, r1
	str r1, [r0, #4]
	add r0, r4, #0
	add r0, #0x4f
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x4f
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x4f
	ldrb r0, [r0]
	cmp r0, #0x10
	bhs _02255BA6
_02255BA4:
	b _02255CB0
_02255BA6:
	add r0, r4, #0
	add r0, #0x4c
	ldrb r1, [r0]
	mov r0, #0x27
	lsl r0, r0, #4
	mul r0, r1
	add r2, r6, #4
	add r7, r2, r0
	add r0, r4, #0
	mov r1, #0
	add r0, #0x4f
	strb r1, [r0]
	add r0, r5, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #6
	bl Save_Gymmick_AssertMagic_GetData
	add r3, r0, #0
	mov ip, r0
	add r0, r4, #0
	add r0, #0x4c
	ldrb r2, [r0]
	add r3, #0xc
	ldrb r0, [r3, r2]
	add r0, r0, #1
	lsr r1, r0, #0x1f
	lsl r6, r0, #0x1e
	sub r6, r6, r1
	mov r0, #0x1e
	ror r6, r0
	add r0, r1, r6
	strb r0, [r3, r2]
	add r0, r4, #0
	add r0, #0x4c
	ldrb r1, [r0]
	mov r0, ip
	add r0, r0, r1
	ldrb r0, [r0, #0xc]
	strb r0, [r7, #6]
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	add r6, r0, #0
	bl MapObject_GetXCoord
	add r5, r0, #0
	add r0, r6, #0
	bl MapObject_GetZCoord
	add r2, r0, #0
	lsl r1, r5, #0x10
	lsl r2, r2, #0x10
	mov r0, #1
	lsr r1, r1, #0x10
	lsr r2, r2, #0x10
	add r3, r7, #0
	bl ov04_022554FC
	mov r0, #0xc
	str r0, [r4]
	b _02255CB0
_02255C26:
	add r1, r4, #0
	add r1, #0x4c
	ldrb r2, [r1]
	mov r1, #0x27
	lsl r1, r1, #4
	mul r1, r2
	add r1, r6, r1
	add r5, #0x9c
	ldrb r1, [r1, #0xb]
	ldr r0, [r5]
	bl MapPropManager_GetMapPropByIndex
	bl MapProp_GetRotation
	mov r1, #1
	ldr r2, [r0, #4]
	lsl r1, r1, #0xa
	sub r2, r2, r1
	str r2, [r0, #4]
	ldr r2, [r4, #0x64]
	add r1, r2, r1
	str r1, [r4, #0x64]
	ldr r2, [r4, #0x68]
	cmp r1, r2
	blt _02255CB0
	ldr r1, [r4, #0x6c]
	sub r1, r1, r2
	str r1, [r0, #4]
	mov r0, #0xb
	str r0, [r4]
	b _02255CB0
_02255C64:
	add r1, r4, #0
	add r1, #0x4c
	ldrb r2, [r1]
	mov r1, #0x27
	lsl r1, r1, #4
	mul r1, r2
	add r1, r6, r1
	add r5, #0x9c
	ldrb r1, [r1, #0xb]
	ldr r0, [r5]
	bl MapPropManager_GetMapPropByIndex
	bl MapProp_GetRotation
	mov r1, #1
	ldr r2, [r0, #4]
	lsl r1, r1, #0xa
	add r2, r2, r1
	str r2, [r0, #4]
	ldr r2, [r4, #0x64]
	sub r1, r2, r1
	str r1, [r4, #0x64]
	cmp r1, #0
	bgt _02255CB0
	ldr r1, [r4, #0x6c]
	str r1, [r0, #4]
	mov r0, #0xc
	str r0, [r4]
	b _02255CB0
_02255C9E:
	ldr r0, _02255CB8 ; =SEQ_SE_GS_GONDORA_IDOU
	mov r1, #0
	bl StopSE
	add r0, r4, #0
	bl Heap_Free
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02255CB0:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02255CB4: .word SEQ_SE_GS_GONDORA_KABEHIT
_02255CB8: .word SEQ_SE_GS_GONDORA_IDOU
	thumb_func_end ov04_02255AC4


	thumb_func_start ov04_02255CBC
ov04_02255CBC: ; 0x02255CBC
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	ldrb r1, [r4, #4]
	add r6, r2, #0
	add r5, r0, #0
	sub r2, r1, #1
	lsl r2, r2, #0x18
	lsr r7, r2, #0x18
	add r2, r4, #0
	add r2, #0xa8
	bl ov04_02255910
	cmp r0, #0xff
	beq _02255CDC
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02255CDC:
	ldrb r1, [r4, #4]
	add r2, r4, #0
	add r0, r5, #0
	add r2, #0xd0
	bl ov04_02255910
	cmp r0, #0xff
	beq _02255CF0
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02255CF0:
	ldrb r1, [r4, #5]
	add r2, r4, #0
	add r0, r5, #0
	add r2, #0x68
	bl ov04_02255910
	cmp r0, #0xff
	beq _02255D04
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02255D04:
	add r2, r4, #0
	add r0, r5, #0
	add r1, r7, #0
	add r2, #0x28
	bl ov04_02255910
	cmp r0, #0xff
	beq _02255D18
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02255D18:
	add r0, r5, #0
	add r1, r4, #0
	bl ov04_02255D34
	mov r1, #1
	lsl r1, r1, #0xe
	cmp r0, r1
	bhs _02255D2E
	strh r0, [r6]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02255D2E:
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov04_02255CBC


	thumb_func_start ov04_02255D34
ov04_02255D34: ; 0x02255D34
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	add r7, r0, #0
	ldr r0, [r5]
	cmp r0, #0
	bne _02255D48
	mov r1, #0xe
	ldr r3, _02255D78 ; =ov04_02257638
	ldr r4, _02255D7C ; =ov04_02257618
	b _02255D4E
_02255D48:
	ldr r3, _02255D80 ; =ov04_02257648
	ldr r4, _02255D84 ; =ov04_02257614
	mov r1, #0x18
_02255D4E:
	ldrb r0, [r5, #4]
	add r2, r5, #0
	add r2, #0xf8
	str r0, [sp]
	add r0, r7, #0
	bl ov04_02255960
	mov r2, #0x6e
	lsl r2, r2, #2
	add r6, r0, #0
	ldr r1, [sp]
	add r0, r7, #0
	add r2, r5, r2
	add r3, r4, #0
	bl ov04_02255960
	cmp r6, r0
	bhi _02255D74
	add r0, r6, #0
_02255D74:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02255D78: .word ov04_02257638
_02255D7C: .word ov04_02257618
_02255D80: .word ov04_02257648
_02255D84: .word ov04_02257614
	thumb_func_end ov04_02255D34


	thumb_func_start ov04_02255D88
ov04_02255D88: ; 0x02255D88
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	add r4, r1, #0
	ldr r6, [r4, #0x70]
	add r7, r0, #0
	ldr r1, [r6, #4]
	ldr r5, [r1, #0x24]
	ldr r1, [r4]
	cmp r1, #6
	bhi _02255E5C
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02255DA8: ; jump table
	.short _02255FB8 - _02255DA8 - 2 ; case 0
	.short _02255DB6 - _02255DA8 - 2 ; case 1
	.short _02255DEA - _02255DA8 - 2 ; case 2
	.short _02255FB8 - _02255DA8 - 2 ; case 3
	.short _02255EDE - _02255DA8 - 2 ; case 4
	.short _02255EEC - _02255DA8 - 2 ; case 5
	.short _02255F1C - _02255DA8 - 2 ; case 6
_02255DB6:
	add r0, r4, #0
	mov r1, #0
	add r0, #0x4f
	strb r1, [r0]
	add r1, r4, #0
	add r1, #0x4c
	ldrb r2, [r1]
	mov r1, #0x27
	lsl r1, r1, #4
	mul r1, r2
	add r1, r5, r1
	ldrb r1, [r1, #9]
	add r0, r6, #0
	add r2, r4, #4
	bl ov04_02255910
	cmp r0, #0xff
	bne _02255DE2
	mov r0, #2
	add sp, #0x40
	str r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_02255DE2:
	mov r0, #4
	add sp, #0x40
	str r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_02255DEA:
	add r1, r4, #0
	add r1, #0x4c
	ldrb r2, [r1]
	mov r1, #0x27
	lsl r1, r1, #4
	mul r1, r2
	add r0, r6, #0
	add r1, r5, r1
	add r0, #0x9c
	ldrb r1, [r1, #0xb]
	ldr r0, [r0]
	bl MapPropManager_GetMapPropByIndex
	str r0, [sp]
	ldr r1, [sp]
	add r0, sp, #0x34
	bl MapProp_GetTranslation
	add r0, sp, #0x34
	add r1, r4, #0
	add r1, #0x58
	add r2, r0, #0
	bl VEC_Add
	ldr r0, [sp]
	add r1, sp, #0x34
	bl MapProp_SetTranslation
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	add r1, sp, #0x28
	add r6, r0, #0
	bl MapObject_CopyPositionVector
	add r0, sp, #0x28
	add r1, r4, #0
	add r1, #0x58
	add r2, r0, #0
	bl VEC_Add
	add r0, r6, #0
	add r1, sp, #0x28
	bl MapObject_SetPositionVector
	add r0, r4, #0
	add r0, #0x4f
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x4f
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x4f
	ldrb r0, [r0]
	cmp r0, #2
	bhs _02255E5E
_02255E5C:
	b _02255FB8
_02255E5E:
	add r0, r4, #0
	mov r1, #0
	add r0, #0x4f
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x4c
	ldrb r1, [r0]
	mov r0, #0x27
	lsl r0, r0, #4
	mul r0, r1
	add r0, r5, r0
	ldrb r0, [r0, #9]
	add r1, r4, #0
	bl ov04_02255858
	add r0, r4, #0
	add r0, #0x4d
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x4d
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x4d
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x4e
	ldrb r0, [r0]
	cmp r1, r0
	blo _02255ED6
	add r0, r6, #0
	add r1, sp, #0x1c
	bl MapObject_CopyPositionVector
	ldr r2, [sp, #0x1c]
	add r0, r6, #0
	asr r1, r2, #0xf
	lsr r1, r1, #0x10
	add r1, r2, r1
	asr r1, r1, #0x10
	bl MapObject_SetCurrentX
	ldr r2, [sp, #0x24]
	add r0, r6, #0
	asr r1, r2, #0xf
	lsr r1, r1, #0x10
	add r1, r2, r1
	asr r1, r1, #0x10
	bl MapObject_SetCurrentZ
	add r0, r6, #0
	bl sub_02060F78
	add r0, r7, #0
	bl SysTask_Destroy
	mov r0, #3
	add sp, #0x40
	str r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_02255ED6:
	mov r0, #1
	add sp, #0x40
	str r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_02255EDE:
	ldr r0, _02255FBC ; =SEQ_SE_GS_GONDORA_KABEHIT
	bl PlaySE
	mov r0, #5
	add sp, #0x40
	str r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_02255EEC:
	add r1, r4, #0
	add r1, #0x4d
	ldrb r1, [r1]
	cmp r1, #0
	bne _02255F02
	bl SysTask_Destroy
	mov r0, #7
	add sp, #0x40
	str r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_02255F02:
	ldr r1, [r4, #0x58]
	mov r0, #0
	mvn r0, r0
	add r2, r1, #0
	mul r2, r0
	str r2, [r4, #0x58]
	ldr r1, [r4, #0x60]
	add sp, #0x40
	mul r0, r1
	str r0, [r4, #0x60]
	mov r0, #6
	str r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_02255F1C:
	add r1, r4, #0
	add r1, #0x4c
	ldrb r2, [r1]
	mov r1, #0x27
	lsl r1, r1, #4
	mul r1, r2
	add r0, r6, #0
	add r1, r5, r1
	add r0, #0x9c
	ldrb r1, [r1, #0xb]
	ldr r0, [r0]
	bl MapPropManager_GetMapPropByIndex
	add r5, r0, #0
	add r0, sp, #0x10
	add r1, r5, #0
	bl MapProp_GetTranslation
	add r0, sp, #0x10
	add r1, r4, #0
	add r1, #0x58
	add r2, r0, #0
	bl VEC_Add
	add r0, r5, #0
	add r1, sp, #0x10
	bl MapProp_SetTranslation
	ldr r0, [r6, #0x40]
	bl PlayerAvatar_GetMapObject
	add r1, sp, #4
	add r5, r0, #0
	bl MapObject_CopyPositionVector
	add r0, sp, #4
	add r1, r4, #0
	add r1, #0x58
	add r2, r0, #0
	bl VEC_Add
	add r0, r5, #0
	add r1, sp, #4
	bl MapObject_SetPositionVector
	add r0, r4, #0
	add r0, #0x4f
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x4f
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x4f
	ldrb r0, [r0]
	cmp r0, #2
	blo _02255FB8
	add r0, r4, #0
	mov r1, #0
	add r0, #0x4f
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x4d
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x4d
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x4d
	ldrb r0, [r0]
	cmp r0, #0
	bne _02255FB8
	add r0, r7, #0
	bl SysTask_Destroy
	mov r0, #7
	str r0, [r4]
_02255FB8:
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02255FBC: .word SEQ_SE_GS_GONDORA_KABEHIT
	thumb_func_end ov04_02255D88


	thumb_func_start ov04_02255FC0
ov04_02255FC0: ; 0x02255FC0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #2
	bl Save_Gymmick_AssertMagic_GetData
	add r4, r0, #0
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
	ldr r0, [r4]
	cmp r0, #0
	beq _0225603E
	add r0, r5, #0
	bl ov04_02256278
	add r7, r0, #0
	ldr r4, _02256040 ; =0x00000000
	beq _02256026
_02256004:
	ldr r2, [r5, #0x54]
	mov r0, #0xae
	add r1, r4, #0
	bl MapPropAnimationManager_GetAnimationData
	add r6, r0, #0
	mov r1, #1
	bl MapPropAnimationData_SetAnimationPaused
	add r0, r6, #0
	bl MapPropAnimationData_GoToLastAnimationFrame
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, r7
	blo _02256004
_02256026:
	ldr r2, [r5, #0x54]
	mov r0, #0xaf
	mov r1, #0
	bl MapPropAnimationManager_GetAnimationData
	add r4, r0, #0
	mov r1, #1
	bl MapPropAnimationData_SetAnimationPaused
	add r0, r4, #0
	bl MapPropAnimationData_GoToLastAnimationFrame
_0225603E:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02256040: .word 0x00000000
	thumb_func_end ov04_02255FC0
