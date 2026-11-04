#include "global.h"

#include "nnsys/g2d_internal.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_course_ui.h"
#include "pokeathlon/pokeathlon_results_announcement.h"

#include "bg_window.h"
#include "font.h"
#include "font_sprite.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "math_util.h"
#include "message_format.h"
#include "obj_pltt_transfer.h"
#include "player_data.h"
#include "screen_fade.h"
#include "sprite_resource.h"
#include "sprite_transfer.h"
#include "system.h"
#include "text.h"

static void PokeathlonResults_LoadPlateResources(PokeathlonResultsAnnouncementPlates *plates);
static void PokeathlonResults_InitPlateResourcesHeader(PokeathlonResultsAnnouncementPlates *plates);
static void PokeathlonResults_CreatePlateSprites(PokeathlonResultsAnnouncementPlates *plates, int index, Sprite **sprites);
static void PokeathlonResults_PrintPlateName(PokeathlonResultsAnnouncementPlates *plates, int participant, PokeathlonResultsAnnouncementPlate *plate);
static void PokeathlonResults_PrintPlateText(PokeathlonResultsAnnouncementPlates *plates, String *string, PokeathlonResultsAnnouncementPlate *plate);
static void PokeathlonResults_RefreshPlate(PokeathlonResultsAnnouncementPlate *plate);
static void PokeathlonResults_SetPlateVisible(BOOL firstPlace, BOOL draw, PokeathlonResultsAnnouncementPlate *plate);
static void PokeathlonResults_SetPlateSpritePositions(int x, int y, PokeathlonResultsAnnouncementPlate *plate);
static void PokeathlonResults_MovePlateSprites(int dx, int dy, PokeathlonResultsAnnouncementPlate *plate);
static void PokeathlonResults_InitTextWindows(PokeathlonResultsAnnouncementPlates *plates);
static void PokeathlonResults_CreateText(PokeathlonResultsAnnouncementPlates *plates, PokeathlonResultsAnnouncementTextWindow *window, String *string, int x, int dx, int dy, Sprite *parent, PokeathlonResultsAnnouncementText *out);
static void PokeathlonResults_DestroyText(PokeathlonResultsAnnouncementText *text);
static void PokeathlonResults_CreateScoreboardText(PokeathlonResultsAnnouncementScoreboard *scoreboard, PokeathlonResultsAnnouncementTextWindow *window, String *string, int x, int dx, int dy, Sprite *parent, PokeathlonResultsAnnouncementText *out);
static void PokeathlonResults_DestroyScoreboardText(PokeathlonResultsAnnouncementText *text);
static void PokeathlonResults_SetScoreDigits(PokeathlonResultsAnnouncementScoreboardTeam *team, s32 points);

static const VecFx32 sResultsAnnouncementPlatePos = { 0, FX32_CONST(16), 0 };

PokeathlonResultsAnnouncementPlates *PokeathlonResults_NewPlates(enum HeapID heapId, BgConfig *bgConfig, PokeathlonCourseData *course) {
    PokeathlonResultsAnnouncementPlates *plates = Heap_Alloc(heapId, sizeof(PokeathlonResultsAnnouncementPlates));
    int i;
    MI_CpuFill8(plates, 0, sizeof(PokeathlonResultsAnnouncementPlates));
    plates->heapId = heapId;
    plates->fontSystem = FontSystem_NewInit(10, heapId);
    plates->bgConfig = bgConfig;
    plates->course = course;
    for (i = 0; i < 5; i++) {
        plates->plates[i].index = i;
    }
    return plates;
}

