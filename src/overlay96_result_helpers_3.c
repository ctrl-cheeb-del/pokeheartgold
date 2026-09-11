#include "overlay96_result_helpers_private.h"

void ov96_0220B1B8(u8 *p){s32 i;for(i=0;i<16;i++,p+=0x14){if(!PTR(p,0))GF_AssertFail();Sprite_DeleteAndFreeResources(PTR(p,0));}}
