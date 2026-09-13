#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov15_021FDC6C(void *work) {
    ov15_021FDF20(work);
    Camera_Delete(PTR(work, 0x818));
    GF3dRender_DeleteSimpleManager();
}
