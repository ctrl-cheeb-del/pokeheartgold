#include "global.h"

typedef struct Overlay45State {
    u8 data[0x600];
} Overlay45State;

void ov45_0222A1F8(void);
void *ov45_0222A1FC(Overlay45State *);
void *ov45_0222A210(Overlay45State *);
void *ov45_0222A22C(Overlay45State *);
void *ov45_0222A2C8(void **);
int ov45_0222A324(Overlay45State *);
int ov45_0222A330(Overlay45State *);
int ov45_0222A394(Overlay45State *);
void *ov45_0222A424(Overlay45State *);
void ov45_0222A430(Overlay45State *, void *);
void ov45_0222A4C8(Overlay45State *, u8);
int ov45_0222A920(Overlay45State *);
void *ov45_0222A99C(void **);
void *ov45_0222A9A0(Overlay45State *);
void *ov45_0222A9C8(Overlay45State *);
u8 ov45_0222AA54(Overlay45State *);
void *ov45_0222AB1C(Overlay45State *);
int ov45_0222ADA0(void);
u16 ov45_0222B020(Overlay45State *);
u8 ov45_0222B028(Overlay45State *);
u8 ov45_0222B034(Overlay45State *);
u16 ov45_0222B040(Overlay45State *);
void ov45_0222B0A4(Overlay45State *);
u8 ov45_0222B0B0(Overlay45State *);
void ov45_0222BB58(Overlay45State *);
void ov45_0222BCA0(s16 *);
int ov45_0222BCA8(s16 *);
void ov45_0222BCB8(s16 *);
void ov45_0222BD24(u8 *);
u8 ov45_0222BD2C(u8 *);
void ov45_0222BD30(u8 *);
void ov45_0222BD40(void *);
void ov45_0222BE00(u8 *, u16);
void ov45_0222BE48(u16 *);
void ov45_0222BE54(u16 *);
s16 ov45_0222BE94(u8 *);
void ov45_0222C36C(void);
void ov45_0222C3A8(u32 *);
void *ov45_0222CB3C(Overlay45State *);
void *ov45_0222CB40(Overlay45State *);
u16 ov45_0222CCDC(u8 *);
void ov45_0222CDC0(void);

void MI_CpuCopy8(const void *, void *, u32);
void ov45_0222DE58(void *);
void ov45_0222E03C(void *);
void ov45_0222DECC(void *);
void ov45_0222DEE0(void *);
void ov45_0222DEF4(void *);
void ov45_0222DF14(void *);
void ov45_0222DF58(void *);
void ov45_02233204(void);
void sub_02023910(void *);
void ov45_02230A4C(void *, int);
void sub_020181EC(void *);
void ov45_0222A404(u8 *);
int ov45_0222A414(u8 *);
void ov45_0222A498(u8 *, const void *);
void ov45_0222A4A8(u8 *);
int ov45_0222A4B8(u8 *);
void ov45_0222D8C8(u8 *);
void ov45_0222DCE8(u8 *);
void ov45_0222DCFC(u8 *);
void ov45_0222DD08(u8 *);
void ov45_0222DD14(u8 *);
void ov45_0222DD20(u8 *);
void ov45_0222DD2C(u8 *);
u16 ov45_0222DD38(u8 *);
void ov45_0222E7FC(void);
void ov45_022306F4(u8 *);
void ov45_02230700(u8 *);
void ov45_02230AC0(u8 *);
int ov45_0222D448(void);
void ov45_0222D8BC(u32 *, u32 *);
u32 ov45_0222DCF4(u32 *, u32 *);
u16 ov45_0222DF50(u8 *);
int ov45_0222E598(void);
int ov45_0222E59C(void);
int ov45_0222F7A8(int);
int ov45_0222F7B0(int);
void ov45_0222FDD4(void);
void ov45_02230378(u8 *, u32 *);
void ov45_02230384(u8 *, u32 *);
void ov45_02230390(void);
void ov45_022308B0(u8 *, u32);
int ov45_022308B8(u8 *);
void ov45_02230968(u8 *);
void ov45_02230974(u8 *, u8);
int ov45_02230994(u8 *);
void *ov45_022309C4(int, void *);
u32 ov45_02230A58(u8 *);

void ov45_0222A498(u8 *p, const void *q) {
    MI_CpuCopy8(p + 0x3e0, q, 4);
}

void ov45_0222A4A8(u8 *p) {
    ov45_0222BD24(p + 0x3a0);
}

int ov45_0222A4B8(u8 *p) {
    return ov45_0222BD2C(p + 0x3a0);
}

void ov45_0222A4C8(Overlay45State *p, u8 v) {
    p->data[0x208] = v;
}
