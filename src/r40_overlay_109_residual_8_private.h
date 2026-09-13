#ifndef R40_OV109_R8_PRIVATE_H
#define R40_OV109_R8_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "render_window.h"
typedef struct R40PhotoApp8 {
    u32 heapId;
    u8 pad04[0x10];
    BgConfig *bg;
    u8 pad18[0xB];
    u8 frame;
    u8 pad24[0x88];
    NNSG2dScreenData *scrnAC;
    void *rawB0;
    NNSG2dScreenData *scrnB4;
    void *rawB8;
    NNSG2dScreenData *scrnBC;
    void *rawC0;
} R40PhotoApp8;
void ov109_021E694C(R40PhotoApp8 *);
void ov109_021E6AFC(R40PhotoApp8 *);
void ov109_021E6B5C(R40PhotoApp8 *);
#endif
