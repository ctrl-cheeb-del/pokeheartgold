#include "overlay02_follow_mon_r54_private.h"

int ov02_0224EF94(void *fieldSystem);
void ov02_0224F058(void *fieldSystem, void *cond);
int ov02_0224F108(void *fieldSystem, const FollowMonInteractionEntry *entry, void *cond);
void ov02_0224F324(void *mon, void *cond);
void ov02_0224F4BC(void *fieldSystem, void *cond);
void ov02_0224F580(void *fieldSystem, void *cond);
void ov02_0224F5D0(void *fieldSystem, void *cond);
void ov02_0224F5FC(void *fieldSystem, void *cond);

int ov02_0224EF94(void *fieldSystem);
int ov02_0224F108(void *fieldSystem, const FollowMonInteractionEntry *entry, void *cond);
void ov02_0224F324(void *mon, void *cond);
void ov02_0224F4BC(void *fieldSystem, void *cond);
void ov02_0224F580(void *fieldSystem, void *cond);
void ov02_0224F5D0(void *fieldSystem, void *cond);
void ov02_0224F5FC(void *fieldSystem, void *cond);

void ov02_0224F058(void *fieldSystem, void *cond) {
    void *mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(PTR(fieldSystem, 0xc)));
    U16(PTR(fieldSystem, 0x120), 0x87e) = GetMonData(mon, 5, NULL);
    U8(PTR(fieldSystem, 0x120), 0x87d) = GetMonData(mon, 0x70, NULL);
    ov02_0224F324(mon, cond);
    ov02_0224F4BC(fieldSystem, cond);
    ov02_0224F580(fieldSystem, cond);
    ov02_0224F5D0(fieldSystem, cond);
    ov02_0224F5FC(fieldSystem, cond);
    ov02_0224F644(fieldSystem, cond);
    ov02_0224F64C(fieldSystem, cond);
    ov02_0224F698(fieldSystem, cond);
    ov02_0224F6AC(fieldSystem, U16(PTR(fieldSystem, 0x120), 0x87e), U8(PTR(fieldSystem, 0x120), 0x87d), cond);
    ov02_0224F728(fieldSystem, cond);
    ov02_0224F76C(U16(PTR(fieldSystem, 0x120), 0x87e), cond);
}
