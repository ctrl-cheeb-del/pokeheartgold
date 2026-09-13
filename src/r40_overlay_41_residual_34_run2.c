#include "global.h"

#include "r40_overlay_41_residual_34_private.h"

typedef struct R40ListNode {
    void *value;
    u32 type;
    struct R40ListNode *next;
} R40ListNode;

void ov41_022487F8(void *data, int index, void *value) {
    u8 *p = data;
    ov41_02248A18(data, 0);
    *(s32 *)p = index;
    *(void **)(p + 0x14 + index * 12) = value;
    ov41_02248A18(data, 1);
    ov41_02248724(data);
}
