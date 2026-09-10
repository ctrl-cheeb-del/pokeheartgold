#include "global.h"

#include "frontier_application_internal.h"
#include "heap.h"
#include "unk_02032844.h"
#include "unk_02033AE0.h"
#include "unk_02034354.h"
#include "unk_02035900.h"
#include "unk_02037C94.h"
#include "unk_0205A44C.h"
typedef struct Packet {
    u32 command;
    u8 data[20];
} Packet;
typedef struct Menu {
    Work97024 *parent;
    Packet packet;
    u32 blocked, count, state, remoteValue, participantCount, participantMask, unk34;
    u16 unk38;
    u8 pad3a[6];
    u16 flags40, flags42, flags44;
    s16 flags46;
    u16 flags48, flags4a;
    u8 *sendBuffer, *receiveBuffer;
    u32 unk54;
} Menu;
typedef struct Handshake {
    u8 sender, count, command, accepted;
} Handshake;
u32 MATH_CountPopulation(u32 value);
void sub_02038C1C(int count);
void sub_0205AD24(void *ptr);
void ov85_021E9C84(void *ptr, int event, int value);
void ov85_021E9D9C(void *ptr, int event, int value);
void ov85_021E8680(void *ptr, void *data);
void ov85_021E86AC(void *ptr, u32 data);
void ov85_021E85C4(void *ptr, u8 data);
void ov85_021E85CC(void *ptr, void *data);
void ov85_021E8740(void *ptr, int sender, u32 data);
void ov85_021E8748(void *ptr, void *data);
extern const u32 _0210884C[];
typedef void (*Callback)(int, int, void *, Menu *);
extern const Callback _02108804[];
void *sub_02096C88(Work97024 *parent, enum HeapID heap);

void sub_02096CE0(Menu *menu);

