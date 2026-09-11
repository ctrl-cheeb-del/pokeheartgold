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

void ov01_021E95CC(Camera *camera, u8 *state) {
    u8 step = 0xC;
    int total = *state * step;
    if (total > 0x60) {
        return;
    }
    if ((u16)total > 0x60) {
        step = (u16)total - 0x60;
    }
    if ((u16)(Camera_GetPerspectiveAngle(camera) - step) != 0) {
        Camera_AdjustPerspectiveAngle(-step, camera);
    }
    (*state)++;
}

void ov01_021E9610(Camera *camera, u8 *state) {
    int total = *state << 4;
    u8 step;
    int angle;
    if (total >= 0x60) {
        return;
    }
    if ((u16)total > 0x60) {
        step = (u16)total - 0x60;
    } else {
        step = 0x10;
    }
    angle = Camera_GetPerspectiveAngle(camera);
    angle += step;
    if ((u16)angle != 0) {
        Camera_AdjustPerspectiveAngle(step, camera);
    }
    (*state)++;
}

int GetDoorSE(FieldSystem *fieldSystem, int modelId, BOOL opening) {
    DoorSEData data;

    NARC_ReadWholeMember(ov01_021FB904(fieldSystem->areaDataManager), modelId, &data);
    if (opening) {
        switch (data.doorType) {
        case 1:
            return SEQ_SE_DP_DOOR_OPEN;
        case 2:
            return SEQ_SE_DP_DOOR10;
        case 3:
            return SEQ_SE_PL_DOOR_OPEN5;
        case 4:
            return SEQ_SE_GS_HIKIDO_OPEN;
        }
        GF_ASSERT(FALSE);
        return SEQ_SE_DP_DOOR_OPEN;
    }
    switch (data.doorType) {
    case 1:
        return SEQ_SE_DP_DOOR_CLOSE2;
    case 2:
        return 0;
    case 3:
        return 0;
    case 4:
        return SEQ_SE_GS_HIKIDO_CLOSE;
    }
    GF_ASSERT(FALSE);
    return SEQ_SE_DP_DOOR_CLOSE2;
}

int ov01_021E9700(u16 modelId) {
    int ret = 0xFFFF;
    switch (modelId) {
    case 0x3D:
        ret = 0;
        break;
    case 0xE0:
        ret = 1;
        break;
    }
    return ret;
}