void PokeathlonResults_FreePlates(PokeathlonResultsAnnouncementPlates *plates) {
    PokeathlonResultsAnnouncementText *name;
    PokeathlonResultsAnnouncementText *text;
    PokeathlonResultsAnnouncementTextWindow *window;
    int i;
    i = 0;
    name = &plates->plates[0].name;
    text = &plates->plates[0].text;
    do {
        PokeathlonResults_DestroyText(name);
        PokeathlonResults_DestroyText(text);
        Sprite_Delete(plates->plates[i].sprites[0]);
        Sprite_Delete(plates->plates[i].sprites[1]);
        Sprite_Delete(plates->plates[i].sprites[2]);
        Sprite_Delete(plates->plates[i].sprites[3]);
        name = (PokeathlonResultsAnnouncementText *)((u8 *)name + sizeof(PokeathlonResultsAnnouncementPlate));
        text = (PokeathlonResultsAnnouncementText *)((u8 *)text + sizeof(PokeathlonResultsAnnouncementPlate));
        i++;
    } while (i < 5);
    i = 0;
    window = &plates->nameWindow;
    do {
        TextOBJLayout_Delete(window->layout);
        RemoveWindow(&window->window);
        i++;
        window++;
    } while (i < 2);
    FontSystem_Delete(plates->fontSystem);
    SpriteTransfer_DeleteCharTransferTask(plates->resources[0]);
    SpriteTransfer_DeletePlttTransferTask(plates->resources[1]);
    for (i = 0; i < 6; i++) {
        Destroy2DGfxResObjMan(plates->resourceManagers[i]);
    }
    SpriteList_Delete(plates->spriteList);
    Heap_Free(plates);
}

void PokeathlonResults_DrawPlates(PokeathlonResultsAnnouncementPlates *plates) {
    SpriteList_RenderAndAnimateSprites(plates->spriteList);
}

void PokeathlonResults_InitPlates(PokeathlonResultsAnnouncementPlates *plates, int unused) {
    int i;
    PokeathlonResultsAnnouncementPlate *plate;

    PokeathlonResults_LoadPlateResources(plates);
    PokeathlonResults_InitPlateResourcesHeader(plates);
    i = 0;
    plate = plates->plates;
    for (; i < 5; i++, plate++) {
        PokeathlonResults_CreatePlateSprites(plates, (u8)i, plate->sprites);
    }
    PokeathlonResults_InitTextWindows(plates);
    G2dRenderer_SetSubSurfaceCoords(&plates->renderer, 0, FX32_CONST(300));
    G2dRenderer_SetMainSurfaceCoords(&plates->renderer, 0, 0);
}

// Shows the next free plate at (x, y) for a ranking entry.
PokeathlonResultsAnnouncementPlate *PokeathlonResults_ShowPlate(PokeathlonResultsAnnouncementPlates *plates, int x, int y, PokeathlonCourseScore *score) {
    PokeathlonResultsAnnouncementPlate *plate;
    PokeathlonCourseParticipant *participant;
    BOOL isNpc;
    int index;

    index = plates->nextPlate;
    plate = &plates->plates[index];
    GF_ASSERT(!plate->active);
    participant = PokeathlonCourse_GetParticipantData(plates->course, score->participant);
    isNpc = participant->npcTeam > 0;
    plate->x = x;
    plate->y = y;
    plate->participant = score->participant;
    plate->rank = score->rank;
    PokeathlonResults_PrintPlateText(plates, score->text, plate);
    PokeathlonResults_PrintPlateName(plates, score->participant, plate);
    plates->firstPlace = plate->rank == 0;
    GF_ASSERT((s32)plate->participant < POKEATHLON_PARTICIPANTS);
    if (isNpc) {
        u32 picture = PokeathlonCourse_GetNpcTrainerPicFileId(PokeathlonCourse_GetNpcTeamSpriteId((u8)participant->npcTeam));
        PokeathlonCourse_LoadTrainerPicIntoSprite(plate->sprites[3], picture, 11, plates->heapId);
    } else {
        PokeathlonCourse_LoadPlayerTrainerPic(plate->sprites[3], plates->course, (u8)plate->participant, 27);
    }
    PokeathlonResults_RefreshPlate(plate);
    PokeathlonResults_SetPlateVisible(plates->firstPlace, TRUE, plate);
    plate->active = TRUE;
    plates->nextPlate = (plates->nextPlate + 1) % 5;
    return plate;
}

void PokeathlonResults_HidePlate(PokeathlonResultsAnnouncementPlate *plate) {
    GF_ASSERT(plate->active);
    plate->active = FALSE;
    PokeathlonResults_DestroyText(&plate->name);
    PokeathlonResults_DestroyText(&plate->text);
}

void PokeathlonResults_GetPlatePos(PokeathlonResultsAnnouncementPlate *plate, int *x, int *y) {
    *x = plate->x;
    *y = plate->y;
}

