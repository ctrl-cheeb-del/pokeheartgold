#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_0208C3E4.inc"
	.include "global.inc"

	.public gOverlayTemplate_Battle
	.public gNatureStatMods

	.public _0208C3EC
	.public _0208C428
	.public _0208C444
	.public _0208C44C
	.public _0208C458
	.public _0208C464
	.public _0208C470
	.public _0208C480
	.public _0208C48A
	.public _0208C48C
	.public _0208C4AE
	.public _0208C4CE
	.public _0208C4D0
	.public _0208C4D4
	.public _0208C4D8
	.public _0208C4DC
	.public _0208C4F8
	.public _0208C500
	.public _0208C512
	.public _0208C52A
	.public _0208C536
	.public _0208C548
	.public _0208C55A
	.public _0208C55C
	.public _0208C56C
	.public _0208C5E0
	.public _0208C600
	.public _0208C60C
	.public _0208C610
	.public _0208C69C
	.public _0208C6A8
	.public _0208C6AC
	.public _0208C6B0
	.public _0208C6FA
	.public _0208C70A
	.public _0208C730
	.public _0208C734
	.public _0208C738
	.public _0208C774
	.public _0208C790
	.public _0208C794
	.public _0208C7B6
	.public _0208C7DA
	.public _0208C7F4
	.public _0208C816
	.public _0208C81A
	.public _0208C83C
	.public _0208C840
	.public _0208C844
	.public _0208C848
	.public _0208C84C
	.public _0208C8C4
	.public _0208C99C
	.public _0208C9A0
	.public _0208CA14
	.public _0208CA1E
	.public _0208CBC8
	.public _0208CBCC
	.public _0208CBD0
	.public _0208CC40
	.public _0208CC48
	.public _0208CC58
	.public _0208CC68
	.public _0208CC78
	.public _0208CC7E
	.public _0208CC84
	.public _0208CD34
	.public _0208CDF0
	.public _0208CE00
	.public _0208CE1C
	.public _0208CE2A
	.public _0208CE96
	.public _0208CEC4
	.public _0208CF3C
	.public _0208CF4A
	.public _0208CFA8
	.public _0208CFAC
	.public _0208CFB0
	.public _0208CFE8
	.public _0208D00A
	.public _0208D02C
	.public _0208D04E
	.public _0208D074
	.public _0208D0A0
	.public _0208D102
	.public _0208D110
	.public _0208D170
	.public _0208D174
	.public _0208D458
	.public _0208D45C
	.public _0208D460
	.public _0208D464
	.public _0208D468
	.public _0208D46C
	.public _0208D470
	.public _0208D48C
	.public _0208D53A
	.public _0208D6AA
	.public _0208D6B0
	.public _0208D6B4
	.public _0208D720
	.public _0208D724
	.public _0208D73E
	.public _0208D7B0
	.public _0208D7B4
	.public _0208D7B8
	.public _0208D7BC
	.public _0208D7C0
	.public _0208D854
	.public _0208D870
	.public _0208D874
	.public _0208D878
	.public _0208D87C
	.public _0208D880
	.public _0208D8B8
	.public _0208D8CA
	.public _0208D952
	.public _0208D994
	.public _0208D998
	.public _0208D99C
	.public _0208DA10
	.public _0208DA1E
	.public _0208DA4E
	.public _0208DA5C
	.public _0208DAC8
	.public _0208DACC
	.public _0208DAD0
	.public _0208DB4E
	.public _0208DB60
	.public _0208DBEC
	.public _0208DC2A
	.public _0208DC32
	.public _0208DC60
	.public _0208DC64
	.public _0208DCD6
	.public _0208DD12
	.public _0208DD18
	.public _0208DD1C
	.public _0208DD82
	.public _0208DD98
	.public _0208DD9C
	.public _0208DDBA
	.public _0208DDC4
	.public _0208DDCA
	.public _0208DDCE
	.public _0208DDD2
	.public _0208DDD6
	.public _0208DDDA
	.public _0208DDDE
	.public _0208DDE2
	.public _0208DDE4
	.public _0208DE34
	.public _0208DE38
	.public _0208DE3C
	.public _02104C84
	.public _02104CC4
	.public _02104D04
	.public _02104D94
	.public sub_0208C3E4
	.public sub_0208C42C
	.public sub_0208C4E0
	.public sub_0208C560
	.public sub_0208C57C
	.public sub_0208C614
	.public sub_0208C6B4
	.public sub_0208C73C
	.public sub_0208C778
	.public sub_0208C7F8
	.public sub_0208C850
	.public sub_0208C87C
	.public sub_0208C8C8
	.public sub_0208C9A4
	.public sub_0208CBD4
	.public sub_0208CC88
	.public sub_0208CFB4
	.public sub_0208D078
	.public sub_0208D0A4
	.public sub_0208D178
	.public sub_0208D474
	.public sub_0208D520
	.public sub_0208D6B8
	.public sub_0208D728
	.public sub_0208D7C4
	.public sub_0208D884
	.public sub_0208D9A0
	.public sub_0208DAD4
	.public sub_0208DB1C
	.public sub_0208DB58
	.public sub_0208DB64
	.public sub_0208DBF0
	.public sub_0208DC68
	.public sub_0208DD20
	.public sub_0208DDA0
	.text
	.public sub_0208C4E0
	.public sub_0208C560
	.public sub_0208C73C
	.public sub_0208C778
	.public sub_0208C7F8
	.public sub_0208C850
	.public sub_0208C87C
	.public sub_0208D078
	.public sub_0208D0A4
	.public sub_0208D474
	.public sub_0208D6B8
	.public sub_0208D728
	.public sub_0208D7C4
	.public sub_0208DAD4
	.public sub_0208DB1C
	.public sub_0208DB58
	.public sub_0208DB64
	.public sub_0208DBF0
	.public sub_0208DC68
	.public sub_0208DD20
	.public sub_0208DDA0

	thumb_func_start sub_0208D884
