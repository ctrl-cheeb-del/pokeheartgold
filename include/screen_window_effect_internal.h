#ifndef POKEHEARTGOLD_SCREEN_WINDOW_EFFECT_INTERNAL_H
#define POKEHEARTGOLD_SCREEN_WINDOW_EFFECT_INTERNAL_H
#include "global.h"

#include "heap.h"
#include "sys_task_api.h"

typedef struct {
    s32 a;
    s32 b;
} Pair8;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Quad16;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Triple12;

typedef struct {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s32 e;
    s32 f;
} Window16;

typedef struct {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    s32 state;
    void *unk10;
    void *work;
    u32 unk18;
    u32 unk1C;
    u32 heapId;
} Manager;

extern void GF_AssertFail(void);
extern void sub_02010EC8(void *work);
extern void sub_02010F34(u32, u32, void *);
extern void *sub_02010EE0(void *, u32);
extern void sub_02010F00(SysTask *, void *);
extern void sub_02010FEC(void *, u32, u32, u32);
struct FadeBlankPair;
extern void sub_0200FFB4(struct FadeBlankPair *data, int index, enum HeapID heapId);
void sub_02012E6C(void *, const void *, u32, u32, void *, u32, u32, u32);
BOOL sub_02012F54(void *work);
void sub_02013004(s32, s32, s32, s32, s32, s32, s32 *, s32 *);
void sub_020131AC(void *work);
void sub_02012DD8(Manager *manager, const void *config);
BOOL sub_02012E10(Manager *manager);

void sub_020131F4(u32 value, BOOL screen);
void sub_02013220(u32 value, BOOL enable, BOOL high, BOOL screen);
void sub_020132A8(u32 value, BOOL enable, BOOL screen);
s8 sub_020132E8(BOOL high, BOOL screen);
s8 sub_0201333C(BOOL screen);
void sub_02013364(s32 a, s32 b, s32 c, s32 d, BOOL high, BOOL screen);
void sub_020134BC(SysTask *task, void *data);
void sub_020134D0(SysTask *task, void *data);
void sub_020134EC(SysTask *task, void *data);
void sub_02013504(SysTask *task, void *data);
void sub_02013424(Pair8 *base, s32 value, s32 slot);
void sub_02013440(void *base, s32 a, s32 b, s32 slot, s32 group);
void sub_02013468(void *base, s32 a, s32 b, s32 slot);
void sub_02013488(void *base, s32 a, s32 b, s32 c, s32 d, s32 slot, s32 group);

typedef char AssertWindowPair[(sizeof(Pair8) == 8) ? 1 : -1];
typedef char AssertWindowQuad[(sizeof(Quad16) == 16) ? 1 : -1];
typedef char AssertWindowTriple[(sizeof(Triple12) == 12) ? 1 : -1];
typedef char AssertWindowCoords[(sizeof(Window16) == 16) ? 1 : -1];
typedef char AssertWindowManager[(sizeof(Manager) == 0x24) ? 1 : -1];
typedef char AssertWindowWork[(offsetof(Manager, work) == 0x14) ? 1 : -1];
typedef char AssertWindowHeap[(offsetof(Manager, heapId) == 0x20) ? 1 : -1];

#endif
