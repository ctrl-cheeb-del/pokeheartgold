#include "ov41_wave31_helpers_private.h"

void ov41_02249D60(void *d){u32 scr;void *alloc=GfGfxLoader_GetScrnData(PTR(PTR(d,0),4),U32(PTR(d,0),8),0,&scr,U32(d,0x14));void *owner=PTR(d,0);ov41_02249F7C(PTR(owner,0),U32(owner,0x1c),(void *)scr,U32(owner,0x14),U32(owner,0x18),U32(owner,0xc),U32(owner,0x10),U32(owner,0x28),U32(owner,0x20));Heap_Free(alloc);memset(d,0,0x18);}
