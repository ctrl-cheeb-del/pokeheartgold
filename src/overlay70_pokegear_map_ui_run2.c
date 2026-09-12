#include "overlay70_pokegear_map_ui_private.h"

#define OV70_STATE (*(u32 *)_02246800)
#define OV70_ERR   (*(s32 *)(_02246800 + 4))

#define OV70_FAIL()    \
    OV70_STATE = 0x18; \
    OV70_ERR = -13;    \
    ov38_0221BFEC()

void ov70_02237F64(void *a);
void ov70_02237FB4(void);
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
void ov70_022387F8(void);
void ov70_02238818(u8 *work, void *ovy);

void ov70_02238008(void *b) {
    *(void **)(ov70_02246900 + 0x40) = b;
    ov38_0221BE84();
    if (ov70_02238360(ov70_0224613C, ov70_02246814, 0, b, 0x124)) {
        OV70_STATE = 6;
    } else {
        OV70_FAIL();
    }
}

void ov70_02238058(void *b) {
    *(void **)(ov70_02246900 + 0x40) = b;
    ov38_0221BE84();
    if (ov70_02238360(ov70_02246184, ov70_02246814, 0, b, 0x124)) {
        OV70_STATE = 8;
    } else {
        OV70_FAIL();
    }
}

void ov70_022380A8(void) {
    ov38_0221BE84();
    if (ov70_02238360(ov70_022461D0, ov70_02246814, 0, ov70_0224693C, 2)) {
        OV70_STATE = 0xa;
    } else {
        OV70_FAIL();
    }
}

void ov70_022380EC(void) {
    ov38_0221BE84();
    if (ov70_02238360(ov70_0224621C, ov70_02246814, 0, ov70_0224693C, 2)) {
        OV70_STATE = 0xc;
    } else {
        OV70_FAIL();
    }
}

void ov70_02238130(void *src, int n, void *c) {
    *(void **)(ov70_02246900 + 0x40) = c;
    ov38_0221BE84();
    *(Ov70Mac6 *)ov70_02246814 = *(Ov70Mac6 *)src;
    _02246800[0x1a] = (u8)n;
    if (ov70_02238360(ov70_02246268, ov70_02246814, 7, c, 0x124 * n)) {
        OV70_STATE = 0xe;
    } else {
        OV70_FAIL();
    }
}
