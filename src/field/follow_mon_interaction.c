#include "global.h"

#include "constants/global_fieldmap.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/scrcmd.h"
#include "constants/sndseq.h"
#include "constants/species.h"
#include "constants/sprites.h"
#include "constants/weather.h"

#include "field/bottom_screen_app.h"
#include "field/field_effect_helpers.h"
#include "field/map_object_billboard_motion.h"
#include "field/map_object_models.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0040.h"
#include "overlay_2/overlay_02_field_utils.h"

#include "bg_window.h"
#include "dialog_box.h"
#include "fashion_case.h"
#include "field_system.h"
#include "field_terrain.h"
#include "field_time_events.h"
#include "filesystem.h"
#include "follow_mon.h"
#include "heap.h"
#include "item.h"
#include "map_events.h"
#include "map_events_internal.h"
#include "map_header.h"
#include "map_object.h"
#include "map_object_movement_commands.h"
#include "math_util.h"
#include "message_format.h"
#include "metatile_behavior.h"
#include "msgdata.h"
#include "overlay_01.h"
#include "overlay_02.h"
#include "party.h"
#include "player_avatar.h"
#include "player_data.h"
#include "pm_string.h"
#include "pokemon.h"
#include "render_window.h"
#include "save_local_field_data.h"
#include "save_vars_flags.h"
#include "script_manager.h"
#include "script_pokemon_util.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "sys_flags.h"
#include "system.h"
#include "task.h"

// What the following Pokemon and its surroundings look like when the player talks to it; compared against the
// conditions of the interaction tables (FollowMonRule) to pick an interaction script.
typedef struct FollowMonSituation {
    u8 hasHeldItem;
    u8 heldItemPocket;
    u8 hpBucket;
    u8 status;
    u8 level;
    u8 type1;
    u8 type2;
    u8 friendship;
    u8 natureGroup;
    u8 gender;
    u8 speciesAttr;
    u8 shinyLeaves;
    u8 nearbyObjects;
    u8 hiddenItems;
    u8 nearBreakableRock;
    u8 nearRock;
    u8 nearTree;
    u8 weather;
    u8 metatileBehavior;
    u8 encounterTile;
    u8 timeOfDay;
    s8 mood;
    u8 pokeathlonStat;
    u8 facing;
    u8 padding_18[2];
    u16 mapId;
} FollowMonSituation;

// FollowMonSituation.heldItemPocket / FollowMonRule.heldItem
enum FollowMonPocket {
    FOLLOW_MON_POCKET_BALLS = 1,
    FOLLOW_MON_POCKET_MEDICINE,
    FOLLOW_MON_POCKET_BATTLE_ITEMS,
    FOLLOW_MON_POCKET_ITEMS,
    FOLLOW_MON_POCKET_MAIL,
    FOLLOW_MON_POCKET_BERRIES,
    FOLLOW_MON_POCKET_TMHMS,
    FOLLOW_MON_POCKET_NONE,
    FOLLOW_MON_POCKET_ANY,
};

// FollowMonSituation.hpBucket / FollowMonRule.hp
enum FollowMonHpBucket {
    FOLLOW_MON_HP_FULL = 1,
    FOLLOW_MON_HP_HIGH,
    FOLLOW_MON_HP_HALF,
    FOLLOW_MON_HP_LOW,
    FOLLOW_MON_HP_VERY_LOW,
};

// FollowMonSituation.status / FollowMonRule.status
enum FollowMonStatus {
    FOLLOW_MON_STATUS_NONE = 1,
    FOLLOW_MON_STATUS_BURN,
    FOLLOW_MON_STATUS_FREEZE,
    FOLLOW_MON_STATUS_PARALYSIS,
    FOLLOW_MON_STATUS_POISON,
    FOLLOW_MON_STATUS_ANY = 7,
    FOLLOW_MON_STATUS_SLEEP,
};

// FollowMonSituation.gender / FollowMonRule.gender
enum FollowMonGender {
    FOLLOW_MON_GENDER_MALE = 1,
    FOLLOW_MON_GENDER_NOT_MALE,
};

// FollowMonSituation.weather / FollowMonRule.weather
enum FollowMonWeather {
    FOLLOW_MON_WEATHER_OTHER,
    FOLLOW_MON_WEATHER_SUNNY,
    FOLLOW_MON_WEATHER_RAIN = 3,
};

// FollowMonSituation.encounterTile / FollowMonRule.encounterTile
enum FollowMonTile {
    FOLLOW_MON_TILE_ENCOUNTERS = 1,
    FOLLOW_MON_TILE_NO_ENCOUNTERS,
};

// FollowMonSituation.timeOfDay / FollowMonRule.timeOfDay
enum FollowMonTimeOfDay {
    FOLLOW_MON_TIME_NONE,
    FOLLOW_MON_TIME_MORN,
    FOLLOW_MON_TIME_DAY,
    FOLLOW_MON_TIME_EVE,
    FOLLOW_MON_TIME_NITE,
    FOLLOW_MON_TIME_LATE,
};

// FollowMonSituation.pokeathlonStat / FollowMonRule.pokeathlonStat
enum FollowMonPokeathlonStat {
    FOLLOW_MON_STAT_POWER = 1,
    FOLLOW_MON_STAT_STAMINA,
    FOLLOW_MON_STAT_SKILL,
    FOLLOW_MON_STAT_JUMP,
    FOLLOW_MON_STAT_SPEED,
};

// FollowMonSituation.facing / FollowMonRule.facing
enum FollowMonFacing {
    FOLLOW_MON_FACING_NONE,
    FOLLOW_MON_FACING_EAST,
    FOLLOW_MON_FACING_WEST,
    FOLLOW_MON_FACING_NORTH,
    FOLLOW_MON_FACING_SOUTH,
};

// FollowMonSituation.type1 / type2, FollowMonRule.type
enum FollowMonType {
    FOLLOW_MON_TYPE_NONE,
    FOLLOW_MON_TYPE_NORMAL,
    FOLLOW_MON_TYPE_FIRE,
    FOLLOW_MON_TYPE_WATER,
    FOLLOW_MON_TYPE_ELECTRIC,
    FOLLOW_MON_TYPE_GRASS,
    FOLLOW_MON_TYPE_ICE,
    FOLLOW_MON_TYPE_FIGHTING,
    FOLLOW_MON_TYPE_POISON,
    FOLLOW_MON_TYPE_GROUND,
    FOLLOW_MON_TYPE_FLYING,
    FOLLOW_MON_TYPE_PSYCHIC,
    FOLLOW_MON_TYPE_BUG,
    FOLLOW_MON_TYPE_ROCK,
    FOLLOW_MON_TYPE_GHOST,
    FOLLOW_MON_TYPE_DRAGON,
    FOLLOW_MON_TYPE_DARK,
    FOLLOW_MON_TYPE_STEEL,
};

// Results of FollowMonInteraction_Run.
enum FollowMonInteractionResult {
    FOLLOW_MON_INTERACTION_RUNNING,
    FOLLOW_MON_INTERACTION_DONE,
    FOLLOW_MON_INTERACTION_QUESTION,
    FOLLOW_MON_INTERACTION_GIVE_ACCESSORY,
    FOLLOW_MON_INTERACTION_GIVE_SHINY_LEAF,
};

// flags of FollowMonInteraction_PrintGiftMessage / FollowMon_ExpandGiftMessage
enum FollowMonGiftMessage {
    FOLLOW_MON_GIFT_LEAF_NOT_GIVEN,
    FOLLOW_MON_GIFT_LEAF_GIVEN,
    FOLLOW_MON_GIFT_ACCESSORY_NOT_GIVEN,
    FOLLOW_MON_GIFT_ACCESSORY_GIVEN,
};

enum FollowMonInteractionState {
    INTERACTION_STATE_START_MOVEMENT,
    INTERACTION_STATE_SHOW_EMOTE,
    INTERACTION_STATE_PRINT_MESSAGE,
    INTERACTION_STATE_START_WAIT,
    INTERACTION_STATE_NEXT_STEP,
    INTERACTION_STATE_RUN_MOVEMENT,
    INTERACTION_STATE_WAIT_MESSAGE,
    INTERACTION_STATE_WAIT,
    INTERACTION_STATE_OPEN_CHOICE = 10,
    INTERACTION_STATE_WAIT_CHOICE_APP,
    INTERACTION_STATE_WAIT_ANSWER,
    INTERACTION_STATE_CLOSE_CHOICE,
};

enum FollowMonInteractionMoveState {
    INTERACTION_MOVE_STATE_LOAD,
    INTERACTION_MOVE_STATE_INIT,
    INTERACTION_MOVE_STATE_NEXT_STEP,
    INTERACTION_MOVE_STATE_STEP,
    INTERACTION_MOVE_STATE_FINISH,
};

