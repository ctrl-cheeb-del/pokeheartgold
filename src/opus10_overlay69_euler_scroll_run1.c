#include "global.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov69Angle;

typedef struct {
    MtxFx33 mtx;
    u16 id;
    u16 unk_26;
    u8 unk_28[8];
} Ov69GlobeEntry;

typedef struct {
    u8 unk_00[0x54];
} Ov69GlobeModel;

extern const MtxFx33 ov69_021E7728;
extern const MtxFx33 ov69_021E774C;
extern const MtxFx33 ov69_021E7794;

extern int ov69_021E6300(int country);
extern fx32 Camera_GetDistance(void *camera);
extern void Camera_SetDistance(fx32 distance, void *camera);
extern void Camera_PushLookAtToNNSGlb(void);
extern void Thunk_G3X_Reset(void);
extern void RequestSwap3DBuffers(u32 sortMode, u32 bufferMode);
extern void GF3dRender_DrawModel(void *obj, const VecFx32 *translation, const MtxFx33 *rotation, const VecFx32 *scale);
extern void *NewMsgDataFromNarc(u32 kind, u32 narcId, u32 msgId, u32 heapId);
extern void ReadMsgDataIntoString(void *msgData, int msgNo, void *string);
extern void DestroyMsgData(void *msgData);
extern int LocationGmmDatGetGmmNo(int index);

void ov69_021E70A8(MtxFx33 *dst, const Ov69Angle *ang);
void ov69_021E7120(MtxFx33 *dst, const Ov69Angle *ang);
int ov69_021E7198(u8 *work, u32 newKeys, u32 repeatKeys);
int ov69_021E737C(u8 *work);
void ov69_021E7408(u8 *work);
int ov69_021E7520(int country, int msgNo, void *dest, void *src, u32 heapId);

int ov69_021E7198(u8 *work, u32 newKeys, u32 repeatKeys);
int ov69_021E737C(u8 *work);
void ov69_021E7408(u8 *work);
int ov69_021E7520(int country, int msgNo, void *dest, void *src, u32 heapId);

void ov69_021E70A8(MtxFx33 *dst, const Ov69Angle *ang) {
    MtxFx33 mtx;
    MTX_RotY33_(dst, FX_SinIdx((u16)ang->y), FX_CosIdx((u16)ang->y));
    MTX_RotX33_(&mtx, FX_SinIdx((u16)ang->x), FX_CosIdx((u16)ang->x));
    MTX_Concat33(dst, &mtx, dst);
    MTX_RotZ33_(&mtx, FX_SinIdx((u16)ang->z), FX_CosIdx((u16)ang->z));
    MTX_Concat33(dst, &mtx, dst);
}

void ov69_021E7120(MtxFx33 *dst, const Ov69Angle *ang) {
    MtxFx33 mtx;
    MTX_RotY33_(dst, FX_SinIdx((u16)ang->x), FX_CosIdx((u16)ang->x));
    MTX_RotX33_(&mtx, FX_SinIdx((u16)-ang->y), FX_CosIdx((u16)-ang->y));
    MTX_Concat33(dst, &mtx, dst);
    MTX_RotZ33_(&mtx, FX_CosIdx((u16)ang->z), FX_SinIdx((u16)ang->z));
    MTX_Concat33(dst, &mtx, dst);
}
