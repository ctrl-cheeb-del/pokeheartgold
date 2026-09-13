#include <string.h>

#include "r40_overlay_90_residual_7_private.h"

BOOL ov90_02258B54(Ov90Status *status) {
    BOOL result = FALSE;

    if (status->data != NULL) {
        if (status->value != sub_02037454(status->data)) {
            result = TRUE;
        }
        if (sub_02039264() == 1) {
            result = TRUE;
        }
        if (sub_020390C4() >= 2) {
            result = TRUE;
        }
        if (result == TRUE) {
            status->data->ready = TRUE;
        }
        if (status->data->ready == TRUE) {
            result = TRUE;
        }
    }
    return result;
}

BOOL ov90_02258B98(Ov90Status *status) {
    if (status->data == NULL) {
        GF_AssertFail();
    }
    if (status->data->ready != TRUE) {
        GF_AssertFail();
    }
    if (sub_02034420() == 1) {
        sub_020343E4();
        sub_0203986C();
    } else if (sub_020392A0() == 1) {
        return TRUE;
    }
    return FALSE;
}

Ov90Resource *ov90_02258BD4(void *owner, u32 heapId) {
    Ov90Resource *resource = Heap_Alloc(heapId, 0x1CC);

    memset(resource, 0, 0x1CC);
    resource->owner = owner;
    resource->narc = NARC_New(0xC8, heapId);
    ov90_02258DD0(resource->manager, 1, heapId);
    resource->resource = ov90_02258E54(resource->manager, resource->narc, 3, 3, 2, 1, 0, 5000, heapId);
    return resource;
}

void ov90_02258C38(Ov90Resource *resource) {
    if (resource->task != NULL) {
        SysTask_Destroy(resource->task);
        resource->task = NULL;
    }
    if (resource->sprite != NULL) {
        Sprite_Delete(resource->sprite);
    }
    ov90_0225BD08(resource->auxiliary);
    ov90_02258E10(resource->manager);
    NARC_Delete(resource->narc);
    Heap_Free(resource);
}
