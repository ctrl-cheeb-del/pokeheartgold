#include "overlay12_battle_controller_core_private.h"

void ov12_022621C4(BattleSystem *bsys, int direction) {
    u8 *buffer;
    u16 *read;
    u16 *write;
    u16 *end;

    if (direction == 1) {
        buffer = BattleSystem_GetRecvBufferPtr(bsys);
        read = ov12_0223A978(bsys);
        write = ov12_0223A984(bsys);
        end = ov12_0223A990(bsys);
    } else {
        buffer = BattleSystem_GetSendBufferPtr(bsys);
        read = ov12_0223A954(bsys);
        write = ov12_0223A960(bsys);
        end = ov12_0223A96C(bsys);
    }
    if (*read != *write) {
        if (*read == *end) {
            *read = 0;
            *end = 0;
        }
        if (BattleController_RecvData(bsys, &buffer[*read]) == TRUE) {
            *read += (buffer[*read + 2] | (buffer[*read + 3] << 8)) + 4;
        }
    }
}

void ov12_02262240(BattleSystem *bsys, int direction, int battlerId, const void *data, u8 size) {
    int i;

    if ((bsys->battleType & 4) && !(*(u32 *)((u8 *)bsys + 0x240C) & 0x10)) {
        if (direction == 1) {
            for (i = 0; i < sub_02037454(); i++) {
                ov12_0224ECC4(bsys->ctx, i, battlerId, *(const u8 *)data);
            }
        }
        sub_02074F9C(bsys, direction, battlerId, (u8 *)data, size);
    } else {
        if (direction == 1) {
            ov12_0224ECC4(bsys->ctx, 0, battlerId, *(const u8 *)data);
        }
        BattleController_SendData(bsys, direction, battlerId, data, size);
    }
}

void BattleController_EmitPlayEncounterAnimation(BattleSystem *bsys, BOOL battlerId) {
    u32 buffer[2];

    buffer[0] = 1;
    buffer[1] = BattleSystem_GetRandTemp(bsys);
    ov12_02262240(bsys, 1, battlerId, buffer, sizeof(buffer));
}
