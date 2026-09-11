#include "lobby_session_internal.h"

Lobby *_021D41C8;

void sub_02058190(FieldSystem *fieldSystem) {
    int i;
    int netId;

    sub_0200FC60(0, 0);
    sub_0200FC60(1, 0);
    sub_020398D4(1, 1);
    if (sub_02037D78()) {
        if (_021D41C8 == NULL) {
            sub_02058038(fieldSystem);
            _021D41C8->host = 1;
        } else {
            _021D41C8->host = 0;
        }
        _021D41C8->ready = 0;
        netId = sub_0203769C();
        sub_02034818(sub_0203769C());
        for (i = 0; i < sub_02037454(); i++) {
            if (_021D41C8->packets[i] == NULL) {
                _021D41C8->packets[i] = Heap_Alloc((enum HeapID)0, 0x66C);
            }
        }
        sub_02068FC8(0, 0, 0, 0xFF, _021D41C8->fieldSystem, _021D41C8->packets[netId]);
        sub_02037AC0(0x5F);
        sub_020582F4(sub_020588F8, 0);
    }
}
