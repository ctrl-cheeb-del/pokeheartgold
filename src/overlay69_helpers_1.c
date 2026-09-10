#include "global.h"

#include "overlay_manager.h"
#include "system.h"

typedef struct {
    u32 x;
    u32 y;
} Ov69Point;
typedef struct {
    u8 pad_0000[0xC010];
    void *bgConfig;
    u8 window14[0x10];
    u8 window24[0x10];
    u8 window34[0x10];
    u8 window44[0x10];
    u8 window54[0x10];
    void *listMenu;
    void *listMenuItems;
} Ov69Ui;
typedef struct {
    u8 pad_0000[0xC2AC];
    s32 camera[12];
} Ov69Camera;
typedef struct {
    u8 pad_0000[0xC2EC];
    s32 light[3];
} Ov69Light;
typedef struct {
    enum HeapID heapId;
    u8 pad_0004[0xC00C];
    void *bgConfig;
    u8 pad_C014[0x6C];
    void *messageFormat;
    u8 pad_C084[0x258];
    void *camera;
} Ov69ExitData;

extern int LocationGmmDatIndexGetByCountryMsgNo(int country);
extern void PlaySE(u16 seqNo);
extern void sub_0200E5D4(void *window, int fillValue);
extern void RemoveWindow(void *window);
extern void Heap_Free(void *ptr);
extern void DestroyListMenu(void *menu, int *selection, int *cursor);
extern void ListMenuItems_Delete(void *items);
extern void FreeBgTilemapBuffer(void *bgConfig, int bgId);
extern int GF_DegreeToSinCosIdxNoWrap(int degree);
extern u32 FX_Sqrt(u32 value);
extern void *OverlayManager_GetData(OverlayManager *man);
extern void GfGfx_EngineATogglePlanes(int mask, BOOL enable);
extern void GfGfx_EngineBTogglePlanes(int mask, BOOL enable);
extern void Camera_Delete(void *camera);
extern void MessageFormat_Delete(void *fmt);
extern void GF3dRender_DeleteSimpleManager(void);
extern void OverlayManager_FreeData(OverlayManager *man);

int ov69_021E6300(int country);
void ov69_021E68D8(int unused0, int unused1, int flag);
BOOL ov69_021E758C(int country);
void ov69_021E6C14(Ov69Ui *data);
void ov69_021E6F48(void *data);
void ov69_021E6A54(Ov69Ui *data);
void ov69_021E67B8(Ov69Ui *data);
int ov69_021E75F8(const Ov69Point *a, const Ov69Point *b);
void ov69_021E6F8C(Ov69Camera *data);
void ov69_021E706C(Ov69Light *data);
BOOL GeonetGlobe_Exit(OverlayManager *man, int *state);

BOOL GeonetGlobe_Exit(OverlayManager *man, int *state) {
    Ov69ExitData *data = OverlayManager_GetData(man);
    enum HeapID heapId = data->heapId;
    GfGfx_EngineATogglePlanes(4, FALSE);
    GfGfx_EngineBTogglePlanes(4, FALSE);
    GfGfx_EngineATogglePlanes(8, FALSE);
    GfGfx_EngineBTogglePlanes(8, FALSE);
    Camera_Delete(data->camera);
    MessageFormat_Delete(data->messageFormat);
    GF3dRender_DeleteSimpleManager();
    Heap_Free(data->bgConfig);
    Main_SetVBlankIntrCB(NULL, NULL);
    OverlayManager_FreeData(man);
    Heap_Destroy(heapId);
    gSystem.screensFlipped = FALSE;
    return TRUE;
}
