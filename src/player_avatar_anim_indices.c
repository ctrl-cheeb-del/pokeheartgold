#include "player_avatar_anim_indices_internal.h"

u32 sub_0205BFF0(u32 param0, u32 param1) {
    u32 base;

    switch (param1) {
    case 0:
        base = 0xB;
        break;
    case 1:
        base = 0x13;
        break;
    case 2:
        base = 0x1B;
        break;
    case 3:
        base = 0x73;
        break;
    }

    return base + param0 * 4;
}

u32 sub_0205C01C(u32 param0, u32 param1) {
    u32 base;

    switch (param1) {
    case 0:
        base = 0xA;
        break;
    case 1:
        base = 0x12;
        break;
    case 2:
        base = 0x1A;
        break;
    case 3:
        base = 0x72;
        break;
    }

    return base + param0 * 4;
}

u32 sub_0205C048(u32 param0, u32 param1) {
    u32 base;

    switch (param1) {
    case 0:
        base = 0xD;
        break;
    case 1:
        base = 0x15;
        break;
    case 2:
        base = 0x1D;
        break;
    case 3:
        base = 0x75;
        break;
    }

    return base + param0 * 4;
}

u32 sub_0205C074(u32 param0, u32 param1) {
    u32 base;

    switch (param1) {
    case 0:
        base = 0xC;
        break;
    case 1:
        base = 0x14;
        break;
    case 2:
        base = 0x1C;
        break;
    case 3:
        base = 0x74;
        break;
    }

    return base + param0 * 4;
}

u32 sub_0205C0A0(u32 param0, u32 param1) {
    u32 base;

    switch (param0) {
    case 0:
        base = 0x25;
        break;
    case 1:
        base = 0x31;
        break;
    case 2:
        base = 0x3D;
        break;
    case 3:
        base = 0x7D;
        break;
    }

    return base + param1 / 2;
}

u32 sub_0205C0CC(u32 param0) {
    u32 ret;

    switch (param0) {
    case 0:
        ret = 0x23;
        break;
    case 1:
        ret = 0x2F;
        break;
    case 2:
        ret = 0x3B;
        break;
    case 3:
        ret = 0x7B;
        break;
    }

    return ret;
}

u32 sub_0205C0F4(u32 param0) {
    u32 ret;

    switch (param0) {
    case 0:
        ret = 0x22;
        break;
    case 1:
        ret = 0x2E;
        break;
    case 2:
        ret = 0x3A;
        break;
    case 3:
        ret = 0x7A;
        break;
    }

    return ret;
}

u32 sub_0205C11C(u32 param0) {
    u32 ret;

    switch (param0) {
    case 0:
        ret = 0x24;
        break;
    case 1:
        ret = 0x30;
        break;
    case 2:
        ret = 0x3C;
        break;
    case 3:
        ret = 0x7C;
        break;
    }

    return ret;
}

u32 sub_0205C144(u32 param0) {
    u32 ret;

    switch (param0) {
    case 0:
        ret = 0;
        break;
    case 1:
        ret = 1;
        break;
    case 2:
        ret = 2;
        break;
    case 3:
        ret = 2;
        GF_AssertFail();
        break;
    }

    return ret;
}

u32 sub_0205C174(u32 param0, u32 param1) {
    u32 base;

    switch (param0) {
    case 0:
        base = 0x4B;
        break;
    case 1:
        base = 0x53;
        break;
    case 2:
        base = 0x5B;
        break;
    case 3:
        base = 0x8B;
        break;
    }

    return base + param1;
}

u32 sub_0205C1A0(u32 param0) {
    u32 ret;

    switch (param0) {
    case 0:
        ret = 0x47;
        break;
    case 1:
        ret = 0x4F;
        break;
    case 2:
        ret = 0x57;
        break;
    case 3:
        ret = 0x87;
        break;
    }

    return ret;
}

u32 sub_0205C1C8(u32 param0) {
    u32 ret;

    switch (param0) {
    case 0:
        ret = 0x46;
        break;
    case 1:
        ret = 0x4E;
        break;
    case 2:
        ret = 0x56;
        break;
    case 3:
        ret = 0x86;
        break;
    }

    return ret;
}

u32 sub_0205C1F0(u32 param0) {
    u32 ret;

    switch (param0) {
    case 0:
        ret = 0x48;
        break;
    case 1:
        ret = 0x50;
        break;
    case 2:
        ret = 0x58;
        break;
    case 3:
        ret = 0x88;
        break;
    }

    return ret;
}

u32 sub_0205C218(u32 param0) {
    u32 ret;

    switch (param0) {
    case 0:
        ret = 0x49;
        break;
    case 1:
        ret = 0x51;
        break;
    case 2:
        ret = 0x59;
        break;
    case 3:
        ret = 0x89;
        break;
    }

    return ret;
}

u32 sub_0205C240(u32 param0) {
    u32 ret;

    switch (param0) {
    case 0:
        ret = 0x4A;
        break;
    case 1:
        ret = 0x52;
        break;
    case 2:
        ret = 0x5A;
        break;
    case 3:
        ret = 0x8A;
        break;
    }

    return ret;
}
