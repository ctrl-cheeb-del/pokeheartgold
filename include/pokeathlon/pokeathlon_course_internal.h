#ifndef POKEHEARTGOLD_POKEATHLON_POKEATHLON_COURSE_INTERNAL_H
#define POKEHEARTGOLD_POKEATHLON_POKEATHLON_COURSE_INTERNAL_H

#include "global.h"

#include "pokeathlon/pokeathlon.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_save.h"

#include "apricorn_internal.h"
#include "obj_char_transfer.h"
#include "overlay_manager.h"
#include "player_data.h"
#include "pm_string.h"
#include "sprite.h"
#include "sprite_resource.h"
#include "sprite_resource_header.h"
#include "sys_task.h"

// Course participants

// One Pokemon of a participant's team.
struct PokeathlonCourseMon {
    u16 species;
    u16 form;
    u32 personality;
    u8 stats[5]; // current Pokeathlon performance (power, stamina, jump, skill, speed)
    u8 padding_0D;
    u16 starColors; // 3 bits per stat, in the order of stats
    u8 isShiny;
    u8 gender;
    u16 nickname[POKEMON_NAME_LENGTH + 1];
};

// A course participant.
struct PokeathlonCourseParticipant {
    s32 npcTeam; // NARC a/2/5/8 entry + 1 of an NPC team, 0 for a player
    PokeathlonCourseMon mons[POKEATHLON_TEAM_SIZE];
};

// Score list (PokeathlonCourseData.scores): the per-event result rows and the course point totals

#define POKEATHLON_COURSE_SCORE_ENTRY_MAX  12
#define POKEATHLON_COURSE_EVENT_POINTS_MAX 10

struct PokeathlonCourseScore {
    s32 participant;
    u8 padding_04[5];
    u8 rank;
    u16 points;
    s32 score;
    String *text;
    String *name;
};

struct PokeathlonCourseScoreList {
    s32 count;
    u32 unk04;
    s32 next;
    u32 sortOrder;
    BOOL totalsAdded;
    u32 totals[POKEATHLON_PARTICIPANTS];
    PokeathlonCourseScore entries[POKEATHLON_COURSE_SCORE_ENTRY_MAX];
    PokeathlonCourseScore *ranking[POKEATHLON_COURSE_SCORE_ENTRY_MAX];
    u32 eventPoints[POKEATHLON_COURSE_EVENT_POINTS_MAX][POKEATHLON_PARTICIPANTS];
};

// Doubly linked node of the insertion sort in PokeathlonCourseScoreList_Rank.
typedef struct PokeathlonCourseScoreNode {
    struct PokeathlonCourseScoreNode *prev;
    struct PokeathlonCourseScoreNode *next;
    PokeathlonCourseScore *entry;
} PokeathlonCourseScoreNode;

// Pokemon sprites built from the overworld models (NARC data/mmodel/mmodel)

// One loaded Pokemon sprite.
struct PokeathlonCourseMonGfx {
    SpriteResource *charRes;
    SpriteResource *plttRes;
    SpriteResource *cellRes;
    SpriteResource *animRes;
    Sprite *sprite;
    PokeathlonCourseMonInfo info;
    u32 topRow;     // first non-transparent pixel row of the first frame
    BOOL shiftedUp; // large frame drawn one tile row higher
};

struct PokeathlonCourseMonGfxManager {
    enum HeapID heapId;
    u16 count;
    u16 loadedCount;
    BOOL shiftLargeUp;
    BOOL loaded;
    BOOL ownsSpriteList;
    SpriteList *ownSpriteList;
    SpriteList *spriteList;
    G2dRenderer renderer;
    GF_2DGfxResMan *resMans[POKEATHLON_RES_TYPES];
    PokeathlonCourseMonGfx *mons;
    u8 buffer[0x800]; // one frame of character data
};

struct PokeathlonCourseMonGfxTemplate {
    BOOL loadAtOnce; // load all Pokemon in one frame
    int priority;
    BOOL vramTransfer;
    NNS_G2D_VRAM_TYPE vram;
    NNS_G2D_VRAM_TYPE whichScreen;
    int sizeTypes[POKEATHLON_MONS]; // 1..3, selects the shadow / marker offsets of each Pokemon
};

// The task that loads the requested Pokemon sprites, one per frame.
typedef struct PokeathlonCourseMonGfxLoad {
    u16 count;
    u16 current;
    int baseIndex;
    int state;
    PokeathlonCourseMonGfxManager *manager;
    PokeathlonCourseMonGfxTemplate template;
    PokeathlonCourseMonInfo infos[16];
} PokeathlonCourseMonGfxLoad;

// Course sprite resources (NARC a/1/5/3)

struct PokeathlonCourseSpriteResources {
    enum HeapID heapId;
    u32 flags; // which of the 12 sprite groups are loaded
    NNS_G2D_VRAM_TYPE charVram;
    GF_2DGfxResMan *resMans[POKEATHLON_RES_TYPES];
    SpriteResource *chars[POKEATHLON_MONS];
    SpriteResource *cells[POKEATHLON_MONS];
    SpriteResource *anims[POKEATHLON_MONS];
    SpriteResource *palette;
    SpriteResource *extraPalette;
};

