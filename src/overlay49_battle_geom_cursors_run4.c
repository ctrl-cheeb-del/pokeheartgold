#include "overlay49_battle_geom_cursors_private.h"

#pragma require_prototypes off

typedef struct Ov49C {
    u8 b[0xC];
} Ov49C;
typedef struct Ov49B4 {
    u8 b[0xB4];
} Ov49B4;
typedef struct Ov49E4 {
    u16 h;
    u8 b[0xE2];
} Ov49E4;

extern void GF_AssertFail(void);

extern void ov49_0225D528(void *p, void *a, u32 b, void *c);
extern void ov45_0222D740(void *p);
extern void ov49_0225D574(void *p);
extern void ov49_0225D57C(void *p, void *a, fx32 b);
extern u32 ov49_0225D5A0(void *p, void *a, fx32 b);
extern u32 ov49_022588A0(void *p, void *a);
extern void sub_020180BC(void *p, void *a, void *b, u32 c, void *d, void *e);
extern void sub_020180F8(void *p, void *a);
extern void sub_020181D4(void *p, void *a);
extern void sub_020181E0(void *p, void *a);
extern void sub_020181EC(void *p);
extern void sub_02018198(void *p, u32 a);
extern void ov49_0225EB08(void *p, void *a);
extern void ov49_0225ECF0(void *p, void *a);
extern void ov49_0225ED98(void *p, void *a);
extern void ov49_0225CCF0(void *p);
extern void ov49_0225CF94(void *p);
extern void ov49_0225D160(void *p, void *a);
extern void ov49_0225CE88(void *p);
extern void ov49_0225CCC0(void *p);
extern void sub_020181B0(void *p, void *a);
extern void sub_020182A0(void *p, u32 a);
extern void NNS_G3dMdlSetMdlAlphaAll(void *p, u32 a);
extern void GfGfxLoader_LoadFromOpenNarc(void *p, u32 a, u32 b, void *c, u32 d);

void ov49_0225D6AC(void *p, void *a);
void ov49_0225D6F0(void *p, void *a);
void ov49_0225D76C(void *p, void *a);
void ov49_0225D7B8(void *p, void *a);
void ov49_0225D804(void *p);
void *ov49_0225D820(void *p);
void ov49_0225DA70(void *p, void *a);
void *ov49_0225DBF8(void *p);
void ov49_0225DCBC(void *p);
void ov49_0225DD0C(void *a, void *b);

void ov49_0225E2B4(void *p) {
    int i;
    for (i = 0; i < U8_AT(p, 0x613); i++) {
        ov49_0225CF94((void *)U32_AT((u32 *)p + i, 0x208));
    }
    for (i = 0; i < U8_AT(p, 0x612); i++) {
        ov49_0225D160((void *)U32_AT(p, 4), (void *)U32_AT((u32 *)p + i, 8));
    }
    ov49_0225CE88((void *)U32_AT(p, 4));
    ov49_0225CCC0((void *)U32_AT(p, 4));
    Heap_Free(p);
}

void ov49_0225E318(void *p) {
    int i;
    for (i = 0; i < U8_AT(p, 0x608); i++) {
        ov49_0225EB08(&((Ov49C *)((u8 *)p + 0x248))[i], (void *)U32_AT(p, 4));
    }
    for (i = 0; i < U8_AT(p, 0x609); i++) {
        ov49_0225ECF0(&((Ov49C *)((u8 *)p + 0x368))[i], (void *)U32_AT(p, 4));
    }
    for (i = 0; i < U8_AT(p, 0x60B); i++) {
        ov49_0225ED98(&((Ov49C *)((u8 *)p + 0x4E8))[i], (void *)U32_AT(p, 4));
    }
    ov49_0225CCF0((void *)U32_AT(p, 4));
}