enum FollowMonTaskState {
    FOLLOW_MON_TASK_STATE_LOAD_SCRIPT,
    FOLLOW_MON_TASK_STATE_RUN,
    FOLLOW_MON_TASK_STATE_QUESTION,
    FOLLOW_MON_TASK_STATE_GIVE_ACCESSORY,
    FOLLOW_MON_TASK_STATE_GIVE_SHINY_LEAF,
    FOLLOW_MON_TASK_STATE_WAIT_GIFT_MESSAGE,
};

typedef struct ShinyLeafMonDataIds {
    u32 ids[5];
} ShinyLeafMonDataIds;

typedef struct ShinyLeafMasks {
    u8 masks[5];
} ShinyLeafMasks;

typedef struct FollowMonJumpOnSpotEnv {
    u16 count;
    u16 done;
    EventObjectMovementMan *movement;
} FollowMonJumpOnSpotEnv;

typedef struct FollowMonGrowAndShrinkEnv {
    u16 wait;
    u16 frame;
} FollowMonGrowAndShrinkEnv;

extern const ShinyLeafMasks gShinyLeafMasks;
extern const ShinyLeafMonDataIds gShinyLeafMonDataIds;
extern const MovementScriptCommand gFollowMonJumpOnSpotMovements[][5]; // per facing direction
extern const u32 gNatureGroups[];
extern const VecFx32 gFollowMonGrowScale;
extern const VecFx32 gFollowMonShrinkScale;

static int FollowMon_SelectInteraction(FieldSystem *fieldSystem);
static void FollowMon_GetSituation(FieldSystem *fieldSystem, FollowMonSituation *situation);
static BOOL FollowMonRule_Matches(FieldSystem *fieldSystem, const FollowMonRule *rule, const FollowMonSituation *situation);
static void FollowMonSituation_SetMonCondition(Pokemon *mon, FollowMonSituation *situation);
static void FollowMonSituation_SetNearbyObjects(FieldSystem *fieldSystem, FollowMonSituation *situation);
static void FollowMonSituation_SetHiddenItems(FieldSystem *fieldSystem, FollowMonSituation *situation);
static void FollowMonSituation_SetWeather(FieldSystem *fieldSystem, FollowMonSituation *situation);
static void FollowMonSituation_SetTerrain(FieldSystem *fieldSystem, FollowMonSituation *situation);
static void FollowMonSituation_SetMapId(FieldSystem *fieldSystem, FollowMonSituation *situation);
static void FollowMonSituation_SetTimeOfDay(FieldSystem *fieldSystem, FollowMonSituation *situation);
static void FollowMonSituation_SetMood(FieldSystem *fieldSystem, FollowMonSituation *situation);
static void FollowMonSituation_SetBestPokeathlonStat(FieldSystem *fieldSystem, u16 species, u8 form, FollowMonSituation *situation);
static void FollowMonSituation_SetFacing(FieldSystem *fieldSystem, FollowMonSituation *situation);
static void FollowMonSituation_SetSpeciesAttr(int species, FollowMonSituation *situation);
static enum FollowMonType FollowMonSituation_ConvertType(int type);
static enum FollowMonPocket FollowMonSituation_ConvertItemPocket(int pocket);
static void FollowMonInteraction_LoadScript(FollowMonInteraction *interaction, int script);
static enum FollowMonInteractionResult FollowMonInteraction_Run(FieldSystem *fieldSystem, FollowMonInteraction *interaction);
static BOOL FollowMonInteraction_StepHasMovement(FollowMonInteraction *interaction, FollowMonInteractionStep *step);
static BOOL FollowMonInteraction_TryShowEmote(FieldSystem *fieldSystem, FollowMonInteraction *interaction, FollowMonInteractionStep *step);
static BOOL FollowMon_TryPrintInteractionMessage(FieldSystem *fieldSystem, FollowMonInteraction *interaction, FollowMonInteractionStep *step);
static void FollowMonInteraction_PrintGiftMessage(FieldSystem *fieldSystem, FollowMonInteraction *interaction, int flags);
static BOOL FollowMonInteraction_StepHasWait(FollowMonInteraction *interaction, FollowMonInteractionStep *step);
static void FollowMon_ExpandInteractionMessage(FieldSystem *fieldSystem, String *dest, enum HeapID heapId, int msgNo);
static void FollowMon_ExpandGiftMessage(FieldSystem *fieldSystem, String *dest, enum HeapID heapId, int flags, u8 accessory);
static void FollowMonMovement_ApplyOffset(const FollowMonMovementStep *move, LocalMapObject *object);
static void FollowMonMovement_PlaySound(const FollowMonMovementStep *move, u16 sound, u16 species, u8 form);
static void FollowMonMovement_ApplyFacing(FollowMonInteraction *interaction, const FollowMonMovementStep *move, LocalMapObject *object);
static void FollowMon_TryShakeGrass(FollowMonInteraction *interaction, LocalMapObject *object, u8 oldDirection);
static void FollowMon_GetCoordsInDirection(LocalMapObject *object, u32 direction, int *x, int *z);
static BOOL FollowMonMovement_Step(FollowMonInteraction *interaction, LocalMapObject *object);
static BOOL FollowMonMovement_HasNextStep(FollowMonInteraction *interaction);
static BOOL FollowMonInteraction_RunMovement(FieldSystem *fieldSystem, FollowMonInteraction *interaction, int movement);
static BOOL Task_FollowMonInteract(TaskManager *taskManager);
static void FollowMon_PlaceholdersSet(FieldSystem *fieldSystem, MessageFormat *messageFormat);
static void FollowMon_ApplyInteractionEffects(FieldSystem *fieldSystem, FollowMonInteraction *interaction);
BOOL FollowMonRule_CheckFriendship(int rule, int friendship);
BOOL FollowMonRule_CheckMood(int rule, int mood);
BOOL FollowMonRule_CheckSpeciesAttr(u32 rule, u32 value);
BOOL FollowMonRule_CheckShinyLeaf(int leaf, u8 shinyLeaves);
static BOOL Task_FollowMonJumpOnSpot(TaskManager *taskManager);
static BOOL Task_FollowMonGrowAndShrink(TaskManager *taskManager);

void FieldSystem_FollowMonInteract(FieldSystem *fieldSystem) {
    TaskManager_Call(fieldSystem->taskman, Task_FollowMonInteract, NULL);
}

static int FollowMon_SelectInteraction(FieldSystem *fieldSystem) {
    FollowMonSituation situation;
    int order[100];
    int *scan;
    FollowMonRule *rules;
    int i;
    int j;
    int count;
    int *cursor;

    ReadWholeNarcMemberByIdPair(fieldSystem->followMonInteraction->rules, NARC_a_2_2_0, MapHeader_GetMapSec(fieldSystem->location->mapId) + 1);
    ReadWholeNarcMemberByIdPair(&fieldSystem->followMonInteraction->rules[30], NARC_a_2_2_0, 0);
    FollowMon_GetSituation(fieldSystem, &situation);
    rules = fieldSystem->followMonInteraction->rules;

    // Rules 30-41 first, then the map section's rules 0-29, then 42-99.
    count = 0;
    cursor = order;
    for (i = 0; i < 12; i++) {
        *cursor++ = i + 30;
        count++;
    }
    for (i = 0, cursor = &order[count]; i < 30; i++) {
        *cursor++ = i;
        count++;
    }
    for (i = 42, cursor = &order[count]; i < 100; i++) {
        *cursor++ = i;
        count++;
    }

    for (j = 0, scan = order; j < 100; j++, scan++) {
        FollowMonRule *rule = &rules[*scan];
        if (rule->script != 0 && FollowMonRule_Matches(fieldSystem, rule, &situation)) {
            return rule->script;
        }
    }
    GF_ASSERT(FALSE);
    return 0;
}

static void FollowMon_GetSituation(FieldSystem *fieldSystem, FollowMonSituation *situation) {
    Pokemon *mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(fieldSystem->saveData));
    fieldSystem->followMonInteraction->species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    fieldSystem->followMonInteraction->form = GetMonData(mon, MON_DATA_FORM, NULL);
    FollowMonSituation_SetMonCondition(mon, situation);
    FollowMonSituation_SetNearbyObjects(fieldSystem, situation);
    FollowMonSituation_SetHiddenItems(fieldSystem, situation);
    FollowMonSituation_SetWeather(fieldSystem, situation);
    FollowMonSituation_SetTerrain(fieldSystem, situation);
    FollowMonSituation_SetMapId(fieldSystem, situation);
    FollowMonSituation_SetTimeOfDay(fieldSystem, situation);
    FollowMonSituation_SetMood(fieldSystem, situation);
    FollowMonSituation_SetBestPokeathlonStat(fieldSystem, fieldSystem->followMonInteraction->species, fieldSystem->followMonInteraction->form, situation);
    FollowMonSituation_SetFacing(fieldSystem, situation);
    FollowMonSituation_SetSpeciesAttr(fieldSystem->followMonInteraction->species, situation);
}

