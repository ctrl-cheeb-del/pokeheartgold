#ifndef SOL_R27_PRIVATE_H
#define SOL_R27_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "msgdata.h"
#include "player_data.h"
#include "text.h"
typedef struct Sprite Sprite;
typedef struct R27Vec {
    s32 x, y, z;
} R27Vec;
typedef struct R27Work {
    enum HeapID heap;
    void *course;
    Sprite *sprites[2];
    BgConfig *bg;
    Window windowA;
    Window windowB;
    MsgData *msgData;
    MessageFormat *format;
    NNSG2dScreenData *screenData;
    void *screenAlloc;
    u8 pad044[8];
    void *label;
} R27Work;
u32 ov96_021E5F24(void *);
PlayerProfile *PokeathlonCourse_GetPlayerProfileFromData(void *, u32);
void ov96_0221497C(R27Work *, u32);
void ov96_022146C0(R27Work *);
void ov96_022147FC(R27Work *);
void ov96_02214854(R27Work *);
void ov96_022148A4(R27Work *);

void *ov96_021EB3E4(void *, s32, s32, s32, u8);
void ov96_021EB52C(void *, BOOL, BOOL);
void ov96_021EB588(void *, const R27Vec *);
void ov96_021EB564(void *, s32);
void *ov96_021EB5E8(void *);
Sprite *ov96_021EA2C4(void *, void *, s32, u32);
extern const u8 ov96_0221D648[2];
extern const u8 ov96_0221D64C[2];
extern const R27Vec ov96_0221D660;
extern const R27Vec ov96_0221D66C;
void Sprite_SetDrawFlag(Sprite *, BOOL);
void Sprite_SetMatrix(Sprite *, const R27Vec *);
void Sprite_SetAnimCtrlSeq(Sprite *, s32);
void ov96_02214718(void *, R27Work *, void *);
extern const WindowTemplate ov96_0221D650;
extern const WindowTemplate ov96_0221D658;
#endif
