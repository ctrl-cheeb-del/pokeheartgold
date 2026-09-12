#include "overlay40_pc_box_theme_private.h"

void ov40_02239340(void *p);
void ov40_022393F4(void *p);
void ov40_02239418(void *p);
void ov40_02239514(void *p);
u32 ov40_02239538(void *p, int idx);
void ov40_02239574(void *p);
void ov40_022397BC(void *p, int a);
void ov40_02239838(void *p);
void ov40_022398F8(void *p);
void ov40_0223992C(void *p);
void ov40_02239954(u32 sel, int flag, void *scene);
int ov40_022399B8(void *p);
int ov40_02239A58(void *p);
int ov40_0223A034(void *p);
int ov40_0223A080(void *p);
int ov40_0223A158(void *p);

void ov40_02238EBC(void *p, u32 *a) {
    void *w = PTR(p, 0x860);
    if (*a == 1) {
        WORD(w, 0x388) = 0;
        return;
    }
    PTR(w, 0x388) = ov39_02227F14(ov40_0223D540(p), (u8 *)w + 0x38C, 0x14);
    MI_CpuCopy8((u8 *)w + 0x38C, (u8 *)w + 0x3DC, 0x2A30);
}

void ov40_02238F00(void *p) {
    void *w = PTR(p, 0x860);
    if (WORD(w, 0x1C) == 0) {
        *(Ov40Blob44 *)((u8 *)w + 0xB0C) = ov40_02245418;
        WORD(w, 0x748) = 0;
    } else {
        *(Ov40Blob44 *)((u8 *)w + 0xB0C) = ov40_02245444;
        PTR(w, 0x748) = NewString_ReadMsgData(PTR(p, 0x4C),
            *((u8 *)PTR(w, 0x714) + WORD(w, 0xC) * 0x1C8) + 0x5E);
    }
    WORD(w, 0xB10) = WORD(w, 0x20);
    PTR(w, 0xB0C) = (u8 *)w + 0x74C + WORD(w, 0xC) * 0x140;
    ov40_02230964(p, 1);
    ov40_0222F734((u8 *)p + 0x49C);
    ov40_0222EB9C((u8 *)p + 0x49C, p, WORD(w, 0x744), (u8 *)w + 0xB0C, WORD(w, 0xC), WORD(w, 0x14), PTR(w, 0x748));
    ov40_0222FA5C((u8 *)p + 0x47C, (u8 *)p + 0x49C);
    ov40_0222F740((u8 *)p + 0x49C, p, 1);
    ov40_0222F858((u8 *)p + 0x49C, 0x70, 0xB8);
    ov40_02230964(p, 0);
}
