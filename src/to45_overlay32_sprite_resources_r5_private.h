#ifndef TO45_OV32_R5_PRIVATE_H
#define TO45_OV32_R5_PRIVATE_H

#include "global.h"

#include "filesystem.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "unk_02009D48.h"
#include "unk_0200A090.h"

#define NAME_PICKER_NUM_SPRITES 4

typedef struct NamePickerDataPartial {
    u8 pad000[0x14C];
    SpriteList *spriteList;
    u8 pad150[0x128];
    GF_2DGfxResMan *resMans[4];
    SpriteResource *resObjs[4];
    Sprite *sprites[NAME_PICKER_NUM_SPRITES];
} NamePickerDataPartial;

extern const u8 ov32_0225E178[NAME_PICKER_NUM_SPRITES][4];

void ov32_0225DB1C(SpriteResource **resObjs, GF_2DGfxResMan **resMans, NARC *narc, int charFileId, int plttFileId, int cellFileId, int animFileId, int plttNum, int charId, int plttId, int cellId, int animId);
void ov32_0225DBAC(SpriteResource **resObjs, GF_2DGfxResMan **resMans, SpriteResourcesHeader *header, int priority);
void ov32_0225DC0C(NamePickerDataPartial *data, int index, SpriteResourcesHeader *header, const u8 *spec);
void ov32_0225DC68(NamePickerDataPartial *data, NARC *narc);

typedef char AssertSpriteListOffset[offsetof(NamePickerDataPartial, spriteList) == 0x14C ? 1 : -1];
typedef char AssertResMansOffset[offsetof(NamePickerDataPartial, resMans) == 0x278 ? 1 : -1];
typedef char AssertResObjsOffset[offsetof(NamePickerDataPartial, resObjs) == 0x288 ? 1 : -1];
typedef char AssertSpritesOffset[offsetof(NamePickerDataPartial, sprites) == 0x298 ? 1 : -1];

#endif
