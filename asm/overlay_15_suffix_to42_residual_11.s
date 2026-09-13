#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text

	.public _022004EC
	.public _02201300
	.public _02201480
	.public ov15_021FEA5C
	.public ov15_021FEB64
	.public ov15_021FEB84
	.public ov15_021FECA0
	.public ov15_021FECC4
	.public ov15_021FECD8
	.public ov15_021FED24
	.public ov15_021FED3C
	.public ov15_021FED58
	.public ov15_021FED60
	.public ov15_021FEDEC
	.public ov15_021FEEA4
	.public ov15_021FEF48
	.public ov15_021FF004
	.public ov15_021FF058
	.public ov15_021FF068
	.public ov15_021FF0FC
	.public ov15_021FF1E0
	.public ov15_021FF29C
	.public ov15_021FF364
	.public ov15_021FF4EC
	.public ov15_021FF560
	.public ov15_021FF6BC
	.public ov15_021FF758
	.public ov15_021FF7AC
	.public ov15_021FF7C4
	.public ov15_021FF7FC
	.public ov15_021FF834
	.public ov15_021FF844
	.public ov15_021FF850
	.public ov15_021FF894
	.public ov15_021FF8D4
	.public ov15_021FF950
	.public ov15_021FF964
	.public ov15_021FFECC
	.public ov15_021FFF24
	.public ov15_021FFF34
	.public ov15_021FFFDC
	.public ov15_02200030
	.public ov15_0220005C
	.public ov15_02200140
	.public ov15_022001C4
	.public ov15_0220023C
	.public ov15_02200294
	.public ov15_022002B4
	.public ov15_022002EC
	.public ov15_02200300
	.public ov15_02200428
	.public ov15_02200458
	.public ov15_022004DC
	.public ov15_022004F4
	.public ov15_02200500
	.public ov15_0220050C
	.public ov15_02200518
	.public ov15_02200528
	.public ov15_02200529
	.public ov15_0220052A
	.public ov15_0220052B
	.public ov15_0220053C
	.public ov15_02200584
	.public ov15_02200585
	.public ov15_02200586
	.public ov15_02200587
	.public ov15_022005CC
	.public ov15_02200618
	.public ov15_02200640
	.public ov15_02200641
	.public ov15_02200642
	.public ov15_02200643
	.public ov15_022006CC
	.public ov15_022006E8
	.public ov15_02200704
	.public ov15_02200720
	.public ov15_0220073C
	.public ov15_02200758
	.public ov15_02200774
	.public ov15_02200790
	.public ov15_022008B0
	.public ov15_022008D0
	.public ov15_022008E8
	.public ov15_02200908
	.public ov15_02201304
	.public ov15_02201314
	.public ov15_02201328
	.public ov15_02201340
	.public ov15_02201368
	.public ov15_022013A8
	.public ov15_02201468
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021F9C78
	.extern ov15_021FB680
	.extern ov15_021FBC6C
	.extern ov15_021FBC8C
	.extern ov15_021FBCAC
	.extern ov15_021FC224
	.extern ov15_021FC37C
	.extern ov15_021FC3E0
	.extern ov15_021FC3EC
	.extern ov15_021FD3C0
	.extern ov15_021FD3F0
	.extern ov15_021FE17C
	.extern ov15_021FE1D0
	.extern ov15_021FE204
	.extern ov15_021FE3E0
	.extern ov15_021FE584
	.extern ov15_021FE5A4
	.extern ov15_021FE5C4
	.extern ov15_021FE620
	.extern ov15_021FE914
	.extern ov15_021FE990
	.public ov15_021FE9F0
	.public ov15_021FEA5C
	.public ov15_021FEB64
	.public ov15_021FEB84
	.public ov15_021FECA0
	.public ov15_021FECC4
	.public ov15_021FECD8
	.public ov15_021FED24
	.public ov15_021FED3C
	.public ov15_021FED58
	.public ov15_021FED60
	.public ov15_021FEDEC
	.public ov15_021FEEA4
	.public ov15_021FEF48
	.public ov15_021FEFC4
	.public ov15_021FF004
	.public ov15_021FF058
	.public ov15_021FF068
	.public ov15_021FF0FC
	.public ov15_021FF1E0
	.public ov15_021FF29C
	.public ov15_021FF320
	.public ov15_021FF364
	.public ov15_021FF4EC
	.public ov15_021FF560
	.public ov15_021FF570
	.public ov15_021FF66C
	.public ov15_021FF6BC
	.public ov15_021FF758
	.public ov15_021FF7AC
	.public ov15_021FF7C4
	.public ov15_021FF7FC
	.public ov15_021FF834
	.public ov15_021FF844
	.public ov15_021FF850
	.public ov15_021FF894
	.public ov15_021FF8D4
	.public ov15_021FF8F0
	.public ov15_021FF950
	.public ov15_021FF964
	.public ov15_021FF97C
	.public ov15_021FFA40
	.public ov15_021FFAD0
	.public ov15_021FFDD8
	.public ov15_021FFEC0
	.public ov15_021FFECC
	.public ov15_021FFF24
	.public ov15_021FFF34
	.public ov15_021FFFDC
	.public ov15_02200030
	.public ov15_0220005C
	.public ov15_022000F4
	.public ov15_02200140
	.public ov15_022001C4
	.public ov15_0220023C
	.public ov15_02200294
	.public ov15_022002B4
	.public ov15_022002EC
	.public ov15_02200300
	.public ov15_02200428
	.public ov15_02200458
	.public ov15_022004DC
	.extern _022004EC
	.extern ov15_022004F4
	.extern ov15_02200500
	.extern ov15_0220050C
	.extern ov15_02200518
	.extern ov15_02200528
	.extern ov15_02200529
	.extern ov15_0220052A
	.extern ov15_0220052B
	.extern ov15_0220053C
	.extern ov15_02200550
	.extern ov15_02200568
	.extern ov15_02200584
	.extern ov15_02200585
	.extern ov15_02200586
	.extern ov15_02200587
	.extern ov15_022005A8
	.extern ov15_022005CC
	.extern ov15_022005F0
	.extern ov15_02200618
	.extern ov15_02200640
	.extern ov15_02200641
	.extern ov15_02200642
	.extern ov15_02200643
	.extern ov15_02200684
	.extern ov15_022006CC
	.extern ov15_022006E8
	.extern ov15_02200704
	.extern ov15_02200720
	.extern ov15_0220073C
	.extern ov15_02200758
	.extern ov15_02200774
	.extern ov15_02200790
	.extern ov15_022008B0
	.extern ov15_022008B8
	.extern ov15_022008C8
	.extern ov15_022008D0
	.extern ov15_022008E8
	.extern ov15_02200908
	.extern ov15_02200998
	.extern ov15_022009A0
	.extern ov15_022009A8
	.extern ov15_022009BC
	.extern ov15_022009D4
	.extern ov15_022009D5
	.extern ov15_022009D6
	.extern ov15_022009D7
	.extern ov15_022009F4
	.extern ov15_02200A14
	.extern ov15_02200A34
	.extern ov15_02200A35
	.extern ov15_02200A36
	.extern ov15_02200A37
	.extern ov15_02200A58
	.extern ov15_02200A88
	.extern ov15_02200AB8
	.extern ov15_02200AB9
	.extern ov15_02200ABA
	.extern ov15_02200ABB
	.extern ov15_02200B0C
	.extern _02201300
	.extern ov15_02201304
	.extern ov15_02201314
	.extern ov15_02201328
	.extern ov15_02201340
	.extern ov15_02201368
	.extern ov15_022013A8
	.extern ov15_02201468
	.extern _02201480

