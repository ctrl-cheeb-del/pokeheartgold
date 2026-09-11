#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_02249A40(Ov41Node *node) { memset(node, 0, sizeof(Ov41Node)); }

void ov41_02249A50(Ov41Node *node, Ov41Node *at) {
    node->next = at->next;
    at->next->prev = node;
    node->prev = at;
    at->next = node;
}

void ov41_02249A60(Ov41Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void ov41_02249A70(Ov41Node *head) {
    Ov41Node *node = head->next;
    while (node != head) {
        Ov41Node *next = node->next;
        ov41_02249A60(node);
        ov41_02249A40(node);
        node = next;
    }
}

void ov41_02249A90(Ov41Dispatch *d, s32 arg) {
    if (d->mode < 3) ov41_02246014(d->obj, arg);
    else ov41_02249700(d->obj, arg);
}
