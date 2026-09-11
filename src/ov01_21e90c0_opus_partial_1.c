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

Struct021E90C0 *ov01_021E90C0(void) {
    Struct021E90C0 *ptr = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(Struct021E90C0));
    ptr->unk00 = 0;
    ptr->unk1C = 0;
    return ptr;
}

void ov01_021E90D4(void *ptr) {
    Heap_Free(ptr);
}

void ov01_021E90DC(u32 a0, u32 a1, Struct021E90C0 *p) {
    p->unk04 = a0;
    p->unk08 = a1;
}
