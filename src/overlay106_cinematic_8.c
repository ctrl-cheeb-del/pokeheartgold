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

void ov106_021E664C(void *data) {
    ov106_021E6634(data, 0);
    SpriteSystem_FreeResourcesAndManager(PTR(data, 8), PTR(data, 0xc));
    SpriteSystem_Free(PTR(data, 8));
}

void ov106_021E6668(void *data) {
    if (PTR(data, 0x10)) {
        ManagedSprite_TickFrame(PTR(data, 0x10));
    }
}

void ov106_021E6678(void *src, u32 dst, u32 size) {
    DC_FlushRange(src, size);
    GX_LoadOBJ(src, dst, size);
}

void ov106_021E6694(void *src, u32 dst, u32 size) {
    DC_FlushRange(src, size);
    GX_LoadOBJPltt(src, dst, size);
}