void PokeathlonResults_SetPlatePos(PokeathlonResultsAnnouncementPlate *plate, int x, int y) {
    plate->x = x;
    plate->y = y;
    PokeathlonResults_SetPlateSpritePositions(x, y, plate);
}

void PokeathlonResults_MovePlate(PokeathlonResultsAnnouncementPlate *plate, int dx, int dy) {
    plate->x += dx;
    plate->y += dy;
    PokeathlonResults_MovePlateSprites(dx, dy, plate);
}

u16 PokeathlonResults_GetPlateRank(PokeathlonResultsAnnouncementPlate *plate) {
    return plate->rank;
}

static void PokeathlonResults_LoadPlateResources(PokeathlonResultsAnnouncementPlates *plates) {
    int i;
    plates->spriteList = G2dRenderer_Init(55, &plates->renderer, plates->heapId);
    for (i = 0; i < 6; i++) {
        plates->resourceManagers[i] = Create2DGfxResObjMan(1, (GfGfxResType)i, plates->heapId);
    }
    plates->resources[0] = AddCharResObjFromNarc(plates->resourceManagers[GF_GFX_RES_TYPE_CHAR], NARC_a_1_6_0, 9, FALSE, 103, NNS_G2D_VRAM_TYPE_2DMAIN, plates->heapId);
    plates->resources[1] = AddPlttResObjFromNarc(plates->resourceManagers[GF_GFX_RES_TYPE_PLTT], NARC_a_1_6_0, 6, FALSE, 103, NNS_G2D_VRAM_TYPE_2DMAIN, 6, plates->heapId);
    plates->resources[2] = AddCellOrAnimResObjFromNarc(plates->resourceManagers[GF_GFX_RES_TYPE_CELL], NARC_a_1_6_0, 8, FALSE, 103, GF_GFX_RES_TYPE_CELL, plates->heapId);
    plates->resources[3] = AddCellOrAnimResObjFromNarc(plates->resourceManagers[GF_GFX_RES_TYPE_ANIM], NARC_a_1_6_0, 7, FALSE, 103, GF_GFX_RES_TYPE_ANIM, plates->heapId);
    SpriteTransfer_CreateCharTransferTask_AllocAtEnd(plates->resources[0]);
    SpriteTransfer_CreateExtPlttTransferTask(plates->resources[1]);
}

