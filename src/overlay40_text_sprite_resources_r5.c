#include "overlay40_text_sprite_resources_r5_private.h"

void ov40_0222D55C(u8 *work) {
    struct {
        int i;
        u8 *rows[2];
    } local;
    int j;
    u8 *row0;
    u8 *row1;
    u8 **cursor;

    local.i = 0;
    row0 = work + 0x5fc;
    row1 = work + 0x534;
    do {
        local.rows[0] = row0;
        local.rows[1] = row1;
        j = 0;
        cursor = local.rows;
        while (j < 2) {
            sub_02013938(PTR(*cursor, 0x18));
            TextOBJ_Destroy(PTR(*cursor, 0x14));
            sub_02021B5C(*cursor + 0x1c);
            j++;
            cursor++;
        }
        row0 += 0x28;
        row1 += 0x28;
        local.i++;
    } while (local.i < 5);
}

void ov40_0222D5AC(u8 *entry, u8 *ctx, int variant) {
    s16 position[2];
    TextObjCreateR19 create;
    u32 window[4];
    int resourceId = 0x270f;

    if (variant == 2) {
        resourceId++;
    }
    InitWindow(window);
    AddTextWindowTopLeftCorner(PTR(ctx, 0x10), window, 0x14, 2, 0, 0);
    PTR(entry, 0xc) = sub_02013910(window, 0x6d);
    sub_02021AC8(sub_02013688(window, variant, 0x6d), 1, variant, entry + 0x10);
    ManagedSprite_GetPositionXY(PTR(entry, 4), &position[1], &position[0]);
    create.charData = PTR(ctx, 0x3c);
    create.window = window;
    create.spriteList = SpriteManager_GetSpriteList(PTR(ctx, 8));
    create.paletteProxy = SpriteManager_FindPlttResourceProxy(PTR(ctx, 8), resourceId);
    create.resource = *(void **)PTR(entry, 4);
    create.font = PTR(entry, 0x14);
    create.y = position[1] + 0x24;
    create.x = position[0] - 8;
    create.priority = 3;
    create.palette = 0;
    create.variant = variant;
    create.heapId = 0x6d;
    PTR(entry, 8) = TextOBJ_Create(&create, PTR(entry, 0xc));
    sub_020138E0(PTR(entry, 8), 1);
    RemoveWindow(window);
    TextOBJ_SetSpritesDrawFlag(PTR(entry, 8), 0);
}

void ov40_0222D66C(u8 *entry, u8 *ctx, int msgId) {
    u32 window[4];
    void *string;

    string = NewString_ReadMsgData(PTR(ctx, 0x34), msgId);
    InitWindow(window);
    AddTextWindowTopLeftCorner(PTR(ctx, 0x10), window, 0x14, 2, 0, 0);
    AddTextPrinterParameterizedWithColor(window, 0, string, 0, 0, 0xff, 0x000e0d00, 0);
    TextOBJ_CopyFromBGWindow(PTR(entry, 8), PTR(entry, 0xc), window, 0x6d);
    String_Delete(string);
    RemoveWindow(window);
}

void ov40_0222D6D0(u8 *entry) {
    sub_02013938(PTR(entry, 0xc));
    TextOBJ_Destroy(PTR(entry, 8));
    sub_02021B5C(entry + 0x10);
}

void ov40_0222D6EC(u8 *work, int vram) {
    void *narc = PTR(work, 0x14);
    void *system = PTR(work, 0x18);
    void *manager = PTR(work, 0x1c);

    SpriteSystem_LoadCharResObjFromOpenNarc(system, manager, narc, 0x31, 0, vram, 0x2e94);
    SpriteSystem_LoadCellResObjFromOpenNarc(system, manager, narc, 0x1a, 0, 0x2e94);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system, manager, narc, 0x1b, 0, 0x2e94);
}

void ov40_0222D73C(u8 *work, int vram) {
    void *narc = PTR(work, 0x14);
    void *system = PTR(work, 0x18);
    void *manager = PTR(work, 0x1c);

    SpriteSystem_LoadCharResObjFromOpenNarc(system, manager, narc, 0x7a, 0, vram, 0x2e94);
    SpriteSystem_LoadCellResObjFromOpenNarc(system, manager, narc, 0x7b, 0, 0x2e94);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system, manager, narc, 0x7c, 0, 0x2e94);
}

void ov40_0222D78C(u8 *work, int vram) {
    void *narc = PTR(work, 0x14);
    void *system = PTR(work, 0x18);
    void *manager = PTR(work, 0x1c);

    SpriteSystem_LoadCharResObjFromOpenNarc(system, manager, narc, 0x1e, 0, vram, 0x2e94);
    SpriteSystem_LoadCellResObjFromOpenNarc(system, manager, narc, 0x20, 0, 0x2e94);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system, manager, narc, 0x1f, 0, 0x2e94);
}

void ov40_0222D7DC(u8 *work) {
    SpriteManager_UnloadCharObjById(PTR(work, 0x1c), 0x2e94);
    SpriteManager_UnloadCellObjById(PTR(work, 0x1c), 0x2e94);
    SpriteManager_UnloadAnimObjById(PTR(work, 0x1c), 0x2e94);
}

void *ov40_0222D800(u8 *work, int vram) {
    ManagedSpriteTemplateR19 template;
    void *sprite;

    template.x = 0x80;
    template.y = 0x60;
    template.z = 0;
    template.animation = 0;
    template.drawPriority = 1;
    template.bgPriority = 3;
    template.resIdList[4] = -1;
    template.resIdList[5] = -1;
    template.pal = 0;
    template.vram = vram;
    template.vramTransfer = 0;
    template.resIdList[0] = 0x2e94;
    template.resIdList[2] = 0x2e94;
    template.resIdList[3] = 0x2e94;
    if (vram == 1) {
        template.resIdList[1] = 0x270f;
    } else {
        template.resIdList[1] = 0x2710;
    }
    sprite = SpriteSystem_NewSprite(PTR(work, 0x18), PTR(work, 0x1c), &template);

    ManagedSprite_SetPaletteOverride(sprite, 2);
    ManagedSprite_SetAnim(sprite, 0);
    ManagedSprite_TickFrame(sprite);
    return sprite;
}
