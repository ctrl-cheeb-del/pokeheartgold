#include "constants/sndseq.h"
#include "constants/moves.h"
#include "constants/std_script.h"
#include "constants/species.h"
#include "constants/sprites.h"
#include "constants/maps.h"
#include "constants/mmodel.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0096_D31R0201.h"
#include "msgdata/msg/msg_0066_D23R0102.h"
	.include "asm/macros.inc"
	.public ov01_02203654
	.public ov01_02203890
	.public ov01_022094B0
	.public ov01_022094BC
	.public ov01_022094C8
	.public ov01_022094DC
	.public ov01_022094F0
	.public ov01_02209504
	.public ov01_02209B18
	.include "overlay_01_022031C0.inc"
	.include "global.inc"

	.text
	.public ov01_022031C0
	.public ov01_022031E8
	.public ov01_022031F8
	.public ov01_02203270
	.public ov01_0220329C
	.public ov01_0220335C
	.public ov01_022033E0
	.public ov01_022033E4
	.public ov01_022034B8
	.public ov01_022034F8
	.public ov01_022035A4
	.public ov01_022035DC
	.public ov01_022037E8
	.public ov01_02203820
	.public ov01_022039BC
	.public ov01_022039E0
	.rodata

ov01_022094B0: ; 0x022094B0
	.word 0x1000, 0x1000, 0x1000

ov01_022094BC: ; 0x022094BC
	.word 0x1000, 0x1000, 0x1000

ov01_022094C8: ; 0x022094C8
	.word 0x00000054
	.word ov01_02203820
	.word ov01_022033E0
	.word ov01_02203890
	.word ov01_022037E8

ov01_022094DC: ; 0x022094DC
	.word 0x00000054
	.word ov01_0220335C
	.word ov01_022033E0
	.word ov01_022033E4
	.word ov01_022034B8

ov01_022094F0: ; 0x022094F0
	.word 0x00000054
	.word ov01_022035DC
	.word ov01_022033E0
	.word ov01_02203654
	.word ov01_022037E8

ov01_02209504: ; 0x02209504
	.word 0x00000054
	.word ov01_0220335C
	.word ov01_022033E0
	.word ov01_022034F8
	.word ov01_022035A4

	.data

	.balign 4, 0
ov01_02209B18: ; 0x02209B18
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
