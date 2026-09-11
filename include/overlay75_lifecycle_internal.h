#ifndef TO40_OVERLAY75_OVERLAY75_LIFECYCLE_INTERNAL_H
#define TO40_OVERLAY75_OVERLAY75_LIFECYCLE_INTERNAL_H

#include "global.h"

#include "heap.h"
#include "main.h"
#include "overlay_manager.h"
#include "pm_string.h"
#include "poke_overlay.h"
#include "system.h"
#include "title_screen.h"
#include "unk_02034B0C.h"
#include "unk_02037C94.h"
#include "unk_020915B0.h"

FS_EXTERN_OVERLAY(OVY_70);

typedef struct Overlay75State {
    OverlayManager *child;
    SaveData *saveData;
    Options *options;
    void *heapAllocation;
    void *expHeap;
    u8 padding_14[0x68];
    u32 onlineLoaded;
    u32 previousSelection;
    u32 padding_84;
    u32 selection;
    u8 padding_8C[0x84];
    String *string110;
    String *string114;
    u32 padding_118;
} Overlay75State;

typedef struct Overlay75Dispatch {
    void *(*createArgs)(Overlay75State *state);
    void (*destroyArgs)(Overlay75State *state);
    const OverlayManagerTemplate *template;
    u32 unloadOnline;
} Overlay75Dispatch;

extern void *_02249BE0;
extern const Overlay75Dispatch ov75_02249904[];

void Sound_SetSceneAndPlayBGM(int scene, int seqNo, int mode);
BOOL LoadOVY38(void);
void UnloadDwcOverlay(void);
void UnloadOVY38(void);
void sub_02034DE0(void);
BOOL sub_02034DB8(void);
void ov00_021ECB40(void);
void ov70_022378DC(void);
int ov00_021EC9D4(void);
void sub_0203A930(int value);
void ov00_021EC294(void *(*alloc)(int, u32, int), void (*free)(int, void *));
void *ov75_02246BF0(int unused, u32 size, int alignment);
void ov75_02246C18(int unused, void *ptr);
BOOL ov75_02246960(OverlayManager *manager);
BOOL ov75_022469D8(OverlayManager *manager, int *step);
BOOL ov75_02246B00(OverlayManager *manager);
void ov75_02246B48(Overlay75State *state);
void ov75_02246B98(Overlay75State *state);

#endif
