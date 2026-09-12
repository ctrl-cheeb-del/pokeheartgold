#ifndef POKEHEARTGOLD_OVERLAY81_GRID_WINDOWS_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY81_GRID_WINDOWS_INTERNAL_H

#include "global.h"

#pragma require_prototypes off

#define OV81_GRID_PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define OV81_GRID_U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define OV81_GRID_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

#endif
