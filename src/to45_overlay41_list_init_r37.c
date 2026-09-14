#include "global.h"

#include "to45_overlay41_list_init_r37_private.h"

extern void ov41_02248A28(Ov41ListHolderR37 *holder, u32 value);
extern void ov41_02246008(void *data, u32 value);

void ov41_022489A8(Ov41ListHolderR37 *holders, const Ov41InitInputR37 *input) {
    ov41_02248A28(&holders[1], input->value_1C);
    holders[0].list = NULL;
    ov41_022489E4(holders[1].list, 1);
    ov41_02248A28(&holders[2], input->value_20);
    ov41_02248A28(&holders[3], input->value_24);
    ov41_02248A28(&holders[4], 1);
}

void ov41_022489E4(Ov41ListNodeR37 *sentinel, u32 value) {
    Ov41ListNodeR37 *node = sentinel->next;

    while (node != sentinel) {
        if (node->type <= 2) {
            ov41_02246008(node->data, value);
        }
        node = node->next;
    }
}
