#include "to46_wireless_connection_packet_import_private.h"

void sub_02034C20(u8 *data) {
    u8 *packet;
    int kind;
    int id;

    kind = sub_0203993C();
    id = sub_02039954();
    packet = data + 0x50;

    if (kind != 14) {
        if (!sub_0203401C(packet[4]) || !sub_0203401C(kind)) {
            if (packet[0x54] != 0 && packet[4] == 10) {
                return;
            }
            if (packet[4] != kind) {
                return;
            }
        }
    }
    if (kind != 14 && packet[5] != id) {
        return;
    }
    MI_CpuCopy8(data, _021D4134.work->packet, 0xC0);
    _021D4134.work->pending = 1;
}

void sub_02034C94(void) {
    Work34C20 *work;
    u8 *packet;
    u8 *slot;
    int i;

    work = _021D4134.work;
    packet = work->packet;
    if (work->pending == 0) {
        return;
    }
    work->pending = 0;
    for (i = 0; i < 16; i++) {
        if (_021D4134.work->slots[i] != 0) {
            if (sub_02034BF8(&_021D4134.work->records[i][4], packet + 4, 6)) {
                _021D4134.work->slots[i] = 0x12C;
                MI_CpuCopy8(packet, _021D4134.work->records[i], 0xC0);
                return;
            }
        }
    }
    slot = (u8 *)_021D4134.work;
    for (i = 0; i < 16; i++, slot += 2) {
        if (*(u16 *)(slot + 0xD44) == 0) {
            break;
        }
    }
    if (i < 16) {
        _021D4134.work->slots[i] = 0x12C;
        MI_CpuCopy8(packet, _021D4134.work->records[i], 0xC0);
        _021D4134.work->changed = 1;
    }
}
