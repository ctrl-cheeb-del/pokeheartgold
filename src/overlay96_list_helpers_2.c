#include "overlay96_list_helpers_private.h"

u32 ov96_0220CCBC(R97Item *p){s32 i=0;u8 roll=(u8)(MTRandom()%100);u8 kind=(u8)(p->w[1+p->v5.b.state]>>26);if(kind>=3)GF_AssertFail();i+=ov96_0221CE08[kind];if(roll<i)return 1;return 0;}
