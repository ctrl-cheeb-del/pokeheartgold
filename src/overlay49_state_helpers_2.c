#include "overlay49_state_helpers_private.h"
#pragma require_prototypes off

void ov49_0226571C(void *p) {
    int i;
    for (i=0;i<15;i++,p=(u8 *)p+0x10) Heap_Free(*(void **)((u8 *)p+0x10550));
}

void ov49_02265738(void *p, void *narc, u32 heap) {
    int i = 0; u8 *dst=(u8 *)p+0x10640;
    for(;i<39;i++,dst+=4) ov49_02258830(dst,narc,i+0x90,heap);
}

void ov49_02265760(void *p) {
    int i;
    for (i = 0; i < 39; i++, p = (u8 *)p + 4) {
        NNSG3dResTex *tex = NNS_G3dGetTex(*(NNSG3dResFileHeader **)((u8 *)p + 0x10640));
        NNSGfdTexKey key;
        NNSGfdTexKey key4x4;
        NNS_G3dTexReleaseTexKey(tex, &key, &key4x4);
        NNS_GfdDefaultFuncFreeTexVram(key);
        NNS_GfdDefaultFuncFreeTexVram(key4x4);
        NNS_GfdDefaultFuncFreePlttVram(NNS_G3dPlttReleasePlttKey(tex));
        Heap_Free(*(void **)((u8 *)p + 0x10640));
    }
}
