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

void *ov106_021E601C(int a, int b) {
    Setup44 s;
    GfGfx_EngineATogglePlanes(2, 0);
    GfGfx_EngineATogglePlanes(4, 0);
    GfGfx_EngineATogglePlanes(8, 0);
    GX_ResetBankForBG();
    s = ov106_021E6DD8;
    s.v[8] = a;
    s.v[9] = b;
    return ov106_021E5E0C(&s);
}

void ov106_021E6064(void *data) {
    ov106_021E5E5C(data, 1, 0, 1);
    GX_SetBankForBG((GXVRamBG)4);
    GfGfx_EngineATogglePlanes(14, 1);
}

int ScriptCinematic_HoOh(void *data) {
    U32(data, 0x40c) = sScriptCinematicSubs_HoOh[U32(data, 0x40c)](data);
    if (U32(data, 0x40c) == 6) {
        return 0;
    }
    ov106_021E5C30(data);
    return 1;
}

int ov106_021E60B0(void *data) {
    u32 i;
    ov106_021E5900(data);
    ov106_021E5A44((u8 *)PTR(data, 0) + 4);
    ov106_021E5A74((void *)ov106_021E6E04);
    ov106_021E59FC(data, (void *)ov106_021E6E74);
    i = U16(PTR(data, 0), 0x4e);
    ov106_021E5AA8(data, 0xf5, ov106_021E6E50 + 12 * i, 1);
    ov106_021E59A4(data, 6, 1, 3);
    return 2;
}

int ov106_021E6104(void *data) {
    ov106_021E5BBC(data);
    ov106_021E594C(data);
    return 6;
}

int ov106_021E6118(void *data) {
    if (IsPaletteFadeFinished() == 1) {
        return U32(data, 0x410);
    }
    return 2;
}

int ov106_021E6130(void *data) {
    u32 t;
    if (ov106_021E5D08(data) == 0 && IsPaletteFadeFinished() == 1) {
        U32(data, 0x414) = 0;
        return 4;
    }
    t = U32(data, 0x414);
    if (t == 0) {
        PlaySE(0x930);
    } else if (t == 0x28) {
        PlaySE(0x92e);
    } else if (t == 0x4e) {
        sub_02005E44(0x48d);
        PlaySE(0x932);
    } else if (t == 0x62) {
        PlaySE(0x92f);
    } else if (t == 0x81) {
        ov106_021E597C(data, 6, 1, 3);
    }
    U32(data, 0x414)
    ++;
    return 3;
}

int ov106_021E61B8(void *data) {
    u32 i;
    ov106_021E5BBC(data);
    ov106_021E59FC(data, (void *)ov106_021E6E9C);
    i = U16(PTR(data, 0), 0x4e);
    ov106_021E5AA8(data, 0xf5, ov106_021E6E2C + 12 * i, 1);
    ov106_021E5954(data, 6, 1, 5);
    return 2;
}

int ov106_021E61F8(void *data) {
    if (ov106_021E5D08(data) == 0 && IsPaletteFadeFinished() == 1) {
        U32(data, 0x414) = 0;
        return 1;
    }
    if ((U32(data, 0x414) & 0x3f) == 0) {
        PlaySE(0x92d);
    }
    if (U32(data, 0x414) == 0xbe) {
        ov106_021E59D0(data, 10, 1, 1);
    }
    U32(data, 0x414)
    ++;
    return 5;
}

int ScriptCinematic_Lugia(void *data) {
    U32(data, 0x40c) = sScriptCinematicSubs_Lugia[U32(data, 0x40c)](data);
    if (U32(data, 0x40c) == 4) {
        return 0;
    }
    ov106_021E5C30(data);
    return 1;
}