// Course states, in the order of sPokeathlonStateInfoFuncTable (PokeathlonCourse_SetNextState)

enum PokeathlonCourseStateId {
    POKEATHLON_COURSE_STATE_SEND_EVENTS,
    POKEATHLON_COURSE_STATE_RUN_EVENT_OVERLAY,
    POKEATHLON_COURSE_STATE_RUN_WAIT,
    POKEATHLON_COURSE_STATE_SEND_PARTICIPANT,
    POKEATHLON_COURSE_STATE_SEND_PARTICIPANTS,
    POKEATHLON_COURSE_STATE_SEND_PROFILES,
    POKEATHLON_COURSE_STATE_SEND_RECORD,
    POKEATHLON_COURSE_STATE_START_OPENING,
    POKEATHLON_COURSE_STATE_WAIT_OPENING_START,
    POKEATHLON_COURSE_STATE_RUN_OPENING,
    POKEATHLON_COURSE_STATE_END_OPENING,
    POKEATHLON_COURSE_STATE_START_EVENT_INTRO,
    POKEATHLON_COURSE_STATE_WAIT_EVENT_INTRO_START,
    POKEATHLON_COURSE_STATE_RUN_EVENT_INTRO,
    POKEATHLON_COURSE_STATE_END_EVENT_INTRO,
    POKEATHLON_COURSE_STATE_START_ROUND,
    POKEATHLON_COURSE_STATE_WAIT_ROUND_START,
    POKEATHLON_COURSE_STATE_SEND_EVENT_DATA,
    POKEATHLON_COURSE_STATE_RUN_EVENT,
    POKEATHLON_COURSE_STATE_RESET_DATA_COPY_AREA,
    POKEATHLON_COURSE_STATE_SEND_EVENT_RESULT,
    POKEATHLON_COURSE_STATE_SEND_EVENT_RESULTS,
    POKEATHLON_COURSE_STATE_END_ROUND,
    POKEATHLON_COURSE_STATE_EXIT_EVENT,
    POKEATHLON_COURSE_STATE_NEXT_ROUND,
    POKEATHLON_COURSE_STATE_START_RESULTS,
    POKEATHLON_COURSE_STATE_WAIT_RESULTS_START,
    POKEATHLON_COURSE_STATE_RUN_RESULTS,
    POKEATHLON_COURSE_STATE_END_RESULTS,
    POKEATHLON_COURSE_STATE_SEND_MON_COUNTERS,
    POKEATHLON_COURSE_STATE_SEND_RESULTS,
    POKEATHLON_COURSE_STATE_START_CLOSING,
    POKEATHLON_COURSE_STATE_WAIT_CLOSING_START,
    POKEATHLON_COURSE_STATE_RUN_CLOSING,
    POKEATHLON_COURSE_STATE_CREATE_JUICE_RECORDS,
    POKEATHLON_COURSE_STATE_SEND_JUICE_RECORD,
    POKEATHLON_COURSE_STATE_STORE_JUICE_RECORDS,
    POKEATHLON_COURSE_STATE_EXIT,
    POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND,
};

// Link sync points (PokeathlonCourse_SetStateTransitionType): the course goes on once every player reached it.
enum PokeathlonCourseSync {
    POKEATHLON_COURSE_SYNC_EVENTS = 1,
    POKEATHLON_COURSE_SYNC_ALL_PARTICIPANTS = 3,
    POKEATHLON_COURSE_SYNC_PROFILES,
    POKEATHLON_COURSE_SYNC_RECORD,
    POKEATHLON_COURSE_SYNC_OPENING,
    POKEATHLON_COURSE_SYNC_EVENT_INTRO,
    POKEATHLON_COURSE_SYNC_ROUND_START,
    POKEATHLON_COURSE_SYNC_EVENT_DATA = 10,
    POKEATHLON_COURSE_SYNC_RESULTS,
    POKEATHLON_COURSE_SYNC_CLOSING,
    POKEATHLON_COURSE_SYNC_COURSE_RESULTS,
    POKEATHLON_COURSE_SYNC_JUICE_RECORDS,
    POKEATHLON_COURSE_SYNC_JUICE_RECORDS_RECEIVED,
    POKEATHLON_COURSE_SYNC_EVENT_END,
    POKEATHLON_COURSE_SYNC_WAIT,
    POKEATHLON_COURSE_SYNC_RELAY_RUN,
    POKEATHLON_COURSE_SYNC_PENNANT_CAPTURE,
    POKEATHLON_COURSE_SYNC_LAMP_JUMP,
    POKEATHLON_COURSE_SYNC_CIRCLE_PUSH,
};

