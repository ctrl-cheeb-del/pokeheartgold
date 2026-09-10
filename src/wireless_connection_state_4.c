#include "wireless_connection_state_internal.h"

void sub_020353B8(void) {
    u8 *packet = *(u8 **)(_021D4134.work + 0xD88);

    if (packet[6] != sub_02035610()) {
        packet[6] = sub_02035610();
        DC_FlushRange(*(void **)(_021D4134.work + 0xD88), 0x5C);
        sub_02033240(*(void **)(_021D4134.work + 0xD88), 0x5C);
        sub_020339B4(*(void **)(_021D4134.work + 0xD88), 0x5C, *(void **)(_021D4134.work + 0xD80), _021D4134.localId);
    }
}
