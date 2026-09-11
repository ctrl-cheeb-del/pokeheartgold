	.include "asm/macros.inc"
	.public BattleArcade_GetMonCount
	.public BattleArcade_GetOpponentMonCount
	.public BattleArcade_MultiplayerCheck
	.public BattleArcade_NewBattleSetup
	.public _0223804A
	.public _02238054
	.public _0223805A
	.public _02238062
	.public _02238070
	.public _0223807C
	.public _0223808C
	.public _02238090
	.public _02238094
	.public _02238098
	.public _0223809C
	.public _022380B0
	.public _022380C8
	.public _022380D6
	.public _022380DE
	.public _022380FA
	.public _02238102
	.public _02238106
	.public _0223810E
	.public _02238112
	.public _0223812E
	.public _02238136
	.public _0223813A
	.public _02238142
	.public _02238146
	.public _022381B4
	.public _022381C8
	.public _022381CA
	.public _022381DC
	.public _02238202
	.public _0223824A
	.public _0223826A
	.public _0223828A
	.public _0223829A
	.public _02238304
	.public _0223832A
	.public _02238330
	.public _02238354
	.public _0223835C
	.public _02238360
	.public _02238364
	.public _02238368
	.public _0223836C
	.public _0223837C
	.public _02238380
	.public _022383EC
	.public _02238424
	.public _02238440
	.public _02238466
	.public _0223847E
	.public _02238488
	.public _0223848C
	.public _0223848E
	.public _02238494
	.public _022384B4
	.public _022384B8
	.public _022384C4
	.public _022384CC
	.public _022384D4
	.public ov80_02238034
	.public ov80_022380A0
	.public ov80_02238344
	.public ov80_02238370
	.public ov80_02238384
	.public ov80_022383A8
	.public ov80_022383C0
	.public ov80_02238430
	.public ov80_02238444
	.public ov80_02238498
	.public ov80_022384BC
	.public ov80_0223D514
	.public ov80_0223D516
	.public ov80_0223D518
	.public ov80_0223D51A
	.include "overlay_80_02238034.inc"
	.include "global.inc"

    .text
	.public BattleArcade_GetMonCount
	.public BattleArcade_GetOpponentMonCount
	.public BattleArcade_MultiplayerCheck
	.public ov80_02238034
	.public ov80_02238370
	.public ov80_02238384
	.public ov80_022383A8
	.public ov80_02238430
	.public ov80_02238444
	.public ov80_02238498
	.public ov80_022384BC
    .rodata

ov80_0223D514: ; 0x0223D514
	.byte 0x00, 0x00

ov80_0223D516: ; 0x0223D516
	.byte 0x63, 0x00

ov80_0223D518: ; 0x0223D518
	.byte 0x64, 0x00

ov80_0223D51A: ; 0x0223D51A
	.byte 0x77, 0x00, 0x50, 0x00, 0x77, 0x00
	.byte 0x78, 0x00, 0x8B, 0x00, 0x64, 0x00, 0x8B, 0x00, 0x8C, 0x00, 0x9F, 0x00, 0x78, 0x00, 0x9F, 0x00
	.byte 0xA0, 0x00, 0xB3, 0x00, 0x8C, 0x00, 0xB3, 0x00, 0xB4, 0x00, 0xC7, 0x00, 0xA0, 0x00, 0xC7, 0x00
	.byte 0xC8, 0x00, 0xDB, 0x00, 0xB4, 0x00, 0xDB, 0x00, 0xDC, 0x00, 0xEF, 0x00, 0xC8, 0x00, 0x2B, 0x01
	.byte 0xC8, 0x00, 0x2B, 0x01
