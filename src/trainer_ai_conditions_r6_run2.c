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

void ov10_0221DA24(BattleSystem *, AIState *);
void ov10_0221DAE4(BattleSystem *, AIState *);
void ov10_0221DBA4(BattleSystem *, AIState *);
void ov10_0221DC48(BattleSystem *, AIState *);
void ov10_0221DCEC(BattleSystem *, AIState *);
void ov10_0221DD5C(BattleSystem *, AIState *);

#define U8(p, o)  (*(u8 *)&(p)->data[(o)])
#define U16(p, o) (*(u16 *)&(p)->data[(o)])
#define U32(p, o) (*(u32 *)&(p)->data[(o)])

void ov10_0221DA24(BattleSystem *bsys, AIState *p) {
    u32 kind, move, out, battler;
    s32 i;
    (void)bsys;
    ov10_0221EF24(p, 1);
    kind = ov10_0221EEF0(p);
    move = ov10_0221EEF0(p);
    out = ov10_0221EEF0(p);
    battler = ov10_0221EF34(p, (u8)kind);
    switch (kind) {
    case 1:
        for (i = 0; i < 4; i++) {
            if (*(u16 *)((u8 *)p + battler * 0xC0 + i * 2 + 0x2D4C) == move) {
                break;
            }
        }
        if (i < 4) {
            ov10_0221EF24(p, out);
            return;
        }
        break;
    case 3:
        if (*(u32 *)((u8 *)p + battler * 0xC0 + 0x2D8C) != 0) {
            for (i = 0; i < 4; i++) {
                if (*(u16 *)((u8 *)p + battler * 0xC0 + i * 2 + 0x2D4C) == move) {
                    break;
                }
            }
            if (i < 4) {
                ov10_0221EF24(p, out);
                return;
            }
        }
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            if (*(u16 *)((u8 *)p + battler * 8 + i * 2 + 0x370) == move) {
                break;
            }
        }
        if (i < 4) {
            ov10_0221EF24(p, out);
        }
        break;
    }
}

void ov10_0221DAE4(BattleSystem *bsys, AIState *p) {
    u32 kind, move, out, battler;
    s32 i;
    (void)bsys;
    ov10_0221EF24(p, 1);
    kind = ov10_0221EEF0(p);
    move = ov10_0221EEF0(p);
    out = ov10_0221EEF0(p);
    battler = ov10_0221EF34(p, (u8)kind);
    switch (kind) {
    case 1:
        for (i = 0; i < 4; i++) {
            if (*(u16 *)((u8 *)p + battler * 0xC0 + i * 2 + 0x2D4C) == move) {
                break;
            }
        }
        if (i == 4) {
            ov10_0221EF24(p, out);
            return;
        }
        break;
    case 3:
        if (*(u32 *)((u8 *)p + battler * 0xC0 + 0x2D8C) != 0) {
            for (i = 0; i < 4; i++) {
                if (*(u16 *)((u8 *)p + battler * 0xC0 + i * 2 + 0x2D4C) == move) {
                    break;
                }
            }
            if (i == 4) {
                ov10_0221EF24(p, out);
                return;
            }
        }
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            if (*(u16 *)((u8 *)p + battler * 8 + i * 2 + 0x370) == move) {
                break;
            }
        }
        if (i == 4) {
            ov10_0221EF24(p, out);
        }
        break;
    }
}

void ov10_0221DBA4(BattleSystem *bsys, AIState *p) {
    u32 kind, type, out, battler;
    s32 i;
    u16 move;
    (void)bsys;
    ov10_0221EF24(p, 1);
    kind = ov10_0221EEF0(p);
    type = ov10_0221EEF0(p);
    out = ov10_0221EEF0(p);
    battler = ov10_0221EF34(p, (u8)kind);
    switch (kind) {
    case 1:
        for (i = 0; i < 4; i++) {
            move = ((AiBattlerView *)p)->battlers[battler].moves[i];
            if (move != 0 && ((AiMoveView *)p)->moves[move].type == type) {
                break;
            }
        }
        if (i < 4) {
            ov10_0221EF24(p, out);
            return;
        }
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            move = ((AiStateView *)p)->knownMoves[battler].moves[i];
            if (move != 0 && ((AiMoveView *)p)->moves[move].type == type) {
                break;
            }
        }
        if (i < 4) {
            ov10_0221EF24(p, out);
        }
        break;
    }
}

void ov10_0221DC48(BattleSystem *bsys, AIState *p) {
    u32 kind, type, out, battler;
    s32 i;
    u16 move;
    (void)bsys;
    ov10_0221EF24(p, 1);
    kind = ov10_0221EEF0(p);
    type = ov10_0221EEF0(p);
    out = ov10_0221EEF0(p);
    battler = ov10_0221EF34(p, (u8)kind);
    switch (kind) {
    case 1:
        for (i = 0; i < 4; i++) {
            move = ((AiBattlerView *)p)->battlers[battler].moves[i];
            if (move != 0 && ((AiMoveView *)p)->moves[move].type == type) {
                break;
            }
        }
        if (i == 4) {
            ov10_0221EF24(p, out);
            return;
        }
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            move = ((AiStateView *)p)->knownMoves[battler].moves[i];
            if (move != 0 && ((AiMoveView *)p)->moves[move].type == type) {
                break;
            }
        }
        if (i == 4) {
            ov10_0221EF24(p, out);
        }
        break;
    }
}

void ov10_0221DCEC(BattleSystem *bsys, AIState *p) {
    u32 kind, which, out, battler;
    AiFlagFields *flags;
    (void)bsys;
    ov10_0221EF24(p, 1);
    kind = ov10_0221EEF0(p);
    which = ov10_0221EEF0(p);
    out = ov10_0221EEF0(p);
    battler = ov10_0221EF34(p, (u8)kind);
    switch (which) {
    case 0:
        flags = (AiFlagFields *)((u8 *)p + 0x2DC8 + battler * 0xC0);
        if (flags->first != 0) {
            ov10_0221EF24(p, out);
        }
        break;
    case 1:
        flags = (AiFlagFields *)((u8 *)p + 0x2DC8 + battler * 0xC0);
        if (flags->second != 0) {
            ov10_0221EF24(p, out);
        }
        break;
    }
}

void ov10_0221DD5C(BattleSystem *bsys, AIState *p) {
    u32 which, out;
    u32 battler;
    (void)bsys;
    ov10_0221EF24(p, 1);
    which = ov10_0221EEF0(p);
    out = ov10_0221EEF0(p);
    switch (which) {
    case 0:
        battler = U8(p, 0x3CF);
        if (U16(p, 0x356) == U16(p, 0x2DE8 + 0xC0 * battler)) {
            ov10_0221EF24(p, out);
        }
        break;
    case 1:
        battler = U8(p, 0x3CF);
        if (U16(p, 0x356) == U16(p, 0x2DEC + 0xC0 * battler)) {
            ov10_0221EF24(p, out);
        }
        break;
    }
}
