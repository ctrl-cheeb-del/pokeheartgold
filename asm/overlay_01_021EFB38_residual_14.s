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

	thumb_func_start ov01_021F0CDC
ov01_021F0CDC: ; 0x021F0CDC
	push {r4, lr}
	mov r2, #1
	lsl r2, r2, #0x1a
	add r4, r0, #0
	ldr r1, [r2]
	ldr r0, _021F0D1C ; =0xFFFF1FFF
	and r0, r1
	str r0, [r2]
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	mov r1, #1
	str r1, [r0]
	add r0, r4, #0
	add r0, #0xdc
	ldr r0, [r0]
	bl ov01_021FB554
	add r0, r4, #0
	mov r1, #0
	add r0, #0xdc
	str r1, [r0]
	add r0, r4, #0
	add r0, #0xe0
	ldr r0, [r0]
	bl SysTask_Destroy
	mov r0, #0
	add r4, #0xe0
	str r0, [r4]
	pop {r4, pc}
	nop
_021F0D1C: .word 0xFFFF1FFF
	thumb_func_end ov01_021F0CDC


	thumb_func_start ov01_021F0D20
ov01_021F0D20: ; 0x021F0D20
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5]
	mov r1, #1
	add r2, r0, #0
	tst r2, r1
	bne _021F0D42
	ldr r1, _021F0DAC ; =0x00001720
	tst r1, r0
	bne _021F0D38
	cmp r0, #0
	bne _021F0D3C
_021F0D38:
	mov r1, #0
	b _021F0D42
_021F0D3C:
	bl GF_AssertFail
	mov r1, #0
_021F0D42:
	mov r0, #0x15
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0x18
	bhi _021F0D94
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021F0D58: ; jump table
	.short _021F0D8A - _021F0D58 - 2 ; case 0
	.short _021F0D8A - _021F0D58 - 2 ; case 1
	.short _021F0D8A - _021F0D58 - 2 ; case 2
	.short _021F0D8A - _021F0D58 - 2 ; case 3
	.short _021F0D8A - _021F0D58 - 2 ; case 4
	.short _021F0D92 - _021F0D58 - 2 ; case 5
	.short _021F0D8A - _021F0D58 - 2 ; case 6
	.short _021F0D8E - _021F0D58 - 2 ; case 7
	.short _021F0D8A - _021F0D58 - 2 ; case 8
	.short _021F0D8A - _021F0D58 - 2 ; case 9
	.short _021F0D8A - _021F0D58 - 2 ; case 10
	.short _021F0D8A - _021F0D58 - 2 ; case 11
	.short _021F0D94 - _021F0D58 - 2 ; case 12
	.short _021F0D94 - _021F0D58 - 2 ; case 13
	.short _021F0D94 - _021F0D58 - 2 ; case 14
	.short _021F0D94 - _021F0D58 - 2 ; case 15
	.short _021F0D94 - _021F0D58 - 2 ; case 16
	.short _021F0D94 - _021F0D58 - 2 ; case 17
	.short _021F0D94 - _021F0D58 - 2 ; case 18
	.short _021F0D94 - _021F0D58 - 2 ; case 19
	.short _021F0D94 - _021F0D58 - 2 ; case 20
	.short _021F0D94 - _021F0D58 - 2 ; case 21
	.short _021F0D94 - _021F0D58 - 2 ; case 22
	.short _021F0D94 - _021F0D58 - 2 ; case 23
	.short _021F0D8A - _021F0D58 - 2 ; case 24
_021F0D8A:
	mov r4, #0
	b _021F0D94
_021F0D8E:
	mov r4, #2
	b _021F0D94
_021F0D92:
	mov r4, #4
_021F0D94:
	mov r0, #0x57
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	sub r0, r0, #3
	cmp r0, #1
	bhi _021F0DA2
	add r4, r4, #1
_021F0DA2:
	mov r0, #6
	mul r0, r1
	add r0, r4, r0
	pop {r3, r4, r5, pc}
	nop
_021F0DAC: .word 0x00001720
	thumb_func_end ov01_021F0D20
