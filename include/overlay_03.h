#ifndef POKEHEARTGOLD_OVERLAY_03_H
#define POKEHEARTGOLD_OVERLAY_03_H

#include "field/field_sprite_manager.h"
#include "pokeathlon/pokeathlon_save.h"

#include "bag_types_def.h"
#include "dex_mon_measures.h"
#include "game_stats.h"
#include "list_menu.h"
#include "mart.h"
#include "safari_zone.h"
#include "save_vars_flags.h"
#include "script.h"
#include "apricorn_box.h"

enum PokeathlonData {
    OVERALL_DATA,
    EVENT_DATA,
    ACTION_DATA
};

enum MartTypes {
    MART_TYPE_NORMAL = 0,
    MART_TYPE_1, // MART_TYPE_DECOR?
    MART_TYPE_SEAL,
    MART_TYPE_3, // MART_TYPE_FRONTIER?
    MART_TYPE_4, // MART_TYPE_POKEATHLON?
};

enum BattleRegulationValidationResult {
    BATTLE_REGULATION_VALIDATION_RESULT_SUCCESS = 0,
    BATTLE_REGULATION_VALIDATION_RESULT_TOTAL_LEVEL_EXCEEDED,
    BATTLE_REGULATION_VALIDATION_RESULT_DUPLICATE_SPECIES,
    BATTLE_REGULATION_VALIDATION_RESULT_DUPLICATE_ITEMS,
    BATTLE_REGULATION_VALIDATION_RESULT_INVALID_TEAM_SIZE,
    BATTLE_REGULATION_VALIDATION_RESULT_INVALID_POKEMON,
};

typedef struct MartButtonPressAnim {
    u8 unk0[4];
} MartButtonPressAnim;

typedef struct MartData {
    BgConfig *bgConfig;
    BagView *bagView;
    Window windows[6];
    u8 unk68[0x20];
    MsgData *messageData;
    MessageFormat *messageFormat;
    Camera *camera;
    FieldSpriteManager fieldSpriteManager;
    Sprite *sprites[19];
    u16 spriteDrawn[2]; // Draw flags for sprites 0 and 1.
    PlayerProfile *playerProfile;
    void *inventory;
    Options *options;
    PokeathlonSave *pokeathlonSave;
    SaveApricornBox *apricornBox;
    GameStats *gameStats;
    SaveVarsFlags *varsFlags;
    u32 unk264;
    u16 *itemIds;
    const struct MartItem *priceOverrides;
    u8 numItems;
    u8 pageStart;
    u8 state;
    u8 sellOnly;
    String *string;
    u8 bgPriority[4];
    u32 engineAPlanes;
    u8 printerID;
    u8 unk281;
    u8 unk282;
    u8 martType;
    u16 item;
    s16 quantity;
    u16 maxQuantity;
    u16 unk28A;
    int cost;
    int cursorPos;
    u32 touchButton;
    u32 touchMartAction;
    MartButtonPressAnim buttonPressAnim;
    u16 *result;
} MartData;

void CommClub_StartJoin(FieldSystem *fieldSystem, u32 commType, u16 course, u16 arg3);
void CommClub_OnChildStarted();
u32 CommClub_PollJoinResult();
void CommClub_StartHost(FieldSystem *fieldSystem, u32 commType, u16 course, u16 arg3);
void CommClub_OnParentConnected();
u32 CommClub_PollHostResult();

void StartTask_BattleRegulationMenu(TaskManager *taskManager, u16 *result);
void BattleRegulation_BufferName(FieldSystem *fieldSystem, MessageFormat *messageFormat, u32 ruleset);
void BattleRegulation_SetActiveRuleset(FieldSystem *fieldSystem, u16 rulesetIndex);
void BattleRegulation_PrintRulesWindow(FieldSystem *fieldSystem, Window *window, u32 ruleset);
u16 BattleRegulation_CheckParty(FieldSystem *fieldSystem, MessageFormat *msgFmt, u32 ruleset);
u32 BattleRegulation_GetLinkModeOffset(int);

BOOL Task_Mart(TaskManager *taskManager);
int MartData_CheckCannotBuy(MartData *data, u32 money);
int MartData_GetOwnedQuantity(MartData *data, int itemID);
u32 MartData_GetItemPrice(MartData *data, u16 itemID);
void MartData_CreateSprites(MartData *data);
void CustomSafariLink_ExchangeAreaSets(FieldSystem *fieldSystem);
void PokeathlonRecords_Show(TaskManager *taskManager, enum PokeathlonData data);

#endif // POKEHEARTGOLD_OVERLAY_03_H
