#ifndef TO45_OV41_R5_PRIVATE_H
#define TO45_OV41_R5_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "heap.h"
#include "unk_02026E30.h"

typedef struct Ov41R5Config {
    u32 values[4];
} Ov41R5Config;

typedef struct Ov41R5Work {
    u8 pad00[4];
    void *ptr04;
    u8 pad08[8];
    void *ptr10;
    u8 pad14[8];
    void *ptr1C;
    void *ptr20;
    u8 pad24[8];
    void *ptr2C;
    u8 pad30[0x10];
    BgConfig *bgConfig;
    u8 pad44[0x13C];
    NARC *narc;
} Ov41R5Work;

extern const Ov41R5Config ov41_0224BFB4;

void ov41_022467E4(Ov41R5Work *, const Ov41R5Config *);
void ov41_02246CC0(Ov41R5Work *, u32, u32, u32);
void ov41_02246A50(Ov41R5Work *);
void ov41_02246C90(Ov41R5Work *, int);
void ov41_02246A94(Ov41R5Work *);
void ov41_022468FC(Ov41R5Work *);
void ov41_02246CB0(Ov41R5Work *);
void ov41_02246820(Ov41R5Work *);
void ov41_02246A20(Ov41R5Work *);
void ov41_02246D2C(Ov41R5Work *);
void ov41_02246B34(Ov41R5Work *);
void ov41_02246A7C(Ov41R5Work *);
void ov41_02246830(Ov41R5Work *);
void ov41_02246B5C(Ov41R5Work *);
void Thunk_G3X_Reset(void);
void NNS_G2dSetupSoftwareSpriteCamera(void);
void PokepicManager_DrawAll(void *);

void ov41_02246170(Ov41R5Work *);
void ov41_022461D0(Ov41R5Work *);
void ov41_0224621C(Ov41R5Work *);

#endif
