#include "global.h"

#include "bg_window.h"
#include "font.h"
#include "heap.h"
#include "obj_char_transfer.h"
#include "sprite.h"
#include "sys_task_api.h"
#include "system.h"
#include "unk_02009D48.h"
#include "unk_0200B150.h"

#define PTR(base, offset) (*(void **)((u8 *)(base) + (offset)))

extern u8 *ov102_021E8F68(u8 *work);
extern void ov102_021E91BC(void *work);
extern SysTask *ov102_021E93D4(SysTaskFunc func, void *work, u32 priority);
extern void ov102_021E93DC(SysTask *task, void *work);
extern void ov102_021E93E0(SysTask *task, void *work);
extern const ObjCharTransferTemplate ov102_021EC698;

void *ov102_021E909C(void *arg0, void *arg1);
void ov102_021E9144(void *arg);
void ov102_021E9198(void *work);

void *ov102_021E909C(void *arg0, void *arg1) {
    u8 *work = Heap_Alloc(HEAP_ID_35, 0x234);
    int i;
    u8 *cursor;

    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    PTR(work, 0x18) = arg0;
    PTR(work, 0x1C) = arg1;
    PTR(work, 0x1F8) = ov102_021E8F68(arg0);
    ov102_021E9198(work);
    NNS_G2dInitOamManagerModule();
    OamManager_Create(1, 0x7F, 0, 0x20, 0, 0x7F, 0, 0x20, HEAP_ID_35);
    PTR(work, 0x24) = G2dRenderer_Init(0x80, (G2dRenderer *)(work + 0x28), HEAP_ID_35);
    PTR(work, 0x20) = BgConfig_Alloc(HEAP_ID_35);
    PTR(work, 0) = SysTask_CreateOnMainQueue(ov102_021E93DC, work, 2);
    PTR(work, 4) = ov102_021E93D4(ov102_021E93E0, work, 1);
    cursor = work;
    for (i = 0; i < 4; i++, cursor += 4) {
        PTR(cursor, 8) = NULL;
    }
    FontID_Alloc(4, HEAP_ID_35);
    return work;
}

void ov102_021E9144(void *arg) {
    u8 *work = arg;
    int i;
    u8 *cursor;

    if (work == NULL) {
        return;
    }
    Main_SetVBlankIntrCB(NULL, NULL);
    FontID_Release(4);
    i = 0;
    cursor = work;
    do {
        if (PTR(cursor, 8) != NULL) {
            SysTask_Destroy(PTR(cursor, 8));
        }
        i++;
        cursor += 4;
    } while (i < 4);
    SysTask_Destroy(PTR(work, 0));
    SysTask_Destroy(PTR(work, 4));
    OamManager_Free();
    SpriteList_Delete(PTR(work, 0x24));
    ov102_021E91BC(work);
    Heap_Free(PTR(work, 0x20));
    Heap_Free(work);
}

void ov102_021E9198(void *work) {
#pragma unused(work)
    ObjCharTransferTemplate template = ov102_021EC698;

    ObjCharTransfer_Init(&template);
    ObjCharTransfer_ClearBuffers();
}
