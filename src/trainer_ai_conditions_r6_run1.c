#include "global.h"

typedef struct BattleSystem BattleSystem;
typedef struct AIState {
    u8 data[0x3200];
} AIState;
typedef struct AiFlagFields {
    u32 first : 3;
    u32 second : 3;
    u32 rest : 26;
} AiFlagFields;
typedef struct AiKnownMoveSet {
    u16 moves[4];
} AiKnownMoveSet;
typedef struct AiBattlerData {
    u16 moves[4];
    u8 padding[0xB8];
} AiBattlerData;
typedef struct AiMoveData {
    u16 type;
    u8 padding[14];
} AiMoveData;
typedef struct AiStateView {
    u8 padding0[0x370];
    AiKnownMoveSet knownMoves[4];
} AiStateView;
typedef struct AiBattlerView {
    u8 padding0[0x2D4C];
    AiBattlerData battlers[4];
} AiBattlerView;
typedef struct AiMoveView {
    u8 padding0[0x3DE];
    AiMoveData moves[512];
} AiMoveView;

void ov10_0221EF24(AIState *, int);
u32 ov10_0221EEF0(AIState *);
u32 ov10_0221EF34(AIState *, u8);
int GetBattlerVar(AIState *, int, u32, void *);
u8 GetBattlerAbility(AIState *, int);
u32 ov10_0221F084(BattleSystem *, AIState *, u16, u16, u8 *, u32, u32, u32, u32);
extern const u16 ov10_0222B080[];
extern const u16 ov10_0222B098[];

void ov10_0221D67C(BattleSystem *, AIState *);
void ov10_0221D6D0(BattleSystem *, AIState *);
void ov10_0221D724(BattleSystem *, AIState *);
void ov10_0221D778(BattleSystem *, AIState *);
void ov10_0221D7CC(BattleSystem *, AIState *);
void ov10_0221D8F8(BattleSystem *, AIState *);
void ov10_0221DA24(BattleSystem *, AIState *);
void ov10_0221DAE4(BattleSystem *, AIState *);
void ov10_0221DBA4(BattleSystem *, AIState *);
void ov10_0221DC48(BattleSystem *, AIState *);
void ov10_0221DCEC(BattleSystem *, AIState *);
void ov10_0221DD5C(BattleSystem *, AIState *);

#define U8(p, o)  (*(u8 *)&(p)->data[(o)])
#define S8(p, o)  (*(s8 *)&(p)->data[(o)])
#define U16(p, o) (*(u16 *)&(p)->data[(o)])
#define U32(p, o) (*(u32 *)&(p)->data[(o)])

void ov10_0221D67C(BattleSystem *bsys, AIState *p) {
    u32 battler, offset, rhs, out;
    u32 idx;
    (void)bsys;
    ov10_0221EF24(p, 1);
    battler = ov10_0221EEF0(p);
    offset = ov10_0221EEF0(p);
    rhs = ov10_0221EEF0(p);
    out = ov10_0221EEF0(p);
    idx = ov10_0221EF34(p, (u8)battler);
    if (*(s8 *)((u8 *)p + 0x2D58 + 0xC0 * idx + offset) < (s32)rhs) {
        ov10_0221EF24(p, out);
    }
}

void ov10_0221D6D0(BattleSystem *bsys, AIState *p) {
    u32 battler, offset, rhs, out;
    u32 idx;
    (void)bsys;
    ov10_0221EF24(p, 1);
    battler = ov10_0221EEF0(p);
    offset = ov10_0221EEF0(p);
    rhs = ov10_0221EEF0(p);
    out = ov10_0221EEF0(p);
    idx = ov10_0221EF34(p, (u8)battler);
    if (*(s8 *)((u8 *)p + 0x2D58 + 0xC0 * idx + offset) > (s32)rhs) {
        ov10_0221EF24(p, out);
    }
}

void ov10_0221D724(BattleSystem *bsys, AIState *p) {
    u32 battler, offset, rhs, out;
    u32 idx;
    (void)bsys;
    ov10_0221EF24(p, 1);
    battler = ov10_0221EEF0(p);
    offset = ov10_0221EEF0(p);
    rhs = ov10_0221EEF0(p);
    out = ov10_0221EEF0(p);
    idx = ov10_0221EF34(p, (u8)battler);
    if (*(s8 *)((u8 *)p + 0x2D58 + 0xC0 * idx + offset) == (s32)rhs) {
        ov10_0221EF24(p, out);
    }
}

void ov10_0221D778(BattleSystem *bsys, AIState *p) {
    u32 battler, offset, rhs, out;
    u32 idx;
    (void)bsys;
    ov10_0221EF24(p, 1);
    battler = ov10_0221EEF0(p);
    offset = ov10_0221EEF0(p);
    rhs = ov10_0221EEF0(p);
    out = ov10_0221EEF0(p);
    idx = ov10_0221EF34(p, (u8)battler);
    if (*(s8 *)((u8 *)p + 0x2D58 + 0xC0 * idx + offset) != (s32)rhs) {
        ov10_0221EF24(p, out);
    }
}
