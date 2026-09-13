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
	.public ov74_022311F4
	.public ov74_02231214
	.public ov74_02231238
	.extern gApp_MainMenu_SelectOption_ConnectToRanger
	.extern gApp_MainMenu_SelectOption_MigrateFromAgb
	.extern gApp_MainMenu_SelectOption_MysteryGift

	thumb_func_start ov74_022311F4
ov74_022311F4: ; 0x022311F4
	push {r3}
	sub sp, #4
	mov r2, #0
	str r2, [sp]
	add r3, sp, #0
_022311FE:
	add r1, r0, r2
	ldrb r1, [r1, #2]
	add r2, r2, #1
	strb r1, [r3]
	add r3, r3, #1
	cmp r2, #4
	blo _022311FE
	ldr r0, [sp]
	add sp, #4
	pop {r3}
	bx lr
	thumb_func_end ov74_022311F4


	thumb_func_start ov74_02231214
ov74_02231214: ; 0x02231214
	push {r3}
	sub sp, #4
	mov r2, #0
	add r1, sp, #0
	strh r2, [r1]
	add r3, sp, #0
_02231220:
	ldrb r1, [r0, r2]
	add r2, r2, #1
	strb r1, [r3]
	add r3, r3, #1
	cmp r2, #2
	blo _02231220
	add r1, sp, #0
	mov r0, #0
	ldrsh r0, [r1, r0]
	add sp, #4
	pop {r3}
	bx lr
	thumb_func_end ov74_02231214


	thumb_func_start ov74_02231238
ov74_02231238: ; 0x02231238
	push {r4, r5, r6, lr}
	add r5, r1, #0
	ldr r1, _0223125C ; =0x00002710
	add r6, r0, #0
	add r4, r2, #0
	bl _u32_div_f
	str r1, [r5]
	ldr r1, _0223125C ; =0x00002710
	add r0, r6, #0
	bl _u32_div_f
	ldr r1, _0223125C ; =0x00002710
	bl _u32_div_f
	str r1, [r4]
	pop {r4, r5, r6, pc}
	nop
_0223125C: .word 0x00002710
	thumb_func_end ov74_02231238
