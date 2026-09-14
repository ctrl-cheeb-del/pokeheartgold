#ifndef TO45_OV70_R18_R8_PRIVATE_H
#define TO45_OV70_R18_R8_PRIVATE_H

#include "global.h"

#include "to41_overlay_70_residual_18_private.h"

typedef struct Ov70InputRecord {
    s16 species;
    s8 a;
    s8 b;
    s8 c;
    s8 d;
    u8 selection;
    u8 extra;
} Ov70InputRecord;

typedef struct Ov70Key6 {
    s16 species;
    s8 a;
    s8 b;
    s8 c;
    s8 d;
} Ov70Key6;

typedef struct Ov70Keys {
    u8 pad[0x48];
    u32 newKeys;
} Ov70Keys;

typedef struct Ov70R8Work {
    u8 pad0000[0x2c];
    u32 state;
    u8 pad0030[0x260 - 0x30];
    u8 mapRecord[0xb8a - 0x260];
    Ov70Key6 current;
    Ov70Key6 stored;
    u8 pad0b96[2];
    u32 storedExtra;
    u8 pad0b9c[0x11de - 0xb9c];
    u16 changed;
    u8 pad11e0[0x12cc - 0x11e0];
    u32 extra;
    u8 pad12d0[0x1604 - 0x12d0];
    u32 counter;
} Ov70R8Work;

extern Ov70Keys gSystem;

u32 GetMonBaseStat(int species, int attr);
int ov70_0223EDE4(u8 *record, u32 value);
void ov70_0223C420(R14Work *w, int value);
void ov70_0223C304(R14Work *w);
int ov70_0223BFA8(void *arg, int which);
void ov70_02238130(void *src, int n, void *dest);
void ov70_022381A4(void *src, void *dest);
int ov70_0223CC68(const void *a, const void *b, int c, int d);
BOOL ov70_02237F38(void);
u32 ov70_02237F58(void);
void ov70_02241184(R14Work *w, int value, int mode);
void ov70_0223CC04(void *bg, void *window, void *msgData, int flag);
void sub_020399EC(void);
void StopSE(u16 id);
u32 sub_0202DB80(void *);
u32 sub_0202DB90(void *);
void ov00_021ECB94(RTCDate *date, RTCTime *time);

void ov70_0223BD90(R14Work *w, int value);
int ov70_0223BE84(R14Work *w);
int ov70_0223BF00(R14Work *w);
int ov70_0223C008(Ov70R8Work *w);
int ov70_0223C0C8(R14Work *w);

#endif