BOOL sub_02096D14(Menu *menu, u32 command, void *data, u32 size);
BOOL sub_02096D4C(Menu *menu, u32 command, void *data, u32 size);
void sub_02096D60(int sender, int unused, Packet *packet, Menu *menu);
void sub_02096D80(int sender, int unused, void *data, Menu *menu);
void sub_02096DA8(int sender, int unused, void *data, Menu *menu);
void sub_02096DB4(int sender, int unused, void *data, Menu *menu);
void sub_02096DBC(int sender, int unused, void *data, Menu *menu);
void sub_02096DE4(int sender, int unused, void *data, Menu *menu);
void sub_02096DF4(int sender, int unused, void *data, Menu *menu);
void sub_02096ED0(int sender, int unused, void *data, Menu *menu);
void sub_02096EF0(int sender, int unused, void *data, Menu *menu);
void sub_02096F0C(int sender, int unused, void *data, Menu *menu);
void sub_02096F2C(int sender, int unused, void *data, Menu *menu);
void sub_02096F3C(int sender, int unused, void *data, Menu *menu);
void sub_02096F50(int sender, int unused, void *data, Menu *menu);
void sub_02096F60(int sender, int unused, void *data, Menu *menu);
void sub_02096F70(int sender, int unused, void *data, Menu *menu);
void sub_02096F80(int sender, int unused, void *data, Menu *menu);
void sub_02096F9C(int sender, int unused, void *data, Menu *menu);
void sub_02096FAC(int sender, int unused, void *data, Menu *menu);
void sub_02096FBC(int sender, int unused, void *data, Menu *menu);
void sub_02096FD0(int sender, int unused, void *data, Menu *menu);
u32 sub_02096FE4(void);
u32 sub_02096FE8(void);
void *sub_02096FF0(int sender, Menu *menu);
int sub_02096FFC(void);
void *sub_02097018(Menu *menu, int sender);
void *sub_02096C88(Work97024 *parent, enum HeapID heap) {
    Menu *menu = Heap_Alloc(heap, sizeof(Menu));
    GF_ASSERT(menu);
    memset(menu, 0, sizeof(Menu));
    menu->parent = parent;
    menu->sendBuffer = Heap_Alloc(heap, 0x1bd0);
    menu->receiveBuffer = Heap_Alloc(heap, 0x1bd0);
    return menu;
}
void sub_02096CC8(void *ptr) {
    Menu *menu = ptr;
    Heap_Free(menu->sendBuffer);
    Heap_Free(menu->receiveBuffer);
    Heap_Free(menu);
}
void sub_02096CE0(Menu *menu) {
    sub_0203410C(_0210884C, 0x87, menu);
}
void sub_02096CF4(void *ptr) {
    Menu *menu = ptr;
    sub_02038C1C(2);
    sub_02037FF0();
    sub_0205AD24(menu->parent->input.communication);
    sub_0205A904(0);
}
BOOL sub_02096D14(Menu *menu, u32 command, void *data, u32 size) {
    Packet *packet;
    GF_ASSERT(command < 18);
    GF_ASSERT(size + 4 <= 24);
    packet = &menu->packet;
    packet->command = command;
    memcpy(packet->data, data, size);
    return sub_02037030(0x82, packet, 24);
}
BOOL sub_02096D4C(Menu *menu, u32 command, void *data, u32 size) {
    if (menu->blocked == 1) {
        return FALSE;
    }
    return sub_02096D14(menu, command, data, size);
}
void sub_02096D60(int sender, int unused, Packet *packet, Menu *menu) {
    if (packet->command >= 18) {
        GF_ASSERT(FALSE);
        return;
    }
    _02108804[packet->command](sender, unused, packet->data, menu);
}
void sub_02096D80(int sender, int unused, void *data, Menu *menu) {
    menu->flags46 |= 1 << sender;
    memcpy(sub_02097018(menu, sender), data, 0x590);
}
void sub_02096DA8(int sender, int unused, void *data, Menu *menu) {
    if (sender == 0) {
        menu->remoteValue = *(u8 *)data;
    }
}
void sub_02096DB4(int sender, int unused, void *data, Menu *menu) {
    menu->count++;
}
void sub_02096DBC(int sender, int unused, void *data, Menu *menu) {
    if (sub_0203769C() != 0) {
        menu->count = 0;
        menu->state = 1;
        ov85_021E9C84(menu->parent->field38, 31, (u8)sender);
    }
}
void sub_02096DE4(int sender, int unused, void *data, Menu *menu) {
    ov85_021E9C84(menu->parent->field38, 2, 0);
}
void sub_02096DF4(int sender, int unused, void *data, Menu *menu) {
    Handshake *src = data;
    if (sender != 0) {
        Handshake packet;
        if (sub_0203769C() != 0) {
            return;
        }
        packet = *src;
        packet.sender = sender;
        packet.count = menu->participantCount;
        switch (src->command) {
        case 0:
            if (menu->participantCount != sub_02037454() || menu->participantCount != sub_02096FFC() || menu->participantCount != MATH_CountPopulation(sub_02033250())) {
                packet.accepted = 0;
            } else {
                menu->participantMask |= 1 << sender;
                packet.accepted = 1;
                sub_02038C1C(sub_02037454());
            }
            break;
        case 1:
            break;
        }
        sub_02096D4C(menu, 2, &packet, 4);
        return;
    }
    switch (src->command) {
    case 0: {
        int id = src->sender;
        if (id != sub_0203769C()) {
            return;
        }
        if (src->accepted == 0) {
            ov85_021E9C84(menu->parent->field38, 8, id);
            return;
        }
        menu->unk38 = src->count;
        ov85_021E9C84(menu->parent->field38, 7, src->sender);
        return;
    }
    case 1:
        ov85_021E9C84(menu->parent->field38, 19, src->sender);
        break;
    }
}
void sub_02096ED0(int sender, int unused, void *data, Menu *menu) {
    ov85_021E9D9C(menu->parent->field38, 1, *(u8 *)data);
    if (sub_0203769C() == 0) {
        menu->unk34 = 0;
    }
}
void sub_02096EF0(int sender, int unused, void *data, Menu *menu) {
    if (sub_0203769C() != 0) {
        ov85_021E9C84(menu->parent->field38, 13, 0);
    }
}
void sub_02096F0C(int sender, int unused, void *data, Menu *menu) {
    if (sub_0203769C() == 0) {
        u8 id = sender;
        sub_02096D4C(menu, 0, &id, 1);
    }
}
void sub_02096F2C(int sender, int unused, void *data, Menu *menu) {
    menu->flags40 |= *(u16 *)data;
}
void sub_02096F3C(int sender, int unused, void *data, Menu *menu) {
    menu->flags42 |= 1 << sender;
}
void sub_02096F50(int sender, int unused, void *data, Menu *menu) {
    ov85_021E8680(menu->parent->field34, data);
}
void sub_02096F60(int sender, int unused, void *data, Menu *menu) {
    ov85_021E86AC(menu->parent->field34, *(u32 *)data);
}
void sub_02096F70(int sender, int unused, void *data, Menu *menu) {
    ov85_021E85C4(menu->parent->field34, *(u8 *)data);
}
void sub_02096F80(int sender, int unused, void *data, Menu *menu) {
    if (sub_0203769C() != 0) {
        ov85_021E85CC(menu->parent->field34, data);
    }
}
void sub_02096F9C(int sender, int unused, void *data, Menu *menu) {
    ov85_021E8740(menu->parent->field34, sender, *(u32 *)data);
}
void sub_02096FAC(int sender, int unused, void *data, Menu *menu) {
    ov85_021E8748(menu->parent->field34, data);
}
void sub_02096FBC(int sender, int unused, void *data, Menu *menu) {
    menu->flags48 |= 1 << sender;
}
void sub_02096FD0(int sender, int unused, void *data, Menu *menu) {
    menu->flags4a |= 1 << sender;
}
u32 sub_02096FE4(void) {
    return 24;
}
u32 sub_02096FE8(void) {
    return 0x590;
}
void *sub_02096FF0(int sender, Menu *menu) {
    return menu->sendBuffer + sender * 0x590;
}
int sub_02096FFC(void) {
    int i, count = 0;
    for (i = 0; i < 5; i++) {
        if (sub_02034818(i) != NULL) {
            count++;
        }
    }
    return count;
}
void *sub_02097018(Menu *menu, int sender) {
    return menu->receiveBuffer + sender * 0x590;
}
