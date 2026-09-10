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
	.include "overlay_01_021FE590.inc"
	.include "global.inc"

	.public ov01_021FE590
	.public ov01_021FE5A4
	.public ov01_021FE5B4
	.public ov01_021FE5BC
	.public ov01_021FE5CC
	.public ov01_021FE61C
	.public ov01_021FE64C
	.public ov01_021FE65C
	.public ov01_021FE66C
	.public ov01_021FE6B4
	.public ov01_021FE6F4
	.public ov01_021FE70C
	.public ov01_021FE768
	.public ov01_02209084
	.public ov01_02209098
	.public ov01_022090AC

	.rodata

ov01_02209084: ; 0x02209084
	.word 0x0000001C
	.word ov01_021FE6B4
	.word ov01_021FE6F4
	.word ov01_021FE70C
	.word ov01_021FE768
