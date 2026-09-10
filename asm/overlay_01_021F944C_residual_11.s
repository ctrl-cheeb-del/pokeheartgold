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

	thumb_func_start ov01_021FA564
ov01_021FA564: ; 0x021FA564
	push {r3, r4, r5, r6, r7, lr}
	str r1, [sp]
	mov r1, #1
	ldr r0, [sp]
	lsl r1, r1, #8
	ldr r4, [r0, r1]
	add r0, #0xe0
	ldr r0, [r0]
	mov r6, #0
	ldr r5, [r4, #0xc]
	bl sub_020238F8
	cmp r0, #1
	beq _021FA618
	add r7, r4, #4
	b _021FA5AE
_021FA584:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _021FA5AA
	ldr r0, [sp]
	ldr r1, [r5]
	mov r2, #0
	bl FldObjSys_ReadMModelFromNarc
	add r2, r0, #0
	ldr r0, [sp]
	ldr r1, [r5, #4]
	ldr r3, [r5, #8]
	bl ov01_021FA61C
	mov r0, #0
	str r0, [r5, #0xc]
	ldrsh r0, [r7, r0]
	add r0, r0, #1
	strh r0, [r7]
_021FA5AA:
	add r5, #0x10
	add r6, r6, #1
_021FA5AE:
	mov r0, #4
	ldrsh r1, [r4, r0]
	mov r0, #2
	ldrsh r0, [r4, r0]
	cmp r1, r0
	bge _021FA5C2
	mov r0, #0
	ldrsh r0, [r4, r0]
	cmp r6, r0
	blt _021FA584
_021FA5C2:
	mov r6, #0
	ldrsh r0, [r4, r6]
	ldr r7, [r4, #0xc]
	sub r1, r0, #1
	cmp r1, #0
	ble _021FA614
	add r5, r7, #0
_021FA5D0:
	ldr r1, [r5, #0xc]
	cmp r1, #0
	bne _021FA606
	add r2, r6, #1
	cmp r2, r0
	bge _021FA606
	lsl r1, r2, #4
	add r3, r7, r1
_021FA5E0:
	ldr r1, [r3, #0xc]
	cmp r1, #0
	beq _021FA5FE
	lsl r0, r2, #4
	add r3, r7, r0
	mov ip, r3
	add r2, r5, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r1, #0
	mov r0, ip
	str r1, [r0, #0xc]
	b _021FA606
_021FA5FE:
	add r2, r2, #1
	add r3, #0x10
	cmp r2, r0
	blt _021FA5E0
_021FA606:
	mov r0, #0
	ldrsh r0, [r4, r0]
	add r6, r6, #1
	add r5, #0x10
	sub r1, r0, #1
	cmp r6, r1
	blt _021FA5D0
_021FA614:
	mov r0, #0
	strh r0, [r4, #4]
_021FA618:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov01_021FA564
