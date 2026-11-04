#include "global.h"

#include "constants/pokemon.h"
#include "constants/species.h"

#include "application/pokedex/pokedex_internal.h"
#include "application/pokedex/pokedex_text_util.h"
#include "graphic/zukan_gra.naix"

#include "char_tiles.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "palette.h"
#include "pokedex.h"
#include "pokedex_language.h"
#include "pokedex_language_order.h"
#include "pokemon.h"
#include "pokemon_icon_idx.h"
#include "sprite.h"
#include "sprite_resource_header.h"
#include "sprite_system.h"

// Sprite slots: pokedexApp->sprites[120]. Character / palette / cell / animation resource ids start at 0xC550.
// The list screen lays its icon grid out as two sets of 30 sprites (iconPage selects the one shown).

void PokedexApp_InitSprites(PokedexAppData *pokedexApp) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    PokedexApp_OpenMonIconNarc(pokedexApp);
    PokedexApp_CreateSpriteSystem(pokedexApp);
}

void PokedexApp_FreeSprites(PokedexAppData *pokedexApp) {
    PokedexApp_DeleteAllSprites(pokedexApp);
    PokedexApp_DestroySpriteSystem(pokedexApp);
    PokedexApp_CloseMonIconNarc(pokedexApp);
}

void PokedexApp_TickSprites(PokedexAppData *pokedexApp) {
    u32 i;

    for (i = 0; i < 120; i++) {
        if (pokedexApp->sprites[i]) {
            ManagedSprite_TickFrame(pokedexApp->sprites[i]);
        }
    }
}

void PokedexApp_CreateSpriteSystem(PokedexAppData *pokedexApp) {
    OamManagerParam oamManagerParam;
    OamCharTransferParam oamCharTransferParam;
    SpriteResourceCountsListUnion capacities;

    pokedexApp->spriteSystem = SpriteSystem_Alloc(HEAP_ID_POKEDEX_APP);
    pokedexApp->spriteManager = SpriteManager_New(pokedexApp->spriteSystem);
    oamManagerParam = gPokedexOamManagerParam;
    oamCharTransferParam = gPokedexOamCharTransferParam;
    SpriteSystem_Init(pokedexApp->spriteSystem, &oamManagerParam, &oamCharTransferParam, 32);
    capacities = gSpriteResourceCapacities;
    SpriteSystem_InitSprites(pokedexApp->spriteSystem, pokedexApp->spriteManager, 120);
    SpriteSystem_InitManagerWithCapacities(pokedexApp->spriteSystem, pokedexApp->spriteManager, &capacities);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(pokedexApp->spriteSystem), 0, FX32_CONST(512));
}

void PokedexApp_DestroySpriteSystem(PokedexAppData *pokedexApp) {
    SpriteSystem_FreeResourcesAndManager(pokedexApp->spriteSystem, pokedexApp->spriteManager);
    SpriteSystem_Free(pokedexApp->spriteSystem);
}

void PokedexApp_DeleteSprite(PokedexAppData *pokedexApp, int index) {
    if (pokedexApp->sprites[index]) {
        Sprite_DeleteAndFreeResources(pokedexApp->sprites[index]);
        pokedexApp->sprites[index] = NULL;
    }
}

void PokedexApp_DeleteAllSprites(PokedexAppData *pokedexApp) {
    u32 i;

    for (i = 0; i < 120; i++) {
        PokedexApp_DeleteSprite(pokedexApp, i);
    }
}

// Copies character data straight into the VRAM the sprite's image proxy points at.
void PokedexApp_LoadSpriteCharData(PokedexAppData *pokedexApp, int index, const void *data, u32 size, NNS_G2D_VRAM_TYPE vram) {
    u32 location = NNS_G2dGetImageLocation(Sprite_GetImageProxy(pokedexApp->sprites[index]->sprite), vram);

    DC_FlushRange(data, size);
    if (vram == NNS_G2D_VRAM_TYPE_2DMAIN) {
        GX_LoadOBJ(data, location, size);
    } else {
        GXS_LoadOBJ(data, location, size);
    }
}

void PokedexApp_SetSpriteTranslucent(PokedexAppData *pokedexApp, int index, int enabled) {
    if (enabled == TRUE) {
        ManagedSprite_SetOamMode(pokedexApp->sprites[index], GX_OAM_MODE_XLU);
    } else {
        ManagedSprite_SetOamMode(pokedexApp->sprites[index], GX_OAM_MODE_NORMAL);
    }
}

void PokedexApp_SetSpriteAnim(PokedexAppData *pokedexApp, int index, int anim) {
    ManagedSprite_SetAnimationFrame(pokedexApp->sprites[index], 0);
    ManagedSprite_SetAnim(pokedexApp->sprites[index], anim);
}

int PokedexApp_IsSpriteAnimating(PokedexAppData *pokedexApp, int index) {
    return ManagedSprite_IsAnimated(pokedexApp->sprites[index]);
}

void PokedexApp_SetSpriteVisible(PokedexAppData *pokedexApp, int index, int visible) {
    if (visible == TRUE) {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], TRUE);
    } else {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], FALSE);
    }
}

ManagedSprite *PokedexApp_NewSprite(PokedexAppData *pokedexApp, const ManagedSpriteTemplate *template) {
    if (template->vram == NNS_G2D_VRAM_TYPE_2DMAIN) {
        return SpriteSystem_NewSprite(pokedexApp->spriteSystem, pokedexApp->spriteManager, template);
    }
    return SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, template, FX32_CONST(512));
}

void PokedexApp_MoveSprite(PokedexAppData *pokedexApp, int index, int dx, int dy, int subscreen) {
    s16 x;
    s16 y;

    if (!subscreen) {
        ManagedSprite_GetPositionXY(pokedexApp->sprites[index], &x, &y);
        ManagedSprite_SetPositionXY(pokedexApp->sprites[index], x + dx, y + dy);
    } else {
        ManagedSprite_GetPositionXYWithSubscreenOffset(pokedexApp->sprites[index], &x, &y, FX32_CONST(512));
        ManagedSprite_SetPositionXYWithSubscreenOffset(pokedexApp->sprites[index], x + dx, y + dy, FX32_CONST(512));
    }
}

void PokedexApp_SetSpritePos(PokedexAppData *pokedexApp, int index, s16 x, s16 y, int subscreen) {
    if (!subscreen) {
        ManagedSprite_SetPositionXY(pokedexApp->sprites[index], x, y);
    } else {
        ManagedSprite_SetPositionXYWithSubscreenOffset(pokedexApp->sprites[index], x, y, FX32_CONST(512));
    }
}

void PokedexApp_GetSpritePos(PokedexAppData *pokedexApp, int index, s16 *x, s16 *y, int subscreen) {
    if (!subscreen) {
        ManagedSprite_GetPositionXY(pokedexApp->sprites[index], x, y);
    } else {
        ManagedSprite_GetPositionXYWithSubscreenOffset(pokedexApp->sprites[index], x, y, FX32_CONST(512));
    }
}

void PokedexApp_OpenMonIconNarc(PokedexAppData *pokedexApp) {
    pokedexApp->iconNarc = NARC_New(NARC_poketool_icongra_poke_icon, HEAP_ID_POKEDEX_APP);
}

void PokedexApp_CloseMonIconNarc(PokedexAppData *pokedexApp) {
    NARC_Delete(pokedexApp->iconNarc);
}

// count icon sprites (characters 0xC550 + i), the shared icon palettes, cells and animations
void PokedexApp_LoadMonIconResources(PokedexAppData *pokedexApp, u32 count) {
    u32 i;

    for (i = 0; i < count; i++) {
        SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000076_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, 0xC550 + i);
    }
    SpriteSystem_LoadPaletteBufferFromOpenNarc(pokedexApp->paletteData, PLTTBUF_MAIN_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->iconNarc, GetMonIconPlttNaix(), FALSE, 3, NNS_G2D_VRAM_TYPE_2DMAIN, 0xC550);
    SpriteSystem_LoadCellResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->iconNarc, GetMonIconCell64KNaix(), FALSE, 0xC550);
    SpriteSystem_LoadAnimResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->iconNarc, GetMonIconAnim64KNaix(), FALSE, 0xC550);
}

void PokedexApp_UnloadMonIconResources(PokedexAppData *pokedexApp, u32 count) {
    u32 i;

    for (i = 0; i < count; i++) {
        SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC550 + i);
    }
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC550);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC550);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC550);
}

// 60 icon sprites from slot first on, each with its own character resource
void PokedexApp_CreateMonIconSprites(PokedexAppData *pokedexApp, int first) {
    ManagedSpriteTemplate template;
    ManagedSpriteTemplate base;
    u32 i;
    u8 *slot;

    i = 0;
    slot = (u8 *)pokedexApp + first * sizeof(ManagedSprite *);
    base = gMonIconSpriteTemplate;
    for (; i < 60; i++) {
        template = base;
        template.resIdList[GF_GFX_RES_TYPE_CHAR] = 0xC550 + i;
        *(ManagedSprite **)(slot + offsetof(PokedexAppData, sprites)) = SpriteSystem_NewSprite(pokedexApp->spriteSystem, pokedexApp->spriteManager, &template);
        slot += sizeof(ManagedSprite *);
    }
}

