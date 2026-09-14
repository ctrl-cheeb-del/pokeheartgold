#ifndef TO45_OV96_R89_PRIVATE_H
#define TO45_OV96_R89_PRIVATE_H

#include "global.h"

#include "unk_02020B8C.h"

typedef struct Ov96R89Slot {
    u32 active;
    u8 pad04[8];
    u32 coordIndex;
    u16 x;
    u16 z;
} Ov96R89Slot;

typedef struct Ov96R89Slots {
    Ov96R89Slot slot[5];
    struct {
        u16 x;
        u16 z;
    } coords[20];
    u16 current;
    u16 remaining;
} Ov96R89Slots;

typedef struct Ov96R89Entity {
    void *objects[4];
    u8 pad10[0x48];
    VecFx32 position;
    VecFx32 velocity;
    u8 pad70[0x28];
    u32 field98;
    u8 pad9C[6];
    u8 fieldA2;
    u8 padA3;
    u8 state;
    u8 padA5;
    u8 blocked;
    u8 padA7[3];
    u8 amount;
    u8 padAB[5];
    u8 category;
    u8 direction;
    u8 padB2[1];
    u8 flags[5];
} Ov96R89Entity;

void GF_AssertFail(void);
int ov96_021EAF8C(void *);
void ov96_021E8228(void *, u8, u8, int, int);

extern const VecFx32 ov96_0221CAC8;

void ov96_02207800(Ov96R89Slots *);
void ov96_02207818(Ov96R89Slots *);
void ov96_02207870(void *);
BOOL ov96_022078B0(Ov96R89Slots *, Ov96R89Entity *, u8 *);
BOOL ov96_02207990(const VecFx32 *, const VecFx32 *, fx32, fx32);
int ov96_022079B8(const VecFx32 *);
BOOL ov96_02207A34(void *, Ov96R89Entity *, Ov96R89Entity *);
BOOL ov96_02207B8C(Ov96R89Entity *);

#endif
