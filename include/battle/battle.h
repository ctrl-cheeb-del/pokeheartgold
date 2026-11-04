#ifndef POKEHEARTGOLD_BATTLE_H
#define POKEHEARTGOLD_BATTLE_H

#include "constants/battle.h"
#include "constants/moves.h"

#include "bag.h"
#include "bag_cursor.h"
#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "game_stats.h"
#include "item.h"
#include "move.h"
#include "msgdata.h"
#include "obj_char_transfer.h"
#include "options.h"
#include "palette.h"
#include "player_data.h"
#include "pokedex.h"
#include "pokemon_storage_system.h"
#include "pokepic.h"
#include "sav_chatot.h"
#include "sprite.h"
#include "sprite_system.h"
#include "sys_task_api.h"
#include "trainer_data.h"
#include "message_printer_number.h"
#include "font_sprite.h"

typedef struct BattleMessage {
    u8 command;
    u8 tag;
    u16 id;
    int param[6];
    int numDigits;
    int battlerId;
} BattleMessage;

typedef struct BattleMessageData {
    u32 id;
    int tag;
    int params[6];
} BattleMessageData;

typedef struct GetterWork GetterWork;

typedef struct FieldConditionData {
    u32 weatherTurns;
    u8 futureSightTurns[4];
    u8 wishTurns[4];
    u16 futureSightMoveNo[4];
    int battlerIdFutureSight[4];
    int futureSightDamage[4];
    u8 wishTarget[4];
} FieldConditionData;

typedef struct SideConditionData {
    u32 reflectBattler : 2;
    u32 reflectTurns : 3;
    u32 lightScreenBattler : 2;
    u32 lightScreenTurns : 3;
    u32 mistBattler : 2;
    u32 mistTurns : 3;
    u32 safeguardBattler : 2;
    u32 safeguardTurns : 3;
    u32 followMeFlag : 1;
    u32 battlerIdFollowMe : 2;
    u32 battlerBitKnockedOffItem : 6;
    u32 unk0_1D : 3;
    u32 spikesLayers : 2;
    u32 toxicSpikesLayers : 2;
    u32 unk4_4 : 28;
} SideConditionData;

typedef struct TurnData {
    u32 struggleFlag : 1;
    u32 ppDecrementFlag : 1;
    u32 protectFlag : 1;
    u32 helpingHandFlag : 1;
    u32 magicCoatFlag : 1;
    u32 snatchFlag : 1;
    u32 roostFlag : 1;
    u32 runFlag : 2; // 1 - Fled using item, 2 - Fled using ability
    u32 endureFlag : 1;
    u32 unk0_A : 22;
    int physicalDamage[4];
    int battlerIdPhysicalDamage;
    int battlerBitPhysicalDamage;
    int specialDamage[4];
    int battlerIdSpecialDamage;
    int battlerBitSpecialDamage;
    int lastDamageTaken;
    int battlerIdLastDamage;
    int assuranceDamageMask;
} TurnData;

typedef struct SelfTurnData {
    u32 ignorePressure : 1;
    u32 lightningRodFlag : 1;
    u32 stormDrainFlag : 1;
    u32 moldBreakerFlag : 1;
    u32 trickRoomFlag : 1;
    u32 endureItemFlag : 1;
    u32 rolloutCount : 3;
    u32 unk0_9 : 23;
    int physicalDamage;
    int battlerIdPhysicalAttacker;
    int specialDamage;
    int battlerIdSpecialAttacker;
    int statusFlags;
    int shellBellDamage;
} SelfTurnData;

typedef struct TrainerAIData {
    u8 evalStep;
    u8 moveSlot;
    u16 move;
    s8 movePoints[4]; // higher points = more priority for selection
    int calcTemp;
    u32 aiFlags;
    u8 stateFlags;
    u8 aiBitShift;
    u8 unk12;
    u8 unk13;
    u8 *unk14;
    u8 moveDamageRolls[4];
    u16 moves[BATTLER_MAX][MOVES_MAX];
    u8 abilities[BATTLER_MAX];
    u16 heldItems[BATTLER_MAX];
    u16 trainerItems[2][4];
    u32 scriptStackPointer[8];
    u8 scriptStackSize;
    u8 trainerItemCounts[2];
    u8 battlerIdAttacker;
    u8 battlerIdTarget;
    u8 useItem[2];
    u8 usedItemCondition[2];
    u16 usedItem[2];
    u8 selectedTarget[4];
    MoveTbl moveData[NUM_MOVES + 1];
    ItemData *itemData;
    u16 unk280[4];
    u16 unk288[4];
} TrainerAIData;

