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
	.public ov01_02209110
	.include "overlay_01_021FEC38.inc"
	.include "global.inc"

	.text
	.public ov01_021FEC38
	.public ov01_021FEC54
	.public ov01_021FEC64
	.public ov01_021FEC8C
	.public ov01_021FECA0
	.public ov01_021FED14
	.public ov01_021FED4C
	.public ov01_021FED58
	.public ov01_021FED80
	.rodata

ov01_02209110: ; 0x02209110
	.word 0x00000080
	.word ov01_021FED14
	.word ov01_021FED4C
	.word ov01_021FED58
	.word ov01_021FED80
