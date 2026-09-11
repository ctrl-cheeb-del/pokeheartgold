#include "ov49_wave34_windows_private.h"

void ov49_0225C8A8(void *p){int i;u8 *q;TouchHitboxController_Destroy(PTR(p,0x1c));RemoveWindow((u8 *)p+0xc);i=0;q=p;for(;i<3;i++,q+=4)Heap_Free(PTR(q,0x20));U8(p,2)=0;}
