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

int ov106_021E6B50(void *data, void *cmd) {
    void *ctx = PTR(data, 0x418);
    if (U32(cmd, 0) != 6) {
        GF_AssertFail();
    }
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(ctx, 4), U32(cmd, 8) + 0x44, PTR(ctx, 0), U32(cmd, 4), 0, 0, 1, 0x99);
    ov106_021E69F0(ctx, U32(cmd, 4), U32(cmd, 8));
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(ctx, 4), U32(cmd, 8), PTR(ctx, 0), U32(cmd, 4), 0, 0, 1, 0x99);
    return 1;
}

int ov106_021E6BB0(void *state, void *cmd) {
    (void)state;
    if (U32(cmd, 0) != 7) {
        GF_AssertFail();
    }
    ToggleBgLayer((u8)U32(cmd, 4), (u8)U32(cmd, 8));
    return 1;
}

int ov106_021E6BD4(void *state, void *cmd) {
    (void)state;
    if (U32(cmd, 0) != 8) {
        GF_AssertFail();
    }
    SetBgPriority((u8)U32(cmd, 4), (u8)U32(cmd, 8));
    return 1;
}

int ov106_021E6BF8(void *state, void *cmd) {
    u8 *ctx = PTR(state, 0x418);
    if (U32(cmd, 0) != 9) {
        GF_AssertFail();
    }
    if (U32(cmd, 4) == 0) {
        U32(ctx, 0x1c) = U32(cmd, 8);
        U32(ctx, 0x20) = U32(cmd, 0xc);
    } else {
        U32(ctx, 0x24) = U32(cmd, 8);
        U32(ctx, 0x28) = U32(cmd, 0xc);
    }
    return 1;
}

int ov106_021E6C28(void *state, void *cmd) {
    u8 *ctx = PTR(state, 0x418);
    if (U32(cmd, 0) != 10) {
        GF_AssertFail();
    }
    U32(ctx, 0x2c) = U32(cmd, 4);
    U32(ctx, 0x30) = U32(cmd, 8);
    U32(state, 0x40c) = 3;
    U32(state, 0x410) = 4;
    return 2;
}

int ov106_021E6C5C(void *state, void *cmd) {
    u8 *ctx = PTR(state, 0x418);
    if (U32(cmd, 0) != 11) {
        GF_AssertFail();
    }
    *(volatile u16 *)0x04000050 = 0;
    U32(ctx, 0x1c) = 0;
    U32(ctx, 0x20) = 0;
    U32(ctx, 0x24) = 0;
    U32(ctx, 0x28) = 0;
    return 1;
}

int ov106_021E6C88(void *state, void *cmd) {
    u8 *ctx = PTR(state, 0x418);
    if (U32(cmd, 0) != 12) {
        GF_AssertFail();
    }
    U16(ctx, 0x18) = GF_GetCurrentPlayingBGM();
    return 1;
}

int ov106_021E6CA8(void *state, void *cmd) {
    u16 bgm;
    (void)state;
    if (U32(cmd, 0) != 13) {
        GF_AssertFail();
    }
    bgm = GF_GetCurrentPlayingBGM();
    StopBGM(bgm, 0);
    return 1;
}

int ov106_021E6CC4(void *state, void *cmd) {
    u8 *ctx = PTR(state, 0x418);
    if (U32(cmd, 0) != 14) {
        GF_AssertFail();
    }
    if (U32(cmd, 4) == 0xffffffff) {
        PlayBGM(U16(ctx, 0x18));
    } else {
        PlayBGM((u16)U32(cmd, 4));
    }
    return 1;
}

int ov106_021E6CF8(void *state, void *cmd) {
    u8 *ctx = PTR(state, 0x418);
    if (U32(cmd, 0) != 15) {
        GF_AssertFail();
    }
    ManagedSprite_SetDrawFlag(PTR(ctx, 0x10), U32(cmd, 4));
    return 1;
}

int ov106_021E6D1C(void *state, void *cmd) {
    u8 *ctx = PTR(state, 0x418);
    if (U32(cmd, 0) != 16) {
        GF_AssertFail();
    }
    ManagedSprite_SetPositionXY(PTR(ctx, 0x10), (s16)U32(cmd, 4), (s16)U32(cmd, 8));
    return 1;
}

int ov106_021E6D48(void *state, void *cmd) {
    u8 *ctx = PTR(state, 0x418);
    if (U32(cmd, 0) != 17) {
        GF_AssertFail();
    }
    ManagedSprite_SetPriority(PTR(ctx, 0x10), U32(cmd, 4));
    return 1;
}

int ov106_021E6D6C(void) {
    return 1;
}
