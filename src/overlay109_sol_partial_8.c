#include "constants/heap.h"
#include "constants/sndseq.h"
#include "constants/species.h"

#include "overlay109_sol_partial_internal.h"

void ov109_021E5A20(void);
void ov109_021E5A70(PhotoAlbumApp *app);
void ov109_021E5B40(PhotoAlbumApp *app);
BOOL ov109_021E5B60(PhotoAlbumApp *app);
BOOL ov109_021E5B98(PhotoAlbumApp *app);
int ov109_021E5BAC(PhotoAlbumApp *app);
int ov109_021E5BF4(PhotoAlbumApp *app);
extern const TouchscreenHitbox ov109_021E7A18[];
extern void PlaySE(u16 seqId);
int ov109_021E5C40(PhotoAlbumApp *app);
int ov109_021E5C48(PhotoAlbumApp *app);
int ov109_021E5C68(PhotoAlbumApp *app);
int ov109_021E5C88(PhotoAlbumApp *app);
int ov109_021E5C90(PhotoAlbumApp *app);
int ov109_021E5C98(PhotoAlbumApp *app);
int ov109_021E5CAC(PhotoAlbumApp *app);
void ov109_021E5CB4(PhotoAlbumApp *app);
void ov109_021E5CE4(PhotoAlbumApp *app);
void ov109_021E5D08(PhotoAlbumApp *app);
void ov109_021E5D5C(PhotoAlbumApp *app);
void ov109_021E5DB8(PhotoAlbumApp *app, int a, int b);
void ov109_021E5DEC(PhotoAlbumApp *app);
void ov109_021E5EC8(PhotoAlbumApp *app);
int ov109_021E5F10(PhotoAlbumApp *app);
int ov109_021E5F40(PhotoAlbumApp *app, u8 hit);
int ov109_021E5FFC(PhotoAlbumApp *app, int *a);
void ov109_021E6058(PhotoAlbumApp *app);
int ov109_021E61BC(PhotoAlbumApp *app);
int ov109_021E61DC(PhotoAlbumApp *app);
int ov109_021E628C(PhotoAlbumApp *app, u8 hit);
int ov109_021E638C(PhotoAlbumApp *app, int *a);
void ov109_021E63E8(PhotoAlbumApp *app);
int ov109_021E656C(PhotoAlbumApp *app);
int ov109_021E66C4(PhotoAlbumApp *app);
int ov109_021E681C(PhotoAlbumApp *app);
int ov109_021E682C(PhotoAlbumApp *app);
void ov109_021E685C(PhotoAlbumApp *app);
void ov109_021E6898(PhotoAlbumApp *app);
void ov109_021E68B8(PhotoAlbumApp *app, int on);
void ov109_021E68D4(PhotoAlbumApp *app);
void ov109_021E691C(PhotoAlbumApp *app, fx32 v);
void ov109_021E692C(void);
void ov109_021E694C(PhotoAlbumApp *app);
void ov109_021E6AFC(PhotoAlbumApp *app);
void ov109_021E6B5C(PhotoAlbumApp *app);
void ov109_021E6C7C(PhotoAlbumApp *app);
void ov109_021E6C9C(PhotoAlbumApp *app);
void ov109_021E6D2C(PhotoAlbumApp *app);
void ov109_021E6D84(PhotoAlbumApp *app);
void ov109_021E6DBC(PhotoAlbumApp *app);
void ov109_021E6DE4(PhotoAlbumApp *app);
void ov109_021E6E64(PhotoAlbumApp *app);
void ov109_021E6E9C(PhotoAlbumApp *app);
void ov109_021E6EC0(PhotoAlbumApp *app);
void ov109_021E6EE4(PhotoAlbumApp *app);
void ov109_021E6F60(PhotoAlbumApp *app);
void ov109_021E6F7C(PhotoAlbumApp *app);
void ov109_021E6FD4(PhotoAlbumApp *app, u8 bgId, int which, int idx);
void ov109_021E7030(PhotoAlbumApp *app);
void ov109_021E70C4(PhotoAlbumApp *app, int a, int b, u8 c);
void ov109_021E7114(PhotoAlbumApp *app);
void ov109_021E7178(PhotoAlbumApp *app);
void ov109_021E71BC(PhotoAlbumApp *app);
void ov109_021E7248(PhotoAlbumApp *app);
void ov109_021E7388(PhotoAlbumApp *app, int a);
void ov109_021E73F8(PhotoAlbumApp *app, int a, int b, int c);
void ov109_021E7474(PhotoAlbumApp *app, u8 x, u8 y, int draw);
void ov109_021E74D4(PhotoAlbumApp *app, int draw);
void ov109_021E7524(PhotoAlbumApp *app);
void ov109_021E7584(PhotoAlbumApp *app, int idx);
int ov109_021E75B4(PhotoAlbumApp *app);
void ov109_021E75C8(PhotoAlbumApp *app);
int ov109_021E7640(PhotoAlbumApp *app);
void ov109_021E76F0(PhotoAlbumApp *app);
int ov109_021E7748(PhotoAlbumApp *app);
void ov109_021E77D4(PhotoAlbumApp *app);
void ov109_021E7810(SysTask *task, PhotoAlbumTask *data);
u8 ov109_021E7850(Photo *photo);