static BOOL FollowMonRule_Matches(FieldSystem *fieldSystem, const FollowMonRule *rule, const FollowMonSituation *situation) {
    u16 flag;
    u32 nearbyObject;

    if ((int)LCRandom() % 100 >= rule->chance) {
        return FALSE;
    }
    flag = rule->flag;
    if (flag && !Save_VarsFlags_CheckFlagInArray(Save_VarsFlags_Get(fieldSystem->saveData), flag)) {
        return FALSE;
    }
    if (rule->heldItem) {
        if (rule->heldItem == FOLLOW_MON_POCKET_ANY) {
            if (!situation->hasHeldItem) {
                return FALSE;
            }
        } else if (rule->heldItem != situation->heldItemPocket) {
            return FALSE;
        }
    }
    if (rule->hp && rule->hp != situation->hpBucket) {
        return FALSE;
    }
    if (rule->status) {
        if (rule->status == FOLLOW_MON_STATUS_ANY) {
            if (situation->status != FOLLOW_MON_STATUS_BURN && situation->status != FOLLOW_MON_STATUS_FREEZE && situation->status != FOLLOW_MON_STATUS_PARALYSIS && situation->status != FOLLOW_MON_STATUS_POISON && situation->status != FOLLOW_MON_STATUS_SLEEP) {
                return FALSE;
            }
        } else if (rule->status != situation->status) {
            return FALSE;
        }
    }
    if (rule->nearbyObjects) {
        if (rule->nearbyObjects == 5) {
            if (situation->nearbyObjects < 5) {
                return FALSE;
            }
        } else if (rule->nearbyObjects != situation->nearbyObjects) {
            return FALSE;
        }
    }
    if (rule->hiddenItems) {
        if (rule->hiddenItems == 4) {
            if (situation->hiddenItems < 4) {
                return FALSE;
            }
        } else if (rule->hiddenItems != situation->hiddenItems) {
            return FALSE;
        }
    }
    if (rule->level && rule->level != situation->level) {
        return FALSE;
    }
    nearbyObject = rule->nearbyRock;
    if (nearbyObject) {
        if (nearbyObject == 3 && !situation->nearBreakableRock) {
            return FALSE;
        }
        if (nearbyObject == 1 && !situation->nearRock) {
            return FALSE;
        }
        if (nearbyObject == 2) {
            return FALSE;
        }
        return FALSE;
    }
    if (rule->type && rule->type != situation->type1 && rule->type != situation->type2) {
        return FALSE;
    }
    if (rule->weather && rule->weather != situation->weather) {
        return FALSE;
    }
    if (rule->metatileBehavior && rule->metatileBehavior != situation->metatileBehavior) {
        return FALSE;
    }
    if (rule->encounterTile && rule->encounterTile != situation->encounterTile) {
        return FALSE;
    }
    if (rule->mapId && rule->mapId - 1 != situation->mapId) {
        return FALSE;
    }
    if (rule->timeOfDay && rule->timeOfDay != situation->timeOfDay) {
        return FALSE;
    }
    if (rule->mood && !FollowMonRule_CheckMood(rule->mood, situation->mood)) {
        return FALSE;
    }
    if (rule->pokeathlonStat && rule->pokeathlonStat != situation->pokeathlonStat) {
        return FALSE;
    }
    if (rule->friendship && !FollowMonRule_CheckFriendship(rule->friendship, situation->friendship)) {
        return FALSE;
    }
    if (rule->natureGroup && rule->natureGroup != situation->natureGroup) {
        return FALSE;
    }
    if (rule->speciesAttr && !FollowMonRule_CheckSpeciesAttr(rule->speciesAttr, situation->speciesAttr)) {
        return FALSE;
    }
    if (rule->shinyLeaf && !FollowMonRule_CheckShinyLeaf(rule->shinyLeaf, situation->shinyLeaves)) {
        return FALSE;
    }
    if (rule->gender && rule->gender != situation->gender) {
        return FALSE;
    }
    if (rule->facing && rule->facing != situation->facing) {
        return FALSE;
    }
    return TRUE;
}

static void FollowMonSituation_SetMonCondition(Pokemon *mon, FollowMonSituation *situation) {
    ShinyLeafMonDataIds leafIds;
    int item;
    int hp;
    int hpPercent;
    int status;
    int level;
    int type1;
    int type2;
    int i;

    item = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    if (item != ITEM_NONE) {
        situation->hasHeldItem = TRUE;
        situation->heldItemPocket = FollowMonSituation_ConvertItemPocket(GetItemAttr(item, ITEMATTR_FIELD_POCKET, HEAP_ID_FIELD2));
    } else {
        situation->hasHeldItem = FALSE;
        situation->heldItemPocket = FOLLOW_MON_POCKET_NONE;
    }
    hp = GetMonData(mon, MON_DATA_HP, NULL);
    hpPercent = hp * 100 / (int)GetMonData(mon, MON_DATA_MAX_HP, NULL);
    if (hpPercent == 100) {
        situation->hpBucket = FOLLOW_MON_HP_FULL;
    } else if (hpPercent >= 75) {
        situation->hpBucket = FOLLOW_MON_HP_HIGH;
    } else if (hpPercent >= 50) {
        situation->hpBucket = FOLLOW_MON_HP_HALF;
    } else if (hpPercent >= 25) {
        situation->hpBucket = FOLLOW_MON_HP_LOW;
    } else {
        situation->hpBucket = FOLLOW_MON_HP_VERY_LOW;
    }
    status = GetMonData(mon, MON_DATA_STATUS, NULL);
    if (status & (MON_STATUS_PSN_MASK | MON_STATUS_TOX_MASK)) {
        situation->status = FOLLOW_MON_STATUS_POISON;
    } else if (status & MON_STATUS_SLP_MASK) {
        situation->status = FOLLOW_MON_STATUS_SLEEP;
    } else if (status & MON_STATUS_BRN_MASK) {
        situation->status = FOLLOW_MON_STATUS_BURN;
    } else if (status & MON_STATUS_FRZ_MASK) {
        situation->status = FOLLOW_MON_STATUS_FREEZE;
    } else if (status & MON_STATUS_PRZ_MASK) {
        situation->status = FOLLOW_MON_STATUS_PARALYSIS;
    } else if (status == 0) {
        situation->status = FOLLOW_MON_STATUS_NONE;
    } else {
        GF_ASSERT(FALSE);
        situation->status = FOLLOW_MON_STATUS_NONE;
    }
    level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    if (level + 2 >= 50) {
        situation->level = 4;
    } else if (level - 2 <= 50) {
        situation->level = 6;
    } else {
        situation->level = 5;
    }
    type1 = GetMonData(mon, MON_DATA_TYPE_1, NULL);
    type2 = GetMonData(mon, MON_DATA_TYPE_2, NULL);
    situation->type1 = FollowMonSituation_ConvertType(type1);
    situation->type2 = FollowMonSituation_ConvertType(type2);
    situation->friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
    situation->natureGroup = gNatureGroups[GetMonNature(mon)];
    if (GetMonData(mon, MON_DATA_GENDER, NULL) == MON_MALE) {
        situation->gender = FOLLOW_MON_GENDER_MALE;
    } else {
        situation->gender = FOLLOW_MON_GENDER_NOT_MALE;
    }
    leafIds = gShinyLeafMonDataIds;
    situation->shinyLeaves = 0;
    for (i = 0; i < 5; i++) {
        situation->shinyLeaves |= (u8)GetMonData(mon, leafIds.ids[i], NULL) << i;
    }
}