void *PokedexApp_LoadMonIconCharData(PokedexAppData *pokedexApp, u32 species, u32 form, NNSG2dCharacterData **charData) {
    u32 file = GetBattleMonIconNaixEx(species, FALSE, form);
    return GfGfxLoader_GetCharDataFromOpenNarc(pokedexApp->iconNarc, file, FALSE, charData, HEAP_ID_POKEDEX_APP);
}

void PokedexApp_SetMonIconGraphics(PokedexAppData *pokedexApp, const void *data, int index, int palette) {
    int offset = SpriteManager_FindPlttResourceOffset(pokedexApp->spriteManager, 0xC550, NNS_G2D_VRAM_TYPE_2DMAIN);

    PokedexApp_LoadSpriteCharData(pokedexApp, index, data, 0x200, NNS_G2D_VRAM_TYPE_2DMAIN);
    ManagedSprite_SetPaletteOverride(pokedexApp->sprites[index], offset + palette);
}

void PokedexApp_SetMonIcon(PokedexAppData *pokedexApp, u32 species, u32 form, int index) {
    NNSG2dCharacterData *charData;
    void *raw = PokedexApp_LoadMonIconCharData(pokedexApp, species, form, &charData);
    int palette = GetBattleMonIconPaletteEx(species, form, FALSE);

    PokedexApp_SetMonIconGraphics(pokedexApp, charData->pRawData, index, palette);
    Heap_Free(raw);
}

// the sub screen's icon (area screen)
void PokedexApp_SetMonIconSub(PokedexAppData *pokedexApp, u32 species, u32 form, int index) {
    NNSG2dCharacterData *charData;
    void *raw = PokedexApp_LoadMonIconCharData(pokedexApp, species, form, &charData);
    int offset;

    PokedexApp_LoadSpriteCharData(pokedexApp, index, charData->pRawData, 0x200, NNS_G2D_VRAM_TYPE_2DSUB);
    offset = SpriteManager_FindPlttResourceOffset(pokedexApp->spriteManager, 0xC551, NNS_G2D_VRAM_TYPE_2DSUB);
    ManagedSprite_SetPaletteOverride(pokedexApp->sprites[index], offset + GetBattleMonIconPaletteEx(species, form, FALSE));
    Heap_Free(raw);
}

// Shows list entry entry's icon in sprite slot sprite (translucent while only seen).
void PokedexApp_SetListIcon(PokedexAppData *pokedexApp, int entry, int sprite) {
    ManagedSprite **sprites = pokedexApp->sprites;
    u32 form, species;

    ManagedSprite_SetDrawFlag(sprites[sprite], FALSE);
    species = pokedexApp->listEntries[entry].species;
    if (species != SPECIES_NONE) {
        form = Pokedex_GetSeenFormByIdx(pokedexApp->args->pokedex, species, 0);
        species = pokedexApp->listEntries[entry].species;
        if (species == SPECIES_PICHU) {
            if (form == 2) {
                form = 1;
            } else {
                form = 0;
            }
        }
        PokedexApp_SetMonIcon(pokedexApp, species, form, sprite);
        ManagedSprite_SetDrawFlag(sprites[sprite], TRUE);
        if (pokedexApp->listEntries[entry].caughtState == POKEDEXAPP_ENTRY_SEEN) {
            PokedexApp_SetSpriteTranslucent(pokedexApp, sprite, TRUE);
        } else {
            PokedexApp_SetSpriteTranslucent(pokedexApp, sprite, FALSE);
        }
    }
}

// Fills the shown icon set (sprites first + 30 * iconPage) with the 30 entries of the current list page.
void PokedexApp_DrawListIconGrid(PokedexAppData *pokedexApp, int first) {
    u16 i;
    u16 sprite;
    int col;
    int row;

    for (i = 0; i < 30; i++) {
        sprite = first + i + 30 * (pokedexApp->iconPage ^ 1);
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[sprite], FALSE);
    }
    for (i = 0; i < 30; i++) {
        sprite = first + i + 30 * pokedexApp->iconPage;
        PokedexApp_SetListIcon(pokedexApp, i + 15 * pokedexApp->listPage, sprite);
        col = i % 5;
        row = i / 5;
        ManagedSprite_SetPositionXY(pokedexApp->sprites[sprite], 48 + 40 * col, 24 + 40 * row);
    }
}

// Scrolls the icon grid down by dy; icons leaving the bottom wrap to the top, showing the entries of the row above.
void PokedexApp_ScrollListIconsBackward(PokedexAppData *pokedexApp, int first, int dy, u8 row) {
    s16 x, y;
    u16 i, count;
    int sprite;

    count = 0;
    for (i = 0; i < 30; i++) {
        sprite = first + i + pokedexApp->iconPage * 30;
        ManagedSprite_GetPositionXY(pokedexApp->sprites[sprite], &x, &y);
        if (y == 224) {
            y = -16;
            PokedexApp_SetListIcon(pokedexApp, count + (pokedexApp->listPage * 15 - (row + 1) * 5), sprite);
            count++;
        }
        y += dy;
        ManagedSprite_SetPositionXY(pokedexApp->sprites[sprite], x, y);
    }
}

static inline int AddInts(int a, int b) {
    return b + a;
}

// Scrolls the icon grid up by -dy; icons leaving the top wrap to the bottom, showing the entries of the row below.
void PokedexApp_ScrollListIconsForward(PokedexAppData *pokedexApp, int first, int dy, u8 row) {
    struct {
        s16 y, x;
    } pos;

    int sprite, base;
    u16 i, count = 0;

    i = count;
    base = (row + 5) * 5;
    for (; i < 30; i++) {
        sprite = first + i + pokedexApp->iconPage * 30;
        ManagedSprite_GetPositionXY(pokedexApp->sprites[sprite], &pos.x, &pos.y);
        if (pos.y == -16) {
            pos.y = 224;
            PokedexApp_SetListIcon(pokedexApp, count + AddInts(base, 15 * pokedexApp->listPage), sprite);
            count++;
        }
        pos.y += dy;
        ManagedSprite_SetPositionXY(pokedexApp->sprites[sprite], pos.x, pos.y);
    }
}

void PokedexApp_LoadMonPicResources(PokedexAppData *pokedexApp) {
    SpriteSystem_LoadCharResObj(pokedexApp->spriteSystem, pokedexApp->spriteManager, NARC_a_0_0_8, 76, FALSE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC58C);
    SpriteSystem_LoadCharResObj(pokedexApp->spriteSystem, pokedexApp->spriteManager, NARC_a_0_0_8, 76, FALSE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC58D);
    SpriteSystem_LoadPaletteBuffer(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, NARC_a_0_0_8, 75, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 0xC552);
    SpriteSystem_LoadPaletteBuffer(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, NARC_a_0_0_8, 75, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 0xC553);
    SpriteSystem_LoadCellResObj(pokedexApp->spriteSystem, pokedexApp->spriteManager, NARC_a_0_0_8, 77, FALSE, 0xC551);
    SpriteSystem_LoadAnimResObj(pokedexApp->spriteSystem, pokedexApp->spriteManager, NARC_a_0_0_8, 78, FALSE, 0xC551);
}

void PokedexApp_UnloadMonPicResources(PokedexAppData *pokedexApp) {
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC58C);
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC58D);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC552);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC553);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC551);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC551);
}

// a second Pokemon picture pair (characters 0xC58E-0xC58F), sharing the first pair's cells and animations
void PokedexApp_LoadFormsSpriteResources(PokedexAppData *pokedexApp) {
    SpriteSystem_LoadCharResObj(pokedexApp->spriteSystem, pokedexApp->spriteManager, NARC_a_0_0_8, 76, FALSE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC58E);
    SpriteSystem_LoadCharResObj(pokedexApp->spriteSystem, pokedexApp->spriteManager, NARC_a_0_0_8, 76, FALSE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC58F);
    SpriteSystem_LoadPaletteBuffer(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, NARC_a_0_0_8, 75, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 0xC554);
    SpriteSystem_LoadPaletteBuffer(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, NARC_a_0_0_8, 75, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 0xC555);
}

void PokedexApp_UnloadFormsSpriteResources(PokedexAppData *pokedexApp) {
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC58E);
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC58F);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC554);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC555);
}

// The Pokemon picture is a pair of sprites (index, index + 1); PokedexApp_SwapMonPic alternates between them.
void PokedexApp_CreateMonPicSprites(PokedexAppData *pokedexApp, int index) {
    pokedexApp->sprites[index] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gPokedexMonPicSpriteTemplate0, FX32_CONST(512));
    (pokedexApp->sprites + 1)[index] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gPokedexMonPicSpriteTemplate1, FX32_CONST(512));
}

