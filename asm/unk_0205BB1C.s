#include "constants/species.h"
#include "constants/sndseq.h"
#include "msgdata/msg/msg_0666.h"
	.include "asm/macros.inc"
	.include "unk_0205BB1C.inc"
	.include "global.inc"

	.rodata
	.public sRegiSpecies

sRegiSpecies:
	.short SPECIES_REGIROCK
	.short SPECIES_REGICE
	.short SPECIES_REGISTEEL
