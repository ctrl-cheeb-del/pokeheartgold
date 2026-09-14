#ifndef TO47_OVERLAY83_MENU_BUILDERS_PRIVATE_H
#define TO47_OVERLAY83_MENU_BUILDERS_PRIVATE_H

#include "global.h"

#include "list_menu_items.h"
#include "overlay83_sol_partial_internal.h"

#pragma require_prototypes off

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov83MenuRect {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;
} Ov83MenuRect;

typedef struct Ov83MenuTemplate {
    Ov83MenuRect rect;
    ListMenuItem *items;
    MsgData *msgData;
    u8 count;
} Ov83MenuTemplate;

extern const u8 ov83_02248010[];
extern const u16 ov83_02248018[];

void *ov83_02247CCC(void *a, void *tmpl, int c, int d, u8 e);
u8 ov83_0224777C(void *save, int mode, int index);
int ov80_02237B24(int value, int mode);

void ov83_022469E4(void *p, u8 count, int c, int d, u8 e);
void ov83_02246AA4(u8 *p);
void ov83_02246B6C(u8 *p);

#endif
