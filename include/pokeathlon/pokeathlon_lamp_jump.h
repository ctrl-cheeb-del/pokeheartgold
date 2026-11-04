#ifndef POKEHEARTGOLD_POKEATHLON_POKEATHLON_LAMP_JUMP_H
#define POKEHEARTGOLD_POKEATHLON_POKEATHLON_LAMP_JUMP_H

#include "global.h"

#include "pokeathlon/pokeathlon.h"
#include "pokeathlon/pokeathlon_course_types_def.h"

#include "bg_window.h"
#include "camera.h"

// Lamp Jump: flicking one of the player's three Pokemon downward on the trampoline launches it upward, and the
// Pokemon earn points for the lamps they reach. The other participants' points are simulated from their stats.

#define LAMP_JUMP_COLUMNS 128 // of the trampoline
#define LAMP_JUMP_LAMPS   29

// One of the player's three Pokemon.
typedef struct PokeathlonLampJumpMon {
    PokeathlonCourseMonObject *sprite;
    PokeathlonCourseSpritePoolSprite *effectSprite;
    fx32 drawX;
    fx32 drawY;
    u32 unk10;
    u32 unk14;
    fx32 velocityX;
    fx32 x;
    u16 score;
    u16 unk22;
    u16 combo;  // lamps hit in this jump, up to 5
    u8 stunned; // cannot be touched while set
    u8 stunTimer;
    u8 bounceReady;
    u8 colliding[POKEATHLON_TEAM_SIZE]; // touching each of the other Pokemon
    s32 bounce;      // scales the bounce off the trampoline, in twelfths
    s32 stunFrames;  // after a collision
    s32 flickScale;  // scales the sideways speed of a flick, in twelfths
} PokeathlonLampJumpMon;

// Vertical motion of one Pokemon.
typedef struct PokeathlonLampJumpJump {
    fx32 velocity;
    fx32 unk04;
    s32 height;
    u32 unk0C;
    BOOL airborne; // above the trampoline after a bounce
    BOOL jumping;
    fx32 launchVelocity;
} PokeathlonLampJumpJump;

// The trampoline: a height per column (2 pixels wide); below 0 = pressed down.
typedef struct PokeathlonLampJumpTrampoline {
    s32 surface[LAMP_JUMP_COLUMNS];                     // the lowest of the dents and lines below
    s32 dents[POKEATHLON_TEAM_SIZE][LAMP_JUMP_COLUMNS]; // the dent under each Pokemon
    s32 lines[3][LAMP_JUMP_COLUMNS];                    // the cloth between two Pokemon: 0-1, 1-2, 2-0
    s32 monColumns[POKEATHLON_TEAM_SIZE];               // the column of each Pokemon
} PokeathlonLampJumpTrampoline;

typedef struct PokeathlonLampJump {
    BgConfig *bgConfig;
    Window windows[5];
    enum HeapID heapId;
    void *bg2ScreenFile;
    NNSG2dScreenData *bg2Screen;
    PokeathlonCourseSpritePool *scene;
    PokeathlonCourseSpritePoolSprite *timerLabel;
    PokeathlonCourseSpritePoolSprite *playerSprites[POKEATHLON_PARTICIPANTS];
    PokeathlonCourseSpritePoolSprite *effectSprites[3];
    Sprite *timerDigits[2];
    struct PokeathlonLampJumpLamps *lamps;
    PokeathlonLampJumpMon mons[POKEATHLON_TEAM_SIZE];
    struct PokeathlonLampJumpCpuPlayers *cpuPlayers;
    int timer;      // frames left
    u8 selectedMon; // 3 = none
    u8 holdFrames;
    u8 hitLamp;    // sent to the other players every frame
    u8 nextEffect; // next of effectPositions / effectPending
    VecFx32 effectPositions[POKEATHLON_TEAM_SIZE];
    u8 effectPending[POKEATHLON_TEAM_SIZE];
    VecFx32 touchStart;
    u8 unk178[0x10];
    PokeathlonCourseSpriteResources *spriteResources;
    PokeathlonCourseMonObjects *monSpriteManager;
    Camera *camera;
    VecFx32 cameraTarget;

    union {
        struct {
            s32 trampolineRows[7][LAMP_JUMP_COLUMNS]; // the trampoline as rows
            s32 monColumns[POKEATHLON_TEAM_SIZE];     // x / 2 of each Pokemon, in pixels
        };

        PokeathlonLampJumpTrampoline trampoline;
    };

    PokeathlonLampJumpJump jumps[POKEATHLON_TEAM_SIZE];
    NNSG2dCellTransferState *cellTransferState;
} PokeathlonLampJump;

// NARC a/1/7/0 member 6: parameters per performance level.
typedef struct PokeathlonLampJumpMonParams {
    u32 acceleration[5];
    u32 velocity[5];
    u32 scale[5];
} PokeathlonLampJumpMonParams;

// A block of the link data exchanged every frame (PokeathlonCourse_GetDataCopyArea).
typedef union PokeathlonLampJumpSyncBlock {
    s32 words[9];
    u8 bytes[36];
} PokeathlonLampJumpSyncBlock;

