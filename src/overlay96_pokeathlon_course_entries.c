/*
 * overlay96_pokeathlon_course_entries.c
 *
 * Trailing 15 functions of asm/overlay_96_residual_98.s
 * (0x0220E22C .. 0x0220E850, 1572 bytes reference-padded).
 *
 * NOTE FOR INTEGRATION: ov96_0220D630 and ov96_0220D6B0 are declared extern here
 * but are DEFINED in the remaining residual assembly. Splitting this object off
 * turns two intra-object calls (in ov96_0220E834 and ov96_0220E818) into external
 * references. That is expected; the .text bytes are byte-identical either way.
 */
#include <nitro/mi/memory.h>

#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef union Bits {
    u32 raw;
    struct {
        u32 lo : 2;
        u32 val : 16;
        u32 hi : 14;
    } f;
    struct {
        u32 rest : 30;
        u32 top : 2;
    } g;
    struct {
        u32 v7 : 7;
        u32 pad : 25;
    } h;
    struct {
        u32 a : 24;
        u32 b : 6;
        u32 c : 2;
    } k;
} Bits;
#define BITS(p, o) (*(Bits *)((u8 *)(p) + (o)))

extern u8 gSystem[];
extern void GF_AssertFail(void);
extern s32 _s32_div_f(s32, s32);

extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern void *PokeathlonCourse_GetDataCopyArea(void *);
extern u32 PokeathlonCourse_GetField1ED(void *);
extern void PokeathlonCourse_IncrementField1ED(void *);
extern void *PokeathlonCourse_AllocPtr4FromHeap(void *, u32);
extern void PokeathlonCourse_SetField5E0_AtIndex(void *, u8, u16);
extern u16 PokeathlonCourse_GetField5F0_AtIndex(void *, u8);
extern void PokeathlonCourse_SetVBlankIntrCB(void *);
extern void PokeathlonCourse_SetField1F4(void *, u32);
extern void PokeathlonCourse_FreePtr4HeapAlloc(void *);
extern void *PokeathlonCourse_GetGraphicsSystem(void *);
extern void PokeathlonCourse_SetStateField07(void *, u32);

extern u32 ov96_021E637C(void *);
extern void ov96_021E8318(void *, u8);
extern void *ov96_021E8A20(void *);
extern u32 ov96_021E5F24(void *);
extern u32 ov96_021E667C(void *);
extern void ov96_021E6670(void *, u32);
extern void **ov96_021E61D8(void *, u32, void *, void *);
extern void ov96_021E64B8(void *);
extern void ov96_021E6550(void *);
extern void ov96_021E9510(void *);
extern void ov96_021E95F8(void *, void *, u32, u32, u8, u8, u32);
extern void ov96_021E93B4(void *, u32);
extern void ov96_021E952C(void *);
extern void ov96_021E9570(void *, u32);
extern u32 ov96_021EAA00(void *);
extern void *ov96_021EAF8C(void *);

extern u32 ov96_0220D408(void *);
extern void ov96_0220D420(void *, void *, void *);
extern u32 ov96_0220D630(void *);
extern void ov96_0220D6B0(void *, u32);

extern void ov96_0220E868(void);
extern void ov96_0220E9A0(void *, u8);
extern void ov96_0220EA08(void *);
extern void ov96_0220EAA4(void *);
extern void ov96_0220EB3C(void *);
extern void ov96_0220ED9C(void *);
extern void ov96_0220EE4C(void *);
extern void ov96_0220EE8C(void *);
extern void ov96_0220EFD0(void *, void *, u32);
extern void ov96_0220F03C(void *);
extern u32 ov96_0220F1CC(void *);
extern void ov96_0220F3FC(void *);
extern void ov96_0220F4A0(void *);
extern void ov96_0220FA18(void *, void *);
extern void ov96_0220FF64(void *, void *);
extern void ov96_0221007C(void *, void *, void *, void *);
extern void ov96_022101D0(void *);
extern void ov96_0221022C(void *);
extern void *ov96_02210240(void *, void *, void *, void *, void *, u32, u32, void *);
extern void ov96_022102D4(void *);
extern void ov96_02210324(void *, u8, u16);
extern u32 ov96_022104C4(void *);
extern void *ov96_022107F0(void *, u32);
extern void ov96_02210850(void *);
extern void ov96_0221A56C(void *, u32);