static void PokeathlonResults_InitPlateResourcesHeader(PokeathlonResultsAnnouncementPlates *plates) {
    CreateSpriteResourcesHeader(&plates->resourcesHeader, 103, 103, 103, 103, -1, -1, FALSE, 0, plates->resourceManagers[GF_GFX_RES_TYPE_CHAR], plates->resourceManagers[GF_GFX_RES_TYPE_PLTT], plates->resourceManagers[GF_GFX_RES_TYPE_CELL], plates->resourceManagers[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
}

static void PokeathlonResults_InitPlateSpriteTemplate(SpriteTemplate *template, PokeathlonResultsAnnouncementPlates *plates, SpriteResourcesHeader *unused, NNS_G2D_VRAM_TYPE whichScreen) {
    template->spriteList = plates->spriteList;
    template->header = &plates->resourcesHeader;
    template->position.x = 0;
    template->position.y = 0;
    template->position.z = 0;
    template->scale.x = FX32_ONE;
    template->scale.y = FX32_ONE;
    template->scale.z = FX32_ONE;
    template->rotation = 0;
    template->drawPriority = 2;
    template->whichScreen = whichScreen;
    template->heapID = plates->heapId;
}

static Sprite *PokeathlonResults_CreatePlateSprite(SpriteTemplate *template, int anim, int priority) {
    Sprite *sprite = Sprite_CreateAffine(template);
    Sprite_SetAnimActiveFlag(sprite, TRUE);
    Sprite_SetAnimCtrlSeq(sprite, anim);
    Sprite_SetDrawFlag(sprite, FALSE);
    Sprite_SetDrawPriority(sprite, priority);
    return sprite;
}

// The team picture of each plate gets its own character and palette slot.
static void PokeathlonResults_CreatePlateSprites(PokeathlonResultsAnnouncementPlates *plates, int index, Sprite **sprites) {
    SpriteTemplate template;
    Sprite *sprite;
    NNSG2dImageProxy *imageProxy;
    NNSG2dImagePaletteProxy *paletteProxy;
    NNS_G2D_VRAM_TYPE vramType;

    struct {
        u32 location;
        u32 offset;
        u32 paletteLocation;
        volatile u32 paletteOffset;
    } slots;

    PokeathlonResults_InitPlateSpriteTemplate(&template, plates, &plates->resourcesHeader, NNS_G2D_VRAM_TYPE_2DMAIN);
    sprites[0] = PokeathlonResults_CreatePlateSprite(&template, 17, 4);
    sprites[1] = PokeathlonResults_CreatePlateSprite(&template, 5, 0);
    sprites[2] = PokeathlonResults_CreatePlateSprite(&template, 18, 1);
    sprites[3] = PokeathlonResults_CreatePlateSprite(&template, 0, 2);
    sprite = sprites[3];
    vramType = Sprite_GetVramType(sprite);
    imageProxy = Sprite_GetImageProxy(sprite);
    paletteProxy = Sprite_GetPaletteProxy(sprite);
    slots.location = NNS_G2dGetImageLocation(imageProxy, vramType);
    slots.offset = index << 9;
    NNS_G2dInitImageProxy(imageProxy);
    NNS_G2dSetImageLocation(imageProxy, vramType, slots.location + slots.offset);
    slots.paletteLocation = NNS_G2dGetImagePaletteLocation(paletteProxy, vramType);
    slots.paletteOffset = (index + 6) << 5;
    NNS_G2dInitImagePaletteProxy(paletteProxy);
    NNS_G2dSetImagePaletteLocation(paletteProxy, vramType, slots.paletteLocation + slots.paletteOffset);
    Sprite_SetImageProxy(sprite, imageProxy);
    Sprite_SetPaletteProxy(sprite, paletteProxy);
    Sprite_SetPalOffset(sprite, index);
}

static void PokeathlonResults_PrintPlateName(PokeathlonResultsAnnouncementPlates *plates, int participant, PokeathlonResultsAnnouncementPlate *plate) {
    PlayerProfile *profile = PokeathlonCourse_GetPlayerProfileFromData(plates->course, participant);
    String *name = PlayerProfile_GetPlayerName_NewString(profile, plates->heapId);
    PokeathlonResults_CreateText(plates, &plates->nameWindow, name, 0, -56, -16, plate->sprites[0], &plate->name);
    String_Delete(name);
}

static void PokeathlonResults_PrintPlateText(PokeathlonResultsAnnouncementPlates *plates, String *string, PokeathlonResultsAnnouncementPlate *plate) {
    PokeathlonResults_CreateText(plates, &plates->textWindow, string, 0, -56, 0, plate->sprites[0], &plate->text);
}

// Plate color by participant, rank sprite.
static void PokeathlonResults_RefreshPlate(PokeathlonResultsAnnouncementPlate *plate) {
    PokeathlonResults_SetPlateSpritePositions(plate->x, plate->y, plate);
    Sprite_SetPaletteOverride(plate->sprites[0], plate->participant + 2);
    Sprite_SetAnimCtrlSeq(plate->sprites[1], plate->rank + 5);
}

static void PokeathlonResults_SetPlateVisible(BOOL firstPlace, BOOL draw, PokeathlonResultsAnnouncementPlate *plate) {
    Sprite_SetDrawFlag(plate->sprites[0], draw);
    Sprite_SetDrawFlag(plate->sprites[1], draw);
    if (firstPlace) {
        Sprite_SetDrawFlag(plate->sprites[2], draw);
    }
    TextOBJ_SetSpritesDrawFlag(plate->name.textObj, draw);
    TextOBJ_SetSpritesDrawFlag(plate->text.textObj, draw);
}

static void PokeathlonResults_SetPlateSpritePositions(int x, int y, PokeathlonResultsAnnouncementPlate *plate) {
    VecFx32 pos = sResultsAnnouncementPlatePos;
    pos.y += y << FX32_SHIFT;
    pos.x = (x + 128) << FX32_SHIFT;
    Sprite_SetMatrix(plate->sprites[0], &pos);
    pos.x = (x + 16) << FX32_SHIFT;
    Sprite_SetMatrix(plate->sprites[1], &pos);
    pos.x = (x + 48) << FX32_SHIFT;
    Sprite_SetMatrix(plate->sprites[2], &pos);
    pos.y -= FX32_CONST(4);
    Sprite_SetMatrix(plate->sprites[3], &pos);
    TextOBJ_UpdatePosition(plate->name.textObj);
    TextOBJ_UpdatePosition(plate->text.textObj);
}

static void PokeathlonResults_MovePlateSprites(int dx, int dy, PokeathlonResultsAnnouncementPlate *plate) {
    VecFx32 pos = *Sprite_GetMatrixPtr(plate->sprites[0]);
    pos.x += dx << FX32_SHIFT;
    pos.y += dy << FX32_SHIFT;
    Sprite_SetMatrix(plate->sprites[0], &pos);
    pos = *Sprite_GetMatrixPtr(plate->sprites[1]);
    pos.x += dx << FX32_SHIFT;
    pos.y += dy << FX32_SHIFT;
    Sprite_SetMatrix(plate->sprites[1], &pos);
    pos = *Sprite_GetMatrixPtr(plate->sprites[3]);
    pos.x += dx << FX32_SHIFT;
    pos.y += dy << FX32_SHIFT;
    Sprite_SetMatrix(plate->sprites[3], &pos);
    Sprite_SetMatrix(plate->sprites[2], &pos);
    TextOBJ_UpdatePosition(plate->name.textObj);
    TextOBJ_UpdatePosition(plate->text.textObj);
}

static void PokeathlonResults_InitTextWindow(PokeathlonResultsAnnouncementPlates *plates, PokeathlonResultsAnnouncementTextWindow *window, int width) {
    TextOBJLayout *layout;
    InitWindow(&window->window);
    AddTextWindowTopLeftCorner(plates->bgConfig, &window->window, width, 2, 0, 0);
    layout = TextOBJLayout_New(&window->window, plates->heapId);
    window->layout = layout;
    window->charSize = TextOBJLayout_GetCharSize(layout, NNS_G2D_VRAM_TYPE_2DMAIN);
}

static void PokeathlonResults_InitTextWindows(PokeathlonResultsAnnouncementPlates *plates) {
    PokeathlonResults_InitTextWindow(plates, &plates->nameWindow, 8);
    PokeathlonResults_InitTextWindow(plates, &plates->textWindow, 24);
}

static void PokeathlonResults_CreateText(PokeathlonResultsAnnouncementPlates *plates, PokeathlonResultsAnnouncementTextWindow *window, String *string, int x, int dx, int dy, Sprite *parent, PokeathlonResultsAnnouncementText *out) {
    TextOBJTemplate template;
    ObjCharSpaceReservation charSlot;
    TextOBJ *textObj;
    FillWindowPixelBufferText_AssumeTileSize32(&window->window, 0);
    AddTextPrinterParameterizedWithColorAndSpacing(&window->window, 0, string, x, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 0), 0, 0, NULL);
    ObjCharTransfer_ReserveCharSpace(window->charSize, TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, &charSlot);
    template.fontSystem = plates->fontSystem;
    template.window = &window->window;
    template.spriteList = plates->spriteList;
    template.plttResourceProxy = SpriteTransfer_GetPaletteProxy(plates->resources[1], NULL);
    template.sprite = parent;
    template.offset = charSlot.offset;
    template.x = dx;
    template.y = dy;
    template.bgPriority = 0;
    template.drawPriority = 3;
    template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.heapID = plates->heapId;
    textObj = FontOAM_Create(&template);
    TextOBJ_SetPaletteNum(textObj, 0);
    out->textObj = textObj;
    out->charSlot = charSlot;
}

static void PokeathlonResults_DestroyText(PokeathlonResultsAnnouncementText *text) {
    if (text->textObj != NULL) {
        TextOBJ_Destroy(text->textObj);
        ObjCharTransfer_FreeCharSpace(&text->charSlot);
        text->textObj = NULL;
    }
}

PokeathlonResultsAnnouncementScoreboard *PokeathlonResults_NewScoreboard(enum HeapID heapId, BgConfig *bgConfig, PokeathlonCourseSpritePool *scene) {
    PokeathlonResultsAnnouncementScoreboard *scoreboard = Heap_Alloc(heapId, sizeof(PokeathlonResultsAnnouncementScoreboard));
    PokeathlonResultsAnnouncementTextWindow *window;
    TextOBJLayout *layout;
    MI_CpuFill8(scoreboard, 0, sizeof(PokeathlonResultsAnnouncementScoreboard));
    scoreboard->heapId = heapId;
    scoreboard->fontSystem = FontSystem_NewInit(4, heapId);
    scoreboard->scene = scene;
    window = &scoreboard->window;
    InitWindow(&window->window);
    AddTextWindowTopLeftCorner(bgConfig, &window->window, 8, 2, 0, 0);
    layout = TextOBJLayout_New(&window->window, scoreboard->heapId);
    window->layout = layout;
    window->charSize = TextOBJLayout_GetCharSize(layout, NNS_G2D_VRAM_TYPE_2DSUB);
    return scoreboard;
}

void PokeathlonResults_FreeScoreboard(PokeathlonResultsAnnouncementScoreboard *scoreboard) {
    s32 i;
    PokeathlonResultsAnnouncementText *name;
    PokeathlonResultsAnnouncementTextWindow *window;
    i = 0;
    name = &scoreboard->teams[0].name;
    for (; i < POKEATHLON_PARTICIPANTS; i++, name = (PokeathlonResultsAnnouncementText *)((u8 *)name + sizeof(PokeathlonResultsAnnouncementScoreboardTeam))) {
        PokeathlonResults_DestroyScoreboardText(name);
    }
    window = &scoreboard->window;
    TextOBJLayout_Delete(window->layout);
    RemoveWindow(&window->window);
    FontSystem_Delete(scoreboard->fontSystem);
    Heap_Free(scoreboard);
}

void PokeathlonResults_LoadScoreboardResources(PokeathlonResultsAnnouncementScoreboard *scoreboard, s32 index) {
    PokeathlonCourseSpritePool_SetResourceId(scoreboard->scene, index, 104);
    PokeathlonCourseSpritePool_LoadChar(scoreboard->scene, NARC_poketool_pokezukan, 3, 104, NNS_G2D_VRAM_TYPE_2DSUB);
    PokeathlonCourseSpritePool_LoadPltt(scoreboard->scene, NARC_poketool_pokezukan, 0, 104, NNS_G2D_VRAM_TYPE_2DSUB, 5);
    PokeathlonCourseSpritePool_LoadCell(scoreboard->scene, NARC_poketool_pokezukan, 2, 104);
    PokeathlonCourseSpritePool_LoadAnim(scoreboard->scene, NARC_poketool_pokezukan, 1, 104);
}

void PokeathlonResults_InitScoreboard(PokeathlonResultsAnnouncementScoreboard *scoreboard, PokeathlonCourseData *course, int y) {
    int i;
    int j;
    Sprite *sprite;
    VecFx32 pos;
    String *name;
    PokeathlonResultsAnnouncementScoreboardTeam *team;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        sprite = PokeathlonCourseSpritePool_CreateSprite(scoreboard->scene, 0, NNS_G2D_VRAM_TYPE_2DSUB, 104, 3);
        pos.z = 0;
        pos.x = (i * 64) << FX32_SHIFT;
        pos.y = (y + 16) << FX32_SHIFT;
        Sprite_SetMatrix(sprite, &pos);
        Sprite_SetAnimActiveFlag(sprite, TRUE);
        Sprite_SetAnimCtrlSeq(sprite, 0);
        Sprite_SetPalIndexRespectVramOffset(sprite, i);
        Sprite_SetDrawPriority(sprite, 2);
        for (j = 0; j < 3; j++) {
            sprite = PokeathlonCourseSpritePool_CreateSprite(scoreboard->scene, 0, NNS_G2D_VRAM_TYPE_2DSUB, 104, 4);
            pos.z = 0;
            pos.x = (i * 64 + 8 + j * 16) << FX32_SHIFT;
            pos.y = (y + 24) << FX32_SHIFT;
            Sprite_SetMatrix(sprite, &pos);
            Sprite_SetAnimActiveFlag(sprite, TRUE);
            Sprite_SetAnimCtrlSeq(sprite, 1);
            Sprite_SetDrawPriority(sprite, 1);
        }
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        team = &scoreboard->teams[i];
        team->plate = PokeathlonCourseSpritePool_Take(scoreboard->scene, 104, 3);
        PokeathlonCourseSpritePoolSprite_Show(team->plate, TRUE, TRUE);
        for (j = 0; j < 3; j++) {
            team->digits[j] = PokeathlonCourseSpritePool_Take(scoreboard->scene, 104, 4);
            PokeathlonCourseSpritePoolSprite_Show(team->digits[j], TRUE, TRUE);
        }
        name = PlayerProfile_GetPlayerName_NewString(PokeathlonCourse_GetPlayerProfileFromData(course, i), scoreboard->heapId);
        sprite = PokeathlonCourseSpritePoolSprite_GetSprite(scoreboard->teams[i].plate);
        PokeathlonResults_CreateScoreboardText(scoreboard, &scoreboard->window, name, 2, 0, -16, sprite, &scoreboard->teams[i].name);
        String_Delete(name);
        TextOBJ_SetSpritesDrawFlag(scoreboard->teams[i].name.textObj, TRUE);
        scoreboard->teams[i].y = y + 16;
    }
}

