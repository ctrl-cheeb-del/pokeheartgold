#include "overlay70_pokegear_map_ui_private.h"

#define OV70_STATE (*(u32 *)_02246800)
#define OV70_ERR   (*(s32 *)(_02246800 + 4))

#define OV70_FAIL()    \
    OV70_STATE = 0x18; \
    OV70_ERR = -13;    \
    ov38_0221BFEC()

void ov70_02237F64(void *a);
void ov70_02237FB4(void);
void ov70_02238008(void *b);
void ov70_02238058(void *b);
void ov70_022380A8(void);
void ov70_022380EC(void);
void ov70_02238130(void *src, int n, void *c);
void ov70_022381A4(void *src, void *c);
void ov70_02238208(void *a, void *b, void *c);
void ov70_0223826C(void);
void ov70_022382C0(void);
void ov70_02238304(void *a, void *b);
int ov70_02238360(void *a, void *b, int c, void *d, int e);
int ov70_02238398(int x);
int ov70_02238430(void *ovy, u32 *state);
int ov70_022385C0(void *ovy, u32 *state);
int ov70_022386F4(void *ovy);
void ov70_022387AC(u8 *work);

void ov70_022387F8(void) {
    Ov70Banks banks;

    banks = ov70_02245218;
    GfGfx_SetBanks(&banks);
}

void ov70_02238818(u8 *work, void *ovy) {
    *(void **)work = OverlayManager_GetArgs(ovy);
    *(u32 *)(work + 0x14) = 0;
    ov70_02238E50(work, 0, 0);
    *(u16 *)(work + 0x11c) = 0;
    *(u16 *)(work + 0xb8a) = 0;
    work[0xb8c] = 3;
    work[0xb8d] = 0;
    work[0xb8e] = 0;
    *(u16 *)(work + 0xb90) = 0;
    *(u16 *)(work + 0x11dc) = 0;
    *(u16 *)(work + 0x120) = 0x12;
    *(u16 *)(work + 0x11f8) = 0;
    *(u16 *)(work + 0x11fa) = 0;
    *(u16 *)(work + 0x11de) = 0;
    *(u32 *)(work + 0x11bc) = 0;
    *(u32 *)(work + 0x12cc) = 0;
}
