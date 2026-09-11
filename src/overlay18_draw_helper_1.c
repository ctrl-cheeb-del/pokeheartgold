#include "overlay18_draw_helper_private.h"

void ov18_021F2EC8(void*w,int i,int j){if(*(u16*)((u8*)w+0x1032+i*4)==2)ManagedSprite_SetDrawFlag(*(void**)((u8*)w+0x670+j*4),1);else ManagedSprite_SetDrawFlag(*(void**)((u8*)w+0x670+j*4),0);}
