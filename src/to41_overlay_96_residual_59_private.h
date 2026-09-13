#ifndef OV96_RESIDUAL_59_PRIVATE_H
#define OV96_RESIDUAL_59_PRIVATE_H

#include "global.h"

#include "gf_gfx_planes.h"

typedef struct Ov96R59Entry {
    u8 pad00[8];
    u32 unk08;
    u8 pad0C[8];
    u32 unk14;
    u8 pad18[4];
} Ov96R59Entry;

typedef struct Ov96R59Triple {
    u32 a[5];
    u32 b[5];
    u32 c[5];
} Ov96R59Triple;

typedef struct Ov96R59Sel {
    u8 pad00[2];
    u8 unk02;
    u8 unk03;
    u8 unk04;
} Ov96R59Sel;

typedef struct Ov96R59Dst {
    u8 pad00[0x2c];
    u32 unk2C;
    u32 unk30;
    u32 unk34;
} Ov96R59Dst;

typedef struct Ov96R59Ball {
    u8 pad00[8];
    fx32 unk08;
    u8 pad0C[0xc];
    fx32 unk18;
    fx32 unk1C;
    u32 unk20;
    u8 pad24[4];
} Ov96R59Ball;

typedef struct Ov96R59Cnt {
    u8 pad00[0x20];
    u16 unk20;
    u8 pad22[2];
    u16 unk24;
} Ov96R59Cnt;

typedef struct Ov96R59Work {
    u8 pad000[0x84];
    void *unk084;
    void *unk088;
    u8 pad08C[0xb0];
    u32 unk13C;
    u8 pad140[0x60];
    u32 unk1A0[0x383];
} Ov96R59Work;

typedef struct Ov96R59Slots {
    u8 pad000[0x3a0];
    fx32 unk3A0[1][0x80];
} Ov96R59Slots;

extern void Thunk_G3X_Reset(void);
extern void Camera_PushLookAtToNNSGlb(void);
extern void RequestSwap3DBuffers(u32, u32);
extern void MI_CpuFill8(void *, u8, u32);

extern void Sprite_SetAnimCtrlSeq(void *, int);
extern void *PokeathlonCourse_GetHeapAllocPtr4(void *course);
extern const GraphicsBanks ov96_0221C1F4;

extern void ov96_021F61C8(Ov96R59Work *);
extern u32 ov96_021E5F24(void *);
extern Ov96R59Sel *ov96_021E60D8(void *, u8, void *);
extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern void ov96_021EB2BC(void *, s32, s32, s32, s32);
extern void ov96_021EB2F4(void *, s32, s32, s32, s32, s32);
extern void ov96_021EB334(void *, s32, s32, s32);
extern void ov96_021EB36C(void *, s32, s32, s32);
extern void ov96_021E6454(void *, int);
extern void ov96_021F6B50(int, fx32, fx32 *);
extern void ov96_021F5D3C(void *);
extern void ov96_021F5EC4(void *);
extern void *PokeathlonCourse_GetGraphicsSystem(void *);
extern u16 PokeathlonCourse_GetField5F0_AtIndex(void *, u8);
extern void ov96_021E9510(void *);
extern void ov96_021E95F8(void *, void *, u32, u32, u8, u8, u32);
extern void ov96_021E93B4(void *, u32);
extern void ov96_0221A56C(void *, u32);
extern void ov96_021E952C(void *);
extern void ov96_021E9570(void *, u32);
extern void AddWindow(void *, void *, const void *);
extern void BG_FillCharDataRange(void *, u32, u32, u32, u32);
extern void LoadFontPal0(u32, u32, u32);
typedef struct Ov96R59Window {
    u8 raw[0x10];
} Ov96R59Window;

typedef struct Ov96R59WindowTemplate {
    u8 raw[8];
} Ov96R59WindowTemplate;

typedef struct Ov96R59UiWork {
    void *bgConfig;
    Ov96R59Window windows[5];
    u32 heapId;
} Ov96R59UiWork;

extern const Ov96R59WindowTemplate ov96_0221C1CC[];

void ov96_021F637C(Ov96R59Work *w);
void ov96_021F5630(void);
void *ov96_021F74A4(enum HeapID heapId);
BOOL ov96_021F6060(const VecFx32 *a, fx32 ra, const VecFx32 *b, fx32 rb);
u8 ov96_021F65D8(Ov96R59Cnt *c);
void ov96_021F6B28(Ov96R59Ball *a, Ov96R59Ball *b);
void ov96_021F7130(Ov96R59Ball *a);
void ov96_021F6E68(Ov96R59Work *w, int total);
void ov96_021F6E38(Ov96R59Work *w);
void ov96_021F5F34(int x, int y, const VecFx32 *a, VecFx32 *b);
void ov96_021F6BB0(Ov96R59Work *w);
void ov96_021F6BE4(Ov96R59Slots *w, int slot, int idx, fx32 val);
void ov96_021F715C(void *a0, Ov96R59Triple *t, void *a2, Ov96R59Dst *d);
void ov96_021F6F3C(Ov96R59Work *w, int v);
void ov96_021F5B60(void *course);
void ov96_021F6C18(void *a);
u32 ov96_021F54D4(void *course);
void ov96_021F7050(void *work);

#endif
