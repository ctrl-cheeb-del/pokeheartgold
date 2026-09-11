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

BOOL ov01_021EC728(WeatherFade *p) {
    BOOL ret = ov01_021EB840(&p->l1);
    ov01_021EB840(&p->l2);
    ov01_021EB840(&p->l3);
    ov01_021EB840(&p->l4);
    ov01_021EB840(&p->l5);
    ov01_021EC678(p->unk00, p->l5.cur, p->l1.cur, (u16)(p->l2.cur | (p->l3.cur << 5) | (p->l4.cur << 10)));
    return ret;
}

void ov01_021EC774(WeatherAnim *p) {
    int i;
    for (i = 0; i < 0x20; i++) {
        p->unk04[i] = 0;
    }
    ov01_021EA8C4(p->unk00, p->unk04);
}

void ov01_021EC790(WeatherAnim *p, int a1, int a2) {
    p->unk24 = 0x7F;
    p->unk28 = 0;
    p->unk2C = a1;
    if (a2 == 1) {
        p->unk2E = 1;
    } else {
        p->unk2E = -1;
    }
}

BOOL ov01_021EC7AC(WeatherAnim *p) {
    BOOL ret = ov01_021EC7E8(p);
    if (p->unk28 == 0) {
        ov01_021EA8C4(p->unk00, p->unk04);
    }
    return ret;
}

void ov01_021EC7C8(WeatherAnim *p) {
    p->unk24 = 1;
    p->unk28 = 0;
    p->unk2C = 0;
    p->unk2E = 1;
    ov01_021EC828(p);
    ov01_021EA8C4(p->unk00, p->unk04);
}

BOOL ov01_021EC7E8(WeatherAnim *p) {
    BOOL ret = FALSE;
    if (p->unk2E == 0) {
        ret = TRUE;
    } else if (p->unk24 <= 0) {
        ret = TRUE;
    } else {
        s32 v = p->unk28 + 1;
        p->unk28 = v;
        if (v >= p->unk2C) {
            p->unk28 = 0;
            ov01_021EC828(p);
            p->unk24 = p->unk24 - 1;
            if (p->unk24 <= 0) {
                ret = TRUE;
            }
        }
    }
    return ret;
}

void ov01_021EC828(WeatherAnim *p) {
    s32 v;
    s32 i;
    s32 lo;
    if (p->unk2E < 0) {
        v = 0x7F - p->unk24;
    } else {
        v = p->unk24;
    }
    lo = v / 4;
    for (i = 0x1F; i > lo; i--) {
        p->unk04[i] = (u8)((i - lo) << 2);
    }
}
