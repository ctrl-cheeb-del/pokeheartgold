#include "constants/sndseq.h"
#include "constants/moves.h"
#include "constants/std_script.h"
#include "constants/species.h"
#include "constants/sprites.h"
#include "constants/maps.h"
#include "constants/mmodel.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0096_D31R0201.h"
#include "msgdata/msg/msg_0066_D23R0102.h"
	.include "asm/macros.inc"
	.public ov01_021F9704
	.public ov01_021F9744
	.public ov01_021F9778
	.public ov01_021F9798
	.public ov01_021F97BC
	.public ov01_021F9808
	.public ov01_021F98CC
	.public ov01_021F9918
	.public ov01_021F9980
	.public ov01_021F9B54
	.public ov01_021F9B84
	.public ov01_021F9BAC
	.public ov01_021F9BD4
	.public ov01_021F9C78
	.public ov01_021F9CA8
	.public ov01_021F9CD0
	.public ov01_021F9CF8
	.public ov01_021F9DD0
	.public ov01_021F9E04
	.public ov01_021F9E30
	.public ov01_021F9E9C
	.public ov01_021F9FCC
	.public ov01_021FA01C
	.public ov01_021FA094
	.public ov01_021FA108
	.public ov01_021FA31C
	.public ov01_021FA370
	.public ov01_021FA470
	.public ov01_021FA564
	.public ov01_021FA668
	.public ov01_021FA6A4
	.public ov01_021FA6E0
	.public ov01_021FA71C
	.public ov01_021FA75C
	.public ov01_021FA854
	.public ov01_021FA97C
	.public ov01_021FAB9C
	.public sub_021FA248
	.include "overlay_01_021F944C.inc"
	.include "global.inc"

	.text
	.public ov01_02208B64
	.public ov01_02208B70
	.public ov01_02208B80
	.public ov01_02208B90
	.public FldObjSys_ReadMModelFromNarc
	.public ov01_021F944C
	.public ov01_021F94A0
	.public ov01_021F94C0
	.public ov01_021F9510
	.public ov01_021F9528
	.public ov01_021F9574
	.public ov01_021F95A8
	.public ov01_021F95CC
	.public ov01_021F9610
	.public ov01_021F9630
	.public ov01_021F9654
	.public ov01_021F9688
	.public ov01_021F9698
	.public ov01_021F96E4
	.public ov01_021F9890
	.public ov01_021F98B4
	.public ov01_021F9968
	.public ov01_021F9974
	.public ov01_021F99A4
	.public ov01_021F99D0
	.public ov01_021F99FC
	.public ov01_021F9A18
	.public ov01_021F9A44
	.public ov01_021F9A70
	.public ov01_021F9A8C
	.public ov01_021F9AAC
	.public ov01_021F9AB4
	.public ov01_021F9AD0
	.public ov01_021F9AE4
	.public ov01_021F9B00
	.public ov01_021F9B10
	.public ov01_021F9B38
	.public ov01_021F9C24
	.public ov01_021F9C34
	.public ov01_021F9C5C
	.public ov01_021F9D48
	.public ov01_021F9D5C
	.public ov01_021F9D88
	.public ov01_021F9DA4
	.public ov01_021F9EC4
	.public ov01_021F9EEC
	.public ov01_021F9F14
	.public ov01_021F9F3C
	.public ov01_021F9F54
	.public ov01_021F9F6C
	.public ov01_021F9F84
	.public ov01_021F9FB0
	.public ov01_021FA1C8
	.public ov01_021FA1D0
	.public ov01_021FA1D8
	.public ov01_021FA1DC
	.public ov01_021FA1E4
	.public ov01_021FA1EC
	.public ov01_021FA1F4
	.public ov01_021FA1FC
	.public ov01_021FA200
	.public ov01_021FA204
	.public ov01_021FA208
	.public ov01_021FA20C
	.public ov01_021FA210
	.public ov01_021FA214
	.public ov01_021FA218
	.public ov01_021FA21C
	.public ov01_021FA220
	.public ov01_021FA224
	.public ov01_021FA228
	.public ov01_021FA22C
	.public ov01_021FA230
	.public ov01_021FA234
	.public ov01_021FA28C
	.public ov01_021FA298
	.public ov01_021FA2A0
	.public ov01_021FA2AC
	.public ov01_021FA2B8
	.public ov01_021FA2D4
	.public ov01_021FA2EC
	.public ov01_021FA314
	.public ov01_021FA3DC
	.public ov01_021FA3E8
	.public ov01_021FA40C
	.public ov01_021FA44C
	.public ov01_021FA458
	.public ov01_021FA464
	.public ov01_021FA4F0
	.public ov01_021FA524
	.public ov01_021FA61C
	.public ov01_021FA798
	.public ov01_021FA7C8
	.public ov01_021FA7F8
	.public ov01_021FA804
	.public ov01_021FA8F8
	.public ov01_021FA930

	thumb_func_start ov01_021F9704