thumb_func_start ov15_021FF97C
ov15_021FF97C: ; 0x021FF97C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	mov r0, #0x9b
	lsl r0, r0, #2
	add r4, r2, #0
	add r6, r1, #0
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	cmp r4, #0
	beq _021FFA34
	add r0, r6, #0
	bl TMHMGetMove
	mov r1, #3
	add r4, r0, #0
	bl GetMoveAttr
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	add r0, r4, #0
	mov r1, #1
	bl GetMoveAttr
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	bl sub_020776B4
	add r7, r0, #0
	add r0, r6, #0
	bl sub_02077678
	add r3, r0, #0
	mov r0, #1
	str r0, [sp]
	ldr r0, _021FFA38 ; =0x0000C103
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r7, #0
	bl SpriteSystem_ReplaceCharResObj
	add r0, r6, #0
	bl sub_0207769C
	add r1, r0, #0
	mov r0, #0x9b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r1, #4
	bl ManagedSprite_SetPaletteOverride
	bl sub_02077830
	add r6, r0, #0
	add r0, r4, #0
	bl sub_02077800
	add r3, r0, #0
	mov r0, #1
	str r0, [sp]
	ldr r0, _021FFA3C ; =0x0000C104
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl SpriteSystem_ReplaceCharResObj
	add r0, r4, #0
	bl sub_02077818
	add r1, r0, #0
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r1, #4
	bl ManagedSprite_SetPaletteOverride
