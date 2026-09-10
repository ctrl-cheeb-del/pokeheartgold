#include "global.h"

FS_EXTERN_OVERLAY(OVY_0);
FS_EXTERN_OVERLAY(OVY_13);
FS_EXTERN_OVERLAY(OVY_38);

extern BOOL HandleLoadOverlay(u32, u32);
extern void UnloadOverlayByID(u32);
extern void ov13_0221BA00(void *);
extern void OS_ResetSystem(u32);
extern void Heap_Create(u32, u32, u32);
extern void Heap_Destroy(u32);
extern void *OverlayManager_GetArgs(void *);

BOOL LoadDwcOverlay(void);
void UnloadDwcOverlay(void);
BOOL LoadOVY13(void);
void UnloadOVY13(void);
void sub_020915F0(void *, void *);
BOOL LoadOVY38(void);
void UnloadOVY38(void);
BOOL sub_02091634(void *, u32 *);
