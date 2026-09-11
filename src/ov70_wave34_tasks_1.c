#include "global.h"
typedef struct Sprite Sprite;
typedef struct Vec { s32 x,y,z; } Vec;
typedef struct TaskEnv { s32 state; s32 pos; s32 which; void *work; } TaskEnv;
typedef struct SysTask SysTask;
extern void Sprite_SetAnimCtrlSeq(Sprite *, int);
extern void Sprite_SetMatrix(Sprite *, Vec *);
extern int TouchscreenHitbox_FindRectAtTouchNew(const void *);
extern const u8 ov70_02245D26[];
extern SysTask *CreateSysTaskAndEnvironment(void (*)(SysTask *, void *), u32, u32, u32);
extern void *SysTask_GetData(SysTask *);
extern void PlaySE(u32);
extern void DestroySysTaskAndEnvironment(SysTask *);
extern int Sprite_IsAnimated(Sprite *);
extern void ov70_02240D74(void *, int);
extern void ov70_02240F58(SysTask *, TaskEnv *);
extern void ov70_02241048(SysTask *, TaskEnv *);
void ov70_02240F58(SysTask *, TaskEnv *);
void ov70_02241048(SysTask *, TaskEnv *);
void ov70_02240F3C(TaskEnv *, int);
void ov70_02240EF4(void *, int);
void ov70_02241004(void *, int);
void ov70_022410F0(Sprite *, int, int);
int ov70_02241164(int);

void ov70_02240EF4(void *work, int which) {
    SysTask *task;
    TaskEnv *env;
    ov70_02240D74(work, which);
    task = CreateSysTaskAndEnvironment((void (*)(SysTask *, void *))ov70_02240F58, 0x10, 5, 0x3d);
    *(SysTask **)((u8 *)work + 0x11d8) = task;
    env = SysTask_GetData(*(SysTask **)((u8 *)work + 0x11d8));
    env->state = 0;
    env->pos = -40;
    env->which = which;
    env->work = work;
    ov70_02240F3C(env, 0);
    PlaySE(0x62e);
}

void ov70_02240F3C(TaskEnv *env, int anim) {
    Sprite *sprite = *(Sprite **)((u8 *)env->work + 0xEE4);
    Sprite_SetAnimCtrlSeq(sprite, anim + 7 * env->which);
}

void ov70_02240F58(SysTask *task, TaskEnv *env) {
    void *work=env->work;
    switch(env->state) {
    case 0:
        if(env->pos>0xa0){env->pos=0xa0;env->state=1;ov70_02240F3C(env,1);}
        env->pos+=5;
        ov70_022410F0(*(Sprite **)((u8*)work+0xee4),0x80,env->pos);
        break;
    case 1:
        if(!Sprite_IsAnimated(*(Sprite **)((u8*)work+0xee4))){ov70_02240F3C(env,2);env->state=2;}
        break;
    case 2:
        if(env->pos<=0x8a){env->pos=0x8a;env->state=3;ov70_02240F3C(env,3);}else env->pos-=2;
        ov70_022410F0(*(Sprite **)((u8*)work+0xee4),0x80,env->pos);
        break;
    case 3:
        PlaySE(0x60c);*(u16*)((u8*)env->work+0x11dc)=1;DestroySysTaskAndEnvironment(task);break;
    }
}

void ov70_02241004(void *work, int which) {
    SysTask *task;
    TaskEnv *env;
    task = CreateSysTaskAndEnvironment((void (*)(SysTask *, void *))ov70_02241048, 0x10, 5, 0x3d);
    *(SysTask **)((u8 *)work + 0x11d8) = task;
    env = SysTask_GetData(*(SysTask **)((u8 *)work + 0x11d8));
    env->state = 0;
    env->pos = 0x8a;
    env->which = which;
    env->work = work;
    ov70_02240F3C(env, 5);
    PlaySE(0x60d);
}

void ov70_02241048(SysTask *task, TaskEnv *env) {
    void *work=env->work;
    switch(env->state) {
    case 0:
        if(env->pos>0xa0){env->pos=0xa0;env->state=1;ov70_02240F3C(env,6);}
        env->pos+=2;
        ov70_022410F0(*(Sprite **)((u8*)work+0xee4),0x80,env->pos);
        break;
    case 1:
        if(!Sprite_IsAnimated(*(Sprite **)((u8*)work+0xee4))){ov70_02240F3C(env,0);env->state=2;PlaySE(0x62f);}
        break;
    case 2:
        if(env->pos < -20){env->state=3;ov70_02240F3C(env,3);}
        env->pos-=5;
        ov70_022410F0(*(Sprite **)((u8*)work+0xee4),0x80,env->pos);
        break;
    case 3:
        *(u16*)((u8*)work+0x11dc)=1;DestroySysTaskAndEnvironment(task);break;
    }
}

void ov70_022410F0(Sprite *sprite, int x, int y) {
    Vec scale;
    float value;
    if (x > 0) value = (float)(x << 12) + 0.5f;
    else value = (float)(x << 12) - 0.5f;
    scale.x = (s32)value;
    y -= 8;
    if (y > 0) value = (float)(y << 12) + 0.5f;
    else value = (float)(y << 12) - 0.5f;
    scale.y = (s32)value + 0x100000;
    scale.z = 0;
    Sprite_SetMatrix(sprite, &scale);
}

int ov70_02241164(int count) {
    int hit = TouchscreenHitbox_FindRectAtTouchNew(ov70_02245D26);
    if (hit == -1 || hit >= count) hit = -1;
    return hit;
}