_021FFA34:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FFA38: .word 0x0000C103
_021FFA3C: .word 0x0000C104
	thumb_func_end ov15_021FF97C

thumb_func_start ov15_021FFA40
ov15_021FFA40: ; 0x021FFA40
	push {r4, r5, r6, r7, lr}
	sub sp, #0x4c
	ldr r3, _021FFAC4 ; =ov15_022009BC
	add r2, sp, #0x34
	add r4, r0, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r0, #6
	bl SpriteSystem_Alloc
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	bl SpriteManager_New
	mov r7, #0x93
	lsl r7, r7, #2
	add r2, sp, #0x14
	ldr r3, _021FFAC8 ; =ov15_022009F4
	str r0, [r4, r7]
	ldmia r3!, {r0, r1}
	add r6, r2, #0
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	ldr r5, _021FFACC ; =ov15_022009A8
	stmia r2!, {r0, r1}
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r6, #0
	str r0, [r3]
	sub r0, r7, #4
	ldr r0, [r4, r0]
	mov r3, #0x20
	bl SpriteSystem_Init
	sub r1, r7, #4
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	mov r2, #0x27
	bl SpriteSystem_InitSprites
	sub r1, r7, #4
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	add r2, sp, #0x34
	bl SpriteSystem_InitManagerWithCapacities
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
	nop
_021FFAC4: .word ov15_022009BC
_021FFAC8: .word ov15_022009F4
_021FFACC: .word ov15_022009A8
	thumb_func_end ov15_021FFA40

thumb_func_start ov15_021FFAD0
ov15_021FFAD0: ; 0x021FFAD0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _021FFDAC ; =0x0000C0F9
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xf
	mov r3, #0x1a
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _021FFDB0 ; =0x0000C0FA
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xf
	mov r3, #6
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _021FFDB4 ; =0x0000C0FB
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xf
	mov r3, #0x33
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _021FFDB8 ; =0x0000C102
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0x3c
	mov r3, #4
	bl SpriteSystem_LoadCharResObj
	mov r4, #0
	add r6, r4, #0
	mov r7, #2
