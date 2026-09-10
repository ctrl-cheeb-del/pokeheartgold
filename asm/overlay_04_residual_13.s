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

	thumb_func_start ov04_02256950
ov04_02256950: ; 0x02256950
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r0, #0
	add r7, r2, #0
	add r2, r6, #0
	add r2, #0xd0
	str r1, [sp]
	ldr r1, _02256A38 ; =0x00001DB4
	ldr r3, [r2]
	mov r2, #0xc
	add r1, r6, r1
	mul r2, r3
	add r5, r1, r2
	ldrh r1, [r1, r2]
	cmp r1, #0
	beq _02256978
	bl GF_AssertFail
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_02256978:
	add r1, r7, #0
	bl ov04_02256AC4
	mov r0, #1
	strh r0, [r5]
	mov r0, #0x14
	add r4, r7, #0
	mul r4, r0
	ldr r1, _02256A3C ; =ov04_02257674
	add r0, r6, #0
	ldrh r1, [r1, r4]
	add r0, #0xd4
	strh r7, [r5, #2]
	lsl r1, r1, #0x18
	lsr r2, r1, #0x18
	mov r1, #0x9a
	lsl r1, r1, #2
	mul r1, r2
	add r0, r0, r1
	bl ov04_02256A90
	str r0, [r5, #4]
	ldr r0, _02256A40 ; =ov04_02256734
	add r1, r5, #0
	mov r2, #0
	bl SysTask_CreateOnMainQueue
	str r0, [r5, #8]
	ldr r0, [r5, #4]
	mov r1, #1
	add r0, #0x54
	bl Field3dObject_SetActiveFlag
	add r1, sp, #4
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r0, [sp]
	ldr r0, [r0, #0x40]
	bl PlayerAvatar_GetMapObject
	add r1, sp, #4
	bl MapObject_CopyPositionVector
	ldr r0, _02256A44 ; =ov04_0225766C
	ldr r2, _02256A48 ; =ov04_02257677
	ldr r0, [r0, r4]
	ldrsb r2, [r2, r4]
	lsl r1, r0, #4
	ldr r0, _02256A4C ; =ov04_02257676
	add r1, #8
	ldrsb r0, [r0, r4]
	lsl r2, r2, #4
	lsl r0, r0, #4
	add r0, r1, r0
	lsl r1, r0, #0xc
	ldr r0, _02256A50 ; =ov04_02257670
	str r1, [sp, #4]
	ldr r0, [r0, r4]
	lsl r0, r0, #4
	add r0, #8
	add r0, r0, r2
	lsl r3, r0, #0xc
	str r3, [sp, #0xc]
	ldr r0, [r5, #4]
	ldr r2, [sp, #8]
	add r0, #0x54
	bl Field3dObject_SetPosEx
	mov r4, #0
	mov r7, #0x14
_02256A08:
	ldr r0, [r5, #4]
	add r1, r0, #4
	add r0, r4, #0
	mul r0, r7
	add r0, r1, r0
	mov r1, #0
	bl Field3dModelAnimation_FrameSet
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _02256A08
	add r0, r6, #0
	add r0, #0xd0
	ldr r0, [r0]
	mov r1, #3
	add r0, r0, #1
	bl _s32_div_f
	add r6, #0xd0
	str r1, [r6]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02256A38: .word 0x00001DB4
_02256A3C: .word ov04_02257674
_02256A40: .word ov04_02256734
_02256A44: .word ov04_0225766C
_02256A48: .word ov04_02257677
_02256A4C: .word ov04_02257676
_02256A50: .word ov04_02257670
	thumb_func_end ov04_02256950
