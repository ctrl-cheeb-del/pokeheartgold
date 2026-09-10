	.include "asm/macros.inc"
	.include "overlay_72.inc"
	.include "global.inc"

	.text
	.public NintendoWfc_Exit
	.public NintendoWfc_Init
	.public NintendoWfc_Main
	.public _0223B330
	.public _0223B4E0
	.public _0223B820
	.public ov72_022378DC
	.public ov72_02237B54
	.public ov72_02237B80
	.public ov72_02237BD0
	.public ov72_02237C30
	.public ov72_02237CB0
	.public ov72_02237CF4
	.public ov72_02237D50
	.public ov72_02237D88
	.public ov72_022380FC
	.public ov72_02238124
	.public ov72_02238164
	.public ov72_02238194
	.public ov72_02238408
	.public ov72_02238688
	.public ov72_022386F4
	.public ov72_02238730
	.public ov72_02238750
	.public ov72_02238778
	.public ov72_022387D8
	.public ov72_02238800
	.public ov72_0223886C
	.public ov72_0223894C
	.public ov72_0223897C
	.public ov72_022389C8
	.public ov72_02238B18
	.public ov72_02238BEC
	.public ov72_02238E3C
	.public ov72_02238EE4
	.public ov72_02239040
	.public ov72_02239108
	.public ov72_02239198
	.public ov72_022391E8
	.public ov72_02239220
	.public ov72_022392BC
	.public ov72_02239370
	.public ov72_022393CC
	.public ov72_022394A4
	.public ov72_022394D8
	.public ov72_02239638
	.public ov72_022396E8
	.public ov72_02239760
	.public ov72_02239784
	.public ov72_022397E8
	.public ov72_022398BC
	.public ov72_02239A3C
	.public ov72_02239A88
	.public ov72_02239BEC
	.public ov72_02239C14
	.public ov72_02239CB4
	.public ov72_02239CD8
	.public ov72_02239D6C
	.public ov72_02239E58
	.public ov72_02239F04
	.public ov72_02239F60
	.public ov72_02239F8C
	.public ov72_02239FD8
	.public ov72_0223A014
	.public ov72_0223A044
	.public ov72_0223A06C
	.public ov72_0223A0E0
	.public ov72_0223A1AC
	.public ov72_0223A1CC
	.public ov72_0223A200
	.public ov72_0223A280
	.public ov72_0223A2E8
	.public ov72_0223A314
	.public ov72_0223A350
	.public ov72_0223A3A8
	.public ov72_0223A3E0
	.public ov72_0223A420
	.public ov72_0223A460
	.public ov72_0223A4DC
	.public ov72_0223A520
	.public ov72_0223A588
	.public ov72_0223A5B4
	.public ov72_0223A5E0
	.public ov72_0223A680
	.public ov72_0223A738
	.public ov72_0223A760
	.public ov72_0223A7F4
	.public ov72_0223A8A0
	.public ov72_0223A8F0
	.public ov72_0223AA9C
	.public ov72_0223AB84
	.public ov72_0223ABB0
	.public ov72_0223AC00
	.public ov72_0223AC2C
	.public ov72_0223ACA8
	.public ov72_0223AD20
	.public ov72_0223AD64
	.public ov72_0223AD94
	.public ov72_0223AE20
	.public ov72_0223AE6C
	.public ov72_0223AED0
	.public ov72_0223AF1C
	.public ov72_0223AF48
	.public ov72_0223AF7C
	.public ov72_0223B088
	.public ov72_0223B0C4
	.public ov72_0223B1C8
	.public ov72_0223B2C0
	.public ov72_0223B2FC
	.public ov72_0223B338
	.public ov72_0223B344
	.public ov72_0223B354
	.public ov72_0223B364
	.public ov72_0223B366
	.public ov72_0223B37C
	.public ov72_0223B3A4
	.public ov72_0223B3A6
	.public ov72_0223B3D8
	.public ov72_0223B3F4
	.public ov72_0223B410
	.public ov72_0223B42C
	.public ov72_0223B448
	.public ov72_0223B464
	.public ov72_0223B466
	.public ov72_0223B468
	.public ov72_0223B46A
	.public ov72_0223B46C
	.public ov72_0223B478
	.public ov72_0223B479
	.public ov72_0223B48C
	.public ov72_0223B4C0
	.public ov72_0223B4C2
	.public ov72_0223B4C8
	.public ov72_0223B52C
	.public ov72_0223B578
	.public ov72_0223B5C4
	.public ov72_0223B60C
	.public ov72_0223B654
	.public ov72_0223B658
	.public ov72_0223B65C
	.public ov72_0223B660
	.public ov72_0223B744
	.public ov72_0223B774
	.public ov72_0223B7B8
	.public ov72_0223B7FC
	.public ov72_0223B82C
	.public ov72_0223B834
	.public ov72_0223B900
	.public ov72_0223B91B
	.public ov72_0223B920
	.public ov72_0223B923
	.public ov72_0223B92C

	.public ov72_022378C0
	.public ov72_02237B74
	.public ov72_02238144
	.public ov72_02238160
	.public ov72_022383DC
	.public ov72_02238668
	.public ov72_02238680
	.public ov72_022387A0
	.public ov72_022387C4
	.public ov72_022387D0
	.public ov72_02238AEC
	.public ov72_02238FFC
	.public ov72_02239098
	.public ov72_022390D8
	.public ov72_02239168
	.public ov72_022392AC
	.public ov72_022393B0
	.public ov72_02239614
	.public ov72_0223985C
	.public ov72_0223988C
	.public ov72_022399CC
	.public ov72_02239A08
	.public ov72_02239B5C
	.public ov72_02239B98
	.public ov72_02239BC8
	.public ov72_02239C8C
	.public ov72_02239D3C
	.public ov72_02239E94
	.public ov72_02239E9C
	.public ov72_02239EB4
	.public ov72_02239ED4
	.public ov72_02239F30
	.public ov72_02239FBC
	.public ov72_0223A010
	.public ov72_0223A414
	.public ov72_0223A41C
	.public ov72_0223A444
	.public ov72_0223A71C
	.public ov72_0223A8DC
	.public ov72_0223ABF4
	.public ov72_0223ABF8
	.public ov72_0223ABFC
	.public ov72_0223AC6C
	.public ov72_0223AC88
	.public ov72_0223ACA4
	.public ov72_0223AF70
	.public ov72_0223B084
	.public ov72_0223B2E4

	thumb_func_start ov72_0223B2FC
