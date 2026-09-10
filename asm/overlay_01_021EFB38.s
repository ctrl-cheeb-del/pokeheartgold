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

	thumb_func_start ov01_021EFB38
ov01_021EFB38: ; 0x021EFB38
	push {r3, lr}
	ldr r2, _021EFB5C ; =ov01_02209B64
	ldr r2, [r2, #4]
	lsl r3, r2, #2
	ldr r2, _021EFB60 ; =ov01_022068C4
	ldr r2, [r2, r3]
	blx r2
	ldr r0, _021EFB5C ; =ov01_02209B64
	ldr r1, [r0, #8]
	add r1, r1, #1
	str r1, [r0, #8]
	bl OS_GetTick
	mov r0, #0
	add r1, r0, #0
	bl OS_SetTick
	pop {r3, pc}
	.balign 4, 0
_021EFB5C: .word ov01_02209B64
_021EFB60: .word ov01_022068C4
	thumb_func_end ov01_021EFB38


	thumb_func_start ov01_021EFB64
ov01_021EFB64: ; 0x021EFB64
	push {r3, lr}
	cmp r0, #0xc
	blt _021EFB78
	cmp r0, #0x21
	bgt _021EFB78
	ldr r0, _021EFBE8 ; =FS_OVERLAY_ID(OVY_115)
	mov r1, #2
	bl HandleLoadOverlay
	pop {r3, pc}
_021EFB78:
	add r1, r0, #0
	sub r1, #0x22
	cmp r1, #2
	bhi _021EFB8A
	ldr r0, _021EFBEC ; =FS_OVERLAY_ID(OVY_116)
	mov r1, #2
	bl HandleLoadOverlay
	pop {r3, pc}
_021EFB8A:
	cmp r0, #0x27
	blt _021EFB9C
	cmp r0, #0x2c
	bgt _021EFB9C
	ldr r0, _021EFBF0 ; =FS_OVERLAY_ID(OVY_117)
	mov r1, #2
	bl HandleLoadOverlay
	pop {r3, pc}
_021EFB9C:
	cmp r0, #0x2d
	bne _021EFBAA
	ldr r0, _021EFBF4 ; =FS_OVERLAY_ID(OVY_118)
	mov r1, #2
	bl HandleLoadOverlay
	pop {r3, pc}
_021EFBAA:
	cmp r0, #0
	blt _021EFBBC
	cmp r0, #5
	bgt _021EFBBC
	ldr r0, _021EFBF8 ; =FS_OVERLAY_ID(OVY_120)
	mov r1, #2
	bl HandleLoadOverlay
	pop {r3, pc}
_021EFBBC:
	cmp r0, #6
	blt _021EFBCE
	cmp r0, #0xb
	bgt _021EFBCE
	ldr r0, _021EFBFC ; =FS_OVERLAY_ID(OVY_119)
	mov r1, #2
	bl HandleLoadOverlay
	pop {r3, pc}
_021EFBCE:
	cmp r0, #0x2e
	bne _021EFBDC
	ldr r0, _021EFBF8 ; =FS_OVERLAY_ID(OVY_120)
	mov r1, #2
	bl HandleLoadOverlay
	pop {r3, pc}
_021EFBDC:
	ldr r0, _021EFC00 ; =FS_OVERLAY_ID(OVY_114)
	mov r1, #2
	bl HandleLoadOverlay
	pop {r3, pc}
	nop
_021EFBE8: .word FS_OVERLAY_ID(OVY_115)
_021EFBEC: .word FS_OVERLAY_ID(OVY_116)
_021EFBF0: .word FS_OVERLAY_ID(OVY_117)
_021EFBF4: .word FS_OVERLAY_ID(OVY_118)
_021EFBF8: .word FS_OVERLAY_ID(OVY_120)
_021EFBFC: .word FS_OVERLAY_ID(OVY_119)
_021EFC00: .word FS_OVERLAY_ID(OVY_114)
	thumb_func_end ov01_021EFB64


	thumb_func_start ov01_021EFC04
ov01_021EFC04: ; 0x021EFC04
	push {r3, lr}
	cmp r0, #0xc
	blt _021EFC16
	cmp r0, #0x21
	bgt _021EFC16
	ldr r0, _021EFC78 ; =FS_OVERLAY_ID(OVY_115)
	bl UnloadOverlayByID
	pop {r3, pc}
_021EFC16:
	add r1, r0, #0
	sub r1, #0x22
	cmp r1, #2
	bhi _021EFC26
	ldr r0, _021EFC7C ; =FS_OVERLAY_ID(OVY_116)
	bl UnloadOverlayByID
	pop {r3, pc}
_021EFC26:
	cmp r0, #0x27
	blt _021EFC36
	cmp r0, #0x2c
	bgt _021EFC36
	ldr r0, _021EFC80 ; =FS_OVERLAY_ID(OVY_117)
	bl UnloadOverlayByID
	pop {r3, pc}
_021EFC36:
	cmp r0, #0x2d
	bne _021EFC42
	ldr r0, _021EFC84 ; =FS_OVERLAY_ID(OVY_118)
	bl UnloadOverlayByID
	pop {r3, pc}
_021EFC42:
	cmp r0, #0
	blt _021EFC52
	cmp r0, #5
	bgt _021EFC52
	ldr r0, _021EFC88 ; =FS_OVERLAY_ID(OVY_120)
	bl UnloadOverlayByID
	pop {r3, pc}
_021EFC52:
	cmp r0, #6
	blt _021EFC62
	cmp r0, #0xb
	bgt _021EFC62
	ldr r0, _021EFC8C ; =FS_OVERLAY_ID(OVY_119)
	bl UnloadOverlayByID
	pop {r3, pc}
_021EFC62:
	cmp r0, #0x2e
	bne _021EFC6E
	ldr r0, _021EFC88 ; =FS_OVERLAY_ID(OVY_120)
	bl UnloadOverlayByID
	pop {r3, pc}
_021EFC6E:
	ldr r0, _021EFC90 ; =FS_OVERLAY_ID(OVY_114)
	bl UnloadOverlayByID
	pop {r3, pc}
	nop
_021EFC78: .word FS_OVERLAY_ID(OVY_115)
_021EFC7C: .word FS_OVERLAY_ID(OVY_116)
_021EFC80: .word FS_OVERLAY_ID(OVY_117)
_021EFC84: .word FS_OVERLAY_ID(OVY_118)
_021EFC88: .word FS_OVERLAY_ID(OVY_120)
_021EFC8C: .word FS_OVERLAY_ID(OVY_119)
_021EFC90: .word FS_OVERLAY_ID(OVY_114)
	thumb_func_end ov01_021EFC04
