#include "overlay70_pokegear_map_ui_private.h"

#define OV70_STATE (*(u32 *)_02246800)
#define OV70_ERR   (*(s32 *)(_02246800 + 4))

#define OV70_FAIL()    \
    OV70_STATE = 0x18; \
    OV70_ERR = -13;    \
    ov38_0221BFEC()

void ov70_02237F64(void *a);
void ov70_02237FB4(void);
void ov70_02238008(void *b);
void ov70_02238058(void *b);
void ov70_022380A8(void);
void ov70_022380EC(void);
void ov70_02238130(void *src, int n, void *c);
void ov70_022381A4(void *src, void *c);
void ov70_02238208(void *a, void *b, void *c);
void ov70_0223826C(void);
void ov70_022382C0(void);
void ov70_02238304(void *a, void *b);
int ov70_02238360(void *a, void *b, int c, void *d, int e);
int ov70_02238398(int x);
int ov70_02238430(void *ovy, u32 *state);
int ov70_022385C0(void *ovy, u32 *state);
void ov70_022387AC(u8 *work);
void ov70_022387F8(void);
void ov70_02238818(u8 *work, void *ovy);

int ov70_022386F4(void *ovy) {
    u8 *work = OverlayManager_GetData(ovy);

    Heap_Free(*(void **)(work + 0x4c));
    UnloadOVY38();
    UnloadDwcOverlay();
    ov70_02238E98(work);
    DestroyMsgData(*(void **)(work + 0xba4));
    DestroyMsgData(*(void **)(work + 0xbac));
    DestroyMsgData(*(void **)(work + 0xba8));
    DestroyMsgData(*(void **)(work + 0xba0));
    DestroyMsgData(*(void **)(work + 0xbb0));
    MessageFormat_Delete(*(void **)(work + 0xb9c));
    ov70_0223887C(work);
    sub_02034DE0();
    TextFlags_SetCanTouchSpeedUpPrint(0);
    Heap_Free(*(void **)(work + 4));
    Heap_Free(*(void **)work);
    OverlayManager_FreeData(ovy);
    FontID_Release(4);
    *(u32 *)0x04000000 &= 0xFFFF1FFF;
    *(u32 *)0x04001000 &= 0xFFFF1FFF;
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy(0x3d);
    return 1;
}
