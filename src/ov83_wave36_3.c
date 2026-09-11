#include "ov83_wave36_private.h"

void ov83_0224465C(void *p,int bg){GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p,0x560),0x30,PTR(p,0x4c),bg,0,0,1,0x6b);if(ov80_02237D8C(U8(p,9))==0)GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p,0x560),0x2c,PTR(p,0x4c),bg,0,0,1,0x6b);else GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p,0x560),0x2d,PTR(p,0x4c),bg,0,0,1,0x6b);}

void ov83_022446D0(void){void *d;void *a=GfGfxLoader_GetPlttData(0xb7,0x9d,&d,0x6b);DC_FlushRange(PTR(d,0xc),0x80);GX_LoadBGPltt(PTR(d,0xc),0,0x80);Heap_Free(a);}

void ov83_02244704(void *p,int bg){GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p,0x560),0x30,PTR(p,0x4c),bg,0,0,1,0x6b);GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p,0x560),0x2e,PTR(p,0x4c),bg,0,0,1,0x6b);}

void ov83_0224474C(void){void *d;void *a=GfGfxLoader_GetPlttData(0xb7,0x9d,&d,0x6b);DC_FlushRange(PTR(d,0xc),0x80);GX_LoadBGPltt(PTR(d,0xc),0,0x80);Heap_Free(a);}

void ov83_02244780(void *p,int bg){GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p,0x560),0x28,PTR(p,0x4c),bg,0,0,1,0x6b);GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p,0x560),0x93,PTR(p,0x4c),bg,0,0,1,0x6b);GfGfxLoader_GXLoadPalFromOpenNarc(PTR(p,0x560),0xbe,4,0,0,0x6b);}
