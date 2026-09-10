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

void ov69_021E6F48(void *data) {
    Heap_Free(*(void **)((u8 *)data + 0xC2A0));
    Heap_Free(*(void **)((u8 *)data + 0xC29C));
    Heap_Free(*(void **)((u8 *)data + 0xC2A8));
    Heap_Free(*(void **)((u8 *)data + 0xC2A4));
    Heap_Free(*(void **)((u8 *)data + 0xC0DC));
}

void ov69_021E6F8C(Ov69Camera *data) {
    data->camera[0] = 0;
    data->camera[1] = 0;
    data->camera[2] = 0;
    data->camera[3] = 0x1000;
    data->camera[4] = 0x1000;
    data->camera[5] = 0x1000;
    data->camera[6] = 0x1A40;
    data->camera[7] = 0x7C00;
    data->camera[8] = 0;
    data->camera[9] = 0x1000;
    data->camera[10] = 0x1000;
    data->camera[11] = 0x1000;
}
