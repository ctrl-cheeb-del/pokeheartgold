#include "overlay49_menu_graphics_private.h"

void ov49_0225A7C0(void *work) {
    SpriteList_RenderAndAnimateSprites(PTR_AT(work, 4));
    thunk_UpdateCellTransferStateManager();
}
