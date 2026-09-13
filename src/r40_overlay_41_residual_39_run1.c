#include "global.h"

#include "r40_overlay_41_residual_39_private.h"
typedef struct Node {
    void *value;
    u32 kind;
    struct Node *next;
} Node;

void *ov41_02248AFC(void *data, int a1, int a2, int wanted) {
    Node *node;
    int i = 0;
    Node *sentinel = ov41_02248ABC(data, a1, a2);
    node = sentinel->next;
    while (node != sentinel) {
        if (i == wanted) {
            return node;
        }
        node = node->next;
        i++;
    }
    return NULL;
}

void ov41_02248B20(void *data, void *object, int index, void *value) {
    if (*(int *)data != index || value != *(void **)((u8 *)data + 0x14 + index * 12)) {
        ov41_02246008(object, 0);
    } else {
        ov41_02246008(object, 1);
    }
}