// Decodes the Pokemon picture into sprite's VRAM. mode 0 loads its palette, 1 loads it into the palette buffer
// only, anything else fills the palette with black.
void PokedexApp_LoadMonPicToSprite(PokedexAppData *pokedexApp, int species, u8 form, u8 gender, u8 facing, int sprite, int mode) {
    PokepicTemplate pokepic;
    TileRect rect = gPokedexMonPicSpriteRect;
    void *buffer = Heap_AllocAtEnd(HEAP_ID_POKEDEX_APP, 3200);
    u32 personality, location, palette;
    ManagedSprite **sprites;
    int index;

    MI_CpuClearFast(&pokepic, sizeof(PokepicTemplate));
    if (species == SPECIES_SPINDA && facing == 2) {
        personality = Pokedex_GetSeenSpindaPersonality(pokedexApp->args->pokedex, 0);
    } else {
        personality = 0;
    }
    ((void (*)(PokepicTemplate *, int, u8, u8, u8, u8, u32))GetMonSpriteCharAndPlttNarcIdsEx)(&pokepic, species, gender, facing, 0, form, personality);
    CharTiles_LoadMonRectAsObjFromNarc((NarcId)pokepic.narcID, pokepic.charDataID, HEAP_ID_POKEDEX_APP, &rect, buffer, personality, FALSE, facing, species);
    sprites = pokedexApp->sprites;
    index = sprite;
    location = NNS_G2dGetImageLocation(Sprite_GetImageProxy(sprites[index]->sprite), NNS_G2D_VRAM_TYPE_2DSUB);
    DC_FlushRange(buffer, 3200);
    GXS_LoadOBJ(buffer, location, 3200);
    palette = NNS_G2dGetImagePaletteLocation(Sprite_GetPaletteProxy(sprites[index]->sprite), NNS_G2D_VRAM_TYPE_2DSUB);
    if (mode == 0) {
        GfGfxLoader_GXLoadPal((NarcId)pokepic.narcID, pokepic.palDataID, GF_PAL_LOCATION_SUB_OBJ, (enum GFPalSlotOffset)palette, 32, HEAP_ID_POKEDEX_APP);
        PaletteData_LoadPaletteSlotFromHardware(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, (u16)(palette >> 1), 32);
    } else if (mode == 1) {
        PaletteData_LoadNarc(pokedexApp->paletteData, (NarcId)pokepic.narcID, pokepic.palDataID, HEAP_ID_POKEDEX_APP, PLTTBUF_SUB_OBJ, 32, (u16)(palette >> 1));
    } else {
        PaletteData_FillPaletteInBuffer(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, PLTTSEL_BOTH, 0, (u16)(palette >> 1), (u16)((palette >> 1) + 16));
    }
    Heap_Free(buffer);
}

// Hides the shown picture of the pair at index, shows the other one with species (back facing) or, for no
// species, shows sprite old instead.
void PokedexApp_SwapMonPic(PokedexAppData *pokedexApp, int species, int index, int old) {
    int gender, form;

    ManagedSprite_SetDrawFlag(pokedexApp->sprites[index + pokedexApp->monPicSwap], FALSE);
    pokedexApp->monPicSwap = (u8)(pokedexApp->monPicSwap ^ 1);
    index += pokedexApp->monPicSwap;
    if (!species) {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[old], TRUE);
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], FALSE);
        return;
    }
    ManagedSprite_SetDrawFlag(pokedexApp->sprites[old], FALSE);
    ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], TRUE);
    gender = ((int (*)(Pokedex *, int, u32))Pokedex_SpeciesGetLastSeenGender)(pokedexApp->args->pokedex, species, 0);
    form = Pokedex_GetSeenFormByIdx(pokedexApp->args->pokedex, species, 0);
    if (species == SPECIES_PICHU) {
        if (form == 2) {
            form = 1;
            gender = form;
        } else {
            form = 0;
        }
    }
    PokedexApp_LoadMonPicToSprite(pokedexApp, species, form, gender, 2, index, 0);
}

void PokedexApp_ShowMonPic(PokedexAppData *pokedexApp, int species, int index, int old) {
    PokedexApp_SwapMonPic(pokedexApp, species, index, old);
}

void PokedexApp_LoadFootprintResources(PokedexAppData *pokedexApp) {
    NarcId narcId = Pokefoot_GetNarcId();

    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000077_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC599);
    SpriteSystem_LoadPaletteBuffer(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, narcId, Pokefoot_GetPlttFileId(), FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 0xC55B);
    SpriteSystem_LoadCellResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000078_NCER_lz, TRUE, 0xC558);
    SpriteSystem_LoadAnimResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000079_NANR_lz, TRUE, 0xC558);
}

void PokedexApp_UnloadFootprintResources(PokedexAppData *pokedexApp) {
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC599);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC55B);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC558);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC558);
}

void PokedexApp_CreateFootprintSprite(PokedexAppData *pokedexApp, int index) {
    pokedexApp->sprites[index] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gFootprintSpriteTemplate, FX32_CONST(512));
    ManagedSprite_SetPaletteOverride(pokedexApp->sprites[index], SpriteManager_FindPlttResourceOffset(pokedexApp->spriteManager, 0xC55B, NNS_G2D_VRAM_TYPE_2DSUB));
    ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], FALSE);
}

// No footprint on the foreign-language pages, for an empty entry, a seen-only one or Origin Forme Giratina.
void PokedexApp_UpdateFootprintSprite(PokedexAppData *pokedexApp, u32 species, int entry, int sprite) {
    void *graphics;

    if (pokedexApp->language != GAME_LANGUAGE || species == SPECIES_NONE || pokedexApp->listEntries[entry].caughtState == POKEDEXAPP_ENTRY_SEEN
        || (species == SPECIES_GIRATINA && Pokedex_GetSeenFormByIdx(pokedexApp->args->pokedex, species, 0) == 1)) {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[sprite], FALSE);
    } else {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[sprite], TRUE);
        graphics = PokedexApp_LoadFootprintGraphics(species, HEAP_ID_POKEDEX_APP);
        PokedexApp_LoadSpriteCharData(pokedexApp, sprite, graphics, 128, NNS_G2D_VRAM_TYPE_2DSUB);
        Heap_Free(graphics);
    }
}

// characters 0xC593-0xC596: two type icons, twice (PokedexApp_UpdateTypeIcons alternates between the pairs)
void PokedexApp_LoadTypeIconResources(PokedexAppData *pokedexApp) {
    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000036_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC593);
    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000036_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC594);
    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000036_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC595);
    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000036_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC596);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000035_NCLR, FALSE, 4, NNS_G2D_VRAM_TYPE_2DSUB, 0xC558);
    SpriteSystem_LoadCellResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000033_NCER_lz, TRUE, 0xC555);
    SpriteSystem_LoadAnimResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000034_NANR_lz, TRUE, 0xC555);
}

void PokedexApp_UnloadTypeIconResources(PokedexAppData *pokedexApp) {
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC593);
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC594);
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC595);
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC596);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC558);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC555);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC555);
}

// sprites index, index + 1: first pair (type 1, type 2); index + 2, index + 3: second pair
void PokedexApp_CreateTypeIconSprites(PokedexAppData *pokedexApp, int index) {
    ManagedSpriteTemplate template = gTypeIconSpriteTemplate;

    pokedexApp->sprites[index] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &template, FX32_CONST(512));
    template.resIdList[GF_GFX_RES_TYPE_CHAR] = 0xC595;
    (pokedexApp->sprites + 2)[index] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &template, FX32_CONST(512));
    template.x += 49;
    template.resIdList[GF_GFX_RES_TYPE_CHAR] = 0xC594;
    (pokedexApp->sprites + 1)[index] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &template, FX32_CONST(512));
    template.resIdList[GF_GFX_RES_TYPE_CHAR] = 0xC596;
    (pokedexApp->sprites + 3)[index] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &template, FX32_CONST(512));
}

// Hides the shown type icon pair and draws species' types into the other one (the second icon only for a
// dual-type species).
void PokedexApp_UpdateTypeIcons(PokedexAppData *pokedexApp, u32 species, int entry, int index) {
    int offset;
    u8 swap;
    int form;
    u16 type1;
    u16 type2;

    if (pokedexApp->language != GAME_LANGUAGE || species == SPECIES_NONE || pokedexApp->listEntries[entry].caughtState == POKEDEXAPP_ENTRY_SEEN) {
        index *= 4;
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)pokedexApp->sprites + index), FALSE);
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)&pokedexApp->sprites[1] + index), FALSE);
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)&pokedexApp->sprites[2] + index), FALSE);
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)&pokedexApp->sprites[3] + index), FALSE);
        return;
    }
    if (pokedexApp->typeIconSwap == 0) {
        offset = index * 4;
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)pokedexApp->sprites + offset), FALSE);
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)&pokedexApp->sprites[1] + offset), FALSE);
        index += 2;
    } else {
        offset = index * 4;
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)&pokedexApp->sprites[2] + offset), FALSE);
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)&pokedexApp->sprites[3] + offset), FALSE);
    }
    swap = pokedexApp->typeIconSwap ^ 1;
    pokedexApp->typeIconSwap = swap;
    form = Pokedex_GetSeenFormByIdx(pokedexApp->args->pokedex, species, 0);
    if (species == SPECIES_PICHU) {
        if (form == 2) {
            form = 1;
        } else {
            form = 0;
        }
    }
    type1 = GetMonBaseStat_HandleAlternateForm(species, form, BASE_TYPE1);
    PokedexApp_SetTypeIconGraphics(pokedexApp, index, type1);
    offset = index * 4;
    ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)pokedexApp->sprites + offset), TRUE);
    type2 = GetMonBaseStat_HandleAlternateForm(species, form, BASE_TYPE2);
    if (type2 == 0 || type1 == type2) {
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)&pokedexApp->sprites[1] + offset), FALSE);
    } else {
        PokedexApp_SetTypeIconGraphics(pokedexApp, index + 1, type2);
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)&pokedexApp->sprites[1] + offset), TRUE);
    }
}

