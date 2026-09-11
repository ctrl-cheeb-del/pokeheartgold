#ifndef POKEHEARTGOLD_OVERLAY45_STATE_HELPERS_7_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY45_STATE_HELPERS_7_PRIVATE_H

#include "global.h"

#include "font.h"
#include "msgdata.h"
#include "player_data.h"
#include "pm_string.h"

typedef struct Ov45Work {
    u8 data[0x600];
} Ov45Work;
#define U8(w, o)  (*(u8 *)((w)->data + (o)))
#define S16(w, o) (*(s16 *)((w)->data + (o)))
#define U16(w, o) (*(u16 *)((w)->data + (o)))
#define U32(w, o) (*(u32 *)((w)->data + (o)))

void Sound_SetSceneAndPlayBGM(int, int, int);
void ov45_0222BC84(void *);
int ov45_0222E9E0(void);
void ov45_0222EC68(void);
void ov45_0222EC10(void *);
void *ov45_0222EA2C(int);
int ov45_0222BADC(void *, void *);
void ov45_0222CB74(void *, int, int);
void ov45_0222BA3C(Ov45Work *);
void ov45_0222BAC4(void *, void *);
void ov45_0222B118(Ov45Work *, int);
int ov45_0222B28C(void *, int, int);
u32 ov45_0222A9A0(Ov45Work *);
int ov45_0222A9CC(Ov45Work *);
int ov45_0222AA5C(Ov45Work *);
int ov45_0222AA10(Ov45Work *);
void ov45_0222A844(Ov45Work *, PlayerProfile *, enum HeapID);
int ov45_0222AFF8(Ov45Work *);
int ov45_0222B00C(Ov45Work *);
void ov45_0222EC90(u16);
void ov45_0222BE28(Ov45Work *, u16);
void ov45_0222BD5C(void *);
void ov45_0222A5E8(Ov45Work *, int);
void ov45_0222A4D0(Ov45Work *);
void ov45_0222A520(Ov45Work *, int);
void ov45_0222A53C(void);
void ov45_0222A548(void);
BOOL ov45_0222A550(void *, int);
void *ov45_0222A578(Ov45Work *, u32);
void *ov45_0222A5C0(Ov45Work *);
void ov45_0222A704(Ov45Work *, int, int);
void ov45_0222A72C(Ov45Work *, u8);
void ov45_0222A770(Ov45Work *, int, int);
void ov45_0222A7DC(Ov45Work *, u32, u32);

#endif