static void FollowMonSituation_SetNearbyObjects(FieldSystem *fieldSystem, FollowMonSituation *situation) {
    LocalMapObject *object;
    int i;
    int count;
    int playerX;
    int playerZ;

    situation->nearbyObjects = 0;
    situation->nearBreakableRock = 0;
    situation->nearRock = 0;
    situation->nearTree = 0;
    playerX = PlayerAvatar_GetXCoord(fieldSystem->playerAvatar);
    playerZ = PlayerAvatar_GetZCoord(fieldSystem->playerAvatar);
    count = MapObjectManager_GetObjectCount(fieldSystem->mapObjectManager);
    object = MapObjectManager_GetObjects(fieldSystem->mapObjectManager);
    for (i = 0; i < count; i++) {
        if (MapObject_CheckActive(object) == TRUE) {
            int x = MapObject_GetXCoord(object);
            int z = MapObject_GetZCoord(object);
            int dx = playerX - x;
            int dz = playerZ - z;
            u32 sprite = MapObject_GetSpriteID(object);
            if (sprite == SPRITE_ROCK) {
                situation->nearRock = TRUE;
            } else if (sprite == SPRITE_BREAKROCK) {
                situation->nearBreakableRock = TRUE;
            } else if (sprite == SPRITE_TREE) {
                situation->nearTree = TRUE;
            } else if (dx >= -1 && dx <= 1 && dz >= -1 && dz <= 1) {
                u32 id = MapObject_GetID(object);
                if (id != obj_partner_poke && id != obj_player) {
                    situation->nearbyObjects++;
                }
            }
        }
        MapObjectArray_NextObject2(&object);
    }
}

static void FollowMonSituation_SetHiddenItems(FieldSystem *fieldSystem, FollowMonSituation *situation) {
    int count = 0;
    BgEvent *events = Field_GetBgEvents(fieldSystem);
    int numEvents = Field_GetNumBgEvents(fieldSystem);
    int i;

    if (numEvents != 0 && events != NULL) {
        for (i = 0; i < numEvents; i++) {
            if (events->type == BG_TYPE_HIDDEN_ITEM && !FieldSystem_FlagCheck(fieldSystem, HiddenItemScriptNoToFlagId(events->scriptId))) {
                count++;
            }
            events++;
        }
    }
    situation->hiddenItems = count;
}

static void FollowMonSituation_SetWeather(FieldSystem *fieldSystem, FollowMonSituation *situation) {
    switch (LocalFieldData_GetWeatherType(Save_LocalFieldData_Get(fieldSystem->saveData))) {
    case WEATHER_SUNNY:
        situation->weather = FOLLOW_MON_WEATHER_SUNNY;
        break;
    case WEATHER_RAIN:
        situation->weather = FOLLOW_MON_WEATHER_RAIN;
        break;
    default:
        situation->weather = FOLLOW_MON_WEATHER_OTHER;
        break;
    }
}

static void FollowMonSituation_SetTerrain(FieldSystem *fieldSystem, FollowMonSituation *situation) {
    int x = MapObject_GetXCoord(FollowMon_GetMapObject(fieldSystem));
    int z = MapObject_GetZCoord(FollowMon_GetMapObject(fieldSystem));
    u8 behavior = GetMetatileBehavior(fieldSystem, x, z);
    situation->metatileBehavior = behavior;
    fieldSystem->followMonInteraction->metatileBehavior = behavior;
    if (MetatileBehavior_CanGenerateWalkingEncounters(behavior)) {
        situation->encounterTile = FOLLOW_MON_TILE_ENCOUNTERS;
    } else {
        situation->encounterTile = FOLLOW_MON_TILE_NO_ENCOUNTERS;
    }
}

static void FollowMonSituation_SetMapId(FieldSystem *fieldSystem, FollowMonSituation *situation) {
    situation->mapId = fieldSystem->location->mapId;
}

static void FollowMonSituation_SetTimeOfDay(FieldSystem *fieldSystem, FollowMonSituation *situation) {
    switch (Field_GetTimeOfDay(fieldSystem)) {
    case RTC_TIMEOFDAY_MORN:
        situation->timeOfDay = FOLLOW_MON_TIME_MORN;
        break;
    case RTC_TIMEOFDAY_DAY:
        situation->timeOfDay = FOLLOW_MON_TIME_DAY;
        break;
    case RTC_TIMEOFDAY_EVE:
        situation->timeOfDay = FOLLOW_MON_TIME_EVE;
        break;
    case RTC_TIMEOFDAY_NITE:
        situation->timeOfDay = FOLLOW_MON_TIME_NITE;
        break;
    case RTC_TIMEOFDAY_LATE:
        situation->timeOfDay = FOLLOW_MON_TIME_LATE;
        break;
    default:
        GF_ASSERT(FALSE);
        situation->timeOfDay = FOLLOW_MON_TIME_NONE;
        break;
    }
}

static void FollowMonSituation_SetMood(FieldSystem *fieldSystem, FollowMonSituation *situation) {
    situation->mood = FollowMonMood_Get(fieldSystem->followMonMood);
}

static void FollowMonSituation_SetBestPokeathlonStat(FieldSystem *fieldSystem, u16 species, u8 form, FollowMonSituation *situation) {
    PartyExtraSub aprijuice;
    struct PokeathlonPerformanceStars stars;
    enum FollowMonPokeathlonStat stat;
    u32 best;
    Party *party = SaveArray_Party_Get(fieldSystem->saveData);
    u8 slot = GetIdxOfFirstAliveMonInParty_CrashIfNone(party);

    Party_GetMonAprijuiceModifiers(party, &aprijuice, slot);
    CalcMonPokeathlonStars(&stars, Party_GetMonByIndex(party, slot), (s8 *)&aprijuice, HEAP_ID_FIELD2);
    best = stars.power;
    stat = FOLLOW_MON_STAT_POWER;
    if (best < stars.stamina) {
        best = stars.stamina;
        stat = FOLLOW_MON_STAT_STAMINA;
    }
    if (best < stars.jump) {
        best = stars.jump;
        stat = FOLLOW_MON_STAT_JUMP;
    }
    if (best < stars.skill) {
        best = stars.skill;
        stat = FOLLOW_MON_STAT_SKILL;
    }
    if (best < stars.speed) {
        stat = FOLLOW_MON_STAT_SPEED;
    }
    situation->pokeathlonStat = stat;
}

static void FollowMonSituation_SetFacing(FieldSystem *fieldSystem, FollowMonSituation *situation) {
    switch (MapObject_GetFacingDirection(fieldSystem->followMon.mapObject)) {
    case DIR_NORTH:
        situation->facing = FOLLOW_MON_FACING_NORTH;
        break;
    case DIR_SOUTH:
        situation->facing = FOLLOW_MON_FACING_SOUTH;
        break;
    case DIR_WEST:
        situation->facing = FOLLOW_MON_FACING_WEST;
        break;
    case DIR_EAST:
        situation->facing = FOLLOW_MON_FACING_EAST;
        break;
    default:
        situation->facing = FOLLOW_MON_FACING_NONE;
        break;
    }
}

static void FollowMonSituation_SetSpeciesAttr(int species, FollowMonSituation *situation) {
    u8 *attrs;
    if (species <= SPECIES_NONE || species > SPECIES_ARCEUS) {
        GF_ASSERT(FALSE);
        return;
    }
    attrs = AllocAtEndAndReadWholeNarcMemberByIdPair(NARC_a_2_3_1, 0, HEAP_ID_FIELD2);
    situation->speciesAttr = attrs[species - 1];
    Heap_Free(attrs);
}

static enum FollowMonType FollowMonSituation_ConvertType(int type) {
    switch (type) {
    case TYPE_NORMAL:
        return FOLLOW_MON_TYPE_NORMAL;
    case TYPE_FIGHTING:
        return FOLLOW_MON_TYPE_FIGHTING;
    case TYPE_FLYING:
        return FOLLOW_MON_TYPE_FLYING;
    case TYPE_POISON:
        return FOLLOW_MON_TYPE_POISON;
    case TYPE_GROUND:
        return FOLLOW_MON_TYPE_GROUND;
    case TYPE_ROCK:
        return FOLLOW_MON_TYPE_ROCK;
    case TYPE_BUG:
        return FOLLOW_MON_TYPE_BUG;
    case TYPE_GHOST:
        return FOLLOW_MON_TYPE_GHOST;
    case TYPE_STEEL:
        return FOLLOW_MON_TYPE_STEEL;
    case TYPE_FIRE:
        return FOLLOW_MON_TYPE_FIRE;
    case TYPE_WATER:
        return FOLLOW_MON_TYPE_WATER;
    case TYPE_GRASS:
        return FOLLOW_MON_TYPE_GRASS;
    case TYPE_ELECTRIC:
        return FOLLOW_MON_TYPE_ELECTRIC;
    case TYPE_PSYCHIC:
        return FOLLOW_MON_TYPE_PSYCHIC;
    case TYPE_ICE:
        return FOLLOW_MON_TYPE_ICE;
    case TYPE_DRAGON:
        return FOLLOW_MON_TYPE_DRAGON;
    case TYPE_DARK:
        return FOLLOW_MON_TYPE_DARK;
    }
    GF_ASSERT(FALSE);
    return FOLLOW_MON_TYPE_NONE;
}