void PokedexApp_SetTypeIconGraphics(PokedexAppData *pokedexApp, int index, u32 type) {
    NNSG2dCharacterData *charData;
    void *raw;
    int palette;

    raw = GfGfxLoader_GetCharDataFromOpenNarc(pokedexApp->gfxNarc, PokedexApp_GetTypeIconCharFile(type), TRUE, &charData, HEAP_ID_POKEDEX_APP);
    PokedexApp_LoadSpriteCharData(pokedexApp, index, charData->pRawData, 0x180, NNS_G2D_VRAM_TYPE_2DSUB);
    palette = SpriteManager_FindPlttResourceOffset(pokedexApp->spriteManager, 0xC558, NNS_G2D_VRAM_TYPE_2DSUB);
    ManagedSprite_SetPaletteOverride(pokedexApp->sprites[index], palette + PokedexApp_GetTypeIconPalette(type));
    Heap_Free(raw);
}

// language icons, main screen
void PokedexApp_LoadLanguageIconResources(PokedexAppData *pokedexApp) {
    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000053_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, 0xC597);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(pokedexApp->paletteData, PLTTBUF_MAIN_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000056_NCLR, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 0xC559);
    SpriteSystem_LoadCellResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000054_NCER_lz, TRUE, 0xC556);
    SpriteSystem_LoadAnimResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000055_NANR_lz, TRUE, 0xC556);
}

void PokedexApp_UnloadLanguageIconResources(PokedexAppData *pokedexApp) {
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC597);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC559);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC556);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC556);
}

// language icons, sub screen
void PokedexApp_LoadLanguageIconResourcesSub(PokedexAppData *pokedexApp) {
    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000053_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC598);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000056_NCLR, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 0xC55A);
    SpriteSystem_LoadCellResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000054_NCER_lz, TRUE, 0xC557);
    SpriteSystem_LoadAnimResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000055_NANR_lz, TRUE, 0xC557);
}

void PokedexApp_UnloadLanguageIconResourcesSub(PokedexAppData *pokedexApp) {
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC598);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC55A);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC557);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC557);
}

void PokedexApp_CreateSpriteInSlot(PokedexAppData *pokedexApp, int index, const ManagedSpriteTemplate *template) {
    if (template->vramTransfer == TRUE) {
        pokedexApp->sprites[index] = SpriteSystem_NewSprite(pokedexApp->spriteSystem, pokedexApp->spriteManager, template);
    } else {
        pokedexApp->sprites[index] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, template, FX32_CONST(512));
    }
}

// sprites 18-23: the six foreign-language icons (24 pixels apart from x 124); 8: the current language's icon
void PokedexApp_CreateLanguageIconSprites(PokedexAppData *pokedexApp) {
    ManagedSpriteTemplate template = gLanguageIconSpriteTemplate;
    u32 i;
    int x;

    for (i = 18, x = 0x1B0; i <= 23; i++) {
        template.x = x - 0x134;
        PokedexApp_CreateSpriteInSlot(pokedexApp, i, &template);
        ManagedSprite_SetPaletteOverride(pokedexApp->sprites[i], SpriteManager_FindPlttResourceOffset(pokedexApp->spriteManager, 0xC55A, NNS_G2D_VRAM_TYPE_2DSUB));
        x += 24;
    }
    PokedexApp_CreateSpriteInSlot(pokedexApp, 8, &gPokedexLanguageIconSpriteTemplate);
}

void PokedexApp_UpdateCurrentLanguageIcon(PokedexAppData *pokedexApp, u32 species, int sprite) {
    if (species == SPECIES_NONE || !Pokedex_GetInternationalViewFlag(pokedexApp->args->pokedex)) {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[sprite], FALSE);
    } else {
        PokedexApp_SetSpriteAnim(pokedexApp, sprite, LanguageToDexFlag(pokedexApp->language));
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[sprite], TRUE);
    }
}

// One icon per language species has a Pokedex entry in, right-aligned; the shown language's icon is highlighted.
void PokedexApp_UpdateLanguageIcons(PokedexAppData *pokedexApp, u16 species, int first) {
    s16 index, shown;

    if (!species || !Pokedex_GetInternationalViewFlag(pokedexApp->args->pokedex)) {
        for (index = (s16)first; (u32)index < (u32)first + 6; index++) {
            ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], FALSE);
        }
    } else {
        shown = 0;
        for (index = (s16)(first + 5); (u32)index >= (u32)first; index--) {
            u32 which = index - first;
            int language = DexFlagToLanguage(GetDexLanguageCycleFlag(which));
            if (PokedexApp_HasCaughtInLanguage(pokedexApp, species, language) == TRUE || language == GAME_LANGUAGE) {
                int current = LanguageToDexFlag(pokedexApp->language);
                int flag = GetDexLanguageCycleFlag(which);
                s16 x, y;
                if (flag == current) {
                    PokedexApp_SetSpriteAnim(pokedexApp, index, flag);
                } else {
                    PokedexApp_SetSpriteAnim(pokedexApp, index, flag + 6);
                }
                ManagedSprite_GetPositionXY(pokedexApp->sprites[index], &x, &y);
                ManagedSprite_SetPositionXY(pokedexApp->sprites[index], (s16)(124 + 24 * (5 - shown)), y);
                ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], TRUE);
                shown++;
            } else {
                ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], FALSE);
            }
        }
    }
}

// list cursor and markers, main screen
void PokedexApp_LoadMainObjResources(PokedexAppData *pokedexApp) {
    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000012_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, 0xC590);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(pokedexApp->paletteData, PLTTBUF_MAIN_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000015_NCLR, FALSE, 5, NNS_G2D_VRAM_TYPE_2DMAIN, 0xC556);
    SpriteSystem_LoadCellResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000013_NCER_lz, TRUE, 0xC552);
    SpriteSystem_LoadAnimResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000014_NANR_lz, TRUE, 0xC552);
}

void PokedexApp_UnloadMainObjResources(PokedexAppData *pokedexApp) {
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC590);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC556);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC552);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC552);
}

void PokedexApp_LoadSubObjResources(PokedexAppData *pokedexApp) {
    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000026_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC591);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000032_NCLR, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 0xC557);
    SpriteSystem_LoadCellResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000027_NCER_lz, TRUE, 0xC553);
    SpriteSystem_LoadAnimResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000028_NANR_lz, TRUE, 0xC553);
    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000029_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC592);
    SpriteSystem_LoadCellResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000030_NCER_lz, TRUE, 0xC554);
    SpriteSystem_LoadAnimResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000031_NANR_lz, TRUE, 0xC554);
}

void PokedexApp_UnloadSubObjResources(PokedexAppData *pokedexApp) {
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC591);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC557);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC553);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC553);
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC592);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC554);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC554);
}

// List screen: 0-7 cursor, markers and arrows, 9-10 sub screen frame, 11-12 Pokemon picture, 13 footprint,
// 14-17 type icons, 18-23 language icons, 8 current language, 24-83 the icon grid.
void PokedexApp_SetupListSprites(PokedexAppData *pokedexApp) {
    u16 species;
    int cursor;

    PokedexApp_LoadListSpriteResources(pokedexApp);
    PokedexApp_CreateMonIconSprites(pokedexApp, 24);
    PokedexApp_DrawListIconGrid(pokedexApp, 24);
    PokedexApp_CreateListSprites(pokedexApp);
    if (pokedexApp->nationalDex == 0) {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[0], FALSE);
    } else {
        PokedexApp_SetDexModeSwitchPos(pokedexApp, 0);
    }
    PokedexApp_MoveSpriteToListCursor(pokedexApp, 5);
    PokedexApp_UpdateListPageArrows(pokedexApp, 2, 1);
    PokedexApp_UpdateListScrollbarSize(pokedexApp, 1, 1);
    PokedexApp_SyncListScrollbarToPage(pokedexApp, 1, 1);
    species = PokedexApp_GetCursorSpecies(pokedexApp);
    cursor = PokedexApp_GetListCursorIndex(pokedexApp);
    PokedexApp_CreateMonPicSprites(pokedexApp, 11);
    PokedexApp_ShowMonPic(pokedexApp, species, 11, 10);
    PokedexApp_CreateTypeIconSprites(pokedexApp, 14);
    PokedexApp_UpdateTypeIcons(pokedexApp, species, cursor, 14);
    PokedexApp_CreateFootprintSprite(pokedexApp, 13);
    PokedexApp_UpdateFootprintSprite(pokedexApp, species, cursor, 13);
    PokedexApp_UpdateCaughtMarkSprite(pokedexApp, cursor, 9);
    PokedexApp_CreateLanguageIconSprites(pokedexApp);
    PokedexApp_UpdateLanguageIcons(pokedexApp, species, 18);
    PokedexApp_UpdateCurrentLanguageIcon(pokedexApp, species, 8);
    ManagedSprite_SetDrawFlag(pokedexApp->sprites[8], FALSE);
}

void PokedexApp_LoadListSpriteResources(PokedexAppData *pokedexApp) {
    PokedexApp_LoadMonIconResources(pokedexApp, 60);
    PokedexApp_LoadMainObjResources(pokedexApp);
    PokedexApp_LoadLanguageIconResources(pokedexApp);
    PokedexApp_LoadMonPicResources(pokedexApp);
    PokedexApp_LoadFootprintResources(pokedexApp);
    PokedexApp_LoadTypeIconResources(pokedexApp);
    PokedexApp_LoadSubObjResources(pokedexApp);
    PokedexApp_LoadLanguageIconResourcesSub(pokedexApp);
}

