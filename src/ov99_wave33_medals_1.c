#include "ov99_wave33_medals_private.h"

void ov99_021E7258(R8Work *w,u32 unused){u8 i;u8 mask=ov99_021E7180((u32)w);i=0;do{ManagedSprite_SetDrawFlag(w->all[i+15],mask&1);mask=(u8)(mask>>1);i++;}while(i<5);}

void *ov99_021E728C(R8Work *w,u32 *halfSize){u32 size;void *p=GfGfxLoader_LoadFromOpenNarc_GetSizeOut(w->narc,ov99_021E9F4C[ov99_021E714C()],FALSE,w->heap,FALSE,&size);*halfSize=size>>1;return p;}
