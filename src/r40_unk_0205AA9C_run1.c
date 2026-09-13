#include "r40_unk_0205AA9C_private.h"

void sub_0205AA9C(MessageFormat *msgFmt, u16 mode, u16 objId, PlayerProfile *profile, SaveEasyChat *easyChat) {
    MsgData *msgData;
    PlayerProfile *selected;
    int language;
    int msgNo;
    String *str;

    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, 0x2E2, HEAP_ID_FIELD1);
    if (mode == 0) {
        selected = sub_02035798(objId - 1);
    } else {
        selected = sub_02034818(sub_0203769C() ^ 1);
    }
    if (selected == NULL) {
        DestroyMsgData(msgData);
        return;
    }
    BufferPlayersName(msgFmt, 0, selected);
    BufferPlayersName(msgFmt, 1, profile);
    language = PlayerProfile_GetLanguage(selected);
    if (language >= 1 && language <= 7) {
        u16 idx = language - 1;
        if (idx < 7 && _020FC898[idx] >= 0) {
            Save_EasyChat_SetGreetingFlag(easyChat, _020FC898[idx]);
        }
    }
    switch (language) {
    case 1:
        msgNo = 0xD3;
        break;
    case 2:
        msgNo = 0xD4;
        break;
    case 3:
        msgNo = 0xD5;
        break;
    case 4:
        msgNo = 0xD6;
        break;
    case 5:
        msgNo = 0xD7;
        break;
    case 7:
        msgNo = 0xD8;
        break;
    default:
        msgNo = 0xD9;
        break;
    }
    str = NewString_ReadMsgData(msgData, msgNo);
    BufferString(msgFmt, 2, str, 0, 1, language);
    Heap_Free(str);
    DestroyMsgData(msgData);
}
