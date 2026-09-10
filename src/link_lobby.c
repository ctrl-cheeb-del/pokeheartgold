#include "link_lobby_internal.h"

void sub_02058034(void) {
}

void sub_02058038(FieldSystem *fieldSystem) {
    if (_021D41C8 == NULL) {
        sub_02091574(fieldSystem);
        _021D41C8 = Heap_Alloc((enum HeapID)15, sizeof(Lobby));
        MI_CpuFill8(_021D41C8, 0, sizeof(Lobby));
        _021D41C8->timer = 50;
        _021D41C8->task = SysTask_CreateOnMainQueue(sub_020582CC, NULL, 10);
        _021D41C8->fieldSystem = fieldSystem;
        _021D41C8->party = NULL;
        sub_02058034();
        sub_0203778C(_021D41C8->pad18);
    }
}

void sub_02058098(void) {
    int i;
    if (_021D41C8) {
        SysTask_Destroy(_021D41C8->task);
        for (i = 0; i < 4; i++) {
            if (_021D41C8->packets[i]) {
                Heap_Free(_021D41C8->packets[i]);
            }
        }
        if (_021D41C8->party) {
            Heap_Free(_021D41C8->party);
        }
        Heap_Free(_021D41C8);
        _021D41C8 = NULL;
    }
}

void sub_020580E4(FieldSystem *fieldSystem, s32 arg1, s32 arg2) {
    if (sub_02037474() == 0) {
        sub_02037D8C(FieldSystem_GetSaveData(fieldSystem), arg1, arg2, fieldSystem->linkBattleRuleset, 0);
        sub_02058038(fieldSystem);
        sub_020582F4(sub_02058304, 0);
    }
}

void sub_02058124(FieldSystem *fieldSystem, u8 arg1, u32 arg2) {
    if (sub_02037474() == 0) {
        sub_02037DD4(FieldSystem_GetSaveData(fieldSystem), arg1, arg2, fieldSystem->linkBattleRuleset, 0);
        sub_02058038(fieldSystem);
        sub_020582F4(sub_0205832C, 0);
    }
}

void sub_02058164(u16 mode) {
    _021D41C8->mode = mode;
    sub_020582F4(sub_0205834C, 0);
}

void sub_02058180(void) {
    sub_020582F4(sub_020588A0, 0);
}
