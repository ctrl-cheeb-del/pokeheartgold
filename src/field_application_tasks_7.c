#include "field_application_tasks_internal.h"

void *sub_02059DB0(void *fieldSystem) {
    void *data;
    if (fieldSystem == NULL) {
        GF_AssertFail();
    }
    if (*(void **)((u8 *)fieldSystem + 0x80) != NULL) {
        return NULL;
    }
    Heap_CreateAtEnd(3, 0x1F, 0xA80);
    data = sub_02059E1C(fieldSystem);
    if (data == NULL) {
        data = *(void **)((u8 *)fieldSystem + 0x80);
    }
    sub_02091574(fieldSystem);
    sub_02038C1C(2);
    sub_0205A034(data, sub_02059E88, 0x28);
    return data;
}

void sub_02059E04(void *p) {
    void *env = *(void **)((u8 *)p + 0x80);
    if (env != NULL) {
        sub_0205A034(env, sub_0205A07C, 5);
    }
}

void *sub_02059E1C(void *fieldSystem) {
    u8 *data;
    void *saveData;
    if (*(void **)((u8 *)fieldSystem + 0x80) != NULL) {
        return NULL;
    }
    saveData = FieldSystem_GetSaveData(fieldSystem);
    sub_02037F18();
    data = Heap_Alloc(0x1F, 0x190);
    MI_CpuFill8(data, 0, 0x190);
    *(u32 *)(data + 0x10) = 0;
    *(u32 *)(data + 0x14) = 0x28;
    *(void **)(data + 0xC) = SysTask_CreateOnMainQueue(sub_0205A03C, data, 0xA);
    *(void **)data = fieldSystem;
    *(void **)(data + 4) = saveData;
    *(void **)(data + 8) = Save_PlayerData_GetProfile(saveData);
    sub_0205ABBC(data);
    sub_0203778C(data + 0x150);
    return data;
}

void sub_02059E88(void *p) {
    MailMessageScratch message;
    if (sub_02035650() != 0) {
        MailMsg_Init_Default(&message);
        sub_0205AB88(&message);
        sub_0205AA6C(p, &message);
        sub_0205A034(p, sub_02059EBC, 0x28);
    }
}
