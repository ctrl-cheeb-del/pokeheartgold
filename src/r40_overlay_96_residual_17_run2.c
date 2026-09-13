#include "r40_overlay_96_residual_17_private.h"

void *ov96_021E92E0(u32 heapId);
void ov96_021E9320(Ov96R17Work *work);
Ov96R17Record *ov96_021E9344(Ov96R17Work *work);
Ov96R17Record *ov96_021E9370(Ov96R17Work *work, u32 index);
void ov96_021E9394(Ov96R17Work *work);
void *ov96_021E94EC(Ov96R17Work *work, u32 index);

void *ov96_021E94EC(Ov96R17Work *work, u32 index) {
    if (index >= 4) {
        GF_AssertFail();
    }
    if ((s32)index >= work->count) {
        GF_AssertFail();
    }
    return work->ordered[index];
}
