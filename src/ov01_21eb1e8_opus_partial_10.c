#include "ov01_21eb1e8_opus_partial_internal.h"

void ov01_021EB1E8(void *textureManager);
void *WeatherManager_New(void *fieldSystem);
void WeatherManager_Delete(void *weatherManager);
void WeatherManager_SetWeather(void *weatherManager, int a1);
BOOL WeatherManager_ChangeWeather(void *weatherManager, int weatherType);
u32 ov01_021EB31C(WeatherManager *mgr);
int ov01_021EB4B4(int a0, int a1);
void ov01_021EB56C(void *a0, WeatherSys *sys);
void ov01_021EB578(void *a0, int a1, int a2);
WeatherSys *ov01_021EB64C(void *fieldSystem);
u16 ov01_021EB804(WeatherSys *sys, int idx);
void ov01_021EB818(int a0, int a1);
void ov01_021EB830(WeatherLerp *p, int from, int to, int dur);
BOOL ov01_021EB840(WeatherLerp *p);
void ov01_021EB86C(WeatherSys *sys, u16 a1, WeatherGfx *gfx);
void ov01_021EB968(void *a0, u16 a1, void **gfx);
BOOL ov01_021EBA08(WeatherSys *sys, int idx);
void ov01_021EBB40(WeatherSys *sys, int idx, u16 a2);
void ov01_021EBB68(WeatherSys *sys, int idx);
void ov01_021EBD18(WeatherSys *a0, u16 a1);
BOOL ov01_021EBD34(WeatherSys *sys, WeatherRec *rec);
BOOL ov01_021EBEB8(WeatherRec *rec);
void ov01_021EBEF0(WeatherSys *sys, u16 a1, WeatherGfx *gfx);
void ov01_021EBF24(WeatherSys *sys, u16 a1, WeatherGfx *gfx);
void ov01_021EBF58(WeatherSys *sys, u16 a1, WeatherGfx *gfx);
void ov01_021EBF94(WeatherSys *sys, u16 a1, WeatherGfx *gfx);
void ov01_021EC028(WeatherSpriteMgr *mgr);
void ov01_021EC058(WeatherSpriteMgr *mgr);
void ov01_021EC1BC(WeatherSpriteWork *w, int n);
void ov01_021EC1E4(WeatherSpriteWork *w);
void ov01_021EC29C(WeatherSpriteWork *w);
void ov01_021EC2CC(WeatherSpriteWork *head);
void ov01_021EC2E4(WeatherSpriteWork *head, void (*fn)(WeatherSpriteWork *));
void ov01_021EC300(void);
void ov01_021EC304(VecFx32 *dst, WeatherSpriteWork *w);
void ov01_021EB5A4(WeatherGfxMgr *m);
void ov01_021EBFD0(WeatherSys *sys, WeatherRec *rec);
WeatherSpriteWork *ov01_021EC1F4(WeatherSpriteMgr *mgr, int n);
void ov01_021EC470(void *a0, s32 *px, s32 *py);
void ov01_021EDA50(int a0, void *p);
void ov01_021EC504(WeatherEmit *p, u32 a1, int a2, int a3, int a4, int a5, int a6, int a7, u32 a8, u32 a9);
void ov01_021EC52C(WeatherEmit *p, int a1, int a2, int a3, u32 a4);
BOOL ov01_021EC650(void *a0, void *a1, int mode);
void ov01_021EC678(void *a0, int a1, int a2, int a3);
void ov01_021EC774(WeatherAnim *p);
void ov01_021EC790(WeatherAnim *p, int a1, int a2);
BOOL ov01_021EC7AC(WeatherAnim *p);
void ov01_021EC7C8(WeatherAnim *p);
WeatherSpriteWork *ov01_021EC8D8(WeatherSpriteMgr *mgr);
void ov01_021ED44C(WeatherSpriteWork *w);
void ov01_021EDA7C(void *task, void *p);
void ov01_021EDAB4(void *p, int seqNo);
void ov01_021EDAE0(void *p);

extern const u32 ov01_0220673C[4];

extern const u32 ov01_0220674C[4];

extern const u32 ov01_0220675C[9][3];

extern WeatherRec ov01_022098B0[14];

BOOL ov01_021EBEB8(WeatherRec *rec) {
    if (rec->unk00 != 0xFFFF) {
        if (rec->unk0C != NULL) {
            return TRUE;
        }
        rec->unk0C = Heap_Alloc(4, 0x64);
        if (rec->unk0C == NULL) {
            return FALSE;
        }
        memset(rec->unk0C, 0, 0x64);
    }
    return TRUE;
}

void ov01_021EBEF0(WeatherSys *sys, u16 a1, WeatherGfx *gfx) {
    if (a1 != 0xFFFF) {
        gfx->unk08 = ov01_021EB898(sys->unk18, 2, a1, sys->unk10, sys->narc, 0);
    }
}

void ov01_021EBF24(WeatherSys *sys, u16 a1, WeatherGfx *gfx) {
    if (a1 != 0xFFFF) {
        gfx->unk0C = ov01_021EB898(sys->unk18, 3, a1, sys->unk14, sys->narc, 0);
    }
}

void ov01_021EBF58(WeatherSys *sys, u16 a1, WeatherGfx *gfx) {
    if (a1 != 0xFFFF) {
        gfx->unk00 = ov01_021EB898(sys->unk18, 0, a1, sys->unk08, sys->narc, 1);
        SpriteTransfer_CreateCharTransferTask_AllocAtEnd(gfx->unk00);
        sub_0200A740(gfx->unk00);
    }
}

void ov01_021EBF94(WeatherSys *sys, u16 a1, WeatherGfx *gfx) {
    if (a1 != 0xFFFF) {
        gfx->unk04 = ov01_021EB898(sys->unk18, 1, a1, sys->unk0C, sys->narc, 1);
        SpriteTransfer_CreatePlttTransferTask(gfx->unk04);
        sub_0200A740(gfx->unk04);
    }
}

void ov01_021EBFD0(WeatherSys *sys, WeatherRec *rec) {
    if (rec->unk00 != 0xFFFF) {
        ov01_021EC240((u8 *)rec->unk0C + 0x40, sys, rec->unk0C, 0, 1);
        memset((u8 *)rec->unk0C + 0x10, 0, 0x30);
        *(void **)((u8 *)rec->unk0C + 0x10) = sys->unkFC;
        *(void **)((u8 *)rec->unk0C + 0x14) = (u8 *)rec->unk0C + 0x40;
        *(s32 *)((u8 *)rec->unk0C + 0x24) = 0x1000;
        *(s32 *)((u8 *)rec->unk0C + 0x28) = 0x1000;
        *(s32 *)((u8 *)rec->unk0C + 0x2C) = 0x1000;
        *(s32 *)((u8 *)rec->unk0C + 0x38) = 1;
    }
}

void ov01_021EC028(WeatherSpriteMgr *mgr) {
    int i;
    for (i = 0; i < 0x40; i++) {
        mgr->works[i].sprite = Sprite_CreateAffine(mgr->unk08 + 0x10);
        Sprite_SetDrawFlag(mgr->works[i].sprite, FALSE);
        if (mgr->works[i].sprite == NULL) {
            GF_AssertFail();
        }
    }
}

void ov01_021EC058(WeatherSpriteMgr *mgr) {
    int i;
    for (i = 0; i < 0x40; i++) {
        if (mgr->works[i].sprite != NULL) {
            Sprite_Delete(mgr->works[i].sprite);
            mgr->works[i].sprite = NULL;
        }
    }
}
