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

	thumb_func_start sub_0208C8C8
sub_0208C8C8: ; 0x0208C8C8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r4, r0, #0
	str r3, [sp, #0x10]
	mov r0, #0x89
	mov r3, #0x7a
	lsl r0, r0, #2
	lsl r7, r1, #4
	lsl r3, r3, #4
	ldr r5, [r4, r0]
	ldr r0, [r4, r3]
	add r3, #0xc
	add r1, r2, #0
	ldr r2, [r4, r3]
	bl ReadMsgDataIntoString
	ldr r1, _0208C99C ; =0x000007AC
	mov r0, #0
	ldr r1, [r4, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	add r1, sp, #0x48
	ldrb r2, [r1]
	lsr r1, r0, #1
	sub r1, r2, r1
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	add r0, r1, r0
	str r1, [sp, #0x14]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x18]
	add r0, sp, #0x4c
	ldrb r0, [r0]
	mov r1, #0
	ldr r2, _0208C99C ; =0x000007AC
	str r0, [sp, #0x1c]
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208C9A0 ; =0x00010200
	ldr r3, [sp, #0x14]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r4, r2]
	add r0, r5, r7
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0
	str r0, [sp]
	add r3, sp, #0x28
	ldrh r2, [r3, #0x14]
	ldrb r3, [r3, #0x1c]
	ldr r1, [sp, #0x10]
	add r0, r4, #0
	bl sub_0208C87C
	ldr r1, _0208C99C ; =0x000007AC
	mov r0, #0
	ldr r1, [r4, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov ip, r0
	ldr r0, [sp, #0x1c]
	mov r1, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208C9A0 ; =0x00010200
	ldr r2, _0208C99C ; =0x000007AC
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r3, [sp, #0x14]
	mov r6, ip
	ldr r2, [r4, r2]
	add r0, r5, r7
	sub r3, r3, r6
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0
	str r0, [sp]
	add r3, sp, #0x28
	ldrh r2, [r3, #0x18]
	ldrb r3, [r3, #0x1c]
	ldr r1, [sp, #0x38]
	add r0, r4, #0
	bl sub_0208C87C
	ldr r0, [sp, #0x1c]
	mov r1, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208C9A0 ; =0x00010200
	ldr r2, _0208C99C ; =0x000007AC
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r4, r2]
	ldr r3, [sp, #0x18]
	add r0, r5, r7
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0208C99C: .word 0x000007AC
_0208C9A0: .word 0x00010200
	thumb_func_end sub_0208C8C8


	thumb_func_start sub_0208C9A4
sub_0208C9A4: ; 0x0208C9A4
	push {r4, lr}
	sub sp, #0x10
	ldr r3, _0208CBC8 ; =0x000E0F00
	mov r1, #0
	mov r2, #7
	add r4, r0, #0
	str r1, [sp]
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x17
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #2
	mov r2, #0x6d
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #3
	mov r2, #0x7e
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #4
	mov r2, #0x80
	bl sub_0208C850
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r0, [r0, #0x34]
	cmp r0, #0
	beq _0208CA14
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #5
	mov r2, #0x9d
	bl sub_0208C850
	b _0208CA1E
_0208CA14:
	add r0, r4, #0
	add r0, #0x54
	mov r1, #0
	bl FillWindowPixelBuffer
_0208CA1E:
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #6
	mov r2, #4
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #7
	mov r2, #8
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #8
	mov r2, #0xa
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #9
	mov r2, #0xc
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #0xa
	mov r2, #0xd
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #0xb
	mov r2, #0xf
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #0xc
	mov r2, #0x11
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #0xd
	mov r2, #0x13
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #0xf
	mov r2, #0x6e
	bl sub_0208C850
	mov r3, #0
	add r0, r4, #0
	mov r1, #0x10
	mov r2, #0x6f
	str r3, [sp]
	bl sub_0208C7F8
	mov r0, #0
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0x11
	mov r2, #0x70
	mov r3, #1
	bl sub_0208C7F8
	mov r0, #0
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0x12
	mov r2, #0x71
	mov r3, #3
	bl sub_0208C7F8
	mov r0, #0
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0x13
	mov r2, #0x72
	mov r3, #4
	bl sub_0208C7F8
	mov r0, #0
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0x14
	mov r2, #0x73
	mov r3, #2
	bl sub_0208C7F8
	mov r2, #0x7a
	lsl r2, r2, #4
	ldr r0, [r4, r2]
	add r2, #0xc
	ldr r2, [r4, r2]
	mov r1, #0x74
	bl ReadMsgDataIntoString
	mov r1, #0
	str r1, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _0208CBC8 ; =0x000E0F00
	add r2, #0x55
	str r0, [sp, #8]
	add r0, r4, r2
	ldr r2, _0208CBCC ; =0x000007AC
	str r1, [sp, #0xc]
	ldr r2, [r4, r2]
	mov r3, #3
	bl AddTextPrinterParameterizedWithColor
	mov r2, #0x7a
	lsl r2, r2, #4
	ldr r0, [r4, r2]
	add r2, #0xc
	ldr r2, [r4, r2]
	mov r1, #0x92
	bl ReadMsgDataIntoString
	mov r3, #0
	str r3, [sp]
	mov r1, #0xff
	str r1, [sp, #4]
	ldr r0, _0208CBC8 ; =0x000E0F00
	ldr r2, _0208CBCC ; =0x000007AC
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r1, #0x75
	add r0, r4, r1
	ldr r2, [r4, r2]
	mov r1, #4
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #0x18
	mov r2, #0x95
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #0x19
	mov r2, #0x93
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #0x1a
	mov r2, #0x94
	bl sub_0208C850
	mov r0, #2
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #0x1b
	mov r2, #0xa2
	bl sub_0208C850
	mov r0, #2
	str r0, [sp]
	ldr r3, _0208CBD0 ; =0x00010200
	add r0, r4, #0
	mov r1, #0x1c
	mov r2, #0xa0
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBD0 ; =0x00010200
	add r0, r4, #0
	mov r1, #0x1d
	mov r2, #0xb6
	bl sub_0208C850
	mov r0, #0
	str r0, [sp]
	ldr r3, _0208CBC8 ; =0x000E0F00
	add r0, r4, #0
	mov r1, #0x1e
	mov r2, #0xb3
	bl sub_0208C850
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_0208CBC8: .word 0x000E0F00
_0208CBCC: .word 0x000007AC
_0208CBD0: .word 0x00010200
	thumb_func_end sub_0208C9A4


	thumb_func_start sub_0208CBD4
sub_0208CBD4: ; 0x0208CBD4
	push {r4, lr}
	sub sp, #0x10
	mov r2, #0
	add r4, r0, #0
	str r2, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, [r4]
	mov r1, #1
	add r3, r2, #0
	bl FillBgTilemapRect
	mov r0, #2
	str r0, [sp]
	mov r0, #0x12
	str r0, [sp, #4]
	mov r0, #0x16
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	mov r2, #0
	ldr r0, [r4]
	mov r1, #1
	add r3, r2, #0
	bl FillBgTilemapRect
	mov r0, #1
	str r0, [sp]
	mov r0, #0x12
	str r0, [sp, #4]
	mov r0, #0x17
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	mov r2, #0
	ldr r0, [r4]
	mov r1, #4
	add r3, r2, #0
	bl FillBgTilemapRect
	ldr r0, _0208CC84 ; =0x000007BC
	ldrsb r0, [r4, r0]
	cmp r0, #3
	bhi _0208CC7E
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0208CC40: ; jump table
	.short _0208CC48 - _0208CC40 - 2 ; case 0
	.short _0208CC58 - _0208CC40 - 2 ; case 1
	.short _0208CC68 - _0208CC40 - 2 ; case 2
	.short _0208CC78 - _0208CC40 - 2 ; case 3
_0208CC48:
	add r0, r4, #0
	bl sub_0208CC88
	add r0, r4, #0
	bl sub_0208D0A4
	add sp, #0x10
	pop {r4, pc}
_0208CC58:
	add r0, r4, #0
	bl sub_0208D178
	add r0, r4, #0
	bl sub_0208D474
	add sp, #0x10
	pop {r4, pc}
_0208CC68:
	add r0, r4, #0
	bl sub_0208D520
	add r0, r4, #0
	bl sub_0208D6B8
	add sp, #0x10
	pop {r4, pc}
_0208CC78:
	add r0, r4, #0
	bl sub_0208D728
_0208CC7E:
	add sp, #0x10
	pop {r4, pc}
	nop
_0208CC84: .word 0x000007BC
	thumb_func_end sub_0208CBD4


	thumb_func_start sub_0208CC88
sub_0208CC88: ; 0x0208CC88
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0x5d
	lsl r0, r0, #2
	add r0, r4, r0
	bl ScheduleWindowCopyToVram
	mov r0, #0xa
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	beq _0208CD34
	add r0, r4, #4
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	add r0, #0x74
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	add r0, #0x84
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	add r0, #0x94
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	add r0, #0xa4
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	add r0, #0xb4
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	add r0, #0xc4
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	add r0, #0xd4
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	add r0, #0xe4
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x10
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x20
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x30
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x40
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x50
	bl ClearWindowTilemapAndScheduleTransfer
	add sp, #0x10
	pop {r3, r4, r5, pc}
_0208CD34:
	add r0, r4, #4
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x74
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x84
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x94
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0xa4
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0xb4
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0xc4
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0xd4
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0xe4
	bl ScheduleWindowCopyToVram
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	add r0, #0x10
	bl FillWindowPixelBuffer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	add r0, #0x20
	bl FillWindowPixelBuffer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	add r0, #0x30
	bl FillWindowPixelBuffer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	add r0, #0x40
	bl FillWindowPixelBuffer
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	add r0, #0x50
	bl FillWindowPixelBuffer
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	add r1, #0x10
	ldrh r1, [r4, r1]
	ldr r0, [r0, #0x1c]
	bl Pokedex_ConvertToCurrentDexNo
	add r2, r0, #0
	beq _0208CDF0
	mov r0, #2
	str r0, [sp]
	add r0, r4, #0
	mov r1, #9
	mov r3, #3
	bl sub_0208C87C
	b _0208CE00
_0208CDF0:
	mov r2, #0x7a
	lsl r2, r2, #4
	ldr r0, [r4, r2]
	add r2, #0xc
	ldr r2, [r4, r2]
	mov r1, #0x16
	bl ReadMsgDataIntoString
_0208CE00:
	mov r1, #0xa
	lsl r1, r1, #6
	ldr r0, [r4, r1]
	lsl r0, r0, #2
	lsr r0, r0, #0x1f
	bne _0208CE1C
	sub r1, #0x5c
	ldr r1, [r4, r1]
	ldr r2, _0208CFA8 ; =0x00010200
	add r0, r4, #0
	mov r3, #2
	bl sub_0208C778
	b _0208CE2A
_0208CE1C:
	sub r1, #0x5c
	ldr r1, [r4, r1]
	ldr r2, _0208CFAC ; =0x00050600
	add r0, r4, #0
	mov r3, #2
	bl sub_0208C778
_0208CE2A:
	mov r1, #0x23
	lsl r1, r1, #4
	mov r0, #0
	ldr r1, [r4, r1]
	add r2, r0, #0
	mov r3, #0x48
	bl FontID_String_GetCenterAlignmentX
	mov r1, #0
	add r3, r0, #0
	mov r2, #0x89
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208CFA8 ; =0x00010200
	lsl r2, r2, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [r4, r2]
	add r2, #0xc
	ldr r2, [r4, r2]
	add r0, #0x10
	bl AddTextPrinterParameterizedWithColor
	mov r1, #0x9d
	lsl r1, r1, #2
	ldrb r0, [r4, r1]
	cmp r0, #0
	bne _0208CE96
	sub r1, #0x3c
	mov r0, #0
	ldr r1, [r4, r1]
	add r2, r0, #0
	mov r3, #0x48
	bl FontID_String_GetCenterAlignmentX
	mov r1, #0
	add r3, r0, #0
	mov r2, #0x89
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0xc1
	lsl r0, r0, #0xa
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	lsl r2, r2, #2
	ldr r0, [r4, r2]
	add r2, #0x14
	ldr r2, [r4, r2]
	add r0, #0x20
	bl AddTextPrinterParameterizedWithColor
	b _0208CEC4
_0208CE96:
	sub r1, #0x3c
	mov r0, #0
	ldr r1, [r4, r1]
	add r2, r0, #0
	mov r3, #0x48
	bl FontID_String_GetCenterAlignmentX
	mov r1, #0
	add r3, r0, #0
	mov r2, #0x89
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208CFAC ; =0x00050600
	lsl r2, r2, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [r4, r2]
	add r2, #0x14
	ldr r2, [r4, r2]
	add r0, #0x20
	bl AddTextPrinterParameterizedWithColor
_0208CEC4:
	mov r0, #2
	mov r2, #0x91
	str r0, [sp]
	lsl r2, r2, #2
	ldr r2, [r4, r2]
	add r0, r4, #0
	lsl r2, r2, #0x10
	mov r1, #0x10
	lsr r2, r2, #0x10
	mov r3, #5
	bl sub_0208C87C
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	ldr r2, _0208CFA8 ; =0x00010200
	add r0, r4, #0
	add r1, #0x30
	mov r3, #2
	bl sub_0208C778
	mov r0, #0
	mov r2, #0x92
	str r0, [sp]
	lsl r2, r2, #2
	ldr r2, [r4, r2]
	add r0, r4, #0
	mov r1, #0x12
	mov r3, #7
	bl sub_0208C87C
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	ldr r2, _0208CFA8 ; =0x00010200
	add r0, r4, #0
	add r1, #0x40
	mov r3, #1
	bl sub_0208C778
	ldr r3, _0208CFB0 ; =0x00000242
	ldrb r0, [r4, r3]
	lsl r0, r0, #0x19
	lsr r0, r0, #0x19
	cmp r0, #0x64
	bhs _0208CF3C
	mov r0, #0
	add r2, r3, #0
	str r0, [sp]
	add r2, #0xe
	ldr r5, [r4, r2]
	add r2, r3, #6
	ldr r2, [r4, r2]
	add r0, r4, #0
	mov r1, #0x15
	sub r2, r5, r2
	mov r3, #7
	bl sub_0208C87C
	b _0208CF4A
_0208CF3C:
	mov r2, #0
	add r0, r4, #0
	mov r1, #0x15
	mov r3, #7
	str r2, [sp]
	bl sub_0208C87C
_0208CF4A:
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	ldr r2, _0208CFA8 ; =0x00010200
	add r0, r4, #0
	add r1, #0x50
	mov r3, #1
	bl sub_0208C778
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ScheduleWindowCopyToVram
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x10
	bl ScheduleWindowCopyToVram
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x20
	bl ScheduleWindowCopyToVram
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x30
	bl ScheduleWindowCopyToVram
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x40
	bl ScheduleWindowCopyToVram
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x50
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_0208CFA8: .word 0x00010200
_0208CFAC: .word 0x00050600
_0208CFB0: .word 0x00000242
	thumb_func_end sub_0208CC88


	thumb_func_start sub_0208CFB4
sub_0208CFB4: ; 0x0208CFB4
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r0, r1, #0
	add r1, r2, #0
	mov r2, #0x13
	bl sub_0208E600
	add r4, r0, #0
	ldr r2, [r4, #0x18]
	cmp r2, #0
	beq _0208CFE8
	ldr r0, [r4, #0x14]
	mov r1, #0
	sub r0, r0, #1
	lsl r0, r0, #4
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208D074 ; =0x00010200
	mov r3, #6
	str r0, [sp, #8]
	add r0, r5, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
_0208CFE8:
	ldr r2, [r4, #0x20]
	cmp r2, #0
	beq _0208D00A
	ldr r0, [r4, #0x1c]
	mov r1, #0
	sub r0, r0, #1
	lsl r0, r0, #4
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208D074 ; =0x00010200
	mov r3, #6
	str r0, [sp, #8]
	add r0, r5, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
_0208D00A:
	ldr r2, [r4, #0x28]
	cmp r2, #0
	beq _0208D02C
	ldr r0, [r4, #0x24]
	mov r1, #0
	sub r0, r0, #1
	lsl r0, r0, #4
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208D074 ; =0x00010200
	mov r3, #6
	str r0, [sp, #8]
	add r0, r5, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
_0208D02C:
	ldr r2, [r4, #0x38]
	cmp r2, #0
	beq _0208D04E
	ldr r0, [r4, #0x34]
	mov r1, #0
	sub r0, r0, #1
	lsl r0, r0, #4
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0208D074 ; =0x00010200
	mov r3, #6
	str r0, [sp, #8]
	add r0, r5, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
_0208D04E:
	mov r0, #5
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x12
	str r0, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r0, [r5]
	mov r1, #1
	mov r3, #0x10
	bl FillBgTilemapRect
	add r0, r4, #0
	bl sub_0208E994
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_0208D074: .word 0x00010200
	thumb_func_end sub_0208CFB4
