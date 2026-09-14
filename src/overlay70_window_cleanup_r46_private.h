#ifndef OV70_R34_R2_PRIVATE_H
#define OV70_R34_R2_PRIVATE_H
#include "global.h"

typedef struct Ov70Window {
    u8 bytes[0x10];
} Ov70Window;

typedef struct Ov70MenuWork {
    void *bgConfig;
    Ov70Window *windows;
    u8 pad08[0x14];
    void *cellManager;
} Ov70MenuWork;

void sub_02019B1C(void *, int, s8 *, s8 *);
void FillWindowPixelBuffer(Ov70Window *, u8);
void CopyWindowPixelsToVram_TextMode(Ov70Window *);
void RemoveWindow(Ov70Window *);
void FillBgTilemapRect(void *, int, int, int, int, int, int, int);
void BgCommitTilemapBufferToVram(void *, int);
void ov70_02241DB4(Ov70MenuWork *, int);

#endif
