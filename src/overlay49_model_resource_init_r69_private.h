#ifndef POKEHEARTGOLD_OVERLAY49_MODEL_RESOURCE_INIT_R69_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY49_MODEL_RESOURCE_INIT_R69_PRIVATE_H

// clang-format off
#include "global.h"
#include "gf_gfx_loader.h"
#include <nnsys/g3d/binres/res_struct_accessor.h>
#include <nnsys/g3d/binres/res_struct_accessor_inline.h>
// clang-format on

#define PTR_AT(base, offset) (*(void **)((u8 *)(base) + (offset)))

void NNS_G3dMdlSetMdlEmiAll(void *model, u32 emission);
void ov49_02265698(void *work, NARC *narc, enum HeapID heapId);

#endif
