#ifndef GUARD_POKEHEARTGOLD_APPLICATION_POKEDEX_POKEDEX_INTERNAL_H
#define GUARD_POKEHEARTGOLD_APPLICATION_POKEDEX_POKEDEX_INTERNAL_H

#include "global.h"

#include "application/pokedex/pokedex_internal_constants.h"

#include "bg_cell_manager.h" // 0x0201956C
#include "bg_window.h"
#include "char_tiles.h"
#include "grid_input_handler.h" // 0x02019BA4
#include "msgdata.h"
#include "overlay_18.h"
#include "palette.h"
#include "sprite_system.h"

enum {
    POKEDEXAPP_MAINSEQ_00 = 0,
    POKEDEXAPP_MAINSEQ_01 = 1,
    POKEDEXAPP_MAINSEQ_02 = 2,
    POKEDEXAPP_MAINSEQ_03 = 3,
    POKEDEXAPP_MAINSEQ_04 = 4,
    POKEDEXAPP_MAINSEQ_05 = 5,
    POKEDEXAPP_MAINSEQ_06 = 6,
    POKEDEXAPP_MAINSEQ_07 = 7,
    POKEDEXAPP_MAINSEQ_08 = 8,
    POKEDEXAPP_MAINSEQ_09 = 9,
    POKEDEXAPP_MAINSEQ_10 = 10,
    POKEDEXAPP_MAINSEQ_11 = 11,
    POKEDEXAPP_MAINSEQ_12 = 12,
    POKEDEXAPP_MAINSEQ_13 = 13,
    POKEDEXAPP_MAINSEQ_14 = 14,
    POKEDEXAPP_MAINSEQ_15 = 15,
    POKEDEXAPP_MAINSEQ_16 = 16,
    POKEDEXAPP_MAINSEQ_17 = 17,
    POKEDEXAPP_MAINSEQ_18 = 18,
    POKEDEXAPP_MAINSEQ_19 = 19,
    POKEDEXAPP_MAINSEQ_20 = 20,
    POKEDEXAPP_MAINSEQ_21 = 21,
    POKEDEXAPP_MAINSEQ_22 = 22,
    POKEDEXAPP_MAINSEQ_23 = 23,
    POKEDEXAPP_MAINSEQ_24 = 24,
    POKEDEXAPP_MAINSEQ_25 = 25,
    POKEDEXAPP_MAINSEQ_26 = 26,
    POKEDEXAPP_MAINSEQ_27 = 27,
    POKEDEXAPP_MAINSEQ_28 = 28,
    POKEDEXAPP_MAINSEQ_29 = 29,
    POKEDEXAPP_MAINSEQ_30 = 30,
    POKEDEXAPP_MAINSEQ_31 = 31,
    POKEDEXAPP_MAINSEQ_32 = 32,
    POKEDEXAPP_MAINSEQ_33 = 33,
    POKEDEXAPP_MAINSEQ_34 = 34,
    POKEDEXAPP_MAINSEQ_35 = 35,
    POKEDEXAPP_MAINSEQ_36 = 36,
    POKEDEXAPP_MAINSEQ_37 = 37,
    POKEDEXAPP_MAINSEQ_38 = 38,
    POKEDEXAPP_MAINSEQ_39 = 39,
    POKEDEXAPP_MAINSEQ_40 = 40,
    POKEDEXAPP_MAINSEQ_41 = 41,
    POKEDEXAPP_MAINSEQ_42 = 42,
    POKEDEXAPP_MAINSEQ_43 = 43,
    POKEDEXAPP_MAINSEQ_44 = 44,
    POKEDEXAPP_MAINSEQ_45 = 45,
    POKEDEXAPP_MAINSEQ_46 = 46,
    POKEDEXAPP_MAINSEQ_47 = 47,
    POKEDEXAPP_MAINSEQ_48 = 48,
    POKEDEXAPP_MAINSEQ_49 = 49,
    POKEDEXAPP_MAINSEQ_50 = 50,
    POKEDEXAPP_MAINSEQ_51 = 51,
    POKEDEXAPP_MAINSEQ_52 = 52,
    POKEDEXAPP_MAINSEQ_53 = 53,
    POKEDEXAPP_MAINSEQ_54 = 54,
    POKEDEXAPP_MAINSEQ_55 = 55,
    POKEDEXAPP_MAINSEQ_56 = 56,
    POKEDEXAPP_MAINSEQ_57 = 57,
    POKEDEXAPP_MAINSEQ_58 = 58,
    POKEDEXAPP_MAINSEQ_59 = 59,
    POKEDEXAPP_MAINSEQ_60 = 60,
    POKEDEXAPP_MAINSEQ_61 = 61,
    POKEDEXAPP_MAINSEQ_62 = 62,
    POKEDEXAPP_MAINSEQ_63 = 63,
    POKEDEXAPP_MAINSEQ_64 = 64,
    POKEDEXAPP_MAINSEQ_65 = 65,
    POKEDEXAPP_MAINSEQ_66 = 66,
    POKEDEXAPP_MAINSEQ_67 = 67,
    POKEDEXAPP_MAINSEQ_68 = 68,
    POKEDEXAPP_MAINSEQ_69 = 69,
    POKEDEXAPP_MAINSEQ_70 = 70,
    POKEDEXAPP_MAINSEQ_71 = 71,
    POKEDEXAPP_MAINSEQ_72 = 72,
    POKEDEXAPP_MAINSEQ_73 = 73,
    POKEDEXAPP_MAINSEQ_74 = 74,
    POKEDEXAPP_MAINSEQ_75 = 75,
    POKEDEXAPP_MAINSEQ_76 = 76,
    POKEDEXAPP_MAINSEQ_77 = 77,
    POKEDEXAPP_MAINSEQ_78 = 78,
    POKEDEXAPP_MAINSEQ_79 = 79,
    POKEDEXAPP_MAINSEQ_80 = 80,
    POKEDEXAPP_MAINSEQ_81 = 81,
    POKEDEXAPP_MAINSEQ_82 = 82,
    POKEDEXAPP_MAINSEQ_83 = 83,
    POKEDEXAPP_MAINSEQ_84 = 84,
    POKEDEXAPP_MAINSEQ_85 = 85,
    POKEDEXAPP_MAINSEQ_86 = 86,
    POKEDEXAPP_MAINSEQ_87 = 87,
    POKEDEXAPP_MAINSEQ_88 = 88,
    POKEDEXAPP_MAINSEQ_89 = 89,
    POKEDEXAPP_MAINSEQ_90 = 90,
    POKEDEXAPP_MAINSEQ_91 = 91,
    POKEDEXAPP_MAINSEQ_92 = 92,
    POKEDEXAPP_MAINSEQ_MAX = 93,
};

typedef struct PokedexAppData PokedexAppData;

typedef struct PokedexFlashButtonState {
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u8 bgId;
    u8 state;
    u8 timer;
    u8 normalPalette : 4;
    u8 flashPalette : 4;
} PokedexFlashButtonState;

typedef struct PokedexListDragState {
    u32 touchX;
    u32 touchY;
    s16 switchX;
    u16 state;
} PokedexListDragState;

typedef struct PokedexEntrySlideState {
    u16 state;
    u8 timer;
    u8 buttonsShown;
} PokedexEntrySlideState;

typedef struct PokedexBasicSeqState {
    u8 state;
} PokedexBasicSeqState;

typedef struct PokedexListScrollState {
    u16 *numberTilemap;
    u8 state;
    u8 scrollStep;
    u8 scrollbarStep;
    u8 wrapCursor;
} PokedexListScrollState;

