#ifndef TO45_OV96_R54_R2_PRIVATE_H
#define TO45_OV96_R54_R2_PRIVATE_H

#include "global.h"

typedef struct Ov96R54Object {
    void *object;
    u8 pad04[0x14];
    s32 state;
    s32 oldX;
    s32 oldY;
    s32 oldZ;
    s32 x;
    s32 y;
    s32 z;
    u8 pad34[4];
    s32 completion;
    u8 pad3C[4];
    u8 mode;
    u8 pad41;
    u16 value;
    u8 pad44[0x4c];
} Ov96R54Object;

typedef struct Ov96R54Course {
    u8 pad00[0x20];
    Ov96R54Object objects[4][3];
} Ov96R54Course;

void ov96_021EB06C(void *, s32, s32, s32 *, s32 *);
void ov96_021EB0A4(void *, u16, u16, s32 *, s32 *);
int ov96_021F3180(u8, u16, u16, u8 *);
void FillBgTilemapRect(void *, u8, u16, u8, u8, u8, u8, u8);
void ScheduleBgTilemapBufferTransfer(void *, u8);

extern const u16 ov96_0221BDD4[][2];
void ov96_021F2834(void *);
void ov96_021F295C(int, void *);
void ov96_021F2984(u32, void *);
void ov96_021F2A00(Ov96R54Course *);
BOOL ov96_021F2A84(Ov96R54Object (*)[3], int);

#endif
