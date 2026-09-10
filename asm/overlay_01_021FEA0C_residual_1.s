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
	.public ov01_022090F0
	.public ov01_022090FC
	.include "overlay_01_021FEA0C.inc"
	.include "global.inc"

	.text
	.public ov01_021FEA0C
	.public ov01_021FEA20
	.public ov01_021FEA30
	.public ov01_021FEA38
	.public ov01_021FEA48
	.public ov01_021FEA7C
	.public ov01_021FEA90
	.public ov01_021FEAA0
	.public ov01_021FEAB0
	.public ov01_021FEB30
	.public ov01_021FEB3C
	.public ov01_021FEB78
	.public ov01_021FEB8C
	.public ov01_021FEBC0
	.rodata

ov01_022090F0: ; 0x022090F0
	.byte 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00

ov01_022090FC: ; 0x022090FC
	.word 0x00000024
	.word ov01_021FEB3C
	.word ov01_021FEB78
	.word ov01_021FEB8C
	.word ov01_021FEBC0
