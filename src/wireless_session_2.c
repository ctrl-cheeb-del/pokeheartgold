#include "wireless_session_internal.h"

BOOL sub_02033528(void *buf, u32 a1) {
    u32 p = (u32)buf;
    u32 mod;

    mod = p << 27;
    mod = mod >> 27;
    if (mod != 0) {
        p += 32 - mod;
    }
    _021D4124.unk_04 = (W6_WmWork *)p;
    _021D4124.unk_04->unk_1308 = 0;
    _021D4124.unk_04->unk_1304 = 0;
    _021D4124.unk_04->unk_1318 = 0;
    _021D4124.unk_04->unk_132C = 0;
    _021D4124.unk_04->unk_132E = 1;
    _021D4124.unk_04->unk_1330 = 0;
    _021D4124.unk_04->unk_1310 = 0;
    _021D4124.unk_04->unk_0000 = 0;
    _021D4124.unk_04->unk_0004 = 0;
    _021D4124.unk_04->unk_131C = 0;
    _021D4124.unk_04->unk_1334 = 8;
    _021D4124.unk_04->unk_1335 = 0;
    _021D4124.unk_04->unk_1342 = 0;
    if (!sub_020335D4(a1)) {
        return FALSE;
    }
    return TRUE;
}