sub_0208D884: ; 0x0208D884
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	mov r0, #0x89
	add r4, r1, #0
	lsl r0, r0, #2
	add r1, #8
	lsl r7, r1, #4
	ldr r6, [r5, r0]
	cmp r4, #4
	beq _0208D8B8
	lsl r1, r4, #1
	add r2, r5, r1
	add r1, r0, #0
	add r1, #0x40
	ldrh r1, [r2, r1]
	add r2, r0, #0
	add r2, #0x48
	str r1, [sp, #0x20]
	add r1, r5, r4
	ldrb r2, [r1, r2]
	add r0, #0x4c
	str r2, [sp, #0x1c]
	ldrb r0, [r1, r0]
	str r0, [sp, #0x18]
	b _0208D8CA
_0208D8B8:
	add r0, #8
	ldr r0, [r5, r0]
	mov r1, #0
	ldrh r0, [r0, #0x18]
	str r0, [sp, #0x20]
	bl GetMoveMaxPP
	str r0, [sp, #0x1c]
	str r0, [sp, #0x18]
_0208D8CA:
	ldr r2, _0208D994 ; =0x000007B4
	ldr r1, [sp, #0x20]
	ldr r0, [r5, r2]
	sub r2, #8
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	mov r0, #2
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208D998 ; =0x00010200
	mov r1, #0
	str r0, [sp, #8]
	ldr r2, _0208D99C ; =0x000007AC
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r6, r7
	mov r3, #1
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _0208D952
	mov r2, #0x7a
	lsl r2, r2, #4
	ldr r0, [r5, r2]
	add r2, #0xc
	ldr r2, [r5, r2]
	mov r1, #0x87
	bl ReadMsgDataIntoString
	mov r3, #0x10
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208D998 ; =0x00010200
	mov r1, #0
	str r0, [sp, #8]
	ldr r2, _0208D99C ; =0x000007AC
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r6, r7
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	add r1, r4, #0
	add r0, #0x8d
	str r0, [sp]
	ldr r0, [sp, #0x1c]
	add r4, #0x88
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	add r1, #8
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r0, #0x3c
	str r0, [sp, #0x10]
	mov r0, #0x10
	str r0, [sp, #0x14]
	add r0, r5, #0
	mov r2, #0x75
	add r3, r4, #0
	bl sub_0208C8C8
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
_0208D952:
	mov r2, #0x7a
	lsl r2, r2, #4
	ldr r0, [r5, r2]
	add r2, #0xc
	ldr r2, [r5, r2]
	mov r1, #0x99
	bl ReadMsgDataIntoString
	ldr r1, _0208D99C ; =0x000007AC
	mov r0, #0
	ldr r1, [r5, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	add r3, r0, #0
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208D998 ; =0x00010200
	lsr r4, r3, #1
	str r0, [sp, #8]
	mov r1, #0
	mov r3, #0x3c
	ldr r2, _0208D99C ; =0x000007AC
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r6, r7
	sub r3, r3, r4
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0208D994: .word 0x000007B4
_0208D998: .word 0x00010200
_0208D99C: .word 0x000007AC
	thumb_func_end sub_0208D884


	thumb_func_start sub_0208D9A0
sub_0208D9A0: ; 0x0208D9A0
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r0, #0
	mov r0, #0x61
	lsl r0, r0, #2
	add r0, r5, r0
	add r4, r1, #0
	bl ScheduleWindowCopyToVram
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	mov r0, #0x69
	lsl r0, r0, #2
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	add r0, #0xd0
	bl FillWindowPixelBuffer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	add r0, #0xe0
	bl FillWindowPixelBuffer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	add r0, #0xf0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	mov r1, #2
	bl GetMoveAttr
	add r2, r0, #0
	cmp r2, #1
	bhi _0208DA10
	mov r2, #0x7a
	lsl r2, r2, #4
	ldr r0, [r5, r2]
	add r2, #0xc
	ldr r2, [r5, r2]
	mov r1, #0x9a
	bl ReadMsgDataIntoString
	b _0208DA1E
_0208DA10:
	mov r0, #0
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0x96
	mov r3, #3
	bl sub_0208C87C
_0208DA1E:
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	ldr r2, _0208DAC8 ; =0x00010200
	add r0, r5, #0
	add r1, #0xd0
	mov r3, #1
	bl sub_0208C778
	add r0, r4, #0
	mov r1, #4
	bl GetMoveAttr
	add r2, r0, #0
	bne _0208DA4E
	mov r2, #0x7a
	lsl r2, r2, #4
	ldr r0, [r5, r2]
	add r2, #0xc
	ldr r2, [r5, r2]
	mov r1, #0x9a
	bl ReadMsgDataIntoString
	b _0208DA5C
_0208DA4E:
	mov r0, #0
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0x97
	mov r3, #3
	bl sub_0208C87C
_0208DA5C:
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	ldr r2, _0208DAC8 ; =0x00010200
	add r0, r5, #0
	add r1, #0xe0
	mov r3, #1
	bl sub_0208C778
	ldr r2, _0208DACC ; =0x000002ED
	mov r0, #1
	mov r1, #0x1b
	mov r3, #0x13
	bl NewMsgDataFromNarc
	ldr r2, _0208DAD0 ; =0x000007AC
	add r1, r4, #0
	ldr r2, [r5, r2]
	add r6, r0, #0
	bl ReadMsgDataIntoString
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	ldr r2, _0208DAC8 ; =0x00010200
	add r0, r5, #0
	add r1, #0xf0
	mov r3, #0
	bl sub_0208C778
	add r0, r6, #0
	bl DestroyMsgData
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0xd0
	bl ScheduleWindowCopyToVram
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0xe0
	bl ScheduleWindowCopyToVram
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0xf0
	bl ScheduleWindowCopyToVram
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	nop
_0208DAC8: .word 0x00010200
_0208DACC: .word 0x000002ED
_0208DAD0: .word 0x000007AC
	thumb_func_end sub_0208D9A0
