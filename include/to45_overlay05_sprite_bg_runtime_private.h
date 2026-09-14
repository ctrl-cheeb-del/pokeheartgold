#ifndef TO45_OV05_R8_PRIVATE_H
#define TO45_OV05_R8_PRIVATE_H

#include "global.h"

typedef struct Ov05R8SpriteSource {
    u32 field00;
    u32 field04;
    u32 field08;
    u32 field0C;
    u32 field10;
    u32 field14;
    u32 field18;
} Ov05R8SpriteSource;

typedef struct Ov05R8SpriteTemplate {
    u16 field00;
    u16 field02;
    u16 field04;
    u16 field06;
    u32 field08;
    u32 field0C;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1C;
    u32 field20;
    u8 pad24[8];
    u32 field2C;
    u32 field30;
} Ov05R8SpriteTemplate;

typedef struct Ov05R8WorkSprites {
    u8 pad000[0x198];
    void *sprites[30];
    u32 count;
} Ov05R8WorkSprites;

typedef struct Ov05R8Root {
    u8 pad00[0x24];
    u32 heapId;
} Ov05R8Root;

typedef struct Ov05R8WorkInit {
    Ov05R8Root *root;
    u8 pad004[0x18C];
    void *spriteSystem;
    void *spriteManager;
} Ov05R8WorkInit;

typedef struct Ov05R8OamConfig {
    u32 values[8];
} Ov05R8OamConfig;

typedef struct Ov05R8TransferConfig {
    u32 values[5];
} Ov05R8TransferConfig;

typedef struct Ov05R8GraphicsModes {
    u32 values[4];
} Ov05R8GraphicsModes;

typedef struct Ov05R8BgTemplate {
    u32 values[7];
} Ov05R8BgTemplate;

extern const Ov05R8OamConfig ov05_0221EBE0;
extern const Ov05R8TransferConfig ov05_0221EAAC;
extern const Ov05R8GraphicsModes ov05_0221EA78;
extern const Ov05R8BgTemplate ov05_0221EB1C;
extern const Ov05R8BgTemplate ov05_0221EB54;
extern const Ov05R8BgTemplate ov05_0221EB70;
extern const Ov05R8BgTemplate ov05_0221EBA8;

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

void *SpriteSystem_NewSprite(void *, void *, const void *);
void Sprite_DeleteAndFreeResources(void *);
void SpriteSystem_FreeResourcesAndManager(void *, void *);
void SpriteSystem_Free(void *);
void Sprite_UpdateAnim(void *, fx32);
void DoScheduledBgGpuUpdates(void *);
void PaletteData_PushTransparentBuffers(void *);
void GF_RunVramTransferTasks(void);
void SpriteSystem_TransferOam(void);
void GF_CreateVramTransferManager(u32, u32);
void *SpriteSystem_Alloc(u32);
void *SpriteManager_New(void *);
void SpriteSystem_Init(void *, const void *, const void *, u32);
void SpriteSystem_InitSprites(void *, void *, u32);
void SpriteSystem_InitManagerWithCapacities(void *, void *, const void *);
void GfGfx_EngineATogglePlanes(u8, u8);
void SetBothScreensModesAndDisable(const void *);
void InitBgFromTemplate(void *, int, const void *, int);
void BgClearTilemapBufferAndCommit(void *, int);
void ScheduleSetBgPosText(void *, int, int, int);
void BgSetPosTextAndCommit(void *, int, int, int);

void ov05_0221CD24(Ov05R8WorkInit *, const void *, u32);
void ov05_0221CDC4(void *, const Ov05R8SpriteSource *);
void ov05_0221CE0C(void *);
void ov05_0221CE50(void *);
void ov05_0221CE88(void *);
void ov05_0221CEB8(void *, int, int);

#endif
