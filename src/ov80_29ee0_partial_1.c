#include "ov80_29ee0_partial_internal.h"

void *ov80_02229EE0(int narcId, int memberId, int heapId) {
    return AllocAndReadWholeNarcMemberByIdPair(heapId, narcId, memberId);
}

void ov80_02229EF4(void *dest, int narcId, int memberId) {
    ReadWholeNarcMemberByIdPair(dest, memberId, narcId);
}

void *ov80_02229F04(TrainerRecord *record, int trainerId, int heapId, int memberId) {
    void *msgData = NewMsgDataFromNarc(1, 0x1B, 0x1B, heapId);
    void *raw;
    void *string;

    MI_CpuFill8(record, 0, 0x30);
    raw = ov80_02229EE0((u16)trainerId, heapId, memberId);
    record->id = trainerId;
    record->value18 = 0xFFFF;
    record->value1A = trainerId * 3;
    record->species = *(u16 *)raw;
    string = NewString_ReadMsgData(msgData, trainerId);
    CopyStringToU16Array(string, record->name, 8);
    String_Delete(string);
    DestroyMsgData(msgData);
    return raw;
}
