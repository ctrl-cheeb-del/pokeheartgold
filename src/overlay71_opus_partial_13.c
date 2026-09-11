#include "overlay71_opus_partial_internal.h"

extern u32 GetBoxMonData(void *boxmon, int field, void *dest);
extern u32 GetMonBaseStat_HandleAlternateForm(u32 species, u32 form, u32 stat);
extern void SpriteList_RenderAndAnimateSprites(void *list);
extern void OamManager_ApplyAndResetBuffers(void);
extern void *SysTask_GetData(void *task);
extern void SysTask_Destroy(void *task);
extern void GF_AssertFail(void);
extern void Heap_Free(void *ptr);
extern void *Heap_Alloc(u32 heapId, u32 size);
extern u32 Options_GetFrame(void *options);
extern void Camera_GetLookAtCamPos(Ov71Vec3 *dst, void *camera);
extern void Camera_SetAnglePos(void *arg0, void *camera);
extern void Camera_AdjustAngleTarget(void *arg0, void *camera);
extern void Camera_ApplyPerspectiveType(void *arg0, void *camera);
extern void Camera_SetPerspectiveAngle(void *arg0, void *camera);
extern void Camera_UnsetStaticPtr(void);
extern void Camera_Delete(void *camera);
extern void Sprite_SetAnimCtrlSeq(void *sprite, int seq);
extern void Sprite_SetDrawFlag(void *sprite, int flag);
extern void Sprite_Delete(void *sprite);
extern void G3X_Reset(void);
extern void RequestSwap3DBuffers(int a, int b);
extern void Main_SetVBlankIntrCB(void *cb, void *arg);

extern void ov71_022479C8(Ov71Sub2 *w);
extern void ov71_022474CC(void *arg);

extern s32 _0224C040;
extern void *ov71_0224C044[0x20];
extern u32 ov71_0224C0C4;
extern u32 ov71_0224C0C8[2];
extern u32 ov71_0224C0D0[4];
extern u32 _0224C020[8];

BOOL ov71_02246B28(void *boxmon);
void ov71_02246C48(void *unused, Ov71Sprs *sprs);
void ov71_02246D40(Ov71Sys *sys);
void ov71_02246E84(Ov71Sys *sys, int clear, int set, u16 value);
void ov71_02246F60(Ov71Sys *sys, int index);

void ov71_022472FC(Ov71Pair *pair);
void ov71_02247320(Ov71Ctx *ctx, Ov71Src *src, Ov71Opt *opt, void *a3, u8 a4);
void *ov71_02247384(Ov71Ctx *ctx);
void *ov71_02247388(Ov71Ctx *ctx);
void *ov71_0224738C(Ov71Ctx *ctx);
u32 ov71_02247390(Ov71Ctx *ctx);
u32 ov71_02247398(Ov71Ctx *ctx);
u32 ov71_022473A0(Ov71Ctx *ctx);
u16 ov71_022473A8(Ov71Big *w);
u16 ov71_022473B0(Ov71Big *w);
u16 ov71_022473BC(Ov71Big *w);
u16 ov71_022473C4(Ov71Big *w);
u32 ov71_022473D0(Ov71Ctx *ctx);
u32 ov71_022473DC(Ov71Ctx *ctx);
void ov71_022473E4(void);
void ov71_022473F0(void);
void ov71_02247424(void *ptr);
void ov71_022475F8(Ov71Cam *cam);
void ov71_022476B4(Ov71Cam *cam, Ov71Vec3 *dst);
void ov71_022476C4(Ov71Cam *cam, const Ov71Vec3 *src);
void ov71_022476D4(Ov71Cam *cam, Ov71S16Vec3 *dst);
void ov71_022476EC(Ov71Cam *cam, const Ov71S16Vec3 *src);
void ov71_02247704(Ov71Cam *cam, void *value);
void ov71_02247730(Ov71Cam2 *cam, u32 value);
void ov71_022477EC(Ov71Cam *cam, Ov71Vec3 *dst);
void ov71_0224780C(Ov71Cam *cam, void *arg0);
void ov71_0224781C(Ov71Cam *cam, void *arg0);
void ov71_0224782C(Ov71Cam *cam, void *arg0);
void ov71_0224783C(Ov71Cam *cam, void *arg0);
void ov71_022478B8(Ov71Cam *cam);
void ov71_02247498(Ov71CamSet *set);
BOOL ov71_02247990(Ov71Sub2 *w, u32 *state);
BOOL ov71_022483AC(Ov71D4 *w, u32 *state);
extern void *ov71_0224BC64[4];
extern void *ov71_0224BCFC[4];
void ov71_0224809C(Ov71Sprs *sprs);
BOOL ov71_02248110(Ov71Cam2 *cam);
void ov71_02248120(Ov71Cam2 *cam);
BOOL ov71_022481C8(Ov71Cam2 *cam);
u32 ov71_022481D8(Ov71Cam2 *cam);
void ov71_022481EC(Ov71Cam2 *cam);
void ov71_02248B54(Ov71Flag *w);
void ov71_02248CF4(void *task);
void ov71_02248E04(void *task);
void *ov71_02249254(void *task);
void *ov71_02249260(void *task);

