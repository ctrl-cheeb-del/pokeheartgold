#include <string.h>

#include "global.h"

#include "to45_overlay45_model_pool_r41_private.h"

void ov45_02230A5C(Ov45R41ModelResource *resource, Ov45R41ModelInstance *instance) {
    sub_020181B0(instance, resource);
}

Ov45R41Entry *ov45_02230A6C(Ov45R41Pool *pool) {
    u32 i;

    for (i = 0; i < pool->count; i++) {
        if (!ov45_02230AA4(&pool->entries[i])) {
            return &pool->entries[i];
        }
    }
    GF_ASSERT(FALSE);
    return NULL;
}

BOOL ov45_02230AA4(Ov45R41Entry *entry) {
    if (entry->unk_04 != NULL) {
        return TRUE;
    }
    return FALSE;
}

void ov45_02230AB4(Ov45R41Entry *entry) {
    memset(entry, 0, sizeof(*entry));
}
