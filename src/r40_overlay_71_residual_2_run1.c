#include "r40_overlay_71_residual_2_private.h"

BOOL TradeSequence_Exit(OverlayManager *manager, int *state) {
    OSIntrMode enabled = OS_DisableInterrupts();
    u8 *data = OverlayManager_GetData(manager);
    SysTask_Destroy(*(SysTask **)(data + 0x144));
    sub_0203A914();
    MessageFormat_Delete(*(MessageFormat **)(data + 0xc));
    DestroyMsgData(*(MsgData **)(data + 0x10));
    String_Delete(*(String **)(data + 0x14));
    Heap_Free(*(void **)(data + 8));
    SpriteList_Delete(*(SpriteList **)(data + 0x18));
    OamManager_Free();
    OverlayManager_FreeData(manager);
    Heap_Destroy((enum HeapID)0x38);
    Heap_Destroy((enum HeapID)0x39);
    OS_RestoreInterrupts(enabled);
    return TRUE;
}
