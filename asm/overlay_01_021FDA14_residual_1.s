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
	.include "overlay_01_021FDA14.inc"
	.include "global.inc"

	.public ov01_021FDA14
	.public ov01_021FDA30
	.public ov01_021FDA40
	.public ov01_021FDA5C
	.public ov01_021FDA74
	.public ov01_021FDAC0
	.public ov01_021FDB34
	.public ov01_021FDB44
	.public ov01_021FDBCC
	.public ov01_021FDC7C
	.public ov01_021FDD48
	.public ov01_021FDD94
	.public ov01_021FDE08
	.public ov01_021FDE64
	.public ov01_021FDEAC
	.public ov01_021FDF14
	.public ov01_021FDF20
	.public ov01_021FDF64
	.public ov01_021FDF88
	.public ov01_021FDFD4
	.public ov01_021FE058
	.public ov01_021FE0EC
	.public ov01_021FE190
	.public ov01_02208F74
	.public ov01_02208F88
	.public ov01_02208F9C
	.public ov01_02208FB0
	.public ov01_02208FC8

	.rodata

ov01_02208F74: ; 0x02208F74
	.word 0x00000038
	.word ov01_021FDFD4
	.word ov01_021FDB34
	.word ov01_021FE058
	.word ov01_021FE0EC

ov01_02208F88: ; 0x02208F88
	.word 0x00000038
	.word ov01_021FDAC0
	.word ov01_021FDB34
	.word ov01_021FDB44
	.word ov01_021FDBCC

ov01_02208F9C: ; 0x02208F9C
	.word 0x00000038
	.word ov01_021FDEAC
	.word ov01_021FDF14
	.word ov01_021FDF20
	.word ov01_021FDF64
