#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_TOUCH_REGION_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_TOUCH_REGION_PRIVATE_H

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

void GF_AssertFail(void);
void ov96_0220B148(void *object, s16 *y, s16 *x);
void System_GetTouchNewCoords(u32 *x, u32 *y);

typedef struct Ov96R93State {
    u8 pad[0x180];
    u32 mode : 4;
    u32 active : 4;
    u32 rest : 24;
} Ov96R93State;

BOOL ov96_0220A910(Ov96R93State *state);

#endif
