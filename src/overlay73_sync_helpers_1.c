#include "overlay73_sync_helpers_private.h"

int ov73_021E6CC0(void *work, int state) {
    s32 *counter=(s32 *)((u8 *)work+0x324);
    s32 old=(*counter)++;
    if (old > 0x3C) *(s32 *)((u8 *)work+0x318)=0xF;
    return state;
}

int ov73_021E6CDC(void *work, int state) {
    ov73_021E756C(work,5,0);
    ov73_021E670C(work,10);
    ov73_021E66F0(work);
    return state;
}

int ov73_021E6CFC(void *work, int state) {
    s32 *counter=(s32 *)((u8 *)work+0x324);
    (*counter)++;
    if (*counter > 0x3C) {
        BeginNormalPaletteFade(0,16,16,0,16,1,0x32);
        state=3;
    }
    ov73_021E66F0(work);
    return state;
}

int ov73_021E6D38(void *work, int state) {
    ov73_021E67A8(work);
    *(s32 *)((u8 *)work+0x318)=12;
    ov73_021E66F0(work);
    return state;
}
