#ifndef OV45_R24_PRIVATE_H
#define OV45_R24_PRIVATE_H
#include "global.h"

#include "easy_chat.h"

typedef struct Ov45Triple {
    u32 x[3];
} Ov45Triple;

typedef struct Ov45Grid {
    u32 active;
    s32 target;
    s32 counters[9];
    u32 pad2C[9];
    u32 pad50[27];
    u32 padBC[27];
} Ov45Grid;

typedef struct Ov45WordSet {
    u8 flags[20];
    u16 words[20][4];
    WallpaperPasswordBank *bank;
} Ov45WordSet;

typedef struct Ov45Timer {
    u32 active;
    s64 start;
    s32 elapsed;
    s32 duration;
    u32 phase;
    u32 counter;
} Ov45Timer;

extern void GF_AssertFail(void);
extern u32 MTRandom(void);

extern int ov45_0222EC68(void *);
extern int ov45_0222BADC(void *, u32);
extern int ov45_0222A920(void *);
extern int ov45_0222AFF8(void *);
extern int ov45_0222B048(void *, int);
extern void ov45_0222BE08(void *, int, int);
extern int ov45_0222BD74(void *, int);
extern void ov45_0222BE48(void *);
extern void ov45_0222BD4C(void *);
extern void ov45_0222BE54(void *);
extern void ov45_0222BD5C(void *);
extern void ov45_0222ECB8(s64 *);
extern const s32 ov45_02254A3C[];
extern void (*const ov45_02254A60[])(void *, void *, u32);
extern const u16 _02254A28[][2];

void ov45_0222C3B0(Ov45Grid *);
int ov45_0222C408(Ov45Grid *, u32, u32);
void ov45_0222C480(Ov45Grid *, u32);
int ov45_0222C4B4(Ov45Grid *, u32);
int ov45_0222C4E4(Ov45Grid *, u32);
int ov45_0222C4FC(Ov45Grid *, u32);
void ov45_0222C514(Ov45Grid *, int);
int ov45_0222C54C(Ov45Grid *, u32);
void ov45_0222C580(Ov45Grid *, u32);
int ov45_0222C5B4(Ov45Grid *, u32);
void ov45_0222C5E8(Ov45Grid *, u32, u32);
BOOL ov45_0222C61C(Ov45Grid *, u32, u32);
u32 ov45_0222C658(Ov45Grid *, u32);
void ov45_0222C688(void *, u16 *, void *, u8 *);
void ov45_0222C73C(void *, u16 *, void *, u8 *);
void ov45_0222C79C(void *, u16 *, void *, u8 *);
void ov45_0222C800(void *, void *, void *, u8 *);
void ov45_0222C828(void *, u8 *, void *, void *);
void ov45_0222C83C(void *, void *, void *, u8 *);
void ov45_0222C858(void *, void *, u32, u8 *);
void ov45_0222C88C(void *, void *, void *, u8 *);
void ov45_0222C8AC(Ov45WordSet *);
void ov45_0222C8C8(Ov45WordSet *, u32, u32);
u32 ov45_0222C900(Ov45WordSet *);
void ov45_0222C944(Ov45WordSet *, u32, u8);
u32 ov45_0222C95C(Ov45WordSet *, u32);
void ov45_0222C978(Ov45WordSet *, enum HeapID);
void ov45_0222C994(Ov45WordSet *);
void ov45_0222C9A0(Ov45WordSet *, u32, u8, u32);
u32 ov45_0222C9D0(Ov45WordSet *, u32);
u16 *ov45_0222C9EC(Ov45WordSet *, u32);
void ov45_0222CA10(WallpaperPasswordBank *, u32, u16 *);
void ov45_0222CAA0(Ov45Timer *);
void ov45_0222CA7C(Ov45Timer *, int, int);
void ov45_0222CA8C(Ov45Timer *);
#endif