typedef struct MoveFailFlags {
    u32 paralysis : 1;
    u32 noEffect : 1;
    u32 imprison : 1;
    u32 infatuation : 1;
    u32 disabled : 1;
    u32 taunt : 1;
    u32 flinch : 1;
    u32 confusion : 1;
    u32 gravity : 1;
    u32 healBlock : 1;
    u32 unused : 21;
} MoveFailFlags;

typedef struct MoveEffectData {
    u32 disabledTurns : 3;
    u32 encoredTurns : 3;
    u32 isCharged : 2;
    u32 tauntTurns : 3;
    u32 protectSuccessTurns : 2;
    u32 perishSongTurns : 2;
    u32 rolloutCount : 3;
    u32 furyCutterCount : 3;
    u32 stockpileCount : 3;
    u32 stockpileDefCount : 3;
    u32 stockpileSpDefCount : 3;
    u32 truantFlag : 1;
    u32 flashFire : 1;
    u32 battlerIdLockOn : 2;
    u32 mimicedMoveIndex : 4;
    u32 battlerIdBinding : 2;
    u32 battlerIdMeanLook : 2;
    u32 lastResortCount : 3;
    u32 magnetRiseTurns : 3;
    u32 healBlockTurns : 3;
    u32 embargoFlag : 3;
    u32 knockOffFlag : 1;   // unclear whether true mean knocked off or not knocked
                            // off based on current information on its usage
    u32 metronomeTurns : 4; // refers to the item, not the move
    u32 micleBerryFlag : 1;
    u32 custapBerryFlag : 1;
    u32 quickClawFlag : 1;
    u32 meFirstFlag : 1;
    u32 unk4_2F : 1; // unused
    int rechargeCount;
    int fakeOutCount;
    int slowStartTurns;
    int meFirstCount;
    int substituteHp;
    u32 transformPersonality;
    u16 disabledMove;
    u16 bindingMove;
    u16 encoredMove;
    u16 encoredMoveIndex;
    u16 lastResortMoves[4];
    u16 moveNoChoice;
    u16 transformGender;
    int heldItemRestoreHp;
} MoveEffectData;

typedef struct BattleMon {
    u16 species;
    u16 atk;
    u16 def;
    u16 speed;
    u16 spAtk;
    u16 spDef;
    u16 moves[MAX_MON_MOVES];
    u32 hpIV : 5;
    u32 atkIV : 5;
    u32 defIV : 5;
    u32 speedIV : 5;
    u32 spAtkIV : 5;
    u32 spDefIV : 5;
    u32 isEgg : 1;
    u32 hasNickname : 1;
    s8 statChanges[NUM_BATTLE_STATS];
    int weight;
    u8 type1;
    u8 type2;
    u8 form : 5;
    u8 shiny : 1;
    u8 unk26_6 : 2;
    u8 ability;
    u32 sendOutFlag : 1;
    u32 intimidateFlag : 1;
    u32 traceFlag : 1;
    u32 downloadFlag : 1;
    u32 anticipationFlag : 1;
    u32 forewarnFlag : 1;
    u32 slowStartFlag : 1;
    u32 slowStartEnded : 1;
    u32 friskFlag : 1;
    u32 moldBreakerFlag : 1;
    u32 pressureFlag : 1;
    u32 unk28_B : 21;
    u8 movePPCur[MAX_MON_MOVES];
    u8 movePP[MAX_MON_MOVES];
    u8 level;
    u8 friendship;
    u16 nickname[POKEMON_NAME_LENGTH + 1];
    s32 hp;
    u32 maxHp;
    u16 otName[PLAYER_NAME_LENGTH + 1];
    u32 exp;
    u32 personality;
    u32 status;
    u32 status2;
    u32 otid;
    u16 item;
    u16 unk76;
    u8 hitCount;
    u8 msgFlag;
    u8 gender : 4;
    u8 otGender : 4;
    u8 ball;
    u32 moveEffectFlags;
    u32 moveEffectFlagsTemp;
    MoveEffectData moveEffectData;
} BattleMon;

typedef struct PokemonStats {
    u32 stats[6];
} PokemonStats;

typedef struct PlayerActions {
    ControllerCommand command;
    u32 battlerIdTarget;
    u32 commandParam;
    u32 inputSelection;
} PlayerActions;

