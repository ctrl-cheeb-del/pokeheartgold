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
	.public ov01_021EFB38
	.public ov01_021EFB64
	.public ov01_021EFC04
	.public ov01_021EFD3C
	.public ov01_021EFEC8
	.public ov01_021EFF28
	.public ov01_021EFFEC
	.public ov01_021F0050
	.public ov01_021F010C
	.public ov01_021F0174
	.public ov01_021F01D0
	.public ov01_021F0250
	.public ov01_021F02C4
	.public ov01_021F0360
	.public ov01_021F03C8
	.public ov01_021F03F8
	.public ov01_021F0454
	.public ov01_021F0500
	.public ov01_021F0614
	.public ov01_021F07E0
	.public ov01_021F08C0
	.public ov01_021F0A4C
	.public ov01_021F0B78
	.public ov01_021F0CDC
	.public ov01_021F0D20
	.public ov01_021F0DDC
	.public ov01_021F0F08
	.public ov01_021F10C8
	.public ov01_021F1148
	.public ov01_021F1224
	.public ov01_021F1250
	.public ov01_021F1310
	.include "overlay_01_021EFB38.inc"
	.include "global.inc"

	.text
	.public ov01_022067D0
	.public ov01_022067E0
	.public ov01_022067FC
	.public ov01_02206844
	.public ov01_0220689C
	.public ov01_022068C4
	.public ov01_02206980
	.public ov01_02209B64
	.public ov01_021EFC94
	.public ov01_021EFCDC
	.public ov01_021EFCF8
	.public ov01_021EFE30
	.public ov01_021EFE34
	.public ov01_021EFE44
	.public ov01_021EFE70
	.public ov01_021EFE80
	.public ov01_021EFF90
	.public ov01_021EFFB0
	.public ov01_021EFFBC
	.public ov01_021EFFD8
	.public ov01_021F0028
	.public ov01_021F00DC
	.public ov01_021F029C
	.public ov01_021F0330
	.public ov01_021F05C4
	.public ov01_021F05F4
	.public ov01_021F06EC
	.public ov01_021F0718
	.public ov01_021F074C
	.public ov01_021F0768
	.public ov01_021F0780
	.public ov01_021F0788
	.public ov01_021F0848
	.public ov01_021F0860
	.public ov01_021F0868
	.public ov01_021F0960
	.public ov01_021F09BC
	.public ov01_021F09EC
	.public ov01_021F0A0C
	.public ov01_021F0B44
	.public ov01_021F0B5C
	.public ov01_021F0C40
	.public ov01_021F0C7C
	.public ov01_021F0CA8
	.public ov01_021F0DB0
	.public ov01_021F0DC8
	.public ov01_021F0E74
	.public ov01_021F0E90
	.public ov01_021F0EAC
	.public ov01_021F0EC0
	.public ov01_021F0FB8
	.public ov01_021F1008
	.public ov01_021F1044
	.public ov01_021F1060
	.public ov01_021F1094
	.public ov01_021F1210
	.public ov01_021F127C
	.public ov01_021F1290
	.public ov01_021F12B4
	.public ov01_021F12D0
	.public ov01_021F12E8

	thumb_func_start ov01_021EFD3C
ov01_021EFD3C: ; 0x021EFD3C
	push {r3, r4, lr}
	sub sp, #4
	add r4, r1, #0
	ldr r1, [r4]
	cmp r1, #5
	bhi _021EFE22
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021EFD54: ; jump table
	.short _021EFD60 - _021EFD54 - 2 ; case 0
	.short _021EFD98 - _021EFD54 - 2 ; case 1
	.short _021EFDB2 - _021EFD54 - 2 ; case 2
	.short _021EFDC6 - _021EFD54 - 2 ; case 3
	.short _021EFDE0 - _021EFD54 - 2 ; case 4
	.short _021EFE04 - _021EFD54 - 2 ; case 5
_021EFD60:
	ldr r0, [r4, #0xc]
	cmp r0, #1
	bne _021EFD7A
	mov r0, #8
	str r0, [sp]
	add r0, r4, #0
	ldr r2, [r4, #0x14]
	add r0, #0x30
	mov r1, #0
	mov r3, #2
	bl ov01_021EFFB0
	b _021EFD90
_021EFD7A:
	cmp r0, #2
	bne _021EFD90
	mov r0, #8
	str r0, [sp]
	add r0, r4, #0
	ldr r2, [r4, #0x14]
	add r0, #0x30
	mov r1, #0
	mov r3, #1
	bl ov01_021EFFB0
_021EFD90:
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021EFE22
_021EFD98:
	mov r0, #3
	str r0, [sp]
	add r0, r4, #0
	ldr r2, [r4, #0x10]
	ldr r3, [r4, #0xc]
	add r0, #0x18
	mov r1, #0
	bl ov01_021EFFB0
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021EFE22
_021EFDB2:
	add r0, r4, #0
	add r0, #0x18
	bl ov01_021EFFBC
	cmp r0, #0
	beq _021EFE22
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021EFE22
_021EFDC6:
	mov r0, #3
	str r0, [sp]
	add r0, r4, #0
	ldr r1, [r4, #0x10]
	ldr r3, [r4, #0xc]
	add r0, #0x18
	mov r2, #0
	bl ov01_021EFFB0
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021EFE22
_021EFDE0:
	add r0, r4, #0
	add r0, #0x18
	bl ov01_021EFFBC
	cmp r0, #0
	beq _021EFE22
	ldr r0, [r4, #8]
	add r1, r0, #1
	str r1, [r4, #8]
	ldr r0, [r4, #4]
	cmp r1, r0
	bne _021EFDFE
	mov r0, #5
	str r0, [r4]
	b _021EFE22
_021EFDFE:
	mov r0, #1
	str r0, [r4]
	b _021EFE22
_021EFE04:
	mov r1, #0
	str r1, [r4]
	str r1, [r4, #8]
	ldr r2, [r4, #0x48]
	cmp r2, #0
	beq _021EFE14
	mov r1, #1
	str r1, [r2]
_021EFE14:
	bl SysTask_Destroy
	add r0, r4, #0
	bl Heap_Free
	add sp, #4
	pop {r3, r4, pc}
_021EFE22:
	add r4, #0x30
	add r0, r4, #0
	bl ov01_021EFFBC
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov01_021EFD3C