void PokedexApp_CreateListSprites(PokedexAppData *pokedexApp) {
    const ManagedSpriteTemplate *template = gPokedexListSpriteTemplates;
    u32 i;

    for (i = 0; i <= 7; i++) {
        pokedexApp->sprites[i] = SpriteSystem_NewSprite(pokedexApp->spriteSystem, pokedexApp->spriteManager, template);
        template ++;
    }
    ManagedSprite_SetDrawFlag(pokedexApp->sprites[6], FALSE);
    ManagedSprite_SetDrawFlag(pokedexApp->sprites[7], FALSE);
    pokedexApp->sprites[9] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gPokedexListSprite9Template, FX32_CONST(512));
    pokedexApp->sprites[10] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gPokedexListSprite10Template, FX32_CONST(512));
}

void PokedexApp_SetIntlSpritePairVisible(PokedexAppData *pokedexApp, int index, BOOL visible) {
    if (visible == TRUE && Pokedex_GetInternationalViewFlag(pokedexApp->args->pokedex) == TRUE) {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], TRUE);
        ManagedSprite_SetDrawFlag((pokedexApp->sprites + 1)[index], TRUE);
    } else {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], FALSE);
        ManagedSprite_SetDrawFlag((pokedexApp->sprites + 1)[index], FALSE);
    }
}

void PokedexApp_SetIntlSpriteVisible(PokedexAppData *pokedexApp, int index, BOOL visible) {
    if (visible == TRUE && Pokedex_GetInternationalViewFlag(pokedexApp->args->pokedex) == TRUE) {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], TRUE);
    } else {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[index], FALSE);
    }
}

void PokedexApp_SetDexModeSwitchPos(PokedexAppData *pokedexApp, int index) {
    if (pokedexApp->dexMode == 0) {
        ManagedSprite_SetPositionXY(pokedexApp->sprites[index], 144, 128);
    } else {
        ManagedSprite_SetPositionXY(pokedexApp->sprites[index], 112, 128);
    }
}

BOOL PokedexApp_IsTouchOnSprite0(PokedexAppData *pokedexApp, u32 x, u32 y) {
    s16 spriteX;
    s16 spriteY;

    ManagedSprite_GetPositionXY(pokedexApp->sprites[0], &spriteX, &spriteY);
    if (x >= spriteX - 16 && x < spriteX + 16 && y >= spriteY - 16 && y < spriteY + 16) {
        return TRUE;
    }
    return FALSE;
}

void PokedexApp_MoveSpriteX(PokedexAppData *pokedexApp, int index, s16 dx) {
    s16 x;
    s16 y;
    ManagedSprite **sprites = pokedexApp->sprites;

    ManagedSprite_GetPositionXY(sprites[index], &x, &y);
    ManagedSprite_SetPositionXY(sprites[index], x + dx, y);
}

void PokedexApp_SetSpriteX(PokedexAppData *pokedexApp, int index, s16 x) {
    s16 oldX;
    s16 y;
    ManagedSprite **sprites = pokedexApp->sprites;

    ManagedSprite_GetPositionXY(sprites[index], &oldX, &y);
    ManagedSprite_SetPositionXY(sprites[index], x, y);
}

s16 PokedexApp_GetDexModeSwitchX(PokedexAppData *pokedexApp) {
    if (pokedexApp->dexMode == 0) {
        return 144;
    }
    return 112;
}

// Moves sprite onto the icon grid cell of the list cursor.
void PokedexApp_MoveSpriteToListCursor(PokedexAppData *pokedexApp, int sprite) {
    int cursor = pokedexApp->listCursor;
    ManagedSprite **sprites = pokedexApp->sprites;
    int col = cursor % 5;
    int row = cursor / 5;

    ManagedSprite_SetPositionXY(sprites[sprite], col * 40 + 48, row * 40 + 24);
    ManagedSprite_SetDrawFlag(sprites[sprite], TRUE);
}

void PokedexApp_HideListCursor(PokedexAppData *pokedexApp) {
    ManagedSprite_SetDrawFlag(pokedexApp->sprites[5], FALSE);
}

// sprite: up arrow, sprite + 1: down arrow (greyed out on the first / last page)
void PokedexApp_UpdateListPageArrows(PokedexAppData *pokedexApp, int sprite, int mode) {
    if (pokedexApp->listPage == 0) {
        PokedexApp_SetSpriteAnim(pokedexApp, sprite, 7);
    } else {
        PokedexApp_SetSpriteAnim(pokedexApp, sprite, 5);
    }
    if (pokedexApp->listPage == PokedexApp_GetLastListPage(pokedexApp, mode)) {
        PokedexApp_SetSpriteAnim(pokedexApp, sprite + 1, 10);
    } else {
        PokedexApp_SetSpriteAnim(pokedexApp, sprite + 1, 8);
    }
}

void PokedexApp_UpdateListScrollbarSize(PokedexAppData *pokedexApp, int sprite, int mode) {
    PokedexApp_SetSpriteAnim(pokedexApp, sprite, PokedexApp_GetListScrollbarSizeAnim(pokedexApp, mode));
}

// The scrollbar gets shorter as the list gets longer: animations 11-23.
int PokedexApp_GetListScrollbarSizeAnim(PokedexAppData *pokedexApp, int mode) {
    u32 length = PokedexApp_GetListLength(pokedexApp, mode);
    u32 i = 0;

    do {
        if (length <= gListScrollbarSizeThresholds[i]) {
            break;
        }
        i++;
    } while (i < 12);
    return i + 11;
}

u32 PokedexApp_GetListScrollbarLength(PokedexAppData *pokedexApp, int sprite) {
    return (gPokedexScrollbarLengths + 1)[ManagedSprite_GetActiveAnim(pokedexApp->sprites[sprite])];
}

int PokedexApp_GetListScrollbarMinY(PokedexAppData *pokedexApp, int sprite) {
    return (PokedexApp_GetListScrollbarLength(pokedexApp, sprite) >> 1) + 21;
}

int PokedexApp_GetListScrollbarMaxY(PokedexAppData *pokedexApp, int sprite) {
    return 131 - (PokedexApp_GetListScrollbarLength(pokedexApp, sprite) >> 1);
}

BOOL PokedexApp_IsTouchOnListScrollbar(PokedexAppData *pokedexApp, int sprite, u32 x, u32 y) {
    s16 spriteX;
    s16 spriteY;
    u32 length;

    ManagedSprite_GetPositionXY(pokedexApp->sprites[sprite], &spriteX, &spriteY);
    length = PokedexApp_GetListScrollbarLength(pokedexApp, sprite);
    if (x >= spriteX - 11 && x <= spriteX + 11 && y >= spriteY - (length >> 1) && y <= spriteY + (length >> 1)) {
        return TRUE;
    }
    return FALSE;
}

// Moves the scrollbar to y (clamped) and turns to the page it now points at; TRUE when the page changed.
BOOL PokedexApp_DragListScrollbar(PokedexAppData *pokedexApp, int sprite, u32 x, u32 y, int mode) {
    s16 spriteX;
    s16 spriteY;
    u32 min;
    u32 step;
    u32 lastPage;

    ManagedSprite_GetPositionXY(pokedexApp->sprites[sprite], &spriteX, &spriteY);
    min = PokedexApp_GetListScrollbarMinY(pokedexApp, sprite);
    if (y < min) {
        y = min;
    }
    step = PokedexApp_GetListScrollbarMaxY(pokedexApp, sprite);
    if (y > step) {
        y = step;
    }
    ManagedSprite_SetPositionXY(pokedexApp->sprites[sprite], spriteX, y);

    min = PokedexApp_GetListScrollbarMinY(pokedexApp, sprite);
    step = PokedexApp_GetListScrollbarMaxY(pokedexApp, sprite) - min;
    lastPage = PokedexApp_GetLastListPage(pokedexApp, mode);
    step = (step << 8) / lastPage;
    {
        u32 offset = (y - min) << 8;
        u32 i = 0;
        u32 left = i;
        u32 right = i;

        while (i <= lastPage) {
            if (offset >= left && offset < right + step) {
                if (pokedexApp->listPage == i) {
                    break;
                }
                pokedexApp->listPage = i;
                return TRUE;
            }
            left += step;
            right += step;
            i++;
        }
    }
    return FALSE;
}

int PokedexApp_GetListScrollbarYForPage(PokedexAppData *pokedexApp, int page, int sprite, int mode) {
    int min = PokedexApp_GetListScrollbarMinY(pokedexApp, sprite);
    int y = PokedexApp_GetListScrollbarMaxY(pokedexApp, sprite);
    u32 lastPage = PokedexApp_GetLastListPage(pokedexApp, mode);

    if (page != lastPage) {
        u32 step = ((y - min) << 8) / lastPage;
        u32 scaled = step;
        scaled *= page;
        y = min + (scaled >> 8);
    }
    return y;
}

// distance of position from the scrollbar's y, in units of divisor
u32 PokedexApp_GetListScrollbarStepCount(PokedexAppData *pokedexApp, int sprite, u32 position, u32 divisor) {
    s16 x;
    s16 y;

    ManagedSprite_GetPositionXY(pokedexApp->sprites[sprite], &x, &y);
    if (position >= y) {
        return (position - y) / divisor;
    }
    return (y - position) / divisor;
}

