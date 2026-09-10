#include "global.h"

typedef struct FieldTextureSlotPrivate {
    void *textureData;
    void *paletteData;
    void *texture;
    void *animation;
    void *record;
    u16 frame;
    u16 timer;
} FieldTextureSlotPrivate;

typedef struct FieldTextureManagerPrivate {
    void *archiveData;
    void *records;
    FieldTextureSlotPrivate slots[16];
    u32 busy;
} FieldTextureManagerPrivate;

extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern void GF_AssertFail(void);
extern void *NARC_New(u32, u32);
extern void NARC_Delete(void *);
extern void *NARC_AllocAndReadWholeMember(void *, u32, u32);
extern void *sub_02020838(void *, u32);
extern void GF_CreateNewVramTransferTask(u32, void *, void *, void *);
extern void *sub_020208DC(void *, void *);
extern void *sub_020209E0(void *, void *);
extern int sprintf(char *, const char *, ...);
extern const char ov01_02209898[];

FieldTextureManagerPrivate *FieldTextureManager_Init(void);
u32 FieldTextureManager_LoadTexture(FieldTextureManagerPrivate *, void *);
s32 ov01_021EB058(FieldTextureManagerPrivate *, void *, u32, void *);
void FieldTextureManager_Free(FieldTextureManagerPrivate *);
void ov01_021EB18C(FieldTextureManagerPrivate *, u32);
void FieldTextureManager_FreeAllSlots(FieldTextureManagerPrivate *);
void FieldTextureManager_Destroy(FieldTextureManagerPrivate *);
