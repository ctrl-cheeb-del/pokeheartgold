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
	.include "overlay_01_022001E4.inc"
	.include "global.inc"

	.public ov01_022001E4
	.public ov01_022001F8
	.public ov01_02200208
	.public ov01_02200210
	.public ov01_02200220
	.public ov01_02200228
	.public ov01_02200238
	.public ov01_0220024C
	.public ov01_02200260
	.public ov01_022002AC
	.public ov01_022002FC
	.public ov01_0220032C
	.public ov01_0220035C
	.public ov01_0220036C
	.public ov01_0220037C
	.public ov01_0220038C
	.public ov01_0220039C
	.public ov01_022003B0
	.public ov01_022003C4
	.public ov01_022003F4
	.public ov01_02200400
	.public ov01_02200418
	.public ov01_02200480
	.public ov01_022004EC
	.public ov01_02200508
	.public ov01_02200540
	.public ov01_0220059C
	.public ov01_02200614
	.public ov01_022092C8
	.public ov01_022092DC
	.public ov01_022092F0

	.rodata

ov01_022092C8:
	.word 0x00000044
	.word ov01_02200418
	.word ov01_022004EC
	.word ov01_02200480
	.word ov01_02200508

ov01_022092DC: ; 0x022092DC
	.word 0x00000044
	.word ov01_0220059C
	.word ov01_022004EC
	.word ov01_02200614
	.word ov01_02200508

ov01_022092F0: ; 0x022092F0
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
