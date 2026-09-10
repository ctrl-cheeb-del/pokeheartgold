#ifndef POKEHEARTGOLD_FIELD_FOLLOW_SHADOW_INTERNAL_H
#define POKEHEARTGOLD_FIELD_FOLLOW_SHADOW_INTERNAL_H

// Thumb comes from the SOURCE: global.h -> nitro/code16.h -> #pragma thumb on
#include "global.h"

#include "field_effect_model_bank_internal.h"
#include "field_effect_renderer_list_internal.h"
#include "gf_rtc.h"
#include "map_object.h"
#include "overlay_01_021F1348.h"
#include "unk_020689C8.h"
#include "unk_02069660.h"
#include "unk_0206979C.h"

// ---- not declared in any tracked header (see report.md) ----
void sub_020699AC(void *a0, VecFx32 *pos, VecFx32 *scale, MtxFx33 *mtx);
BOOL ov01_021F8F88(LocalMapObject *object);
void ov01_021F8FA0(LocalMapObject *object, VecFx32 *a1);

// The instance block allocated by ov01_021FD41C; 0x1c8 == 0x72 * 4.
typedef struct FollowShadow {
    int unk0;
    int unk4;
    u32 unk8;
    u32 unkC;
    fx32 unk10;
    VecFx32 unk14;
    FieldSystem *unk20;
    SysTask *unk24;
    UnkOv01_021FFECC_sub unk28[4];
    NNSG3dRenderObj unk78[4];
} FollowShadow; // 0x1c8

// The per-renderer work block; 0x20 is the first word of each template below.
typedef struct FollowShadowWork {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    int unkC;
    void *unk10;
    u32 unk14;
    FollowShadow *unk18;
    LocalMapObject *unk1C;
} FollowShadowWork; // 0x20

extern const u32 ov01_02208E90[4];
extern const UnkOv01_02209280 ov01_02208EA0;
extern const fx32 ov01_02208EB4[5];
extern const UnkOv01_02209280 ov01_02208EC8;
extern const UnkOv01_02209280 ov01_02208EDC;
extern const MtxFx33 ov01_02208EF0;
extern const MtxFx33 ov01_02208F14;
extern const VecFx32 ov01_02208F38[5];

FollowShadow *ov01_021FD41C(FieldSystem *fieldSystem);
void ov01_021FD440(FollowShadow *work);
void ov01_021FD458(FollowShadow *work);
void ov01_021FD47C(FollowShadow *work);
void ov01_021FD488(FollowShadow *work, VecFx32 *dest);
int ov01_021FD498(fx32 value);
void ov01_021FD4A4(FollowShadow *work, int timeOfDay);
void ov01_021FD4D0(fx32 *value, fx32 target, fx32 step);
void ov01_021FD4F4(SysTask *task, FollowShadow *work);
void ov01_021FD5CC(FollowShadow *work);
void ov01_021FD60C(FollowShadow *work);
void ov01_021FD624(FollowShadow *work, u32 alpha);
void ov01_021FD640(LocalMapObject *object);
void ov01_021FD684(LocalMapObject *object);
BOOL ov01_021FD6C8(void *a0, FollowShadowWork *work);
void ov01_021FD714(void *a0, FollowShadowWork *work);
void ov01_021FD718(void *a0, FollowShadowWork *work);
BOOL ov01_021FD784(void *a0, FollowShadowWork *work);
void ov01_021FD7D4(void *a0, FollowShadowWork *work);
void ov01_021FD838(void *a0, FollowShadowWork *work);
void ov01_021FD8E8(LocalMapObject *object, int a1);
void ov01_021FD92C(void *a0, FollowShadowWork *work);
void ov01_021FD980(void *a0, FollowShadowWork *work);
void ov01_021FD9CC(u32 direction, VecFx32 *pos);

#endif // POKEHEARTGOLD_FIELD_FOLLOW_SHADOW_INTERNAL_H
