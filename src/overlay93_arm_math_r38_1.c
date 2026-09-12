#include "overlay93arm_r38_private.h"

extern void GF_AssertFail(void);
void ov93_0225F268(s32 x, s32 y, s16 *outX, s16 *outY);

typedef struct Ov93WorkScratch {
    u8 pad000[0x10];
    s32 f010;
    u8 pad014[0x20 - 0x14];
    s32 f020;
    u8 pad024[0x20c - 0x24];
    s32 f20c;
    s32 f210;
    u8 pad214[0x218 - 0x214];
    s32 f218;
    u8 pad21c[0x224 - 0x21c];
    s32 f224;
    s32 f228;
    s32 f22c;
    s32 f230;
    u8 pad234[0x238 - 0x234];
    s32 f238;
    s32 f23c;
    s32 f240;
    u8 pad244[0x248 - 0x244];
    s32 f248;
    u8 pad24c[0x270 - 0x24c];
    u32 f270;
    u8 f274;
} Ov93WorkScratch;

extern const u8 ov93_02262C05[];
extern const u8 ov93_02262C06[];
extern const u8 ov93_02262C07[];
extern const u8 ov93_02262C08[];
extern s32 ov93_0225F9AC(Ov93WorkScratch *work);
int ov93_0225F370(Ov93WorkScratch *work);
extern BOOL IsSEPlaying(u16 seqNo);
extern void PlaySE(u16 seqNo);
extern s32 ov93_0225F548(Ov93WorkScratch *work, s32 mode, s32 amount);
extern void ov93_0225EB38(Ov93WorkScratch *work);
int ov93_0225F44C(Ov93WorkScratch *work);

void ov93_0225F268(s32 x, s32 y, s16 *outX, s16 *outY) {
    s32 tx = ((s64)x << 12) / 0x80000;
    s32 ty = ((s64)y << 12) / 0x80000;

    if (tx > 0x7fff) {
        GF_AssertFail();
    }
    if (tx < -0x8000) {
        GF_AssertFail();
    }
    if (ty > 0x7fff) {
        GF_AssertFail();
    }
    if (ty < -0x8000) {
        GF_AssertFail();
    }
    if (tx - 0x800 > 0x7fff) {
        GF_AssertFail();
    }
    if (tx - 0x800 < -0x8000) {
        GF_AssertFail();
    }
    if (ty + 0x800 > 0x7fff) {
        GF_AssertFail();
    }
    if (ty + 0x800 < -0x8000) {
        GF_AssertFail();
    }
    *outX = tx - 0x800;
    *outY = ty + 0x800;
}
