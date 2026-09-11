#include "ov99_wave33_medals_private.h"

void ov99_021E7758(R8Work *w,u32 species){void *fmt=ov98_0221EEFC(w->text);if(species!=0){BufferSpeciesName(fmt,0,species);ov98_0221EBD8(w->text,5,0x7c,0);}else ov98_0221EE84(w->text,5);}

void ov99_021E7794(R8Work *w){u32 v=ov99_021E71B0(w);if(v>0x1ed)v=0;ov99_021E76D8(w,v);ov99_021E7758(w,v);ov99_021E7258(w,v);GfGfx_EngineBTogglePlanes(4,(u8)ov99_021E7198(w,v));}

void ov99_021E77D8(R8Work *w){int i;ManagedSprite_SetDrawFlag(w->all[3],0);ov99_021E7758(w,0);for(i=0;i<5;i++)ManagedSprite_SetDrawFlag(w->all[i+15],0);GfGfx_EngineBTogglePlanes(4,0);}