extern BOOL IsPaletteFadeFinished(void);
extern void FreeBgTilemapBuffer(void *bgConfig, u32 layer);
extern void BeginNormalPaletteFade(u32 a, u32 b, u32 c, u16 d, u16 e, u8 f, u32 g);
extern void ov71_0224A080(Ov71Sub2 *w);
extern BOOL ov71_02249E6C(Ov71Sub2 *w);
extern BOOL ov71_0224AB7C(Ov71Sub2 *w);
extern BOOL ov71_0224ADE4(Ov71Sub2 *w);
extern void *ov71_0224BDE8[2];
extern void *ov71_0224BE7C[2];

void ov71_02247708(Ov71Cam *cam, u32 value);
BOOL ov71_02247C34(Ov71Spr *w, const u32 *state);
void ov71_022483E4(Ov71D4 *w);
void ov71_022489F8(Ov71D4 *w);
void ov71_02248B24(Ov71Grid2 *grid);
Ov71Scene *ov71_022494A0(Ov71Ctx *ctx);
void ov71_022494D0(Ov71Scene *sc);
void ov71_02249538(Ov71Scene *sc);
void ov71_022497C8(Ov71Scene *sc);
void ov71_022498E0(Ov71Scene *sc);
void ov71_02249970(Ov71Scene *sc);
void ov71_02249988(Ov71Sub2 *w);
void ov71_02249990(Ov71Sub2 *w);
BOOL ov71_02249A50(Ov71Sub2 *w);
void ov71_02249C90(Ov71Sub2 *w);
Ov71Sub2 *ov71_02249CF0(Ov71Ctx *ctx);
void ov71_02249D14(Ov71Sub2 *w);
BOOL ov71_02249D28(Ov71Sub2 *w, u32 *state);
BOOL ov71_02249D58(Ov71Sub2 *w);
void ov71_0224A12C(Ov71Scene *sc);
BOOL ov71_0224A15C(Ov71Sub2 *w, u32 *state);
void ov71_0224A3D8(Ov71Scene *sc);
void ov71_0224A500(Ov71Scene *sc);
void ov71_0224A590(Ov71Scene *sc);
void ov71_0224A5A8(Ov71Sub2 *w);
void ov71_0224A5B0(Ov71Sub2 *w);
BOOL ov71_0224A684(Ov71Sub2 *w);
void ov71_0224A8A8(Ov71Sub2 *w);
BOOL ov71_0224A9F8(Ov71Sub2 *w);
void ov71_0224AEF4(Ov71Scene *sc);
void ov71_0224AFB8(void *task);
void ov71_0224B068(void *task);
void ov71_0224B11C(void *task);

/* ---- round-2 batch 1 ---- */
extern BOOL IsFanfarePlaying(void);
extern BOOL IsPaletteFadeFinished(void);
extern int _s32_div_f(int lhs, int rhs);
extern void ov71_02246D54(void *arg);

BOOL ov71_0224B960(Ov71Task2 *w);
void ov71_0224B970(Ov71Task2 *w);
void ov71_0224B990(void *task, Ov71Bright *w);
void ov71_0224BA48(void *task);
void ov71_0224BAA0(Ov71Scroll *w, s32 target, s32 frames);
void ov71_0224B8EC(Ov71SprPair *w);
BOOL ov71_0224B450(Ov71SprPair *w, void **pending);
BOOL ov71_0224B6F0(Ov71Fanfare *w, s32 limit);
Ov71Cell *ov71_0224A920(Ov71Ctx *ctx);
void ov71_0224ADB0(Ov71Bgs *w);
void ov71_0224B0E8(void *task, Ov71Slide *w);

/* ---- round-2 batch 2 ---- */
extern void BgSetPosTextAndCommit(void *bgConfig, u32 layer, u32 op, u32 value);
extern void *ov71_0224BEF0[3];
extern void *ov71_0224BD7C[2];
extern void ov71_0224A9C4(Ov71Cell *w);
extern void ov71_02249538(Ov71Scene *w);

void ov71_0224A954(Ov71Cell *w);
BOOL ov71_0224A98C(Ov71Cell *w, u32 *state);
BOOL ov71_02249500(Ov71Scene *w, u32 *state);
void ov71_0224A0B8(void *bgConfig, u32 y, u32 x);

BOOL ov71_02247C34(Ov71Spr *w, const u32 *state) {
    if (*state == 0 && IsPaletteFadeFinished()) {
        Sprite_SetAnimCtrlSeq(w->unk_3C, 1);
        Sprite_SetDrawFlag(w->unk_3C, 1);
        return TRUE;
    }
    return FALSE;
}
