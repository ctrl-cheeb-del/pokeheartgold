#include "field_link_messages_internal.h"

void sub_0205A44C(int a0, int a1, u8 *a2, struct FieldSysPriv *fsys) {
    fsys->unk80->unk2C = 1;
    fsys->unk80->unk40 = *a2;
    if (*a2 == 4) {
        sub_020388E0();
    }
}

void sub_0205A46C(int a0, int a1, u8 *a2, struct FieldSysPriv *fsys) {
    fsys->unk80->unk44 = 1;
}

BOOL sub_0205A478(struct UnkStruct_02059E1C *p) {
    return p->unk44;
}

int sub_0205A47C(struct UnkStruct_02059E1C *p, int a1) {
    if (p->unk30 == 0) {
        sub_02037030(0x68, NULL, 0);
        return a1;
    }
    return 0;
}

void sub_0205A498(int a0, int a1, void *a2) {
    sub_02034818(sub_0203769C() ^ 1);
    *(u16 *)((u8 *)a2 + 0x66A) = 1;
}

void *sub_0205A4B4(int idx, struct FieldSysPriv *fsys) {
    return fsys->unk80->unk188[idx];
}

void sub_0205A4C4(int a0, int a1, u8 *a2, struct FieldSysPriv *fsys) {
    fsys->unk80->unk176[a0] = *a2;
}

BOOL sub_0205A4D8(struct UnkStruct_02059E1C *p) {
    int netId = sub_0203769C();
    if (p->unk176[netId] == 2) {
        return 1;
    }
    if (p->unk176[netId ^ 1] == 2) {
        return 2;
    }
    return 0;
}

void sub_0205A508(int a0) {
    u8 sp0;
    sp0 = a0;
    sub_02037030(0x65, &sp0, 1);
}

int sub_0205A51C(int a0) {
    int i;
    const u16 *p = _020FC824;
    for (i = 0; i < 10; i++, p++) {
        if (*p <= a0 && *p + 4 > a0) {
            return i;
        }
    }
    return -1;
}
