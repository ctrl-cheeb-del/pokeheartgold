#define PlayerAvatar_SetRunningShoesLock PlayerAvatar_SetRunningShoesLock_u16
#include "r45_overlay28_private.h"
#undef PlayerAvatar_SetRunningShoesLock

void PlayerAvatar_SetRunningShoesLock(PlayerAvatar *avatar, u32 lock);

void ov28_0225DA74(DowsingMchn *ptr);
void ov28_0225DB8C(DowsingMchn *ptr, NARC *narc);

SysTask *ov28_0225D520(BgConfig *bgConfig, void *a1, FieldSystem *fieldSystem, void *a3);
void ov28_0225D650(BgConfig *bgConfig);
void ov28_0225D7E0(DowsingMchn *ptr);
void ov28_0225DC2C(SysTask *task, void *data);
int ov01_021E7F54(FieldSystem *fieldSystem);
int ov01_021F6BD0(int a);
int ov01_021F6BB0(int a);
void ov28_0225D5EC(void *unused, SysTask *task);
BOOL ov28_0225D624(void);
void ov28_0225D628(void);
void ov28_0225D6E0(BgConfig *bgConfig);
void ov28_0225D6FC(DowsingMchn *ptr, NARC *narc);
void ov28_0225D764(DowsingMchn *ptr);
void ov28_0225D7C4(DowsingMchn *ptr);
void ov28_0225D878(DowsingMchn *ptr);
void ov28_0225D898(DowsingMchn *ptr, NARC *narc);
void ov28_0225D8D0(DowsingMchn *ptr);
void ov28_0225D8EC(DowsingMchn *ptr);
void ov28_0225D910(DowsingMchn *ptr);
void ov28_0225DB54(DowsingMchn *ptr);
void ov28_0225DB8C(DowsingMchn *ptr, NARC *narc);
void ov28_0225DBFC(DowsingMchn *ptr);
void DowsingMchn_GetHiddenItemLocs(DowsingMchn *ptr);
void DowsingMchn_FreeHiddenItemLocs(DowsingMchn *ptr);
void ov28_0225DE04(fx32 *ptr, int deg);
u16 ov28_0225DE64(int x, int y);
u16 ov28_0225DE78(int x, int y);
u16 ov28_0225DE88(int a);
void ov28_0225DE98(DowsingMchnAngle *ptr);
void ov28_0225DEB0(DowsingMchn *ptr);
void ov28_0225DF14(DowsingMchn *ptr);
void ov28_0225DFBC(DowsingMchn *ptr);
void ov28_0225E060(DowsingMchn *ptr);
void ov28_0225E0DC(DowsingMchnAngle *ptr);
void ov28_0225E424(Sprite *sprite, int deg);
BOOL ov28_0225E7D4(DowsingMchn *ptr);
BOOL ov28_0225E8B8(const TouchscreenHitbox *hitbox, Sprite *sprite, int idleAnim, int pressedAnim);
BOOL ov28_0225EA58(DowsingMchn *ptr);
BOOL FieldSystem_TaskIsRunning(FieldSystem *fieldSystem);
u8 ov28_0225E51C(DowsingMchn *ptr, int x, int y);
void ov28_0225E810(DowsingMchn *ptr);
void ov28_0225E900(DowsingMchn *ptr);
void ov28_0225E938(DowsingMchn *ptr);
void ov28_0225E9E0(DowsingMchn *ptr);

extern const u8 ov28_0225EA91[];
extern const u8 ov28_0225EB7C[];
extern const TouchscreenHitbox _0225EA7C;
extern const TouchscreenHitbox ov28_0225EA80;
extern const TouchscreenHitbox ov28_0225EA84;

void ov28_0225DF04(DowsingMchnAngle *ptr);
void ov28_0225DFA4(DowsingMchnAngle *ptr);
void ov28_0225E054(DowsingMchnAngle *ptr);

/* callees not written here */
void ov28_0225D8EC(DowsingMchn *ptr);
void ov28_0225DA74(DowsingMchn *ptr);

void ov28_0225D878(DowsingMchn *ptr) {
    u32 i;
    for (i = 0; i < 5; i++) {
        RemoveWindow(&ptr->windows[i]);
    }
    FontID_Release(4);
}

void ov28_0225D898(DowsingMchn *ptr, NARC *narc) {
    ptr->spriteList = G2dRenderer_Init(HEAP_ID_8, (G2dRenderer *)&ptr->renderer, HEAP_ID_8);
    G2dRenderer_SetSubSurfaceCoords((G2dRenderer *)&ptr->renderer, 0, 0x100000);
    ov28_0225D8EC(ptr);
    ov28_0225DA74(ptr);
    ov28_0225DB8C(ptr, narc);
}

void ov28_0225D8D0(DowsingMchn *ptr) {
    ov28_0225DBFC(ptr);
    ov28_0225DB54(ptr);
    ov28_0225D910(ptr);
    SpriteList_Delete(ptr->spriteList);
}

void ov28_0225D8EC(DowsingMchn *ptr) {
    u32 i;
    for (i = 0; i < 4; i++) {
        ptr->resMans[i] = Create2DGfxResObjMan(2, (GfGfxResType)i, HEAP_ID_8);
    }
}

void ov28_0225D910(DowsingMchn *ptr) {
    u32 i;
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(ptr->resMans[i]);
    }
}
