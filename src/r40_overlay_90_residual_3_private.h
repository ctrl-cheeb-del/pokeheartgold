#ifndef OV90_RESIDUAL_3_PRIVATE_H
#define OV90_RESIDUAL_3_PRIVATE_H
#include "global.h"
typedef struct Ov90Work3 {
    u8 pad[0x10];
    u8 count;
} Ov90Work3;
void SysTask_Destroy(void *);
void ov90_0225A108(void *);
void ov90_0225A340(void *);
void ov90_02259EAC(void *);
void ov90_02259434(void *);
void ov90_02259784(void *);
void ov90_022591D4(void *);
void ov90_02258E10(void *);
void ov90_02259158(void *);
void ov90_02259084(void *);
void Heap_Free(void *);
void ov90_02258938(Ov90Work3 *);
#endif
