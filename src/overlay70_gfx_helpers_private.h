#ifndef R19_OVERLAY70_PRIVATE_H
#define R19_OVERLAY70_PRIVATE_H
#include "global.h"

#define R19_U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define R19_U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define R19_S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define R19_U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define R19_PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov70Gfx19 {
    u8 pad[0x11e0];
    void *charAlloc;
    void *charData;
    void *plttAlloc;
    void *plttData;
} Ov70Gfx19;

u32 Sprite_GetDrawFlag(void *);
u32 Sprite_GetAnimationNumber(void *);
void Sprite_SetAnimCtrlSeq(void *, u32);
u32 ov70_0224122C(u32);
void *GfGfxLoader_GetPlttData(u32, s32, void *, u32);
void *GfGfxLoader_GetCharData(u32, s32, BOOL, void *, u32);
int SpriteToUnionRoomAvatarIdx(int, int);
void Heap_Free(void *);
void ov70_022410F0(void *, u32, u32);
void ov70_02238F9C(void *, s32, s32);
void *ov70_0223E49C(void *, void *, u32, u32);
void *sub_02088288(void *);
void *Save_SpecialRibbons_Get(void *);
void *sub_0208828C(void *);
void sub_02089D40(void *, const void *);
void sub_0208AD34(void *, void *);
void *OverlayManager_New(const void *, void *, u32);
BOOL OverlayManager_Run(void *);
void OverlayManager_Delete(void *);
void ov70_02238E50(void *, u32, u32);
extern const u16 ov70_02245CFC[];
extern const u16 ov70_02245D0A[];
typedef struct Ov70Pair19 { u16 value; u16 pad; } Ov70Pair19;
extern const Ov70Pair19 ov70_02245D0C[];
extern const u8 ov70_02245D48[];
extern const u8 gOverlayTemplate_PokemonSummary[];

void ov70_02241234(void *);
void ov70_0224127C(void *);
void ov70_022412C8(void *, void *, u32, int, int);
void ov70_02241308(void *);
void ov70_02241330(void *, u32, u32);
void ov70_02241358(void *);
void ov70_02241380(void *);
int ov70_022413AC(void *);
int ov70_02241468(void *);

#endif