void PokedexApp_MoveListScrollbar(PokedexAppData *pokedexApp, int sprite, int dy) {
    s16 x;
    s16 y;

    ManagedSprite_GetPositionXY(pokedexApp->sprites[sprite], &x, &y);
    ManagedSprite_SetPositionXY(pokedexApp->sprites[sprite], x, y + dy);
}

void PokedexApp_SyncListScrollbarToPage(PokedexAppData *pokedexApp, int sprite, int mode) {
    s16 x;
    s16 y;

    ManagedSprite_GetPositionXY(pokedexApp->sprites[sprite], &x, &y);
    ManagedSprite_SetPositionXY(pokedexApp->sprites[sprite], x, PokedexApp_GetListScrollbarYForPage(pokedexApp, pokedexApp->listPage, sprite, mode));
}

// the Poke Ball mark of a caught entry
void PokedexApp_UpdateCaughtMarkSprite(PokedexAppData *pokedexApp, int entry, int sprite) {
    if (pokedexApp->listEntries[entry].caughtState == POKEDEXAPP_ENTRY_CAUGHT) {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[sprite], TRUE);
    } else {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[sprite], FALSE);
    }
}

void PokedexApp_FreeListSprites(PokedexAppData *pokedexApp) {
    PokedexApp_DeleteAllSprites(pokedexApp);
    PokedexApp_UnloadMonIconResources(pokedexApp, 60);
    PokedexApp_UnloadMainObjResources(pokedexApp);
    PokedexApp_UnloadLanguageIconResources(pokedexApp);
    PokedexApp_UnloadMonPicResources(pokedexApp);
    PokedexApp_UnloadFootprintResources(pokedexApp);
    PokedexApp_UnloadTypeIconResources(pokedexApp);
    PokedexApp_UnloadSubObjResources(pokedexApp);
    PokedexApp_UnloadLanguageIconResourcesSub(pokedexApp);
}

void PokedexApp_SetupSearchSprites(PokedexAppData *pokedexApp) {
    PokedexApp_LoadSearchSpriteResources(pokedexApp);
    PokedexApp_CreateSearchSprites(pokedexApp);
}

void PokedexApp_LoadSearchSpriteResources(PokedexAppData *pokedexApp) {
    PokedexApp_LoadMonIconResources(pokedexApp, 60);
    PokedexApp_LoadMainObjResources(pokedexApp);
    PokedexApp_LoadLanguageIconResources(pokedexApp);

    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000072_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, 0xC5A0);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(pokedexApp->paletteData, PLTTBUF_MAIN_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000075_NCLR, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 0xC561);
    SpriteSystem_LoadCellResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000073_NCER_lz, TRUE, 0xC55E);
    SpriteSystem_LoadAnimResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000074_NANR_lz, TRUE, 0xC55E);

    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000072_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC59F);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000075_NCLR, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 0xC560);
    SpriteSystem_LoadCellResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000073_NCER_lz, TRUE, 0xC55D);
    SpriteSystem_LoadAnimResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000074_NANR_lz, TRUE, 0xC55D);

    SpriteSystem_LoadCharResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000023_NCGR_lz, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 0xC59E);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000032_NCLR, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 0xC55F);
    SpriteSystem_LoadCellResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000024_NCER_lz, TRUE, 0xC55C);
    SpriteSystem_LoadAnimResObjFromOpenNarc(pokedexApp->spriteSystem, pokedexApp->spriteManager, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000025_NANR_lz, TRUE, 0xC55C);
}

void PokedexApp_UnloadSearchSpriteResources(PokedexAppData *pokedexApp) {
    PokedexApp_UnloadMonIconResources(pokedexApp, 60);
    PokedexApp_UnloadMainObjResources(pokedexApp);
    PokedexApp_UnloadLanguageIconResources(pokedexApp);
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC59F);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC560);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC55D);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC55D);
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC5A0);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC561);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC55E);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC55E);
}

// Search result entry, sub screen: 44-45 frame, 46-47 Pokemon picture, 48 footprint, 49-52 type icons,
// 53-58 language icons (all hidden at first).
void PokedexApp_CreateSearchEntrySprites(PokedexAppData *pokedexApp) {
    ManagedSpriteTemplate template;
    u32 i;
    int x;

    PokedexApp_LoadMonPicResources(pokedexApp);
    PokedexApp_LoadFootprintResources(pokedexApp);
    PokedexApp_LoadTypeIconResources(pokedexApp);
    PokedexApp_LoadSubObjResources(pokedexApp);
    PokedexApp_LoadLanguageIconResourcesSub(pokedexApp);
    pokedexApp->sprites[44] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gPokedexListSprite9Template, FX32_CONST(512));
    pokedexApp->sprites[45] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gPokedexListSprite10Template, FX32_CONST(512));
    PokedexApp_CreateMonPicSprites(pokedexApp, 46);
    PokedexApp_CreateFootprintSprite(pokedexApp, 48);
    PokedexApp_CreateTypeIconSprites(pokedexApp, 49);
    template = gLanguageIconSpriteTemplate;
    for (i = 53, x = 1272; i <= 58; i++) {
        template.x = x - 1148;
        PokedexApp_CreateSpriteInSlot(pokedexApp, i, &template);
        ManagedSprite_SetPaletteOverride(pokedexApp->sprites[i], SpriteManager_FindPlttResourceOffset(pokedexApp->spriteManager, 0xC55A, NNS_G2D_VRAM_TYPE_2DSUB));
        x += 24;
    }
    for (i = 44; i <= 58; i++) {
        ManagedSprite_SetDrawFlag(pokedexApp->sprites[i], FALSE);
        ManagedSprite_SetPriority(pokedexApp->sprites[i], 2);
    }
}

void PokedexApp_UnloadSearchEntryResources(PokedexAppData *pokedexApp) {
    PokedexApp_UnloadMonPicResources(pokedexApp);
    PokedexApp_UnloadFootprintResources(pokedexApp);
    PokedexApp_UnloadTypeIconResources(pokedexApp);
    PokedexApp_UnloadSubObjResources(pokedexApp);
    PokedexApp_UnloadLanguageIconResourcesSub(pokedexApp);
}

// Search screen: 0-25 menu sprites, 26-27 and 43 sub screen, 28 body type icon, 29-42 body type choices
// (5 per row), 59-118 icon grid.
void PokedexApp_CreateSearchSprites(PokedexAppData *pokedexApp) {
    u16 i;
    ManagedSpriteTemplate template;

    for (i = 0; i <= 25; i++) {
        pokedexApp->sprites[i] = SpriteSystem_NewSprite(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gPokedexSearchSpriteTemplates[i]);
        PokedexApp_SetSpriteVisible(pokedexApp, i, FALSE);
    }
    pokedexApp->sprites[43] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gPokedexSearchSprite43Template, FX32_CONST(512));
    PokedexApp_SetSpriteVisible(pokedexApp, 43, FALSE);
    pokedexApp->sprites[26] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gPokedexSearchSprite26Template, FX32_CONST(512));
    pokedexApp->sprites[27] = SpriteSystem_NewSpriteWithYOffset(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gPokedexSearchSprite27Template, FX32_CONST(512));
    PokedexApp_SetSpriteVisible(pokedexApp, 27, FALSE);
    template = gPokedexBodyTypeIconSpriteTemplate;
    for (i = 28; i <= 42; i++) {
        if (i == 28) {
            template.x = 224;
            template.y = 72;
            pokedexApp->sprites[i] = SpriteSystem_NewSprite(pokedexApp->spriteSystem, pokedexApp->spriteManager, &template);
            if (pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_BODY_TYPE] == DEX_SEARCH_BODYTYPE_ALL) {
                PokedexApp_SetSpriteVisible(pokedexApp, i, FALSE);
            } else {
                PokedexApp_SetSpriteAnim(pokedexApp, i, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_BODY_TYPE]);
            }
        } else {
            u16 choice = i - 29;
            template.x = 32 + 48 * (choice % 5);
            template.y = 56 + 40 * (choice / 5);
            pokedexApp->sprites[i] = SpriteSystem_NewSprite(pokedexApp->spriteSystem, pokedexApp->spriteManager, &template);
            PokedexApp_SetSpriteAnim(pokedexApp, i, choice);
            PokedexApp_SetSpriteVisible(pokedexApp, i, FALSE);
        }
    }
    PokedexApp_CreateMonIconSprites(pokedexApp, 59);
}

void PokedexApp_FreeSearchSprites(PokedexAppData *pokedexApp) {
    PokedexApp_DeleteAllSprites(pokedexApp);
    PokedexApp_UnloadSearchSpriteResources(pokedexApp);
}

void PokedexApp_FreeSprites26And27(PokedexAppData *pokedexApp) {
    PokedexApp_DeleteSprite(pokedexApp, 26);
    PokedexApp_DeleteSprite(pokedexApp, 27);
    SpriteManager_UnloadCharObjById(pokedexApp->spriteManager, 0xC59E);
    SpriteManager_UnloadPlttObjById(pokedexApp->spriteManager, 0xC55F);
    SpriteManager_UnloadCellObjById(pokedexApp->spriteManager, 0xC55C);
    SpriteManager_UnloadAnimObjById(pokedexApp->spriteManager, 0xC55C);
}

// body type 14 is "any": no icon
void PokedexApp_UpdateBodyTypeSprite(PokedexAppData *pokedexApp) {
    if (pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_BODY_TYPE] == DEX_SEARCH_BODYTYPE_ALL) {
        PokedexApp_SetSpriteVisible(pokedexApp, 28, FALSE);
    } else {
        PokedexApp_SetSpriteVisible(pokedexApp, 28, TRUE);
        PokedexApp_SetSpriteAnim(pokedexApp, 28, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_BODY_TYPE]);
    }
}

