#ifndef R40_OV109_R5_PRIVATE_H
#define R40_OV109_R5_PRIVATE_H
#include "global.h"

#include "system.h"
typedef struct R40PhotoAlbumApp {
    u8 pad00[0xC];
    int nextMenuState;
    u8 pad10[9];
    u8 curPage;
    u8 numPages;
    u8 cursorX;
    u8 cursorY;
} R40PhotoAlbumApp;
extern int ov109_021E75B4(void *);
extern int ov109_021E5F40(void *, u8);
extern void ov109_021E7474(void *, u8, u8, int);
extern void PlaySE(u16);
int ov109_021E6058(R40PhotoAlbumApp *);
#endif
