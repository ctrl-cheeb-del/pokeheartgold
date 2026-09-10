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

	thumb_func_start ov01_021F10C8
ov01_021F10C8: ; 0x021F10C8
	push {r4, r5, lr}
	sub sp, #0x3c
	add r4, r1, #0
	add r5, r0, #0
	ldrh r0, [r4]
	cmp r0, #2
	bne _021F1136
	bl sub_02014DA0
	add r1, sp, #0x30
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	ldr r3, _021F113C ; =ov01_022067E0
	str r0, [r1, #8]
	ldmia r3!, {r0, r1}
	add r2, sp, #0x24
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	add r0, sp, #0
	bl MTX_Identity33_
	add r0, sp, #0x30
	bl NNS_G3dGlbSetBaseTrans
	add r0, sp, #0x24
	bl NNS_G3dGlbSetBaseScale
	ldr r1, _021F1140 ; =NNS_G3dGlb + 0xBC
	add r0, sp, #0
	bl MI_Copy36B
	ldr r1, _021F1144 ; =NNS_G3dGlb + 0x80
	mov r0, #0xa4
	ldr r2, [r1, #0x7c]
	bic r2, r0
	str r2, [r1, #0x7c]
	ldr r0, [r4, #4]
	mov r1, #0
	bl ov01_021E631C
	ldr r0, [r4, #4]
	mov r1, #0
	bl ov01_021E6340
	mov r0, #0
	add r1, r0, #0
	bl SetBgPriority
	mov r0, #1
	strb r0, [r4, #2]
	add r0, r5, #0
	bl SysTask_Destroy
_021F1136:
	add sp, #0x3c
	pop {r4, r5, pc}
	nop
_021F113C: .word ov01_022067E0
_021F1140: .word NNS_G3dGlb + 0xBC
_021F1144: .word NNS_G3dGlb + 0x80
	thumb_func_end ov01_021F10C8


	thumb_func_start ov01_021F1148
ov01_021F1148: ; 0x021F1148
	push {r4, r5, lr}
	sub sp, #0x6c
	ldr r5, _021F11F8 ; =ov01_0220689C
	add r4, r0, #0
	add r3, sp, #0x44
	mov r2, #5
_021F1154:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021F1154
	add r0, sp, #0x44
	bl GfGfx_SetBanks
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r5, _021F11FC ; =ov01_022067FC
	add r3, sp, #0x34
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r0, [r4, #8]
	bl Thunk_ov01_021E6138
	ldr r2, _021F1200 ; =0x0400000E
	mov r0, #0x43
	ldrh r1, [r2]
	and r1, r0
	ldr r0, _021F1204 ; =0x00004884
	orr r0, r1
	strh r0, [r2]
	mov r0, #3
	add r1, r0, #0
	bl SetBgPriority
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add r0, sp, #0x24
	bl MTX_Identity22_
	mov r2, #0
	str r2, [sp]
	ldr r0, _021F1208 ; =0x04000030
	add r1, sp, #0x24
	add r3, r2, #0
	str r2, [sp, #4]
	bl G2x_SetBGyAffine_
	ldr r5, _021F120C ; =ov01_02206844
	add r3, sp, #8
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #2
	str r0, [r3]
	ldr r0, [r4, #8]
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #2
	mov r1, #0x20
	mov r2, #0
	mov r3, #4
	bl BG_ClearCharDataRange
	ldr r0, [r4, #8]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add sp, #0x6c
	pop {r4, r5, pc}
	.balign 4, 0
_021F11F8: .word ov01_0220689C
_021F11FC: .word ov01_022067FC
_021F1200: .word 0x0400000E
_021F1204: .word 0x00004884
_021F1208: .word 0x04000030
_021F120C: .word ov01_02206844
	thumb_func_end ov01_021F1148
