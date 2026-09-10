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

	thumb_func_start ov04_02256758
ov04_02256758: ; 0x02256758
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	mov r2, #0x20
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	bl HeapExp_FndInitAllocator
	mov r0, #0
	str r0, [sp, #0x14]
_0225676A:
	ldr r0, [sp, #0x14]
	mov r1, #0x9a
	add r4, r0, #0
	lsl r1, r1, #2
	mul r4, r1
	ldr r0, [sp, #8]
	mov r1, #0
	add r0, r0, r4
	add r0, #0xd4
	str r1, [r0]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #8]
	lsl r0, r0, #4
	add r1, #0x10
	str r0, [sp, #0x10]
	add r0, r1, r0
	ldr r2, [sp, #0x14]
	ldr r3, [sp, #0xc]
	mov r1, #0xf8
	bl Field3dModel_LoadFromFilesystem
	mov r0, #0
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	add r0, #0xd8
	add r0, r0, r4
	str r0, [sp, #0x18]
	ldr r0, [sp, #8]
	str r0, [sp, #0x24]
	add r0, #0x10
	str r0, [sp, #0x24]
_022567A8:
	ldr r1, [sp, #0x1c]
	mov r0, #0xcc
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #0x18]
	mov r1, #0
	add r0, r0, r2
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x18]
	add r5, r1, #0
	str r1, [r0, r2]
	ldr r0, [sp, #0x20]
	add r4, r0, #4
_022567C2:
	ldr r0, [sp, #0xc]
	add r3, r5, #1
	str r0, [sp]
	ldr r0, [sp, #8]
	mov r6, #0xc
	str r0, [sp, #4]
	mov r0, #0x14
	mul r6, r3
	ldr r3, [sp, #0x14]
	mul r0, r5
	ldr r2, [sp, #0x24]
	ldr r1, [sp, #0x10]
	add r0, r4, r0
	add r1, r2, r1
	mov r2, #0xf8
	add r3, r6, r3
	bl Field3dModelAnimation_LoadFromFilesystem
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #4
	blo _022567C2
	ldr r0, [sp, #0x20]
	ldr r2, [sp, #0x24]
	ldr r1, [sp, #0x10]
	add r0, #0x54
	add r1, r2, r1
	bl Field3dObject_InitFromModel
	ldr r0, [sp, #0x20]
	mov r5, #0
	add r7, r0, #0
	add r4, r0, #4
	add r7, #0x54
_02256808:
	mov r0, #0x14
	add r6, r5, #0
	mul r6, r0
	add r0, r7, #0
	add r1, r4, r6
	bl Field3dObject_AddAnimation
	add r0, r4, r6
	mov r1, #0
	bl Field3dModelAnimation_FrameSet
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #4
	blo _02256808
	mov r1, #0
	add r0, sp, #0x28
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x28]
	ldr r2, [sp, #0x2c]
	ldr r3, [sp, #0x30]
	add r0, #0x54
	bl Field3dObject_SetPosEx
	ldr r0, [sp, #0x20]
	mov r1, #0
	add r0, #0x54
	str r0, [sp, #0x20]
	bl Field3dObject_SetActiveFlag
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x1c]
	cmp r0, #3
	blo _022567A8
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x14]
	cmp r0, #0xc
	blo _0225676A
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov04_02256758


	thumb_func_start ov04_0225686C
ov04_0225686C: ; 0x0225686C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r0, #0
	mov r0, #0
	str r0, [sp, #8]
	add r0, r6, #0
	str r0, [sp, #0xc]
	add r0, #0x10
	str r0, [sp, #0xc]
	add r0, r6, #0
	str r0, [sp, #0x10]
	add r0, #0xd8
	str r0, [sp, #0x10]
	mov r7, #0x14
_02256888:
	ldr r0, [sp, #8]
	lsl r1, r0, #4
	ldr r0, [sp, #0xc]
	add r0, r0, r1
	bl Field3dModel_Unload
	mov r0, #0
	str r0, [sp, #4]
	ldr r1, [sp, #8]
	mov r0, #0x9a
	lsl r0, r0, #2
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #0x10]
	add r0, r0, r2
	str r0, [sp]
_022568A8:
	ldr r1, [sp, #4]
	mov r0, #0xcc
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp]
	mov r5, #0
	add r0, r0, r2
	add r4, r0, #4
_022568B8:
	add r0, r5, #0
	mul r0, r7
	add r0, r4, r0
	add r1, r6, #0
	bl Field3dModelAnimation_Unload
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #4
	blo _022568B8
	ldr r0, [sp, #4]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	cmp r0, #3
	blo _022568A8
	ldr r0, [sp, #8]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	cmp r0, #0xc
	blo _02256888
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov04_0225686C
