#include "ov96_wave30_sprite_private.h"

void ov96_0220AF30(u8 *p){if(!p)GF_AssertFail();if(!PTR(p,0))GF_AssertFail();if(!PTR(p,4))GF_AssertFail();Sprite_DeleteAndFreeResources(PTR(p,0));Sprite_DeleteAndFreeResources(PTR(p,4));Heap_Free(p);}