extern void sub_02021238(PhotoAlbumApp *app);
extern void HBlankInterruptDisable(void);
extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void GF_DestroyVramTransferManager(void);
extern void thunk_ClearMainOAM(enum HeapID heapId);
extern SysTask *SysTask_CreateOnMainQueue(void (*func)(SysTask *, void *), void *data, u32 prio);
extern void SysTask_Destroy(SysTask *task);
extern void sub_020210BC(void);
extern void sub_02021148(int a);
extern const WindowTemplate ov109_021E78F4[3];
extern const GraphicsBanks ov109_021E79F0;

int ov109_021E681C(PhotoAlbumApp *app) {
    int r = ov109_021E7640(app);
    if (r < 0) {
        r = 4;
    }
    return r;
}

int ov109_021E682C(PhotoAlbumApp *app) {
    switch (app->subState) {
    case 0:
        ov109_021E76F0(app);
        ++app->subState;
        break;
    case 1:
        if (ov109_021E7748(app) != 7) {
            app->subState = 0;
            return 1;
        }
        break;
    }
    return 7;
}

void ov109_021E685C(PhotoAlbumApp *app) {
    if (app->spriteSystem != NULL) {
        SpriteSystem_TransferOam();
    }
    ov109_021E6898(app);
    ov109_021E68D4(app);
    NNS_GfdDoVramTransfer();
    DoScheduledBgGpuUpdates(app->bgConfig);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

void ov109_021E6898(PhotoAlbumApp *app) {
    if (app->bgToggleReq) {
        ToggleBgLayer(GF_BG_LYR_MAIN_2, app->bgToggleVal);
    }
    app->bgToggleReq = FALSE;
}

void ov109_021E68B8(PhotoAlbumApp *app, int on) {
    app->bgToggleVal = on;
    app->bgToggleReq = TRUE;
}

void ov109_021E68D4(PhotoAlbumApp *app) {
    MtxFx22 mtx;
    if (app->unk_18_1) {
        mtx._01 = 0;
        mtx._10 = 0;
        mtx._11 = FX_Inv(FX32_ONE);
        mtx._00 = FX_Inv(app->zoom);
        SetBgAffine(app->bgConfig, GF_BG_LYR_MAIN_2, &mtx, 0x80, 0x78);
        app->unk_18_1 = FALSE;
    }
}

void ov109_021E691C(PhotoAlbumApp *app, fx32 v) {
    app->zoom = v;
    app->unk_18_1 = TRUE;
}

void ov109_021E692C(void) {
    GraphicsBanks banks = ov109_021E79F0;
    GfGfx_SetBanks(&banks);
}
