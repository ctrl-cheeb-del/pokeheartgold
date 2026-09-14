#ifndef POKEHEARTGOLD_OVERLAY41_ACCESSORY_PORTRAIT_R4_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY41_ACCESSORY_PORTRAIT_R4_PRIVATE_H

#include "global.h"
#include "fashion_case.h"
#include "gf_3d_loader.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "overlay_41.h"
#include "overlay_manager.h"
#include "screen_fade.h"
#include "system.h"
#include "touchscreen.h"

typedef struct SaveFashionMon SaveFashionMon;

typedef struct Ov41AccessoryList {
    SaveFashionMon *mon;
    u8 *items[20];
    int count;
    u32 unused_58;
    u32 background;
} Ov41AccessoryList;

typedef struct Ov41CharEntry {
    void *owner;
    NNSG2dCharacterData *unpacked;
} Ov41CharEntry;

typedef struct Ov41PaletteEntry {
    void *owner;
    NNSG2dPaletteData *unpacked;
    u32 mode;
} Ov41PaletteEntry;

typedef struct Ov41GfxManagers {
    Ov41CharEntry *charEntries;
    u32 unused_04;
    Ov41PaletteEntry *paletteEntry;
    u32 unused_0C;
    GF_2DGfxRawResMan *charManager;
    GF_2DGfxRawResMan *paletteManager;
} Ov41GfxManagers;

typedef struct Ov41Work {
    SaveFashionDataSub *fashionData;
    u32 unused_04;
    int selection;
    int mode;
    void *portrait;
    u8 gfx[0x180 - 0x14];
    NARC *narc;
    u8 tail[0x1A0 - 0x184];
} Ov41Work;

typedef struct Ov41PortraitConfig {
    u32 value;
    u32 x;
    u32 y;
    enum HeapID heapId;
} Ov41PortraitConfig;

BOOL sub_0202BDEC(SaveFashionDataSub *fashionData, int index);
SaveFashionMon *sub_0202BE14(SaveFashionDataSub *fashionData);
u8 *sub_0202BE2C(SaveFashionDataSub *fashionData, int index);
u8 sub_0202BE80(SaveFashionDataSub *fashionData);
u8 sub_0202BEFC(u8 *item);

void ov41_02246130(void);
void ov41_02246150(void);
void ov41_022464AC(Ov41GfxManagers *managers, enum HeapID heapId);
void ov41_02246670(void *gfx, enum HeapID heapId);
void ov41_02246698(void *gfx);
void ov41_022466C8(void *gfx);
void *ov41_0224B530(Ov41PortraitConfig *config, SaveFashionDataSub *fashionData);
void ov41_0224B554(void *portrait);
void ov41_0224B57C(void *portrait);
void ov41_0224BBF0(void *work);
void ov41_0224BC04(Ov41Work *work);
void ov41_0224BCA4(Ov41Work *work);
void ov41_0224BCF0(Ov41Work *work);
void ov41_0224BD8C(Ov41Work *work);
void ov41_0224BDCC(Ov41Work *work);
void ov41_0224BE34(Ov41Work *work);
void ov41_0224BE5C(Ov41Work *work);

void GfGfx_SwapDisplay(void);
void Thunk_G3X_Reset(void);
void NNS_G2dSetupSoftwareSpriteCamera(void);
void RequestSwap3DBuffers(int sortMode, int bufferMode);
void PlaySE(u32 seqNo);

void ov41_0224B8F0(Ov41AccessoryList *list, SaveFashionDataSub *fashionData);
void ov41_0224B938(Ov41Work *work, Ov41GfxManagers *managers, Ov41AccessoryList *list, enum HeapID heapId);
void ov41_0224B958(Ov41Work *work, Ov41GfxManagers *managers, Ov41AccessoryList *list, enum HeapID heapId);

#endif