// Medals of a Pokemon (PokeathlonSave_AddMonMedals): one per solo course (args course 0..4, in this order).
#define POKEATHLON_MEDAL_SPEED   (1 << 0)
#define POKEATHLON_MEDAL_POWER   (1 << 1)
#define POKEATHLON_MEDAL_SKILL   (1 << 2)
#define POKEATHLON_MEDAL_STAMINA (1 << 3)
#define POKEATHLON_MEDAL_JUMP    (1 << 4)
#define POKEATHLON_MEDALS_ALL    (POKEATHLON_MEDAL_SPEED | POKEATHLON_MEDAL_POWER | POKEATHLON_MEDAL_SKILL | POKEATHLON_MEDAL_STAMINA | POKEATHLON_MEDAL_JUMP)

// Link commands (0x16..0x21). In a single-player course the commands go through a local queue that runs them
// in the next VBlank task, so the course code is the same for both.

#define POKEATHLON_COURSE_CMD_FIRST            0x16
#define POKEATHLON_COURSE_CMD_EVENTS           0x16
#define POKEATHLON_COURSE_CMD_PARTICIPANT      0x17
#define POKEATHLON_COURSE_CMD_ALL_PARTICIPANTS 0x18
#define POKEATHLON_COURSE_CMD_PROFILES         0x19
#define POKEATHLON_COURSE_CMD_RECORD           0x1A
#define POKEATHLON_COURSE_CMD_PACKET           0x1B
#define POKEATHLON_COURSE_CMD_EVENT_DATA       0x1C
#define POKEATHLON_COURSE_CMD_EVENT_RESULT     0x1D
#define POKEATHLON_COURSE_CMD_EVENT_RESULTS    0x1E
#define POKEATHLON_COURSE_CMD_MON_COUNTERS     0x1F
#define POKEATHLON_COURSE_CMD_RESULTS          0x20
#define POKEATHLON_COURSE_CMD_JUICE_RECORD     0x21
#define POKEATHLON_COURSE_CMD_INLINE_SIZE      0x26
#define POKEATHLON_COURSE_CMD_SLOTS            8 // commands the local queue holds

typedef void (*PokeathlonCourseCmdFunc)(int netId, int size, void *data, void *context);
typedef int (*PokeathlonCourseCmdSizeFunc)(void);
typedef void *(*PokeathlonCourseCmdBufferFunc)(int netId, void *context, int size);

typedef struct PokeathlonCourseCmd {
    PokeathlonCourseCmdFunc func;
    PokeathlonCourseCmdSizeFunc getSize;
    PokeathlonCourseCmdBufferFunc getBuffer;
} PokeathlonCourseCmd;

typedef struct PokeathlonCourseCmdSlot {
    BOOL active;
    u32 cmd;
    u8 data[0x28];
    s32 size;
    void *buffer;
} PokeathlonCourseCmdSlot;

typedef struct PokeathlonCourseCmdQueue {
    PokeathlonCourseCmdSlot slots[POKEATHLON_COURSE_CMD_SLOTS];
    const PokeathlonCourseCmd *cmds;
    int cmdCount;
    PokeathlonCourseData *context;
    SysTask *task;
} PokeathlonCourseCmdQueue;

struct PokeathlonCourseLink {
    u16 isLink; // 1 = wireless link, 0 = local queue
    u16 checkSize;
    PokeathlonCourseCmdQueue *queue;
};

struct PokeathlonCoursePoint {
    u16 x;
    u16 y;
};

// One entry of NARC poketool/personal_performance.
struct PokeathlonCoursePerformance {
    u8 stats[5]; // base Pokeathlon performance (power, stamina, jump, skill, speed)
    u8 isTall;   // sprites drawn over the Pokemon sit higher
    u8 collisionSizeClass;
    u8 heightClass; // 1..3
    u8 spriteSizeType;
    u8 unk09[11];
};

// The performance data of every participant's Pokemon.
typedef struct PokeathlonCoursePerformanceTable {
    PokeathlonCoursePerformance mons[POKEATHLON_PARTICIPANTS][POKEATHLON_TEAM_SIZE];
} PokeathlonCoursePerformanceTable;

// A marker sprite following a Pokemon.
typedef struct PokeathlonCourseMarker {
    BOOL active;
    PokeathlonCourseMonObject *object;
    Sprite *sprite;
    SysTask *task;
} PokeathlonCourseMarker;

typedef struct PokeathlonCourseMarkers {
    u32 count;
    PokeathlonCourseMarker markers[3];
} PokeathlonCourseMarkers;

// A player's result of the event that is running (exchanged with link commands 0x1D / 0x1E).
typedef struct PokeathlonCourseEventResult {
    u16 score;
    u16 unk2;
} PokeathlonCourseEventResult;

typedef void (*PokeathlonCourseFinishFunc)(PokeathlonCourseData *course);

// Data the host sends to the other players before an event (PokeathlonCourse_SetEventDataTransfer).
typedef struct PokeathlonCourseEventData {
    void *toSend;
    void *recvBuffer;
    u32 size;
    BOOL pending;
} PokeathlonCourseEventData;

