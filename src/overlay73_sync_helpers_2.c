#include "overlay73_sync_helpers_private.h"

int ov73_021E6DF8(void *work, int state) {
    if (sub_0203769C()==0) {
        ov73_021E756C(work,5,0);
    } else {
        void *player = sub_02034818(0);
        BufferPlayersName(*(void **)((u8 *)work+0x24),0,player);
        ov73_021E756C(work,16,0);
    }
    ov73_021E670C(work,14);
    *(s32 *)((u8 *)work+0x324)=0;
    ov73_021E66F0(work);
    return state;
}

int ov73_021E6E48(void *work, int state) {
    s32 *counter=(s32 *)((u8 *)work+0x324);
    (*counter)++;
    if (*counter > 0x2D) *(s32 *)((u8 *)work+0x318)=15;
    ov73_021E66F0(work);
    return state;
}

int ov73_021E6E6C(void *work, int state) {
    sub_02037AC0(0xC9);
    *(s32 *)((u8 *)work+0x318)=16;
    ov73_021E66F0(work);
    return state;
}

int ov73_021E6E8C(void *work, int state) {
    if (sub_02037B38(0xC9)!=0) {
        sub_020398D4(0,0);
        BeginNormalPaletteFade(0,16,16,0,16,1,0x32);
        state=3;
    }
    ov73_021E66F0(work);
    return state;
}

int ov73_021E6ECC(void *work, int state) {
    if (ov73_021E75FC(*(void **)((u8 *)work+0x4C)) != 0) ov73_021E756C(work,9,0);
    *(s32 *)((u8 *)work+0x318)=18;
    ov73_021E66F0(work);
    return state;
}

int ov73_021E6EF8(void *work, int state) {
    if (ov73_021E75FC(*(void **)((u8 *)work+0x4C)) != 0) *(s32 *)((u8 *)work+0x318)=10;
    ov73_021E66F0(work);
    return state;
}
