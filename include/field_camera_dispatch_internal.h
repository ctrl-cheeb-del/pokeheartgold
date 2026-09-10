#ifndef PRIVATE_OV01_021FCD2C_H
#define PRIVATE_OV01_021FCD2C_H
#include "global.h"
typedef struct LocalCameraTask {
    int heapId, state, done, mode;
    fx32 initial, amount, target;
    u32 duration;
    fx32 current;
    u32 elapsed;
    fx32 step;
    void *fieldSystem, *camera;
} LocalCameraTask;
void *Heap_AllocAtEnd(int, u32);
void Heap_Free(void *);
fx32 Camera_GetDistance(void *);
void Camera_SetDistance(fx32, void *);
void *SysTask_CreateOnMainQueue(void (*)(void *, void *), void *, int);
void *SysTask_GetData(void *);
void SysTask_Destroy(void *);
void ov01_021FCDA8(void *, LocalCameraTask *);
void ov01_021FCE44(LocalCameraTask *);
void ov01_021FCE5C(LocalCameraTask *);
BOOL ov01_021FCE74(LocalCameraTask *);
void ov01_021FCE34(LocalCameraTask *);
void ov01_021FCD2C(void *, int);
BOOL ov01_021FCD6C(void *);
void ov01_021FCD78(void *);
void ov01_021FCD8C(void *, int, fx32, u32);
void ov01_021FCDBC(LocalCameraTask *);
void ov01_021FCDC4(LocalCameraTask *);
void ov01_021FCDFC(LocalCameraTask *);
#endif
