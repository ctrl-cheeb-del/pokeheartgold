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

void ov90_0225BD08(Ov90Slide *slide) {
    int i;
    if (slide->task != NULL) {
        SysTask_Destroy(slide->task);
        slide->task = NULL;
    }
    for (i = 0; i < 2; i++) {
        if (slide->sprites[i] != NULL) {
            Sprite_Delete(slide->sprites[i]);
            slide->sprites[i] = NULL;
        }
    }
    HBlankInterruptDisable();
    *(vu32 *)0x04000000 = (*(vu32 *)0x04000000 & 0xFFFF1FFF) | (slide->savedMain << 13);
    {
        u32 window = (*(vu16 *)0x0400004A & ~0x3F) | slide->savedControl.value;
        if (slide->savedControl.enable) {
            window |= 0x20;
        }
        *(vu16 *)0x0400004A = window;
    }
}

void ov90_0225BD84(Ov90Slide *slide) {
    int i;
    memset(slide->back, 0, sizeof(slide->back));
    for (i = 0; i < 23 - slide->displacement; i++) {
        slide->back[0x49 + i] = 1;
        slide->back[0x79 - i] = 1;
    }
    if (slide->task == NULL) {
        slide->task = SysTask_CreateOnVWaitQueue(ov90_0225BDE4, slide, 0);
    }
}

void ov90_0225BDE4(SysTask *task, void *data) {
    Ov90Slide *slide = data;
    memcpy(slide->front, slide->back, sizeof(slide->front));
    SysTask_Destroy(slide->task);
    slide->task = NULL;
}

void ov90_0225BE08(Ov90Slide *slide) {
    int scanline;
    u32 mode;
    vu16 *vcount = (vu16 *)0x04000006;
    scanline = ((int)*vcount + 1) % 256;
    if (scanline < 192) {
        mode = (*(vu32 *)0x04000000 & 0xE000) >> 13;
        if ((*(vu16 *)0x04000004 & 2) != 0) {
            if (scanline < 0x49 || scanline > 0x79) {
                u32 window = (*(vu16 *)0x0400004A & ~0x3F) | slide->savedControl.value;
                if (slide->savedControl.enable) {
                    window |= 0x20;
                }
                *(vu16 *)0x0400004A = window;
                mode |= slide->savedMain;
            } else {
                u32 window = (*(vu16 *)0x0400004A & ~0x3F) | slide->savedBlend.value;
                if (slide->savedBlend.enable) {
                    window |= 0x20;
                }
                *(vu16 *)0x0400004A = window;
                mode &= ~(slide->savedMain | 2);
            }
            if (slide->front[scanline] == 1) {
                *(vu32 *)0x04000000 = (*(vu32 *)0x04000000 & 0xFFFF1FFF) | ((mode | 1) << 13);
            } else {
                *(vu32 *)0x04000000 = (*(vu32 *)0x04000000 & 0xFFFF1FFF) | ((mode & ~1) << 13);
            }
        }
    }
}

void ov90_0225BEE0(SysTask *task, Ov90AnimTask *work) {
    switch (work->state) {
    case 1: {
        extern void ov90_0225BAD0(Ov90Slide *, void *, void *, void *);
        ov90_0225BAD0(&work->slide, work->resource, work->field8, work->owner);
    }
        work->sprite = ov90_02258EB4(work->resource, work->field8, 0x80, 0x61, 0x40, (int)work->owner);
        Sprite_SetPriority(work->sprite, 0);
        work->state++;
        break;
    case 2:
        if (ov90_0225BBD0(&work->slide) == TRUE) {
            work->state++;
            work->timer = 0;
        }
        break;
    case 3: {
        fx32 oldFrame = Sprite_GetAnimationFrame(work->sprite);
        fx32 frame;
        Sprite_UpdateAnim(work->sprite, 2 * FX32_ONE);
        frame = Sprite_GetAnimationFrame(work->sprite);
        if (oldFrame != frame) {
            switch (frame) {
            case 7:
                PlaySE(0x5DD);
                break;
            case 9:
                PlaySE(0x5DD);
                break;
            case 11:
                PlaySE(0x5DD);
                break;
            case 13:
                PlaySE(0x5DD);
                break;
            case 15:
                PlaySE(0x642);
                break;
            }
        }
        if (frame == 15) {
            if (work->timer == 0) {
                Sprite_SetPalOffsetRespectVramOffset(work->sprite, 0);
            } else if (work->timer == 4) {
                Sprite_SetPalOffsetRespectVramOffset(work->sprite, 1);
            }
            work->timer++;
            if (work->timer >= 8) {
                work->timer = 0;
            }
        }
        if (!Sprite_IsAnimated(work->sprite)) {
            work->state++;
            Sprite_SetPalOffsetRespectVramOffset(work->sprite, 0);
        }
    } break;
    case 4:
        if (ov90_0225BBF0(&work->slide) == TRUE) {
            Sprite_Delete(work->sprite);
            work->sprite = NULL;
            work->state++;
            work->timer = 0;
        }
        break;
    case 5:
        work->timer++;
        if (work->timer >= 2) {
            work->state = 0;
            ov90_0225BD08(&work->slide);
            SysTask_Destroy(work->task);
            work->task = NULL;
        }
        break;
    }
}

void ov90_0225C06C(SysTask *task, Ov90AnimTask *work) {
    switch (work->state) {
    case 1:
        /* The initializer and slide setup are intentionally kept together. */
        extern void ov90_0225BAD0(Ov90Slide *, void *, void *, void *);
        ov90_0225BAD0(&work->slide, work->resource, work->field8, work->owner);
        work->sprite = ov90_02258EB4(work->resource, work->field8, 0x80, 0x61, 0x40, (int)work->owner);
        Sprite_SetAnimCtrlSeq(work->sprite, 1);
        Sprite_SetPriority(work->sprite, 0);
        work->state++;
        break;
    case 2:
        if (ov90_0225BBD0(&work->slide) == TRUE) {
            Sprite_SetAnimActiveFlag(work->sprite, TRUE);
            work->state++;
            work->timer = 0;
        }
        break;
    case 3:
        work->timer++;
        if (work->timer >= 50) {
            work->state++;
        }
        break;
    case 4:
        if (ov90_0225BBF0(&work->slide) == TRUE) {
            Sprite_Delete(work->sprite);
            work->sprite = NULL;
            work->timer = 0;
            work->state++;
        }
        break;
    case 5:
        work->timer++;
        if (work->timer >= 2) {
            work->state = 0;
            ov90_0225BD08(&work->slide);
            SysTask_Destroy(work->task);
            work->task = NULL;
        }
        break;
    }
}
