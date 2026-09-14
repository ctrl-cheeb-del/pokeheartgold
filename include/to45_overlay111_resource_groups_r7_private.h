#ifndef TO45_OVERLAY111_RESOURCE_GROUPS_R7_PRIVATE_H
#define TO45_OVERLAY111_RESOURCE_GROUPS_R7_PRIVATE_H

#include "global.h"

#include "sprite_system.h"
#include "unk_0208C3E4_internal.h"

typedef struct Ov111PanelR7 {
    u32 unk_00;
    ManagedSprite *sprites[2];
    Window windows[6];
} Ov111PanelR7;

typedef struct Ov111PanelGroupR7 {
    u8 padding[0x18];
    Ov111PanelR7 *panels[2];
} Ov111PanelGroupR7;

typedef struct Ov111EntryR7 {
    void *unk_00;
    u32 unk_04;
    void *unk_08;
    void *unk_0C;
    void *unk_10;
    s8 unk_14;
    u8 padding[0x0B];
} Ov111EntryR7;

typedef struct Ov111EntryOwnerR7 {
    void *unk_00;
    u32 unk_04;
    void *unk_08;
    u8 padding[0x08];
    s8 unk_14;
    u8 padding_15[3];
    Ov111EntryR7 *entries[2];
} Ov111EntryOwnerR7;

void ov111_021E6694(Ov111PanelR7 *panel);
Ov111EntryR7 *ov111_021E66DC(enum HeapID heapId, void *a1, void *a2, void *a3, void *a4, s8 a5);
void ov111_021E6710(Ov111PanelGroupR7 *group);
void ov111_021E6738(Ov111EntryOwnerR7 *owner, int index, void *a2, void *a3, void *a4);

#endif