typedef struct PokedexSeqU16PairState {
    u16 unk_0;
    u16 unk_2;
} PokedexSeqU16PairState;

typedef struct PokedexEntryDragState {
    u32 touchX;
    u32 touchY;
    u8 filler_8[2];
    u16 state;
} PokedexEntryDragState;

typedef struct PokedexSearchPageChangeState {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
} PokedexSearchPageChangeState;

typedef struct PokedexSliderState {
    u32 prevValue;
    u32 holdFrames;
    u16 arrowSprite;
    s16 direction;
} PokedexSliderState;

typedef struct PokedexEntryTabSwitchState {
    u16 state;
    u8 fadeStart;
} PokedexEntryTabSwitchState;

// Weight check: the scale animation (gWeightCheckAnimFuncs[animIndex], one per weight-difference class)
typedef struct PokedexWeightCheckAnim {
    PokedexAppData *pokedexApp; // 0x00
    s32 dropOffset;             // 0x04 figures dropping onto the pans, fx32
    u16 animIndex;              // 0x08
    u8 monLighter;              // 0x0A the Pokemon is lighter than the player
    u8 step;                    // 0x0B
    s32 rotationSpeed;          // 0x0C beam rotation per frame
    s32 rotationAccel;          // 0x10
    s32 rotationEndSpeed;       // 0x14
    s16 dropSpeed;              // 0x18 the thrown figure's vertical speed
    s16 dropAccel;              // 0x1A
    u16 dropSprite;             // 0x1C the thrown figure (2 trainer, 4 Pokemon)
    u16 dropTargetSprite;       // 0x1E its pan (8, 9)
} PokedexWeightCheckAnim;

typedef struct PokedexWeightCheckState {
    int state;
    PokedexWeightCheckAnim *anim;
} PokedexWeightCheckState;

typedef union PokedexSeqState {
    PokedexFlashButtonState state_04;
    PokedexListDragState state_06;
    PokedexEntrySlideState state_09;
    PokedexBasicSeqState state_10;
    PokedexListScrollState state_13;
    PokedexSeqU16PairState state_16;
    PokedexEntryDragState state_17;
    PokedexSearchPageChangeState state_26;
    PokedexSliderState state_38;
    PokedexEntryTabSwitchState state_69;
    PokedexWeightCheckState state_77;
    u8 padding[16];
} PokedexSeqState;

// PokedexListEntry.caughtState
enum {
    POKEDEXAPP_ENTRY_SEEN = 1,
    POKEDEXAPP_ENTRY_CAUGHT = 2,
};

typedef struct PokedexSearchResults {
    u16 entries[NATIONAL_DEX_COUNT][2];
    u16 count;
    u16 caughtCount;
} PokedexSearchResults;

typedef struct PokedexListEntry {
    u16 species;     // 0x0
    u16 caughtState; // 0x2
} PokedexListEntry;

typedef struct PokedexSizeCheckData {
    s16 *player_ypos;  // 0x0
    s16 *player_scale; // 0x4
    s16 *mon_ypos;     // 0x8
    s16 *mon_scale;    // 0xC
} PokedexSizeCheckData;

typedef struct PokedexMapList {
    s32 *maps;
    s32 nMaps;
} PokedexMapList;

typedef struct PokedexAreaList {
    PokedexMapList overworldByTime; // 0x00
    PokedexMapList overworldOther;  // 0x08
    PokedexMapList dungeonByTime;   // 0x10
    PokedexMapList dungeonOther;    // 0x18
    PokedexMapList areas;           // 0x20
    u32 *areaSources;               // 0x28
} PokedexAreaList;

typedef struct PokedexDungeonArea {
    u8 x;      // 0x00
    u8 y;      // 0x01
    u8 unk_02; // 0x02
    u8 unk_03; // 0x03
} PokedexDungeonArea;

typedef struct PokedexOverworldArea {
    u8 x;          // 0x00
    u8 y;          // 0x01
    u8 width;      // 0x02
    u8 height;     // 0x03
    u8 unk_04[32]; // 0x04
} PokedexOverworldArea;

typedef struct PokedexBgRect {
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} PokedexBgRect;

typedef struct PokedexSliderValue {
    u16 height;
    u16 weight;
} PokedexSliderValue;

struct PokedexAppData {
    PokedexArgs *args;                              // 0x0000
    BgConfig *bgConfig;                             // 0x0004
    BgCellManager *bgCellManager;                   // 0x0008
    Window windows[101];                            // 0x000C
    MsgData *msgData;                               // 0x065C
    MessageFormat *msgFormat;                       // 0x0660
    String *strBufFormatted;                        // 0x0664
    SpriteSystem *spriteSystem;                     // 0x0668
    SpriteManager *spriteManager;                   // 0x066C
    ManagedSprite *sprites[120];                    // 0x0670
    PaletteData *paletteData;                       // 0x0850
    NARC *gfxNarc;                                  // 0x0854
    NARC *iconNarc;                                 // 0x0858
    int nextSeq;                                    // 0x085C
    int fadeNextSeq;                                // 0x0860
    u32 keyInput;                                   // 0x0864
    PokedexSeqState seqState;                       // 0x0868
    PokedexSearchResults searchResults;             // 0x0878
    PokedexListEntry listEntries[518];              // 0x1030
    void *heights;                                  // 0x1848
    void *weights;                                  // 0x184C
    PokedexSliderValue *sliderValues;               // 0x1850
    u8 *speciesAreaMasks;                           // 0x1854
    u8 dexMode;                                     // 0x1858
    u8 listPage;                                    // 0x1859 list / search result page
    u8 listCursor;                                  // 0x185A cursor on the page (5 per row)
    u8 entryTab;                                    // 0x185B
    u8 language;                                    // 0x185C language of the shown entry
    u8 countWindowSwap;                             // 0x185D
    u8 iconPage;                                    // 0x185E which of the two icon grid sprite sets is shown
    u8 monPicSwap : 4;                              // 0x185F which of the two picture sprites is shown
    u8 typeIconSwap : 4;                            // 0x185F which type icon pair is shown
    int nationalDex;                                // 0x1860
    GridInputHandler *gridInput;                    // 0x1864
    u32 dexSearchCriteria[DEX_SEARCH_CRITERIA_NUM]; // 0x1868
    u32 dexSearchCriteriaBak[2];                    // 0x1890
    int subBgPriorityRequest;                       // 0x1898
    int prevGridInput;                              // 0x189C search grids: input before the OK / cancel buttons
    u8 entryFromSearch;                             // 0x18A0
    u8 unk_18A1;                                    // 0x18A1
    u16 curSpecies;                                 // 0x18A2
    u8 seenForms[0x20];                             // 0x18A4
    s8 numSeenForms;                                // 0x18C4
    s8 selectedForm;                                // 0x18C5
    s8 compareForm;                                 // 0x18C6
    u8 compareSide : 5;                             // 0x18C7
    u8 formPicSwapA : 1;                            // 0x18C7 which sprite pair shows the (left) form picture
    u8 formPicSwapB : 1;                            // 0x18C7 same for the compare screen's right picture
    u8 showBackPic : 1;                             // 0x18C7
    s8 areaRegion;                                  // 0x18C8
    s8 areaTimeOfDay;                               // 0x18C9
    s8 areaListPos;                                 // 0x18CA
    u8 areaBlinkAlpha : 6;                          // 0x18CB
    u8 areaBlinkPhase : 1;                          // 0x18CB
    u8 areaBlinkFadingOut : 1;                      // 0x18CB
    PokedexSizeCheckData sizeCheckData;             // 0x18CC
    PokedexAreaList areaList;                       // 0x18DC
    PokedexDungeonArea *dungeonAreaTable;           // 0x1908
    PokedexOverworldArea *overworldAreaTable;       // 0x190C
}; // size: 0x1910

