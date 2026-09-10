#include "wireless_session_internal.h"

BOOL sub_020332C0(void) {
    u8 macAddress[6];
    u32 seed;
    u16 ret;

    OS_GetMacAddress(macAddress);
    seed = *(u32 *)0x027FFC3C;
    seed = ((u16 *)macAddress)[2] + (((u16 *)macAddress)[1] + (((u16 *)macAddress)[0] + seed));
    _021D4124.unk_04->unk_1338 = seed;
    _021D4124.unk_04->unk_1338 = _021D4124.unk_04->unk_1338 * 0x10DCD + 0x3039;
    _021D4124.unk_04->unk_133C = 0;
    _021D4124.unk_04->unk_133E = 101;
    sub_02032844(3);
    ret = sub_0203335C(1);
    if (ret == 0x18) {
        sub_02032858(0x18);
        sub_02032844(9);
        sub_02039AD8(1);
        return FALSE;
    }
    if (ret != 2) {
        sub_02032858(ret);
        sub_02032844(9);
        return FALSE;
    }
    return TRUE;
}

u16 sub_0203335C(u16 channel) {
    int allowed;

    allowed = WM_GetAllowedChannel();
    if (allowed == 0x8000) {
        sub_02032858(3);
        sub_02032844(9);
        sub_02039AD8(1);
        return 3;
    }
    if (allowed == 0) {
        sub_02032858(0x16);
        sub_02032844(9);
        sub_02039AD8(1);
        return 0x18;
    }
    while (!((1 << (channel - 1)) & allowed)) {
        channel++;
        if (channel > 16) {
            return 0x18;
        }
    }
    return (u16)sub_02033454(sub_020333D8, channel);
}

void sub_020333D8(void *arg) {
    W6_WMMeasureChannelCallback *cb = (W6_WMMeasureChannelCallback *)arg;
    u16 channel;
    u16 ratio;
    u16 ret;

    if (cb->errcode != 0) {
        sub_02032858(cb->errcode);
        sub_02032844(9);
        sub_02039AD8(1);
        return;
    }
    channel = cb->channel;
    ratio = cb->ccaBusyRatio;
    if (_021D4124.unk_04->unk_133E > ratio) {
        _021D4124.unk_04->unk_133E = ratio;
        _021D4124.unk_04->unk_1340 = 1 << (channel - 1);
    } else if (_021D4124.unk_04->unk_133E == ratio) {
        _021D4124.unk_04->unk_1340 |= 1 << (channel - 1);
    }
    ret = sub_0203335C((u16)(channel + 1));
    if (ret == 0x18) {
        sub_02032844(7);
        return;
    }
    if (ret != 2) {
        sub_02032844(9);
    }
}

int sub_02033454(W6_WMCallbackFunc callback, u16 channel) {
    return WM_MeasureChannel(callback, 3, 0x11, channel, 30);
}

u16 sub_02033468(void) {
    sub_02032844(1);
    _021D4124.unk_04->unk_133C = sub_02033494(_021D4124.unk_04->unk_1340);
    return _021D4124.unk_04->unk_133C;
}
