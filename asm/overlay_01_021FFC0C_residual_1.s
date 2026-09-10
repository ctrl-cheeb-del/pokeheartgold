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
	.public ov01_02209258
	.include "overlay_01_021FFC0C.inc"
	.include "global.inc"

	.text
	.public ov01_021FFC0C
	.public ov01_021FFC28
	.public ov01_021FFC38
	.public ov01_021FFC80
	.public ov01_021FFCA8
	.public ov01_021FFD64
	.public ov01_021FFD70
	.public ov01_021FFE98
	.rodata

ov01_02209258: ; 0x02209258
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