static enum FollowMonPocket FollowMonSituation_ConvertItemPocket(int pocket) {
    switch (pocket) {
    case POCKET_ITEMS:
        return FOLLOW_MON_POCKET_ITEMS;
    case POCKET_MEDICINE:
        return FOLLOW_MON_POCKET_MEDICINE;
    case POCKET_BALLS:
        return FOLLOW_MON_POCKET_BALLS;
    case POCKET_TMHMS:
        return FOLLOW_MON_POCKET_TMHMS;
    case POCKET_BERRIES:
        return FOLLOW_MON_POCKET_BERRIES;
    case POCKET_MAIL:
        return FOLLOW_MON_POCKET_MAIL;
    case POCKET_BATTLE_ITEMS:
        return FOLLOW_MON_POCKET_BATTLE_ITEMS;
    default:
        GF_ASSERT(FALSE);
        return FOLLOW_MON_POCKET_NONE;
    }
}

FollowMonInteraction *FollowMonInteraction_New(enum HeapID heapId) {
    FollowMonInteraction *interaction = Heap_Alloc(heapId, sizeof(FollowMonInteraction));
    MI_CpuFill8(interaction, 0, sizeof(FollowMonInteraction));
    return interaction;
}

static void FollowMonInteraction_LoadScript(FollowMonInteraction *interaction, int script) {
    int i;

    ReadWholeNarcMemberByIdPair(interaction->steps, NARC_a_2_2_1, script - 1);
    interaction->movementState = INTERACTION_MOVE_STATE_LOAD;
    interaction->state = INTERACTION_STATE_START_MOVEMENT;
    interaction->movementIndex = 0;
    interaction->stepIndex = 0;
    interaction->movementFrame = 0;
    interaction->waitFrames = 0;
    interaction->printerId = 0;
    for (i = 0; i < 5; i++) {
        if (interaction->steps[i].movement == 0xFFFF) {
            break;
        }
    }
    interaction->stepCount = i;
}

void FollowMonInteraction_Delete(FollowMonInteraction *interaction) {
    Heap_Free(interaction);
}

static inline enum FollowMonInteractionResult FollowMonInteraction_Finish(FieldSystem *fieldSystem, FollowMonInteraction *interaction) {
    FollowMon_ApplyInteractionEffects(fieldSystem, interaction);
    if (interaction->askQuestion) {
        return FOLLOW_MON_INTERACTION_QUESTION;
    }
    if (interaction->accessory) {
        return FOLLOW_MON_INTERACTION_GIVE_ACCESSORY;
    }
    if (interaction->shinyLeaf) {
        return FOLLOW_MON_INTERACTION_GIVE_SHINY_LEAF;
    }
    return FOLLOW_MON_INTERACTION_DONE;
}

static inline void FollowMonInteraction_CloseMessage(FieldSystem *fieldSystem, FollowMonInteraction *interaction) {
    ClearFrameAndWindow2(&interaction->window, FALSE);
    RemoveWindow(&interaction->window);
    String_Delete(interaction->string);
    fieldSystem->textbox_open = FALSE;
    interaction->state = INTERACTION_STATE_START_WAIT;
}

static enum FollowMonInteractionResult FollowMonInteraction_Run(FieldSystem *fieldSystem, FollowMonInteraction *interaction) {
    FollowMonInteractionStep *step;
    u16 movement;
    u32 index = interaction->stepIndex;

    if (index >= NELEMS(interaction->steps)) {
        return FollowMonInteraction_Finish(fieldSystem, interaction);
    }
    step = &interaction->steps[index];
    movement = step->movement;
    if (movement == 0xFFFF) {
        return FollowMonInteraction_Finish(fieldSystem, interaction);
    }
    switch (interaction->state) {
    case INTERACTION_STATE_START_MOVEMENT:
        if (FollowMonInteraction_StepHasMovement(interaction, step)) {
            MapObject_UnpauseMovement(fieldSystem->followMon.mapObject);
            interaction->movementState = INTERACTION_MOVE_STATE_LOAD;
            interaction->state = INTERACTION_STATE_RUN_MOVEMENT;
            break;
        }
    case INTERACTION_STATE_SHOW_EMOTE:
        if (FollowMonInteraction_TryShowEmote(fieldSystem, interaction, step)) {
            MapObject_UnpauseMovement(fieldSystem->followMon.mapObject);
            interaction->state = INTERACTION_STATE_PRINT_MESSAGE;
            break;
        }
    case INTERACTION_STATE_PRINT_MESSAGE:
        if (FollowMon_TryPrintInteractionMessage(fieldSystem, interaction, step)) {
            MapObject_PauseMovement(fieldSystem->followMon.mapObject);
            interaction->state = INTERACTION_STATE_WAIT_MESSAGE;
            break;
        }
    case INTERACTION_STATE_START_WAIT:
        if (FollowMonInteraction_StepHasWait(interaction, step)) {
            interaction->state = INTERACTION_STATE_WAIT;
            break;
        }
    case INTERACTION_STATE_NEXT_STEP:
        interaction->stepIndex = (u8)(interaction->stepIndex + 1);
        interaction->state = INTERACTION_STATE_START_MOVEMENT;
        break;
    case INTERACTION_STATE_RUN_MOVEMENT:
        if (FollowMonInteraction_RunMovement(fieldSystem, interaction, movement)) {
            interaction->state = INTERACTION_STATE_SHOW_EMOTE;
        }
        break;
    case INTERACTION_STATE_WAIT_MESSAGE:
        if (DialogBox_IsPrintFinished(interaction->printerId) == TRUE) {
            if (interaction->stepCount > interaction->stepIndex + 1) {
                if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
                    FollowMonInteraction_CloseMessage(fieldSystem, interaction);
                }
            } else {
                if (interaction->askQuestion) {
                    interaction->state = INTERACTION_STATE_START_WAIT;
                } else if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
                    FollowMonInteraction_CloseMessage(fieldSystem, interaction);
                }
            }
        }
        break;
    case INTERACTION_STATE_WAIT:
        if (interaction->waitFrames >= step->wait) {
            interaction->stepIndex = (u8)(interaction->stepIndex + 1);
            interaction->state = INTERACTION_STATE_START_MOVEMENT;
        } else {
            interaction->waitFrames++;
        }
        break;
    }
    return FOLLOW_MON_INTERACTION_RUNNING;
}

static BOOL FollowMonInteraction_StepHasMovement(FollowMonInteraction *interaction, FollowMonInteractionStep *step) {
    return step->movement != 0;
}

static BOOL FollowMonInteraction_TryShowEmote(FieldSystem *fieldSystem, FollowMonInteraction *interaction, FollowMonInteractionStep *step) {
    u8 emote;
    if (MetatileBehavior_Is113Or114Or46(fieldSystem->followMonInteraction->metatileBehavior)) {
        return FALSE;
    }
    emote = step->emote;
    if (emote != 0) {
        if (emote > 14) {
            return FALSE;
        }
        FieldSystem_ShowEmoteBubble(fieldSystem, fieldSystem->followMon.mapObject, emote - 1);
        return TRUE;
    }
    return FALSE;
}

static BOOL FollowMon_TryPrintInteractionMessage(FieldSystem *fieldSystem, FollowMonInteraction *interaction, FollowMonInteractionStep *step) {
    Options *options;
    if (step->message != 0) {
        interaction->string = String_New(1024, HEAP_ID_FIELD2);
        DialogBox_AddWindowToLayer3(fieldSystem->bgConfig, &interaction->window, GF_BG_LYR_MAIN_3);
        FollowMon_ExpandInteractionMessage(fieldSystem, interaction->string, HEAP_ID_FIELD2, step->message - 1);
        options = Save_PlayerData_GetOptionsAddr(fieldSystem->saveData);
        DialogBox_LoadFrame(&interaction->window, options);
        interaction->printerId = DialogBox_PrintMessage(&interaction->window, interaction->string, options, TRUE);
        fieldSystem->textbox_open = TRUE;
        return TRUE;
    }
    return FALSE;
}

static void FollowMonInteraction_PrintGiftMessage(FieldSystem *fieldSystem, FollowMonInteraction *interaction, int flags) {
    Options *options;
    interaction->string = String_New(1024, HEAP_ID_FIELD2);
    DialogBox_AddWindowToLayer3(fieldSystem->bgConfig, &interaction->window, GF_BG_LYR_MAIN_3);
    FollowMon_ExpandGiftMessage(fieldSystem, interaction->string, HEAP_ID_FIELD2, flags, interaction->accessory);
    options = Save_PlayerData_GetOptionsAddr(fieldSystem->saveData);
    DialogBox_LoadFrame(&interaction->window, options);
    interaction->printerId = DialogBox_PrintMessage(&interaction->window, interaction->string, options, TRUE);
    fieldSystem->textbox_open = TRUE;
}

