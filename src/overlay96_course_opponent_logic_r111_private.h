#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_OPPONENT_LOGIC_R111_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_OPPONENT_LOGIC_R111_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "sys_task_api.h"

typedef struct Ov96OpponentBgWork {
    void *spriteSystem;
    BgConfig *bgConfig;
    SysTask *task;
    fx32 offset;
    fx32 step;
    s8 frame;
    u8 duration;
    u16 padding_16;
    u32 direction;
} Ov96OpponentBgWork;

void ov96_02214B84(void *course, u8 *work);
void ov96_022155A0(void *course, u8 *work, void **entry);
int ov96_02215460(void *arg0, void *arg1, int state, int index, void *data);
int ov96_02215478(void *arg0, void *arg1, int arg2);
int ov96_02215058(void *arg0, void *arg1, int arg2, int arg3);
int ov96_02215614(int x, int y, int otherX, int otherY);
BOOL ov96_02215650(int x1, int y1, int x2, int y2, u8 quadrant, u8 otherQuadrant);
BOOL ov96_0221567C(int x1, int y1, int x2, int y2, u8 quadrant, u8 otherQuadrant);
BOOL ov96_022156A8(int x, int y, const u16 (*points)[2]);
BOOL ov96_022156E8(const VecFx32 *arg0, fx32 radius, const VecFx32 *arg2, fx32 extra);
void ov96_02215710(SysTask *task, Ov96OpponentBgWork *work);

#endif