// A link packet of the event that is running; the data copy area holds 7 of them.
typedef struct PokeathlonCoursePacket {
    u8 data[0x24];
    u8 isHostPacket;
    u8 unk25[3];
} PokeathlonCoursePacket;

// Callbacks of the event that is running (PokeathlonCourseData.event).
typedef struct PokeathlonCourseEvent {
    BOOL (*init)(PokeathlonCourseData *course);
    void (*draw)(PokeathlonCourseData *course, u32 param);
    void (*onResults)(PokeathlonCourseData *course, u32 param);
    void (*exit)(PokeathlonCourseData *course, u32 param);
    BOOL sendsOwnResult;
} PokeathlonCourseEvent;

#define POKEATHLON_MON_COUNTER_MAX 9999 // the cap of the counters of a Pokemon and of the instructions

// The course results (PokeathlonCourse_GetFieldData).
struct PokeathlonCourseResults {
    u32 counters[POKEATHLON_PARTICIPANTS][POKEATHLON_TEAM_SIZE][8]; // per participant and Pokemon
    u32 bonuses;
    u32 instructions;
    u16 eventPoints[POKEATHLON_PARTICIPANTS][POKEATHLON_LINK_ROUNDS];
    u16 eventScores[POKEATHLON_PARTICIPANTS][POKEATHLON_LINK_ROUNDS];
    u8 wonRound[POKEATHLON_LINK_ROUNDS];
    u8 lastInRound[POKEATHLON_LINK_ROUNDS];
    u16 wonCourse : 1;
    u16 lastInCourse : 1;
    u16 rank : 2;
    u16 unkBits4 : 12;
    u16 totalPoints;
    PokeathlonStatistics record; // the player's saved record
};

// The course (overlay data of PokeathlonCourse_Init .. PokeathlonCourse_Exit).
struct PokeathlonCourseData {
    u32 padding_00[4];
    u8 padding_10[0x14C];
    u8 padding_15C;
    u8 padding_15D[0x83];
    const PokeathlonCourseEvent *event;
    void *work;
    u8 eventIds[POKEATHLON_LINK_ROUNDS]; // event of each round, as sent to the other players
    u8 unk1EC;
    u8 eventInitState;
    u8 participantCount; // Number of active participants (1-4)
    u8 receivedCount;
    u32 round;
    BOOL eventDrawEnabled;
    PokeathlonCourseArgs *args;
    BOOL boxCancelled;
    PokeathlonCourseParticipant localParticipant;
    u32 boxCourseId;
    OverlayManager *subOverlay;
    enum HeapID heapId;
    PokeathlonCourseLink *link;
    PokeathlonCoursePacket packets[7]; // the data copy area
    PokeathlonCourseEventData eventData;
    PokeathlonCourseState courseState;
    PokeathlonStateInfo stateInfo;
    PokeathlonStateInfo eventStateInfo;
    u32 unk3D4;
    u32 roundEvents[POKEATHLON_LINK_ROUNDS];
    u32 courseId;
    PokeathlonCourseParticipant participants[POKEATHLON_PARTICIPANTS];
    PlayerProfile *playerProfiles;
    PokeathlonCourseEventResult eventResults[POKEATHLON_PARTICIPANTS]; // the player's own, then (host) everybody's
    u16 receivedResults[18];                     // the results the host sent
    PokeathlonCourseScoreList *scores;
    PokeathlonCoursePerformanceTable performance;
    Sprite *countSprite; // event HUD: "3, 2, 1" and "Finish"
    u8 hudTimer;
    u8 finishState;
    u16 hudBaseY;
    Sprite *newRecordSprite;
    Sprite *timeUpSprite;
    u32 hudPlanes; // BG planes shown again after "Finish"
    Sprite *startSprites[3];
    u8 startSpriteCount;
    u8 startState;
    u8 rounds; // 3 solo, 4 link
    u8 timeUpSeconds;
    PokeathlonCourseResults results;
    PokeathlonStatistics records[POKEATHLON_PARTICIPANTS]; // every player's saved record
    u32 localCounters[POKEATHLON_TEAM_SIZE][8];
    u8 monCounters[0x180];
    s32 frameCounter;
    u16 frameTimer;
    u16 recordScore; // the event result compared with the saved record
    BOOL counterEnabled;
    PokeathlonCourseMarkers markers;
    ApricornRecord *juiceRecord;
    ApricornRecord *playerJuiceRecords;
    PokeathlonCourseFinishFunc finishCallback;
};

// Saved records (parts of PokeathlonSave)

#define POKEATHLON_RECORD_RANKS  5       // the top 5 of an event ranking
#define POKEATHLON_STATISTIC_MAX 9999999 // the cap of the play counts and statistics

// A Pokemon of a course record.
typedef struct PokeathlonCourseSavedMon {
    u32 species : 9;
    u32 form : 5;
    u32 gender : 2;
    u32 isShiny : 1;
    u32 unused : 15;
    u32 personality;
    u32 unk08;
} PokeathlonCourseSavedMon;