typedef struct BattleContext {
    u8 selectionState[4];
    u8 selectionNextState[4];
    ControllerCommand command;
    ControllerCommand commandNext;
    int stateFieldConditionUpdate;
    int fieldConditionUpdateData;
    int stateUpdateMonCondition;
    int updateMonConditionData;
    int stateUpdateFieldConditionExtra;
    int updateFieldConditionExtraData;
    int stateBeforeTurn;
    int beforeTurnData;
    int attackerAfterMoveState;
    int unk_34;
    int afterMoveMessageType;
    int afterMoveHitState;
    int afterMoveEffectState;
    int afterMoveEffectIndex;
    int tryMoveState;
    int checkMoveHitState;
    int checkAttackerStatusState;
    int checkMoveImmunityState;
    int sendOutState;
    int vanishOffBattlerId;
    int unk_60;
    int battlerIdAttacker;
    int battlerIdAttackerTemp;
    int battlerIdTarget;
    int battlerIdTargetTemp;
    int battlerIdFainted;
    int battlerIdSwitch;
    int battlerIdSwitchTemp;
    int battlerIdAbility;
    int battlerIdMagicCoat;
    int statChangeType;
    int statChangeParam;
    int statChangeFlag;
    int battlerIdStatChange;
    int lastBattlerId;
    int gainedExp;
    int partyGainedExp;
    u32 expEarnFlags[2];
    NarcId scriptNarcId;
    int scriptFileId;
    int scriptSeqNo;
    int scriptStackDepth;
    NarcId scriptStackNarcId[4];
    int scriptStackFileId[4];
    int scriptStackSeqNo[4];
    int executionIndex;
    int waitCounter;
    BattleMessage buffMsg;
    int battlerIdTemp;
    int battlerIdLeechSeedRecv;
    int battlerIdLeechSeeded;
    int moveTemp;
    int itemTemp;
    int abilityTemp;
    int msgTemp;
    int calcTemp;
    int tempData;
    u32 showPartyFlags[4];
    u32 payDayCount;
    int totalTurns;
    int totalTimesFainted[4];
    int totalDamage[4];
    int meFirstTotal;
    GetterWork *getterWork;
    PokemonStats *prevLevelStats;
    u32 fieldCondition;
    FieldConditionData fieldConditionData;
    u32 fieldSideConditionFlags[2];
    SideConditionData fieldSideConditionData[2];
    TurnData turnData[4];
    SelfTurnData selfTurnData[4];
    MoveFailFlags moveFail[4];
    TrainerAIData trainerAIData;
    u32 *aiScriptTemp;
    u32 aiScriptCursor;
    u32 battleStatus;
    u32 battleStatus2;
    int damage;
    int hitDamage; // amount of damage dealt on hit, ie ignoring overkill damage
    int criticalCnt;
    int criticalMultiplier;
    int movePower;
    int powerMultiplier;
    int hpCalc;
    int moveType;
    int moveAnimVariant;
    int prizeMoneyValue;
    u32 moveStatusFlag;
    u32 sideEffectFlagsDirect;
    u32 sideEffectFlagsIndirect;
    u32 sideEffectFlagsAbility;
    u8 multiHitCount;
    u8 multiHitCountTemp;
    u8 moveTargetLoopIndex;
    u8 beatUpCount;
    u32 multiHitLoop;
    u32 moveCheckSkipFlags;
    u32 checkMultiHit;
    u32 status2ClearMask[4];
    u8 selectedMonIndex[4];
    u8 switchMonIndex[4];
    u8 aiSwitchedPartySlot[4];
    PlayerActions playerActions[4];
    u8 executionOrder[4]; // accounts for running, items, etc used in battler
                          // slots
    u8 turnOrder[4];      // by pokemon speed, accounting for trick room
    u32 effectiveSpeed[4];
    u8 linkBuffer[4][4][16];
    u8 battleBuffer[4][256];
    int battleScriptBuffer[400];
    BattleMon battleMons[4];
    u32 moveNoTemp;
    u32 moveNoCur;
    u32 moveNoPrev;
    u32 moveNoLockedInto[4];
    u16 moveNoProtect[4];
    u16 moveNoHit[4];
    u16 moveNoHitBattler[4];
    u16 moveNoHitType[4];
    u16 moveNoBattlerPrev[4];
    u16 moveNoCopied[4];
    u16 moveNoCopiedHit[4][4];
    u16 moveNoSketch[4];
    u16 moveNoSelected[4];
    u16 movePos[4];
    u16 conversion2Move[4];
    u16 conversion2BattlerId[4];
    u16 conversion2Type[4];
    u16 moveNoMetronome[4];
    int storedDamage[4];
    int battlerIdStoredDamage[4];
    int turnOrderIndexTemp;
    u8 switchInFlag;
    u8 levelUpMons;
    u16 unk_310A;
    u16 quickClawRandom[4];
    int flingData;
    int flingScript;
    u8 safariCatchRateStage;
    u8 safariRunAttempts;
    u8 runAttempts;
    u8 battleEndFlag;
    u8 magnitude;
    u8 weatherCheckFlag;
    s16 hpTemp;
    u16 recycleItem[4];
    u8 partyOrder[4][6];
    int victoryMusicPlayed;
    int queueTimeout;
    u8 recordInputFlags[4];
    int battlersOnField;
    u32 battleContinueFlag : 1;
    u32 unused : 31;
} BattleContext;

