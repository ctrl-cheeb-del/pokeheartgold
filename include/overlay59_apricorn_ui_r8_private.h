#ifndef OV59_R8_PRIVATE_H
#define OV59_R8_PRIVATE_H

#include "global.h"

#include "overlay_manager.h"
#include "system.h"
#include "touchscreen.h"

typedef struct Ov59R8Work {
    u8 raw[0x254];
    void *sprites[15];
} Ov59R8Work;

typedef struct Ov59R8TaskData {
    void *owner;
    u8 state;
    u8 limit;
    u8 counter;
    u8 pad7;
    s16 x;
    s16 y;
    s32 dx;
    s32 dy;
    s32 curX;
    s32 curY;
    void *sprite;
} Ov59R8TaskData;

extern u8 ov59_0223C908[];
extern u8 ov59_0223C924[];
extern u8 ov59_0223C940[];

u8 ov59_02239EA8(Ov59R8Work *work);
void ov59_02239C90(SysTask *task, Ov59R8TaskData *data);
u16 ov59_02239E0C(int unused, const u16 *entry, int mode);
void ov59_02239C70(Ov59R8Work *work);
int ov59_02239EF8(Ov59R8Work *work);
int ov59_02239F18(Ov59R8Work *work);
int ov59_0223A03C(Ov59R8Work *work);
int ov59_0223A05C(Ov59R8Work *work);
int ov59_0223A07C(Ov59R8Work *work, u32 input);
int ov59_0223A0B8(Ov59R8Work *work);
int ov59_0223A120(Ov59R8Work *work, int *hit);
int ov59_0223A194(Ov59R8Work *work, u32 input);
int ov59_0223A350(Ov59R8Work *work, u32 input);
int ov59_0223A268(Ov59R8Work *work);
int ov59_0223A2D0(Ov59R8Work *work, int *hit);
int ov59_0223A3B0(Ov59R8Work *work);
int ov59_0223A418(Ov59R8Work *work, int *hit);
int ov59_0223A48C(Ov59R8Work *work, int input);
int ov59_0223A58C(Ov59R8Work *work);
int ov59_0223A614(Ov59R8Work *work, int *hit);
int ov59_0223A564(int value, int max, int delta);
BOOL ov59_0223A678(Ov59R8Work *work);
void ov59_0223A7FC(Ov59R8Work *work, int direction);
BOOL ov59_0223A8E0(OverlayManager *manager, int *state);
BOOL ov59_0223A948(OverlayManager *manager, int *state);
BOOL ov59_0223A9B8(OverlayManager *manager, int *state);
void ov59_0223AA6C(Ov59R8Work *work);
void ov59_022388C4(Ov59R8Work *work);
void ov59_022387D0(Ov59R8Work *work, int arg);
void ov59_02238834(Ov59R8Work *work, int a, int b);
void ov59_02238A04(Ov59R8Work *work, int value);
void ov59_02238CFC(Ov59R8Work *work, int msg, int arg);
void ov59_02238FF4(Ov59R8Work *work, int arg);
void ov59_0223ACD0(void);
void ov59_0223A9E4(Ov59R8Work *work);
BOOL ov59_0223AABC(Ov59R8Work *work);
BOOL ov59_0223AB00(Ov59R8Work *work);
int ov59_0223AB3C(Ov59R8Work *work);
int ov59_0223AB90(Ov59R8Work *work);
int ov59_0223ABE4(Ov59R8Work *work);
int ov59_0223ABEC(Ov59R8Work *work);
int ov59_0223AC48(Ov59R8Work *work);
void ov59_0223AD20(Ov59R8Work *work);
void ov59_0223AD58(Ov59R8Work *work);
void ov59_0223AD84(Ov59R8Work *work);
void ov59_0223AE20(Ov59R8Work *work);
void ov59_0223AE88(Ov59R8Work *work);
void ov59_0223C304(void *p);
void sub_020210BC(void);
void sub_02021148(int arg);
void sub_02021238(void);
void Sprite_Delete(void *sprite);
void Sprite_SetAnimActiveFlag(void *sprite, BOOL flag);
void Sprite_ResetAnimCtrlState(void *sprite);
void Sprite_SetMatrix(void *sprite, const void *matrix);
void Sprite_SetPositionXY(void *sprite, s16 x, s16 y);
void SysTask_Destroy(SysTask *task);
void PlaySE(u32 seq);
void BeginNormalPaletteFade(int, int, int, int, int, int, int);
BOOL IsPaletteFadeFinished(void);
void SpriteSystem_DrawSprites(void *system);
int MenuInputStateMgr_GetState(void *manager);
void MenuInputStateMgr_SetState(void *manager, int state);
void *Save_PlayerData_GetOptionsAddr(void *save);
int Options_GetTextFrameDelay(void *options);
int Options_GetFrame(void *options);
void *Save_ApricornBox_Get(void *save);
void sub_02031CEC(void *src, void *dst);
void sub_02031DA0(void *src, void *dst);

#endif
