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
	.public _021FEE60
	.public _021FEEA4
	.public _021FEEC0
	.public ov01_02209124
	.include "overlay_01_021FED9C.inc"
	.include "global.inc"

	.text
	.public ov01_021FED9C
	.public ov01_021FEDB8
	.public ov01_021FEDC8
	.public ov01_021FEDF0
	.public ov01_021FEE04
	.public ov01_021FEE64
	.public ov01_021FEE9C
	.public ov01_021FEEA8
	.public ov01_021FEED0
	.rodata

ov01_02209124: ; 0x02209124
	.word 0x00000080
	.word ov01_021FEE64
	.word ov01_021FEE9C
	.word ov01_021FEEA8
	.word ov01_021FEED0
