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
	.public _021FAC54
	.public _021FAC70
	.public _021FAC88
	.public _021FAC8E
	.public _021FAC94
	.public _021FACB0
	.public _021FACBC
	.public _021FACD0
	.public ov01_021FAC44
	.public ov01_02209B70
	.include "overlay_01_021FAC44.inc"
	.include "global.inc"

	.text
	.public ov01_021FACB4
	.public ov01_021FACE4
	.public ov01_021FACEC
	.public ov01_021FACF8
	.bss

ov01_02209B70: ; 0x02209B70
	.space 4 * 0xF000