_021FFB54:
	mov r0, #0
	mov r1, #1
	bl GetItemIndexMapping
	add r3, r0, #0
	ldr r0, _021FFDBC ; =0x0000C0FC
	str r6, [sp]
	mov r1, #0x93
	str r7, [sp, #4]
	add r0, r4, r0
	str r0, [sp, #8]
	mov r0, #0x92
	lsl r0, r0, #2
	lsl r1, r1, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	mov r2, #0x12
	bl SpriteSystem_LoadCharResObj
	add r4, r4, #1
	cmp r4, #6
	blt _021FFB54
	ldr r0, _021FFDC0 ; =0x0000C103
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #1
	mov r3, #0
	bl sub_020776B8
	ldr r0, _021FFDC4 ; =0x0000C104
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #1
	mov r3, #0
	bl sub_02077834
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _021FFDAC ; =0x0000C0F9
	mov r1, #0x92
	mov r2, #0xf
	lsl r1, r1, #2
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r3, r2, #0
	bl SpriteSystem_LoadPlttResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _021FFDC8 ; =0x0000C101
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0x3c
	mov r3, #0xa
	bl SpriteSystem_LoadPlttResObj
	mov r1, #0x92
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	ldr r3, _021FFDB8 ; =0x0000C102
	mov r2, #1
	bl sub_020776EC
	mov r0, #0
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r0, _021FFDB0 ; =0x0000C0FA
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xf
	mov r3, #0x2f
	bl SpriteSystem_LoadPlttResObj
	mov r4, #0
	add r6, r4, #0
	mov r7, #1
_021FFC2A:
	mov r0, #0
	mov r1, #2
	bl GetItemIndexMapping
	str r6, [sp]
	add r3, r0, #0
	mov r1, #0x93
	str r7, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r0, _021FFDB4 ; =0x0000C0FB
	lsl r1, r1, #2
	add r0, r4, r0
	str r0, [sp, #0xc]
	mov r0, #0x92
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	mov r2, #0x12
	bl SpriteSystem_LoadPlttResObj
	add r4, r4, #1
	cmp r4, #6
	blt _021FFC2A
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FFDAC ; =0x0000C0F9
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xf
	mov r3, #0x19
	bl SpriteSystem_LoadCellResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FFDB0 ; =0x0000C0FA
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xf
	mov r3, #5
	bl SpriteSystem_LoadCellResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FFDB4 ; =0x0000C0FB
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xf
	mov r3, #0x31
	bl SpriteSystem_LoadCellResObj
	bl GetItemIconCell
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FFDBC ; =0x0000C0FC
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0x12
	bl SpriteSystem_LoadCellResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FFDCC ; =0x0000C0FD
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0x3c
	mov r3, #5
	bl SpriteSystem_LoadCellResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FFDAC ; =0x0000C0F9
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xf
	mov r3, #0x15
	bl SpriteSystem_LoadAnimResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FFDB0 ; =0x0000C0FA
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xf
	mov r3, #0x18
	bl SpriteSystem_LoadAnimResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FFDB4 ; =0x0000C0FB
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xf
	mov r3, #4
	bl SpriteSystem_LoadAnimResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FFDBC ; =0x0000C0FC
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0xf
	mov r3, #0x32
	bl SpriteSystem_LoadAnimResObj
	bl GetItemIconAnim
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FFDCC ; =0x0000C0FD
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0x12
	bl SpriteSystem_LoadAnimResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FFDD0 ; =0x0000C0FE
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0x3c
	mov r3, #6
	bl SpriteSystem_LoadAnimResObj
	mov r1, #0x92
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r2, _021FFDD0 ; =0x0000C0FE
	ldr r1, [r5, r1]
	add r3, r2, #1
	bl sub_0207775C
	mov r2, #0x6a
	lsl r2, r2, #4
	mov r0, #0xf
	mov r1, #0x30
	add r2, r5, r2
	mov r3, #6
	bl GfGfxLoader_GetPlttData
	ldr r1, _021FFDD4 ; =0x0000069C
	str r0, [r5, r1]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FFDAC: .word 0x0000C0F9
_021FFDB0: .word 0x0000C0FA
_021FFDB4: .word 0x0000C0FB
_021FFDB8: .word 0x0000C102
_021FFDBC: .word 0x0000C0FC
_021FFDC0: .word 0x0000C103
_021FFDC4: .word 0x0000C104
_021FFDC8: .word 0x0000C101
_021FFDCC: .word 0x0000C0FD
_021FFDD0: .word 0x0000C0FE
_021FFDD4: .word 0x0000069C
	thumb_func_end ov15_021FFAD0

thumb_func_start ov15_021FFDD8
ov15_021FFDD8: ; 0x021FFDD8
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r4, _021FFEBC ; =ov15_02200B0C
	mov r7, #0
	add r5, r6, #0
_021FFDE2:
	mov r0, #0x92
	mov r1, #0x93
	lsl r0, r0, #2
	lsl r1, r1, #2
	mov r3, #1
	ldr r0, [r6, r0]
	ldr r1, [r6, r1]
	add r2, r4, #0
	lsl r3, r3, #0x14
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #0x25
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r7, r7, #1
	add r4, #0x34
	add r5, r5, #4
	cmp r7, #0x27
	blo _021FFDE2
	add r0, r1, #0
	add r0, #0x4c
	ldr r0, [r6, r0]
	mov r1, #1
	bl ManagedSprite_SetPriority
	mov r7, #0xb
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #6
_021FFE1C:
	ldr r0, [r4, r7]
	mov r1, #1
	bl ManagedSprite_SetPriority
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #4
	blo _021FFE1C
	mov r7, #0x9d
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #2
_021FFE34:
	ldr r0, [r4, r7]
	mov r1, #1
	bl ManagedSprite_SetPriority
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #8
	blo _021FFE34
	add r0, r6, #0
	mov r1, #1
	bl ov15_02200458
	mov r0, #0x25
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x9b
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r7, #0xb
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #6
_021FFE78:
	ldr r0, [r4, r7]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #4
	blo _021FFE78
	mov r7, #0x2d
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #4
_021FFE90:
	ldr r0, [r4, r7]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #6
	blo _021FFE90
	mov r0, #0xba
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0xba
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #1
	bl ManagedSprite_SetPriority
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FFEBC: .word ov15_02200B0C
	thumb_func_end ov15_021FFDD8
