#ifndef OV96_R71U1_PRIVATE_H
#define OV96_R71U1_PRIVATE_H
#include "global.h"

#include "system.h"

#define U16AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))

typedef struct Ov96R71Sel {
    s32 idx;
    u32 flag;
} Ov96R71Sel;

extern BOOL System_GetTouchNew(void);
extern u32 ov96_021E5F24(void *);
extern void ov96_021E8228(void *, u32, u32, u32, u32);
extern u8 ov96_021FB784(void *, s32, s32);
extern BOOL ov96_021FA6D0(void *, void *);
#endif