typedef struct BattleSystem BattleSystem;

typedef struct BattleHpBar {
    struct {
        u8 script;
    };
    ManagedSprite *boxObj;
    ManagedSprite *arrowObj;
    BattleSystem *battleSystem;
    SysTask *task;
    Window unk14;
    u8 battlerId;
    u8 type;
    u8 monId;
    u8 safariBallCount;
    s32 hp;
    s32 maxHp;
    s32 gainedHp;
    s32 hpCalc;
    s32 exp;
    s32 maxExp;
    s32 gainedExp;
    s32 expCalc;
    u8 level;
    u8 gender;
    u8 status;
    u8 caught;
    u8 command;
    u8 delay;
    u8 expSoundTimer;
    u8 slideOut : 1;
    u8 slideDone : 1;
    u8 unk_4F_2 : 1;
    u8 showHpNumbers : 1;
    SysTask *sysTask;
    u16 bobAngle;
} BattleHpBar;

typedef struct BallThrow BallThrow;

typedef struct BattleCursorPosition {
    s8 commandX;
    s8 commandY;
    s8 moveX;
    s8 moveY;
    s8 targetX;
    s8 targetY;
    s8 monTargetType;
    u8 unk_07[1];
} BattleCursorPosition;

typedef struct OpponentData {
    u32 inputTasks[6];
    ManagedSprite *managedSprite;
    u32 *unk1C;
    Pokepic *pokepic;
    u32 *unk24;
    BattleHpBar hpBar;
    BattleCursorPosition cursorPosition;
    BallThrow *ballData;
    u8 unk8C[0x108];
    u8 battlerId;
    u8 battlerType;
    u8 inputMode;
    u8 mainMenuShown;
    SysTask *pokepicBobTask;
    u16 pokepicBobAngle;
    int substituteShown;
    NARC *pokepicAnimNarc;
    u8 commandReceived;
    u8 unk1A9[3];
} OpponentData;

typedef struct BattleTerrain {
    ManagedSprite *sprite;
    BattleSystem *battleSystem;
    u8 side;
    u8 terrainId;
    s16 unkA;
    s16 unkC;
    u16 unused;
} BattleTerrain; // size: 0x10

typedef struct MonPicData {
    u8 *charBuffer;
    int narcId;
    int paletteId;
    int height;
} MonPicData;

typedef struct BattleSystemUnusedWords {
    int unk0;
    int unk4;
    int unk8;
} BattleSystemUnusedWords;

typedef struct BattleInput BattleInput;