static BOOL FollowMonInteraction_StepHasWait(FollowMonInteraction *interaction, FollowMonInteractionStep *step) {
    interaction->waitFrames = 0;
    return step->wait != 0;
}

static void FollowMon_ExpandInteractionMessage(FieldSystem *fieldSystem, String *dest, enum HeapID heapId, int msgNo) {
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0265_bin, heapId);
    MessageFormat *messageFormat = MessageFormat_New(heapId);
    String *string;
    FollowMon_PlaceholdersSet(fieldSystem, messageFormat);
    string = NewString_ReadMsgData(msgData, msgNo);
    StringExpandPlaceholders(messageFormat, dest, string);
    String_Delete(string);
    MessageFormat_Delete(messageFormat);
    DestroyMsgData(msgData);
}

// flags: bit 1 set for an accessory, clear for a shiny leaf; bit 0 set when it was given.
static void FollowMon_ExpandGiftMessage(FieldSystem *fieldSystem, String *dest, enum HeapID heapId, int flags, u8 accessory) {
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0040_bin, heapId);
    MessageFormat *messageFormat = MessageFormat_New(heapId);
    String *string;
    int msgNo;
    if (flags & 2) {
        BufferPlayersName(messageFormat, 0, Save_PlayerData_GetProfile(fieldSystem->saveData));
        if (flags & 1) {
            BufferFashionName(messageFormat, 1, accessory - 1);
            msgNo = msg_0040_00032;
        } else {
            BufferFashionNameWithArticle(messageFormat, 1, accessory - 1);
            msgNo = msg_0040_00095;
        }
    } else {
        Pokemon *mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(fieldSystem->saveData));
        BoxPokemon *boxMon = Mon_GetBoxMon(mon);
        BufferPlayersName(messageFormat, 0, Save_PlayerData_GetProfile(fieldSystem->saveData));
        BufferBoxMonNickname(messageFormat, 1, boxMon);
        msgNo = (flags & 1) ? msg_0040_00097 : msg_0040_00098;
    }
    string = NewString_ReadMsgData(msgData, msgNo);
    StringExpandPlaceholders(messageFormat, dest, string);
    String_Delete(string);
    MessageFormat_Delete(messageFormat);
    DestroyMsgData(msgData);
}

static void FollowMonMovement_ApplyOffset(const FollowMonMovementStep *move, LocalMapObject *object) {
    VecFx32 pos;
    u32 species;
    MapObject_CopyPositionVector(object, &pos);
    if (move->dx != 0) {
        pos.x += move->dx << FX32_SHIFT;
    }
    if (move->dy != 0) {
        species = FollowMon_GetSpecies(object);
        if (species != SPECIES_DIGLETT && species != SPECIES_DUGTRIO) {
            FollowMonBillboard_AddHeight(object, move->dy);
        }
    }
    if (move->dz != 0) {
        pos.z += move->dz << FX32_SHIFT;
    }
    MapObject_SetPositionVector(object, &pos);
}

static void FollowMonMovement_PlaySound(const FollowMonMovementStep *move, u16 sound, u16 species, u8 form) {
    if (move->playSound == 0 || sound == 0) {
        return;
    }
    if (sound > SEQ_SE_END) {
        PlayCryEx(sound == SEQ_SE_END + 1 ? 0 : 11, species, 0x1FF, 0x1FF, 0x1FF, form);
    } else {
        PlaySE(sound);
    }
}

static void FollowMonMovement_ApplyFacing(FollowMonInteraction *interaction, const FollowMonMovementStep *move, LocalMapObject *object) {
    if (move->facing != 0) {
        u8 direction = MapObject_GetFacingDirection(object);
        MapObject_SetFacingDirectionDirect(object, move->facing - 1);
        FollowMon_TryShakeGrass(interaction, object, direction);
    }
}

// When a large following Pokemon turned while facing east or west, rustle the grass beside it.
static void FollowMon_TryShakeGrass(FollowMonInteraction *interaction, LocalMapObject *object, u8 oldDirection) {
    int x;
    int z;
    int behavior;
    FieldSystem *fieldSystem;
    if (!FollowMonObject_IsLarge(object) || oldDirection == (u8)MapObject_GetFacingDirection(object)) {
        return;
    }
    if (interaction->savedFacing != DIR_WEST && interaction->savedFacing != DIR_EAST) {
        return;
    }
    fieldSystem = MapObject_GetFieldSystem(object);
    FollowMon_GetCoordsInDirection(object, interaction->savedFacing, &x, &z);
    behavior = GetMetatileBehavior(fieldSystem, x, z);
    if (MetatileBehavior_IsTallGrass(behavior) == TRUE) {
        TallGrass_SpawnAt(object, FALSE, x, z, TRUE);
    } else if (MetatileBehavior_IsVeryTallGrass(behavior) == TRUE) {
        VeryTallGrass_SpawnAt(object, FALSE, x, z, TRUE);
    }
}