extern void *Heap_Create(u32, u32, u32);
extern void Heap_Destroy(u32);
extern void Main_SetVBlankIntrCB(void *, void *);
extern void Main_SetHBlankIntrCB(void *, void *);
extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void GfGfx_SwapDisplay(void);
extern void GfGfx_EngineATogglePlanes(u32, u32);
extern void GfGfx_EngineBTogglePlanes(u32, u32);
extern void *BgConfig_Alloc(u32);
extern void *SpriteManager_GetSpriteList(void *);
extern void Sprite_SetDrawPriority(void *, u32);
extern void SpriteSystem_DrawSprites(void *);
extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern u32 IsPaletteFadeFinished(void);
extern s32 GF_SinDeg(u16);
extern void sub_0203A994(u32);
extern void sub_0203A914(void);

u32 ov96_0220E22C(void *course, u8 *state);
void ov96_0220E2A8(void *course);
u32 ov96_0220E2DC(void *course, u8 *state);
u32 ov96_0220E394(void *course, u8 *state);
u32 ov96_0220E3F0(void *course);
u32 ov96_0220E5F4(void *course);
u32 ov96_0220E60C(void *course);
u32 ov96_0220E670(void *course);
s16 ov96_0220E6DC(int a0, int a1);
u32 ov96_0220E70C(void *w, u32 i, u32 j);
void *ov96_0220E74C(void *w, u32 i);
void ov96_0220E770(void *w, u32 i, u32 j, s16 *out, void **out2);
u8 ov96_0220E7BC(void *course, u32 idx);
void ov96_0220E818(void *w, u32 a1, u32 i, u32 j);
u32 ov96_0220E834(void *w, u32 i, u32 j);

u32 ov96_0220E22C(void *course, u8 *state) {
    void *w = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_0220EFD0((u8 *)w + 0x6a4, PTR(w, 8), U32(w, 0));
    switch (*state) {
    case 0:
        BeginNormalPaletteFade(0, 1, 1, 0x7fff, 6, 1, U32(w, 0));
        (*state)++;
    case 1:
        if (IsPaletteFadeFinished()) {
            (*state)++;
        }
        break;
    case 2:
        if (ov96_021E637C(course)) {
            PokeathlonCourse_SetStateField07(course, 1);
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

void ov96_0220E2A8(void *course) {
    u8 v;
    ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(course) + 0xf0);
    v = (u8)ov96_022104C4(PTR(PokeathlonCourse_GetHeapAllocPtr4(course), 0xc4));
    ov96_021E8318(course, v);
    ov96_0220E9A0(course, v);
}

u32 ov96_0220E2DC(void *course, u8 *state) {
    void *w = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_0220EFD0((u8 *)w + 0x6a4, PTR(w, 8), U32(w, 0));
    switch (*state) {
    case 0:
        ov96_0220F03C(course);
        if (ov96_0220F1CC(course)) {
            (*state)++;
        }
        break;
    case 1: {
        void *p;
        ov96_0220F03C(course);
        p = ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(course) + 0xf0);
        ov96_02210324(PTR(w, 0xc4), (u8)BITS(p, 0x1c).g.top, (u16)BITS(p, 0x20).h.v7);
        if (ov96_021E667C(course)) {
            if (ov96_0220D408((u8 *)w + 0x6a8)) {
                BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, U32(w, 0));
                PokeathlonCourse_SetStateField07(course, 2);
            }
        }
        break;
    }
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

u32 ov96_0220E394(void *course, u8 *state) {
    void *w = PokeathlonCourse_GetHeapAllocPtr4(course);
    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            u32 done = ov96_021E5F24(course);
            w = PokeathlonCourse_GetHeapAllocPtr4(course);
            if (done == 0) {
                int i;
                Bits *p;
                for (i = 0, p = (Bits *)((u8 *)w + 0x23c); i < 4; i++) {
                    PokeathlonCourse_SetField5E0_AtIndex(course, (u8)i, (u16)p->f.val);
                    p = (Bits *)((u8 *)p + 0xe4);
                }
            }
            return 1;
        }
    } else {
        GF_AssertFail();
    }
    return 0;
}