// Best total of a course with its round points and Pokemon (one per course at the start of PokeathlonSave).
typedef struct PokeathlonCourseBestRecord {
    u16 roundPoints[POKEATHLON_SOLO_ROUNDS];
    u16 totalPoints;
    PokeathlonCourseSavedMon mons[POKEATHLON_TEAM_SIZE];
} PokeathlonCourseBestRecord;

// A result in an event ranking: score, the Pokemon (form << 10 | species) and, in link rankings, the trainer.
typedef struct PokeathlonCourseRankEntry {
    u16 score;
    u16 mons[POKEATHLON_TEAM_SIZE];
    u32 trainerId;
    u16 name[PLAYER_NAME_LENGTH + 1];
    u8 language;
    u8 padding[3];
} PokeathlonCourseRankEntry;

// Top 5 of a solo event (Pokeathlon_RecordsSolo).
typedef struct PokeathlonCourseEventRecord {
    PokeathlonEventRecordEntry top[POKEATHLON_RECORD_RANKS];
    u32 timesPlayed;
} PokeathlonCourseEventRecord;

typedef struct PokeathlonCourseTrainerRecord {
    u32 trainerId;
    u16 name[PLAYER_NAME_LENGTH + 1];
    u8 language;
    u8 padding[3];
} PokeathlonCourseTrainerRecord;

// Top 5 of a link event (Pokeathlon_RecordsLink).
typedef struct PokeathlonCourseLinkEventRecord {
    PokeathlonEventRecordEntry top[POKEATHLON_RECORD_RANKS];
    u32 timesPlayed;
    PokeathlonCourseTrainerRecord trainers[POKEATHLON_RECORD_RANKS];
} PokeathlonCourseLinkEventRecord;

// NPC teams (NARC a/2/5/8): five for each course, the link courses' teams also make the pool of the random
// course, and the harder teams of supreme courses follow the normal ones.
#define POKEATHLON_NPC_TEAMS_PER_COURSE 5
#define POKEATHLON_NPC_TEAMS_LINK_START 25
#define POKEATHLON_NPC_TEAMS_LINK       25
#define POKEATHLON_NPC_TEAMS_HARD_START 50
#define POKEATHLON_NPC_TEAMS            100

#define POKEATHLON_RANDOM_EVENT_SETS 10 // the event sets the random course picks from

// An NPC team (NARC a/2/5/8).
typedef struct PokeathlonCourseNpcTeam {
    u16 species[POKEATHLON_TEAM_SIZE];
    u8 nameId; // msg 310
    u8 msgId;
} PokeathlonCourseNpcTeam;

extern const PokeathlonCourseEvent gPokeathlonCourseEvent_Opening;
extern const PokeathlonCourseEvent gPokeathlonCourseEvent_Closing;
extern const PokeathlonCourseEvent gPokeathlonCourseEvent_ResultsAnnouncement;
extern const PokeathlonCourseEvent gPokeathlonCourseEvent_Wait;
extern const PokeathlonCourseEvent gPokeathlonCourseEvent_EventIntro;
extern const PokeathlonCourseEvent *const gPokeathlonCourseEvents[];        // events by event id
extern const PokeathlonCourseStepFunc *const gPokeathlonCourseEventSteps[]; // their state functions
extern PokeathlonCourseStepFunc gPokeathlonCourseOpeningSteps[];
extern PokeathlonCourseStepFunc gPokeathlonCourseClosingSteps[];
extern PokeathlonCourseStepFunc gPokeathlonCourseWaitSteps[];
extern PokeathlonCourseStepFunc gPokeathlonEventIntroSteps[];
extern const PokeathlonCourseStepFunc gPokeathlonResultsAnnouncementSteps[];
extern const u8 gPokeathlonEventScoreOrders[];     // score order of each event (0: higher is better, 1: lower)
extern const u16 gPokeathlonEventTargetScores[];   // target score of each event
extern const u8 gPokeathlonCourseEventIds[][POKEATHLON_LINK_ROUNDS];    // events of the courses 0..9
extern const u8 gPokeathlonCourse10EventSets[POKEATHLON_RANDOM_EVENT_SETS][POKEATHLON_LINK_ROUNDS];
extern const u16 gPokeathlonNpcTeamSpriteIds[POKEATHLON_NPC_TEAMS];
extern const u16 gPokeathlonPerformanceFileIds[];  // performance file of each species' first form
extern const PokeathlonCourseCmd gPokeathlonCourseCmds[POKEATHLON_COURSE_CMD_JUICE_RECORD - POKEATHLON_COURSE_CMD_FIRST + 1];

BOOL PokeathlonCourseObject_IsDrawn(PokeathlonCourseMonObject *object);

