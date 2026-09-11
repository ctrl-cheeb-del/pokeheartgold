#include "ov01_21e90c0_opus_partial_internal.h"

Struct021E90C0 *ov01_021E90C0(void);
void ov01_021E90D4(void *ptr);
void ov01_021E90DC(u32 a0, u32 a1, Struct021E90C0 *p);
void ov01_021E95CC(Camera *camera, u8 *state);
void ov01_021E9610(Camera *camera, u8 *state);
int ov01_021E9700(u16 modelId);
BOOL ov01_021E9ABC(TaskManager *taskman);
void ov01_021E9BB8(FieldSystem *fieldSystem, u32 idx);
void ov01_021E9BDC(FieldSystem *fieldSystem, u32 idx);
void ov01_021E9C00(FieldSystem *fieldSystem, u8 idx);
void ov01_021E9C20(FieldSystem *fieldSystem, u32 idx);
u8 *ov01_021E9C30(void);
BOOL ov01_021EA1F4(FieldSystem *fieldSystem, u16 modelId);
void ov01_021EA3B0(NNSG3dResMdl *renderObj);
void LoadAreaOrDungeonLightTxt(u32 archiveID, ModelAttributes *modelAttributes);
BOOL ov01_021E9EEC(TaskManager *taskman);
BOOL ov01_021E9F78(TaskManager *taskman);
const s8 *ov01_021EA668(const s8 *src, u16 *dest);
const s8 *ov01_021EA578(const s8 *src, u16 *colorOut, s16 *vecOut);

/* ---- .rodata / .data --------------------------------------------------- */

extern char ov01_02209868[24] __attribute__((aligned(4)));
extern char ov01_02209880[24] __attribute__((aligned(4)));
extern char ov01_02209850[24] __attribute__((aligned(4)));
extern char ov01_02209820[24] __attribute__((aligned(4)));
extern char ov01_02209838[24] __attribute__((aligned(4)));

extern const u32 ov01_02206408[4];
extern const u32 ov01_02206418[4];
extern const AreaLightTemplate ov01_02206428[2];
extern const char *const ov01_02206450[5];

/* ---- functions --------------------------------------------------------- */

void AreaLightManager_Free(AreaLightManager **areaLightManager) {
    GF_ASSERT(areaLightManager != NULL);
    ov01_021EA564(&(*areaLightManager)->entries);
    Heap_FreeExplicit(HEAP_ID_FIELD1, *areaLightManager);
    *areaLightManager = NULL;
}

void AreaLightManager_UpdateActiveTemplate(AreaLightManager *areaLightManager) {
    s32 sec;
    u32 prevEndTime;
    s32 prev;

    GF_ASSERT(areaLightManager != NULL);
    sec = GF_RTC_TimeToSec() / 2;
    if (areaLightManager->count <= 1) {
        return;
    }
    prev = areaLightManager->activeIndex - 1;
    if (prev >= 0) {
        prevEndTime = areaLightManager->entries[prev].endTime;
    } else {
        prevEndTime = 0;
    }
    if (sec >= (s32)areaLightManager->entries[areaLightManager->activeIndex].endTime || sec < (s32)prevEndTime) {
        areaLightManager->activeIndex++;
        if (areaLightManager->activeIndex >= areaLightManager->count) {
            areaLightManager->activeIndex = 0;
        }
        if (areaLightManager->unk10 != 0) {
            ov01_021EA398(areaLightManager);
        }
    }
}

void ov01_021EA300(AreaLightEntry *entry, ModelAttributes *modelAttributes) {
    int i;
    const s16 *dir;
    const u16 *col;

    i = 0;
    dir = (const s16 *)entry;
    col = (const u16 *)entry;
    for (; i < 4; i++, dir += 3, col++) {
        if (entry->mask & (1 << i)) {
            ov01_021EAAB8(modelAttributes, i, dir[7], dir[8], dir[9]);
            ov01_021EAAE0(modelAttributes, i, col[3]);
        } else {
            ov01_021EAAB8(modelAttributes, i, 0, 0, 0);
            ov01_021EAAE0(modelAttributes, i, 0);
        }
    }
    ov01_021EAAF4(modelAttributes, entry->unk26, 0, 0);
    ov01_021EAB08(modelAttributes, entry->unk28, 1);
    ov01_021EAB1C(modelAttributes, entry->unk2A, 0, 0);
    ov01_021EAB30(modelAttributes, entry->unk2C, 1);
}

void ov01_021EA398(AreaLightManager *areaLightManager) {
    ov01_021EA300(&areaLightManager->entries[areaLightManager->activeIndex], areaLightManager->modelAttributes);
}

void ov01_021EA3B0(NNSG3dResMdl *renderObj) {
    NNSi_G3dModifyMatFlag(renderObj, FALSE, NNS_G3D_MATFLAG_DIFFUSE);
    NNSi_G3dModifyMatFlag(renderObj, FALSE, NNS_G3D_MATFLAG_AMBIENT);
    NNSi_G3dModifyMatFlag(renderObj, FALSE, NNS_G3D_MATFLAG_SPECULAR);
    NNSi_G3dModifyMatFlag(renderObj, FALSE, NNS_G3D_MATFLAG_EMISSION);
}
