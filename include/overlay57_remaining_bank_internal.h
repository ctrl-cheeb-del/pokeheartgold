#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
typedef struct Work {
    u8 pad[0x64];
    void *seals;
    u8 pad68[0x18];
    u8 qty[0x51];
    u8 padD1[0x32b];
    u32 f3fc;
    u32 f400;
    u32 f404;
    u32 f408;
} Work;
typedef struct TaskData {
    u32 state;
    void *sprite;
    void *obj;
} TaskData;
u32 SealCaseInventory_GetSealQuantity(void *, u32);
void SealCaseInventory_SetSealQuantity(void *, u32, u32);
void CopyPokemonToPokemon(void *, void *);
u32 GetMonData(void *, u32, void *);
void sub_020196E8(void *, int, int, int);
void ManagedSprite_SetAnimationFrame(void *, u32);
void GF_AssertFail(void);
void sub_02013794(void *, s32 *, s32 *);
void sub_020136B4(void *, s32, s32);
void SysTask_Destroy(void *);
void Heap_Free(void *);
void *Heap_Alloc(u32, u32);
void *SysTask_CreateOnMainQueue(void (*)(void *, TaskData *), TaskData *, u32);
void ov57_0223B7C4(Work *);
void ov57_0223B78C(Work *);
void ov57_0223B7A8(Work *);
void ov57_0223B828(Work *, u32, u32, u32);
void ov57_0223B858(void *, u32);
void ov57_0223B890(void *, s32, s32);
void ov57_0223B8B8(void *, TaskData *);
void ov57_0223B90C(void *, void *);
#endif
