#ifndef POKEHEARTGOLD_POKEATHLON_POKEATHLON_COURSE_TYPES_DEF_H
#define POKEHEARTGOLD_POKEATHLON_POKEATHLON_COURSE_TYPES_DEF_H

#include "global.h"

#include "sprite.h"

// A course is played by four participants (players or NPC teams) with three Pokemon each.
#define POKEATHLON_PARTICIPANTS 4
#define POKEATHLON_TEAM_SIZE    3
#define POKEATHLON_MONS         (POKEATHLON_PARTICIPANTS * POKEATHLON_TEAM_SIZE)
#define POKEATHLON_NO_MON       POKEATHLON_MONS // "no Pokemon" in the 0..11 mon indices

#define POKEATHLON_EVENT_COUNT 10  // event ids 0..9
#define POKEATHLON_POINTS_MAX  999 // the cap of the points of a round and of a course
#define POKEATHLON_SCORE_MAX   999 // the cap of an event score

#define POKEATHLON_SOLO_ROUNDS 3 // events of a solo course
#define POKEATHLON_LINK_ROUNDS 4 // events of a link course

#define POKEATHLON_SIZE_CLASSES 3 // PokeathlonCourse_GetCollisionSizeClass returns 1..3

// The courses: the five solo courses give the medal of their name, the link courses two medals each; the last
// link course plays one of ten random event sets.
enum PokeathlonCourseId {
    POKEATHLON_COURSE_SPEED,
    POKEATHLON_COURSE_POWER,
    POKEATHLON_COURSE_SKILL,
    POKEATHLON_COURSE_STAMINA,
    POKEATHLON_COURSE_JUMP,
    POKEATHLON_COURSE_LINK_SPEED_JUMP,
    POKEATHLON_COURSE_LINK_SKILL_JUMP,
    POKEATHLON_COURSE_LINK_POWER_SKILL,
    POKEATHLON_COURSE_LINK_POWER_STAMINA,
    POKEATHLON_COURSE_LINK_SPEED_STAMINA,
    POKEATHLON_COURSE_LINK_RANDOM,
};

#define POKEATHLON_SOLO_COURSES POKEATHLON_COURSE_LINK_SPEED_JUMP // courses 0..4
#define POKEATHLON_MEDALS       POKEATHLON_SOLO_COURSES           // one per solo course

// The events (gPokeathlonCourseEvents), POKEATHLON_EVENT_COUNT of them.
enum PokeathlonEventId {
    POKEATHLON_EVENT_HURDLE_DASH,
    POKEATHLON_EVENT_PENNANT_CAPTURE,
    POKEATHLON_EVENT_CIRCLE_PUSH,
    POKEATHLON_EVENT_BLOCK_SMASH,
    POKEATHLON_EVENT_DISC_CATCH,
    POKEATHLON_EVENT_LAMP_JUMP,
    POKEATHLON_EVENT_RELAY_RUN,
    POKEATHLON_EVENT_RING_DROP,
    POKEATHLON_EVENT_SNOW_THROW,
    POKEATHLON_EVENT_GOAL_ROLL,
};

// What PokeathlonCourse_AddMonCounter counts for a Pokemon; at the end of the course the counts are added to the
// saved statistics (PokeathlonStatistics.monInstructions..monSelfImpedes).
enum PokeathlonMonCounter {
    POKEATHLON_COUNTER_INSTRUCTIONS,
    POKEATHLON_COUNTER_FAILURES,
    POKEATHLON_COUNTER_JUMPS,
    POKEATHLON_COUNTER_POINTS,
    POKEATHLON_COUNTER_TACKLES,
    POKEATHLON_COUNTER_FALLS,
    POKEATHLON_COUNTER_DASHES,
    POKEATHLON_COUNTER_SWITCHES,
    POKEATHLON_COUNTER_SELF_IMPEDES,
};

typedef struct PokeathlonCourseSpritePoolTemplate PokeathlonCourseSpritePoolTemplate;
typedef struct PokeathlonCourseSpritePoolSprite PokeathlonCourseSpritePoolSprite;
typedef struct PokeathlonCourseSpritePool PokeathlonCourseSpritePool;
typedef struct PokeathlonCourseMonInfo PokeathlonCourseMonInfo;
typedef struct PokeathlonCourseScore PokeathlonCourseScore;
typedef struct PokeathlonCourseScoreList PokeathlonCourseScoreList;
typedef struct PokeathlonCourseMonGfx PokeathlonCourseMonGfx;
typedef struct PokeathlonCourseMonGfxTemplate PokeathlonCourseMonGfxTemplate;
typedef struct PokeathlonCourseSpriteResources PokeathlonCourseSpriteResources;
typedef struct PokeathlonCourseMonObject PokeathlonCourseMonObject;
typedef struct PokeathlonCourseMonObjects PokeathlonCourseMonObjects;
typedef struct PokeathlonCourseMonGfxManager PokeathlonCourseMonGfxManager;
typedef struct PokeathlonCourseLink PokeathlonCourseLink;
typedef struct PokeathlonCoursePoint PokeathlonCoursePoint;
typedef struct PokeathlonCoursePerformance PokeathlonCoursePerformance;
typedef struct PokeathlonEventBanner PokeathlonEventBanner;
typedef struct PokeathlonCourseMessageBox PokeathlonCourseMessageBox;

