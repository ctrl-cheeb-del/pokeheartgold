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

WeatherSys *ov01_021EB64C(void *fieldSystem) {
    WeatherSys *sys = Heap_Alloc(4, sizeof(WeatherSys));
    sys->fieldSystem = fieldSystem;
    ov01_021EB4B8(&sys->unk08);
    sys->recs = ov01_022098B0;
    sys->sfx = ov01_0220675C;
    sys->narc = NARC_New(0x3F, 4);
    return sys;
}
