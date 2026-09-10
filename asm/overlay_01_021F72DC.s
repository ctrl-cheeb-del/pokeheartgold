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
	.public ov01_021F72DC
	.public ov01_021F7504
	.public ov01_021F772C
	.public ov01_021F7810
	.public ov01_021F7894
	.public ov01_021F7918
	.public ov01_021F7A90
	.public ov01_021F7B14
	.public ov01_021F7B90
	.public ov01_021F7C14
	.public ov01_021F7C80
	.public ov01_021F7CE4
	.public ov01_021F7E6C
	.public ov01_021F7EE4
	.public ov01_021F7F54
	.public ov01_021F80C4
	.public ov01_021F8164
	.public ov01_021F81FC
	.public ov01_021F82F0
	.public ov01_021F8374
	.public ov01_021F84F4
	.public ov01_021F85F4
	.public ov01_021F8708
	.public ov01_021F878C
	.public ov01_021F8874
	.public ov01_021F89B8
	.public ov01_021F8AB0
	.public ov01_021F8B30
	.include "overlay_01_021F72DC.inc"
	.include "global.inc"

	.text
	.public ov01_022089CC
	.public ov01_022089D8
	.public ov01_022089E8
	.public ov01_022089F8
	.public ov01_02208A08
	.public ov01_02208A18
	.public ov01_02208A28
	.public ov01_02208A38
	.public ov01_02208A48
	.public ov01_02208A64
	.public ov01_02208A80
	.public ov01_02208AA0
	.public ov01_02208AC0
	.public ov01_02208AE4
	.public ov01_02208B0C
	.public ov01_02208B34
	.public ov01_021F73CC
	.public ov01_021F73F4
	.public ov01_021F7408
	.public ov01_021F7434
	.public ov01_021F7478
	.public ov01_021F74B4
	.public ov01_021F74C8
	.public ov01_021F7704
	.public ov01_021F771C
	.public ov01_021F77A4
	.public ov01_021F77D0
	.public ov01_021F796C
	.public ov01_021F79A0
	.public ov01_021F79DC
	.public ov01_021F7A18
	.public ov01_021F7A54
	.public ov01_021F7CBC
	.public ov01_021F7DA8
	.public ov01_021F7DD0
	.public ov01_021F7DFC
	.public ov01_021F7E28
	.public ov01_021F7FC8
	.public ov01_021F801C
	.public ov01_021F8070
	.public ov01_021F829C
	.public ov01_021F8400
	.public ov01_021F847C
	.public ov01_021F856C
	.public ov01_021F85BC
	.public ov01_021F86B8
	.public ov01_021F8804
	.public ov01_021F883C
	.public ov01_021F88F0
	.public ov01_021F894C
	.public ov01_021F8A4C
	.public ov01_021F8BA8
	.public ov01_021F8BE0
	.public ov01_021F8C00
	.public ov01_021F8C30
	.public ov01_021F8C3C
	.public ov01_021F8C64
	.public ov01_021F8C88
	.public ov01_021F8CC8
	.public ov01_021F8CFC
	.public ov01_021F8D24
	.public ov01_021F8D28
	.public ov01_021F8D40
	.public ov01_021F8D58

	thumb_func_start ov01_021F72DC
ov01_021F72DC: ; 0x021F72DC
	push {r4, lr}
	add r4, r0, #0
	bl MapObject_GetSpriteID
	cmp r0, #0xf8
	bgt _021F7356
	bge _021F737E
	cmp r0, #0x62
	bgt _021F7308
	cmp r0, #0x61
	blt _021F72FA
	beq _021F737E
	cmp r0, #0x62
	beq _021F737E
	b _021F7388
_021F72FA:
	cmp r0, #0
	bgt _021F7302
	beq _021F737E
	b _021F7388
_021F7302:
	cmp r0, #0x15
	beq _021F737E
	b _021F7388
_021F7308:
	cmp r0, #0xb0
	bgt _021F7310
	beq _021F737E
	b _021F7388
_021F7310:
	add r1, r0, #0
	sub r1, #0xb1
	cmp r1, #0x18
	bhi _021F7388
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021F7324: ; jump table
	.short _021F737E - _021F7324 - 2 ; case 0
	.short _021F737E - _021F7324 - 2 ; case 1
	.short _021F737E - _021F7324 - 2 ; case 2
	.short _021F737E - _021F7324 - 2 ; case 3
	.short _021F737E - _021F7324 - 2 ; case 4
	.short _021F7388 - _021F7324 - 2 ; case 5
	.short _021F7388 - _021F7324 - 2 ; case 6
	.short _021F7388 - _021F7324 - 2 ; case 7
	.short _021F7388 - _021F7324 - 2 ; case 8
	.short _021F7388 - _021F7324 - 2 ; case 9
	.short _021F7388 - _021F7324 - 2 ; case 10
	.short _021F737E - _021F7324 - 2 ; case 11
	.short _021F737E - _021F7324 - 2 ; case 12
	.short _021F7388 - _021F7324 - 2 ; case 13
	.short _021F7388 - _021F7324 - 2 ; case 14
	.short _021F7388 - _021F7324 - 2 ; case 15
	.short _021F7388 - _021F7324 - 2 ; case 16
	.short _021F7388 - _021F7324 - 2 ; case 17
	.short _021F7388 - _021F7324 - 2 ; case 18
	.short _021F737E - _021F7324 - 2 ; case 19
	.short _021F737E - _021F7324 - 2 ; case 20
	.short _021F737E - _021F7324 - 2 ; case 21
	.short _021F737E - _021F7324 - 2 ; case 22
	.short _021F737E - _021F7324 - 2 ; case 23
	.short _021F737E - _021F7324 - 2 ; case 24
_021F7356:
	ldr r2, _021F73C0 ; =0x00000103
	cmp r0, r2
	bgt _021F736E
	bge _021F737E
	cmp r0, #0xf9
	bgt _021F7366
	beq _021F737E
	b _021F7388
_021F7366:
	sub r1, r2, #1
	cmp r0, r1
	beq _021F737E
	b _021F7388
_021F736E:
	add r1, r2, #1
	cmp r0, r1
	bgt _021F7378
	beq _021F737E
	b _021F7388
_021F7378:
	add r1, r2, #2
	cmp r0, r1
	bne _021F7388
_021F737E:
	add r0, r4, #0
	bl sub_0205F40C
	ldr r0, [r0, #4]
	pop {r4, pc}
_021F7388:
	mov r1, #0x6b
	lsl r1, r1, #2
	cmp r0, r1
	blt _021F73A0
	ldr r1, _021F73C4 ; =0x000003E1
	cmp r0, r1
	bgt _021F73A0
	add r0, r4, #0
	bl sub_0205F40C
	ldr r0, [r0]
	pop {r4, pc}
_021F73A0:
	ldr r1, _021F73C8 ; =0x00000106
	cmp r0, r1
	blt _021F73B4
	add r1, r1, #7
	cmp r0, r1
	bgt _021F73B4
	add r0, r4, #0
	bl sub_02064084
	pop {r4, pc}
_021F73B4:
	add r0, r4, #0
	bl sub_0205F40C
	ldr r0, [r0, #4]
	pop {r4, pc}
	nop
_021F73C0: .word 0x00000103
_021F73C4: .word 0x000003E1
_021F73C8: .word 0x00000106
	thumb_func_end ov01_021F72DC
