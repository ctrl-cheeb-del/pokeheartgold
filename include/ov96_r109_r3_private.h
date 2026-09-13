#ifndef TO42_R109_R3_PRIVATE_H
#define TO42_R109_R3_PRIVATE_H
#include <nitro/fx/fx_vec.h>

#include "global.h"

#include "bg_window.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "msgdata.h"
#include "text.h"
typedef struct Vec2s32 {
    s32 x, y;
} Vec2s32;
typedef struct PickOut {
    u8 pad0[8];
    s32 x, y;
    u8 pad10[0x32];
    u8 index;
} PickOut;
typedef struct StateObj {
    u8 pad[0x5c];
    u16 state;
} StateObj;
extern const u8 ov96_0221DC80[];
extern const s16 ov96_0221D438[], ov96_0221D43A[];
extern int LCRandom(void);
extern int _s32_div_f(s32, s32);
extern u8 *ov96_021E60D8(void *, void *, void *);
extern void sub_02020F4C(void *, void *, void *, Vec2s32 *, Vec2s32 *);
extern BOOL sub_02020EB0(Vec2s32 *, Vec2s32 *, Vec2s32 *, Vec2s32 *);
extern void GF_AssertFail(void);
extern void PlaySE(int);
extern u32 ov96_022143DC(const void *);
extern u32 ov96_02214394(u32, u8);
extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern PlayerProfile *PokeathlonCourse_GetPlayerProfileFromData(void *, u32);
extern const WindowTemplate ov96_0221D1F8;
extern const WindowTemplate ov96_0221D360[];
void ov96_02213D00(void *, void *, void *, const Vec2s32 *);
BOOL ov96_02213D2C(const VecFx32 *, const VecFx32 *, const VecFx32 *, const VecFx32 *, VecFx32 *);
void ov96_0221359C(void *, s32 *, void *, void *, u8 *);
void ov96_0221362C(u8 *);
void ov96_022136A4(u8 *, u32);
void ov96_02213E60(u8 *, PickOut *);
u8 ov96_02213EC4(u8 *);
s32 ov96_02213F5C(s32);
void ov96_02213FB4(StateObj *);
void ov96_02213FF4(u8 *, u32, BOOL, s32);
void ov96_02214044(u8 *, u32, u32);
void ov96_022140F4(void *);
void ov96_022141B0(void *);
#endif
