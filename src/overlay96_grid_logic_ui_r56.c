#include "overlay96_grid_logic_r56_private.h"

void *ov96_021F3BF0(s32 heapId, void *arg1, void *arg2) {
    void *work = Heap_Alloc(heapId, 0x174);
    MI_CpuFill8(work, 0, 0x174);
    R17_S32(work, 0) = heapId;
    R17_PTR(work, 8) = arg1;
    R17_PTR(work, 4) = arg2;
    ov96_021F4558(work);
    R17_PTR(work, 0x5C) = NewMsgDataFromNarc(1, 0x1B, 0x135, heapId);
    R17_PTR(work, 0x60) = MessageFormat_New(heapId);
    return work;
}

void ov96_021F3C38(void *work) {
    s32 i = 0;
    void *p = work;
    for (; i < 12; i++, p = (u8 *)p + 8) {
        Heap_Free(R17_PTR(p, 0x98));
        Heap_Free(R17_PTR(p, 0x9C));
    }
    {
        void *q;
        s32 j;
        j = 0;
        q = work;
        for (; j < 4; j++, q = (u8 *)q + 4) {
            Heap_Free(R17_PTR(q, 0x154));
        }
        Heap_Free(R17_PTR(work, 0x164));
        {
            void *r;
            s32 k;
            k = 0;
            r = work;
            for (; k < 2; k++, r = (u8 *)r + 4) {
                Heap_Free(R17_PTR(r, 0x168));
            }
            MessageFormat_Delete(R17_PTR(work, 0x60));
            DestroyMsgData(R17_PTR(work, 0x5C));
            {
                void *window = work;
                s32 n = 0;
                window = (u8 *)window + 0xC;
                for (; n < 5; n++, window = (u8 *)window + 0x10) {
                    RemoveWindow(window);
                }
            }
        }
    }
    Heap_Free(work);
}
