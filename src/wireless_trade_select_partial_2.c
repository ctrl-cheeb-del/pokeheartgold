#include "wireless_trade_select_partial_private.h"

void ov65_0221C3DC(void *fmt, void *party, u32 base) {
    int i;

    for (i = 0; i < Party_GetCount(party); i++) {
        BufferBoxMonNickname(fmt, i + base, Mon_GetBoxMon(Party_GetMonByIndex(party, i)));
    }
}

void ov65_0221C414(void *dst, void *msgData, void *format, void *party, int base) {
    int i;
    void *string;

    for (i = 0; i < Party_GetCount(party); i++) {
        string = ReadMsgData_ExpandPlaceholders(msgData, format, base + 1 + i, 0x1a);
        ov65_0221FB4C(dst, string, 8, 0, 1, 0);
        String_Delete(string);
        dst = (u8 *)dst + 0x10;
    }
}
