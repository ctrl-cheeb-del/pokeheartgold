#ifndef TO45_OV40_PC_MODE_LAST_PRIVATE_H
#define TO45_OV40_PC_MODE_LAST_PRIVATE_H

#include <nitro/fs/overlay.h>

#include "global.h"

#define PTR(p, off) (*(void **)((u8 *)(p) + (off)))
#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define S32(p, off) (*(s32 *)((u8 *)(p) + (off)))

int ov40_02234D94(void *);
int ov40_02234F98(void *);
int ov40_02234A38(void *);
void ov40_022307DC(void *, int, int);
void GfGfx_EngineATogglePlanes(int, int);
void GfGfx_EngineBTogglePlanes(int, int);
typedef void (*HitboxCallback)(u32, int, void *);
void *TouchHitboxController_Create(const void *, int, HitboxCallback, void *, int);
int TouchHitboxController_IsTriggered(void *);
void TouchHitboxController_Destroy(void *);
void ov40_02235FFC(void *);
BOOL TouchscreenHitbox_TouchNewIsIn(const void *);
void ov40_02230944(void *);
void ov40_0223610C(void);
void ov40_02235FD0(u32, int, void *);
extern const u8 ov40_02245708[];
extern const u8 ov40_022451C4[];
void SetBgPriority(int, int);
void Heap_Free(void *);
void sub_020314BC(void *);
void BgClearTilemapBufferAndCommit(void *, int);
int ov40_0222DA84(void *, int);
int ov40_0222DA00(void *, void *, int, int);
void ov40_02230964(void *, int);
void ov40_02235B10(void *);
void PaletteData_BlendPalettes(void *, int, int, int, int);
void ov40_0222DAA8(void *);
void ov40_0222D88C(void *);
void ov40_0222FB90(void *, int);
int ov40_0222FBB4(void *);
void ov41_0224B57C(void);
void ov40_0222BC54(void *);
void ov40_02235994(void);
void ov40_0222DD08(void *);
void ov40_0222BF64(void *, int, int, void *);
void UnloadOverlayByID(int);
void Main_SetVBlankIntrCB(void (*)(void *), void *);
void ov40_0222BD04(void *);
extern u8 SDK_OVERLAY_OVY_41_ID[];
int ov40_0223D5CC(void *);
void ov40_0223077C(void *, void *, int, int);
void sub_020879E0(void *, int);
void sub_02087A08(void *, int, int);
void ov40_0222DED0(void *, int);
void PlaySE(int);
void *ov40_0223D540(void *);
int ov39_022273F8(void *, void *);
void ov40_0222DFB0(void *);
int ov39_02227D44(void *, void **);
void StopSE(int, int);
void ov40_02230CDC(void *, int, void *, void *);
void ov40_0222BF80(void *, int);
BOOL System_GetTouchNew(void);

#endif
