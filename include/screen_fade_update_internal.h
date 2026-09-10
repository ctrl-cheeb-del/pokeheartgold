#ifndef POKEHEARTGOLD_SCREEN_FADE_UPDATE_INTERNAL_H
#define POKEHEARTGOLD_SCREEN_FADE_UPDATE_INTERNAL_H
#include "global.h"

#include "heap.h"
#include "screen_fade.h"
#include "sys_task_api.h"

typedef struct FadeParam {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 screen;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u16 color;
    u16 pad26;
    u32 state;
    void *task;
} FadeParam;

typedef void (*FadeBlankFunc)(u32);
typedef struct FadeBlankPair {
    u32 values[2];
    FadeBlankFunc funcs[2];
    u32 active[2];
} FadeBlankPair;

void SetMasterBrightness(PMLCDTarget screen, int brightness);
void sub_0200FBF4(PMLCDTarget screen, u16 color);
void sub_0200FE78(u32 *dst, u32 a1, u32 a2, u32 a3);
void sub_0200FE84(FadeParam *dst, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u16 color);
void sub_0200FEB0(FadeBlankPair *data);
void sub_0200FECC(FadeBlankPair *data);
void sub_02010014(u32 value);
u16 sub_02010018(u8 *data, u16 color);
u16 sub_0201002C(u8 *data);
void sub_02010050(SysTask *task, void *arg);
void sub_02010064(FadeParam *param);
void sub_02010094(FadeParam *param);
void sub_020100C4(void *data);
void sub_0200FE14(int mode, u32 *dst);

#include "global.h"

typedef struct FadeUpdate {
    u32 mode;
    u32 mainActive;
    u32 subActive;
} FadeUpdate;
typedef BOOL (*FadeFunc)(void *);
extern FadeFunc sFadeFuncPtrs[];
BOOL DoFadeUpdateFrame(FadeUpdate *state, void *mainWork, void *subWork);
void FadeWork_UpdateFrame(u32 *active, void *work);
BOOL CallFadeFunc(void *work);

void HBlankInterruptDisable(void);
void sub_0200FF5C(FadeBlankPair *data, int index);
void sub_0200FF88(void *a0, u32 a1, u32 a2, u32 a3, enum HeapID heapId);
void sub_0200FFB4(FadeBlankPair *data, int index, enum HeapID heapId);
void sub_0200FFD8(SysTask *task, void *arg);
void sub_0200FFF8(SysTask *task, void *arg);
void sub_0200FEE4(void *a0, u32 a1, u32 a2, u32 a3);

typedef struct FadeSetTaskData {
    void *a0;
    u32 a1;
    u32 a2;
    u32 a3;
} FadeSetTaskData;
typedef struct FadeClearTaskData {
    FadeBlankPair *data;
    int index;
} FadeClearTaskData;

void sub_0200FE14(int mode, u32 *dst);
void sub_0200FE78(u32 *dst, u32 a1, u32 a2, u32 a3);
void sub_0200FE84(FadeParam *dst, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u16 color);
void sub_0200FEB0(FadeBlankPair *data);
void sub_0200FECC(FadeBlankPair *data);
BOOL DoFadeUpdateFrame(FadeUpdate *state, void *mainWork, void *subWork);
void FadeWork_UpdateFrame(u32 *active, void *work);
BOOL CallFadeFunc(void *work);
void sub_0200FF5C(FadeBlankPair *data, int index);
void sub_0200FF88(void *a0, u32 a1, u32 a2, u32 a3, enum HeapID heapId);
void sub_0200FFB4(FadeBlankPair *fade, int index, enum HeapID heapId);
void sub_0200FFD8(SysTask *task, void *arg);
void sub_0200FFF8(SysTask *task, void *arg);
void sub_02010014(u32 value);
u16 sub_02010018(u8 *data, u16 color);
u16 sub_0201002C(u8 *data);
void sub_02010050(SysTask *task, void *arg);
void sub_02010064(FadeParam *param);
void sub_02010094(FadeParam *param);

#endif