struct PokeathlonCourseData;

// What the Pokemon sprite loader needs to know about one Pokemon.
struct PokeathlonCourseMonInfo {
    u16 species;
    u16 form;
    u16 isLarge; // overworld sprite uses the 64x64 frames (follower parameter byte 1)
    u8 isShiny;
    u8 gender;
    int participant;
    u32 personality;
};

// A Pokemon's front picture: char and palette data loaded uncompressed from its NARC, uploaded into a picture
// sprite's VRAM when needed.
typedef struct PokeathlonCourseMonPic {
    void *chars;
    void *palette;
} PokeathlonCourseMonPic;

// A Pokemon on a course screen: its sprite plus a shadow and a player marker. Created by the course
// sprite factory (PokeathlonCourseMonObjects_Load).
struct PokeathlonCourseMonObject {
    PokeathlonCourseMonGfx *gfx; // the loaded Pokemon sprite
    Sprite *shadowSprite;
    Sprite *markerSprite;
    s32 markerOffsetY;
    s32 shadowOffsetY; // rows between the frame bottom and the ground point
    s32 halfWidth;
    s32 halfHeight;
    s32 touchRadius;
    s32 x; // centre
    s32 y;
    s32 topRow;           // first non-transparent pixel row of the frame
    s32 collisionOffsetY; // centre of the collision circle, rows above the frame bottom
    s32 collisionRadius;
    u32 animState;
    u32 anim;
    s32 drawPriorityStep;
    BOOL shadowHidden;
};

// Collision circle of a Pokemon size class (PokeathlonCourseObject_SetCollision); each event reads its table of
// POKEATHLON_SIZE_CLASSES of them from NARC a/1/7/0.
typedef struct PokeathlonCourseCollision {
    s32 offsetY;
    s32 radius;
} PokeathlonCourseCollision;

struct PokeathlonCourseMonObjects {
    enum HeapID heapId;
    int count;
    int baseDrawPriority;
    BOOL loaded;
    SpriteList *spriteList;
    PokeathlonCourseMonGfxManager *gfxManager;
    PokeathlonCourseSpriteResources *resources;
    PokeathlonCourseMonObject objects[POKEATHLON_MONS];
};

#define POKEATHLON_RES_TYPES 4 // sprite resource managers of the course screens: char, palette, cell, animation

// What PokeathlonCourseSpritePool_New sets up: sprite and resource capacities.
struct PokeathlonCourseSpritePoolTemplate {
    int capacity;      // sprites
    int resourceCount; // resource ids
    u8 resCounts[POKEATHLON_RES_TYPES];
};

// PokeathlonCourse_GetMode, PokeathlonCourseArgs.mode
enum PokeathlonCourseMode {
    POKEATHLON_COURSE_MODE_SOLO,
    POKEATHLON_COURSE_MODE_LINK,
};

// Where the packets of the data copy area (PokeathlonCourse_GetDataCopyArea) are: the own input, the frame the host
// builds, the inputs it collects from the four participants, then the frame every participant receives.
#define POKEATHLON_COURSE_DATA_SLOT_SIZE 0x28
#define POKEATHLON_COURSE_DATA_FRAME_OUT (1 * POKEATHLON_COURSE_DATA_SLOT_SIZE)
#define POKEATHLON_COURSE_DATA_INPUTS    (2 * POKEATHLON_COURSE_DATA_SLOT_SIZE)
#define POKEATHLON_COURSE_DATA_FRAME_IN  (6 * POKEATHLON_COURSE_DATA_SLOT_SIZE)

// What the host keeps of one participant's stylus.
typedef struct PokeathlonCourseTouch {
    BOOL pressed; // on the frame the stylus touches the screen
    BOOL held;
    u32 unk8;
} PokeathlonCourseTouch;

// One of the cells around a CPU Pokemon, rated each time the Pennant Capture and Relay Run CPUs pick a target.
typedef struct PokeathlonCourseCpuCell {
    int x; // cell centre
    int y;
    int targetX; // a random point of the cell
    int targetY;
    s16 score;
    s16 index;
} PokeathlonCourseCpuCell;

// A node of the list the CPUs sort their cells with (node 0 is the head).
typedef struct PokeathlonCourseCpuCellNode {
    struct PokeathlonCourseCpuCellNode *prev;
    struct PokeathlonCourseCpuCellNode *next;
    PokeathlonCourseCpuCell *cell;
} PokeathlonCourseCpuCellNode;

// One step of a course scene; returns TRUE when the step is done.
typedef BOOL (*PokeathlonCourseStepFunc)(struct PokeathlonCourseData *course, u8 *state);

// Steps of an event's play state: the start countdown, the event itself, then the finish
enum PokeathlonEventPlayState {
    EVENT_PLAY_STATE_COUNTDOWN,
    EVENT_PLAY_STATE_RUN,
    EVENT_PLAY_STATE_FINISH,
};

#endif // POKEHEARTGOLD_POKEATHLON_POKEATHLON_COURSE_TYPES_DEF_H