BOOL PokeathlonLampJump_Init(PokeathlonCourseData *course);
BOOL PokeathlonLampJump_Draw(PokeathlonCourseData *course);
BOOL PokeathlonLampJump_ShowResults(PokeathlonCourseData *course);
BOOL PokeathlonLampJump_Exit(PokeathlonCourseData *course);
BOOL PokeathlonLampJump_Play(PokeathlonCourseData *course, u8 *state);
BOOL PokeathlonLampJump_CalcScores(PokeathlonCourseData *course, u8 *state);
BOOL PokeathlonLampJump_CheckCollision(const VecFx32 *a, fx32 radiusA, const VecFx32 *b, fx32 radiusB);

// One lamp; touching a lit lamp puts it out and scores.
typedef struct PokeathlonLampJumpLamp {
    BOOL lit;
    VecFx32 pos;
    PokeathlonCourseSpritePoolSprite *sprite;
    PokeathlonCourseSpritePoolSprite *pointsSprite; // the points of the hit
    PokeathlonCourseSpritePoolSprite *hitSprite;
} PokeathlonLampJumpLamp;

typedef struct PokeathlonLampJumpLamps {
    PokeathlonLampJumpLamp lamps[LAMP_JUMP_LAMPS];
    int relightTimer;
} PokeathlonLampJumpLamps;

// The participants without a player: every 3 frames one of them may hit a lamp, more likely with more Jump
// and Skill.
typedef struct PokeathlonLampJumpCpuPlayers {
    BOOL active;
    u8 *dataCopy;       // PokeathlonCourse_GetDataCopyArea
    u8 skill[POKEATHLON_PARTICIPANTS];                           // per participant, the sum of the Skill of its Pokemon
    u8 jump[POKEATHLON_PARTICIPANTS];                            // per participant, the sum of the Jump of its Pokemon
    u8 skillUpTo[POKEATHLON_PARTICIPANTS][POKEATHLON_TEAM_SIZE]; // per participant, the Skill sums up to each Pokemon (picks the one that hits)
    u8 count;
    u8 current;
    u8 tick;
    u8 interval;
    u8 first; // first participant without a player
    u8 unk21; // the same (4: none)
    u8 unk22[2];
} PokeathlonLampJumpCpuPlayers;

void PokeathlonLampJump_Draw3D(PokeathlonLampJump *lampJump);
void PokeathlonLampJump_InitCamera(PokeathlonLampJump *lampJump);
void PokeathlonLampJump_CalcTrampolineSurface(PokeathlonLampJumpTrampoline *trampoline);
void PokeathlonLampJump_UpdateJumps(PokeathlonCourseData *course, PokeathlonLampJump *lampJump);
void PokeathlonLampJump_SetRestingHeights(PokeathlonLampJump *lampJump);
void PokeathlonLampJump_LoadSpriteResources(PokeathlonCourseSpritePool *scene);
void PokeathlonLampJump_CreateSprites(PokeathlonLampJump *lampJump, PokeathlonCourseSpritePool *scene);
void PokeathlonLampJump_PlaceSprites(PokeathlonLampJump *lampJump, u8 self);
void PokeathlonLampJump_UpdateScoreDisplay(PokeathlonLampJump *lampJump);
void PokeathlonLampJump_UpdateTimerDisplay(PokeathlonLampJump *lampJump, u16 frames);
void PokeathlonLampJump_PrintPlayerNames(PokeathlonCourseData *course, PokeathlonLampJump *lampJump);
void PokeathlonLampJump_InitWindows(PokeathlonLampJump *lampJump);
void PokeathlonLampJump_PrintTotal(PokeathlonLampJump *lampJump, u16 score);
void PokeathlonLampJump_SetMonParams(PokeathlonCourseData *course, PokeathlonLampJumpMonParams *params, u8 member, PokeathlonLampJumpMon *mon);
BOOL PokeathlonLampJump_CollideMons(PokeathlonCourseData *course, PokeathlonLampJump *lampJump);
PokeathlonLampJumpLamps *PokeathlonLampJump_NewLamps(enum HeapID heapId);
void PokeathlonLampJump_FreeLamps(PokeathlonLampJumpLamps *lamps);
void PokeathlonLampJump_UpdateLamps(PokeathlonLampJumpLamps *lamps);
PokeathlonLampJumpCpuPlayers *PokeathlonLampJump_NewCpuPlayers(enum HeapID heapId, int count, int unused, u8 *dataCopy, PokeathlonCourseData *course);
void PokeathlonLampJump_FreeCpuPlayers(PokeathlonLampJumpCpuPlayers *cpu);
int PokeathlonLampJump_UpdateCpuPlayers(PokeathlonCourseData *course, PokeathlonLampJumpCpuPlayers *cpu);

extern u8 gPokeathlonLampJumpSoundPlayers[]; // sound player of each Pokemon
extern int gPokeathlonLampJumpTrampolineRed; // red of the next trampoline vertex

#endif // POKEHEARTGOLD_POKEATHLON_POKEATHLON_LAMP_JUMP_H
