#include "overlay73_sync_helpers_private.h"

int ov73_021E6FAC(Ov73FarWork *work, int state) {
    if (work->sync != NULL) {
        void *current=sub_02037454();
        if (work->sync != current) work->sync=NULL;
    }
    *(s32 *)((u8 *)work+0x318)=0x15;
    *(s32 *)((u8 *)work+0x324)=0;
    ov73_021E66F0(work);
    return state;
}

int ov73_021E6FE8(Ov73FarWork *work, int state) {
    if (work->sync != NULL) {
        void *current = sub_02037454();
        if (work->sync != current) work->sync = NULL;
    }
    work->countdown--;
    if (work->countdown < 0) work->sync = NULL;
    work->counter++;
    if (work->counter > 0x3C && work->sync == NULL) {
        work->state = 0;
        if (sub_0203769C() == 0) ov73_021E781C(work,1);
    }
    ov73_021E66F0(work);
    return state;
}
