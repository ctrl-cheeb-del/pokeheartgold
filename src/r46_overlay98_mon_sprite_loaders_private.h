#ifndef TO46_OVERLAY_98_RESIDUAL_2_PRIVATE_H
#define TO46_OVERLAY_98_RESIDUAL_2_PRIVATE_H

#include "global.h"

#include "constants/species.h"

#include "filesystem_files_def.h"
#include "heap.h"
#include "overlay_98_remaining_internal.h"
#include "pokemon.h"
#include "pokemon_icon_idx.h"
#include "sprite_system.h"
#include "unk_02013FDC.h"

typedef struct Ov98MonInfo {
    u32 species : 9;
    u32 form : 5;
    u32 gender : 2;
    u32 shiny : 1;
    u32 personality;
} Ov98MonInfo;

extern const u32 _0221F194[2];
extern const UnkStruct_02014E30 ov98_0221F19C;

void ov98_0221EA4C(ManagedSprite *, NarcId, s32, BOOL, BOOL, enum HeapID);
void ov98_0221E7E8(ManagedSprite *, const Ov98MonInfo *, BOOL, BOOL, enum HeapID);
void ov98_0221E8A8(Ov98SpriteContext *, const int *, int, int, BOOL);
void ov98_0221E970(Ov98SpriteContext *, ManagedSprite *, const Ov98MonInfo *, BOOL, BOOL);

#endif
