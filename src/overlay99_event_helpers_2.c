#include "overlay99_event_helpers_private.h"

void ov99_021E7EBC(u8 *w){u8 i;NARC_Delete(*(void **)(w+8));NARC_Delete(*(void **)(w+4));for(i=0;i<7;i++)FreeBgTilemapBuffer(*(void **)w,ov99_021EA348[i]);Heap_Free(*(void **)w);}