void PokedexApp_HideBodyTypeOptionSprites(PokedexAppData *pokedexApp, int hideIcon) {
    u32 i;

    if (hideIcon == TRUE) {
        PokedexApp_SetSpriteVisible(pokedexApp, 28, FALSE);
    }
    for (i = 29; i <= 42; i++) {
        PokedexApp_SetSpriteVisible(pokedexApp, i, FALSE);
    }
}

// TRUE: body type icon only (search menu); FALSE: the body type page with all choices
void PokedexApp_SetBodyTypeSpriteLayout(PokedexAppData *pokedexApp, int menu) {
    u32 i;

    PokedexApp_UpdateBodyTypeSprite(pokedexApp);
    if (menu == TRUE) {
        ManagedSprite_SetPositionXY(pokedexApp->sprites[28], 224, 72);
        for (i = 29; i <= 42; i++) {
            PokedexApp_SetSpriteVisible(pokedexApp, i, FALSE);
        }
    } else {
        ManagedSprite_SetPositionXY(pokedexApp->sprites[28], 152, 20);
        for (i = 29; i <= 42; i++) {
            PokedexApp_SetSpriteVisible(pokedexApp, i, TRUE);
        }
    }
}

// sprites 1-16: the height / weight page's slider
void PokedexApp_SetSliderSpritesVisible(PokedexAppData *pokedexApp, int visible) {
    u32 i;

    for (i = 1; i <= 16; i++) {
        PokedexApp_SetSpriteVisible(pokedexApp, i, visible);
    }
}

// Places the slider's two handles (5: max, 11: min) and their digits (6-10, 12-16).
void PokedexApp_UpdateSliderSprites(PokedexAppData *pokedexApp, u32 min, u32 max, int weight) {
    if (!weight) {
        PokedexApp_SetHeightSliderX(pokedexApp, PokedexApp_SliderValueToX(pokedexApp, max), 5, TRUE);
        PokedexApp_SetHeightSliderX(pokedexApp, PokedexApp_SliderValueToX(pokedexApp, min), 11, FALSE);
        PokedexApp_DrawHeightDigits(pokedexApp, 6, pokedexApp->sliderValues[max].height);
        PokedexApp_DrawHeightDigits(pokedexApp, 12, pokedexApp->sliderValues[min].height);
    } else {
        PokedexApp_SetWeightSliderX(pokedexApp, PokedexApp_SliderValueToX(pokedexApp, max), 5, TRUE);
        PokedexApp_SetWeightSliderX(pokedexApp, PokedexApp_SliderValueToX(pokedexApp, min), 11, FALSE);
        PokedexApp_DrawWeightDigits(pokedexApp, 6, pokedexApp->sliderValues[max].weight);
        PokedexApp_DrawWeightDigits(pokedexApp, 12, pokedexApp->sliderValues[min].weight);
    }
    PokedexApp_UpdateSliderLimitSprites(pokedexApp, max, 1);
    PokedexApp_UpdateSliderLimitSprites(pokedexApp, min, 3);
}

// page: 0 search menu, 1 body type, 2 height, 3 weight, others hide the page sprites
void PokedexApp_UpdateSearchSprites(PokedexAppData *pokedexApp, int page) {
    switch (page) {
    case 0:
        PokedexApp_SetBodyTypeSpriteLayout(pokedexApp, TRUE);
        PokedexApp_SetSliderSpritesVisible(pokedexApp, FALSE);
        break;
    case 1:
        PokedexApp_SetBodyTypeSpriteLayout(pokedexApp, FALSE);
        PokedexApp_SetSliderSpritesVisible(pokedexApp, FALSE);
        break;
    case 2:
        PokedexApp_HideBodyTypeOptionSprites(pokedexApp, TRUE);
        PokedexApp_SetSliderSpritesVisible(pokedexApp, TRUE);
        PokedexApp_SetSpriteAnim(pokedexApp, 5, 67);
        PokedexApp_SetSpriteAnim(pokedexApp, 11, 68);
        PokedexApp_UpdateSliderSprites(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_HEIGHT_MIN], pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_HEIGHT_MAX], FALSE);
        break;
    case 3:
        PokedexApp_HideBodyTypeOptionSprites(pokedexApp, TRUE);
        PokedexApp_SetSliderSpritesVisible(pokedexApp, TRUE);
        PokedexApp_SetSpriteAnim(pokedexApp, 5, 41);
        PokedexApp_SetSpriteAnim(pokedexApp, 11, 42);
        PokedexApp_UpdateSliderSprites(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_WEIGHT_MIN], pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_WEIGHT_MAX], TRUE);
        break;
    default:
        PokedexApp_HideBodyTypeOptionSprites(pokedexApp, TRUE);
        PokedexApp_SetSliderSpritesVisible(pokedexApp, FALSE);
        break;
    }
}

// Moves handle sprite index (and its four digits) to x, clamped to 52-204; x 0 keeps the current position.
// moveCursor also moves the cursor (sprite 0).
void PokedexApp_SetHeightSliderX(PokedexAppData *pokedexApp, int x, int index, int moveCursor) {
    s16 curX;
    s16 curY;

    ManagedSprite_GetPositionXY(pokedexApp->sprites[index], &curX, &curY);
    if (x == 0) {
        x = curX;
    } else if ((u32)x < 52) {
        x = 52;
    } else if ((u32)x > 204) {
        x = 204;
    }

    ManagedSprite_GetPositionXY(pokedexApp->sprites[index], &curX, &curY);
    ManagedSprite_SetPositionXY(pokedexApp->sprites[index], x, curY);
    ManagedSprite_GetPositionXY((pokedexApp->sprites + 1)[index], &curX, &curY);
    ManagedSprite_SetPositionXY((pokedexApp->sprites + 1)[index], x - 20, curY);
    ManagedSprite_SetPositionXY((pokedexApp->sprites + 2)[index], x - 12, curY);
    ManagedSprite_SetPositionXY((pokedexApp->sprites + 3)[index], x + 4, curY);
    ManagedSprite_SetPositionXY((pokedexApp->sprites + 4)[index], x + 12, curY);

    if (moveCursor == TRUE) {
        ManagedSprite_GetPositionXY(pokedexApp->sprites[0], &curX, &curY);
        ManagedSprite_SetPositionXY(pokedexApp->sprites[0], x, curY);
    }
}

// as PokedexApp_SetHeightSliderX, with five digits
void PokedexApp_SetWeightSliderX(PokedexAppData *pokedexApp, int x, int index, int moveCursor) {
    s16 curX;
    s16 curY;

    ManagedSprite_GetPositionXY(pokedexApp->sprites[index], &curX, &curY);
    if (x == 0) {
        x = curX;
    } else if ((u32)x < 52) {
        x = 52;
    } else if ((u32)x > 204) {
        x = 204;
    }

    ManagedSprite_GetPositionXY(pokedexApp->sprites[index], &curX, &curY);
    ManagedSprite_SetPositionXY(pokedexApp->sprites[index], x, curY);
    ManagedSprite_GetPositionXY((pokedexApp->sprites + 1)[index], &curX, &curY);
    ManagedSprite_SetPositionXY((pokedexApp->sprites + 1)[index], x - 20, curY);
    ManagedSprite_SetPositionXY((pokedexApp->sprites + 2)[index], x - 12, curY);
    ManagedSprite_SetPositionXY((pokedexApp->sprites + 3)[index], x - 4, curY);
    ManagedSprite_SetPositionXY((pokedexApp->sprites + 4)[index], x + 4, curY);
    ManagedSprite_SetPositionXY((pokedexApp->sprites + 5)[index], x + 20, curY);

    if (moveCursor == TRUE) {
        ManagedSprite_GetPositionXY(pokedexApp->sprites[0], &curX, &curY);
        ManagedSprite_SetPositionXY(pokedexApp->sprites[0], x, curY);
    }
}

// height in decimetres, shown as feet and inches (999: the slider's end, 99'00")
void PokedexApp_DrawHeightDigits(PokedexAppData *pokedexApp, int index, u16 height) {
    u32 inches;
    u32 feet;
    u32 remainder;

    if (height == 999) {
        inches = 1188;
    } else {
        inches = (((u32)10000 * height) / 254 + 5) / 10;
    }

    feet = inches / 12;
    remainder = inches % 12;
    if (feet >= 10) {
        PokedexApp_SetSpriteAnim(pokedexApp, index, feet / 10 + 43);
        PokedexApp_SetSpriteVisible(pokedexApp, index, TRUE);
    } else {
        PokedexApp_SetSpriteVisible(pokedexApp, index, FALSE);
    }
    PokedexApp_SetSpriteAnim(pokedexApp, index + 1, feet % 10 + 43);
    PokedexApp_SetSpriteVisible(pokedexApp, index + 1, TRUE);
    PokedexApp_SetSpriteAnim(pokedexApp, index + 2, remainder / 10 + 43);
    PokedexApp_SetSpriteVisible(pokedexApp, index + 2, TRUE);
    PokedexApp_SetSpriteAnim(pokedexApp, index + 3, remainder % 10 + 43);
    PokedexApp_SetSpriteVisible(pokedexApp, index + 3, TRUE);
    PokedexApp_SetSpriteVisible(pokedexApp, index + 4, FALSE);
}

