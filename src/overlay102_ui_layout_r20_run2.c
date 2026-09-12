#include "overlay102_ui_layout_r20_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov102_021EA380(u8 *work) {
    if (PTR(work, 0x80) != NULL) {
        DestroyListMenuCursorObj(PTR(work, 0x80));
    }
    if (PTR(work, 0x60) != NULL) {
        Sprite_Delete(PTR(work, 0x60));
    }
    if (PTR(work, 0x64) != NULL) {
        Sprite_Delete(PTR(work, 0x64));
    }
    if (PTR(work, 0x68) != NULL) {
        Sprite_Delete(PTR(work, 0x68));
    }
    if (PTR(work, 0x6C) != NULL) {
        Sprite_Delete(PTR(work, 0x6C));
    }
    if (PTR(work, 0x70) != NULL) {
        Sprite_Delete(PTR(work, 0x70));
    }
    if (PTR(work, 0x74) != NULL) {
        Sprite_Delete(PTR(work, 0x74));
    }
    if (PTR(work, 0x78) != NULL) {
        DestroyMsgData(PTR(work, 0x78));
    }
    if (PTR(work, 0x7C) != NULL) {
        String_Delete(PTR(work, 0x7C));
    }
    RemoveWindow(work + 0xC);
    RemoveWindow(work + 0x1C);
    RemoveWindow(work + 0x2C);
    RemoveWindow(work + 0x3C);
    RemoveWindow(work + 0x4C);
    YesNoPrompt_Destroy(PTR(work, 0x1E8));
    Heap_Free(work);
}
