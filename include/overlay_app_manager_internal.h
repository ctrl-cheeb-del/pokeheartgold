#ifndef POKEHEARTGOLD_OVERLAY_APP_MANAGER_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY_APP_MANAGER_INTERNAL_H
#include "global.h"

#include "gf_gfx_planes.h"
#include "heap.h"
#include "overlay_manager.h"
#include "sound_02004A44.h"
#include "system.h"
#include "unk_02034B0C.h"
#include "unk_02037C94.h"
#include "unk_020915B0.h"

typedef struct UnkStruct_020192D0_Args {
    void *unk00;
    u32 unk04;
    u32 unk08;
    u8 unk0C;
    u8 padding[3];
} UnkStruct_020192D0_Args;

typedef struct UnkStruct_020192D0 {
    UnkStruct_020192D0_Args *args;
    int unk04;
    OverlayManager *unk08;
    void *unk0C;
    NNSFndHeapHandle unk10;
    u8 unk14[0x78 - 0x14];
    int unk78;
    int unk7C;
} UnkStruct_020192D0;

void LoadOVY38(void);
void UnloadOVY38(void);
void sub_0203A930(int a0);
const OverlayManagerTemplate *sub_02087E10(u8 a0);
BOOL sub_02034DB8(void);
void sub_02034DE0(void);
void ov00_021EC294(void *(*alloc)(int, u32, int), void (*free)(int, void *, u32));
int ov00_021EC9D4(void);
void ov00_021ECB40(void);

extern const OverlayManagerTemplate _020F6288;

BOOL sub_020192D0(OverlayManager *man, int *state);
BOOL sub_0201935C(OverlayManager *man, int *state);
BOOL sub_02019490(OverlayManager *man, int *state);
void sub_020194B4(UnkStruct_020192D0 *data);
void sub_020194F8(UnkStruct_020192D0 *data);
void *sub_02019520(int name, u32 size, int align);
void sub_02019548(int name, void *ptr, u32 size);

static NNSFndHeapHandle _021D1108;

BOOL sub_020192D0(OverlayManager *man, int *state);
BOOL sub_0201935C(OverlayManager *man, int *state);
BOOL sub_02019490(OverlayManager *man, int *state);
void sub_020194B4(UnkStruct_020192D0 *data);
void sub_020194F8(UnkStruct_020192D0 *data);
void *sub_02019520(int name, u32 size, int align);
void sub_02019548(int name, void *ptr, u32 size);

#endif