#pragma opt_strength_reduction off

// weight in hectograms, shown in tenths of pounds over five digits, leading zeroes hidden (9999: 9999.0 lbs)
void PokedexApp_DrawWeightDigits(PokedexAppData *pokedexApp, int index, u32 weight) {
    u32 shown, i, divisor, digit;

    if (weight == 9999) {
        weight = 99990;
    } else {
        weight = (weight * 220462 + 50000) / 100000;
    }
    shown = FALSE;
    divisor = 10000;
    for (i = shown; i < 5; i++) {
        digit = weight / divisor;
        if (digit != 0 || shown == TRUE) {
            shown = TRUE;
            PokedexApp_SetSpriteAnim(pokedexApp, index + i, digit + 43);
            PokedexApp_SetSpriteVisible(pokedexApp, index + i, TRUE);
        } else {
            PokedexApp_SetSpriteVisible(pokedexApp, index + i, FALSE);
        }
        weight %= divisor;
        divisor /= 10;
        if (i == 2) {
            shown = TRUE;
        }
    }
}

#pragma opt_strength_reduction reset

// the handle's arrows: no left arrow at the minimum, no right arrow at the maximum (152)
void PokedexApp_UpdateSliderLimitSprites(PokedexAppData *pokedexApp, u32 value, int index) {
    if (value == 0) {
        PokedexApp_SetSpriteAnim(pokedexApp, index, 58);
        PokedexApp_SetSpriteAnim(pokedexApp, index + 1, 53);
    } else if (value == 152) {
        PokedexApp_SetSpriteAnim(pokedexApp, index, 56);
        PokedexApp_SetSpriteAnim(pokedexApp, index + 1, 55);
    } else {
        PokedexApp_SetSpriteAnim(pokedexApp, index, 56);
        PokedexApp_SetSpriteAnim(pokedexApp, index + 1, 53);
    }
}

u32 PokedexApp_GetSliderValue(PokedexAppData *pokedexApp, int index) {
    s16 x;
    s16 y;
    ManagedSprite *sprite = pokedexApp->sprites[index];

    ManagedSprite_GetPositionXY(sprite, &x, &y);
    return x - 52;
}

int PokedexApp_SliderValueToX(PokedexAppData *pokedexApp, int value) {
    return value + 52;
}

void PokedexApp_ShowReturningDexModeSwitch(PokedexAppData *pokedexApp) {
    s16 x;
    s16 y;

    if (pokedexApp->nationalDex == 1) {
        PokedexApp_SetSpriteVisible(pokedexApp, 17, TRUE);
        PokedexApp_SetDexModeSwitchPos(pokedexApp, 17);
        ManagedSprite_GetPositionXY(pokedexApp->sprites[17], &x, &y);
        ManagedSprite_SetPositionXY(pokedexApp->sprites[17], x - 288, y);
    }
}

void PokedexApp_MoveReturningDexModeSwitch(PokedexAppData *pokedexApp, int dx) {
    s16 x;
    s16 y;

    ManagedSprite_GetPositionXY(pokedexApp->sprites[17], &x, &y);
    ManagedSprite_SetPositionXY(pokedexApp->sprites[17], x + dx, y);
}

// 44-58: the search result entry's sprites; 43: the body type icon on the sub screen
void PokedexApp_SetSearchEntrySpritesVisible(PokedexAppData *pokedexApp, BOOL visible) {
    u32 i;

    if (visible == TRUE) {
        for (i = 44; i <= 58; i++) {
            PokedexApp_SetSpriteVisible(pokedexApp, i, TRUE);
        }
        PokedexApp_SetSpriteVisible(pokedexApp, 43, FALSE);
    } else {
        for (i = 44; i <= 58; i++) {
            PokedexApp_SetSpriteVisible(pokedexApp, i, FALSE);
        }
        PokedexApp_UpdateSearchBodyTypeIcon(pokedexApp);
    }
}

void PokedexApp_UpdateSearchBodyTypeIcon(PokedexAppData *pokedexApp) {
    if (pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_BODY_TYPE] == DEX_SEARCH_BODYTYPE_ALL) {
        PokedexApp_SetSpriteVisible(pokedexApp, 43, FALSE);
    } else {
        PokedexApp_SetSpriteVisible(pokedexApp, 43, TRUE);
        PokedexApp_SetSpriteAnim(pokedexApp, 43, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_BODY_TYPE]);
    }
}

void PokedexApp_MoveSearchSummaryIcons(PokedexAppData *pokedexApp, int dy) {
    s16 x;
    s16 y;

    ManagedSprite_GetPositionXY(pokedexApp->sprites[28], &x, &y);
    ManagedSprite_SetPositionXY(pokedexApp->sprites[28], x, y + dy);
    ManagedSprite_GetPositionXY(pokedexApp->sprites[43], &x, &y);
    ManagedSprite_SetPositionXY(pokedexApp->sprites[43], x, y + dy);
}

void PokedexApp_ShowSprite25Raised(PokedexAppData *pokedexApp) {
    ManagedSprite_SetPositionXY(pokedexApp->sprites[25], 48, -96);
    PokedexApp_SetSpriteVisible(pokedexApp, 25, TRUE);
}

void PokedexApp_MoveSprite25Vertically(PokedexAppData *pokedexApp, int dy) {
    s16 x;
    s16 y;

    ManagedSprite_GetPositionXY(pokedexApp->sprites[25], &x, &y);
    ManagedSprite_SetPositionXY(pokedexApp->sprites[25], x, y + dy);
}

void PokedexApp_ShowSprite25(PokedexAppData *pokedexApp) {
    ManagedSprite_SetPositionXY(pokedexApp->sprites[25], 48, 24);
    PokedexApp_SetSpriteVisible(pokedexApp, 25, TRUE);
}

// seenForms[index]: bit 7 set: a form (Pichu: 0 male, 1 female, 2 Spiky-eared), else 1 male, 2 female,
// 3 genderless.
void PokedexApp_GetSeenFormAndGender(PokedexAppData *pokedexApp, u32 index, u8 *form, u8 *gender) {
    u8 value = pokedexApp->seenForms[index];

    if (value & 0x80) {
        if (pokedexApp->curSpecies == SPECIES_PICHU) {
            switch (value ^ 0x80) {
            case 0:
                *form = 0;
                *gender = MON_MALE;
                return;
            case 1:
                *form = 0;
                *gender = MON_FEMALE;
                return;
            case 2:
                *form = 1;
                *gender = MON_FEMALE;
                return;
            }
            return;
        }
        *form = value ^ 0x80;
        *gender = Pokedex_SpeciesGetLastSeenGender(pokedexApp->args->pokedex, pokedexApp->curSpecies, 0);
        return;
    }
    *form = 0;
    switch (pokedexApp->seenForms[index]) {
    case 1:
        *gender = MON_MALE;
        return;
    case 2:
        *gender = MON_FEMALE;
        return;
    case 3:
        break;
    }
    *gender = MON_GENDERLESS;
}

void PokedexApp_CreateEntryTabCursor(PokedexAppData *pokedexApp) {
    PokedexApp_LoadMainObjResources(pokedexApp);
    pokedexApp->sprites[0] = SpriteSystem_NewSprite(pokedexApp->spriteSystem, pokedexApp->spriteManager, &gPokedexEntryTabCursorSpriteTemplate);
    ManagedSprite_SetPaletteOverride(pokedexApp->sprites[0], 4);
    PokedexApp_SetSpriteVisible(pokedexApp, 0, FALSE);
}

void PokedexApp_FreeEntryTabCursor(PokedexAppData *pokedexApp) {
    PokedexApp_DeleteSprite(pokedexApp, 0);
    PokedexApp_UnloadMainObjResources(pokedexApp);
}

void PokedexApp_MoveEntryTabCursor(PokedexAppData *pokedexApp, int index) {
    PokedexApp_SetSpritePos(pokedexApp, 0, index * 64 + 32, 176, FALSE);
}

// Area screen: 1-8 from gPokedexAreaSpriteTemplates, the icon of the shown form in 1, then the player marker, the area list's
// scrollbar and the map markers.
void PokedexApp_SetupAreaSprites(PokedexAppData *pokedexApp) {
    u8 form, gender;
    u32 i;

    PokedexApp_LoadAreaSpriteResources(pokedexApp);
    for (i = 1; i <= 8; i++) {
        pokedexApp->sprites[i] = PokedexApp_NewSprite(pokedexApp, &gPokedexAreaSpriteTemplates[i - 1]);
    }
    PokedexApp_SetPlayerMarkerAnim(pokedexApp, 1);
    PokedexApp_GetSeenFormAndGender(pokedexApp, 0, &form, &gender);
    PokedexApp_SetMonIconSub(pokedexApp, pokedexApp->curSpecies, form, 1);
    PokedexApp_UpdatePlayerMarker(pokedexApp);
    PokedexApp_SetupAreaListScrollbar(pokedexApp);
    PokedexApp_CreateAreaMarkerSprites(pokedexApp);
}

void PokedexApp_FreeAreaSprites(PokedexAppData *pokedexApp) {
    u32 i;

    for (i = 1; i < 59; i++) {
        PokedexApp_DeleteSprite(pokedexApp, i);
    }
    PokedexApp_UnloadAreaSpriteResources(pokedexApp);
}