static void FollowMon_GetCoordsInDirection(LocalMapObject *object, u32 direction, int *x, int *z) {
    *x = MapObject_GetXCoord(object);
    *z = MapObject_GetZCoord(object);
    switch (direction) {
    case DIR_NORTH:
        (*z)++;
        break;
    case DIR_SOUTH:
        (*z)--;
        break;
    case DIR_WEST:
        (*x)++;
        break;
    case DIR_EAST:
        (*x)--;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

static BOOL FollowMonMovement_Step(FollowMonInteraction *interaction, LocalMapObject *object) {
    FollowMonMovementStep *move = &interaction->movements[interaction->movementIndex];
    if (interaction->movementFrame == 0) {
        FollowMonMovement_ApplyOffset(move, object);
        FollowMonMovement_PlaySound(move, interaction->steps[interaction->stepIndex].sound, interaction->species, interaction->form);
        FollowMonMovement_ApplyFacing(interaction, move, object);
    }
    interaction->movementFrame++;
    if (interaction->movementFrame >= move->duration) {
        interaction->movementIndex++;
        return TRUE;
    }
    return FALSE;
}

static BOOL FollowMonMovement_HasNextStep(FollowMonInteraction *interaction) {
    if (interaction->movementIndex >= 10) {
        return FALSE;
    }
    if (interaction->movements[interaction->movementIndex].facing == 0xFF) {
        return FALSE;
    }
    interaction->movementFrame = 0;
    return TRUE;
}

static BOOL FollowMonInteraction_RunMovement(FieldSystem *fieldSystem, FollowMonInteraction *interaction, int movement) {
    u8 direction;
    if (movement == 0) {
        GF_ASSERT(FALSE);
        return TRUE;
    }
    switch (interaction->movementState) {
    case INTERACTION_MOVE_STATE_LOAD:
        ReadWholeNarcMemberByIdPair(interaction->movements, NARC_a_2_2_2, movement - 1);
    case INTERACTION_MOVE_STATE_INIT:
        MapObject_CopyPositionVector(fieldSystem->followMon.mapObject, &interaction->savedPosition);
        interaction->savedFacing = MapObject_GetFacingDirection(fieldSystem->followMon.mapObject);
        FollowMonBillboard_SetHeight(fieldSystem->followMon.mapObject, 0);
        FollowMonBillboard_SetShadowAnchored(fieldSystem->followMon.mapObject, TRUE);
        interaction->movementState = INTERACTION_MOVE_STATE_NEXT_STEP;
        interaction->movementIndex = 0;
        break;
    case INTERACTION_MOVE_STATE_NEXT_STEP:
        if (!FollowMonMovement_HasNextStep(interaction)) {
            interaction->movementState = INTERACTION_MOVE_STATE_FINISH;
            break;
        }
        interaction->movementState = INTERACTION_MOVE_STATE_STEP;
    case INTERACTION_MOVE_STATE_STEP:
        if (FollowMonMovement_Step(interaction, fieldSystem->followMon.mapObject)) {
            interaction->movementState = INTERACTION_MOVE_STATE_NEXT_STEP;
        }
        break;
    case INTERACTION_MOVE_STATE_FINISH:
        direction = MapObject_GetFacingDirection(fieldSystem->followMon.mapObject);
        FollowMonBillboard_SetHeight(fieldSystem->followMon.mapObject, 0);
        FollowMonBillboard_SetShadowAnchored(fieldSystem->followMon.mapObject, FALSE);
        MapObject_SetPositionVector(fieldSystem->followMon.mapObject, &interaction->savedPosition);
        MapObject_SetFacingDirectionDirect(fieldSystem->followMon.mapObject, interaction->savedFacing);
        FollowMon_TryShakeGrass(interaction, fieldSystem->followMon.mapObject, direction);
        return TRUE;
    }
    return FALSE;
}

static inline void FieldSystem_CloseFollowMonMessage(FieldSystem *fieldSystem) {
    ClearFrameAndWindow2(&fieldSystem->followMonInteraction->window, FALSE);
    RemoveWindow(&fieldSystem->followMonInteraction->window);
    String_Delete(fieldSystem->followMonInteraction->string);
    fieldSystem->textbox_open = FALSE;
}

static BOOL Task_FollowMonInteract(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    u32 *state = TaskManager_GetStatePtr(taskManager);

    switch (*state) {
    case FOLLOW_MON_TASK_STATE_LOAD_SCRIPT:
        FollowMonInteraction_LoadScript(fieldSystem->followMonInteraction, FollowMon_SelectInteraction(fieldSystem));
        (*state)++;
        break;
    case FOLLOW_MON_TASK_STATE_RUN: {
        enum FollowMonInteractionResult result = FollowMonInteraction_Run(fieldSystem, fieldSystem->followMonInteraction);
        if (result == FOLLOW_MON_INTERACTION_DONE) {
            MapObject_PauseMovement(fieldSystem->followMon.mapObject);
            return TRUE;
        }
        if (result == FOLLOW_MON_INTERACTION_QUESTION) {
            fieldSystem->followMonInteraction->state = INTERACTION_STATE_OPEN_CHOICE;
            *state = FOLLOW_MON_TASK_STATE_QUESTION;
        } else if (result == FOLLOW_MON_INTERACTION_GIVE_ACCESSORY) {
            *state = FOLLOW_MON_TASK_STATE_GIVE_ACCESSORY;
        } else if (result == FOLLOW_MON_INTERACTION_GIVE_SHINY_LEAF) {
            *state = FOLLOW_MON_TASK_STATE_GIVE_SHINY_LEAF;
        }
        break;
    }
    case FOLLOW_MON_TASK_STATE_QUESTION:
        switch (fieldSystem->followMonInteraction->state) {
        case INTERACTION_STATE_OPEN_CHOICE:
            FieldSystem_SwitchBottomScreenApp(fieldSystem, BOTTOM_SCREEN_APP_CHOICE_MENU, 0);
            fieldSystem->followMonInteraction->state = INTERACTION_STATE_WAIT_CHOICE_APP;
            break;
        case INTERACTION_STATE_WAIT_CHOICE_APP: {
            u8 appId = FieldSystem_GetBottomScreenAppId(fieldSystem);
            u8 appState = FieldSystem_GetBottomScreenAppState(fieldSystem);
            if (appId == BOTTOM_SCREEN_APP_CHOICE_MENU && appState == BOTTOM_SCREEN_APP_STATE_RUNNING) {
                FieldSystem_SetTouchscreenChoiceMenuState(fieldSystem, BOTTOM_SCREEN_APP_CHOICE_MENU, TOUCHSCREEN_CHOICE_MENU_STATE_SHOW_YES_NO, &fieldSystem->followMonInteraction->answer);
                fieldSystem->followMonInteraction->state = INTERACTION_STATE_WAIT_ANSWER;
            }
            break;
        }
        case INTERACTION_STATE_WAIT_ANSWER: {
            u8 appId = FieldSystem_GetBottomScreenAppId(fieldSystem);
            int menuState = FieldSystem_GetTouchscreenChoiceMenuState(fieldSystem);
            if (appId == BOTTOM_SCREEN_APP_CHOICE_MENU && menuState == TOUCHSCREEN_CHOICE_MENU_STATE_DONE) {
                FieldSystem_SwitchBottomScreenApp(fieldSystem, BOTTOM_SCREEN_APP_TOUCHSCREEN_MENU, 0);
                fieldSystem->followMonInteraction->state = INTERACTION_STATE_CLOSE_CHOICE;
            }
            break;
        }
        case INTERACTION_STATE_CLOSE_CHOICE: {
            u8 appId = FieldSystem_GetBottomScreenAppId(fieldSystem);
            u8 appState = FieldSystem_GetBottomScreenAppState(fieldSystem);
            if (appId == BOTTOM_SCREEN_APP_TOUCHSCREEN_MENU && appState == BOTTOM_SCREEN_APP_STATE_RUNNING) {
                switch (fieldSystem->followMonInteraction->answer) {
                case 0:
                    FieldSystem_CloseFollowMonMessage(fieldSystem);
                    if (!fieldSystem->followMonInteraction->yesScript) {
                        MapObject_PauseMovement(fieldSystem->followMon.mapObject);
                        return TRUE;
                    }
                    FollowMonInteraction_LoadScript(fieldSystem->followMonInteraction, fieldSystem->followMonInteraction->yesScript);
                    *state = FOLLOW_MON_TASK_STATE_RUN;
                    break;
                case 1:
                    FieldSystem_CloseFollowMonMessage(fieldSystem);
                    if (!fieldSystem->followMonInteraction->noScript) {
                        MapObject_PauseMovement(fieldSystem->followMon.mapObject);
                        return TRUE;
                    }
                    FollowMonInteraction_LoadScript(fieldSystem->followMonInteraction, fieldSystem->followMonInteraction->noScript);
                    *state = FOLLOW_MON_TASK_STATE_RUN;
                    break;
                }
            }
            break;
        }
        }
        break;
    case FOLLOW_MON_TASK_STATE_GIVE_ACCESSORY: {
        FashionCase *fashionCase = Save_FashionData_GetFashionCase(Save_FashionData_Get(fieldSystem->saveData));
        int accessory = fieldSystem->followMonInteraction->accessory - 1;
        GF_ASSERT(accessory >= 0 && accessory < 100);
        if (FashionCase_CanGiveAccessory(fashionCase, accessory, 1)) {
            FashionCase_GiveFashionItem(fashionCase, accessory, 1);
            FollowMonInteraction_PrintGiftMessage(fieldSystem, fieldSystem->followMonInteraction, FOLLOW_MON_GIFT_ACCESSORY_GIVEN);
            PlayFanfare(SEQ_ME_ACCE);
        } else {
            FollowMonInteraction_PrintGiftMessage(fieldSystem, fieldSystem->followMonInteraction, FOLLOW_MON_GIFT_ACCESSORY_NOT_GIVEN);
        }
        *state = FOLLOW_MON_TASK_STATE_WAIT_GIFT_MESSAGE;
        break;
    }
    case FOLLOW_MON_TASK_STATE_GIVE_SHINY_LEAF: {
        int attr;
        Pokemon *mon;
        switch (fieldSystem->followMonInteraction->shinyLeaf) {
        case 1:
            attr = MON_DATA_SHINY_LEAF_A;
            break;
        case 2:
            attr = MON_DATA_SHINY_LEAF_B;
            break;
        case 3:
            attr = MON_DATA_SHINY_LEAF_C;
            break;
        case 4:
            attr = MON_DATA_SHINY_LEAF_D;
            break;
        case 5:
            attr = MON_DATA_SHINY_LEAF_E;
            break;
        default:
            GF_ASSERT(FALSE);
            return TRUE;
        }
        mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(fieldSystem->saveData));
        if (!(u8)GetMonData(mon, attr, NULL)) {
            u8 value;
            SetFlag99C(Save_VarsFlags_Get(fieldSystem->saveData));
            value = TRUE;
            SetMonData(mon, attr, &value);
            FollowMonInteraction_PrintGiftMessage(fieldSystem, fieldSystem->followMonInteraction, FOLLOW_MON_GIFT_LEAF_GIVEN);
            PlayFanfare(SEQ_ME_ACCE);
        } else {
            FollowMonInteraction_PrintGiftMessage(fieldSystem, fieldSystem->followMonInteraction, FOLLOW_MON_GIFT_LEAF_NOT_GIVEN);
        }
        *state = FOLLOW_MON_TASK_STATE_WAIT_GIFT_MESSAGE;
        break;
    }
    case FOLLOW_MON_TASK_STATE_WAIT_GIFT_MESSAGE:
        if (DialogBox_IsPrintFinished(fieldSystem->followMonInteraction->printerId) == TRUE && !IsFanfarePlaying() && (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B))) {
            FieldSystem_CloseFollowMonMessage(fieldSystem);
            MapObject_PauseMovement(fieldSystem->followMon.mapObject);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static void FollowMon_PlaceholdersSet(FieldSystem *fieldSystem, MessageFormat *messageFormat) {
    Pokemon *mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(fieldSystem->saveData));
    BoxPokemon *boxMon = Mon_GetBoxMon(mon);
    BufferBoxMonNickname(messageFormat, 0, boxMon);
    BufferBoxMonSpeciesName(messageFormat, 1, boxMon);
    BufferPlayersName(messageFormat, 2, Save_PlayerData_GetProfile(fieldSystem->saveData));
    BufferLocationName(messageFormat, 3, MapHeader_GetMapSec(fieldSystem->location->mapId));
    BufferItemName(messageFormat, 4, GetMonData(mon, MON_DATA_HELD_ITEM, NULL));
}

static void FollowMon_ApplyInteractionEffects(FieldSystem *fieldSystem, FollowMonInteraction *interaction) {
    Pokemon *mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(fieldSystem->saveData));
    s8 mood = FollowMonMood_Get(fieldSystem->followMonMood);
    int value = mood;

    value += fieldSystem->followMonInteraction->moodChange;
    if (value > 127) {
        value = 127;
    } else if (value < -127) {
        value = -127;
    }
    FollowMonMood_Set(fieldSystem->followMonMood, value);
    value = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
    value += fieldSystem->followMonInteraction->friendshipChange;
    if (value > FRIENDSHIP_MAX) {
        value = FRIENDSHIP_MAX;
    } else if (value < 0) {
        value = 0;
    }
    SetMonData(mon, MON_DATA_FRIENDSHIP, &value);
}

BOOL FollowMonRule_CheckFriendship(int rule, int friendship) {
    switch (rule) {
    case 1:
        if (friendship != FRIENDSHIP_MAX) {
            break;
        }
        return TRUE;
    case 2:
        if (friendship < 200) {
            break;
        }
        if (friendship >= FRIENDSHIP_MAX) {
            break;
        }
        return TRUE;
    case 3:
        if (friendship < 150) {
            break;
        }
        if (friendship >= 200) {
            break;
        }
        return TRUE;
    case 4:
        if (friendship < 90) {
            break;
        }
        if (friendship >= 150) {
            break;
        }
        return TRUE;
    case 5:
        if (friendship < 60) {
            break;
        }
        if (friendship >= 90) {
            break;
        }
        return TRUE;
    case 6:
        if (friendship < 30) {
            break;
        }
        if (friendship >= 60) {
            break;
        }
        return TRUE;
    case 7:
        if (friendship < 1) {
            break;
        }
        if (friendship >= 30) {
            break;
        }
        return TRUE;
    case 8:
        if (friendship != 0) {
            break;
        }
        return TRUE;
    case 9:
        if (friendship < 90) {
            break;
        }
        return TRUE;
    case 10:
        if (friendship >= 60) {
            break;
        }
        return TRUE;
    }
    return FALSE;
}

BOOL FollowMonRule_CheckMood(int rule, int mood) {
    switch (rule) {
    case 1:
        if (mood != 127) {
            break;
        }
        return TRUE;
    case 2:
        if (mood < 100) {
            break;
        }
        if (mood >= 127) {
            break;
        }
        return TRUE;
    case 3:
        if (mood < 50) {
            break;
        }
        if (mood >= 100) {
            break;
        }
        return TRUE;
    case 4:
        if (mood < 30) {
            break;
        }
        if (mood >= 50) {
            break;
        }
        return TRUE;
    case 5:
        if (mood <= -30) {
            break;
        }
        if (mood >= 30) {
            break;
        }
        return TRUE;
    case 6:
        if (mood <= -50) {
            break;
        }
        if (mood > -30) {
            break;
        }
        return TRUE;
    case 7:
        if (mood <= -127) {
            break;
        }
        if (mood > -50) {
            break;
        }
        return TRUE;
    case 8:
        if (mood != -127) {
            break;
        }
        return TRUE;
    case 9:
        if (mood < 0) {
            break;
        }
        return TRUE;
    case 10:
        if (mood > -1) {
            break;
        }
        return TRUE;
    }
    return FALSE;
}

// Rules up to 249 ask for that exact value; 250-254 ask for a range.
BOOL FollowMonRule_CheckSpeciesAttr(u32 rule, u32 value) {
    if (rule <= 249) {
        if (rule == value) {
            return TRUE;
        }
    } else {
        switch (rule) {
        case 250:
            if (value > 19) {
                break;
            }
            return TRUE;
        case 251:
            if (value > 130) {
                break;
            }
            return TRUE;
        case 252:
            if (value < 140) {
                break;
            }
            if (value > 149) {
                break;
            }
            return TRUE;
        case 253:
            if (value < 160) {
                break;
            }
            return TRUE;
        case 254:
            if (value < 220) {
                break;
            }
            return TRUE;
        default:
            GF_ASSERT(FALSE);
            return FALSE;
        }
    }
    return FALSE;
}

// TRUE when the Pokemon does not have shiny leaf `leaf` (1-5) yet.
BOOL FollowMonRule_CheckShinyLeaf(int leaf, u8 shinyLeaves) {
    ShinyLeafMasks masks = gShinyLeafMasks;
    int i;
    for (i = 0; i < 5; i++) {
        if ((masks.masks[leaf - 1] & shinyLeaves) == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL FieldSystem_FirstAliveMonHasType(FieldSystem *fieldSystem, u8 type) {
    Pokemon *mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(fieldSystem->saveData));
    u32 type1 = GetMonData(mon, MON_DATA_TYPE_1, NULL);
    u32 type2 = GetMonData(mon, MON_DATA_TYPE_2, NULL);
    if (type1 == type || type2 == type) {
        return TRUE;
    }
    return FALSE;
}

void FollowMon_JumpOnSpot(FieldSystem *fieldSystem, u8 count) {
    if ((u32)(FollowMon_GetSpecies(fieldSystem->followMon.mapObject) - SPECIES_DIGLETT) > 1) {
        FollowMonJumpOnSpotEnv *env = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(FollowMonJumpOnSpotEnv));
        env->count = count;
        env->done = 0;
        TaskManager_Call(fieldSystem->taskman, Task_FollowMonJumpOnSpot, env);
    }
}

static BOOL Task_FollowMonJumpOnSpot(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FollowMonJumpOnSpotEnv *env = TaskManager_GetEnvironment(taskManager);
    u32 *state = TaskManager_GetStatePtr(taskManager);

    switch (*state) {
    case 0:
        MapObject_UnpauseMovement(fieldSystem->followMon.mapObject);
        (*state)++;
    case 1:
        if (MapObject_AreBitsSetForMovementScriptInit(FollowMon_GetMapObject(fieldSystem))) {
            MapObject_PauseMovement(fieldSystem->followMon.mapObject);
            (*state)++;
        }
        break;
    case 2: {
        u8 direction = MapObject_GetFacingDirection(fieldSystem->followMon.mapObject);
        env->movement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gFollowMonJumpOnSpotMovements[direction]);
        (*state)++;
        break;
    }
    case 3:
        if (EventObjectMovementMan_IsFinish(env->movement) == TRUE) {
            EventObjectMovementMan_Delete(env->movement);
            env->done++;
            if (env->done >= env->count) {
                (*state)++;
            } else {
                *state = 0;
            }
        }
        break;
    case 4:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

BOOL FollowMon_StartGrowAndShrink(FieldSystem *fieldSystem) {
    FollowMonGrowAndShrinkEnv *env = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(FollowMonGrowAndShrinkEnv));
    env->wait = 0;
    env->frame = 0;
    TaskManager_Call(fieldSystem->taskman, Task_FollowMonGrowAndShrink, env);
    return TRUE;
}

// Grows the billboard to 1.5 times its size over 10 frames, holds it for 10 frames, then shrinks it back.
static BOOL Task_FollowMonGrowAndShrink(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    u32 *state = TaskManager_GetStatePtr(taskManager);
    FollowMonGrowAndShrinkEnv *env = TaskManager_GetEnvironment(taskManager);

    switch (*state) {
    case 0: {
        VecFx32 scale;
        scale = gFollowMonGrowScale;
        env->frame++;
        scale.x = (s32)((double)env->frame * 2048.0 / 10.0 + 4096.0);
        scale.y = (s32)((double)env->frame * 2048.0 / 10.0 + 4096.0);
        BillboardObject_SetScale(MapObjectManager_GetFollowMonBillboard(fieldSystem->mapObjectManager), &scale);
        if (env->frame >= 10) {
            env->frame = 0;
            env->wait = 0;
            (*state)++;
        }
        break;
    }
    case 1:
        env->wait++;
        if (env->wait >= 10) {
            (*state)++;
        }
        break;
    case 2: {
        VecFx32 scale;
        scale = gFollowMonShrinkScale;
        env->frame++;
        if (env->frame >= 10) {
            (*state)++;
        } else {
            scale.x = (s32)((double)(10 - env->frame) * 2048.0 / 10.0 + 4096.0);
            scale.y = (s32)((double)(10 - env->frame) * 2048.0 / 10.0 + 4096.0);
        }
        BillboardObject_SetScale(MapObjectManager_GetFollowMonBillboard(fieldSystem->mapObjectManager), &scale);
        break;
    }
    case 3:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}
