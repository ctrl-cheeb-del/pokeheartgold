#include "overlay49_model_resource_init_r69_private.h"

void ov49_02265698(void *work, NARC *narc, enum HeapID heapId) {
    int i;

    for (i = 0; i < 15; i++, work = (u8 *)work + 0x10) {
        PTR_AT(work, 0x10550) = GfGfxLoader_LoadFromOpenNarc(narc, i + 0x81, FALSE, heapId, FALSE);
        PTR_AT(work, 0x10554) = NNS_G3dGetMdlSet(PTR_AT(work, 0x10550));
        PTR_AT(work, 0x10558) = NNS_G3dGetMdlByIdx(PTR_AT(work, 0x10554), 0);
        PTR_AT(work, 0x1055C) = NULL;
        NNS_G3dMdlSetMdlEmiAll(PTR_AT(work, 0x10558), 0x7FFF);
    }
}
