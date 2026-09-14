#include "global.h"

#include "heap.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct Ov59MoveTask {
    void *owner;
    u8 direction;
    u8 pad5;
    u8 frames;
    u8 pad7;
    fx32 step;
    s16 x;
    s16 y;
    VecFx32 scale;
    void *sprite;
} Ov59MoveTask;

void Sprite_SetDrawFlag(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_ResetAnimCtrlState(void *);
void Sprite_SetAffineScale(void *, const VecFx32 *);
void *SysTask_CreateOnMainQueue(void (*)(void *, Ov59MoveTask *), Ov59MoveTask *, u32);
void ov59_0223BFC8(void *, Ov59MoveTask *);
void ov59_0223BE44(u8 *, int, u8, int);
void ov59_0223BE70(u8 *, int, int);
