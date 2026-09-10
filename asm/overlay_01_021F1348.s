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
	.include "overlay_01_021F1348.inc"
	.include "global.inc"

	.public ov01_02208C5C

	.public FieldEffectManager_New
	.public FieldEffectManager_InitAnimManagerList
	.public ov01_021F1390
	.public ov01_021F13B0
	.public FieldEffectManager_InitRenderers
	.public FieldEffectManager_Render
	.public FieldEffectManager_Free
	.public ov01_021F141C
	.public ov01_021F1430
	.public ov01_021F1448
	.public ov01_021F1450
	.public ov01_021F1468
	.public ov01_021F146C
	.public ov01_021F1478
	.public ov01_021F147C
	.public ov01_021F1490
	.public ov01_021F149C
	.public ov01_021F14A8
	.public ov01_021F14B4
	.public ov01_021F14DC
	.public ov01_021F14F4
	.public ov01_021F151C
	.public ov01_021F1538
	.public ov01_021F1560
	.public ov01_021F1588
	.public ov01_021F15A0
	.public ov01_021F15AC
	.public ov01_021F15B4
	.public ov01_021F15C4
	.public ov01_021F15EC
	.public ov01_021F15FC
	.public ov01_021F1610
	.public ov01_021F1620
	.public ov01_021F1640
	.public ov01_021F1648
	.public ov01_021F16B8
	.public ov01_021F16EC
	.public ov01_021F1740
	.public ov01_021F1758
	.public ov01_021F17BC
	.public ov01_021F17F0
	.public ov01_021F1804
	.public ov01_021F1824
	.public ov01_021F18A8
	.public ov01_021F18C8
	.public ov01_021F18D4
	.public ov01_021F18F0
	.public ov01_021F18FC
	.public ov01_021F1908
	.public ov01_021F1924
	.public ov01_021F1930
	.public ov01_021F1970
	.public ov01_021F197C
	.public ov01_021F19B4
	.public ov01_021F19D0
	.public ov01_021F19F4
	.public ov01_021F1A18
	.public ov01_021F1A34
	.public ov01_021F1A48
	.public ov01_021F1AB8
	.public ov01_021F1AD4
	.public _021F138C
	.public _021F13C4
	.public _021F13DC
	.public _021F13EA
	.public _021F13F0
	.public _021F142A
	.public _021F144C
	.public _021F1462
	.public _021F1498
	.public _021F14A4
	.public _021F14B0
	.public _021F14E6
	.public _021F14F2
	.public _021F1544
	.public _021F1556
	.public _021F155C
	.public _021F156A
	.public _021F1578
	.public _021F157E
	.public _021F1590
	.public _021F159C
	.public _021F159E
	.public _021F15BE
	.public _021F15CE
	.public _021F15D6
	.public _021F15DE
	.public _021F15E8
	.public _021F160E
	.public _021F161C
	.public _021F163A
	.public _021F1644
	.public _021F16EA
	.public _021F171C
	.public _021F1736
	.public _021F173C
	.public _021F178A
	.public _021F1798
	.public _021F17B4
	.public _021F17E0
	.public _021F180A
	.public _021F1816
	.public _021F183C
	.public _021F1846
	.public _021F184C
	.public _021F1858
	.public _021F185E
	.public _021F1866
	.public _021F18A0
	.public _021F18AE
	.public _021F18B8
	.public _021F18D0
	.public _021F18F8
	.public _021F1904
	.public _021F192C
	.public _021F1962
	.public _021F1978
	.public _021F19AC
	.public _021F19B0
	.public _021F19F0
	.public _021F1A78
	.public _021F1A96
	.public _021F1A98
	.public _021F1AA2
	.public _021F1AA4
	.public _021F1AAE
	.public _021F1AE8
	.public _021F1AF4
	.public _021F1AF8
	.public ov01_02206988

	.text
	.public FieldEffectManager_Free
	.public FieldEffectManager_InitAnimManagerList
	.public FieldEffectManager_InitRenderers
	.public FieldEffectManager_New
	.public FieldEffectManager_Render
	.public ov01_021F1390
	.public ov01_021F13B0
	.public ov01_021F141C
	.public ov01_021F1430
	.public ov01_021F1448
	.public ov01_021F1450
	.public ov01_021F1468
	.public ov01_021F146C
	.public ov01_021F1478
	.public ov01_021F147C
	.public ov01_021F1490
	.public ov01_021F149C
	.public ov01_021F14A8
	.public ov01_021F14B4
	.public ov01_021F14DC
	.public ov01_021F14F4
	.public ov01_021F151C
	.public ov01_021F1538
	.public ov01_021F1560
	.public ov01_021F1588
	.public ov01_021F15A0
	.public ov01_021F15AC
	.public ov01_021F15B4
	.public ov01_021F15C4
	.public ov01_021F15EC
	.public ov01_021F15FC
	.public ov01_021F1610
	.public ov01_021F1620
	.public ov01_021F1640
	.public ov01_021F1648
	.public ov01_021F16B8
	.public ov01_021F16EC
	.public ov01_021F1740
	.public ov01_021F17BC
	.public ov01_021F17F0
	.public ov01_021F1804
	.public ov01_021F18A8
	.public ov01_021F18C8
	.public ov01_021F18D4
	.public ov01_021F18F0
	.public ov01_021F18FC
	.public ov01_021F1908
	.public ov01_021F1924
	.public ov01_021F1930
	.public ov01_021F1970
	.public ov01_021F197C
	.public ov01_021F19B4
	.public ov01_021F19D0
	.public ov01_021F19F4
	.public ov01_021F1A18
	.public ov01_021F1A34
	.public ov01_021F1AB8

	thumb_func_start ov01_021F1758
ov01_021F1758: ; 0x021F1758
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	ldr r5, [r0, #0x20]
	add r6, r1, #0
	ldr r0, [r5, #0x10]
	add r1, r2, #0
	add r4, r3, #0
	bl ov01_021FC5A4
	add r7, r0, #0
	ldr r0, [r5, #0x14]
	add r1, r4, #0
	bl ov01_021FC5A4
	add r1, sp, #0xc
	bl sub_02026E18
	ldr r0, [r5, #0x18]
	ldr r1, [sp, #0x30]
	bl GF3dGfxRawResMan_GetObjById
	add r4, r0, #0
	bne _021F178A
	bl GF_AssertFail
_021F178A:
	add r0, r4, #0
	bl GF3dGfxRawResObj_GetTex
	ldr r1, [sp, #0x34]
	cmp r1, #1
	bne _021F1798
	mov r4, #0
_021F1798:
	str r0, [sp]
	ldr r0, [sp, #0x38]
	str r4, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	add r1, r6, #0
	add r2, r7, #0
	add r3, sp, #0xc
	bl ov01_021F1824
	add r4, r0, #0
	bne _021F17B4
	bl GF_AssertFail
_021F17B4:
	add r0, r4, #0
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov01_021F1758
