#include "global.h"

#include "heap.h"
#include "sprite_system.h"
#include "to45_overlay111_resource_groups_r7_private.h"

extern Ov111EntryR7 *ov111_021E63D0(Ov111EntryOwnerR7 *owner, void *a1, void *a2, int index, void *a4);
extern void ov111_021E6268(void *a0, void *a1, s8 a2, void *a3);
extern void ov111_021E64C8(Ov111EntryR7 *entry, void *a1);

void ov111_021E6694(Ov111PanelR7 *panel) {
    int i;

    GF_ASSERT(panel != NULL);
    for (i = 0; i < 2; i++) {
        if (panel->sprites[i] != NULL) {
            Sprite_DeleteAndFreeResources(panel->sprites[i]);
            panel->sprites[i] = NULL;
        }
    }
    for (i = 0; i < 6; i++) {
        ClearWindowTilemapAndCopyToVram(&panel->windows[i]);
        RemoveWindow(&panel->windows[i]);
    }
    Heap_Free(panel);
}

Ov111EntryR7 *ov111_021E66DC(enum HeapID heapId, void *a1, void *a2, void *a3, void *a4, s8 a5) {
    Ov111EntryR7 *entry = Heap_Alloc(heapId, sizeof(Ov111EntryR7));

    MI_CpuFill8(entry, 0, sizeof(Ov111EntryR7));
    entry->unk_04 = (u32)a1;
    entry->unk_00 = (void *)heapId;
    entry->unk_08 = a2;
    entry->unk_0C = a3;
    entry->unk_10 = a4;
    entry->unk_14 = a5;
    return entry;
}

void ov111_021E6710(Ov111PanelGroupR7 *group) {
    int i;

    GF_ASSERT(group != NULL);
    for (i = 0; i < 2; i++) {
        if (group->panels[i] != NULL) {
            ov111_021E6694(group->panels[i]);
        }
    }
    Heap_Free(group);
}

void ov111_021E6738(Ov111EntryOwnerR7 *owner, int index, void *a2, void *a3, void *a4) {
    Ov111EntryR7 *entry = ov111_021E63D0(owner, a2, a3, index, a4);

    ov111_021E6268(entry->unk_08, entry->unk_00, owner->unk_14, owner->unk_00);
    ov111_021E64C8(entry, owner->unk_08);
    owner->entries[index] = entry;
}
