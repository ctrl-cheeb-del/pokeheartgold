#include "global.h"

#define PTR(p, off) (*(void **)((u8 *)(p) + (off)))

void sub_02030938(void *p);
void sub_020314BC(void *p);
void TouchHitboxController_IsTriggered(void *controller);
void ClearWindowTilemapAndCopyToVram(void *window);
void RemoveWindow(void *window);
void ov40_0222D6D0(void *p);
void Sprite_DeleteAndFreeResources(void *sprite);
void ov40_0222D7DC(void *p);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void ov40_0222FF48(void *p, void *a1, void *a2);
void *ov40_0223D540(void *p);
void ov39_02227F74(void *p, void *dest);
void ov39_02227FA8(void *p, void *dest1, void *dest2);
void MI_CpuCopy8(const void *src, void *dest, u32 size);
void FillWindowPixelBuffer(void *window, u8 fillValue);
void *NewString_ReadMsgData(void *msgData, int msgId);
int ov40_022306C0(void *window, void *string);
u8 AddTextPrinterParameterizedWithColor(void *window, int fontId, void *string, u32 x, u32 y, u32 textSpeed, u32 color, void *callback);
void String_Delete(void *string);
void ScheduleWindowCopyToVram(void *window);
void InitWindow(void *window);
void AddWindowParameterized(void *bgConfig, void *window, int bgId, int x, int y, int width, int height, int palette, int baseTile);
void ov40_0223A83C(void *p);
int ov40_0223A85C(void *p);
int ov40_0223AF24(void *p);
int ov40_0223C240(void *p);
void ov40_0223CCA0(void *p);
void ov40_0223CE38(void *p);
void ov40_0223D1AC(void *p, BOOL draw);
void ov40_0223D1F0(void *p);
void ov40_0223D504(void *p);
void ov40_0223A324(void *p, int *mode);
void ov40_0223A360(void *p, int *mode);
void ov40_0223B44C(void *p);
void ov40_0223B480(void *p);
void ov40_0223B538(void *p);
void ov40_0223B574(void *p);
void ov40_0223CCBC(void *p, int msgId);
void ov40_0223CD14(void *p);

void ov40_0223A83C(void *p) {
    void *inner = PTR(p, 0x860);
    sub_02030938(PTR(inner, 0x224));
    sub_020314BC(PTR(inner, 0x194));
}

int ov40_0223A85C(void *p) {
    void *inner = PTR(p, 0x860);
    TouchHitboxController_IsTriggered(PTR(inner, 0x190));
    return 0;
}
