#ifndef OV40_PRIVATE_H
#define OV40_PRIVATE_H

#include "global.h"

#include "message_format.h"

typedef struct Ov40State {
    u8 raw[0x4000];
} Ov40State;

void TouchHitboxController_IsTriggered(void *controller);
void TouchHitboxController_Destroy(void *controller);
void ManagedSprite_SetPositionXYWithSubscreenOffset(void *sprite, int x, int y, int offset);
void ManagedSprite_GetPositionXYWithSubscreenOffset(void *sprite, int *x, int *y, int offset);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void Sprite_DeleteAndFreeResources(void *sprite);
void ClearWindowTilemapAndCopyToVram(void *window);
void RemoveWindow(void *window);
void GfGfx_SwapDisplay(void);
void GF_AssertFail(void);
void PlaySE(u16 seqNo);
void *Save_GameStats_Get(void *saveData);
void GameStats_AddScore(void *stats, int score);
void Pokepic_Delete(void *pic);
void sub_020314BC(void *ptr);
void ov39_02227778(void *ptr);
void ov39_022272EC(void *ptr);

void ov40_0222CFBC(void *p, int value);
void ov40_0222CF94(void *p);
void ov40_0222CBC0(void *p);
void ov40_0222D910(void *p, int a1, int a2, int a3, int a4, int a5, void *a6);
void ov40_0222F9E0(void *p, int a1, int count);
int ov40_022303B8(void *p);
void ov40_0222FF74(void *p);
void ov40_02230424(void *p, int value);
void ov40_02230864(void *p);
void ov40_0222D6D0(void *p);
BOOL ov40_0224222C(void *p);
BOOL ov40_02242490(void *p);
BOOL ov40_0224253C(void *p);
BOOL ov40_022428D4(void *p);
BOOL ov40_02242AEC(void *p);
void ov40_022425E8(void *p);
void ov40_02243B94(void *p);
void ov40_0222BF80(void *p, int value);
void ov40_0222BF8C(void *p, u32 value);
void ov40_0222F9C0(void *p);
void ov40_0222E4C4(void *p, BOOL draw);
void ov40_0222E618(void *p, BOOL draw);
int ov40_02230404(void *p);
void ov40_0222CE7C(void *p);
void ov40_0222E09C(void *p, BOOL value);
void ov40_0222E690(void *p, BOOL value);
void ov40_0222E510(void *p, BOOL value);
BOOL ov40_0223D5CC(void *p);
BOOL ov39_02227DB8(void *p);
void ov40_0222D7DC(void *p);
void SysTask_Destroy(void *task);
void sub_02088030(void *p);
void ManagedSprite_SetPositionXY(void *sprite, int x, int y);

static inline void clear_windows(void *base, int count) {
    int i;
    for (i = 0; i < count; i++, base = (u8 *)base + 0x10) {
        ClearWindowTilemapAndCopyToVram(base);
        RemoveWindow(base);
    }
}


void ov40_02236158(void);
void ov40_02238EB8(void);
void ov40_02242E48(void);
void *ov40_0223D540(void *p);
void ov40_0222BF8C(void *p, u32 value);
void ov40_0222BF80(void *p, int value);
void ov40_0222DAA8(void *p);
void ov40_0222DD8C(void *p, u32 value);
u32 ov40_0222DD94(void *p);
void *ov40_0222FBB4(void *p);
void *ov40_0222C4DC(void *p);
void *ov40_02230958(void *p);
void ov40_02230964(void *p, void *value);
void ov40_0222FC40(void *p, u32 value);
void ov40_0222FA24(void *p);
void ov40_0222FE98(void *narc);
void ov40_0222C474(void *p);
void ov40_0222E618(void *p, BOOL draw);
void ov40_0222F734(void *p);
void ov40_0222FA18(void *p);
void *ov40_0222FE8C(void);
int ov40_02230404(void *p);
void ov40_0222D288(void *sprite, int x, int y);
void ov40_0222D294(void *sprite, int *x, int *y);
void ov40_0222F9D4(void *p, int value);
int ov40_0223A274(void);
int ov40_0223FD80(void *p);
int ov40_0224147C(void *p);
int ov40_02244054(int value, int flag);
void ov40_0222C4E8(void *p, u32 value);
MessageFormat *ov40_0222DAB0(enum HeapID heapId);
void ov40_0222E4C4(void *p, BOOL draw);
void ov40_0222FF64(void *a0, void *a1, void *sprite);
void ov40_022306E0(void *p);
void ov40_022309CC(void *p);
BOOL ov40_022371D4(u32 a, u32 mask);
void ov40_0222E7DC(void *p, BOOL draw);
void ov40_0222F720(void *p);
void ov40_0222F9C0(void *p);
int ov40_02230410(void *p);
void ov40_02230638(void *p, int value);
void ov40_02230944(void *p);
void ov40_022439B8(void *p);
void ov40_0222D874(void *p);
void ov40_0222FB28(void *p, int score);
BOOL ov40_022361C8(u16 *p);
void ov40_02237564(void *p);
void ov40_0223D5E8(void *p);
void ov40_0223D600(void *p);
void ov40_0224320C(void *p, u32 value);
int ov40_0224326C(void *p);
void ov40_0222BF64(void *p, u32 value, BOOL valid, u32 *out);
void ov40_0222BF94(void *p);
void ov40_0222CABC(void *p);
void ov40_0222E79C(void *p, BOOL value);
void ov40_0223584C(void *p);
void ov40_0223655C(void *p);
void ov40_0223CCA0(void *p);
BOOL ov40_0223D5CC(void *p);
void ov40_0222E4A4(void *p);
void ov40_02230398(void *p);
void ov40_02232FCC(void *p);
void ov40_02237C54(void *p);
void ov40_02241A34(void *p);
void ov40_0223610C(void *p);
void ov40_022393F4(void *p);
void ov40_02239514(void *p);
void ov40_02236FE0(void *p);
void ov40_02237008(void *p);
void ov40_02237C74(void *p);
void ov40_02237D6C(void *p);
void ov40_0223E848(void *p);
void ov40_0223CE38(void *p);
void ov40_02244494(void *p);
void ov40_022306A0(void *p, BOOL draw);
void ov40_0222F858(void *p, int y1, int y2);

#endif
