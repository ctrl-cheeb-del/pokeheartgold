#ifndef OVERLAY96_SHOP_ASSETS_R53_TAIL_PRIVATE_H
#define OVERLAY96_SHOP_ASSETS_R53_TAIL_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "heap.h"

typedef struct Ov96ShopWorkR53 {
    BgConfig *bgConfig;
    u8 pad04[0x10];
    enum HeapID heapId;
    u8 pad18[0x71c];
    void *screenAlloc;
    NNSG2dScreenData *screenData;
    u8 pad73C[0x38];
    void *graphicsObject;
} Ov96ShopWorkR53;

void ov96_021F3CBC(void *);
void ov96_021F0D60(Ov96ShopWorkR53 *work);
void *PokeathlonCourse_GetHeapAllocPtr4(void *course);
void *PokeathlonCourse_GetDataCopyArea(void *course);
void *ov96_021E8A20(void *ptr);
void ov96_021EB63C(void *ptr, int value);
void ov96_021EB144(void *ptr, int value);
void ov96_021E65A4(void *course);
void *ov96_021F46B4(void *ptr);
void ov96_021E8318(void *course, void *ptr);
void ov96_021F2EFC(void *work, void *ptr);
u8 ov96_021F30F8(u8 value, int kind);
BOOL System_GetTouchNew(void);
BOOL System_GetTouchHeld(void);
u32 ov96_021E5F24(void *course);
void ov96_021E8228(void *course, u8 player, u8 type, u8 index, u32 value);
void ov96_021F1614(void *course);
BOOL ov96_021F107C(void *course);

#endif
