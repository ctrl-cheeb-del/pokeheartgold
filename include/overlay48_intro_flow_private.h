#ifndef OVERLAY48_INTRO_FLOW_PRIVATE_H
#define OVERLAY48_INTRO_FLOW_PRIVATE_H

#include "global.h"

#include "camera.h"
#include "gf_3d_vramman.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "location_gmm_dat.h"
#include "msgdata.h"
#include "overlay_manager.h"
#include "render_window.h"
#include "save_wifi_history.h"
#include "screen_fade.h"
#include "sprite.h"
#include "system.h"
#include "yes_no_prompt.h"

#define U8AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define S16AT(p, n) (*(s16 *)((u8 *)(p) + (n)))
#define U32AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define S32AT(p, n) (*(s32 *)((u8 *)(p) + (n)))
#define PTRAT(p, n) (*(void **)((u8 *)(p) + (n)))
#define ADD(p, n)   ((void *)((u8 *)(p) + (n)))

/* 8-byte aggregate at work+4, passed BY VALUE to ov48_022598EC / ov48_02259BC0
   (proved by the ldmia r3!,{r1,r2} register-pair load at the BC0 call site and
   by the r3+[sp] straddle at the 8EC call site). */
typedef struct Ov48Pair {
    u32 a;
    u32 b;
} Ov48Pair;

/* 6- and 4-byte NARC records walked by ov48_02258A80. */
typedef struct Ov48Rec6 {
    u16 kind;
    s16 x;
    s16 y;
} Ov48Rec6;

typedef struct Ov48Rec4 {
    s16 x;
    s16 y;
} Ov48Rec4;

/* 0x30-byte place record; the array starts at +4 behind a u32 count. */
typedef struct Ov48Entry {
    s16 x;
    s16 y;
    MtxFx33 mtx;
    s16 a;
    s16 b;
    s16 c;
} Ov48Entry;

typedef struct Ov48EntryList {
    u32 count;
    Ov48Entry entries[1];
} Ov48EntryList;

extern const MtxFx33 ov48_0225B1EC;

/* Lever #12: at 0xC700 the member spelling still uses register-offset addressing,
   but unlike the ADD() pointer expression it is NOT a CSE candidate, so MWCC
   re-materialises `mov #0xc7 ; lsl #8` per access as the reference does. */
typedef struct Ov48AtC700 {
    u8 _pad[0xC700];
    u32 field;
} Ov48AtC700;
#define AT_C700(p) (&((Ov48AtC700 *)(p))->field)

extern void Heap_Free(void *);
extern void HBlankInterruptDisable(void);
extern void GF_AssertFail(void);

extern u32 ov45_0222A330(void *);
extern void ov45_0222A4A8(void *);
extern void ov45_0222A520(void *, u32);
extern u32 ov45_0222D844(void);

/* Intra-module callees defined elsewhere in the link unit. */
void ov48_02259030(void *);
void ov48_02259050(void *);
void ov48_02259090(void *);
u32 ov48_0225909C(void *);
void ov48_02259130(void *, void *);
void ov48_022593F4(void *, void *);
void ov48_02259464(void *, void *, u32);
void ov48_022594A8(void *);
void ov48_02259824(void *, void *, u32);
void ov48_02259868(void *);
void ov48_022598CC(void *, VecFx32 *);
void ov48_022598DC(void *, VecFx32 *);
void ov48_022598EC(void *, u32, void *, Ov48Pair, u32);
void ov48_02259984(void *);
u16 ov48_02259A68(void *, u16, u16);
void ov48_02259BC0(void *, Ov48Pair, u32);
void ov48_02259C38(void *);
void ov48_02259C4C(void *);
u32 ov48_02259C78(void *, void *);
void ov48_02259D00(void *, void *, void *, u32);
void ov48_02259D94(void *);
u32 ov48_02259E5C(void *, s32);
void ov48_02259E78(void *);
void ov48_02259E90(void *);
void ov48_02259EAC(void *, void *, void *, void *, u32);
void ov48_02259F14(void *);
void ov48_02259F48(void *);
u32 ov48_02259F8C(void *);
void ov48_02259FEC(void *);
void ov48_0225A00C(void *, void *, void *, u32);
void ov48_0225A108(void *, void *);
void ov48_0225A1D0(void *);
void ov48_0225A1EC(void *);
void ov48_0225B068(void *, enum HeapID);
void ov48_0225B0A4(void *);
u16 ov48_02259CFC(void *);

/* Functions defined by this translation unit. */
BOOL ov48_02258800(OverlayManager *, u32 *);
BOOL ov48_02258920(OverlayManager *, u32 *);
BOOL ov48_022589FC(OverlayManager *, u32 *);
void ov48_02258A80(void *, void *, u32);
void ov48_02258B7C(void *, u32, s32, s32, u16, u16, void *);
void ov48_02258BF4(MtxFx33 *, VecFx32 *);
void ov48_02258C6C(MtxFx33 *, VecFx32 *);
void ov48_02258CE4(s32, s32, u32 *, u32 *, u32 *, u32 *);
u32 ov48_02258D54(void *, u32, u32);
void ov48_02258F0C(void *);
u32 ov48_02258F64(void *);

#endif
