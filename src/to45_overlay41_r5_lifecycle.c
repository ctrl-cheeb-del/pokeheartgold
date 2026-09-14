#include "to45_overlay41_r5_lifecycle_private.h"

void ov41_02246170(Ov41R5Work *work) {
    Ov41R5Config config = ov41_0224BFB4;

    work->narc = NARC_New((NarcId)0x1A, HEAP_ID_14);
    ov41_022467E4(work, &config);
    ov41_02246CC0(work, HEAP_ID_14, 0x2800, 0x20);
    ov41_02246A50(work);
    ov41_02246C90(work, 13);
    ov41_02246A94(work);
    work->bgConfig = BgConfig_Alloc(HEAP_ID_14);
    ov41_022468FC(work);
}

void ov41_022461D0(Ov41R5Work *work) {
    ov41_02246CB0(work);
    ov41_02246820(work);
    ov41_02246A20(work);
    Heap_Free(work->bgConfig);
    ov41_02246D2C(work);
    ov41_02246B34(work);
    ov41_02246A7C(work);
    NARC_Delete(work->narc);
    Heap_Free(work->ptr04);
    work->ptr04 = NULL;
    Heap_Free(work->ptr10);
    work->ptr10 = NULL;
}

void ov41_0224621C(Ov41R5Work *work) {
    Thunk_G3X_Reset();
    NNS_G2dSetupSoftwareSpriteCamera();
    if (work->ptr1C != NULL) {
        ov41_02246830(work);
    }
    if (work->ptr2C != NULL) {
        PokepicManager_DrawAll(work->ptr20);
    }
    RequestSwap3DBuffers(GX_SORTMODE_AUTO, GX_BUFFERMODE_Z);
    ov41_02246B5C(work);
}
