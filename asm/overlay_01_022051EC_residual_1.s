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
	.public ov01_022096CC
	.include "overlay_01_022051EC.inc"
	.include "global.inc"

	.text
	.public ov01_022051EC
	.public ov01_02205208
	.public ov01_02205218
	.public ov01_022052A4
	.public ov01_022052C4
	.public ov01_022052F4
	.public ov01_02205300
	.public ov01_02205350
	.public ov01_02205354
	.public ov01_02205364
	.public ov01_02205388
	.public ov01_022053C4
	.rodata

ov01_022096CC: ; 0x022096CC
	.word 0x00000008
	.word ov01_02205300
	.word ov01_02205354
	.word ov01_02205350
	.word ov01_02205364
