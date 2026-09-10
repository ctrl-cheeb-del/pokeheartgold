#include "network_communication_state_internal.h"

void sub_02037D2C(void) {
    if (_021D4150 != NULL) {
        sub_02034154();
        if (_021D4150->allocation != NULL) {
            Heap_Free(_021D4150->allocation);
        }
        if (sub_02039998()) {
            Heap_Destroy(0x30);
        }
        sub_0203A914();
        sub_02034DE0();
        Heap_Free(_021D4150);
        Heap_Destroy(15);
        _021D4150 = NULL;
    }
}

BOOL sub_02037D78(void) {
    return _021D4150 != NULL;
}

void sub_02037D8C(void *saveData, int mode, int parameter, void *userData) {
    if (sub_02037474() == 0) {
        Heap_CreateAtEnd(3, 15, 0x7080);
        sub_02037C98(saveData, mode);
        _021D4150->parameter4F = parameter;
        _021D4150->userData = userData;
        sub_020381C0(sub_02038218, 0);
    }
}

void sub_02037DD4(void *saveData, int mode, int parameter, void *userData) {
    if (sub_02037474() == 0) {
        Heap_CreateAtEnd(3, 15, 0x7080);
        sub_02037C98(saveData, mode);
        _021D4150->parameter4F = parameter;
        _021D4150->userData = userData;
        sub_020381C0(sub_02038294, 0);
    }
}

void sub_02037E1C(int request) {
    _021D4150->request4D = request;
    sub_020381C0(sub_020382E4, 0);
}

void sub_02037E38(void) {
    sub_02036274();
    sub_020381C0(sub_020383B0, 0);
}
