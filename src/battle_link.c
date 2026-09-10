#include "battle_link_internal.h"

void sub_02074E5C(BattleSystem *battle) {
    LinkTask *send, *recv;
    if (BattleSystem_GetBattleSpecial(battle) & 0x10) {
        return;
    }
    send = Heap_Alloc((enum HeapID)5, sizeof(LinkTask));
    recv = Heap_Alloc((enum HeapID)5, sizeof(LinkTask));
    sub_0203410C(_020FFE30, 12, battle);
    send->battle = battle;
    send->state = 0;
    recv->battle = battle;
    recv->state = 0;
    ov12_0223BBFC(battle, &send->state);
    ov12_0223BC08(battle, &recv->state);
    SysTask_CreateOnMainQueue(sub_02075434, send, 0);
    SysTask_CreateOnMainQueue(sub_020754C0, recv, 0);
}
void sub_02074EC4(LinkWork *work) {
    sub_0203410C(_020FFE30, 12, work);
}
u32 sub_02074ED8(void) {
    return 4;
}
u32 sub_02074EDC(void) {
    return PlayerProfile_sizeof();
}
u32 sub_02074EE4(void) {
    return PartyCore_sizeof();
}
u32 sub_02074EEC(void) {
    return 1000;
}
u32 sub_02074EF4(void) {
    return sizeof(Trainer);
}
void *sub_02074EF8(int sender, LinkWork *work) {
    BattleSetup *setup = work->setup;
    if (setup->battleType & 0x80) {
        return setup->profile[sender * 2];
    }
    return setup->profile[sender];
}
void *sub_02074F18(int sender, LinkWork *work) {
    BattleSetup *setup = work->setup;
    if (setup->battleType & 0x80) {
        return &setup->trainer[sender * 2];
    }
    return &setup->trainer[sender];
}
void *sub_02074F38(int sender, LinkWork *work) {
    BattleSetup *setup = work->setup;
    if (setup->battleType & 0x80) {
        return setup->party[sender * 2];
    }
    return setup->party[sender];
}
void *sub_02074F54(int sender, LinkWork *work) {
    BattleSetup *setup = work->setup;
    if (setup->battleType & 0x80) {
        return setup->chatot[sender * 2];
    }
    return setup->chatot[sender];
}
void *sub_02074F74(int sender, LinkWork *work) {
    return &work->setup->trainer[1];
}
void *sub_02074F7C(int sender, LinkWork *work) {
    return &work->setup->trainer[3];
}
void *sub_02074F84(int sender, LinkWork *work) {
    return work->setup->party[1];
}
void *sub_02074F8C(int sender, LinkWork *work) {
    return work->setup->party[3];
}
void *sub_02074F94(int sender, LinkWork *work) {
    return work->friends[sender];
}
