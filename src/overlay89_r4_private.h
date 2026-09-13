#include "global.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"

void *GF_3DVramMan_Create(int heapId, int texMode, int numTex, int plttMode, int numPltt, void (*initializer)(void));
void ov89_02259D50(void *data);
void *ov89_02259D70(int heapId);
void ov89_02259D8C(void);
