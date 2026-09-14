#include "to45_overlay41_r35_private.h"

BOOL ov41_0224883C(void *unused, u32 x, u32 y) {
    TouchscreenHitbox hitbox;

    hitbox.rect.top = 0x12;
    hitbox.rect.bottom = 0x8F;
    hitbox.rect.left = 0xA;
    hitbox.rect.right = 0x76;
    return TouchscreenHitbox_PointIsIn(&hitbox, x, y);
}

Ov41R35Node *ov41_02248858(void *owner, int a1, int a2, int a3) {
    Ov41R35Node *node;
    Ov41R35Node *head;

    head = ov41_02248A94(owner);
    node = head->next;

    while (node != head) {
        if (ov41_02249AA8(node, a1, a2, a3) == TRUE) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void ov41_0224888C(u8 *state, int index) {
    Ov41R35Config config;

    config.resource = *(void **)(state + 0x54);
    config.field04 = 0x1A;
    config.field08 = index * 2 + 0x81;
    config.field0C = 0x85;
    config.field10 = index * 2 + 0x82;
    config.field14 = 8;
    config.field18 = 0x81;
    config.field1C = 3;
    config.field20 = 1;
    config.field24 = 2;
    config.field28 = 0;
    config.field2C = 0xE;
    ov41_02249C7C(state + 0x5C, &config);
    *(u32 *)(state + 0x40) = index;
}
