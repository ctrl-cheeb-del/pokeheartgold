#include "config.h"
#include "msgdata/msg/msg_0247.h"
#include "msgdata/msg/msg_0442.h"
#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_74_thumb.inc"
	.include "global.inc"
	.public gApplication_TitleScreen
	.public sub_020342C0

	.public MainMenuApp_Init
	.public MainMenuApp_Main
	.public MainMenuApp_Exit
	.public ov74_0223B2C0
	.public ov74_0223B2CC
	.public ov74_0223B2D8
	.public ov74_0223B2E8
	.public gApp_MainMenu_SelectOption_ConnectToRanger
	.public gApp_MainMenu_SelectOption_MigrateFromAgb
	.public gApp_MainMenu_SelectOption_MysteryGift

	.text
	.public ov74_02231164
	.extern gApp_MainMenu_SelectOption_ConnectToRanger
	.extern gApp_MainMenu_SelectOption_MigrateFromAgb
	.extern gApp_MainMenu_SelectOption_MysteryGift
	.extern ov74_02231154

	thumb_func_start ov74_02231164
ov74_02231164: ; 0x02231164
	push {r4, lr}
	bl ov74_02231154
	mov r2, #0x71
	mov r1, #0
	lsl r2, r2, #2
	add r4, r0, #0
	bl MI_CpuFill8
	mov r1, #0x46
	lsl r1, r1, #2
	add r0, r1, #0
	add r0, #0xa8
	strh r1, [r4, r0]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_02231164