ov72_0223B2FC: ; 0x0223B2FC
	push {lr}
	sub sp, #0xc
	lsl r3, r1, #2
	ldr r1, _0223B328 ; =ov72_0223B4C0
	ldrh r1, [r1, r3]
	lsl r1, r1, #0xc
	str r1, [sp]
	ldr r1, _0223B32C ; =ov72_0223B4C2
	ldr r2, [r0, #0x34]
	ldrh r1, [r1, r3]
	add r1, r2, r1
	lsl r1, r1, #0xc
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	ldr r0, [r0, #4]
	add r1, sp, #0
	bl Sprite_SetMatrix
	add sp, #0xc
	pop {pc}
	nop
_0223B328: .word ov72_0223B4C0
_0223B32C: .word ov72_0223B4C2
	thumb_func_end ov72_0223B2FC

	.rodata

_0223B330:
	.byte 0x00, 0x17, 0x0D, 0x07, 0x04, 0x0D, 0x00, 0x00

ov72_0223B338: ; 0x0223B338
	.byte 0x28, 0x00, 0xB0, 0x00, 0x80, 0x00, 0xB0, 0x00
	.byte 0xD8, 0x00, 0xB0, 0x00

ov72_0223B344: ; 0x0223B344
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x43, 0x00, 0x00, 0x00

ov72_0223B354: ; 0x0223B354
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

ov72_0223B364: ; 0x0223B364
	.byte 0x60, 0x00

ov72_0223B366: ; 0x0223B366
	.byte 0x1D, 0x00, 0x80, 0x00, 0x1D, 0x00, 0xA0, 0x00, 0x1D, 0x00
	.byte 0x50, 0x00, 0x1D, 0x00, 0x70, 0x00, 0x1D, 0x00, 0x90, 0x00, 0x1D, 0x00

ov72_0223B37C: ; 0x0223B37C
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x60, 0x00, 0x00, 0x00

ov72_0223B3A4: ; 0x0223B3A4
	.byte 0x20, 0x00

ov72_0223B3A6: ; 0x0223B3A6
	.byte 0x51, 0x00, 0x50, 0x00, 0x51, 0x00, 0x80, 0x00, 0x51, 0x00
	.byte 0xAE, 0x00, 0x51, 0x00, 0xE0, 0x00, 0x51, 0x00, 0x20, 0x00, 0x80, 0x00, 0x50, 0x00, 0x80, 0x00
	.byte 0x80, 0x00, 0x80, 0x00, 0xAE, 0x00, 0x80, 0x00, 0xE0, 0x00, 0x80, 0x00, 0x28, 0x00, 0xB0, 0x00
	.byte 0x80, 0x00, 0xB0, 0x00, 0xD8, 0x00, 0xB0, 0x00

ov72_0223B3D8: ; 0x0223B3D8
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1B, 0x02, 0x00, 0x02, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

ov72_0223B3F4: ; 0x0223B3F4
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1F, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov72_0223B410: ; 0x0223B410
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x1E, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov72_0223B42C: ; 0x0223B42C
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1F, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov72_0223B448: ; 0x0223B448
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1E, 0x04, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

ov72_0223B464: ; 0x0223B464
	.byte 0x05, 0x06

ov72_0223B466: ; 0x0223B466
	.byte 0x00, 0x01

ov72_0223B468: ; 0x0223B468
	.byte 0x08, 0x09

ov72_0223B46A: ; 0x0223B46A
	.byte 0x03, 0x04

ov72_0223B46C: ; 0x0223B46C
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x0C, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00

ov72_0223B478: ; 0x0223B478
	.byte 0x01

ov72_0223B479: ; 0x0223B479
	.byte 0x07, 0x07, 0x07, 0x0D, 0x07, 0x13, 0x07
	.byte 0x19, 0x07, 0x01, 0x0D, 0x07, 0x0D, 0x0D, 0x0D, 0x13, 0x0D, 0x19, 0x0D

ov72_0223B48C: ; 0x0223B48C
	.byte 0x0A, 0x05, 0x04, 0x01
	.byte 0x0A, 0x06, 0x00, 0x02, 0x0B, 0x07, 0x01, 0x03, 0x0C, 0x08, 0x02, 0x04, 0x0C, 0x09, 0x03, 0x00
	.byte 0x00, 0x0A, 0x09, 0x06, 0x01, 0x0A, 0x05, 0x07, 0x02, 0x0B, 0x06, 0x08, 0x03, 0x0C, 0x07, 0x09
	.byte 0x04, 0x0C, 0x08, 0x05, 0x0D, 0x0E, 0x0C, 0x0B, 0x07, 0x02, 0x0A, 0x0C, 0x0F, 0x10, 0x0B, 0x0A

ov72_0223B4C0: ; 0x0223B4C0
	.byte 0x80, 0x00

ov72_0223B4C2: ; 0x0223B4C2
	.byte 0x48, 0x00, 0x80, 0x00, 0x78, 0x00

ov72_0223B4C8: ; 0x0223B4C8
	.byte 0x32, 0x5C, 0x03, 0xFB, 0x63, 0x8C, 0x03, 0xFB
	.byte 0xFF, 0x00, 0x00, 0x00

	.data

_0223B4E0:
	.asciz "http://gamestats2.gs.nintendowifi.net/pokemondpds/battletower/roomnum.asp"
	.balign 4, 0

ov72_0223B52C: ; 0x0223B52C
	.asciz "http://gamestats2.gs.nintendowifi.net/pokemondpds/battletower/download.asp"
	.balign 4, 0

ov72_0223B578: ; 0x0223B578
	.asciz "http://gamestats2.gs.nintendowifi.net/pokemondpds/battletower/upload.asp"
	.balign 4, 0

ov72_0223B5C4: ; 0x0223B5C4
	.asciz "http://gamestats2.gs.nintendowifi.net/pokemondpds/battletower/info.asp"
	.balign 4, 0

ov72_0223B60C: ; 0x0223B60C
	.asciz "http://gamestats2.gs.nintendowifi.net/pokemondpds/common/setProfile.asp"
	.balign 4, 0

ov72_0223B654: ; 0x0223B654
	.word ov72_0223886C

ov72_0223B658: ; 0x0223B658
	.word ov72_0223894C

ov72_0223B65C: ; 0x0223B65C
	.word ov72_0223897C

ov72_0223B660: ; 0x0223B660
	.word ov72_022390D8
	.word ov72_02239108
	.word ov72_022391E8
	.word ov72_02239220
	.word ov72_022392AC
	.word ov72_022392BC
	.word ov72_02239370
	.word ov72_022393B0
	.word ov72_022393CC
	.word ov72_022394A4
	.word ov72_022394D8
	.word ov72_02239614
	.word ov72_02239638
	.word ov72_022396E8
	.word ov72_02239760
	.word ov72_02239784
	.word ov72_022397E8
	.word ov72_0223988C
	.word ov72_022398BC
	.word ov72_022399CC
	.word ov72_0223985C
	.word ov72_02239ED4
	.word ov72_02239F04
	.word ov72_02239F30
	.word ov72_02239F60
	.word ov72_02239A08
	.word ov72_02239A3C
	.word ov72_02239A88
	.word ov72_02239B5C
	.word ov72_02239B98
	.word ov72_02239BC8
	.word ov72_02239BEC
	.word ov72_02239C14
	.word ov72_02239C8C
	.word ov72_02239CB4
	.word ov72_02239CD8
	.word ov72_02239D3C
	.word ov72_02239D6C
	.word ov72_02239E58
	.word ov72_02239E9C
	.word ov72_02239EB4
	.word ov72_02239F8C
	.word ov72_02239FBC
	.word ov72_02239FD8
	.word ov72_0223A010
	.word ov72_02239E94
	.word ov72_0223A014
	.word ov72_0223A1AC
	.word ov72_0223A200
	.word ov72_0223A1CC
	.word ov72_0223A044
	.word ov72_02239168
	.word ov72_02239198
	.word ov72_0223A06C
	.word ov72_0223A0E0
	.word ov72_0223A2E8
	.word ov72_0223A314

ov72_0223B744: ; 0x0223B744
	.word ov72_0223A5B4
	.word ov72_0223A5E0
	.word ov72_0223A71C
	.word ov72_0223AB84
	.word ov72_0223ABF4
	.word ov72_0223ABF8
	.word ov72_0223ABFC
	.word ov72_0223AC00
	.word ov72_0223AC2C
	.word ov72_0223AC88
	.word ov72_0223AC6C
	.word ov72_0223ACA4

ov72_0223B774: ; 0x0223B774
	.byte 0x0E, 0x2F, 0x58, 0x77, 0x0E, 0x2F, 0x78, 0x97, 0x0E, 0x2F, 0x98, 0xB7
	.byte 0x3C, 0x63, 0x0C, 0x33, 0x3C, 0x63, 0x3C, 0x63, 0x3C, 0x63, 0x6C, 0x93, 0x3C, 0x63, 0x9E, 0xC3
	.byte 0x3C, 0x63, 0xCC, 0xF3, 0x6C, 0x93, 0x0C, 0x33, 0x6C, 0x93, 0x3C, 0x63, 0x6C, 0x93, 0x6C, 0x93
	.byte 0x6C, 0x93, 0x9E, 0xC3, 0x6C, 0x93, 0xCC, 0xF3, 0xA4, 0xBB, 0x04, 0x4B, 0xA4, 0xBB, 0x5C, 0xA3
	.byte 0xA4, 0xBB, 0xB4, 0xFB, 0xFF, 0x00, 0x00, 0x00

ov72_0223B7B8: ; 0x0223B7B8
	.byte 0x0E, 0x2F, 0x48, 0x67, 0x0E, 0x2F, 0x68, 0x87
	.byte 0x0E, 0x2F, 0x88, 0xA7, 0x3C, 0x63, 0x0C, 0x33, 0x3C, 0x63, 0x3C, 0x63, 0x3C, 0x63, 0x6C, 0x93
	.byte 0x3C, 0x63, 0x9E, 0xC3, 0x3C, 0x63, 0xCC, 0xF3, 0x6C, 0x93, 0x0C, 0x33, 0x6C, 0x93, 0x3C, 0x63
	.byte 0x6C, 0x93, 0x6C, 0x93, 0x6C, 0x93, 0x9E, 0xC3, 0x6C, 0x93, 0xCC, 0xF3, 0xA4, 0xBB, 0x04, 0x4B
	.byte 0xA4, 0xBB, 0x5C, 0xA3, 0xA4, 0xBB, 0xB4, 0xFB, 0xFF, 0x00, 0x00, 0x00

ov72_0223B7FC: ; 0x0223B7FC
	.word ov72_0223AF70, ov72_0223AF7C, ov72_0223B084, ov72_0223B088

	.bss

_0223B820:
	.space 0xC

ov72_0223B82C: ; 0x0223B82C
	.space 0x8

ov72_0223B834: ; 0x0223B834
	.space 0xCC

ov72_0223B900: ; 0x0223B900
	.space 0x1B

ov72_0223B91B: ; 0x0223B91B
	.space 0x5

ov72_0223B920: ; 0x0223B920
	.space 0x3

ov72_0223B923: ; 0x0223B923
	.space 0x9

ov72_0223B92C: ; 0x0223B92C
	.space 0x14
