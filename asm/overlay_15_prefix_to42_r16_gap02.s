#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021FC7EC
	.public ov15_021FCB64
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021F9C78
	.extern ov15_021FA074
	.extern ov15_021FA0E4
	.extern ov15_021FA104
	.extern ov15_021FA170
	.extern ov15_021FA68C
	.extern ov15_021FA6C0
	.extern ov15_021FA73C
	.extern ov15_021FAC2C
	.extern ov15_021FB518
	.extern ov15_021FB680
	.extern ov15_021FBC6C
	.extern ov15_021FBC8C
	.extern ov15_021FBCAC
	.extern ov15_021FBD28
	.extern ov15_021FC224
	.extern ov15_021FC37C
	.extern ov15_021FC3E0
	.extern ov15_021FC3EC
	.extern ov15_021FD3C0
	.extern ov15_021FD3F0
	.extern ov15_021FD43C
	.extern ov15_021FD574
	.extern ov15_021FD774
	.extern ov15_021FD788
	.extern ov15_021FD7D0
	.extern ov15_021FD810
	.extern ov15_021FE17C
	.extern ov15_021FE1D0
	.extern ov15_021FE204
	.extern ov15_021FE3E0
	.extern ov15_021FE584
	.extern ov15_021FE5A4
	.extern ov15_021FE5C4
	.extern ov15_021FE620
	.extern ov15_021FE868

	.public Bag_Exit
	.public Bag_Init
	.public Bag_Main
	.public ov15_021F9C78
	.public ov15_021FB680
	.public ov15_021FBC6C
	.public ov15_021FBC8C
	.public ov15_021FBCAC
	.public ov15_021FC224
	.public ov15_021FC37C
	.public ov15_021FC3E0
	.public ov15_021FC3EC
	.public ov15_021FD3C0
	.public ov15_021FD3F0
	.public ov15_021FE17C
	.public ov15_021FE1D0
	.public ov15_021FE204
	.public ov15_021FE3E0
	.public ov15_021FE584
	.public ov15_021FE5A4
	.public ov15_021FE5C4
	.public ov15_021FE620
	.extern _022004EC
	.extern _02201300
	.extern _02201480
	.extern ov15_021FEA5C
	.extern ov15_021FEB64
	.extern ov15_021FEB84
	.extern ov15_021FECA0
	.extern ov15_021FECC4
	.extern ov15_021FECD8
	.extern ov15_021FED24
	.extern ov15_021FED3C
	.extern ov15_021FED58
	.extern ov15_021FED60
	.extern ov15_021FEDEC
	.extern ov15_021FEEA4
	.extern ov15_021FEF48
	.extern ov15_021FF004
	.extern ov15_021FF058
	.extern ov15_021FF068
	.extern ov15_021FF0FC
	.extern ov15_021FF1E0
	.extern ov15_021FF29C
	.extern ov15_021FF364
	.extern ov15_021FF4EC
	.extern ov15_021FF560
	.extern ov15_021FF6BC
	.extern ov15_021FF758
	.extern ov15_021FF7AC
	.extern ov15_021FF7C4
	.extern ov15_021FF7FC
	.extern ov15_021FF834
	.extern ov15_021FF844
	.extern ov15_021FF850
	.extern ov15_021FF894
	.extern ov15_021FF8D4
	.extern ov15_021FF950
	.extern ov15_021FF964
	.extern ov15_021FFECC
	.extern ov15_021FFF24
	.extern ov15_021FFF34
	.extern ov15_021FFFDC
	.extern ov15_02200030
	.extern ov15_0220005C
	.extern ov15_02200140
	.extern ov15_022001C4
	.extern ov15_0220023C
	.extern ov15_02200294
	.extern ov15_022002B4
	.extern ov15_022002EC
	.extern ov15_02200300
	.extern ov15_02200428
	.extern ov15_02200458
	.extern ov15_022004DC
	.extern ov15_022004F4
	.extern ov15_02200500
	.extern ov15_0220050C
	.extern ov15_02200518
	.extern ov15_02200528
	.extern ov15_02200529
	.extern ov15_0220052A
	.extern ov15_0220052B
	.extern ov15_0220053C
	.extern ov15_02200584
	.extern ov15_02200585
	.extern ov15_02200586
	.extern ov15_02200587
	.extern ov15_022005CC
	.extern ov15_02200618
	.extern ov15_02200640
	.extern ov15_02200641
	.extern ov15_02200642
	.extern ov15_02200643
	.extern ov15_022006CC
	.extern ov15_022006E8
	.extern ov15_02200704
	.extern ov15_02200720
	.extern ov15_0220073C
	.extern ov15_02200758
	.extern ov15_02200774
	.extern ov15_02200790
	.extern ov15_022008B0
	.extern ov15_022008D0
	.extern ov15_022008E8
	.extern ov15_02200908
	.extern ov15_02201304
	.extern ov15_02201314
	.extern ov15_02201328
	.extern ov15_02201340
	.extern ov15_02201368
	.extern ov15_022013A8
	.extern ov15_02201468
	thumb_func_start ov15_021FC7EC
