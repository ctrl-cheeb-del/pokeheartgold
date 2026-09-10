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

	thumb_func_start ov01_021F9FCC
ov01_021F9FCC: ; 0x021F9FCC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r1, #0
	mov r1, #0
	add r4, r2, #0
	str r1, [sp, #4]
	str r1, [sp]
	add r1, sp, #0
	add r2, sp, #4
	mov r3, #1
	add r6, r0, #0
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #1
	bne _021FA016
	add r7, sp, #0
_021F9FEC:
	cmp r4, #0
	beq _021F9FF6
	ldr r0, [sp]
	cmp r4, r0
	beq _021FA006
_021F9FF6:
	ldr r0, [sp]
	bl MapObject_GetSpriteID
	cmp r0, r5
	bne _021FA006
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021FA006:
	add r0, r6, #0
	add r1, r7, #0
	add r2, sp, #4
	mov r3, #1
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #1
	beq _021F9FEC
_021FA016:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov01_021F9FCC


	thumb_func_start ov01_021FA01C
ov01_021FA01C: ; 0x021FA01C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r1, #0
	mov r1, #0
	add r5, r2, #0
	str r1, [sp, #4]
	str r1, [sp]
	add r1, sp, #0
	add r2, sp, #4
	mov r3, #1
	add r7, r0, #0
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #1
	bne _021FA088
_021FA03A:
	cmp r5, #0
	beq _021FA044
	ldr r0, [sp]
	cmp r5, r0
	beq _021FA078
_021FA044:
	ldr r0, [sp]
	bl MapObject_GetSpriteID
	add r4, r0, #0
	ldr r0, _021FA090 ; =0x0000FFFF
	cmp r4, r0
	beq _021FA078
	ldr r0, [sp]
	bl ov01_021F9318
	ldrh r0, [r0]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	cmp r0, #1
	bne _021FA078
	ldr r0, _021FA090 ; =0x0000FFFF
	cmp r4, r0
	beq _021FA078
	add r0, r4, #0
	bl ov01_021FA28C
	cmp r6, r0
	bne _021FA078
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021FA078:
	add r0, r7, #0
	add r1, sp, #0
	add r2, sp, #4
	mov r3, #1
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #1
	beq _021FA03A
_021FA088:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FA090: .word 0x0000FFFF
	thumb_func_end ov01_021FA01C


	thumb_func_start ov01_021FA094
ov01_021FA094: ; 0x021FA094
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r1, #0
	mov r1, #0
	add r5, r2, #0
	str r1, [sp, #4]
	str r1, [sp]
	add r1, sp, #0
	add r2, sp, #4
	mov r3, #1
	add r7, r0, #0
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #1
	bne _021FA0FE
_021FA0B2:
	cmp r5, #0
	beq _021FA0BC
	ldr r0, [sp]
	cmp r0, r5
	beq _021FA0EE
_021FA0BC:
	ldr r0, _021FA104 ; =0x0000FFFF
	cmp r4, r0
	beq _021FA0EE
	ldr r0, [sp]
	bl ov01_021F9318
	ldrh r0, [r0]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	cmp r0, #1
	bne _021FA0EE
	ldr r0, [sp]
	bl MapObject_GetSpriteID
	ldr r1, _021FA104 ; =0x0000FFFF
	add r4, r0, #0
	cmp r4, r1
	beq _021FA0EE
	bl ov01_021FA2A0
	cmp r6, r0
	bne _021FA0EE
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021FA0EE:
	add r0, r7, #0
	add r1, sp, #0
	add r2, sp, #4
	mov r3, #1
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #1
	beq _021FA0B2
_021FA0FE:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FA104: .word 0x0000FFFF
	thumb_func_end ov01_021FA094


	thumb_func_start ov01_021FA108
ov01_021FA108: ; 0x021FA108
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r1, #0
	add r6, r0, #0
	add r7, r2, #0
	bl sub_0205F1A0
	add r4, r0, #0
	add r0, r5, #0
	bl ov01_021FA28C
	str r0, [sp]
	ldr r1, [sp]
	add r0, r4, #0
	bl ov01_021F9EEC
	cmp r0, #1
	bne _021FA14E
	ldr r1, [sp]
	add r0, r6, #0
	add r2, r7, #0
	bl ov01_021FA01C
	cmp r0, #0
	bne _021FA14E
	add r0, r4, #0
	add r0, #0xf8
	ldr r0, [r0]
	ldr r1, [sp]
	bl ov01_021FC588
	ldr r1, [sp]
	add r0, r4, #0
	bl ov01_021F9BAC
_021FA14E:
	add r0, r5, #0
	bl ov01_021FA2A0
	str r0, [sp, #4]
	ldr r1, [sp, #4]
	add r0, r4, #0
	bl ov01_021F9F14
	cmp r0, #1
	bne _021FA184
	ldr r1, [sp, #4]
	add r0, r6, #0
	add r2, r7, #0
	bl ov01_021FA094
	cmp r0, #0
	bne _021FA184
	add r0, r4, #0
	add r0, #0xfc
	ldr r0, [r0]
	ldr r1, [sp, #4]
	bl ov01_021FC588
	ldr r1, [sp, #4]
	add r0, r4, #0
	bl ov01_021F9CD0
_021FA184:
	add r0, r4, #0
	add r1, r5, #0
	bl ov01_021F9EC4
	cmp r0, #1
	bne _021FA1C2
	add r0, r6, #0
	add r1, r5, #0
	add r2, r7, #0
	bl ov01_021F9FCC
	cmp r0, #0
	bne _021FA1C2
	add r0, r4, #0
	bl ov01_021FA1F4
	add r1, r5, #0
	bl GF3dGfxRawResMan_FreeObjById
	add r0, r4, #0
	add r1, r5, #0
	bl ov01_021F9E04
	add r0, r4, #0
	add r1, r5, #0
	bl ov01_021FA4F0
	add r0, r4, #0
	add r1, r5, #0
	bl ov01_021FA6A4
_021FA1C2:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov01_021FA108
