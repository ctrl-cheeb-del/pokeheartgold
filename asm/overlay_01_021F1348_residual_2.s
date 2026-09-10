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

	thumb_func_start ov01_021F1824
ov01_021F1824: ; 0x021F1824
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldrh r5, [r6, #4]
	add r0, r1, #0
	ldr r1, [sp, #0x1c]
	str r2, [sp]
	ldr r6, [r6, #0x1c]
	add r7, r3, #0
	str r1, [sp, #0x1c]
	mov r4, #0
	add r2, r5, #0
	add r3, r6, #0
_021F183C:
	ldr r1, [r3]
	cmp r1, r0
	bne _021F1846
	ldr r0, [r3, #4]
	pop {r3, r4, r5, r6, r7, pc}
_021F1846:
	add r3, #8
	sub r2, r2, #1
	bne _021F183C
_021F184C:
	ldr r1, [r6]
	cmp r1, #0xf
	bne _021F1858
	str r0, [r6]
	ldr r4, [r6, #4]
	b _021F185E
_021F1858:
	add r6, #8
	sub r5, r5, #1
	bne _021F184C
_021F185E:
	cmp r4, #0
	bne _021F1866
	bl GF_AssertFail
_021F1866:
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x28
	bl memset
	ldr r0, [sp]
	add r2, r4, #0
	str r0, [r4]
	add r2, #0xc
	ldmia r7!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r7!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [sp, #0x18]
	str r0, [r4, #4]
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq _021F18A0
	bl GF3dGfxRawResObj_GetTexKey
	str r0, [r4, #0x1c]
	ldr r0, [sp, #0x1c]
	bl GF3dGfxRawResObj_GetTex4x4Key
	str r0, [r4, #0x20]
	ldr r0, [sp, #0x1c]
	bl GF3dGfxRawResObj_GetPlttKey
	str r0, [r4, #0x24]
_021F18A0:
	ldr r0, [sp, #0x20]
	str r0, [r4, #8]
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov01_021F1824
