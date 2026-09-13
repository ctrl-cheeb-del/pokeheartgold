#include "global.h"

#include "r40_overlay_41_residual_34_private.h"

typedef struct R40ListNode {
    void *value;
    u32 type;
    struct R40ListNode *next;
} R40ListNode;

void ov41_022486F8(void *data) {
    int i;
    int j;
    u8 *p = data;
    for (i = 0; i < 3; i++, p += 12) {
        for (j = 0; j < *(s32 *)(p + 0x10); j++) {
            ov41_02249A70((u8 *)*(void **)(p + 0xC) + j * 0x10);
        }
    }
}

void ov41_02248724(void *unused) {
    R40ListNode *node;
    int index = -1;
    R40ListNode *sentinel = ov41_02248A94();
    node = sentinel->next;
    while (node != sentinel) {
        if (node->type <= 2) {
            ov41_02246014(node->value, index);
        }
        node = node->next;
        index--;
    }
}

BOOL ov41_02248750(void *data, int index, void *value) {
    u8 *p = data;
    if (*(u32 *)(p + 0x3C) == 0) {
        int old = *(s32 *)p;
        ov41_02248B84(data, old, *(void **)(p + 0x14 + old * 12), index, value);
        *(s32 *)p = index;
        *(void **)(p + 0x14 + index * 12) = value;
        ov41_02248724(data);
        return TRUE;
    }
    return FALSE;
}
