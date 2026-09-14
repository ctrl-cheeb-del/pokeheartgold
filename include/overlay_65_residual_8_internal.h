#ifndef TO45_SOL_R6_OVERLAY65_RESIDUAL8_H
#define TO45_SOL_R6_OVERLAY65_RESIDUAL8_H

#include "global.h"

#include "list_menu.h"
#include "message_format.h"
#include "msgdata.h"
#include "player_data.h"
#include "pm_string.h"

#define PTR(p, o)  (*(void **)((u8 *)(p) + (o)))
#define VPTR(p, o) (*(void *volatile *)((u8 *)(p) + (o)))
#define U32(p, o)  (*(u32 *)((u8 *)(p) + (o)))

typedef struct Ov65WorkR8 {
    u8 padding[0x36a0];
    void *entries;
} Ov65WorkR8;

typedef struct Ov65CallbacksR8 {
    u8 padding[0x2220];
    void *callback;
} Ov65CallbacksR8;

extern int ov65_0221FC54(void *, void *, void *, void *, int);
extern void ov65_0221E330(void *, u32);
extern int ov65_0221E740(void *);
extern int ov65_0221E354(void *);
extern int ov65_0221E3BC(void *);
extern int ov65_0221E474(void *);
extern int ov65_0221E558(void *);
extern int ov65_0221E600(void *);
extern int ov65_0221E684(void *);
extern void *sub_02034818(u32);
extern void *Save_Frontier_GetStatic(void *);
extern void sub_020311AC(void *, u32);
extern void sub_0202C338(void *, u32);
extern void sub_0203A280(void *, u32, int, int, int);
extern int sub_0202C2F8(void *);
extern BOOL sub_0202C2DC(void *, int);
extern void *sub_0202C254(void *, int);
extern void CopyU16ArrayToString(String *, const u16 *);
extern void sub_0200E5D4(void *, int);
extern void *ov65_0221FCA0(void *, int, void *, void *);
extern void PlaySE(u32);

#endif
