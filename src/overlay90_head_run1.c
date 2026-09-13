#include <string.h>

#include "global.h"

typedef struct SysTask SysTask;
typedef struct Sprite Sprite;

typedef struct Ov90WindowBits {
    u8 value : 5;
    u8 enable : 1;
    u8 unused : 2;
} Ov90WindowBits;

typedef struct Ov90Slide {
    Sprite *sprites[2];
    s16 step;
    s16 displacement;
    u8 front[0xC0];
    u8 back[0xC0];
    SysTask *task;
    Ov90WindowBits savedControl;
    Ov90WindowBits savedBlend;
    u8 pad192[2];
    u32 savedMain;
} Ov90Slide;

typedef struct Ov90AnimTask {
    void *owner;
    u16 state;
    s16 timer;
    void *field8;
    u8 pad0C[0x1C];
    void *resource;
    SysTask *task;
    Sprite *sprite;
    Ov90Slide slide;
} Ov90AnimTask;

extern BOOL IsFanfarePlaying(void);
extern void GF_AssertFail(void);
extern void *sub_0202C6F4(void *);
extern int sub_0203484C(int);
extern int sub_0203A084(void *, int, u32 *);
extern void sub_0202C554(void *, u32, int);
extern void sub_0202C584(void *, u32, int);
extern void sub_0202C5B4(void *, u32, int);
extern void ov45_0222ACB8(void *, int, int, int, int, int, int);
extern void *ov90_02258EB4(void *, void *, int, int, int, int);
extern void Sprite_SetAnimCtrlSeq(Sprite *, int);
extern void Sprite_SetPriority(Sprite *, int);
extern void Sprite_SetDrawFlag(Sprite *, BOOL);
extern void Sprite_SetAnimActiveFlag(Sprite *, BOOL);
extern fx32 Sprite_GetAnimationFrame(Sprite *);
extern void Sprite_UpdateAnim(Sprite *, fx32);
extern BOOL Sprite_IsAnimated(Sprite *);
extern void Sprite_SetPalOffsetRespectVramOffset(Sprite *, int);
extern void Sprite_Delete(Sprite *);
extern void Sprite_SetMatrix(Sprite *, const void *);
extern void SysTask_Destroy(SysTask *);
extern SysTask *SysTask_CreateOnVWaitQueue(void (*)(SysTask *, void *), void *, u32);
extern void HBlankInterruptDisable(void);
extern BOOL Main_SetHBlankIntrCB(void (*)(void *), void *);
extern void PlaySE(u16);
extern const s32 ov90_0225C2B4[][3];

BOOL ov90_0225B978(u8 *work);
void ov90_0225B9A8(u8 *work);
int ov90_0225BA14(u8 *work);
void ov90_0225BA38(u8 *work);
void ov90_0225BAA0(u8 *work);
BOOL ov90_0225BBD0(Ov90Slide *slide);
BOOL ov90_0225BBF0(Ov90Slide *slide);
void ov90_0225BC28(Ov90Slide *slide, int direction);
void ov90_0225BD08(Ov90Slide *slide);
void ov90_0225BD84(Ov90Slide *slide);
void ov90_0225BDE4(SysTask *task, void *data);
void ov90_0225BE08(Ov90Slide *slide);
void ov90_0225BEE0(SysTask *task, Ov90AnimTask *work);
void ov90_0225C06C(SysTask *task, Ov90AnimTask *work);

BOOL ov90_0225B978(u8 *work) {
    if (*(u32 *)(work + 0x660) == 1 && !IsFanfarePlaying()) {
        *(u32 *)(work + 0x660) = 0;
    }
    return *(u32 *)(work + 0x660) != 1;
}

void ov90_0225B9A8(u8 *work) {
    void *obj = sub_0202C6F4(*(void **)(work + 0xC));
    int i;
    for (i = 0; i < work[0x14]; i++) {
        u32 value;
        int kind = sub_0203484C(work[0x10 + i]);
        int result = sub_0203A084(*(void **)(work + 0xC), kind, &value);
        switch (result) {
        case 0:
        case 1:
            switch (work[7]) {
            case 0:
                sub_0202C554(obj, value, 1);
                break;
            case 1:
                sub_0202C584(obj, value, 1);
                break;
            case 2:
                sub_0202C5B4(obj, value, 1);
                break;
            }
            break;
        }
    }
}

int ov90_0225BA14(u8 *work) {
    switch (work[7]) {
    case 0:
        return 0;
    case 1:
        return 0;
    case 2:
        GF_AssertFail();
        return 0;
    }
}
