#include "overlay106_cinematic_internal.h"
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct {
    u32 v[4];
} Modes;
typedef struct {
    u32 v[10];
} Banks;
typedef struct {
    u32 v[3];
} Vec3;
typedef struct {
    u32 v[11];
} Setup44;
extern const Modes ov106_021E6D7C;
extern const Banks ov106_021E6DB0;
extern const Banks ov106_021E6FE8;
extern int (*const sScriptCinematicSubs_HoOh[])(void *);
extern int (*const sScriptCinematicSubs_Lugia[])(void *);
extern int (*const sScriptCinematicSubs_Arceus[])(void *);
extern const Setup44 ov106_021E6DD8;
extern const u8 ov106_021E6EFC[];
extern const u8 ov106_021E6EC4[];
extern const u8 ov106_021E6EE4[];
extern const u8 ov106_021E6E9C[];
extern const u8 ov106_021E6E2C[];
extern const u8 ov106_021E6E04[];
extern const u8 ov106_021E6E74[];
extern const u8 ov106_021E6E50[];

int ov106_021E6A80(void *state, void *cmd) {
    u32 cur;
    if (U32(cmd, 0) != 0) {
        GF_AssertFail();
    }
    cur = U32(state, 0x414);
    if (cur == U32(cmd, 4)) {
        U32(state, 0x414) = 0;
        return 2;
    }
    U32(state, 0x414) = cur + 1;
    return 0;
}

int ov106_021E6AB0(void *state, void *cmd) {
    if (U32(cmd, 0) != 1) {
        GF_AssertFail();
    }
    ov106_021E5954(state, U32(cmd, 4), U32(cmd, 8), 4);
    return 1;
}

int ov106_021E6AD0(void *state, void *cmd) {
    if (U32(cmd, 0) != 2) {
        GF_AssertFail();
    }
    ov106_021E597C(state, U32(cmd, 4), U32(cmd, 8), 4);
    return 1;
}

int ov106_021E6AF0(void *state, void *cmd) {
    if (U32(cmd, 0) != 3) {
        GF_AssertFail();
    }
    ov106_021E59A4(state, U32(cmd, 4), U32(cmd, 8), 4);
    return 1;
}

int ov106_021E6B10(void *state, void *cmd) {
    if (U32(cmd, 0) != 4) {
        GF_AssertFail();
    }
    ov106_021E59D0(state, U32(cmd, 4), U32(cmd, 8), 4);
    return 1;
}
