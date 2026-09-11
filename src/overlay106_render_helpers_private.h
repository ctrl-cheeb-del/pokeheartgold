#ifndef OV106_PRIVATE_H
#define OV106_PRIVATE_H
#include "global.h"
extern const u32 ov106_021E6D8C[9];
extern const u32 _021E6D70[3];
extern void Thunk_G3X_Reset(void);
extern void Camera_PushLookAtToNNSGlb(void);
extern void GF3dRender_DrawModel(void *, void *, void *, void *);
extern void RequestSwap3DBuffers(int, int);
extern void Heap_Free(void *);
void ov106_021E5A44(const s16 *);
void ov106_021E5A74(const u16 *);
void ov106_021E5C30(u8 *);
void ov106_021E5BBC(u8 *);
BOOL ov106_021E5CD0(u8 *, u32);
#endif
