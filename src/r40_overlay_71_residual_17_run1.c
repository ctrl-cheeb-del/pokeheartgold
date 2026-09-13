#include "r40_overlay_71_residual_17_private.h"
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))

void *ov71_022482EC(void *arg) {
    void *p = Heap_Alloc(0x39, 0x16C);
    if (p != NULL) {
        PTR(p, 0) = arg;
        PTR(p, 4) = NULL;
        PTR(p, 0xC0) = ov71_02247384(arg);
        U32(p, 0xD4) = 0;
        U32(p, 0xC4) = 0;
        U32(p, 0xCC) = 0;
        U32(p, 0x160) = 0;
        U32(p, 0x164) = 0;
        U32(p, 0xBC) = MTRandom();
        U32(p, 0xD0) = 0;
        U32(p, 0x168) = 0;
        SysTask_CreateOnVWaitQueue(ov71_02248B60, p, 0);
    }
    return p;
}

void ov71_02248358(void *p) {
    OSIntrMode enabled = OS_DisableInterrupts();
    if (p != NULL) {
        ov71_0224889C(p);
        ov71_022489F8(p);
        ov71_02248B24(p);
        if (PTR(p, 0x160) != NULL) {
            SysTask_Destroy(PTR(p, 0x160));
        }
        if (PTR(p, 0x164) != NULL) {
            ov71_02248E04(PTR(p, 0x164));
        }
        SetMTRNGSeed(U32(p, 0xBC));
        Heap_Free(p);
    }
    OS_RestoreInterrupts(enabled);
}
