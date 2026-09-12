#ifndef POKEHEARTGOLD_OVERLAY14_BOX_WINDOW_FRAME_R58_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY14_BOX_WINDOW_FRAME_R58_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "unk_0201956C.h"
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
extern void ov14_021F5BD8(void *, u32, u32, u32, u32);
extern void ov14_021F5950(void *, u32, u32, u32);
extern void sub_02019A60(void *, u32, void *);
void ov14_021F605C(void *);
void ov14_021F6070(void *);
void ov14_021F6094(void *);
void ov14_021F60A8(void *);
void ov14_021F60BC(UnkStruct_0201956C *, int, Window *);
void ov14_021F6208(UnkStruct_0201956C *, int, Window *);
void ov14_021F6244(void *);
#endif
