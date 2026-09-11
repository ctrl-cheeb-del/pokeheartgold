#include "ov96_wave31_free_private.h"

void ov96_0220B500(u8 *p){s32 i;u8 *q;if(!p)GF_AssertFail();i=0;q=p;for(;i<9;i++,q+=4){void *sprite=PTR(q,0x10);if(sprite)Sprite_DeleteAndFreeResources(sprite);}Heap_Free(p);}
