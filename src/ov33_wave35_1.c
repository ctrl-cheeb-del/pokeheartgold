#include "ov33_wave35_private.h"
extern const Ov33Entry ov33_0225DA50[];

void ov33_0225D8D4(Ov33Env *env) {
    u16 i;
    String *str;
    const Ov33Entry *entry;
    MsgData *msgData;
    u16 halfWidth;
    u16 x;

    FontID_Alloc(4, HEAP_ID_8);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, 191, HEAP_ID_8);
    entry = &ov33_0225DA50[env->count - 1];

    for (i = 0; i < env->count; i++) {
        LoadRectToBgTilemapRect(env->bgConfig, GF_BG_LYR_SUB_1, env->tilemap, entry->x, (u8)(entry->y + (entry->spacing + 6) * i), 0x20, 6);
        str = NewString_ReadMsgData(msgData, env->args->msgIds[i]);
        halfWidth = GetWindowWidth(&env->windows[i]) * 8 / 2;
        x = halfWidth - FontID_String_GetWidth(4, str, 0) / 2;
        AddTextPrinterParameterizedWithColor(&env->windows[i], 4, str, x, 0, 0xFF, 0x00020100, NULL);
        CopyWindowPixelsToVram_TextMode(&env->windows[i]);
        ScheduleWindowCopyToVram(&env->windows[i]);
        String_Delete(str);
    }

    DestroyMsgData(msgData);
    FontID_Release(4);
    ScheduleBgTilemapBufferTransfer(env->bgConfig, GF_BG_LYR_SUB_1);
}
