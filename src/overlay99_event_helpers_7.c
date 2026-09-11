#include "overlay99_event_helpers_private.h"

void ov99_021E875C(u8 *w){u8 i;NARC_Delete(*(void **)(w+8));for(i=0;i<6;i++)FreeBgTilemapBuffer(*(void **)(w+4),ov99_021EA59C[i]);Heap_Free(*(void **)(w+4));}

void ov99_021E8788(u8 *w){int flag;if(*(u32 *)(w+0xB0)!=0)flag=1;else if(*(u32 *)(w+0xBC+*(s8 *)(w+0xAC)*4)==0)flag=1;else flag=0;ov99_021E89EC(w);ov99_021E86D4(w,w[0xAC],0x1A,0,flag,1);}