ov15_021FC7EC: ; 0x021FC7EC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r1, _021FCAB0 ; =gSystem
	mov r2, #0x40
	ldr r3, [r1, #0x4c]
	add r5, r0, #0
	mov r4, #0
	tst r2, r3
	beq _021FC80E
	ldr r0, _021FCAB4 ; =0x00000644
	add r4, r4, #1
	ldr r1, [r5, r0]
	lsl r2, r1, #2
	ldr r1, _021FCAB8 ; =ov15_02200640
	ldrb r1, [r1, r2]
	str r1, [r5, r0]
	b _021FC9CA
_021FC80E:
	mov r2, #0x80
	tst r2, r3
	beq _021FC824
	ldr r0, _021FCAB4 ; =0x00000644
	add r4, r4, #1
	ldr r1, [r5, r0]
	lsl r2, r1, #2
	ldr r1, _021FCABC ; =ov15_02200641
	ldrb r1, [r1, r2]
	str r1, [r5, r0]
	b _021FC9CA
_021FC824:
	mov r2, #0x20
	add r6, r3, #0
	tst r6, r2
	beq _021FC87C
	ldr r1, _021FCAB4 ; =0x00000644
	ldr r3, _021FCAC0 ; =ov15_02200642
	ldr r1, [r5, r1]
	lsl r6, r1, #2
	ldrb r3, [r3, r6]
	cmp r3, #0xe
	bne _021FC854
	mov r1, #4
	str r1, [sp]
	mov r1, #0xe
	add r2, sp, #0xc
	mov r3, #1
	str r4, [sp, #4]
	bl ov15_021FA73C
	cmp r0, #1
	bne _021FC8A6
	add sp, #0x10
	mov r0, #0x10
	pop {r4, r5, r6, pc}
_021FC854:
	cmp r1, #0x10
	beq _021FC8B2
	cmp r1, #0
	blt _021FC874
	cmp r1, #8
	bge _021FC874
	sub r2, #0x21
	bl ov15_021FA6C0
	ldr r1, _021FCAB4 ; =0x00000644
	ldr r2, [r5, r1]
	cmp r2, r0
	beq _021FC8B2
	str r0, [r5, r1]
	add r4, r4, #1
	b _021FC9CA
_021FC874:
	ldr r0, _021FCAB4 ; =0x00000644
	add r4, r4, #1
	str r3, [r5, r0]
	b _021FC9CA
_021FC87C:
	mov r2, #0x10
	tst r3, r2
	beq _021FC8D8
	ldr r1, _021FCAB4 ; =0x00000644
	ldr r2, _021FCAC4 ; =ov15_02200643
	ldr r1, [r5, r1]
	lsl r3, r1, #2
	ldrb r2, [r2, r3]
	cmp r2, #0xf
	bne _021FC8AE
	mov r1, #4
	str r1, [sp]
	add r2, sp, #8
	mov r1, #0xf
	add r2, #3
	mov r3, #1
	str r4, [sp, #4]
	bl ov15_021FA73C
	cmp r0, #1
	beq _021FC8A8
_021FC8A6:
	b _021FCB5A
_021FC8A8:
	add sp, #0x10
	mov r0, #0x10
	pop {r4, r5, r6, pc}
_021FC8AE:
	cmp r1, #0x10
	bne _021FC8B4
_021FC8B2:
	b _021FC9CA
_021FC8B4:
	cmp r1, #0
	blt _021FC8D0
	cmp r1, #8
	bge _021FC8D0
	mov r2, #1
	bl ov15_021FA6C0
	ldr r1, _021FCAB4 ; =0x00000644
	ldr r2, [r5, r1]
	cmp r2, r0
	beq _021FC9CA
	str r0, [r5, r1]
	add r4, r4, #1
	b _021FC9CA
_021FC8D0:
	ldr r0, _021FCAB4 ; =0x00000644
	add r4, r4, #1
	str r2, [r5, r0]
	b _021FC9CA
_021FC8D8:
	ldr r3, [r1, #0x48]
	lsl r1, r2, #5
	tst r1, r3
	beq _021FC952
	ldr r1, _021FCAB4 ; =0x00000644
	ldr r1, [r5, r1]
	cmp r1, #0
	blt _021FC922
	cmp r1, #8
	bge _021FC922
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	sub r2, #0x11
	add r1, #0x64
	ldrb r1, [r1]
	bl ov15_021FA6C0
	ldr r1, _021FCAB4 ; =0x00000644
	str r0, [r5, r1]
	ldr r1, [r5, r1]
	add r0, r5, #0
	bl ov15_021FFECC
	mov r0, #4
	str r0, [sp]
	add r0, r4, #0
	str r0, [sp, #4]
	ldr r1, _021FCAB4 ; =0x00000644
	add r2, sp, #8
	ldr r1, [r5, r1]
	add r0, r5, #0
	add r2, #2
	mov r3, #1
	bl ov15_021FA73C
	b _021FC94C
_021FC922:
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r2, #0
	add r1, #0x64
	ldrb r1, [r1]
	add r0, r5, #0
	mvn r2, r2
	bl ov15_021FA6C0
	add r1, r0, #0
	mov r0, #4
	str r0, [sp]
	mov r0, #0
	add r2, sp, #8
	str r0, [sp, #4]
	add r0, r5, #0
	add r2, #2
	mov r3, #1
	bl ov15_021FA73C
_021FC94C:
	add sp, #0x10
	mov r0, #0x10
	pop {r4, r5, r6, pc}
_021FC952:
	add r2, #0xf0
	add r1, r3, #0
	tst r1, r2
	beq _021FC9CA
	ldr r1, _021FCAB4 ; =0x00000644
	ldr r1, [r5, r1]
	cmp r1, #0
	blt _021FC99C
	cmp r1, #8
	bge _021FC99C
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r2, #1
	add r1, #0x64
	ldrb r1, [r1]
	bl ov15_021FA6C0
	ldr r1, _021FCAB4 ; =0x00000644
	str r0, [r5, r1]
	ldr r1, [r5, r1]
	add r0, r5, #0
	bl ov15_021FFECC
	mov r0, #4
	str r0, [sp]
	add r0, r4, #0
	str r0, [sp, #4]
	ldr r1, _021FCAB4 ; =0x00000644
	add r2, sp, #8
	ldr r1, [r5, r1]
	add r0, r5, #0
	add r2, #1
	mov r3, #1
	bl ov15_021FA73C
	b _021FC9C4
_021FC99C:
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r0, r5, #0
	add r1, #0x64
	ldrb r1, [r1]
	mov r2, #1
	bl ov15_021FA6C0
	add r1, r0, #0
	mov r0, #4
	str r0, [sp]
	mov r0, #0
	add r2, sp, #8
	str r0, [sp, #4]
	add r0, r5, #0
	add r2, #1
	mov r3, #1
	bl ov15_021FA73C
_021FC9C4:
	add sp, #0x10
	mov r0, #0x10
	pop {r4, r5, r6, pc}
_021FC9CA:
	ldr r1, _021FCAB4 ; =0x00000644
	ldr r0, [r5, r1]
	cmp r0, #0x11
	bne _021FC9DE
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0x64
	ldrb r0, [r0]
	str r0, [r5, r1]
_021FC9DE:
	cmp r4, #0
	beq _021FCA02
	ldr r0, _021FCAC8 ; =0x000005DC
	bl PlaySE
	ldr r1, _021FCAB4 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	ldr r1, _021FCAB4 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FA0E4
	add r0, r5, #0
	bl ov15_021FA170
_021FCA02:
	mov r1, #0
	add r0, sp, #8
	strb r1, [r0]
	add r0, r5, #0
	bl ov15_021FAC2C
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _021FCA8A
	add r0, r5, #0
	add r1, r4, #0
	bl ov15_021FA104
	cmp r0, #0
	beq _021FCA64
	cmp r4, #8
	bhs _021FCA46
	add r0, r5, #0
	add r1, r4, #0
	bl ov15_021FA68C
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _021FCA64
	ldr r1, _021FCAB4 ; =0x00000644
	add r0, r5, #0
	str r4, [r5, r1]
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	b _021FCA64
_021FCA46:
	ldr r1, _021FCAB4 ; =0x00000644
	add r0, r5, #0
	str r4, [r5, r1]
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	ldr r0, _021FCAB4 ; =0x00000644
	ldr r1, [r5, r0]
	cmp r1, #8
	blt _021FCA64
	cmp r1, #0xd
	bgt _021FCA64
	add r0, r5, #0
	bl ov15_021FA0E4
_021FCA64:
	mov r0, #4
	str r0, [sp]
	mov r3, #1
	add r0, r5, #0
	add r1, r4, #0
	add r2, sp, #8
	str r3, [sp, #4]
	bl ov15_021FA73C
	cmp r0, #1
	beq _021FCB40
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r2, #5
	add r1, #0x68
	strh r2, [r1]
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FCA8A:
	ldr r0, _021FCAB0 ; =gSystem
	mov r3, #1
	ldr r1, [r0, #0x48]
	add r0, r1, #0
	tst r0, r3
	beq _021FCAF2
	mov r0, #4
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r1, _021FCAB4 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r2, sp, #8
	bl ov15_021FA73C
	add r4, r0, #0
	ldr r0, _021FCAB4 ; =0x00000644
	b _021FCACC
	.balign 4, 0
_021FCAB0: .word gSystem
_021FCAB4: .word 0x00000644
_021FCAB8: .word ov15_02200640
_021FCABC: .word ov15_02200641
_021FCAC0: .word ov15_02200642
_021FCAC4: .word ov15_02200643
_021FCAC8: .word 0x000005DC
_021FCACC:
	ldr r1, [r5, r0]
	cmp r1, #8
	blt _021FCADC
	cmp r1, #0xd
	bgt _021FCADC
	add r0, r5, #0
	bl ov15_021FA0E4
_021FCADC:
	cmp r4, #1
	beq _021FCB40
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #5
	add r0, #0x68
	strh r1, [r0]
	add sp, #0x10
	add r0, r4, #0
	pop {r4, r5, r6, pc}
_021FCAF2:
	mov r0, #2
	tst r0, r1
	beq _021FCB40
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r2, [r5, r0]
	mov r1, #0
	add r2, #0x66
	strh r1, [r2]
	ldr r0, [r5, r0]
	mov r2, #5
	add r0, #0x68
	strh r2, [r0]
	add r0, r5, #0
	bl ov15_021FD774
	mov r0, #SEQ_SE_GS_GEARCANCEL>>6
	lsl r0, r0, #6
	bl PlaySE
	ldr r0, _021FCB60 ; =0x00000644
	ldr r1, [r5, r0]
	cmp r1, #8
	blt _021FCB2C
	cmp r1, #0xd
	bgt _021FCB2C
	add r0, r5, #0
	bl ov15_021FA0E4
_021FCB2C:
	mov r0, #0x24
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0x13
	mov r2, #9
	mov r3, #8
	bl ov15_021FD7D0
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FCB40:
	add r0, sp, #8
	ldrb r0, [r0]
	cmp r0, #1
	bne _021FCB58
	add r0, r5, #0
	mov r1, #0x14
	mov r2, #0x29
	mov r3, #0x22
	bl ov15_021FD810
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FCB58:
	mov r0, #0x10
_021FCB5A:
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_021FCB60: .word 0x00000644
	thumb_func_end ov15_021FC7EC


	thumb_func_start ov15_021FCB64
ov15_021FCB64: ; 0x021FCB64
	push {r3, r4, r5, lr}
	sub sp, #8
	mov r1, #0x8d
	add r4, r0, #0
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r3, r1, #4
	add r1, #0x64
	ldrb r2, [r1]
	mov r1, #0xc
	mul r1, r2
	add r5, r3, r1
	mov r2, #0
	mov r1, #4
	add r3, r2, #0
	bl ov15_021FD574
	mov r0, #0x1a
	mov r1, #1
	lsl r0, r0, #6
	strh r1, [r4, r0]
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	add r0, #0x66
	ldrh r0, [r0]
	mov r2, #6
	bl GetItemAttr
	asr r1, r0, #1
	ldr r0, _021FCD70 ; =0x00000684
	mov r2, #0
	str r1, [r4, r0]
	ldr r0, [r4]
	mov r1, #5
	bl ov15_021FD43C
	ldr r0, [r4]
	mov r1, #5
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #0xa5
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0xa6
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r0, r4, #0
	mov r1, #0
	bl ov15_02200458
	add r0, r4, #0
	mov r1, #0
	bl ov15_021FD788
	ldr r2, _021FCD74 ; =0x00000644
	mov r1, #6
	ldr r2, [r4, r2]
	ldrsh r1, [r5, r1]
	add r0, r4, #0
	sub r2, #8
	bl ov15_021FF4EC
	ldr r1, _021FCD74 ; =0x00000644
	add r0, r4, #0
	ldr r1, [r4, r1]
	sub r1, #8
	bl ov15_022002B4
	mov r2, #0x8d
	lsl r2, r2, #2
	ldr r2, [r4, r2]
	add r0, r4, #0
	add r2, #0x66
	ldrh r2, [r2]
	add r1, r4, #4
	bl ov15_021FECA0
	add r0, r4, #0
	bl ov15_021FFF24
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #3
	add r0, #0x66
	ldrh r0, [r0]
	mov r2, #6
	bl GetItemAttr
	cmp r0, #0
	bne _021FCC32
	ldr r0, _021FCD70 ; =0x00000684
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _021FCC7C
_021FCC32:
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0x4c
	bl NewString_ReadMsgData
	mov r2, #0xbd
	lsl r2, r2, #2
	add r5, r0, #0
	ldr r0, [r4, r2]
	sub r2, #0xc0
	ldr r2, [r4, r2]
	mov r1, #0
	add r2, #0x66
	ldrh r2, [r2]
	bl BufferItemName
	mov r0, #0xbd
	ldr r1, _021FCD78 ; =0x000005E4
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	add r2, r5, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	bl String_Delete
	add r0, r4, #0
	mov r1, #0
	bl ov15_021FEF48
	ldr r1, _021FCD7C ; =0x00000616
	add sp, #8
	strb r0, [r4, r1]
	mov r0, #0x18
	pop {r3, r4, r5, pc}
_021FCC7C:
	add r0, r4, #0
	mov r1, #0
	bl ov15_021FF0FC
	add r0, r4, #0
	bl ov15_021FF068
	add r0, r4, #0
	mov r1, #2
	bl ov15_021FEDEC
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r2, [r4, r0]
	mov r3, #6
	add r0, r2, #0
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	mul r0, r1
	add r1, r2, r0
	add r2, #0x66
	ldr r0, [r1, #4]
	ldrb r1, [r1, #0xd]
	ldrh r2, [r2]
	bl Pocket_GetQuantity
	cmp r0, #1
	bne _021FCD0C
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0x4e
	bl NewString_ReadMsgData
	mov r1, #0
	add r5, r0, #0
	mov r2, #0x1a
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	lsl r2, r2, #6
	mov r0, #0xbd
	ldrsh r3, [r4, r2]
	add r2, r2, #4
	lsl r0, r0, #2
	ldr r2, [r4, r2]
	ldr r0, [r4, r0]
	mul r2, r3
	mov r3, #6
	bl BufferIntegerAsString
	mov r0, #0xbd
	ldr r1, _021FCD78 ; =0x000005E4
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	add r2, r5, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	bl String_Delete
	add r0, r4, #0
	mov r1, #1
	bl ov15_021FEF48
	ldr r1, _021FCD7C ; =0x00000616
	add sp, #8
	strb r0, [r4, r1]
	mov r0, #0x15
	pop {r3, r4, r5, pc}
_021FCD0C:
	mov r1, #6
	ldrsh r3, [r5, r1]
	ldr r1, _021FCD74 ; =0x00000644
	ldr r0, [r5]
	ldr r2, [r4, r1]
	add r1, #0x3e
	add r2, r3, r2
	sub r2, #8
	lsl r2, r2, #2
	add r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r4, r1]
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0x4d
	bl NewString_ReadMsgData
	mov r2, #0xbd
	lsl r2, r2, #2
	add r5, r0, #0
	ldr r0, [r4, r2]
	sub r2, #0xc0
	ldr r2, [r4, r2]
	mov r1, #0
	add r2, #0x66
	ldrh r2, [r2]
	bl BufferItemName
	mov r0, #0xbd
	ldr r1, _021FCD78 ; =0x000005E4
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	add r2, r5, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	bl String_Delete
	add r0, r4, #0
	mov r1, #1
	bl ov15_021FEF48
	ldr r1, _021FCD7C ; =0x00000616
	strb r0, [r4, r1]
	mov r0, #0x11
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_021FCD70: .word 0x00000684
_021FCD74: .word 0x00000644
_021FCD78: .word 0x000005E4
_021FCD7C: .word 0x00000616
	thumb_func_end ov15_021FCB64
