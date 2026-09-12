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
void ov49_0225E2B4(void *p);
void ov49_0225E318(void *p);

void ov49_0225DCBC(void *p) {
    int i;
    int j;
    void *a;
    void *b;
    void *q;
    for (i = 0, a = p, b = p; i < 0x12; a = (u8 *)a + 0xC, b = (u8 *)b + 0x10, i++) {
        for (j = 0, q = a; j < 3; j++, q = (u8 *)q + 4) {
            if (U32_AT(q, 0x120)) {
                Heap_Free((void *)U32_AT(q, 0x120));
                U32_AT(q, 0x120) = 0;
            }
        }
        ov49_0225D574(b);
    }
}

void ov49_0225DD0C(void *a, void *b) {
    if (U16_AT(b, 0)) {
        if (ov49_022588A0((u8 *)a + U16_AT(b, 2) * 0x10, (u8 *)b + 4)) {
            if (U8_AT(b, 0xE0) == 1) {
                NNS_G3dMdlSetMdlAlphaAll((void *)U32_AT((u8 *)a + U16_AT(b, 2) * 0x10, 8), U8_AT(b, 0xE1));
            }
            sub_020181EC((u8 *)b + 4);
            if (U8_AT(b, 0xE0) == 1) {
                NNS_G3dMdlSetMdlAlphaAll((void *)U32_AT((u8 *)a + U16_AT(b, 2) * 0x10, 8), U8_AT(b, 0xE2));
            }
        }
    }
}
