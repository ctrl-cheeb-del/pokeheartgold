#include "global.h"

#include "to47_overlay83_profile_sync_private.h"

BOOL ov83_022450A8(void *p, int kind, int param) {
    int value;
    switch (kind) {
    case 20:
        value = 0x35;
        ov83_02245104(p, kind);
        break;
    case 21:
        value = 0x36;
        ov83_0224517C(p, kind, param);
        break;
    case 22:
        value = 0x37;
        ov83_02245210(p, kind);
        break;
    case 23:
        value = 0x38;
        ov83_02245248(p, kind);
        break;
    }
    if (sub_02037030(value, (u8 *)p + 0x564, 0x28) == 1) {
        return TRUE;
    }
    return FALSE;
}

void ov83_02245104(void *p, int value) {
    void *profile = Save_PlayerData_GetProfile(*(void **)((u8 *)p + 0x2BC));
    int i;
    int gender;
    u8 *dest;
    *(u16 *)((u8 *)p + 0x564) = value;
    gender = PlayerProfile_GetTrainerGender(profile);
    i = 0;
    *(u16 *)((u8 *)p + 0x566) = gender;
    dest = (u8 *)p + 4;
    do {
        *(u16 *)(dest + 0x564) = ov83_0224777C(*(void **)((u8 *)p + 0x2BC), *((u8 *)p + 9), i);
        i++;
        dest += 2;
    } while (i < 3);
}

typedef struct Ov83Record {
    u16 unused[2];
    u16 values[3];
} Ov83Record;

typedef struct Ov83State {
    u8 unused_000[0x17];
    u8 count;
    u8 unused_018[0x59F];
    u8 values[3];
} Ov83State;

void ov83_0224514C(int id, void *unused, Ov83Record *record, Ov83State *state);

void ov83_0224514C(int id, void *unused, Ov83Record *record, Ov83State *state) {
    int i;
    u16 *src;
    state->count++;
    if (id != sub_0203769C()) {
        i = 0;
        src = record->values;
        do {
            state->values[i] = *src;
            i++;
            src++;
        } while (i < 3);
    }
}
