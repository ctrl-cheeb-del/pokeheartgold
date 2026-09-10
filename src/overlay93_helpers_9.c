#include "overlay93_helpers_internal.h"

/* ------------------------------------------------------------------ */
/* .rodata owned by this object but PRESERVED AS ASSEMBLY (extern only) */
/* ------------------------------------------------------------------ */
extern u32 (*const ov93_02262C94[])(void *, void *, void *);
extern void (*const ov93_02263114[])(void *);
extern const struct SpriteTemplate ov93_02262F6C;
extern const struct SpriteTemplate ov93_02262FA0;
extern const struct SpriteTemplate ov93_02262F38;
extern const u32 ov93_022630E4[];

/* ------------------------------------------------------------------ */
/* Symbols from sibling objects (overlay_93_thumb_1.o / overlay_93_arm.o)
   and from the rest of the game. Prototype only, never defined here.   */
/* ------------------------------------------------------------------ */
extern void ov93_0225E144(void *, void *);
extern void ov93_0225E230(void *, const void *);
extern void ov93_0225E48C(void *, u32, u32);

extern void *SpriteSystem_NewSprite(void *, void *, const struct SpriteTemplate *);
extern void Sprite_DeleteAndFreeResources(void *);
extern void Sprite_TickFrame(void *);
extern void ManagedSprite_SetDrawFlag(void *, u32);
extern void ManagedSprite_SetAnim(void *, u32);
extern void ManagedSprite_SetOamMode(void *, u32);
extern void ManagedSprite_TickNFrames(void *, u32);
extern void FontOAM_Delete(void *);
extern void sub_02021B5C(void *);
extern void *OverlayManager_CreateAndGetData(void *, u32, u32);
extern void *OverlayManager_GetData(void *);
extern void *OverlayManager_GetArgs(void *);
extern void OverlayManager_FreeData(void *);
extern void BgClearTilemapBufferAndCommit(void *, u32);
extern u32 sub_02037030(u32, void *, u32);
extern void sub_0203410C(const u32 *, u32, void *);
extern u32 sub_0203769C(void);

/* ------------------------------------------------------------------ */
/* Forward declarations for everything defined in this file.           */
/* ------------------------------------------------------------------ */
void ov93_0225FBF0(void *bg, u32 a, u32 b, void *out);
void ov93_0225FC8C(void *bg, void *work);
u32 ov93_0225FCA4(void *a, void *b, u32 c);
u32 ov93_0225FDF4(s32 n);
u32 ov93_0225FE5C(void *p);
void ov93_0225FE80(void *sys, void *bg, void *p);
s32 ov93_0225FEAC(void *sys);
void ov93_0225FEC4(void *sys, void *p);
void ov93_022602E4(void *sys);
void ov93_02260908(void *sys);
void ov93_02260A14(void *sys);
u32 ov93_02260A30(void *sys);
void *ov93_02260984(void *sys, u32 a, u32 b);
void ov93_022609E0(void *sys);
u32 ov93_02260A58(void *sys, void *slot, u32 c, u32 d);
void ov93_02260A8C(void *e);
void *ov93_02260F84(void *sys);
void ov93_02260AD8(void *sys, void *e);
u32 ov93_02260B70(s32 n);
void ov93_02260B84(void *sys);
void ov93_02260F14(void *a, u16 b, u32 c, void *out);
void ov93_0226114C(void *sys, void *arr);
void ov93_022612E0(void *sys, void *arr);
u32 ov93_022614F4(void *sys, void **out);
void ov93_02261528(void *e, u8 state);
u32 ov93_02261538(void *a, void *b, void *e);
u32 ov93_0226154C(void *a, void *b, void *e);
void ov93_02261C3C(void *sys, void *arr);
void ov93_02261D1C(void *sys, void *arr);
void ov93_02261D3C(void *sys, void *e);
void ov93_02261FB0(void *p);
void *ov93_02262230(void *sys);
void ov93_02262338(void *sys, void *sprite);
void *ov93_02262344(void *sys);
void ov93_02262368(void *sys, void *sprite);
void ov93_02262444(void *sys, void **out);
void ov93_02262484(void *sys, void *arr);
u32 ov93_02262598(void *man);
u32 ov93_02262108(void *sys);
void ov93_02262310(void *sys);
u32 ov93_022626E8(void *man);
void ov93_022626FC(void *a);
u32 ov93_02262710(void);
u32 ov93_02262714(void);
void ov93_02262718(void *a, void *b, void *c, void *d);
u32 ov93_02262724(void *a, void *b);
void ov93_0226273C(void *a, void *b, void *c, void *d);
u32 ov93_02262748(void);
u32 ov93_022627A4(void);
u32 ov93_022627C0(void *a, void *b);
void ov93_022627E8(void *sys, const void *body);
void ov93_02262814(void *sys, void *e);
void ov93_02262830(void *sys, u16 h, u8 c);
void ov93_02262860(void *sys, void *e);
void ov93_02262884(void *sys, u16 b, u8 c, u8 d);
void ov93_022628B8(void *sys, void *e);
void ov93_022628F4(void *sys, u8 v);
void ov93_02262920(void *sys, void *e);
void ov93_02262934(void *sys, u8 v);
void ov93_02262960(void *sys, void *e);
void ov93_0226297C(void *sys, u8 a, u8 b);
void ov93_022629A8(void *sys, void *e);
void ov93_022629B8(void *sys, u8 v);
void ov93_022629E4(void *sys, void *e);

/* ------------------------------------------------------------------ */
/* Local types                                                         */
/* ------------------------------------------------------------------ */
typedef struct Ov93EvtBody {
    u32 a, b, c, d;
} Ov93EvtBody;

typedef struct Ov93Evt {
    u32 kind;
    union {
        Ov93EvtBody blob;
        struct {
            u8 b4, b5, b6, b7;
        } b;
        struct {
            u16 h4;
            u8 b6, b7, b8;
        } h;
    } u;
} Ov93Evt;

/* Ticker/counter block used by 0225FE5C / 0225FEAC. */
typedef struct Ov93Counter {
    u32 unk0;
    u32 unk4;
    s32 cur;   /* 0x08 */
    s32 total; /* 0x0c */
    s32 rem;   /* 0x10 */
    s32 step;  /* 0x14 */
} Ov93Counter;

/* Sprite slot used by the 0x380C array (0xc bytes each). */
typedef struct Ov93Slot {
    void *sprite; /* 0x0 */
    u8 unk4;
    u8 anim; /* 0x5 */
    u8 free; /* 0x6 */
    u8 unk7;
    u32 unk8;
} Ov93Slot;

/* ------------------------------------------------------------------ */

void ov93_0226114C(void *sys, void *arr) {
    void **p = (void **)arr;
    s32 i;
    (void)sys;
    for (i = 0; i < 4; i++) {
        Sprite_DeleteAndFreeResources(*p);
        p++;
    }
}
