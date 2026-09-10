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
	.public _021FF720
	.public _021FF7AC
	.public _021FF7FC
	.public _021FF82E
	.public ov01_022091EC
	.public ov01_02209200
	.include "overlay_01_021FF6B0.inc"
	.include "global.inc"

	.text
	.public ov01_021FF6B0
	.public ov01_021FF6CC
	.public ov01_021FF6DC
	.public ov01_021FF724
	.public ov01_021FF74C
	.public ov01_021FF7B0
	.public ov01_021FF7F4
	.public ov01_021FF800
	.public ov01_021FF830
	.rodata

ov01_022091EC: ; 0x022091EC
	.word 0x00000024
	.word ov01_021FF7B0
	.word ov01_021FF7F4
	.word ov01_021FF800
	.word ov01_021FF830

ov01_02209200: ; 0x02209200
	.byte 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
