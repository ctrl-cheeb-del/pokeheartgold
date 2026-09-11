#include "overlay96_result_helpers_private.h"

void ov96_0220B324(u8 *p){s32 i;for(i=0;i<16;i++,p+=0x14){if(U32(p,4)==1&&ov96_0220B2D4(p)){ManagedSprite_SetDrawFlag(PTR(p,0),0);U32(p,4)=0;}}}

void ov96_0220B354(u8 *p){s32 i;for(i=0;i<16;i++,p+=0x14)if(U32(p,4)==1)ManagedSprite_SetAnimateFlag(PTR(p,0),0);}
