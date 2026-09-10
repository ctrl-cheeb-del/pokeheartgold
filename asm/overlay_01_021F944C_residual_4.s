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

	thumb_func_start ov01_021F9B54
ov01_021F9B54: ; 0x021F9B54
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r7, r1, #0
	bl ov01_021FA200
	add r6, r0, #0
	add r0, r5, #0
	bl ov01_021FA20C
	lsl r4, r0, #2
	add r0, r5, #0
	bl ov01_021FA214
	add r3, r0, #0
	add r0, r6, r4
	add r1, r7, #0
	mov r2, #0xff
	bl ov01_021F9AB4
	cmp r0, #0
	bne _021F9B82
	bl GF_AssertFail
_021F9B82:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov01_021F9B54


	thumb_func_start ov01_021F9B84
ov01_021F9B84: ; 0x021F9B84
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r7, r1, #0
	bl ov01_021FA200
	add r6, r0, #0
	add r0, r5, #0
	bl ov01_021FA20C
	lsl r4, r0, #2
	add r0, r5, #0
	bl ov01_021FA214
	add r2, r0, #0
	add r0, r6, r4
	add r1, r7, #0
	bl ov01_021F9AD0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov01_021F9B84


	thumb_func_start ov01_021F9BAC
ov01_021F9BAC: ; 0x021F9BAC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r7, r1, #0
	bl ov01_021FA200
	add r6, r0, #0
	add r0, r5, #0
	bl ov01_021FA20C
	lsl r4, r0, #2
	add r0, r5, #0
	bl ov01_021FA214
	add r3, r0, #0
	add r0, r6, r4
	add r1, r7, #0
	mov r2, #0xff
	bl ov01_021F9AE4
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov01_021F9BAC


	thumb_func_start ov01_021F9BD4
ov01_021F9BD4: ; 0x021F9BD4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	add r7, r0, #0
	add r0, r6, #0
	bl ov01_021FA1DC
	add r0, r6, #0
	bl ov01_021FA200
	add r4, r0, #0
	add r0, r6, #0
	bl ov01_021FA20C
	lsl r0, r0, #2
	add r5, r4, r0
	add r0, r6, #0
	bl ov01_021FA214
	add r4, r0, #0
_021F9BFA:
	ldr r1, [r5]
	cmp r1, #0xff
	beq _021F9C1C
	add r0, r7, #0
	mov r2, #0
	bl ov01_021FA01C
	cmp r0, #0
	bne _021F9C1C
	add r0, r6, #0
	add r0, #0xf8
	ldr r0, [r0]
	ldr r1, [r5]
	bl ov01_021FC588
	mov r0, #0xff
	str r0, [r5]
_021F9C1C:
	add r5, r5, #4
	sub r4, r4, #1
	bne _021F9BFA
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov01_021F9BD4
