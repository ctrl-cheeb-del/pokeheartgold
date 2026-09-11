	.include "asm/macros.inc"
	.public _0223A05E
	.public _0223A0B4
	.public _0223A0B8
	.public _0223A0BC
	.public _0223A13C
	.public _0223A140
	.public _0223A16C
	.public _0223A170
	.public _0223A188
	.public _0223A194
	.public _0223A1BA
	.public _0223A3AA
	.public _0223A3BA
	.public _0223A3D4
	.public _0223A3E2
	.public _0223A410
	.public _0223A42E
	.public _0223A43E
	.public _0223A458
	.public _0223A468
	.public _0223A476
	.public _0223A48A
	.public _0223A4A6
	.public _0223A4AC
	.public _0223A4C4
	.public _0223A4D0
	.public _0223A4F4
	.public _0223A4FC
	.public _0223A4FE
	.public _0223A50C
	.public _0223A510
	.public _0223A514
	.public _0223A518
	.public _0223A51C
	.public _0223A520
	.public _0223A524
	.public _0223A528
	.public _0223A52C
	.public _0223A530
	.public _0223A534
	.public _0223A57A
	.public _0223A594
	.public _0223A5A8
	.public _0223A5B8
	.public _0223A5D8
	.public _0223A5E8
	.public _0223A5FA
	.public _0223A620
	.public _0223A628
	.public _0223A646
	.public _0223A660
	.public _0223A668
	.public _0223A6A6
	.public _0223A6B2
	.public _0223A6D6
	.public _0223A732
	.public _0223A784
	.public _0223A79E
	.public _0223A7C0
	.public _0223A7FA
	.public _0223A808
	.public _0223A818
	.public _0223A822
	.public _0223A862
	.public _0223A876
	.public _0223A8A8
	.public _0223A8BE
	.public _0223A914
	.public _0223AA3C
	.public _0223AA40
	.public _0223AA44
	.public _0223AA48
	.public _0223AA66
	.public _0223AA7E
	.public _0223AAAE
	.public _0223AAC8
	.public _0223AACC
	.public _0223AB00
	.public _0223AB28
	.public _0223AB60
	.public _0223AB88
	.public _0223ABA8
	.public _0223ABE4
	.public _0223ABFE
	.public _0223AC1C
	.public _0223AC20
	.public ov80_0223A00C
	.public ov80_0223A0C0
	.public ov80_0223A0EC
	.public ov80_0223A144
	.public ov80_0223A174
	.public ov80_0223A62C
	.public ov80_0223A748
	.public ov80_0223A75C
	.public ov80_0223A78C
	.public ov80_0223A81C
	.public ov80_0223A834
	.public ov80_0223A8C4
	.public ov80_0223A8D4
	.public ov80_0223A91C
	.public ov80_0223A938
	.public ov80_0223AA4C
	.public ov80_0223AA80
	.public ov80_0223AAD0
	.public ov80_0223AB34
	.public ov80_0223AB94
	.public ov80_0223DB30
	.public ov80_0223DB64
	.public ov80_0223DB98
	.include "overlay_80_0223A00C.inc"
	.include "global.inc"

    .text
	.public ov80_0223A00C
	.public ov80_0223A0C0
	.public ov80_0223A144
	.public ov80_0223A748
	.public ov80_0223A75C
	.public ov80_0223A78C
	.public ov80_0223A81C
	.public ov80_0223A8C4
	.public ov80_0223A8D4
	.public ov80_0223A91C
	.public ov80_0223AA4C
	.public ov80_0223AA80
	.public ov80_0223AAD0
	.public ov80_0223AB34
	.public ov80_0223AB94
    .rodata

ov80_0223DB30: ; 0x0223DB30
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0xDA, 0x07, 0x00, 0x00, 0xD2, 0x07, 0x00, 0x00, 0xD2, 0x07, 0x00, 0x00
	.byte 0xD2, 0x07, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

ov80_0223DB64: ; 0x0223DB64
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xDB, 0x07, 0x00, 0x00, 0xD3, 0x07, 0x00, 0x00
	.byte 0xD3, 0x07, 0x00, 0x00, 0xD3, 0x07, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov80_0223DB98: ; 0x0223DB98
	.byte 0xC3, 0x02, 0x00, 0x00, 0xBA, 0xB9, 0xBB, 0xBC
	.byte 0xCA, 0xC9, 0xCB, 0x00, 0xC5, 0x02, 0x00, 0x00, 0xAE, 0xAD, 0xAF, 0xB0, 0xC1, 0xC0, 0xC2, 0x00
	.byte 0xC5, 0x02, 0x00, 0x00, 0xAE, 0xAD, 0xAF, 0xB0, 0xC1, 0xC0, 0xC2, 0x00, 0xC7, 0x02, 0x00, 0x00
	.byte 0xAA, 0xA9, 0xAB, 0xAC, 0xBE, 0xBD, 0xBF, 0x00, 0xC4, 0x02, 0x00, 0x00, 0xB6, 0xB5, 0xB7, 0xB8
	.byte 0xC7, 0xC6, 0xC8, 0x00, 0xC6, 0x02, 0x00, 0x00, 0xB2, 0xB1, 0xB3, 0xB4, 0xC4, 0xC3, 0xC5, 0x00
