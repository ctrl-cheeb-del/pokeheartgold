#include <string.h>

#include "global.h"

#include "overlay90_roster_internal.h"

void ov90_02258800(Ov90LinkRoster *roster, void *connection, u32 value, u8 mode, void *records) {
    int slot;
    int local;
    int count;
    memset(roster, 0, sizeof(Ov90LinkRoster));
    roster->count = sub_020347A0();
    local = sub_0203769C();
    count = 0;
    for (slot = 0; slot < 4; slot++) {
        if (sub_02034818(slot) != NULL) {
            if (local == slot) {
                roster->localSlot = count;
            }
            roster->slots[count] = slot;
            count++;
        }
    }
    if (count != roster->count) {
        GF_AssertFail();
    }
    if (connection == NULL) {
        roster->isHost = TRUE;
    }
    roster->value = value;
    roster->mode = mode;
    roster->records = records;
}
