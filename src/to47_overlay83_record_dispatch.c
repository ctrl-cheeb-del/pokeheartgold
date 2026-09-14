#include "global.h"

#include "to47_overlay83_record_dispatch_private.h"

BOOL ov83_02241368(void *p, int kind, int param) {
    int value;
    switch (kind) {
    case 10:
        value = 0x31;
        ov83_022413C4(p, kind);
        break;
    case 11:
        value = 0x32;
        ov83_0224143C(p, kind, param);
        break;
    case 12:
        value = 0x33;
        ov83_022414CC(p, kind);
        break;
    case 13:
        value = 0x34;
        ov83_02241504(p, kind);
        break;
    }
    if (sub_02037030(value, (u8 *)p + 0x7AC, 0x28) == 1) {
        return TRUE;
    }
    return FALSE;
}

void ov83_022413C4(void *p, int value) {
    void *profile;
    int i;
    u8 *dest;
    profile = Save_PlayerData_GetProfile(*(void **)((u8 *)p + 0x50C));
    *(u16 *)((u8 *)p + 0x7AC) = value;
    *(u16 *)((u8 *)p + 0x7AE) = PlayerProfile_GetTrainerGender(profile);
    for (i = 0, dest = (u8 *)p + 4; i < 3; i++, dest += 2) {
        *(u16 *)(dest + 0x7AC) = ov83_0224777C(*(void **)((u8 *)p + 0x50C), *((u8 *)p + 9), i);
    }
}

void ov83_0224140C(int id, void *unused, void *record, void *state) {
    int i;
    u8 *src;
    (*((u8 *)state + 0xF))++;
    if (id != sub_0203769C()) {
        for (i = 0, src = (u8 *)record + 4; i < 3; i++, src += 2) {
            ((u8 *)state + (u32)i)[0x7FF] = *(u16 *)src;
        }
    }
}
