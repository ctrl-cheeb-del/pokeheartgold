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
	.public ov01_021EB058
	.public ov01_021EB18C
	.public ov01_02209898
	.include "overlay_01_021EAFD4.inc"
	.include "global.inc"

	.text
	.public FieldTextureManager_Destroy
	.public FieldTextureManager_Free
	.public FieldTextureManager_FreeAllSlots
	.public FieldTextureManager_Init
	.public FieldTextureManager_LoadTexture
	.data

	.balign 4, 0
ov01_02209898:
	.asciz "data/fld_anime%d.bin"
