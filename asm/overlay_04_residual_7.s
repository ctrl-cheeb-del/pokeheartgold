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

	thumb_func_start ov04_02255090
ov04_02255090: ; 0x02255090
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	bl Save_Gymmick_GetType
	cmp r0, #6
	beq _022550A8
	mov r0, #0
	pop {r4, r5, r6, pc}
_022550A8:
	ldr r0, [r5, #4]
	ldr r4, [r0, #0x24]
	cmp r4, #0
	bne _022550B4
	mov r0, #0
	pop {r4, r5, r6, pc}
_022550B4:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetXCoord
	add r6, r0, #0
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetZCoord
	add r2, r0, #0
	lsl r1, r6, #0x10
	lsl r2, r2, #0x10
	add r0, r4, #0
	lsr r1, r1, #0x10
	lsr r2, r2, #0x10
	bl ov04_02255708
	pop {r4, r5, r6, pc}
	thumb_func_end ov04_02255090


	thumb_func_start ov04_022550D4
ov04_022550D4: ; 0x022550D4
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	ldr r0, [sp, #0x18]
	mov r6, #0x79
	str r0, [sp, #0x18]
	mov r0, #0
	mov ip, r0
	ldr r0, [sp]
	lsl r6, r6, #2
	ldr r0, [r0, #4]
	add r3, r1, #0
	ldr r0, [r0, #0x24]
	sub r4, r6, #4
	add r7, r0, #4
_022550F0:
	mov r0, #0
	add r1, r7, #0
_022550F4:
	ldr r5, [r1, r4]
	cmp r3, r5
	bne _0225510A
	ldr r5, [r1, r6]
	cmp r2, r5
	bne _0225510A
	ldr r0, [sp, #0x18]
	mov r1, #0
	str r1, [r0]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0225510A:
	add r0, r0, #1
	add r1, #8
	cmp r0, #0x12
	blt _022550F4
	mov r0, #0x27
	lsl r0, r0, #4
	add r7, r7, r0
	mov r0, ip
	add r0, r0, #1
	mov ip, r0
	cmp r0, #3
	blt _022550F0
	ldr r0, [sp]
	add r1, r3, #0
	bl GetMetatileBehavior
	bl MetatileBehavior_IsMagma
	cmp r0, #0
	beq _0225513A
	ldr r1, [sp, #0x18]
	mov r0, #1
	str r0, [r1]
	pop {r3, r4, r5, r6, r7, pc}
_0225513A:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov04_022550D4


	thumb_func_start ov04_02255140
ov04_02255140: ; 0x02255140
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #4]
	str r1, [sp, #0x38]
	str r2, [r1, #8]
	ldr r2, [sp, #8]
	str r2, [r1, #0xc]
	ldr r1, [sp, #4]
	add r2, r1, #1
	ldr r1, [sp, #0x38]
	str r2, [r1, #0x10]
	ldr r2, [sp, #8]
	str r2, [r1, #0x14]
	ldr r1, [sp, #4]
	sub r7, r1, #1
	ldr r1, [sp, #0x38]
	cmp r0, #1
	str r7, [r1, #0x18]
	ldr r2, [sp, #8]
	str r2, [r1, #0x1c]
	ldr r2, [sp, #4]
	str r2, [r1, #0x20]
	ldr r2, [sp, #8]
	str r2, [r1, #0x24]
	bne _0225517C
	b _022552D6
_0225517C:
	mov r0, #0
	str r0, [r1]
	mov r2, #5
	strb r2, [r1, #4]
	mov r2, #7
	strb r2, [r1, #5]
	ldr r1, [sp, #4]
	ldr r4, [sp, #0x38]
	str r1, [sp, #0x1c]
	ldr r1, [sp, #8]
	str r1, [sp, #0x20]
	ldr r1, [sp, #4]
	add r3, r1, #3
	ldr r1, [sp, #8]
	str r3, [sp, #0x1c]
	sub r2, r1, #2
	str r2, [sp, #0x20]
_0225519E:
	add r1, r2, r0
	str r3, [r4, #0x28]
	str r1, [r4, #0x2c]
	add r0, r0, #1
	add r4, #8
	cmp r0, #7
	blt _0225519E
	ldr r0, [sp, #4]
	ldr r3, [sp, #0x38]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	mov r4, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #4]
	sub r2, r0, #3
	ldr r0, [sp, #8]
	str r2, [sp, #0x1c]
	sub r1, r0, #2
	str r1, [sp, #0x20]
_022551C4:
	add r0, r1, r4
	str r2, [r3, #0x68]
	str r0, [r3, #0x6c]
	add r4, r4, #1
	add r3, #8
	cmp r4, #7
	blt _022551C4
	ldr r0, [sp, #4]
	ldr r2, [sp, #0x38]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	mov r3, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #4]
	sub r1, r0, #2
	ldr r0, [sp, #8]
	str r1, [sp, #0x1c]
	add r0, r0, #5
	str r0, [sp, #0x20]
_022551EA:
	add r4, r2, #0
	add r4, #0xa8
	str r1, [r4]
	add r4, r2, #0
	add r4, #0xac
	str r0, [r4]
	add r4, r2, #0
	add r4, #0xa8
	ldr r4, [r4]
	add r5, r4, r3
	add r4, r2, #0
	add r4, #0xa8
	add r3, r3, #1
	add r2, #8
	str r5, [r4]
	cmp r3, #5
	blt _022551EA
	ldr r0, [sp, #4]
	ldr r2, [sp, #0x38]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	mov r3, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #4]
	sub r1, r0, #2
	ldr r0, [sp, #8]
	str r1, [sp, #0x1c]
	sub r0, r0, #3
	str r0, [sp, #0x20]
_02255224:
	add r4, r2, #0
	add r4, #0xd0
	str r1, [r4]
	add r4, r2, #0
	add r4, #0xd4
	str r0, [r4]
	add r4, r2, #0
	add r4, #0xd0
	ldr r4, [r4]
	add r5, r4, r3
	add r4, r2, #0
	add r4, #0xd0
	add r3, r3, #1
	add r2, #8
	str r5, [r4]
	cmp r3, #5
	blt _02255224
	ldr r0, [sp, #4]
	mov r6, #0
	sub r0, r0, #4
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	str r6, [sp, #0x10]
	add r4, r0, #4
_02255254:
	ldr r0, [sp, #0xc]
	str r4, [sp, #0x20]
	str r0, [sp, #0x1c]
	sub r2, r0, r6
	ldr r0, [sp, #0x10]
	str r2, [sp, #0x1c]
	lsl r1, r0, #3
	ldr r0, [sp, #0x38]
	mov r3, #0
	add r5, r0, r1
_02255268:
	add r0, r5, #0
	add r0, #0xf8
	str r2, [r0]
	add r0, r5, #0
	add r0, #0xfc
	str r4, [r0]
	add r0, r5, #0
	add r0, #0xfc
	ldr r0, [r0]
	sub r1, r0, r3
	add r0, r5, #0
	add r0, #0xfc
	add r3, r3, #1
	add r5, #8
	str r1, [r0]
	cmp r3, #7
	blt _02255268
	ldr r0, [sp, #0x10]
	add r6, r6, #1
	add r0, r0, #7
	str r0, [sp, #0x10]
	cmp r6, #2
	blt _02255254
	ldr r0, [sp, #0x38]
	mov r4, #0
	ldrb r3, [r0, #4]
	cmp r3, #0
	ble _022552D4
	ldr r0, [sp, #4]
	add r2, r0, #3
	ldr r0, [sp, #8]
	str r2, [sp, #0x1c]
	sub r1, r0, #2
	str r1, [sp, #0x20]
	cmp r3, #0
	ble _022552D4
	mov r6, #0x6f
	lsl r6, r6, #2
	ldr r3, [sp, #0x38]
	add r0, r6, #0
_022552B8:
	mov r5, #0x6e
	lsl r5, r5, #2
	str r2, [r3, r5]
	add r5, r5, #4
	str r1, [r3, r5]
	ldr r5, [r3, r6]
	add r5, r5, r4
	str r5, [r3, r0]
	ldr r5, [sp, #0x38]
	add r4, r4, #1
	ldrb r5, [r5, #4]
	add r3, #8
	cmp r4, r5
	blt _022552B8
_022552D4:
	b _02255432
_022552D6:
	ldr r0, [sp, #0x38]
	mov r1, #1
	str r1, [r0]
	mov r1, #4
	strb r1, [r0, #4]
	mov r1, #8
	strb r1, [r0, #5]
	ldr r0, [sp, #4]
	ldr r4, [sp, #0x38]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	mov r3, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #4]
	add r2, r0, #2
	ldr r0, [sp, #8]
	str r2, [sp, #0x1c]
	sub r1, r0, #2
	str r1, [sp, #0x20]
_022552FC:
	add r0, r1, r3
	str r2, [r4, #0x28]
	str r0, [r4, #0x2c]
	add r3, r3, #1
	add r4, #8
	cmp r3, #8
	blt _022552FC
	ldr r0, [sp, #4]
	ldr r3, [sp, #0x38]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	mov r4, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #4]
	sub r2, r0, #3
	ldr r0, [sp, #8]
	str r2, [sp, #0x1c]
	sub r1, r0, #2
	str r1, [sp, #0x20]
_02255322:
	add r0, r1, r4
	str r2, [r3, #0x68]
	str r0, [r3, #0x6c]
	add r4, r4, #1
	add r3, #8
	cmp r4, #8
	blt _02255322
	ldr r0, [sp, #4]
	ldr r2, [sp, #0x38]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	mov r3, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #4]
	sub r1, r0, #2
	ldr r0, [sp, #8]
	str r1, [sp, #0x1c]
	add r0, r0, #6
	str r0, [sp, #0x20]
_02255348:
	add r4, r2, #0
	add r4, #0xa8
	str r1, [r4]
	add r4, r2, #0
	add r4, #0xac
	str r0, [r4]
	add r4, r2, #0
	add r4, #0xa8
	ldr r4, [r4]
	add r5, r4, r3
	add r4, r2, #0
	add r4, #0xa8
	add r3, r3, #1
	add r2, #8
	str r5, [r4]
	cmp r3, #4
	blt _02255348
	ldr r0, [sp, #4]
	ldr r2, [sp, #0x38]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	mov r3, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #4]
	sub r1, r0, #2
	ldr r0, [sp, #8]
	str r1, [sp, #0x1c]
	sub r0, r0, #3
	str r0, [sp, #0x20]
_02255382:
	add r4, r2, #0
	add r4, #0xd0
	str r1, [r4]
	add r4, r2, #0
	add r4, #0xd4
	str r0, [r4]
	add r4, r2, #0
	add r4, #0xd0
	ldr r4, [r4]
	add r5, r4, r3
	add r4, r2, #0
	add r4, #0xd0
	add r3, r3, #1
	add r2, #8
	str r5, [r4]
	cmp r3, #4
	blt _02255382
	ldr r0, [sp, #4]
	mov r6, #0
	sub r0, r0, #4
	str r0, [sp, #0x14]
	ldr r0, [sp, #8]
	str r6, [sp, #0x18]
	add r4, r0, #5
_022553B2:
	ldr r0, [sp, #0x14]
	str r4, [sp, #0x20]
	str r0, [sp, #0x1c]
	sub r2, r0, r6
	ldr r0, [sp, #0x18]
	str r2, [sp, #0x1c]
	lsl r1, r0, #3
	ldr r0, [sp, #0x38]
	mov r3, #0
	add r5, r0, r1
_022553C6:
	add r0, r5, #0
	add r0, #0xf8
	str r2, [r0]
	add r0, r5, #0
	add r0, #0xfc
	str r4, [r0]
	add r0, r5, #0
	add r0, #0xfc
	ldr r0, [r0]
	sub r1, r0, r3
	add r0, r5, #0
	add r0, #0xfc
	add r3, r3, #1
	add r5, #8
	str r1, [r0]
	cmp r3, #8
	blt _022553C6
	ldr r0, [sp, #0x18]
	add r6, r6, #1
	add r0, #8
	str r0, [sp, #0x18]
	cmp r6, #3
	blt _022553B2
	ldr r0, [sp, #0x38]
	mov r4, #0
	ldrb r3, [r0, #4]
	cmp r3, #0
	ble _02255432
	ldr r0, [sp, #4]
	add r2, r0, #3
	ldr r0, [sp, #8]
	str r2, [sp, #0x1c]
	sub r1, r0, #2
	str r1, [sp, #0x20]
	cmp r3, #0
	ble _02255432
	mov r6, #0x6f
	lsl r6, r6, #2
	ldr r3, [sp, #0x38]
	add r0, r6, #0
_02255416:
	mov r5, #0x6e
	lsl r5, r5, #2
	str r2, [r3, r5]
	add r5, r5, #4
	str r1, [r3, r5]
	ldr r5, [r3, r6]
	add r5, r5, r4
	str r5, [r3, r0]
	ldr r5, [sp, #0x38]
	add r4, r4, #1
	ldrb r5, [r5, #4]
	add r3, #8
	cmp r4, r5
	blt _02255416
_02255432:
	ldr r0, [sp, #8]
	mov r6, #0x1e
	sub r2, r0, #1
	mov r1, #0
	lsl r6, r6, #4
	str r7, [sp, #0x1c]
	str r2, [sp, #0x20]
	mov ip, r1
	add r4, r6, #4
_02255444:
	ldr r3, [sp, #0x38]
	lsl r5, r1, #3
	mov r0, #0
	add r5, r3, r5
_0225544C:
	add r3, r7, r0
	str r3, [r5, r6]
	str r2, [r5, r4]
	add r0, r0, #1
	add r5, #8
	cmp r0, #3
	blt _0225544C
	mov r0, ip
	add r0, r0, #1
	add r1, r1, #3
	add r2, r2, #1
	mov ip, r0
	cmp r0, #6
	blt _02255444
	ldr r1, [sp]
	ldr r0, [sp, #0x38]
	ldr r3, [sp, #0x38]
	strb r1, [r0, #6]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl ov04_022554FC
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov04_02255140


	thumb_func_start ov04_02255480
ov04_02255480: ; 0x02255480
	push {r4, r5}
	ldr r4, [r3]
	ldr r3, [r3, #4]
	ldr r5, [sp, #8]
	sub r4, r4, r1
	sub r3, r3, r2
	cmp r0, #1
	beq _0225549C
	cmp r0, #2
	beq _022554A4
	cmp r0, #3
	beq _022554AE
	pop {r4, r5}
	bx lr
_0225549C:
	neg r0, r3
	str r0, [r5]
	str r4, [r5, #4]
	b _022554B4
_022554A4:
	neg r0, r4
	str r0, [r5]
	neg r0, r3
	str r0, [r5, #4]
	b _022554B4
_022554AE:
	str r3, [r5]
	neg r0, r4
	str r0, [r5, #4]
_022554B4:
	ldr r0, [r5]
	add r0, r0, r1
	str r0, [r5]
	ldr r0, [r5, #4]
	add r0, r0, r2
	str r0, [r5, #4]
	pop {r4, r5}
	bx lr
	thumb_func_end ov04_02255480
