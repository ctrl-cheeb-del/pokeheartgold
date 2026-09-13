#include "global.h"

#include "r40_overlay_105_residual_2_candidate_private.h"

typedef struct State {
    u8 raw[0x1000];
} State;
typedef struct Banks {
    u32 v[10];
} Banks;
extern const Banks ov105_021E5E54;
extern void *OverlayManager_GetData(void *);
extern void Heap_Free(void *);
extern void Camera_Delete(void *);
extern void OverlayManager_FreeData(void *);
extern void GF3dRender_DeleteSimpleManager(void);
extern void Heap_Destroy(int);
extern void GfGfx_SetBanks(const void *);

void ov105_021E5C84(void) {
    Banks banks = ov105_021E5E54;
    GfGfx_SetBanks(&banks);
}
