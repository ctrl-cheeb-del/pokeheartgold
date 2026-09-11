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

void ov01_021EA564(AreaLightEntry **p) {
    Heap_FreeExplicit(HEAP_ID_FIELD1, *p);
    *p = NULL;
}

const s8 *ov01_021EA578(const s8 *src, u16 *colorOut, s16 *vecOut) {
    s8 line[256];
    s8 field[256];
    s32 vec[3];
    u16 rgb[3];
    const s8 *p;
    int i;

    src = Ascii_GetDelim(src, line, '\r');
    p = Ascii_GetDelim(line, field, ',');
    if (Ascii_StrToL(field) == 1) {
        for (i = 0; i < 3; i++) {
            p = Ascii_GetDelim(p, field, ',');
            rgb[i] = Ascii_StrToL(field);
        }
        *colorOut = rgb[0] | (rgb[1] << 5) | (rgb[2] << 10);
        for (i = 0; i < 3; i++) {
            p = Ascii_GetDelim(p, field, ',');
            vec[i] = Ascii_StrToL(field);
        }
        vecOut[0] = vec[0];
        vecOut[1] = vec[1];
        vecOut[2] = vec[2];
        if (vecOut[0] > 0x1000) {
            vecOut[0] = 0x1000;
        }
        if (vecOut[0] < -0x1000) {
            vecOut[0] = -0x1000;
        }
        if (vecOut[1] > 0x1000) {
            vecOut[1] = 0x1000;
        }
        if (vecOut[1] < -0x1000) {
            vecOut[1] = -0x1000;
        }
        if (vecOut[2] > 0x1000) {
            vecOut[2] = 0x1000;
        }
        if (vecOut[2] < -0x1000) {
            vecOut[2] = -0x1000;
        }
    } else {
        *colorOut = 0xFFFF;
    }
    return src;
}

const s8 *ov01_021EA668(const s8 *src, u16 *dest) {
    s8 line[256];
    s8 field[256];
    u16 rgb[3];
    const s8 *p;
    int i;

    src = Ascii_GetDelim(src, line, '\r');
    p = line;
    for (i = 0; i < 3; i++) {
        p = Ascii_GetDelim(p, field, ',');
        rgb[i] = Ascii_StrToL(field);
    }
    *dest = rgb[0] | (rgb[1] << 5) | (rgb[2] << 10);
    return src;
}

void LoadAreaOrDungeonLightTxt(u32 archiveID, ModelAttributes *modelAttributes) {
    AreaLightEntry *entries;
    s32 count;
    s32 sec;
    s32 i;
    u32 index;
    AreaLightEntry *entry;

    GF_ASSERT(archiveID < 5);
    count = ov01_021EA3E0(ov01_02206450[archiveID], &entries);
    sec = GF_RTC_TimeToSec() / 2;
    i = 0;
    if (count > 0) {
        entry = entries;
        do {
            if (entry->endTime > (u32)sec) {
                index = i;
                break;
            }
            i++;
            entry++;
        } while (i < count);
    }
    ov01_021EA300(&entries[index], modelAttributes);
    ov01_021EA564(&entries);
}
