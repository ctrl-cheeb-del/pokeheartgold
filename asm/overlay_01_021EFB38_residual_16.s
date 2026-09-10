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

	thumb_func_start ov01_021F0F08
ov01_021F0F08: ; 0x021F0F08
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, _021F0FAC ; =ov01_02209B64
	add r4, r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne _021F0F1C
	bl GF_AssertFail
_021F0F1C:
	ldr r0, _021F0FAC ; =ov01_02209B64
	ldr r0, [r0]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021F0F2A
	bl GF_AssertFail
_021F0F2A:
	mov r1, #0x12
	mov r0, #4
	lsl r1, r1, #0xa
	bl Heap_Alloc
	ldr r2, _021F0FAC ; =ov01_02209B64
	mov r3, #0x12
	ldr r1, [r2]
	lsl r3, r3, #0xa
	str r0, [r1, #0xc]
	mov r0, #1
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r2, [r2]
	ldr r0, _021F0FB0 ; =ov01_021F1224
	ldr r1, _021F0FB4 ; =ov01_021F1250
	ldr r2, [r2, #0xc]
	bl sub_02014DB4
	ldr r1, _021F0FAC ; =ov01_02209B64
	ldr r2, [r1]
	str r0, [r2, #8]
	ldr r0, [r1]
	ldr r0, [r0, #8]
	cmp r0, #0
	bne _021F0F64
	bl GF_AssertFail
_021F0F64:
	ldr r0, _021F0FAC ; =ov01_02209B64
	mov r1, #1
	ldr r0, [r0]
	ldr r0, [r0, #8]
	bl sub_02015528
	ldr r0, _021F0FAC ; =ov01_02209B64
	ldr r0, [r0]
	ldr r0, [r0, #8]
	bl sub_02015524
	add r2, r0, #0
	mov r0, #1
	mov r1, #0xe1
	lsl r0, r0, #0xc
	lsl r1, r1, #0xe
	bl Camera_SetPerspectiveClippingPlane
	mov r2, #0
	add r0, r5, #0
	add r1, r4, #0
	mov r3, #4
	str r2, [sp]
	bl GfGfxLoader_LoadFromOpenNarc
	add r1, r0, #0
	ldr r0, _021F0FAC ; =ov01_02209B64
	mov r2, #0
	ldr r0, [r0]
	add r3, r2, #0
	ldr r0, [r0, #8]
	bl sub_0201526C
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_021F0FAC: .word ov01_02209B64
_021F0FB0: .word ov01_021F1224
_021F0FB4: .word ov01_021F1250
	thumb_func_end ov01_021F0F08
