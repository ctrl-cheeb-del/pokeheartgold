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
void ov49_0225DA70(void *p, void *a);
void *ov49_0225DBF8(void *p);
void ov49_0225DCBC(void *p);
void ov49_0225DD0C(void *a, void *b);
void ov49_0225E2B4(void *p);
void ov49_0225E318(void *p);

void ov49_0225D804(void *p) {
    int i;
    void *q;
    if (U32_AT(p, 0)) {
        for (i = 0, q = (u8 *)p + 4; i < 2; i++, q = (u8 *)q + 0x78) {
            sub_020181EC(q);
        }
    }
}

void *ov49_0225D820(void *p) {
    int i;
    for (i = 0; i < U8_AT(p, 0x124); i++) {
        if (((Ov49B4 *)U32_AT(p, 0x11C))[i].b[0] == 0) {
            return (u8 *)U32_AT(p, 0x11C) + i * 0xB4;
        }
    }
    GF_AssertFail();
    return NULL;
}
