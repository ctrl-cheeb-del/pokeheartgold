#include "apricorn_internal.h"

String *sub_020322AC(SaveApricornBox *box, int type, u32 heapId);
String *sub_02032308(SaveApricornBox *box, u16 type, u32 heapId);
void sub_02032340(SaveApricornBox *box, u8 amount);

String *sub_020322AC(SaveApricornBox *box, int type, u32 heapId) {
    String *result = String_New(9, (enum HeapID)heapId);
    if (type < 5) {
        MsgData *msgData = NewMsgDataFromNarc((MsgDataLoadType)1, (NarcId)0x1B, 0x15, (enum HeapID)heapId);
        ReadMsgDataIntoString(msgData, type + 0xE, result);
        DestroyMsgData(msgData);
    } else if (type < 8) {
        u32 offset = (u8)(type - 5) << 5;
        if (sub_02031D6C((UnkStruct_02031CEC *)((u8 *)box + 0x38 + offset))) {
            CopyU16ArrayToString(result, (u16 *)((u8 *)box + 0x28 + offset));
        }
    }
    return result;
}

String *sub_02032308(SaveApricornBox *box, u16 type, u32 heapId) {
    UnkStruct_02031CEC data;
    MsgData *msgData;
    String *result;
    sub_02031CEC(box, type, &data);
    msgData = NewMsgDataFromNarc((MsgDataLoadType)1, (NarcId)0x1B, 0x15, (enum HeapID)heapId);
    result = NewString_ReadMsgData(msgData, sub_02032004(&data) + 0x13);
    DestroyMsgData(msgData);
    return result;
}

void sub_02032340(SaveApricornBox *box, u8 amount) {
    int value = box->unk_0C[2] + amount;
    if (value > 255) {
        box->unk_0C[2] = 255;
    } else {
        box->unk_0C[2] = value;
    }
}