ov01_021F9704: ; 0x021F9704
	push {r4, r5, r6, lr}
	add r2, r0, #0
	add r2, #0xf4
	ldr r4, [r2]
	ldr r2, [r0, #4]
	add r6, r4, #0
	add r5, r2, #0
_021F9712:
	ldr r3, [r6]
	cmp r3, r1
	bne _021F971C
	ldr r0, [r6, #4]
	pop {r4, r5, r6, pc}
_021F971C:
	add r6, #8
	sub r5, r5, #1
	bne _021F9712
	ldr r3, _021F9740 ; =0x0000FFFF
_021F9724:
	ldr r5, [r4]
	cmp r5, r3
	bne _021F9736
	str r1, [r4]
	ldr r2, [r4, #4]
	bl ov01_021FA370
	ldr r0, [r4, #4]
	pop {r4, r5, r6, pc}
_021F9736:
	add r4, #8
	sub r2, r2, #1
	bne _021F9724
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021F9740: .word 0x0000FFFF
	thumb_func_end ov01_021F9704


	thumb_func_start ov01_021F9744
ov01_021F9744: ; 0x021F9744
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r4, r2, #0
	bl sub_0205F1A0
	add r1, r0, #0
	add r1, #0xf4
	ldr r2, [r1]
	ldr r1, [r0, #4]
_021F9756:
	ldr r0, [r2]
	cmp r0, r5
	bne _021F976C
	ldr r3, [r2, #4]
	mov r2, #5
_021F9760:
	ldmia r3!, {r0, r1}
	stmia r4!, {r0, r1}
	sub r2, r2, #1
	bne _021F9760
	mov r0, #1
	pop {r3, r4, r5, pc}
_021F976C:
	add r2, #8
	sub r1, r1, #1
	bne _021F9756
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov01_021F9744


	thumb_func_start ov01_021F9778
ov01_021F9778: ; 0x021F9778
	add r2, r0, #0
	add r2, #0xf4
	ldr r3, [r2]
	ldr r2, [r0, #4]
_021F9780:
	ldr r0, [r3]
	cmp r0, r1
	bne _021F978C
	ldr r0, _021F9794 ; =0x0000FFFF
	str r0, [r3]
	bx lr
_021F978C:
	add r3, #8
	sub r2, r2, #1
	bne _021F9780
	bx lr
	.balign 4, 0
_021F9794: .word 0x0000FFFF
	thumb_func_end ov01_021F9778


	thumb_func_start ov01_021F9798
ov01_021F9798: ; 0x021F9798
	push {r3, r4}
	add r1, r0, #0
	add r1, #0xf4
	ldr r4, [r1]
	ldr r1, _021F97B8 ; =0x0000FFFF
	ldr r3, [r0, #4]
	add r0, r1, #0
_021F97A6:
	ldr r2, [r4]
	cmp r2, r0
	beq _021F97AE
	str r1, [r4]
_021F97AE:
	add r4, #8
	sub r3, r3, #1
	bne _021F97A6
	pop {r3, r4}
	bx lr
	.balign 4, 0
_021F97B8: .word 0x0000FFFF
	thumb_func_end ov01_021F9798


	thumb_func_start ov01_021F97BC
ov01_021F97BC: ; 0x021F97BC
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r5, r1, #0
	add r6, r2, #0
	bl MapObjectManager_GetObjectCount
	add r4, r0, #0
	add r0, r7, #0
	bl MapObjectManager_GetObjects2
	ldr r7, _021F9804 ; =0x0000FFFF
	str r0, [sp]
_021F97D4:
	ldr r0, [sp]
	cmp r0, r5
	beq _021F97F4
	bl MapObject_CheckActive
	cmp r0, #1
	bne _021F97F4
	ldr r0, [sp]
	bl MapObject_GetSpriteID
	cmp r0, r7
	beq _021F97F4
	cmp r0, r6
	bne _021F97F4
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021F97F4:
	add r0, sp, #0
	bl MapObjectArray_NextObject
	sub r4, r4, #1
	bne _021F97D4
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F9804: .word 0x0000FFFF
	thumb_func_end ov01_021F97BC


	thumb_func_start ov01_021F9808
ov01_021F9808: ; 0x021F9808
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	add r7, r3, #0
	mov r0, #4
	mov r1, #0x3f
	lsl r2, r4, #0xc
	add r3, r4, #0
	bl ov01_021FC4C4
	add r1, r5, #0
	add r1, #0xf8
	str r0, [r1]
	add r0, r5, #0
	bl ov01_021F9B00
	add r0, r5, #0
	add r1, r6, #0
	bl ov01_021FA208
	add r0, r5, #0
	sub r1, r4, r6
	bl ov01_021FA210
	mov r0, #4
	mov r1, #0x40
	lsl r2, r7, #7
	add r3, r7, #0
	bl ov01_021FC4C4
	add r1, r5, #0
	add r1, #0xfc
	str r0, [r1]
	add r0, r5, #0
	bl ov01_021F9C24
	ldr r1, [sp, #0x18]
	add r0, r5, #0
	bl ov01_021FA218
	ldr r1, [sp, #0x18]
	add r0, r5, #0
	sub r1, r7, r1
	bl ov01_021FA220
	ldr r0, [sp, #0x1c]
	mov r1, #4
	bl GF3dGfxRawResMan_Create
	add r1, r0, #0
	add r0, r5, #0
	bl ov01_021FA1EC
	add r0, r5, #0
	bl ov01_021F9D48
	ldr r1, [sp, #0x20]
	add r0, r5, #0
	bl ov01_021FA228
	ldr r2, [sp, #0x1c]
	ldr r1, [sp, #0x20]
	add r0, r5, #0
	sub r1, r2, r1
	bl ov01_021FA230
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov01_021F9808