struct BattleSystem {
    struct GF3DVramMan *gf3dVramMan;
    BgConfig *bgConfig;
    Window *window;
    MsgData *msgData;
    MsgData *attackMsgData;
    MessageFormat *msgFormat;
    String *msgBuffer;
    u32 drawGraphicsTask;
    u32 criticalHpMusicTask;
    u32 scrollBgTask;
    PaletteData *palette;
    u32 battleType;
    BattleContext *ctx;
    OpponentData *opponentData[4];
    int maxBattlers;
    PlayerProfile *playerProfile[4];
    Bag *bag;
    BagCursor *bagCursor;
    Pokedex *pokedex;
    PCStorage *storage;
    Party *trainerParty[4];
    SOUND_CHATOT *chatotVoice[4];
    PokepicManager *pokepicManager;
    struct BattleAnimSystem *animSystem;
    SpriteSystem *spriteRenderer;
    SpriteManager *gfxHandler;
    u32 *unk98;
    struct BattleSetupSub_134 *unk9C;
    u16 trainerId[4];
    u8 trainerGender[4];
    Trainer trainers[4];
    BattleTerrain terrains[2]; // Battle Background..?
    BattleInput *battleInput;
    struct PartyGauge *partyGauges[2];
    BattleNumberPrinter *hpNumPrinter;
    BattleNumberPrinter *levelNumPrinter;
    struct PaletteBlink *msgIcon;
    Options *options;
    struct SavePalPad *palPad;
    struct WaitingIcon *waitingIcon;
    u8 *keyPressedSave;
    struct LinkBattleScreenArgs *linkScreenArgs;
    struct PokepicAnimManager *pokepicAnimManager; // related to animations
    NNSG2dCellTransferState *cellTransferState;
    MonPicData monPicData[4];
    BattleSystemUnusedWords unk210;
    GameStats *gameStats;
    u8 *bgTiles;
    u16 *bgPalette;
    u8 sendBuffer[0x1000];
    u8 recvBuffer[0x1000];
    u16 bgPaletteBackup[0x70];
    u16 objPaletteBackup[0x70];
    u16 sendReadPos;
    u16 sendWritePos;
    u16 sendEndPos;
    u16 recvReadPos;
    u16 recvWritePos;
    u16 recvEndPos;
    u8 *linkSendState;
    u8 *linkRecvState;
    u8 isServer;
    u8 graphicsMode;
    u8 battleFinished;
    u8 resetBlendRequested : 1;
    u8 battleBanksRequested : 1;
    u8 subMenuBanksRequested : 1;
    u8 criticalHpMusic : 2;
    u8 criticalHpMusicDelay : 3;
    Terrain terrain;
    int backgroundId;
    int location;
    u32 battleSpecial;
    TIMEOFDAY timezone; // might be timeOfDay? unclear
    int safariBallCnt;
    u8 monsBattled[4];
    u32 regulationFlag;
    u8 battleOutcomeFlag;
    u8 tutorialState;
    u16 ballsThrown;
    int evolutionLocation;
    int unk2428;
    int weather;
    BOOL metBill;
    u32 lcrngSeedBackup;
    int bgScrollY;
    int caughtBattlerId;
    int mainMenuReady;
    u8 switchingOrCanPickCommandMask;
    u8 trainerAIOverlayLoaded;
    u16 networkId;
    u32 rand;
    u32 randTemp;
    u16 recordSentCount[4];
    u16 recordRecvCount[4];
    u16 recordInputCount[4];
    int linkPositions[4];
    u32 isRecordingPaused : 1;
    u32 momsSavingsActive : 1;
    u32 hasNonHgssPlayer : 1;
    u32 isFishing : 1;
    u32 unk2474_4 : 28;
    u32 linkVersionMismatch;
    SysTask *recordingStopTask;
    u8 chatotVoiceParam[4];
    Pokemon *bugContestCaughtMon;
    u8 followMonSlot[4];
};

struct GetterWork {
    BattleSystem *battleSystem;
    BattleContext *ctx;
    BallThrow *ballData;
    ManagedSprite *sprites[2];
    TextOBJ *fontOam;
    ObjCharSpaceReservation charSpace;
    int captureType;
    int state;
    int ballID;
    int tempData[8];
    void *tempPointers[2];
}; // size: 0x58

typedef BOOL (*BtlCmdFunc)(BattleSystem *, BattleContext *);

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8[4];
    u16 unk10;
} UnkBtlCmdStruct_CPM;

// This is information used for selecting a target on the bottom screen in a
// double battle
typedef struct TargetPokemon {
    u8 selectedMon;
    u8 gender : 2;
    u8 exists : 1;
    u8 unused1_3 : 5;
    u8 status;
    u8 unused3;
    s16 hp;
    u16 hpMax;
} TargetPokemon;

// Information used for selecting an item on the bottom screen
typedef struct BattleItem {
    u16 id;
    u8 page;
    u8 monIndex;
} BattleItem;

typedef struct BallThrowParams {
    s32 kind;
    enum HeapID heapID;
    s32 mode;
    s32 resTagOffset;
    int ball;
    s32 bgPriority;
    s32 keepSubSurface;
    SpriteSystem *spriteSystem;
    PaletteData *paletteData;
    BattleSystem *battleSystem;
} BallThrowParams;

typedef struct PokedexEntryPopupArgs {
    BgConfig *bgConfig;
    PaletteData *paletteData;
    PokepicManager *pokepicManager;
    Pokemon *mon;
    BOOL natDexEnabled;
    enum HeapID heapID;
} PokedexEntryPopupArgs;

#endif
