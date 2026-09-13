#ifndef OV96_R40_RESIDUAL46_PRIVATE_H
#define OV96_R40_RESIDUAL46_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
extern const GraphicsModes ov96_0221B9BC;
extern const BgTemplate ov96_0221B9CC;
extern const GraphicsBanks ov96_0221B9E8;
void ov96_021EEECC(void);
void ov96_021EEEEC(void *);
void ov96_021EEF0C(BgConfig *, enum HeapID);
#endif
