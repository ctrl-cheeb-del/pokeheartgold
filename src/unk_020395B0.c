#include "unk_020395B0_internal.h"

BOOL sub_020395B0(void) {
    u32 first;
    u32 second;

    if (_021D4150 == NULL) {
        return FALSE;
    }
    if (_021D4150->activity4E == 0x18 || _021D4150->activity4E == 0x24) {
        if (ov00_021EC11C(&first, &second)) {
            ov00_021EC210();
            return TRUE;
        }
    } else if (_021D4150->activity4E == 0x19) {
        if (ov00_021EC11C(&first, &second) && second == 7) {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_0203960C(void) {
    int result = ov00_021E5B6C();
    _021D4150->delay44--;
    if (result == 0x1B) {
        if (_021D4150->activity4E == 0x21) {
            if (ov45_0222E804(_021D4150->field60) == TRUE) {
                _021D4150->active64 = TRUE;
                sub_020381C0(sub_02039C14, _021D4150->delay44);
            } else {
                sub_020381C0(sub_02039DC0, 0);
            }
        } else {
            sub_020381C0(sub_02039144, 0);
        }
    } else {
        if (result != 0) {
            sub_020381C0(sub_02038E90, 0);
        }
        if (_021D4150->delay44 <= 0) {
            sub_020381C0(sub_02038E90, 0);
        }
    }
}

void sub_02039694(void) {
    int value;
    if (sub_02034DB8()) {
        Heap_CreateAtEnd(3, 0x30, 0x35400);
        if (sub_02035ED8(1, 1, 0x200, 1)) {
            value = sub_02033FC4(_021D4150->activity4E);
            ov00_021E5900(_021D4150->saveData, 0x30, 0x2C400, value + 1);
            ov00_021E6CA4(sub_020399DC);
            sub_02035FD8();
            sub_020381C0(sub_0203960C, 0xE10);
        }
    }
}

void *sub_020396FC(SaveData *saveData, u32 size) {
    if (sub_02037474(Save_PlayerData_GetProfile(saveData))) {
        return NULL;
    }
    sub_0201A728(1);
    Heap_CreateAtEnd(3, 0xF, 0x7080);
    sub_02037C98(saveData, 0x17);
    _021D4150->allocation = Heap_Alloc(0xF, size);
    MI_CpuFill8(_021D4150->allocation, 0, size);
    _021D4150->parameter4F = 0;
    _021D4150->saveData = saveData;
    sub_020381C0(sub_02039694, 0);
    return _021D4150->allocation;
}

void sub_0203976C(SaveData *saveData, void *arg) {
    if (!sub_02037474(Save_PlayerData_GetProfile(saveData))) {
        sub_0201A728(1);
        Heap_CreateAtEnd(3, 0xF, 0x7080);
        sub_02037C98(saveData, 0x21);
        _021D4150->allocation = NULL;
        _021D4150->field60 = arg;
        _021D4150->active64 = 0;
        _021D4150->parameter4F = 0;
        _021D4150->saveData = saveData;
        sub_020381C0(sub_02039BA0, 0);
    }
}
