#ifndef PRIVATE_OV01_021F3114_H
#define PRIVATE_OV01_021F3114_H
#include "global.h"
typedef struct LocalSlideState {
    int direction, countdown, state;
    void *fieldSystem, *avatar;
    u32 pad14;
} LocalSlideState;
void *PlayerAvatar_GetMapObject(void *);
int sub_0205F504(void *);
BOOL MetatileBehavior_IsSlideEast(u8);
BOOL MetatileBehavior_IsSlideWest(u8);
BOOL MetatileBehavior_IsSlideNorth(u8);
BOOL MetatileBehavior_IsSlideSouth(u8);
BOOL MetatileBehavior_StopSliding(u8);
void *Heap_AllocAtEnd(int, u32);
void Heap_FreeExplicit(int, void *);
void GF_AssertFail(void);
void PlaySE(int);
void StopSE(int, int);
void *FieldSystem_CreateTask(void *, BOOL (*)(void *), void *);
void *TaskManager_GetEnvironment(void *);
BOOL sub_0205DFC8(void *);
int sub_0206234C(int, int);
void sub_0205DFD4(void *, int);
void PlayerAvatar_SetFacingDirection(void *, int);
void MapObject_SetFlagsBits(void *, u32);
void MapObject_ClearFlagsBits(void *, u32);
void ViridianGymmick_HandleTileAction(void *, u8);
BOOL sub_0205DA34(void *, void *, int);
BOOL ov01_021F3114(void *, void *);
void ov01_021F3170(void *, void *, int);
int ov01_021F31A0(int);
BOOL ov01_021F31CC(void *);
void *ov01_021F3348(u32);
void ov01_021F336C(void *);
#endif
