#ifndef PRIVATE_OV01_02203E40_H
#define PRIVATE_OV01_02203E40_H
#include "global.h"
typedef struct LocalResource {
    u8 pad00[0x60];
    void *task;
    u32 scale;
} LocalResource;
typedef struct LocalManager {
    void *owner;
    u8 pad04[0x54];
    u32 value58;
    LocalResource *resource;
    void *task;
    u32 scale;
} LocalManager;
typedef struct LocalState {
    int mode;
    u32 data04;
    LocalResource *resource;
    void *mapObject;
    fx32 multiplier;
    VecFx32 direction;
} LocalState;
void *ov01_021F1430(void *, u32, u32, u32);
void ov01_021F1448(void *);
void ov01_021F1AB8(void *, int, int, void *, void *, void *);
void *ov01_021F146C(void *);
void *ov01_021F1468(void *);
void *ov01_021F1450(void *, int);
void MapObject_CopyPositionVector(void *, VecFx32 *);
void Camera_GetLookAtCamPos(VecFx32 *, void *);
void VEC_Subtract(const VecFx32 *, const VecFx32 *, VecFx32 *);
fx32 VEC_Distance(const VecFx32 *, const VecFx32 *);
void VEC_Normalize(const VecFx32 *, VecFx32 *);
int MapObject_GetPriorityPlusValue(void *, int);
void *ov01_021F1620(void *, const void *, const VecFx32 *, void *, void *, int);
void *sub_02068D74(void *);
void *sub_02068D98(void *);
int sub_02068D90(void *);
void VEC_MultAdd(fx32, const VecFx32 *, const VecFx32 *, VecFx32 *);
void sub_02068DA8(void *, const VecFx32 *);
void sub_02068DB8(void *, VecFx32 *);
void GF3dRender_DrawModel(void *, const VecFx32 *, const void *, const VecFx32 *);
LocalManager *ov01_02203E40(void *);
void ov01_02203E64(LocalManager *);
void ov01_02203E74(LocalManager *);
void ov01_02203E94(LocalManager *);
void *ov01_02203EA0(void *);
void ov01_02203F2C(void *, u32);
BOOL ov01_02203F3C(void *, LocalState *);
void ov01_02203F68(void);
void ov01_02203F6C(void *, LocalState *);
void ov01_02203F98(void *, LocalState *);
#endif
