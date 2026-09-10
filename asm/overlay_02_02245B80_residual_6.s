#include "constants/abilities.h"
#include "constants/species.h"
#include "constants/sndseq.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/std_script.h"
	.include "asm/macros.inc"
	.public ov02_02245B80
	.public ov02_02245B9C
	.public ov02_02245BC8
	.public ov02_02245D18
	.public ov02_02245DB0
	.public ov02_02245DE0
	.public ov02_02245E04
	.public ov02_02245E68
	.public ov02_02245ED8
	.public ov02_02245FD0
	.public ov02_02246048
	.public ov02_022460AC
	.public ov02_022460CC
	.public ov02_022460FC
	.public ShowLegendaryWing
	.public ov02_022461AC
	.public ov02_022461DC
	.public ov02_022462DC
	.public ov02_022462E8
	.public ov02_02246304
	.public ov02_02246330
	.public ov02_02246398
	.public ov02_02246444
	.public ov02_02246490
	.public ov02_0224650C
	.public ov02_02246534
	.public ov02_02246548
	.public ov02_0224662C
	.public ov02_0224663C
	.public ov02_02246714
	.public ov02_02246744
	.public ov02_02246798
	.public OpenAlphHiddenRoom
	.public ov02_022467E8
	.public ov02_02246818
	.public ov02_0224686C
	.public ov02_02246964
	.public ov02_022469A0
	.public ov02_022469B4
	.public ov02_022469D8
	.public ov02_02246A34
	.public ov02_0225321C
	.public ov02_0225321E
	.public ov02_02253222
	.public ov02_02253228
	.public ov02_0225322E
	.public ov02_02253234
	.public ov02_0225323A
	.public ov02_02253240
	.public ov02_02253246
	.public ov02_0225324C
	.public ov02_02253254
	.public ov02_02253264
	.public ov02_02253D80
	.public ov02_02253D84
	.include "overlay_02.inc"
	.include "global.inc"

	.text
	.rodata

ov02_0225321C:
	.byte 0x0B, 0x00

ov02_0225321E:
	.byte 0x04, 0x00
	.byte 0x05, 0x00

ov02_02253222:
	.byte 0x43, 0x00, 0x42, 0x00, 0x44, 0x00

ov02_02253228:
	.byte 0x45, 0x00, 0x46, 0x00, 0x47, 0x00

ov02_0225322E:
	.byte 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00

ov02_02253234:
	.byte 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00

ov02_0225323A:
	.byte 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00

ov02_02253240:
	.byte 0x39, 0x00, 0x38, 0x00, 0x3A, 0x00

ov02_02253246:
	.byte 0x07, 0x00, 0x08, 0x00, 0x09, 0x00

ov02_0225324C: ; 0x0225324C
	.byte 0x01, 0x09, 0x0A, 0x0E
	.byte 0x02, 0x00, 0x80, 0x00

ov02_02253254: ; 0x02253254
	.byte 0xAE, 0x00, 0x37, 0x03
	.word ov02_02253240
	.byte 0xAE, 0x00, 0x41, 0x03
	.word ov02_02253222

ov02_02253264: ; 0x02253264
	.byte 0xAE, 0x00, 0x0A, 0x01
	.word ov02_0225321C
	.short SEQ_SE_GS_DENKI_TRAP
	.balign 4
	.byte 0xAE, 0x00, 0x03, 0x02
	.word ov02_0225321E
	.short SEQ_SE_GS_DOKU_TRAP
	.balign 4
	.byte 0xAE, 0x00, 0x06, 0x03
	.word ov02_02253246
	.short SEQ_SE_GS_IWA_TRAP
	.balign 4

	.data

ov02_02253D80: ; 0x02253D80
	.word ov02_0225322E

ov02_02253D84: ; 0x02253D84
	.word ov02_02253234
	.word ov02_02253228
	.word ov02_0225323A
