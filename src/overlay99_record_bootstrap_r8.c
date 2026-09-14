#include "global.h"

typedef u8 Ov99RecordBootstrapWork;

#define PTR(p, o)    (*(void **)((p) + (o)))
#define U32_AT(p, o) (*(u32 *)((p) + (o)))

extern u8 SDK_OVERLAY_OVY_98_ID;
extern void HandleLoadOverlay(u32, s32);
extern void *OverlayManager_GetArgs(void *);
extern void GF_AssertFail(void);
extern BOOL Heap_Create(u32, u32, u32);
extern void *OverlayManager_CreateAndGetData(void *, u32, u32);
extern void MI_CpuFill8(void *, u8, u32);
extern void ov99_021E6FD0(void *, void *);
extern void ov98_0221F090(void);
extern void ov99_021E695C(void *);
extern void ov99_021E69D8(void *);
extern void *ov98_0221EABC(u32, void *, u32, const void *, u32);
extern void *ov98_0221E5E0(u32, const void *, u32);
extern void ov99_021E6A9C(void *);
extern void ov99_021E6D34(void *);
extern void ResetVisibleHardwareWindows(int);
extern void Main_SetVBlankIntrCB(void (*)(void *), void *);
extern void ov99_021E6938(void *);
extern const u32 ov99_021E9ED0[];

typedef struct Ov99SpriteResourceCounts {
    u32 values[6];
} Ov99SpriteResourceCounts;

extern const Ov99SpriteResourceCounts ov99_021E9DEC;

int ov99_021E677C(void *manager, int *state);

int ov99_021E677C(void *manager, int *state) {
    Ov99RecordBootstrapWork *work;
    void *args;
    Ov99SpriteResourceCounts config;

    HandleLoadOverlay((u32)&SDK_OVERLAY_OVY_98_ID, 2);
    args = OverlayManager_GetArgs(manager);
    if (args == NULL) {
        GF_AssertFail();
    }
    Heap_Create(3, 0x84, 0x30000);
    work = OverlayManager_CreateAndGetData(manager, 0x124, 0x84);
    MI_CpuFill8(work, 0, 0x124);
    U32_AT(work, 0xc) = 0x84;
    ov99_021E6FD0(work, args);
    ov98_0221F090();
    ov99_021E695C(work);
    ov99_021E69D8(work);
    PTR(work, 0x10) = ov98_0221EABC(U32_AT(work, 0xc), PTR(work, 4), 15, ov99_021E9ED0, 0x13a);
    config = ov99_021E9DEC;
    PTR(work, 0x14) = ov98_0221E5E0(U32_AT(work, 0xc), &config, 0x43);
    ov99_021E6A9C(work);
    ov99_021E6D34(work);
    ResetVisibleHardwareWindows(0);
    ResetVisibleHardwareWindows(1);
    Main_SetVBlankIntrCB(ov99_021E6938, work);
    return 1;
}
