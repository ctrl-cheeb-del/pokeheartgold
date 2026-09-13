#ifndef SOL_R40_FOLLOWUP_OV40_31_6_PRIVATE_H
#define SOL_R40_FOLLOWUP_OV40_31_6_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct SolCtx40 {
    u8 pad[0x330];
    void *hitbox[5];
} SolCtx40;
void ov40_02230964(void *, int);
void ov40_02237008(void *);
void ov40_02236534(void *);
void sub_020878B0(void *, int);
void sub_020879E0(void *, int);
void ov40_0222FB90(void *, int);
int ov40_0222FBB4(void);
void TouchHitboxController_Destroy(void *);
void ov40_0222DAA8(void *);
void ov40_0222D88C(void *);
void BgClearTilemapBufferAndCommit(void *, int);
int ov40_0222DA84(void *, int);
void ov40_0222DD08(void *);
void PaletteData_BlendPalettes(void *, int, int, int, u16);
void ov40_0222BF64(void *, int, int, void *);
void ov40_0222BF80(void *, int);
void sub_020314BC(void *);
void Heap_Free(void *);
#endif
