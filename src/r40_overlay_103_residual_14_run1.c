#include "r40_overlay_103_residual_14_private.h"

u32 ov103_021EDD54(R14Work *work) {
    void *mail = sub_02090E68(work->args->save, 2, work->index, ItemToMailId(work->item), 0x9C);
    *(void **)((u8 *)mail + 0x1C) = work->args->unk8;
    work->mail = mail;
    work->manager = OverlayManager_New(&ov103_021EEC58, work->mail, 0x9C);
    return 0;
}

u32 ov103_021EDD98(R14Work *work) {
    work->result = sub_02090F6C(work->mail);
    if (work->result == 1) {
        void *mon = Party_GetMonByIndex(SaveArray_Party_Get(work->args->save), work->index);
        sub_02090F70(work->mail, mon);
        Bag_TakeItem(Save_Bag_Get(work->args->save), work->item, 1, 0x9C);
    }
    sub_02090F90(work->mail);
    return 0;
}