// Course flow, results, link commands
void PokeathlonCourse_LoadPerformanceData(PokeathlonCourseData *course);
PokeathlonCoursePerformance *PokeathlonCourse_GetPerformance(PokeathlonCourseData *course, int participant, int mon);
u8 *PokeathlonCourse_GetMonStats(PokeathlonCourseData *course, int participant, int mon);
int PokeathlonCourse_GetTouchRadius(void);
int PokeathlonCourse_GetSpriteSizeType(const PokeathlonCoursePerformance *performance);
int PokeathlonCourse_GetCollisionSizeClass(const PokeathlonCoursePerformance *performance);
void PokeathlonCourse_GetMonInfo(PokeathlonCourseData *course, int participant, int which, PokeathlonCourseMonInfo *info);
Sprite **PokeathlonCourse_CreateHudSprites(PokeathlonCourseData *course, int baseY, PokeathlonCourseSpriteResources *resources, SpriteList *spriteList);
Sprite **PokeathlonCourse_CreateHudSpritesInPool(PokeathlonCourseData *course, int baseY, PokeathlonCourseSpriteResources *resources, PokeathlonCourseSpritePool *pool);
void PokeathlonCourse_CreateStartSprites(PokeathlonCourseData *course, int baseY, PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, NNS_G2D_VRAM_TYPE whichScreen, u8 count, PokeathlonCoursePoint *positions);
void PokeathlonCourse_CreateStartSpritesInPool(PokeathlonCourseData *course, int baseY, PokeathlonCourseSpriteResources *resources, PokeathlonCourseSpritePool *pool, NNS_G2D_VRAM_TYPE whichScreen, u8 count, PokeathlonCoursePoint *positions);
BOOL PokeathlonCourse_RunStartCountdown(PokeathlonCourseData *course);
void PokeathlonCourse_UpdateTimeUpCountdown(PokeathlonCourseData *course, int framesLeft);
void PokeathlonCourse_InitMarkers(PokeathlonCourseData *course);
Sprite *PokeathlonCourse_AddMarker(PokeathlonCourseData *course, PokeathlonCourseMonObject *object, PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, int priority);
void PokeathlonCourse_FreeMarkers(PokeathlonCourseData *course);
void PokeathlonCourse_SetMarkerAnim(PokeathlonCourseData *course, u8 index, int seq);
void PokeathlonCourse_StopMarkerAnims(PokeathlonCourseData *course);
void PokeathlonCourse_SetHudPlanes(PokeathlonCourseData *course, u32 planes);
BOOL PokeathlonCourse_RunFinish(PokeathlonCourseData *course);
int PokeathlonCourse_GetPerformanceFileId(int species, int form);
BOOL PokeathlonCourse_State_SendEvents(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_RunEventOverlay(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_RunWait(PokeathlonCourseData *course, u8 *state);
BOOL PokeathlonCourse_State_SendParticipant(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_SendParticipants(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_SendProfiles(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_SendRecord(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_StartOpening(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_WaitOpeningStart(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_RunOpening(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_EndOpening(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_StartEventIntro(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_WaitEventIntroStart(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_RunEventIntro(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_EndEventIntro(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_StartRound(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_WaitRoundStart(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_SendEventData(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_RunEvent(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_ResetDataCopyArea(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_SendEventResult(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_SendEventResults(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_EndRound(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_ExitEvent(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_NextRound(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_StartResults(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_WaitResultsStart(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_RunResults(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_EndResults(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_StartClosing(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_WaitClosingStart(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_RunClosing(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_CreateJuiceRecords(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_SendMonCounters(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_SendResults(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_SendJuiceRecord(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_StoreJuiceRecords(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_Exit(PokeathlonCourseData *course);
BOOL PokeathlonCourse_State_WaitForCommand(void);
void PokeathlonCourse_AddMonCounter(PokeathlonCourseData *course, u8 participant, u8 mon, enum PokeathlonMonCounter counter, int amount);
void PokeathlonCourse_SetRecordScore(PokeathlonCourseData *course, u16 score);
void PokeathlonCourse_SetFinishCallback(PokeathlonCourseData *course, PokeathlonCourseFinishFunc callback);
u16 PokeathlonCourse_GetNpcTeamSpriteId(u32 npcTeam);
u8 PokeathlonCourse_GetNpcTeamMsgId(PokeathlonCourseData *course, u32 npcTeam);
void PokeathlonCourse_SetupNpcParticipants(PokeathlonCourseData *course, int count);
void *PokeathlonCourse_GetJuiceRecord(PokeathlonCourseData *course, u32 index);
BOOL PokeathlonCourse_IsInRange(int x, int y, int targetX, int targetY, int range, int *distance);
void PokeathlonCourseLink_SetCheckSize(PokeathlonCourseLink *link, u16 checkSize);
PokeathlonCourseMonGfxManager *PokeathlonCourseMonGfx_AllocManager(enum HeapID heapId);

// Pokemon sprites
void PokeathlonCourseMonGfx_InitManager(PokeathlonCourseMonGfxManager *manager, u32 count, SpriteList *spriteList);
void PokeathlonCourseMonGfx_FreeManager(PokeathlonCourseMonGfxManager *manager);
void PokeathlonCourseMonGfx_StartLoad(PokeathlonCourseMonGfxManager *manager, s32 count, PokeathlonCourseMonInfo *infos, PokeathlonCourseMonGfxTemplate *template, u32 priority, int baseIndex);
BOOL PokeathlonCourseMonGfx_IsLoaded(PokeathlonCourseMonGfxManager *manager);
PokeathlonCourseMonGfx *PokeathlonCourseMonGfx_Get(PokeathlonCourseMonGfxManager *manager, int index);
Sprite *PokeathlonCourseMonGfx_GetSprite(PokeathlonCourseMonGfx *mon);
PokeathlonCourseMonInfo *PokeathlonCourseMonGfx_GetInfo(PokeathlonCourseMonGfx *mon);
void PokeathlonCourseMonGfx_LoadPalette(PokeathlonCourseMonInfo *info, enum HeapID heapId, u16 *dest);
void PokeathlonCourseMonGfx_SetPalette(PokeathlonCourseMonGfxManager *manager, int index, NNS_G2D_VRAM_TYPE vram, const u16 *palette);
u8 PokeathlonCourseMonGfx_GetTopRow(PokeathlonCourseMonGfx *mon);
void PokeathlonCourseMonGfx_SetScale(PokeathlonCourseMonGfx *mon, f32 x, f32 y);
void PokeathlonCourseMonGfx_ShiftLargeUp(PokeathlonCourseMonGfxManager *manager);
BOOL PokeathlonCourseMonGfx_IsShiftedUp(PokeathlonCourseMonGfx *mon);
void PokeathlonCourse_InitObjTransfer(ObjCharTransferTemplate *charTemplate, int plttCount, enum HeapID heapId, GXOBJVRamModeChar modeMain, GXOBJVRamModeChar modeSub);
void PokeathlonCourse_FreeObjTransfer(void);

// Score list and link command handlers
PokeathlonCourseScore *PokeathlonCourseScoreList_GetEntry(PokeathlonCourseScoreList *list, u32 index);
void PokeathlonCourseScoreList_Rank(PokeathlonCourseScoreList *list, int mode);
PokeathlonCourseScore *PokeathlonCourseScoreList_GetRanked(PokeathlonCourseScoreList *list, u8 index);
void PokeathlonCourseScoreList_Init(PokeathlonCourseScoreList *list);
s32 PokeathlonCourseScoreList_GetCount(PokeathlonCourseScoreList *list);
u32 PokeathlonCourseScoreList_GetField04(PokeathlonCourseScoreList *list);
void PokeathlonCourseScoreList_AddPointsToTotals(PokeathlonCourseScoreList *list);
void PokeathlonCourseScoreList_SaveEventPoints(PokeathlonCourseScoreList *list, int event);
u32 PokeathlonCourseScoreList_GetEventPoints(PokeathlonCourseScoreList *list, int event, int participant);
void PokeathlonCourse_AddScoreEntry(PokeathlonCourseData *course, PokeathlonCourseScoreList *list, u32 participant, u32 score, u8 idx, u8 digits, u32 msgno);
void PokeathlonCourse_AddScoreEntry2(PokeathlonCourseData *course, PokeathlonCourseScoreList *list, u32 participant, u32 score, u32 value1, u32 value2, u8 idx1, u8 idx2, u8 digits1, u8 digits2, u32 msgno);
void PokeathlonCourseCmd_RecvEvents(int netId, int size, void *data, void *context);
void PokeathlonCourseCmd_RecvParticipant(int netId, int size, void *data, void *context);
void PokeathlonCourseCmd_RecvAllParticipants(int netId, int size, void *data, void *context);
void PokeathlonCourseCmd_RecvProfiles(int netId, int size, void *data, void *context);
void PokeathlonCourseCmd_RecvRecord(int netId, int size, void *data, void *context);
void PokeathlonCourseCmd_RecvPacket(int netId, int size, void *data, void *context);
void PokeathlonCourseCmd_RecvEventData(int netId, int size, void *data, void *context);
void PokeathlonCourseCmd_RecvEventResult(int netId, int size, void *data, void *context);
void PokeathlonCourseCmd_RecvEventResults(int netId, int size, void *data, void *context);
void PokeathlonCourseCmd_RecvMonCounters(int netId, int size, void *data, void *context);
void PokeathlonCourseCmd_RecvResults(int netId, int size, void *data, void *context);
void PokeathlonCourseCmd_RecvJuiceRecord(int netId, int size, void *data, void *context);
int PokeathlonCourseCmd_EventsSize(void);
int PokeathlonCourseCmd_ParticipantSize(void);
int PokeathlonCourseCmd_AllParticipantsSize(void);
u32 PokeathlonCourseCmd_ProfilesSize(void);
int PokeathlonCourseCmd_RecordSize(void);
int PokeathlonCourseCmd_MonCountersSize(void);
int PokeathlonCourseCmd_ResultsSize(void);
u32 PokeathlonCourseCmd_JuiceRecordSize(void);
void *PokeathlonCourseCmd_GetEventDataBuffer(int netId, void *context);
void *PokeathlonCourseCmd_GetRecordBuffer(int netId, void *context);
void *PokeathlonCourseCmd_GetResultsBuffer(int netId, void *context);
void *PokeathlonCourseCmd_GetMonCountersBuffer(int netId, void *context, int size);
void *PokeathlonCourseCmd_GetJuiceRecordBuffer(int netId, void *context);

// Sprite resources and course Pokemon objects
PokeathlonCourseSpriteResources *PokeathlonCourseSprites_CreateResources(enum HeapID heapId, u32 flags, NNS_G2D_VRAM_TYPE charVram);
void PokeathlonCourseSprites_FreeResources(PokeathlonCourseSpriteResources *resources);
Sprite *PokeathlonCourseSprites_CreateCountdown(PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, int priority, NNS_G2D_VRAM_TYPE whichScreen, enum HeapID heapId);
Sprite *PokeathlonCourseSprites_CreateTimerDigit(PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, int priority, enum HeapID heapId);
Sprite *PokeathlonCourse_CreateTimerDigitSprite(PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, int priority, enum HeapID heapId);
Sprite *PokeathlonCourseSprites_CreateLapCounterDigit(PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, int priority, enum HeapID heapId);
Sprite *PokeathlonCourseSprites_CreateNewRecord(PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, int priority, enum HeapID heapId);
Sprite *PokeathlonCourseSprites_CreateTimeUpCountdown(PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, int priority, enum HeapID heapId);
Sprite *PokeathlonCourse_CreateTimerDigitSpriteAlt(PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, int priority, enum HeapID heapId);
Sprite *PokeathlonCourseSprites_CreateStart(PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, NNS_G2D_VRAM_TYPE whichScreen, int priority, enum HeapID heapId);
Sprite *PokeathlonCourseSprites_CreateMarker(PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, int priority, enum HeapID heapId);
PokeathlonCourseMonObjects *PokeathlonCourseMonObjects_Create(enum HeapID heapId, int count, int baseDrawPriority, PokeathlonCourseSpriteResources *resources, SpriteList *spriteList);
void PokeathlonCourseMonObjects_Free(PokeathlonCourseMonObjects *objects);
void PokeathlonCourseMonObjects_Load(PokeathlonCourseMonObjects *objects, int count, PokeathlonCourseMonInfo *infos, PokeathlonCourseMonGfxTemplate *template, u32 priority, int baseIndex);
BOOL PokeathlonCourseMonObjects_IsLoaded(PokeathlonCourseMonObjects *objects);
PokeathlonCourseMonObject *PokeathlonCourseMonObjects_Get(PokeathlonCourseMonObjects *objects, u8 index);
void PokeathlonCourseMonObjects_SetPalette(PokeathlonCourseMonObjects *objects, u8 index, NNS_G2D_VRAM_TYPE vram, const u16 *palette);
PokeathlonCourseMonGfx *PokeathlonCourseMonObject_GetGfx(PokeathlonCourseMonObject *object);
void PokeathlonCourseMonObject_SetDrawFlag(PokeathlonCourseMonObject *object, u8 draw);
void PokeathlonCourseMonObject_SetShadowDrawFlag(PokeathlonCourseMonObject *object, BOOL draw);
void PokeathlonCourseMonObject_SetMonDrawFlag(PokeathlonCourseMonObject *object, BOOL draw);
void PokeathlonCourseMonObject_SetDrawPriority(PokeathlonCourseMonObject *object, int drawPriority);
void PokeathlonCourseMonObject_SetDrawPriorityStep(PokeathlonCourseMonObject *object, s32 step);
void PokeathlonCourseMonObject_SetAffineOverwriteMode(PokeathlonCourseMonObject *object, u8 mode);
void PokeathlonCourseMonObject_SetAffineMatrix(PokeathlonCourseMonObject *object, VecFx32 *matrix);
void PokeathlonCourseMonObject_SetAnimStateRaw(PokeathlonCourseMonObject *object, u32 animState);
void PokeathlonCourseMonObject_SetAnimState(PokeathlonCourseMonObject *object, u32 animState);
void PokeathlonCourseMonObject_SetAnim(PokeathlonCourseMonObject *object, int anim);
void PokeathlonCourseMonObject_SetAnimCode(PokeathlonCourseMonObject *object, int anim);
BOOL PokeathlonCourseMonObject_IsAnimated(PokeathlonCourseMonObject *object);
void PokeathlonCourseMonObject_SetPosition(PokeathlonCourseMonObject *object, s32 x, s32 y, BOOL moveShadow);
void PokeathlonCourseMonObject_SetMonPosition(PokeathlonCourseMonObject *object, s32 x, s32 y);
void PokeathlonCourseMonObject_GetSpritePosition(PokeathlonCourseMonObject *object, s32 *x, s32 *y);
void PokeathlonCourseMonObject_GetPosition(PokeathlonCourseMonObject *object, s32 *x, s32 *y);
void PokeathlonCourseMonObject_Move(PokeathlonCourseMonObject *object, s32 dx, s32 dy, u32 animState, BOOL moveShadow);

#endif // POKEHEARTGOLD_POKEATHLON_POKEATHLON_COURSE_INTERNAL_H
