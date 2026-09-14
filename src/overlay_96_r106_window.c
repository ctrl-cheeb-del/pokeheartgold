#include "global.h"

#include "bg_window.h"

#pragma require_prototypes off

typedef struct Ov96R106Work {
    void *course;
    u32 heap;
    void *spriteSystem;
    void *spriteManager;
    BgConfig *bgConfig;
    u8 pad14[8];
    u8 selected;
    u8 pad1D[0xB];
    u8 windows[4][0x10];
} Ov96R106Work;

extern const u32 ov96_0221D15C[];
extern void GF_AssertFail(void);
extern void LoadFontPal0(u32, u32, u32);

void ov96_02210538(Ov96R106Work *work) {
    u8 i;

    if (work == NULL) {
        GF_AssertFail();
    }
    if (work->bgConfig == NULL) {
        GF_AssertFail();
    }
    for (i = 0; i < 4; i++) {
        AddWindow(work->bgConfig, (Window *)work->windows[i], (const WindowTemplate *)&ov96_0221D15C[i * 2]);
    }
    BG_FillCharDataRange(work->bgConfig, (GFBgLayer)7, 0, 1, 0);
    LoadFontPal0(4, 0x1E0, work->heap);
}
