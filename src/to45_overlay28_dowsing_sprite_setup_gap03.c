#include "global.h"

#include "filesystem.h"
#include "overlay_28_helpers_internal.h"
#include "player_avatar.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "unk_0200A090.h"

void ov28_0225D92C(SpriteResource **objects, GF_2DGfxResMan **managers, NARC *narc, int charFile, int commonFile, int cellFile, int animFile, int paletteVram, int charId, int paletteId, int cellId, int animId);
void ov28_0225D9BC(SpriteResource **objects, GF_2DGfxResMan **managers, SpriteResourcesHeader *header, int priority);
void ov28_0225DA1C(DowsingMchn *work, int index, SpriteResourcesHeader *header, const u8 *params);
void ov28_0225DA74(DowsingMchn *work);

extern const u8 ov28_0225EA9A[];
extern const u8 ov28_0225EA9E[];
extern const u8 ov28_0225EAA2[];
extern const u8 ov28_0225EAA6[];

void ov28_0225D9BC(SpriteResource **objects, GF_2DGfxResMan **managers, SpriteResourcesHeader *header, int priority) {
    int charId = GF2DGfxResObj_GetResID(objects[0]);
    int paletteId = GF2DGfxResObj_GetResID(objects[1]);
    int cellId = GF2DGfxResObj_GetResID(objects[2]);
    int animId = GF2DGfxResObj_GetResID(objects[3]);
    CreateSpriteResourcesHeader(header, charId, paletteId, cellId, animId, -1, -1, 0, priority, managers[0], managers[1], managers[2], managers[3], NULL, NULL);
}

void ov28_0225DA1C(DowsingMchn *work, int index, SpriteResourcesHeader *header, const u8 *params) {
    SpriteTemplate template;

    template.spriteList = work->spriteList;
    template.header = header;
    template.position.x = params[0] << FX32_SHIFT;
    template.position.y = (params[1] << FX32_SHIFT) + 0x100000;
    template.position.z = 0;
    template.scale.x = FX32_ONE;
    template.scale.y = FX32_ONE;
    template.scale.z = FX32_ONE;
    template.rotation = 0;
    template.drawPriority = params[2];
    template.whichScreen = (NNS_G2D_VRAM_TYPE)2;
    template.heapID = HEAP_ID_8;
    work->sprites[index] = Sprite_CreateAffine(&template);
    Sprite_SetAnimCtrlSeq(work->sprites[index], params[3]);
}

void ov28_0225DA74(DowsingMchn *work) {
    NARC *narc;
    SpriteResourcesHeader header;

    narc = NARC_New((NarcId)0xe, HEAP_ID_8);
    ov28_0225D92C((SpriteResource **)work->resObjA, work->resMans, narc, 0x46, 7, 0x44, 0x45, 4, 0x1f2, 0x1f2, 0x1f2, 0x1f2);
    NARC_Delete(narc);
    ov28_0225D9BC((SpriteResource **)work->resObjA, work->resMans, &header, 1);
    ov28_0225DA1C(work, 0, &header, ov28_0225EA9A);
    ov28_0225DA1C(work, 1, &header, ov28_0225EA9E);
    ov28_0225DA1C(work, 2, &header, ov28_0225EAA2);
    ov28_0225DA1C(work, 3, &header, ov28_0225EAA6);
    if (PlayerAvatar_CheckRunningShoesLock(FieldSystem_GetPlayerAvatar(work->fieldSystem)) == 0) {
        Sprite_SetAnimCtrlSeq(work->sprites[1], 3);
        Sprite_SetAnimCtrlSeq(work->sprites[2], 11);
    } else {
        Sprite_SetAnimCtrlSeq(work->sprites[1], 4);
        Sprite_SetAnimCtrlSeq(work->sprites[2], 7);
    }
}
