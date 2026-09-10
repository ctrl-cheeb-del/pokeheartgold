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
	.public ov01_02208E0C
	.include "overlay_01_021FCD2C.inc"
	.include "global.inc"

	.text
	.public ov01_021FCD2C
	.public ov01_021FCD6C
	.public ov01_021FCD78
	.public ov01_021FCD8C
	.public ov01_021FCDA8
	.public ov01_021FCDBC
	.public ov01_021FCDC4
	.public ov01_021FCDFC
	.public ov01_021FCE34
	.public ov01_021FCE44
	.public ov01_021FCE5C
	.public ov01_021FCE74
	.rodata

ov01_02208E0C: ; 0x02208E0C
	.word ov01_021FCDBC
	.word ov01_021FCDC4
	.word ov01_021FCDFC
	.word 0x00000000
