#include "r40_unk_0205A904_private.h"

void sub_0205A904(int command) {
    struct UnkSub_0205A904 data;
    MI_CpuFill8(&data, 0, sizeof(data));
    switch (command) {
    case 11:
        sub_0205A8B4(&data, 2);
        break;
    case 5:
    case 6:
    case 7:
        sub_0205A8B4(&data, 2);
        break;
    case 8:
        sub_0205A8B4(&data, 5);
        break;
    case 1:
        sub_0205A8B4(&data, 4);
        break;
    case 9:
        sub_0205A8B4(&data, 5);
        break;
    case 2:
        sub_0205A8B4(&data, 4);
        break;
    case 10:
    case 12:
        sub_0205A8B4(&data, 5);
        break;
    case 3:
    case 13:
        sub_0205A8B4(&data, 4);
        break;
    }
    data.command = command;
    sub_02035854(&data);
    sub_0203588C();
}

int sub_0205A9A0(struct LinkMessageStateA904 *state, MessageFormat *msgFmt) {
    int i;
    int count = 0;
    int msgNo;
    u16 word;
    for (i = 0; i < 10; i++) {
        if (state->objects[i] != NULL) {
            count++;
        }
    }
    if (count != 0) {
        return 0xA6;
    }
    if (!MailMsg_IsInit(&state->mail)) {
        return 0xA7;
    }
    if (MailMsg_GetMsgBank(&state->mail) != 4) {
        int avatar = PlayerProfile_GetAvatar(state->profile);
        int gender = PlayerProfile_GetTrainerGender(state->profile);
        BufferTrainerClassName(msgFmt, 0, GetUnionRoomAvatarAttrBySprite(gender, avatar, 2));
        return 0xA8;
    }
    msgNo = MailMsg_GetMsgNo(&state->mail);
    if (msgNo >= 20) {
        msgNo = 0;
    }
    word = MailMsg_GetFieldI(&state->mail, 0);
    if (word != 0xFFFF) {
        BufferECWord(msgFmt, 0, word);
    }
    return _020FC9D4[msgNo];
}
