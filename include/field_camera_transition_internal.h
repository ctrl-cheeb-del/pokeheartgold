#ifndef PRIVATE_OV01_021F3378_H
#define PRIVATE_OV01_021F3378_H
#include "global.h"
typedef struct LocalTeleportState {
    void *fieldSystem;
    int *done;
    int state;
    int counter;
    int facing;
} LocalTeleportState;
void *PlayerAvatar_GetMapObject(void *);
void PlayerAvatar_SetFacingDirection(void *, int);
int PlayerAvatar_GetFacingDirection(void *);
void *Heap_AllocAtEnd(int, u32);
void Heap_Free(void *);
void *SysTask_CreateOnMainQueue(void (*)(void *, void *), void *, int);
void SysTask_Destroy(void *);
void ov01_021F33B8(void *, LocalTeleportState *);
void ov01_021F348C(void *, LocalTeleportState *);
void ov01_021F3378(LocalTeleportState *);
void ov01_021F35C4(void *, BOOL, int *);
void sub_0205F990(void *, VecFx32 *);
void sub_0205F9A0(void *, const VecFx32 *);
void ov01_021F92A0(void *);
void PlaySE(int);
void BeginNormalPaletteFade(u32, int, int, int, int, int, int);
BOOL IsPaletteFadeFinished(void);
void MapObject_UnpauseMovement(void *);
#endif
