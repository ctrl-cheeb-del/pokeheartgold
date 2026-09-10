#ifndef OV01_021FB4C0_PRIVATE_H
#define OV01_021FB4C0_PRIVATE_H

#include "global.h"

typedef struct HBlankTask HBlankTask;
typedef void (*HBlankTaskCallback)(HBlankTask *, void *);

struct HBlankTask {
    BOOL active;
    void *arg;
    HBlankTaskCallback callback;
};

typedef struct HBlankSystem {
    BOOL running;
    HBlankTask tasks[2];
} HBlankSystem;

extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern BOOL Main_SetHBlankIntrCB(void (*)(void *), void *);
extern void GF_AssertFail(void);

HBlankSystem *HBlankSystem_New(u32);
void HBlankSystem_Delete(HBlankSystem *);
void HBlankSystem_Start(HBlankSystem *);
void HBlankSystem_Stop(HBlankSystem *);
HBlankTask *ov01_021FB530(HBlankSystem *, HBlankTaskCallback, void *);
void ov01_021FB554(HBlankTask *);
void ov01_021FB55C(HBlankSystem *);
void ov01_021FB584(HBlankTask *);
void ov01_021FB594(void *);
void ov01_021FB5B0(HBlankTask *, void *);
HBlankTask *ov01_021FB5B4(HBlankSystem *);

#endif
