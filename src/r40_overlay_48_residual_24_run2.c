#include "r40_overlay_48_residual_24_private.h"

extern u16 GetWindowBaseTile(void *window);
extern BOOL GF_CreateNewVramTransferTask(u32 type, u32 destination, void *source, u32 size);
extern void *GfGfxLoader_GetScrnDataFromOpenNarc(void *narc, int member, BOOL compressed, void *out, u32 heapId);
extern void *GfGfxLoader_GetPlttDataFromOpenNarc(void *narc, int member, void *out, u32 heapId);
extern void Heap_Free(void *ptr);
extern void GF_AssertFail(void);

void ov48_0225AA38(Ov48R24Animation *anim, u32 index, u8 enabled) {
    if (index >= 3) {
        GF_AssertFail();
    }
    anim->enabled[index] = enabled;
}