void PokedexApp_VBlankCallback(void *cb_arg);
void PokedexApp_SetGraphicsBanks(void);
void PokedexApp_InitBgs(PokedexAppData *pokedexApp);
void PokedexApp_SetSubBg3Mode(PokedexAppData *pokedexApp, BOOL useAffine);
void PokedexApp_FreeBgs(PokedexAppData *pokedexApp);
void PokedexApp_ClearBgTilemap(PokedexAppData *pokedexApp, u8 bgId);
void PokedexApp_InitBlend(void);
void PokedexApp_SetBg2Bg3Blend(u8 ev1, u8 ev2);
void PokedexApp_InitPaletteData(PokedexAppData *appData);
void PokedexApp_FreePaletteData(PokedexAppData *pokedexApp);
void PokedexApp_InitMsgData(PokedexAppData *pokedexApp);
void PokedexApp_FreeMsgData(PokedexAppData *pokedexApp);
void PokedexApp_LoadSearchTables(PokedexAppData *pokedexApp);
void PokedexApp_FreeSearchTables(PokedexAppData *pokedexApp);
void PokedexApp_InitBgCells(PokedexAppData *pokedexApp);
void PokedexApp_FreeBgCells(PokedexAppData *pokedexApp);
void PokedexApp_SlideInListButtons(PokedexAppData *pokedexApp);
void PokedexApp_SlideOutListButtons(PokedexAppData *pokedexApp);
void PokedexApp_DrawEntryNameBar(PokedexAppData *pokedexApp);
void PokedexApp_SlideInEntryButtons(PokedexAppData *pokedexApp);
void PokedexApp_SlideOutEntryButtons(PokedexAppData *pokedexApp);
void PokedexApp_SlideInSearchMenuButtons(PokedexAppData *pokedexApp);
void PokedexApp_SlideOutSearchMenuButtons(PokedexAppData *pokedexApp);
void PokedexApp_SlideInSearchPageButtons(PokedexAppData *pokedexApp);
void PokedexApp_SlideOutSearchPageButtons(PokedexAppData *pokedexApp);
void PokedexApp_SlideInSearchResultButtons(PokedexAppData *pokedexApp);
void PokedexApp_SlideOutSearchResultButtons(PokedexAppData *pokedexApp);
void PokedexApp_SlideInEntryTabs(PokedexAppData *pokedexApp);
void PokedexApp_SlideOutEntryTabs(PokedexAppData *pokedexApp);
void PokedexApp_DimEntryTabsIfNotCaught(PokedexAppData *pokedexApp);
void PokedexApp_ShowAreaUnknownBanner(PokedexAppData *pokedexApp);
void PokedexApp_HideAreaUnknownBanner(PokedexAppData *pokedexApp);
void PokedexApp_SetupScreen(PokedexAppData *pokedexApp, int screen);
void PokedexApp_DrawDexModeLabel(PokedexAppData *pokedexApp);
u16 *PokedexApp_BuildListNumberTilemap(PokedexAppData *pokedexApp, u32 firstIndex);
u16 *PokedexApp_BuildSearchResultNumberTilemap(PokedexAppData *pokedexApp, u32 firstIndex);
void PokedexApp_FreeNumberTilemap(u16 *tilemap);
void PokedexApp_DrawListNumbers(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchResultNumbers(PokedexAppData *pokedexApp);
void PokedexApp_LoadNumberTilemap(PokedexAppData *pokedexApp, u16 *tilemap);
BOOL PokedexApp_HasCaughtInLanguage(PokedexAppData *pokedexApp, u16 species, u16 language);
BOOL PokedexApp_HasForeignEntries(PokedexAppData *pokedexApp, u16 species);
void PokedexApp_CycleListEntryLanguage(PokedexAppData *pokedexApp, u16 species, s16 delta);
void PokedexApp_UpdateListEntry(PokedexAppData *pokedexApp);
void PokedexApp_LoadEntryDetailsBg(BgConfig *bgConfig, u8 bgId, u8 language, NARC *narc, enum HeapID heapId);
void PokedexApp_LoadEmptyEntryDetailsBg(BgConfig *bgConfig, u8 bgId, NARC *narc, enum HeapID heapId);
void PokedexApp_ResetSearchCriteria(PokedexAppData *pokedexApp);
void PokedexApp_SetupSearchPage(PokedexAppData *pokedexApp, int searchPage, int initialPos);
void PokedexApp_SelectSearchOrder(PokedexAppData *pokedexApp, int index);
void PokedexApp_HighlightSearchTypes(PokedexAppData *pokedexApp);
void PokedexApp_SelectSearchArea(PokedexAppData *pokedexApp, int index);
void PokedexApp_SelectSearchBodyType(PokedexAppData *pokedexApp, u32 bodyType);
u8 PokedexApp_GetLetterGridCell(int index);
void PokedexApp_SelectSearchLetter(PokedexAppData *pokedexApp, u32 letter);
void PokedexApp_BuildListReturnCells(PokedexAppData *pokedexApp);
void PokedexApp_UpdateSearchResultEntry(PokedexAppData *pokedexApp);
void PokedexApp_CycleSearchEntryLanguage(PokedexAppData *pokedexApp, u16 species, s16 delta);
void PokedexApp_SetSubScreenClipWindow(BOOL enable);
void PokedexApp_LoadFormsGraphics(PokedexAppData *pokedexApp);
void PokedexApp_LoadFormCompareGraphics(PokedexAppData *pokedexApp);
void PokedexApp_CollectSeenForms(PokedexAppData *pokedexApp);
void PokedexApp_LoadSizeData(PokedexAppData *pokedexApp);
void PokedexApp_FreeSizeData(PokedexAppData *pokedexApp);
void PokedexApp_BuildAreaList(PokedexAppData *pokedexApp, int timeOfDay, int region);
void PokedexApp_FreeAreaList(PokedexAppData *pokedexApp);
BOOL PokedexApp_IsDungeonArea(PokedexAppData *pokedexApp, u32 areaIndex);
u32 PokedexApp_GetAreaEncounterFlag(PokedexAppData *pokedexApp, u32 areaIndex, u32 sourceBit);
u32 PokedexApp_GetAreaMapId(PokedexAppData *pokedexApp, u32 areaIndex);
u32 PokedexApp_GetOverworldMapId(u32 idx);
u32 PokedexApp_GetDungeonMapId(u32 index);
BOOL PokedexApp_IsRoute2Area(u32 idx);
BOOL PokedexApp_IsRoute16Area(u32 idx);
void PokedexApp_LoadAreaTables(PokedexAppData *pokedexApp);
void PokedexApp_FreeAreaTables(PokedexAppData *pokedexApp);

BOOL PokedexApp_RunMainSeq(PokedexAppData *pokedexApp, int *pState);
void PokedexApp_AddWindows(PokedexAppData *pokedexApp, const WindowTemplate *templates, u32 count);

void PokedexApp_RemoveAllWindows(PokedexAppData *pokedexApp);
void PokedexApp_PrintFormattedMessage(PokedexAppData *pokedexApp, MsgData *msgData, int windowId, int msgNo, int x, int y, int fontId, int color, int align);
void PokedexApp_SetupListWindows(PokedexAppData *pokedexApp);
void PokedexApp_DrawCountLabel(PokedexAppData *pokedexApp, int windowId, u32 msgNo);
void PokedexApp_DrawCountLabelAndCopy(PokedexAppData *pokedexApp, u32 windowId, u32 msgNo);
void PokedexApp_DrawCountNumber(PokedexAppData *pokedexApp, u32 windowId, u32 value);
void PokedexApp_DrawCountNumberAndCopy(PokedexAppData *pokedexApp, u32 windowId, u32 value);
void PokedexApp_DrawSeenAndCaughtCounts(PokedexAppData *pokedexApp);
void PokedexApp_DrawCenteredSpeciesName(PokedexAppData *pokedexApp, u32 species, int windowId);
void PokedexApp_DrawListEntryHeader(PokedexAppData *pokedexApp, u32 species, u32 entry);
void PokedexApp_DrawSearchEntryHeader(PokedexAppData *pokedexApp, u32 species, u32 entry);
void PokedexApp_DrawInfoLabel(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawDexNumber(PokedexAppData *pokedexApp, u32 species, u32 windowId);
void PokedexApp_DrawSpeciesName(PokedexAppData *pokedexApp, u32 species, u32 windowId);
void PokedexApp_DrawCategory(PokedexAppData *pokedexApp, u32 species, u32 entry, u32 windowId);
void PokedexApp_DrawListEntryDetails(PokedexAppData *pokedexApp, u32 species, u32 entry);
void PokedexApp_DrawFlavorText(PokedexAppData *pokedexApp, u32 species, u32 entry, u32 windowId);
void PokedexApp_DrawHeightLabel(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawWeightLabel(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_PrintHeight(PokedexAppData *pokedexApp, u32 species, u32 state, u32 windowId, u32 x, u32 y, u32 color, u32 align);
void PokedexApp_DrawHeight(PokedexAppData *pokedexApp, u32 species, u32 entry, u32 windowId);
void PokedexApp_PrintWeight(PokedexAppData *pokedexApp, u32 species, u32 state, u32 windowId, u32 x, u32 y, u32 color, u32 align);
void PokedexApp_DrawWeight(PokedexAppData *pokedexApp, u32 species, u32 entry, u32 windowId);
void PokedexApp_DrawForeignDexLabel(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawForeignDexNumber(PokedexAppData *pokedexApp, u32 species, u32 windowId, u32 language);
void PokedexApp_DrawForeignSpeciesName(PokedexAppData *pokedexApp, u32 species, u32 windowId);
void PokedexApp_DrawForeignCategory(PokedexAppData *pokedexApp, u32 species, u32 entry, u32 windowId);
void PokedexApp_DrawSearchEntryDetails(PokedexAppData *pokedexApp, u32 species, u32 entry);
void PokedexApp_SetupSearchWindows(PokedexAppData *pokedexApp);
void PokedexApp_PutSearchWindowCellTiles(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchMessage(PokedexAppData *pokedexApp, u32 page);
void PokedexApp_DrawSearchOrderLabel(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawSearchNameLabel(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawSearchTypeLabel(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawSearchHeightLabel(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawSearchWeightLabel(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawSearchAreaLabel(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawSearchFormLabel(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawSearchButton(PokedexAppData *pokedexApp, int windowId, int msgNo);
void PokedexApp_DrawSearchMenuPage(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchCriteria(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchOrderPage(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchNamePage(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchTypePage(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchHeightPage(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchWeightPage(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchAreaPage(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchFormPage(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchOrderValue(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawSearchNameValue(PokedexAppData *pokedexApp, int windowId);
void PokedexApp_DrawSearchTypeValue(PokedexAppData *pokedexApp, u32 type, u32 windowId, s32 x);
void PokedexApp_DrawHeightValue(PokedexAppData *pokedexApp, u32 height, u32 windowId);
void PokedexApp_DrawWeightValue(PokedexAppData *pokedexApp, u32 weight, u32 windowId);
void PokedexApp_DrawSearchAreaValue(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_DrawSearchCriteriaSummary(PokedexAppData *pokedexApp);
void PokedexApp_DrawSearchResultCounts(PokedexAppData *pokedexApp);
void PokedexApp_PutWindowTilemap(PokedexAppData *pokedexApp, u32 windowId);
void PokedexApp_SetSearchSummaryVisible(PokedexAppData *pokedexApp, BOOL visible);
void PokedexApp_ClearSearchEntryWindows(PokedexAppData *pokedexApp);
void PokedexApp_InitAreaListCells(PokedexAppData *pokedexApp);
void PokedexApp_SetAreaWindowCellTiles(PokedexAppData *pokedexApp);
void PokedexApp_SetFormsWindowCellTiles(PokedexAppData *pokedexApp);
void PokedexApp_SetupAreaWindows(PokedexAppData *pokedexApp);
void PokedexApp_DrawSelectedFormName(PokedexAppData *pokedexApp);
void PokedexApp_FreeAreaWindows(PokedexAppData *pokedexApp);
void PokedexApp_DrawTimeOfDayLabel(PokedexAppData *pokedexApp);
void PokedexApp_DrawAreaList(PokedexAppData *pokedexApp);
u32 PokedexApp_GetAreaListEntryMsg(PokedexAppData *pokedexApp, int index);
void PokedexApp_ScrollAreaList(PokedexAppData *pokedexApp, int direction);
void PokedexApp_SetupSizeCheckWindows(PokedexAppData *pokedexApp);
void PokedexApp_FreeSizeCheckWindows(PokedexAppData *pokedexApp);
void PokedexApp_SetupEntryMenuWindows(PokedexAppData *pokedexApp);
void PokedexApp_FreeEntryMenuWindows(PokedexAppData *pokedexApp);
void PokedexApp_SetupFormsWindows(PokedexAppData *pokedexApp);
void PokedexApp_FreeFormsWindows(PokedexAppData *pokedexApp);
void PokedexApp_DrawFormsWindows(PokedexAppData *pokedexApp);
void PokedexApp_DrawFormList(PokedexAppData *pokedexApp);
u32 PokedexApp_GetFormNameMsg(PokedexAppData *pokedexApp, int index);
void PokedexApp_ScrollFormList(PokedexAppData *pokedexApp, int direction);
void PokedexApp_DrawFormsTitle(PokedexAppData *pokedexApp);
void PokedexApp_ClearFormsWindows(PokedexAppData *pokedexApp);
void PokedexApp_DrawFormCompareWindows(PokedexAppData *pokedexApp);
void PokedexApp_ClearFormCompareWindows(PokedexAppData *pokedexApp);
void PokedexApp_DrawCenteredFormName(PokedexAppData *pokedexApp, int windowId, int index);
void PokedexApp_InitSprites(PokedexAppData *pokedexApp);
void PokedexApp_FreeSprites(PokedexAppData *pokedexApp);
void PokedexApp_TickSprites(PokedexAppData *pokedexApp);
void PokedexApp_CreateSpriteSystem(PokedexAppData *pokedexApp);
void PokedexApp_DestroySpriteSystem(PokedexAppData *pokedexApp);
void PokedexApp_DeleteSprite(PokedexAppData *pokedexApp, int index);
void PokedexApp_DeleteAllSprites(PokedexAppData *pokedexApp);
void PokedexApp_LoadSpriteCharData(PokedexAppData *pokedexApp, int index, const void *data, u32 size, NNS_G2D_VRAM_TYPE vram);
void PokedexApp_SetSpriteTranslucent(PokedexAppData *pokedexApp, int index, int enabled);
void PokedexApp_SetSpriteAnim(PokedexAppData *pokedexApp, int index, int anim);
int PokedexApp_IsSpriteAnimating(PokedexAppData *pokedexApp, int index);
void PokedexApp_SetSpriteVisible(PokedexAppData *pokedexApp, int index, int visible);
ManagedSprite *PokedexApp_NewSprite(PokedexAppData *pokedexApp, const ManagedSpriteTemplate *template);
void PokedexApp_MoveSprite(PokedexAppData *pokedexApp, int index, int dx, int dy, int subscreen);
void PokedexApp_SetSpritePos(PokedexAppData *pokedexApp, int index, s16 x, s16 y, int subscreen);
void PokedexApp_GetSpritePos(PokedexAppData *pokedexApp, int index, s16 *x, s16 *y, int subscreen);
void PokedexApp_OpenMonIconNarc(PokedexAppData *pokedexApp);
void PokedexApp_CloseMonIconNarc(PokedexAppData *pokedexApp);
void PokedexApp_LoadMonIconResources(PokedexAppData *pokedexApp, u32 count);
void PokedexApp_UnloadMonIconResources(PokedexAppData *pokedexApp, u32 count);
void PokedexApp_CreateMonIconSprites(PokedexAppData *pokedexApp, int first);
void *PokedexApp_LoadMonIconCharData(PokedexAppData *pokedexApp, u32 species, u32 form, NNSG2dCharacterData **charData);
void PokedexApp_SetMonIconGraphics(PokedexAppData *pokedexApp, const void *data, int index, int palette);
void PokedexApp_SetMonIcon(PokedexAppData *pokedexApp, u32 species, u32 form, int index);
void PokedexApp_SetMonIconSub(PokedexAppData *pokedexApp, u32 species, u32 form, int index);
void PokedexApp_SetListIcon(PokedexAppData *pokedexApp, int entry, int sprite);
void PokedexApp_DrawListIconGrid(PokedexAppData *pokedexApp, int first);
void PokedexApp_ScrollListIconsBackward(PokedexAppData *pokedexApp, int first, int dy, u8 row);
void PokedexApp_ScrollListIconsForward(PokedexAppData *pokedexApp, int first, int dy, u8 row);
void PokedexApp_LoadMonPicResources(PokedexAppData *pokedexApp);
void PokedexApp_UnloadMonPicResources(PokedexAppData *pokedexApp);
void PokedexApp_LoadFormsSpriteResources(PokedexAppData *pokedexApp);
void PokedexApp_UnloadFormsSpriteResources(PokedexAppData *pokedexApp);
void PokedexApp_CreateMonPicSprites(PokedexAppData *pokedexApp, int index);
void PokedexApp_LoadMonPicToSprite(PokedexAppData *pokedexApp, int species, u8 form, u8 gender, u8 facing, int sprite, int mode);
void PokedexApp_SwapMonPic(PokedexAppData *pokedexApp, int species, int index, int old);
void PokedexApp_ShowMonPic(PokedexAppData *pokedexApp, int species, int index, int old);
void PokedexApp_LoadFootprintResources(PokedexAppData *pokedexApp);
void PokedexApp_UnloadFootprintResources(PokedexAppData *pokedexApp);
void PokedexApp_CreateFootprintSprite(PokedexAppData *pokedexApp, int index);
void PokedexApp_UpdateFootprintSprite(PokedexAppData *pokedexApp, u32 species, int entry, int sprite);
void PokedexApp_LoadTypeIconResources(PokedexAppData *pokedexApp);
void PokedexApp_UnloadTypeIconResources(PokedexAppData *pokedexApp);
void PokedexApp_CreateTypeIconSprites(PokedexAppData *pokedexApp, int index);
void PokedexApp_UpdateTypeIcons(PokedexAppData *pokedexApp, u32 species, int entry, int index);
void PokedexApp_SetTypeIconGraphics(PokedexAppData *pokedexApp, int index, u32 type);
void PokedexApp_LoadLanguageIconResources(PokedexAppData *pokedexApp);
void PokedexApp_UnloadLanguageIconResources(PokedexAppData *pokedexApp);
void PokedexApp_LoadLanguageIconResourcesSub(PokedexAppData *pokedexApp);
void PokedexApp_UnloadLanguageIconResourcesSub(PokedexAppData *pokedexApp);
void PokedexApp_CreateSpriteInSlot(PokedexAppData *pokedexApp, int index, const ManagedSpriteTemplate *template);
void PokedexApp_CreateLanguageIconSprites(PokedexAppData *pokedexApp);
void PokedexApp_UpdateCurrentLanguageIcon(PokedexAppData *pokedexApp, u32 species, int sprite);
void PokedexApp_UpdateLanguageIcons(PokedexAppData *pokedexApp, u16 species, int first);
void PokedexApp_LoadMainObjResources(PokedexAppData *pokedexApp);
void PokedexApp_UnloadMainObjResources(PokedexAppData *pokedexApp);
void PokedexApp_LoadSubObjResources(PokedexAppData *pokedexApp);
void PokedexApp_UnloadSubObjResources(PokedexAppData *pokedexApp);
void PokedexApp_SetupListSprites(PokedexAppData *pokedexApp);
void PokedexApp_LoadListSpriteResources(PokedexAppData *pokedexApp);
void PokedexApp_CreateListSprites(PokedexAppData *pokedexApp);
void PokedexApp_SetIntlSpritePairVisible(PokedexAppData *pokedexApp, int index, BOOL visible);
void PokedexApp_SetIntlSpriteVisible(PokedexAppData *pokedexApp, int index, BOOL visible);
void PokedexApp_SetDexModeSwitchPos(PokedexAppData *pokedexApp, int index);
BOOL PokedexApp_IsTouchOnSprite0(PokedexAppData *pokedexApp, u32 x, u32 y);
void PokedexApp_MoveSpriteX(PokedexAppData *pokedexApp, int index, s16 dx);
void PokedexApp_SetSpriteX(PokedexAppData *pokedexApp, int index, s16 x);
s16 PokedexApp_GetDexModeSwitchX(PokedexAppData *pokedexApp);
void PokedexApp_MoveSpriteToListCursor(PokedexAppData *pokedexApp, int sprite);
void PokedexApp_HideListCursor(PokedexAppData *pokedexApp);
void PokedexApp_UpdateListPageArrows(PokedexAppData *pokedexApp, int sprite, int mode);
void PokedexApp_UpdateListScrollbarSize(PokedexAppData *pokedexApp, int sprite, int mode);
int PokedexApp_GetListScrollbarSizeAnim(PokedexAppData *pokedexApp, int mode);
u32 PokedexApp_GetListScrollbarLength(PokedexAppData *pokedexApp, int sprite);
int PokedexApp_GetListScrollbarMinY(PokedexAppData *pokedexApp, int sprite);
int PokedexApp_GetListScrollbarMaxY(PokedexAppData *pokedexApp, int sprite);
BOOL PokedexApp_IsTouchOnListScrollbar(PokedexAppData *pokedexApp, int sprite, u32 x, u32 y);
BOOL PokedexApp_DragListScrollbar(PokedexAppData *pokedexApp, int sprite, u32 x, u32 y, int mode);
int PokedexApp_GetListScrollbarYForPage(PokedexAppData *pokedexApp, int page, int sprite, int mode);
u32 PokedexApp_GetListScrollbarStepCount(PokedexAppData *pokedexApp, int sprite, u32 position, u32 divisor);
void PokedexApp_MoveListScrollbar(PokedexAppData *pokedexApp, int sprite, int dy);
void PokedexApp_SyncListScrollbarToPage(PokedexAppData *pokedexApp, int sprite, int mode);
void PokedexApp_UpdateCaughtMarkSprite(PokedexAppData *pokedexApp, int entry, int sprite);
void PokedexApp_FreeListSprites(PokedexAppData *pokedexApp);
void PokedexApp_SetupSearchSprites(PokedexAppData *pokedexApp);
void PokedexApp_LoadSearchSpriteResources(PokedexAppData *pokedexApp);
void PokedexApp_UnloadSearchSpriteResources(PokedexAppData *pokedexApp);
void PokedexApp_CreateSearchEntrySprites(PokedexAppData *pokedexApp);
void PokedexApp_UnloadSearchEntryResources(PokedexAppData *pokedexApp);
void PokedexApp_CreateSearchSprites(PokedexAppData *pokedexApp);
void PokedexApp_FreeSearchSprites(PokedexAppData *pokedexApp);
void PokedexApp_FreeSprites26And27(PokedexAppData *pokedexApp);
void PokedexApp_UpdateBodyTypeSprite(PokedexAppData *pokedexApp);
void PokedexApp_HideBodyTypeOptionSprites(PokedexAppData *pokedexApp, int hideIcon);
void PokedexApp_SetBodyTypeSpriteLayout(PokedexAppData *pokedexApp, int menu);
void PokedexApp_SetSliderSpritesVisible(PokedexAppData *pokedexApp, int visible);
void PokedexApp_UpdateSliderSprites(PokedexAppData *pokedexApp, u32 min, u32 max, int weight);
void PokedexApp_UpdateSearchSprites(PokedexAppData *pokedexApp, int page);
void PokedexApp_SetHeightSliderX(PokedexAppData *pokedexApp, int x, int index, int moveCursor);
void PokedexApp_SetWeightSliderX(PokedexAppData *pokedexApp, int x, int index, int moveCursor);
void PokedexApp_DrawHeightDigits(PokedexAppData *pokedexApp, int index, u16 height);
void PokedexApp_DrawWeightDigits(PokedexAppData *pokedexApp, int index, u32 weight);
void PokedexApp_UpdateSliderLimitSprites(PokedexAppData *pokedexApp, u32 value, int index);
u32 PokedexApp_GetSliderValue(PokedexAppData *pokedexApp, int index);
int PokedexApp_SliderValueToX(PokedexAppData *pokedexApp, int value);
void PokedexApp_ShowReturningDexModeSwitch(PokedexAppData *pokedexApp);
void PokedexApp_MoveReturningDexModeSwitch(PokedexAppData *pokedexApp, int dx);
void PokedexApp_SetSearchEntrySpritesVisible(PokedexAppData *pokedexApp, BOOL visible);
void PokedexApp_UpdateSearchBodyTypeIcon(PokedexAppData *pokedexApp);
void PokedexApp_MoveSearchSummaryIcons(PokedexAppData *pokedexApp, int dy);
void PokedexApp_ShowSprite25Raised(PokedexAppData *pokedexApp);
void PokedexApp_MoveSprite25Vertically(PokedexAppData *pokedexApp, int dy);
void PokedexApp_ShowSprite25(PokedexAppData *pokedexApp);
void PokedexApp_GetSeenFormAndGender(PokedexAppData *pokedexApp, u32 index, u8 *form, u8 *gender);
void PokedexApp_CreateEntryTabCursor(PokedexAppData *pokedexApp);
void PokedexApp_FreeEntryTabCursor(PokedexAppData *pokedexApp);
void PokedexApp_MoveEntryTabCursor(PokedexAppData *pokedexApp, int index);
void PokedexApp_SetupAreaSprites(PokedexAppData *pokedexApp);
void PokedexApp_FreeAreaSprites(PokedexAppData *pokedexApp);
void PokedexApp_LoadAreaSpriteResources(PokedexAppData *pokedexApp);
void PokedexApp_UnloadAreaSpriteResources(PokedexAppData *pokedexApp);
void PokedexApp_SetupAreaListScrollbar(PokedexAppData *pokedexApp);
void PokedexApp_UpdateTimeOfDayCursor(PokedexAppData *pokedexApp);
void PokedexApp_UpdatePlayerMarker(PokedexAppData *pokedexApp);
void PokedexApp_UpdatePlayerMarkerVisibility(PokedexAppData *pokedexApp);
void PokedexApp_CreateAreaMarkerSprites(PokedexAppData *pokedexApp);
void PokedexApp_GetOverworldMarkerPos(PokedexAppData *pokedexApp, int mapIndex, s16 *outX, s16 *outY, u8 *shape);
void PokedexApp_GetDungeonMarkerPos(PokedexAppData *pokedexApp, u32 mapIndex, s16 *outX, s16 *outY, u8 *shape);
void PokedexApp_UpdateAreaMarkers(PokedexAppData *pokedexApp);
void PokedexApp_HideAreaMarkers(PokedexAppData *pokedexApp);
void PokedexApp_UpdateAreaMarkerPalettes(PokedexAppData *pokedexApp);
void PokedexApp_GetSpecialAreaMarkers(u32 mapId, u32 *specialAreas);
void PokedexApp_PlaceSpecialAreaMarkers(PokedexAppData *pokedexApp, u32 specialAreas, int index);
void PokedexApp_UpdateSpecialAreaMarkers(PokedexAppData *pokedexApp, u32 specialAreas, u32 hiddenSpecialAreas, int index, u32 palette);
BOOL PokedexApp_HitTestSpecialAreaMarkers(PokedexAppData *pokedexApp, u32 start, s32 x, s32 y);
void PokedexApp_SetupSizeCheckSprites(PokedexAppData *pokedexApp);
void PokedexApp_FreeSizeCheckSprites(PokedexAppData *pokedexApp);
void PokedexApp_LoadSizeCheckResources(PokedexAppData *pokedexApp);
void PokedexApp_UnloadSizeCheckResources(PokedexAppData *pokedexApp);
void PokedexApp_SetSizeCheckMonIcons(PokedexAppData *pokedexApp);
void PokedexApp_DrawSizeCheckMonPic(PokedexAppData *pokedexApp);
void PokedexApp_ScaleSizeCheckTrainer(PokedexAppData *pokedexApp);
void PokedexApp_RotatePoint(u16 angle, s16 *x, s16 *y);
void PokedexApp_SetPanSpritePos(PokedexAppData *pokedexApp, int index, u16 angle, s16 x, s16 y);
void PokedexApp_PlaceFigureOnPan(PokedexAppData *pokedexApp, int index, int from);
void PokedexApp_UpdateScalePans(PokedexAppData *pokedexApp, u32 angle);
void PokedexApp_InitWeightCheckAnim(PokedexAppData *pokedexApp, PokedexWeightCheckAnim *anim);
BOOL PokedexApp_DropFiguresOntoPans(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_RunWeightCheckAnim(PokedexWeightCheckAnim *anim);
void PokedexApp_SetBeamRotation(PokedexWeightCheckAnim *anim, s32 speed, s32 accel);
void PokedexApp_SetBeamSwing(PokedexWeightCheckAnim *anim, s32 speed, s32 accel, s32 endSpeed);
BOOL PokedexApp_WeightAnim_Even(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Tip1(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Tip2(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Tip3(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Tip4(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Tip5(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Tip6(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Tip7(PokedexWeightCheckAnim *anim);
void PokedexApp_StartFigureThrow(PokedexWeightCheckAnim *anim, s16 speed, s16 accel);
void PokedexApp_MoveThrownFigure(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_UpdateThrownFigure(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_TipToStop(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Throw1(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Throw2(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Throw3(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Throw4(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Throw5(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Throw6(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Throw7(PokedexWeightCheckAnim *anim);
BOOL PokedexApp_WeightAnim_Throw8(PokedexWeightCheckAnim *anim);
void PokedexApp_SetupFormsSprites(PokedexAppData *pokedexApp);
void PokedexApp_FreeFormsSprites(PokedexAppData *pokedexApp);
void PokedexApp_CreateFormsSprites(PokedexAppData *pokedexApp);
void PokedexApp_ShowFormMonPicsMode0(PokedexAppData *pokedexApp, int index);
void PokedexApp_ShowFormMonPics(PokedexAppData *pokedexApp, int index, int mode);
void PokedexApp_SetFormListIcon(PokedexAppData *pokedexApp, int sprite, int index);
void PokedexApp_DrawFormListIcons(PokedexAppData *pokedexApp);
void PokedexApp_ScrollFormListIcons(PokedexAppData *pokedexApp, int direction);
void PokedexApp_MoveFormListIcons(PokedexAppData *pokedexApp, int dy);
void PokedexApp_UpdateScrollArrows(PokedexAppData *pokedexApp, s8 index, s8 count, int sprite);
void PokedexApp_SetScrollbarSizeAnim(PokedexAppData *pokedexApp, int sprite, int count, const u16 *thresholds, u32 numSizes);
int PokedexApp_GetScrollbarSizeAnim(PokedexAppData *pokedexApp, int count, const u16 *thresholds, u32 numSizes);
u32 PokedexApp_GetScrollbarLength(PokedexAppData *pokedexApp, int sprite, const u8 *lengths);
int PokedexApp_GetScrollbarMinY(PokedexAppData *pokedexApp, int sprite, const u8 *lengths, int centre, u32 trackLength);
int PokedexApp_GetScrollbarMaxY(PokedexAppData *pokedexApp, int sprite, const u8 *lengths, int centre, u32 trackLength);
BOOL PokedexApp_IsTouchOnFormScrollbar(PokedexAppData *pokedexApp, u32 x, u32 y);
BOOL PokedexApp_IsTouchOnAreaScrollbar(PokedexAppData *pokedexApp, u32 x, u32 y);
BOOL PokedexApp_DragFormScrollbar(PokedexAppData *pokedexApp, u32 x, u32 y);
BOOL PokedexApp_DragAreaScrollbar(PokedexAppData *pokedexApp, u32 x, u32 y);
u32 PokedexApp_GetFormScrollbarY(PokedexAppData *pokedexApp, int index);
u32 PokedexApp_GetAreaScrollbarY(PokedexAppData *pokedexApp, int index);
u32 PokedexApp_GetScrollbarStepCount(PokedexAppData *pokedexApp, int sprite, u32 y, u32 step);
void PokedexApp_MoveScrollbar(PokedexAppData *pokedexApp, int sprite, int dy);
void PokedexApp_SyncFormScrollbar(PokedexAppData *pokedexApp);
void PokedexApp_SyncAreaScrollbar(PokedexAppData *pokedexApp);
void PokedexApp_ShowFormListSprites(PokedexAppData *pokedexApp);
void PokedexApp_HideFormListSprites(PokedexAppData *pokedexApp);
void PokedexApp_ShowFormCompareSprites(PokedexAppData *pokedexApp);
void PokedexApp_HideFormCompareSprites(PokedexAppData *pokedexApp);
void PokedexApp_SetCompareFormIcon(PokedexAppData *pokedexApp, int sprite, int index);
void PokedexApp_ShowFormCompareMonPic(PokedexAppData *pokedexApp, int side, int index, int mode);
void PokedexApp_ShowFormCompareMonPicMode0(PokedexAppData *pokedexApp, int side, int index);
void PokedexApp_UpdateFormCompareSelector(PokedexAppData *pokedexApp);
void PokedexApp_SetPlayerMarkerAnim(PokedexAppData *pokedexApp, int inArea);
void PokedexApp_LoadMonPicToBg(PokedexAppData *pokedexApp, u16 species, u8 form, u8 gender, u8 facing);
void PokedexApp_SetMonPicBgAffine(PokedexAppData *pokedexApp, int y, int scale);
int PokedexApp_HandleListMenuInput(PokedexAppData *pokedexApp);
int PokedexApp_HandleListInput(PokedexAppData *pokedexApp, int mode);
void PokedexApp_CreateSearchMenuGrid(PokedexAppData *pokedexApp, int initialPos);
u32 PokedexApp_HandleSearchMenuInput(PokedexAppData *pokedexApp);
void PokedexApp_UpdateSearchMenuCursor(PokedexAppData *pokedexApp, int target);
void PokedexApp_OnSearchMenuGridMove(void *data, int target, int input);
void PokedexApp_OnSearchMenuGridTouch(void *data, int target, int input);
void PokedexApp_CreateSearchOrderGrid(PokedexAppData *pokedexApp);
u32 PokedexApp_HandleSearchOrderInput(PokedexAppData *pokedexApp);
void PokedexApp_UpdateSearchOrderCursor(PokedexAppData *pokedexApp, int target);
void PokedexApp_OnSearchOrderGridMove(void *data, int target, int input);
void PokedexApp_OnSearchOrderGridTouch(void *data, int target, int input);
void PokedexApp_CreateSearchNameGrid(PokedexAppData *pokedexApp);
u32 PokedexApp_HandleSearchNameInput(PokedexAppData *pokedexApp);
void PokedexApp_UpdateSearchNameCursor(PokedexAppData *pokedexApp, int target);
void PokedexApp_OnSearchNameGridMove(void *data, int target, int input);
void PokedexApp_OnSearchNameGridTouch(void *data, int target, int input);
void PokedexApp_CreateSearchTypeGrid(PokedexAppData *pokedexApp);
u32 PokedexApp_HandleSearchTypeInput(PokedexAppData *pokedexApp);
void PokedexApp_UpdateSearchTypeCursor(PokedexAppData *pokedexApp, int target);
void PokedexApp_OnSearchTypeGridMove(void *data, int target, int input);
void PokedexApp_OnSearchTypeGridTouch(void *data, int target, int input);
void PokedexApp_CreateSearchHeightGrid(PokedexAppData *pokedexApp);
u32 PokedexApp_HandleSearchHeightInput(PokedexAppData *pokedexApp);
void PokedexApp_UpdateSearchHeightCursor(PokedexAppData *pokedexApp, int target);
void PokedexApp_OnSearchHeightGridMove(void *data, int target, int input);
void PokedexApp_OnSearchHeightGridTouch(void *data, int target, int input);
void PokedexApp_CreateSearchWeightGrid(PokedexAppData *pokedexApp);
u32 PokedexApp_HandleSearchWeightInput(PokedexAppData *pokedexApp);
void PokedexApp_UpdateSearchWeightCursor(PokedexAppData *pokedexApp, int target);
void PokedexApp_OnSearchWeightGridMove(void *data, int target, int input);
void PokedexApp_OnSearchWeightGridTouch(void *data, int target, int input);
u32 PokedexApp_GetTouchHeldX(u32 *x);
void PokedexApp_CreateSearchAreaGrid(PokedexAppData *pokedexApp);
u32 PokedexApp_HandleSearchAreaInput(PokedexAppData *pokedexApp);
void PokedexApp_UpdateSearchAreaCursor(PokedexAppData *pokedexApp, int target);
void PokedexApp_OnSearchAreaGridMove(void *data, int target, int input);
void PokedexApp_OnSearchAreaGridTouch(void *data, int target, int input);
void PokedexApp_CreateSearchFormGrid(PokedexAppData *pokedexApp);
u32 PokedexApp_HandleSearchFormInput(PokedexAppData *pokedexApp);
void PokedexApp_UpdateSearchFormCursor(PokedexAppData *pokedexApp, int target);
void PokedexApp_OnSearchFormGridMove(void *data, int target, int input);
void PokedexApp_OnSearchFormGridTouch(void *data, int target, int input);
u32 PokedexApp_HandleSearchResultListInput(PokedexAppData *pokedexApp, int mode);
void PokedexApp_FreeGridInput(PokedexAppData *pokedexApp);
void PokedexApp_DummyGridCallback(void *data, int target, int input);
int PokedexApp_HandleEntryTabTouch(PokedexAppData *pokedexApp, u32 *touched);
u32 PokedexApp_HandleAreaInput(PokedexAppData *pokedexApp, u32 *touched);
u32 PokedexApp_HandleSizeCheckInput(PokedexAppData *pokedexApp, u32 *touched);
u32 PokedexApp_HandleFormsInput(PokedexAppData *pokedexApp, u32 *touched);
u32 PokedexApp_HandleFormCompareInput(PokedexAppData *pokedexApp, u32 *touched);
u32 PokedexApp_HandleEntryMenuInput(PokedexAppData *pokedexApp, u32 *touched);
BOOL PokedexApp_RunSearch(PokedexAppData *pokedexApp, u8 natDexFlag, u32 order, u32 letter, u32 type1, u32 type2, u32 heightMin, u32 heightMax, u32 weightMin, u32 weightMax, u32 areaMask, u32 bodyType);
u16 *PokedexApp_LoadSortData(u32 index, u32 *count);
void PokedexApp_FilterSeen(u16 *dst, u32 *count, const Pokedex *pokedex, const u16 *src, u32 length);
void PokedexApp_StoreSearchResults(PokedexSearchResults *result, const Pokedex *pokedex, const u16 *src, u32 count);
void PokedexApp_ApplySortOrder(u32 order, u16 *dst, u32 *dstCount, const u16 *src, u32 srcCount, const Pokedex *pokedex);
void PokedexApp_FilterByLetter(u32 letter, u16 *dst, u32 *dstCount, const u16 *src, u32 srcCount, const Pokedex *pokedex);
void PokedexApp_FilterByType(u32 type, u16 *dst, u32 *dstCount, const u16 *src, u32 srcCount, const Pokedex *pokedex);
void PokedexApp_FilterByBodyType(u32 bodyType, u16 *dst, u32 *dstCount, const u16 *src, u32 srcCount, const Pokedex *pokedex);
void PokedexApp_FilterByArea(PokedexAppData *pokedexApp, u32 areaMask, u16 *dst, u32 *count, const u16 *src, u32 srcCount, const Pokedex *pokedex);
void PokedexApp_FilterByHeight(PokedexAppData *pokedexApp, u16 min, u16 max, u16 *dst, u32 *count, const u16 *src, u32 srcCount, const Pokedex *pokedex);
void PokedexApp_FilterByWeight(PokedexAppData *pokedexApp, u16 min, u16 max, u16 *dst, u32 *count, const u16 *src, u32 srcCount, const Pokedex *pokedex);
void PokedexApp_IntersectSpeciesLists(u16 *dst, u32 *count, const u16 *lookup, u32 lookupCount, const u16 *src, u32 srcCount, BOOL seenOnly, const Pokedex *pokedex);
u32 PokedexApp_GetListCursorIndex(PokedexAppData *pokedexApp);
u16 PokedexApp_GetCursorSpecies(PokedexAppData *pokedexApp);
u32 PokedexApp_FindSpeciesInResults(PokedexSearchResults *results, u16 species);
void PokedexApp_BuildListEntries(PokedexAppData *pokedexApp, int mode);
u32 PokedexApp_GetListLength(PokedexAppData *pokedexApp, int mode);
u32 PokedexApp_GetLastListPage(PokedexAppData *pokedexApp, int mode);
u32 PokedexApp_IdentityU32(u32 value);

typedef struct PokedexWeightRange {
    u16 min;
    u16 max;
} PokedexWeightRange;

extern const OamManagerParam gPokedexOamManagerParam;
extern const OamCharTransferParam gPokedexOamCharTransferParam;
extern const SpriteResourceCountsListUnion gSpriteResourceCapacities;
extern const ManagedSpriteTemplate gMonIconSpriteTemplate;
extern const ManagedSpriteTemplate gPokedexMonPicSpriteTemplate0; // Pokemon picture, first of the pair
extern const ManagedSpriteTemplate gPokedexMonPicSpriteTemplate1; // Pokemon picture, second of the pair
extern const TileRect gPokedexMonPicSpriteRect;
extern const ManagedSpriteTemplate gFootprintSpriteTemplate;
extern const ManagedSpriteTemplate gTypeIconSpriteTemplate;
extern const ManagedSpriteTemplate gLanguageIconSpriteTemplate;
extern const ManagedSpriteTemplate gPokedexLanguageIconSpriteTemplate;
extern const ManagedSpriteTemplate gPokedexListSpriteTemplates[]; // the list screen's 8 main-screen sprites
extern const ManagedSpriteTemplate gPokedexListSprite9Template;
extern const ManagedSpriteTemplate gPokedexListSprite10Template;
extern const u16 gListScrollbarSizeThresholds[];
extern const u8 gPokedexScrollbarLengths[];                         // scrollbar length per size animation
extern const ManagedSpriteTemplate gPokedexSearchSpriteTemplates[]; // search menu sprites 0-25
extern const ManagedSpriteTemplate gPokedexSearchSprite43Template;
extern const ManagedSpriteTemplate gPokedexSearchSprite26Template;
extern const ManagedSpriteTemplate gPokedexSearchSprite27Template;
extern const ManagedSpriteTemplate gPokedexBodyTypeIconSpriteTemplate; // body type icons
extern const ManagedSpriteTemplate gPokedexEntryTabCursorSpriteTemplate;
extern const ManagedSpriteTemplate gPokedexAreaSpriteTemplates[]; // area screen sprites 1-8

extern const ManagedSpriteTemplate gPokedexFormsSpriteTemplates[];
extern const u16 gPokedexFormScrollbarSizeSteps[];
extern const u8 gPokedexAreaScrollbarLengths[]; // area list scrollbar length per size animation
extern const TileRect gPokedexMonPicBgRect;
extern const u16 gPokedexMonPicBgTilemap[];

extern const u16 gPokedexAreaScrollbarSizeSteps[];
extern u8 gPokedexAreaMarkerSizes[][2]; // width and height of each area marker shape
extern const ManagedSpriteTemplate gAreaMarkerSpriteTemplate;

extern const ManagedSpriteTemplate gPokedexSizeCheckSpriteTemplates[];
extern PokedexWeightRange gWeightCheckDiffRanges[];
extern BOOL (*const gWeightCheckAnimFuncs[])(PokedexWeightCheckAnim *anim);

#endif // GUARD_POKEHEARTGOLD_APPLICATION_POKEDEX_POKEDEX_INTERNAL_H