void PokeathlonResults_SetScore(PokeathlonResultsAnnouncementScoreboard *scoreboard, u32 points, u32 team) {
    GF_ASSERT(team < POKEATHLON_PARTICIPANTS);
    scoreboard->teams[team].points = points;
    PokeathlonResults_SetScoreDigits(&scoreboard->teams[team], points);
}

static void PokeathlonResults_CreateScoreboardText(PokeathlonResultsAnnouncementScoreboard *scoreboard, PokeathlonResultsAnnouncementTextWindow *window, String *string, int x, int dx, int dy, Sprite *parent, PokeathlonResultsAnnouncementText *out) {
    TextOBJTemplate template;
    ObjCharSpaceReservation charSlot;
    TextOBJ *textObj;
    FillWindowPixelBufferText_AssumeTileSize32(&window->window, 0);
    AddTextPrinterParameterizedWithColorAndSpacing(&window->window, 0, string, x, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 0), 0, 0, NULL);
    ObjCharTransfer_ReserveCharSpace(window->charSize, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, &charSlot);
    template.fontSystem = scoreboard->fontSystem;
    template.window = &window->window;
    template.spriteList = PokeathlonCourseSpritePool_GetSpriteList(scoreboard->scene);
    template.plttResourceProxy = ObjPlttTransfer_GetPlttProxyByID(104);
    template.sprite = parent;
    template.offset = charSlot.offset;
    template.x = dx;
    template.y = dy;
    template.bgPriority = 0;
    template.drawPriority = 0;
    template.vram = NNS_G2D_VRAM_TYPE_2DSUB;
    template.heapID = scoreboard->heapId;
    textObj = FontOAM_Create(&template);
    TextOBJ_SetPalIndexRespectVramOffset(textObj, 4);
    out->textObj = textObj;
    out->charSlot = charSlot;
}

static void PokeathlonResults_DestroyScoreboardText(PokeathlonResultsAnnouncementText *text) {
    if (text->textObj != NULL) {
        TextOBJ_Destroy(text->textObj);
        ObjCharTransfer_FreeCharSpace(&text->charSlot);
        text->textObj = NULL;
    }
}

static void PokeathlonResults_SetScoreDigits(PokeathlonResultsAnnouncementScoreboardTeam *team, s32 points) {
    s32 hundreds = points / 100;
    s32 rest = points - hundreds * 100;
    s32 tens = rest / 10;
    Sprite *sprite = PokeathlonCourseSpritePoolSprite_GetSprite(team->digits[0]);
    Sprite_SetAnimCtrlSeq(sprite, hundreds + 1);
    sprite = PokeathlonCourseSpritePoolSprite_GetSprite(team->digits[1]);
    Sprite_SetAnimCtrlSeq(sprite, tens + 1);
    sprite = PokeathlonCourseSpritePoolSprite_GetSprite(team->digits[2]);
    Sprite_SetAnimCtrlSeq(sprite, rest - tens * 10 + 1);
}
