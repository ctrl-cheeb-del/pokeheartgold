#include "constants/sndseq.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/pokemon.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "constants/std_script.h"
#include "fielddata/script/scr_seq/event_D24R0204.h"
#include "constants/field_move_response.h"
	.include "asm/macros.inc"
	.include "unk_020632B0.inc"
	.include "global.inc"

	.public sub_020632B0
	.public MapObjectMovementCmd108_Step1
	.public _020632FC
	.public _0206330A
	.public _02063336
	.public _02063344
	.public _0206336A
	.public _02063378
	.public _020633A2
	.public _020633B2
	.public _02063416
	.public _0206341C
	.public _02063420
	.public _02063448
	.public _02063456
	.public _020634CC
	.public _020634D0
	.public _02063550
	.public _020635AA
	.public _020635B8
	.public _020635E0
	.public _020635EE
	.public _02063616
	.public _02063624
	.public _0206366E
	.public _0206367C
	.public _02063680
	.public _020FE0C4
	.public _020FE0D4
	.public _020FE0E4
	.public _020FE104
	.public _020FE134
	.public _020FE164
	.public _020FE194
	.public _020FE1A4

	.text
	.public MapObjectMovementCmd108_Step1
	.rodata

	.public _020FE0C4
_020FE0C4:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00
	.public _020FE0D4
_020FE0D4:
	.byte 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00
	.public _020FE0E4
_020FE0E4:
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00
	.public _020FE104
_020FE104:
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063B08
	.word sub_02063C88
	.word sub_02063C88
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063AFC
	.word sub_02063AFC
	.public _020FE134
_020FE134:
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B20
	.word sub_02063CB4
	.word sub_02063CB4
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B00
	.word sub_02063B00
	.public _020FE164
_020FE164:
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B9C
	.word sub_02063D30
	.word sub_02063D30
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B04
	.word sub_02063B04
	; File boundary?
	.public _020FE194
_020FE194:
	.word sub_020643B8
	.word sub_020643E4
	.word sub_02064410
	.word sub_0206443C
	.public _020FE1A4
_020FE1A4:
	.word sub_0206464C
	.word sub_02064668
	.word sub_02064694
	.word sub_020646DC
	.word sub_02064714
	.word sub_02064730
	.word sub_02064748
	.word sub_02064764
	.word sub_02064778
	.word sub_02064790
	.word sub_020647A8
	.word sub_020647C0
	.word sub_020647E8
	.word sub_02064808
	.word sub_02064824
	.word sub_020648A0
	.word sub_020648C8
	.word sub_020648E4
