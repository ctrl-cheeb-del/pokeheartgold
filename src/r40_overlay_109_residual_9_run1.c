#include "r40_overlay_109_residual_9_private.h"

void ov109_021E6C9C(PhotoAlbumApp *app) {
    int i;
    FontID_Alloc(4, app->heapId);
    app->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, (NarcId)0x1B, 0, app->heapId);
    app->messageFormat = MessageFormat_New_Custom(6, 0x16, app->heapId);
    app->str_2C = String_New(0x80, app->heapId);
    app->str_30 = NewString_ReadMsgData(app->msgData, 0);
    for (i = 0; i < 5; i++) {
        app->strs_34[i] = NewString_ReadMsgData(app->msgData, i + 5);
    }
    for (i = 0; i < 2; i++) {
        app->strs_48[i] = NewString_ReadMsgData(app->msgData, i + 10);
    }
    app->listMenuItems = ListMenuItems_New(4, app->heapId);
    for (i = 0; i < 4; i++) {
        ListMenuItems_AppendFromMsgData(app->listMenuItems, app->msgData, i + 1, i);
    }
}
