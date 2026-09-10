#include "global.h"
typedef struct {
    u8 raw[0x1000];
} State;
extern const u32 ov64_021E6FAC[];
extern const u8 ov64_021E6F6C[];
extern const u8 ov64_021E7008[];
extern const u8 ov64_021E6EA8[];
extern void DoScheduledBgGpuUpdates(void *);
extern void SpriteSystem_TransferOam(void);
extern void GX_LoadOBJ(const void *, u32, u32);
extern void GXS_LoadOBJ(const void *, u32, u32);
extern void GX_LoadOBJPltt(const void *, u32, u32);
extern void GfGfx_SetBanks(const void *);
extern void Sprite_DeleteAndFreeResources(void *);
extern void FreeBgTilemapBuffer(void *, int);
extern void Heap_Free(void *);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
extern void DestroyMsgData(void *);
extern void *OverlayManager_GetData(void *);
extern void Main_SetVBlankIntrCB(void *, void *);
extern void ov64_021E6118(State *);
extern void NARC_Delete(void *);
extern void sub_02021238(void);
extern void OverlayManager_FreeData(void *);
extern void Heap_Destroy(int);
extern void SpriteSystem_FreeResourcesAndManager(void *, void *);
extern void SpriteSystem_Free(void *);
extern void ManagedSprite_TickFrame(void *);
extern void RemoveWindow(void *);
extern void *GridInputHandler_Create(const void *, const void *, const void *, void *, int, int, int);
extern void FontID_Release(int);
extern void GridInputHandler_Free(void *);
extern void ov64_021E6BD8(State *, int);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern void SpriteManager_UnloadCharObjById(void *, int);
extern void ManagedSprite_SetDrawFlag(void *, int);
extern void BgFillTilemapBufferAndSchedule(void *, int, int);
extern void *GridInputHandler_GetDpadBox(void *);
extern int SpeciesToOverworldModelIndexOffset(int);
extern int OverworldModelLookupHasFemaleForm(int);
extern int OverworldModelLookupFormCount(int);
extern void ManagedSprite_SetPositionXY(void *, int, int);
extern void ManagedSprite_SetAnimationFrame(void *, int);
extern void ManagedSprite_SetAnim(void *, int);
int HallOfFameShowcase_Exit(void *);
void ov64_021E5A88(State *);
void ov64_021E5CA4(State *);
void ov64_021E6118(State *);
void ov64_021E5AAC(const void *, u32, u32);
void ov64_021E5AC8(const void *, u32, u32);
void ov64_021E5AE4(const void *, u32, u32);
void ov64_021E5B00(void);
void ov64_021E6010(State *, u32);
void ov64_021E602C(State *);
void ov64_021E605C(State *);
void ov64_021E620C(void *);
void ov64_021E622C(State *);
void ov64_021E6260(State *);
void ov64_021E6270(void);
void ov64_021E6274(void);
void ov64_021E6278(State *, int);
void ov64_021E6280(State *, int);
int ov64_021E6E30(int, int, int);
void ov64_021E6288(void);
void ov64_021E62A8(void);
void ov64_021E64F8(State *);
void ov64_021E6754(State *);
void ov64_021E6BD8(State *, int);

int ov64_021E6E30(int species, int form, int female) {
    int ret;
    if (species <= 0 || species > 493) {
        ret = 1;
    } else {
        ret = SpeciesToOverworldModelIndexOffset(species) + 0x129;
        if (OverworldModelLookupHasFemaleForm(species)) {
            if (female == 1) {
                ret++;
            }
        } else {
            if (form > OverworldModelLookupFormCount(species)) {
                form = 0;
            }
            ret += form;
        }
    }
    return ret;
}