u32 ov96_0220E3F0(void *course) {
    void *w = PokeathlonCourse_GetHeapAllocPtr4(course);
    switch (PokeathlonCourse_GetField1ED(course)) {
    case 0:
        Heap_Create(0x5c, 0x8e, 0x60000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        *(u32 *)0x04000000 &= 0xffffe0ff;
        *(u32 *)0x04001000 &= 0xffffe0ff;
        ov96_0220E868();
        gSystem[0x69] = 1;
        GfGfx_SwapDisplay();
        w = PokeathlonCourse_AllocPtr4FromHeap(course, 0x6bc);
        MI_CpuFill8(w, 0, 0x6bc);
        U32(w, 0) = 0x8e;
        U32(w, 4) = (u32)course;
        U32(w, 0x50c) = 0x708;
        PokeathlonCourse_IncrementField1ED(course);
        break;
    case 1:
        PTR(w, 8) = BgConfig_Alloc(U32(w, 0));
        ov96_021E6670(course, 4);
        ov96_0220ED9C(w);
        ov96_0220EE8C(w);
        ov96_0221022C(w);
        sub_0203A994(2);
        ov96_0220EA08(w);
        ov96_0220F3FC(w);
        PokeathlonCourse_IncrementField1ED(course);
        break;
    case 2:
        if (ov96_021EAA00(PTR(w, 0x20))) {
            ov96_0220EB3C(w);
            Sprite_SetDrawPriority(*ov96_021E61D8(course, 0, PTR(w, 0x1c), SpriteManager_GetSpriteList(PTR(w, 0x10))), 0);
            PokeathlonCourse_IncrementField1ED(course);
        }
        break;
    case 3: {
        u8 flag = (u8)ov96_021E5F24(course);
        PTR(w, 0xc4) = ov96_02210240(PTR(w, 0xc), PTR(w, 0x10), PTR(w, 8), PTR(w, 0x18), PTR(w, 0x14), flag, U32(w, 0), course);
        ov96_0221007C((u8 *)w + 0x510, PTR(w, 0xc), PTR(w, 0x10), PTR(w, 0xc4));
        PTR(w, 0xc8) = ov96_022107F0(course, U32(w, 0));
        ov96_021E64B8(course);
        ov96_0220D420((u8 *)w + 0x6a8, PTR(w, 8), PTR(w, 0xc));
        PokeathlonCourse_SetVBlankIntrCB(PTR(w, 8));
        PokeathlonCourse_SetField1F4(course, 1);
        ov96_0220F4A0(w);
        if (ov96_021E5F24(course) == 0) {
            void *p = ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(course) + 0x28);
            BITS(p, 0x1c).k.b = (u32)_s32_div_f((s32)(U32(w, 0x50c) + 0x1e), 0x1e);
            ov96_0220FA18((u8 *)w + 0xcc, course);
        }
        ov96_0220FF64((u8 *)w + 0x4ec, (u8 *)w + 0x15c);
        GfGfx_EngineATogglePlanes(0x10, 1);
        GfGfx_EngineBTogglePlanes(0x10, 1);
        return 1;
    }
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

u32 ov96_0220E5F4(void *course) {
    void *w = PokeathlonCourse_GetHeapAllocPtr4(course);
    if (w == NULL) {
        GF_AssertFail();
    }
    SpriteSystem_DrawSprites(PTR(w, 0x10));
    return 1;
}

u32 ov96_0220E60C(void *course) {
    void *gfx = PokeathlonCourse_GetGraphicsSystem(course);
    int i;
    ov96_021E9510(gfx);
    for (i = 0; i < 4; i++) {
        ov96_021E95F8(course, gfx, i, PokeathlonCourse_GetField5F0_AtIndex(course, (u8)i), 0, 3, 0x127);
    }
    ov96_021E93B4(gfx, 1);
    ov96_0221A56C(gfx, 4);
    ov96_021E952C(gfx);
    ov96_021E9570(gfx, 4);
    return 1;
}

u32 ov96_0220E670(void *course) {
    void *w = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_021E6550(course);
    ov96_02210850(PTR(w, 0xc8));
    ov96_022102D4(PTR(w, 0xc4));
    ov96_022101D0((u8 *)w + 0x510);
    ov96_0220EAA4(w);
    ov96_0220EE4C(w);
    sub_0203A914();
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourse_FreePtr4HeapAlloc(course);
    gSystem[0x69] = 0;
    GfGfx_SwapDisplay();
    Heap_Destroy(0x8e);
    return 1;
}

s16 ov96_0220E6DC(int a0, int a1) {
    s16 v = (s16)(_s32_div_f(0x26 * (a0 * (a1 - 7)), 1000) + 0x80);
    return (s16)(v + ((GF_SinDeg((u16)(a0 << 1)) << 6) >> 0x10));
}

u32 ov96_0220E70C(void *w, u32 i, u32 j) {
    u32 v;
    u32 ret;
    u8 *p;
    if (w == NULL) {
        GF_AssertFail();
    }
    if (i >= 4) {
        GF_AssertFail();
    }
    if (j >= 3) {
        GF_AssertFail();
    }
    ret = 1;
    p = (u8 *)w + i * 0xe4;
    p += j * 0x48;
    v = U32(p, 0x170);
    if (v != 2 && v != 1) {
        ret = 0;
    }
    return ret;
}

void *ov96_0220E74C(void *w, u32 i) {
    if (w == NULL) {
        GF_AssertFail();
    }
    if (i >= 2) {
        GF_AssertFail();
    }
    return (u8 *)w + 0x4f0 + i * 0xc;
}

void ov96_0220E770(void *w, u32 i, u32 j, s16 *out, void **out2) {
    u8 *p;
    if (w == NULL) {
        GF_AssertFail();
    }
    if (i >= 4) {
        GF_AssertFail();
    }
    if (j >= 3) {
        GF_AssertFail();
    }
    p = (u8 *)w + 0x164 + i * 0xe4 + j * 0x48;
    out[0] = (s16)(S32(p, 0x1c) >> 0xc);
    out[1] = (s16)(S32(p, 0x20) >> 0xc);
    *out2 = ov96_021EAF8C(PTR(p, 4));
}

u8 ov96_0220E7BC(void *course, u32 idx) {
    u8 count = 0;
    void *w;
    int i;
    u16 mine;
    Bits *p;
    if (course == NULL) {
        GF_AssertFail();
    }
    w = PokeathlonCourse_GetHeapAllocPtr4(course);
    if (w == NULL) {
        GF_AssertFail();
    }
    i = 0;
    mine = (u16)BITS((u8 *)w + idx * 0xe4, 0x23c).f.val;
    p = (Bits *)((u8 *)w + 0x23c);
    for (; i < 4; i++) {
        u16 other = (u16)p->f.val;
        if (i != (int)idx && mine < other) {
            count++;
        }
        p = (Bits *)((u8 *)p + 0xe4);
    }
    return count;
}

void ov96_0220E818(void *w, u32 a1, u32 i, u32 j) {
    ov96_0220D6B0((u8 *)w + 0x164 + i * 0xe4 + j * 0x48, a1);
}

u32 ov96_0220E834(void *w, u32 i, u32 j) {
    return ov96_0220D630((u8 *)w + 0x164 + i * 0xe4 + j * 0x48);
}
