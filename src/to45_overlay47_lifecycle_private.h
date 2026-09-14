#ifndef TO45_OV47_LIFECYCLE_PRIVATE_H
#define TO45_OV47_LIFECYCLE_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

typedef void (*Ov47InitFunc)(void *, void *, void *, void *, int);
typedef BOOL (*Ov47MainFunc)(void *, void *, void *, void *, void *, int);
typedef void (*Ov47ExitFunc)(void *, void *, void *);
typedef struct OverlayManager OverlayManager;
typedef struct Ov47Args {
    void *save;
    void *context;
    int mode;
} Ov47Args;

extern const Ov47InitFunc ov47_02259FB0[];
extern const Ov47MainFunc ov47_02259FA8[];
extern const Ov47ExitFunc _02259FA0[];

Ov47Args *OverlayManager_GetArgs(OverlayManager *);
void *OverlayManager_CreateAndGetData(OverlayManager *, u32, int);
void *OverlayManager_GetData(OverlayManager *);
void OverlayManager_FreeData(OverlayManager *);
void Heap_Create(int, int, u32);
void Heap_Destroy(int);
void *memset(void *, int, u32);
void GF_AssertFail(void);
void Main_SetVBlankIntrCB(void (*)(void *), void *);
void HBlankInterruptDisable(void);
void BeginNormalPaletteFade(int, int, int, int, int, int, int);
BOOL IsPaletteFadeFinished(void);
void sub_0200616C(int);
void ov45_0222A520(void *, int);
BOOL ov45_0222A330(void *);
void ov45_0222A4A8(void *);
BOOL ov45_0222D844(void);
void ov47_02258A14(void *);
void ov47_02258A1C(void *, void *, int);
void ov47_02258A60(void *);
void ov47_02258A80(void *);
void ov47_02258C70(void *, void *, int);
void ov47_02258CC0(void *);
void ov47_02259228(void *, void *, void *, int);
void ov47_02259278(void *, int);
void ov47_022593A0(void *);

BOOL ov47_02258800(OverlayManager *);
BOOL ov47_02258898(OverlayManager *, int *);
BOOL ov47_022589A8(OverlayManager *);

#endif
