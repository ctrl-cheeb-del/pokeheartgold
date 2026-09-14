#ifndef OVERLAY_90_RESIDUAL_16_RESIDUAL_2_PRIVATE_H
#define OVERLAY_90_RESIDUAL_16_RESIDUAL_2_PRIVATE_H
#include "global.h"
extern const u8 ov90_0225C284[];
extern const u8 ov90_0225C324[][12];
extern const u8 ov90_0225C31C[][12];
extern const s16 ov90_0225C276[];
extern const s16 ov90_0225C274[];
s32 ov90_0225A050(u32 count, u8 first, u8 second);
typedef struct Ov90A088Work {
    void *bgConfig;
    u8 buffers[2][0x180];
    void *task;
} Ov90A088Work;
void BgSetPosTextAndCommit(u32, u32, u32, s32);
void *sub_02014A08(void *, void *, void *);
void sub_02014A78(void *, u32);
void Main_SetHBlankIntrCB(void (*)(void *), void *);
void ov90_0225A1B8(void *);
void ov90_0225A088(Ov90A088Work *, void *, void *);
typedef struct Ov90SpritePair {
    u8 pad00[0x10];
    void *sprite1;
    void *sprite2;
    u16 stage;
    u8 pad1A;
    u8 selection;
} Ov90SpritePair;
void Sprite_SetMatrix(void *, VecFx32 *);
void ov90_02259FC8(Ov90SpritePair *, u32);
#endif
